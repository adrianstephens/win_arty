#ifndef ITERATOR_H
#define ITERATOR_H

namespace iso {

struct not_iterator_t			{};
struct input_iterator_t			{};
struct output_iterator_t		{};
struct forward_iterator_t		: public input_iterator_t			{};
struct bidirectional_iterator_t : public forward_iterator_t			{};
struct random_access_iterator_t : public bidirectional_iterator_t	{};

//-----------------------------------------------------------------------------
// helper for operator->
//-----------------------------------------------------------------------------

template<typename T> struct ref_helper : T {
	template<typename P1> ref_helper(const P1 &_p1) : T(_p1)	{}
	template<typename P1,typename P2> ref_helper(const P1 &_p1, const P2 &_p2) : T(_p1, _p2)	{}
	T*		operator->()	{ return this;	}
};

//-----------------------------------------------------------------------------
//	traits
//-----------------------------------------------------------------------------

template<typename T, typename V = void> struct T_iterator_category { 
    typedef not_iterator_t type; 
};
template<typename T> struct T_iterator_category<T, typename T_void<typename T::iterator_category>::type> {
    typedef typename T::iterator_category type; 
};

template<typename I> struct iterator_traits {
	typedef typename T_iterator_category<I>::type iterator_category;
	typedef typename I::element		element;
	typedef typename I::reference	reference;
};

template<typename T> struct iterator_traits<T*> {
	typedef random_access_iterator_t iterator_category;
	typedef T			element;
	typedef T&			reference;
};

template<typename T> struct iterator_traits<const T> {
	typedef typename iterator_traits<T>::iterator_category iterator_category;
	typedef const typename iterator_traits<T>::element		element;
	typedef	const typename iterator_traits<T>::reference	reference;
};
template<typename T> struct iterator_traits<T&> : iterator_traits<T> {};

template<typename C> struct container_traits {
	typedef typename C::element			element;
	typedef	typename C::reference		reference;
	typedef	typename C::iterator		iterator;
	typedef	typename C::const_iterator	const_iterator;
};

template<typename C> struct container_traits<const C> {
	typedef const typename container_traits<C>::element		element;
	typedef	const typename container_traits<C>::reference	reference;
	typedef	typename container_traits<C>::const_iterator	iterator;
	typedef	typename container_traits<C>::const_iterator	const_iterator;
};
template<typename T> struct container_traits<T&> : container_traits<T> {};

template<typename T> struct container_traits<T*> {
	typedef T			element;
	typedef	T&			reference;
	typedef	T*			iterator;
	typedef	const T*	const_iterator;
};
template<typename T> struct container_traits<T[]>					: container_traits<T*> {};
template<typename T, int N> struct container_traits<T[N]>			: container_traits<T*> {};
template<typename T, int N> struct container_traits<T(&)[N]>		: container_traits<T*> {};
template<typename T, int N> struct container_traits<const T[N]>		: container_traits<const T*> {};
template<typename T> struct container_traits<constructable<T> >		: container_traits<T> {};

#define element_of(T) typename iso::container_traits<T>::element

//template<typename C> constexpr typename container_traits<C>::iterator begin(C &c)				{ return container_traits<C>::iterator::begin(c); }
//template<typename C> constexpr typename container_traits<C>::const_iterator begin(const C &c)	{ return container_traits<C>::const_iterator::begin(c); }
//template<typename C> constexpr typename container_traits<C>::iterator end(C &c)					{ return container_traits<C>::iterator::end(c); }
//template<typename C> constexpr typename container_traits<C>::const_iterator end(const C &c)		{ return container_traits<C>::const_iterator::end(c); }

template<typename C> constexpr typename C::iterator			begin(C &c)			{ return c.begin();		}
template<typename C> constexpr typename C::const_iterator	begin(const C &c)	{ return c.begin();		}
template<typename C> constexpr typename C::iterator			end(C &c)			{ return c.end();		}
template<typename C> constexpr typename C::const_iterator	end(const C &c)		{ return c.end();		}

//template<typename C> constexpr auto begin(C &c)			{ return c.begin();	}
//template<typename C> constexpr auto end(C &c)			{ return c.end();		}

template<typename C, typename T_enable_if<!T_same<typename T_underlying<C>::type, C>::value>::type *dummy = 0> constexpr auto begin(C &c)	{ return begin(get(c));	}
template<typename C, typename T_enable_if<!T_same<typename T_underlying<C>::type, C>::value>::type *dummy = 0> constexpr auto end(C &c)		{ return end(get(c));	}

template<typename T>		constexpr T* begin(T *p)	{ return p;		}
template<typename T, int N>	constexpr T* end(T (&p)[N])	{ return p + N; }

template<class C> constexpr bool is_empty(const C &c)	{ return begin(c) == end(c); }

template<typename I> size_t _distance(I first, I last, input_iterator_t) {
	size_t n = 0;
	while (first != last) {
		++first;
		++n;
	}
	return n;
}
template<typename I> constexpr size_t _distance(I first, I last, random_access_iterator_t) {
	return last - first;
}
template<typename I> constexpr size_t distance(I first, I last) {
	return _distance(first, last, typename iterator_traits<I>::iterator_category());
}
template<typename I> constexpr uint32 distance32(I first, I last) {
	return uint32(distance(first, last));
}

template<typename I> I nth(I first, int i, input_iterator_t) {
	while (i-- > 0)
		++first;
	return first;
}
template<typename I> constexpr I nth(I first, int i, random_access_iterator_t) {
	return first + i;
}
template<typename I> constexpr I nth(I first, int i) {
	return nth(first, i, typename iterator_traits<I>::iterator_category());
}

template<typename C> constexpr inline size_t num_elements(const C &c) {
	return distance(begin(c), end(c));
}

template<typename C> constexpr inline size_t num_elements(C &c) {
	return distance(begin(c), end(c));
}

template<typename C> inline size_t index_of(const C &c, const typename container_traits<C>::const_iterator &i) {
	return distance(begin(c), i);
}

//-----------------------------------------------------------------------------
//	range
//-----------------------------------------------------------------------------

template<typename I> class range {
protected:
	I	a, b;
public:
	typedef	typename iterator_traits<I>::iterator_category	iterator_category;
	typedef	typename iterator_traits<I>::element	element;
	typedef	typename iterator_traits<I>::reference	reference;
	typedef	I	iterator, const_iterator;

	constexpr range()									: a(), b()			{}
	constexpr range(const _none&)						: a(), b()			{}
	constexpr range(const I &_a, const I &_b)			: a(_a), b(_b)		{}
//	constexpr range(const I &p, size_t n)				: a(p), b(p + n)	{}
	template<int N> constexpr range(element (&_a)[N])	: a(_a), b(a + N)	{}
#ifdef USE_RVALUE_REFS
	constexpr range(I &&_a, I &&_b)						: a(move(_a)), b(move(_b))	{}
//	constexpr range(I &&p, size_t n)					: a(move(p)), b(p + n)		{}
#endif

	constexpr reference	operator[](int i)			const	{ return *nth(a, i);	}
	bool				empty()						const	{ return a >= b; }
	constexpr I			begin()						const	{ return a; }
	constexpr I			end()						const	{ return b; }
	constexpr size_t	size()						const	{ return distance(a, b); }
	constexpr uint32	size32()					const	{ return distance32(a, b); }

	reference			back()						const	{ return b[-1]; }
	void				pop_back()							{ --b; }
	reference			pop_back_value()					{ return *--b; }
	reference			front()						const	{ return *a; }
	void				pop_front()							{ ++a; }
	reference			pop_front_value()					{ return *a++; }

	constexpr range		operator&(const range &r)	const	{ return range(max(a, r.a), min(b, r.b)); }
	constexpr bool		overlaps(const range &r)	const	{ return !(r.a > b) && !(r.b < a); }
	constexpr bool		contains(const range &r)	const	{ return !(r.a < a) && !(r.b > b); }
	friend bool			operator<(const range &a, const range &b) { return a.a < b.a || (!(b.a < a.a) && a.b < b.b); }

	range	sub_range(int aoff, int boff = 0) {
		return range<I>((aoff < 0 ? b : a) + aoff, (boff <= 0 ? b : a) + boff);
	}

	template<typename W> friend bool write(W &w, const range &r)	{ return writen(w, r.a, r.size()); }

};

template<typename I>		inline_only range<I>	make_range(const I &a, const I &b)	{ return range<I>(a, b); }
template<typename I>		inline_only range<I>	make_range_n(const I &a, size_t n)	{ return range<I>(a, a + n); }
template<typename T, int N> inline_only range<T*>	make_range(T (&a)[N])				{ return range<T*>(&a[0], &a[N]);	}
template<typename T>		inline_only range<T*>	make_range_n(T (&a)[], size_t n)	{ return range<T*>(&a[0], &a[n]);	}
#ifdef USE_RVALUE_REFS
template<typename I>		inline_only range<typename T_noref<I>::type>	make_range(I &&a, I &&b)		{ return range<typename T_noref<I>::type>(move(a), move(b)); }
template<typename I>		inline_only range<typename T_noref<I>::type>	make_range_n(I &&a, size_t n)	{ return range<typename T_noref<I>::type>(move(a), a + n); }
#endif

template<typename C> range<typename container_traits<C>::iterator> inline_only make_rangec(C &c) {
	return make_range(c.begin(), c.end());
}
template<typename C> range<typename container_traits<C>::iterator> inline_only sub_range(C &c, int a, int b = 0) {
	return make_rangec(c).sub_range(a, b);
}

//-----------------------------------------------------------------------------
//	move_iterator
//-----------------------------------------------------------------------------

template<class T> class move_iterator {
	T	i;
public:
	using iterator_category = typename iterator_traits<T>::iterator_category;
	using element			= typename iterator_traits<T>::element;
	using difference_type	= int;//typename iterator_traits<T>::difference_type;
	using reference			= typename T_noref<typename iterator_traits<T>::reference>::type&&;

	constexpr move_iterator() : i() {}
	constexpr move_iterator(T b) : i(b) {}
	template<class T2> constexpr move_iterator(const move_iterator<T2> &b) : i(b.i) {}
	template<class T2> constexpr move_iterator& operator=(const move_iterator<T2> &b) { i = b.i; return *this; }

	constexpr reference operator*()		const	{ return move(*i); }
	constexpr T			operator->()	const	{ return i; }
	constexpr move_iterator&	operator++()	{ ++i; return *this; }
	constexpr move_iterator		operator++(int) { move_iterator t = *this; ++i; return t; }
	constexpr move_iterator&	operator--()	{ --i; return *this; }
	constexpr move_iterator		operator--(int) { move_iterator t = *this; --i; return t; }

	// random-access iterators only
	constexpr move_iterator&	operator+=(difference_type x)			{ i += x; return *this; }
	constexpr move_iterator		operator+(difference_type x)	const	{ return i + x; }
	constexpr move_iterator&	operator-=(difference_type x)			{ i -= x; return *this; }
	constexpr move_iterator		operator-(difference_type x)	const	{ return i - x; }
	constexpr reference			operator[](difference_type x)	const	{ return move(i[x]); }
};

template<typename T> move_iterator<T> make_move_iterator(T i)				{ return i; }
//template<typename T, int N>	constexpr move_iterator<T*> begin(T (&&p)[N])	{ return p;		}
//template<typename T, int N>	constexpr move_iterator<T*> end(T (&&p)[N])		{ return p + N; }

//-----------------------------------------------------------------------------
//	reverse_iterator
//-----------------------------------------------------------------------------

template<typename I> struct reverse_iterator {
	typedef typename iterator_traits<I>::iterator_category	iterator_category;
	typedef typename iterator_traits<I>::reference			reference;
	typedef typename iterator_traits<I>::element			element;
	I		i;
	reverse_iterator()				{}
	reverse_iterator(I _i)	: i(_i)	{}
	reference			operator*()	 				const	{ return *i;			}
	element*			operator->() 				const	{ return i;				}
	reverse_iterator&	operator++()						{ --i; return *this;	}
	reverse_iterator	operator++(int)						{ return i--;			}
	reverse_iterator&	operator--()						{ ++i; return *this;	}
	reverse_iterator	operator--(int)						{ return i++;			}
	reverse_iterator&	operator+=(int j)					{ i -= j; return *this; }
	reverse_iterator&	operator-=(int j)					{ i += j; return *this; }

	reference			operator[](int j)					{ return *(i - j); }
	const reference		operator[](int j)			const	{ return *(i - j); }

	bool	operator==(const reverse_iterator &b)	const	{ return i == b.i;	}
	bool	operator!=(const reverse_iterator &b)	const	{ return i != b.i;	}
	bool	operator< (const reverse_iterator &b)	const	{ return i >  b.i; }
	bool	operator<=(const reverse_iterator &b)	const	{ return i >= b.i; }
	bool	operator> (const reverse_iterator &b)	const	{ return i <  b.i; }
	bool	operator>=(const reverse_iterator &b)	const	{ return i <= b.i; }

	friend int	operator-(const reverse_iterator &a, const reverse_iterator &b)	{ return b.i - a.i; }
	friend reverse_iterator	operator+(const reverse_iterator &a, int j)			{ return a.i - j;	}
	friend reverse_iterator	operator-(const reverse_iterator &a, int j)			{ return a.i + j;	}
};

template<class C> struct reversed {
	C	&c;
	typedef typename container_traits<C>::iterator			I;
	typedef typename container_traits<C>::const_iterator	CI;
	typedef element_of(C)				element;
	typedef reverse_iterator<I>			iterator;
	typedef reverse_iterator<CI>		const_iterator;
	reversed(C &_c) : c(_c) {}

	const element&			front()	const	{ return c.back();		}
	const element&			back()	const	{ return c.front();		}
	element&				front()			{ return c.back();		}
	element&				back()			{ return c.front();		}

	const_iterator			begin()	const	{ CI i = c.end(); return --i; }
	const_iterator			end()	const	{ CI i = c.begin(); return --i; }
	iterator				begin()			{ I i = c.end(); return --i; }
	iterator				end()			{ I i = c.begin(); return --i; }

	element&		operator[](int i)			{ return *(c.end() - 1 - i); }
	const element&	operator[](int i)	const	{ return *(c.end() - 1 - i); }
};

template<class C>	inline_only reversed<C>	make_reversed(C &c)	{ return c;	}

//-----------------------------------------------------------------------------
//	int_iterator - just an int (or whatever)
//-----------------------------------------------------------------------------

template<typename I> class int_iterator {
	I		i;
public:
	typedef I							element, reference;
	typedef random_access_iterator_t	iterator_category;

	int_iterator(I _i)	: i(_i)	{}
	I				operator*()					const	{ return i; 	}
	int_iterator&	operator++()						{ i = I(i + 1); return *this; }
	int_iterator	operator++(int)						{ I j = i; i = I(i + 1); return j; }
	int_iterator&	operator--()						{ i = I(i - 1); return *this; }
	int_iterator	operator--(int)						{ I j = i; i = I(i - 1); return j; }
	int_iterator&	operator+=(int j)					{ i = I(i + j); return *this; }
	int_iterator&	operator-=(int j)					{ i = I(i - j); return *this; }
	int_iterator	operator+(int j)			const	{ return I(i + j);	}
	int_iterator	operator-(int j)			const	{ return I(i - j);	}
	I				operator[](int j)			const	{ return I(i + j);	}

	int		operator-(const int_iterator &b)	const	{ return i - b.i;	}
	bool	operator==(const int_iterator &b)	const	{ return i == b.i;	}
	bool	operator!=(const int_iterator &b)	const	{ return i != b.i;	}
	bool	operator< (const int_iterator &b)	const	{ return i <  b.i; }
	bool	operator<=(const int_iterator &b)	const	{ return i <= b.i; }
	bool	operator> (const int_iterator &b)	const	{ return i >  b.i; }
	bool	operator>=(const int_iterator &b)	const	{ return i >= b.i; }
};

template<typename I> inline_only int_iterator<I> make_int_iterator(I i) {
	return int_iterator<I>(i);
}

template<typename T> inline_only range<int_iterator<T> > int_range(T a, T b) {
	return range<int_iterator<T> >(a, b);
}

template<typename T> inline_only range<int_iterator<T> > int_range(T b) {
	return range<int_iterator<T> >(T(0), b);
}


//-----------------------------------------------------------------------------
//	indexed_iterator - uses index
//-----------------------------------------------------------------------------

template<typename C, typename X> class indexed_element {
	typedef typename iterator_traits<C>::reference	reference;
	typedef typename iterator_traits<C>::element	element;
	C		&c;
	X		x;
public:
	indexed_element(C &_c, X _x) : c(_c), x(_x)	{}
	operator	reference()							const	{ return c[x];	}
	reference	operator*()							const	{ return c[x];	}
	element*	operator->()						const	{ return &c[x];	}
	X			index()								const	{ return x; }

	indexed_element&	operator=(const element &b)			{ c[x] = b; return *this; }
	indexed_element&	operator=(const indexed_element &b)	{ x = b.x; return *this; }

	element		operator-()							const	{ return -c[x]; }
	element		operator+()							const	{ return c[x]; }
	bool		operator==(const element &b)		const	{ return c[x] == b; }
	bool		operator!=(const element &b)		const	{ return c[x] != b; }
	bool		operator< (const element &b)		const	{ return c[x] <  b; }
	bool		operator<=(const element &b)		const	{ return c[x] <= b; }
	bool		operator>=(const element &b)		const	{ return c[x] >= b; }
	bool		operator> (const element &b)		const	{ return c[x] >  b; }

	friend void swap(indexed_element a, indexed_element b)	{ swap(a.x, b.x); }
	friend reference	get(const indexed_element &a)		{ return a; }
	friend reference	get(indexed_element &a)				{ return a; }
};

template<typename C, typename X> struct indexed_helper {
	typedef	typename iterator_traits<C>::reference	reference;
//	static reference deindex(C &c, X x)			{ return c[x]; }
	static reference deindex(const C &c, X x)	{ return c[x]; }
};
template<typename C, typename X> struct indexed_helper<C, X&> {
	typedef	indexed_element<const C, X&>			reference;
	static reference deindex(const C &c, X &x)	{ return reference(c, x); }
};
template<typename C, typename X> struct indexed_helper<C, const X&> : indexed_helper<C, X> {};

template<typename C, typename I> class indexed_iterator {
	C		c;
	I		i;
	typedef typename iterator_traits<I>::reference	index;
	typedef indexed_helper<C, index>				helper;
public:
	typedef typename iterator_traits<C>::element	element;
	typedef typename helper::reference				reference;

	indexed_iterator(const C &_c, const I &_i) : c(_c), i(_i)	{}
	indexed_iterator& operator=(const indexed_iterator &b)		{ i = b.i; return *this; }
	element*			operator->()				const	{ return &c[*i];	}
	reference			operator*()					const	{ return helper::deindex(c, *i); }
	reference			operator[](int j)			const	{ return helper::deindex(c, i[j]); }

	indexed_iterator&	operator+=(int j)					{ i += j; return *this; }
	indexed_iterator&	operator-=(int j)					{ i -= j; return *this; }
	indexed_iterator&	operator++()						{ ++i; return *this;	}
	indexed_iterator&	operator--()						{ --i; return *this;	}
	indexed_iterator	operator++(int)						{ indexed_iterator t(*this); ++i; return t; }
	indexed_iterator	operator--(int)						{ indexed_iterator t(*this); --i; return t; }
	indexed_iterator	operator+(int j)			const	{ return indexed_iterator(c, i + j); }
	indexed_iterator	operator-(int j)			const	{ return indexed_iterator(c, i - j); }

	bool	operator==(const indexed_iterator &b)	const	{ return i == b.i;	}
	bool	operator!=(const indexed_iterator &b)	const	{ return i != b.i;	}
	bool	operator< (const indexed_iterator &b)	const	{ return i <  b.i; }
	bool	operator<=(const indexed_iterator &b)	const	{ return i <= b.i; }
	bool	operator> (const indexed_iterator &b)	const	{ return i >  b.i; }
	bool	operator>=(const indexed_iterator &b)	const	{ return i >= b.i; }

	friend intptr_t	operator-(const indexed_iterator &a, const indexed_iterator &b) {
		return a.i - b.i;
	}
};

template<typename C, typename I> inline_only indexed_iterator<C,I> make_indexed_iterator(const C &c, const I &i) {
	return indexed_iterator<C,I>(c, i);
}
template<typename C, typename I> struct iterator_traits<indexed_iterator<C,I> > : iterator_traits<C> {
	typedef random_access_iterator_t	iterator_category;
};

template<typename C, typename CI> class indexed_container {
	typedef typename container_traits<CI>::iterator	I;
	C		c;
	CI		i;
public:
	typedef	indexed_iterator<C,I>			iterator;
//	typedef	typename iterator_traits<C>::element	element;
//	typedef	typename iterator_traits<C>::reference	reference;
	typedef typename iterator::element		element;
	typedef typename iterator::reference	reference;

	indexed_container(const C &_c, const CI &_i) : c(_c), i(_i)	{}
	reference		operator[](int j)			{ return c[i[j]];	}
	element			operator[](int j)	const	{ return c[i[j]];	}
	iterator		begin()				const	{ return iterator(c, iso::begin(i)); }
	iterator		end()				const	{ return iterator(c, iso::end(i)); }
	int				size()				const	{ return i.size();	}
};

template<typename C, typename CI> inline_only indexed_container<C,CI> make_indexed_container(C &&c, CI &&i) {
	return indexed_container<C,CI>(c, i);
}

template<typename C> inline_only indexed_container<C, range<int_iterator<int>>> make_indexed_container(C &&c) {
	return make_indexed_container(forward<C>(c), make_range_n(make_int_iterator(0), num_elements(c)));
}

//-----------------------------------------------------------------------------
//	next_iterator - iterate over something with a next() function
//-----------------------------------------------------------------------------

template<typename T> struct next_iterator {
	typedef forward_iterator_t iterator_category;
	typedef T	element, &reference;
	T	mutable	*p;
	int			i;
	mutable int	pi;
	T *getp()		const									{ while (pi < i) {p = next(p); ++pi; } return p; }

	next_iterator(T *_p) : p(_p), i(0), pi(0)	{}
	next_iterator(T *_p, int _i) : p(_p), i(_i), pi(_i) {}
	next_iterator(T *_p, int _i, int _pi) : p(_p), i(_i), pi(_pi) {}
	next_iterator&		operator++()						{ ++i; return *this; }
	next_iterator		operator+(size_t n) const			{ return next_iterator(p, int(i + n), pi); }
	bool		operator==(const next_iterator &b)	const	{ return i == b.i || (b.i <  0 && getp() == b.p); }
	bool		operator!=(const next_iterator &b)	const	{ return i != b.i && (b.i >= 0 || getp() != b.p); }
	T&			operator*()			const					{ return *getp(); }
	T*			operator->()		const					{ return getp(); }
	T&			operator[](int i)	const					{ return *(*this + i); }
};

template<typename T> inline_only T * next(T *p) { return p->next(); }

template<typename T> inline_only next_iterator<T> make_next_iterator(T *p, int i = 0) {
	return next_iterator<T>(p, i);
}

template<typename T> inline_only range<next_iterator<T> > make_range_n(const next_iterator<T> &a, size_t n) {
	return range<next_iterator<T> >(a, next_iterator<T>(a.p, n, 0));
}


//-----------------------------------------------------------------------------
//	stride_iterator
//-----------------------------------------------------------------------------

template<typename T> class stride_iterator {
	template<typename T2> friend class stride_iterator;
	T		*p;
	int		s;
public:
	typedef T							element;
	typedef random_access_iterator_t	iterator_category;
	typedef typename T_type<T>::ref		reference;

	stride_iterator()									{}
	stride_iterator(T *_p, int _s) : p(_p), s(_s)		{}
	stride_iterator(const stride_iterator<void> &i) : p((T*)i.p), s(i.s) {}
	template<typename T2> explicit stride_iterator(const stride_iterator<T2> &i) : p((T*)i.p), s(i.s) {}

	reference			operator*()					const	{ return *p;		}
	element*			operator->()				const	{ return p;			}
	reference			operator[](intptr_t i)		const	{ return *(T*)((char*)p + i * s); }
	stride_iterator&	operator++()						{ p = (T*)((char*)p + s); return *this;		}
	stride_iterator		operator++(int)						{ T	*p0 = p; operator++(); return stride_iterator<T>(p0, s); }
	stride_iterator&	operator--()						{ p = (T*)((char*)p - s); return *this;		}
	stride_iterator		operator--(int)						{ T	*p0 = p; operator--(); return stride_iterator<T>(p0, s); }
	stride_iterator&	operator+=(intptr_t i)				{ p = (T*)((char*)p + i * s); return *this;	}
	stride_iterator&	operator-=(intptr_t i)				{ p = (T*)((char*)p - i * s); return *this;	}
	stride_iterator		operator+(intptr_t i)		const	{ return stride_iterator<T>(*this) += i;	}
	stride_iterator		operator-(intptr_t i)		const	{ return stride_iterator<T>(*this) -= i;	}
	
	intptr_t operator-(const stride_iterator<T> &j)	const	{ return intptr_t(((char*)p - (char*)j.p) / s); }

	bool	operator==(const stride_iterator &b)	const	{ return p == b.p; }
	bool	operator!=(const stride_iterator &b)	const	{ return p != b.p; }
	bool	operator< (const stride_iterator &b)	const	{ return p <  b.p; }
	bool	operator<=(const stride_iterator &b)	const	{ return p <= b.p; }
	bool	operator> (const stride_iterator &b)	const	{ return p >  b.p; }
	bool	operator>=(const stride_iterator &b)	const	{ return p >= b.p; }

	operator T*() const { return p; }
};
template<typename T> inline stride_iterator<T> strided(T *p, int s)					{ return stride_iterator<T>(p, s);	}
template<typename T> inline stride_iterator<T> make_stride_iterator(T *p, int s)	{ return stride_iterator<T>(p, s);	}
template<typename T> inline stride_iterator<T> begin(stride_iterator<T> &i)			{ return i; }
template<typename T> inline stride_iterator<T> begin(const stride_iterator<T> &i)	{ return i; }

//-----------------------------------------------------------------------------
//	param_iterator
//-----------------------------------------------------------------------------

template<typename T, typename P> struct param_element {
	typedef T	element;
	T			&t;
	P			p;
	param_element(T &_t, const P &_p) : t(_t), p(_p) {}
	operator	T&()				const	{ return t; }
	T*			operator->()		const	{ return &t; }
	template<typename C, typename F> param_element<const F, P> get(F C::*f) const {
		return param_element<const F, P>(t.*f, p);
	}
};
/*
template<typename T, typename P> struct param_element<T*, P> {
	typedef T*	element;
	T			*t;
	P			p;
	param_element(T *_t, const P &_p) : t(_t), p(_p) {}
	operator	T*&()						{ return t; }
	T*			operator->()		const	{ return t; }
	template<typename C, typename F> param_element<const F, P> get(F C::*f) const {
		return param_element<const F, P>(t->*f, p);
	}
};

template<typename T, typename P> struct param_element<const T*, P> {
	typedef const T*	element;
	const T		*t;
	P			p;
	param_element(const  T *_t, const P &_p) : t(_t), p(_p) {}
	operator	const T*&()					{ return t; }
	const T		operator->()		const	{ return t; }
	template<typename C, typename F> param_element<const F, P> get(F C::*f) const {
		return param_element<const F, P>(t->*f, p);
	}
};
*/
template<typename T, typename P> T&	get(param_element<T, P> &&a)		{ return a; }
template<typename T, typename P> T&	get(param_element<T, P> &a)			{ return a; }
template<typename T, typename P> T&	get(const param_element<T, P> &a)	{ return a; }

template<typename T, typename P> inline_only param_element<T, P> make_param_element(T &t, const P &p) {
	return param_element<T, P>(t, p);
}
template<typename T, typename P> inline_only param_element<const T, P> make_param_element(const T &t, const P &p) {
	return param_element<const T, P>(t, p);
}


template<typename I, typename P, typename E = param_element<typename iterator_traits<I>::element, P> > struct param_iterator {
	I			i;
	P			p;

	typedef E	element, reference;
	typedef typename iterator_traits<I>::iterator_category iterator_category;

	param_iterator(const I &_i, const P &_p) : i(_i), p(_p) {}

	param_iterator&	operator++()							{ ++i; return *this; }
	param_iterator	operator++(int)							{ I i0 = i; ++i; return param_iterator(i0, p); }
	bool		operator==(const param_iterator &b)	const	{ return i == b.i; }
	bool		operator!=(const param_iterator &b)	const	{ return i != b.i; }
	bool		operator< (const param_iterator &b)	const	{ return i <  b.i; }
	bool		operator<=(const param_iterator &b)	const	{ return i <= b.i; }
	bool		operator> (const param_iterator &b)	const	{ return i >  b.i; }
	bool		operator>=(const param_iterator &b)	const	{ return i >= b.i; }

	element		operator*()			const	{ return element(*i, p); }
	element		operator->()		const	{ return element(*i, p); }
	element		operator[](int j)	const	{ return element(i[j], p); }

	friend param_iterator<I,P> operator+(const param_iterator<I,P> &a, size_t n) {
		return param_iterator<I,P>(a.i + n, a.p);
	}
	friend intptr_t operator-(const param_iterator<I,P> &a, const param_iterator<I,P> &b) {
		return intptr_t(a.i - b.i);
	}
};
template<typename I, typename P> inline_only param_iterator<I,P> make_param_iterator(const I &i, const P &p) {
	return param_iterator<I,P>(i, p);
}
template<typename I, typename P> inline_only param_iterator<I,P&> make_param_ref_iterator(const I &i, P &p) {
	return param_iterator<I,P&>(i, p);
}

template<typename I, typename P> using param_range			= range<param_iterator<I, P> >;
template<typename R, typename P> using param_container		= param_range<typename container_traits<R>::iterator, P>;

template<typename R, typename P> inline_only param_container<R,P> with_param(R &&r, P p) {
	return param_container<R,P>(make_param_iterator(r.begin(), p), make_param_iterator(r.end(), p));
}
template<typename R, typename P> inline_only param_container<R,P&> with_param_ref(R &&r, P &p) {
	return param_container<R,P&>(make_param_ref_iterator(r.begin(), p), make_param_ref_iterator(r.end(), p));
}

//-----------------------------------------------------------------------------
//	after - something that exists after another
//-----------------------------------------------------------------------------

template<typename T> void *get_after(const T *t)	{
	return (void*)(t + 1);
}

template<typename T, typename P> struct after {
	T&		get()		const	{ return *(T*)align(get_after((P*)this), T_alignment<T>::value); }
	operator T&()		const	{ return get(); }
	T*		operator&()	const	{ return &get(); }
	T*		operator->()const	{ return &get(); }
	template<typename T2> T&	operator=(const T2 &t2) { T &t = get(); t = t2; return t; }
	friend T&	get(const after &a)	{ return a; }
};

template<typename T, typename P> inline void *get_after(const after<T,P> *t) {
	return get_after(&t->get());
}

//-----------------------------------------------------------------------------
//	field_iterator - adapts iterator over structs to one over a field of the struct
//-----------------------------------------------------------------------------

template<typename I, typename P> struct field_iterator;
template<typename I, typename E, typename T> struct field_iterator<I, T E::*> {
	I	i;
	T	E::*p;
	typedef typename T_copyconst<typename iterator_traits<I>::reference, T>::type	element, &reference;
	typedef typename iterator_traits<I>::iterator_category	iterator_category;

	field_iterator(const I &_i, T E::*_p) : i(_i), p(_p) {}
	reference		operator*()					const	{ return get(*i).*p;	}
	element*		operator->()				const	{ return &get(*i).*p;	}
	reference		operator[](int b)			const	{ return i[b].*p;		}
	bool	operator==(const field_iterator &b)	const	{ return i == b.i;		}
	bool	operator!=(const field_iterator &b)	const	{ return i != b.i;		}
	field_iterator&		operator+=(int b)				{ i += b; return *this; }
	field_iterator&		operator-=(int b)				{ i -= b; return *this; }
	field_iterator&		operator++()					{ ++i; return *this;	}
	field_iterator&		operator--()					{ --i; return *this;	}
	field_iterator		operator++(int)					{ field_iterator b(*this); ++i; return b; }
	field_iterator		operator--(int)					{ field_iterator b(*this); --i; return b; }

	friend field_iterator	operator+(const field_iterator &a, int b)	{ return field_iterator(a.i + b, a.p); }
	friend field_iterator	operator-(const field_iterator &a, int b)	{ return field_iterator(a.i - b, a.p); }
	friend int				operator-(const field_iterator &a, const field_iterator &b)	{ return a.i - b.i; }
};

template<typename P> struct field_iterator_maker {
	template<P p, typename I> static field_iterator<I, P> make(const I &i) {
		return field_iterator<I, P>(i, p);
	}
	template<P p, typename I, int N> static field_iterator<I*, P> make(I (&i)[N]) {
		return field_iterator<I*, P>(i, p);
	}
};

#define make_field_iterator(i, P)	T_get_class<field_iterator_maker>(P)->make<P>(i)

template<typename C, typename P> struct field_container {
	C			&c;
	P			p;
	typedef field_iterator<typename container_traits<C>::iterator, P>	iterator;
	typedef field_iterator<typename container_traits<const C>::iterator, P>	const_iterator;
	typedef typename iterator::element									element;
	typedef typename iterator::reference								reference;

	field_container(C &_c, P _p) : c(_c), p(_p)	{}
	iterator		begin()							{ return iterator(iso::begin(c), p); }
	iterator		end()							{ return iterator(iso::end(c), p); }
	const_iterator	begin()					const	{ return const_iterator(iso::begin(c), p); }
	const_iterator	end()					const	{ return const_iterator(iso::end(c), p); }
	constexpr reference	operator[](int i)	const	{ return c[i].*p;	}
};

template<typename P> struct field_container_maker {
	template<P p, typename C> static field_container<const C, P> make(const C &c) {
		return field_container<const C, P>(c, p);
	}
	template<P p, typename C> static field_container<C, P> make(C &c) {
		return field_container<C, P>(c, p);
	}
};

#define make_field_container(c, p)	T_get_class<field_container_maker>(p)->make<p>(c)

//-----------------------------------------------------------------------------
//	filter_iterator
//-----------------------------------------------------------------------------

template<typename C, typename F> struct filter_iterator {
	typedef typename container_traits<C>::iterator	I;
	typedef typename iterator_traits<I>::element	element;
	typedef typename iterator_traits<I>::reference	reference;
	typedef forward_iterator_t iterator_category;
	I	i, e;
	F	f;
	filter_iterator(const I &_i, const I &_e, const F &_f) : i(_i), e(_e), f(_f) {
		while (i != e && !f(*i))
			++i;
	}
	filter_iterator& operator++()	{
		do ++i; while (i != e && !f(*i));
		return *this;
	}
	bool		operator==(const filter_iterator &b)	const	{ return i == b.i; }
	bool		operator!=(const filter_iterator &b)	const	{ return i != b.i; }
	reference	operator*()	 							const	{ return *i; }
	element*	operator->() 							const	{ return i; }
};

template<typename C, typename F> range<filter_iterator<C, F> > filter(C &c, const F &f) {
	return make_range(filter_iterator<C, F>(c.begin(), c.end(), f), filter_iterator<C, F>(c.end(), c.end(), f));
}

//-----------------------------------------------------------------------------
//	value_count
//-----------------------------------------------------------------------------

template<typename T> class value_iterator {
protected:
	const T	&t;
public:
	typedef random_access_iterator_t	iterator_category;
	typedef const T						element, &reference;

	inline_only value_iterator(const T &_t) : t(_t)	{}

	reference		operator*()			const	{ return t;		}
	const T*		operator->()		const	{ return &t;	}
	reference		operator[](intptr_t)const	{ return t;	}
	value_iterator&	operator++()				{ return *this;	}
	value_iterator&	operator++(int)				{ return *this;	}
	value_iterator&	operator--()				{ return *this;	}
	value_iterator&	operator--(int)				{ return *this;	}
};
template<typename T>	inline_only value_iterator<T>	make_value_iterator(const T &t)	{ return t;	}

template<typename T> class value_count {
protected:
	const T		&t;
	intptr_t	i;
public:
	typedef const T						element, &reference;
	typedef random_access_iterator_t	iterator_category;
	typedef value_count<T>				iterator, const_iterator;

	inline_only value_count(const T &_a, int _i) : t(_a), i(_i)	{}

	value_count			begin()					const	{ return value_count(t, 0);}
	const value_count&	end()					const	{ return *this;			}

	reference		operator*()					const	{ return t;				}
	const T*		operator->()				const	{ return &t;			}
	value_count&	operator++()						{ ++i; return *this;	}
	value_count		operator++(int)						{ return value_count<T>(t, i++);	}
	value_count&	operator--()						{ --i; return *this;	}
	value_count		operator--(int)						{ return value_count<T>(t, i--);	}
	int				operator-(const value_count<T> &b) const { return i - b.i; }
	value_count<T>	operator+(intptr_t b)				{ return value_count<T>(t, i + b);	}
	bool operator==(const value_count<T> &b)	const	{ return i == b.i;		}
	bool operator!=(const value_count<T> &b)	const	{ return i != b.i;		}
};

template<typename T> inline_only value_count<T> duplicate(const T &t, int n) { return value_count<T>(t, n); }

//-----------------------------------------------------------------------------
//	deferred_op
//-----------------------------------------------------------------------------

struct op_add	{ template<typename A, typename B> A operator()(const A &a, const B &b) const { return a + b; } };
struct op_sub	{ template<typename A, typename B> A operator()(const A &a, const B &b) const { return a - b; } };
struct op_mul	{ template<typename A, typename B> A operator()(const A &a, const B &b) const { return a * b; } };
struct op_div	{ template<typename A, typename B> A operator()(const A &a, const B &b) const { return a / b; } };
struct op_rdiv	{ template<typename A, typename B> A operator()(const A &a, const B &b) const { return b / a; } };
struct op_mod	{ template<typename A, typename B> A operator()(const A &a, const B &b) const { return a % b; } };
struct op_and	{ template<typename A, typename B> A operator()(const A &a, const B &b) const { return a & b; } };
struct op_or	{ template<typename A, typename B> A operator()(const A &a, const B &b) const { return a | b; } };
struct op_xor	{ template<typename A, typename B> A operator()(const A &a, const B &b) const { return a ^ b; } };
struct op_neg	{ template<typename A> A operator()(const A &a) const { return -a; } };
//struct op_recip	{ template<typename A> A operator()(const A &a) const { return reciprocal(a); } };

//binary
template<typename F, typename A, typename B = void> struct deferred_op {
	const A	a;
	const B	b;
	typedef typename A::element			element, reference;

//	typedef indexed_iterator<deferred_op, int_iterator<int> > iterator;
	struct iterator {
		typedef typename A::element			element, reference;
		typedef typename container_traits<A>::const_iterator	AI;
		typedef typename container_traits<B>::const_iterator	BI;
		typedef random_access_iterator_t	iterator_category;
		AI	a;
		BI	b;
		iterator(AI _a, BI _b) : a(_a), b(_b) {}
		element		operator*()	 					const	{ return F()(*a, *b); }
		ref_helper<element>	operator->() 			const	{ return F()(*a, *b); }
		iterator&	operator++()							{ ++a; ++b; return *this; }
		iterator	operator++(int)							{ return iterator(a++, b++); }
		iterator&	operator--()							{ --a; --b; return *this; }
		iterator	operator--(int)							{ return iterator(a--, b--); }
		iterator&	operator+=(int j)						{ a += j; b += j; return *this; }
		iterator&	operator-=(int j)						{ a -= j; b -= j; return *this; }
		element		operator[](int j)						{ return F()(a[j], b[j]); }
		bool		operator==(const iterator &b)	const	{ return a == b.a; }
		bool		operator!=(const iterator &b)	const	{ return a != b.a; }
	};
	typedef iterator const_iterator;

	deferred_op(const A &_a, const B &_b) : a(_a), b(_b) {}
	element		operator[](int i)	const	{ return F()(a[i], b[i]); }
	int			size()				const	{ return max(a.size(), b.size()); }
	iterator	begin()				const	{ return iterator(a.begin(), b.begin()); }
	iterator	end()				const	{ return iterator(a.end(), b.end()); }
};

//unary
template<typename F, typename A> struct deferred_op<F, A, void> {
	const A	a;
	typedef typename A::element	element, &reference;

//	typedef indexed_iterator<deferred_op, int_iterator<int> > iterator;
	struct iterator {
		typedef typename A::element			element, reference;
		typedef typename container_traits<A>::const_iterator	AI;
		typedef random_access_iterator_t	iterator_category;
		AI	a;
		iterator(AI _a) : a(_a) {}
		element		operator*()	 					const	{ return F()(*a); }
		ref_helper<element>	operator->() 			const	{ return F()(*a); }
		iterator&	operator++()							{ ++a; return *this; }
		iterator	operator++(int)							{ return iterator(a++); }
		iterator&	operator--()							{ --a; return *this; }
		iterator	operator--(int)							{ return iterator(a--); }
		iterator&	operator+=(int j)						{ a += j; return *this; }
		iterator&	operator-=(int j)						{ a -= j; return *this; }
		element		operator[](int j)						{ return F()(a[j]); }
		bool		operator==(const iterator &b)	const	{ return a == b.a; }
		bool		operator!=(const iterator &b)	const	{ return a != b.a; }
	};
	typedef iterator const_iterator;

	deferred_op(const A &_a) : a(_a) {}
	element		operator[](int i)	const	{ return F()(a[i]); }
	int			size()				const	{ return a.size(); }
	iterator	begin()				const	{ return iterator(a.begin()); }
	iterator	end()				const	{ return iterator(a.end()); }
};

template<typename F, typename A, typename B> constexpr inline size_t num_elements(const deferred_op<F,A,B> &c) { return c.size(); }

template<typename F, typename A, typename B> deferred_op<F,A,B> make_deferred_op(const A &a, const B &b) { return deferred_op<F, A, B>(a, b); }

template<typename F, typename A, typename B>				deferred_op<op_neg, deferred_op<F,A,B> >	operator-(const deferred_op<F,A,B> &u)				{ return deferred_op<op_neg, deferred_op<F,A,B> >(u); }
template<typename F, typename A, typename B, typename C>	deferred_op<op_add, deferred_op<F,A,B>, C>	operator+(const deferred_op<F,A,B> &u, const C &c)	{ return deferred_op<op_add, deferred_op<F,A,B>, C>(u, c); }
template<typename F, typename A, typename B, typename C>	deferred_op<op_sub, deferred_op<F,A,B>, C>	operator-(const deferred_op<F,A,B> &u, const C &c)	{ return deferred_op<op_sub, deferred_op<F,A,B>, C>(u, c); }
template<typename F, typename A, typename B, typename C>	deferred_op<op_mul, deferred_op<F,A,B>, C>	operator*(const deferred_op<F,A,B> &u, const C &c)	{ return deferred_op<op_mul, deferred_op<F,A,B>, C>(u, c); }
template<typename F, typename A, typename B, typename C>	deferred_op<op_div, deferred_op<F,A,B>, C>	operator/(const deferred_op<F,A,B> &u, const C &c)	{ return deferred_op<op_div, deferred_op<F,A,B>, C>(u, c); }

template<typename T> struct scalar {
	T	t;
	typedef random_access_iterator_t	iterator_category;
	typedef T	element, &reference;
	typedef scalar	iterator, const_iterator;
	scalar(const T &_t) : t(_t) {}
	scalar&		operator++()				{ return *this; }
	element		operator*()			const	{ return t; }
	element		operator[](int i)	const	{ return t; }
	int			size()				const	{ return 0; }
	scalar		begin()				const	{ return *this; }
	scalar		end()				const	{ return *this; }
};

template<typename T> scalar<T> make_scalar(const T &t) { return t; }

//-----------------------------------------------------------------------------
//	meta
//-----------------------------------------------------------------------------
#if 1
template<class T> static auto _has_begin(int)->T_constant0<bool, T_exists<decltype(begin(T()))>::value>;
template<class> static auto _has_begin(...)->T_false;

template <typename T> struct has_begin : decltype(_has_begin<T>(0)) {
};
#else
template<typename T> struct has_begin : yesno {
private:
	template<typename C> static yes test(decltype(begin(*(const T*)0))*);
	template<typename C> static no  test(...);
public:
	static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};
#endif

}//namespace iso

#endif // ITERATOR_H
