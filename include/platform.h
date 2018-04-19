#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef __clang__

#pragma GCC diagnostic ignored "-Wparentheses"
#pragma GCC diagnostic ignored "-Wc++11-narrowing"
#pragma GCC diagnostic ignored "-Wswitch"
#pragma GCC diagnostic ignored "-Wunused-value"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-local-typedef"
#pragma GCC diagnostic ignored "-Wmicrosoft-template"
#pragma GCC diagnostic ignored "-Wignored-attributes"
#pragma GCC diagnostic ignored "-Wundefined-inline"
#pragma GCC diagnostic ignored "-Wint-to-void-pointer-cast"
#pragma GCC diagnostic ignored "-Wmultichar"
#pragma GCC diagnostic ignored "-Winvalid-token-paste"

//#pragma GCC diagnostic ignored "-Wnonportable-include-path"
//#pragma GCC diagnostic ignored "-Wignored-pragma-intrinsic"
//#pragma GCC diagnostic ignored "-Wpragma-pack"
//#pragma GCC diagnostic ignored "-Wexpansion-to-defined"

#define specialised(X)
#else

#pragma warning(disable:4018 4146 4180 4200 4244 4291 4307 4311 4312 4344 4345 4351 4355 4503 4800)
#define specialised(X)	X

#endif


#define ISO_PLATFORM	PC

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#define _INC_MATH
#define _CSTDLIB_
#define __D3DX9MATH_INL__
#define __XNAMATHVECTOR_INL__
#define __XNAMATHMATRIX_INL__
#define __XNAMATHMISC_INL__

#ifndef PLAT_PC
#define PLAT_PC
#endif

#ifdef _M_AMD64
#define	ISO_PTR64
#else
#define USE_STDCALL
#endif

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#endif
#ifndef _CRT_NONSTDC_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#endif

#ifdef _CPPUNWIND
#define USE_EXCEPTIONS
#endif

#ifdef _CPPRTTI
#define USE_RTTI
#endif

#if defined _MSC_VER && _MSC_VER >= 1900
#define USE_EXPLICIT_CONVERSIONS
#define USE_LAMBDAS
#define USE_RANGE_FOR
#define USE_RVALUE_REFS
#define USE_THREAD_LOCAL
#define USE_AUTO_TYPE
#define USE_STRONG_ENUMS
#define USE_VARIADIC_TEMPLATES
#endif

extern "C" {
long labs(long x);
long long llabs(long long x);
}

#if 0//ndef _CRT_ABS_DEFINED
namespace std {
	int abs(int x);
}
#define _CRT_ABS_DEFINED
#endif

#include <windows.h>
#include <crtdbg.h>
#include <string.h>
#include <stdlib.h>
#include <mmsystem.h>
#include <malloc.h>
#include <intrin.h>

#undef min
#undef max
#undef small

#define alloca				_alloca

#ifdef USE_IMPORTS
	#define iso_export		__declspec(dllimport)
	#define iso_local		__declspec(dllexport)
#elif defined(USE_EXPORTS)
	#define iso_export		__declspec(dllexport)
#else
	#define iso_export
#endif

#define __func__			__FUNCTION__
#define inline_only			__forceinline
#define iso_unaligned(T)	UNALIGNED T
#define iso_aligned(T, N)	__declspec(align(N)) T
#define prefetch(i)			(void)0
#define probably(a, b)		(b)
#define	restrict			__restrict
#define strdup				_strdup

namespace iso {
using ::abs;

extern "C" IMAGE_DOS_HEADER __ImageBase;
inline HINSTANCE		GetLocalInstance() { return reinterpret_cast<HINSTANCE>(&__ImageBase); }
iso_export void			SetDefaultInstance(HINSTANCE h);
iso_export HINSTANCE	GetDefaultInstance();
iso_export HINSTANCE	GetInstance(HINSTANCE h);


#define DEFINED_UINT128
struct uint128 {
	__m128i	m;
	uint128() {}
	uint128(const uint128 &b)	: m(b.m) {}
	uint128(__m128i _m)			: m(_m) {}
//	uint128(volatile const uint128 &b) : m(const_cast<__m128i&>(b.m))	{}
	uint128(int i)				: m(_mm_cvtsi32_si128(i))	{}
	uint128(unsigned int i)		: m(_mm_cvtsi32_si128(i))	{}
	uint128(unsigned __int64 i)	: m(_mm_loadl_epi64((__m128i*)&i)) {}
	operator __m128i() const	{ return m; }
	operator __m128i&()			{ return m; }

	void operator=(const uint128 &b) volatile { const_cast<__m128i&>(m) = b.m; }

	friend bool operator==(const uint128 &a, const uint128 &b) {
		__m128i	t = _mm_xor_si128(a.m, b.m);
		return _mm_testz_si128(t, t);
	}
	friend bool operator!=(const uint128 &a, const uint128 &b) {
		return !(a == b);
	}
	friend uint128	operator+ (const uint128 &a, const uint128 &b)	{
		__m128i	s = _mm_add_epi64(a.m, b.m);
		__m128i c = _mm_slli_si128(_mm_srli_epi64(_mm_sub_epi64(s, a.m), 63), 64 / 8);
		return _mm_add_epi64(s, c);
	}
	friend uint128	operator- (const uint128 &a, const uint128 &b)	{
		__m128i	s = _mm_sub_epi64(a.m, b.m);
		__m128i c = _mm_slli_si128(_mm_srli_epi64(_mm_sub_epi64(a.m, s), 63), 64 / 8);
		return _mm_sub_epi64(s, c);
	}
	friend uint128	operator& (const uint128 &a, const uint128 &b)	{ return _mm_and_si128(a.m, b.m); }
	friend uint128	operator| (const uint128 &a, const uint128 &b)	{ return _mm_or_si128(a.m, b.m); }
	friend uint128	operator^ (const uint128 &a, const uint128 &b)	{ return _mm_xor_si128(a.m, b.m); }
	friend uint128	operator<<(const uint128 &a, unsigned int b)	{ return _mm_xor_si128(_mm_sll_epi64(a.m, uint128(b & 63)), _mm_slli_si128(_mm_srl_epi64(a.m, uint128(64 - (b & 63))), 8)); }
	friend uint128	operator>>(const uint128 &a, unsigned int b)	{ return _mm_xor_si128(_mm_srl_epi64(a.m, uint128(b & 63)), _mm_srli_si128(_mm_sll_epi64(a.m, uint128(64 - (b & 63))), 8)); }
};

template<int N, bool mult8, bool lt64> struct shift128_s {
	inline_only static uint128	left(const uint128 &a)	{ return _mm_slli_si128(a, N >> 3); }
	inline_only static uint128	right(const uint128 &a)	{ return _mm_slli_si128(a, N >> 3); }
};
template<int N> struct shift128_s<N, false, true> {
	inline_only static uint128	left(const uint128 &a)	{ return _mm_xor_si128(_mm_slli_epi64(a, N), _mm_slli_si128(_mm_srli_epi64(a, 64 - N), 8)); }
	inline_only static uint128	right(const uint128 &a)	{ return _mm_xor_si128(_mm_srli_epi64(a, N), _mm_srli_si128(_mm_slli_epi64(a, 64 - N), 8)); }
};
template<int N> struct shift128_s<N, false, false> {
	inline_only static uint128	left(const uint128 &a)	{ return _mm_slli_epi64(_mm_slli_si128(a, N >> 3), N & 7); }
	inline_only static uint128	right(const uint128 &a)	{ return _mm_srli_epi64(_mm_srli_si128(a, N >> 3), N & 7); }
};

template<typename T, unsigned N> struct s_shift;
template<unsigned N> struct s_shift<uint128, N> : shift128_s<N, (N & 7) == 0, (N < 64)> {};

#ifdef _M_AMD64
inline_only __int64 mulc(__int64 a, __int64 b, __int64 &r) {
	__int64	h;
	r = _mul128(a, b, &h);
	return h;
}
inline_only unsigned __int64 mulc(unsigned __int64 a, unsigned __int64 b, unsigned __int64 &r) {
	unsigned __int64	h;
	r = _umul128(a, b, &h);
	return h;
}
#endif

struct Win32Error {
	DWORD	err;
	va_list	*args;
	explicit Win32Error(DWORD _err, va_list *_args = 0) : err(_err), args(_args) {}
	Win32Error(va_list *_args = 0) : err(GetLastError()), args(_args) {}
};

void Win32ErrorPrint(const Win32Error &v);
template<typename T> T	Win32ErrorCheck(const T &t,...)		{ if (!t) { va_list args; va_start(args, t); Win32ErrorPrint(&args); } return t; }
inline HINSTANCE		Win32ErrorCheck(HINSTANCE t,...)	{ if (!t) { va_list args; va_start(args, t); Win32ErrorPrint(&args); } return t; }
inline BOOL				Win32ErrorCheck(BOOL t,...)			{ if (!t) { va_list args; va_start(args, t); Win32ErrorPrint(&args); } return t; }


//-----------------------------------------------------------------------------
//	aligned allocs
//-----------------------------------------------------------------------------

void	aligned_free(void *p);
void*	aligned_alloc(size_t size, size_t align);
void*	aligned_realloc(void *p, size_t size, size_t align);
void*	aligned_resize(void *p, size_t size, size_t align);
#define aligned_alloc_unchecked		aligned_alloc
} // namespace iso

//-----------------------------------------------------------------------------
//	dll_function
//-----------------------------------------------------------------------------

template<typename F> struct dll_function {
	F		*f;
	dll_function()	: f(0)	{}
	dll_function(HMODULE dll, const char *name) : f((F*)GetProcAddress(dll, name)) {}
	operator F&()	const { return *f; }
	bool	bind(HMODULE dll, const char *name) { return !!(f = (F*)GetProcAddress(dll, name)); }

};

#endif
