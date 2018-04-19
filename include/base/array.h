#ifndef ARRAY_H
#define ARRAY_H

#include "defs.h"

namespace iso {

template<class W, typename T>	inline bool writen(W &w, const T *t, size_t n);
template<class R, typename T>	inline bool readn(R &r, T *t, size_t n);
template<typename T, class R> const T*	readp(R &r);
template<typename T, class R> const T*	readp(R &r, size_t n);

//-----------------------------------------------------------------------------
//	const_array
//-----------------------------------------------------------------------------

#ifdef USE_VARIADIC_TEMPLATES
template<typename T, typename I, I... args> struct const_array {
	typedef	const T		element, &reference, *iterator, *const_iterator;
	
	static const T*	data() {
		static const T data[sizeof...(args)] = { args... };
		return data;
	}
	operator T*()		const				{ return data(); }

	static bool		contains(const T *e)	{ return e && e >= begin() && e < end(); }
	static bool		contains(const T &e)	{ return &e >= begin() && &e < end(); }
	static int		index_of(const T *e)	{ return e ? e - begin() : -1;	}
	static int		index_of(const T &e)	{ return &e - begin();			}
	static size_t	size()					{ return sizeof...(args);		}
	static uint32	size32()				{ return uint32(size());		}
	static size_t	data_size()				{ return size() * sizeof(T);	}
	static uint32	data_size32()			{ return uint32(data_size());	}

	static const T&	front()					{ return *data();	}
	static const T&	back()					{ return end()[-1];	}
	static const T&	at(size_t i)			{ return data()[i];	}

	static const T*	begin()					{ return data(); }
	static const T*	end()					{ return data() + size(); }

	
	friend size_t	num_elements(const const_array&) { return sizeof...(args); }
};
#endif

//-----------------------------------------------------------------------------
//	array allocation
//-----------------------------------------------------------------------------

template<typename T> inline void construct(T *p, size_t n) {
	while (n--)
		new(p++) T();
}
template<typename T, typename T2> inline void construct(T *p, size_t n, const T2 &t) {
	while (n--)
		new(p++) T(t);
}
template<typename T, typename I> inline void construct_it(T *p, size_t n, I i) {
	while (n--) {
		new(p++) T(*i);
		++i;
	}
}
template<typename T> inline void destruct(T *p, size_t n) {
	while (n--)
		p++->~T();
}
template<typename T, int N> inline void destruct(T (*p)[N], size_t n) {
	destruct(&(*p)[0], n * N);
}
template<typename T> inline void move(T *s, T *d, size_t n) {
	int	i = 1;
	if (s < d) {
		s += n - 1;
		d += n - 1;
		i = -1;
	}
	while (n--) {
		new(d) T(*s);
		s->~T();
		s += i;
		d += i;
	}
}

template<typename T> inline T *allocate(size_t n) {
	return (T*)aligned_alloc(n * sizeof(T), T_alignment<T>::value);
}
template<typename T> inline void deallocate(T *p, size_t n) {
	aligned_free(p);
}
template<typename T> inline T *reallocate(T *p, size_t n0, size_t n1) {
	return (T*)aligned_realloc(p, n1 * sizeof(T), T_alignment<T>::value);
}
template<typename T> inline T *resize(T *p, size_t n0, size_t n1) {
	return (T*)aligned_resize(p, n1 * sizeof(T), T_alignment<T>::value);
}

template<typename T> inline T *reallocate_move(T *p, size_t n0, size_t n1) {
	T	*p1 = allocate<T>(n1);
	move(p, p1, n0);
	return p1;
}

template<typename T> T *new_array(size_t n) {
	T	*p = allocate<T>(n);
	construct(p, n);
	return p;
}
template<typename T> void delete_array(T *p, size_t n) {
	if (p) {
		destruct(p, n);
		deallocate(p, n);
	}
}

//-----------------------------------------------------------------------------
//	class embedded_array
//-----------------------------------------------------------------------------

template<typename T, typename C> class embedded_array {
	C		count;
public:
	typedef const T *iterator, *const_iterator;
	typedef const T	element, &reference;

	size_t		size()	const	{ return count; }
	iterator	begin()	const	{ return (const T*)(this + 1); }
	iterator	end()	const	{ return begin() + count; }
	operator iterator()	const	{ return begin(); }

	template<typename R> bool read(R &r) {
		return r.read(count) && readn(r, begin(), count);
	}

	template<typename R> static const embedded_array *get_ptr(R &r) {
		const embedded_array	*p = r.get_ptr();
		readp<T>(r, p->size());
		return p;
	}
};

template<typename T, typename C> void *get_after(const embedded_array<T, C> *t)	{
	return (void*)t->end();
}

template<typename T, typename C> class embedded_next_array {
	C		count;
public:
	typedef next_iterator<T>	iterator, const_iterator;
	typedef T					element, &reference;

	uint32		size()	const	{ return count; }
	iterator	begin()	const	{ return iterator((T*)(this + 1), 0); }
	iterator	end()	const	{ return iterator((T*)(this + 1), count); }
};

template<typename T, typename C> void *get_after(const embedded_next_array<T, C> *t)	{
	return (void*)t->end();
}

//-----------------------------------------------------------------------------
//	class ref_array
//	reference counted array
//-----------------------------------------------------------------------------

template<typename T> class ref_array {
	struct P {
		uint32	nrefs;
		T		array[];
		P()					: nrefs(1) {}
		void	addref()	{ ++nrefs; }
		void	release()	{ if (--nrefs == 0) delete this; }
		P*		resize(size_t n)					{ return (P*)aligned_realloc(this, sizeof(P) + n * sizeof(T), T_alignment<T>::value); }
		void*	operator new(size_t s, size_t n)	{ return aligned_alloc(s + n * sizeof(T), T_alignment<T>::value); }
		void	operator delete(void *p)			{ return aligned_free(p); }
	};

	P		*p;
public:
	typedef	T	element, &reference;

	template<int N> struct C {
		uint32	nrefs;
		T		array[N];
	};

	ref_array()			: p(0)					{}
	template<int N> ref_array(const C<N> &b)	{ p = (P*)&b; p->addref();	}
	ref_array(const ref_array &b)				{ if (p = b.p) p->addref();	}
	ref_array(size_t n)	: p(new(n) P)			{}
	ref_array(size_t n, const T *t)	: p(new(n) P)	{ construct_it(p->array, n, t); }
	ref_array(size_t n, const T &t)	: p(new(n) P)	{ construct(p->array, n, t); }
	~ref_array()								{ if (p) p->release();		}
	void		operator=(const ref_array &b)	{ if (b.p) b.p->addref(); if (p) p->release(); p = b.p; }

#ifdef USE_RVALUE_REFS
	ref_array(ref_array &&b)					{ p = b.p; b.p = 0;	}
	void		operator=(ref_array &&b)		{ swap(p, b.p); }
#endif

	T*			get()			const			{ return p ? p->array : 0; }
	operator	T*()			const			{ return p ? p->array : 0; }
	bool		shared()		const			{ return p && p->nrefs > 1; }

	void		clear()							{ if (p) { p->release(); p = 0; } }
	void		create(size_t n)				{ clear(); p = new(n) P; }
	void		create(size_t n, const T *t)	{ create(n); construct_it(p->array, n, t); }
	void		create(size_t n, const T &t)	{ create(n); construct(p->array, n, t); }
	void		grow(size_t n) {
		if (p) {
			if (p->nrefs > 1) {
				P	*p2 = new(n) P;
				construct_it(p2->array, n, p->array);
				p->release();
				p = p2;
			} else {
				p = p->resize(n);
			}
		} else {
			p = new(n) P;
		}
	}
	
	ref_array	dup(int n)		const			{ return ref_array(n, get()); }
	friend void	swap(ref_array &a, ref_array &b){ swap(a.p, b.p); }
	friend T*	get(const ref_array &a)			{ return a; }
	friend T*	get(ref_array &a)				{ return a; }
};

template<typename T, T... args> struct static_ref_array {
	enum { size = sizeof...(args) };
	static typename ref_array<T>::template C<sizeof...(args)>	x;
};
template<typename T, T... args> typename ref_array<T>::template C<sizeof...(args)>	static_ref_array<T, args...>::x = {1, {args... }};

//-----------------------------------------------------------------------------
//	column_major
//-----------------------------------------------------------------------------

template<typename T, int S> class fixed_stride_iterator {
	T	(*t)[S];
	friend fixed_stride_iterator operator+(const fixed_stride_iterator &a, int b)	{ return a.t + b; }
	friend fixed_stride_iterator operator-(const fixed_stride_iterator &a, int b)	{ return a.t - b; }
public:
	fixed_stride_iterator(T (*_t)[S]) : t(_t)		{}
	fixed_stride_iterator(T *_t) : t((T(*)[S])_t)	{}
	T&		operator*()								const	{ return t[0][0];		}
	T*		operator->()							const	{ return &t[0][0];		}
	T&		operator[](int i)						const	{ return t[i][0];	}
	bool	operator==(fixed_stride_iterator &b)	const	{ return t == b.t;		}
	bool	operator!=(fixed_stride_iterator &b)	const	{ return t != b.t;		}
	fixed_stride_iterator&	operator+=(int i)				{ t += i; return *this; }
	fixed_stride_iterator&	operator-=(int i)				{ t -= i; return *this; }
	fixed_stride_iterator&	operator++()					{ ++t; return *this;	}
	fixed_stride_iterator&	operator--()					{ --t; return *this;	}
	fixed_stride_iterator	operator++(int)					{ return t++;			}
	fixed_stride_iterator	operator--(int)					{ return t--;			}
};
template<int S, typename T> fixed_stride_iterator<T,S> column(T(*t)[S]) { return t; }
template<int S, typename T> fixed_stride_iterator<T,S> column(T *t)		{ return t; }

template<typename T, int R, int C> class column_major {
	T	t[C][R];
public:
	class row {
		T	(*t)[R];
	public:
		typedef	T									element, &reference;
		typedef fixed_stride_iterator<T, R>			iterator;
		typedef fixed_stride_iterator<const T, R>	const_iterator;

		row(T *_t) : t((T(*)[R])_t)	{}
		T&				operator[](int i)	const	{ return t[i][0];	}
		int				size()				const	{ return C;			}
		iterator		begin()						{ return t;			}
		iterator		end()						{ return t + C;		}
		const_iterator	begin()				const	{ return t;			}
		const_iterator	end()				const	{ return t + C;		}
	};

	class iterator {
		T	*t;
		friend iterator	operator+(const iterator &a, int b)	{ return a.t + b; }
		friend iterator	operator-(const iterator &a, int b)	{ return a.t - b; }
		struct rowp {
			row r, *p;
			rowp(T *t) : r(t), p(&r) {}
			row* operator->() const { return p; }
		};
	public:
		iterator(T *_t) : t(_t)	{}
		row			operator*()				const	{ return t;			}
		rowp		operator->()			const	{ return t;			}
		bool		operator==(iterator &b)	const	{ return t == b.t;	}
		bool		operator!=(iterator &b)	const	{ return t != b.t;	}
		iterator&	operator+=(int i)				{ t += i; return *this; }
		iterator&	operator-=(int i)				{ t -= i; return *this; }
		iterator&	operator++()					{ ++t; return *this; }
		iterator&	operator--()					{ --t; return *this; }
		iterator	operator++(int)					{ return t++;		}
		iterator	operator--(int)					{ return t--;		}
	};
	typedef T							element, &reference;
	typedef column_major<const T, R, C>	ctype;
	typedef typename ctype::iterator	const_iterator;
	typedef typename ctype::row			crow;

	row				operator[](int i)			{ return t[0] + i;	}
	crow			operator[](int i)	const	{ return t[0] + i;	}
	int				size()				const	{ return R;			}
	iterator		begin()						{ return t[0];		}
	iterator		end()						{ return t[0] + R;	}
	const_iterator	begin()				const	{ return t[0];		}
	const_iterator	end()				const	{ return t[0] + R;	}
};

//-----------------------------------------------------------------------------
//	row_major
//-----------------------------------------------------------------------------

// for completeness!
template<typename T, int R, int C> class row_major {
	T	t[R][C];
public:
	class row {
		T	*t;
	public:
		typedef	T			element, &reference, *iterator;
		typedef	const T*	const_iterator;

		row(T *_t) : t(_t)	{}
		T&				operator[](int i)	const	{ return t[i];		}
		int				size()				const	{ return C;			}
		iterator		begin()						{ return t;			}
		iterator		end()						{ return t + C;		}
		const_iterator	begin()				const	{ return t;			}
		const_iterator	end()				const	{ return t + C;		}
	};

	class iterator {
		typedef	T (*A)[C];
		T	(*t)[C];
		struct rowp {
			row r, *p;
			rowp(T *t) : r(t), p(&r) {}
			row* operator->() const { return p; }
		};
	public:
		iterator(T (*_t)[C]) : t(_t) {}
		operator	A&()							{ return t;			}
		operator	A()						const	{ return t;			}
		row			operator*()				const	{ return t[0];		}
		rowp		operator->()			const	{ return t[0];		}
	};
	typedef T							element, &reference;
	typedef row_major<const T, R, C>	ctype;
	typedef typename ctype::iterator	const_iterator;
	typedef typename ctype::row			crow;

	row				operator[](int i)			{ return t[i];	}
	crow			operator[](int i)	const	{ return t[i];	}
	int				size()				const	{ return R;		}
	iterator		begin()						{ return t;		}
	iterator		end()						{ return t + R;	}
	const_iterator	begin()				const	{ return t;		}
	const_iterator	end()				const	{ return t + R;	}
};

//-----------------------------------------------------------------------------
//	class fixed_array
//-----------------------------------------------------------------------------

template<typename T, int N> class fixed_array {
protected:
	T			t[N];
	template<typename I> void _copy(I p) {
		for (int i = 0; i < N; ++i, ++p)
			t[i] = *p;
	}
	template<typename U> void _set(int i, const U& u) {
		t[i] = u;
	}
	template<typename U, typename... UU> void _set(int i, const U& u, const UU&... uu) {
		t[i] = u;
		_set(i + 1, uu...);
	}
public:
	typedef	T			element, &reference, *iterator;
	typedef const T*	const_iterator;

//	constexpr operator	T*()							{ return t;	}
//	constexpr operator	const T*()				const	{ return t;	}
	constexpr T&		operator[](size_t i)			{ return t[i]; }
	constexpr const T&	operator[](size_t i)	const	{ return t[i]; }
	constexpr int		index_of(const T *e)	const	{ return e ? e - t : -1; }
	constexpr int		index_of(const T &e)	const	{ return &e - t; }
	constexpr bool		contains(const T *e)	const	{ return e && e >= t && e < t + N; }
	constexpr bool		contains(const T &e)	const	{ return &e >= t && &e < t + N; }

	fixed_array() {}
	fixed_array(const T &_t) {
		for (iterator i = begin(), e = end(); i < e; ++i)
			*i = _t;
	}
	template<typename U> fixed_array(const U (&c)[N])						{ _copy(&c[0]); }
	template<typename U> fixed_array(const fixed_array<U,N> &c)				{ _copy(c.begin()); }
	template<typename U> fixed_array(const U *p)							{ _copy(p); }
	template<typename U1, typename U2, typename... UU> fixed_array(const U1& u1, const U2& u2, const UU&... uu)	{ _set(0, u1, u2, uu...); }
	template<typename U> fixed_array& operator=(const U (&c)[N])			{ _copy(&c[0]); return *this; }
	template<typename U> fixed_array& operator=(const fixed_array<U,N> &c)	{ _copy(c.begin()); return *this; }
	template<typename U> fixed_array& operator=(const U *p)					{ _copy(p); return *this; }

	template<typename F, typename A, typename B> fixed_array& operator=(const deferred_op<F, A, B> &d) {
		_copy(d.begin());
		return *this;
	}

	template<typename U> friend fixed_array& operator+=(fixed_array &a, const fixed_array<U,N> &c)	{
		for (int i = 0; i < N; ++i)
			a.t[i] += c[i];
		return a;
	}
	template<typename U> friend fixed_array& operator-=(fixed_array &a, const fixed_array<U,N> &c)	{
		for (int i = 0; i < N; ++i)
			a.t[i] -= c[i];
		return a;
	}
	template<typename U> friend fixed_array& operator*=(fixed_array &a, const fixed_array<U,N> &c)	{
		for (int i = 0; i < N; ++i)
			a.t[i] *= c[i];
		return a;
	}
	template<typename U> friend fixed_array& operator/=(fixed_array &a, const fixed_array<U,N> &c)	{
		for (int i = 0; i < N; ++i)
			a.t[i] /= c[i];
		return a;
	}
	template<typename U> friend fixed_array& operator&=(fixed_array &a, const fixed_array<U,N> &c)	{
		for (int i = 0; i < N; ++i)
			a.t[i] &= c[i];
		return a;
	}
	template<typename U> friend fixed_array& operator|=(fixed_array &a, const fixed_array<U,N> &c)	{
		for (int i = 0; i < N; ++i)
			a.t[i] |= c[i];
		return a;
	}
	template<typename U> friend fixed_array& operator^=(fixed_array &a, const fixed_array<U,N> &c)	{
		for (int i = 0; i < N; ++i)
			a.t[i] ^= c[i];
		return a;
	}
	template<typename U> friend deferred_op<op_add, fixed_array, fixed_array<U,N> >	operator+(const fixed_array &a, const fixed_array<U,N> &b)	{
		return deferred_op<op_add, fixed_array, fixed_array<U,N> >(a, b);
	}
	template<typename U> friend deferred_op<op_sub, fixed_array, fixed_array<U,N> >	operator-(const fixed_array &a, const fixed_array<U,N> &b)	{
		return deferred_op<op_sub, fixed_array, fixed_array<U,N> >(a, b);
	}
	template<typename U> friend deferred_op<op_mul, fixed_array, fixed_array<U,N> >	operator*(const fixed_array &a, const fixed_array<U,N> &b)	{
		return deferred_op<op_mul, fixed_array, fixed_array<U,N> >(a, b);
	}
	template<typename U> friend deferred_op<op_div, fixed_array, fixed_array<U,N> >	operator/(const fixed_array &a, const fixed_array<U,N> &b)	{
		return deferred_op<op_div, fixed_array, fixed_array<U,N> >(a, b);
	}
	template<typename U> friend deferred_op<op_and, fixed_array, fixed_array<U,N> >	operator&(const fixed_array &a, const fixed_array<U,N> &b)	{
		return deferred_op<op_and, fixed_array, fixed_array<U,N> >(a, b);
	}
	template<typename U> friend deferred_op<op_or, fixed_array, fixed_array<U,N> >	operator|(const fixed_array &a, const fixed_array<U,N> &b)	{
		return deferred_op<op_or, fixed_array, fixed_array<U,N> >(a, b);
	}
	template<typename U> friend deferred_op<op_xor, fixed_array, fixed_array<U,N> >	operator^(const fixed_array &a, const fixed_array<U,N> &b)	{
		return deferred_op<op_xor, fixed_array, fixed_array<U,N> >(a, b);
	}

	bool operator==(const fixed_array &b) const { return memcmp(this, &b, sizeof(*this)) == 0; }
	bool operator!=(const fixed_array &b) const { return memcmp(this, &b, sizeof(*this)) != 0; }

	constexpr int				size()			const	{ return N;			}
	constexpr const T&			at(size_t i)	const 	{ ISO_ASSERT(i < N); return t[i];	}
	constexpr const T&			front()			const 	{ return t[0];		}
	constexpr const_iterator	begin()			const	{ return t;			}
	constexpr const_iterator	end()			const	{ return t + N;		}

	T&			at(size_t i)	{ ISO_ASSERT(i < N); return t[i];	}
	T&			front()			{ return t[0];		}
	iterator	begin()			{ return t;			}
	iterator	end()			{ return t + N;		}

	friend constexpr size_t num_elements(const fixed_array &t) { return N; }
};

template<typename T, int N> class fixed_array<const T, N> {
protected:
	const T			t[N];
public:
	typedef	const T		element, &reference, *iterator, *const_iterator;

	constexpr operator	const T*()				const	{ return t;	}
	constexpr int		index_of(const T *e)	const	{ return e ? e - t : -1; }
	constexpr int		index_of(const T &e)	const	{ return &e - t; }
	constexpr bool		contains(const T *e)	const	{ return e && e >= t && e < t + N; }
	constexpr bool		contains(const T &e)	const	{ return &e >= t && &e < t + N; }

	template<typename... UU> constexpr fixed_array(const UU&... uu)	: t{uu...} {}

	bool operator==(const fixed_array &b) const { return memcmp(this, &b, sizeof(*this)) == 0; }
	bool operator!=(const fixed_array &b) const { return memcmp(this, &b, sizeof(*this)) != 0; }

	constexpr int				size()			const	{ return N;			}
	constexpr const T&			at(size_t i)	const 	{ ISO_ASSERT(i < N); return t[i];	}
	constexpr const T&			front()			const 	{ return t[0];		}
	constexpr const_iterator	begin()			const	{ return t;			}
	constexpr const_iterator	end()			const	{ return t + N;		}

	friend constexpr size_t num_elements(const fixed_array &t) { return N; }
};

template<typename T, typename ...TT> constexpr fixed_array<const T, sizeof...(TT) + 1> make_fixed_array(const T &t, const TT&... tt) {
	return fixed_array<const T, sizeof...(TT) + 1>(t, tt...);
}

template<typename T, int N> struct T_swap_endian_type<fixed_array<T, N> >			{ typedef fixed_array<T_swap_endian<T>, N> type; };

template<typename T> inline_only fixed_array<T,2> values(const T &a, const T &b) {
	fixed_array<T,2> x; x[0] = a; x[1] = b; return x;
}
template<typename T> inline_only fixed_array<T,3> values(const T &a, const T &b, const T &c) {
	fixed_array<T,3> x; x[0] = a; x[1] = b; x[2] = c; return x;
}
template<typename T> inline_only fixed_array<T,4> values(const T &a, const T &b, const T &c, const T &d) {
	fixed_array<T,4> x; x[0] = a; x[1] = b; x[2] = c; x[3] = d; return x;
}
template<typename T> inline_only fixed_array<T,5> values(const T &a, const T &b, const T &c, const T &d, const T &e) {
	fixed_array<T,5> x; x[0] = a; x[1] = b; x[2] = c; x[3] = d; x[4] = e; return x;
}
template<typename T> inline_only fixed_array<T,6> values(const T &a, const T &b, const T &c, const T &d, const T &e, const T &f) {
	fixed_array<T,6> x; x[0] = a; x[1] = b; x[2] = c; x[3] = d; x[4] = e; x[5] = f; return x;
}
template<typename T> inline_only fixed_array<T,7> values(const T &a, const T &b, const T &c, const T &d, const T &e, const T &f, const T &g) {
	fixed_array<T,7> x; x[0] = a; x[1] = b; x[2] = c; x[3] = d; x[4] = e; x[5] = f; x[6] = g; return x;
}
template<typename T> inline_only fixed_array<T,8> values(const T &a, const T &b, const T &c, const T &d, const T &e, const T &f, const T &g, const T &h) {
	fixed_array<T,8> x; x[0] = a; x[1] = b; x[2] = c; x[3] = d; x[4] = e; x[5] = f; x[6] = g; x[7] = h; return x;
}

//-----------------------------------------------------------------------------
//	class array
//-----------------------------------------------------------------------------

template<typename T, int N> class array : public fixed_array<T, N> {
protected:
	typedef fixed_array<T, N> B;
	uint32		curr_size;
	using		 B::t;

	template<typename I> void _push(I first, I last) {
		while (first != last) {
			push_back(*first);
			++first;
		}
	}
public:
	using typename B::const_iterator;
	using typename B::iterator;

	array() : curr_size(0)	{}
	array(int n, const T &t) : curr_size(n) {
		for (T *dest = this->t; n--; ++dest)
			*dest = t;
	}
	template<typename I> array(I first, I last) : curr_size(0)	{ _push(first, last); }
	template<typename C> array(const C &c) : curr_size(0)		{ _push(iso::begin(c), iso::end(c)); }
	template<typename C> array&	operator=(C &c)					{ clear(); _push(iso::begin(c), iso::end(c)); return *this; }

	bool					contains(const T *e) const	{ return e && e >= t && e < t + curr_size; }
	bool					contains(const T &e) const	{ return &e >= t && &e < t + curr_size; }

	uint32					size()				const	{ return curr_size;			}
	size_t					capacity()			const	{ return N;					}
	bool					empty()				const	{ return curr_size == 0;	}
	bool					full()				const	{ return curr_size == N;	}
	void					clear()						{ curr_size = 0;			}
	void					resize(int i)				{ curr_size = i;			}
	void					resize(int i, const T &t)	{ while (i > curr_size) t[curr_size++] = t; }

	T*						expand()					{ ISO_ASSERT(curr_size < N); return t + curr_size++; }
	T*						expand(size_t n)			{ ISO_ASSERT(curr_size + n <= N); T *r = t + curr_size; curr_size += n; return r; }
	template<typename U> void push_back(const U &v)		{ ISO_ASSERT(curr_size < N); t[curr_size++] = v;	}
	T&						push_back()					{ ISO_ASSERT(curr_size < N); return t[curr_size++];	}
	T&						pop_back()					{ ISO_ASSERT(curr_size > 0); return t[--curr_size];	}

	const T&				back()				const	{ return t[curr_size - 1];	}
	T&						back()						{ return t[curr_size - 1];	}

	const_iterator			end()				const	{ return t + curr_size;		}
	iterator				end()						{ return t + curr_size;		}

	iterator		erase_unordered(iterator iter) {
		ISO_ASSERT(contains(iter));
		iterator last = end() - 1;
		if (iter != last)
			*iter = *last;
		--curr_size;
		return iter;
	}
	friend size_t num_elements(const array &t)	{ return t.size();	}
};

//-----------------------------------------------------------------------------
//	ptr_array
//-----------------------------------------------------------------------------

template<typename T> class ptr_array {
protected:
	T		*p;
	size_t	curr_size;

	T*	_insert(T *t, size_t back) {
		if (back) {
			T *prev = t--;
			new (prev) T(*t);
			while (--back) {
				prev	= t--;
				*prev	= *t;
			}
			t->~T();
		}
		return t;
	}

	template<typename I> T*	_insert(size_t back, I first, I last) {
		size_t		n	= distance(first, last);
		T			*d	= end();
		T			*s	= d - n;

		size_t	nt	= min(n, back);
		back	-= nt;
		n		-= nt;
		while (nt--)
			new(--d) T(*--s);
		while (back--)
			*--d = *--s;
		while (n--)
			new(--d) T(*--last);
		while (last != first)
			*--d = *--last;
		return d;
	}
public:
	typedef typename T_noarray<T>::type	value;
	typedef	T							element, &reference, *iterator;
	typedef const T*					const_iterator;

	ptr_array(size_t _n = 0)	: p(0), curr_size(_n) {}
	ptr_array(T *_p, size_t _n) : p(_p), curr_size(_n) {}

	operator		T*()					const	{ return p;						}
	bool			contains(const T *e)	const	{ return e && e >= p && e < p + curr_size; }
	bool			contains(const T &e)	const	{ return &e >= p && &e < p + curr_size; }
	int				index_of(const T *e)	const	{ return e ? e - p : -1;		}
	int				index_of(const T &e)	const	{ return &e - p;				}
	size_t			size()					const	{ return curr_size;				}
	uint32			size32()				const	{ return uint32(curr_size);		}
	size_t			data_size()				const	{ return curr_size * sizeof(T);	}
	uint32			data_size32()			const	{ return uint32(data_size());	}

	bool			empty()					const	{ return curr_size == 0;		}
	const T&		front()					const	{ return p[0];					}
	const T&		back()					const	{ return p[curr_size - 1];		}
	const T&		at(size_t i)			const	{ return p[i];					}
	T&				front()							{ return p[0];					}
	T&				back()							{ return p[curr_size - 1];		}
	T&				back(size_t i)					{ return p[curr_size - 1 - i];	}
	T&				at(size_t i)					{ return p[i];					}

	const_iterator	begin()					const	{ return p;						}
	const_iterator	end()					const	{ return p + curr_size;			}
	iterator		begin()							{ return p;						}
	iterator		end()							{ return p + curr_size;			}

	iterator		erase_unordered(iterator iter) {
		ISO_ASSERT(contains(iter));
		iterator last = end() - 1;
		if (iter != last)
			*iter = move(*last);
		destruct(last, 1);
		--curr_size;
		return iter;
	}
	iterator		erase(iterator iter) {
		ISO_ASSERT(contains(iter));
		iterator current = iter, next = current + 1;
		while (next != end())
			*current++ = move(*next++);
		destruct(current, 1);
		--curr_size;
		return iter;
	}

	iterator		erase(iterator first, iterator last) {
		ISO_ASSERT(last >= first && first >= begin() && last <= end());
		if (last > first) {
			iterator current = first;
			while (last != end())
				*current++ = move(*last++);
			destruct(current, last - current);
			curr_size = current - begin();
		}
		return first;
	}

	template<typename W> bool	write(W &w)	const	{ return iso::writen(w, p, curr_size); }
	friend size_t num_elements(const ptr_array &t)	{ return t.size();	}
};

template<typename T> ptr_array<T> make_ptr_array(T *p, size_t size) { return ptr_array<T>(p, size); }

template<typename T> class auto_array : public ptr_array<T> {
	typedef ptr_array<T>	B;
public:
	auto_array(T *_p, size_t _n) : B(_p, _n) {
		construct(_p, _n);
	}
	template<typename U> auto_array(T *_p, size_t _n, const U &t) : B(_p, _n) {
		construct(_p, _n, t);
	}
	~auto_array() {
		destruct(B::p, B::curr_size);
	}
};

#define new_auto(T,N)	auto_array<T>(alloc_auto(T, N), N)

//-----------------------------------------------------------------------------
//	trailing_array
//-----------------------------------------------------------------------------

template<typename B, typename M> struct trailing_array {
	struct B2 : B { M array[0]; };
	typedef M			element;
	typedef M*			iterator;
	typedef const M*	const_iterator;

	static size_t	calc_size(uint32 n)			{ return (size_t)&(((B2*)1)->array[n]) - 1; }
	static size_t	calc_size(size_t s, uint32 n)	{ return calc_size(n) + s - sizeof(B); }
	M&				array(int i)				{ return static_cast<B2*>(this)->array[i];	}
	const M&		array(int i)		const	{ return static_cast<const B2*>(this)->array[i]; }
	M&				operator[](int i)			{ return array(i);	}
	const M&		operator[](int i)	const	{ return array(i);	}
	iterator		begin()						{ return &array(0);	}
	const_iterator	begin()				const	{ return &array(0);	}
	iterator		end(uint32 n)				{ return &array(n);	}
	const_iterator	end(uint32 n)		const	{ return &array(n);	}

	constexpr trailing_array()								{}
	trailing_array(uint32 n) {
		construct(begin(), n);
	}
	template<typename C> trailing_array(C &&c, typename T_enable_if<!T_isint<C>::value, void*>::type *x = 0) {
		construct_it(begin(), num_elements(c), iso::begin(c));
	}

	void*						operator new(size_t s, uint32 n)			{ return ::operator new(calc_size(s, n)); }
	void						operator delete(void *p, size_t, uint32)	{ ::operator delete(p); }
	template<typename T> static void*	alloc(size_t s, T &t, uint32 n)		{ return t.alloc(calc_size(s, n), T_alignment<B>::value); }
	template<typename T> void*	operator new(size_t s, uint32 n, T &t)		{ return alloc(s, t, n); }
};

//-----------------------------------------------------------------------------
//	class dynamic_array
//-----------------------------------------------------------------------------

template<typename T> class dynamic_array;
template<typename T, typename C> inline dynamic_array<T>& _assign(dynamic_array<T> &a, const C &c);

template<typename T> class dynamic_array : public ptr_array<T> {
	typedef	ptr_array<T>	B;
	using	B::p;
	using	B::curr_size;

	size_t	max_size;

public:
	using typename B::value;
	using typename B::iterator;
	using typename B::const_iterator;

	dynamic_array()				: max_size(0)	{}
	dynamic_array(_none&)		: max_size(0)	{}
	dynamic_array(size_t n)											: B(allocate<T>(n), n), max_size(n) { construct(p, curr_size); }
	dynamic_array(const dynamic_array &c)							: B(allocate<T>(c.size()), c.size()), max_size(c.size()) { construct_it(p, curr_size, c.begin()); }
	template<typename C> dynamic_array(const dynamic_array<C> &c)	: B(allocate<T>(c.size()), c.size()), max_size(c.size()) { construct_it(p, curr_size, c.begin()); }
	template<typename U> dynamic_array(size_t n, const U &t)		: B(allocate<T>(n), n), max_size(n) { construct(p, curr_size, t); }
	template<typename C> dynamic_array(const C &c, typename T_enable_if<!T_isint<C>::value, void*>::type *x = 0) : B(num_elements(c)) {
		construct_it(p = allocate<T>(max_size = curr_size), curr_size, iso::begin(c));
	}
	template<typename I> dynamic_array(I first, I last, typename T_enable_if<!T_isint<I>::value>::type *dummy = 0) : B(distance(first, last)) {
		construct_it(p = allocate<T>(max_size = curr_size), curr_size, first);
	}
	template<typename C> dynamic_array &operator=(const C &c)		{ return _assign(*this, c); }
	dynamic_array&	operator=(const dynamic_array &b)				{ return _assign(*this, b); }
#ifdef USE_RVALUE_REFS
	dynamic_array(dynamic_array &&c)								: B(c), max_size(c.max_size) { c.p = 0; c.curr_size = 0; }
	dynamic_array&	operator=(dynamic_array &&c)					{ max_size = c.max_size; swap(p, c.p); swap(curr_size, c.curr_size); return *this; }
	template<typename C> dynamic_array(C &&c, typename T_enable_if<!T_isint<C>::value, void*>::type *x = 0) : B(num_elements(c)) {
		construct_it(p = allocate<T>(max_size = curr_size), curr_size, iso::begin(c));
	}
	template<typename U, size_t N> dynamic_array(U (&&c)[N]) : B(N) {
		construct_it(p = allocate<T>(max_size = curr_size), curr_size, make_move_iterator(&c[0]));
	}
	template<typename U, size_t N> dynamic_array&	operator=(U (&&c)[N]) {
		return assign(make_move_iterator(&c[0]), make_move_iterator(&c[N]));
	}
#endif

	~dynamic_array()	{
		if (p) {
			destruct(p, curr_size);
			deallocate(p, max_size);
		}
	}

	void			reserve(size_t i) {
		if (i > max_size)
			p = reallocate(p, curr_size, max_size = i);
	}
	void			resize(size_t i) {
		reserve(i);
		if (i < curr_size)
			destruct(p + i, curr_size - i);
		else if (i > curr_size)
			construct(p + curr_size, i - curr_size);
		curr_size = i;
	}
	void			resize(size_t i, const T &t) {
		reserve(i);
		if (i < curr_size)
			destruct(p + i, curr_size - i);
		else if (i > curr_size)
			construct(p + curr_size, i - curr_size, t);
		curr_size = i;
	}
	T*				_expand() {
		if (curr_size == max_size)
			reserve(max_size ? max_size * 2 : 16);
		return p + curr_size++;
	}
	T*				_expand(size_t n) {
		if (curr_size + n > max_size)
			reserve(max(curr_size + n, max_size ? max_size * 2 : 16));
		T	*r = p + curr_size;
		curr_size += n;
		return r;
	}
	iterator		expand()				{ return new(_expand()) T;	}
	iterator		expand(size_t n)		{ T *t = _expand(n); construct(t, n); return t; }

	iterator		insert(iterator iter)	{
		size_t	back	= B::end() - iter;
		return new(B::_insert(_expand(), back)) T;
	}
	iterator		insert(iterator iter, const T &t) {
		int		i		= this->index_of(t);
		size_t	back	= B::end() - iter;
		return new(B::_insert(_expand(), back)) T(i >= 0 && i < curr_size - 1 ? p[i + int(&t >= iter)] : t);
	}
	template<typename U> iterator insert(iterator iter, const U &t)	{
		size_t	back	= B::end() - iter;
		return new(B::_insert(_expand(), back)) T(t);
	}

	template<typename I> iterator insert(iterator iter, I first, I last) {
		ISO_ASSERT(B::contains(iter));
		size_t	back	= B::end() - iter;
		reserve(curr_size + distance(first, last));
		return B::_insert(back, first, last);
	}

	template<typename I> dynamic_array &append(I first, I last) {
		for (T *dest = _expand(distance(first, last)); first != last; ++first, ++dest)
			new(dest) T(*first);
		return *this;
	}

	template<typename C> dynamic_array &append(const C &c)		{ return append(iso::begin(c), iso::end(c));	}
	template<typename I> dynamic_array &assign(I first, I last)	{ clear(); return append(first, last);			}

	size_t					capacity()		const		{ return max_size; }
	void					clear()						{ destruct(p, curr_size); curr_size = 0; }
	void					reset()						{ clear(); deallocate(p, max_size); max_size = 0; p = 0; }
	T&						set(int i)					{ if (i >= curr_size) resize(i + 1); return (*this)[i]; }

#ifdef USE_RVALUE_REFS
	template<typename U>	T& push_back(U &&t)			{ return *new(_expand()) T(forward<U>(t)); }
	template<typename... U>	T& emplace_back(U&&...t)	{ return *new(_expand()) T(forward<U>(t)...); }
#else
	template<typename U>	T& push_back(const U &t)	{ return *new(_expand()) T(t); }
#endif
	T&						push_back()					{ return *new(_expand()) T; }
	void					pop_back()					{ destruct(p + --curr_size, 1); }
	value					pop_back_value()			{ value t = move(B::back()); pop_back(); return t; }
	T&						pop_back_retref()			{ return p[--curr_size]; }

	void*					alloc(size_t s, size_t a)	{ ISO_ASSERT(s == sizeof(T) && (uintptr_t(p) & (a-1)) == 0); return _expand(); }

	template<typename R> bool	read(R &r, size_t n)	{ resize(n); return readn(r, this->begin(), n); }

	friend void 	swap(dynamic_array<T> &a, dynamic_array<T> &b) {
		swap(a.curr_size, b.curr_size);
		swap(a.max_size, b.max_size);
		swap(a.p, b.p);
	}
};
	
template<typename T, typename C> inline dynamic_array<T>& _assign(dynamic_array<T> &a, const C &c)	{ return a.assign(begin(c), end(c)); }

//-----------------------------------------------------------------------------
//	class circular_buffer
//-----------------------------------------------------------------------------

template<typename I> struct wrap_iterator {
	I	i;
	const I	b, e;
	wrap_iterator(I _i, I _b, I _e) : i(_i), b(_b), e(_e) {}
	wrap_iterator&	operator++()	{ if (++i == e) i = b; return *this; }
	wrap_iterator&	operator--()	{ if (i == b) i = e; --i; return *this; }
	operator I() const				{ return i; }
};

template<typename T, class I = T*> class circular_buffer {
	I			a, b, g;
	int			num;
public:
	typedef wrap_iterator<I>			iterator;
	typedef wrap_iterator<const I>		const_iterator;

	void set_get(I i) {
		g = i;
	}

	T	*put(int n) {
		I	*p = wrap(g + num, a, b);
		if (p + n > b) {
			if (a + n > g)
				return 0;
			num = b - g;
			p	= a;
		}
		num += n;
		return p;
	}

	circular_buffer(I _a, I _b)					{ init(_a, _b); }
	circular_buffer(I _a, int n)				{ init(_a, _a + n); }
	template<typename C> circular_buffer(C &c)	{ init(iso::begin(c), iso::end(c)); }

	void			init(I _a, I _b)		{ g = a = _a; b = _b; num = 0; }
	void			init(I _a, int n)		{ Init(_a, _a + n); }
	void			reset()					{ num = 0; }

	I				get_buffer()	const	{ return a; }
	size_t			capacity()		const	{ return b - a;	}
	int				size()			const	{ return num; }
	size_t			space()			const	{ return capacity() - size(); }
	int				linear_space()	const	{ return (b - (g + num > b ? a : g)) - num; }
	bool			empty()			const	{ return num == 0; }
	bool			full()			const	{ return size() == capacity(); }

	const T&		operator[](int i)const	{ ISO_ASSERT(i < num); return *wrap(g + i, a, b);	}
	const T&		front()			const	{ ISO_ASSERT(num); return *g;						}
	const T&		back()			const	{ ISO_ASSERT(num); return *wrap(g + num - 1, a, b);	}
	T&				operator[](int i)		{ ISO_ASSERT(i < num); return *wrap(g + i, a, b);	}
	T&				front()					{ ISO_ASSERT(num); return *g;						}
	T&				back()					{ ISO_ASSERT(num); return *wrap(g + num - 1, a, b);	}

	const_iterator	begin()			const	{ return const_iterator(g, a, b);					}
	const_iterator	end()			const	{ return const_iterator(wrap(g + num, a, b), a, b);	}
	iterator		begin()					{ return iterator(g, a, b);							}
	iterator		end()					{ return iterator(wrap(g + num, a, b), a, b);		}

	bool	push_back(const T &t) {
		if (full())
			return false;
		*wrap(g + num++, a, b) = t;
		return true;
	}
	T&		push_back() {
		ISO_ASSERT(!full());
		return *wrap(g + num++, a, b);
	}
	void	pop_front() {
		ISO_ASSERT(num);
		--num;
		if (++g == b)
			g = a;
	}
};

//-----------------------------------------------------------------------------
//	class dynamic_circular_buffer
//-----------------------------------------------------------------------------

template<typename T> class dynamic_circular_buffer : public ptr_array<T> {
	typedef ptr_array<T>	B;
	using B::p;
	using B::curr_size;

	size_t		max_size, offset;
	size_t		wrap(size_t i)		const { size_t j = i + offset; return j < max_size ? j : j - max_size; }
	size_t		unwrap(size_t i)	const { return i < offset ? i + max_size - offset : i - offset; }
public:
	typedef wrap_iterator<T*>			iterator;
	typedef wrap_iterator<const T*>		const_iterator;

	dynamic_circular_buffer() : max_size(0), offset(0)	{}
#ifdef USE_RVALUE_REFS
	dynamic_circular_buffer(dynamic_circular_buffer &&c) : B(c), max_size(c.max_size), offset(c.offset) { c.p = 0; }
	dynamic_circular_buffer& operator=(dynamic_circular_buffer &&c) { max_size = c.max_size; offset = c.offset; swap(p, c.p); return *this; }
#endif

	~dynamic_circular_buffer()	{
		destruct(p, curr_size);
		deallocate(p, max_size);
	}

	void			reserve(size_t i) {
		if (i > max_size) {
			size_t	o = offset;
			size_t	m = curr_size;
			T		*p0	= p;
			if (o == 0) {
				m		= 0;
			} else if (curr_size + o > max_size) {
				m		= max_size - o;
				offset	= i - m;
			}
			size_t	k = curr_size - m;
			max_size = i;
			if (resize(p0, k, i)) {
				move(p0 + o, p0 + offset, m);
			} else {
				p = reallocate_move(p0, k, i);
				move(p0 + o, p + offset, m);
			}
		}
	}

	T*				_expand(bool front = false) {
		if (curr_size == max_size)
			reserve(max_size ? max_size * 2 : 16);
		++curr_size;
		if (front) {
			offset = (offset == 0 ? max_size : offset) - 1;
			return p + offset;
		}
		return p + wrap(curr_size - 1);
	}
	T*				_expand(size_t n, bool front = false) {
		if (curr_size + n > max_size)
			reserve(max(curr_size + n, max_size ? max_size * 2 : 16));
		T	*r = p + curr_size;
		curr_size += n;
		if (front) {
			offset = (offset == 0 ? max_size : offset) - n;
			return p + offset;
		}
		return r;
	}
	int				index_of(const T *e)		const	{ return e ? unwrap(e - p) : -1;}
	int				index_of(const T &e)		const	{ return unwrap(&e - p);		}

	const T&		front()						const	{ return p[offset];				}
	const T&		back()						const	{ return p[wrap(curr_size - 1)];}
	const T&		at(size_t i)				const	{ return p[wrap(i)];			}
	const T&		operator[](size_t i)		const	{ return at(i);					}
	
	T&				front()								{ return p[offset];				}
	T&				back()								{ return p[wrap(curr_size - 1)];}
	T&				at(size_t i)						{ return p[wrap(i)];			}
	T&				operator[](size_t i)				{ return at(i);					}

	const_iterator			begin()				const	{ return const_iterator(p + offset, p, p + max_size);			}
	const_iterator			end()				const	{ return const_iterator(p + wrap(curr_size), p, p + max_size);	}
	iterator				begin()						{ return iterator(p + offset, p, p + max_size);					}
	iterator				end()						{ return iterator(p + wrap(curr_size), p, p + max_size);		}

	size_t					capacity()			const	{ return max_size;				}
	void					clear()						{ destruct(p + offset, min(curr_size, max_size - offset)); if (offset + curr_size > max_size) destruct(0, offset + curr_size - max_size); offset = curr_size = 0;	}
	void					reset()						{ clear(); deallocate(p, max_size); max_size = 0; p = 0; }

	template<typename U>	T& push_back(const U &t)	{ return *new(_expand(false)) T(t);	}
	T&						push_back()					{ return *new(_expand(false)) T;	}
	void					pop_back()					{ destruct(p + --curr_size, 1);		}
	T						pop_back_value()			{ T t = back(); pop_back(); return t; }

	template<typename U>	T& push_front(const U &t)	{ return *new(_expand(true)) T(t);	}
	T&						push_front()				{ return *new(_expand(true)) T;		}
	void					pop_front()					{ destruct(p + --curr_size, 1);		}
	T						pop_front_value()			{ T t = back(); pop_front(); return t; }

	iterator		insert(iterator iter)	{
		size_t	back	= B::end() - iter;
		return new(B::_insert(_expand(false), back)) T;
	}
	iterator		insert(iterator iter, const T &t) {
		int		i		= B::index_of(t);
		size_t	back	= B::end() - iter;
		return new(B::_insert(_expand(false), back)) T(i >= 0 && i < curr_size - 1 ? p[i + int(&t >= iter)] : t);
	}
	template<typename U> iterator insert(iterator iter, const U &t)	{
		size_t	back	= B::end() - iter;
		return new(_insert(_expand(false), back)) T(t);
	}

	template<typename I> iterator insert(iterator iter, I first, I last) {
		ISO_ASSERT(B::contains(iter));
		size_t	back	= B::end() - iter;
		reserve(curr_size + distance(first, last));
		return _insert(back, first, last);
	}

	template<typename I> dynamic_circular_buffer &append(I first, I last) {
		for (T *dest = _expand(false, distance(first, last)); first != last; ++first, ++dest)
			new(dest) T(*first);
		return *this;
	}
	template<typename I> dynamic_circular_buffer &prepend(I first, I last) {
		for (T *dest = _expand(true, distance(first, last)); first != last; ++first, ++dest)
			new(dest) T(*first);
		return *this;
	}

	template<typename C> dynamic_circular_buffer &append(const C &c)		{ return append(iso::begin(c), iso::end(c));	}
	template<typename C> dynamic_circular_buffer &prepend(const C &c)		{ return prepend(iso::begin(c), iso::end(c));	}
	template<typename I> dynamic_circular_buffer &assign(I first, I last)	{ clear(); return append(first, last);			}
	template<typename C> dynamic_circular_buffer &operator=(const C &c)		{ return assign(iso::begin(c), iso::end(c));	}
	dynamic_circular_buffer	&operator=(const dynamic_circular_buffer &b)	{ return assign(b.begin(), b.end());			}


	friend void 	swap(dynamic_circular_buffer<T> &a, dynamic_circular_buffer<T> &b) {
		swap(a.offset, b.offset);
		swap(a.curr_size, b.curr_size);
		swap(a.max_size, b.max_size);
		swap(a.p, b.p);
	}
};

//-----------------------------------------------------------------------------
//	class safe_array - entries never get relocated
//-----------------------------------------------------------------------------

template<typename T> class safe_array {
	int			curr_size;
	int			curr_depth;
	void*		p;

	static inline int	depth0(int i)	{ return i < 32 ? 0 : i < 32 * 32 ? 1 : 2; }
	static inline int	depth(int i)	{ return i < 32 * 32 * 32 ? depth0(i) : depth0(i & (32 * 32 * 32 - 1)) + 3; }

	static inline void*	newblock1() {
		void *b = malloc(32 * sizeof(void*));
		memset(b, 0, 32 * sizeof(void*));
		return b;
	}

	static inline void*	newblock(int d)	{
		if (d)
			return newblock1();
		T	*b = allocate<T>(32);
		construct(b, 32);
		return b;
	}

	static void	freeblock(void *b, int d) {
		if (d == 0) {
			destruct((T*)b, 32);
			deallocate((T*)b, 32);
		} else {
			for (int i = 0; i < 32; i++) {
				if (void *p = ((void**)b)[i])
					freeblock(p, d - 1);
			}
			free(b);
		}
	}

	static void *expanddepth(void *b, int n) {
		while (n--) {
			void	*b0 = newblock1();
			*(void**)b0	= b;
			b			= b0;
		}
		return b;
	}

	T	*get(int i) {
		void *p0 = p;
		if (p0) {
			for (int dc = curr_depth; dc; dc--) {
				int		i0	= (i >> (dc * 5)) & 31;
				void	*p1 = ((void**)p0)[i0];
				p0 = p1 ? p1 : (((void**)p0)[i0] = newblock(dc - 1));
			}
		} else {
			p0 = p = newblock(0);
		}
		return ((T*)p0) + (i & 31);
	}

	const T	*get(int i) const {
		void *p0 = p;
		for (int dc = curr_depth; dc; dc--)
			p0 = ((void**)p0)[(i >> (dc * 5)) & 31];
		return ((T*)p0) + (i & 31);
	}

	void resize(int i) {
		if (int n = depth(i - 1) - curr_depth) {
			p = expanddepth(p, n);
			curr_depth += n;
		}
		curr_size = i;
	}

public:
	typedef	T									element, &reference;
	typedef	indexed_iterator<safe_array<T>, int_iterator<int> >			iterator;
	typedef	indexed_iterator<const safe_array<T>, int_iterator<int> >	const_iterator;

	safe_array() : curr_size(0), curr_depth(0), p(0)	{}
	~safe_array()								{ if (p) freeblock(p, curr_depth); }
	T				&operator[](int i)			{ if (i >= curr_size) resize(i + 1); return *get(i); }
	const T			&operator[](int i) const	{ return *get(i); }

	size_t					size()		const	{ return curr_size;							}
	void					clear()				{ if (p) {freeblock(p, curr_depth); p = 0; curr_size = curr_depth = 0; } }
	bool					empty()		const	{ return curr_size == 0;					}

	T*						expand(int n = 1)	{ int i = curr_size; resize(i + n); return get(i); }
	template<typename U>void operator+=(U t)	{ (*this)[curr_size] = t;					}
	template<typename U>void push_back(U t)		{ (*this)[curr_size] = t;					}
	void					pop_back()			{ return *get(--curr_size);					}
	T&						front()				{ return (*this)[0];						}
	T&						back()				{ return (*this)[curr_size - 1];			}

	const_iterator			begin()		const	{ return const_iterator(*this, 0);			}
	const_iterator			end()		const	{ return const_iterator(*this, curr_size);	}
	iterator				begin()				{ return iterator(*this, 0);				}
	iterator				end()				{ return iterator(*this, curr_size);		}
};

//-----------------------------------------------------------------------------
//	hierarchy_traverser
//-----------------------------------------------------------------------------

template<typename C> struct hierarchy_traverser {
	typedef typename container_traits<C>::iterator	I;
	struct entry {
		C		c;
		I		i, e;
		bool	started;
		template<typename C2> entry(C2 &&_c) : c(forward<C2>(_c)), i(c.begin()), e(c.end()), started(false) {}
		bool	next() {
			if (!started) {
				started = true;
				return false;
			}
			return ++i == e;
		}
	};
	dynamic_array<entry>	stack;

	bool		next()	{
		while (stack.back().next()) {
			stack.pop_back();
			if (stack.empty())
				return true;
		}
		return false;
	}

	struct iterator {
		hierarchy_traverser	*h;
		typedef typename iterator_traits<I>::element	element;
		typedef typename iterator_traits<I>::reference	reference;

		iterator(hierarchy_traverser *_h) : h(_h) {}
		reference	operator*()						const	{ return *h->stack.back().i; }
		iterator&	operator++()							{ if (h->next()) h = 0; return *this; }
		bool		operator==(const iterator &b)	const	{ return h == b.h; }
		bool		operator!=(const iterator &b)	const	{ return h != b.h; }
	};

	template<typename C2> hierarchy_traverser(C2 &&c) {
		stack.push_back(forward<C2>(c));
		stack.back().started = true;
	}
	iterator	begin() { return this; }
	iterator	end()	{ return 0; }

	template<typename C2> void push(C2 &&c) {
		stack.push_back(forward<C2>(c));
	}
	const C&	top() const {
		return stack.back().c;
	}
};

template<typename C> hierarchy_traverser<typename T_noref<C>::type> make_hierarchy_traverser(C &&c) { return forward<C>(c); }


}//namespace iso

//-----------------------------------------------------------------------------
//	global functions
//-----------------------------------------------------------------------------

// need to be global for some reason
template<typename T, int N> inline void *operator new(size_t size, iso::array<T,N> &a)			{ T *p = a.expand(); p->~T(); return p; }
template<typename T, int N> inline void operator delete(void *p, iso::array<T,N> &a)			{}
template<typename T, int N> inline void *operator new[](size_t size, iso::array<T,N> &a)		{ ISO_ASSERT(size % sizeof(T) == 0); return a.expand(size / sizeof(T)); }
template<typename T, int N> inline void operator delete[](void *p, iso::array<T,N> &a)			{}

template<typename T> inline void *operator new(size_t size, iso::dynamic_array<T> &a)			{ return a._expand(size / sizeof(T)); }
template<typename T> inline void operator delete(void *p, iso::dynamic_array<T> &a)				{}
template<typename T> inline void *operator new[](size_t size, iso::dynamic_array<T> &a)			{ ISO_ASSERT(size % sizeof(T) == 0); return a._expand(size / sizeof(T)); }
template<typename T> inline void operator delete[](void *p, iso::dynamic_array<T> &a)			{}

template<typename T> inline void *operator new(size_t size, iso::circular_buffer<T> &a)			{ return a.put(iso::div_round_up(size, sizeof(T))); }
template<typename T> inline void operator delete(void *p, iso::circular_buffer<T> &a)			{}
template<typename T> inline void *operator new[](size_t size, iso::circular_buffer<T> &a)		{ return a.put(iso::div_round_up(size, sizeof(T))); }
template<typename T> inline void operator delete[](void *p, iso::circular_buffer<T> &a)			{}

template<typename T> inline void *operator new(size_t size, iso::dynamic_circular_buffer<T> &a, bool front = false)		{ return a._expand(size / sizeof(T), front); }
template<typename T> inline void operator delete(void *p, iso::dynamic_circular_buffer<T> &a, bool front)				{}
template<typename T> inline void *operator new[](size_t size, iso::dynamic_circular_buffer<T> &a, bool front = false)	{ ISO_ASSERT(size % sizeof(T) == 0); return a._expand(size / sizeof(T), front); }
template<typename T> inline void operator delete[](void *p, iso::dynamic_circular_buffer<T> &a, bool front)				{}

template<typename T> inline void *operator new(size_t size, iso::safe_array<T> &a)				{ ISO_ASSERT(size == sizeof(T)); return a.expand(); }
template<typename T> inline void operator delete(void *p, iso::safe_array<T> &a)				{}
template<typename T> inline void *operator new[](size_t size, iso::safe_array<T> &a)			{ ISO_ASSERT(size % sizeof(T) == 0); return a.expand(size / sizeof(T)); }
template<typename T> inline void operator delete[](void *p, iso::safe_array<T> &a)				{}

#endif //ARRAY_H
