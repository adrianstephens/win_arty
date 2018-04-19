#include "strings.h"
#include "bits.h"
//#include "maths.h"
#include "hashes/fnv.h"
#include <stddef.h>

namespace iso {

initialise::initialise(...)	{}
_none				none, terminate, empty;
_maximum			maximum;
_minimum			minimum;

extern void __iso_debug_print(const char*);
iso_export _iso_debug_print_t *_iso_debug_print = &__iso_debug_print;
iso_export _iso_debug_print_t *_iso_set_debug_print(_iso_debug_print_t *f) {
	return exchange(_iso_debug_print, f);
}

char	thousands_separator	= ',';
char	decimal_point		= '.';

enum {
	VS_LEFTALIGN	= 1<<0,	//Left align the result within the given field width.
	VS_PLUS			= 1<<1,	//Prefix the output value with a sign (+ or -) if the output value is of a signed type.
	VS_ZEROES		= 1<<2,	//zeros are added until the minimum width is reached.
	VS_BLANK		= 1<<3,	//Prefix the output value with a blank if the output value is signed and positive.
	VS_CFORMAT		= 1<<4,	//Prefix any nonzero output value with 0, 0x, or 0X; force decimal point in float formats
	VS_PRECISION	= 1<<5,	//Precision specified
	VS_SHORT		= 1<<6,	//Short prefix
	VS_32BIT		= 1<<7,
	VS_64BIT		= 1<<8,
	VS_UPPER		= 1<<9,	//Upper case hex

	VS_LONG			= sizeof(long)== 8 ? VS_64BIT : VS_32BIT,
	VS_LONGLONG		= VS_64BIT,

	VS_SKIP			= VS_LEFTALIGN,
};

//-----------------------------------------------------------------------------
//	scan
//-----------------------------------------------------------------------------

size_t from_string(const char *s, bool &i) {
	const char *p = skip_whitespace(s);
	i = *p && (*p == '1' || to_upper(*p) == 'T');
	while (*p && !is_whitespace(*p))
		p++;
	return p - s;
}

size_t from_string(const char *s, const char *e, bool &i) {
	const char *p = skip_whitespace(s, e);
	i = *p && (*p == '1' || to_upper(*p) == 'T');
	while (p < e && *p && !is_whitespace(*p))
		p++;
	return p - s;
}


template<> accum<char>& accum<char>::vformat(const char *format, va_list argptr) {
	int	n = 0;
	vsprintf(getp(n), format, argptr);
	return *this;
}
template<> accum<char16>& accum<char16>::vformat(const char16 *format, va_list argptr) {
//	vsprintf(getp(0), format, argptr);
	return *this;
}

size_t sprintf(char *buffer, const char *format, ...) {
	va_list valist;
	va_start(valist, format);
	return fixed_accum(buffer, 256).vformat(format, valist).length();
}
size_t _format(char *dest, const char *format, va_list valist) {
	return fixed_accum(dest, 256).vformat(format, valist).length();
}
size_t _format(char *dest, const char *format, ...) {
	va_list valist;
	va_start(valist, format);
	return fixed_accum(dest, 256).vformat(format, valist).length();
}
size_t _format(char *dest, size_t maxlen, const char *format, va_list valist) {
	return fixed_accum(dest, maxlen).vformat(format, valist).length();
}
size_t _format(char *dest, size_t maxlen, const char *format, ...) {
	va_list valist;
	va_start(valist, format);
	return fixed_accum(dest, maxlen).vformat(format, valist).length();
}

template<typename C> accum<C> &operator<<(accum<C> &a, const CODE_GUID &g) {
	//{0x9de1c535, 0x6ae1, 0x11e0, {0x84, 0xe1, 0x18, 0xa9, 0x05, 0xbc, 0xc5, 0x3f}}
	a << "{0x" << hex(g.Data1) << "u, 0x" << hex(g.Data2) << ", 0x" << hex(g.Data3) << ", {";
	for (int i = 0; i < 8; i++)
		a << onlyif(i, ", ") << "0x" << hex(g.Data4[i]);
	return a << "}}";
}
template accum<char> &operator<<(accum<char> &a, const CODE_GUID &g);

template<typename C> accum<C> &operator<<(accum<C> &a, const GUID &g) {
	//{9de1c535-6ae1-11e0-84e118a905bcc53f}
//	return a << '{' << hex(g.Data1) << '-' << hex(g.Data2) << '-' << hex(g.Data3) << '-' << hex((uint64&)g.Data4) << '}';
	int		n = 36;
	char	*s = a.getp(n);
	put_num_base<16>(s, 8, g.Data1);
	s[8] = '-';
	put_num_base<16>(s + 9, 4, g.Data2);
	s[13] = '-';
	put_num_base<16>(s + 14, 4, g.Data3);
	s[18] = '-';
	put_num_base<16>(s + 19, 4, (uint16)*(uint16be*)g.Data4);
	s[23] = '-';
	put_num_base<16>(s + 24, 12, (uint64)(uint64be&)g.Data4);
	return a;
}
template accum<char> &operator<<(accum<char> &a, const GUID &g);

//-----------------------------------------------------------------------------
//	utf8
//-----------------------------------------------------------------------------
uint32 utf8_length_u32(uint32 c, bool strict) {
	if (c < (strict ? 0x80 : 0xc0))
		return 1;
	uint32	n = 2;
	while (c > (2 << (n * 5)))
		n++;
	return n;
}

uint32 utf8_length(char c) {
	uint32	n = 1;
	if (uint8(c) >= 0xc0) {
		do {
			n++;
			c <<= 1;
		} while (c & 0x40);
	}
	return n;
}

uint32 utf8_count(const char *srce) {
	uint32	n = 0;
	if (srce) {
		while (char c = *srce) {
			srce += utf8_length(c);
			n++;
		}
	}
	return n;
}
uint32 utf8_count(const char *srce, const char *end) {
	uint32	n = 0;
	while (srce < end) {
		n++;
		srce += utf8_length(*srce);
	}
	return n;
}

uint32 u32_to_utf8(uint32 c, char *dest, bool strict) {
	if (c < (strict ? 0x80 : 0xc0)) {
		dest[0]	= (char)c;
		return 1;
	}

	uint32	n = 2;
	while (c > (2 << (n * 5)))
		n++;

	dest[0] = char((c >> (n * 6 - 6)) - (1 << (8 - n)));
	for (int i = 1; i < n; i++)
		dest[i] = char(((c >> ((n - i - 1) * 6)) & 0x3f) | 0x80);
	return n;
}

uint32 u32_from_utf8(uint32 &c, const char *srce) {
	const char	*p	= srce;
	uint32	r		= uint8(*p++);
	uint32	m		= 0xc0;
	if (r >= m) {
		do {
			r = ((r & ~m) << 6) | (*p++ & 0x3f);
			m <<= 5;
		} while (r & m);
	}
	c = r;
	return uint32(p - srce);
}

uint32 legalise_utf8(const char *srce, char *dest, size_t maxlen) {
	char *p = dest, *e = p + maxlen - 1, c;
	if (srce) {
		while (p < e && (c = *srce)) {
			if (c > 0x80u && c < 0xc0u)
				*p++ = 0xc2u;
			*p++ = c;
		}
	}
	if (p)
		*p = 0;
	return uint32(p - dest);
}

//-----------------------------------------------------------------------------
//	string transforms
//-----------------------------------------------------------------------------

char_set char_set::whitespace("\t\r\n ");
char_set char_set::digit('0', '9');
char_set char_set::upper('A', 'Z');
char_set char_set::lower('a', 'z');
char_set char_set::alpha		= char_set::upper + char_set::lower;
char_set char_set::alphanum		= char_set::alpha + char_set::digit;
char_set char_set::identifier	= char_set::alpha + char_set::digit;

uint32 string_hash(const char *s, size_t n) {
	return FNV1_str<uint32>(s, n);
}
uint32 string_hash(const char16 *s, size_t n) {
	return FNV1_str<uint32>(s, n);
}
//-----------------------------------------------------------------------------
//	debug
//-----------------------------------------------------------------------------

//#ifndef RELEASE
void _iso_assert(const char *filename, int line, const char *expr) {
	_iso_debug_print(format_string("%s(%d): %s\n", filename, line, expr));
	_iso_debug_break();
}
//#endif

} // iso
