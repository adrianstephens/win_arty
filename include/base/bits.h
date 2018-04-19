#ifndef BITS_H
#define BITS_H

#include "defs.h"

namespace iso {

//-----------------------------------------------------------------------------
// masks
//-----------------------------------------------------------------------------

template<typename T, int N, bool OK=(N < sizeof(T) * 8)> struct s_bit	{ static const T value = T(1) << N; };
template<typename T, int N>				struct s_bit<T,N,false>			{ static const T value = 0; };
template<typename T, int N, int S = 0>	struct s_bits					{ static const T value = s_bit<T, S + N>::value - s_bit<T, S>::value; };

template<typename T> constexpr T	bit(uint32 n)						{ return n < sizeof(T) * 8 ? T(1) << n : 0; }
template<typename T> constexpr T	bits(uint32 n, uint32 s = 0)		{ return bit<T>(s + n) - bit<T>(s); }

constexpr uint32					bit(uint32 n)						{ return bit<uint32>(n);		}
constexpr uint64					bit64(uint32 n)						{ return bit<uint64>(n);		}
constexpr uint32					bits(uint32 n, uint32 s = 0)		{ return bits<uint32>(n, s);	}
constexpr uint64					bits64(uint32 n, uint32 s = 0)		{ return bits<uint64>(n, s);	}

template<typename T> constexpr bool	bit_test(T v, uint32 e)				{ return !!(v & e);			}
template<typename T> constexpr bool	bit_test_all(T v, uint32 e)			{ return (v & e) == e;		}
template<typename T> constexpr bool	bit_test_set(T v, uint32 e)			{ return !!(v & e) | ((v |= e), false); }
template<typename T> constexpr bool	bit_test_set(T v, uint32 e, bool b)	{ return !!(v & e) | ((v ^= (v ^ -T(b)) & e), false);	}
template<typename T> constexpr bool	bit_test_clear(T v, uint32 e)		{ return !!(v & e) | ((v &= ~e), false); }
template<typename T> constexpr bool	bit_test_flip(T v, uint32 e)		{ return !!(v & e) | ((v ^= e), false);	}

template<typename T> inline T&		bit_set(T &v, uint32 e)				{ return v |= e;	}
template<typename T> inline T&		bit_set(T &v, uint32 e, bool b)		{ return v = (v & ~e) | (-int(b) & e); }
template<typename T> inline T&		bit_clear(T &v, uint32 e)			{ return v &= ~e;	}
template<typename T> inline T&		bit_flip(T &v, uint32 e)			{ return v ^= e;	}
template<typename T> inline T&		bit_swap(T &v, uint32 e1, uint32 e2){ bool b1 = bit_test(v, e1); bit_set(e1, bit_test(v, e2)); return bit_set(e2, b1); }


template<typename T> constexpr T	masked_write(T a, T b, T m)			{ return (a & ~m) | (b & m); }

// V bits every N
template<typename T, int N, int V> struct s_bitblocks {
	static const T value	= s_bitblocks<T,N,1>::value * ((1 << V) - 1);
};
template<typename T, int N> struct s_bitblocks<T, N, 1> {
	static const T top		= T(1) << ((sizeof(T) * 8 - 1) / N * N);
	static const T value	= ((top - 1) / s_bits<T, N>::value) | top;
};
template<typename T> constexpr T	_bitevery_helper(T a, T b) {
	return ((a - 1) / b) | a;
}
template<typename T> constexpr T	bitevery(uint32 n) {
	return _bitevery_helper(bit<T>((sizeof(T) * 8 - 1) / n * n), bits<T>(n));
};
template<typename T> constexpr T	bitblocks(uint32 n, uint32 v) {
	return bitevery<T>(n) * ((1 << v) - 1);
};
// N bits every 2N
template<typename T, int N> struct s_chunkmask {
	typedef uint_type_t(T)	U;
	static const T value = T(U(~U(0)) / ((U(1) << N) + 1));
};

//-----------------------------------------------------------------------------
// sign extend
//-----------------------------------------------------------------------------

template<int S, typename T> constexpr SIGNED(T)	sign_extend(T x)				{ return x - ((x << 1) & bit<T>(S)); }
template<typename T>		constexpr SIGNED(T)	sign_extend(T x, uint32 s)		{ return x - ((x << 1) & bit<T>(s)); }
template<typename T>		constexpr SIGNED(T)	_mask_sign_extend(T x, T m)		{ return (x & (m - 1)) - ((x << 1) & m); }
template<int S, typename T> constexpr SIGNED(T)	mask_sign_extend(T x)			{ return _mask_sign_extend(x, bit<T>(S)); }
template<typename T>		constexpr SIGNED(T)	mask_sign_extend(T x, uint32 s)	{ return _mask_sign_extend(x, bit<T>(s)); }

template<bool SIGNED> struct s_extend {
	template<typename T> static constexpr T f(T x, uint32 s)	{ return sign_extend(x, s); }
	template<typename T> static constexpr T mask(T x, uint32 s)	{ return mask_sign_extend(x, s); }
};
template<> struct s_extend<false> {
	template<typename T> static constexpr T f(T x, uint32 s)	{ return x; }
	template<typename T> static constexpr T mask(T x, uint32 s)	{ return x & bits<T>(s); }
};

template<int S, int D, typename T> inline T extend_bits(T x) {
	enum {
		A		= (D + S - 1) / S * S,
		shift	= A - D,
		mult	= ((1 << A) - 1) / ((1 << S) - 1)
	};
	return (x * mult) >> shift;
}

//-----------------------------------------------------------------------------
// shifts/rotates
//-----------------------------------------------------------------------------

template<typename T, unsigned N> struct s_shift {
	static constexpr T left(T a)		{ return a << N; }
	static constexpr T right(T a)		{ return a >> N; }
};
template<int N, bool NEG=(N<0)> struct s_shift1	{
	template<typename T> static constexpr T f(T x)	{ return s_shift<T,N>::left(x); }
	template<typename T> static constexpr T a(T x)	{ return s_shift<T,N>::left(x); }
};
template<int N>	struct s_shift1<N,true>		{
	template<typename T> static constexpr T f(T x)	{ return s_shift<T,-N>::right(x); }
	template<typename T> static constexpr T a(T x)	{ return f(x) | -(f(x & (T(1) << (sizeof(T) * 8 - 1)))); }
};

template<typename T> constexpr T	shift_left(T x, uint32 y)		{ return x << y; }
template<typename T> constexpr T	shift_right(T x, uint32 y)		{ return x >> y; }
template<typename T> constexpr T	shift_bits(T x, int y)			{ return y < 0 ? x >> -y : x << y;	}
template<typename T> constexpr T	ashift_right(T x, uint32 y)		{ return x >> y | -((x & (T(1) << (sizeof(T) * 8 - 1))) >> y); }
template<typename T> constexpr T	ashift_bits(T x, int y)			{ return y < 0 ? ashift_right(x, -y) : x << y; }
template<typename T> constexpr T	rotate_left(T x, uint32 y)		{ return (x << y) | (x >> (sizeof(T) * 8 - y)); }
template<typename T> constexpr T	rotate_right(T x, uint32 y)		{ return (x >> y) | (x << (sizeof(T) * 8 - y)); }
template<typename T> constexpr T	rotate_bits(T x, int y)			{ return rotate_left(x, y & (sizeof(T) * 8 - 1)); }

template<int N,		typename T> constexpr T shift_left(T x)			{ return s_shift<T,N>::left(x);	}
template<int N,		typename T> constexpr T shift_right(T x)		{ return s_shift<T,N>::right(x); }
template<int N,		typename T> constexpr T shift_bits(T x)			{ return s_shift1<N>::f(x); }
template<int N,		typename T> constexpr T ashift_right(T x)		{ return shift_right<N>(x) | -(shift_right<N>(x & (T(1) << (sizeof(T) * 8 - 1)))); }
template<int N,		typename T> constexpr T ashift_bits(T x)		{ return s_shift1<N>::a(x);	}
template<int N,		typename T> constexpr T rotate_left(T x)		{ return shift_left<N>(x) | shift_right<sizeof(T) * 8 - N>(x); }
template<int N,		typename T> constexpr T rotate_right(T x)		{ return shift_right<N>(x) | shift_left<sizeof(T) * 8 - N>(x); }
template<int N,		typename T> constexpr T rotate_bits(T x)		{ return rotate_left<N & (sizeof(T) * 8 - 1)>(x); }

// rotate bits from s for n
template<typename T> constexpr T	rotate_left(T x, uint32 y, uint32 n, uint32 s = 0)		{ return masked_write(x, ((x << y) | (x >> (n - y))), bits<T>(n, s)); }
template<typename T> constexpr T	rotate_right(T x, uint32 y, uint32 n, uint32 s = 0)		{ return masked_write(x, ((x >> y) | (x << (n - y))), bits<T>(n, s)); }

//-----------------------------------------------------------------------------
//	bitfields
//-----------------------------------------------------------------------------

// read/write
template<bool be>	inline void		_write_bytes(void *p, const void *x, int n, int sx)			{ memcpy(p, (const char*)x + sx - n, n); }
template<>			inline void		_write_bytes<false>(void *p, const void *x, int n, int sx)	{ memcpy(p, x, n); }
template<typename T> inline void	write_bytes(void *p, T x, int n)							{ _write_bytes<T_is_bigendian<T>::value>(p, &x, n, sizeof(x)); }
template<typename T> inline void	write_bytes(const memory_block &b, T x)						{ write_bytes<T>(b, x, b.length32()); }

template<bool be>	inline void		_read_bytes(const void *p, int n, void *x, int sx)			{ n = min(n, sx); memcpy((char*)x + sx - n, p, n); }
template<>			inline void		_read_bytes<false>(const void *p, int n, void *x, int sx)	{ n = min(n, sx); memcpy(x, p, n); }
template<typename T> inline T		read_bytes(const void *p, int n)							{ T x = 0; _read_bytes<T_is_bigendian<T>::value>(p, n, &x, sizeof(x)); return s_extend<num_traits<T>::is_signed>::f(x, n * 8); }
template<typename T> inline T		read_bytes(const const_memory_block &b)						{ return read_bytes<T>(b, b.length32()); }

// extract bits
template<typename T> struct T2 {
	typedef ISO_METATYPE(_uint_type<sizeof(T)*2>) type;
	union {
		type	t2;
		T		t[2];
	};
	T2(const T *p) { t[0] = p[0]; t[1] = p[1]; }
	operator type() const { return t2; }
};

template<typename T> struct T2<T_swap_endian<T> > : T2<T> {
	typedef T_swap_endian<typename T2<T>::type> type;
	T2(const T_swap_endian<T> *p) : T2<T>((const T*)p) {};
	operator type() const { return (type&)this->t2; }
};

template<typename T> inline typename T2<T>::type read2(const T *p) {
	return T2<T>(p);
}

template<typename T>				constexpr T			extract_bits(T i, uint32 S, uint32 N)							{ return s_extend<num_traits<T>::is_signed>::mask(i >> S, N); }
//template<typename T>				constexpr T			extract_bits(T i, uint32 S, uint32 N)							{ return (i >> S) & bits<T>(N); }
template<int N, typename T>			constexpr T			extract_bits(T i, uint32 S)										{ return extract_bits(i, S, N);	}
template<int S, int N, typename T>	constexpr T			extract_bits(T i)												{ return extract_bits(i, S, N);	}
template<>							constexpr uint8		extract_bits<0, 8>(uint8 i)										{ return i;	}
template<>							constexpr uint16	extract_bits<0, 16>(uint16 i)									{ return i;	}
template<>							constexpr uint32	extract_bits<0, 32>(uint32 i)									{ return i;	}
template<>							constexpr uint64	extract_bits<0, 64>(uint64 i)									{ return i;	}
template<typename T>				constexpr T			extract_bits(T_swap_endian<T> i, uint32 S, uint32 N)			{ return extract_bits(T(i), sizeof(T) * 8 - S - N, N); }
template<int N, typename T>			constexpr T			extract_bits(T_swap_endian<T> i, uint32 S)						{ return extract_bits<N>(T(i), sizeof(T) * 8 - S - N); }
template<int S, int N, typename T>	constexpr T			extract_bits(T_swap_endian<T> i)								{ return extract_bits<sizeof(T) * 8 - S - N, N>(T(i)); }

template<typename T>				constexpr T			copy_bits(T s, T d, uint32 S, uint32 D, uint32 N)				{ return masked_write(d, shift_bits(s, int(D-S)), bits<T>(N, D)); }
template<int N, typename T>			constexpr T			copy_bits(T s, T d, uint32 S, uint32 D)							{ return masked_write(d, shift_bits(s, int(D-S)), bits<T>(N, D)); }
template<int S, int D, int N, typename T> constexpr T	copy_bits(T s, T d)												{ return masked_write(d, shift_bits<D-S>(s), bits<T>(N, D)); }
template<>							constexpr uint8		copy_bits<0, 0, 8>(uint8 s, uint8 d)							{ return s; }
template<>							constexpr uint16	copy_bits<0, 0, 16>(uint16 s, uint16 d)							{ return s; }
template<>							constexpr uint32	copy_bits<0, 0, 32>(uint32 s, uint32 d)							{ return s; }
template<>							constexpr uint64	copy_bits<0, 0, 64>(uint64 s, uint64 d)							{ return s; }
template<typename T>				constexpr T			copy_bits(T s, T_swap_endian<T> d, uint32 S, uint32 D, uint32 N){ return copy_bits(s, T(d), S, sizeof(T) * 8 - D - N, N); }
template<int N, typename T>			constexpr T			copy_bits(T s, T_swap_endian<T> d, uint32 S, uint32 D)			{ return copy_bits<N>(s, T(d), S, sizeof(T) * 8 - D - N); }
template<int S, int D, int N, typename T> constexpr T	copy_bits(T s, T_swap_endian<T> d)								{ return copy_bits<S, sizeof(T) * 8 - D - N, N>(s, T(d)); }

template<typename T>				inline void			write_bits(void *p, T x, uint32 D, uint32 N)					{ enum {A = sizeof(T) * 8}; p = (T*)p + D / A; *(T*)p = copy_bits(x, *(T*)p, 0, D % A, N); }
template<int N, typename T>			inline void			write_bits(void *p, T x, uint32 D)								{ enum {A = sizeof(T) * 8}; p = (T*)p + D / A; *(T*)p = copy_bits<N>(x, *(T*)p, 0, D % A); }
template<int D, int N, typename T>	inline void			write_bits(void *p, T x)										{ enum {A = sizeof(T) * 8}; p = (T*)p + D / A; *(T*)p = copy_bits<0, D % A, N>(x, *(T*)p); }
template<typename T>				inline void			write_bits(T_swap_endian<T> *p, T x, uint32 D, uint32 N)		{ enum {A = sizeof(T) * 8}; p += D / A; *p = copy_bits(x, *p, 0, D % A, N); }
template<int N, typename T>			inline void			write_bits(T_swap_endian<T> *p, T x, uint32 D)					{ enum {A = sizeof(T) * 8}; p += D / A; *p = copy_bits<N>(x, *p, 0, D % A); }
template<int D, int N, typename T>	inline void			write_bits(T_swap_endian<T> *p, T x)							{ enum {A = sizeof(T) * 8}; p += D / A; *p = copy_bits<0, D % A, N>(x, *p); }

template<typename T>				inline T			read_bits(const T *p, uint32 S, uint32 N)						{ enum {A = sizeof(T) * 8}; p += S / A; S %= A; return S + N <= A ? extract_bits(*p, S, N) : (T)extract_bits(read2(p), S, N); }
template<int N, typename T>			inline T			read_bits(const T *p, uint32 S)									{ enum {A = sizeof(T) * 8}; p += S / A; S %= A; return extract_bits<N>(*p, S); }
template<int S, int N, typename T>	inline T			read_bits(const T *p)											{ enum {A = sizeof(T) * 8}; p += S / A; S %= A; return extract_bits<S, N>(*p); }
template<typename T>				inline T			read_bits(const T_swap_endian<T> *p, uint32 S, uint32 N)		{ enum {A = sizeof(T) * 8}; p += S / A; S %= A; return S + N <= A ? extract_bits(*p, S, N) : (T)extract_bits(read2(p), S, N); }
template<int N, typename T>			inline T			read_bits(const T_swap_endian<T> *p, uint32 S)					{ enum {A = sizeof(T) * 8}; p += S / A; S %= A; return extract_bits<N>(*p, S); }
template<int S, int N, typename T>	inline T			read_bits(const T_swap_endian<T> *p)							{ enum {A = sizeof(T) * 8}; p += S / A; return extract_bits<S % A, N>(*p); }

template<int S, int D, typename T>			constexpr T	move_bit(T x)	{ return shift_bits(x & bit<T>(S), D - S);}
template<int S, int D, int N, typename T>	constexpr T	move_bits(T x)	{ return shift_bits(x & bits<T>(N, S), D - S);}

template<typename T, int S, int N> struct bitfield {
	typedef	T	type;
	typedef typename T_native_endian<T>::type	TN;
	enum	{A = sizeof(T) * 8};
	inline void		set(TN a)				{ T &u = ((T*)this)[S / A]; u = copy_bits<0, S & (A - 1), N>(a, u); }
	inline T		get()	const			{ return extract_bits<S & (A - 1), N>(((T*)this)[S / A]); }
	inline operator T()		const			{ return get(); }
	inline void		operator=(TN a)			{ set(a); }
	friend T		get(const bitfield &a)	{ return a; }
};

template<int S, int N> struct bitfield_min : bitfield<typename _uint_type<N + (S & 7) <= 8 ? 1 : N + (S & 15) <= 16 ? 2 : N + (S & 31) <= 32 ? 4 : 8>::type, S, N> {
};

template<typename T, int S, int N> struct typed_bitfield : bitfield_min<S, N> {
	using typename bitfield_min<S, N>::type;
	operator T()	const		{ uint_type_t(T) u = this->get(); return (T&)u;}
	void operator=(const T &v)	{ this->set(reinterpret_cast<const type&>(v));	}
	friend T		get(const typed_bitfield &a)	{ return a; }
};

template<int B, int N> struct bitfield_array_base {
	typedef typename _uint_type<(B + 7) / 8>::type	U;
	static const int A = sizeof(U) * 8;
	U		u[(B * N + A - 1) / A];
};

template<int B, int N, bool POW2 = (B & (B-1)) == 0> struct bitfield_array : bitfield_array_base<B, N> {
	typedef typename bitfield_array_base<B, N>::U U;
	inline void		set(int i, U a)		{ int s = i * B; U &u = this->u[s / this->A]; u = copy_bits<B>(a, u, 0, s & (this->A - 1)); }
	inline U		get(int i)	const	{ int s = i * B; return extract_bits<B>(this->u[s / this->A], s & (this->A - 1)); }
};

template<int B, int N> struct bitfield_array<B, N, false> : bitfield_array_base<B, N> {
	typedef typename bitfield_array_base<B, N>::U U;
	typedef typename _uint_type<sizeof(U) * 2>::type U2;
	inline void		set(int i, U a)		{ int s = i * B; U2 &u = (U2&)this->u[s / this->A]; u = copy_bits<B,U2>(a, u, 0, s & (this->A - 1)); }
	inline U		get(int i)	const	{ int s = i * B; return extract_bits<B,U2>((U2&)this->u[s / this->A], s & (this->A - 1)); }
};

#ifdef USE_VARIADIC_TEMPLATES

template<typename T, typename... TT>	struct bitfields_size					{ enum {value = bitfields_size<T>::value + bitfields_size<TT...>::value}; };
template<typename T>					struct bitfields_size<T>				{ enum {value = sizeof(T) * 8}; };
template<typename T, int N>				struct bitfields_size<compact<T,N> >	{ enum {value = N}; };

template<int S, typename T, typename... TT>	struct bitfields_fields {
	union {
		bitfields_fields<S, T> a;
		bitfields_fields<S + bitfields_size<T>::value, TT...> b;
	};
};
template<int S, typename T>			struct bitfields_fields<S,T>				: bitfield<T,S,bitfields_size<T>::value> {};
template<int S, typename T, int N>	struct bitfields_fields<S,compact<T,N> >	: bitfield<T,S,N> {};

template<typename U, typename... TT> struct bitfields {
	union {
		typename T_native_endian<U>::type _[(bitfields_size<TT...>::value + sizeof(U) * 8 - 1) / (sizeof(U) * 8)];
		bitfields_fields<0, TT...> a;
	};
};

#endif

//-----------------------------------------------------------------------------
// count/index bits
//-----------------------------------------------------------------------------

template<uint64 X>	struct T_countbits	{
	static const uint64	A = X - ((X >> 1) & (~uint64(0) / 3));
	static const uint64	B = (A & (~uint64(0) / 15 * 3)) + ((A >> 2) & (~uint64(0) / 15 * 3));
	static const uint64	C = (B + (B >> 4)) & (~uint64(0) / 255 * 15);
	enum { value = ((((C & ~uint32(0)) + (C >> 32)) * (~uint32(0) / 255)) >> 24) & 0x3f };
};

inline uint32 count_bits1(uint8 i) { return i & 1; }
inline uint32 count_bits2(uint8 i) { return (i - (i >> 1)) & 3; }
inline uint32 count_bits4(uint8 i) { i -= (i >> 1) & 5; return (i + (i >> 2)) & 3; }

inline uint32 count_bits(uint8 i) {
	i-= (i >> 1) & 0x55;
	i = (i & 0x33) + ((i >> 2) & 0x33);
	return	(i + (i >> 4)) & 0x0f;
}
inline uint32 count_bits(uint16 i) {
	i-= (i >> 1) & 0x5555;
	i = (i & 0x3333) + ((i >> 2) & 0x3333);
	i = i + (i >> 4) & 0xf0f;
	return (i + (i >> 8)) & 0x1f;
}
inline uint32 count_bits(uint32 i) {
	i-= (i >> 1) & 0x55555555;
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return ((i + (i >> 4) & 0xf0f0f0f) * 0x01010101) >> 24;
}
inline uint32 count_bits(uint64 i) {
	i-= (i >> 1) & 0x5555555555555555LL;
	i = (i & 0x3333333333333333LL) + ((i >> 2) & 0x3333333333333333LL);
	return (((i + (i >> 4)) & 0x0f0f0f0f0f0f0f0fLL) * 0x0101010101010101LL) >> 56;
}
template<typename T> inline uint32 count_bits(T i)	{ return count_bits((uint_type_t(T)&)i); }

inline uint32 count_bits(void *begin, void *end) {
	uint32	t	= 0;
	for (uint8 *p = (uint8*)begin, *e = (uint8*)end; p < e; p++)
		t += count_bits(*p);
	return t;
}

// nth set index
inline int nth_set_index(uint8 v, int n) {
	uint8	i0 = v - ((v >> 1) & 0x55);
	uint8	i1 = (i0 & 0x33) + ((i0 >> 2) & 0x33);

	int		r = 0;
	if (n >= (i1 & 0xf)) {
		n	-= (i1 & 0xf);
		i0	>>= 4;
		r	+= 4;
	}
	if (n >= (i0 & 3)) {
		n	-= i0 & 3;
		r	+= 2;
	}
	if (n || !(v & (1 << r)))
		r += 1;
	return r;
}

inline int nth_set_index(uint16 v, int n) {
	uint16	i0 = v - ((v >> 1) & 0x5555);
	uint16	i1 = (i0 & 0x3333) + ((i0 >> 2) & 0x3333);
	uint16	i2 = (i1 + (i1 >> 4)) & 0xf;
	
	int	r = 0;
	if (n >= i2) {
		n	-= i2;
		r	+= 8;
		i0	>>= 8;
		i1	>>= 8;
	}
	if (n >= (i1 & 0xf)) {
		n	-= (i1 & 0xf);
		i0	>>= 4;
		r	+= 4;
	}
	if (n >= (i0 & 3)) {
		n	-= i0 & 3;
		r	+= 2;
	}
	if (n || !(v & (1 << r)))
		r += 1;
	return r;
}

inline int nth_set_index(uint32 v, int n) {
	uint32	i = v - ((v >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = ((i + (i >> 4)) & 0xf0f0f0f) * 0x01010101;
	
	int	r = 0;
	if (n >= uint8(i >> 16)) {
		r += 16;
		i >>= 16;
	}
	if (n >= uint8(i >> 8)) {
		r += 8;
		i >>= 8;
	}
	return r + nth_set_index(uint8(v >> r), n - uint8(i));
}

inline int nth_set_index(uint64 v, int n) {
	uint64	i	= v - ((v >> 1) & 0x5555555555555555LL);
	i = (i & 0x3333333333333333LL) + ((i >> 2) & 0x3333333333333333LL);
	i = ((i + (i >> 4)) & 0x0f0f0f0f0f0f0f0fLL) * 0x0101010101010100LL;

	int	r = 0;
	if (n >= uint8(i >> 32)) {
		r += 32;
		i >>= 32;
	}
	if (n >= uint8(i >> 16)) {
		r += 16;
		i >>= 16;
	}
	if (n >= uint8(i >> 8)) {
		r += 8;
		i >>= 8;
	}
	return r + nth_set_index(uint8(v >> r), n - uint8(i));
}

// nth set bit
inline uint8 nth_set_bit(uint8 v, int n) {
	uint8	i0 = v - ((v >> 1) & 0x55);
	uint8	i1 = (i0 & 0x33) + ((i0 >> 2) & 0x33);

	uint8		r = 1;
	if (n >= (i1 & 0xf)) {
		n	-= (i1 & 0xf);
		i0	>>= 4;
		r	<<= 4;
	}
	if (n >= (i0 & 3)) {
		n	-= i0 & 3;
		r	<<= 2;
	}
	if (n || !(v & r))
		r <<= 1;
	return r;
}

inline uint16 nth_set_bit(uint16 v, int n) {
	uint16	i0 = v - ((v >> 1) & 0x5555);
	uint16	i1 = (i0 & 0x3333) + ((i0 >> 2) & 0x3333);
	uint16	i2 = (i1 + (i1 >> 4)) & 0xf;
	
	uint16	r = 1;
	if (n >= i2) {
		n	-= i2;
		r	<<= 8;
		i0	>>= 8;
		i1	>>= 8;
	}
	if (n >= (i1 & 0xf)) {
		n	-= (i1 & 0xf);
		i0	>>= 4;
		r	<<= 4;
	}
	if (n >= (i0 & 3)) {
		n	-= i0 & 3;
		r	<<= 2;
	}
	if (n || !(v & r))
		r <<= 1;
	return r;
}

inline uint32 nth_set_bit(uint32 v, int n) {
	uint32	i = v - ((v >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = ((i + (i >> 4)) & 0xf0f0f0f) * 0x01010101;
	
	int	r = 0;
	if (n >= uint8(i >> 16)) {
		r += 16;
		i >>= 16;
	}
	if (n >= uint8(i >> 8)) {
		r += 8;
		i >>= 8;
	}
	return nth_set_bit(uint8(v >> r), n - uint8(i)) << r;
}

inline uint64 nth_set_bit(uint64 v, int n) {
	uint64	i	= v - ((v >> 1) & 0x5555555555555555LL);
	i = (i & 0x3333333333333333LL) + ((i >> 2) & 0x3333333333333333LL);
	i = ((i + (i >> 4)) & 0x0f0f0f0f0f0f0f0fLL) * 0x0101010101010100LL;

	int	r = 0;
	if (n >= uint8(i >> 32)) {
		r += 32;
		i >>= 32;
	}
	if (n >= uint8(i >> 16)) {
		r += 16;
		i >>= 16;
	}
	if (n >= uint8(i >> 8)) {
		r += 8;
		i >>= 8;
	}
	return nth_set_bit(uint8(v >> r), n - uint8(i)) << r;
}

template<uint64 X>	struct T_highedge {
	static const uint64	A = X | (X >> 32);
	static const uint64	B = A | (A >> 16);
	static const uint64	C = B | (B >> 8);
	static const uint64	D = C | (C >> 4);
	static const uint64	E = D | (D >> 2);
	static const uint64	value	= E | (E >> 1);
};
template<uint64 X>	struct T_next_pow2 {
	static const uint64	value	= T_highedge<X - 1>::value + 1;
};
template<uint64 X>	struct T_lowest_set {
	static const uint64	value	= X & -X;
};
template<uint64 X>	struct T_highest_set {
	static const uint64	A		= T_highedge<X>::value;
	static const uint64	value	= A - (A >> 1);
};
template<uint64 X>	struct T_lowest_set_index {
	static const uint8	value	= LOG2(X & -X);
};
template<uint64 X>	struct T_highest_set_index {
	static const uint8	value	= LOG2(X);
};
template<uint64 X>	struct T_clear_lowest {
	static const uint64	value	= X & (X - 1);
};

inline uint32 _highedge4(uint8 x) {
	x |= x >> 2;
	return x | (x >> 1);
}
inline uint32 _highedge(uint8 x) {
	x |= x >> 4;
	x |= x >> 2;
	return x | (x >> 1);
}
inline uint32 _highedge(uint16 x) {
	x |= x >> 8;
	x |= x >> 4;
	x |= x >> 2;
	return x | (x >> 1);
}
inline uint32 _highedge(uint32 x) {
	x |= x >> 16;
	x |= x >> 8;
	x |= x >> 4;
	x |= x >> 2;
	return x | (x >> 1);
}
inline uint64 _highedge(uint64 x) {
	x |= x >> 32;
	x |= x >> 16;
	x |= x >> 8;
	x |= x >> 4;
	x |= x >> 2;
	return x | (x >> 1);
}
template<typename T> inline uint_type_t(T) _highedge(T x)				{ return _highedge((uint_type_t(T)&)x);	}

template<typename T> inline bool	is_pow2(T x)						{ return (x & (x - 1)) == 0;			}
template<typename T> inline T		lowest_set(T x)						{ return x & -x;						}
template<typename T> inline T		highest_set(T x)					{ x = _highedge(x); return x - (x >> 1);}
template<typename T> inline T		clear_lowest(T x)					{ return x & (x - 1);					}
template<typename T> inline T		clear_highest(T x)					{ return x & _highedge(x >> 1);			}

inline uint32	highest_set2(uint8 x)		{ return min(x, 2);}
inline uint32	highest_set4(uint8 x)		{ x = _highedge4(x); return x - (x >> 1);}
inline int		lowest_set_index4(uint8 x)	{ return x & 3 ? (x + 1) & 1 : x & 12 ? (x & 4 ? 2 : 3) : -1; }
inline int		highest_set_index4(uint8 x)	{ return x & 12 ? (x >> 2) + 1 : x & 3 ? x - 1 : -1; }

// bit indices
#if defined(__GNUC__)
inline int							highest_set_index(unsigned x)			{ return x ? __builtin_clz(x) ^ (sizeof(x) * 8 - 1) : -1; }
inline int							highest_set_index(unsigned long x)		{ return x ? __builtin_clzl(x) ^ (sizeof(x) * 8 - 1) : -1; }
template<typename T> inline int		highest_set_index(T x)					{ return highest_set_index(uint_type(sizeof(T) < 4 ? 32 : sizeof(T) * 8)(x));	}
#ifdef PLAT_PS3
inline int							highest_set_index(uint64 x)				{ return x > 0x100000000ULL ? highest_set_index(uint32(x >> 32)) + 32 : highest_set_index(uint32(x)); }
template<typename T> inline int		lowest_set_index(T x)					{ return highest_set_index(x & -x);	}
#else
inline int							highest_set_index(unsigned long long x)	{ return x ? __builtin_clzll(x) ^ (sizeof(x) * 8 - 1) : -1; }
inline int							lowest_set_index(unsigned x)			{ return __builtin_ffs(x) - 1; }
inline int							lowest_set_index(unsigned long x)		{ return __builtin_ffsl(x) - 1; }
inline int							lowest_set_index(unsigned long long x)	{ return __builtin_ffsll(x) - 1; }
template<typename T> inline int		lowest_set_index(T x)					{ return lowest_set_index(uint_type(sizeof(T) < 4 ? 32 : sizeof(T) * 8)(x));	}
#endif
#elif defined(PLAT_X360)
template<typename T> inline int		lowest_set_index(T x)					{ return highest_set_index(lowest_set(x)); }
template<typename T> inline int		highest_set_index(T x)					{ return 31 - _CountLeadingZeros(x); }
inline int							highest_set_index(uint64 x)				{ return 63 - _CountLeadingZeros64(x); }
#elif defined(PLAT_PC)
template<typename T> inline int		lowest_set_index(T x)					{ DWORD i; return _BitScanForward(&i, x) ? i : -1;	}
template<typename T> inline int		highest_set_index(T x)					{ DWORD i; return _BitScanReverse(&i, x) ? i : -1;	}
#if defined(_M_IA64) || defined(_M_X64)
inline int							lowest_set_index(uint64 x)				{ DWORD i; return _BitScanForward64(&i, x) ? i : -1;}
inline int							highest_set_index(uint64 x)				{ DWORD i; return _BitScanReverse64(&i, x) ? i : -1;}
#else
inline int							lowest_set_index(uint64 x)				{ DWORD i; return _BitScanForward(&i, uint32(x)) ? i : _BitScanForward(&i, uint32(x>>32)) ? i + 32 : -1;	}
inline int							highest_set_index(uint64 x)				{ DWORD i; return _BitScanReverse(&i, uint32(x>>32)) ? i + 32 : _BitScanReverse(&i, uint32(x)) ? i : -1;	}
#endif
#else
template<typename T> inline int		lowest_set_index(T x)					{ return x ? int(count_bits(T((x - 1) & ~x))) : -1; }
template<typename T> inline int		highest_set_index(T x)					{ return count_bits(_highedge(x)) - 1; }
#endif

template<typename T> inline int		lowest_clear_index(T x)					{ return lowest_set_index(~x); }
template<typename T> inline int		highest_clear_index(T x)				{ return highest_set_index(~x); }

template<typename T> inline T		next_pow2(T x)							{ return T(1) << (highest_set_index(x - 1) + 1); }

// assumes x has only 1 bit set
inline int	bit_index(uint8 x) {
	uint8	m = x | (x >> 4);
	m |= (m & 0xcc) >> 2;
	m |= (m & 0xaa) >> 1;
	return	((m >> 2) & 4) | ((m >> 1) & 3);
}
inline int	bit_index(uint16 x) {
	uint16	m = x | (x >> 8);
	m |= (m & 0xf0f0) >> 4;
	m |= (m & 0xcccc) >> 2;
	m |= (m & 0xaaaa) >> 1;
	return	((m >> 5) & 8) | ((m >> 2) & 4) | ((m >> 1) & 3);
}
inline int	bit_index(uint32 x) {
	uint32	m = x | (x >> 16);
	m |= (m & 0xff00ff00) >> 8;
	m |= (m & 0xf0f0f0f0) >> 4;
	m |= (m & 0xcccccccc) >> 2;
	m |= (m & 0xaaaaaaaa) >> 1;
	return	((m >> 12) & 16) | ((m >> 5) & 8) | ((m >> 2) & 4) | ((m >> 1) & 3);
}
inline int	bit_index(uint64 x) {
	uint64	m = x | (x >> 32);
	m |= (m & 0xffff0000ffff0000ull) >> 16;
	m |= (m & 0xff00ff00ff00ff00ull) >> 8;
	m |= (m & 0xf0f0f0f0f0f0f0f0ull) >> 4;
	m |= (m & 0xccccccccccccccccull) >> 2;
	m |= (m & 0xaaaaaaaaaaaaaaaaull) >> 1;
	return	((m >> 27) & 32) | ((m >> 12) & 16) | ((m >> 5) & 8) | ((m >> 2) & 4) | ((m >> 1) & 3);
}

// lowest consecutive n bits (starting at bits set in starts)
template<typename T> inline int lowest_set_index(T x, int n, T starts = ~T(0)) {
	T	m	= bits<T>(n);
	int	s;
	while ((s = lowest_set_index(x & starts)) < sizeof(T) * 8 - n) {
		if (((x >> s) & m) == m)
			return s;
		x &= -highest_set(~x & (m << s));
	}
	return -1;
}

// lowest consecutive n bits
template<typename T> inline int highest_set_index(T x, int n, T starts = ~T(0)) {
	T	m	= bits<T>(n);
	int	s;
	while ((s = highest_set_index(x)) >= n) {
		if (((x >> (s - n)) & m) == m)
			return s;
		x &= (lowest_set(~x & (m << (s - n))) - 1);
	}
	return -1;
}

#if defined(__GNUC__) || defined(_MSC_VER)
template<typename T> inline uint32	log2_floor(T x)				{ return highest_set_index(x);	}
#else
template<typename T> inline uint32	log2_floor(T x)				{ return float_components(typename _float_type<sizeof(T)>::type(x)).get_exp();	}
//	template<typename T> inline uint32	log2_floor(T x)			{ return count_bits(_highedge(x)) - 1;	}
#endif
template<typename T> inline uint32	log2_ceil(T x)				{ return log2_floor(x - 1) + 1;	}
template<typename T> inline typename T_enable_if<T_isint<T>::value, uint32>::type log2(T x)	{ return log2_floor(x - 1) + 1;	}

//-----------------------------------------------------------------------------
// reverse/interleave
//-----------------------------------------------------------------------------

//flip(T)
template<typename T, int N> struct s_reverse_bits { static inline T f(T x) {
	return s_reverse_bits<T, N / 2>::f(((x & s_chunkmask<T,N>::value) << N) | ((x >> N) & s_chunkmask<T,N>::value));
} };
template<typename T> struct s_reverse_bits<T,0> { static inline T f(T x) { return x; } };
template<typename T> inline T reverse_bits(T x) { return s_reverse_bits<uint_type_t(T), sizeof(T) * 4>::f((uint_type_t(T)&)x); }

inline uint32 reverse_bits2(uint8 i) { return s_reverse_bits<uint8, 1>::f(i); }
inline uint32 reverse_bits4(uint8 i) { return s_reverse_bits<uint8, 2>::f(i); }

//part_by_1(T)
template<typename T, int N> struct s_part_by_1 { static inline T f(T x) {
	return s_part_by_1<T, N / 2>::f((x ^ (x << N)) & s_chunkmask<T,N>::value);
} };
template<typename T> struct s_part_by_1<T,0> { static inline T f(T x) { return x; } };
template<typename T> inline uint_type(sizeof(T) * 16) part_by_1(T x) { return s_part_by_1<uint_type(sizeof(T) * 16), sizeof(T) * 4>::f(x); }

//even_bits(T)
template<typename T, int N> struct s_even_bits { static inline T f(T x) {
	x = s_even_bits<T, N / 2>::f(x) & s_chunkmask<T,N>::value;
	return x | (x >> N);
} };
template<typename T> struct s_even_bits<T,0> { static inline T f(T x) { return x; } };
template<typename T> inline uint_type(sizeof(T) * 4) even_bits(T x) { return s_even_bits<T, sizeof(T) * 2>::f(x); }

//interleave(T) & uninterleave(T)
template<typename T, int N> struct s_interleave {
	static const T	m = s_chunkmask<T, N>::value << N;
	static inline T f(T x) { return s_interleave<T, N / 2>::f((x & ~(m | (m << N))) | ((x & m) << N) | ((x >> N) & m)); }
	static inline T g(T x) { x = s_interleave<T, N / 2>::g(x); return (x & ~(m | (m << N))) | ((x & m) << N) | ((x >> N) & m); }
};
template<typename T> struct s_interleave<T,0>	{
	static inline T f(T x) { return x; }
	static inline T g(T x) { return x; }
};
template<typename T> inline T interleave(T x)	{ return s_interleave<uint_type_t(T), sizeof(T) * 2>::f((uint_type_t(T)&)x); }
template<typename T> inline T uninterleave(T x) { return s_interleave<uint_type_t(T), sizeof(T) * 2>::g((uint_type_t(T)&)x); }

// separate each N bits by M zeros (for B bits)
// un-separate each N bits separated by M zeros (for B bits)
template<typename T, int N, int M, int I, bool MltN> struct s_part_bits {
	static const T	m = s_bitblocks<T, (N + M) << I, N << I>::value;
	static inline T f(T x) { return s_part_bits<T, N, M, I - 1, MltN>::f((x ^ (x << (M << I))) & m); }
	static inline T g(T x) { x = s_part_bits<T, N, M, I - 1, MltN>::g(x) & m; return x ^ (x >> (M << I)); }
};
template<typename T, int N, int M, bool MltN> struct s_part_bits<T, N, M, 0, MltN> {
	static const T	m = s_bitblocks<T, N + M, N>::value;
	static inline T f(T x) { return (x ^ (x << M)) & m; }
	static inline T g(T x) { x &= m; return x ^ (x >> M); }
};
template<typename T, int N, int M, int I> struct s_part_bits<T, N, M, I, true> {
	static const T	m = s_bitblocks<T, (N + M) << (I + 1), N << I>::value;
	static inline T f(T x) { return s_part_bits<T, N, M, I - 1, true>::f((x & m) ^ ((x & ~m) << (M << I)));	}
	static inline T g(T x) { x = s_part_bits<T, N, M, I - 1, true>::g(x); return (x & m) ^ ((x >> (M << I)) & (m << (N << I))); }
};
template<typename T, int N, int M> struct s_part_bits<T, N, M, 0, true> {
	static const T	m = s_bitblocks<T, (N + M) * 2, N>::value;
	static inline T f(T x) { return (x & m) ^ ((x & ~m) << M); }
	static inline T g(T x) { return (x & m) ^ ((x >> M) & (m << N)); }
};

#define PART_RESULT(N,M,B)		uint_type(B / N * (N + M) + B % N)
template<int N, int M, int B, typename T> inline PART_RESULT(N,M,B) part_bits(T x) {
	return s_part_bits<PART_RESULT(N,M,B), N, M, LOG2((B - 1) / N), M < N>::f(x);
}
template<int N, int M, typename T> inline PART_RESULT(N, M, sizeof(T) * 8) part_bits(T x) {
	return part_bits<N, M, sizeof(T) * 8, T>(x);
}
#undef PART_RESULT

template<int N, int M, int B, typename T> inline uint_type(B) unpart_bits(T x) {
	return s_part_bits<T, N, M, LOG2((B - 1) / N), true>::g(x);
}
template<int N, int M, typename T> inline uint_type((sizeof(T) * 8 + N + M - 1) / (N + M) * N) unpart_bits(T x) {
	return unpart_bits<N, M, (sizeof(T) * 8 + N + M - 1) / (N + M) * N, T>(x);
}

//-----------------------------------------------------------------------------
// isqrt and triangles
//-----------------------------------------------------------------------------


#if 0
template<typename T> T isqrt(T n) {
	T root = 0, remainder = n, place = T(1) << (sizeof(T) * 8 - 2);

	while (place > remainder)
		place >>= 2;

	while (place) {
		if (remainder >= root + place) {
			remainder	-= root + place;
			root		+= place << 1;
		}
		root	>>= 1;
		place	>>= 2;
	}
	return root;
}
#elif 1
template<typename T> T isqrt(T n) {
	T		g		= 0;
	for (int bshift = highest_set_index(n) >> 1; bshift >= 0; bshift--) {
		T	b	= T(1) << bshift;
		T	t	= ((g << 1) + b) << bshift;
		if (t <= n) {
			g	+= b;
			n	-= t;
		}
	}
	return g;
}
#else
template<typename T> T isqrt(T n) {
	T	r = 0;
	for (T	b = T(1) << (sizeof(T) * 4 - 1); b; b >>= 1) {
		T	t = r | b;
		if (x >= t * t)
			r = t;
	}
	return r;
}
#endif

inline int triangle_number(int n) {
	return n * (n + 1) / 2;
}
inline int from_triangle_number(int i) {
	return (isqrt(8 * i + 1) - 1) / 2;
}

//with [i,i] index
inline int triangle_index(int a, int b) {
	return a < b ? triangle_number(b) + a : triangle_number(a) + b;
}
inline int triangle_row(int n, int i) {
	return (isqrt(8 * i + 1) - 1) / 2;
}
inline int triangle_col(int n, int i) {
	return i - triangle_number(triangle_row(n, i));
}
inline int triangle_deindex(int n, int i) {
	int	r = triangle_row(n, i);
	return r * n + i - triangle_number(r);
}

//no [i,i] index
inline int triangle_number_excl(int n) {
	return triangle_number(n - 1);
}
inline int triangle_index_excl(int a, int b) {
	return a < b ? triangle_number(b - 1) + a : triangle_number(a - 1) + b;
}

//-----------------------------------------------------------------------------
//	bitarray
//-----------------------------------------------------------------------------

template<typename T> constexpr bool bits_subset(const T &a, const T &b)			{ return !(a & ~b); }
template<typename T> constexpr bool bits_proper_subset(const T &a, const T &b)	{ return a != b && bits_subset(a, b); }

template<typename T> struct _bitarray {
	enum {BITS_PER_T = sizeof(T) * 8, MASK = BITS_PER_T - 1};

	class bitref {
		T	&i;
		T	m;
	public:
		bitref(T &_i, T _m)		: i(_i), m(_m)	{}
		bitref(T *data, int i)	: i(data[i / BITS_PER_T]), m(bit<T>(i & MASK))	{}

		operator	bool()				const	{ return !!(i & m);	}
		void		clear()				const	{ i &= ~m;			}
		void		set()				const	{ i |= m;			}
		void		flip()				const	{ i ^= m;			}
		bool		test_set()			const	{ T t = i & m; i |= m; return !!t;	}
		bool		test_set(bool b)	const	{ T t = i & m; i ^= t ^ (-T(b) & m); return !!t; }
		bool		test_clear()		const	{ T t = i & m; i ^= t; return !!t;	}
		bool		test_flip()			const	{ T t = i & m; i ^= m; return !!t;	}
		bool		operator=(bool b)	const	{ i = (i & ~m) | (-T(b) & m); return b; }
	};

	struct bitindex {
		T	*data;
		int	i;
		bitindex(T *_data, int _i) : data(_data), i(_i)	{}
		int			index()				const	{ return i; }
		operator	bitref()			const	{ return bitref(data, i); }
		bool		operator=(bool b)	const	{ return get_bit(data, i) = b; }
	};

	class iterator {
		T	*i;
		T	m;
	public:
		typedef bool		element;
		typedef	bitref		reference;
		typedef bidirectional_iterator_t	iterator_category;
		iterator(T *_i, T _m) : i(_i), m(_m)	{}
		iterator&			operator++()					{ m = rotate_left(m, 1); i += m & 1; return *this; }
		iterator&			operator--()					{ i -= m & 1; m = rotate_right(m, 1); return *this; }
		bitref				operator*()				const	{ return bitref(*i, m);	}
		ref_helper<bitref>	operator->()			const	{ return operator*();	}
		bool		operator==(const iterator &b)	const	{ return i == b.i && m == b.m;	}
		bool		operator!=(const iterator &b)	const	{ return i != b.i || m != b.m;	}
	};

	class const_iterator {
		const T	*i;
		T	m;
	public:
		typedef bool		element, reference;
		typedef bidirectional_iterator_t	iterator_category;
		const_iterator(const T *_i, T _m) : i(_i), m(_m)	{}
		const_iterator&	operator++()	{ m = rotate_left(m, 1); i += m & 1; }
		const_iterator&	operator--()	{ i -= m & 1; m = rotate_right(m, 1); }
		bool		operator*()	const	{ return !!(*i & m); }
		bool		operator==(const const_iterator &b) const	{ return i == b.i && m == b.m;	}
		bool		operator!=(const const_iterator &b) const	{ return i != b.i || m != b.m;	}
	};

	template<bool set> class set_iterator {
		T		*data;
		int		N;
		int		i;
	public:
		typedef bool		element;
		typedef	bitindex	reference;
		typedef bidirectional_iterator_t	iterator_category;
		set_iterator(T *_data, int _N, int _i) : data(_data), N(_N), i(_i)	{}
		set_iterator&		operator++()						{ i = next(data, i + 1, set, N); return *this; }
		set_iterator&		operator--()						{ i = prev(data, i, set); return *this; }
		bitindex			operator*()					const	{ return bitindex(data, i); }
		ref_helper<bitref>	operator->()				const	{ return bitref(data, i); }
		bool		operator==(const set_iterator &b)	const	{ return i == b.i;	}
		bool		operator!=(const set_iterator &b)	const	{ return i != b.i;	}
	};

	template<bool set> class set_container {
		T		*data;
		int		N;
	public:
		set_container(T *_data, int _N) : data(_data), N(_N)	{}
		set_iterator<set>	begin() const { return set_iterator<set>(data, N, next(data, 0, set, N)); }
		set_iterator<set>	end()	const { return set_iterator<set>(data, N, -1); }
	};

	static uint32			nt(int N)						{ return (N + int(BITS_PER_T) - 1) / int(BITS_PER_T); }

	static void				set_bit(T *data, int i)			{ data[i / BITS_PER_T] |= bit<T>(i & MASK); }
	static void				clear_bit(T *data, int i)		{ data[i / BITS_PER_T] &= ~bit<T>(i & MASK); }

	static bitref			get_bit(T *data, int i)			{ return bitref(data, i); }
	static bool				get_bit(const T *data, int i)	{ return !!(data[i / BITS_PER_T] & bit<T>(i & MASK));	}

	static iterator			get_it(T *data, int i)			{ return iterator( data + i / BITS_PER_T, bit<T>(i & MASK)); }
	static const_iterator	get_it(const T *data, int i)	{ return const_iterator(data + i / BITS_PER_T, bit<T>(i & MASK)); }

	//single bits
	static int				prev(const T *data, int i, bool set);
	static int				next(const T *data, int i, bool set, int N);
	//multiple bits
	static int				prev(const T *data, int i, int n, bool set, T starts);
	static int				next(const T *data, int i, int n, bool set, T starts, int N);

	static bool				all(const T *data, int i, int n, bool set);
	static void				set(T *data, int i, int n);
	static void				clear(T *data, int i, int n);
	static void				flip(T *data, int i, int n);

	static void				copy(T *data0, const T *data1, int n);
	static void				flip(T *data0, const T *data1, int n);
	static bool				same(T *data0, T *data1, int n);
	static bool				subset(T *data0, T *data1, int n);

	static uint32			count_set(T *data, int i, int n);
};

//single bits

template<typename T> int _bitarray<T>::prev(const T *data, int i, bool set) {
	T		flip	= T(set) - 1;
	const T	*end	= data + nt(i);

	if (T t = (end[-1] ^ flip) & bits<T>(((i - 1) & MASK) + 1))
		return ((i - 1) & ~MASK) + highest_set_index(t);

	for (const T *p = end - 1; p-- != data;) {
		if (T t = *p ^ flip)
			return (p - data) * BITS_PER_T + highest_set_index(t);
	}
	return -1;
}

template<typename T> int _bitarray<T>::next(const T *data, int i, bool set, int N) {
	if (i >= N)
		return -1;

	T		flip	= T(set) - 1;
	const T *p		= data + i / BITS_PER_T;

	if (T t = (*p ^ flip) & ~bits<T>(i & MASK)) {
		int n = (i & ~MASK) + lowest_set_index(t);
		if (n < N)
			return n;
	}

	const T	*end	= data + nt(N);
	while (++p < end) {
		if (T t = *p ^ flip) {
			int	n = int(p - data) * BITS_PER_T + lowest_set_index(t);
			if (n < N)
				return n;
		}
	}
	return -1;
}

//multiple bits

template<typename T> int _bitarray<T>::prev(const T *data, int i, int n, bool set, T starts) {
	T		flip	= -T(set);
	const T	*end	= data + nt(i);

	if (int nt = n / BITS_PER_T) {
		// multiple Ts
		for (const T *p = end; p-- > data + nt; ) {
			const T	*p0 = p;
			int		c	= nt;
			T		t;
			while (--c && (t = *p ^ flip) == 0)
				p--;
			if (c == 0) {
				uint32	s = p0 < end - 1 ? lowest_set_index(((p0[1] ^ flip) & starts) | (p0 == end - 2 ? -bit<T>(i & MASK) : 0)) : 0;
				if ((t & bits<T>(BITS_PER_T - (n - s) & MASK)) == 0)
					return (p0 - data) * BITS_PER_T + s;
			}
		}
	} else {
		// single T (though can straddle 2)
		T	m = bits<T>(i & MASK);
		for (const T *p = end; p-- > data + nt; m = ~T(0)) {
			if (T t = (*p ^ ~flip) & m) {
				int	s = highest_set_index(t, n, starts);
				if (s >= 0)
					return (p - data) * BITS_PER_T + s;
				if (p > data && (s = lowest_set_index(~t)) > 0 && ((p[-1] ^ flip) & -bit<T>(BITS_PER_T - n + s)) == 0)
					return (p - data) * BITS_PER_T - n + s;
			}
		}
	}
	return -1;
}

template<typename T> int _bitarray<T>::next(const T *data, int i, int n, bool set, T starts, int N) {
	if (i + n > N)
		return -1;

	T		flip	= -T(set);
	const T	*end	= data + nt(N - n);
	T		starts0	= starts;
	starts	&= ~bits<T>(i & MASK);

	if (int nt = n / BITS_PER_T) {
		// multiple Ts
		for (const T *p = data + i / BITS_PER_T; p < end; ++p, starts = starts0) {
			const T	*p0 = p;
			int		c	= nt;
			T		t;
			while (--c && (t = *p ^ flip) == 0)
				++p;
			if (c == 0) {
				uint32	s = p0 > data ? BITS_PER_T - 1 - highest_set_index((p0[-1] & starts) ^ flip) : 0;
				if ((t & bits<T>((n - s) & MASK)) == 0)
					return (p0 - data) * BITS_PER_T - s;
			}
		}
	} else {
		// single T (though can straddle 2)
		for (const T *p = data + i / BITS_PER_T; p < end; ++p, starts = starts0) {
			if (T t = *p ^ ~flip) {
				int	s = lowest_set_index(t, n, starts);
				if (s >= 0)
					return (p - data) * BITS_PER_T + s;
				if (p < end - 1 && (s = highest_set_index(~t)) < BITS_PER_T - 1 && ((p[1] ^ flip) & bits<T>(n + s - BITS_PER_T + 1)) == 0)
					return (p - data) * BITS_PER_T + s + 1;
			}
		}
	}
	return -1;
}

template<typename T> bool _bitarray<T>::all(const T *data, int i, int n, bool set) {
	if (!n)
		return true;

	T	flip	= -T(set);
	T	m0		= -bit<T>(i & MASK);
	T	m1		= ~T(0) >> (-(i + n) & MASK);
	const T	*p	= data + i / BITS_PER_T;
	const T	*e	= data + (i + n - 1) / BITS_PER_T;

	if (p < e) {
		T	all = (*p++ ^ flip) & m0;
		while (all == 0 && p < e)
			all |= *p++ ^ flip;
		return (all | ((*p ^ flip) & m1)) == 0;
	}
	return ((*p ^ flip) & (m0 & m1)) == 0;
}

template<typename T> void _bitarray<T>::set(T *data, int i, int n) {
	if (n) {
		T	*p	= data + i / BITS_PER_T;
		T	*e	= data + (i + n - 1) / BITS_PER_T;
		T	m0	= bits<T>(i & MASK);
		T	m1	= bits<T>((i + n) & MASK);

		if (p < e) {
			*p++ |= ~m0;
			while (p < e)
				*p++ = ~T(0);
			*p |= m1;
		} else {
			*p |= ~m0 & m1;
		}
	}
}
template<typename T> void _bitarray<T>::clear(T *data, int i, int n) {
	if (n) {
		T	*p	= data + i / BITS_PER_T;
		T	*e	= data + (i + n - 1) / BITS_PER_T;
		T	m0	= bits<T>(i & MASK);
		T	m1	= bits<T>((i + n) & MASK);

		if (p < e) {
			*p++ &= m0;
			while (p < e)
				*p++ = 0;
			*p &= ~m1;
		} else {
			*p &= m0 | ~m1;
		}
	}
}
template<typename T> void _bitarray<T>::flip(T *data, int i, int n) {
	if (n) {
		T	*p	= data + i / BITS_PER_T;
		T	*e	= data + (i + n - 1) / BITS_PER_T;
		T	m0	= bits<T>(i & MASK);
		T	m1	= bits<T>((i + n) & MASK);

		if (p < e) {
			*p++ ^= ~m0;
			while (p < e) {
				*p = ~*p;
				++p;
			}
			*p ^= m1;
		} else {
			*p ^= ~m0 & m1;
		}
	}
}

template<typename T> void _bitarray<T>::copy(T *data0, const T *data1, int n) {
	if (n) {
		T	*e0	= data0 + (n - 1) / BITS_PER_T;
		T	m1	= ~T(0) >> (-n & MASK);

		while (data0 < e0)
			*data0++ = *data1++;
		*data0 = (*data0 & ~m1) | (*data1 & m1);
	}
}

template<typename T> void _bitarray<T>::flip(T *data0, const T *data1, int n) {
	if (n) {
		T	*e0	= data0 + (n - 1) / BITS_PER_T;
		T	m1	= ~T(0) >> (-n & MASK);

		while (data0 < e0)
			*data0++ = ~*data1++;
		*data0 = *data0 ^ (*data1 & m1);
	}
}

template<typename T> bool _bitarray<T>::same(T *data0, T *data1, int n) {
	if (!n)
		return true;

	T	*e0	= data0 + (n - 1) / BITS_PER_T;
	T	m1	= ~T(0) >> (-n & MASK);

	while (data0 < e0) {
		if (*data0++ != *data1++)
			return false;
	}
	return (*data0 & m1) == (*data1 & m1);
}

template<typename T> bool _bitarray<T>::subset(T *data0, T *data1, int n) {
	if (!n)
		return true;

	T	*e0	= data0 + (n - 1) / BITS_PER_T;
	T	m1	= ~T(0) >> (-n & MASK);

	while (data0 < e0) {
		if (*data0++ & ~*data1++)
			return false;
	}
	return !((*data0 & m1) & ~*data1);
}

template<typename T> uint32 _bitarray<T>::count_set(T *data, int i, int n) {
	if (!n)
		return 0;

	T	*p	= data + i / BITS_PER_T;
	T	*e	= data + (i + n - 1) / BITS_PER_T;
	T	m0	= -bit<T>(i & MASK);
	T	m1	= ~T(0) >> (-(i + n) & MASK);

	if (p == e)
		return count_bits(*p & m0 & m1);

#if 0
	uint32	total	= count_bits(*p++ & m0);
	while (p < e)
		total += count_bits(*p++);
	return total + count_bits(*p & m1);
#else
	uint32	total	= 0;
	T		accum	= *p++ & m0;
	while (p < e) {
		T	x = *p++;
		T	t = accum & x;
		accum |= x;
		if (t) {
			total += count_bits(accum);
			accum = t;
		}
	}
	return total + count_bits(accum) + count_bits(*p & m1);
#endif
}


template<int N, typename T = uint32> struct bitarray : _bitarray<T> {
	typedef _bitarray<T> B;
	typedef typename B::bitref	reference;
	typedef bool				element;
	using typename B::iterator;
	using typename B::const_iterator;
	template<bool set> using set_iterator = typename B::template set_iterator<set>;
	template<bool set> using set_container = typename B::template set_container<set>;

	enum { NT = (N + sizeof(T) * 8 - 1) / (sizeof(T) * 8) };

	T	data[NT];

	bitarray()							{ iso::clear(data); }
	bitarray(const _not<bitarray> &b)	{ B::flip(data, b.t.data, N); }

	reference	operator[](int i)			{ return reference(data, i); }
	bool		operator[](int i)	const	{ return B::get_bit(data, i); }
	iterator		begin()					{ return iterator(data, 1); }
	iterator		end()					{ return B::get_it(data, N); }
	const_iterator	begin()			const	{ return iterator(data, 1); }
	const_iterator	end()			const	{ return B::get_it(data, N); }
	size_t			size()			const	{ return N; }

	template<bool set> set_iterator<set>	begin()	{ return set_iterator<set>(data, N, B::next(data, 0, set, N)); }
	template<bool set> set_iterator<set>	end()	{ return set_iterator<set>(data, N, -1); }
	template<bool set> set_container<set>	all()	{ return set_container<set>(data, N); }

	//single bits
	int				lowest(bool set)							const	{ return B::next(data, 0, set, N); }
	int				highest(bool set)							const	{ return B::prev(data, N, set); }
	int				lowest_clear()								const	{ return lowest(false);	}
	int				lowest_set()								const	{ return lowest(true);	}
	int				highest_clear()								const	{ return highest(false);}
	int				highest_set()								const	{ return highest(true);	}
	//next/prev
	int				next(int i, bool set)						const	{ return B::next(data, i, set, N); }
	int				prev(int i, bool set)						const	{ return B::prev(data, i, set); }
	int				next_clear(int i)							const	{ return next(i, false); }
	int				next_set(int i)								const	{ return next(i, true); }
	int				prev_clear(int i)							const	{ return prev(i, false); }
	int				prev_set(int i)								const	{ return prev(i, true); }
	//multiple bits
	int				lowest(int n, bool set, T starts = ~T(0))	const	{ return B::next(data, 0, n, set, starts, N); }
	int				highest(int n, bool set, T starts = ~T(0))	const	{ return B::prev(data, N, n, set, starts); }
	int				lowest_clear(int n, T starts = ~T(0))		const	{ return lowest(n, false, starts);	}
	int				lowest_set(int n, T starts = ~T(0))			const	{ return lowest(n, true, starts); }
	int				highest_clear(int n, T starts = ~T(0))		const	{ return highest(n, false, starts);	}
	int				highest_set(int n, T starts = ~T(0))		const	{ return highest(n, true, starts);	}
	int				next(int i, int n, bool set, T starts = ~T(0))const	{ return B::next(data, i, n, set, starts, N); }
	int				next_clear(int i, int n, T starts = ~T(0))	const	{ return next(i, n, false, starts); }
	int				next_set(int i, int n, T starts = ~T(0))	const	{ return next(i, n, true, starts); }
	int				prev(int i, int n, bool set, T starts = ~T(0))const	{ return B::prev(data, i, n, set, starts); }
	int				prev_clear(int i, int n, T starts = ~T(0))	const	{ return prev(i, n, false, starts); }
	int				prev_set(int i, int n, T starts = ~T(0))	const	{ return prev(i, n, true, starts); }

	bool			all(int i, int n, bool set)					const	{ return B::all(data, i, n, set); }
	bool			all_set(int i, int n)						const	{ return all(i, n, true); }
	bool			all_clear(int i, int n)						const	{ return all(i, n, false); }
	bool			all(bool set)								const	{ return B::all(data, 0, N, set); }
	bool			all_set()									const	{ return all(true); }
	bool			all_clear()									const	{ return all(false); }

	bool			test(int i)									const	{ return B::get_bit(data, i); }
	void			set(int i)											{ return B::set_bit(data, i); }
	void			clear(int i)										{ return B::clear_bit(data, i); }
	void			set(int i, int n)									{ return B::set(data, i, n); }
	void			clear(int i, int n)									{ return B::clear(data, i, n); }

	uint32			count_set()									const	{ return B::count_set(data, 0, N); }
	uint32			count_set(int i, int n)						const	{ return B::count_set(data, i, n); }
	uint32			count_clear()								const	{ return N - B::count_set(data, 0, N); }
	uint32			count_clear(int i, int n)					const	{ return n - B::count_set(data, i, n); }

	bitarray&		operator+=(const bitarray &b)	{ for (int i = 0; i < NT; i++) data[i] |=  b.data[i]; return *this; }
	bitarray&		operator-=(const bitarray &b)	{ for (int i = 0; i < NT; i++) data[i] &= ~b.data[i]; return *this; }
	bitarray&		operator*=(const bitarray &b)	{ for (int i = 0; i < NT; i++) data[i] &=  b.data[i]; return *this; }
	bitarray&		operator^=(const bitarray &b)	{ for (int i = 0; i < NT; i++) data[i] ^=  b.data[i]; return *this; }
	_not<bitarray>	operator~()						{ return *this;	}

	bool	operator==(const bitarray &b)	const	{ return B::same(data, b.data, N); }
	bool	operator< (const bitarray &b)	const	{ return B::subset(data, b.data, N) && !B::same(data, b.data, N); }
	bool	operator<=(const bitarray &b)	const	{ return B::subset(data, b.data, N); }
	bool	operator> (const bitarray &b)	const	{ return b <  *this; }
	bool	operator>=(const bitarray &b)	const	{ return b <= *this; }

	friend bitarray	operator+(const bitarray &a, const bitarray &b)	{ return bitarray(a) += b; }
	friend bitarray	operator-(const bitarray &a, const bitarray &b)	{ return bitarray(a) -= b; }
	friend bitarray	operator*(const bitarray &a, const bitarray &b)	{ return bitarray(a) *= b; }
};

template<int N, typename T> int num_elements(const bitarray<N, T> &) { return N; }

template<typename T = uint32> struct dynamic_bitarray : _bitarray<T> {
	typedef _bitarray<T> B;
	typedef bool				element;
	typedef typename B::bitref	reference;
	using typename B::iterator;
	using typename B::const_iterator;
	template<bool set> using set_iterator = typename B::template set_iterator<set>;
	template<bool set> using set_container = typename B::template set_container<set>;


	uint32	N;
	T		*data;

	dynamic_bitarray()							: N(0), data(0)						{}
	dynamic_bitarray(int _N)					: N(_N), data(new T[B::nt(_N)])		{ B::clear(data, 0, _N); }
	dynamic_bitarray(const dynamic_bitarray &b)	: N(b.N), data(new T[B::nt(b.N)])	{ B::copy(data, b.data, b.N); }
	dynamic_bitarray(const _not<dynamic_bitarray> &b) : N(b.t.N), data(new T[B::nt(b.t.N)]) { B::flip(data, b.t.data, b.t.N); }
#ifdef USE_RVALUE_REFS
	dynamic_bitarray(dynamic_bitarray &&b)		: N(b.N), data(b.data)				{ b.data = 0; }
#endif
	~dynamic_bitarray()							{ delete[] data; }

	dynamic_bitarray(const dynamic_bitarray &b, int _N)	: N(_N), data(new T[B::nt(_N)]) {
		B::copy(data, b.data, min(_N, b.N));
		if (_N > b.N)
			clear(b.N, _N - b.N);
	}

	T*	grow(int N1) {
		uint32 nt0 = B::nt(N), nt1 = B::nt(N1);
		if (nt1 > nt0) {
			T *data1 = new T[nt1];
			B::copy(data1, data, N);
			B::clear(data1, N, N1);
			delete[] data;
			data	= data1;
			N		= N1;
		}
		return data;
	}

	reference	operator[](int i)			{ return reference(data, i); }
	bool		operator[](int i)	const	{ return B::get_bit(data, i); }
	iterator			begin()				{ return iterator(data, 1); }
	iterator			end()				{ return B::get_it(data, N); }
	const_iterator		begin()		const	{ return const_iterator(data, 1); }
	const_iterator		end()		const	{ return B::get_it(data, N); }
	size_t				size()		const	{ return N; }

	template<bool set> set_iterator<set>	begin()	{ return set_iterator<set>(data, N, B::next(data, 0, set, N)); }
	template<bool set> set_iterator<set>	end()	{ return set_iterator<set>(data, N, -1); }
	template<bool set> set_container<set>	all()	{ return set_container<set>(data, N); }

	//single bits
	int				lowest(bool set)							const	{ return B::next(data, 0, set, N); }
	int				highest(bool set)							const	{ return B::prev(data, N, set); }
	int				lowest_clear()								const	{ return lowest(false);	}
	int				lowest_set()								const	{ return lowest(true);	}
	int				highest_clear()								const	{ return highest(false);}
	int				highest_set()								const	{ return highest(true);	}
	//next/prev
	int				next(int i, bool set)						const	{ return B::next(data, i, set, N); }
	int				prev(int i, bool set)						const	{ return B::prev(data, i, set); }
	int				next_clear(int i)							const	{ return next(i, false); }
	int				next_set(int i)								const	{ return next(i, true); }
	int				prev_clear(int i)							const	{ return prev(i, false); }
	int				prev_set(int i)								const	{ return prev(i, true); }
	//multiple bits
	int				lowest(int n, bool set, T starts = ~T(0))	const	{ return B::next(data, 0, n, set, starts, N); }
	int				highest(int n, bool set, T starts = ~T(0))	const	{ return B::prev(data, N, n, set, starts); }
	int				lowest_clear(int n, T starts = ~T(0))		const	{ return lowest(n, false, starts);	}
	int				lowest_set(int n, T starts = ~T(0))			const	{ return lowest(n, true, starts); }
	int				highest_clear(int n, T starts = ~T(0))		const	{ return highest(n, false, starts);	}
	int				highest_set(int n, T starts = ~T(0))		const	{ return highest(n, true, starts);	}
	int				next(int i, int n, bool set, T starts = ~T(0))const	{ return B::next(data, i, n, set, starts, N); }
	int				next_clear(int i, int n, T starts = ~T(0))	const	{ return next(i, n, false, starts); }
	int				next_set(int i, int n, T starts = ~T(0))	const	{ return next(i, n, true, starts); }
	int				prev(int i, int n, bool set, T starts = ~T(0))const	{ return B::prev(data, i, n, set, starts); }
	int				prev_clear(int i, int n, T starts = ~T(0))	const	{ return prev(i, n, false, starts); }
	int				prev_set(int i, int n, T starts = ~T(0))	const	{ return prev(i, n, true, starts); }

	bool			all(int i, int n, bool set)					const	{ return B::all(data, i, n, set); }
	bool			all_set(int i, int n)						const	{ return all(i, n, true); }
	bool			all_clear(int i, int n)						const	{ return all(i, n, false); }
	bool			all(bool set)								const	{ return B::all(data, 0, N, set); }
	bool			all_set()									const	{ return all(true); }
	bool			all_clear()									const	{ return all(false); }

	bool			test(int i)									const	{ return B::get_bit(data, i); }
	void			set(int i)											{ return B::set_bit(data, i); }
	void			clear(int i)										{ return B::clear_bit(data, i); }
	void			set(int i, int n)									{ return B::set(data, i, n); }
	void			clear(int i, int n)									{ return B::clear(data, i, n); }

	uint32			count_set()									const	{ return B::count_set(data, 0, N); }
	uint32			count_set(int i, int n)						const	{ return B::count_set(data, i, n); }
	uint32			count_clear()								const	{ return N - B::count_set(data, 0, N); }
	uint32			count_clear(int i, int n)					const	{ return n - B::count_set(data, i, n); }

	dynamic_bitarray&		operator+=(const dynamic_bitarray &b)		{ T *d = grow(b.N); for (const T *s = b.data, *e = s + b.nt(b.N); s != e;) *d++ |= *s++; return *this; }
	dynamic_bitarray&		operator^=(const dynamic_bitarray &b)		{ T *d = grow(b.N); for (const T *s = b.data, *e = s + b.nt(b.N); s != e;) *d++ ^= *s++; return *this; }
	dynamic_bitarray&		operator-=(const dynamic_bitarray &b)		{ T *d = data; for (const T *s = b.data, *e = s + min(B::nt(N), b.nt(b.N)); s != e;) *d++ &= ~*s++; return *this; }
	dynamic_bitarray&		operator*=(const dynamic_bitarray &b)		{ T *d = data; for (const T *s = b.data, *e = s + min(B::nt(N), b.nt(b.N)); s != e;) *d++ &=  *s++; return *this; }
	_not<dynamic_bitarray>	operator~()									{ return *this;	}

	bool	operator==(const dynamic_bitarray &b)				const	{ return B::same(data, b.data, min(N, b.N)) && (N < b.N ? b.all_clear(N, b.N - N) : all_clear(b.N, N - b.N)); }
	bool	subset_of(const dynamic_bitarray &b)				const	{ return B::subset(data, b.data, min(N, b.N)) && (N < b.N || all_clear(b.N, N - b.N)); }
	bool	proper_subset_of(const dynamic_bitarray &b)			const	{ uint32 n = min(N, b.N); return B::subset(data, b.data, n) && (N < b.N ? (!B::same(data, b.data, n) || !b.all_clear(N, b.N - N)) : (!B::same(data, b.data, n) && all_clear(b.N, N - b.N))); }

	friend dynamic_bitarray	operator+(const dynamic_bitarray &a, const dynamic_bitarray &b)	{ return dynamic_bitarray(a, max(a.N, b.N)) += b; }
	friend dynamic_bitarray	operator^(const dynamic_bitarray &a, const dynamic_bitarray &b)	{ return dynamic_bitarray(a, max(a.N, b.N)) ^= b; }
	friend dynamic_bitarray	operator-(const dynamic_bitarray &a, const dynamic_bitarray &b)	{ return dynamic_bitarray(a) -= b; }
	friend dynamic_bitarray	operator*(const dynamic_bitarray &a, const dynamic_bitarray &b)	{ return dynamic_bitarray(a, min(a.N, b.N)) *= b; }
};

template<typename T> int num_elements(const dynamic_bitarray<T> &a) { return a.size(); }

//-----------------------------------------------------------------------------
//	morton_number
//-----------------------------------------------------------------------------

template<typename T> struct masked_number {
	const T	mask, rest;
	T		i;
	masked_number(T _mask, T _i = 0) : mask(_mask), rest(_i & _mask), i(_i)	{}
	void				operator=(T t)	{ i = t; }
	operator T()		const			{ return (i & ~mask) | rest; }

	void				set(T t) {
		i = 0;
		for (T m = mask, a, b; m && t; t /= b / a, m &= -b) {
			a	= lowest_set(m);
			b	= lowest_set(~m & -a);
			i	|= (t * a) & (b - 1);
		}
	}
	T					get() const {
		T	t = 0;
		for (T m = mask, s = 1, a, b; m & i; s *= b / a, m &= -b) {
			a	= lowest_set(m);
			b	= lowest_set(~m & -a);
			t	|= (i & (b - a)) / a * s;
		}
		return t;
	}
	masked_number&		operator+=(masked_number &b)	{ i = (i |  mask) + (b.i & ~mask); return *this; }
	masked_number&		operator-=(masked_number &b)	{ i = (i & ~mask) - (b.i & ~mask); return *this; }

	masked_number&		operator++()	{ i = (i |  mask) + 1; return *this; }
	masked_number&		operator--()	{ i = (i & ~mask) - 1; return *this; }
	masked_number		operator++(int)	{ masked_number r(*this); operator++(); return r; }
	masked_number		operator--(int)	{ masked_number r(*this); operator--(); return r; }

	friend T			get(const masked_number &a)	{ return a; }
};

template<typename T> struct morton_number : masked_number<T> {
	morton_number(int nbits) : masked_number<T>(0xaaaaaaaa & bits(nbits * 2), 0)	{}
	void		operator=(T t)				{ this->i = t; }
	void		set(T t)					{ this->i = part_by_1(t); }
	T			get() const					{ return unpart_by_1(this->i); }
	friend T	get(const morton_number &a)	{ return a; }
};
/*
template<typename T> struct interleaved2 {
	struct _t {
		const T	mask;
		T		i;
	};
	struct _x : _t {
		void	operator++()	{ i = (i |  mask) + 1; }
		void	operator--()	{ i = (i & ~mask) - 1; }
	};
	struct _y : _t {
		void	operator++()	{ i = (i | ~mask) + 1; }
		void	operator--()	{ i = (i &  mask) - 1; }
	};
	union {
		_x	x;
		_y	y;
	};
	interleaved2(T _mask) { x.mask = _mask; x.i = 0; }
};
*/
} // namespace iso
#endif
