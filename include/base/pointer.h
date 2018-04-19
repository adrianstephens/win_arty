#ifndef POINTER_H
#define POINTER_H

#include "defs.h"
#undef check

namespace iso {

template<class T> class pointer {
	T			*t;
public:
	typedef T			element, *iterator;
	typedef	const T*	const_iterator;
	typedef typename T_type<T>::ref		reference;

	pointer()				: t(0)		{}
	pointer(T *_t)			: t(_t)		{}
	pointer&	operator=(T *t2)		{ t = t2; return *this; }
	T*			get()			const	{ return t; }
	T*			begin()			const	{ return t; }
	T*			operator->()	const	{ return t;	}
	operator	T*()			const	{ return t;	}
	friend T*	get(const pointer &a)	{ return a; }
};

template<typename T, typename O, typename P=void, bool nulls=true> struct offset_pointer {
	O		offset;
	T		*get(const P *base) const	{ return offset ? (T*)((char*)base + offset) : 0; }
	void	set(T *t, const P *base)	{ offset = t ? (char*)t - (char*)base : 0; }
};

template<typename T, typename O, typename P> struct offset_pointer<T,O,P,false> {
	O		offset;
	T		*get(const P *base) const	{ return (T*)((char*)base + offset); }
	void	set(T *t, const P *base)	{ offset = (char*)t - (char*)base; }
};

template<typename T, typename O, typename P=void, bool nulls=true> struct offset_iterator {
	typedef random_access_iterator_t iterator_category;
	typedef const T	element, *pointer, &reference;
	const P									*base;
	const offset_pointer<T, O, P, nulls>	*p;
	offset_iterator(const void *_base, const offset_pointer<T, O, P, nulls> *_p) : base(_base), p(_p) {}
	offset_iterator&	operator++()						{ ++p; return *this; }
	offset_iterator&	operator+=(size_t n)				{ p += n; return *this; }
	offset_iterator&	operator-=(size_t n)				{ p -= n; return *this; }
	bool	operator==(const offset_iterator &b)	const	{ return p == b.p; }
	bool	operator!=(const offset_iterator &b)	const	{ return p != b.p; }
	T&		operator*()								const	{ return *p->get(base); }
	T*		operator->()							const	{ return p->get(base); }
	T&		operator[](int i)						const	{ return *p[i].get(base); }
	friend int operator-(const offset_iterator &a, const offset_iterator &b) {
		return a.p - b.p;
	}
	friend offset_iterator operator+(const offset_iterator &a, size_t n) {
		return offset_iterator(a.base, a.p + n);
	}
};
template<typename T, typename O, typename P, bool nulls> offset_iterator<T,O,P,nulls> make_offset_iterator(const P *base, const offset_pointer<T,O,P,nulls> *p) {
	return offset_iterator<T,O,P,nulls>(base, p);
}

template<typename T, typename O, typename P=void, bool nulls=true> struct offset_iterator_ptr : offset_iterator<T,O,P,nulls> {
	typedef offset_iterator<T,O,P,nulls>	B;
	typedef const T	*element, **pointer, *reference;
	offset_iterator_ptr(const void *_base, const offset_pointer<T,O,P,nulls> *_p) : B(_base, _p) {}
	offset_iterator_ptr& operator++()						{ ++B::p; return *this; }
	T*		operator*()								const	{ return B::p->get(B::base); }
	T*		operator[](int i)						const	{ return B::p[i].get(B::base); }
	friend offset_iterator_ptr operator+(const offset_iterator_ptr &a, size_t n) {
		return offset_iterator_ptr(a.base, a.p + n);
	}
};
template<typename T, typename O, typename P=void, bool nulls> offset_iterator_ptr<T,O,P,nulls> make_offset_iterator_ptr(const void *base, const offset_pointer<T,O,P,nulls> *p) {
	return offset_iterator_ptr<T,O,P,nulls>(base, p);
}

template<typename T, typename O, typename P, bool nulls> inline_only range<offset_iterator<T,O,P,nulls> > make_range_n(const void *base, const offset_pointer<T,O,P,nulls> *p, size_t n) {
	return make_range_n(offset_iterator<T,O,P,nulls>(base, p), n);
}
template<typename T, typename O, typename P, bool nulls, int N> inline_only range<offset_iterator<T,O,P,nulls> > make_range(const void *base, const offset_pointer<T,O,P,nulls> (&a)[N]) {
	return make_range_n(offset_iterator<T,O,P,nulls>(base, a), N);
}
//-----------------------------------------------------------------------------
//	bases for soft_pointer
//-----------------------------------------------------------------------------

struct base_direct {
	void			*ptr;

	static constexpr bool	check(const void *p)	{ return true; }

	constexpr base_direct()	: ptr(0)						{}
	constexpr base_direct(const void *p) : ptr((void*)p)	{}
	void			set(const void *p)	{ ptr = (void*)p; }
	constexpr void*	get()		const	{ return ptr; }
	constexpr bool	operator!()	const	{ return !ptr; }
};

template<typename T> struct base_absolute {
	T				offset;

	static constexpr bool	check(const void *p)		{ return T(p) == intptr_t(p); }
	static constexpr T		assert_check(const void *p)	{ return ISO_CHEAPASSERT(check(p)), T(p); }
	static constexpr T		calc_check(const void *p)	{ return assert_check(p); }

	constexpr base_absolute()				: offset(0)				{}
	constexpr base_absolute(const void *p)	: offset(calc_check(p)) {}
	void			set(const void *p)	{ offset = calc_check(p); }
	constexpr void*	get()		const	{ return offset ? (void*)intptr_t(offset) : 0; }
	constexpr bool	operator!()	const	{ return !offset; }
};

template<typename T> struct base_relative {
	T				offset;

	static constexpr bool	_check(intptr_t t)			{ return T(t) == t; }
	static constexpr T		assert_check(intptr_t t)	{ return ISO_CHEAPASSERT(_check(t)), T(t); }
	constexpr intptr_t		calc(const void *p)	 const	{ return p ? (char*)p - (char*)this : 0; }
	constexpr bool			check(const void *p) const	{ return _check(calc(p)); }
	constexpr T				calc_check(const void *p) const { return assert_check(calc(p)); }

	constexpr base_relative()				: offset(0)						{}
	base_relative(const base_relative &b)	: offset(calc_check(b.get()))	{}
	base_relative(const void *p)			: offset(calc_check(p))			{}
	void	operator=(const base_relative &b)	{ set(b.get()); }
	void	set(const void *p)					{ offset = calc_check(p); }
	void*	get()				const			{ return offset ? (char*)this + offset : 0; }
	bool	operator!()			const			{ return !offset; }
};

template<typename T> struct base_fixed {
	static void		*base;
	static void		*get_base();
	int32			offset;

	static constexpr bool	_check(intptr_t t)			{ return int32(t) == t; }
	static constexpr int32	assert_check(intptr_t t)	{ return (void)(ISO_CHEAPASSERT(_check(t))), int32(t); }
	static intptr_t			calc(const void *p)			{ return p ? (char*)p - (char*)get_base() : 0; }
	static bool				check(const void *p)		{ return _check(calc(p)); }
	static int32			calc_check(const void *p)	{ return assert_check(calc(p)); }

	constexpr base_fixed()		: offset(0)				{}
	base_fixed(const void *p)	: offset(calc_check(p))	{}
	void	set(const void *p)			{ offset = calc_check(p); }
	void*	get()				const	{ return offset ? (char*)get_base() + offset : 0; }
	bool	operator!()			const	{ return !offset; }
};
//template<typename T> void *base_fixed<T>::get_base() {
//	static void *base;
//	return base;
//}

template<typename T, int S> struct base_fixed_shift {
	int32			offset;

	static constexpr bool	_check(const void *p, intptr_t v)		{ return (intptr_t(p) & ((1<<S)-1)) == 0 && int32(v) == v; }
	static constexpr int32	assert_check(const void *p, intptr_t v)	{ return (void)(ISO_CHEAPASSERT(_check(p, v))), int32(v); }
	static intptr_t			calc(const void *p)						{ return p ? ((char*)p - (char*)base_fixed<T>::get_base()) >> S : 0; }
	static bool				check(const void *p)					{ return _check(p, calc(p)); }
	static int32			calc_check(const void *p)				{ return assert_check(p, calc(p)); }

	constexpr base_fixed_shift()	: offset(0)				{}
	base_fixed_shift(const void *p)	: offset(calc_check(p))	{}
	void	set(const void *p)			{ offset = calc_check(p); }
	void*	get()				const	{ return offset ? (char*)base_fixed<T>::get_base() + (intptr_t(offset) << S) : 0; }
	bool	operator!()			const	{ return !offset; }
};

template<typename T, int B> struct base_select {
	int32			offset;

	static void		*base[(1<<B) + 1];
	static void		**get_base();
	base_select()	: offset(0)			{}
	base_select(const void *p)			{ set(p); }
	void	set(const void *p);
	void*	get()				const	{ return offset ? (char*)get_base()[offset & ((1 << B) - 1)] + (offset & -(1 << B)) : 0; }
	bool	operator!()			const	{ return !offset; }
};
//template<typename T, int B> void **base_select<T,B>::get_base() {
//	static void *base[1 << B];
//	return base;
//}
template<typename T, int B> void base_select<T,B>::set(const void *p) {
	if (!p) {
		offset = 0;
		return;
	}
	void	**base = get_base();
	for (int i = 0; i < 1<<B; i++) {
		intptr_t v = (char*)p - (char*)base[i];
		if (int32(v) == v) {
			offset = int32(v) | i;
			return;
		}
	}
	ISO_CHEAPASSERT(0);
}


template<typename T, typename B> class soft_pointer : B {
public:
	typedef T			element, *iterator;
	typedef	const T*	const_iterator;
	typedef typename T_type<T>::ref		reference;

	constexpr soft_pointer()				{}
	soft_pointer(T *t)						{ B::set(t); }
	soft_pointer& operator=(T *t)			{ B::set(t); return *this; }
	T*			get()				const	{ return (T*)B::get(); }
	T*			begin()				const	{ return get(); }
	T*			operator->()		const	{ return get(); }
	operator	T*()				const	{ return get(); }
	bool		operator!()			const	{ return B::operator!(); }
//	template<typename T2> operator T2*() const	{ return static_cast<T2*>(get()); }
	friend T*	get(const soft_pointer &a)	{ return a; }
};

template<typename T> struct rel_pointer : soft_pointer<T, base_relative<int32> > {
	rel_pointer()						{}
	rel_pointer(T *_t) : soft_pointer<T, base_relative<int32> >(_t) {}
	rel_pointer&	operator=(T *_t)	{ soft_pointer<T, base_relative<int32> >::operator=(_t); return *this; }
};

template<typename T, bool R=(sizeof(void*)<=sizeof(int32))> struct pointer32 : pointer<T> {
	pointer32()							{}
	pointer32(T *_t) : pointer<T>(_t)	{}
	pointer32&	operator=(T *_t)		{ pointer<T>::operator=(_t); return *this; }
};

template<typename T> struct pointer32<T, false> : soft_pointer<T, base_fixed_shift<void,2> > {
	pointer32()							{}
	pointer32(T *_t) : soft_pointer<T, base_fixed_shift<void,2> >(_t) {}
	pointer32&	operator=(T *_t)		{ soft_pointer<T, base_fixed_shift<void,2> >::operator=(_t); return *this; }
};

template<typename T>			inline size_t	to_string(char *s, const pointer<T> &t)			{ return to_string(s, (const T*)t);}
template<typename T, typename B>inline size_t	to_string(char *s, const soft_pointer<T, B> &t)	{ return to_string(s, (const T*)t);}

}//namespace iso

#endif // POINTER_H
