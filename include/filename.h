#ifndef FILENAME_H
#define FILENAME_H

#include "base/strings.h"

namespace iso {

#if defined PLAT_X360 || defined PLAT_PC || defined PLAT_XONE
#define USE_FILENAME_WINDOWS
#define DIRECTORY_SEP	'\\'
#define DIRECTORY_ALL	"*.*"
#else
#define USE_FILENAME_UNIX
#undef _MAX_PATH
#define _MAX_PATH		260
#define _MAX_DIR		256
#define _MAX_FNAME		256
#define _MAX_EXT		256
#define DIRECTORY_SEP	'/'
#define DIRECTORY_ALL	"*"
#endif
#define _MAX_VOLUME		16

struct filetime_t {
	uint64 v;
	filetime_t()			: v(0) {}
	filetime_t(uint64 _v)	: v(_v) {}
	operator uint64() const { return v; }
#ifdef _WINDEF_	
	filetime_t(const FILETIME &_v) : v((uint64&)_v) {}
	operator FILETIME() const { return *(FILETIME*)this; }
#endif
};

iso_export bool			matches(const char *p, const char *s);
iso_export bool			exists(const char *f);
iso_export bool			is_dir(const char *f);
iso_export bool			is_file(const char *f);
iso_export bool			is_wild(const char *f);
iso_export uint64		filelength(const char *f);
iso_export filetime_t	filetime_write(const char *f);
iso_export filetime_t	filetime_create(const char *f);

iso_export bool			delete_file(const char *f);
iso_export bool			create_dir(const char *f);
iso_export bool			delete_dir(const char *f);

class filename : public fixed_string<512> {
	typedef fixed_string<512>	B;
public:
	typedef fixed_string<_MAX_VOLUME>	drive_t;
	typedef fixed_string<_MAX_EXT>		ext_t;

	filename() {}
	iso_export filename(const char *s);
	filename(const char16 *s)								: B(s)	{}
	template<typename T> filename(const string_base<T> &s)	: B(s)	{}
	template<typename T> filename(const string_getter<T> &s): B(s)	{}

	iso_export bool			is_url()					const;
	iso_export bool			is_wild()					const;
	iso_export bool			is_relative()				const;
	iso_export drive_t		drive()						const;
	iso_export filename		dir()						const;
	iso_export filename		name()						const;
	iso_export ext_t		ext()						const;
	iso_export filename		name_ext()					const;
	iso_export filename		dir_name_ext()				const;

	const char*				ext_ptr()					const	{ const char *d = rfind('.'); return d && !string_find(d, DIRECTORY_SEP) ? d : 0; }
	const char*				name_ext_ptr()				const	{ const char *d = rfind(DIRECTORY_SEP); return d ? d + 1 : p; }

	iso_export filename&	cleanup();
	iso_export filename&	rem_dir();
	iso_export filename&	rem_first();
	iso_export filename&	add_dir(const count_string &s);
	iso_export filename&	set_dir(const count_string &s);
	iso_export filename&	add_ext(const char *e);
	iso_export filename&	set_ext(const char *e);
	filename&				add_dir(const char *d)				{ if (d) add_dir(count_string(d, strlen(d))); return *this; }
	filename&				set_dir(const char *d)				{ return set_dir(count_string(d, strlen(d))); }

	iso_export filename		relative(const char *f)		const;
	iso_export bool			matches(const char *s)		const;
	iso_export bool			matched(filename &out, const char *spec0, const char *spec1) const;
	iso_export filename		matched(const char *spec0, const char *spec1) const;
	iso_export filename		relative_to(const char *f)	const;
	filename				absolute(const char *f)		const	{ return filename(f).relative(*this); }
	filename				convert_to_backslash()		const	{ filename r; replace(r.begin(), begin(), "/", "\\"); return r; }
	filename				convert_to_fwdslash()		const	{ filename r; replace(r.begin(), begin(), "\\", "/"); return r; }
	bool					exists()					const	{ return iso::exists(*this); }
};

iso_export filename		get_cwd();
iso_export bool			set_cwd(const filename &f);
iso_export filename		get_exec_path();
iso_export filename		get_exec_dir();

class push_cwd {
	filename prev;
public:
	push_cwd(const char *dir)	{ prev = get_cwd(); set_cwd(dir); }
	~push_cwd()					{ set_cwd(prev); }
};

struct _cwd {
	bool	operator=(const char *dir)	{ return set_cwd(dir); }
	operator filename() const			{ return get_cwd(); }
};
extern _cwd cwd;

#ifdef PLAT_PC
HMODULE load_library(const char *name, const char *env, const char *dir);
#endif

}//namespace iso

#endif//FILENAME_H
