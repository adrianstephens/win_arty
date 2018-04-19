#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "filename.h"
#include "base/array.h"

#ifdef PLAT_PS3
#include <cell/cell_fs.h>
#elif defined(PLAT_PS4)
#include <_fs.h>
#elif defined PLAT_MAC || defined PLAT_IOS || defined PLAT_ANDROID
#include <dirent.h>
#endif

namespace iso {

#if defined(PLAT_PC) || defined(PLAT_X360) || defined(PLAT_XONE)
class _directory_iterator {
	WIN32_FIND_DATAA	find;
	HANDLE				h;
protected:
	_directory_iterator() : h(INVALID_HANDLE_VALUE) {}
	bool	open(const char *pattern) {
#ifdef PLAT_X360
		h = FindFirstFileA(pattern, &find);
#else
		h = FindFirstFileExA(pattern, FindExInfoBasic, &find, FindExSearchNameMatch, NULL, FIND_FIRST_EX_LARGE_FETCH);
#endif
		return h != INVALID_HANDLE_VALUE;
	}
	void	close() {
		if (h != INVALID_HANDLE_VALUE)
			FindClose(h);
	}
	bool	next() {
		return !!FindNextFileA(h, &find);
	}
	const char	*name() const {
		return find.cFileName;
	}
	bool	is_dir() const {
		return !!(find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
	}
	filetime_t	write_time()	{ return find.ftLastWriteTime; }
	filetime_t	create_time()	{ return find.ftCreationTime; }
	filetime_t	access_time()	{ return find.ftLastAccessTime; }
};

#elif defined(PLAT_PS3)
class _directory_iterator {
	CellFsDirent		dirent;
	filename			match;
	int					fd;
protected:
	_directory_iterator() : fd(-1) {}
	bool	open(const char *pattern) {
		fd = -1;
		if (cellFsOpendir(filename(pattern).dir(), &fd) == CELL_OK) {
			match = filename(pattern).name_ext();
			return next();
		}
		return false;
	}
	void	close() {
		if (fd != -1)
			cellFsClosedir(fd);
	}
	bool	next() {
		uint64	read;
		while (cellFsReaddir(fd, &dirent, &read) == CELL_OK && read) {
			if (filename(dirent.d_name).matches(match))
				return true;
		}
		return false;
	}
	const char	*name() const {
		return dirent.d_name;
	}
	bool	is_dir() const {
		return !!(dirent.d_type && CELL_FS_TYPE_DIRECTORY);
	}
};

#elif defined(PLAT_PS4)

class _directory_iterator {
	char*				block;
	blksize_t			blocksize;
	int					blockread;
	SceKernelDirent*	dirent;
	filename			match;
	int					fd;
protected:
	_directory_iterator() : fd(-1) {}
	bool	open(const char *pattern) {
		filename	dir = filename(pattern).dir();
		fd = sceKernelOpen(dir, SCE_KERNEL_O_RDONLY | SCE_KERNEL_O_DIRECTORY, SCE_KERNEL_S_IRU | SCE_KERNEL_S_IFDIR);
		if (fd >= 0) {
			SceKernelStat	s;
			sceKernelStat(dir, &s);
			blocksize	= s.st_blksize;
			block		= (char*)malloc(blocksize);
			blockread	= sceKernelGetdents(fd, block, blocksize);
			dirent		= (SceKernelDirent*)block;
			match		= filename(pattern).name_ext();
			if (blockread > 0)
				return filename(dirent->d_name).matches(match) || next();
		}
		return false;
	}
	void	close() {
		if (fd >= 0) {
			sceKernelClose(fd);
			free(block);
		}
	}
	bool	next() {
		for (;;) {
			dirent = (SceKernelDirent*)((char*)dirent + dirent->d_reclen);
			if ((char*)dirent - block < blockread) {
				if (filename(dirent->d_name).matches(match))
					return true;
			} else {
				if (!(blockread = sceKernelGetdents(fd, block, blocksize)))
					return false;
				dirent = (SceKernelDirent*)block;
			}
		}
	}
	const char* name()	const { return dirent->d_name; }
	bool	is_dir()	const { return SCE_KERNEL_S_ISDIR(dirent->d_type); }
};

#elif defined PLAT_WII
class _directory_iterator {
	DVDDir		dir;
	DVDDirEntry	entry;
	bool		is_open;
protected:
	_directory_iterator() : is_open(false) {}
	bool	open(const char *pattern) {
		return (is_open = DVDOpenDir(pattern, &dir)) && next();
	}
	void	close() {
		if (is_open)
			DVDCloseDir(&dir);
	}
	bool	next() {
		return DVDReadDir(&dir, &entry);
	}
	const char* name()	const { return entry.name; }
	bool	is_dir()	const { return !!entry.isDir; }
};

#elif defined PLAT_MAC || defined PLAT_IOS || defined PLAT_ANDROID

class _directory_iterator {
	DIR					*dir;
	struct dirent		entry;
	filename			match;
protected:
	_directory_iterator() : dir(0) {}
	bool	open(const char *pattern) {
		if (dir = opendir(filename(pattern).dir())) {
			match = filename(pattern).name_ext();
			return next();
		}
		return false;
	}
	void	close() {
		if (dir)
			closedir(dir);
	}

	bool	next() {
		struct dirent	*result;
		while (readdir_r(dir, &entry, &result) == 0 && result) {
			if (filename(entry.d_name).matches(match))
				return true;
		}
		return false;
	}
	const char	*name() const { return entry.d_name; }
	bool	is_dir()	const { return entry.d_type & DT_DIR; }
};
#endif

class directory_iterator : public _directory_iterator {
	bool	ok;
	directory_iterator(const directory_iterator &d);
public:
	directory_iterator() : ok(false)		{}
	directory_iterator(const char *pattern) { ok = open(pattern); }
	~directory_iterator()					{ close(); }
	bool	set_pattern(const char *pattern){ close(); return ok = open(pattern); }

	bool	test()			const			{ return ok; }
	bool	is_dir()		const			{ return _directory_iterator::is_dir();	}

	bool	operator++()					{ return ok = ok && next(); }
	operator const char*()	const			{ return ok ? name() : 0; }
};

class directory_iterator2 : public directory_iterator {
protected:
	const char *pattern;
	filename	dir;
	directory_iterator2(const char *_pattern) : pattern(_pattern) {}
	bool	set_dir(const filename &_dir) {
		return set_pattern(filename(dir = _dir).add_dir(pattern));
	}
};

class recursive_directory_iterator : public directory_iterator2 {
protected:
	dynamic_array<directory_iterator>	stack;
	bool	next();

	bool	set_dir(const filename &_dir) {
		return directory_iterator2::set_dir(_dir) || next();
	}
	recursive_directory_iterator(const char *_pattern) : directory_iterator2(_pattern) {}
public:
	recursive_directory_iterator(const filename &fn) : directory_iterator2(fn.name_ext_ptr()) {
		set_dir(fn.dir());
	}
	bool	operator++() {
		return directory_iterator::operator++() || next();
	}
	operator filename() const {
		if (const char *n = name())
			return filename(dir).add_dir(n);
		return filename();
	}
};

template<typename I, typename B> struct directory_helper : B {
	I	i, e;
	bool next_directory_entry() {
		while (i != e) {
			if (B::set_dir(*i++))
				return true;
		}
		return false;
	}
	directory_helper(I begin, I end, const char *_pattern) : B(_pattern), i(begin), e(end) {
		next_directory_entry();
	}
	bool	operator++() {
		return B::operator++() || next_directory_entry();
	}
	operator filename() const {
		if (const char *n = B::name())
			return filename(B::dir).add_dir(n);
		return filename();
	}
};

class pathlist_iterator {
	const char *p;
public:
	pathlist_iterator(const char *_p) : p(_p) {}
	pathlist_iterator& operator++() { 
		if (p && (p = strchr(p, ';')))
			++p;
		return *this;
	}
	bool	operator==(const pathlist_iterator &b) const {
		return p == b.p;
	}
	filename operator*() { 
		const char *n = p ? strchr(p, ';') : 0;
		return n ? filename(str(p, n)) : filename(p);
	}
};

template<typename I> struct multi_directory_iterator : directory_helper<I, directory_iterator2> {
	multi_directory_iterator(I begin, I end, const char *_pattern) : directory_helper<I, directory_iterator2>(begin, end, _pattern) {}
};

template<typename C> multi_directory_iterator<typename container_traits<C>::const_iterator> directories(const C &c, const char *pattern) {
	return multi_directory_iterator<typename container_traits<C>::const_iterator>(begin(c), end(c), pattern);
}

template<typename I> struct recursive_multi_directory_iterator : directory_helper<I, recursive_directory_iterator> {
	recursive_multi_directory_iterator(I begin, I end, const char *_pattern) : directory_helper<I, recursive_directory_iterator>(begin, end, _pattern) {}
};

}

#endif//DIRECTORY_H
