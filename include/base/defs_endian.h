#ifndef DEFS_ENDIAN_H
#define DEFS_ENDIAN_H

#include "defs_base.h"

namespace iso {

//-----------------------------------------------------------------------------
//	endian conversion
//-----------------------------------------------------------------------------

template<typename T, int N> struct s_reverse_bytes {
	static const T mask = T(~T(0)) / ((T(1) << (N * 4)) + 1);	// N bits every 2N
	static constexpr T f(T x) { return s_reverse_bytes<T, N / 2>::f(((x & mask) << (N*4)) | ((x >> (N*4)) & mask)); }
};
template<typename T> struct s_reverse_bytes<T,1> { static constexpr T f(T x) { return x; } };
template<typename T> constexpr T swap_endian_const(T x) { return s_reverse_bytes<T, sizeof(T)>::f(x); }

constexpr uint8	swap_endian(uint8 i) {
	return i;
}

#if defined(__GNUC__)
constexpr uint16	swap_endian(uint16 i) {	return __builtin_bswap16(i);}
constexpr uint32	swap_endian(uint32 i) {	return __builtin_bswap32(i);}
constexpr uint64	swap_endian(uint64 i) {	return __builtin_bswap64(i);}
#elif 0//defined(PLAT_PC)
constexpr uint16	swap_endian(uint16 i) {	return _byteswap_ushort(i);}
constexpr uint32	swap_endian(uint32 i) {	return _byteswap_ulong(i);}
constexpr uint64	swap_endian(uint64 i) {	return _byteswap_uint64(i);}
#else
constexpr uint16	swap_endian(uint16 i) {
	return (i >> 8) | (i << 8);
}
constexpr uint32	swap_endian(uint32 i) {
	uint32	m = 0x0000ffffL;
	i	= ((i & m) << 16) | ((i & ~m) >> 16);
	m	= m ^ (m << 8);
	return((i & m) <<  8) | ((i & ~m) >>  8);
}
constexpr uint64	swap_endian(uint64 i) {
	uint64	m = 0x00000000ffffffffL;
	i	= ((i & m) << 32) | ((i & ~m) >> 32);
	m	= m ^ (m << 16);
	i	= ((i & m) << 16) | ((i & ~m) >> 16);
	m	= m ^ (m << 8);
	return((i & m) <<  8) | ((i & ~m) >>  8);
}
#endif

template<typename T> constexpr T	swap_endian(T t)				{ return force_cast<T>(swap_endian((uint_type_t(T)&)t)); }
template<typename T> constexpr T	endian(T t, bool be)			{ return be == iso_bigendian ? t : swap_endian(t); }
template<typename T> constexpr void	swap_endian_inplace(T &t)		{ (uint_type_t(T)&)t = swap_endian((uint_type_t(T)&)t); }
template<typename T> inline void	endian_inplace(T &t, bool be)	{ if (be != iso_bigendian) swap_endian_inplace(t); }

template<typename T> struct T_native_endian							{ typedef T type; };
template<typename T> struct T_native_endian<constructable<T> >		: T_native_endian<T> {};
template<typename T> struct T_is_native_endian						: T_true {};
template<typename T> struct T_is_native_endian<constructable<T> >	: T_is_native_endian<T> {};
template<typename T> struct T_is_bigendian							: T_constant0<bool, T_is_native_endian<T>::value == iso_bigendian> {};
template<typename T> constexpr	const T& native_endian(const T &t)	{ return t; };
template<typename T> constexpr	bool	is_native_endian(T t)		{ return true; };
template<typename T> constexpr	bool	is_native_endian()			{ return is_native_endian(T(0)); };
template<typename T> constexpr	bool	is_bigendian()				{ return is_native_endian<T>() == iso_bigendian; };

template<typename T> constexpr	const typename T_native_endian<T>::type native_endian(const constructable<T> &t)	{ return t; };

template<typename T> class T_swap_endian {
protected:
	typedef	uint_type_t(T)	S;
	S	i;
	void			set(const T &b)					{ i = swap_endian((S&)b); }
public:
	operator		T()		const					{ S t = swap_endian(i); return (T&)t; }
	T_swap_endian	&operator=(const T &b)			{ set(b); return *this; }
	T				get()	const					{ S t = swap_endian(i); return (T&)t; };
	friend T		get(T_swap_endian &a)			{ return a; }
	friend T		get(const T_swap_endian &a)		{ return a; }

	template<typename B> friend T_swap_endian& operator+=(T_swap_endian &a, const B &b)	{ return a = a + b;	}
	template<typename B> friend T_swap_endian& operator-=(T_swap_endian &a, const B &b)	{ return a = a - b;	}
	template<typename B> friend T_swap_endian& operator*=(T_swap_endian &a, const B &b)	{ return a = a * b;	}
	template<typename B> friend T_swap_endian& operator/=(T_swap_endian &a, const B &b)	{ return a = a / b;	}
	template<typename B> friend T_swap_endian& operator%=(T_swap_endian &a, const B &b)	{ return a = a % b;	}
	template<typename B> friend T_swap_endian& operator&=(T_swap_endian &a, const B &b)	{ return a = a ^ b; }
	template<typename B> friend T_swap_endian& operator|=(T_swap_endian &a, const B &b)	{ return a = a ^ b; }
	template<typename B> friend T_swap_endian& operator^=(T_swap_endian &a, const B &b) { return a = a ^ b; }
	template<typename B> friend T_swap_endian& operator++(T_swap_endian &a)				{ return a = a + 1; }
	template<typename B> friend T_swap_endian& operator--(T_swap_endian &a)				{ return a = a - 1; }
	template<typename B> friend T operator++(T_swap_endian &a, int)						{ T t = a; a = t + 1; return t; }
	template<typename B> friend T operator--(T_swap_endian &a, int)						{ T t = a; a = t - 1; return t; }

};

template<typename T> struct T_underlying<T_swap_endian<T> >  : T_underlying<T> {};
template<typename T> struct T_swap_endian<constructable<T> > : T_swap_endian<T> {};

template<>							struct T_swap_endian_type<uint8>				{ typedef uint8 type; };
template<typename T>				struct T_swap_endian_type<constructable<T> >	: T_swap_endian_type<T> {};
template<typename T, int N>			struct T_swap_endian_type<T[N]>					{ typedef typename T_swap_endian_type<T>::type type[N]; };
template<typename T, bool be>		struct T_endian_type							: T_if<T_is_bigendian<T>::value == be, T, typename T_swap_endian_type<T>::type> {};

template<typename T>				struct T_constructable_swap_endian_type			{ typedef constructable<typename T_swap_endian_type<T>::type> type; };
template<>							struct T_constructable_swap_endian_type<uint8>	{ typedef uint8 type; };
template<typename T, bool be>		struct T_constructable_endian_type				: T_constructable_swap_endian_type<T> {};
template<typename T>				struct T_constructable_endian_type<T, iso_bigendian> { typedef T type; };

template<typename T>				struct T_native_endian<T_swap_endian<T> >		{ typedef T type; };
template<typename T>				struct T_isint<T_swap_endian<T> > : T_isint<T>	{};
template<typename T>				struct num_traits<T_swap_endian<T> > : inherited_num_traits<T_swap_endian<T>, T>	{};

template<typename T>				struct T_is_native_endian<T_swap_endian<T> >	: T_false {};
template<typename T>	constexpr	T		native_endian(T_swap_endian<T> t)		{ return t; };
template<typename T>	constexpr	bool	is_native_endian(T_swap_endian<T> t)	{ return false; };

#ifdef	ISO_BIGENDIAN
#define BE(x)		x
#define LE(x)		iso::T_constructable_swap_endian_type<x>::type
#else
#define LE(x)		x
#define BE(x)		iso::T_constructable_swap_endian_type<x>::type
#endif

typedef BE(uint16)	uint16be;
typedef BE(uint32)	uint32be;
typedef BE(uint64)	uint64be;
typedef BE(int16)	int16be;
typedef BE(int32)	int32be;
typedef BE(int64)	int64be;
typedef BE(float32)	float32be;
typedef BE(float64)	float64be;
typedef BE(float)	floatbe;
typedef BE(double)	doublebe;
typedef BE(xint16)	xint16be;
typedef BE(xint32)	xint32be;
typedef BE(xint64)	xint64be;

typedef LE(uint16)	uint16le;
typedef LE(uint32)	uint32le;
typedef LE(uint64)	uint64le;
typedef LE(int16)	int16le;
typedef LE(int32)	int32le;
typedef LE(int64)	int64le;
typedef LE(float32)	float32le;
typedef LE(float64)	float64le;
typedef LE(float)	floatle;
typedef LE(double)	doublele;
typedef LE(xint16)	xint16le;
typedef LE(xint32)	xint32le;
typedef LE(xint64)	xint64le;

namespace bigendian_ns {
	using iso::int8;
	using iso::uint8;
	typedef	iso::uint16be	uint16;
	typedef	iso::uint32be	uint32;
	typedef	iso::uint64be	uint64;
	typedef	iso::int16be	int16;
	typedef	iso::int32be	int32;
	typedef	iso::int64be	int64;
	typedef	iso::float32be	float32;
	typedef	iso::float64be	float64;
}

namespace littleendian_ns {
	using iso::int8;
	using iso::uint8;
	typedef	iso::uint16le	uint16;
	typedef	iso::uint32le	uint32;
	typedef	iso::uint64le	uint64;
	typedef	iso::int16le	int16;
	typedef	iso::int32le	int32;
	typedef	iso::int64le	int64;
	typedef	iso::float32le	float32;
	typedef	iso::float64le	float64;
}

template<typename T> struct packed<constructable<T_swap_endian<T> > > : _packed<T_swap_endian<T> > {
	typedef	_packed<T_swap_endian<T> >	B;
	packed()									{}
	packed(const T &_t)			{ B::set(_t); }
	operator T_swap_endian<T>()	const			{ return B::get(); }
	operator T()				const			{ return B::get(); }
	template<typename T2> void operator=(const T2 &_t)	{ B::operator=(_t); }
	friend T	get(const packed &a)			{ return a; }
};

}//namespace iso

#endif // DEFS_ENDIAN_H
