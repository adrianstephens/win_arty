#undef min
#undef max

#ifndef DEFS_H
#define DEFS_H

#include "defs_base.h"
#include "defs_int.h"
#include "defs_endian.h"
#include "iterator.h"
#include "stdarg.h"

#define alloc_auto(T,N)	(T*)alloca((N) * sizeof(T))
#define auto_new(T)		new(alloca(sizeof(T))) T

#ifndef _WIN32
struct GUID {
	iso::uint32	Data1;
	iso::uint16	Data2;
	iso::uint16	Data3;
	iso::uint8	Data4[8];
};
inline int compare(const GUID &a, const GUID &b)		{ return memcmp(&a, &b, sizeof(GUID)); }
inline bool operator==(const GUID &a, const GUID &b)	{ return compare(a, b) == 0; }
inline bool operator!=(const GUID &a, const GUID &b)	{ return compare(a, b) != 0; }
#endif

namespace iso {

//-----------------------------------------------------------------------------
//	constexpr
//-----------------------------------------------------------------------------

template<size_t N> using byte_array = constexpr_array<uint8, N>;

constexpr auto		le_byte_array(uint16 v)	{ return byte_array<2>{{ uint8(v), uint8(v >> 8) }}; }
constexpr auto		le_byte_array(uint32 v)	{ return byte_array<4>{{ uint8(v), uint8(v >> 8), uint8(v >> 16), uint8(v >> 24) }}; }
constexpr auto		le_byte_array(ulong v)	{ return byte_array<4>{{ uint8(v), uint8(v >> 8), uint8(v >> 16), uint8(v >> 24) }}; }
constexpr auto		le_byte_array(uint64 v)	{ return byte_array<8>{{ uint8(v), uint8(v >> 8), uint8(v >> 16), uint8(v >> 24), uint8(v >> 32), uint8(v >> 40), uint8(v >> 48), uint8(v >> 56) }}; }

constexpr auto		be_byte_array(uint16 v)	{ return byte_array<2>{{ uint8(v >> 8), uint8(v) }}; }
constexpr auto		be_byte_array(uint32 v)	{ return byte_array<4>{{ uint8(v >> 24), uint8(v >> 16), uint8(v >> 8), uint8(v) }}; }
constexpr auto		be_byte_array(ulong v)	{ return byte_array<4>{{ uint8(v >> 24), uint8(v >> 16), uint8(v >> 8), uint8(v) }}; }
constexpr auto		be_byte_array(uint64 v)	{ return byte_array<8>{{ uint8(v >> 56), uint8(v >> 48), uint8(v >> 40), uint8(v >> 32), uint8(v >> 24), uint8(v >> 16), uint8(v >> 8), uint8(v) }}; }

constexpr uint16	bytes_to_u2(uint8 a, uint8 b)					{ return (uint32(b) << 8) | uint32(a); }
constexpr uint32	bytes_to_u4(uint8 a, uint8 b, uint8 c, uint8 d)	{ return (uint32(d) << 24) | (uint32(c) << 16) | (uint32(b) << 8) | uint32(a); }
constexpr uint64	bytes_to_u8(uint8 a, uint8 b, uint8 c, uint8 d, uint8 e, uint8 f, uint8 g, uint8 h)		{ return bytes_to_u4(a, b, c, d) | (uint64(bytes_to_u4(e, f, g, h)) << 32); }

constexpr auto		to_byte_array(const GUID &v)				{ return be_byte_array(v.Data1) + be_byte_array(v.Data2) + be_byte_array(v.Data3) + make_constexpr_array(v.Data4); }
//template<typename T> constexpr auto	to_byte_array(const T &v)	{ return make_constexpr_array<sizeof(T)>((const uint8*)&v); }

//implemented in platform.cpp
uint64	random_seed();

template<template<typename> class T> struct num_types {
	typedef	typename T<iso::uint8>::type			uint8;
	typedef	typename T<iso::uint16>::type			uint16;
	typedef	typename T<iso::uint32>::type			uint32;
	typedef	typename T<iso::uint64>::type			uint64;
	typedef	typename T<iso::int8>::type				int8;
	typedef	typename T<iso::int16>::type			int16;
	typedef	typename T<iso::int32>::type			int32;
	typedef	typename T<iso::int64>::type			int64;
	typedef	typename T<iso::float32>::type			float32;
	typedef	typename T<iso::float64>::type			float64;
	typedef	typename T<iso::xint16>::type			xint16;
	typedef	typename T<iso::xint32>::type			xint32;
	typedef	typename T<iso::xint64>::type			xint64;
};

#if 1
template<template<typename> class T, class B> struct num_types2 {
	typedef	typename T<typename B::uint8>::type		uint8;
	typedef	typename T<typename B::uint16>::type	uint16;
	typedef	typename T<typename B::uint32>::type	uint32;
	typedef	typename T<typename B::uint64>::type	uint64;
	typedef	typename T<typename B::int8>::type		int8;
	typedef	typename T<typename B::int16>::type		int16;
	typedef	typename T<typename B::int32>::type		int32;
	typedef	typename T<typename B::int64>::type		int64;
	typedef	typename T<typename B::float32>::type	float32;
	typedef	typename T<typename B::float64>::type	float64;
	typedef	typename T<typename B::xint16>::type	xint16;
	typedef	typename T<typename B::xint32>::type	xint32;
	typedef	typename T<typename B::xint64>::type	xint64;
};

template<typename T> struct packed_type { typedef packed<T> type; };
template<typename T> struct packed_types : num_types2<packed_type, T> {};

#else

template<template<typename> class T, template<typename> class U> struct T_type_T {
	template<typename V> struct type : T<U<V> > {};
};

template<typename T> struct packed_type { typedef packed<T> type; };
template<template<typename> class T> struct packed_types : num_types<T_type_T<packed_type,T> >::type> {};

#endif

typedef num_types<T_type>	native;
template<typename T>	struct T_swap_endian0_type	: T_swap_endian_type<T>		{};
template<typename T>	struct T_bigendian0_type	: T_endian_type<T, true>	{};
template<typename T>	struct T_littleendian0_type	: T_endian_type<T, false>	{};

template<typename T>	struct T_swap_endian1_type	: T_constructable_swap_endian_type<T>	{};
template<typename T>	struct T_bigendian_type		: T_constructable_endian_type<T, true>	{};
template<typename T>	struct T_littleendian_type	: T_constructable_endian_type<T, false>	{};

#ifdef	ISO_BIGENDIAN
typedef native							bigendian, bigendian0;
typedef num_types<T_swap_endian1_type>	littleendian;
typedef num_types<T_swap_endian0_type>	littleendian0;
#else
typedef native							littleendian, littleendian0;
typedef num_types<T_swap_endian1_type>	bigendian;
typedef num_types<T_swap_endian0_type>	bigendian0;
#endif

template<bool be> struct endian_types;
template<> struct endian_types<false>	: littleendian	{};
template<> struct endian_types<true>	: bigendian		{};

template<bool be> struct endian_types0;
template<> struct endian_types0<false>	: littleendian0	{};
template<> struct endian_types0<true>	: bigendian0	{};

template<int B, typename T> class T_swap_endian<baseint<B, T> > : public T_swap_endian<T> {
public:
	using T_swap_endian<T>::operator=;
	using T_swap_endian<T>::T_swap_endian;
	friend T	get(T_swap_endian &a)		{ return a; }
	friend T	get(const T_swap_endian &a)	{ return a; }
};

template<typename T, bool S> struct T_signed_native	: T_signed<typename T_native_endian<T>::type, S> {};

//-----------------------------------------------------------------------------
//	compact - cram a type into less bits
//-----------------------------------------------------------------------------

template<typename T, int N> class compact {
	typedef typename T_native_endian<T>::type		T0;
	uintn<(N + 7) / 8, T_is_bigendian<T>::value>	t;
public:
	compact()							{}
	compact(const T0 &t2)				{ t = t2; }
	T0			get()	const			{ return T0((uint_type(N))t); }
	operator	T0()	const			{ return get(); }
	T0			operator=(const T0 &t2)	{ t = t2; return t2; }
	T0			operator+=(const T0 &b)	{ return operator=(get() + b); }
	T0			operator-=(const T0 &b)	{ return operator=(get() - b); }
	T0			operator*=(const T0 &b)	{ return operator=(get() * b); }
	T0			operator/=(const T0 &b)	{ return operator=(get() / b); }
	T0			operator%=(const T0 &b)	{ return operator=(get() % b); }
	T0			operator&=(const T0 &b)	{ return operator=(get() & b); }
	T0			operator|=(const T0 &b)	{ return operator=(get() | b); }
	T0			operator<<=(int b)		{ return operator=(get() << b); }
	T0			operator>>=(int b)		{ return operator=(get() >> b); }
};

typedef compact<bool, 8>	bool8;

//-----------------------------------------------------------------------------
//	optional
//-----------------------------------------------------------------------------

template<typename T> struct optional {
	typedef typename T_underlying<T>::type T0;
	T		t;
	bool	_exists;
	optional()				: _exists(false)		{}
	optional(const _none&)	: _exists(false)		{}
	optional(const T0 &x)	: t(x), _exists(true)	{}
	optional(T0 &&x)		: t(move(x)), _exists(true)	{}
	template<typename T2> T& operator=(const T2 &x)	{ _exists = true; return t = x; }
	operator const	T&()		const				{ ISO_ASSERT(exists()); return t; }
	operator		T&()							{ ISO_ASSERT(exists()); return t; }
	bool			exists()	const				{ return _exists; }
	T				or_default(const T &def = T()) const	{ return _exists ? t : def; }
	friend const T&	get(const optional &t)			{ return t; }
	friend T&		get(optional &t)				{ t._exists = true; return t.t; }
};
template<typename T> struct T_underlying<optional<T> > { typedef T type; };

template<> struct optional<bool> {
	_uint_type<sizeof(bool)>::type	t;
	optional()				: t(2)					{}
	optional(const _none&)	: t(2)					{}
	optional(bool  x)		: t(x)					{}
	bool			operator=(bool x)				{ t = x; return x; }
	operator		bool()		const				{ ISO_ASSERT(exists()); return t == 1; }
	bool			exists()	const				{ return t < 2; }
	bool			or_default(bool def = false) const	{ return t < 2 ? t == 1 : def; }
	friend bool		get(const optional &t)			{ return t; }
	friend bool&	get(optional &t)				{ return (bool&)t.t; }
};

template<> struct optional<bool8> {
	uint8				t;
	optional()				: t(2)					{}
	optional(const _none&)	: t(2)					{}
	optional(bool  x)		: t(x)					{}
	bool			operator=(bool x)				{ t = x; return x; }
	operator		bool()		const				{ ISO_ASSERT(exists()); return t == 1; }
	bool			exists()	const				{ return t < 2; }
	bool			or_default(bool def = false) const	{ return t < 2 ? t == 1 : def; }
	friend bool		get(const optional &t)			{ return t; }
	friend bool8&	get(optional &t)				{ return (bool8&)t.t; }
};

template<typename T> struct optional<T*> {
	T		*t;
	optional()				: t((T*)~uintptr_t(0))	{}
	optional(const _none&)	: t((T*)~uintptr_t(0))	{}
	optional(T *x)			: t(x)					{}
	T*				operator=(T *x)					{ return t = x; }
	T*				operator->() const				{ ISO_ASSERT(exists()); return t; }
	operator		T*()		const				{ ISO_ASSERT(exists()); return t; }
	bool			exists()	const				{ return !!~uintptr_t(t); }
	T*				or_default(T *def = 0) const	{ return exists() ? t : def; }
	friend T*		get(const optional &t)			{ return t; }
	friend T*&		get(optional &t)				{ return t.t; }
};


template<typename T> struct optional_temp {
	T	t;
	T	*p;
	optional_temp(T *_p) : p(_p) {}
	optional_temp(T &&_t) : t(move(_t)), p(&t) {}
	operator	T&()			const		{ return *p; }
	auto		operator->()	const		{ return *p; }
	friend T&	get(optional_temp &t)		{ return t; }
	friend T&	get(const optional_temp &t)	{ return t; }
};
template<typename T> struct optional<T&> {
	T		*t;
	optional()				: t((T*)0)				{}
	optional(const _none&)	: t((T*)0)				{}
	optional(T &x)			: t(&x)					{}
	T&				operator=(T &x)					{ return *(t = &x); }
	operator		T&()		const				{ ISO_ASSERT(exists()); return *t; }
	bool			exists()	const				{ return !!t; }
	optional_temp<T> or_default(T &&def = T()) const	{ if (exists()) return t; return move(def); }
	friend T&		get(const optional &t)			{ return t; }
};
template<typename T> struct T_underlying<optional_temp<T>> { typedef T type; };

//-----------------------------------------------------------------------------
//	templated functions
//-----------------------------------------------------------------------------

template<typename T>				inline		void		unused(const T &t)				{}
template<typename A, typename B>	inline		void		raw_copy(const A &a, B &b)		{ memcpy(&b, &a, sizeof(B));				}
template<typename A, typename B>	inline		void		swap(A &a, B &b)				{ A t = a; a = b; b = t;					}
template<typename A, typename B>	inline		A			exchange(A &a, const B &b)		{ A t = a; a = b; return t;					}
template<typename T>				inline		void 		clear(T &t)						{ memset(&t, 0, sizeof(T));					}
template<typename T>				inline		void 		clear(T *t, int n)				{ memset(t, 0, sizeof(T) * n);				}
template<typename T>				constexpr	T*			unconst(const T *t)				{ return const_cast<T*>(t);					}
template<typename T>				constexpr	T&			unconst(const T &t)				{ return const_cast<T&>(t);					}
template<typename T>				constexpr	const T*	_const(T *t)					{ return const_cast<const T*>(t);					}
template<typename T>				constexpr	const T&	_const(T &t)					{ return const_cast<const T&>(t);					}
template<typename T>				constexpr	const T*	get_ptr(const T &t)				{ return &t;								}
template<typename T>				constexpr	T*			get_ptr(T &t)					{ return &t;								}
template<typename T>				constexpr	T*			get_ptr(T &&t)					{ return &t;								}
template<typename T>				constexpr	T*			get_ptr(T *t)					{ return t;									}
template<typename B, typename A>	constexpr	B			up_cast(A *a)					{ return (B)((char*)a - (int)(A*)(B)1 + 1); }
template<typename T, int N>			constexpr	size_t		num_elements(const T (&t)[N])	{ return N;									}
template<typename T, int N>			constexpr	uint32		num_elements32(const T (&t)[N])	{ return N;									}
template<typename T>				constexpr	uint32		num_elements32(const T &t)		{ return uint32(num_elements(t));			}
template<typename T>				constexpr	uint32		sizeof32()						{ return uint32(sizeof(T));					}
template<typename T>				constexpr	uint32		sizeof32(const T&)				{ return uint32(sizeof(T));					}

template<typename B, typename T, int N> inline T B::* member_element(T (B::*array)[N], int i) {
	uintptr_t p = uintptr_t(&(((B*)0)->*array)[i]);
	return *(T B::**)(&p);
}

template<typename D, typename S>	struct cast_s		{ static inline D f(S s) { return num_traits<D>::cast(s); } };
template<typename T>				struct cast_s<T, T>	{ static inline T f(T t) { return t; } };
template<typename D, typename S> inline D	cast(S s)	{ return cast_s<D, S>::f(s); }
template<typename D, typename S> inline void cast_assign(D &d, const S &s) { d = num_traits<D>::cast(s); };

template<typename T> void deleter(T *p)			{ delete p; }
template<typename T> void creator(void *p)		{ new(p) T(); }

template<typename T> constexpr T*		min(T *a,	void *b)	{ return a < b ? a : (T*)b;	}
template<typename T> constexpr T*		max(T *a,	void *b)	{ return a > b ? a : (T*)b;	}
template<typename T> constexpr const T* min(const T *a, const void *b)	{ return a < b ? a : (const T*)b;	}
template<typename T> constexpr const T* max(const T *a, const void *b)	{ return a > b ? a : (const T*)b;	}

template<typename T> constexpr int		min(int a,		T b)	{ return a < b ? a : int	(b); }
template<typename T> constexpr uint32	min(uint32 a,	T b)	{ return a < b ? a : uint32	(b); }
template<typename T> constexpr float	min(float a,	T b)	{ return a < b ? a : float	(b); }
template<typename T> constexpr double	min(double a,	T b)	{ return a < b ? a : double	(b); }
template<typename T> constexpr int		max(int a,		T b)	{ return a > b ? a : int	(b); }
template<typename T> constexpr uint32	max(uint32 a,	T b)	{ return a > b ? a : uint32	(b); }
template<typename T> constexpr float	max(float a,	T b)	{ return a > b ? a : float	(b); }
template<typename T> constexpr double	max(double a,	T b)	{ return a > b ? a : double	(b); }
#if USE_LONG
template<typename T> constexpr ulong	min(ulong a,	T b)	{ return a < b ? a : ulong	(b); }
template<typename T> constexpr long		min(long a,		T b)	{ return a < b ? a : long	(b); }
template<typename T> constexpr ulong	max(ulong a,	T b)	{ return a > b ? a : ulong	(b); }
template<typename T> constexpr long		max(long a,		T b)	{ return a > b ? a : long	(b); }
#endif
#if USE_64BITREGS
template<typename T> constexpr int64	min(int64 a,	T b)	{ return a < b ? a : int64	(b); }
template<typename T> constexpr uint64	min(uint64 a,	T b)	{ return a < b ? a : uint64	(b); }
template<typename T> constexpr int64	max(int64 a,	T b)	{ return a > b ? a : int64	(b); }
template<typename T> constexpr uint64	max(uint64 a,	T b)	{ return a > b ? a : uint64	(b); }
#endif
//template<typename A, typename B> inline A		min(A a, B b) { return _min(a, b); }
//template<typename A, typename B> inline A		max(A a, B b) { return _max(a, b); }

template<typename T> constexpr typename T_enable_if<T_isnum<T>::value, int>::type 	sign(T a)					{ return a < 0 ? -1 : a == 0 ? 0 : 1;	}
template<typename T> constexpr typename T_enable_if<T_isnum<T>::value, int>::type	compare(T a, T b)			{ return a < b ? -1 : a == b ? 0 : 1;	}

template<typename T> constexpr typename T_enable_if<T_isint<T>::value, T>::type		align(T x, uint32 a)		{ return (x + a - 1) / a * a;				}
template<typename T> constexpr typename T_enable_if<T_isint<T>::value, T>::type		align_down(T x, uint32 a)	{ return x / a * a;							}
template<typename T> constexpr typename T_enable_if<T_isint<T>::value, bool>::type	is_aligned(T x, uint32 a)	{ return x % a == 0;						}
template<typename T>							constexpr T*	align(T *t, uint32 a)							{ return (T*)align(uintptr_t(t), a);		}
template<typename T>							constexpr T*	align_down(T *t, uint32 a)						{ return (T*)align_down(uintptr_t(t), a);	}
template<typename T>							constexpr bool	is_aligned(T *t, uint32 a)						{ return is_aligned(uintptr(t), a);			}

template<typename T>							constexpr T		round_pow2(T t, uint32 n)						{ return (t + (1 << (n - 1))) >> n;			}
template<typename T>							constexpr T		ceil_pow2(T t, uint32 n)						{ return (t + (1 << n ) - 1) >> n;			}
template<typename T>							constexpr T		floor_pow2(T t, uint32 n)						{ return t >> n;							}

template<typename T> constexpr typename T_enable_if<T_isint<T>::value, T>::type		align_pow2(T t, uint32 n)		{ return (t + ((1 << n) - 1)) & -(1 << n);	}
template<typename T> constexpr typename T_enable_if<T_isint<T>::value, T>::type		align_down_pow2(T t, uint32 n)	{ return t & -(1 << n);						}
template<typename T> constexpr typename T_enable_if<T_isint<T>::value, bool>::type	is_aligned_pow2(T x, uint32 n)	{ return (x & ((1 << n) - 1)) == 0;			}
template<typename T>							constexpr T*	align_pow2(T *t, uint32 n)						{ return (T*)align_pow2(uintptr_t(t), n);		}
template<typename T>							constexpr T*	align_down_pow2(T *t, uint32 n)					{ return (T*)align_down_pow2(uintptr_t(t), n);	}
template<typename T>							constexpr bool	is_aligned_pow2(T *t, uint32 n)					{ return is_aligned_pow2(uintptr(t), n);		}

template<typename T, typename A, typename B>	constexpr bool	between(const T &v, const A &a, const B &b)		{ return v >= a && v <= b;					}
template<typename T, typename A, typename B>	constexpr T		clamp(const T &v, const A &a, const B &b)		{ return min(max(v, a), b);					}
template<typename A, typename B>				constexpr A		_fix_wrap(const A &a, const B &b)				{ return a < 0 ? a + b : a;					}
template<typename A, typename B>				constexpr A		wrap(const A &a, const B &b)					{ return _fix_wrap(a % b, b);				}
template<typename A, typename B, typename C>	constexpr A		wrap(const A &a, const B &b, const C &c)		{ return wrap(a - b, c - b) + b;			}
template<typename A>							constexpr A		square(const A &a)								{ return a * a;								}
template<typename A>							constexpr A		cube(const A &a)								{ return a * a * a;							}
template<typename A>							constexpr A		twice(const A &a)								{ return a + a;								}


template<typename A, typename B> constexpr typename T_enable_if< T_isint<A>::value, A>::type	div_round(A a, B b)			{ return (a + b / 2) / b;	}
template<typename A, typename B> constexpr typename T_enable_if< T_isint<A>::value, A>::type	div_round_down(A a, B b)	{ return a / b;				}
template<typename A, typename B> constexpr typename T_enable_if< T_isint<A>::value, A>::type	div_round_up(A a, B b)		{ return (a + b - 1) / b;	}
template<typename A, typename B> constexpr typename T_enable_if<!T_isint<A>::value, A>::type	div_round(A a, B b)			{ return round(a / b);		}
template<typename A, typename B> constexpr typename T_enable_if<!T_isint<A>::value, A>::type	div_round_down(A a, B b)	{ return floor(a / b);		}
template<typename A, typename B> constexpr typename T_enable_if<!T_isint<A>::value, A>::type	div_round_up(A a, B b)		{ return ceil(a / b);		}

template<typename A, typename B, typename C, bool BIG = (T_isint<A>::value && T_isint<B>::value && sizeof(A) + sizeof(B) > 8)> struct s_mul_div {
	typedef	typename _uint_type<sizeof(A) + sizeof(B) - sizeof(C)>::type	R;
	static R	mul_div(A a, B b, C c)	{
		A	l, h = mulc(a, b, l);
		return divc(l, h, c);
	}
};

template<typename A, typename B, typename C> struct s_mul_div<A,B,C,false> {
	enum { AI = T_isint<A>::value, I = AI || T_isint<B>::value };
	typedef	typename T_if<I, typename _uint_type<sizeof(A) + sizeof(B) - sizeof(C)>::type, typename T_if<AI, B, A>::type>::type	R;
	typedef	typename T_if<I, typename _uint_type<sizeof(A) + sizeof(B)>::type, R>::type									M;
	static constexpr R	mul_div(A a, B b, C c)	{ return M(a) * b / c; }
};

template<typename A, typename B, typename C> constexpr typename s_mul_div<A, B, C>::R mul_div(A a, B b, C c) {
	return s_mul_div<A, B, C>::mul_div(a, b, c);
}

template<typename N, typename D> inline N div_check(const N &n, const D &d)	{ return d ? n / d : 0; }
template<typename N, typename D> inline N mod_check(const N &n, const D &d)	{ return d ? n % d : n; }

template<typename T> void negate(T &t) { t = -t; }

template<typename T> struct comparisons {
	template<typename U> friend bool operator==(const T &a, const U &b) { return compare(a, b) == 0; }
	template<typename U> friend bool operator!=(const T &a, const U &b) { return compare(a, b) != 0; }
	template<typename U> friend bool operator< (const T &a, const U &b) { return compare(a, b) <  0; }
	template<typename U> friend bool operator<=(const T &a, const U &b) { return compare(a, b) <= 0; }
	template<typename U> friend bool operator> (const T &a, const U &b) { return compare(a, b) >  0; }
	template<typename U> friend bool operator>=(const T &a, const U &b) { return compare(a, b) >= 0; }
};

//-----------------------------------------------------------------------------
//	getter
//-----------------------------------------------------------------------------

template<class C> struct getter {
	C	&c;
	getter(C &_c) : c(_c) {}
	template<typename T> constexpr operator T() const	{
		return c.template get<T>();
	}
};

//-----------------------------------------------------------------------------
//	struct consts (enum in specified type)
//-----------------------------------------------------------------------------

template<typename E, typename S> struct consts {
	S		v;
public:
	consts()							{}
	consts(const E &e)	: v(e)			{}
	operator	E()		const			{ return E(v);		}
	const E&	operator=(const E &e)	{ v = e; return e;	}
};

//-----------------------------------------------------------------------------
//	struct flags
//-----------------------------------------------------------------------------

#define ENUM_FLAGOPS(X)\
	inline X operator|(X a, X b)	{ return X(int(a) | b); }\
	inline X operator^(X a, X b)	{ return X(int(a) ^ b); }\
	inline X operator-(X a, X b)	{ return X(int(a) & ~b); }

template<typename E, typename S = uint32> struct flags {
	S		v;
	flags()		: v(0)					{}
	flags(S e)	: v(e)					{}
	operator	S()				const	{ return v;					}

	flags&	set(E e)					{ v |= e;	return *this;	}
	flags&	set(E e, bool b)			{ v = (v & ~e) | (-int(b) & e); return *this; }
	flags&	clear(E e)					{ v &= ~e;	return *this;	}
	flags&	flip(E e)					{ v ^= e;	return *this;	}
	flags&	swap(E e1, E e2)			{ bool b1 = test(e1); set(e1, test(e2)); set(e2, b1); return *this;	}

	flags&	set_all(S e)				{ v |= e;	return *this;	}
	flags&	clear_all(S e)				{ v &= ~e;	return *this;	}
	flags&	flip_all(S e)				{ v ^= e;	return *this;	}

	flags	with_set(E e)		const	{ return v | e;				}
	flags	with_set(E e, bool b)const	{ return (v & ~e) | (-int(b) & e); }
	flags	with_clear(E e)		const	{ return v & ~e;			}
	flags	with_flip(E e)		const	{ return v ^ e;				}

	flags	with_set_all(S e)	const	{ return v | e;				}
	flags	with_clear_all(S e)	const	{ return v & ~e;			}
	flags	with_flip_all(S e)	const	{ return v ^ e;				}

	constexpr bool	test(E e)		const	{ return !!(v & e);			}
	constexpr bool	test_any(S e)	const	{ return !!(v & e);			}
	constexpr bool	test_all(S e)	const	{ return (v & e) == e;		}

	bool	test_set(E e)				{ S t = v & e; v |= e; return !!t;	}
	bool	test_set(E e, bool b)		{ S t = v & e; v ^= t ^ (-int(b) & e); return !!t;	}
	bool	test_clear(E e)				{ S t = v & e; v ^= t; return !!t;	}
	bool	test_flip(E e)				{ S t = v & e; v ^= e; return !!t;	}
	bool	flip_test(E e)				{ v ^= e; return !!(v & e);			}
};

//-----------------------------------------------------------------------------
//	pointer_aux - store auxilliary information in unused (low) pointer bits
//-----------------------------------------------------------------------------

template<typename T, int B = T_alignment<T>::value> struct pointer_aux {
	uintptr_t	v;
	constexpr pointer_aux(uintptr_t _v = 0) : v(_v)		{}
	T*				operator=(T *p)						{ v = (v & (B - 1)) | uintptr_t(p); return p; }
	constexpr T*				get()			const	{ return (T*)(v & -intptr_t(B)); }
	constexpr operator T*()						const	{ return get(); }
	constexpr T*				operator->()	const	{ return get(); }
	constexpr uint32			aux()			const	{ return v & (B - 1); }
	constexpr uint32			test(uint32 u)	const	{ return v & u; }
	pointer_aux&	aux(uint32 u)						{ v = (v & -intptr_t(B)) | u; return *this; }
	pointer_aux&	set(uint32 u)						{ v |= u; return *this; }
	pointer_aux&	set(uint32 m, uint32 u)				{ v = (v & ~uintptr_t(m)) | u; return *this; }
	pointer_aux&	clear(uint32 u)						{ v &= ~uintptr_t(u); return *this; }
	pointer_aux&	flip(uint32 u)						{ v ^= u; return *this;	}
	constexpr friend T*	get(const pointer_aux &t)		{ return t; }
};

//-----------------------------------------------------------------------------
//	arbitrary
//-----------------------------------------------------------------------------

class arbitrary {
	uintptr_t	p;
public:
	arbitrary()			{}
	arbitrary			&me()							{ return *this;	}
	bool				operator!()				const	{ return !p; }
	uintptr_t			operator&(uintptr_t b)	const	{ return p & b; }
	uintptr_t			operator|(uintptr_t b)	const	{ return p | b; }
	uintptr_t			operator>>(int b)		const	{ return p >> b; }
	uintptr_t			operator<<(int b)		const	{ return p << b; }
	operator			const void*()			const	{ return (const void*)p;	}
	template<typename T> arbitrary(const T &t)			{ ISO_COMPILEASSERT(sizeof(T) <= sizeof(p)); p = 0; new((void*)this) T(t);	}
	template<typename T> T&				as()			{ ISO_COMPILEASSERT(sizeof(T) <= sizeof(p)); return *(T*)&p; }
	template<typename T> const T&		as()	const	{ ISO_COMPILEASSERT(sizeof(T) <= sizeof(p)); return *(T*)&p; }
	template<typename T> operator T&()					{ return as<T>(); }
	template<typename T> operator const T&()	const	{ return as<T>(); }
	template<typename T> T &operator=(const T &t)		{ p = 0; return as<T>() = t; }
};

class arbitrary_ptr {
	uintptr_t	p;
	struct deref {
		uintptr_t	p;
		deref(uintptr_t _p) : p(_p) {}
		template<typename T> T& operator=(const T &t)	{ return *(T*)p = t; }
	};
public:
	arbitrary_ptr()		{}
	arbitrary_ptr(nullptr_t)						: p(0)				{}
	template<typename T> arbitrary_ptr(T *t)		: p(uintptr_t(t))	{}
	template<typename T> arbitrary_ptr(const T *t)	: p(uintptr_t(t))	{}
	arbitrary_ptr		&me()							{ return *this; }
	bool				operator!()				const	{ return !p; }
	operator			bool()					const	{ return !!p; }
	template<typename T> operator T*()			const	{ return (T*)p;	}
	template<typename T> operator const T*()	const	{ return (T*)p;	}
	template<typename T> T *operator=(T *t)				{ p = uintptr_t(t); return t; }
	template<typename T> const T *operator=(const T *t)	{ p = uintptr_t(t); return t; }
	deref				operator*()				const	{ return p; }
	friend arbitrary_ptr align(arbitrary_ptr x, uint32 a) { return (void*)align(x.p, a); }
};

class arbitrary_const_ptr {
	uintptr_t	p;
public:
	arbitrary_const_ptr()	{}
	arbitrary_const_ptr(nullptr_t)						: p(0)				{}
	template<typename T> arbitrary_const_ptr(const T *t): p(uintptr_t(t))	{}
	arbitrary_const_ptr	&me()							{ return *this; }
	bool				operator!()				const	{ return !p; }
	operator			bool()					const	{ return !!p; }
	template<typename T> const T *operator=(const T *t)	{ p = uintptr_t(t); return t; }
	template<typename T> operator const T*()	const	{ return (const T*)p; }
	friend arbitrary_const_ptr align(arbitrary_const_ptr x, uint32 a) { return (const void*)align(x.p, a); }
};

//-----------------------------------------------------------------------------
//	WRAP
//-----------------------------------------------------------------------------

template<typename T> struct WRAP {
	typedef typename T_noref<T>::type T0;
	T			t;
	WRAP()										: t()	{}
#ifdef USE_RVALUE_REFS
	template<typename T2> WRAP(T2 &&t2)			: t(forward<T2>(t2)) {}
#else
	template<typename T2> WRAP(const T2 &t2)	: t(t2) {}
	template<typename T2> WRAP(T2 &t2)			: t(t2) {}
#endif
	template<typename T2> void operator=(const T2 &t2)	{ t = t2; }
	template<typename T2> void operator=(T2 &t2)		{ t = t2; }
	operator	const T0&()			const	{ return t;		}
	operator	T0&()						{ return t;		}
	T0&			operator->()				{ return t;		}
	const T0&	operator->()		const	{ return t;		}
	T0*			operator&()					{ return &t;	}
	const T0*	operator&()			const	{ return &t;	}
	friend const T0&	get(const WRAP &p)	{ return p;		}
	friend T0&			get(WRAP &p)		{ return p;		}
};
template<typename T, int N> struct WRAP<T[N]> {
	typedef T	A[N];
	A			t;
	WRAP()									{}
	WRAP(const A &_t)						{ memcpy(t, &t, sizeof(A)); }
	operator	const A&()			const	{ return t;		}
	operator	A&()						{ return t;		}
	A*			operator&()					{ return &t;	}
};
template<typename T> struct WRAP<T*> {
	T			*t;
	WRAP(T *_t = 0) : t(_t)	{}
	void		operator=(T *t2)			{ t = t2; }
	operator	const T*()			const	{ return t;		}
	operator	T*&()						{ return t;		}
	T*			operator->()				{ return t;		}
	const T*	operator->()		const	{ return t;		}
	T**			operator&()					{ return &t;	}
	T* const*	operator&()			const	{ return &t;	}
	T&			operator*()			const	{ return *t;	}
	friend T*	get(const WRAP &p)			{ return p;		}
};
template<> struct WRAP<void> {
	char		_;
	void*		operator&()					{ return this;	}
	const void*	operator&()			const	{ return this;	}
};

template<typename T, typename U> struct cast_s<WRAP<T>*,WRAP<U>*>	{ static WRAP<T>* f(WRAP<U> *u)			{ return reinterpret_cast<WRAP<T>*>(static_cast<T*>(u->t)); } };
template<typename T>	struct cast_s<WRAP<T>*,WRAP<void>*>			{ static WRAP<T>* f(WRAP<void> *u)		{ return reinterpret_cast<WRAP<T>*>(u); } };
template<typename U>	struct cast_s<WRAP<void>*,WRAP<U>*>			{ static WRAP<void>* f(WRAP<U> *u)		{ return reinterpret_cast<WRAP<void>*>(u); } };
template<>				struct cast_s<WRAP<void>*,WRAP<void>*>		{ static WRAP<void>* f(WRAP<void> *u)	{ return reinterpret_cast<WRAP<void>*>(u); } };

template<typename T> struct num_traits<WRAP<T> > : inherited_num_traits<WRAP<T>, T> {};
template<typename T> struct T_swap_endian_type<WRAP<T> >			{ typedef T_swap_endian<T> type; };

template<typename T>		struct T_inheritable			{ typedef T				type; };
template<typename T, int N>	struct T_inheritable<T[N]>		{ typedef WRAP<T[N]>	type; };
template<typename T>		struct T_inheritable<T*>		{ typedef WRAP<T*>		type; };
template<>					struct T_inheritable<void>		{ typedef WRAP<void>	type; };
template<>					struct T_inheritable<bool>		{ typedef WRAP<bool>	type; };
template<>					struct T_inheritable<uint8>		{ typedef WRAP<uint8>	type; };
template<>					struct T_inheritable<uint16>	{ typedef WRAP<uint16>	type; };
template<>					struct T_inheritable<uint32>	{ typedef WRAP<uint32>	type; };
template<>					struct T_inheritable<int8>		{ typedef WRAP<int8>	type; };
template<>					struct T_inheritable<int16>		{ typedef WRAP<int16>	type; };
template<>					struct T_inheritable<int32>		{ typedef WRAP<int32>	type; };
template<>					struct T_inheritable<float>		{ typedef WRAP<float>	type; };
template<>					struct T_inheritable<double>	{ typedef WRAP<double>	type; };
#if USE_LONG
template<>					struct T_inheritable<ulong>		{ typedef WRAP<ulong>	type; };
template<>					struct T_inheritable<long>		{ typedef WRAP<long>	type; };
#endif
#if USE_64BITREGS
template<>					struct T_inheritable<uint64>	{ typedef WRAP<uint64>	type; };
template<>					struct T_inheritable<int64>		{ typedef WRAP<int64>	type; };
#endif
#define ISO_INHERITABLE(T)	ISO_METATYPE(T_inheritable<T>)

template<typename T> struct reference {
	T			&t;
	reference(T &_t)			: t(_t)		{}
	operator	T&()						{ return t;		}
	T&			get()						{ return t;		}
	void		operator=(const T &_t)		{ t = _t;		}
	T&			operator->()				{ return t;		}
	T*			operator&()					{ return &t;	}
};

template<typename T> struct element {
	T			t;
	element()					: t()		{}
	element(const T &_t)		: t(_t)		{}
	operator	T&()						{ return t;		}
	operator	const T&()			const	{ return t;		}
	T&			get()						{ return t;		}
	const T&	get()				const	{ return t;		}
	void		operator=(const T &t2)		{ t = t2;		}
	T&			operator->()				{ return t;		}
	const T&	operator->()		const	{ return t;		}
	T*			operator&()					{ return &t;	}
	const T*	operator&()			const	{ return &t;	}
};

//-----------------------------------------------------------------------------
//	class pair + triple
//-----------------------------------------------------------------------------



template<typename _A, typename _B> struct pair : comparisons<pair<_A, _B> > {
	typedef _A	A;
	typedef _B	B;
	A			a;
	B			b;
	pair() : a(), b()	{}
	template<typename A2, typename B2> pair(const pair<A2,B2> &p)	: a(p.a), b(p.b) {}
#ifdef USE_RVALUE_REFS
	pair(const pair &p)					= default;
	pair(pair &&p)						= default;
	pair&	operator=(const pair &p)	= default;
	pair&	operator=(pair &&p)			= default;
	template<typename A2, typename B2> pair(pair<A2,B2> &&p)					: a(move(p.a)), b(move(p.b))				{}
	template<typename A2, typename B2> pair(A2 &&_a, B2 &&_b)					: a(forward<A2>(_a)), b(forward<B2>(_b))	{}
	template<typename A2, typename B2> pair& operator=(const pair<A2,B2> &p)	{ a = p.a; b = p.b; return *this; }
	template<typename A2, typename B2> pair& operator=(pair<A2,B2> &&p)			{ a = move(p.a); b = move(p.b); return *this; }
#else
	pair(typename T_param<_A>::type _a, typename T_param<_B>::type _b) : a(_a), b(_b)	{}
#endif
	friend void swap(pair &a, pair &b) {
		swap(a.a, b.a);
		swap(a.b, b.b);
	}
	template<typename A2, typename B2> friend int compare(const pair &a, const pair<A2,B2> &b) {
		if (int	c = compare(a.a, b.a))
			return c;
		return compare(a.b, b.b);
	}

};

#ifdef USE_RVALUE_REFS
template<typename A, typename B> inline_only pair<typename T_noarray<typename T_noref<A>::type>::type, typename T_noarray<typename T_noref<B>::type>::type> make_pair(A &&a, B &&b) {
	return pair<typename T_noarray<typename T_noref<A>::type>::type, typename T_noarray<typename T_noref<B>::type>::type>(forward<A>(a), forward<B>(b));
}
#else
template<typename A, typename B> inline_only pair<typename T_noarray<A>::type, typename T_noarray<B>::type> make_pair(const A &a, const B &b) {
	return pair<typename T_noarray<A>::type, typename T_noarray<B>::type>(a, b);
}
#endif

template<typename A, typename B> inline_only pair<const A&, const B&> make_pair_ref(const A &a, const B &b) {
	return pair<const A&, const B&>(a, b);
}

#define PAIR(a,b)		pair<a,b>

template<typename _A, typename _B, typename _C> struct triple : comparisons<triple<_A, _B, _C> > {
	typedef _A	A;
	typedef _B	B;
	typedef _C	C;
	A			a;
	B			b;
	C			c;
	inline_only triple() : a(), b()	{}
	template<typename A2, typename B2, typename C2> inline_only triple(const triple<A2,B2,C2> &rhs) : a(rhs.a), b(rhs.b), c(rhs.c) {}
#ifdef USE_RVALUE_REFS
	triple(const triple &p)				= default;
	triple(triple &&p)					= default;
	triple&	operator=(const triple &p)	= default;
	triple&	operator=(triple &&p)		= default;
	template<typename A2, typename B2, typename C2> triple(triple<A2,B2,C2> &&p)					: a(move(p.a)), b(move(p.b)), c(move(p.c))						{}
	template<typename A2, typename B2, typename C2> triple(A2 &&_a, B2 &&_b, C2 &&_c)				: a(forward<A2>(_a)), b(forward<B2>(_b)), c(forward<C2>(_c))	{}
	template<typename A2, typename B2, typename C2> triple& operator=(const triple<A2,B2,C2> &p)	{ a = p.a; b = p.b; c = p.c; return *this; }
	template<typename A2, typename B2, typename C2> triple& operator=(triple<A2,B2,C2> &&p)			{ a = move(p.a); b = move(p.b); c = move(p.c); return *this; }
#else
	inline_only triple(typename T_param<_A>::type _a, typename T_param<_B>::type _b, typename T_param<_C>::type _c) : a(_a), b(_b), c(_c)	{}
#endif
	friend void swap(triple &a, triple &b) {
		swap(a.a, b.a);
		swap(a.b, b.b);
		swap(a.c, b.c);
	}
	template<typename A2, typename B2, typename C2> friend int compare(const triple &a, const triple<A2,B2,C2> &b) {
		if (int	c = compare(a.a, b.a))
			return c;
		if (int	c = compare(a.b, b.b))
			return c;
		return compare(a.c, b.c);
	}
};

#ifdef USE_RVALUE_REFS
template<typename A, typename B, typename C> inline_only triple<typename T_noarray<typename T_noref<A>::type>::type, typename T_noarray<typename T_noref<B>::type>::type, typename T_noarray<typename T_noref<C>::type>::type> make_triple(A &&a, B &&b, C &&c) {
	return triple<typename T_noarray<typename T_noref<A>::type>::type, typename T_noarray<typename T_noref<B>::type>::type, typename T_noarray<typename T_noref<C>::type>::type>(forward<A>(a), forward<B>(b), forward<C>(c));
}
#else
template<typename A, typename B, typename C> inline_only triple<A, B, C> make_triple(const A &a, const B &b, const C &c) {
	return triple<A, B, C>(a, b, c);
}
#endif

template<typename A, typename B, typename C> inline_only triple<const A&, const B&, const C&> maketriple_ref(const A &a, const B &b, const C &c) {
	return triple<const A&, const B&, const C&>(a, b, c);
}
#define TRIPLE(a,b,c)	triple<a,b,c>

//-----------------------------------------------------------------------------
//	class auto_ptr
//-----------------------------------------------------------------------------

template<typename T, void (*D)(T*) = &deleter<T> > class auto_ptr {
	T	*p;
public:
	typedef T element;

	auto_ptr(T *_p = 0)			: p(_p)				{}
	auto_ptr(auto_ptr<T,D> &_p)	: p(_p.release())	{}
	~auto_ptr()										{ D(p);		}

	template<class T2>	auto_ptr<T,D>& operator=(auto_ptr<T2,D> &p2) { reset(p2.release());	return *this; }
	auto_ptr<T,D>& operator=(auto_ptr<T,D>& p2)		{ reset(p2.release());			return *this; }
	auto_ptr<T,D>& operator=(T *p2)					{ reset(p2);					return *this; }

			operator T*()	const					{ return p;						}
	T&		operator*()		const					{ return *p;					}
	T*		operator->()	const					{ return p;						}
	T*		get()			const					{ return p;						}
	T*		release()								{ T *t = p;	p = 0; return t;	}
	void	reset(T* p2 = 0)						{ T *p1 = p; p = p2; if (p1 && p1 != p2) D(p1); }
	friend void	swap(auto_ptr &a, auto_ptr &b)		{ swap(a.p, b.p); }
	friend T*	get(const auto_ptr &a)				{ return a; }
};

template<typename T> inline_only auto_ptr<T> make_auto_ptr(T *p) { return p; }

//-----------------------------------------------------------------------------
//	class ref_ptr
//-----------------------------------------------------------------------------

template<typename T> class ref_ptr {
protected:
	T	*p;
public:
	static ref_ptr make_noref(T *p)			{ ref_ptr r; r.p = p; return r; }
	ref_ptr(const ref_ptr &b)				{ if (p = b.p) p->addref();	}
	ref_ptr(T *b = 0)						{ if (p = b) p->addref();	}
	~ref_ptr()								{ if (p) p->release();		}
	T*		operator=(T *b)					{ if (b) b->addref(); if (p) p->release(); return p = b; }
	T*		operator=(const ref_ptr &b)		{ return operator=(b.p); }

#ifdef USE_RVALUE_REFS
	ref_ptr(ref_ptr &&b)					{ p = b.p; b.p = 0;	}
	T*		operator=(ref_ptr &&b)			{ swap(p, b.p); return p; }
#endif

	operator T*()			const			{ return p; }
	T*		operator->()	const			{ return p; }
	T*		get()			const			{ return p; }
	void	clear()							{ if (p) { p->release(); p = 0; } }
	friend void	swap(ref_ptr &a, ref_ptr &b){ swap(a.p, b.p); }
	friend T*	get(const ref_ptr &a)		{ return a; }
	friend T*	get(ref_ptr &a)				{ return a; }
};

template<typename T, typename R=uint32> class refs {
friend class ref_ptr<T>;
protected:
	R		nrefs;
	refs() : nrefs(0)		{}
	~refs()					{ ISO_RELEASEASSERT(nrefs == 0); }
	void	addref()		{ ++nrefs; }
	void	release()		{ ISO_RELEASEASSERT(nrefs); if (!--nrefs) delete static_cast<T*>(this); }
	void	addref(int n)	{ nrefs += n; }
	void	release(int n)	{ ISO_RELEASEASSERT(nrefs >= n); if (!(nrefs -= n)) delete static_cast<T*>(this); }
public:
	bool	shared() const	{ return nrefs > 1; }
};

template<typename B, typename T> class inherit_refs : public B {
friend class ref_ptr<T>;
protected:
	inherit_refs()			{}
	template<typename P> inherit_refs(P p)	: B(p) {}
	void	release()		{ if (!--this->nrefs) delete static_cast<T*>(this); }
};

//-----------------------------------------------------------------------------
//	saver
//-----------------------------------------------------------------------------

template<typename T> class saver {
	T	o, &r;
public:
	saver(T &t) : o(t), r(t)				{}
	template<typename N> saver(T &t, const N &n) : o(t), r(t) { t = n; }
	~saver()								{ r = o; }
	operator const T&()		const			{ return o;	}
	const T&	original()	const			{ return o;	}
};

template<typename T> inline_only saver<T> save(T &t)							{ return saver<T>(t); }
template<typename T, typename N> inline_only saver<T> save(T &t, const N &n)	{ return saver<T>(t, n); }


//-----------------------------------------------------------------------------
//	index_setter
//-----------------------------------------------------------------------------

template<class T> struct index_setter {
	T	&t;
	int	i;
	index_setter(T &_t, int _i)	: t(_t), i(_i) {}
	template<typename V> void operator=(const V &v)	{ t.set(i, v); }
};

template<typename T> inline_only index_setter<T> make_index_setter(T &t, int i) {
	return index_setter<T>(t, i);
}

//-----------------------------------------------------------------------------
//	memory_block
//----------------------------------------------------------------------------- 

inline void* memdup(const void *p, size_t s) { 
	return memcpy(malloc(s), p, s);
}

struct memory_block_copy : comparisons<memory_block_copy> {
	void	*start;
	size_t	size;
	memory_block_copy(void *_start, size_t _size) : start(_start), size(_size)	{}
	template<typename T>	operator const T&()	const	{ return *(const T*)start; }
	template<typename T>	operator T&()				{ return *(T*)start; }
	memory_block_copy&		operator=(const memory_block_copy &c) {
		memcpy(start, c.start, size); return *this;
	}
	template<typename T> T&	operator=(const T &t)		{ return *(T*)start = t; }

	friend int compare(const memory_block_copy &a, const memory_block_copy &b) {
		int r = memcmp(a.start, b.start, min(a.size, b.size));
		return r ? r : int(intptr_t(a.size) - intptr_t(b.size));
	}
};

struct memory_block {
	void	*start;
	size_t	size;

	constexpr memory_block()							: start(0), size(0)				{}
	constexpr memory_block(const _none&)				: start(0), size(0)				{}
	constexpr memory_block(void *_start, size_t _size)	: start(_start), size(_size)	{}
	constexpr memory_block(const memory_block &t)		: start(t.start), size(t.size)	{}
	template<typename T> explicit memory_block(T &t)	: start(&t), size(sizeof(T))	{}
	template<typename T> operator T*()			const	{ return (T*)start;				}
	operator arbitrary_ptr()					const	{ return start;					}
	operator arbitrary_const_ptr()				const	{ return start;					}

	memory_block_copy	operator*()				const	{ return memory_block_copy(start, size); }
	operator			safe_bool::type()		const	{ return safe_bool::test(start);}
	size_t				length()				const	{ return size;					}
	uint32				length32()				const	{ return uint32(size);			}
	arbitrary_ptr		begin()					const	{ return start;					}
	arbitrary_ptr		end()					const	{ return (char*)start + size;	}
	void				clear_contents()		const	{ memset(start, 0, size);		}
	size_t				copy_to(void *dest)		const	{ memcpy(dest, start, size); return size; }
	size_t				copy_from(void *srce)	const	{ memcpy(start, srce, size); return size; }
	memory_block		sub_block(void *a, void *b)			const	{ if (!a) a = start; ISO_ASSERT(a >= start && b >= a && b <= end()); return memory_block(a, size_t(b) - size_t(a)); }
	memory_block		sub_block(void *a, intptr_t b = 0)	const	{ return sub_block(a, (b <= 0 ? (char*)end() : (char*)a) + b); }
	memory_block		sub_block(intptr_t a, intptr_t b = 0)const	{ return sub_block((char*)start + (a < 0 ? size + a : a), b); }
	memory_block		sub_block_to(intptr_t b)			const	{ return sub_block(start, b); }
	memory_block		sub_block_to(void *b)				const	{ return sub_block(start, b); }
	template<typename T> memory_block operator+(T i)		const	{ return memory_block((char*)start + i, size - i); }
	template<typename T> void fill(const T &t)				const	{ for (T *i = (T*)start, *e = i + size / sizeof(T); i != e; ++i) *i = t; }
	
	template<typename R> bool	read(R &r)		const	{ return r.readbuff(start, size) == size; }
	template<typename W> bool	write(W &w)		const	{ return w.writebuff(start, size) == size; }

protected:
	void			set(void *_start, size_t _size)	{ start = _start; size = _size;	}
};

struct const_memory_block {
	const void	*start;
	size_t		size;

	constexpr const_memory_block()									: start(0), size(0)				{}
	constexpr const_memory_block(const _none&)						: start(0), size(0)				{}
	constexpr const_memory_block(const void *_start, size_t _size)	: start(_start), size(_size)	{}
	const_memory_block(const memory_block &m)						: start(m.start), size(m.size)	{}
	template<typename T> explicit const_memory_block(const T &t)	: start(&t), size(sizeof(T))	{}
	template<typename T, int N> const_memory_block(const char (&t)[N])	: start(&t), size(N - 1)	{}
	template<typename T> operator const T*()const	{ return (const T*)start;		}
	operator arbitrary_const_ptr()			const	{ return start;					}

	const memory_block_copy	operator*()		const	{ return memory_block_copy(const_cast<void*>(start), size); }
	operator		safe_bool::type()		const	{ return safe_bool::test(start);}
	size_t			length()				const	{ return size;					}
	uint32			length32()				const	{ return uint32(size);			}
	arbitrary_const_ptr	begin()				const	{ return start;					}
	arbitrary_const_ptr	end()				const	{ return (const char*)start + size;	}
	size_t			copy_to(void *dest)		const	{ memcpy(dest, start, size); return size; }
	const_memory_block	sub_block(const void *a, const void *b)	const	{ if (!a) a = start; ISO_ASSERT(a >= start && b >= a && b <= end()); return const_memory_block((void*)a, size_t(b) - size_t(a)); }
	const_memory_block	sub_block(const void *a, intptr_t b = 0)const	{ return sub_block(a, (b <= 0 ? (const char*)end() : (const char*)a) + b); }
	const_memory_block	sub_block(intptr_t a, intptr_t b = 0)	const	{ return sub_block((const char*)start + (a < 0 ? size + a : a), b); }
	const_memory_block	sub_block_to(intptr_t b)				const	{ return sub_block(start, b); }
	const_memory_block	sub_block_to(const void *b)				const	{ return sub_block(start, b); }
	template<typename T> const_memory_block operator+(T i)		const	{ return const_memory_block((const char*)start + i, size - i); }
	template<typename W> bool	write(W &w)	const	{ return w.writebuff(start, size) == size; }

protected:
	void			set(const void *_start, size_t _size)	{ start = _start; size = _size;	}
};

template<typename T> inline_only range<T*> make_range(const memory_block &b) {
	return range<T*>(b, b.end());
}
template<typename T> inline_only range<const T*> make_range(const const_memory_block &b) {
	return range<const T*>(b, b.end());
}
template<typename T> inline_only range<next_iterator<T> > make_next_range(const memory_block &b) {
	return range<next_iterator<T> >(next_iterator<T>(b), next_iterator<T>(b.end(), -1));
}
template<typename T> inline_only range<next_iterator<T> > make_next_range(const const_memory_block &b) {
	return range<next_iterator<T> >(next_iterator<T>(b), next_iterator<T>(b.end(), -1));
}

//-----------------------------------------------------------------------------
//	malloc_block
//----------------------------------------------------------------------------- 

struct malloc_block : memory_block {
	template<typename R> static malloc_block unterminated(R &r) {
		size_t			size = r.remaining();
		malloc_block	mb(size);
		r.readbuff(mb, size);
		return mb;
	}
	template<typename R> static malloc_block zero_terminated(R &r) {
		size_t			size = r.remaining();
		malloc_block	mb(size + 1);
		r.readbuff(mb, size);
		((char*)mb)[size] = 0;
		return mb;
	}

	constexpr malloc_block()							: memory_block()						{}
	constexpr malloc_block(const _none&)				: memory_block()						{}
	malloc_block(size_t n)								: memory_block(malloc(n), n)			{}
	malloc_block(const malloc_block &b)					: memory_block(b.start, b.size)			{ const_cast<malloc_block&>(b).start = 0; }
	malloc_block(const memory_block &b)					: memory_block(malloc(b.size), b.size)	{ memcpy(start, b.start, b.size); }
	malloc_block(const const_memory_block &b)			: memory_block(malloc(b.size), b.size)	{ memcpy(start, b.start, b.size); }
	template<typename R> malloc_block(R &r, size_t n)	: memory_block(malloc(n), n)			{ r.readbuff(start, n); }
	~malloc_block()										{ free(start); }

	malloc_block&	create(size_t n) {
		free(start);
		set(malloc(n), n);
		return *this;
	}
	malloc_block&	operator=(const malloc_block &b) {
		if (&b != this) {
			free(start);
			set(b, b.length());
			const_cast<malloc_block&>(b).start = 0;
		}
		return *this;
	}
	malloc_block&	operator+=(const memory_block &b) {
		size_t	new_len = size + b.size;
		start	= realloc(start, new_len);
		memcpy((char*)start + size, b.start, b.size);
		size	= new_len;
		return *this;
	}
	malloc_block&	operator+=(const const_memory_block &b) {
		size_t	new_len = size + b.size;
		start	= realloc(start, new_len);
		memcpy((char*)start + size, b.start, b.size);
		size	= new_len;
		return *this;
	}
	malloc_block&	reserve(size_t n)					{ if (!start || size < n) create(n); return *this; }
	malloc_block&	resize(size_t n)					{ start = realloc(start, n); size = n; return *this; }
	malloc_block	dup()		const					{ malloc_block m(size); copy_to(m); return m; }

	friend void swap(malloc_block &a, malloc_block &b)	{ swap(a.start, b.start); swap(a.size, b.size); }
	friend memory_block keep(malloc_block &m)			{ memory_block r = m; m.start = 0; return r; }
	friend memory_block keep(malloc_block &&m)			{ memory_block r = m; m.start = 0; return r; }
};

struct ref_malloc_block : memory_block {
protected:
	struct header {
		uint32	nrefs;
		uint64	data[];
		header() : nrefs(1) {}
		void	addref()	{ ++nrefs; }
		void	release()	{ if (--nrefs == 0) delete this; }
		void*	operator new(size_t s, size_t n)	{ return malloc(s + n); }
		void	operator delete(void *p)			{ return free(p); }
	};
	header	*h;
public:
	ref_malloc_block()										: h(0) {}
	ref_malloc_block(const memory_block &m, header *_h = 0)	: memory_block(m), h(_h)	{}
	ref_malloc_block(size_t n)								: memory_block((h = new(n) header)->data, n)	{}
	ref_malloc_block(const ref_malloc_block &b)				: memory_block(b.start, b.size), h(b.h)			{ if (h) h->addref(); }
	template<typename R> ref_malloc_block(R &r, size_t n)	: memory_block((h = new(n) header)->data, n)	{ r.readbuff(start, n); }
	~ref_malloc_block()										{ if (h) h->release(); }

	ref_malloc_block&	create(size_t n) {
		if (h)
			h->release();
		set((h = new(n) header)->data, n);
		return *this;
	}
	ref_malloc_block&	operator=(const ref_malloc_block &b) {
		if (b.h)
			b.h->addref();
		if (h)
			h->release();
		h = b.h;
		set(b, b.length());
		return *this;
	}

	ref_malloc_block	sub_block(void *a, void *b)				const	{ return ref_malloc_block(memory_block::sub_block(a, b), h); }
	ref_malloc_block	sub_block(void *a, intptr_t b = 0)		const	{ return sub_block(a, (b <= 0 ? (char*)end() : (char*)a) + b); }
	ref_malloc_block	sub_block(intptr_t a, intptr_t b = 0)	const	{ return sub_block((char*)start + (a < 0 ? size + a : a), b); }
	template<typename T> ref_malloc_block operator+(T i)		const	{ return ref_malloc_block(memory_block::operator+(i), h); }

	friend void swap(ref_malloc_block &a, ref_malloc_block &b)	{ swap(a.start, b.start); swap(a.size, b.size); }
};

//-----------------------------------------------------------------------------
//	recursion_checker
//-----------------------------------------------------------------------------

template<typename T> struct recursion_checker {
	struct entry {
		T		t;
		entry	*prev;
		recursion_checker *checker;
		entry(recursion_checker *_checker, const T &_t) : t(_t), checker(0) {
			if (!_checker->contains(t)) {
				checker = _checker;
				prev	= _checker->top;
			}
		}
		~entry() {
			if (checker)
				checker->top = prev;
		}
		operator bool() const { return !!checker; }
	};
	entry	*top;

	recursion_checker() : top(0) {}
	~recursion_checker() {
		for (auto *i = top; i; i = i->prev)
			i->checker = 0;
	}
	bool contains(const T &t) {
		for (auto *i = top; i; i = i->prev) {
			if (i->t == t)
				return true;
		}
		return false;
	}
	entry check(const T &t) {
		return entry(this, t);
	}
};

//-----------------------------------------------------------------------------
//	singleton
//-----------------------------------------------------------------------------

template<class T> struct singleton {
	static iso_export T&	single()			{ static T t; return t;		}
	operator 	T&()					const	{ return single();			}
	T&			operator()()			const	{ return single();			}
	T*			operator&()				const	{ return &single();			}
	T*			operator->()			const	{ return &single();			}
	T&			operator=(const T &t)	const	{ return single() = t;		}
};

//-----------------------------------------------------------------------------
//	static_list
//-----------------------------------------------------------------------------

template<typename T> struct static_list_first {
	static iso_export T*&	first()	{ static T *first; return first; }
};

template<typename T> class static_list : protected static_list_first<T> {
protected:
	using static_list_first<T>::first;
	T*						next;
public:
	static_list() {
		next	= first();
		first()	= static_cast<T*>(this);
	}
	~static_list() {
		T *p = first();
		if (this == p) {
			first() = next;
		} else while (p) {
			T *n = p->next;
			if (n == this) {
				p->next = next;
				return;
			}
			p = n;
		}
	}

	class iterator {
		T			*p;
	public:
		typedef struct forward_iterator_t iterator_category;
		typedef T	element;
		typedef T*	pointer;
		typedef T&	reference;
		iterator(T *_p) : p(_p)	{}
					operator T*()		const	{ return p;			}
		T&			operator*()			const	{ return *p;		}
		T*			operator->()		const	{ return p;			}
		bool		operator==(T *p2)	const	{ return p == p2;	}
		bool		operator!=(T *p2)	const	{ return p != p2;	}
		iterator	operator++()				{ p = p->static_list<T>::next; return *this;	}
		iterator	operator++(int)				{ iterator i = *this; p = p->next; return i; }
	};

	static range<iterator>	all()	{ return range<iterator>(first(), NULL); }
	static iterator	begin()			{ return first();	}
	static iterator	end()			{ return NULL;		}
	static int		find(T *t)		{ int i = 0; for (T *j = first(); j && j != t; j = j->next) ++i; return i; }
	static T*		index(int i)	{ T *j; for (j = first(); i && j; i--) j = j->next; return j; }
	
	template<typename U> static T*	find_by(U &&u) {
		for (T *j = first(); j; j = j->next) {
			if (*j == u)
				return j;
		}
		return 0;
	}
};

//-----------------------------------------------------------------------------
//	float types
//-----------------------------------------------------------------------------

template<typename F> struct float_components {
	typedef ISO_METATYPE(_uint_type<sizeof(F)>)	I;
	typedef ISO_METATYPE(_sint_type<sizeof(F)>)	S;
	enum {
		E = num_traits<F>::exponent_bits,
		M = num_traits<F>::mantissa_bits,
	};
	static const S
		E_OFF		= (1 << (E - 1)) - 1;
	static const I
		E_MASK		= (1 << E) - 1,
		M_MASK		= (I(1) << M) - 1,
		S_MASK		= I(1) << (M + E),
		SIGNAL_MASK = I(1) << (M - 1)
	;
	union {
	#ifdef	ISO_BIGENDIAN
		struct {I s:1, e:E, m:M;};
	#else
		struct {I m:M, e:E, s:1;};
	#endif
		I		i;
		F		f;
	};

	static float_components	max()		{ return float_components(M_MASK, E_MASK-1, 0);					}
	static float_components	min()		{ return float_components(0, 1, 0);								}
	static float_components	eps()		{ return float_components(0, E_OFF - M, 0);						}
	static float_components	nan()		{ return float_components(M_MASK, E_MASK, 0);					}
	static float_components	inf()		{ return float_components(0, E_MASK, 0);						}
	static float_components	neg_inf()	{ return float_components(0, E_MASK, 1);						}
	static float_components	inf(bool neg){ return float_components(0, E_MASK, neg);						}
	static float_components exp2(int e) { return float_components(I((e < -E_OFF ? 0 : e + E_OFF))<<M);	}

	static I	to_uint(F f)			{ return float_components(f + F(1<<M)).i & M_MASK;				}
	static S	to_int(F f)				{ S i = S(to_uint(f)); return f < 0 ? -i : i;					}
	static F	to_float(I i)			{ return float_components(i | (M + E_OFF) << M).f - F(1<<M);	}
	static F	to_float(S i)			{ F f = to_float(I(i < 0 ? -i : i)); return i < 0 ? -f : f;		}

	float_components() 		{}
#ifdef	ISO_BIGENDIAN
	constexpr float_components(I _m, int _e, int _s) : s(_s), e(_e), m(_m) {}
#else
	constexpr float_components(I _m, int _e, int _s) : m(_m), e(_e), s(_s) {}
#endif
	constexpr float_components(F _f)	: f(_f)	{}
	constexpr float_components(I _i)	: i(_i)	{}

	bool	get_sign()			const	{ return !!s;					}
	int		get_exp()			const	{ return e - E_OFF;				}
	F		get_mant()			const	{ return float_components(m, E_OFF, s).f;	}

	float_components& set_sign(bool _s)	{ s = int(_s);					return *this; }
	float_components& set_exp(int _e)	{ e = _e + E_OFF;				return *this; }
	float_components& set_mant(F _m)	{ m = float_components(_m).m;	return *this; }
	float_components& add_exp(int _e)	{ e += _e;						return *this; }

	float_components operator-() const	{ return i ^ S_MASK; }

	I		_fracmask()			const	{ return I(-1) >> (e < E_OFF ? 1 : e - E_OFF + E + 1); }
	F		trunc()				const	{ return float_components(i & ~_fracmask()).f;	}
	F		floor()				const	{ I m = _fracmask(); return float_components(i & ~m).f + (s && (i & m) ? -1 : 0);	}
	F		ceil()				const	{ I m = _fracmask(); return float_components(i & ~m).f + (!s && (i & m) ? +1 : 0);	}

	bool	is_special()		const	{ return e == E_MASK;			}
	bool	is_nan()			const	{ return e == E_MASK && m;		}
	bool	is_signalling_nan()	const	{ return is_nan() &&  (m & SIGNAL_MASK);	}
	bool	is_quiet_nan()		const	{ return is_nan() && !(m & SIGNAL_MASK);	}
	bool	is_inf()			const	{ return e == E_MASK && !m;		}
	bool	is_denorm()			const	{ return e == 0 && m;			}

	I		monotonic()	const	{ return (i ^ (0 - s)) ^ float_components(0,0,1).i;	}
};

template<int BYTES>		struct _float_type		{ typedef float64	type; };
template<>				struct _float_type<1>	{ typedef float32	type; };
template<>				struct _float_type<2>	{ typedef float32	type; };
template<>				struct _float_type<3>	{ typedef float32	type; };
template<>				struct _float_type<4>	{ typedef float32	type; };

typedef float_components<float> iorf;
#if USE_64BITREGS
typedef float_components<double> iord;
#endif

inline_only	uint32	float2uint(float f)		{ return iorf::to_uint(f);	}
inline_only	float	uint2float(uint32 i)	{ return iorf::to_float(i);	}
inline_only	int		float2int(float f)		{ return iorf::to_int(f);	}
inline_only	float	int2float(int32 i)		{ return iorf::to_float(i);	}

//-----------------------------------------------------------------------------
//	interval
//-----------------------------------------------------------------------------

template<typename T> struct interval {
	T a, b;

	constexpr interval() {}
	constexpr interval(const _none&)			: a(iso::maximum), b(-iso::maximum)	{}
	constexpr interval(const interval &i)		: a(i.a), b(i.b)	{}
	constexpr interval(const T &_a, const T &_b): a(_a), b(_b)		{}
	explicit interval(const T &_a)				: a(_a), b(_a)		{}
	void	operator=(const T &_a)				{ a = b = _a; }

	constexpr bool overlaps(const interval &i)	const	{ return !(i.b < a) && !(b < i.a); }
	constexpr bool contains(const interval &i)	const	{ return i.a >= a && i.b <= b; }
	constexpr bool contains(const T &t)			const	{ return t >= a && t <= b; }
	constexpr bool		empty()					const	{ return a >= b; }
	constexpr T			minimum()				const	{ return min(a, b); }
	constexpr T			maximum()				const	{ return max(a, b); }
	constexpr SIGNED(T)	length()				const	{ return b - a; }
	constexpr const T&	begin()					const	{ return a; }
	constexpr const T&	end()					const	{ return b; }
	constexpr T			centre()				const	{ return (a + b) / 2; }
	constexpr interval	expand(const T &t)		const	{ return interval(a - t, b + t); }

	T&			begin()							{ return a; }
	T&			end()							{ return b; }

	template<typename F> T	from(F f)	const	{ T t; t = a + f * (b - a); return t; }

	interval& operator|=(const interval &i)	{ a = min(a, i.a); b = max(b, i.b); return *this; }
	interval& operator&=(const interval &i)	{ a = max(a, i.a); b = min(b, i.b); return *this; }
	interval& operator|=(const T &t)		{ a = min(a, t); b = max(b, t); return *this; }
	interval& operator+=(const T &t)		{ a += t; b += t; return *this; }
	interval& operator-=(const T &t)		{ a -= t; b -= t; return *this; }

	friend constexpr bool		operator<(const interval &a, const T &b)				{ return a.b <= b; }
	friend constexpr bool		operator<(const interval &a, const interval &b)			{ return a.a < b.a || (!(b.a < a.a) && a.b < b.b); }
	friend constexpr interval	operator|(const interval &a, const interval &b)			{ return interval(min(a.a, b.a), max(a.b, b.b)); }
	friend constexpr interval	operator&(const interval &a, const interval &b)			{ return interval(max(a.a, b.a), min(a.b, b.b)); }
	friend constexpr interval	operator+(const interval &i, const T &t)				{ return interval(i.a + t, i.b + t); }
	friend constexpr interval	operator-(const interval &i, const T &t)				{ return interval(i.a - t, i.b - t); }
	friend constexpr interval	operator/(const interval &i, const T &t)				{ return interval(i.a / t, i.b / t); }
	friend constexpr interval	mul_about(const interval &i, const T &c, const T &t)	{ return (i - c) * t + c; }
	friend constexpr interval	mul_centre(const interval &i, const T &t)				{ return mul_about(i, i.centre(), t); }
	friend constexpr interval	abs(const interval &i)									{ return interval(i.minimum(), i.maximum()); }

	template<typename F> friend constexpr interval operator*(const interval &a, const interval<F> &b)	{
		return interval<T>(a.from(b.a), a.from(b.b));
	}
};
template<typename T> interval<T> make_interval(const T &a, const T &b)		{ return interval<T>(a, b); }
template<typename T> interval<T> make_abs_interval(const T &a, const T &b)	{ return interval<T>(min(a, b), max(a, b)); }

template<typename I> interval<typename iterator_traits<I>::element> get_extent(I i0, I i1) {
	interval<typename iterator_traits<I>::element>	r(*i0);
	for (++i0; i0 != i1; ++i0)
		r	|= *i0;
	return r;
}

template<typename C> interval<typename container_traits<C>::element> get_extent(const C &c) {
	auto	i0 = c.begin(), i1 = c.end();
	interval<typename container_traits<C>::element>	r(*i0);
	for (++i0; i0 != i1; ++i0)
		r	|= *i0;
	return r;
}

template<typename T> struct interval<constructable<T> > : interval<T> {
	using interval<T>::interval;
	using interval<T>::operator=;
};

//-----------------------------------------------------------------------------
//	rational
//-----------------------------------------------------------------------------

template<typename T> T gcd(T a, T b) {
	if (a > b)
		swap(a, b);
	if (!a)
		return b;
	while (T r = b % a) {
		b = a;
		a = r;
	}
	return a;
}

template<typename T> struct rational {
	T	n, d;

	static rational normalised(T n, T d) {
		T	g = gcd(n, d);
		if (g > 1) {
			n	/= g;
			d	/= g;
		}
		return rational(n, d);
	}

	rational() {}
	rational(T _n, T _d) {
		if (d < 0) {
			n = -_n;
			d = -_d;
		} else {
			n = _n;
			d = _d;
		}
	}
	explicit rational(T _n) : n(_n), d(1) {}

	operator	float()	const	{ return float(n) / d;	}

	template<typename B>	friend rational	operator+(const rational &a, const rational<B> &b)	{ return rational(a.n * b.d + b.n * a.d, a.d * b.d); }
	template<typename B>	friend rational	operator-(const rational &a, const rational<B> &b)	{ return rational(a.n * b.d - b.n * a.d, a.d * b.d); }
	template<typename B>	friend rational	operator*(const rational &a, const rational<B> &b)	{ return rational(a.n * b.n, a.d * b.d); }
	template<typename B>	friend rational	operator/(const rational &a, const rational<B> &b)	{ return rational(a.n * b.d, a.d * b.n); }
	template<typename B>	friend rational	operator+(const rational &a, const B &b)			{ return rational(a.n + b * a.d, a.d); }
	template<typename B>	friend rational	operator-(const rational &a, const B &b)			{ return rational(a.n - b * a.d, a.d); }
	template<typename B>	friend rational	operator*(const rational &a, const B &b)			{ return rational(a.n * b, a.d); }
	template<typename B>	friend rational	operator/(const rational &a, const B &b)			{ return rational(a.n, a.d * b); }
	
	friend rational reciprocal(const rational &r)						{ return rational(r.d, r.n); }
	friend rational frac(const rational<T> &r)							{ return rational(r.n % r.d, r.d); }
	friend T		trunc(const rational<T> &r)							{ return r.n / r.d;	}
	friend T		round(const rational<T> &r)							{ return (r.n + r.d / 2) / r.d;	}
	friend rational mod(const rational<T> &a, const rational<T> &b)		{ return a - b * trunc(a / b); }
};

//-----------------------------------------------------------------------------
//	table generation
//-----------------------------------------------------------------------------

template<typename A, typename B> struct table2 {
	constexpr static int	size()			{ return A::size() + B::size(); }
	constexpr static uint32	index(int i)	{ return i < A::size() ? A::index(i) : B::index(i - A::size()); }
};
template<uint32 A, uint32 B> struct table2<T_constant0<uint32, A>, T_constant0<uint32, B> > {
	constexpr static int	size()			{ return 2; }
	constexpr static uint32 index(int i)	{ return i == 0 ? A : B; }
};

template<typename T, class G, int N, int I> struct gen_table : table2<gen_table<T, G, N / 2, I>, gen_table<T, G, N - N / 2, I + N / 2> > {};

template<typename T, class G, int I> struct gen_table<T, G, 1, I> {
	constexpr static int	size()			{ return 1; }
	constexpr static uint32 index(int i)	{ return G::f(I); }
};

//-----------------------------------------------------------------------------
//	misc
//-----------------------------------------------------------------------------

template<int N, int A = 1>	struct spacer		{ typename _uint_type<A>::type _[N]; };
template<int A>				struct spacer<0,A>	{};
template<typename T>		struct space_for : spacer<sizeof(T) / T_alignment<T>::value, T_alignment<T>::value> {};

template<typename T, int O>	struct offset_type : spacer<O> {
	typedef T type;
	typedef typename T_noref<T>::type T0;
	T			t;
	template<typename T2> offset_type(const T2 &t2)		: t(t2) {}
	template<typename T2> offset_type(T2 &t2)			: t(t2) {}
	template<typename T2> void operator=(const T2 &t2)	{ t = t2; }
	template<typename T2> void operator=(T2 &t2)		{ t = t2; }
	operator	const T0&()			const				{ return t;		}
	operator	T0&()									{ return t;		}
	T0&			operator->()							{ return t;		}
	const T0&	operator->()		const				{ return t;		}
	T0*			operator&()								{ return &t;	}
	const T0*	operator&()			const				{ return &t;	}
	friend const T0&	get(const offset_type &p)		{ return p;		}
	friend T0&			get(offset_type &p)				{ return p;		}
};

template<typename T> struct def_init {
	T	t;
	template<typename T2> def_init(const T2 &t2) : t(t2) {}
	def_init() : t()			{}
	T *operator&()				{ return &t; }
	operator T&()				{ return t; }
	operator const T&() const	{ return t; }
	T& operator=(const T &_t)	{ return t = _t; }
};

template<typename T, int N> struct num_init {
	T	t;
	template<typename T2> num_init(const T2 &t2) : t(t2) {}
	num_init() : t(N)			{}
	T *operator&()				{ return &t; }
	operator T&()				{ return t; }
	operator const T&() const	{ return t; }
	T& operator=(const T &_t)	{ return t = _t; }
};

struct initialise { initialise(...); };

template<typename T> struct _not {
	const T	&t;
	_not(const T &_t) : t(_t) {}
};

template<typename T> _not<T>	make_not(const T &t)		{ return t; }
template<typename T> const T&	make_not(const _not<T> &t)	{ return t.t; }


template<typename T, int I, typename P = T*> struct counted {
	P		p;
	counted()					{}
	counted(T *_p)				{ p = _p; }
	template<typename P2> counted(const counted<T,I,P2> &_p) { p = _p; }
	void	operator=(T *_p)	{ p = _p; }
	operator T*()	const		{ return p; }
	T*		begin()	const		{ return p; }
};
template<int I, typename T> counted<T, I, T*> make_counted(T *p) { return p; }

template<template<class> class M, typename T, int I, typename P> struct T_map<M, counted<T,I,P> > {
	typedef counted<typename T_map<M, T>::type, I, typename T_map<M, P>::type> type;
};

template<typename T, typename... TT> union union_of {
	T				t;
	union_of<TT...>	u;
};
template<typename T> union union_of<T> {
	T				t;
};

template<template<class> class M, typename...TT> struct T_map<M, union_of<TT...> >	{
	typedef union_of<typename T_map<M, TT>::type...> type;
};

template<int I, typename... TT> struct selection {
	union_of<TT...>	t;
};

template<template<class> class M, int I, typename...TT> struct T_map<M, selection<I, TT...> >	{
	typedef selection<I, typename T_map<M, TT>::type...> type;
};


//-----------------------------------------------------------------------------

}//namespace iso

//-----------------------------------------------------------------------------
//	global functions
//-----------------------------------------------------------------------------

// need to be global for some reason

template<int N> inline void *operator new(size_t size, iso::spacer<N> &a)	{ ISO_ASSERT(size <= N); return &a; }
template<int N> inline void *operator new[](size_t size, iso::spacer<N> &a)	{ ISO_ASSERT(size <= N); return &a; }

#endif // DEFS_H
