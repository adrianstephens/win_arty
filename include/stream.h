#ifndef STREAM_H
#define STREAM_H

#include "base/defs.h"

#ifndef PLAT_WII
#include <stdio.h>
#include <fcntl.h>
#endif

#ifdef PLAT_PC
#include "io.h"
//extern "C" intptr_t _get_osfhandle(int fd);
#define fdopen				_fdopen
#endif

#ifndef EOF
#define	EOF			(-1)
#endif
#ifndef SEEK_SET
#define	SEEK_SET	0
#endif
#ifndef SEEK_CUR
#define	SEEK_CUR	1
#endif
#ifndef SEEK_END
#define	SEEK_END	2
#endif

namespace iso {

#ifdef PLAT_PC
inline FILE* fopen(char const* filename, char const* mode) {
	FILE	*h;
	return fopen_s(&h, filename, mode) ? 0 : h;
}
#endif

typedef int64		streamptr;

template<typename T> struct T_terminated : T_inheritable<T>::type {
	template<typename T2> T_terminated(const T2 &t2) : T_inheritable<T>::type(t2)	{}
	friend const T& get(const T_terminated<T> &t) { return t; }
};
template<typename T> inline T_terminated<T> terminated(const T &t) { return t; }

//-----------------------------------------------------------------------------
//	defaults
//-----------------------------------------------------------------------------

template<typename S> struct stream_defaults {
	bool		eof()						{ return static_cast<S*>(this)->tell() >= static_cast<S*>(this)->length(); }
	bool		exists()					{ return true;	}
	bool		canseek()					{ return true;	}
	void		seek(streamptr offset)		{}
	void		seek_cur(streamptr offset)	{ static_cast<S*>(this)->seek(static_cast<S*>(this)->tell() + offset); }
	void		seek_end(streamptr offset)	{ static_cast<S*>(this)->seek(static_cast<S*>(this)->length() + offset); }
	streamptr	tell()						{ return -1;	}
	streamptr	length()					{ return stream_length(static_cast<S*>(this)); }
	size_t		remaining()					{ return static_cast<S*>(this)->length() - static_cast<S*>(this)->tell(); }
	S&			_clone()					{ return *static_cast<S*>(this); }
};

//-----------------------------------------------------------------------------
//	reader_mixout/writer_mixout
//-----------------------------------------------------------------------------

template<class R, typename T>	inline bool read(R &r, T &t);
template<class R, typename T, typename... TT> bool read(R &r, T &t, TT&... tt) {
	return read(r, t) && read(r, tt...);
}
template<class R> inline bool check_readbuff(R &r, void *buffer, size_t size) {
	return r.readbuff(buffer, size) == size;
}
template<class R> inline malloc_block read_all(R &r) {
	r.seek(0); return malloc_block(r, r.length());
}

template<class R, typename T> static yesno::yes	can_read(decltype(((T*)0)->read(*(R*)0))*);
template<class R, typename T> static yesno::no	can_read(...);

template<int N>	struct read_s {
	template<class R, typename T> static inline bool f(R &r, T &t)				{ return r.readbuff(&t, sizeof(T)) == sizeof(T);	}
	template<class R, typename T> static inline bool f(R &r, T *t, size_t n)	{ return r.readbuff(t, sizeof(T) * n) == sizeof(T) * n;	}
};
template<>		struct read_s<sizeof(yesno::yes)> {
	template<class R, typename T> static inline bool f(R &r, T &t)				{ return t.read(r); }
	template<class R, typename T, int N> static inline bool f(R &r, T (&t)[N])	{ bool ret = true; for (int i = 0; i < N && (ret = t[i].read(r)); i++) {} return ret; }
	template<class R, typename T> static inline bool f(R &r, T *t, size_t n)	{ bool ret = true; for (int i = 0; i < n && (ret = t[i].read(r)); i++) {} return ret; }
};

template<class R, typename T>			inline bool read(R &r, T &t)			{ return read_s<sizeof(can_read<R,T>(0))>::f(r, t);		}
template<class R, typename T>			inline bool readn(R &r, T *t, size_t n)	{ return read_s<sizeof(can_read<R,T>(0))>::f(r, t, n);	}
template<class R, typename T>			inline bool readnx1(R &r, T *t, size_t n){ bool ret = true; for (int i = 0; i < n && (ret = read(r, t[i])); i++) {} return ret; }
template<class R, typename T, int N>	inline bool read(R &r, T (&t)[N])		{ return read_s<sizeof(can_read<R,T>(0))>::f(r, t);		}

template<class R, typename T>			inline bool static_read(R &r, T &t)		{ return read(r, t); }
/*
template<class S> class reader_mixout : public S {
public:
	reader_mixout()											{}
	template<typename A> reader_mixout(A &a) : S(a)			{}
	template<typename A> reader_mixout(const A &a) : S(a)	{}
	template<typename A, typename B> reader_mixout(const A &a, const B &b) : S(a, b)	{}

	template<typename T>bool	read(T &t)					{ return static_read(*this, t);	}
	template<typename T>T		get()						{ T t; read(t); return t;		}
	getter<reader_mixout>		get()						{ return *this;	}
	reader_mixout&				me()						{ return *this;	}
};

template<class S, typename T> inline reader_mixout<S>&	operator>>(reader_mixout<S> &r, T &t) {
	read_s<sizeof(can_read<reader_mixout<S>, T>(0))>::f(r, t); return r;
}
*/
template<class S> struct reader_mixin0 {
	S&							me()		{ return *static_cast<S*>(this); }
	template<typename T>bool	read(T &t)	{ return static_read(me(), t);	}
	template<typename T>T		get()		{ T t; read(t); return t;		}
	getter<reader_mixin0>		get()		{ return *this;	}
};

template<class S> struct reader_mixin : reader_mixin0<S>, stream_defaults<S> {
	int	getc()								{ uint8 c; return static_cast<S*>(this)->readbuff(&c, 1) ? c : EOF; }
	int	readbuff(void *buffer, size_t size)	{ char *p = (char*)buffer; int i, c; for (i = 0; i < (int)size && (c = static_cast<S*>(this)->getc()) != EOF; *p++ = c, i++) {} return i; }
};

//-------------------------------------

template<class W, typename T>	inline bool write(W &w, const T &t);
template<class W, typename T, typename... TT> bool write(W &w, const T &t, const TT&... tt) {
	return write(w, t) && write(w, tt...);
}
template<class W> inline bool check_writebuff(W &w, const void *buffer, size_t size) { return w.writebuff(buffer, size) == size; }

template<class W, typename T> static yesno::yes	can_write(decltype(((const T*)0)->write(*(W*)0))*);
template<class W, typename T> static yesno::no	can_write(...);

template<int N>	struct write_s {
	template<class W, typename T> static inline bool f(W &w, const T &t)				{ return w.writebuff(&t, sizeof(T)) == sizeof(T); }
	template<class W, typename T> static inline bool f(W &w, const T *t, size_t n)		{ return w.writebuff(t, sizeof(T) * n) == sizeof(T) * n; }
};
template<>		struct write_s<sizeof(yesno::yes)> {
	template<class W, typename T> static inline bool f(W &w, const T &t)				{ return t.write(w); }
	template<class W, typename T, int N> static inline bool f(W &w, const T (&t)[N])	{ bool ret = true; for (int i = 0; i < N && (ret = t[i].write(w)); i++) {} return ret; }
	template<class W, typename I> static inline bool f(W &w, I i, size_t n)				{ bool ret = true; while (n-- && (ret = i->write(w))) ++i; return ret; }
};

template<class W, typename T>			inline bool write(W &w, const T &t)					{ return write_s<sizeof(can_write<W,T>(0))>::f(w, t); }
template<class W, typename T>			inline bool writen(W &w, const T *t, size_t n)		{ return write_s<sizeof(can_write<W,T>(0))>::f(w, t, n); }
template<class W, typename I>			inline bool writen(W &w, I i, size_t n)				{ return write_s<sizeof(can_write<W,typename iterator_traits<I>::element>(0))>::f(w, i, n); }
template<class W, typename T, int N>	inline bool write(W &w, T (&t)[N])					{ return write_s<sizeof(can_write<W,T>(0))>::f(w, t); }
template<class W, int N>				inline bool	write(W &w, const char (&s)[N])			{ return w.writebuff(s, N - 1) == N - 1; }
template<class W>						inline bool	write(W &w, const char *s)				{ return !s || check_writebuff(w, s, strlen(s)); }
template<class W>						inline bool	write(W &w, char *s)					{ return !s || check_writebuff(w, s, strlen(s)); }

template<class W, typename T>			inline bool static_write(W &w, const T &t)			{ return write(w, t); }
/*
template<class S> class writer_mixout : public S {
public:
	writer_mixout()											{}
	template<typename A> writer_mixout(A &a) : S(a)			{}
	template<typename A> writer_mixout(const A &a) : S(a)	{}
	template<typename A, typename B> writer_mixout(const A &a, const B &b) : S(a, b)	{}

	writer_mixout&				me()						{ return *this;	}
	template<typename T>bool	write(const T &t)			{ return static_write(*this, t); }
	template<int N>		bool	write(const char (&s)[N])	{ return S::writebuff(s, N - 1) == N - 1; }
};

template<class S, typename T> inline writer_mixout<S>&	operator<<(writer_mixout<S> &w, T &t) {
	write_s<sizeof(can_write<writer_mixout<S>,T>(0))>::f(w, t); return w;
}
*/
template<class S> struct writer_mixin0 {
	S&							me()						{ return *static_cast<S*>(this); }
	template<typename T>bool	write(const T &t)			{ return static_write(me(), t); }
	template<int N>		bool	write(const char (&s)[N])	{ return me().writebuff(s, N - 1) == N - 1; }
};

template<class S> struct writer_mixin : writer_mixin0<S>, stream_defaults<S> {
	int	putc(int c)									{ uint8 v = c; return static_cast<S*>(this)->writebuff(&v, 1) ? v : EOF; }
	int	writebuff(const void *buffer, size_t size)	{ char *p = (char*)buffer; int i; for (i = 0; i < (int)size && static_cast<S*>(this)->putc(*p++) != EOF; i++) {} return i; }
};

//-----------------------------------------------------------------------------
//	readp
//-----------------------------------------------------------------------------

template<class R, typename T> static yesno::yes	has_get_ptr(decltype(T::get_ptr(*(R*)0))*);
template<class R, typename T> static yesno::no	has_get_ptr(...);

template<int N>	struct get_ptr_s {
	template<typename T, class R> static inline const T* f(R &r, size_t n = 1)	{ return r.template get_ptr<T>(n);	}
};
template<>		struct get_ptr_s<sizeof(yesno::yes)> {
	template<typename T, class R> static inline const T* f(R &r)			{ return T::get_ptr(r); }
	template<typename T, class R> static inline const T* f(R &r, size_t n)	{
		if (n) {
			const T *p = T::get_ptr(r);
			while (--n)
				T::get_ptr(r);
			return p;
		}
		return 0;
	}
};

template<typename T, class R> const T*	readp(R &r)				{ return get_ptr_s<sizeof(has_get_ptr<R,T>(0))>::template f<T>(r);	}
template<typename T, class R> const T*	readp(R &r, size_t n)	{ return get_ptr_s<sizeof(has_get_ptr<R,T>(0))>::template f<T>(r, n);	}

template<class R> struct _readp {
	R	&r;
	_readp(R &_r) : r(_r)	{}
	template<typename T> operator const T*() const	{ return readp<T>(r); }
};

template<class R> _readp<R>	readp(R &r)	{ return r; }

template<class R, typename T> bool read(R &r, T *&t) { t = readp<T>(r); return true; }

//-----------------------------------------------------------------------------
//	helpers
//-----------------------------------------------------------------------------

template<int N, bool A = (N > 1024)> struct byte_buffer {
	uint8		buffer[N];
	operator uint8*()	{ return buffer; }
};

template<int N> struct byte_buffer<N, true> {
	uint8		*buffer;
	byte_buffer() : buffer((uint8*)malloc(N)) {}
	~byte_buffer()		{ free(buffer); }
	operator uint8*()	{ return buffer; }
};

template<class W, class R> streamptr stream_copy(W &w, R &r, void *buffer, size_t buffer_size) {
	streamptr	total = 0;
	while (uint32 read = r.readbuff(buffer, buffer_size))
		total += w.writebuff(buffer, read);
	return total;
}

template<int N, class W, class R> streamptr stream_copy(W &w, R &r) {
	byte_buffer<N>	buffer;
	return stream_copy(w, r, buffer, N);
}

template<typename R> void stream_skip(R &r, intptr_t skip)	{
	ISO_ASSERT(skip >= 0);
	while (skip) {
		char	dummy[1024];
		skip -= r.readbuff(dummy, min(skip, 1024));
	}
}

template<typename S> inline streamptr stream_length(S *s) {
	streamptr pos = s->tell();
	s->seek_end(0);
	streamptr len = s->tell();
	s->seek(pos);
	return len;
}

template<typename S> struct check_end {
	S			&s;
	streamptr	end;
	check_end(S &_s, streamptr offset) : s(_s), end(s.tell() + offset) {}
	~check_end() { ISO_ASSERT(s.tell() == end); }
};
template<typename S> check_end<S> make_check_end(S &s, streamptr offset) { return check_end<S>(s, offset); }

template<typename S> struct skip_end {
	S			&s;
	streamptr	end;
	skip_end(S &_s, streamptr offset) : s(_s), end(s.tell() + offset) {}
	~skip_end() { s.seek(end); }
};
template<typename S> skip_end<S> make_skip_end(S &s) { return skip_end<S>(s); }

//-----------------------------------------------------------------------------
//	block_writer/block_reader
//-----------------------------------------------------------------------------

template<int N> struct stream_block {
	enum {BLOCK_SIZE = N};
	uint8		block[N];
	streamptr	p;
	stream_block() : p(0)	{}
	memory_block		buffered()			{ return memory_block(block, p % N); }
	const_memory_block	buffered()	const	{ return const_memory_block(block, p % N); }
};

// has a process(uint8 block[N]) for one block at a time

template<typename T, int N> struct block_writer : writer_mixin<block_writer<T, N> >, stream_block<N> {
	using stream_block<N>::block;
	using stream_block<N>::p;
	int			writebuff(const void *buffer, size_t size);
	streamptr	tell()		const	{ return p;	}
};

template<typename T, int N> int block_writer<T, N>::writebuff(const void *buffer, size_t size) {
	uint32	n = 0;

	if (uint32 o = p % N) {
		n = N - o;
		if (size < n) {
			memcpy(block + o, buffer, size);
			p += size;
			return int(size);
		}
		memcpy(block + o, buffer, n);
		static_cast<T*>(this)->process(block);
	}

	buffer	= (uint8*)buffer + n;
	size_t remain = size - n;
	while (remain >= N) {
		static_cast<T*>(this)->process((uint8*)buffer);
		buffer	= (uint8*)buffer + N;
		remain -= N;
	}
	memcpy(block, buffer, remain);

	p += size;
	return int(size);
}

// has a process(uint8 block[N], size_t len) for multiple blocks

template<typename T, int N> struct block_writer2 : writer_mixin<block_writer2<T, N> >, stream_block<N> {
	using stream_block<N>::block;
	using stream_block<N>::p;
	int			writebuff(const void *buffer, size_t size);
	streamptr	tell()		const	{ return p;	}
};

template<typename T, int N> int block_writer2<T, N>::writebuff(const void *buffer, size_t size) {
	uint32	n = 0;
	
	if (uint32 o = p % N) {
		n = N - o;
		if (size < n) {
			memcpy(block + o, buffer, size);
			p += size;
			return int(size);
		}
		memcpy(block + o, buffer, n);
		static_cast<T*>(this)->process(block, N);
	}

	size_t rem = (size - n) % N;
	static_cast<T*>(this)->process((const uint8*)buffer + n, size - n - rem);
	memcpy(block, (const uint8*)buffer + size - rem, rem);

	p += size;
	return int(size);
}

template<typename T, int N> struct block_reader : reader_mixin<block_reader<T, N> >, stream_block<N> {
	using stream_block<N>::block;
	using stream_block<N>::p;
	int			readbuff(void *buffer, size_t size);
	streamptr	tell()		const	{ return this->p;	}
};

template<typename T, int N> int block_reader<T, N>::readbuff(void *buffer, size_t size) {
	uint32	n = 0;

	if (uint32 o = p % N) {
		n = N - o;
		if (size < n) {
			memcpy(buffer, block + o, size);
			p += size;
			return int(size);
		}
		memcpy(buffer, block + o, n);
	}

	buffer	= (uint8*)buffer + n;
	size_t remain = size - n;
	while (remain >= N) {
		static_cast<T*>(this)->process((uint8*)buffer);
		buffer	= (uint8*)buffer + N;
		remain -= N;
	}
	
	if (remain) {
		static_cast<T*>(this)->process(block);
		memcpy(buffer, block, remain);
	}

	p += size;
	return int(size);
}
//-----------------------------------------------------------------------------
//	buffered_reader / buffered_writer
//-----------------------------------------------------------------------------

template<int N> class stream_buffer : protected byte_buffer<N> {
protected:
	streamptr	current, buffer_start;
	using byte_buffer<N>::buffer;
public:
	stream_buffer() : current(0), buffer_start(0)	{}
	memory_block		buffered()			{ return memory_block(buffer, current - buffer_start); }
	const_memory_block	buffered()	const	{ return const_memory_block(buffer, current - buffer_start); }
};

template<class S, int N> class buffered_reader : public S, public stream_buffer<N> {
	streamptr	 end;
	using stream_buffer<N>::current;
	using stream_buffer<N>::buffer_start;
	int	more() {
		int read = S::readbuff(this->buffer, N);
		buffer_start = end;
		end += read;
		return read;
	}
public:
	template<typename T> buffered_reader(T &_t) : S(_t), end(0)	{}

	int			readbuff(void *buffer, size_t size);
	int			getc()								{ if (current == end && !more()) return EOF; return this->buffer[current++ - buffer_start]; }
	streamptr	tell()				const			{ return current; }
};

template<class S, int N> int buffered_reader<S, N>::readbuff(void *buffer, size_t size) {
	size_t	total = 0;
	while (size) {
		ISO_ASSERT(current >= buffer_start);
		while (current >= end) {
			if (!more())
				return int(total);
		}
		size_t	size2 = end - current;
		if (size2 > size)
			size2 = size;
		memcpy(buffer, this->buffer + int(current - buffer_start), size2);

		total	+= size2;
		current	+= size2;
		buffer	= (uint8*)buffer + size2;
		size	-= size2;
	}
	return int(total);
}

template<class S, int N> class buffered_writer : public S, public stream_buffer<N> {
	using stream_buffer<N>::current;
	using stream_buffer<N>::buffer_start;
	int				flush() {
		int	write = S::writebuff(this->buffer, current - buffer_start);
		buffer_start = current;
		return write;
	}
public:
	template<typename T> buffered_writer(T &_t) : S(_t) {}
	~buffered_writer() { flush(); }

	int			writebuff(const void *buffer, size_t size);
	int			putc(int c)							{ if (current - buffer_start == N) flush(); return this->buffer[current++ - buffer_start] = c; }

	bool		eof()								{ return false; }
	void		seek(streamptr offset)				{ flush(); S::seek(buffer_start = current = offset); }
	void		seek_cur(streamptr offset)			{ seek(current + offset); }
	void		seek_end(streamptr offset)			{ seek(S::length() + offset); }
	streamptr	tell()				const			{ return current; }
};

template<class S, int N> int buffered_writer<S, N>::writebuff(const void *buffer, size_t size) {
	for (size_t i = 0, n; i < size; i += n) {
		if ((n = buffer_start + N - current) == 0) {
			flush();
			n = N;
		}
		if (n >= size - i)
			n = size - i;

		memcpy(this->buffer + int(current - buffer_start), (const char*)buffer + i, n);
		current	+= n;
	}
	return int(size);
}

//-----------------------------------------------------------------------------
//	filereader/filewriter
//-----------------------------------------------------------------------------

#ifdef PLAT_WII

class filereader {
	DVDFileInfo	info;
	streamptr	current, buffer_start;
	char		buffer_space[2048] __attribute__ ((aligned(32)));;
public:
	filereader(const char *filename) : current(0), buffer_start(-2048) { if (!DVDOpen(filename, &info)) info.length = 0; }
	~filereader()									{ if (info.length) DVDClose(&info);	}
	bool		exists()							{ return info.length;	}
	streamptr	length()							{ return info.length;	}
	streamptr	tell()								{ return current;		}
	bool		canseek()							{ return true;	}
	void		seek(streamptr offset)				{ current = offset; }
	void		seek_cur(streamptr offset)			{ current += offset; }
	void		seek_end(streamptr offset)			{ current = info.length + offset; }
//	void		seek(streamptr offset, int origin)	{ current = stream_seek(offset, origin, current, info.length); }

	int			readbuff(void *buffer, size_t size) {
		size			= min(size, info.length - current);
		size_t	total	= size;
		while (size) {
			streamptr	offset = current - buffer_start;
			if (offset < 0 || offset >= 2048) {
				buffer_start	= current & ~2047;
				offset			= current - buffer_start;
				if (buffer_start < info.length) {
					size_t	size2	= min(2048, info.length - buffer_start);
					DVDRead(&info, buffer_space, size2 & ~31, buffer_start);
					if (size2 & 31) {
						DVDRead(&info, buffer_space + 2048 - 32, 32, (info.length - 32 + 3) & ~3);
						memcpy(buffer_space + (size2 & ~31), buffer_space + 2048 - ((info.length + 3) & 28), size2 & 31);
					}
				}
			}
			size_t	size2 = min(size_t(2048 - offset), size);
			if ((uint32(buffer) & 0xc0000000) == OS_BASE_UNCACHED) {
				ISO_ASSERT(((uint32(buffer) | uint32(offset) | size2) & 3) == 0);
				for (uint32 *d = (uint32*)buffer, *s = (uint32*)(buffer_space + int(offset)), *e = d + size2 / 4; d < e; *d++ = *s++);
			} else {
				memcpy(buffer, buffer_space + int(offset), size2);
			}

			current	+= size2;
			buffer	= (char*)buffer + size2;
			size	-= size2;
		}
		return total;
	}
};

#else

class file {
protected:
	mutable FILE *h;
public:
	file() : h(0)												{}
	file(FILE *_h) : h(_h)										{}
	file(int fd, const char *mode) : h(0)						{ open(fd, mode); }
	file(const char *filename,const char *mode) : h(0)			{ open(filename, mode); }
	~file()														{ close(); }

	bool		close()											{ FILE *t = h; h = 0; return t && fclose(t) == 0; }
	bool		open(int fd, const char *mode)					{ close(); return !!(h = _fdopen(fd, mode)); }
	bool		open(const char *filename, const char *mode)	{ close(); return filename && (h = fopen(filename, mode)); }
	bool		open(FILE *_h)									{ close(); return !!(h = _h);			}

	bool		exists()										{ return h != 0;						}
	bool		eof()											{ return !!feof(h);						}
//	bool		eof()											{ return !!_eof(fileno(h));				}
	bool		canseek()										{ return true;	}

#if defined(PLAT_PC) || defined(PLAT_X360)
	void		_seek(streamptr offset, int origin)				{ if (h) _fseeki64(h, offset, origin);	}
	streamptr	tell()											{ return h ? _ftelli64(h) : 0;			}
#elif defined(PLAT_MAC) || defined(PLAT_IOS)
	void		_seek(streamptr offset, int origin)				{ if (h) fseeko(h, offset, origin);		}
	streamptr	tell()											{ return h ? ftello(h) : 0;				}
#else
	void		_seek(streamptr offset, int origin)				{ if (h) fseek(h, offset, origin);		}
	streamptr	tell()											{ return h ? ftell(h) : 0;				}
#endif
	streamptr	length()										{ return stream_length(this);			}

	void		seek(streamptr offset)							{ _seek(offset, SEEK_SET); }
	void		seek_cur(streamptr offset)						{ _seek(offset, SEEK_CUR); }
	void		seek_end(streamptr offset)						{ _seek(offset, SEEK_END); }

#if defined(PLAT_PC) || defined(PLAT_X360)
	bool		lock(bool lock = true, bool wait = false) const	{
		if (!h)
			return false;
		return true;
/*
		HANDLE h = (HANDLE)_get_osfhandle(fileno(this->h));
		OVERLAPPED offset =	{0, 0, 0, 0, NULL};
		return lock
			? !!LockFileEx(h, LOCKFILE_EXCLUSIVE_LOCK + (wait ? 0 : LOCKFILE_FAIL_IMMEDIATELY), 0, 1, 0, &offset)
			: !!UnlockFileEx(h, 0, 1, 0, &offset);
*/
	}
#elif 0//defined(PLAT_MAC) || defined(PLAT_IOS)
	bool		lock(bool lock = true, bool wait = false) const	{ return h && flock(fileno(h), (lock ? LOCK_EX : LOCK_UN) | (wait ? 0 : LOCK_NB)) == 0; }
#else
	bool		lock(bool lock = true, bool wait = false) const	{ return true; }
#endif
};

#ifdef PLAT_PC
#define HAS_DUP
#endif

class filereader : public file {
public:
	filereader()												{}
	filereader(const char *filename)	: file(filename, "rb")	{}
	filereader(FILE *_h)				: file(_h)				{}
	bool		open(int fd)									{ return file::open(fd, "rb"); }
	bool		open(const char *filename)						{ return file::open(filename, "rb"); }
	bool		open(FILE *_h)									{ return file::open(_h); }
	int			readbuff(void *buffer, size_t size)				{ return exists() ? (int)fread(buffer, 1, size, h) : 0; }
	int			getc()											{ return exists() ? fgetc(h) : EOF; }
#ifdef HAS_DUP
	FILE		*_clone() const									{ return fdopen(_dup(_fileno(h)), "rb"); }
#else
	FILE		*_clone() const									{ return 0; }
#endif
};

class filewriter : public file {
public:
	filewriter()												{}
	filewriter(const char *filename)	: file(filename, "wb")	{ if (!lock()) close(); }
	filewriter(FILE *_h)				: file(_h)				{}
	bool		open(int fd)									{ return file::open(fd, "wb"); }
	bool		open(const char *filename)						{ return file::open(filename, "wb"); }
	bool		open(FILE *_h)									{ return file::open(_h); }
	int			writebuff(const void *buffer, size_t size)		{ ISO_ASSERT(buffer); return buffer && exists() ? (int)fwrite(buffer, 1, size, h): 0;	}
	int			putc(int c)										{ return exists() ? fputc(c, h) : EOF; }
#ifdef HAS_DUP
	FILE		*_clone() const									{ return fdopen(_dup(_fileno(h)), "wb"); }
#else
	FILE		*_clone() const									{ return 0; }
#endif
};

class fileappender : public file {
public:
	fileappender()												{}
	fileappender(const char *filename)	: file(filename, "ab")	{ if (!lock()) close(); }
	fileappender(FILE *_h)				: file(_h)				{}
	bool		open(int fd)									{ return file::open(fd, "ab"); }
	bool		open(const char *filename)						{ return file::open(filename, "ab"); }
	bool		open(FILE *_h)									{ return file::open(_h); }
	int			writebuff(const void *buffer, size_t size)		{ ISO_ASSERT(buffer); return buffer && exists() ? (int)fwrite(buffer, 1, size, h): 0;	}
	int			putc(int c)										{ return exists() ? fputc(c, h) : EOF; }
#ifdef HAS_DUP
	FILE		*_clone() const									{ return fdopen(_dup(_fileno(h)), "ab"); }
#else
	FILE		*_clone() const									{ return 0; }
#endif
};

#endif

//-----------------------------------------------------------------------------
//	generic reader/writer adapters
//-----------------------------------------------------------------------------

template<typename T> struct common_ref {
	T	&t;
	common_ref(T &_t)	: t(_t)	{}
	bool		eof()						{ return t.eof(); }
	bool		exists()					{ return t.exists(); }
	bool		canseek()					{ return t.canseek(); }
	void		seek(streamptr offset)		{ return t.seek(offset); }
	void		seek_cur(streamptr offset)	{ return t.seek_cur(offset); }
	void		seek_end(streamptr offset)	{ return t.seek_end(offset); }
	streamptr	tell()						{ return t.tell();	}
	streamptr	length()					{ return t.length(); }
	T&			_clone()					{ return t._clone(); }
};

template<typename T> struct reader_ref : common_ref<T> {
	using common_ref<T>::t;
	reader_ref(T &_t)	: common_ref<T>(_t)	{}
	int			getc()										{ return t.getc(); }
	int			readbuff(void *buffer, size_t size)			{ return t.readbuff(buffer, size); }
};
template<typename T> struct writer_ref : common_ref<T> {
	using common_ref<T>::t;
	writer_ref(T &_t)	: common_ref<T>(_t)	{}
	int			putc(int c)									{ return t.putc(c); }
	int			writebuff(const void *buffer, size_t size)	{ return t.writebuff(buffer, size); }
};

template<typename T> struct common_ptr {
	T	*t;
	common_ptr(T *_t)	: t(_t)	{}
	~common_ptr()							{ delete t; }
	bool		eof()						{ return t->eof(); }
	bool		exists()					{ return t->exists(); }
	bool		canseek()					{ return t->canseek(); }
	void		seek(streamptr offset)		{ return t->seek(offset); }
	void		seek_cur(streamptr offset)	{ return t->seek_cur(offset); }
	void		seek_end(streamptr offset)	{ return t->seek_end(offset); }
	streamptr	tell()						{ return t->tell();	}
	streamptr	length()					{ return t->length(); }
	T*			_clone()					{ return new T(t->_clone()); }
};

template<typename T> struct reader_ptr : common_ptr<T> {
	using common_ptr<T>::t;
	reader_ptr(T *_t)	: common_ptr<T>(_t)	{}
	int			getc()										{ return t->getc(); }
	int			readbuff(void *buffer, size_t size)			{ return t->readbuff(buffer, size); }
};
template<typename T> struct writer_ptr : common_ptr<T> {
	using common_ptr<T>::t;
	writer_ptr(T *_t)	: common_ptr<T>(_t)	{}
	int			putc(int c)									{ return t->putc(c); }
	int			writebuff(const void *buffer, size_t size)	{ return t->writebuff(buffer, size); }
};


template<typename T> class reader_offset : public reader_mixin0<reader_offset<T> >, public reader_ref<T> {
	using reader_ref<T>::t;
	streamptr	offset, end;
public:
	reader_offset(T &_t, streamptr _offset, streamptr _end) : reader_ref<T>(_t), offset(_offset), end(_end ? _end : _t.length() - offset) {}
	reader_offset(T &_t, streamptr _end = 0)				: reader_ref<T>(_t), offset(_t.tell()), end(_end ? _end : _t.length() - offset) {}
	int			readbuff(void *buffer, size_t size) {
		streamptr p = tell();
		if (p + size > end)
			size = size_t(end - p);
		return t.readbuff(buffer, size);
	}
	int				getc()						{ return tell() < end ? t.getc() : EOF; }
	void			seek(streamptr offset)		{ t.seek(offset + this->offset); }
	void			seek_end(streamptr offset)	{ t.seek(offset + this->end); }
	streamptr		tell()						{ return t.tell() - offset;	}
	streamptr		length()					{ return end;	}
	reader_offset	_clone()					{ return reader_offset(t._clone(), offset, end); }
};
template<typename T> reader_offset<T> make_reader_offset(T &t, streamptr offset, streamptr end) {
	return reader_offset<T>(t, offset, end);
}
template<typename T> reader_offset<T> make_reader_offset(T &t, streamptr end = 0) {
	return reader_offset<T>(t, end);
}

template<typename T> class writer_offset : public writer_mixin0<writer_offset<T> >, public writer_ref<T> {
	using writer_ref<T>::t;
	streamptr	offset;
public:
	writer_offset(T &_t) : writer_ref<T>(_t)	{ offset = _t.tell(); }
	void		seek(streamptr offset)			{ t.seek(offset + this->offset); }
	streamptr	tell()							{ return t.tell() - offset;	}
	streamptr	length()						{ return t.length() - offset;	}
};

template<typename T> writer_offset<T> make_writer_offset(T &t) {
	return writer_offset<T>(t);
}

template<typename T> class interleaved_reader : public reader_mixin0<interleaved_reader<T> >, public reader_ref<T> {
	using reader_ref<T>::t;
	streamptr 	block, offset, stride;
	streamptr	filepos;
public:
	interleaved_reader(T &_t, streamptr _block, streamptr _offset, streamptr _stride) : reader_ref<T>(_t), block(_block), offset(_offset), stride(_stride), filepos(0) {}
	int			readbuff(void *buffer, size_t size) {
		int 	total = 0;
		while (size) {
			streamptr	sector			= filepos / block;
			streamptr	sector_offset	= filepos - sector * block;

			t.seek(sector * stride + offset + sector_offset);
			size_t	read			= size < block - sector_offset ? size : size_t(block - sector_offset);
			int		read_actual		= t.readbuff(buffer, read);

			size	-= read_actual;
			buffer	=  (char*)buffer + read_actual;
			filepos	+= read_actual;
			total	+= read_actual;

			if (read != read_actual)
				break;
		}
		return total;
	}
	void		seek(streamptr offset)				{ filepos = offset; }
	void		seek_cur(streamptr offset)			{ filepos += offset; }
	void		seek_end(streamptr offset)			{ filepos = length() + offset; }
	streamptr	tell()								{ return filepos;	}
	streamptr	length()							{ streamptr len = t.length() - offset; return len / stride * block + min(len % stride, block); }
	interleaved_reader	_clone()					{ return interleaved_reader(t._clone(), block, offset, stride); }
};

template<typename T> interleaved_reader<T> make_interleaved_reader(T &t, streamptr block, streamptr offset, streamptr stride) {
	return interleaved_reader<T>(t, block, offset, stride);
}

template<typename T0, typename T1> class combined_reader : public reader_mixin<combined_reader<T0, T1> > {
	T0			&t0;
	T1			&t1;
	streamptr	length0;
	streamptr	filepos;
public:
	combined_reader(T0 &_t0, T1 &_t1) : t0(_t0), t1(_t1), length0(_t0.length()), filepos(0) {}
	int			readbuff(void *buffer, size_t size) {
		int	result0 = 0;
		if (filepos < length0) {
			result0		= t0.readbuff(buffer, min(size, length0 - filepos));
			filepos		+= result0;

			if (filepos < length0)
				return result0;

			buffer = (char*)buffer + result0;
			size	-= result0;
			t1.seek(0);
		}

		int	result1 = t1.readbuff(buffer, size);
		filepos += result1;
		return result0 + result1;
	}
	void		seek(streamptr offset) {
		filepos = offset;
		if (filepos < length0)
			t0.seek(filepos);
		else
			t1.seek(filepos - length0);
	}
	void		seek_cur(streamptr offset)	{ seek(filepos + offset); }
	void		seek_end(streamptr offset)	{ seek(length() + offset); }
	streamptr	tell()						{ return filepos; }
	streamptr	length()					{ return length0 + t1.length(); }
};

template<typename T0, typename T1> combined_reader<T0, T1> make_combined_reader(T0 &t0, T1 &t1) {
	return combined_reader<T0, T1>(t0, t1);
}
//-----------------------------------------------------------------------------
//	nullwriter
//-----------------------------------------------------------------------------

class null_writer : writer_mixin<null_writer> {
	streamptr	p, end;
public:
	null_writer()											{ p = end = 0;}
	void		seek(streamptr offset)						{ p = offset; }
	void		seek_cur(streamptr offset)					{ p += offset; }
	void		seek_end(streamptr offset)					{ p = end + offset; }
	streamptr	tell()										{ return p;	}
	int			putc(int c)									{ if (++p > end) end = p; return c & 0xff;}
	int			writebuff(const void *buffer, size_t size)	{ if ((p += (int)size) > end) end = p; return (int)size;}
};

//-----------------------------------------------------------------------------
//	byte_reader/byte_writer
//-----------------------------------------------------------------------------

struct byte_reader : reader_mixin<byte_reader> {
	const uint8	*p;
	byte_reader() : p(0)								{}
	byte_reader(const void *_p) : p((uint8*)_p)			{}
	void		operator=(const void *_p)				{ p = (uint8*)_p; }
	void		set_buffer(const void *_p)				{ p = (uint8*)_p; }
	const_memory_block peek_block(size_t size)	const	{ return const_memory_block(p, size); }
	int			peekc()							const	{ return *p; }
	int			readbuff(void *buffer, size_t size)		{ memcpy(buffer, p, size); p += size; return int(size); }
	int			getc()									{ return *p++; }
	void		skip(int64 size)						{ p += size; }

	struct _get_ptr {
		byte_reader	&b;
		size_t		n;
		_get_ptr(byte_reader &_b, size_t _n) : b(_b), n(_n)	{}
		template<typename T> operator const T*() const		{ return b.get_ptr<T>(n); }
	};
	template<typename T> const T*	get_ptr(size_t n = 1)	{ const T *t = (const T*)p; p = (const uint8*)(t + n); return t; }
	_get_ptr						get_ptr(size_t n = 1)	{ return _get_ptr(*this, n); }
	const_memory_block				get_block(size_t n)		{ p += n; return const_memory_block(p - n, n); }
};

struct byte_writer : writer_mixin<byte_writer> {
	uint8	*p;
	byte_writer() : p(0)								{}
	byte_writer(void *_p) : p((uint8*)_p)				{}
	void	operator=(void *_p)							{ p = (uint8*)_p; }
	void	set_buffer(void *_p)						{ p = (uint8*)_p; }
	int		writebuff(const void *buffer, size_t size)	{ memcpy(p, buffer, size); p += size; return int(size); }
	int		putc(int c)									{ return *p++ = c; }

	struct _get_ptr {
		byte_writer	&b;
		size_t		n;
		_get_ptr(byte_writer &_b, size_t _n) : b(_b), n(_n)	{}
		template<typename T> operator T*() const			{ return b.get_ptr<T>(n); }
	};
	template<typename T> T*			get_ptr(size_t n = 1)	{ T *t = (T*)p; p = (uint8*)(t + n); return t; }
	_get_ptr						get_ptr(size_t n = 1)	{ return _get_ptr(*this, n); }
	memory_block					get_block(size_t n)		{ p += n; return memory_block(p - n, n); }
};

//-----------------------------------------------------------------------------
//	memory_reader/memory_writer
//-----------------------------------------------------------------------------

class memory_reader_owner;
class memory_reader : public reader_mixin<memory_reader> {
protected:
	const_memory_block	b;
	const uint8			*p;
	struct _get_ptr {
		memory_reader	&b;
		size_t			n;
		_get_ptr(memory_reader &_b, size_t _n) : b(_b), n(_n)	{}
		template<typename T> operator const T*() const			{ return b.get_ptr<T>(n); }
	};
public:
	memory_reader(const const_memory_block &_b) : b(_b), p(_b) {}
	size_t				remaining()				const	{ return (const uint8*)b.end() - p; }
	const_memory_block	peek_block(size_t size)	const	{ return const_memory_block(p, min(size, remaining())); }
	int					peekc()					const	{ return *p; }
	const_memory_block	get_block(size_t size)			{ size = min(size, remaining()); p += size; return const_memory_block(p - size, size); }

	bool			eof()						const	{ return p == b.end(); }
	streamptr		tell()						const	{ return p - (uint8*)b.start; }
	streamptr		length()					const	{ return b.length(); }
	bool			canseek()					const	{ return true; }
	void			seek(streamptr offset)				{ p = (const uint8*)b.start + min(offset, b.size); }
	void			seek_cur(streamptr offset)			{ p += offset; }
	void			seek_end(streamptr offset)			{ p = (const uint8*)b.end() + offset; }
	int				getc()								{ return eof() ? EOF : *p++; }
	int				readbuff(void *buffer, size_t size) { size = min(size, remaining()); memcpy(buffer, p, size); p += size; return int(size); }

	const void*		get_data(size_t at)			const	{ return b + at; }
	const void*		getp()						const	{ return p; }
	template<typename T> const T*	get_ptr(size_t n = 1)	{ const T *t = (const T*)p; p = (const uint8*)(t + n); return t; }
	_get_ptr						get_ptr(size_t n = 1)	{ return _get_ptr(*this, n); }

	struct _with_len {
		memory_reader		&r;
		const_memory_block	b;
		_with_len(memory_reader &_r, uint32 len) : r(_r), b(_r.b) {
			r.b		= r.b.sub_block_to(r.tell() + len);
		}
		~_with_len() {
			r.b		= b;
		}
	};
	_with_len	with_len(uint32 len) {
		return _with_len(*this, len);
	}
};

class memory_reader_owner : public memory_reader {
public:
	memory_reader_owner(const const_memory_block &_b) : memory_reader(keep(malloc_block(_b))) {}
	~memory_reader_owner()							{ free(unconst((const void*)b)); }
	const const_memory_block&	_clone()	const	{ return b; }
};

class memory_writer : public writer_mixin<memory_writer> {
protected:
	memory_block	b;
	uint8			*p;
	struct _get_ptr {
		memory_writer	&b;
		size_t			n;
		_get_ptr(memory_writer &_b, size_t _n) : b(_b), n(_n) {}
		template<typename T> operator T*() const { return b.get_ptr<T>(n); }
	};
public:
	memory_writer(const memory_block &_b) : b(_b), p(_b) {}
	size_t			remaining()		const				{ return (uint8*)b.end() - p; }
	memory_block	get_block(size_t size)				{ size = min(size, remaining()); p += size; return memory_block(p - size, size); }

	bool			eof()			const				{ return p == b.end(); }
	streamptr		tell()			const				{ return p - (uint8*)b.start; }
	streamptr		length()		const				{ return b.length(); }
	bool			canseek()		const				{ return true; }
	void			seek(streamptr offset)				{ p = (uint8*)b.start + min(offset, b.size); }
	void			seek_cur(streamptr offset)			{ p += offset; }
	void			seek_end(streamptr offset)			{ p = (uint8*)b.end() + offset; }
	int				putc(int c)							{ return eof() ?  EOF : (*p++ = c & 0xff); }
	int				writebuff(const void *buffer, size_t size) { size = min(size, remaining()); memcpy(p, buffer, size); p += size; return int(size); }

	void*					get_data(size_t at) const	{ return b + at; }
	void*					getp()				const	{ return p; }
	template<typename T> T*	get_ptr(size_t n = 1)		{ T *t = (T*)p; p = (uint8*)(t + n); return t; }
	_get_ptr				get_ptr(size_t n = 1)		{ return _get_ptr(*this, n); }

	operator void*()							const	{ return b; }
	operator const_memory_block()				const	{ return const_memory_block(b, tell()); }
};

class dynamic_memory_writer : public writer_mixin<dynamic_memory_writer> {
protected:
	malloc_block	b;
	size_t			p, e;
	struct _get_ptr {
		dynamic_memory_writer	&b;
		size_t					n;
		_get_ptr(dynamic_memory_writer &_b, size_t _n) : b(_b), n(_n) {}
		template<typename T> operator T*() const { return b.get_ptr<T>(n); }
	};
public:
	size_t		alloc_offset(size_t n) {
		size_t	p0	= p;
		p			= p0 + n;
		if (p > b.length())
			b.resize(p * 2);
		if (p > e)
			e = p;
		return p0;
	}
	void*	alloc(size_t n) {
		return b + alloc_offset(n);
	}

	dynamic_memory_writer() : p(0), e(0)					{}
	streamptr	tell()								const	{ return p; }
	streamptr	length()							const	{ return e; }
	void		seek(streamptr offset)						{ p = offset; }
	void		seek_cur(streamptr offset)					{ p += offset; }
	void		seek_end(streamptr offset)					{ p = e + offset; }
	int			putc(int c)									{ return (*(uint8*)alloc(1) = c) & 0xff; }
	int			writebuff(const void *buffer, size_t size)	{ memcpy(alloc(size), buffer, size); return int(size); }

	dynamic_memory_writer			_clone()		const	{ return *this; }
	void*							get_data(size_t at) const { return b + at; }
	void*							getp()			const	{ return get_data(p); }
	template<typename T> T*			get_ptr(size_t n = 1)	{ return (T*)alloc(sizeof(T) * n); }
	_get_ptr						get_ptr(size_t n = 1)	{ return _get_ptr(*this, n); }
	memory_block					get_block(size_t size)	{ return memory_block(alloc(size), size); }

	operator void*()								const	{ return b; }
	operator const_memory_block()					const	{ return const_memory_block(b, e); }
	operator malloc_block&&()								{ b.size = min(b.size, e); return move(b); }
};


//-----------------------------------------------------------------------------
//	istream/ostream - virtualised reader/writers
//-----------------------------------------------------------------------------

struct istream : reader_mixin<istream> {
	virtual				~istream()									{}
	virtual bool		eof()										{ return false; }
	virtual bool		exists()									{ return true;	}
	virtual bool		canseek()									{ return true;	}
	virtual streamptr	tell()										{ return -1;	}
	virtual streamptr	length()									{ return stream_length(this); }
	virtual void		seek(streamptr offset)						{}
	virtual void		seek_cur(streamptr offset)					{}
	virtual void		seek_end(streamptr offset)					{}
	virtual int			getc()										{ uint8 c; return readbuff(&c, 1) ? c : EOF; }
	virtual int			readbuff(void *buffer, size_t size)			{ char *p = (char*)buffer; int i, c; for (i = 0; i < (int)size && (c = getc()) != EOF; *p++ = c, i++) {} return i; }
	virtual istream*	clone()										{ return 0; }
	void				align(int a)								{ seek((tell() + a - 1) / a * a);	}
	uint32				tell32()									{ return uint32(tell()); }
	uint32				length32()									{ return uint32(length()); }
};

struct ostream : writer_mixin<ostream> {
	virtual				~ostream()									{}
	virtual bool		eof()										{ return false; }
	virtual bool		exists()									{ return true;	}
	virtual bool		canseek()									{ return true;	}
	virtual streamptr	tell()										{ return -1;	}
	virtual streamptr	length()									{ return stream_length(this); }
	virtual void		seek(streamptr offset)						{}
	virtual void		seek_cur(streamptr offset)					{}
	virtual void		seek_end(streamptr offset)					{}
	virtual int			putc(int c)									{ uint8 v = c; return writebuff(&v, 1) ? v : EOF; }
	virtual int			writebuff(const void *buffer, size_t size)	{ char *p = (char*)buffer; int i; for (i = 0; i < (int)size && putc(*p++) != EOF; i++) {} return i; }
	virtual ostream*	clone()										{ return 0; }
	void				align(int a, char pad = 0x55)				{ while (tell() % a) putc(pad);	}
	uint32				tell32()									{ return uint32(tell()); }
	uint32				length32()									{ return uint32(length()); }
};

//-----------------------------------------------------------------------------
//	virtualising wrappers
//-----------------------------------------------------------------------------

template<typename S> struct istream_mixout : istream, S {
	istream_mixout()												{}
	template<typename...PP> istream_mixout(PP&&...pp) : S(forward<PP>(pp)...)	{}
	virtual bool		eof()										{ return S::eof(); }
	virtual bool		exists()									{ return S::exists(); }
	virtual bool		canseek()									{ return S::canseek(); }
	virtual void		seek(streamptr offset)						{ return S::seek(offset); }
	virtual void		seek_cur(streamptr offset)					{ return S::seek_cur(offset); }
	virtual void		seek_end(streamptr offset)					{ return S::seek_end(offset); }
	virtual streamptr	tell()										{ return S::tell(); }
	virtual streamptr	length()									{ return S::length(); }
	virtual int			getc()										{ return S::getc(); }
	virtual int			readbuff(void *buffer, size_t size)			{ return S::readbuff(buffer, size); }
	virtual istream*	clone()										{ return new istream_mixout<S>(S::_clone()); }

	istream_mixout&				me()								{ return *this; }
	template<typename T>bool	read(T &t)							{ return static_read(me(), t);	}
	template<typename T>T		get()								{ T t; read(t); return t;		}
	getter<istream_mixout>		get()								{ return *this;	}
};

template<typename S> struct ostream_mixout : ostream, S {
	ostream_mixout()												{}
	template<typename...PP> ostream_mixout(PP&&...pp) : S(forward<PP>(pp)...)	{}
	virtual bool		eof()										{ return S::eof(); }
	virtual bool		exists()									{ return S::exists(); }
	virtual bool		canseek()									{ return S::canseek(); }
	virtual void		seek(streamptr offset)						{ return S::seek(offset); }
	virtual void		seek_cur(streamptr offset)					{ return S::seek_cur(offset); }
	virtual void		seek_end(streamptr offset)					{ return S::seek_end(offset); }
	virtual streamptr	tell()										{ return S::tell(); }
	virtual streamptr	length()									{ return S::length(); }
	virtual int			putc(int c)									{ return S::putc(c); }
	virtual int			writebuff(const void *buffer, size_t size)	{ return S::writebuff(buffer, size); }
	virtual ostream*	clone()										{ return new ostream_mixout<S>(S::_clone()); }

	ostream_mixout&				me()								{ return *this;	}
	template<typename T>bool	write(const T &t)					{ return static_write(me(), t); }
	template<int N>		bool	write(const char (&s)[N])			{ return S::writebuff(s, N - 1) == N - 1; }
};

template<class T> struct reader_to_istream : istream, reference<T> {
	reader_to_istream(T &_t) : reference<T>(_t)					{}
	bool		eof()											{ return this->t.eof(); }
	bool		exists()										{ return this->t.exists(); }
	bool		canseek()										{ return this->t.canseek(); }
	void		seek(streamptr offset)							{ return this->t.seek(offset); }
	void		seek_cur(streamptr offset)						{ return this->t.seek_cur(offset); }
	void		seek_end(streamptr offset)						{ return this->t.seek_end(offset); }
	streamptr	tell()											{ return this->t.tell(); }
	streamptr	length()										{ return this->t.length(); }
	int			getc()											{ return this->t.getc(); }
	int			readbuff(void *buffer, size_t size)				{ return this->t.readbuff(buffer, size); }
	istream*	clone()											{ return new istream_mixout<T>(this->t._clone()); }
};
template<typename S> reader_to_istream<S> make_istream(S &s)	{ return s; }

template<class T> struct writer_to_ostream : ostream, reference<T> {
	writer_to_ostream(T &_t) : reference<T>(_t)					{}
	bool		eof()											{ return this->t.eof(); }
	bool		exists()										{ return this->t.exists(); }
	bool		canseek()										{ return this->t.canseek(); }
	void		seek(streamptr offset)							{ return this->t.seek(offset); }
	void		seek_cur(streamptr offset)						{ return this->t.seek_cur(offset); }
	void		seek_end(streamptr offset)						{ return this->t.seek_end(offset); }
	streamptr	tell()											{ return this->t.tell(); }
	streamptr	length()										{ return this->t.length(); }
	int			putc(int c)										{ return this->t.putc(c); }
	int			writebuff(const void *buffer, size_t size)		{ return this->t.writebuff(buffer, size); }
	ostream*	clone()											{ return new ostream_mixout<T>(this->t._clone()); }
};
template<typename S> writer_to_ostream<S> make_ostream(S &s)	{ return s; }

typedef ostream_mixout<null_writer>				NullStream;
typedef istream_mixout<filereader>				FileInput;
typedef ostream_mixout<filewriter>				FileOutput;
typedef ostream_mixout<fileappender>			FileAppend;
typedef istream_mixout<memory_reader>			MemoryInput;
typedef ostream_mixout<memory_writer>			MemoryOutput;
typedef ostream_mixout<dynamic_memory_writer>	MemoryOutput2;

typedef istream_mixout<reader_ptr<istream> >				istream_ptr;
typedef ostream_mixout<writer_ptr<ostream> >				ostream_ptr;
typedef istream_mixout<reader_ref<istream> >				istream_chain;
typedef ostream_mixout<writer_ref<ostream> >				ostream_chain;
typedef istream_mixout<reader_offset<istream> >				istream_offset;
typedef ostream_mixout<writer_offset<ostream> >				ostream_offset;
typedef istream_mixout<interleaved_reader<istream> >		interleaved_istream;
typedef istream_mixout<combined_reader<istream, istream> >	combined_istream;

template<int N> using buffered_istream = istream_mixout<buffered_reader<reader_ref<istream>, N> >;

//-----------------------------------------------------------------------------
//	helpers
//-----------------------------------------------------------------------------

struct memlink : malloc_block {
	memlink		*next;
	memlink(size_t n)			: malloc_block(n), next(0)	{}
	memlink(void *p, size_t n)	: malloc_block(n), next(0)	{ memcpy(start, p, size); }
};
struct memchain {
	struct iterator {
		memlink	*p;
		iterator(memlink *_p) : p(_p)	{}
		iterator& operator++()			{ p = p->next; return *this; }
		operator memlink*()		const	{ return p;	}
		memlink	*operator->()	const	{ return p;	}
	};

	memlink		*first, *last;
	memchain() : first(0), last(0) {}
	~memchain() {
		for (memlink *p = first, *n; p; p = n) {
			n = p->next;
			delete p;
		}
	}
	void		push_back(memlink *link) {
		(first ? last->next : first) = link;
		last = link;
	}
	iterator	begin()	const	{ return first;			}
	iterator	end()	const	{ return (memlink*)0;	}

	size_t		total()	const	{
		size_t	t = 0;
		for (iterator i = begin(); i != end(); ++i)
			t += i->size;
		return t;
	}

	void		flatten(void *dest) const {
		for (iterator i = begin(); i != end(); ++i) {
			memcpy(dest, *i, i->size);
			dest = (uint8*)dest + i->size;
		}
	}
};

} //namespace iso

#endif	// STREAM_H
