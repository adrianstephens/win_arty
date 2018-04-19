#undef min
#undef max

#ifndef DEFS_BASE_H
#define DEFS_BASE_H

#include <platform.h>

#ifndef ISO_PREFIX
#define ISO_PREFIX	ISO_PLATFORM
#endif

#ifndef iso_export
#define iso_export
#endif
#ifndef iso_local
#define iso_local
#endif

#ifndef CTOR_RETURN
#define CTOR_RETURN
#endif

#ifdef USE_EXCEPTIONS
#define rethrow			throw
#define iso_throw(x)	throw x
#define catch_all()		catch(...)
#else
#define try				if (true)
#define catch(x)		else if (x=0)
#define catch_all()		else if (0)
#define rethrow
#define iso_throw(x)	iso::unused(x)
#endif

#define COMMA				,
#define CONCAT(x, y)		x##y
#define CONCAT2(x, y)		CONCAT(x, y)
#define CONCAT3(x, y)		CONCAT2(x, y)
#define STRINGIFY(c)		#c
#define STRINGIFY2(c)		STRINGIFY(c)
#define NO_PARENTHESES(...) __VA_ARGS__
#define EXPAND(X)			X

#define VA_N(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,N,...) N
#define VA_HEAD_(_0,...)	_0
#define VA_TAIL_0(...)
#define VA_TAIL_1(_0,...)	,__VA_ARGS__
#define VA_REST_(X,...)		__VA_ARGS__

#if defined PLAT_PC || defined PLAT_X360	// __VA_ARGS__ is always interpreted as a single parameter!
#define VA_N_(tuple)		VA_N tuple
#define VA_HEAD__(tuple)	VA_HEAD_ tuple
#define VA_TAIL__0(tuple)	VA_TAIL_0 tuple
#define VA_TAIL__1(tuple)	VA_TAIL_1 tuple
#define VA_REST__(tuple)	VA_REST_ tuple
#define VA_NUM(...)			VA_N_((__VA_ARGS__,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1))
#define VA_MORE(...)		VA_N_((__VA_ARGS__,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0))
#define VA_HEAD(...)		VA_HEAD__((__VA_ARGS__))
#define VA_TAIL(...)		CONCAT3(VA_TAIL__, VA_MORE(__VA_ARGS__))((__VA_ARGS__))
#define VA_REST(...)		VA_REST__((__VA_ARGS__))
#else
#define VA_NUM(...)			VA_N(__VA_ARGS__,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)
#define VA_MORE(...)		VA_N(__VA_ARGS__,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0)
#define VA_HEAD(...)		VA_HEAD_(__VA_ARGS__,)
#define VA_TAIL(...)		CONCAT3(VA_TAIL_, VA_MORE(__VA_ARGS__))(__VA_ARGS__)
#endif

#define _VA1(M,X)			M(X)
#define _VA2(M,X, ...)		EXPAND(M(X)_VA1 (M,__VA_ARGS__))
#define _VA3(M,X, ...)		EXPAND(M(X)_VA2 (M,__VA_ARGS__))
#define _VA4(M,X, ...)		EXPAND(M(X)_VA3 (M,__VA_ARGS__))
#define _VA5(M,X, ...)		EXPAND(M(X)_VA4 (M,__VA_ARGS__))
#define _VA6(M,X, ...)		EXPAND(M(X)_VA5 (M,__VA_ARGS__))
#define _VA7(M,X, ...)		EXPAND(M(X)_VA6 (M,__VA_ARGS__))
#define _VA8(M,X, ...)		EXPAND(M(X)_VA7 (M,__VA_ARGS__))
#define _VA9(M,X, ...)		EXPAND(M(X)_VA8 (M,__VA_ARGS__))
#define _VA10(M,X, ...)		EXPAND(M(X)_VA9 (M,__VA_ARGS__))
#define _VA11(M,X, ...)		EXPAND(M(X)_VA10(M,__VA_ARGS__))
#define _VA12(M,X, ...)		EXPAND(M(X)_VA11(M,__VA_ARGS__))
#define _VA13(M,X, ...)		EXPAND(M(X)_VA12(M,__VA_ARGS__))
#define _VA14(M,X, ...)		EXPAND(M(X)_VA13(M,__VA_ARGS__))
#define _VA15(M,X, ...)		EXPAND(M(X)_VA14(M,__VA_ARGS__))
#define _VA16(M,X, ...)		EXPAND(M(X)_VA15(M,__VA_ARGS__))
#define _VA17(M,X, ...)		EXPAND(M(X)_VA16(M,__VA_ARGS__))
#define _VA18(M,X, ...)		EXPAND(M(X)_VA17(M,__VA_ARGS__))
#define _VA19(M,X, ...)		EXPAND(M(X)_VA18(M,__VA_ARGS__))
#define _VA20(M,X, ...)		EXPAND(M(X)_VA19(M,__VA_ARGS__))
#define _VA21(M,X, ...)		EXPAND(M(X)_VA20(M,__VA_ARGS__))
#define _VA22(M,X, ...)		EXPAND(M(X)_VA21(M,__VA_ARGS__))
#define _VA23(M,X, ...)		EXPAND(M(X)_VA22(M,__VA_ARGS__))
#define _VA24(M,X, ...)		EXPAND(M(X)_VA23(M,__VA_ARGS__))
#define _VA25(M,X, ...)		EXPAND(M(X)_VA24(M,__VA_ARGS__))
#define _VA26(M,X, ...)		EXPAND(M(X)_VA25(M,__VA_ARGS__))
#define _VA27(M,X, ...)		EXPAND(M(X)_VA26(M,__VA_ARGS__))
#define _VA28(M,X, ...)		EXPAND(M(X)_VA27(M,__VA_ARGS__))
#define _VA29(M,X, ...)		EXPAND(M(X)_VA28(M,__VA_ARGS__))
#define _VA30(M,X, ...)		EXPAND(M(X)_VA29(M,__VA_ARGS__))
#define _VA31(M,X, ...)		EXPAND(M(X)_VA30(M,__VA_ARGS__))
#define VA_APPLY(M,...)		EXPAND(CONCAT3(_VA, VA_NUM(__VA_ARGS__))(M,__VA_ARGS__))

#define _VAP1(M, P,X)		M(P,X)
#define _VAP2(M, P,X, ...)	EXPAND(M(P,X)_VAP1 (M,P,__VA_ARGS__))
#define _VAP3(M, P,X, ...)	EXPAND(M(P,X)_VAP2 (M,P,__VA_ARGS__))
#define _VAP4(M, P,X, ...)	EXPAND(M(P,X)_VAP3 (M,P,__VA_ARGS__))
#define _VAP5(M, P,X, ...)	EXPAND(M(P,X)_VAP4 (M,P,__VA_ARGS__))
#define _VAP6(M, P,X, ...)	EXPAND(M(P,X)_VAP5 (M,P,__VA_ARGS__))
#define _VAP7(M, P,X, ...)	EXPAND(M(P,X)_VAP6 (M,P,__VA_ARGS__))
#define _VAP8(M, P,X, ...)	EXPAND(M(P,X)_VAP7 (M,P,__VA_ARGS__))
#define _VAP9(M, P,X, ...)	EXPAND(M(P,X)_VAP8 (M,P,__VA_ARGS__))
#define _VAP10(M,P,X, ...)	EXPAND(M(P,X)_VAP9 (M,P,__VA_ARGS__))
#define _VAP11(M,P,X, ...)	EXPAND(M(P,X)_VAP10(M,P,__VA_ARGS__))
#define _VAP12(M,P,X, ...)	EXPAND(M(P,X)_VAP11(M,P,__VA_ARGS__))
#define _VAP13(M,P,X, ...)	EXPAND(M(P,X)_VAP12(M,P,__VA_ARGS__))
#define _VAP14(M,P,X, ...)	EXPAND(M(P,X)_VAP13(M,P,__VA_ARGS__))
#define _VAP15(M,P,X, ...)	EXPAND(M(P,X)_VAP14(M,P,__VA_ARGS__))
#define _VAP16(M,P,X, ...)	EXPAND(M(P,X)_VAP15(M,P,__VA_ARGS__))
#define _VAP17(M,P,X, ...)	EXPAND(M(P,X)_VAP16(M,P,__VA_ARGS__))
#define _VAP18(M,P,X, ...)	EXPAND(M(P,X)_VAP17(M,P,__VA_ARGS__))
#define _VAP19(M,P,X, ...)	EXPAND(M(P,X)_VAP18(M,P,__VA_ARGS__))
#define _VAP20(M,P,X, ...)	EXPAND(M(P,X)_VAP19(M,P,__VA_ARGS__))
#define _VAP21(M,P,X, ...)	EXPAND(M(P,X)_VAP20(M,P,__VA_ARGS__))
#define _VAP22(M,P,X, ...)	EXPAND(M(P,X)_VAP21(M,P,__VA_ARGS__))
#define _VAP23(M,P,X, ...)	EXPAND(M(P,X)_VAP22(M,P,__VA_ARGS__))
#define _VAP24(M,P,X, ...)	EXPAND(M(P,X)_VAP23(M,P,__VA_ARGS__))
#define _VAP25(M,P,X, ...)	EXPAND(M(P,X)_VAP24(M,P,__VA_ARGS__))
#define _VAP26(M,P,X, ...)	EXPAND(M(P,X)_VAP25(M,P,__VA_ARGS__))
#define _VAP27(M,P,X, ...)	EXPAND(M(P,X)_VAP26(M,P,__VA_ARGS__))
#define _VAP28(M,P,X, ...)	EXPAND(M(P,X)_VAP27(M,P,__VA_ARGS__))
#define _VAP29(M,P,X, ...)	EXPAND(M(P,X)_VAP28(M,P,__VA_ARGS__))
#define _VAP30(M,P,X, ...)	EXPAND(M(P,X)_VAP29(M,P,__VA_ARGS__))
#define _VAP31(M,P,X, ...)	EXPAND(M(P,X)_VAP30(M,P,__VA_ARGS__))
#define VA_APPLYP(M,P,...)	EXPAND(CONCAT3(_VAP, VA_NUM(__VA_ARGS__))(M,P,__VA_ARGS__))


#define likely(expr)		probably(true,expr)
#define unlikely(expr)		probably(false,expr)
#define iso_offset(S,M)		(size_t(&(((S*)1)->M)) - 1)
#define ISO_COMPILEASSERT(exp)	typedef iso::T_enable_if<!!(exp)> iso_compileassert_typedef##_LINE_

#ifndef __PLACEMENT_NEW_INLINE
inline_only void *operator new(size_t, void *p)		{ return p; }
inline_only void operator delete(void*, void*)		{}
#define __PLACEMENT_NEW_INLINE
#endif

#ifndef __PLACEMENT_VEC_NEW_INLINE
inline_only void *operator new[](size_t, void *p)	{ return p; }
inline_only void operator delete[](void*, void*)	{}
#define __PLACEMENT_VEC_NEW_INLINE
#endif

#ifdef	ISO_BIGENDIAN
#define iso_bigendian	true
#define ISO_BIT(n,b)	(1 << ((((n) - 1 - (b)) & ~7) + ((b) & 7)))
#define ISO_BITFIELDS2(a,b)									a,b
#define ISO_BITFIELDS3(a,b,c)								a,b,c
#define ISO_BITFIELDS4(a,b,c,d)								a,b,c,d
#define ISO_BITFIELDS5(a,b,c,d,e)							a,b,c,d,e
#define ISO_BITFIELDS6(a,b,c,d,e,f)							a,b,c,d,e,f
#define ISO_BITFIELDS7(a,b,c,d,e,f,g)						a,b,c,d,e,f,g
#define ISO_BITFIELDS8(a,b,c,d,e,f,g,h)						a,b,c,d,e,f,g,h
#define ISO_BITFIELDS9(a,b,c,d,e,f,g,h,i)					a,b,c,d,e,f,g,h,i
#define ISO_BITFIELDS10(a,b,c,d,e,f,g,h,i,j)				a,b,c,d,e,f,g,h,i,j
#define ISO_BITFIELDS11(a,b,c,d,e,f,g,h,i,j,k)				a,b,c,d,e,f,g,h,i,j,k
#define ISO_BITFIELDS12(a,b,c,d,e,f,g,h,i,j,k,l)			a,b,c,d,e,f,g,h,i,j,k,l
#define ISO_BITFIELDS13(a,b,c,d,e,f,g,h,i,j,k,l,m)			a,b,c,d,e,f,g,h,i,j,k,l,m
#define ISO_BITFIELDS14(a,b,c,d,e,f,g,h,i,j,k,l,m,n)		a,b,c,d,e,f,g,h,i,j,k,l,m,n
#define ISO_BITFIELDS15(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)		a,b,c,d,e,f,g,h,i,j,k,l,m,n,o
#define ISO_BITFIELDS16(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)	a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
#else
#define iso_bigendian	false
#define ISO_BIT(n,b)	(1 << (b))
#define ISO_BITFIELDS2(a,b)									b,a
#define ISO_BITFIELDS3(a,b,c)								c,b,a
#define ISO_BITFIELDS4(a,b,c,d)								d,c,b,a
#define ISO_BITFIELDS5(a,b,c,d,e)							e,d,c,b,a
#define ISO_BITFIELDS6(a,b,c,d,e,f)							f,e,d,c,b,a
#define ISO_BITFIELDS7(a,b,c,d,e,f,g)						g,f,e,d,c,b,a
#define ISO_BITFIELDS8(a,b,c,d,e,f,g,h)						h,g,f,e,d,c,b,a
#define ISO_BITFIELDS9(a,b,c,d,e,f,g,h,i)					i,h,g,f,e,d,c,b,a
#define ISO_BITFIELDS10(a,b,c,d,e,f,g,h,i,j)				j,i,h,g,f,e,d,c,b,a
#define ISO_BITFIELDS11(a,b,c,d,e,f,g,h,i,j,k)				k,j,i,h,g,f,e,d,c,b,a
#define ISO_BITFIELDS12(a,b,c,d,e,f,g,h,i,j,k,l)			l,k,j,i,h,g,f,e,d,c,b,a
#define ISO_BITFIELDS13(a,b,c,d,e,f,g,h,i,j,k,l,m)			m,l,k,j,i,h,g,f,e,d,c,b,a
#define ISO_BITFIELDS14(a,b,c,d,e,f,g,h,i,j,k,l,m,n)		n,m,l,k,j,i,h,g,f,e,d,c,b,a
#define ISO_BITFIELDS15(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o)		o,n,m,l,k,j,i,h,g,f,e,d,c,b,a
#define ISO_BITFIELDS16(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)	p,o,n,m,l,k,j,i,h,g,f,e,d,c,b,a
#endif

namespace iso {

//-----------------------------------------------------------------------------
//	basic types
//-----------------------------------------------------------------------------

#ifndef USE_64BITREGS
#define USE_64BITREGS	1
#endif
#ifndef USE_LONG
#define USE_LONG		1
#endif

typedef	signed char			int8;
typedef	signed short		int16;
typedef	int					int32;
typedef	__int64				int64;

typedef	unsigned char		uint8;
typedef	unsigned short		uint16;
typedef	unsigned int		uint32;
typedef	unsigned __int64	uint64;
typedef	unsigned long		ulong;

typedef float				float32;
typedef double				float64;

#ifndef DEFINED_UINT128
struct uint128 {uint8 a[16];};
#endif

struct _none {};
extern _none none, terminate, empty;

//-----------------------------------------------------------------------------
//	debug stuff
//-----------------------------------------------------------------------------

typedef void _iso_debug_print_t(const char*);
extern iso_export _iso_debug_print_t	*_iso_debug_print;
extern iso_export _iso_debug_print_t	*_iso_set_debug_print(_iso_debug_print_t *f);
iso_export	void _iso_debug_break();
iso_export	void _iso_dump_heap(uint32 flags);
iso_export	void _iso_assert(const char *filename, int line, const char *expr);
inline		void _iso_break_if(bool x)		{ if (x) _iso_debug_break(); }

template<typename T> inline_only T _iso_verify(T t, const char *filename, int line, const char *expr) {
	if (!t)
		_iso_assert(filename, line, expr);
	return t;
}

#ifdef DEBUG
	#define ISO_ON_DEBUG(x)			x
	#define ISO_ON_DEBUG_STMT(x)	x
#else
	#define ISO_ON_DEBUG(x)
	#define ISO_ON_DEBUG_STMT(x)	((void)0)
#endif

#if defined NDEBUG && !defined RELEASE
	#define RELEASE
#endif

#ifdef RELEASE
	#define ISO_NOT_RELEASE(x)
	#define ISO_NOT_RELEASE_STMT(x)	((void)0)
	#define ISO_VERIFY(exp)			(exp)
#else
	#define ISO_NOT_RELEASE(x)		x
	#define ISO_NOT_RELEASE_STMT(x)	x
	#define ISO_VERIFY(exp)			iso::_iso_verify(exp, __FILE__, __LINE__, #exp)
#endif

#define ISO_OUTPUT(x)					iso::_iso_debug_print(x)
#define ISO_RELEASECHECKHEAP(flags)		iso::_iso_dump_heap(flags)
#define ISO_RELEASECHEAPASSERT(exp)		iso::_iso_break_if(!(exp))
#define ISO_RELEASEASSERT2(exp, msg)	do { if (!(exp)) iso::_iso_assert(__FILE__, __LINE__, msg); } while(0)
#define ISO_RELEASEASSERT(exp)			ISO_RELEASEASSERT2(exp, #exp)

#define ISO_CHEAPASSERT(exp)	ISO_NOT_RELEASE_STMT(ISO_RELEASECHEAPASSERT(exp))
#define ISO_ASSERT(exp)			ISO_NOT_RELEASE_STMT(ISO_RELEASEASSERT(exp))
#define ISO_ASSERT2(exp, msg)	ISO_NOT_RELEASE_STMT(ISO_RELEASEASSERT2(exp, msg))
#define ISO_CHECKHEAP(flags)	ISO_NOT_RELEASE_STMT(iso::_iso_dump_heap(flags))
#define ISO_ASSUME(exp, x)		ISO_NOT_RELEASE_STMT({ if (!(exp)) iso::_iso_debug_print(x); })
#define ISO_TRACE(x)			ISO_NOT_RELEASE_STMT(iso::_iso_debug_print(x))

#define ISO_TRACE_BASE(s,e)		ISO_TRACE(#e ": 0x%08x\n", size_t(static_cast<e*>((s*)1)) - 1)
#define ISO_TRACE_ELEMENT(s,e)	ISO_TRACE(#e ": 0x%08x\n", size_t(&((s*)1)->e) - 1)

//-----------------------------------------------------------------------------
//	meta programming templates
//-----------------------------------------------------------------------------

#define ISO_METATYPE(x)		typename x::type
#define ISO_METAVALUE(x)	x::value
#define param(T)			iso::T_param<T>::type
#define paramT(T)			ISO_METATYPE(iso::T_param<T>)

template<typename T> struct T_noparentheses;
template<typename T> struct T_noparentheses<void(T)> { typedef T type; };
#define TNO_PARENTHESES(T)	typename T_noparentheses<void(T)>::type

#ifdef USE_RVALUE_REFS
#define CRREF(T)	T&&
#define RREF(T)		T&&
#else
#define CRREF(T)	const T&
#define RREF(T)		T&
#endif

template<template<class> class M, typename T>			struct T_map				{ typedef typename M<T>::type type; };
template<template<class> class M, typename T>			struct T_map<M, const T>	{ typedef const typename T_map<M, T>::type type; };
template<template<class> class M, typename T>			struct T_map<M, T*>			{ typedef typename M<typename T_map<M,T>::type*>::type		type; };
//template<template<class> class M, typename T, int N>	struct T_map<M, T[N]>		{ typedef typename M<typename T_map<M,T>::type[N]>::type	type; };
template<template<class> class M>						struct T_map<M, _none>		{ typedef _none type; };

template<typename T>						struct T_void					{ typedef void type; };

template<typename T>						struct T_deref;
template<typename T>						struct T_deref<T*>				{ typedef T type; };
template<typename T>						struct T_deref<T*&>				{ typedef T type; };
template<typename T>						struct T_deref<const T*>		{ typedef const T type; };
template<typename C, typename T>			struct T_deref<T C::*>			{ typedef T type; };
template<typename C, typename T>			struct T_deref<const T C::*>	{ typedef const T type; };

template<typename T, typename = void>		struct T_ref								{ typedef T type; };
template<typename T>						struct T_ref<T, typename T_void<T&>::type>	{ typedef T &type; };

template<typename T, typename = void>		struct T_rref								{ typedef T type; };
template<typename T>						struct T_rref<T, typename T_void<T&>::type>	{ typedef T &&type; };

template<typename T>						struct T_reftoptr				{ typedef T type; };
template<typename T>						struct T_reftoptr<T&>			{ typedef T *type; };

template<typename T>						struct T_noconst				{ typedef T type; };
template<typename T>						struct T_noconst<const T>		{ typedef T type; };

template<typename T>						struct T_noref					{ typedef T type; };
template<typename T>						struct T_noref<T&>				{ typedef T type; };
#ifdef USE_RVALUE_REFS
template<typename T>						struct T_noref<T&&>				{ typedef T type; };
#endif

template<typename T>						struct T_noarray				{ typedef T type; };
template<typename T, int N>					struct T_noarray<T[N]>			{ typedef T *type; };

template<typename A, typename B>			struct T_copyconst				{ typedef B type; };
template<typename A, typename B>			struct T_copyconst<const A, B>	{ typedef const B type; };
template<typename A, typename B>			struct T_copyconst<const A&, B>	{ typedef const B type; };

template<typename T>						struct T_param					{ typedef const T& type; };
template<typename T>						struct T_param<T&>				{ typedef T& type; };
template<typename T>						struct T_type {
	typedef T							type;
	typedef const T						ctype;
	typedef	ISO_METATYPE(T_noref<T>)	&ref;
	typedef ISO_METATYPE(T_noref<const T>)	&cref;
};
template<typename T>						struct T_type<const T> {
	typedef T							type, ctype;
	typedef	typename T_type<T>::cref	ref, cref;
};
template<>									struct T_type<void> {
	typedef void type, ctype, ref, base;
	typedef const int cref;
};

template<typename T, T N>					struct T_constant0				{ static const T value = N; operator T() const { return N; } };
template<typename T, T N>					struct T_constant				{ T t; constexpr T_constant() : t(N) {} operator T() const { return t; } };
template<int i>								struct T_num					: T_constant0<int,i>	{};

struct T_false	: T_constant0<bool, false>	{};
struct T_true	: T_constant0<bool, true>	{};
template<typename T>						struct T_true_type : T_true		{ typedef T type; };

template<typename T, T>						struct T_checktype;
template<bool b, typename T = void>			struct T_enable_if;
template<typename T>						struct T_enable_if<true, T>		{ typedef T type; };

template<typename A,typename B,typename R=A>struct T_same					: T_false {};
template<typename A, typename R>			struct T_same<A,A,R>			: T_true_type<R> {};
template<typename T, typename R=T>			struct T_exists					: T_true_type<R> {};
template<bool b, typename T, typename F>	struct T_if						{ typedef F type; };
template<typename T, typename F>			struct T_if<true, T, F>			{ typedef T type; };
template<bool b, int T, int F>				struct T_ifnum					: T_num<F>	{};
template<int T, int F>						struct T_ifnum<true, T, F>		: T_num<T>	{};
template<typename T>						struct T_is_lvalue				: T_false	{};
template<typename T>						struct T_is_lvalue<const T&>	: T_false	{};
template<typename T>						struct T_is_lvalue<T&>			: T_true	{};

template<typename> struct T_noclass;
template<typename S, typename C>			struct T_noclass<S (C::*)>		{ typedef S type; };

template<template<class> class C, typename T>				constexpr C<T>*					T_get_class(T *t)				{ return (C<T>*)0; }
template<template<class> class C, typename S, typename T>	constexpr C<T S::*>*			T_get_class(T S::*t)			{ return (C<T S::*>*)0; }
//template<template<class> class C, typename S, typename T>	constexpr C<T>*					T_get_class(T S::*t)			{ return (C<T S::*>*)0; }
template<template<class> class C, typename S, typename T>	constexpr C<T (S::*)()>*		T_get_class(T (S::*t)())		{ return (C<T (S::*)()>*)0; }
template<template<class> class C, typename S, typename T>	constexpr C<T (S::*)() const>*	T_get_class(T (S::*t)() const)	{ return (C<T (S::*)() const>*)0; }
template<template<class> class C, typename S, typename T, typename P1>	inline C<T (S::*)(P1) const>*	T_get_class(T (S::*t)(P1) const)	{ return (C<T (S::*)(P1) const>*)0; }

template<typename B, typename T>	inline uintptr_t	T_get_base_offset()				{ return uintptr_t(static_cast<B*>((T*)1)) - 1; }
template<typename B, typename T>	inline uintptr_t	T_get_base_offset(T *t)			{ return T_get_base_offset<B, T>(); }
template<typename S, typename T>	inline T*			T_get_member_type(T S::*t)		{ return (T*)0; }
template<typename S, typename T>	inline uintptr_t	T_get_member_offset(T S::*t)	{ return uintptr_t(&(((S*)0)->*t)); }
template<typename S, typename T>	inline S*			T_get_enclosing(T *p, T S::*t)	{ return (S*)((uint8*)p - T_get_member_offset(t)); }
#define ISO_GETMEMBERTYPE(p) typename T_deref<decltype(T_get_member_type(&p))>::type

template<int A, int B>	struct T_max : T_ifnum<(A > B), A, B> {};
template<int A, int B>	struct T_min : T_ifnum<(A < B), A, B> {};

struct yesno {
	typedef char yes;
	struct no { yes c[2]; };
	template<int N>			struct num	{ num(int); };
	template<typename T>	struct type { type(int); };
};

template<typename T> struct T_isclass : yesno {
	template<typename C>	static yes	test(int C::*);
	template<typename C>	static no	test(...);
	enum { value = sizeof(test<T>(0)) == sizeof(yes) };
};

template<typename T> struct is_abstract : yesno {
	// Deduction fails if T is void, function type, reference type or an abstract class type
	template<typename C>	static no	test(C(*)[1]);
	template<typename C>	static yes	test(...);
	enum { value = sizeof(test<T>(0)) == sizeof(yes) };
};

template<typename A, typename B> class T_conversion : yesno {
	static yes	test(B);
	static no	test(...);
	static A	a();
public:
	static void _()	{}
	enum {
		exists		= sizeof(test(a())) == sizeof(yes),
		exists2way	= exists && T_conversion<B, A>::exists,
		sametype	= false
	};
};

template<typename T> struct T_conversion<T, T>			{ enum { exists = true, exists2way = true, sametype = true };	};
template<typename A, typename B> struct T_inheritance	{ enum { exists = T_conversion<const A*, const B*>::exists };	};
template<typename B> struct T_inheritance<void, B>		{ enum { exists = false};										};

template<typename A, typename B> class T_constructable : yesno {
	template<typename U>	static yes	&test(U);
	template<typename>		static no	&test(...);
	static bool const value = sizeof(test<A>(*(B*)0)) == sizeof(yes);
};

#define T_HASMEMFUNC(F) template<typename T, typename S> struct has_##F : yesno {\
	template<typename U>	static yes	&test(T_checktype<S U::*, &U::F>*);		\
	template<typename>		static no	&test(...);								\
	static bool const value = sizeof(test<T>(0)) == sizeof(yes);				\
}

struct safe_bool {
	int	x;
	typedef int safe_bool::*type;
	static constexpr type	test(int i)			{ return i ? &safe_bool::x : 0; }
	template<typename T> static constexpr type	test(const T *p)	{ return p ? &safe_bool::x : 0; }
};

template<uint64 X, int N>	struct _LOG2	{ enum { test = (X >> N) > 0, value = test * N + _LOG2<(X >> (test * N)), N / 2>::value }; };
template<>				struct _LOG2<1, 0>	{ enum { value = 0 }; };
#define LOG2(X)			_LOG2<X, 32>::value

#ifdef USE_VARIADIC_TEMPLATES
//-----------------------------------------------------------------------------
//	variadic template helpers
//-----------------------------------------------------------------------------

template<typename... TT>						struct VT_count					{ enum { value = sizeof...(TT) }; };
template<size_t N, typename... TT>				struct VT_index;
template<size_t N, typename T0, typename... TT>	struct VT_index<N, T0, TT...>	{ typedef typename VT_index<N-1, TT...>::type type; };
template<typename T0, typename... TT>			struct VT_index<0, T0, TT...>	{ typedef T0 type; };

template<size_t...> struct index_list {};

template<size_t N, size_t... II>	struct make_index_list : make_index_list<N - 1, N - 1, II...> {};
template<size_t... II>				struct make_index_list<0, II...> : index_list<II...> { typedef index_list<II...> type; };
template<typename... TT>			struct T_make_index_list : make_index_list<sizeof...(TT)> {};

template<size_t N, size_t... II>	struct make_rev_index_list : make_rev_index_list<N - 1, II..., N> {};
template<size_t... II>				struct make_rev_index_list<0, II...> { typedef index_list<II...> type; };


template<typename T, T... VV>		struct value_list { enum {count = sizeof...(VV)}; typedef value_list type; };
template<size_t N, typename T, T...>			struct VV_index;
template<size_t N, typename T, T V, T... VV>	struct VV_index<N, T, V, VV...>	: VV_index<N - 1, T, VV...> {};
template<typename T, T V, T... VV>				struct VV_index<0, T, V, VV...>	: T_constant0<T, V> {};

template<size_t N, typename VL>					struct VL_index;
template<size_t N, typename T, T... VV>			struct VL_index<N, value_list<T, VV...> > : VV_index<N, T, VV...> {};

template<typename T, T... V0, T... V1> value_list<T, V0..., V1...> operator+(value_list<T, V0...>, value_list<T, V1...>) { return {}; }

template<typename T, typename S, size_t len, T... VV>	struct explode : explode<T, S, len - 1, S::array[len - 1], VV...> {};
template<typename T, typename S, T... VV>				struct explode<T, S, 0, VV...> : value_list<T, VV...> {};

template<template<typename...> class X, typename... TT> struct T_reverse;
template<template<typename...> class X> struct T_reverse<X> {
	template<typename... UU> using _type = X<UU...>;
};
template<template<typename...> class X, typename T, typename... TT> struct T_reverse<X, T, TT...> {
	template<typename... UU> using _type = typename T_reverse<X, TT...>::template _type<T, UU...>;
	using type = _type<>;
};

#if 0
template<typename T, template<typename T2, T2...> class X, T... II> struct V_reverse;
template<typename T, template<typename T2, T2...> class X> struct V_reverse<T, X> {
	template<T... UU> using _type = X<T, UU...>;
};
template<typename T, template<typename T2, T2...> class X, T I, T... II> struct V_reverse<T, X, I, II...> {
	template<T... UU> using _type = typename V_reverse<T, X, II...>::template _type<I, UU...>;
	using type = _type<>;
};
#endif

template<typename T, size_t N> struct constexpr_array {
	T t[N];
	constexpr size_t	size()					const	{ return N; }
	constexpr const T&	operator[](size_t i)	const	{ return t[i]; }
	constexpr T&		operator[](size_t i)			{ return t[i]; }
	constexpr const T*	begin()					const	{ return t; }
};

template<typename T> struct constexpr_array<T, 0> {
	const T* t = nullptr;
	constexpr size_t	size()					const	{ return 0; }
	constexpr const T*	begin()					const	{ return nullptr; }
};

template<typename T, typename T2, T2... v>				constexpr constexpr_array<T, sizeof...(v)>				make_constexpr_array(const value_list<T2, v...> &vals)	{ return {{T(v)...}}; }
template<typename T, T... v>							constexpr constexpr_array<T, sizeof...(v)>				make_constexpr_array(const value_list<T, v...> &vals)	{ return {{v...}}; }

template<typename T, typename T2, size_t N, size_t... I> constexpr constexpr_array<T, sizeof...(I)>				make_constexpr_array(const T2 (&p)[N], const index_list<I...>, size_t offset)	{ return {{T(p[I + offset])...}}; }
template<typename T, typename T2, size_t N, size_t... I> constexpr constexpr_array<T, sizeof...(I)>				make_constexpr_array(const T2 (&p)[N], const index_list<I...>)	{ return {{T(p[I])...}}; }
template<typename T, size_t N1, size_t N2, size_t... I1, size_t... I2> constexpr constexpr_array<T, N1 + N2>	concat(const constexpr_array<T,N1> &a1, const index_list<I1...>, const constexpr_array<T,N2> &a2, const index_list<I2...>) { return {{a1[I1]..., a2[I2]...}}; }

template<typename T, size_t N>							constexpr auto	make_constexpr_array(const T (&v)[N])		{ return make_constexpr_array<T>(v, make_index_list<N>()); }
template<typename T, typename T2, size_t N>				constexpr auto	make_constexpr_array(const T2 (&v)[N])		{ return make_constexpr_array<T>(v, make_index_list<N>()); }
template<typename T, size_t N, typename T2, size_t N2>	constexpr auto	make_constexpr_array(const T2 (&v)[N2])		{ return make_constexpr_array<T>(v, make_index_list<N>()); }

template<typename T, typename T2, size_t N> constexpr auto	make_constexpr_array(const constexpr_array<T2,N> &v)	{ return make_constexpr_array<T>(v.t, make_index_list<N>()); }

template<typename T, size_t N1>				constexpr auto	operator+(const constexpr_array<T, N1> &a1, const constexpr_array<T, 0>&)		{ return a1; }
template<typename T, size_t N1, size_t N2>	constexpr auto	operator+(const constexpr_array<T, N1> &a1, const constexpr_array<T, N2> &a2)	{ return concat(a1, make_index_list<N1>(),  a2, make_index_list<N2>()); }
template<typename T, size_t N>				constexpr auto	operator+(const constexpr_array<T, N> &a, T v)									{ return concat(a, make_index_list<N>(), constexpr_array<T, 1>{{v}}, make_index_list<1>()); }
template<typename T, size_t N1, size_t N2>	constexpr auto	operator+(const constexpr_array<T, N1> &a1, const T (&a2)[N2])					{ return a1 + make_constexpr_array<T, N2 - 1>(a2); }
template<typename T, size_t N1, size_t N2>	constexpr auto	operator+(const T (&a1)[N1], const constexpr_array<T, N2> &a2)					{ return make_constexpr_array<T, N1 - 1>(a1) + a2; }

template<size_t O, typename T, size_t N>	constexpr auto	trim_front(const constexpr_array<T,N> &v)						{ return make_constexpr_array<T>(v.t, make_index_list<N - O>(), O); }
template<size_t O, typename T, size_t N>	constexpr auto	trim_back(const constexpr_array<T,N> &v)						{ return make_constexpr_array<T>(v.t, make_index_list<N - O>(), 0); }
template<size_t N, typename T, size_t N2>	constexpr auto	slice(const constexpr_array<T,N2> &v, size_t offset)			{ return make_constexpr_array<T>(v.t, make_index_list<N>(), offset); }

#endif

//-----------------------------------------------------------------------------
//	casts
//-----------------------------------------------------------------------------

template<typename T> constexpr const T&			get(const T &t)			{ return t; }
template<typename B, typename A> constexpr B	force_cast(const A &a)	{ return reinterpret_cast<const B&>(a); }

#ifdef USE_RVALUE_REFS
template<typename T> typename T_rref<T>::type	declval() noexcept;
template<typename T> constexpr typename T_noref<T>::type&& move(T &&a)	{ return static_cast<typename T_noref<T>::type&&>(a); }
template<typename T, int N> constexpr T			(&move(T (&a)[N]))[N]	{ return a; }
template<typename T> constexpr T&&				forward(typename T_noref<T>::type& a) noexcept	{ return static_cast<T&&>(a); }
template<typename T> constexpr bool				is_constexpr(T &&t)		{ return noexcept(move(t)); }
template<typename T> constexpr T&&				get(T &&t)				{ return forward<T>(t); }
#else
template<typename T> constexpr T&				move(const T &t)		{ return const_cast<T&>(t); }
template<typename T> constexpr T&				get(T &t)				{ return t; }
#endif

template<typename T> struct T_underlying { typedef T type; };

template<typename T> struct T_alignment	{
	struct S { char c; T t; };
	enum { value = sizeof(S) - sizeof(T) };
};

template<typename T> struct T_log2alignment	{
	enum { value = LOG2(T_alignment<T>::value) };
};

template<typename T> inline void*	allocate() {
	return aligned_alloc(sizeof(T), T_alignment<T>::value);
}

//-----------------------------------------------------------------------------
//	constructable
//-----------------------------------------------------------------------------

template<typename T> struct constructable : T {
	typedef typename T_underlying<T>::type T0;
	constructable() {}
	constructable(const T0 &x)										{ T::operator=(x); }
	template<typename T2> constructable&	operator=(const T2 &x)	{ T::operator=(x); return *this; }
	friend const T&		get(const constructable &t)			{ return t; }
	friend T&			get(constructable &t)				{ return t; }
};
template<typename T> struct T_underlying<constructable<T> > : T_underlying<T> {};

//-----------------------------------------------------------------------------
//	data layout
//-----------------------------------------------------------------------------

template<int N> struct _aligner {
	inline void*				operator new(size_t size)			{ return aligned_alloc(size, N);	}
	inline void					operator delete(void *p)			{ aligned_free(p);					}
	inline void*				operator new[](size_t size)			{ return aligned_alloc(size, N);	}
	inline void					operator delete[](void *p)			{ aligned_free(p);					}
	template<typename T> void*	operator new(size_t size, T *p)		{ return p; }
	template<typename T> void*	operator new[](size_t size, T *p)	{ return p; }
	template<typename T> void*	operator new(size_t size, T &t)		{ return t.alloc(size, N); }
	template<typename T> void*	operator new[](size_t size, T &t)	{ return t.alloc(size, N); }
};

template<int N> struct aligner	: _aligner<N> {};

#if defined __GNUC__ || defined __MWERKS__
template<> struct aligner<16>	: _aligner<16> {} __attribute__((__aligned__(16)));
template<> struct aligner<128>	: _aligner<128> {} __attribute__((__aligned__(128)));
#else
template<> struct __declspec(align(16))		aligner<16>		: _aligner<16> {};
template<> struct __declspec(align(128))	aligner<128>	: _aligner<128> {};
#endif

template<typename T, int N> struct aligned : public T, public aligner<N> {
	template<typename T2> T	&operator=(const T2 &t)	{ return *(T*)this = t; }
};

//-----------------------------------------------------------------------------
//	number traits
//-----------------------------------------------------------------------------

template<typename T> class T_swap_endian;
template<typename T> struct T_swap_endian_type						{ typedef T_swap_endian<T> type; };
template<typename T> struct T_swap_endian_type<T_swap_endian<T> >	{ typedef T type; };

template<typename T> struct vec_traits { enum {dims = 1, simd = false}; };
template<typename T> struct vec_traits<const T>					: vec_traits<T> {};
template<typename T, int N> struct vec_traits<aligned<T,N> >	: vec_traits<T> {};
template<typename T> struct vec_traits<constructable<T> >		: vec_traits<T> {};

template<typename T> struct num_traits {
	enum {bits = sizeof(T) * 8};
	static const bool	is_signed	= T(~T(0)) < 0;
	static const bool	is_float	= false;
	static constexpr T	min()						{ return is_signed ? T(-(T(1) << (sizeof(T) * 8 - 1))) : T(0); }
	static constexpr T	max()						{ return T(~min());	}
	template<typename T2> static constexpr T cast(const T2 &t) {
		return ISO_CHEAPASSERT(
			(!num_traits<T2>::is_signed || (is_signed ? t >= min() : t >= 0))		//min check
		&&	(!num_traits<T2>::is_signed && is_signed ? T(t) >= 0 : t <= max())		//max check
		), T(t);
	}
	static constexpr T	cast(float t)				{ return ISO_CHEAPASSERT(t >= min() && t <= max()), T(t + 0.5f); }
};

template<> struct num_traits<float> {
	enum {bits = 32, exponent_bits = 8, mantissa_bits = 23};
	static const bool		is_signed	= true;
	static const bool		is_float	= true;
	static constexpr float	min()					{ return -max(); }
	static constexpr float	max()					{ return force_cast<float>(0x7f7fffffu); }
	template<typename T2> static constexpr float cast(const T2 &t)					{ return float(t); }
	template<typename T2> static constexpr float cast(const T_swap_endian<T2> &t)	{ return float(T2(t)); }
};

template<> struct num_traits<double> {
	enum {bits = 64, exponent_bits = 11, mantissa_bits = 52};
	static const bool		is_signed	= true;
	static const bool		is_float	= true;
	static constexpr double	min()					{ return -max(); }
	static constexpr double	max()					{ return force_cast<double>(0x7fefffffffffffffull); }
	template<typename T2> static constexpr double cast(const T2 &t)	{ return double(t); }
};

template<typename T> struct num_traits<constructable<T> > : num_traits<T> {
	template<typename T2> static constexpr constructable<T> cast(const T2 &t)	{ return constructable<T>(t); }
};

template<typename S, typename T = typename S::base> struct inherited_num_traits : num_traits<T> {
	template<typename T2> static constexpr S	cast(T2 t)	{ return num_traits<T>::cast(t); }
};

struct _m_maximum {
	template<typename T> constexpr operator T() const { return -num_traits<T>::max(); }
};
struct _maximum {
	template<typename T> constexpr operator T() const { return num_traits<T>::max(); }
	inline _m_maximum	operator-() const		{ return _m_maximum(); }
};
struct _minimum {
	template<typename T> constexpr operator T() const { return num_traits<T>::min(); }
};

extern _maximum maximum;
extern _minimum minimum;

//-----------------------------------------------------------------------------
//	packed
//-----------------------------------------------------------------------------

#if (defined PLAT_WII && !defined __GNUC__) || defined PLAT_PS3

template<typename T> class _packed {
	uint8	t[sizeof(T)];
	T&		get(T &a)	const						{ memcpy(&a, t, sizeof(T)); return a; }
protected:
	T		get()		const						{ T a; get(a); return a; }
	void	set(const T &a)							{ memcpy(t, &a, sizeof(T)); }
public:
	operator T()		const						{ return get(); }
	void operator=(const T &_t)						{ set(_t); }
	const T operator->() const						{ return get(); }
	T operator++()									{ T a; set(++get(a)); return a; }
	T operator--()									{ T a; set(--get(a)); return a; }
	T operator++(int)								{ T a, b = get(a); set(++b); return a; }
	T operator--(int)								{ T a, b = get(a); set(--b); return a; }
	T operator+=(const T &_t)						{ T a; get(a); set(a += _t); return a; }
	T operator-=(const T &_t)						{ T a; get(a); set(a -= _t); return a; }
	T operator*=(const T &_t)						{ T a; get(a); set(a *= _t); return a; }
	T operator/=(const T &_t)						{ T a; get(a); set(a /= _t); return a; }
	friend T	get(const _packed &a)				{ return a; }
};

#elif defined __GNUC__
// THIS WASN'T WORKING FOR packed floats so we are using the WII version.

template<typename T> class _packed {
	T		t;
protected:
	T		get()	const							{ return t; }
	template<typename X> void set(const X &x)		{ t = x; }
public:
	operator T()	const							{ return get(); }
	template<typename X> void operator=(const X &x)	{ set(x); }
	T& operator->()									{ return t; }
	T operator++()									{ return ++t; }
	T operator++(int)								{ return t++; }
	T operator--()									{ return --t; }
	T operator--(int)								{ return t--; }
	T operator+=(const T &_t)						{ return t += _t; }
	T operator-=(const T &_t)						{ return t -= _t; }
	T operator*=(const T &_t)						{ return t *= _t; }
	T operator/=(const T &_t)						{ return t /= _t; }
	friend T	get(const _packed &a)				{ return a; }
} __attribute__((packed));

#else

template<typename T> class _packed {
	uint8		t[sizeof(T)];
protected:
	T		get()	const								{ return *(iso_unaligned(T*))t; }
	template<typename X> void set(const X &x)			{ *(iso_unaligned(T*))t = x; }
public:
	operator T()	const								{ return get(); }
	template<typename X> void operator=(const X &x)		{ set(x); }
	iso_unaligned(T&) operator->()						{ return *(iso_unaligned(T*))t;			}
	T operator++()										{ return ++*(iso_unaligned(T*))t;		}
	T operator++(int)									{ return (*(iso_unaligned(T*))t)++;		}
	T operator--()										{ return --*(iso_unaligned(T*))t;		}
	T operator--(int)									{ return (*(iso_unaligned(T*))t)--;		}
	template<typename T2> T operator+=(const T2 &_t)	{ return *(iso_unaligned(T*))t += _t;	}
	template<typename T2> T operator-=(const T2 &_t)	{ return *(iso_unaligned(T*))t -= _t;	}
	template<typename T2> T operator*=(const T2 &_t)	{ return *(iso_unaligned(T*))t *= _t;	}
	template<typename T2> T operator/=(const T2 &_t)	{ return *(iso_unaligned(T*))t /= _t;	}
	friend T get(const _packed &a)	{ return a; }
};

#endif

template<typename T> struct T_underlying<_packed<T> > : T_underlying<T> {};

template<typename T> struct packed : _packed<T> {
	packed()					{}
	packed(const T &_t)			{ this->set(_t); }
	void operator=(const T &_t)	{ this->set(_t); }
};

template<typename T> struct packed<constructable<T> > : _packed<T> {
	packed()					{}
	packed(const T &_t)			{ this->set(_t); }
	void operator=(const T &_t)	{ this->set(_t); }
};

template<typename T> struct T_underlying<packed<T> >	: T_underlying<T> {};
template<typename T> struct num_traits<packed<T> >		: num_traits<T> {};
template<typename T> struct vec_traits<packed<T> >		: vec_traits<T> {};

}//namespace iso

#endif // DEFS_BASE_H
