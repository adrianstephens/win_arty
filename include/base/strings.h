#ifndef STRINGS_H
#define STRINGS_H

#include "functions.h"
#include "bits.h"

#ifndef RELEASE
#define ISO_TRACEF(...)	iso::trace_accum(__VA_ARGS__)
#else
#define ISO_TRACEF(...)	iso::dummy_accum()
#endif

#define ISO_ASSERTF(exp, ...)	ISO_NOT_RELEASE_STMT({ if (!(exp)) iso::_iso_assert(__FILE__, __LINE__, format_string(__VA_ARGS__)); })
#define ISO_ASSUMEF(exp, ...)	ISO_NOT_RELEASE_STMT({ if (!(exp)) iso::trace_accum(__VA_ARGS__); })
#define ISO_OUTPUTF(...)		iso::trace_accum(__VA_ARGS__)

#define throw_accum(x) iso_throw(((iso::toggle_accum&)(iso::toggle_accum() << x)).begin())

namespace iso {
using ::strlen;
using ::strcpy;

template<typename T> struct char_type {
	T	t;
	char_type()					{}
	explicit char_type(T _t) : t (_t) {}
	template<typename X> char_type& operator=(const X &x)	{ t = x; return *this; }
	operator uint32()	const	{ return t; }
};

template<typename T> struct T_swap_endian_type<char_type<T> >			{ typedef char_type<T_swap_endian<T> > type; };

typedef char_type<uint8>	char8;
typedef T_if<sizeof(wchar_t)==2, wchar_t, char16_t>::type	char16;
typedef T_if<sizeof(wchar_t)==4, wchar_t, char32_t>::type	char32;

typedef BE(char16)	char16be;
typedef LE(char16)	char16le;
typedef BE(char32)	char32be;
typedef LE(char32)	char32le;


template<typename T> struct T_ischar							: T_false {};
template<typename T> struct T_ischar<T&>						: T_ischar<T> {};
template<typename T> struct T_ischar<constructable<T> >			: T_ischar<T> {};
template<typename T> struct T_ischar<T_swap_endian_type<T> >	: T_ischar<T> {};
template<typename T> struct T_ischar<char_type<T> >				: T_true {};

template<> struct T_ischar<char>	: T_true {};
template<> struct T_ischar<char16>	: T_true {};
template<> struct T_ischar<char32>	: T_true {};

iso_export uint32	utf8_length(char c);
iso_export uint32	utf8_length_u32(uint32 c, bool strict = true);
iso_export uint32	utf8_count(const char *srce);
iso_export uint32	utf8_count(const char *srce, const char *end);
iso_export uint32	u32_to_utf8(uint32 c, char *dest, bool strict = true);
iso_export uint32	u32_from_utf8(uint32 &c, const char *srce);
iso_export uint32	legalise_utf8(const char *srce, char *dest, size_t maxlen);
iso_export size_t	_format(char *dest, const char *format, va_list valist);
iso_export size_t	_format(char *dest, const char *format, ...);
iso_export size_t	_format(char *dest, size_t maxlen, const char *format, va_list valist);
iso_export size_t	_format(char *dest, size_t maxlen, const char *format, ...);

//-----------------------------------------------------------------------------
//	constexpr
//-----------------------------------------------------------------------------

template<typename T, size_t N>				constexpr auto	make_constexpr_string(const T (&value)[N])					{ return make_constexpr_array<T, T>(value, make_index_list<N - 1>()); }
template<typename T, typename T2, size_t N> constexpr auto	make_constexpr_string(const T2 (&value)[N])					{ return make_constexpr_array<T, T2>(value, make_index_list<N - 1>()); }
template<typename T, size_t N>				constexpr auto	make_constexpr_string(const constexpr_array<T, N> &value)	{ return value; }
template<typename T, typename T2, size_t N>	constexpr auto	make_constexpr_string(const constexpr_array<T2, N> &value)	{ return make_constexpr_array<T>(value); }
template<typename T, size_t N1, size_t N2>	constexpr auto	concat(const T (&v1)[N1], const T (&v2)[N2])				{ return concat(make_constexpr_string(v1), make_constexpr_string(v2)); }

//-----------------------------------------------------------------------------
//	utf8
//-----------------------------------------------------------------------------

template<typename C> uint32	u32_to_utf8(uint32 c, const C *dest, bool strict = true) {
	*dest = C(c);
	return 1;
}
template<typename C> uint32	u32_from_utf8(uint32 &c, const C *srce) {
	c = *srce;
	return 1;
}

template<typename C> size_t utf8_length(const C *srce, bool strict = true) {
	size_t	n = 0;
	if (srce) {
		while (uint32 c = *srce++)
			n += utf8_length_u32(c, strict);
	}
	return n;
}
template<typename I> size_t utf8_length(I srce, I end, bool strict = true) {
	size_t	n = 0;
	while (srce != end)
		n += utf8_length_u32(*srce++, strict);
	return n;
}

template<typename C> size_t to_utf8(const C *srce, char *dest, size_t maxlen, bool strict = true) {
	char	*d	= dest;
	if (srce) {
		for (char *de = maxlen ? d + maxlen : (char*)~uintptr_t(0); d < de && *srce;)
			d += u32_to_utf8(*srce++, d, strict);
	}
	return d - dest;
}
template<typename I> size_t to_utf8(I srce, I end, char *dest, size_t maxlen, bool strict = true) {
	char	*d	= dest, *de = maxlen ? d + maxlen : (char*)~uintptr_t(0);
	while (d < de && srce != end)
		d += u32_to_utf8(*srce++, d, strict);
	return d - dest;
}

template<typename C> size_t from_utf8(const char *srce, C *dest, size_t maxlen) {
	C *d = dest;
	if (srce) {
		uint32	c;
		for (C *de = maxlen ? d + maxlen : (C*)~uintptr_t(0); d < de && *srce; *d++ = c)
			srce += u32_from_utf8(c, srce);
	}
	return d - dest;
}
template<typename C> size_t from_utf8(const char *srce, const char *end, C *dest, size_t maxlen) {
	C			*d	= dest, *de = maxlen ? d + maxlen : (C*)~uintptr_t(0);
	while (d < de && srce < end) {
		uint32	c;
		srce += u32_from_utf8(c, srce);
		*d++ = c;
	}
	return d - dest;
}

inline						uint32 utf8_count(const char *srce, size_t len)										{ return utf8_count(srce, srce + len);}
template<typename I>		size_t utf8_length(I srce, size_t len, bool strict = true)							{ return utf8_length(srce, srce + len, strict);}

template<typename I>		size_t to_utf8(I srce, size_t len, char *dest, size_t maxlen, bool strict = true)	{ return to_utf8(srce, srce + len, dest, maxlen, strict);}
template<typename C, int N> size_t to_utf8(const C *srce, char (&dest)[N], bool strict = true)					{ return to_utf8(srce, dest, N, strict); }
template<typename C, int N> size_t to_utf8(const C *srce, const C *end, char (&dest)[N], bool strict = true)	{ return to_utf8(srce, end, dest, N, strict); }
template<typename C, int N> size_t to_utf8(const C *srce, size_t len, char (&dest)[N], bool strict = true)		{ return to_utf8(srce, srce + len, dest, N, strict); }

template<typename C>		size_t from_utf8(const char *srce, size_t len, C *dest, size_t maxlen)				{ return from_utf8(srce, srce + len, dest, maxlen);}
template<typename C, int N> size_t from_utf8(const char *srce, C (&dest)[N])									{ return from_utf8(srce, dest, N); }
template<typename C, int N> size_t from_utf8(const char *srce, const char *end, C (&dest)[N])					{ return from_utf8(srce, end, dest, N); }
template<typename C, int N> size_t from_utf8(const char *srce, size_t len, C (&dest)[N])						{ return from_utf8(srce, srce + len, dest, N); }

//-----------------------------------------------------------------------------
//	character tests
//-----------------------------------------------------------------------------

constexpr bool	is_whitespace(char c)				{ return c > 0 && c <= ' '; }
constexpr bool	is_digit(char c)					{ return between(c, '0', '9'); }
constexpr bool	is_upper(char c)					{ return between(c, 'A', 'Z'); }
constexpr bool	is_lower(char c)					{ return between(c, 'a', 'z'); }
constexpr bool	is_alpha(char c)					{ return between(c, 'A', 'z') && (c <= 'Z' || c >= 'a'); }
constexpr bool	is_alphanum(char c)					{ return between(c, '0', 'z') && (c <= '9' || c >= 'a' || (c >= 'A' && c <= 'Z')); }
constexpr bool	is_hex(char c)						{ return between(c, '0', 'f') && (c <= '9' || c >= 'a' || (c >= 'A' && c <= 'F')); }
constexpr char	to_upper(char c)					{ return is_lower(c) ? c - ('a' - 'A') : c; }
constexpr char	to_lower(char c)					{ return is_upper(c) ? c + ('a' - 'A') : c; }
constexpr char	to_digit(uint8 n, char ten = 'A')	{ return n < 10 ? n + '0' : n - 10 + ten; }
constexpr uint8 from_digit(char c)					{ return c <= '9' ? c - '0' : (c & 31) + 9; }

template<typename C> void to_lower(C *dest, const C *srce) {
	if (srce) {
		while (C x = *srce++)
			*dest++ = to_lower(x);
	}
	*dest = 0;
}

template<typename C> void to_upper(C *dest, const C *srce) {
	if (srce) {
		while (C x = *srce++)
			*dest++ = to_upper(x);
	}
	*dest = 0;
}

constexpr constexpr_array<char, 2>	to_hex_string(uint8 u)	{ return {{to_digit(u >> 4, 'a'), to_digit(u & 15, 'a')}}; }
constexpr constexpr_array<char, 4>	to_hex_string(uint16 u)	{ return to_hex_string(uint8(u >> 8)) + to_hex_string(uint8(u)); }
constexpr constexpr_array<char, 8>	to_hex_string(uint32 u)	{ return to_hex_string(uint16(u >> 16)) + to_hex_string(uint16(u)); }
constexpr constexpr_array<char, 8>	to_hex_string(ulong u)	{ return to_hex_string(uint16(u >> 16)) + to_hex_string(uint16(u)); }
constexpr constexpr_array<char, 16>	to_hex_string(uint64 u)	{ return to_hex_string(uint32(u >> 32)) + to_hex_string(uint32(u)); }

template<typename T, int N> struct to_hex_string_s	{ static constexpr auto	f(const T *p)	{ return to_hex_string(p[0]) + to_hex_string_s<T, N - 1>::f(p + 1); } };
template<typename T> struct to_hex_string_s<T, 0>	{ static constexpr auto	f(const T *)	{ return constexpr_array<char, 0>(); } };
template<int N, typename T> constexpr auto	to_hex_string(const T *p)		{ return to_hex_string_s<T, N>::f(p); }

template<int B> struct from_hex_string_s;
template<> struct from_hex_string_s<1> { template<int N> static constexpr uint8		f(const constexpr_array<char, N> &a, int o)	{ return (from_digit(a[o]) << 4) | from_digit(a[o + 1]); } };
template<> struct from_hex_string_s<2> { template<int N> static constexpr uint16	f(const constexpr_array<char, N> &a, int o)	{ return ((uint16)from_hex_string_s<1>::f(a, o) << 8)  | from_hex_string_s<1>::f(a, o + 2); } };
template<> struct from_hex_string_s<4> { template<int N> static constexpr uint32	f(const constexpr_array<char, N> &a, int o)	{ return ((uint32)from_hex_string_s<2>::f(a, o) << 16) | from_hex_string_s<2>::f(a, o + 4); } };
template<> struct from_hex_string_s<8> { template<int N> static constexpr uint64	f(const constexpr_array<char, N> &a, int o)	{ return ((uint64)from_hex_string_s<4>::f(a, o) << 32) | from_hex_string_s<4>::f(a, o + 8); } };
template<typename T, size_t N> constexpr T	from_hex_string(constexpr_array<char, N> &a, int o = 0)	{ return (T)from_hex_string_s<sizeof(T)>::f(a, o); }

//constexpr auto to_dec_string(int n) { return n < 10 ? make_constexpr_array<char>({'0' + n % 10}) : to_dec_string(n / 10) + ('0' + n % 10); }

class char_set : bitarray<256> {
	typedef	bitarray<256> B;
public:
	static char_set whitespace, digit, upper, lower, alpha, alphanum, identifier;

	char_set()									{}
	char_set(const B &b)		: B(b)			{}
	char_set(char c)							{ set(c); }
	char_set(char s, char e)					{ set(s, e - s + 1); }
	char_set(const char *s)						{ while (*s) set(*s++);	}
	char_set&	operator+=(const char_set &b)	{ B::operator+=(b); return *this; }
	char_set&	operator-=(const char_set &b)	{ B::operator-=(b); return *this; }
	char_set&	operator*=(const char_set &b)	{ B::operator*=(b); return *this; }
	char_set	operator~()						{ return B(B::operator~());	}

	bool		test(char c)	const			{ return B::test(c); }

	friend char_set	operator|(const char_set &a, const char_set &b)		{ return char_set(a) += b; }
	friend char_set	operator+(const char_set &a, const char_set &b)		{ return char_set(a) += b; }
	friend char_set	operator-(const char_set &a, const char_set &b)		{ return char_set(a) -= b; }
	friend char_set	operator*(const char_set &a, const char_set &b)		{ return char_set(a) *= b; }
};

//-----------------------------------------------------------------------------
//	string_base function templates
//-----------------------------------------------------------------------------

template<typename C> inline C *skip_whitespace(C *srce) {
	while (is_whitespace(*srce))
		srce++;
	return srce;
}
template<typename C> inline C *skip_whitespace(C *srce, C *end) {
	while ((!end || srce < end) && is_whitespace(*srce))
		srce++;
	return srce;
}

template<typename T> struct case_insensitive {
	T	t;
	case_insensitive(T _t) : t(_t)	{}
	operator T()	const			{ return to_lower(t); }
};
template<typename T> struct case_insensitive<T*> {
	typedef case_insensitive<T>			*type;
};
template<typename T> struct case_insensitive<const T*> {
	typedef const case_insensitive<T>	*type;
};
template<typename T> struct case_insensitive<T *const> {
	typedef case_insensitive<T>			*type;
};
template<typename T> struct case_insensitive<const T *const> {
	typedef const case_insensitive<T>	*type;
};
template<typename T, int N> struct case_insensitive<T[N]> {
	typedef typename case_insensitive<T*>::type		type;
};
template<typename T> inline typename case_insensitive<T*>::type make_case_insensitive(T *t) {
	return (typename case_insensitive<T*>::type)t;
}
template<typename T> inline range<typename case_insensitive<T>::type> make_case_insensitive(range<T> &t) {
	return make_range(make_case_insensitive(t.begin()), make_case_insensitive(t.end()));
}

template<typename T> struct char_traits {
	typedef	T							case_sensitive;
	typedef	iso::case_insensitive<T>	case_insensitive, case_other;
};
template<typename T> struct char_traits<case_insensitive<T> > {
	typedef	T							case_sensitive, case_other;
	typedef	iso::case_insensitive<T>	case_insensitive;
};
template<typename T> struct char_traits<const T> : char_traits<T> {};

typedef case_insensitive<char>		ichar;
typedef case_insensitive<char16>	ichar16;


inline int compare(char a, char b)		{ return a - b; }
inline int compare(char16 a, char16 b)	{ return a - b; }
inline int compare(char a, char16 b)	{ return a - b; }
inline int compare(char16 a, char b)	{ return a - b; }
template<typename A, typename B> inline int compare(case_insensitive<A> a, B b) { return to_lower(a.t) - to_lower(b); }
template<typename A, typename B> inline int compare(A a, case_insensitive<B> b) { return to_lower(a) - to_lower(b.t); }

template<typename T> T*				string_end(T *s)			{ if (s) while (*s) s++; return s; }
template<typename T> inline size_t	string_len(T *s)			{ return string_end(s) - s; }
template<typename T> inline uint32	string_len32(T *s)			{ return uint32(string_len(s)); }
template<typename T> T*				string_end(T *s, T *e)		{ while (s < e && *s) s++; return s; }
template<typename T> inline size_t	string_len(T *s, T *e)		{ return string_end(s, e) - s; }
template<typename T> inline uint32	string_len32(T *s, T *e)	{ return uint32(string_len(s, e)); }

template<typename T> inline size_t	string_term(T *d, size_t n)	{ if (d) d[n] = 0; return n; }

template<typename A, typename B> inline int string_cmp(const A *a, const B *b) {
	if (!a || !b)
		return a ? 1 : b ? -1 : 0;
	for (;;) {
		A	ca = *a++;
		B	cb = *b++;
		if (ca == 0 || cb == 0)
			return cb - ca;
		if (int d = compare(ca, cb))
			return d;
	}
}
// no terminators in a or b
template<typename A, typename B> inline int string_cmp0(const A *a, const B *b, size_t n) {
	while (n--) {
		if (int d = compare(*a++, *b++))
			return d;
	}
	return 0;
}
// terminator in a only
template<typename A, typename B> inline int string_cmp1(const A *a, const B *b, size_t n) {
	if (!a)
		return n ? -1 : 0;
	while (n--) {
		A	ca = *a++;
		if (ca == 0)
			return -1;
		if (int d = compare(ca, *b++))
			return d;
	}
	return *a != 0;
}
// terminator in a or b
template<typename A, typename B> inline int string_cmp(const A *a, const B *b, size_t n) {
	if (!a)
		return n ? -1 : 0;
	while (n--) {
		A	ca = *a++;
		B	cb = *b++;
		if (ca == 0 || cb == 0)
			return cb - ca;
		if (int d = compare(ca, cb))
			return d;
	}
	return 0;
}

template<typename A, typename B> inline int string_cmp(const A *a, const B *b, const _none&) {
	return string_cmp(a, b);
}
template<typename A, typename B> inline int string_cmp(const A *a, const B *b, const A *ae) {
	return -string_cmp1(b, a, ae - a);
}
template<typename A, typename B> inline int string_cmp(const A *a, const B *b, const _none&, const B *be) {
	return string_cmp1(a, b, be - b);
}
template<typename A, typename B> inline int string_cmp(const A *a, const B *b, const A *ae, const B *be) {
	int	r = string_cmp0(a, b, min(ae - a, be - b));
	return r ? r : compare(ae - a, be - b);
}

template<typename A, typename B> inline bool char_match(const A &a, const B &b) {
	return compare(a, b) == 0;
}
template<typename A> inline bool char_match(const A &a, const char_set &set) {
	return set.test(a);
}

// find char or char_set (forward)
template<typename T, typename S> T *string_find(T *p, S c, T *e) {
	while (p < e) {
		if (char_match(*p, c))
			return p;
		++p;
	}
	return 0;
}
template<typename T, typename S> T *string_find(T *p, S c) {
	if (p) {
		while (T c2 = *p) {
			if (char_match(c2, c))
				return p;
			++p;
		}
	}
	return 0;
}
template<typename T, typename S> inline T *string_find(T *p, S c, const _none&) {
	return string_find(p, c);
}

// find string (forward)
template<typename T, typename S> T *string_find(T *p, const S *s, T *e) {
	if (p) {
		size_t	len = string_len(s);
		for (e -= len; p <= e; p++) {
			if (string_cmp(p, s, len) == 0)
				return p;
		}
	}
	return 0;
}
template<typename T, typename S> inline	T*	string_find(T *p, const S *s, T *pe, const S *se) {
	if (p) {
		size_t	len = se - s;
		for (pe -= len; p <= pe; p++) {
			if (string_cmp(p, s, len) == 0)
				return p;
		}
	}
	return 0;
}

template<typename T, typename S> inline	T *string_find(T *p, S *s) {
	return string_find(p, (const S*)s);
}
template<typename T, typename S> inline	T *string_find(T *p, const S *s) {
	return string_find(p, s, string_end(p));
}
template<typename T, typename S> inline T *string_find(T *p, const S *s, const _none&) {
	return string_find(p, s, string_end(p));
}
template<typename T, typename S> inline T *string_find(T *p, const S *s, const _none&, const _none&) {
	return string_find(p, s, string_end(p));
}
template<typename T, typename S> inline T *string_find(T *p, const S *s, const _none&, const S *se) {
	return string_find(p, s, string_end(p), se);
}

// find char or char_set (reverse)
template<typename T, typename S> T *string_rfind(T *p, S c, T *e) {
	while (p < e) {
		if (char_match(*--e, c))
			return e;
	}
	return 0;
}
// find string (reverse)
template<typename T, typename S> T *string_rfind(T *p, const S *s, T *e) {
	size_t	len = string_len(s);
	for (e -= len; e >= p; e--) {
		if (string_cmp(e, s, len) == 0)
			return e;
	}
	return 0;
}

// find number of matches of char or char_set
template<typename T, typename S> int string_count(const T *s, S c, const T *e) {
	int	n = 0;
	while (const T *p = string_find(s, c, e)) {
		s = p + 1;
		++n;
	}
	return n;
}
template<typename T, typename S> int string_count(const T *s, S c) {
	int	n = 0;
	while (const T *p = string_find(s, c)) {
		s = p + 1;
		++n;
	}
	return n;
}

// string_copy
template<typename S, typename D> size_t _chars_copy(D *d, const S *s) {
	if (d) {
		if (s) {
			D	*d0 = d;
			while (*d++ = *s++);
			return d - d0 - 1;
		}
	}
	return 0;
}
template<typename I, typename D> size_t _chars_copy(D *d, I s, I e) {
	D	*d0 = d;
	if (d) {
		while (s != e) {
			if (!(*d = *s++))
				break;
			++d;
		}
	}
	return d - d0;
}

template<typename S, typename D> size_t	chars_copy(D *d, const S *s)						{ return _chars_copy(d, s); }
template<typename I, typename D> size_t	chars_copy(D *d, I s, I e)							{ return _chars_copy(d, s, e); }
template<typename S> size_t				chars_copy(char *d, const S *s)						{ return to_utf8(s, d, 0); }
template<typename I> size_t				chars_copy(char *d, I s, I e)						{ return to_utf8(s, e, d, 0); }

template<typename D> size_t				chars_copy(D *d, const char *s)						{ return from_utf8(s, d, 0); }
template<typename D> size_t				chars_copy(D *d, const char *s, const char *e)		{ return from_utf8(s, e, d, 0); }
inline size_t							chars_copy(char *d, const char *s)					{ return _chars_copy(d, s); }
inline size_t							chars_copy(char *d, const char *s, const char *e)	{ return _chars_copy(d, s, e); }

template<typename D> size_t				chars_copy(D *d, char *s)							{ return from_utf8(s, d, 0); }
template<typename D> size_t				chars_copy(D *d, char *s, char *e)					{ return from_utf8(s, e, d, 0); }
inline size_t							chars_copy(char *d, char *s)						{ return _chars_copy(d, s); }
inline size_t							chars_copy(char *d, char *s, char *e)				{ return _chars_copy(d, s, e); }

template<typename S, typename D> size_t	string_copy(D *d, const S *s)						{ return string_term(d, chars_copy(d, s)); }
template<typename I, typename D> size_t	string_copy(D *d, I s, I e)							{ return string_term(d, chars_copy(d, s, e)); }
template<typename D, typename I> size_t	string_copy(D *d, I s, size_t n)					{ return string_copy(d, s, s + n); }
	
template<typename D> struct string_len_s {
	template<typename S>	static	size_t f(const S *s)					{ return string_len(s); }
	template<typename I>	static	size_t f(I s, I e)						{ return e - s; }
	static							size_t f(const char *s)					{ return utf8_count(s); }
	static							size_t f(const char *s, const char *e)	{ return utf8_count(s, e); }
	static							size_t f(char *s)						{ return utf8_count(s); }
	static							size_t f(char *s, char *e)				{ return utf8_count(s, e); }
};

template<> struct string_len_s<char> {
	template<typename S>	static	size_t f(const S *s)					{ return utf8_length(s); }
	template<typename I>	static	size_t f(I s, I e)						{ return utf8_length(s, e); }
	static							size_t f(const char *s)					{ return string_len(s); }
	static							size_t f(const char *s, const char *e)	{ return e - s;	}
	static							size_t f(char *s)						{ return string_len(s); }
	static							size_t f(char *s, char *e)				{ return e - s;	}
};

template<typename D, typename S> size_t string_copy_len(const S *s)		{ return string_len_s<D>::f(s); }
template<typename D, typename I> size_t string_copy_len(I s, I e)		{ return string_len_s<D>::f(s, e); }
template<typename D, typename I> size_t string_copy_len(I s, size_t n)	{ return string_len_s<D>::f(s, s + n); }

template<typename C> void replace(C *dest, const C *srce, const C *from, const C *to) {
	size_t		flen	= string_len(from);
	size_t		tlen	= string_len(to);

	while (const C *found = string_find(srce, from)) {
		memcpy(dest, srce, (found - srce) * sizeof(C));
		dest += found - srce;
		memcpy(dest, to, tlen * sizeof(C));
		dest += tlen;
		srce = found + flen;
	}
	string_copy(dest, srce);
}
	
template<typename C> void replace(C *s, const C from, const C to) {
	while (*s) {
		if (*s == from)
			*s = to;
		++s;
	}
}

template<typename I> constexpr range<I> string_substr(int s, int n, I b, I e)	{
	return range<I>(b ? (s < 0 ? e : b) + s : b, b ? (n < 0 ? e : b) + n : b);
}
template<typename I> constexpr range<I> string_substr(int s, I b, I e) {
	return range<I>(e ? (s < 0 ? e : b) + s : e, e); 
}
template<typename I> constexpr I string_substr(int s, I b, const _none&) {
	return (s < 0 ? string_end(b) : b) + s; 
}

inline bool string_check(const char *s, const char_set &set) {
	while (char c = *s++) {
		if (!set.test(c))
			return false;
	}
	return true;
}

inline bool string_check(const char *s, size_t n, const char_set &set) {
	while (n--) {
		if (!set.test(*s++))
			return false;
	}
	return true;
}

iso_export uint32 string_hash(const char *s, size_t n);
iso_export uint32 string_hash(const char16 *s, size_t n);

//-----------------------------------------------------------------------------
//	string_getter
//-----------------------------------------------------------------------------

template<typename T> struct string_getter {
	T	t;
	string_getter(const T &_t) : t(_t) {}
	string_getter(T &&_t) : t(move(_t)) {}
	size_t	len()							const	{ return t.string_len(); }			// default impl
	size_t	get(char *s, size_t len)		const	{ return t.string_get(s, len); }	// default impl
	size_t	get(char16 *s, size_t len)		const	{ return t.string_get(s, len); }	// default impl

	template<typename T>	bool operator==(const T &s2)	{ return s2 == *this; }
	template<typename T>	bool operator!=(const T &s2)	{ return s2 != *this; }
	template<typename T>	bool operator< (const T &s2)	{ return s2 >  *this; }
	template<typename T>	bool operator<=(const T &s2)	{ return s2 >= *this; }
	template<typename T>	bool operator> (const T &s2)	{ return s2 <  *this; }
	template<typename T>	bool operator>=(const T &s2)	{ return s2 <= *this; }
};

template<typename C, typename T> inline size_t to_string(C *s, const string_getter<T> &g) {
	return g.get(s, g.len());
}

//-----------------------------------------------------------------------------
//	string traits
//-----------------------------------------------------------------------------

template<typename S> struct string_traits : container_traits<S> {
	typedef typename container_traits<S>::iterator	iterator, start_type;
	static constexpr start_type		start(S &s)				{ return begin(s);	}
	static constexpr iterator		begin(S &s)				{ return iso::begin(s);	}
	static constexpr iterator		end(S &s)				{ return string_end(iso::begin(s));	}
	static constexpr _none			terminator(const S &s)	{ return none; }
	static constexpr size_t			len(const S &s)			{ return string_len(begin(s));	}
};

template<typename T> struct string_traits<range<T*> > : container_traits<range<T*> > {
	typedef range<T*>	S;
	typedef _none		start_type;
	typedef T*			iterator;
	static constexpr _none			start(const S &s)		{ return none;		}
	static constexpr iterator		begin(S &s)				{ return s.begin();	}
	static constexpr T*				end(const S &s)			{ return s.end();	}
	static constexpr T*				terminator(const S &s)	{ return s.end();	}
	static constexpr size_t			len(const S &s)			{ return s.size();	}
};
template<typename T> struct string_traits<const range<T*> > : container_traits<const range<T*> > {
	typedef const range<T*>	S;
	typedef _none			start_type;
	typedef const T*		iterator;
	static constexpr _none			start(S &s)				{ return none;		}
	static constexpr iterator		begin(S &s)				{ return s.begin();	}
	static constexpr T*				end(S &s)				{ return s.end();	}
	static constexpr T*				terminator(S &s)		{ return s.end();	}
	static constexpr size_t			len(S &s)				{ return s.size();	}
};

template<typename I, typename S> struct substr_type		{ typedef I type; };
template<typename I> struct substr_type<I, _none>		{ typedef range<I> type; };

//-----------------------------------------------------------------------------
//	string_base
//-----------------------------------------------------------------------------

template<typename B> class string_base {
protected:
	B			p;
	typedef	string_traits<B>		traits;
	typedef	string_traits<const B>	const_traits;

public:
	typedef typename traits::element			element;
	typedef	typename traits::iterator			iterator;
	typedef	typename const_traits::iterator		const_iterator;

	constexpr string_base()								{}
	constexpr string_base(const B &_p) : p(_p)			{}
	B&							representation()		{ return p; }
	constexpr const B&			representation() const	{ return p; }

	constexpr size_t			length()		const	{ return const_traits::len(p);	}
	constexpr uint32			length32()		const	{ return uint32(const_traits::len(p));	}
	constexpr const_iterator	begin()			const	{ return const_traits::begin(p);}
	constexpr const_iterator	end()			const	{ return const_traits::end(p);	}
	iterator					begin()					{ return traits::begin(p);		}
	iterator					end()					{ return traits::end(p);		}

	constexpr operator typename const_traits::start_type() const		{ return const_traits::start(p); }
	operator typename traits::start_type()								{ return traits::start(p); }

	template<typename S> element*			find(const S &s)			{ return string_find(begin(), s, traits::terminator(p)); }
	template<typename S> element*			rfind(const S &s)			{ return string_rfind(begin(), s, end()); }
	template<typename S> const element*		find(const S &s)	const	{ return string_find(begin(), s, const_traits::terminator(p)); }
	template<typename S> const element*		rfind(const S &s)	const	{ return string_rfind(begin(), s, end()); }

	template<typename S> bool				begins(const S &s)	const	{ return string_cmp(begin(), iso::begin(s), string_len(s)) == 0; }
	template<typename S> bool				ends(const S &s)	const	{ size_t len = string_len(s); return len <= length() && string_cmp(end() - len, iso::begin(s), len) == 0; }

	string_base<typename substr_type<iterator, typename traits::start_type>::type>				substr(int s)		{ return string_substr(s, begin(), traits::terminator(p)); }
	string_base<typename substr_type<const_iterator, typename const_traits::start_type>::type>	substr(int s) const	{ return string_substr(s, begin(), traits::terminator(p)); }
	string_base<range<iterator> >					substr(int s, int n)				{ return string_substr(s, n, begin(), end()); }
	constexpr string_base<range<const_iterator> >	substr(int s, int n)		const	{ return string_substr(s, n, begin(), end()); }
	constexpr string_base<range<const_iterator> >	substr(const_iterator s)	const	{ return range<const_iterator>(s, end()); }
	constexpr string_base<range<const_iterator> >	substr_to(const_iterator e) const	{ return range<const_iterator>(begin(), e); }

	constexpr operator const_memory_block()								const	{ return const_memory_block(begin(), length() * sizeof(element)); }

	template<typename B2> int	compare_to(const string_base<B2> &s2)	const	{ return -s2.compare_to(begin(), const_traits::terminator(p)); }
	template<typename C> int	compare_to(const C *s2)					const	{ return string_cmp(begin(), s2, const_traits::terminator(p)); }
	template<typename C> int	compare_to(const C *s2, const _none&)	const	{ return string_cmp(begin(), s2, const_traits::terminator(p)); }
	template<typename C> int	compare_to(const C *s2, const C *e2)	const	{ return string_cmp(begin(), s2, const_traits::terminator(p), e2); }
	int							compare_to(const_iterator s2)			const	{ return string_cmp(begin(), s2, const_traits::terminator(p)); }

	template<typename T> int	compare_to(const string_getter<T> &s2)	const	{
		size_t	len	= s2.len();
		len	= len ? min(length() + 1, len) : length() + 1;
		element	*p	= alloc_auto(element, len + 1);
		len = s2.get(unconst(p), len + 1);
		return compare_to(p, p + len);
	}

	template<typename R> bool read(R &r)			{ return r.read(p); }
	template<typename W> bool write(W &w) const		{ return w.write(p); }

	// friends

	friend						void	swap(string_base &a, string_base &b)					{ swap(a.p, b.p); }
	friend						uint32	hash(const string_base &s)								{ return string_hash(s.begin(), s.length()); }
	friend						size_t	string_len(const string_base &s)						{ return s.length(); }
	template<typename D> friend	size_t	string_copy(D *d, const string_base &s)					{ return string_copy(d, s.begin(), s.end()); }
	template<typename D> friend	size_t	string_copy_len(const string_base &s)					{ return string_copy_len<D>(s.begin(), s.end()); }
	template<typename T> friend	T*		string_find(T *p, const string_base &s, const _none&)	{ return string_find(p, s.begin(), none, s.end());	}
	template<typename T> friend	T*		string_find(T *p, const string_base &s, T *e)			{ return string_find(p, s.begin(), e, s.end());	}
};

//-----------------------------------------------------------------------------
//	compares
//-----------------------------------------------------------------------------

template<typename B, typename T>			inline int	compare(const string_base<B> &s1, const T &s2)		{ return s1.compare_to(s2); }
template<typename B, typename C, int N>		inline int	compare(const string_base<B> &s1, const C (&s2)[N])	{ return s1.compare_to(&s2[0], &s2[N - 1]); }
template<typename B, typename T>			inline bool operator==(const string_base<B> &s1, const T &s2)	{ return compare(s1, s2) == 0;	}
template<typename B, typename T>			inline bool operator!=(const string_base<B> &s1, const T &s2)	{ return compare(s1, s2) != 0;	}
template<typename B, typename T>			inline bool operator< (const string_base<B> &s1, const T &s2)	{ return compare(s1, s2) <  0;	}
template<typename B, typename T>			inline bool operator<=(const string_base<B> &s1, const T &s2)	{ return compare(s1, s2) <= 0;	}
template<typename B, typename T>			inline bool operator> (const string_base<B> &s1, const T &s2)	{ return compare(s1, s2) >  0;	}
template<typename B, typename T>			inline bool operator>=(const string_base<B> &s1, const T &s2)	{ return compare(s1, s2) >= 0;	}
template<typename B, typename T>			inline bool operator==(const T *s1, const string_base<B> &s2)	{ return compare(s2, s1) == 0; }
template<typename B, typename T>			inline bool operator!=(const T *s1, const string_base<B> &s2)	{ return compare(s2, s1) != 0; }
template<typename B, typename T>			inline bool operator< (const T *s1, const string_base<B> &s2)	{ return compare(s2, s1) >  0; }
template<typename B, typename T>			inline bool operator<=(const T *s1, const string_base<B> &s2)	{ return compare(s2, s1) >= 0; }
template<typename B, typename T>			inline bool operator> (const T *s1, const string_base<B> &s2)	{ return compare(s2, s1) <  0; }
template<typename B, typename T>			inline bool operator>=(const T *s1, const string_base<B> &s2)	{ return compare(s2, s1) <= 0; }

//-----------------------------------------------------------------------------
//	read/read_to/read_line
//-----------------------------------------------------------------------------

template<typename R> bool read_to(R &r, const char_set &set, char *p, uint32 n) {
	int		c = r.getc();
	if (c == -1)
		return false;

	char	*e = p + n - 1;
	while (c && c != -1 && !set.test(c)) {
		if (p == e)
			return false;
		*p++ = c;
		c = r.getc();
	}

	*p = 0;
	return true;
}
template<typename R> bool read_line(R &r, char *p, uint32 n) {
	int	c;
	do c = r.getc(); while (c == '\r' || c == '\n');

	if (c == -1)
		return false;

	char *e = p + n - 1;
	while (c && c != -1 && c != '\n' && c != '\r') {
		if (p == e)
			return false;
		*p++ = c;
		c = r.getc();
	}

	*p = 0;
	return true;
}
template<typename R, int N> bool read_to(R &r, const char_set &set, char (&p)[N]) {
	return read_to(r, set, p, N);
}
template<typename R, int N> bool read_line(R &r, char (&p)[N]) {
	return read_line(r, p, N);
}

//-----------------------------------------------------------------------------
//	count_string
//-----------------------------------------------------------------------------

template<typename T> class count_string_base : public string_base<range<T*> > {
public:
	constexpr count_string_base()		{}
	constexpr count_string_base(const string_base<range<T*> > &b)		: string_base<range<T*> >(b)	{}
	template<int N> constexpr count_string_base(T (&p)[N], size_t n)	: string_base<range<T*> >(range<T*>(p, p + N - 1))	{}
	constexpr count_string_base(T *p)			: string_base<range<T*> >(range<T*>(p, string_end(p)))	{}
	constexpr count_string_base(T *p, size_t n)	: string_base<range<T*> >(range<T*>(p, p + n))	{}
	constexpr count_string_base(T *p, T *e)		: string_base<range<T*> >(range<T*>(p, e))		{}
//	count_string_base(const count_string_base<const typename char_traits<T>::case_other> &b) : string_base<range<T*> >(range<T*>((T*)b.begin(), (T*)b.end()))	{}
	template<typename B> explicit count_string_base(const string_base<B> &b) : string_base<range<T*> >(range<T*>((T*)b.begin(), (T*)b.end()))	{}
	constexpr bool	blank()				const	{ return this->p.size() == 0;	}
	constexpr bool	operator!()			const	{ return this->p.size() == 0;	}
	constexpr T		operator[](int i)	const	{ return this->begin()[i];		}
	constexpr operator safe_bool::type() const	{ return safe_bool::test(!blank());}
};

typedef count_string_base<const char>		count_string;
typedef count_string_base<const char16>		count_string16;
typedef count_string_base<const ichar>		icount_string;
typedef count_string_base<const ichar16>	icount_string16;

template<typename C> count_string_base<const C> trim(const C *s, const C *e) {
	s = skip_whitespace(s);
	while (is_whitespace(e[-1]))
		--e;
	return count_string_base<const C>(s, e);
}
template<typename C> inline count_string_base<const C>	trim(const C *s)				{ return trim(s, string_end(s)); }
template<typename B> inline count_string_base<const typename string_traits<B>::element>	trim(const string_base<B> &s)	{ return trim(s.begin(), s.end()); }

//-----------------------------------------------------------------------------
//	embedded_string
//-----------------------------------------------------------------------------

template<typename C> struct embedded_string_traits {
	typedef C				element, *start_type, *iterator;
	typedef const C			*const_start_type, *const_iterator;
	static C				*begin(C &s)			{ return (C*)&s; }
	static C				*start(C &s)			{ return (C*)&s; }
	static C				*end(C &s)				{ return (C*)string_end(&s); }
	static inline _none		terminator(const C &s)	{ return none; }
	static inline size_t	len(const C &s)			{ return string_len(&s); }
};

template<> struct string_traits<char> : embedded_string_traits<char> {};
template<> struct string_traits<char16> : embedded_string_traits<char16> {};
template<> struct string_traits<const char> : embedded_string_traits<const char> {};
template<> struct string_traits<const char16> : embedded_string_traits<const char16> {};

typedef string_base<char>	embedded_string;
typedef string_base<char16>	embedded_string16;

inline void *get_after(const embedded_string *t) {
	return (void*)(t->end() + 1);
}
inline void *get_after(const embedded_string16 *t) {
	return (void*)(t->end() + 1);
}

//-----------------------------------------------------------------------------
//	pascal_string
//-----------------------------------------------------------------------------

template<int N, typename U=uint8, typename C=char> struct _pascal_string {
	U		len;
	C		buffer[N - 1];
	_pascal_string()	{}
	_pascal_string(const C *s) : len(U(string_len(s))) { memcpy(buffer, s, len * sizeof(C)); }
};
template<int N, typename U, typename C> struct string_traits<_pascal_string<N,U,C> > {
	typedef _pascal_string<N,U,C>	S;
	typedef C				element, *start_type, *iterator;
	typedef const C			*const_start_type, *const_iterator;
	static C				*begin(S &s)			{ return s.buffer; }
	static C				*start(S &s)			{ return s.buffer; }
	static C				*end(S &s)				{ return s.buffer + s.len; }
	static const C			*terminator(const S &s)	{ return s.buffer + s.len; }
	static inline size_t	len(const S &s)			{ return s.len; }
};
template<int N, typename U, typename C> struct string_traits<const _pascal_string<N,U,C> > : string_traits<_pascal_string<N,U,C> > {
	typedef const _pascal_string<N,U,C>	S;
	typedef const C			element, *start_type, *iterator;
	static const C			*begin(S &s)			{ return s.buffer; }
	static const C			*start(S &s)			{ return s.buffer; }
	static const C			*end(S &s)				{ return s.buffer + s.len; }
};

template<typename R, int N, typename U, typename C> bool read(R &r, _pascal_string<N,U,C> &s) {
	s.len = r.template get<U>();
	return check_readbuff(r, s.buffer, s.len * sizeof(C));
}

template<typename W, int N, typename U, typename C> bool write(W &w, const _pascal_string<N,U,C> &s) {
	w.write(s.len);
	return check_writebuff(w, s.buffer, s.len * sizeof(C));
}

typedef string_base<_pascal_string<256,uint8,char> >	pascal_string;

//-----------------------------------------------------------------------------
//	string & string16
//-----------------------------------------------------------------------------

template<typename C> class alloc_string : public string_base<C*> {
protected:
	typedef string_base<C*> B;
	using B::p;
	C					*_alloc(size_t n)						{ return p = n ? (C*)malloc((n + 1) * sizeof(C)) : 0; }
	template<typename S> void init(const S *s)					{ string_copy(_alloc(string_copy_len<C>(s)), s); }
	template<typename I> void init(I s, I e)					{ string_copy(_alloc(string_copy_len<C>(s, e)), s, e); }

public:
	alloc_string()					: B(0)						{}
	~alloc_string()												{ free(p); }
	explicit alloc_string(size_t n)								{ _alloc(n); if (n) p[n] = 0; }
	alloc_string(const alloc_string<C> &s)						{ init(s.begin(), s.end()); }
#ifdef USE_RVALUE_REFS
	alloc_string(alloc_string<C> &&s)							{ p = s.p; s.p = 0;; }
#endif
	alloc_string(const C *s)									{ init(s); }
	template<typename S> alloc_string(const S *s)				{ init(s); }
	template<typename S> alloc_string(const S *s, const S *e)	{ init(s, e); }
	template<typename S> alloc_string(const S *s, size_t n)		{ init(s, s + n); }
	template<typename T> alloc_string(const string_base<T> &s)	{ init(s.begin(), s.end()); }
	template<typename T> alloc_string(const string_getter<T> &s) { size_t n = s.len(); s.get(_alloc(n), n); }

	alloc_string&			operator=(const alloc_string<C> &s)	{ if (s.p != p) { free(p); init(s.begin(), s.end()); } return *this; }
	alloc_string&			operator=(const C *s)				{ free(p); init(s); return *this; }
	template<typename S> alloc_string& operator=(const S *s)	{ free(p); init(s); return *this; }
	template<typename T> alloc_string& operator=(const string_base<T> &s)	{ C *o = p; init(s.begin(), s.end()); free(o); return *this; }
	template<typename T> alloc_string& operator=(const string_getter<T> &s) { free(p); size_t n = s.len(); s.get(_alloc(n), n); return *this; }

	C*						extend(size_t n)					{ size_t n0 = B::length(); p = (C*)realloc(p, (n0 + n + 1) * sizeof(C)); p[n0 + n] = 0; return p + n0; }
	alloc_string&			append(const C *s, size_t n)		{ memcpy(extend(n), s, n * sizeof(C)); return *this; }
	alloc_string&			append(const C *s)					{ return append(s, string_len(s)); }
	alloc_string&			operator+=(const C *s)				{ return append(s); }
	alloc_string&			operator+=(C c)						{ return append(&c, 1); }
	alloc_string&			alloc(size_t n)						{ free(p); _alloc(n); return *this; }
	alloc_string&			resize(size_t n)					{ p = (C*)realloc(p, (n + 1) * sizeof(C)); if (p) p[n] = 0; return *this; }
	alloc_string&			clear()								{ free(p); p = 0; return *this; }

	template<typename T> alloc_string& append(const string_base<T> &s)		{ return append(s.begin(), s.length()); }
	template<typename T> alloc_string& operator+=(const string_base<T> &s)	{ return append(s.begin(), s.length()); }

	template<typename R> bool read(R &r, size_t n)				{ resize(n); return check_readbuff(r, p, n * sizeof(C)); }
	template<typename R> bool read_line(R &r);
	template<typename R> bool read_to(R &r, const char_set &set);

	friend uint32	hash(const alloc_string &s)					{ return string_hash(s.begin(), s.length()); }
};

typedef alloc_string<char>		string;
typedef alloc_string<char16>	string16;

template<typename T> inline string		str8(const T &s)		{ return s; }	//string(s)
inline string_base<const char*>			str8(const char *s)		{ return s; }
template<typename T> inline string16 	str16(const T &s)		{ return s; }	//string16(s)
inline string_base<const char16*>		str16(const char16 *s)	{ return s; }

template<typename B1, typename B2> inline alloc_string<typename T_noconst<typename string_base<B1>::element>::type> operator+(const string_base<B1> &s1, const string_base<B2> &s2) {
	size_t n1 = s1.length(), n2 = s2.length();
	alloc_string<typename T_noconst<typename string_base<B1>::element>::type> s(n1 + n2);
	string_copy(s.begin(), s1.begin(), n1);
	string_copy(s.begin() + n1, s2.begin(), n2);
	return s;
}
template<typename B1, typename B2> inline alloc_string<typename T_noconst<typename string_base<B1>::element>::type> operator+(const string_base<B1> &s1, const B2 *s2) {
	size_t n1 = s1.length(), n2 = string_len(s2);
	alloc_string<typename T_noconst<typename string_base<B1>::element>::type> s(n1 + n2);
	string_copy(s.begin(), s1.begin(), n1);
	string_copy(s.begin() + n1, s2, n2);
	return s;
}
template<typename B1, typename B2> inline alloc_string<B1> operator+(const B1 *s1, const string_base<B2> &s2) {
	size_t n1 = string_len(s1), n2 = s2.length();
	alloc_string<B1> s(n1 + n2);
	string_copy(s.begin(), s1, n1);
	string_copy(s.begin() + n1, s2.begin(), n2);
	return s;
}

template<typename C> alloc_string<C> to_lower(const C *c) {
	alloc_string<C>	s(string_len(c));
	to_lower(s.begin(), c);
	return s;
}

template<typename C> alloc_string<C> to_upper(const C *c) {
	alloc_string<C>	s(string_len(c));
	to_upper(s.begin(), c);
	return s;
}

//-----------------------------------------------------------------------------
//	string_param
//-----------------------------------------------------------------------------

template<typename C> class string_param : public string_base<const C*> {
	typedef string_base<const C*>	B;
	C		*mem;
	C		*alloc(size_t n) { B::p = mem = (C*)malloc((n + 1) * sizeof(C)); return mem; }

public:
	string_param(const C *s) : B(s), mem(0)	{}
	template<typename T> string_param(const T *s)				{ string_copy(alloc(string_copy_len<C>(s)), s); }
	template<typename T> string_param(const string_base<T> &s)	{ string_copy(alloc(string_copy_len<C>(s)), s); }
	template<typename T, int N> string_param(const string_base<C[N]> &s) : B(s.p), mem(0) {}
//	template<typename T> string_param(const string_base<T> &s, typename T_enable_if<T_same<typename string_base<T>::element, C>::value,int>::type dummy = 0) : B(s.begin()), mem(0) {}
	~string_param() { free(mem); }
};

//-----------------------------------------------------------------------------
//	fixed_string<int>
//-----------------------------------------------------------------------------

template<typename C> struct accum;
typedef accum<char>		string_accum;
typedef accum<char16>	string_accum16;

template<int N, typename C = char> class fixed_string : public string_base<C[N]> {
	typedef	string_base<C[N]>	B;
public:
	fixed_string()												{ B::p[0] = 0;								}
	fixed_string(const C *s)									{ string_copy(B::p, s);						}
	fixed_string(const C *fmt, va_list valist)					{ _format(B::p, N, fmt, valist);			}
	fixed_string(const constexpr_array<C, N - 1> &s)			{ memcpy(B::p, &s, N - 1); B::p[N - 1] = 0;	}
	template<typename T> explicit fixed_string(const T *s)		{ string_copy(B::p, s);						}
	template<typename T> fixed_string(const string_base<T> &s)	{ string_copy(B::p, s.begin(), s.end());	}
	template<typename T> fixed_string(const string_getter<T> &s) { B::p[s.get(B::p, N)] = 0; }


	template<typename T> fixed_string&	operator=(const T *s)				{ string_copy(B::p, s, N - 1); return *this; }
	template<typename T> fixed_string&	operator=(const string_base<T> &s)	{ string_copy(B::p, s.begin(), min(s.length(), N - 1)); return *this; }

	fixed_string&						operator+=(const char c)			{ append(c); return *this; }
	template<typename T> fixed_string&	operator+=(const T *s)				{ append(s); return *this; }
	template<typename T> fixed_string&	operator+=(const string_base<T> &s)	{ append(s.begin(), s.length()); return *this; }

	fixed_string&	clear()							{ B::p[0] = 0; return *this;				}
	size_t			max_length()		const		{ return N;									}
	size_t			remaining()			const		{ return N - this->length();				}
	bool			blank()				const		{ return !B::p[0];							}
	bool			operator!()			const		{ return !B::p[0];							}

	void			append(const C *s, size_t n)	{ if (s) string_copy(B::end(), s, n);		}
	void			append(const C *s)				{ append(s, string_len(s));					}
	void			append(const C c)				{ C *e = B::end(); e[0] = c; e[1] = 0;		}

	accum<C>		format(string_param<C> fmt, ...);
	template<class R> bool read_to(R &r, const char_set &set)	{ return iso::read_to(r, set, B::p, N); }
	template<class R> bool read_line(R &r)						{ return iso::read_line(r, B::p, N); }

	friend inline fixed_string replace(const fixed_string &srce, const C *from, const C *to) {
		fixed_string	dest;
		replace(dest, srce, from, to);
		return dest;
	}
	friend inline fixed_string to_lower(const fixed_string &srce) {
		fixed_string	dest;
		to_lower(dest.begin(), srce.begin());
		return dest;
	}
	friend inline fixed_string to_upper(const fixed_string &srce) {
		fixed_string	dest;
		to_upper(dest.begin(), srce.begin());
		return dest;
	}
};

template<int N1, int N2, typename C> inline fixed_string<N1+N2,C> operator+(const fixed_string<N1,C> &s1, const fixed_string<N2,C> &s2) {
	return fixed_string<N1+N2,C>(s1) += s2;
}
template<int N1, int N2, typename C> inline fixed_string<N1+N2,C> operator+(const fixed_string<N1,C> &s1, const C (&s2)[N2]) {
	return fixed_string<N1+N2,C>(s1) += s2;
}
template<int N1, int N2, typename C> inline fixed_string<N1+N2,C> operator+(const C (&s1)[N1], const fixed_string<N2,C> &s2) {
	return fixed_string<N1+N2,C>(s1) += s2;
}

//-----------------------------------------------------------------------------
//	makers
//-----------------------------------------------------------------------------

template<typename T> string_base<T*>			str(T *p)							{ return p; }
template<typename T> string_base<range<T*> >	str(T *p, size_t n)					{ return range<T*>(p, p + n); }
template<typename T> string_base<range<T*> >	str(T *p, T *e)						{ return range<T*>(p, e); }
inline string_base<range<const char*> >			str8(const const_memory_block &b)	{ return make_range<const char>(b); }
inline string_base<range<const char16*> >		str16(const const_memory_block &b)	{ return make_range<const char16>(b); }
inline string_base<range<char*> >				str8(const memory_block &b)			{ return make_range<char>(b); }
inline string_base<range<char16*> >				str16(const memory_block &b)		{ return make_range<char16>(b); }

template<typename T> string_base<typename case_insensitive<T*>::type>			istr(T *p)						{ return make_case_insensitive(p); }
template<typename T> string_base<range<typename case_insensitive<T*>::type> >	istr(T *p, size_t n)			{ return make_range_n(make_case_insensitive(p), n); }
template<typename T> string_base<range<typename case_insensitive<T*>::type> >	istr(T *p, T *e)				{ return make_range(make_case_insensitive(p), make_case_insensitive(e)); }
template<typename B> string_base<typename case_insensitive<B>::type>			istr(string_base<B> &s)			{ return make_case_insensitive(s.representation()); }
template<typename B> string_base<typename case_insensitive<const B>::type>		istr(const string_base<B> &s) 	{ return make_case_insensitive(s.representation()); }

template<typename T, size_t N> constexpr const string_base<const T(&)[N]>					cstr(const T (&p)[N])	{ return p; }
template<typename T, size_t N> constexpr const string_base<const case_insensitive<T>(&)[N]>	icstr(const T (&p)[N])	{ return (case_insensitive<T>(&)[N])p; }

template<typename T, size_t N>	constexpr count_string_base<const T>	str(const constexpr_array<T, N> &s)	{ return count_string_base<const T>(s.t, N); }
template<typename B>			constexpr const string_base<B>&			str(const string_base<B> &s)		{ return s; }

template<int N, typename C> fixed_string<N, C>&			fstr(C (&p)[N])							{ return (fixed_string<N,C>&)p; }
template<int N> inline		fixed_string<N, char>		str8(const fixed_string<N, char16> &s)	{ return fixed_string<N, char>(s); }
template<int N> inline		const char*					str8(const fixed_string<N, char> &s)	{ return s; }
template<int N> inline		fixed_string<N, char16>		str16(const fixed_string<N, char> &s)	{ return fixed_string<N, char16>(s); }
template<int N> inline		const char16*				str16(const fixed_string<N, char16> &s)	{ return s; }

template<int N, typename T> fixed_string<N, char>		str(const string_getter<T> &s)		{ return s; }
template<typename T>		fixed_string<256, char>		str(const string_getter<T> &s)		{ return s; }
template<int N, typename T> fixed_string<N, char16>		str16(const string_getter<T> &s)	{ return s; }
template<typename T>		fixed_string<256, char16>	str16(const string_getter<T> &s)	{ return s; }

//-----------------------------------------------------------------------------
//	write integer
//-----------------------------------------------------------------------------

template<int B, typename T> inline int len_num_base(T i) {
	int len;
	for (len = 1; i >= B; ++ len)
		i /= B;
	return len;
}
template<int B, typename T, typename C> inline void put_num_base(C *s, int len, T i, char ten = 'A') {
	while (len--) {
		s[len] = to_digit(uint32(i % B), ten);
		i /= B;
	}
}
template<int B, typename T, typename C> size_t put_unsigned_num_base(C *s, T i, char ten = 'A') {
	int n = len_num_base<B>(i);
	put_num_base<B>(s, n, i, ten);
	return n;
}
template<int B, typename T, typename C> size_t put_signed_num_base(C *s, T i, char ten = 'A') {
	if (i < 0) {
		*s = '-';
		return put_unsigned_num_base<B>(s + 1, uint_type_t(T)(-i), ten) + 1;
	}
	return put_unsigned_num_base<B>(s, uint_type_t(T)(i), ten);
}

template<typename T> inline int len_num_base(int B, T i) {
	int len;
	for (len = 1; i >= B; ++ len)
		i /= B;
	return len;
}
template<typename T, typename C> inline void put_num_base(int B, C *s, int len, T i, char ten = 'A') {
	while (len--) {
		s[len] = to_digit(uint32(i % B), ten);
		i /= B;
	}
}
template<typename T, typename C> size_t put_unsigned_num_base(int B, C *s, T i, char ten = 'A') {
	int n = len_num_base(B, i);
	put_num_base(B, s, n, i, ten);
	return n;
}
template<typename T, typename C> size_t put_signed_num_base(int B, C *s, T i, char ten = 'A') {
	if (i < 0) {
		*s = '-';
		return put_unsigned_num_base(B, s + 1, uint_type_t(T)(-i), ten) + 1;
	}
	return put_unsigned_num_base(B, s, uint_type_t(T)(i), ten);
}


template<bool SIGNED> struct s_put_num {
	template<int B, typename T, typename C> static size_t base(C *s, const T &i, char ten = 'A') { return put_signed_num_base<B>(s, native_endian(i), ten); }
};
template<> struct s_put_num<false>	{
	template<int B, typename T, typename C> static size_t base(C *s, const T &i, char ten = 'A') { return put_unsigned_num_base<B>(s, native_endian(i), ten); }
};

//-----------------------------------------------------------------------------
//	read integer
//-----------------------------------------------------------------------------

inline bool is_prefixed_int(const char *p) {
	return p[0] == '0' ? (
			(p[1] == 'x' && string_check(p + 2, char_set("0123456789abcdefABCDEF")))
		||	(p[1] == 'b' && string_check(p + 2, char_set("01")))
		||	string_check(p, char_set("01234567"))
	) : string_check(p, char_set::digit);
}

inline bool is_signed_int(const char *p) {
	return is_prefixed_int(p + int(p[0] == '+' || p[0] == '-'));
}

template<int B, typename T, typename C> inline const C *get_num_base(const C *p, T &i) {
	T		r;
	uint32	d;
	for (r = 0; is_alphanum(*p) && (d = from_digit(*p)) < B && r <= num_traits<T>::max() / B; ++p)
		r = r * B + d;
	i = r;
	return p;
}
template<typename T, typename C> inline const char *get_prefixed_num(const C *p, T &i) {
	return *p == '0' ? (p[1] == 'x' ? get_num_base<16>(p + 2, i) : p[1] == 'b' ? get_num_base<2>(p + 2, i) : get_num_base<8>(p + 1, i)) : get_num_base<10>(p, i);
}
template<typename T, typename C> size_t get_unsigned_num(const C *s, T &i) {
	if (const C *p = s)
		return get_prefixed_num(skip_whitespace(p), i) - s;
	return 0;
}
template<typename T, typename C> size_t get_signed_num(const C *s, T &i) {
	if (const C *p = s) {
		p = skip_whitespace(p);
		if (*p == '-') {
			p = get_prefixed_num(p + 1, i);
			i = -i;
			return p - s;
		}
		return get_prefixed_num(p + int(*p == '+'), i) - s;
	}
	return 0;
}


template<int B, typename T, typename C> inline const C *get_num_base(const C *p, const C *e, T &i) {
	T		r;
	uint32	d;
	for (r = 0; p < e && is_alphanum(*p) && (d = from_digit(*p)) < B && r <= num_traits<T>::max() / B; ++p)
		r = r * B + d;
	i = r;
	return p;
}
template<typename T, typename C> inline const char *get_prefixed_num(const C *p, const C *e, T &i) {
	return *p == '0' ? (p[1] == 'x' ? get_num_base<16>(p + 2, e, i) : p[1] == 'b' ? get_num_base<2>(p + 2, e, i) : get_num_base<8>(p + 1, e, i)) : get_num_base<10>(p, e, i);
}
template<typename T, typename C> size_t get_unsigned_num(const C *s, const C *e, T &i) {
	if (const C *p = s)
		return get_prefixed_num(skip_whitespace(p), e, i) - s;
	return 0;
}
template<typename T, typename C> size_t get_signed_num(const C *s, const C *e, T &i) {
	if (const C *p = s) {
		p = skip_whitespace(p, e);
		if (*p == '-') {
			p = get_prefixed_num(p + 1, e, i);
			i = -i;
			return p - s;
		}
		return get_prefixed_num(p + int(*p == '+'), e, i) - s;
	}
	return 0;
}
//-----------------------------------------------------------------------------
//	formatting
//-----------------------------------------------------------------------------

template<int N> inline	fixed_string<N> vformat_string(const char *fmt, va_list valist)		{ return fixed_string<N>(fmt, valist);	}
template<int N>			fixed_string<N> format_string(const char *fmt, ...)					{ va_list valist; va_start(valist, fmt); return fixed_string<N>(fmt, valist); }
inline fixed_string<256>				vformat_string(const char *fmt, va_list valist)		{ return fixed_string<256>(fmt, valist); }
inline fixed_string<256>				format_string(const char *fmt, ...)					{ va_list valist; va_start(valist, fmt); return vformat_string(fmt, valist); }

//to_string can take any of these forms:
//size_t			to_string(char *s, T t)				--
//fixed_string<N>	to_string(T t)						-- we know the (maximum) output size
//string_base<B>	to_string(T t)						--
//size_t			to_string(fixed_string<N> &d, T t)	-- we know the (maximum) output size
//const char*		to_string(T t)						-- returns (portion of) input as string

template<typename C, int B, typename T> inline size_t	to_string(C *s, baseint<B,T> v)	{ return s_put_num<num_traits<T>::is_signed>::template base<B,T>(s, v.i); }

template<typename C> inline size_t	to_string(C *s, int i)			{ return put_signed_num_base<10>(s, i); }
template<typename C> inline size_t	to_string(C *s, uint32 i)		{ return put_unsigned_num_base<10>(s, i); }
//template<typename C> inline size_t	to_string(C *s, const void *v)	{ s[0] = '0'; s[1] = 'x'; return put_unsigned_num_base<16>(s + 2, (uintptr_t)v) + 2; }
#if USE_LONG
template<typename C> inline size_t	to_string(C *s, long i)			{ return put_signed_num_base<10>(s, i); }
template<typename C> inline size_t	to_string(C *s, ulong i)		{ return put_unsigned_num_base<10>(s, i); }
#endif
#if USE_64BITREGS
template<typename C> inline size_t	to_string(C *s, int64 i)		{ return put_signed_num_base<10>(s, i); }
template<typename C> inline size_t	to_string(C *s, uint64 i)		{ return put_unsigned_num_base<10>(s, i); }
#endif

inline size_t	to_string(char *s, char c)			{ *s = c; return 1; }
inline size_t	to_string(char *s, char16 c)		{ return u32_to_utf8(c, s); }
inline size_t	to_string(char *s, const char16 *v)	{ return to_utf8(v, s, 0); }
inline size_t	to_string(char *s, char32 c)		{ return u32_to_utf8(c, s); }
inline size_t	to_string(char *s, const char32 *v)	{ return to_utf8(v, s, 0); }

iso_export size_t			to_string(char *s, float f);
iso_export size_t			to_string(char *s, double f);

template<typename C, typename B> inline size_t to_string(C *s, const string_base<B> &v)			{ return string_copy(s, v.begin(), v.end()); }
//template<typename C, typename B> inline size_t to_string(C *s, const count_string_base<B> &v)	{ return string_copy(s, v.begin(), v.end()); }
template<typename B> inline typename T_enable_if<!T_same<typename string_traits<B>::start_type,_none>::value, typename string_traits<const B>::start_type>::type
	to_string(const string_base<B> &v)	{ return v; }

template<int N, typename T> inline fixed_string<N>	_to_string(const T &t)	{ fixed_string<N> s; s[to_string(s.begin(), t)] = 0; return s; }
inline const char*			to_string(const char *v)				{ return v ? v : ""; }
inline const char*			to_string(bool v)						{ return v ? "true" : "false"; }
inline fixed_string<2>		to_string(char v)						{ return _to_string<2>(v); }
inline fixed_string<8>		to_string(char16 v)						{ return _to_string<8>(v); }
inline fixed_string<8>		to_string(char32 v)						{ return _to_string<8>(v); }
inline fixed_string<16>		to_string(int v)						{ return _to_string<16>(v); }
inline fixed_string<16>		to_string(uint32 v)						{ return _to_string<16>(v); }
inline fixed_string<16>		to_string(float v)						{ return _to_string<16>(v); }
inline fixed_string<32>		to_string(double v)						{ return _to_string<32>(v); }
//inline fixed_string<32>		to_string(const void *v)				{ return _to_string<32>(v); }
#if USE_LONG
inline fixed_string<16>		to_string(long v)						{ return _to_string<16>(v); }
inline fixed_string<16>		to_string(ulong v)						{ return _to_string<16>(v); }
#endif
#if USE_64BITREGS
inline fixed_string<32>		to_string(int64 v)						{ return _to_string<32>(v); }
inline fixed_string<32>		to_string(uint64 v)						{ return _to_string<32>(v); }
#endif

template<int B, typename T> inline fixed_string<baseint<B,T>::digits + 1>	to_string(baseint<B,T> v)	{ return _to_string<baseint<B,T>::digits + 1>(v); }

template<typename C, class T> struct has_to_string {
	template<typename U>	static decltype(to_string(*(U*)0))			test0(int);
	template<typename>		static void									test0(...);
	template<typename U>	static decltype(to_string((C*)0, *(U*)0))	test1(int);
	template<typename>		static void									test1(...);
	template<typename B>	static int									test3(string_base<B>*);
	static					void										test3(...);
	static int const value	= T_ischar<T>::value								? 0	// is it a char?
							: !T_same<decltype(test3((T*)0)), void>::value		? 3	// is it (or does it inherit from) a string_base<B>?
							: T_same<decltype(test0<T>(0)), const C*>::value	? 1	// is there a const C *to_string(T)?
							: !T_same<decltype(test1<T>(0)), void>::value		? 2	// is there a to_string(C*, T)?
							: !T_same<decltype(test0<T>(0)), void>::value		? 1	// is there a X to_string(T)?
							: 0;
};
template<typename C, class T, int N> struct has_to_string<C, T[N]> : T_num<0> {};

template<typename T> struct is_string : yesno {
	template<typename B> static yes test(const string_base<B>*);
	static no test(...);
	static bool const value = sizeof(test((T*)0)) == sizeof(yes);
};

template<typename T> inline decltype(to_string(*(T*)0))	to_string(const constructable<T> &t)	{
	return to_string(get(t));
}

inline size_t	to_string(char *s, bool v)	{ string_copy(s, to_string(v)); return string_len(s); }


//template<typename C, typename T> inline typename T_enable_if<has_to_string0<T>::value, size_t>::type	to_string(C *s, const T &t)	{
//	return string_copy(s, to_string(get(t)));
//}

//-----------------------------------------------------------------------------
//	string_accum
//-----------------------------------------------------------------------------

template<typename C> struct accum : virtfunc<C*(int&)> {
	C*			startp;

	struct _item {
		const void	*p;
		void		(*f)(accum &a, const void *p);
		template<typename T> static void thunk(accum &a, const void *p) { a << *(const T*)p; }
		template<typename T> _item(const T *t) : p(t), f(&thunk<T>) {}
		void		operator()(accum &a) const { f(a, p); }
	};
public:
	accum() : startp(0) {}

	C*			getp(int &n)			{ return (*this)(n); }
	C*			getp()					{ int n = 0; return (*this)(n); }
	accum&		move(int n)				{ if (int n0 = n) { getp(n); ISO_ASSERT(n == n0); } return *this; }
	size_t		length()				{ return getp() - startp;		}
	size_t		remaining()				{ int n = 0; getp(n); return n;	}

	const C*	begin()		const		{ return startp;				}
	const C*	term()					{ *getp() = 0; return startp;	}
	operator	C*()					{ *getp() = 0; return startp;	}

	accum&		vformat(const C *fmt, va_list valist);
	accum&		format(string_param<C> fmt, ...) {
		va_list valist;
		va_start(valist, fmt);
		return vformat(fmt, valist);
	}

	accum&		vformat(const C *fmt, const _item *items);
	template<typename... PP> accum& format_indexed(string_param<C> fmt, PP... pp) {
		_item	items[] = {&pp...};
		return vformat(fmt, items);
	}

	accum&		merge(const C *s, size_t n) {
		while (int n2 = int(n)) {
			C *d	= getp(n2);
			if (!n2)
				break;
			memcpy(d, s, n2 * sizeof(C));
			n	-= n2;
			s	+= n2;
		}
		return *this;
	}
	template<typename S> accum&	merge(const S *s, size_t n)	{
		while (int n2 = int(string_copy_len<C>(s, n))) {
			C *d	= getp(n2);
			chars_copy(d, s, s + n2);
			int	n1	= int(string_copy_len<S>(d, n2));
			n	-= n1;
			s	+= n1;
		}
		return *this;
	}
	accum&		putc(C c)									{ int n = 1; *getp(n) = c; return *this;	}
	accum&		putc(C c, int n)							{ if (n > 0) { C *d = getp(n); memset(d, c, n * sizeof(C)); } return *this;	}

	operator count_string_base<const C>()					{ return count_string_base<const C>(startp, getp()); }
	friend C	*to_string(const accum &v)					{ return v.startp; }
};

extern template accum<char>& accum<char>::vformat(const char *format, va_list argptr);
extern template accum<char16>& accum<char16>::vformat(const char16 *format, va_list argptr);

template<typename C> accum<C>& accum<C>::vformat(const C *fmt, const _item *items) {
	if (fmt) while (C c = *fmt++) {
		if (c == '%') {
			if (*fmt != '%') {
				int		x;
				fmt = get_num_base<10>(fmt, x);
				items[x](*this);
				continue;
			}
			fmt++;
		}
		putc(c);
	}
	return *this;
}

inline string_base<const char*>		str(accum<char> &s)		{ return s.term(); }
inline string_base<const char*>		str8(accum<char> &s)	{ return s.term(); }
inline string16						str16(accum<char> &s)	{ return s.term(); }
inline string_base<const char16*>	str(accum<char16> &s)	{ return s.term(); }
inline string_base<const char16*>	str16(accum<char16> &s)	{ return s.term(); }
inline string						str8(accum<char16> &s)	{ return s.term(); }

#if !defined PLAT_PC || defined(__clang__)
template<typename C, class T>			inline accum<C>& operator<<(accum<C> &&a, const T &t) { return a << t; }
#endif

//template<typename C, class T>			inline accum<C>& operator<<(accum<C> &a, const constructable<T> &t)			{ return a << (T&)t; }

template<typename C, class T>			inline typename T_enable_if<has_to_string<C,T>::value == 1, accum<C>&>::type operator<<(accum<C> &a, const T &t) {
	return a << to_string(get(t));
}
template<typename C, class T>			inline typename T_enable_if<has_to_string<C,T>::value == 2 && !is_string<T>::value, accum<C>&>::type operator<<(accum<C> &a, const T &t) {
	int n = 0; return a.move(int(to_string(a.getp(n), t)));
}

template<typename C, typename T> inline accum<C> & operator<<(accum<C> &a, const string_getter<T> &g) {
	int		n = int(g.len());
	auto	p = a.getp(n);
	return a.move(int(g.get(p, n)));
}

template<typename C, class T, int N>		typename T_enable_if<!T_ischar<T>::value, accum<C>&>::type operator<<(accum<C> &a, const T (&t)[N])					{ for (int i = 0; i < N; i++) a << t[i]; return a;	}
template<typename C>						inline accum<C>& operator<<(accum<C> &a, int f(C*))																	{ int n = 0; return a.move(f(a.getp(n)));	}
template<typename C1, typename C2>			inline accum<C1>& operator<<(accum<C1> &a, const accum<C2> &b)														{ return a.merge(b.begin(), b.length());	}

template<typename C1, typename C2>			inline typename T_enable_if<T_ischar<C2>::value, accum<C1>&>::type operator<<(accum<C1> &a, const C2 *const &s)		{ return a.merge(s, string_len(s));			}
template<typename C1, typename C2>			inline typename T_enable_if<T_ischar<C2>::value, accum<C1>&>::type operator<<(accum<C1> &a, C2 c)					{ int n = 1; *a.getp(n) = c; return a;		}
template<typename C1, typename C2, int N>	inline typename T_enable_if<T_ischar<C2>::value, accum<C1>&>::type operator<<(accum<C1> &a, const C2 (&s)[N])		{ return a.merge(s, N - 1);					}
template<typename C1, typename B>			inline accum<C1>& operator<<(accum<C1> &a, const string_base<B> &s)													{ return a.merge(s.begin(), s.length());	}
template<typename C, int N>					inline accum<C>& operator<<(accum<C> &a, const constexpr_array<char, N> &s)											{ return a.merge(&s[0], N);					}
template<typename C, int N>					inline accum<C>& operator<<(accum<C> &a, const constexpr_array<char16, N> &s)										{ return a.merge(&s[0], N);					}

template<typename T, typename C> struct accumT : accum<C> {
	accumT()	{ accum<C>::template bind<T, &T::getp>(); }
	T&	me()	{ return *static_cast<T*>(this); }
};

template<typename C> class fixed_accumT : public accumT<fixed_accumT<C>, C> {
	typedef accumT<fixed_accumT<C>, C>	B;
	using B::startp;
	C	*p, *endp;
protected:
	fixed_accumT()		{}
	void				init(C *_p, C *_endp)				{ startp = p = _p; endp = _endp - 1; }
	void				init(C *_p, size_t n)				{ init(_p, _p + n - 1); }
public:
	fixed_accumT(C *_p, size_t n)							{ init(_p, n);		}
	fixed_accumT(C *_p, C *_endp)							{ init(_p, _endp);	}
	template<int N>		fixed_accumT(C(&_p)[N])				{ init(_p, N);		}
	template<int N>		fixed_accumT(string_base<C[N]> &s)	{ init(s, N);		}
	template<int N>		fixed_accumT(fixed_string<N,C> &s)	{ init(s.end(), s.remaining()); }
	~fixed_accumT() 										{ *p = 0; }

	C*					getp()			const				{ return p; }
	C*					getp(int &n) {
		C	*t	= p;
		int	r	= int(endp - p);
		if (n)
			p += (r = min(n, r));
		n = r;
		return t;
	}
	fixed_accumT&		reset()								{ p = startp; return *this;	}
	size_t				length()		const				{ return p - startp;				}
	size_t				remaining()		const				{ return endp - p;					}
	const C*			end()			const				{ return p;							}
	C*					dup()								{ *p = 0; return strdup(startp);	}
	operator			C*()								{ *p = 0; return startp;			}
};

typedef fixed_accumT<char>		fixed_accum;
typedef fixed_accumT<char16>	fixed_accum16;

inline char *to_string(fixed_accum &v) {
	return v;
}

template<typename C, int N, typename T> inline fixed_accumT<C> operator<<(fixed_string<N,C> &s, const T &t) {
	fixed_accumT<C>	a(s, s + N);
	a.move(int(s.length())) << t;
	return a;
}
template<int N, typename C>	accum<C> fixed_string<N,C>::format(string_param<C> fmt, ...) {
	va_list valist;
	va_start(valist, fmt);
	return fixed_accumT<C>(*this).vformat(fmt, valist);
}

struct CODE_GUID : GUID {
	CODE_GUID(const GUID &g) : GUID(g) {};
};

template<typename C> accum<C>&	operator<<(accum<C> &a, const GUID &g);
template<typename C> accum<C>&	operator<<(accum<C> &a, const CODE_GUID &g);

template<typename F> typename T_exists<decltype((*(const F*)0)(*(string_accum*)0)), string_accum&>::type operator<<(string_accum &sa, const F &f) { f(sa); return sa; }

#if 1

template<typename T> inline auto onlyif(bool b, const T &t)	{
	return [=](string_accum &sa) { if (b) sa << t; };
}
template<typename T1, typename T2> inline auto ifelse(bool b, const T1 &t1, const T2 &t2) {
	return [=](string_accum &sa) { if (b) sa << t1; else sa << t2; };
}

#else

template<typename T> struct _onlyif {
	bool		b;
	const T		&t;
	_onlyif(bool _b, const T &_t) : b(_b), t(_t) {}
};
template<typename T> inline _onlyif<T> onlyif(bool b, const T &t)								{ return _onlyif<T>(b, t);		}
template<typename T> inline string_accum& operator<<(string_accum &a, const _onlyif<T> &b)		{ return b.b ? (a << b.t) : a;	}

template<typename T1, typename T2> struct _ifelse {
	bool		b;
	const T1	&t1;
	const T2	&t2;
	_ifelse(bool _b, const T1 &_t1, const T2 &_t2) : b(_b), t1(_t1), t2(_t2) {}
};
template<typename T1, typename T2> inline _ifelse<T1, T2> ifelse(bool b, const T1 &t1, const T2 &t2)			{ return _ifelse<T1, T2>(b, t1, t2);		}
template<typename T1, typename T2> inline string_accum& operator<<(string_accum &a, const _ifelse<T1, T2> &b)	{ return b.b ? (a << b.t1) : (a << b.t2);	}
#endif

class _justify {
protected:
	mutable string_accum	*a;
	mutable char			*p;
	uint16					w;
	char					c;
	void	init(string_accum &_a) const	{ a = &_a; p = a->getp(); }
public:
	explicit _justify(uint16 _w, char _c = ' ') : a(0), w(_w), c(_c)				{}
	_justify(string_accum &_a, uint16 _w, char _c = ' ') : w(_w), c(_c)	{ init(_a); }
};

class leftjustify : _justify {
	void	done() const {
		uint16 len = uint16(a->getp() - p);
		if (len < w)
			a->putc(c, w - len);
	}
public:
	explicit leftjustify(uint16 _w, char _c = ' ') : _justify(_w, _c)						{}
	leftjustify(string_accum &_a, uint16 _w, char _c = ' ') : _justify(_a, _w, _c)	{}
	~leftjustify()																	{ if (a) done(); }
	operator string_accum&()										const			{ done(); string_accum *t = a; a = 0; return *t; }
	template<typename T> const leftjustify& operator<<(const T &t)	const			{ *a << t; return *this; }
	string_accum& operator<<(const _none&)							const			{ done(); string_accum *t = a; a = 0; return *t; }
	friend const leftjustify &operator<<(string_accum &a, const leftjustify &t)		{ t.init(a); return t; }
};

class rightjustify : _justify {
	void	done() const {
		uintptr_t len = a->getp() - p;
		if (len < w) {
			uint16	n = uint16(w - len);
			a->move(n);
			memmove(p + n, p, len);
			memset(p, c, n);
		}
	}
public:
	explicit rightjustify(uint16 _w, char _c = ' ') : _justify(_w, _c)						{}
	rightjustify(string_accum &_a, uint16 _w, char _c = ' ') : _justify(_a, _w, _c)	{}
	~rightjustify()																	{ if (a) done(); }
	operator string_accum&()										const			{ done(); string_accum *t = a; a = 0; return *t; }
	template<typename T> const rightjustify& operator<<(const T &t) const			{ *a << t; return *this; }
	string_accum& operator<<(const _none&)							const			{ done(); string_accum *t = a; a = 0; return *t; }
	friend const rightjustify &operator<<(string_accum &a, const rightjustify &t)	{ t.init(a); return t; }
};

class tabs : _justify {
	iso_export void	tab(char *p0, char *p1) const;
public:
	explicit tabs(uint16 _w, char _c = ' ') : _justify(_w, _c)								{}
	tabs(string_accum &_a, uint16 _w, char _c = ' ') : _justify(_a, _w, _c)			{}
	operator string_accum&()										const			{ return *a; }
	template<typename T> const tabs& operator<<(const T &t)			const			{ char *p0 = a->getp(); *a << t; tab(p0, a->getp()); return *this; }
	string_accum& operator<<(const _none&)							const			{ return *a; }
	friend const tabs &operator<<(string_accum &a, const tabs &t)					{ t.init(a); return t; }
};

class repeat {
	char	c;
	int		n;
public:
	repeat(char _c, int _n) : c(_c), n(_n) {}
	friend string_accum &operator<<(string_accum &a, const repeat &t)				{ return a.putc(t.c, t.n); }
};

template<typename T> class separated_number_s {
	T		v;
	int		d;
	char	c;
	size_t process(char *s) const {
		size_t	len = to_string(s, v);
		size_t	n	= (len - 1 - int(!is_digit(*s))) / d;
		size_t	ret	= len + n;
		for (char *p = s + len, *e = s + ret; n--;) {
			for (int d1 = d; d1--; *--e = *--p);
			*--e = c;
		}
		return ret;
	}
public:
	separated_number_s(T _v, int _d, char _c) : v(_v), d(_d), c(_c) {}
	friend size_t to_string(char *s, const separated_number_s<T> &x) { return x.process(s); }
};
template<typename T> separated_number_s<T>	separated_number(const T t, int d = 3, char c = ',') { return separated_number_s<T>(t, d, c); }

template<typename T> struct _formatter {
	const char	*s;
	const T		&t;
	_formatter(const char *_s, const T &_t) : s(_s), t(_t)	{}
	friend size_t to_string(char *s, const _formatter<T> &x) { return _format(s, x.s, x.t); }
};
template<typename T> inline _formatter<T> formatter(const char *s, const T &t) { return _formatter<T>(s, t); }

//-----------------------------------------------------------------------------
//	scanning
//-----------------------------------------------------------------------------
int				vscan_string(const char *buffer, const char *format, va_list valist);
int				scan_string(const char *buffer, const char *format, ...);

inline size_t		from_string(const char *s, string &x)						{ x = s; return string_len(s); }
inline size_t		from_string(const char *s, const char *&i)					{ i = s; return string_len(s); }
inline size_t		from_string(const char *s, int8 &i)							{ return get_signed_num(s, i); }
inline size_t		from_string(const char *s, uint8 &i)						{ return get_unsigned_num(s, i); }
inline size_t		from_string(const char *s, int16 &i)						{ return get_signed_num(s, i); }
inline size_t		from_string(const char *s, uint16 &i)						{ return get_unsigned_num(s, i); }
inline size_t		from_string(const char *s, int &i)							{ return get_signed_num(s, i); }
inline size_t		from_string(const char *s, uint32 &i)						{ return get_unsigned_num(s, i); }

inline size_t		from_string(const char *s, const char *e, string &x)		{ x = count_string(s, e); return e - s; }
inline size_t		from_string(const char *s, const char *e, const char *&i)	{ i = s; return e - s; }
inline size_t		from_string(const char *s, const char *e, int8 &i)			{ return get_signed_num(s, e, i); }
inline size_t		from_string(const char *s, const char *e, uint8 &i)			{ return get_unsigned_num(s, e, i); }
inline size_t		from_string(const char *s, const char *e, int16 &i)			{ return get_signed_num(s, e, i); }
inline size_t		from_string(const char *s, const char *e, uint16 &i)		{ return get_unsigned_num(s, e, i); }
inline size_t		from_string(const char *s, const char *e, int &i)			{ return get_signed_num(s, e, i); }
inline size_t		from_string(const char *s, const char *e, uint32 &i)		{ return get_unsigned_num(s, e, i); }
#if USE_LONG
inline size_t		from_string(const char *s, long &i)							{ return get_signed_num(s, i); }
inline size_t		from_string(const char *s, ulong &i)						{ return get_unsigned_num(s, i); }
inline size_t		from_string(const char *s, const char *e, long &i)			{ return get_signed_num(s, e, i); }
inline size_t		from_string(const char *s, const char *e, ulong &i)			{ return get_unsigned_num(s, e, i); }
#endif
#if USE_64BITREGS
inline size_t		from_string(const char *s, int64 &i)						{ return get_signed_num(s, i); }
inline size_t		from_string(const char *s, uint64 &i)						{ return get_unsigned_num(s, i); }
inline size_t		from_string(const char *s, const char *e, int64 &i)			{ return get_signed_num(s, e, i); }
inline size_t		from_string(const char *s, const char *e, uint64 &i)		{ return get_unsigned_num(s, e, i); }
#endif

iso_export size_t	from_string(const char *s, bool &i);
iso_export size_t	from_string(const char *s, float &f);
iso_export size_t	from_string(const char *s, double &f);
iso_export size_t	from_string(const char *s, GUID &g);

iso_export size_t	from_string(const char *s, const char *e, bool &i);
iso_export size_t	from_string(const char *s, const char *e, float &f);
iso_export size_t	from_string(const char *s, const char *e, double &f);
iso_export size_t	from_string(const char *s, const char *e, GUID &g);

template<typename T> inline size_t	from_string(const char *s, const char *e, T &t) { return from_string(s, t); };
template<typename T> inline size_t	from_string(const count_string &s, T &t)		{ return from_string(s.begin(), s.end(), t); };
template<typename T> T				from_string(const char *s)						{ T t = T(); from_string(s, t); return t; }
template<typename T> T				from_string(const char *s, const char *e)		{ T t = T(); from_string(s, e, t); return t; }
template<typename T> T				from_string(const count_string &s)				{ T t = T(); from_string(s.begin(), s.end(), t); return t; }

template<typename T>		inline size_t	from_string(const char *s, constructable<T> &i)	{
	return from_string(s, (T&)i);
}
template<typename T>		inline size_t	from_string(const char *s, const char *e, constructable<T> &i)	{
	return from_string(s, e, (T&)i);
}
template<int B, typename T> inline size_t	from_string(const char *s, baseint<B,T> &i)	{
	if (const char *p = s)
		return get_num_base<B, T>(skip_whitespace(p), i.i) - s;
	return 0;
}
template<int B, typename T> inline size_t	from_string(const char *s, const char *e, baseint<B,T> &i)	{
	if (const char *p = s)
		return get_num_base<B, T>(skip_whitespace(p), e, i.i) - s;
	return 0;
}

template<typename R, typename T>				struct _read_as				{ T t; };
template<typename R, typename B, typename T>	struct _read_as<R,T B::*>	{ T B::* p; _read_as(T B::* _p) : p(_p) {} };
template<typename R, typename B, typename T>	_read_as<R,T B::*>	read_as(T B::* p)	{ return p; }

template<typename R, typename T> inline size_t	from_string(const char *s, _read_as<R,T> &x) {
	R	r;
	size_t	len = from_string(s, r);
	if (len)
		x.t = T(r);
	return len;
}

template<typename T, T N> inline size_t	from_string(const char *s, T_constant0<T,N> &x)		{ return 1; };

//-----------------------------------------------------------------------------
//	string_scan
//-----------------------------------------------------------------------------

class string_scan {
	const char	*p, *endp;
public:
	string_scan(const char *_p) : p(_p), endp(_p + string_len(p))			{}
	string_scan(const char *_p, const char *_end) : p(_p), endp(_end)	{}
	template<typename T> string_scan(const string_base<T> &s) : p(s.begin()), endp(s.end())		{}

	template<typename T>string_scan& operator>>(T &t) const				{ return (*const_cast<string_scan*>(this)) >> t; }
	size_t				remaining()		const							{ return max(endp - p, 0);	}
	count_string		remainder()		const							{ return str(p, endp);		}
	const char*			getp()			const							{ return p;					}
	char				peekc()			const							{ return *p;				}
	char				peekc(int n)	const							{ return p[n];				}
	count_string		peeks()			const							{ return str(p, endp);		}
	string_scan&		move(int n)										{ p += n; return *this;		}
	string_scan&		skip_whitespace()								{ while (p < endp && is_whitespace(*p)) ++p; return *this; }

	const char*			scan(char c)									{ if (const char *r = str(p, endp - p).find(c)) return p = r; return 0; }
	const char*			scan(const char *s)								{ if (const char *r = str(p, endp - p).find(s)) return p = r; return 0; }
	const char*			iscan(char c)									{ if (const char *r = (const char*)istr(p, endp - p).find(c)) return p = r; return 0; }
	const char*			iscan(const char *s)							{ if (const char *r = (const char*)istr(p, endp - p).find(s)) return p = r; return 0; }
	const char*			scan(const char_set &set)						{ if (const char *r = str(p, endp - p).find(set)) return p = r; return 0; }

	const char*			scan_skip(char c)								{ if (const char *r = str(p, endp - p).find(c)) return p = r + 1; return 0; }
	const char*			scan_skip(const char *s)						{ if (const char *r = str(p, endp - p).find(s)) return p = r + string_len(s); return 0; }
	const char*			iscan_skip(char c)								{ if (const char *r = (const char*)istr(p, endp - p).find(c)) return p = r + 1; return 0; }
	const char*			iscan_skip(const char *s)						{ if (const char *r = (const char*)istr(p, endp - p).find(s)) return p = r + string_len(s); return 0; }
	char				scan_skip(const char_set &set)					{ if (const char *r = str(p, endp - p).find(set)) { p = r + 1; return *r; } return 0; }

	bool				check(const char *s)							{ if (str(p, endp - p).begins(s)) { p += string_len(s); return true; } return false; }
	bool				icheck(const char *s)							{ if (istr(p, endp - p).begins(s)) { p += string_len(s); return true; } return false; }

	char				getc()											{ return p < endp ? *p++ : 0; }
	count_string		get_token()										{ const char *s = skip_whitespace().getp(); while (p < endp && !is_whitespace(*p)) ++p; return str(s, p); }
	count_string		get_token(const char_set &set)					{ const char *s = skip_whitespace().getp(); while (p < endp && set.test(*p)) ++p; return str(s, p); }
	count_string		get_token(const char_set &first, const char_set &set) { const char *s = skip_whitespace().getp(); if (first.test(*s)) while (++p < endp && set.test(*p)); return str(s, p); }
	count_string		get_n(int n)									{ const char *s = p; move(n); return str(s, p); }

	template<typename T> inline T get()									{ T t; move(int(from_string(getp(), t))); return t; }
	template<typename T> inline bool get(T &t)							{ size_t m = from_string(getp(), t); move(int(m)); return m != 0; }
	getter<string_scan>	get()											{ return *this; }
};

inline string_scan& operator>>(string_scan &a, const char c)			{ ISO_ASSERT(*a.getp() == c); return a.move(1); }
inline string_scan& operator>>(string_scan &a, const char *s)			{ size_t len = string_len(s); ISO_ASSERT(string_cmp(a.getp(), s, len) == 0); return a.move(int(len)); }
template<typename T> inline string_scan& operator>>(string_scan &a, T &t)	{ return a.move(int(from_string(a.getp(), t))); }

template<char SEP> struct part_iterator {
	const char *s, *e, *p, *n;

	part_iterator(const char *_s)					: s(_s), e(string_end(s)), p(_s), n(string_find(s, SEP, e))	{ if (!n) n = e; }
	part_iterator(const char *_s, const char *_e)	: s(_s), e(_e), p(_s), n(string_find(s, SEP, e))			{ if (!n) n = e; }

	count_string operator*() {
		return str(p, n);
	}
	count_string full() {
		return str(s, n);
	}
	part_iterator&	operator++() {
		if (n != e) {
			p = n + 1;
			n = string_find(p, SEP, e);
			if (!n)
				n = e;
		} else {
			p = n;
		}
		return *this;
	}
	part_iterator&	operator--() {
		if (p != s) {
			n = p == e ? p : p - 1;
			p = string_rfind(s, SEP, n);
			p = p ? p + 1 : s;
		} else {
			n = p;
		}
		return *this;
	}
};


//-----------------------------------------------------------------------------
//	buffer_accum<int>
//-----------------------------------------------------------------------------

template<int N>	class buffer_accum : public fixed_accum {
	string_base<char[N]>	s;
public:
	buffer_accum()									: fixed_accum(s)	{}
	buffer_accum(const char *fmt, ...)				: fixed_accum(s)	{ va_list valist; va_start(valist, fmt); vformat(fmt, valist); }
	template<typename T> buffer_accum(const T &t)	: fixed_accum(s)	{ *(fixed_accum*)this << t; }

	friend string_base<char[N]>		str(buffer_accum &s)	{ *s.getp() = 0; return s.s; }
	friend string_base<char[N]>		str8(buffer_accum &s)	{ *s.getp() = 0; return s.s; }
	friend fixed_string<N,char16>	str16(buffer_accum &s)	{ *s.getp() = 0; return fixed_string<N, char16>(s.s); }
};

template<int N>	inline string_accum& operator<<(string_accum &a, const buffer_accum<N> &b)	{ return a.merge(b.begin(), b.length()); }

struct trace_accum : buffer_accum<512> {
	trace_accum() {}
	trace_accum(const char *fmt, ...)	{ va_list valist; va_start(valist, fmt); vformat(fmt, valist); }
	template<typename T> trace_accum(const T &t) { *this << t; }
	~trace_accum()						{ _iso_debug_print((const char*)*this); }
};

template<typename T, typename C, int N> class buffered_accum : public accumT<buffered_accum<T,C,N>, C> {
protected:
	C		temp[N], *p;
public:
	void	check_flush(C *e) {
		if (e > end(temp) - 64) {
			static_cast<T*>(this)->flush(temp, p - temp);
			//memcpy(temp, p, (e - p) * sizeof(C));
			p = temp;
		}
	}
	C*		getp(int &n) {
		if (n == 0) {
			check_flush(p);
			n = int(end(temp) - p);
			return p;
		}
		if (n < 0) {
			ISO_ASSERT(p + n >= temp);
			return p -= n;
		}
		n = min(n, N);
		check_flush(p + n);
		C *t = p;
		p += n;
		return t;
	}
	buffered_accum&		putc(C c) {
		*p++ = c;
		check_flush(p);
		return *this;
	}

	buffered_accum() : p(temp)	{}
	template<int N2> buffered_accum(const buffered_accum<T,C,N2> &b) : p(temp)	{ unconst(b).flush(); }
	~buffered_accum()			{ static_cast<T*>(this)->flush(temp, p - temp); }
};

template<typename W, int N> struct stream_accum : buffered_accum<stream_accum<W, N>, char, N> {
	W			&w;
	void		flush(const char *s, size_t n) { w.writebuff(s, n); }
	stream_accum(W &_w) : w(_w) {}
	stream_accum(W &_w, const char *fmt, ...) : w(_w) { va_list valist; va_start(valist, fmt); this->vformat(fmt, valist); }
	template<typename T> stream_accum(W &_w, const T &t) : w(_w) { *this << t; }
};

struct dummy_accum {
	dummy_accum() {}
	dummy_accum(const char *fmt, ...)	{}
	template<typename T> dummy_accum(const T &t) {}
	template<typename T> dummy_accum& operator<<(const T &t) { return *this; }
};

class temp_accum {
	malloc_block	mb;
	fixed_accum		sa;
public:
	temp_accum(size_t size) : mb(size), sa(mb, mb.length()) {}
	template<typename T> string_accum&	operator<<(const T &t)	{ return sa << t; }
	operator	string_accum&()	{ return sa; }
	operator	const char*()	{ return sa; }
};

template<typename C> class builder : public accumT<builder<C>, C> {
	typedef	alloc_string<C>	S;
	S			&s;
	size_t		curr_size, max_size;
public:
	C*		getp(int &n) {
		size_t	offset	= curr_size;

		if (n == 0)
			n = max(int(max_size - curr_size), 64);
		else
			curr_size += n;

		if (offset + n > max_size)
			this->startp = s.resize(max_size = max(max_size * 2, offset + n)).begin();

		return s.begin() + offset;
	}

	builder(S &_s, bool clear=true) : s(_s)								{ this->startp = s.begin(); max_size = s.length(); curr_size = clear ? 0 : max_size; }
	builder(const builder &b) : s(b.s)									{ this->startp = b.startp; curr_size = b.curr_size; max_size = b.max_size; }
	template<typename T> builder(S &_s, const T &t, bool clear) : s(_s)	{ this->startp = s.begin(); max_size = s.length(); curr_size = clear ? 0 : max_size; *this << t; }
	~builder() 															{ flush(); }
	void		flush() { s.resize(max_size = curr_size); s[curr_size] = 0; }
	operator	S&()	{ flush(); return s; }
	const C*	begin()	{ flush(); return s.begin(); }
};

template<typename C, typename T> inline builder<C> operator<<(alloc_string<C> &a, const T &t)	{ return builder<C>(a, t, false); }

typedef builder<char>	string_builder;
typedef builder<char16>	string16_builder;

struct toggle_accum : string_builder {
	string&	get_buffer() {
		static string	s[2];
		static int		i = 0;
		return s[i++ & 1];
	}
	toggle_accum()									: string_builder(get_buffer())	{}
	toggle_accum(const char *fmt, ...)				: string_builder(get_buffer())	{ va_list valist; va_start(valist, fmt); vformat(fmt, valist); }
	template<typename T> toggle_accum(const T &t)	: string_builder(get_buffer())	{ *this << t; }
};

//-----------------------------------------------------------------------------
//	
//-----------------------------------------------------------------------------

template<typename C> alloc_string<C> replace(const C *srce, const C *from, const C *to) {
	alloc_string<C>		dest;
	builder<C>			b(dest);
	size_t				flen	= string_len(from);
	size_t				tlen	= string_len(to);

	while (const C *found = str(srce).find(from)) {
		b.merge(srce, found - srce);
		b.merge(to, tlen);
		srce = found + flen;
	}
	b << srce;
	b.flush();
	return dest;
}

template<typename B, typename C> alloc_string<C> replace(const string_base<B> &srce, const C *from, const C *to) {
	typedef typename T_noconst<typename string_base<B>::element>::type E;
	alloc_string<E>		dest;
	builder<E>			b(dest);
	size_t				flen	= string_len(from);
	size_t				tlen	= string_len(to);

	const E *begin = srce.begin(), *end = srce.end();
	while (const E *found = str(begin, end).find(from)) {
		b.merge(begin, found - begin);
		b.merge(to, tlen);
		begin = found + flen;
	}
	b.merge(begin, end - begin);
	b.flush();
	return dest;
}

template<class R, typename C> bool read(R &r, alloc_string<C> &s) {
	builder<C>	b(s);
	for (int c; (c = r.getc()) && c != -1; )
		b.putc(c);
	return true;
}
/*template<class W, typename C> bool write(W &w, const alloc_string<C> &s) {
	if (size_t len = s.length())
		w.writebuff(s, (len + 1) * sizeof(C));
	else
		w.write(C(0));
	return true;
}*/
template<typename C> template<typename R> bool alloc_string<C>::read_line(R &r) {
	int	c;
	do c = r.getc(); while (c == '\r' || c == '\n');
	if (c == -1)
		return false;
	for (builder<C> b(*this); c && c != -1 && c != '\n' && c != '\r'; c = r.getc())
		b.putc(c);
	return true;
}

template<typename C> template<typename R> bool alloc_string<C>::read_to(R &r, const char_set &set) {
	int	c = r.getc();
	if (c == -1)
		return false;
	for (builder<C> b(*this); c && c != -1 && !set.test(c); c = r.getc())
		b.putc(c);
	return true;
}

//-----------------------------------------------------------------------------
//	sa_getparams
//-----------------------------------------------------------------------------
#if 0
template<typename T, typename L> struct sa_getparams {
	typedef typename L::head	A;
	typedef	typename L::tail	B;
	sa_getparams<T,B>	b;
	A					a;
	inline_only sa_getparams<T,B>& operator<<(const A &_a) { a = _a; return b; }
};

template<typename T, typename A> struct sa_getparams<T, typelist<A> > {
	A				a;
	inline_only string_accum& operator<<(const A &_a) {	a = _a; return (*reinterpret_cast<T*>(this))();	}
};

template<typename F> struct sa_holder : sa_getparams<sa_holder<F>, typename function<F>::P::tail> {
	string_accum	&acc;
	F				&f;
	string_accum	&operator()()		{ return acc.move(call(f, pair<char*,sa_holder&>(acc.getp(), *this))); }
	sa_holder(string_accum &_acc, F &_f) : acc(_acc), f(_f)	{}
};

template<typename F> inline_only
	typename T_same<typename function<F>::R, int, sa_holder<F> >::type
	operator<<(string_accum &acc, F *f)	{ return sa_holder<F>(acc, *f); };
#endif
//-----------------------------------------------------------------------------
//	multi_string
//-----------------------------------------------------------------------------

template<typename C> struct multi_string_base {
	struct iterator {
		C	*p;
		iterator(C *_p) : p(_p) {}
		iterator &operator++()	{ p += string_len(p) + 1; return *this; }
		operator C*()	const	{ return p && *p ? p : 0; }
	};
/*	static C *create(const C **pp, int n) {
		size_t	t = 1;
		for (const C **i = pp, **e = i + n; i != e; ++i)
			t += *i ? string_len(*i) + 1 : 1;
		C	*p = (C*)malloc(t), *d = p;
		for (const C **i = pp, **e = i + n; i != e; ++i) {
			if (const C *s = *i)
				while (*d++ = *s++);
		}
		*d++ = 0;
		return p;
	}*/
	template<typename S> static C *create(const S *pp, size_t n) {
		size_t	t = 1;
		for (const S *i = pp, *e = i + n; i != e; ++i)
			t += *i ? string_len(*i) + 1 : 1;
		C	*p = (C*)malloc(t), *d = p;
		for (const S *i = pp, *e = i + n; i != e; ++i) {
			if (const C *s = *i)
				while (*d++ = *s++);
		}
		*d++ = 0;
		return p;
	}

	C	*p;
	multi_string_base(C *_p = 0) : p(_p) {}
	operator	C*()	const	{ return p; }
	iterator	begin()	const	{ return iterator(p); }
	iterator	end()	const	{ return iterator(0); }

	size_t		size()	const {
		size_t	n = 0;
		if (const C *x = p) {
			while (*x) {
				n++;
				while (*x++);
			}
		}
		return n;
	}
	size_t		length() const {
		if (const C *x = p) {
			while (*x)
				while (*x++);
			return x - p;
		}
		return 0;
	}
};

template<typename C> struct multi_string_alloc : multi_string_base<C> {
	typedef multi_string_base<C>	B;
	using B::p;

	template<typename I> void append(I s, I e)	{
		size_t len1 = this->length(), len2 = string_copy_len<C>(s, e);
		p = (C*)realloc(p, (len1 + len2 + 2) * sizeof(C));
		string_copy(p + len1, s, e);
		p[len1 + len2 + 1] = 0;
	}
	template<typename S> void append(const S *s)	{
		size_t len1 = this->length(), len2 = string_copy_len<C>(s);
		p = (C*)realloc(p, (len1 + len2 + 2) * sizeof(C));
		string_copy(p + len1, s);
		p[len1 + len2 + 1] = 0;
	}

	multi_string_alloc()					{}
	multi_string_alloc(size_t size)												: B((C*)malloc(size * sizeof(C))) {}
	multi_string_alloc(const C **pp, size_t n)									: B(B::create(pp, n))	{}
	multi_string_alloc(const B &b)												: B((C*)memdup(b.p, (b.length() + 1) * sizeof(C))) {}
	multi_string_alloc(multi_string_alloc &&b)									: B(b.p)				{ b.p = 0; }
//	multi_string_alloc(const multi_string_alloc &b)								: B(b.p)				{ unconst(b).p = 0; }
	template<typename S> multi_string_alloc(const string_base<S> *pp, size_t n)	: B(B::create(pp, n))	{}
	~multi_string_alloc()					{ free(p); }

	multi_string_alloc&	operator=(const B &b)					{ free(p); p = (C*)memdup(b.p, (b.length() + 1) * sizeof(C)); return *this; }
	multi_string_alloc&	operator=(const multi_string_alloc &b)	{ free(p); p = b.p; unconst(b).p = 0; return *this; }

	multi_string_alloc& operator+=(const B &b) {
		size_t len1 = this->length(), len2 = b.length();
		p = (C*)realloc(p, (len1 + len2 + 1) * sizeof(C));
		memcpy(p + len1, b.p, (len2 + 1) * sizeof(C));
		return *this;
	}
	template<typename S> multi_string_alloc& push_back(const string_base<S> &b) {
		append(b.begin(), b.end());
		return *this;
	}
	template<typename S> multi_string_alloc& push_back(const S *s) {
		append(s);
		return *this;
	}
	template<typename S> multi_string_alloc	operator+(const string_base<S> &b) && {
		append(b.begin(), b.end());
		return move(*this);
	}
};

typedef multi_string_base<char>		multi_string;
typedef multi_string_base<char16>	multi_string16;

//-----------------------------------------------------------------------------
//	escape sequences
//-----------------------------------------------------------------------------

template<typename C> alloc_string<C> escape(const C *s, const C *e) {
	alloc_string<C>	out;
	for (builder<C> b(out); s < e;) {
		C c = *s++;
		switch (c) {
			case '\a':	b.putc(C('\\')); c = 'a';	break;
			case '\b':	b.putc(C('\\')); c = 'b';	break;
			case '\f':	b.putc(C('\\')); c = 'f';	break;
			case '\n':	b.putc(C('\\')); c = 'n';	break;
			case '\r':	b.putc(C('\\')); c = 'r';	break;
			case '\t':	b.putc(C('\\')); c = 't';	break;
			case '\v':	b.putc(C('\\')); c = 'v';	break;
			case '\\':	b.putc(C('\\')); break;
			case '\'':	b.putc(C('\\')); break;
			case '"':	b.putc(C('\\')); break;
		}
		if (c < ' ' || c == 127) {
			b.format("\\x%02x", (uint8)c);
		} else if (c >= 0x80) {
			uint32	v;
			s += u32_from_utf8(v, s);
			b.format(v < 0x10000 ? "\\u%04x" : "\\U%08x", v);
		} else {
			b.putc(c);
		}
	}
	return out;
}

template<typename C> string unescape(const C *s, const C *e) {
	alloc_string<C>	out;
	for (builder<C> b(out); s < e;) {
		C c = *s++;
		if (c == '\\') {
			switch (c = *s++) {
				case 'a':	c = '\a';	break;
				case 'b':	c = '\b';	break;
				case 'f':	c = '\f';	break;
				case 'n':	c = '\n';	break;
				case 'r':	c = '\r';	break;
				case 't':	c = '\t';	break;
				case 'v':	c = '\v';	break;
				case '\\':	break;
				case '\'':	break;
				case '"':	break;

				case 'x': {
					c = 0;
					while (s < e && is_hex(*s))
						c = c * 16 + from_digit(*s++);
					break;
				}
				case 'u': {
					uint32	v = 0;
					for (int i = 4; i-- && s < e && is_hex(*s);)
						v = v * 16 + from_digit(*s++);
					b << char16(v);
					continue;
				}
				case 'U': {
					uint32	v = 0;
					for (int i = 8; i-- && s < e && is_hex(*s);)
						v = v * 16 + from_digit(*s++);
					b << char32(v);
					continue;
				}
				case '0': case '1': case '2': case '3': {
					c -= '0';
					if (s > e && between(*s, '0', '7')) {
						c = c * 8 + *s++ - '0';
						if (s < e && between(*s, '0', '7'))
							c = c * 8 + *s++ - '0';
					}
					break;
				}
			}
		}
		b.putc(c);
	}
	return out;
}

template<typename B> alloc_string<typename T_noconst<typename string_base<B>::element>::type> escape(const string_base<B> &s) {
	return escape(s.begin(), s.end());
}

template<typename B> alloc_string<typename T_noconst<typename string_base<B>::element>::type> unescape(const string_base<B> &s) {
	return unescape(s.begin(), s.end());
}

}//namespace iso

#endif // STRINGS_H
