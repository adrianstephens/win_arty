#include <excpt.h>
#include <windows.h>
#include "base/defs.h"
#include "base/pointer.h"
#include "base/strings.h"

#if defined _MSC_VER && _MSC_VER >= 1900
#include "stdio.h"
#pragma comment(lib, "legacy_stdio_definitions")
//extern "C" FILE * __cdecl __iob_func(void) {
//	static FILE _iob[] = { *stdin, *stdout, *stderr };
//	return _iob;
//}
#endif

namespace iso {
	void __iso_debug_print(const char *s)				{ OutputDebugStringA(s); }
	iso_export void _iso_dump_heap(uint32 flags)		{ _CrtCheckMemory();	}
	iso_export void _iso_debug_break()					{ __debugbreak();		}

	HINSTANCE	hinst	= GetLocalInstance();
	void		SetDefaultInstance(HINSTANCE h)	{ hinst = h;			}
	HINSTANCE	GetDefaultInstance()			{ return hinst;			}
	HINSTANCE	GetInstance(HINSTANCE h)		{ return h ? h : hinst; }

	static inline size_t adjust_size(size_t size, size_t align) {
		return size ? size + 8 + max(align, 8) - 1 : 0;
	}
	static inline void	*get_alloc_block(void *p) {
		return ((void**)p)[-1];
	}
	static inline void	*get_aligned_block(void *p, size_t align) {
		if (p) {
			size_t	mask	= max(align, 8) - 1;
			void	**p2 = (void**)(((uintptr_t)p + 8 + mask) & ~mask);
			p2[-1]	= p;
			p		= p2;
		}
		return p;
	}

	struct HeapValidator {
#if 0
		HANDLE h;
		HeapValidator(HANDLE _h = GetProcessHeap()) : h(_h)	{ ISO_ASSERT(HeapValidate(h, 0, 0)); }
		~HeapValidator()					{ ISO_ASSERT(HeapValidate(h, 0, 0)); }
#else
		HeapValidator()				{}
		HeapValidator(HANDLE _h)	{}
#endif
	};

	void	aligned_free(void *p) {
		HeapValidator	validator;
		if (p)
			HeapFree(GetProcessHeap(), 0, get_alloc_block(p));
	}

	__declspec(allocator) void*	aligned_alloc(size_t size, size_t align) {
		return size ? get_aligned_block(HeapAlloc(GetProcessHeap(), 0, adjust_size(size, align)), align) : 0;
	}

	void*	aligned_realloc(void *p, size_t size, size_t align) {
		HeapValidator	validator;
		if (!p) {
			p = HeapAlloc(GetProcessHeap(), 0, adjust_size(size, align));
		} else {
			void	*p0		= get_alloc_block(p);
			size_t	size0	= HeapSize(GetProcessHeap(), 0, p0);
			if ((char*)p0 + size0 >= (char*)p + size)
				return p;

			p = HeapReAlloc(GetProcessHeap(), 0, p0, adjust_size(size, align));
			if (!p) {
				HeapFree(GetProcessHeap(), 0, p0);
				return p;
			}
		}
		return get_aligned_block(p, align);
	}

	void *aligned_resize(void *p, size_t size, size_t align) {
		HeapValidator	validator;
		if (!p)
			return 0;
		void	*p0		= get_alloc_block(p);
		size_t	size0	= HeapSize(GetProcessHeap(), 0, p0);
		size_t	size1	= ((char*)p - (char*)p0) + size;
		return size0 >= size1 || HeapReAlloc(GetProcessHeap(), HEAP_REALLOC_IN_PLACE_ONLY, p0, size1) ? p : 0;
	}

	size_t to_string(char *s, const Win32Error &v)	{ 
		return FormatMessageA(
			FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			v.err,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			s, 256,
			v.args
		);
	}

	string_accum &operator<<(string_accum &sa, const Win32Error &v)	{ 
		char	*msg;
		if (FormatMessageA(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			v.err,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR)&msg, 0,
			v.args
		)) {
			sa << msg;
			LocalFree(msg);
		}
		return sa;
	}

	iso_export void com_error_handler(long hr) {
		ISO_TRACEF("FAIL with HRESULT 0x%08x: ", hr) << Win32Error(hr) << '\n';
	}

	void Win32ErrorPrint(const Win32Error &v) {
		ISO_TRACEF() << v;
	}

	void throw_hresult(HRESULT hr) {
		throw_accum(Win32Error(hr));
	}

	uint64	random_seed()	{
		FILETIME t;
		GetSystemTimeAsFileTime(&t);
		return (uint64&)t;
	}

} // iso
