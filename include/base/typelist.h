#ifndef TYPELIST_H
#define TYPELIST_H

#include "defs.h"

namespace iso {

//-----------------------------------------------------------------------------
//	typelist
//-----------------------------------------------------------------------------

#ifdef USE_VARIADIC_TEMPLATES
template<typename... TT> struct typelist {
	enum { align = 1 };
};

template<typename T0, typename... TT> struct typelist<T0, TT...> {
	typedef T0				head;
	typedef typelist<TT...>	tail;
	template<typename T> struct cat { typedef typelist<T0, TT..., T> type; };
};

template<typename T>		struct TL_count;
template<typename... TT>	struct TL_count<typelist<TT...> >		{ enum { value = sizeof...(TT) }; };

template<typename T> struct TL_alignment {
	enum { value = T_max<T_alignment<typename T::head>::value, TL_alignment<typename T::tail>::value>::value };
};
template<> struct TL_alignment<typelist<> > {
	enum { value = 1 };
};
#else

template <
	typename T0  = _none, typename T1  = _none, typename T2  = _none, typename T3  = _none,
	typename T4  = _none, typename T5  = _none, typename T6  = _none, typename T7  = _none,
	typename T8  = _none, typename T9  = _none, typename T10 = _none, typename T11 = _none,
	typename T12 = _none, typename T13 = _none, typename T14 = _none, typename T15 = _none,
	typename T16 = _none, typename T17 = _none, typename T18 = _none, typename T19 = _none,
	typename T20 = _none, typename T21 = _none, typename T22 = _none, typename T23 = _none,
	typename T24 = _none, typename T25 = _none, typename T26 = _none, typename T27 = _none,
	typename T28 = _none, typename T29 = _none, typename T30 = _none, typename T31 = _none
> struct typelist {
	typedef T0		head;
	typedef typelist <
		T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15,
		T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31
	>				tail;
	template<typename T> struct cat { typedef typelist<
		T, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15,
		T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30
	> type; };
};

template<typename T>		struct TL_count							{ enum { value = 1 + TL_count<typename T::tail>::value }; };
template<>					struct TL_count<typelist<> >			{ enum { value = 0 }; };

#endif

template<typename T, int N>	struct TL_index							{ typedef typename TL_index<typename T::tail, N - 1>::type	type; };
template<typename T>		struct TL_index<T, 0>					{ typedef typename T::head									type; };

//-----------------------------------------------------------------------------
//	tuple helpers
//-----------------------------------------------------------------------------

template<typename T, int N = -1, int O = 0> struct tuple_offset	: tuple_offset<typename T::tail, N - 1, sizeof(offset_type<typename T::head, O>)> {};
template<typename T, int N> struct tuple_offset<T, N, 0>		: tuple_offset<typename T::tail, N - 1, sizeof(typename T::head)> {};

template<typename T, int O>	struct tuple_offset<T, 0, O>			{ enum {size = O }; typedef typename T::head type;};
template<typename T>		struct tuple_offset<T, 0, 0>			{ enum {size = 0 }; typedef typename T::head type;};

template<int N, int O>		struct tuple_offset<typelist<>, N, O>	{ enum {size = O }; typedef _none type;};
template<int O>				struct tuple_offset<typelist<>, 0, O>	{ enum {size = O }; typedef _none type;};
template<>					struct tuple_offset<typelist<>, 0, 0>	{ enum {size = 0 }; typedef _none type;};

//-----------------------------------------------------------------------------
//	tuple
//-----------------------------------------------------------------------------

#ifdef USE_VARIADIC_TEMPLATES

template<typename T, int O> struct offset_typelist;

template<typename T> struct tuple;

template<typename T, int O> struct tuple<offset_typelist<T, O> > {
	typedef typename TL_index<T,O>::type	head_t;
	typedef tuple<typename T_if<(O + 1 == TL_count<T>::value), typelist<>, offset_typelist<T, O + 1> >::type>	tail_t;
	typedef	offset_type<head_t, tuple_offset<T, O>::size>	head_offset_t;
	enum	{ alignment = TL_alignment<T>::value };

	union {
//		char		data[(tuple_offset<T>::size + alignment - 1) / alignment * alignment];
		char		data[tuple_offset<T>::size];
		typename _uint_type<alignment>::type	_aligner;
	};
	template<int N>	typename TL_index<T, N+O>::type			&get()			{ typedef tuple_offset<T, N+O> R; return *((offset_type<typename R::type, R::size>*)data); }
	template<int N>	const typename TL_index<T, N+O>::type	&get() const	{ typedef tuple_offset<T, N+O> R; return *((offset_type<typename R::type, R::size>*)data); }

	head_t&			head()			{ return get<0>(); }
	tail_t&			tail()			{ return reinterpret_cast<tail_t&>(data); }
	const head_t&	head()	const	{ return get<0>(); }
	const tail_t&	tail()	const	{ return reinterpret_cast<const tail_t&>(data); }

	template<typename P0, typename... PP> void set(const P0 &p0, const PP&... pp) {
		head() = p0;
		tail().set(pp...);
	}
	template<typename T2> void set(const tuple<T2> &p) {
		head() = p.head();
		tail().set(p.tail());
	}
	tuple()	{}
	template<typename... PP>	tuple(const PP&... pp)	{ set(pp...); }
	template<typename T2> tuple(const tuple<T2> &t2)	{ set(t2); }
	template<typename T2> tuple& operator=(const T2 &p) { set(p); return *this; }
};

template<typename T> struct tuple : tuple<offset_typelist<T,0> > {
	typedef tuple<offset_typelist<T,0> > B;
	tuple()	{}
	template<typename... PP>	tuple(const PP&... pp)	: B(pp...)	{}
	template<typename T2> tuple(const tuple<T2> &t2)	: B(t2)		{}
	template<typename T2> tuple& operator=(const T2 &p) { B::operator=(p); return *this; }
};

template<> struct tuple<typelist<> > { void set(...) {} };

template<typename... TT> tuple<typelist<TT...> > make_tuple(const TT&... tt) {
	return tuple<typelist<TT...> >(tt...);
}

template<template<class> class M, typename... TT> struct T_map<M, typelist<TT...> >  {
	typedef typelist<typename T_map<M, TT>::type...> type;
};

//template<typename T, int O>	struct offset_type<tuple<T>, O> : spacer<align(O, TL_alignment<T>::value)> {
//	typedef tuple<T> type;
//	type		t;
//};

#else

template<typename T> struct tuple {
	char	data[tuple_offset<T>::size];
	template<int N>	typename TL_index<T, N>::type	&get()				{ typedef tuple_offset<T, N> R; return *((offset_type<typename R::type, R::size>*)data); }
	template<int N>	const typename TL_index<T, N>::type	&get() const	{ typedef tuple_offset<T, N> R; return *((offset_type<typename R::type, R::size>*)data); }

	void set(
		const typename TL_index<T, 0>::type &t00 = _none(),	const typename TL_index<T, 1>::type &t01 = _none(),
		const typename TL_index<T, 2>::type &t02 = _none(),	const typename TL_index<T, 3>::type &t03 = _none(),
		const typename TL_index<T, 4>::type &t04 = _none(),	const typename TL_index<T, 5>::type &t05 = _none(),
		const typename TL_index<T, 6>::type &t06 = _none(),	const typename TL_index<T, 7>::type &t07 = _none(),
		const typename TL_index<T, 8>::type &t08 = _none(),	const typename TL_index<T, 9>::type &t09 = _none(),
		const typename TL_index<T,10>::type &t10 = _none(),	const typename TL_index<T,11>::type &t11 = _none(),
		const typename TL_index<T,12>::type &t12 = _none(),	const typename TL_index<T,13>::type &t13 = _none(),
		const typename TL_index<T,14>::type &t14 = _none(),	const typename TL_index<T,15>::type &t15 = _none(),
		const typename TL_index<T,16>::type &t16 = _none(),	const typename TL_index<T,17>::type &t17 = _none(),
		const typename TL_index<T,18>::type &t18 = _none(),	const typename TL_index<T,19>::type &t19 = _none(),
		const typename TL_index<T,20>::type &t20 = _none(),	const typename TL_index<T,21>::type &t21 = _none(),
		const typename TL_index<T,22>::type &t22 = _none(),	const typename TL_index<T,23>::type &t23 = _none(),
		const typename TL_index<T,24>::type &t24 = _none(),	const typename TL_index<T,25>::type &t25 = _none(),
		const typename TL_index<T,26>::type &t26 = _none(),	const typename TL_index<T,27>::type &t27 = _none(),
		const typename TL_index<T,28>::type &t28 = _none(),	const typename TL_index<T,29>::type &t29 = _none(),
		const typename TL_index<T,30>::type &t30 = _none(),	const typename TL_index<T,31>::type &t31 = _none()
	) {
		(typename T::head&)data = t00;
		((tuple<typename T::tail>*)(data + tuple_offset<T, 1, 0>::size))->set(
			t01, t02, t03, t04, t05, t06, t07,
			t08, t09, t10, t11, t12, t13, t14, t15,
			t16, t17, t18, t19, t20, t21, t22, t23,
			t24, t25, t26, t27, t28, t29, t30, t31
		);
	}
	tuple()	{}
	tuple(
		const typename TL_index<T, 0>::type &t00,			const typename TL_index<T, 1>::type &t01 = _none(),
		const typename TL_index<T, 2>::type &t02 = _none(),	const typename TL_index<T, 3>::type &t03 = _none(),
		const typename TL_index<T, 4>::type &t04 = _none(),	const typename TL_index<T, 5>::type &t05 = _none(),
		const typename TL_index<T, 6>::type &t06 = _none(),	const typename TL_index<T, 7>::type &t07 = _none(),
		const typename TL_index<T, 8>::type &t08 = _none(),	const typename TL_index<T, 9>::type &t09 = _none(),
		const typename TL_index<T,10>::type &t10 = _none(),	const typename TL_index<T,11>::type &t11 = _none(),
		const typename TL_index<T,12>::type &t12 = _none(),	const typename TL_index<T,13>::type &t13 = _none(),
		const typename TL_index<T,14>::type &t14 = _none(),	const typename TL_index<T,15>::type &t15 = _none(),
		const typename TL_index<T,16>::type &t16 = _none(),	const typename TL_index<T,17>::type &t17 = _none(),
		const typename TL_index<T,18>::type &t18 = _none(),	const typename TL_index<T,19>::type &t19 = _none(),
		const typename TL_index<T,20>::type &t20 = _none(),	const typename TL_index<T,21>::type &t21 = _none(),
		const typename TL_index<T,22>::type &t22 = _none(),	const typename TL_index<T,23>::type &t23 = _none(),
		const typename TL_index<T,24>::type &t24 = _none(),	const typename TL_index<T,25>::type &t25 = _none(),
		const typename TL_index<T,26>::type &t26 = _none(),	const typename TL_index<T,27>::type &t27 = _none(),
		const typename TL_index<T,28>::type &t28 = _none(),	const typename TL_index<T,29>::type &t29 = _none(),
		const typename TL_index<T,30>::type &t30 = _none(),	const typename TL_index<T,31>::type &t31 = _none()
	) {
		set(
			t00, t01, t02, t03, t04, t05, t06, t07,
			t08, t09, t10, t11, t12, t13, t14, t15,
			t16, t17, t18, t19, t20, t21, t22, t23,
			t24, t25, t26, t27, t28, t29, t30, t31
		);
	}
};

template<> struct tuple<typelist<> > {
	void set(
		const _none &t00 = _none(), const _none &t01 = _none(), const _none &t02 = _none(), const _none &t03 = _none(),
		const _none &t04 = _none(), const _none &t05 = _none(), const _none &t06 = _none(), const _none &t07 = _none(),
		const _none &t08 = _none(), const _none &t09 = _none(), const _none &t10 = _none(), const _none &t11 = _none(),
		const _none &t12 = _none(), const _none &t13 = _none(), const _none &t14 = _none(), const _none &t15 = _none(),
		const _none &t16 = _none(), const _none &t17 = _none(), const _none &t18 = _none(), const _none &t19 = _none(),
		const _none &t20 = _none(), const _none &t21 = _none(), const _none &t22 = _none(), const _none &t23 = _none(),
		const _none &t24 = _none(), const _none &t25 = _none(), const _none &t26 = _none(), const _none &t27 = _none(),
		const _none &t28 = _none(), const _none &t29 = _none(), const _none &t30 = _none(), const _none &t31 = _none()
	) {}
};

template <
	typename T0  = _none, typename T1  = _none, typename T2  = _none, typename T3  = _none,
	typename T4  = _none, typename T5  = _none, typename T6  = _none, typename T7  = _none,
	typename T8  = _none, typename T9  = _none, typename T10 = _none, typename T11 = _none,
	typename T12 = _none, typename T13 = _none, typename T14 = _none, typename T15 = _none,
	typename T16 = _none, typename T17 = _none, typename T18 = _none, typename T19 = _none,
	typename T20 = _none, typename T21 = _none, typename T22 = _none, typename T23 = _none,
	typename T24 = _none, typename T25 = _none, typename T26 = _none, typename T27 = _none,
	typename T28 = _none, typename T29 = _none, typename T30 = _none, typename T31 = _none
> tuple<typelist<
	T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15,
	T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31
> > make_tuple(
	const T0  &t00,				const T1  &t01 = _none(),
	const T2  &t02 = _none(),	const T3  &t03 = _none(),
	const T4  &t04 = _none(),	const T5  &t05 = _none(),
	const T6  &t06 = _none(),	const T7  &t07 = _none(),
	const T8  &t08 = _none(),	const T9  &t09 = _none(),
	const T10 &t10 = _none(),	const T11 &t11 = _none(),
	const T12 &t12 = _none(),	const T13 &t13 = _none(),
	const T14 &t14 = _none(),	const T15 &t15 = _none(),
	const T16 &t16 = _none(),	const T17 &t17 = _none(),
	const T18 &t18 = _none(),	const T19 &t19 = _none(),
	const T20 &t20 = _none(),	const T21 &t21 = _none(),
	const T22 &t22 = _none(),	const T23 &t23 = _none(),
	const T24 &t24 = _none(),	const T25 &t25 = _none(),
	const T26 &t26 = _none(),	const T27 &t27 = _none(),
	const T28 &t28 = _none(),	const T29 &t29 = _none(),
	const T30 &t30 = _none(),	const T31 &t31 = _none()
) {
	return tuple<typelist<
		T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15,
		T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31
	> >(
		t00, t01, t02, t03, t04, t05, t06, t07,
		t08, t09, t10, t11, t12, t13, t14, t15,
		t16, t17, t18, t19, t20, t21, t22, t23,
		t24, t25, t26, t27, t28, t29, t30, t31
	);
}

template<template<class> class M,
	typename T0 , typename T1 , typename T2 , typename T3 ,
	typename T4 , typename T5 , typename T6 , typename T7 ,
	typename T8 , typename T9 , typename T10, typename T11,
	typename T12, typename T13, typename T14, typename T15,
	typename T16, typename T17, typename T18, typename T19,
	typename T20, typename T21, typename T22, typename T23,
	typename T24, typename T25, typename T26, typename T27,
	typename T28, typename T29, typename T30, typename T31
> struct T_map<M, typelist<
	T0,		T1,		T2,		T3,		T4,		T5,		T6,		T7,
	T8,		T9,		T10,	T11,	T12,	T13,	T14,	T15,
	T16,	T17,	T18,	T19,	T20,	T21,	T22,	T23,
	T24,	T25,	T26,	T27,	T28,	T29,	T30,	T31
> > {
	typedef typelist<
		typename T_map<M, T0>::type,	typename T_map<M, T1>::type,	typename T_map<M, T2>::type,	typename T_map<M, T3>::type,
		typename T_map<M, T4>::type,	typename T_map<M, T5>::type,	typename T_map<M, T6>::type,	typename T_map<M, T7>::type,
		typename T_map<M, T8>::type,	typename T_map<M, T9>::type,	typename T_map<M, T10>::type,	typename T_map<M, T11>::type,
		typename T_map<M, T12>::type,	typename T_map<M, T13>::type,	typename T_map<M, T14>::type,	typename T_map<M, T15>::type,
		typename T_map<M, T16>::type,	typename T_map<M, T17>::type,	typename T_map<M, T18>::type,	typename T_map<M, T19>::type,
		typename T_map<M, T20>::type,	typename T_map<M, T21>::type,	typename T_map<M, T22>::type,	typename T_map<M, T23>::type,
		typename T_map<M, T24>::type,	typename T_map<M, T25>::type,	typename T_map<M, T26>::type,	typename T_map<M, T27>::type,
		typename T_map<M, T28>::type,	typename T_map<M, T29>::type,	typename T_map<M, T30>::type,	typename T_map<M, T31>::type
	> type;
};

#endif

template<typename T> struct T_alignment<tuple<T> > { enum { value = TL_alignment<T>::value }; };

template<template<class> class M, typename TL> struct T_map<M, tuple<TL> > {
	typedef tuple<typename T_map<M, TL>::type> type;
};

//-----------------------------------------------------------------------------
//	as_tuple
//-----------------------------------------------------------------------------

template<typename T>		struct TL_fields;
template<typename T>		struct TL_fields<const T> : TL_fields<T> {};

template<typename T, typename TL = typename TL_fields<T>::type> struct as_tuple : tuple<TL> {};

template<typename T> struct as_tuple<T, typename TL_fields<T>::type> : tuple<typename TL_fields<T>::type> {
	operator T&()				{ return *(T*)this; }
	operator const T&() const	{ return *(T*)this; }
};

template<typename T, typename TL> struct T_alignment<as_tuple<T, TL> > : T_alignment<tuple<TL> > {};

template<template<class> class M, typename T, typename TL> struct T_map<M, as_tuple<T, TL> > {
	typedef as_tuple<T, typename T_map<M, TL>::type> type;
};

//-----------------------------------------------------------------------------
//	vallist (tuple without the packing stuff)
//-----------------------------------------------------------------------------

#ifdef USE_VARIADIC_TEMPLATES

template<int N, typename VL>	struct vallist_get;

template<typename... TT> struct vallist {
	typedef typelist<TT...>				TL;
	typedef typename TL::head			head_t;
	typedef vallist<typename TL::tail>	tail_t;
	typedef T_make_index_list<TT...>	indices;

	head_t	head;
	tail_t	tail;

	template<typename P0, typename... PP> void set(P0 &&p0, PP&&... pp) {
		head = p0;
		tail.set(forward<PP>(pp)...);
	}
	template<typename... TT2> void set(const vallist<TT2...> &p) {
		head = p.head;
		tail = p.tail;
	}

	template<int N>	typename VT_index<N, TT...>::type		&get()				{ return vallist_get<N, TT...>(*this); }
	template<int N>	const typename VT_index<N, TT...>::type	&get()		const	{ return vallist_get<N, TT...>(*this); }

	vallist()	{}
	template<typename... PP>	vallist(PP&&... pp)			{ set(forward<PP>(pp)...); }
	template<typename T2> vallist(const vallist<T2> &t2)	{ set(t2); }
	template<typename T2> vallist& operator=(const T2 &p)	{ set(p); return *this; }
};

template<> struct vallist<> {
	typedef index_list<>		indices;
	void set(...) {}
};

template<typename... TT> struct vallist<typelist<TT...> > : vallist<TT...> {
	vallist()	{}
	template<typename... PP>	vallist(PP&&... pp)			{ this->set(forward<PP>(pp)...); }
	template<typename T2> vallist(const vallist<T2> &t2)	{ this->set(t2); }
	template<typename T2> vallist& operator=(const T2 &p)	{ this->set(p); return *this; }
};

template<typename... TT> vallist<TT...> make_vallist(TT&&... tt) {
	return vallist<TT...>(forward<TT>(tt)...);
}

template<int N, typename VL>	struct vallist_get {
	typedef typename TL_index<typename VL::TL, N>::type	type;
	static type			&f(VL &v)		{ return v.tail.template get<N-1>(); }
	static const type	&f(const VL &v)	{ return v.tail.template get<N-1>(); }
};


template<typename VL> struct vallist_get<0, VL> {
	typedef typename VL::head	type;
	static type			&f(VL &v)		{ return v.head; }
	static const type	&f(const VL &v)	{ return v.head; }
};

template<int N, typename... TT>	typename VT_index<N, TT...>::type &index(vallist<TT...> &v) {
	return v.template get<N>();
}
template<int N, typename... TT>	const typename VT_index<N, TT...>::type &index(const vallist<TT...> &v) {
	return v.template get<N>();
}
#endif

}//namespace iso

#endif // TYPELIST_H
