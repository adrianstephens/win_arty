#ifndef DEFS_INT_H
#define DEFS_INT_H

#include "defs_base.h"

namespace iso {

//-----------------------------------------------------------------------------
//	integer types
//-----------------------------------------------------------------------------

template<typename T> struct T_isint						: T_false {};
template<typename T> struct T_isint<T&>					: T_isint<T> {};
template<typename T> struct T_isint<constructable<T> >	: T_isint<T> {};
template<typename T> struct T_isint<packed<T> >			: T_isint<T> {};

template<> struct T_isint<int8>		: T_true {};
template<> struct T_isint<int16>	: T_true {};
template<> struct T_isint<int32>	: T_true {};
template<> struct T_isint<int64>	: T_true {};
template<> struct T_isint<uint8>	: T_true {};
template<> struct T_isint<uint16>	: T_true {};
template<> struct T_isint<uint32>	: T_true {};
template<> struct T_isint<uint64>	: T_true {};

#if USE_LONG
template<> struct T_isint<long>		: T_true {};
template<> struct T_isint<ulong>	: T_true {};
#endif

template<typename T> struct T_isnum	: T_isint<T> {};
template<> struct T_isnum<float>	: T_true {};
template<> struct T_isnum<double>	: T_true {};

template<int BYTES>		struct _sint_type;
template<>				struct _sint_type<1>	{ typedef int8		type; };
template<>				struct _sint_type<2>	{ typedef int16		type; };
template<>				struct _sint_type<3>	{ typedef int32		type; };
template<>				struct _sint_type<4>	{ typedef int32		type; };
template<>				struct _sint_type<5>	{ typedef int64		type; };
template<>				struct _sint_type<6>	{ typedef int64		type; };
template<>				struct _sint_type<7>	{ typedef int64		type; };
template<>				struct _sint_type<8>	{ typedef int64		type; };
#define sint_type(BITS)	ISO_METATYPE(iso::_sint_type<(BITS + 7) / 8>)
#define sint_type_t(T)	ISO_METATYPE(iso::_sint_type<sizeof(T)>)

template<int BYTES>		struct _uint_type;
template<>				struct _uint_type<1>	{ typedef uint8		type; };
template<>				struct _uint_type<2>	{ typedef uint16	type; };
template<>				struct _uint_type<3>	{ typedef uint32	type; };
template<>				struct _uint_type<4>	{ typedef uint32	type; };
template<>				struct _uint_type<5>	{ typedef uint64	type; };
template<>				struct _uint_type<6>	{ typedef uint64	type; };
template<>				struct _uint_type<7>	{ typedef uint64	type; };
template<>				struct _uint_type<8>	{ typedef uint64	type; };
#define uint_type(BITS)	ISO_METATYPE(iso::_uint_type<((BITS + 7) / 8)>)
#define uint_type_t(T)	ISO_METATYPE(iso::_uint_type<sizeof(T)>)

template<typename T, bool S> struct T_signed	{ typedef T type; };
template<> struct T_signed<uint8,  true>		{ typedef int8 type; };
template<> struct T_signed<uint16, true>		{ typedef int16 type; };
template<> struct T_signed<uint32, true>		{ typedef int32 type; };
template<> struct T_signed<uint64, true>		{ typedef int64 type; };
template<> struct T_signed<int8,  false>		{ typedef uint8 type; };
template<> struct T_signed<int16, false>		{ typedef uint16 type; };
template<> struct T_signed<int32, false>		{ typedef uint32 type; };
template<> struct T_signed<int64, false>		{ typedef uint64 type; };
#define SIGNED(T)		typename iso::T_signed<T, true>::type
#define UNSIGNED(T)		typename iso::T_signed<T, false>::type


template<int B, bool S>	struct _int_type			{ typedef typename _sint_type<B>::type type; };
template<int B>			struct _int_type<B, false>	{ typedef typename _uint_type<B>::type type; };
#define int_type(b, S)	typename iso::_int_type<(b + 7) / 8, S>::type

//-----------------------------------------------------------------------------
//	baseint - associate a number base with an int for printing
//-----------------------------------------------------------------------------

template<int B, typename T> struct baseint {
	enum {digits = sizeof(T) * 32 / LOG2(B*B*B*B) + 1};
	T	i;
	operator T()	const	{ return i; }
	template<typename T2> baseint&	operator= (T2 j)	{ i = j; return *this;	}
	template<typename T2> baseint&	operator+=(T2 j)	{ i += j; return *this;	}
	template<typename T2> baseint&	operator-=(T2 j)	{ i -= j; return *this;	}
	template<typename T2> baseint&	operator*=(T2 j)	{ i *= j; return *this;	}
	template<typename T2> baseint&	operator/=(T2 j)	{ i /= j; return *this;	}
	template<typename T2> baseint&	operator|=(T2 j)	{ i |= j; return *this;	}
	template<typename T2> baseint&	operator&=(T2 j)	{ i &= j; return *this;	}
	template<typename T2> baseint&	operator^=(T2 j)	{ i ^= j; return *this;	}
	friend T	get(const baseint &a)	{ return a; }
};
template<int B, typename T> struct T_underlying<baseint<B, T> > : T_underlying<T> {};
template<int B, typename T> struct T_isint<baseint<B, T> >		: T_isint<T> {};

typedef constructable<baseint<16,uint8> >	xint8;
typedef constructable<baseint<16,uint16> >	xint16;
typedef constructable<baseint<16,uint32> >	xint32;
typedef constructable<baseint<16,uint64> >	xint64;

template<typename T> inline constructable<baseint<16, typename T_underlying<T>::type> >	hex(T t)	{ return (typename T_underlying<T>::type)t; }
template<typename T> inline constructable<baseint<8,  typename T_underlying<T>::type> >	oct(T t)	{ return get(t); }
template<typename T> inline constructable<baseint<2,  typename T_underlying<T>::type> >	bin(T t)	{ return get(t); }

//-----------------------------------------------------------------------------
//	rawint - to prevent endian swapping
//-----------------------------------------------------------------------------

template<typename T> struct rawint {
	T	i;
	rawint()				{}
	rawint(T _i) : i(_i)	{}
	operator T()	const	{ return i; }
};
typedef rawint<uint8>	rint8;
typedef rawint<uint16>	rint16;
typedef rawint<uint32>	rint32;
typedef rawint<uint64>	rint64;

template<int B, typename T> struct num_traits<baseint<B,T> > : inherited_num_traits<baseint<B,T>, T> {};

//-----------------------------------------------------------------------------
//	arbitrary length unsigned integers (always unaligned)
//-----------------------------------------------------------------------------

template<int N, bool BE=iso_bigendian> class _uintn {
	typedef typename _uint_type<N>::type	I;
	uint8	a[N];
	inline_only uint8					low1()	const	{ return a[BE ? N - 1 : 0]; }
	inline_only uint8					&low1()			{ return a[BE ? N - 1 : 0]; }
	inline_only const _uintn<N-1, BE>	&high()	const	{ return (_uintn<N-1, BE>&)a[1 - BE]; }
	inline_only _uintn<N-1, BE>			&high()			{ return (_uintn<N-1, BE>&)a[1 - BE]; }

	inline_only uint8					high1()	const	{ return a[BE ? 0 : N - 1]; }
	inline_only uint8					&high1()		{ return a[BE ? 0 : N - 1]; }
	inline_only const _uintn<N-1, BE>	&low()	const	{ return (_uintn<N-1, BE>&)a[BE]; }
	inline_only _uintn<N-1, BE>			&low()			{ return (_uintn<N-1, BE>&)a[BE]; }
public:
	template<typename J> void operator=(J x)	{ low1() = uint8(x); high() = x >> 8; }
	inline_only operator I() const	{ return low1() | (high() << 8); }
};

template<bool BE> class _uintn<1,BE> {
	uint8		a;
public:
	template<typename J> void operator=(J x)	{ a = uint8(x);	}
	operator uint8() const		{ return a;	}
};

template<int N, bool BE = iso_bigendian> class _intn : _uintn<N, BE> {
	typedef _uintn<N, BE>					B;
	typedef typename _sint_type<N>::type	I;
	template<typename T> static constexpr SIGNED(T)	sign_extend(T x)	{ return x - ((x << 1) & (T(1) << (N * 8))); }
public:
	inline_only void operator=(I x)	{ B::operator=(x); }
	inline_only operator I() const	{ return sign_extend(B::operator I()); }
};

template<int N, bool BE> _uintn<N,!BE>	swap_endian(const _uintn<N,BE> &u) {
	_uintn<N,!BE>	r;
	for (int i = 0; i < N; i++)
		((uint8*)&r)[i] = ((uint8*)&u)[N - 1 - i];
	return r;
}

template<int N, bool BE> struct T_swap_endian_type<_uintn<N,BE> > { typedef _uintn<N,!BE> type; };

template<int N, bool BE> struct T_underlying<_uintn<N,BE> >	{ typedef typename _uint_type<N>::type type; };
template<int N, bool BE> struct T_underlying<_intn<N,BE> >	{ typedef typename _sint_type<N>::type type; };
template<int N, bool BE=iso_bigendian> using uintn = constructable<_uintn<N,BE> >;
template<int N, bool BE=iso_bigendian> using intn  = constructable<_intn<N,BE> >;

template<int N, bool BE> struct T_isint<_uintn<N,BE> > : T_true {};

typedef uintn<3, false>	uint24le;
typedef uintn<3, true>	uint24be;

//-----------------------------------------------------------------------------
// carry operations
//-----------------------------------------------------------------------------

template<typename T> inline bool addc(T a, T b, bool c, T &r) {
	T	t = a + b + T(c);
	r = t;
	return t < a || (c && t == a);
}
template<typename T> inline bool subc(T a, T b, bool c, T &r) {
	T	t = a - b - T(c);
	r = t;
	return t > a || (c && t == a);
}

template<typename T, bool BIG = (sizeof(T) * 2 > 8)> struct s_mulc {
	enum { HBITS = sizeof(T) * 4 };
	typedef	typename _uint_type<(sizeof(T) + 1) / 2>::type	H;

	static inline T mul(T a, T b, T &r) {
		if ((a | b) < (T(1) << HBITS)) {
			r = a * b;
			return 0;
		}

		H	a0 = H(a), a1 = H(a >> HBITS);
		H	b0 = H(b), b1 = H(b >> HBITS);
		T	r0 = T(a0) * b0;
		T	r1 = T(a0) * b1 + T(b0) * a1;
		T	r2 = T(a1) * b1;

		r = r0 + (r1 << HBITS);
		return (r1 >> HBITS) + r2;
	}
	static inline T madd(T a, T b, T c, T &r) {
		if ((a | b) < (T(1) << HBITS)) {
			r = a * b + c;
			return 0;
		}

		H	a0 = H(a), a1 = H(a >> HBITS);
		H	b0 = H(b), b1 = H(b >> HBITS);
		T	r0 = T(a0) * b0 + c;
		T	r1 = T(a0) * b1 + T(b0) * a1;
		T	r2 = T(a1) * b1;

		r = r0 + (r1 << HBITS);
		return (r1 >> HBITS) + r2;
	}
	static inline T div(T a0, T a1, T b) {
		if (a1 >= b)
			return T(~T(0));
		T	r1	= (a1 << HBITS) | (a0 >> HBITS);
		T	d1	= r1 / b;
		T	r2	= ((r1 % b) << HBITS) | H(a0);
		T	d2	= r2 / b;

		return d2 | (d1 << HBITS);
	}
};

template<typename T> struct s_mulc<T, false> {
	typedef	typename _uint_type<sizeof(T) * 2>::type	D;

	static inline T mul(T a, T b, T &r) {
		D x = D(a) * b;
		r	= T(x);
		return x >> (sizeof(T) * 8);
	}
	static inline T madd(T a, T b, T c, T &r) {
		D x	= D(a) * b + c;
		r	= T(x);
		return x >> (sizeof(T) * 8);
	}
	static inline T div(T a0, T a1, T b) {
		return a1 >= b
			? T(~T(0))
			: T(((D(a1) << (sizeof(T) * 8)) | a0) / b);
	}
};

template<typename T> inline T mulc(T a, T b, T &r) {
	return s_mulc<T>::mul(a, b, r);
}
template<typename T> inline T maddc(T a, T b, T c, T &r) {
	return s_mulc<T>::madd(a, b, c, r);
}
template<typename T> inline T divc(T a0, T a1, T b) {
	return s_mulc<T>::div(a0, a1, b);
}

}//namespace iso

#endif // DEFS_INT_H
