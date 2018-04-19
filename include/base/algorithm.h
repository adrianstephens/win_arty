#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "defs.h"

namespace iso {

struct assigner {
	template<typename T1, typename T2> void operator()(const T1 &a, T2 &&b) const { b = a; }
};

struct swapper {
	template<typename T1, typename T2> void operator()(T1 &a, T2 &b) const { swap(a, b); }
};

template<typename A> struct setter {
	const A	&a;
	setter(const A &_a) : a(_a) {}
	template<typename B> void operator()(B &b) const { b = a; }
};

template<class F> struct transformer {
	F	f;
	transformer(F _f) : f(_f) {}
	template<typename P1, typename R> void operator()(const P1 &p1, R &r) const { r = f(p1); }
	template<typename P1, typename P2, typename R> void operator()(const P1 &p1, const P2 &p2, R &r) const { r = f(p1, p2); }
};

template<class F> struct counter {
	F	f;
	int	n;
	counter(F _f) : n(0), f(_f) {}
	template<typename P1> void operator()(const P1 &p1) { n += int(f(p1)); }
	template<typename P1, typename P2> void operator()(const P1 &p1, const P2 &p2) { n += int(f(p1, p2)); }
	operator int() const	{ return n; }
};

// predicates
struct less				{ template<typename A, typename B> bool operator()(const A &a, const B &b) const { return a  < b; } };
struct less_equal		{ template<typename A, typename B> bool operator()(const A &a, const B &b) const { return a <= b; } };
struct greater			{ template<typename A, typename B> bool operator()(const A &a, const B &b) const { return a  > b; } };
struct greater_equal	{ template<typename A, typename B> bool operator()(const A &a, const B &b) const { return a >= b; } };
struct equal_to			{ template<typename A, typename B> bool operator()(const A &a, const B &b) const { return a == b; } };
struct not_equal_to		{ template<typename A, typename B> bool operator()(const A &a, const B &b) const { return a != b; } };
struct equal_vec		{ template<typename T> inline bool operator()(const T &a, const T &b) const { return all(a == b); } };
struct not_equal_vec	{ template<typename T> inline bool operator()(const T &a, const T &b) const { return any(a != b); } };

template<typename P, typename B> struct bound_predicate {
	P		p;
	const B	&b;
	template<typename A> bool	operator()(const A &a) const { return p(a, b); }
	bound_predicate(const B &_b) : b(_b)	{}
};

template<typename P> struct _deref {
	P	p;
	template<typename A, typename B> bool operator()(const A *a, const B *b) const { return p(*a, *b); }
	_deref(P _p) : p(_p) {}
};

template<typename P> _deref<P> deref(P p) { return p; }

//-----------------------------------------------------------------------------
//	actions
//-----------------------------------------------------------------------------
struct delete_s {
	template<typename T> void operator()(const T &a)	{ delete a; } 
};

struct erase {
	template<class C, class I> void operator()(C &c, I i) {
		c.erase(i);
	}
};

//-----------------------------------------------------------------------------
//	accumulators
//-----------------------------------------------------------------------------
template<typename T> struct sum_s {
	typename T_noconst<T>::type	v;
	sum_s() : v()			{}
	void operator()(const T &a)	{ v += a; } 
	operator T() const			{ return v; }
};
template<typename T> struct product_s {
	typename T_noconst<T>::type	v;
	product_s() : v(1)		{}
	void operator()(const T &a)	{ v *= a; } 
	operator T() const			{ return v; }
};
template<typename T> struct min_s {
	typename T_noconst<T>::type	v;
	bool	first;
	min_s() : first(true)		{}
	void operator()(const T &a)	{ v = first ? a : min(v, a); first = false; }
	operator T() const			{ return v; }
};
template<typename T> struct max_s {
	typename T_noconst<T>::type	v;
	bool	first;
	max_s() : first(true)		{}
	void operator()(const T &a)	{ v = first ? a : max(v, a); first = false; } 
	operator T() const			{ return v; }
};
template<typename T> struct range_s {
	typename T_noconst<T>::type	a, b;
	bool	first;
	range_s() : first(true), a(), b()	{}
	void operator()(const T &x)	{
		if (first) {
			a = b = x;
			first = false;
		} else {
			a = min(a, x);
			b = max(b, x);
		}
	}
	T	len() const {
		return b - a + 1;
	}
};

//-----------------------------------------------------------------------------
//	reverse
//-----------------------------------------------------------------------------
template<class I> inline void reverse(I a, I b) {
	while (a < b)
		swap(*a++, *--b);
}
template<class C> inline void reverse(C &c) {
	return reverse(begin(c), end(c));
}

//a..b with decreasing c
template<class I> inline I reverse0(I a, I b, I c) {
	while (a < b)
		swap(*a++, *--c);
	return c;
}

//b..c with increasing a
template<class I> inline I reverse1(I a, I b, I c) {
	while (b < c)
		swap(*a++, *--c);
	return a;
}


//exchange a..b with b..c
template<class I> inline void block_exchange(I a, I b, I c) {
	reverse(a, b);
	reverse(b, c);
	reverse(a, c);
}

//exchange a..b with c..d
template<class I> inline void block_exchange(I a, I b, I c, I d) {
	reverse(a, b);
	reverse(c, d);
	if (b - a <= d - c)
		reverse(c, reverse0(a, b, d));
	else
		reverse(reverse1(a, c, d), b);
}


//-----------------------------------------------------------------------------
//	for_each
//-----------------------------------------------------------------------------
template<class I, class F> inline F for_eachi(I i, I end, F f) {
	for (; i != end; ++i)
		f(i);
	return f;
}
template<class I, class F> inline F for_each(I i, I end, F f) {
	for (; i != end; ++i)
		f(*i);
	return f;
}
template<class I, class F> inline F for_eachn(I i, size_t n, F f) {
	while (n--) {
		f(*i);
		++i;
	}
	return f;
}
template<class C, class F> inline F for_each(C &c, F f) {
	return for_each(begin(c), end(c), f);
}
#ifdef NEED_CONST
template<class C, class F> inline F for_each(const C &c, F f) {
	return for_each(begin(c), end(c), f);
}
#endif

// for_each2
template<class I1, class I2, class F> inline F for_each2(I1 i1, I1 end, I2 i2, F f) {
	for (; i1 != end; ++i1, ++i2)
		f(*i1, *i2);
	return f;
}
template<class I1, class I2, class F> inline F for_each2n(I1 i1, I2 i2, size_t n, F f) {
	while (n--) {
		f(*i1, *i2);
		++i1;
		++i2;
	}
	return f;
}
template<class C1, class C2, class F> inline F for_each2(C1 &c1, C2 &c2, F f) {
	return for_each2(begin(c1), end(c1), begin(c2), f);
}
#ifdef NEED_CONST
template<class C1, class C2, class F> inline F for_each2(const C1 &c1, const C2 &c2, F f) {
	return for_each2(begin(c1), end(c1), begin(c2), f);
}
#endif
// for_each3
template<class I1, class I2, class I3, class F> inline F for_each3(I1 i1, I1 end, I2 i2, I3 i3, F f) {
	for (; i1 != end; ++i1, ++i2, ++i3)
		f(*i1, *i2, *i3);
	return f;
}
template<class I1, class I2, class I3, class F> inline F for_each3n(I1 i1, I2 i2, I3 i3, size_t n, F f) {
	while (n--) {
		f(*i1, *i2, *i3);
		++i1;
		++i2;
		++i3;
	}
	return f;
}
template<class C1, class C2, class C3, class F>	inline F for_each3(C1 &c1, C2 &c2, C3 &c3, F f) {
	return for_each3(begin(c1), end(c1), begin(c2), begin(c3), f);
}
#ifdef NEED_CONST
template<class C1, class C2, class C3, class F>	inline F for_each3(const C1 &c1, const C2 &c2, const C3 &c3, F f) {
	return for_each3(begin(c1), end(c1), begin(c2), begin(c3), f);
}
#endif

//-----------------------------------------------------------------------------
//	copies
//-----------------------------------------------------------------------------

template<class I, class O> inline void copy(I first, I last, O dest)		{ for_each2(first, last, dest, assigner()); }
template<class C, class O> inline void copy(const C &c, RREF(O) dest)		{ for_each2(c, dest, assigner()); }
template<class I, class O> inline void copyn(I srce, O dest, size_t n)		{ for_each2n(srce, dest, n, assigner()); }

template<class A, class B> inline void swap_ranges(A first, A last, B dest)	{ for_each2(first, last, dest, swapper()); }
template<class A, class B> inline void swap_ranges(A &&a, B &&b)			{ swap_ranges(a.begin(), a.end(), b.begin()); }


// optimised copies
inline void copy(uint8 *first, uint8 *last, uint8 *dest)	{ memcpy(dest, first, last - first); }
inline void copyn(uint8 *srce, uint8 *dest, size_t n)		{ memcpy(dest, srce, n); }

template<class I, class V> inline void fill(I first, I last, V value) {
	while (first != last) {
		*first = value;
		++first;
	}
}
//template<class C, class V> inline void fill(const C &c, V value)			{ fill(c.begin(), c.end(), value); }
//template<class I, class V> inline void filln(I srce, V value, size_t n)		{ fill(srce, srce + n, value); }

//-----------------------------------------------------------------------------
//	transforms
//-----------------------------------------------------------------------------
template<class I, class O, class F> inline void transform(I first, I last, O dest, F f)								{ for_each2(first, last, dest, transformer<F>(f)); }
template<class C, class O, class F> inline void transform(C &c, O &dest, F f)										{ for_each2(c, dest, transformer<F>(f)); }
template<class C, class O, class F> inline void transform(const C &c, const O &dest, F f)							{ for_each2(c, dest, transformer<F>(f)); }
template<class I1, class I2, class O, class F> inline void transform(I1 first1, I1 last1, I2 first2, O dest, F f)	{ for_each3(first1, last1, first2, dest, transformer<F>(f)); }
template<class I, class O, class F> inline void transformn(I first, O dest, F f, size_t n)							{ for_each2n(first, dest, n, transformer<F>(f)); }
template<class I1, class I2, class O, class F> inline O transformn(I1 first1, I2 first2, O dest, F f, size_t n)		{ for_each3n(first1, first2, dest, n, transformer<F>(f)); }


template<class C, class I> inline void append(C &c, I first, I last)	{
	for (; first != last; ++first)
		c.push_back(*first);
}
template<class C1, class C2> inline void append(C1 &c1, const C2 &c2) {
	append(c1, begin(c2), end(c2));
}

template<class C, class I> inline void prepend(C &c, I first, I last) {
	for (; first != last; ++first)
		c.push_front(*first);
}
template<class C1, class C2> inline void prepend(C1 &c1, const C2 &c2) {
	prepend(c1, begin(c2), end(c2));
}

template<class I, class F> inline int count(I first, I last, F f)	{ return for_each(first, last, counter<F>(f)); }
template<class C, class F> inline int count(C &c, F f)				{ return for_each(c, counter<F>(f)); }

template<class C, class F> struct transformed {
	C		&c;
	F		f;
	
	typedef typename container_traits<C>::iterator	I;
	
	struct iterator {
		typedef typename iterator_traits<I>::iterator_category iterator_category;
		typedef decltype(f(**(I*)0))	element, reference;
		const F	&f;
		I		i;
		iterator(const F &_f, I &&_i) : f(_f), i(_i) {}
		iterator&	operator++()	{ ++i; return *this; }
		auto operator*()			{ return f(*i); }
		friend bool operator==(const iterator &a, const iterator &b) { return a.i == b.i; }
		friend bool operator!=(const iterator &a, const iterator &b) { return a.i != b.i; }
	};

	transformed(C &_c, const F &_f)	: c(_c), f(_f)	{}
	transformed(C &_c, F &&_f)		: c(_c), f(_f)	{}
	iterator	begin()	const	{ return iterator(f, c.begin()); }
	iterator	end()	const	{ return iterator(f, c.end()); }

	typedef iterator			const_iterator;
	typedef typename iterator::element	element, reference;
};

template<class C, class F> auto make_transformed(C &c, F &&f) {
	return transformed<C, typename T_noref<F>::type>(c, forward<F>(f));
}

//-----------------------------------------------------------------------------
//	finds
//-----------------------------------------------------------------------------

template<class I> inline I max_iterator(I i, I end) {
	I	max	= i;
	while (++i != end) {
		if (*max < *i)
			max = i;
	}
	return max;
}

template<class I> inline I min_iterator(I i, I end) {
	I	min	= i;
	while (++i != end) {
		if (*i < *min)
			min = i;
	}
	return min;
}

template<class C> inline typename container_traits<C>::iterator max_iterator(C &c) {
	return max_iterator(begin(c), end(c));
}
template<class C> inline typename container_traits<C>::iterator min_iterator(C &c) {
	return min_iterator(begin(c), end(c));
}

template<class I, class P> inline I find_if(I i, I end, P pred) {
	while (i != end) {
		if (pred(*i))
			break;
		++i;
	}
	return i;
}
template<class I, class P> inline I find_ifn(I i, P pred, size_t n) {
	while (n--) {
		if (pred(*i))
			break;
		++i;
	}
	return i;
}
template<class C, class P> inline typename container_traits<C>::iterator find_if(C &c, P pred) {
	return find_if(begin(c), end(c), pred);
}
template<class C, class P> inline typename container_traits<C>::const_iterator find_if(const C &c, P pred) {
	return find_if(begin(c), end(c), pred);
}

template<class I, class T> inline I find(I first, I last, const T &t) {
	return find_if(first, last, bound_predicate<equal_to, T>(t));
}
template<class I, class T> inline I findn(I first, const T &t, size_t n) {
	return find_ifn(first, bound_predicate<equal_to, T>(t), n);
}
template<class C, class T> inline typename container_traits<C>::iterator find(C &c, const T &t) {
	return find(begin(c), end(c), t);
}
template<class C, class T> inline typename container_traits<C>::const_iterator find(const C &c, const T &t) {
	return find(begin(c), end(c), t);
}

//-------------------------------------
// find_check: return fail instead of end
//-------------------------------------
template<class I, class T> inline I find_check(I first, I last, const T &t, I fail = I()) {
	I	i = find(first, last, t);
	return i == last ? fail : i;
}
template<class C, class T, class I=typename container_traits<C>::iterator> inline I find_check(C &c, const T &t, I fail = I()) {
	return find_check(begin(c), end(c), t, fail);
}
template<class C, class T, class I=typename container_traits<C>::const_iterator> inline I find_check(const C &c, const T &t, I fail = I()) {
	return find_check(begin(c), end(c), t, fail);
}

template<class I, class P> inline I remove(I i, I end, P pred) {
	while (i != end) {
		if (pred(*i))
			swap(*i, *--end);
		else
			++i;
	}
	return i;
}

template<class C, class P> inline typename container_traits<C>::iterator remove(C &c, P pred) {
	return remove(begin(c), end(c), pred);
}

//-------------------------------------
// action: perform action if item found
//-------------------------------------
template<class C, class I, class A> void _action(C &c, I i, A act) {
	if (i != c.end())
		act(c, i);
}

template<class C, class P, class A> inline void action_if(C &c, P pred, A act) {
	return _action(c, find_if(begin(c), end(c), pred), act);
}
template<class C, class T, class A> inline void action(C &c, const T &t, A act) {
	return _action(c, find(begin(c), end(c), t), act);
}

//-----------------------------------------------------------------------------
// upper/lower bound
//-----------------------------------------------------------------------------

// lower bound
template<class I, class T> inline I _lower_bound(I first, I last, const T &t, input_iterator_t) {
	while (first != last && *first < t)
		++first;
	return first;
}
template<class I, class T> inline I _lower_bound(I first, I last, const T &t, random_access_iterator_t) {
	for (auto n = last - first; n; n >>= 1) {
		I middle = first + (n >> 1);
		if (*middle < t) {
			first = ++middle;
			--n;
		}
	}
	return first;
}
template<class I, class T> inline I lower_bound(I first, I last, const T &t) {
	return _lower_bound(first, last, t, typename iterator_traits<I>::iterator_category());
}
template<class C, class T> inline typename container_traits<C>::iterator lower_boundc(C &c, const T &t) {
	return lower_bound(begin(c), end(c), t);
}
template<class C, class T> inline typename container_traits<C>::const_iterator lower_boundc(const C &c, const T &t) {
	return lower_bound(begin(c), end(c), t);
}

//...with pred
template<class I, class T, class P> inline I _lower_bound(I first, I last, const T &t, P pred, input_iterator_t) {
	while (first != last && pred(*first, t))
		++first;
	return first;
}
template<class I, class T, class P> inline I _lower_bound(I first, I last, const T &t, P pred, random_access_iterator_t) {
	for (auto n = last - first; n; n >>= 1) {
		I middle = first + (n >> 1);
		if (pred(*middle, t)) {
			first = ++middle;
			--n;
		}
	}
	return first;
}
template<class I, class T, class P> inline I lower_bound(I first, I last, const T &t, P pred) {
	return _lower_bound(first, last, t, pred, typename iterator_traits<I>::iterator_category());
}
template<class C, class T, class P> inline typename container_traits<C>::iterator lower_boundc(C &c, const T &t, P pred) {
	return lower_bound(begin(c), end(c), t, pred);
}
template<class C, class T, class P> inline typename container_traits<C>::const_iterator lower_boundc(const C &c, const T &t, P pred) {
	return lower_bound(begin(c), end(c), t, pred);
}

// upper bound
template<class I, class T> inline I _upper_bound(I first, I last, const T &t, input_iterator_t) {
	while (first != last && !(t < *first))
		++first;
	return first;
}
template <class I, class T> inline I _upper_bound(I first, I last, const T& t, random_access_iterator_t) {
	for (auto n = last - first; n; n >>= 1) {
		I	middle = first + (n >> 1);
		if (!(t < *middle)) {
			first = ++middle;
			--n;
		}
	}
	return first;
}
template<class I, class T> inline I upper_bound(I first, I last, const T &t) {
	return _upper_bound(first, last, t, typename iterator_traits<I>::iterator_category());
}
template<class C, class T> inline typename container_traits<C>::iterator upper_boundc(C &c, const T &t) {
	return upper_bound(begin(c), end(c), t);
}
template<class C, class T> inline typename container_traits<C>::const_iterator upper_boundc(const C &c, const T &t) {
	return upper_bound(begin(c), end(c), t);
}
//...with pred
template<class I, class T, class P> inline I _upper_bound(I first, I last, const T &t, P pred, input_iterator_t) {
	while (first != last && !(t < *first))
		++first;
	return first;
}
template<class I, class T, class P> inline I _upper_bound(I first, I last, const T &t, P pred, random_access_iterator_t) {
	for (auto n = last - first; n; n >>= 1) {
		I middle = first + (n >> 1);
		if (!pred(t, *middle)) {
			first = ++middle;
			--n;
		}
	}
	return first;
}
template<class I, class T, class P> inline I upper_bound(I first, I last, const T &t, P pred) {
	return _upper_bound(first, last, t, pred, typename iterator_traits<I>::iterator_category());
}
template<class C, class T, class P> inline typename C::iterator upper_boundc(C &c, const T &t, P pred) {
	return upper_bound(begin(c), end(c), t, pred);
}
template<class C, class T, class P> inline typename C::const_iterator upper_boundc(const C &c, const T &t, P pred) {
	return upper_bound(begin(c), end(c), t, pred);
}

//-----------------------------------------------------------------------------
//	binary_search
//-----------------------------------------------------------------------------
template<typename I, class T, class P> inline I binary_search(I first, I last, const T &t, P pred) {
	I fail = last;
	while (first < last) {
		I middle = first + ((last - first) >> 1);
		if (pred(t, *middle))
			last = middle;
		else if (pred(*middle, t))
			first = middle + 1;
		else
			return middle;
	}
	return fail;
}

template<class C, class T, class P> inline typename C::iterator binary_search(C &c, const T &t, P pred) {
	return binary_search(begin(c), end(c), t, pred);
}

template<typename I, class T> inline I binary_search(I first, I last, T t) {
	I fail = last;
	while (first < last) {
		I middle = first + ((last - first) >> 1);
		if (t < *middle)
			last = middle;
		else if (*middle < t)
			first = middle + 1;
		else
			return middle;
	}
	return fail;
}

template<class C, class T> inline typename container_traits<C>::iterator binary_search(C &c, const T &t) {
	return binary_search(begin(c), end(c), t);
}

//-----------------------------------------------------------------------------
//	sort
//-----------------------------------------------------------------------------
template<class I, class P> void selection_sort(I lo, I hi, P comp) {
	while (--hi != lo) {
		I	max = lo, p = lo;
		while (p != hi) {
			if (comp(*max, *++p))
				max = p;
		}
		swap(*max, *hi);
	}
}

template<class I, class P> void sort(I lo, I hi, P comp) {
	if (hi - lo < 2)
		return;

	struct stack_entry {
		I	lo, hi;
		stack_entry(I _lo, I _hi) : lo(_lo), hi(_hi) {}
	};
	typedef void	*dummy_entry[sizeof(stack_entry) / sizeof(void*)];
	dummy_entry		stack[30], *sp = stack;

	--hi;
	for (;;) {
		uintptr_t	size = (hi - lo) + 1;
		// below a certain size, it is faster to use a O(n^2) sorting method
		if (size <= 8) {
			++hi;
			selection_sort(lo, hi, comp);
		} else {
			// Sort the first, middle, last elements into order
			I	mid = lo + size / 2;

			if (comp(*mid, *lo))
				swap(*lo, *mid);

			if (comp(*hi, *lo))
				swap(*lo, *hi);

			if (comp(*hi, *mid))
				swap(*mid, *hi);

			I		lo2 = lo, hi2 = hi;
			for (;;) {
				if (lo2 < mid)
					while (++lo2 < mid && !comp(*mid, *lo2));
				if (lo2 >= mid)
					while (++lo2 <= hi && !comp(*mid, *lo2));

				while (--hi2 > mid && comp(*mid, *hi2));

				if (hi2 < lo2)
					break;

				swap(*lo2, *hi2);

				// If the partition element was moved, follow it
				// Only need to check for mid == hi2, since before the swap, *lo2 > *mid => lo2 != mid.
				if (mid == hi2)
					mid = lo2;
			}

			++hi2;
			if (hi2 > mid)
				while (--hi2 > mid && !comp(*hi2, *mid));
			if (hi2 <= mid)
				while (--hi2 > lo && !comp(*hi2, *mid));

			if (hi2 - lo >= hi - lo2) {
				if (lo < hi2)
					new(sp++) stack_entry(lo, hi2);
				if (lo2 < hi) {
					lo = lo2;
					continue;
				}
			} else {
				if (lo2 < hi)
					new(sp++) stack_entry(lo2, hi);
				if (lo < hi2) {
					hi = hi2;
					continue;
				}
			}
		}

		if (sp-- == stack)
			break;

		stack_entry	*e = (stack_entry*)sp;
		lo = e->lo;
		hi = e->hi;
		e->~stack_entry();
	}
}

template<class I> void sort(I lo, I hi) {
	sort(lo, hi, less());
}

template<class C, class P> void sort(C &c, P comp) {
	sort(begin(c), end(c), comp);
}

template<class C> void sort(C &c) {
	sort(c, less());
}

template<class I, class P> I firstn(I lo, I hi, int n, P comp) {
	--hi;

	I	stop = lo + n;
	if (stop > hi)
		stop = hi;

	for (;;) {
		I	mid = lo + ((hi - lo + 1) >> 1);

		if (comp(*mid, *lo))
			swap(*lo, *mid);

		if (comp(*hi, *lo))
			swap(*lo, *hi);

		if (comp(*hi, *mid))
			swap(*mid, *hi);

		I		lo2 = lo, hi2 = hi;
		for (;;) {
			if (lo2 < mid)
				while (++lo2 < mid && !comp(*mid, *lo2));
			if (lo2 >= mid)
				while (++lo2 <= hi && !comp(*mid, *lo2));

			while (--hi2 > mid && comp(*mid, *hi2));

			if (hi2 < lo2)
				break;

			swap(*lo2, *hi2);

			if (mid == hi2)
				mid = lo2;
		}

		++hi2;
		if (hi2 > mid)
			while (--hi2 > mid && !comp(*hi2, *mid));
		if (hi2 <= mid)
			while (--hi2 > lo && !comp(*hi2, *mid));

		if (hi2 < stop) {
			if (lo2 > stop)
				return stop;
			lo = lo2;
		} else {
			hi = hi2;
		}
	}
}

template<class I, class P> I median(I lo, I hi, P comp) {
	return firstn(lo, hi, int((hi - lo) >> 1), comp);
}

//insertion_sort

template<class I, class P> void insertion_sort(I lo, I hi, P comp) {
	typedef typename iterator_traits<I>::element	T;
	if (lo == hi)
		return;
	for (I i = lo, j, k; j = i, ++i != hi;) {
		if (comp(*i, *j)) {
			T	t = *i;
			*i = *j;
			while ((k = j) > lo && comp(t, *--j))
				*k = *j;
			*k = t;
		}
	}
}

//-----------------------------------------------------------------------------
//	heap (and priority queue)
//-----------------------------------------------------------------------------

template<typename I, typename P> void heap_siftdown(I begin, I end, I root, P comp) {
	for (;;) {
		I	child = root + (root - begin + 1);
		if (child >= end)
			break;
		if (child + 1 < end && comp(child[1], child[0]))
			++child;
		if (!comp(*child, *root))
			break;
		swap(*root, *child);
		root	= child;
	}
}
template<typename I, typename P> void heap_siftup(I begin, I end, I child, P comp) {
	while (child > begin) {
		I	parent = begin + (child - begin - 1) / 2;
		if (comp(*parent, *child))
			break;
		swap(*parent, *child);
		child = parent;
	}
}

template<typename I, typename P> void heap_make(I begin, I end, P comp) {
	for (I i = begin + (end - begin - 2) / 2; i >= begin; --i)
		heap_siftdown(begin, end, i, comp);
}

template<typename I, typename P> void heap_push(I begin, I end, P comp) {
	heap_siftup(begin, end, end - 1, comp);
}

template<typename I, typename P> void heap_pop(I begin, I end, P comp) {
	swap(*--end, *begin);
	heap_siftdown(begin, end, begin, comp);
}

template<typename I, typename P> void heap_remove(I begin, I end, I item, P comp) {
	swap(*--end, *item);
	if (comp(*item, *end))
		heap_siftup(begin, end, item, comp);
	else
		heap_siftdown(begin, end, item, comp);
}
template<typename I, typename P> void heap_update(I begin, I end, I item, P comp) {
	I	parent = begin + (item - begin - 1) / 2;
	if (comp(*item, *parent))
		heap_siftup(begin, end, item, comp);
	else
		heap_siftdown(begin, end, item, comp);
}
template<typename I, typename P> void heap_sort(I begin, I end, P comp) {
	for (I i = end; i > begin + 1; --i) {
		swap(*--i, *begin);
		heap_siftdown(begin, i, begin, comp);
	}
}

// only efficient if item is near front
// requires a==b is equivalent to !comp(a,b) && !comp(b,a)
template<typename I, typename P, typename T> I heap_find(I begin, I end, const T &item, P comp) {
	for (I i = begin; ;) {
		if (comp(*i, item)) {
			I	next = i + (i - begin + 1);
			if (next < end) {
				i = next;
				continue;
			}

		} else if (!comp(item, *i)) {
			return i;
		}

		while (!((i - begin) & 1)) {
			i = begin + (i - begin - 1) / 2;
			if (i == begin)
				return end;
		}
		++i;
	}
}
// only efficient if item is near front
// requires a==b is equivalent to !comp(a,b) && !comp(b,a)
template<typename I, typename P, typename E, typename T> I heap_find(I begin, I end, const T &item, P comp, E equal) {
	for (I i = begin; ;) {
		if (equal(item, *i))
			return i;

		if (comp(*i, item)) {
			I	next = i + (i - begin + 1);
			if (next < end) {
				i = next;
				continue;
			}
		}

		while (!((i - begin) & 1)) {
			i = begin + (i - begin - 1) / 2;
			if (i == begin)
				return end;
		}
		++i;
	}
}

template<typename I>			void heap_make(I begin, I end)	{ heap_make(begin, end, less()); }
template<typename I>			void heap_push(I begin, I end)	{ heap_push(begin, end, less()); }
template<typename I>			void heap_pop (I begin, I end)	{ heap_pop (begin, end, less()); }
template<typename I>			void heap_sort(I begin, I end)	{ heap_sort(begin, end, less()); }
template<typename I>			void heap_remove(I begin, I end, I item) { heap_remove(begin, end, item, less()); }
template<typename I>			void heap_update(I begin, I end, I item) { heap_update(begin, end, item, less()); }

template<class C, typename P>	void heap_make(C &c, P comp)	{ heap_make(begin(c), end(c), comp); }
template<class C, typename P>	void heap_push(C &c, P comp)	{ heap_push(begin(c), end(c), comp); }
template<class C, typename P>	void heap_pop (C &c, P comp)	{ heap_pop (begin(c), end(c), comp); }
template<class C, typename P>	void heap_sort(C &c, P comp)	{ heap_sort(begin(c), end(c), comp); }

template<class C>				void heap_make(C &c)			{ heap_make(c, less()); }
template<class C>				void heap_push(C &c)			{ heap_push(c, less()); }
template<class C>				void heap_pop (C &c)			{ heap_pop (c, less()); }
template<class C>				void heap_sort(C &c)			{ heap_sort(c, less()); }

template<class C, typename P = less> struct priority_queue : C {
	P	p;
	typedef typename container_traits<C>::element	element;
	typedef typename container_traits<C>::iterator	iterator;

	priority_queue()	{}
	template<typename P2> priority_queue(const P2 &p2) : p(p2)	{}

	const element&	top()	const				{ return C::front(); }
	element&		top()						{ return C::front(); }
	void			pop()						{ heap_pop(C::begin(), C::end(), p); C::pop_back(); }
	element			pop_value()					{ heap_pop(C::begin(), C::end(), p); return C::pop_back_value(); }
	template<typename T2> void push(const T2 &t) { C::push_back(t); heap_push(C::begin(), C::end(), p); }

	iterator		find(const element &t)		{ return heap_find(C::begin(), C::end(), t, p); }
	template<typename E> iterator	find(const element &t, E e) { return heap_find(C::begin(), C::end(), t, p, e); }
	void			remove(iterator i)			{ heap_remove(C::begin(), C::end(), i, p); C::pop_back(); }

	friend void swap(const priority_queue &a, const priority_queue &b) {
		swap(a.c, b.c);
		swap(a.p, b.p);
	}
};

template<class C, typename P = less> struct priority_queue_ref {
	C	&c;
	P	p;
	typedef typename container_traits<C>::element	element;
	typedef typename container_traits<C>::iterator	iterator;

	priority_queue_ref(C &_c)	: c(_c) {}
	template<typename P2> priority_queue_ref(C &_c, const P2 &p2) : c(_c), p(p2)	{ heap_make(c); }

	const element&	top()	const				{ return c.front(); }
	element&		top()						{ return c.front(); }
	void			pop()						{ heap_pop(c.begin(), c.end(), p); c.pop_back(); }
	element			pop_value()					{ heap_pop(c.begin(), c.end(), p); return c.pop_back_value(); }
	template<typename T2> void push(const T2 &t) { c.push_back(t); heap_push(c.begin(), c.end(), p); }
	void			update(iterator i)			{ heap_update(c.begin(), c.end(), i, p); }

	iterator		find(const element &t)		{ return heap_find(c.begin(), c.end(), t, p); }
	template<typename E> iterator	find(const element &t, E e) { return heap_find(c.begin(), c.end(), t, p, e); }
	void			remove(iterator i)			{ heap_remove(c.begin(), c.end(), i, p); c.pop_back(); }
};

template<class C, typename P>	priority_queue<C, P>		make_priority_queue(P p)		{ return priority_queue<C, P>(p); }
template<class C, typename P>	priority_queue_ref<C, P>	make_priority_queue(C &c, P p)	{ return priority_queue_ref<C, P>(c, p); }
template<class C>				priority_queue_ref<C>		make_priority_queue(C &c)		{ return priority_queue_ref<C, less>(c); }

//-----------------------------------------------------------------------------
//	partition
//-----------------------------------------------------------------------------

template<typename I, class P> I partition(I begin, I end, P test) {
	I no = begin, yes = end;
	while (no != yes) {
		if (test(*no)) {
			while (no != yes && test(*--yes));
			if (no == yes)
				break;
			swap(*no, *yes);
		}
		++no;
	}
	return yes;
}

//-----------------------------------------------------------------------------
//	unique
//-----------------------------------------------------------------------------

template<typename I> I unique(I begin, I end) {
	if (begin == end)
		return end;

	I prev = begin;
	while (++begin != end) {
		if (!(*prev == *begin))
			*++prev = *begin;
	}
	return ++prev;
}

template<typename I, class P> I unique(I begin, I end, P pred) {
	if (begin == end)
		return end;

	I prev = begin;
	while (++begin != end) {
		if (!pred(*prev, *begin))
			*++prev = *begin;
	}
	return ++prev;
}

//-----------------------------------------------------------------------------
//	nearest_neighbour
//-----------------------------------------------------------------------------

template<typename C, typename X> typename container_traits<C>::iterator nearest_neighbour(C &c, const X &x, float &_min_dist) {
	typedef typename container_traits<C>::iterator	I;
	I		besti	= c.begin();
	float	bestd	= maximum;

	for (auto i = besti, e = c.end(); i != e; ++i) {
		const float d	= dist2(*i, x);
		if (d < bestd) {
			bestd	= d;
			besti	= i;
		}
	}

	_min_dist = bestd;
	return besti;
}

} // namespace iso

#endif // ALGORITHM_H
