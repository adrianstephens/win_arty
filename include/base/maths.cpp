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
_epsilon			epsilon;
_infinity			infinity;
_nan				nan;

_zero				zero;
_quarter			quarter;
_third				third;
_half				half;
_one				one, identity;
_two				two;
_four				four;
_pi					pi;
constant<__sqrt<__int<2> > >	sqrt2;
constant<__sqrt<__half> >		rsqrt2;
constant<__sqrt<__int<3> > >	sqrt3;
constant<__ratio<__sqrt<__int<3> >, __int<2> > >	sqrt3_2;
constant<__sign>	sign_mask;

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

template<typename T> inline const char *get_float(const char *p, T &f) {
	typename _uint_type<sizeof(T)>::type	r;
	bool	sign = *p == '-';

	p = get_num_base<10>(p + int(sign || *p == '+'), r);

	T	f0 = T(r);
	while (is_digit(*p)) {
		f0 *= 10;
		p++;
	}
	if (*p == '.') {
		const char *p0 = p + 1;
		uint32 nf = uint32((p = get_num_base<10>(p0, r)) - p0);
		f0 += r / pow(T(10), nf);
		while (is_digit(*p))
			p++;
	}
	if (*p == 'e' || *p == 'E') {
		bool	signe = p[1] == '-';
		uint32	r;
		p	= get_num_base<10>(p + 1 + int(signe || p[1] == '+'), r);
		f0	= signe ? f0 / pow(T(10), r) : f0 * pow(T(10), r);
	}
	f = sign ? -f0 : f0;
	return p;
}

size_t from_string(const char *s, float &f) {
	return s ? get_float(skip_whitespace(s), f) - s : 0;
}
size_t from_string(const char *s, double &f) {
	return s ? get_float(skip_whitespace(s), f) - s : 0;
}

template<typename T> inline const char *get_float(const char *p, const char *e, T &f) {
	typename _uint_type<sizeof(T)>::type	r;
	bool	sign = *p == '-';

	p = get_num_base<10>(p + int(sign || *p == '+'), e, r);

	T	f0 = T(r);
	while (p < e && is_digit(*p)) {
		f0 *= 10;
		p++;
	}
	if (*p == '.') {
		const char *p0 = p + 1;
		uint32 nf = uint32((p = get_num_base<10>(p0, e, r)) - p0);
		f0 += r / pow(T(10), nf);
		while (p < e && is_digit(*p))
			p++;
	}
	if (*p == 'e' || *p == 'E') {
		bool	signe = p[1] == '-';
		uint32	r;
		p	= get_num_base<10>(p + 1 + int(signe || p[1] == '+'), e, r);
		f0	= signe ? f0 / pow(T(10), r) : f0 * pow(T(10), r);
	}
	f = sign ? -f0 : f0;
	return p;
}

size_t from_string(const char *s, const char *e, float &f) {
	return s ? get_float(skip_whitespace(s, e), e, f) - s : 0;
}
size_t from_string(const char *s, const char *e, double &f) {
	return s ? get_float(skip_whitespace(s, e), e, f) - s : 0;
}

size_t from_string(const char *s, GUID &g) {
	if (!s)
		return 0;
	const char *p = s;
	if (*p == '{')
		p++;
	p = get_num_base<16>(p, g.Data1);
	if (*p != '-')
		return 0;
	p = get_num_base<16>(p + 1, g.Data2);
	if (*p != '-')
		return 0;
	p = get_num_base<16>(p + 1, g.Data3);
	if (*p != '-')
		return 0;
	uint16	t16;
	uint64	t64;
	p = get_num_base<16>(p + 1, t16);
	if (*p != '-')
		return 0;
	p = get_num_base<16>(p + 1, t64);
	if (*s == '{' && *p++ != '}')
		return 0;
	*(uint64be*)g.Data4 = t64 + (uint64(t16) << 48);
	return p - s;
}

int	vscan_string(const char *buffer, const char *format, va_list argptr) {
	int			total	= 0;
	const char *p		= buffer;
	char		c;
	for (const char *in = format; c = *in; in++) {
		if (c == '%') {
			in++;
			if (*in == '%') {
				if (c == *p) {
					++p;
					continue;
				}
				break;	
			}

			uint32	flags		= 0;
			int		width		= 0;
			if (*in == '*') {
				in++;
				flags |= VS_SKIP;
			}
			in = get_num_base<10>(in, width);

			switch (*in) {
				case 'h':
					flags |= VS_SHORT;
					in++;
					break;
				case 'l':
					in++;
					flags |= VS_LONG;
					if (*in == 'l') {
						flags |= VS_LONGLONG;
						in++;
					}
					break;
				case 'I':
					if (in[1] == '3' && in[2] == '2') {
						flags |= VS_32BIT;
						in += 3;
					} else if (in[1] == '6' && in[2] == '4') {
						flags |= VS_64BIT;
						in += 3;
					}
					break;
			}
			switch (char fmt = *in) {
				case 'c':
					*va_arg(argptr, char*) = *p++;
					++total;
					break;
				case 'd':
				case 'i':
					if (flags & VS_64BIT)
						p += from_string(p, *va_arg(argptr, int64*));
					else if (flags & VS_SHORT)
						p += from_string(p, *va_arg(argptr, int16*));
					else
						p += from_string(p, *va_arg(argptr, int32*));
					++total;
					break;
				case 'o':
					if (flags & VS_64BIT)
						p = get_num_base<8>(p, *va_arg(argptr, uint64*));
					else if (flags & VS_SHORT)
						p = get_num_base<8>(p, *va_arg(argptr, uint16*));
					else
						p = get_num_base<8>(p, *va_arg(argptr, uint32*));
					++total;
					break;
				case 'u':
					if (flags & VS_64BIT)
						p = get_num_base<10>(p, *va_arg(argptr, uint64*));
					else if (flags & VS_SHORT)
						p = get_num_base<10>(p, *va_arg(argptr, uint16*));
					else
						p = get_num_base<10>(p, *va_arg(argptr, uint32*));
					++total;
					break;
				case 'x':
					if (flags & VS_64BIT)
						p = get_num_base<16>(p, *va_arg(argptr, uint64*));
					else if (flags & VS_SHORT)
						p = get_num_base<16>(p, *va_arg(argptr, uint16*));
					else
						p = get_num_base<16>(p, *va_arg(argptr, uint32*));
					++total;
					break;
				case 'e':case 'E':case 'f':case 'g':case 'G':
					if (flags & (VS_64BIT|VS_32BIT))
						p += from_string(p, *va_arg(argptr, double*));
					else
						p += from_string(p, *va_arg(argptr, float*));
					++total;
					break;
				case 'n':
					*va_arg(argptr, int*) = int(p - buffer);
					++total;
					break;
				case 's': {
					char	*s = va_arg(argptr, char*);
					while (is_whitespace(*p))
						++p;
					while (!is_whitespace(*p))
						*s++ = *p++;
					*s = 0;
					++total;
					break;
				}
			}

		} else if (is_whitespace(c)) {
			while (is_whitespace(*p))
				++p;

		} else if (c == *p) {
			++p;

		} else {
			break;
		}
	}
	return total;
}

int	scan_string(const char *buffer, const char *format, ...) {
	va_list valist;
	va_start(valist, format);
	return vscan_string(buffer, format, valist);
}

//-----------------------------------------------------------------------------
// Grisu2 implementation (slightly simpler than Grisu3) for converting doubles to strings
//
// Sources:
// Based on Florian Loitsch 2010 "Printing Floating-Point Numbers Quickly and Accurately with Integers"
//	http://florian.loitsch.com/publications/dtoa-pldi2010.pdf
//	https://github.com/floitsch/double-conversion (BSD licensed)
//
// Also implementations by Milo Yip and night-shift used as reference
//	https://github.com/miloyip/dtoa-benchmark
//	https://github.com/night-shift/fpconv
//-----------------------------------------------------------------------------

struct diy_fp {
	typedef float_components<double>	C;
	uint64	m;
	int		e;

	diy_fp() {}
	diy_fp(uint64 _m, int _e) : m(_m), e(_e) {}
	diy_fp(double w) {
		C	c(w);
		if (c.e == 0) {			// subnormals
			int	s = 63 - highest_set_index(c.m);
			m	= c.m << s;
			e	= 1 - (C::E_OFF + 63) - s;
		} else {
			m	= (c.m | (uint64(1) << C::M)) << (63 - C::M);
			e	= c.e - (C::E_OFF + 63);
		}
	}

	operator double() const	{
		int		s	= C::M - highest_set_index(m);
		return C(shift_bits(m, s), e + (C::E_OFF + 63) + s, 0).f;
	}

};

// multiply from Florian paper
diy_fp operator*(const diy_fp &x, const diy_fp &y) {
	uint64 xa		= x.m >> 32, xb = x.m & 0xFFFFFFFF;
	uint64 ya		= y.m >> 32, yb = y.m & 0xFFFFFFFF;

	uint64 upper	= xa * ya;
	uint64 lower	= xb * yb;
	uint64 cross1	= xb * ya;
	uint64 cross2	= xa * yb;

	uint64 tmp		= (lower >> 32) + (cross1 & 0xFFFFFFFF) + (cross2 & 0xFFFFFFFF) + (1u << 31);

	// note - exponent is no longer normalised
	return diy_fp(upper + (cross1>>32) + (cross2>>32) + (tmp>>32), x.e + y.e + 64);
}

diy_fp find_cachedpow10(int e, int &k) {
	static const diy_fp pow10cache[] = {
		diy_fp(18054884314459144840U, -1220),	//1e-348
		diy_fp(13451937075301367670U, -1193),	//1e-340
		diy_fp(10022474136428063862U, -1166),	//1e-332
		diy_fp(14934650266808366570U, -1140),	//1e-324
		diy_fp(11127181549972568877U, -1113),	//1e-316
		diy_fp(16580792590934885855U, -1087),	//1e-308
		diy_fp(12353653155963782858U, -1060),	//1e-300
		diy_fp(18408377700990114895U, -1034),	//1e-292
		diy_fp(13715310171984221708U, -1007),	//1e-284
		diy_fp(10218702384817765436U, -980),	//1e-276
		diy_fp(15227053142812498563U, -954),	//1e-268
		diy_fp(11345038669416679861U, -927),	//1e-260
		diy_fp(16905424996341287883U, -901),	//1e-252
		diy_fp(12595523146049147757U, -874),	//1e-244
		diy_fp( 9384396036005875287U, -847),	//1e-236
		diy_fp(13983839803942852151U, -821),	//1e-228
		diy_fp(10418772551374772303U, -794),	//1e-220
		diy_fp(15525180923007089351U, -768),	//1e-212
		diy_fp(11567161174868858868U, -741),	//1e-204
		diy_fp(17236413322193710309U, -715),	//1e-196
		diy_fp(12842128665889583758U, -688),	//1e-188
		diy_fp( 9568131466127621947U, -661),	//1e-180
		diy_fp(14257626930069360058U, -635),	//1e-172
		diy_fp(10622759856335341974U, -608),	//1e-164
		diy_fp(15829145694278690180U, -582),	//1e-156
		diy_fp(11793632577567316726U, -555),	//1e-148
		diy_fp(17573882009934360870U, -529),	//1e-140
		diy_fp(13093562431584567480U, -502),	//1e-132
		diy_fp( 9755464219737475723U, -475),	//1e-124
		diy_fp(14536774485912137811U, -449),	//1e-116
		diy_fp(10830740992659433045U, -422),	//1e-108
		diy_fp(16139061738043178685U, -396),	//1e-100
		diy_fp(12024538023802026127U, -369),	//1e-92
		diy_fp(17917957937422433684U, -343),	//1e-84
		diy_fp(13349918974505688015U, -316),	//1e-76
		diy_fp( 9946464728195732843U, -289),	//1e-68
		diy_fp(14821387422376473014U, -263),	//1e-60
		diy_fp(11042794154864902060U, -236),	//1e-52
		diy_fp(16455045573212060422U, -210),	//1e-44
		diy_fp(12259964326927110867U, -183),	//1e-36
		diy_fp(18268770466636286478U, -157),	//1e-28
		diy_fp(13611294676837538539U, -130),	//1e-20
		diy_fp(10141204801825835212U, -103),	//1e-12
		diy_fp(15111572745182864684U, -77),		//1e-4
		diy_fp(11258999068426240000U, -50),		//1e+4
		diy_fp(16777216000000000000U, -24),		//1e+12
		diy_fp(12500000000000000000U, 3),		//1e+20
		diy_fp( 9313225746154785156U, 30),		//1e+28
		diy_fp(13877787807814456755U, 56),		//1e+36
		diy_fp(10339757656912845936U, 83),		//1e+44
		diy_fp(15407439555097886824U, 109),		//1e+52
		diy_fp(11479437019748901445U, 136),		//1e+60
		diy_fp(17105694144590052135U, 162),		//1e+68
		diy_fp(12744735289059618216U, 189),		//1e+76
		diy_fp( 9495567745759798747U, 216),		//1e+84
		diy_fp(14149498560666738074U, 242),		//1e+92
		diy_fp(10542197943230523224U, 269),		//1e+100
		diy_fp(15709099088952724970U, 295),		//1e+108
		diy_fp(11704190886730495818U, 322),		//1e+116
		diy_fp(17440603504673385349U, 348),		//1e+124
		diy_fp(12994262207056124023U, 375),		//1e+132
		diy_fp( 9681479787123295682U, 402),		//1e+140
		diy_fp(14426529090290212157U, 428),		//1e+148
		diy_fp(10748601772107342003U, 455),		//1e+156
		diy_fp(16016664761464807395U, 481),		//1e+164
		diy_fp(11933345169920330789U, 508),		//1e+172
		diy_fp(17782069995880619868U, 534),		//1e+180
		diy_fp(13248674568444952270U, 561),		//1e+188
		diy_fp( 9871031767461413346U, 588),		//1e+196
		diy_fp(14708983551653345445U, 614),		//1e+204
		diy_fp(10959046745042015199U, 641),		//1e+212
		diy_fp(16330252207878254650U, 667),		//1e+220
		diy_fp(12166986024289022870U, 694),		//1e+228
		diy_fp(18130221999122236476U, 720),		//1e+236
		diy_fp(13508068024458167312U, 747),		//1e+244
		diy_fp(10064294952495520794U, 774),		//1e+252
		diy_fp(14996968138956309548U, 800),		//1e+260
		diy_fp(11173611982879273257U, 827),		//1e+268
		diy_fp(16649979327439178909U, 853),		//1e+276
		diy_fp(12405201291620119593U, 880),		//1e+284
		diy_fp( 9242595204427927429U, 907),		//1e+292
		diy_fp(13772540099066387757U, 933),		//1e+300
		diy_fp(10261342003245940623U, 960),		//1e+308
		diy_fp(15290591125556738113U, 986),		//1e+316
		diy_fp(11392378155556871081U, 1013),	//1e+324
		diy_fp(16975966327722178521U, 1039),	//1e+332
		diy_fp(12648080533535911531U, 1066),	//1e+340
	};
	static const int firstpow10 = -348; // first cached power of 10
	static const int cachestep	= 8;	// power of 10 steps between cache items
	static const int alpha		= -60;
	const double inv_log2_10	= 0.30102999566398114;

	// k calculation from the paper ceil((alpha - e + q - 1) / log2(10))
	// exponent is shifted by #bits
	int k0	= (int)ceil((alpha - e - 1) * inv_log2_10);
	int i	= (k0 - firstpow10 + cachestep - 1) / cachestep;

	// output the decimal power that corresponds to this k
	k = firstpow10 + i * cachestep;
	return pow10cache[i];
}

static int gen_digits(uint64 upper, uint64 delta, uint32 e, char *digits, int &k) {
//	uint64 delta	= upper.m - lower.m;

	// generate 1.0 to the desired exponent so we can split integer from decimal part
//	uint32	e		= -upper.e;
	uint64	m		= uint64(1) << e;

	// mask off integer and decimal parts
	uint32 intpart	= uint32(upper >> e);
	uint64 decpart	= upper & (m - 1);

	int		len		= 0;
	int		kappa	= 10;
	uint32	div		= 1000000000; // highest possible pow10 in 32bits = 10^9

	// handle integer component before decimal separator
	while (kappa > 0) {
		// don't include preceeding 0 digits
		if (len || intpart >= div) {
			digits[len++] = '0' + intpart / div;
			intpart %= div;
		}

		kappa--;
		div /= 10;

		// delta is the difference between upper and lower, and the left side is the current remainder after the currently generated digits have been removed.
		// If that is small enough that we've produced the number, exit and increment k to account for the extra exponential
		if ((uint64(intpart) << e) + decpart <= delta) {
			k -= kappa;
			return len;
		}
	}

	// note, after this part if we're still here, intpart is 0 as we've masked off all digits, so only decpart remains.
	// Kappa has also reached 0, beyond here it decrements below 0

	// handle decimal portion after separator
	do {
		decpart *= 10;
		uint32 digit = uint32(decpart >> e);

		// don't include preceeding 0s
		if (digit || len)
			digits[len++] = '0' + digit;

		// remove this pow10 from the decimal part
		decpart &= m - 1;
		kappa--;
		delta *= 10;

		// stop looping when decpart is lower than delta (see above for termination condition)
	} while (decpart > delta);

	k -= kappa;
	return len;
}

int grisu2(double w, char *digits, int &k, int maxdigits) {
	uint64	m	= float_components<double>(w).m;
	int		e	= float_components<double>(w).e;
	uint64	m0	= m;

	if (e == 0) {
		// subnormals
		int	s = 52 - highest_set_index(m);
		m <<= s;
		e = 1 - (1023 + 52) - s;
	} else {
		m |= uint64(1) << 52;
		e -= (1023 + 52);
	}

	diy_fp	upper((m << 11) + (1 << 10), e - 11);
	diy_fp	delta((1 << 10) + (m0 == 0 ? (1 << 9) : (1 << 10)), e - 11);

	if (maxdigits) {
		uint64	t = uint64(1) << 63;
		for (int i = maxdigits; i--;)
			t /= 10;
		upper = diy_fp((m << 11) + t / 2, e - 11);
		delta = diy_fp(t, e - 11);
	}

	diy_fp	ck	= find_cachedpow10(upper.e, k);
	upper = upper * ck;
	delta = delta * ck;

//	ISO_ASSERT(delta.m == upper.m - lower.m);

	// squeeze the range in by 1 ULP
	//lower.m++;
	//upper.m--;
//	uint64	delta = upper.m - lower.m;
//	if (maxdigits)
//		delta = 

	return gen_digits(upper.m, delta.m, -upper.e, digits, k);
}

//-----------------------------------------------------------------------------
//	format
//-----------------------------------------------------------------------------

template<typename C> inline C *fill_char(C *p, int n, int c = ' ') {
	while (n-- > 0)
		*p++ = c;
	return p;
}
template<typename C> inline C *put_sign(C *p, bool sign, uint32 flags) {
	if (sign)
		*p++ = '-';
	else if (flags & VS_PLUS)
		*p++ = '+';
	else if (flags & VS_BLANK)
		*p++ = ' ';
	return p;
}

template<int B, typename T> int get_exp(T &f) {
	int	exp = 0;
	if (f < 1) {
		if (f)
			do exp--; while ((f *= B) < 1);
	} else while (f >= B) {
		f /= B;
		exp++;
	}
	return exp;
}
template<int B, typename T, typename C> C *put_float(C *p, T &f, int n, C ten = 'A') {
	while (n--) {
		int	i = (int)f;
		*p++ = to_digit(i, ten);
		f = (f - i) * B;
	}
	return p;
}
template<int B, typename T> int get_floatlen(T f, int n) {
	int	r = 0;
	for (int i = 1; i <= n; i++) {
		if (f >= 1)
			r = i;
		f = (f - int(f)) * B;
	}
	return r;
}

template<typename T, bool S = num_traits<T>::is_signed> struct absval {
	ISO_METATYPE(_uint_type<sizeof(T)>)	u;
	bool	neg;
	absval(T t) : u(t < 0 ? -t : t), neg(t < 0) {}
};
template<typename T> struct absval<T, false> {
	T	u;
	static const bool neg = false;
	absval(T t) : u(t) {}
};
template<int B, typename T, typename C> C *put_num(C *p, T x, uint32 flags, int width) {
	absval<T>	a(x);
	bool	sign	= a.neg || (flags & (VS_PLUS | VS_BLANK));
	int		len		= len_num_base<B>(a.u);
	int		extra	= width - len - int(sign);
	if (!(flags & (VS_LEFTALIGN | VS_ZEROES)))
		p = fill_char(p, extra);
	p = put_sign(p, a.neg, flags);
	if ((flags & VS_ZEROES) && !(flags & VS_LEFTALIGN))
		p = fill_char(p, extra, '0');
	put_num_base<B>(p, len, a.u, flags & VS_UPPER ? 'A' : 'a');
	p += len;
	return flags & VS_LEFTALIGN ? fill_char(p, extra) : p;
}

static const char *special_num(iorf x)	{ return x.m ? "#QNAN" : x.s ? "-#INF" : "#INF"; }
static const char *special_num(iord x)	{ return x.m ? "#QNAN" : x.s ? "-#INF" : "#INF"; }
template<typename T> static const char *special_num(T x) { return special_num(float_components<T>(x)); }


template<int B, typename T, typename C> void put_num(accum<C> &acc, T x, uint32 flags, int width) {
	absval<T>	a(x);
	bool	sign	= a.neg || (flags & (VS_PLUS | VS_BLANK));
	int		len		= len_num_base<B>(a.u);
	int		total	= max(width, len + int(sign));
	C		*p		= acc.getp(total);

	int		extra	= width - len - int(sign);
	if (!(flags & (VS_LEFTALIGN | VS_ZEROES)))
		p = fill_char(p, extra);
	p = put_sign(p, a.neg, flags);
	if ((flags & VS_ZEROES) && !(flags & VS_LEFTALIGN))
		p = fill_char(p, extra, '0');
	put_num_base<B>(p, len, a.u, flags & VS_UPPER ? 'A' : 'a');
	if (flags & VS_LEFTALIGN)
		fill_char(p + len, extra);
}

template<typename C> void put_str(accum<C> &acc, const C *s, uint32 flags, int width, uint32 precision) {
	uint32	len	= flags & VS_PRECISION
		? string_len32(s, s + precision)
		: string_len32(s);

	width	= max(width, len);
	C	*p	= acc.getp(width);

	len		= min(width, len);
	if (!(flags & VS_LEFTALIGN))
		p = fill_char(p, width - len);
	for (int i = len; i--;)
		*p++ = *s++;
	if (flags & VS_LEFTALIGN)
		p = fill_char(p, width - len);
}

template<typename C1, typename C2> void put_str(accum<C1> &acc, const C2 *s, uint32 flags, int width, uint32 precision) {
	put_str(acc, alloc_string<C1>(s).begin(), flags, width, precision);
}

template<typename C> accum<C>& accum<C>::vformat(const C *format, va_list argptr) {
	C		c;
	if (format) for (const C *in = format; c = *in; in++) {
		if (c == '%') {
			if (in[1] == '%') {
				putc(c);
				in++;
				continue;
			}
			uint32	flags		= 0;
			uint32	precision	= 6;
			int		width		= 0;
			for (bool stop = false; !stop;) switch (*++in) {
				case '-': flags |= VS_LEFTALIGN;	break;
				case '+': flags |= VS_PLUS;			break;
				case '0': flags |= VS_ZEROES;		break;
				case ' ': flags |= VS_BLANK;		break;
				case '#': flags |= VS_CFORMAT;		break;
				default: stop = true; break;
			}
			if (*in == '*') {
				in++;
				width = va_arg(argptr, int);
			} else {
				in = get_num_base<10>(in, width);
			}
//			if (width && out + width > guard)
//				break;

			if (*in == '.') {
				flags |= VS_PRECISION;
				if (in[1] == '*') {
					in += 2;
					precision = va_arg(argptr, int);
				} else {
					in = get_num_base<10>(in + 1, precision);
				}
			}
			switch (*in) {
				case 'h':
					flags |= VS_SHORT;
					in++;
					break;
				case 'l':
					in++;
					flags |= VS_LONG;
					if (*in == 'l') {
						flags |= VS_LONGLONG;
						in++;
					}
					break;
				case 'I':
					if (in[1] == '3' && in[2] == '2') {
						flags |= VS_32BIT;
						in += 3;
					} else if (in[1] == '6' && in[2] == '4') {
						flags |= VS_64BIT;
						in += 3;
					}
					break;
			}
			switch (C fmt = *in) {
				case 'c':
					if (!(flags & VS_LEFTALIGN))
						putc(' ', width - 1);
					putc(va_arg(argptr, int));
					if (flags & VS_LEFTALIGN)
						putc(' ', width - 1);
					break;

				case 'd': case 'i':
					if (flags & VS_64BIT) {
						put_num<10>(*this, va_arg(argptr, int64), flags, width);
					} else {
						int	 val = va_arg(argptr, int);
						put_num<10>(*this, flags & VS_SHORT ? (short)val : val, flags, width);
					}
					break;

				case 'b':
					if (flags & VS_64BIT) {
						put_num<2>(*this, va_arg(argptr, uint64), flags, width);
					} else {
						uint32	val = va_arg(argptr, uint32);
						put_num<2>(*this, flags & VS_SHORT ? (uint16)val : val, flags, width);
					}
					break;

				case 'B': {
					uint32	val = va_arg(argptr, uint32);
					put_str(*this, val ? "true" : "false", flags & ~VS_PRECISION, width, 0);
					break;
				}

				case 'o':
					if (flags & VS_64BIT) {
						put_num<8>(*this, va_arg(argptr, uint64), flags, width);
					} else {
						uint32	val = va_arg(argptr, uint32);
						put_num<8>(*this, flags & VS_SHORT ? (uint16)val : val, flags, width);
					}
					break;

				case 'u':
					if (flags & VS_64BIT) {
						put_num<10>(*this, va_arg(argptr, uint64), flags, width);
					} else {
						uint32	val = va_arg(argptr, uint32);
						put_num<10>(*this, flags & VS_SHORT ? (uint16)val : val, flags, width);
					}
					break;

				case 'x': case 'X': {
					uint32	flags2 = flags | (fmt == 'X' ? VS_UPPER : 0);
					if (flags & VS_64BIT) {
						put_num<16>(*this, va_arg(argptr, uint64), flags2, width);
					} else {
						uint32	val = va_arg(argptr, uint32);
						put_num<16>(*this, flags & VS_SHORT ? (uint16)val : val, flags2, width);
					}
					break;
				}
				case 'p': case 'P': {
					uint32	flags2 = flags | (fmt == 'P' ? VS_UPPER : 0);
					put_num<16>(*this, va_arg(argptr, uintptr_t), flags2, width);
					break;
				}
				case 'e': case 'E': {
					float	val = (float)va_arg(argptr, double);
					if (iorf(val).is_special()) {
						put_str(*this, special_num(val), flags & ~VS_PRECISION, width, 0);
						break;
					}
					bool	sign = val < 0;
					if (sign)
						val = -val;
#if 0
					int		exp	= get_exp<10>(val);
					if (val) {
						val += 0.5f / pow(10, precision);
						if (val >= 10) {
							val /= 10;
							exp++;
						}
					}
					if (!(flags & VS_PRECISION))
						precision = get_floatlen<10>(val, 6);
					int		len	= precision + int(precision > 0) + 5 + int(sign || (flags & (VS_PLUS | VS_BLANK)));
					if (!(flags & VS_LEFTALIGN))
						out = fill_char(out, width - len);
					out = put_float<10>(put_sign(out, sign, flags), val, 1);
					if (precision) {
						*out++ = decimal_point;
						out = put_float<10>(out, val, precision);
					}
					*out++ = fmt;
					out = put_num<10>(out, exp, VS_PLUS | VS_ZEROES, 3);
#else
					char	digits[18];
					int		k, n = grisu2(val, digits, k, flags & VS_PRECISION ? precision : 0);

					if (!(flags & VS_PRECISION))
						precision = n;
					else if (n > precision)
						n = precision;

					int		len	= precision + int(precision > 0) + 5 + int(sign || (flags & (VS_PLUS | VS_BLANK)));
					C		*p	= getp(len);
					if (!(flags & VS_LEFTALIGN))
						p = fill_char(p, width - len);

					p = put_sign(p, sign, flags);
					*p++ = digits[0];
					if (precision) {
						*p++ = decimal_point;
						for (int i = 1; i < n; i++)
							*p++ = digits[i];
						for (int i = n; i < precision; i++)
							*p++ = '0';
					}
					*p++ = fmt;
					p = put_num<10>(p, n - k - 1, VS_PLUS | VS_ZEROES, 3);
#endif
					if (flags & VS_LEFTALIGN)
						p = fill_char(p, width - len);
					break;
				}
				case 'f': {
					float	val = (float)va_arg(argptr, double);
					if (iorf(val).is_special()) {
						put_str(*this, special_num(val), flags & ~VS_PRECISION, width, 0);
						break;
					}
					bool	sign = val < 0;
					if (sign)
						val = -val;
#if 1
					int		exp	= get_exp<10>(val);
					if (val) {
						val += 0.5f / pow(10, exp + precision);
						if (val >= 10) {
							val /= 10;
							exp++;
						}
					}
					if (!(flags & VS_PRECISION))
						precision = max(get_floatlen<10>(val, exp + 6) - exp, 0);
					int		len	= precision + int(precision > 0) + 1 + max(exp, 0) + int(sign || (flags & (VS_PLUS | VS_BLANK)));
					C		*p	= getp(len);

					if (!(flags & VS_LEFTALIGN))
						p = fill_char(p, width - len);
					p = put_sign(p, sign, flags);
					if (exp < 0)
						*p++ = '0';
					else
						p = put_float<10>(p, val, exp + 1);

					if (precision) {
						*p++ = decimal_point;
						while (precision && exp < -1) {
							exp++;
							precision--;
							*p++ = '0';
						}
						p = put_float<10>(p, val, precision);
					}
#else
					char	digits[18];
					int		k, n = grisu2(val, digits, k, flags & VS_PRECISION ? precision : 0);

					if (!(flags & VS_PRECISION))
						precision = n;
					else if (n > precision)
						n = precision;

					int		len	= precision + int(precision > 0) + 5 + int(sign || (flags & (VS_PLUS | VS_BLANK)));
					if (!(flags & VS_LEFTALIGN))
						out = fill_char(out, width - len);

					out = put_sign(out, sign, flags);
					if (exp < 0)
						*out++ = '0';
					else
						for (int i = 0; i < n; i++)
							*out++ = digits[i];
					if (precision) {
						*out++ = decimal_point;
						while (precision && exp < -1) {
							exp++;
							precision--;
							*out++ = '0';
						}
						for (int i = 0; i < n; i++)
							*out++ = digits[i];
					}
#endif
					if (flags & VS_LEFTALIGN)
						p = fill_char(p, width - len);
					break;
				}
				case 'g': case 'G': {
					float	val = (float)va_arg(argptr, double);
					if (iorf(val).is_special()) {
						put_str(*this, special_num(val), flags & ~VS_PRECISION, width, 0);
						break;
					}
					bool	sign = val < 0;
					if (sign)
						val = -val;
					int		exp	= get_exp<10>(val);
					if (val) {
						val += 5.f / pow(10, precision);
						if (val >= 10) {
							val /= 10;
							exp++;
						}
					}
					if (!(flags & VS_PRECISION))
						precision = max(get_floatlen<10>(val, 6), min(exp + 1, int(precision)));
					int		len = int(sign || (flags & (VS_PLUS | VS_BLANK)));
					C		*p;

					if (exp < -4 || exp >= int(precision)) {
						if (precision)
							precision--;
						len	+= precision + int(precision > 0) + 5;
						p	= getp(len);
						if (!(flags & VS_LEFTALIGN))
							p = fill_char(p, width - len);
						p = put_float<10>(put_sign(p, sign, flags), val, 1);
						if (precision) {
							*p++ = decimal_point;
							p = put_float<10>(p, val, precision);
						}
						*p++ = fmt - 2;
						p = put_num<10>(p, exp, VS_PLUS | VS_ZEROES, 3);
					} else {
						len	+= precision + int(precision > exp + 1) - min(exp, 0);
						p	= getp(len);
						if (!(flags & VS_LEFTALIGN))
							p = fill_char(p, width - len);
						p = put_sign(p, sign, flags);
						if (exp < 0) {
							*p++ = '0';
							*p++ = decimal_point;
							while (exp < -1) {
								exp++;
								*p++ = '0';
							}
						} else {
							p = put_float<10>(p, val, exp + 1);
							precision -= exp + 1;
							if (precision)
								*p++ = decimal_point;
						}
						p = put_float<10>(p, val, precision);
					}
					if (flags & VS_LEFTALIGN)
						p = fill_char(p, width - len);
					break;
				}
				case 'a': case 'A': {
					float	val = (float)va_arg(argptr, double);
					if (iorf(val).is_special()) {
						put_str(*this, special_num(val), flags & ~VS_PRECISION, width, 0);
						break;
					}
					bool	sign = val < 0;
					if (sign)
						val = -val;
					int		exp	= get_exp<16>(val);
					if (val) {
						val += 0.5f / pow(16, precision);
						if (val >= 16) {
							val /= 16;
							exp++;
						}
					}
					if (!(flags & VS_PRECISION))
						precision = get_floatlen<16>(val, 6);
					int		len	= precision + int(precision > 0) + 7 + (sign || (flags & (VS_PLUS | VS_BLANK)));
					C		*p	= getp(len);

					if (!(flags & VS_LEFTALIGN))
						p = fill_char(p, width - len);
					p = put_sign(p, sign, flags);
					*p++ = '0';
					*p++ = fmt + ('x' - 'a');
					p = put_float<16>(p, val, 1, fmt);

					if (precision) {
						*p++ = decimal_point;
						p = put_float<16>(p, val, precision, fmt);
					}
					*p++ = fmt + ('p' - 'a');
					p = put_num<10>(p, exp, VS_PLUS | VS_ZEROES, 3);
					if (flags & VS_LEFTALIGN)
						p = fill_char(p, width - len);
					break;
				}
				case 'n': {
					int	*ptr = va_arg(argptr, int*);
					*ptr = int(getp() - startp);
					break;
				}
				case 's': {
					char *s = va_arg(argptr, char*);
					put_str(*this, s ? s : "(null)", flags, width, precision);
					break;
				}
				case 'S': {
					char16 *s = va_arg(argptr, char16*);
					put_str(*this, s ? s : (char16*)u"(null)", flags, width, precision);
					break;
				}
			}
		} else {
			putc(c);
		}
	}
	return *this;
}

template accum<char>& accum<char>::vformat(const char *format, va_list argptr);
template accum<char16>& accum<char16>::vformat(const char16 *format, va_list argptr);

#if 0
template<> string_accum16& string_accum16::vformat(const char16 *format, va_list argptr) {
	struct temp_accum : buffered_accum<temp_accum, char, 256> {
		string_accum16		&a;
		void		flush(const char *s, size_t n)	{ a.merge(s, n); }
		temp_accum(string_accum16 &_a) : a(_a) {}
	};
	temp_accum(*this).vformat(str8(format), argptr);
	return *this;
}
#endif
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


template<typename T> size_t put_float(char *s, T f) {
	char	*out		= s;
	uint32	precision	= 6;

	if (float_components<T>(f).is_special()) {
		strcpy(s, special_num(f));
		return strlen(s);
	}

	bool	sign = f < 0;
	if (sign) {
		*out++ = '-';
		f = -f;
	}
	int		exp	= get_exp<10>(f);
	if (f) {
		f += 5.f / pow(10, precision);
		if (f >= 10) {
			f /= 10;
			exp++;
		}
	}
	precision = max(get_floatlen<10>(f, 6), min(exp + 1, int(precision)));

	if (exp < -4 || exp >= int(precision)) {
		if (precision)
			precision--;
		out = put_float<10>(out, f, 1);
		if (precision) {
			*out++ = decimal_point;
			out = put_float<10>(out, f, precision);
		}
		*out++ = 'e';
		out = put_num<10>(out, exp, VS_PLUS | VS_ZEROES, 3);
	} else {
		if (exp < 0) {
			*out++ = '0';
			*out++ = decimal_point;
			while (exp < -1) {
				exp++;
				*out++ = '0';
			}
		} else {
			out = put_float<10>(out, f, exp + 1);
			precision -= exp + 1;
			if (precision)
				*out++ = decimal_point;
		}
		out = put_float<10>(out, f, precision);
	}
	return out - s;
}

size_t	to_string(char *s, float f)		{ return put_float(s, f);	}
size_t	to_string(char *s, double f)	{ return put_float(s, f);	}

enum {
	FF_PLUS		= VS_PLUS,
	FF_BLANK	= VS_BLANK,
	FF_ZEROES	= VS_ZEROES,
	FF_EFORMAT,
	FF_FFORMAT,
	FF_GFORMAT,
};

size_t format_float(char *s, float val, int align, int precision, uint32 flags) {
	char	*out	= s;
	if (iorf(val).is_special()) {
		const char *sp = special_num(val);
		int	len	= int(strlen(sp));
		out = fill_char(out, -align - len);
		for (int i = len; i--;)
			*out++ = *s++;
		out = fill_char(out, align - len);
		return out - s;
	}

	bool	sign = val < 0;
	if (sign)
		val = -val;

	int		exp	= get_exp<10>(val);
	if (val) {
		val += 5.f / pow(10, uint32(precision < 0 ? 6 : precision));
		if (val >= 10) {
			val /= 10;
			exp++;
		}
	}

	if (precision < 0)
		precision = max(get_floatlen<10>(val, 6), min(exp + 1, int(precision)));

	int		len = int(sign || (flags & (FF_PLUS | FF_BLANK)));

	if (exp < -4 || exp >= precision) {
		if (precision)
			precision--;

		len	+= precision + int(precision > 0) + 5;
		out = fill_char(out, -align - len);

		out = put_float<10>(put_sign(out, sign, flags), val, 1);
		if (precision) {
			*out++ = decimal_point;
			out = put_float<10>(out, val, precision);
		}
		*out++ = 'e';
		out = put_num<10>(out, exp, VS_PLUS | VS_ZEROES, 3);

	} else {
		len	+= precision + int(precision > exp + 1) - min(exp, 0);
		out = fill_char(out, -align - len);
		out = put_sign(out, sign, flags);

		if (exp < 0) {
			*out++ = '0';
			*out++ = decimal_point;
			while (exp < -1) {
				exp++;
				*out++ = '0';
			}
		} else {
			out = put_float<10>(out, val, exp + 1);
			precision -= exp + 1;
			if (precision)
				*out++ = decimal_point;
		}
		out = put_float<10>(out, val, precision);
	}
	return fill_char(out, align - len) - s;
}

void tabs::tab(char *p0, char *p1) const {
	uint32	s	= 0;
	for (char *pp = p0, *pt = p; pp < p1; ++pp) {
		if (*pp == '\t') {
			s += w - (pp - pt) % w - 1;
			pt = pp + 1;
		}
	}

	if (s) {
		a->move(s);
		char	*p2		= a->getp();
		char	*tab	= string_rfind(p0, '\t', p1);
		size_t	n		= p1 - tab - 1;

		p1	= tab;
		p2 -= n;
		memcpy(p2, tab + 1, n);

		while (char *tab = string_rfind(p0, '\t', p1)) {
			n	= p1 - tab - 1;
			s	= w - n % w;
			p2 -= s;
			memset(p2, ' ', s);

			p1	= tab;
			p2 -= n;
			memcpy(p2, tab + 1, n);
		}

		s	= w - (p1 - p) % w;
		memset(p1, ' ', s);
	}
}

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
//	soft_float
//-----------------------------------------------------------------------------

void soft_float_make_table(float *table, uint32 mb, uint32 eb, bool sb) {
	int		eo	= 128 - (1 << (eb - 1));
	iorf	*p	= (iorf*)table;
	for (int s = 0; s < 1 << int(sb); s++) {
		//zero
		*p++ = iorf(0, 0, s).f;
		//denormals
		for (int m = 1; m < 1 << mb; m++) {
			int	h = highest_set_index(m);
			*p++ = iorf(m << (23 - h), eo - mb + h + 1, s).f;
		}
		//normals
		for (int e = 1; e < 1 << eb; e++)
			for (int m = 0; m < 1 << mb; m++)
				*p++ = iorf(m << (23 - mb), e + eo, s).f;
	}
};

//-----------------------------------------------------------------------------
//	gamma/lgamma
//-----------------------------------------------------------------------------

#if 1
//from john d cook
//only for x < 12
double gamma_direct(double x) {
	// The algorithm directly approximates gamma over (1,2) and uses reduction identities to reduce other arguments to this interval.
	double	y = x;
	int		n = 0;

	// bring y into (1,2)
	if (x < 1) {
		y += 1;
	} else {
		n = static_cast<int>(floor(y)) - 1;
		y -= n;
	}

	static const double p[] = {
		-1.71618513886549492533811E+0,
		 2.47656508055759199108314E+1,
		-3.79804256470945635097577E+2,
		 6.29331155312818442661052E+2,
		 8.66966202790413211295064E+2,
		-3.14512729688483675254357E+4,
		-3.61444134186911729807069E+4,
		 6.64561438202405440627855E+4
	};

	static const double q[] = {
		-3.08402300119738975254353E+1,
		 3.15350626979604161529144E+2,
		-1.01515636749021914166146E+3,
		-3.10777167157231109440444E+3,
		 2.25381184209801510330112E+4,
		 4.75584627752788110767815E+3,
		-1.34659959864969306392456E+5,
		-1.15132259675553483497211E+5
	};

	double	num = 0;
	double	den = 1;

	double	z = y - 1;
	for (int i = 0; i < 8; i++) {
		num = (num + p[i]) * z;
		den = den * z + q[i];
	}
	double result = num / den + 1;

	// Apply correction if argument was not initially in (1,2)
	if (x < 1) {
		// Use identity gamma(z) = gamma(z+1)/z
		result /= (y - 1);
	} else {
		// Use the identity gamma(z+n) = z*(z+1)* ... *(z+n-1)*gamma(z)
		for (int i = 0; i < n; i++)
			result *= y++;
	}
	return result;
}

//only for x >= 12
double lgamma_direct(double x) {
	static const double c[8] = {
		1.0		/ 12.0,
		-1.0	/ 360.0,
		1.0		/ 1260.0,
		-1.0	/ 1680.0,
		1.0		/ 1188.0,
		-691.0	/ 360360.0,
		1.0		/ 156.0,
		-3617.0 / 122400.0
	};
	double z	= 1 / (x * x);
	double sum	= c[7];
	for (int i = 6; i >= 0; i--)
		sum = sum * z + c[i];

	static const double halfLogTwoPi = 0.91893853320467274178032973640562;
	return (x - 0.5) * ln(x) - x + sum / x + halfLogTwoPi;
}

double lgamma(double x) { // x must be positive
	if (x <= 0)
		return nan;

	if (x < 12)
		return ln(abs(gamma_direct(x)));

	return lgamma_direct(x);
}

double gamma(double x) {
	const double gamma = 0.577215664901532860606512090; // Euler's gamma constant

	if (x <= 0)
		return nan;

	// For small x, 1/Gamma(x) has power series x + gamma x^2 - ...
	if (x < 0.001)
		return 1 / (x * (1 + gamma * x));

	if (x < 12)
		return gamma_direct(x);

	if (x > 171.624)
		return infinity;

	return exp(lgamma(x));
}

#else
// from stl
float lgamma(float x) {	// moderately accurate log gamma
	static const float coeff[6] = {
		 76.18009172947146f,
		-86.50532032941677f,
		 24.01409824083091f,
		 -1.23173972450155f,
		  0.1208650973866179E-2f,
		 -0.5395239384953E-5f
	};

	float v0 = x + 5.5f;
	float v1 = 1.000000000190015f;

	for (int i = 0; i < 6; ++i)
		v1 += coeff[i] / (x + (i + 1));

	return log(2.5066282746310005f * v1 / x) - v0 + (x + 0.5f) * log(v0);
}

double lgamma(double x) {	// moderately accurate log gamma
	static const double coeff[6] = {
		 76.18009172947146,
		-86.50532032941677,
		 24.01409824083091,
		 -1.23173972450155,
		  0.1208650973866179E-2,
		 -0.5395239384953E-5
	};

	double v0 = x + 5.5;
	double v1 = 1.000000000190015;

	for (int i = 0; i < 6; ++i)
		v1 += coeff[i] / (x + (i + 1));
	return log(2.5066282746310005 * v1 / x) - v0 + (x + 0.5) * log(v0);
}
#endif

//-----------------------------------------------------------------------------
//	PRIME
//-----------------------------------------------------------------------------

const uint16 primes[2048] = {
        2,     3,     5,     7,    11,    13,    17,    19,       23,    29,    31,    37,    41,    43,    47,    53,
       59,    61,    67,    71,    73,    79,    83,    89,       97,   101,   103,   107,   109,   113,   127,   131,
      137,   139,   149,   151,   157,   163,   167,   173,      179,   181,   191,   193,   197,   199,   211,   223,
      227,   229,   233,   239,   241,   251,   257,   263,      269,   271,   277,   281,   283,   293,   307,   311,
      313,   317,   331,   337,   347,   349,   353,   359,      367,   373,   379,   383,   389,   397,   401,   409,
      419,   421,   431,   433,   439,   443,   449,   457,      461,   463,   467,   479,   487,   491,   499,   503,
      509,   521,   523,   541,   547,   557,   563,   569,      571,   577,   587,   593,   599,   601,   607,   613,
      617,   619,   631,   641,   643,   647,   653,   659,      661,   673,   677,   683,   691,   701,   709,   719,
      727,   733,   739,   743,   751,   757,   761,   769,      773,   787,   797,   809,   811,   821,   823,   827,
      829,   839,   853,   857,   859,   863,   877,   881,      883,   887,   907,   911,   919,   929,   937,   941,
      947,   953,   967,   971,   977,   983,   991,   997,     1009,  1013,  1019,  1021,  1031,  1033,  1039,  1049,
     1051,  1061,  1063,  1069,  1087,  1091,  1093,  1097,     1103,  1109,  1117,  1123,  1129,  1151,  1153,  1163,
     1171,  1181,  1187,  1193,  1201,  1213,  1217,  1223,     1229,  1231,  1237,  1249,  1259,  1277,  1279,  1283,
     1289,  1291,  1297,  1301,  1303,  1307,  1319,  1321,     1327,  1361,  1367,  1373,  1381,  1399,  1409,  1423,
     1427,  1429,  1433,  1439,  1447,  1451,  1453,  1459,     1471,  1481,  1483,  1487,  1489,  1493,  1499,  1511,
     1523,  1531,  1543,  1549,  1553,  1559,  1567,  1571,     1579,  1583,  1597,  1601,  1607,  1609,  1613,  1619,
     1621,  1627,  1637,  1657,  1663,  1667,  1669,  1693,     1697,  1699,  1709,  1721,  1723,  1733,  1741,  1747,
     1753,  1759,  1777,  1783,  1787,  1789,  1801,  1811,     1823,  1831,  1847,  1861,  1867,  1871,  1873,  1877,
     1879,  1889,  1901,  1907,  1913,  1931,  1933,  1949,     1951,  1973,  1979,  1987,  1993,  1997,  1999,  2003,
     2011,  2017,  2027,  2029,  2039,  2053,  2063,  2069,     2081,  2083,  2087,  2089,  2099,  2111,  2113,  2129,
     2131,  2137,  2141,  2143,  2153,  2161,  2179,  2203,     2207,  2213,  2221,  2237,  2239,  2243,  2251,  2267,
     2269,  2273,  2281,  2287,  2293,  2297,  2309,  2311,     2333,  2339,  2341,  2347,  2351,  2357,  2371,  2377,
     2381,  2383,  2389,  2393,  2399,  2411,  2417,  2423,     2437,  2441,  2447,  2459,  2467,  2473,  2477,  2503,
     2521,  2531,  2539,  2543,  2549,  2551,  2557,  2579,     2591,  2593,  2609,  2617,  2621,  2633,  2647,  2657,
     2659,  2663,  2671,  2677,  2683,  2687,  2689,  2693,     2699,  2707,  2711,  2713,  2719,  2729,  2731,  2741,
     2749,  2753,  2767,  2777,  2789,  2791,  2797,  2801,     2803,  2819,  2833,  2837,  2843,  2851,  2857,  2861,
     2879,  2887,  2897,  2903,  2909,  2917,  2927,  2939,     2953,  2957,  2963,  2969,  2971,  2999,  3001,  3011,
     3019,  3023,  3037,  3041,  3049,  3061,  3067,  3079,     3083,  3089,  3109,  3119,  3121,  3137,  3163,  3167,
     3169,  3181,  3187,  3191,  3203,  3209,  3217,  3221,     3229,  3251,  3253,  3257,  3259,  3271,  3299,  3301,
     3307,  3313,  3319,  3323,  3329,  3331,  3343,  3347,     3359,  3361,  3371,  3373,  3389,  3391,  3407,  3413,
     3433,  3449,  3457,  3461,  3463,  3467,  3469,  3491,     3499,  3511,  3517,  3527,  3529,  3533,  3539,  3541,
     3547,  3557,  3559,  3571,  3581,  3583,  3593,  3607,     3613,  3617,  3623,  3631,  3637,  3643,  3659,  3671,
     3673,  3677,  3691,  3697,  3701,  3709,  3719,  3727,     3733,  3739,  3761,  3767,  3769,  3779,  3793,  3797,
     3803,  3821,  3823,  3833,  3847,  3851,  3853,  3863,     3877,  3881,  3889,  3907,  3911,  3917,  3919,  3923,
     3929,  3931,  3943,  3947,  3967,  3989,  4001,  4003,     4007,  4013,  4019,  4021,  4027,  4049,  4051,  4057,
     4073,  4079,  4091,  4093,  4099,  4111,  4127,  4129,     4133,  4139,  4153,  4157,  4159,  4177,  4201,  4211,
     4217,  4219,  4229,  4231,  4241,  4243,  4253,  4259,     4261,  4271,  4273,  4283,  4289,  4297,  4327,  4337,
     4339,  4349,  4357,  4363,  4373,  4391,  4397,  4409,     4421,  4423,  4441,  4447,  4451,  4457,  4463,  4481,
     4483,  4493,  4507,  4513,  4517,  4519,  4523,  4547,     4549,  4561,  4567,  4583,  4591,  4597,  4603,  4621,
     4637,  4639,  4643,  4649,  4651,  4657,  4663,  4673,     4679,  4691,  4703,  4721,  4723,  4729,  4733,  4751,
     4759,  4783,  4787,  4789,  4793,  4799,  4801,  4813,     4817,  4831,  4861,  4871,  4877,  4889,  4903,  4909,
     4919,  4931,  4933,  4937,  4943,  4951,  4957,  4967,     4969,  4973,  4987,  4993,  4999,  5003,  5009,  5011,
     5021,  5023,  5039,  5051,  5059,  5077,  5081,  5087,     5099,  5101,  5107,  5113,  5119,  5147,  5153,  5167,
     5171,  5179,  5189,  5197,  5209,  5227,  5231,  5233,     5237,  5261,  5273,  5279,  5281,  5297,  5303,  5309,
     5323,  5333,  5347,  5351,  5381,  5387,  5393,  5399,     5407,  5413,  5417,  5419,  5431,  5437,  5441,  5443,
     5449,  5471,  5477,  5479,  5483,  5501,  5503,  5507,     5519,  5521,  5527,  5531,  5557,  5563,  5569,  5573,
     5581,  5591,  5623,  5639,  5641,  5647,  5651,  5653,     5657,  5659,  5669,  5683,  5689,  5693,  5701,  5711,
     5717,  5737,  5741,  5743,  5749,  5779,  5783,  5791,     5801,  5807,  5813,  5821,  5827,  5839,  5843,  5849,
     5851,  5857,  5861,  5867,  5869,  5879,  5881,  5897,     5903,  5923,  5927,  5939,  5953,  5981,  5987,  6007,
     6011,  6029,  6037,  6043,  6047,  6053,  6067,  6073,     6079,  6089,  6091,  6101,  6113,  6121,  6131,  6133,
     6143,  6151,  6163,  6173,  6197,  6199,  6203,  6211,     6217,  6221,  6229,  6247,  6257,  6263,  6269,  6271,
     6277,  6287,  6299,  6301,  6311,  6317,  6323,  6329,     6337,  6343,  6353,  6359,  6361,  6367,  6373,  6379,
     6389,  6397,  6421,  6427,  6449,  6451,  6469,  6473,     6481,  6491,  6521,  6529,  6547,  6551,  6553,  6563,
     6569,  6571,  6577,  6581,  6599,  6607,  6619,  6637,     6653,  6659,  6661,  6673,  6679,  6689,  6691,  6701,
     6703,  6709,  6719,  6733,  6737,  6761,  6763,  6779,     6781,  6791,  6793,  6803,  6823,  6827,  6829,  6833,
     6841,  6857,  6863,  6869,  6871,  6883,  6899,  6907,     6911,  6917,  6947,  6949,  6959,  6961,  6967,  6971,
     6977,  6983,  6991,  6997,  7001,  7013,  7019,  7027,     7039,  7043,  7057,  7069,  7079,  7103,  7109,  7121,
     7127,  7129,  7151,  7159,  7177,  7187,  7193,  7207,     7211,  7213,  7219,  7229,  7237,  7243,  7247,  7253,
     7283,  7297,  7307,  7309,  7321,  7331,  7333,  7349,     7351,  7369,  7393,  7411,  7417,  7433,  7451,  7457,
     7459,  7477,  7481,  7487,  7489,  7499,  7507,  7517,     7523,  7529,  7537,  7541,  7547,  7549,  7559,  7561,
     7573,  7577,  7583,  7589,  7591,  7603,  7607,  7621,     7639,  7643,  7649,  7669,  7673,  7681,  7687,  7691,
     7699,  7703,  7717,  7723,  7727,  7741,  7753,  7757,     7759,  7789,  7793,  7817,  7823,  7829,  7841,  7853,
     7867,  7873,  7877,  7879,  7883,  7901,  7907,  7919,     7927,  7933,  7937,  7949,  7951,  7963,  7993,  8009,
     8011,  8017,  8039,  8053,  8059,  8069,  8081,  8087,     8089,  8093,  8101,  8111,  8117,  8123,  8147,  8161,
     8167,  8171,  8179,  8191,  8209,  8219,  8221,  8231,     8233,  8237,  8243,  8263,  8269,  8273,  8287,  8291,
     8293,  8297,  8311,  8317,  8329,  8353,  8363,  8369,     8377,  8387,  8389,  8419,  8423,  8429,  8431,  8443,
     8447,  8461,  8467,  8501,  8513,  8521,  8527,  8537,     8539,  8543,  8563,  8573,  8581,  8597,  8599,  8609,
     8623,  8627,  8629,  8641,  8647,  8663,  8669,  8677,     8681,  8689,  8693,  8699,  8707,  8713,  8719,  8731,
     8737,  8741,  8747,  8753,  8761,  8779,  8783,  8803,     8807,  8819,  8821,  8831,  8837,  8839,  8849,  8861,
     8863,  8867,  8887,  8893,  8923,  8929,  8933,  8941,     8951,  8963,  8969,  8971,  8999,  9001,  9007,  9011,
     9013,  9029,  9041,  9043,  9049,  9059,  9067,  9091,     9103,  9109,  9127,  9133,  9137,  9151,  9157,  9161,
     9173,  9181,  9187,  9199,  9203,  9209,  9221,  9227,     9239,  9241,  9257,  9277,  9281,  9283,  9293,  9311,
     9319,  9323,  9337,  9341,  9343,  9349,  9371,  9377,     9391,  9397,  9403,  9413,  9419,  9421,  9431,  9433,
     9437,  9439,  9461,  9463,  9467,  9473,  9479,  9491,     9497,  9511,  9521,  9533,  9539,  9547,  9551,  9587,
     9601,  9613,  9619,  9623,  9629,  9631,  9643,  9649,     9661,  9677,  9679,  9689,  9697,  9719,  9721,  9733,
     9739,  9743,  9749,  9767,  9769,  9781,  9787,  9791,     9803,  9811,  9817,  9829,  9833,  9839,  9851,  9857,
     9859,  9871,  9883,  9887,  9901,  9907,  9923,  9929,     9931,  9941,  9949,  9967,  9973, 10007, 10009, 10037,
    10039, 10061, 10067, 10069, 10079, 10091, 10093, 10099,    10103, 10111, 10133, 10139, 10141, 10151, 10159, 10163,
    10169, 10177, 10181, 10193, 10211, 10223, 10243, 10247,    10253, 10259, 10267, 10271, 10273, 10289, 10301, 10303,
    10313, 10321, 10331, 10333, 10337, 10343, 10357, 10369,    10391, 10399, 10427, 10429, 10433, 10453, 10457, 10459,
    10463, 10477, 10487, 10499, 10501, 10513, 10529, 10531,    10559, 10567, 10589, 10597, 10601, 10607, 10613, 10627,
    10631, 10639, 10651, 10657, 10663, 10667, 10687, 10691,    10709, 10711, 10723, 10729, 10733, 10739, 10753, 10771,
    10781, 10789, 10799, 10831, 10837, 10847, 10853, 10859,    10861, 10867, 10883, 10889, 10891, 10903, 10909, 10937,
    10939, 10949, 10957, 10973, 10979, 10987, 10993, 11003,    11027, 11047, 11057, 11059, 11069, 11071, 11083, 11087,
    11093, 11113, 11117, 11119, 11131, 11149, 11159, 11161,    11171, 11173, 11177, 11197, 11213, 11239, 11243, 11251,
    11257, 11261, 11273, 11279, 11287, 11299, 11311, 11317,    11321, 11329, 11351, 11353, 11369, 11383, 11393, 11399,
    11411, 11423, 11437, 11443, 11447, 11467, 11471, 11483,    11489, 11491, 11497, 11503, 11519, 11527, 11549, 11551,
    11579, 11587, 11593, 11597, 11617, 11621, 11633, 11657,    11677, 11681, 11689, 11699, 11701, 11717, 11719, 11731,
    11743, 11777, 11779, 11783, 11789, 11801, 11807, 11813,    11821, 11827, 11831, 11833, 11839, 11863, 11867, 11887,
    11897, 11903, 11909, 11923, 11927, 11933, 11939, 11941,    11953, 11959, 11969, 11971, 11981, 11987, 12007, 12011,
    12037, 12041, 12043, 12049, 12071, 12073, 12097, 12101,    12107, 12109, 12113, 12119, 12143, 12149, 12157, 12161,
    12163, 12197, 12203, 12211, 12227, 12239, 12241, 12251,    12253, 12263, 12269, 12277, 12281, 12289, 12301, 12323,
    12329, 12343, 12347, 12373, 12377, 12379, 12391, 12401,    12409, 12413, 12421, 12433, 12437, 12451, 12457, 12473,
    12479, 12487, 12491, 12497, 12503, 12511, 12517, 12527,    12539, 12541, 12547, 12553, 12569, 12577, 12583, 12589,
    12601, 12611, 12613, 12619, 12637, 12641, 12647, 12653,    12659, 12671, 12689, 12697, 12703, 12713, 12721, 12739,
    12743, 12757, 12763, 12781, 12791, 12799, 12809, 12821,    12823, 12829, 12841, 12853, 12889, 12893, 12899, 12907,
    12911, 12917, 12919, 12923, 12941, 12953, 12959, 12967,    12973, 12979, 12983, 13001, 13003, 13007, 13009, 13033,
    13037, 13043, 13049, 13063, 13093, 13099, 13103, 13109,    13121, 13127, 13147, 13151, 13159, 13163, 13171, 13177,
    13183, 13187, 13217, 13219, 13229, 13241, 13249, 13259,    13267, 13291, 13297, 13309, 13313, 13327, 13331, 13337,
    13339, 13367, 13381, 13397, 13399, 13411, 13417, 13421,    13441, 13451, 13457, 13463, 13469, 13477, 13487, 13499,
    13513, 13523, 13537, 13553, 13567, 13577, 13591, 13597,    13613, 13619, 13627, 13633, 13649, 13669, 13679, 13681,
    13687, 13691, 13693, 13697, 13709, 13711, 13721, 13723,    13729, 13751, 13757, 13759, 13763, 13781, 13789, 13799,
    13807, 13829, 13831, 13841, 13859, 13873, 13877, 13879,    13883, 13901, 13903, 13907, 13913, 13921, 13931, 13933,
    13963, 13967, 13997, 13999, 14009, 14011, 14029, 14033,    14051, 14057, 14071, 14081, 14083, 14087, 14107, 14143,
    14149, 14153, 14159, 14173, 14177, 14197, 14207, 14221,    14243, 14249, 14251, 14281, 14293, 14303, 14321, 14323,
    14327, 14341, 14347, 14369, 14387, 14389, 14401, 14407,    14411, 14419, 14423, 14431, 14437, 14447, 14449, 14461,
    14479, 14489, 14503, 14519, 14533, 14537, 14543, 14549,    14551, 14557, 14561, 14563, 14591, 14593, 14621, 14627,
    14629, 14633, 14639, 14653, 14657, 14669, 14683, 14699,    14713, 14717, 14723, 14731, 14737, 14741, 14747, 14753,
    14759, 14767, 14771, 14779, 14783, 14797, 14813, 14821,    14827, 14831, 14843, 14851, 14867, 14869, 14879, 14887,
    14891, 14897, 14923, 14929, 14939, 14947, 14951, 14957,    14969, 14983, 15013, 15017, 15031, 15053, 15061, 15073,
    15077, 15083, 15091, 15101, 15107, 15121, 15131, 15137,    15139, 15149, 15161, 15173, 15187, 15193, 15199, 15217,
    15227, 15233, 15241, 15259, 15263, 15269, 15271, 15277,    15287, 15289, 15299, 15307, 15313, 15319, 15329, 15331,
    15349, 15359, 15361, 15373, 15377, 15383, 15391, 15401,    15413, 15427, 15439, 15443, 15451, 15461, 15467, 15473,
    15493, 15497, 15511, 15527, 15541, 15551, 15559, 15569,    15581, 15583, 15601, 15607, 15619, 15629, 15641, 15643,
    15647, 15649, 15661, 15667, 15671, 15679, 15683, 15727,    15731, 15733, 15737, 15739, 15749, 15761, 15767, 15773,
    15787, 15791, 15797, 15803, 15809, 15817, 15823, 15859,    15877, 15881, 15887, 15889, 15901, 15907, 15913, 15919,
    15923, 15937, 15959, 15971, 15973, 15991, 16001, 16007,    16033, 16057, 16061, 16063, 16067, 16069, 16073, 16087,
    16091, 16097, 16103, 16111, 16127, 16139, 16141, 16183,    16187, 16189, 16193, 16217, 16223, 16229, 16231, 16249,
    16253, 16267, 16273, 16301, 16319, 16333, 16339, 16349,    16361, 16363, 16369, 16381, 16411, 16417, 16421, 16427,
    16433, 16447, 16451, 16453, 16477, 16481, 16487, 16493,    16519, 16529, 16547, 16553, 16561, 16567, 16573, 16603,
    16607, 16619, 16631, 16633, 16649, 16651, 16657, 16661,    16673, 16691, 16693, 16699, 16703, 16729, 16741, 16747,
    16759, 16763, 16787, 16811, 16823, 16829, 16831, 16843,    16871, 16879, 16883, 16889, 16901, 16903, 16921, 16927,
    16931, 16937, 16943, 16963, 16979, 16981, 16987, 16993,    17011, 17021, 17027, 17029, 17033, 17041, 17047, 17053,
    17077, 17093, 17099, 17107, 17117, 17123, 17137, 17159,    17167, 17183, 17189, 17191, 17203, 17207, 17209, 17231,
    17239, 17257, 17291, 17293, 17299, 17317, 17321, 17327,    17333, 17341, 17351, 17359, 17377, 17383, 17387, 17389,
    17393, 17401, 17417, 17419, 17431, 17443, 17449, 17467,    17471, 17477, 17483, 17489, 17491, 17497, 17509, 17519,
    17539, 17551, 17569, 17573, 17579, 17581, 17597, 17599,    17609, 17623, 17627, 17657, 17659, 17669, 17681, 17683,
    17707, 17713, 17729, 17737, 17747, 17749, 17761, 17783,    17789, 17791, 17807, 17827, 17837, 17839, 17851, 17863,
};

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
