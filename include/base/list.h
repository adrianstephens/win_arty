#ifndef LIST_H
#define LIST_H

#include "defs.h"

namespace iso {

//-----------------------------------------------------------------------------
// double linked list
//-----------------------------------------------------------------------------
template<typename T, typename L=T> struct link_base {
	union {
		struct { T *prev, *next; };
		T	*link[2];
	};
	void	join(L *link)				{ next = static_cast<T*>(link); link->prev = static_cast<T*>(this); }
	void	insert_after(L *link)		{ link->join(static_cast<L*>(next)); join(link); }
	void	insert_before(L *link)		{ static_cast<L*>(prev)->join(link); link->join(static_cast<L*>(this)); }
	void	insert_after(L *a, L *b)	{ b->join(next); join(a); }
	void	insert_before(L *a, L *b)	{ prev->join(a); b->join(static_cast<L*>(this)); }
	void	unlink()					{ static_cast<L*>(prev)->join(next); next = 0; }
	void	unlink(L *to)				{ static_cast<L*>(prev)->join(to); }
	void	init()						{ prev = next = static_cast<T*>(this);	}
};

template<typename T, typename L, typename L2> class list_iterator_base {
	L				*p;
public:
	typedef bidirectional_iterator_t iterator_category;
	typedef T		element, *pointer, &reference;

	list_iterator_base(L *_p = 0) : p(_p)	{}
						operator T*()			const	{ return ((L2*)p)->data();	}
//	T&					operator*()				const	{ return *((L2*)p)->data();	}
	T*					operator->()			const	{ return ((L2*)p)->data();	}
	L*					link()					const	{ return p;	}
	list_iterator_base&	operator++()					{ p = ((L2*)p)->next; return *this;	}
	list_iterator_base	operator++(int)					{ list_iterator_base i = *this; p = ((L2*)p)->next; return i; }
	list_iterator_base&	operator--()					{ p = ((L2*)p)->prev; return *this;	}
	list_iterator_base	operator--(int)					{ list_iterator_base i = *this; p = ((L2*)p)->prev; return i; }
	list_iterator_base& operator+=(int i)				{ while (i--) p = ((L2*)p)->next; return *this; }
	list_iterator_base& operator-=(int i)				{ while (i--) p = ((L2*)p)->prev; return *this; }
	bool				operator==(const list_iterator_base &b) const { return p == b.p; }
	bool				operator!=(const list_iterator_base &b) const { return p != b.p; }

	//prevent pointer arithmetic
	template<typename I> list_iterator_base	operator+(I i) const { return list_iterator_base(*this) += i; }
	template<typename I> list_iterator_base	operator-(I i) const { return list_iterator_base(*this) -= i; }

	void	insert_after(list_iterator_base i)	{ i.p->unlink(); p->insert_after(i.p); }
	void	insert_before(list_iterator_base i)	{ i.p->unlink(); p->insert_before(i.p); }
	void	insert_after(list_iterator_base b, list_iterator_base e) {
		if (e != b) {
			L	*ep	= e.p->prev;
			b.p->unlink(ep);
			p->insert_after(b.p, ep);
		}
	}

	void	insert_before(list_iterator_base b, list_iterator_base e) {
		if (e != b) {
			L	*ep	= e.p->prev;
			b.p->unlink(ep);
			p->insert_before(b.p, ep);
		}
	}
	L2		*remove() {
		L2	*i = (L2*)p;
		p = i->next;
		i->unlink();
		return i;
	}
};

template<typename T, typename L, typename L2=L> class list_base {
protected:
	link_base<L, L2>	head;
	void				reset()		{ head.init(); }
public:
	typedef T												element, &reference;
	typedef list_iterator_base<T, L, L2>					iterator;
	typedef list_iterator_base<const T, const L, const L2>	const_iterator;

	list_base()						{ head.init(); }
#ifdef USE_RVALUE_REFS
	list_base(list_base &&b) {
		if (b.empty()) {
			reset();
		} else {
			head = b.head;
			head.next->prev = head.prev->next = static_cast<L*>(&head);
			b.reset();
		}
	}
	void operator=(list_base &&b) {
		if (b.empty()) {
			reset();
		} else {
			head = b.head;
			head.next->prev = head.prev->next = static_cast<L*>(&head);
			b.reset();
		}
	}
#else
	list_base(list_base &b)	{
		if (b.empty()) {
			head.init();
		} else {
			head = b.head;
			head.next->prev = head.prev->next = static_cast<L*>(&head);
			b.head.init();
		}
	}
	void operator=(list_base &b) {
		if (b.empty()) {
			head.init();
		} else {
			head = b.head;
			head.next->prev = head.prev->next = static_cast<L*>(&head);
			b.head.init();
		}
	}
#endif

	list_base(iterator begin, iterator end) {
		L	*b = begin.link(), *e = end.link();
		head.next		= b;
		head.prev		= e->prev;
		b->prev->next	= e;
		e->prev			= b->prev;
		head.next->prev = head.prev->next = static_cast<L*>(&head);
	}

	const_iterator	begin()		const		{ return head.next;						}
	const_iterator	end()		const		{ return static_cast<const L*>(&head);	}
	iterator		begin()					{ return head.next;						}
	iterator		end()					{ return static_cast<L*>(&head);		}
	const T&		front()		const		{ return *head.next->data();			}
	const T&		back()		const		{ return *head.prev->data();			}
	T&				front()					{ return *head.next->data();			}
	T&				back()					{ return *head.prev->data();			}
	bool			empty()		const		{ return begin() == end();				}
	size_t			size()		const;
	uint32			size32()	const		{ return uint32(size()); }
	bool			verify()	const;
	T&				operator[](int i)		{ return *(begin() += i); }
	const T&		operator[](int i) const	{ return *(begin() += i); }

	void			append(list_base &&b)	{ end().insert_before(b.begin(), b.end()); b.reset(); }
	void			prepend(list_base &&b)	{ begin().insert_before(b.begin(), b.end()); b.reset(); }

	void swap(list_base &b) {
		link_base<L, L2>	ahead = head;

		if (b.empty()) {
			head.init();
		} else {
			head = b.head;
			head.next->prev = head.prev->next = static_cast<L*>(&head);
		}
		if (ahead.next == static_cast<const L*>(&head)) {
			b.head.init();
		} else {
			b.head = ahead;
			ahead.next->prev = ahead.prev->next = static_cast<L*>(&b.head);
		}
	}
};

template<typename T, typename L, typename L2> size_t list_base<T,L,L2>::size() const {
	size_t	size = 0;
	for (const_iterator	i = begin(), e = end(); i != e; ++i)
		++size;
	return size;
}

template<typename T, typename L, typename L2> bool list_base<T,L,L2>::verify() const {
	if (head.next->prev != static_cast<const L*>(&head) || head.prev->next != static_cast<const L*>(&head))
		return false;

	for (const_iterator	i = begin(); i != end(); ) {
		const_iterator	p = i, n = ++i;
		if (p != --n)
			return false;
	}
	return true;
}

template<typename T> struct e_link : public link_base<T, e_link<T> > {
	typedef link_base<T, e_link<T> >	B;
	typedef T							element;
	e_link()								{ B::next = 0;					}
	~e_link()								{ if (B::next) B::unlink();		}
	bool			is_linked()	const		{ return B::next != 0;			}
	T*				unlink()				{ B::unlink(); B::next = 0; return static_cast<T*>(this); }
	void			unlink(e_link *to)		{ B::unlink(to); }
	const T*		data()		const		{ return static_cast<const T*>(this);	}
	T*				data()					{ return static_cast<T*>(this);			}
};

template<typename T> class e_list : public list_base<T, T, e_link<T> > {
	typedef list_base<T, T, e_link<T> >	B;
public:
	using typename B::iterator;
	e_list()								{}
#ifdef USE_RVALUE_REFS
	e_list(e_list &&b) : B(move(b))			{}
	void			operator=(e_list &&b)	{ removeall(); B::operator=(move(b)); }
#else
	e_list(e_list &b) : B(b)				{}
	void			operator=(e_list &b)	{ removeall(); B::operator=(b);		}
#endif
	e_list(iterator begin, iterator end) : B(begin, end)	{}
					~e_list()				{ removeall();	}
	void			push_front(T *t)		{ B::head.insert_after(t);			}
	void			push_back(T *t)			{ B::head.insert_before(t);			}
	void			push_front(const T &t)	{ push_front(new T(t));				}
	void			push_back(const T &t)	{ push_back(new T(t));				}
	T*				pop_front()				{ return static_cast<e_link<T>*>(B::head.next)->unlink(); }
	T*				pop_back()				{ return static_cast<e_link<T>*>(B::head.prev)->unlink(); }
	void			removeall()				{ while (!B::empty()) pop_back();	}
	void			deleteall()				{ while (!B::empty()) delete pop_back(); }
	static T*		remove(T *t)			{ return t->unlink();				}
	T*				tail()					{ return B::head.prev;				}

	friend void swap(e_list &a, e_list &b)	{ a.swap(b); }
};

template<typename T> struct link : public link_base<link<T> > {
	typedef link_base<link<T> >			B;
	typedef T							element;
	T				t;
	link(const T &_t) : t(_t)				{}
	link*			unlink()				{ B::unlink(); return this; }
	const T*		data()		const		{ return &t; }
	T*				data()					{ return &t; }
};

template<typename T> class list : public list_base<T, link<T> > {
	typedef list_base<T, link<T> >	B;
public:
	using typename B::iterator;
	list()									{}
#ifdef USE_RVALUE_REFS
	list(list &&b) : B(move(b))				{}
	void			operator=(list &&b)		{ removeall(); B::operator=(move(b)); }
#else
	list(list &b) : B(b)					{}
	void			operator=(list &b)		{ removeall(); B::operator=(b); }
#endif
	list(iterator begin, iterator end) : B(begin, end)	{}
	~list()									{ removeall();	}
	void			push_front(const T &t)	{ B::head.insert_after( new link<T>(t));	}
	void			push_back(const T &t)	{ B::head.insert_before(new link<T>(t));	}
	void			pop_front()				{ delete B::head.next->unlink();			}
	void			pop_back()				{ delete B::head.prev->unlink();			}
	void			removeall()				{ while (!B::empty()) pop_back();			}
	bool			empty()		const		{ return B::empty();						}
	
	void			remove(iterator &i)	{ delete i.remove(); }
	void			insert_before(iterator &i, const T &t)	{ i.link()->insert_before(new link<T>(t)); }
	void			insert_after(iterator &i, const T &t)	{ i.link()->insert_after( new link<T>(t)); }

	friend void swap(list &a, list &b)		{ a.swap(b); }
};

template<typename T, typename L, typename L2, class P> void sort(list_iterator_base<T,L,L2> lo, list_iterator_base<T,L,L2> hi, P comp) {
	--lo;
	for (int chunk = 1;; chunk <<= 1) { // For each power of two
		int	num_merges = 0;

		for (list_iterator_base<T,L,L2> i = lo, r = ++i; i != hi; i = r) {
			num_merges++;
			// Find next sublist
			for (int n = chunk; n-- && r != hi; ++r);

			// Merge two sublists
			int	nl = chunk, nr = chunk;
			while (nl && nr && r != hi) {
				if (comp(*r, *i)) {
					i.insert_before(r++);
					--nr;
				} else {
					++i;
					--nl;
				}
			}
			while (nr-- && r != hi)
				++r;
		}
		if (num_merges < 2)
			break;
	}
}

//-----------------------------------------------------------------------------
// single linked list
//-----------------------------------------------------------------------------

template<typename T> struct slink_base {
	T		*next;
	void	insert_after(T *link)		{ link->next = next; next = link; }
	void	insert_after(T *a, T *b)	{ b->next = next; next = a; }
	T*		unlink_next()				{ T *n = next; next = n->next; n->next = 0; return n; }
	T*		unlink(T *t)				{ T *n = next; next = t->next; n->next = 0; return n; }
	void	init()						{ next = static_cast<T*>(this); }
};

// points to current element for efficiency
template<typename T, typename L> class slist_iterator_base {
protected:
	L		*p;
public:
	typedef forward_iterator_t		iterator_category;
	typedef T						element, *pointer, &reference;

	slist_iterator_base(L *_p) : p(_p)	{}
							operator T*()			const	{ return p->data(); }
//	T&						operator*()				const	{ return *p->data(); }
	T*						operator->()			const	{ return p->data(); }
	slist_iterator_base&	operator++()					{ p = p->next; return *this; }
	slist_iterator_base		operator++(int)					{ slist_iterator_base i = *this; p = p->next; return i; }
	slist_iterator_base&	operator+=(int i)				{ while (i--) p = p->next; return *this; }
	bool					operator==(const slist_iterator_base &b) const { return p == b.p; }
	bool					operator!=(const slist_iterator_base &b) const { return p != b.p; }
	L*						link()					const	{ return p; }

	//prevent pointer arithmetic
	template<typename I> slist_iterator_base	operator+(I i) const { return slist_iterator_base(*this) += i; }
};

// points to element before current one to allow for insertions/deletions
template<typename T, typename L> class slist_iterator_basep {
protected:
	L		*p;
public:
	typedef forward_iterator_t		iterator_category;
	typedef T						element, *pointer, &reference;

	explicit slist_iterator_basep(L *_p) : p(_p)	{}
	operator slist_iterator_base<T,L>()				const	{ return p->next; }
							operator T*()			const	{ return p->next->data(); }
//	T&						operator*()				const	{ return *p->next->data(); }
	T*						operator->()			const	{ return p->next->data(); }
	slist_iterator_basep&	operator++()					{ p = p->next; return *this; }
	slist_iterator_basep	operator++(int)					{ slist_iterator_basep i = *this; p = p->next; return i; }
	slist_iterator_basep&	operator+=(int i)				{ while (i--) p = p->next; return *this; }
	bool					operator==(const slist_iterator_basep<T,L> &b)	const { return uintptr_t(b.p) & 1 ? (uintptr_t(p->next) | 1) == uintptr_t(b.p) : p == b.p; }
	bool					operator!=(const slist_iterator_basep<T,L> &b)	const { return !(*this == b); }
	bool					operator==(const slist_iterator_base<T,L> &b)	const { return b == *this; }
	bool					operator!=(const slist_iterator_base<T,L> &b)	const { return b != *this; }

	//prevent pointer arithmetic
	template<typename I> slist_iterator_basep	operator+(I i) const { return slist_iterator_basep(*this) += i; }

	L*		unlink()										{ return p->unlink_next(); }

	void	insert_after(slist_iterator_basep i)			{ p->next->insert_after(i.unlink());			}
	void	insert_before(slist_iterator_basep i)			{ L *n = i.unlink(); p->insert_after(n); p = n;	}
	void	insert_after(slist_iterator_basep b, slist_iterator_basep e) {
		if (e.p != b.p)
			p->next->insert_after(b.p->unlink(e.p->next), e.p->next);
	}
	void	insert_before(slist_iterator_basep b, slist_iterator_basep e) {
		if (e.p != b.p)
			p->insert_after(b.p->unlink(e.p->next), e.p->next);
	}
};

template<typename T, typename L> class slist_base {
protected:
	slink_base<L>	head;
	L*				_back()			{ return prev(static_cast<const L*>(&head)); }
	const L*		_back()	const	{ return prev(static_cast<const L*>(&head)); }
	void			reset()			{ head.init(); }
public:
	typedef T										element, &reference;
	typedef slist_iterator_base<T, L>				iterator;
	typedef slist_iterator_base<const T, const L>	const_iterator;
	typedef slist_iterator_basep<T, L>				iteratorp;

	slist_base() { reset(); }
#ifdef USE_RVALUE_REFS
	slist_base(slist_base &&b) {
		head = b.head;
		b._back()->next = static_cast<L*>(&head);
		b.reset();
	}
#else
	slist_base(slist_base &b)	{
		head = b.head;
		b.back()->next = static_cast<L*>(&head);
		b.reset();
	}
#endif

	struct _insertable {
		typedef T							element, &reference;
		typedef slist_iterator_basep<T, L>	iterator, const_iterator;
		slist_base	&list;
		_insertable(slist_base &_list) : list(_list) {}
		iterator	begin()		const		{ return iterator(static_cast<L*>(&list.head)); }
		iterator	end()		const		{ return iterator((L*)(uintptr_t(static_cast<L*>(&list.head)) | 1)); }
	};
	
	L*				prev(const L *p)		{
		L *i = static_cast<L*>(&head);
		while (i->next != p) {
			i = i->next;
			if (i == static_cast<L*>(&head))
				return 0;
		}
		return i;
	}
	const L*		prev(const L *p) const	{
		const L *i = static_cast<const L*>(&head); 
		while (i->next != p) {
			i = i->next;
			if (i == static_cast<const L*>(&head))
				return 0;
		}
		return i;
	}

	size_t			size()		const;
	uint32			size32()	const		{ return uint32(size()); }
	bool			empty()		const		{ return head.next == static_cast<const L*>(&head); }
	const T&		front()		const		{ return *head.next->data(); }
	T&				front()					{ return *head.next->data(); }
	T&				back()		const		{ return *_back()->data(); }

	iteratorp		beginp()				{ return iteratorp(static_cast<L*>(&head)); }
	const_iterator	begin()		const		{ return head.next; }
	const_iterator	end()		const		{ return static_cast<const L*>(&head); }
	iterator		begin()					{ return head.next; }
	iterator		end()					{ return static_cast<L*>(&head); }

	void			push_front(L *t)		{ head.insert_after(t); }
	L*				pop_front()				{ return head.unlink_next(); }
	void			push_back(L *t)			{ _back()->insert_after(t); }
	L*				remove(iteratorp i)		{ return i.unlink(); }

	T&				operator[](int i)		{ return *(begin() += i); }
	const T&		operator[](int i) const	{ return *(begin() += i); }

	void			append(slist_base &&b)	{ if (!b.empty()) _back()->insert_after(b.head.next, b._back()); b.reset(); }
	void			prepend(slist_base &&b)	{ if (!b.empty()) head.insert_after(b.head.next, b._back()); b.reset(); }
	_insertable		insertable()			{ return *this; }

	void swap(slist_base &b) {
		L	*ahead = head.next;

		if (b.empty())
			head.init();
		else
			head.next = b.head.next;

		if (ahead == static_cast<const L*>(&head))
			b.head.init();
		else
			b.head.next = ahead;
	}
};

template<typename L> struct slist_appender {
	L	*end, *prev;
	template<typename T> slist_appender(slist_base<T, L> &list) : end(list.end()), prev(end) {}
	~slist_appender()	{
		prev->next = end;
	}
	void	add_child(L *child) {
		prev->next	= child;
		prev		= child;
	}
};

template<typename T, typename L> size_t slist_base<T,L>::size() const {
	size_t	size = 0;
	for (const_iterator	i = begin(), e = end(); i != e; ++i)
		++size;
	return size;
}

template<typename T> struct e_slink : public slink_base<T> {
	typedef T		element;
	const T*		data()		const		{ return static_cast<const T*>(this); }
	T*				data()					{ return static_cast<T*>(this); }
};

template<typename T> class e_slist : public slist_base<T, T> {
	typedef slist_base<T, T>	B;
public:
	void			removeall()				{ B::reset(); }
	void			deleteall()				{ while (!B::empty()) delete B::pop_front(); }

	friend void swap(e_slist &a, e_slist &b) { a.swap(b); }
};

template<typename T> struct slink : public slink_base<slink<T> > {
	typedef T		element;
	T				t;
	slink()						{}
	slink(const T &_t) : t(_t)	{}
	const T*		data()		const		{ return &t; }
	T*				data()					{ return &t; }
};

template<typename T> class slist : public slist_base<T, slink<T> > {
	typedef slist_base<T, slink<T> >	B;
public:
					~slist()				{ removeall();	}
	void			push_front(const T &t)	{ B::push_front(new slink<T>(t)); }
	void			pop_front()				{ delete B::pop_front(); }
	void			removeall()				{ while (!B::empty()) pop_front(); }
	void			remove(typename B::iteratorp i)	{ delete i.unlink(); }

	friend void swap(slist &a, slist &b)	{ a.wwap(b); }
};

template<typename T, typename L, class P> void sort(slist_iterator_basep<T,L> lo, slist_iterator_base<T,L> hi, P comp) {
	for (int chunk = 1;; chunk <<= 1) { // For each power of two
		int	num_merges = 0;

		for (slist_iterator_basep<T,L> i = lo, r = i; i != hi; i = r) {
			num_merges++;
			// Find next sublist
			for (int n = chunk; n-- && r != hi; ++r);

			// Merge two sublists
			int	nl = chunk, nr = chunk;
			while (nl && nr && r != hi) {
				if (comp(*r, *i)) {
					i.insert_before(r);
					--nr;
				} else {
					++i;
					--nl;
				}
			}
			while (nr-- && r != hi)
				++r;
		}
		if (num_merges < 2)
			break;
	}
}

//-----------------------------------------------------------------------------
// single linked list with tail pointer
//-----------------------------------------------------------------------------

template<typename T, typename L> class slist2_base : public slist_base<T, L> {
protected:
	typedef slist_base<T, L> B;
	using B::head;
	L*				tail;
	void			reset()	{ B::reset(); tail = static_cast<L*>(&head); }
public:
	typedef typename B::iteratorp	iteratorp;

	slist2_base() : tail(static_cast<L*>(&head)) {}
#ifdef USE_RVALUE_REFS
	slist2_base(slist2_base &&b) {
		head = b.head;
		tail = b.tail;
		tail->next = static_cast<L*>(&head);
		b.reset();
	}
#else
	slist2_base(slist2_base &b)	{
		head = b.head;
		tail = b.tail;
		tail->next = static_cast<L*>(&head);
		b.reset();
	}
#endif
	T&				back()		const	{ return *tail; }
	iteratorp		endp()				{ return tail; }
	void			push_back(L *t)		{ tail->insert_after(t); tail = t; }

	void			append(slist2_base &&b)	{
		if (!b.empty()) {
			tail->insert_after(b.head.next, b.tail);
			tail = b.tail;
		}
		b.reset();
	}
	void			prepend(B &&b)	{
		if (!b.empty())
			head.insert_after(b.head.next, b.tail);
		b.reset();
	}
//	void			append(slist2_base &b)	{ append(move(b)); }
//	void			prepend(B &b)			{ prepend(move(b)); }
};

template<typename T> class e_slist2 : public slist2_base<T, T> {
	typedef slist2_base<T, T>	B;
public:
	void			removeall()				{ B::reset(); }
	void			deleteall()				{ while (!B::empty()) delete B::pop_front(); }

	friend void swap(e_slist2 &a, e_slist2 &b)	{ a.swap(b); }
};

template<typename T> class slist2 : public slist2_base<T, slink<T> > {
	typedef slist2_base<T, slink<T> >	B;
public:
					~slist2()				{ removeall();	}
	void			push_front(const T &t)	{ B::push_front(new slink<T>(t)); }
	void			pop_front()				{ delete B::pop_front(); }
	void			removeall()				{ while (!B::empty()) pop_front(); }
	void			remove(typename B::iteratorp i)	{ delete i.unlink(); }

	friend void swap(slist2 &a, slist2 &b)	{ a.swap(b); }
};

//-----------------------------------------------------------------------------
// circular
//-----------------------------------------------------------------------------

template<typename L> struct circular_list {
	L	*p;
public:
	typedef typename L::element		element, &reference;

	class iterator {
		L		*p;
		bool	moved;
	public:
		typedef forward_iterator_t		iterator_category;
		typedef typename L::element		element, &reference;

		iterator(L *_p, bool _moved) : p(_p), moved(_moved)	{}
		reference	operator*()		const	{ return *p->data(); }
		element*	operator->()	const	{ return p->data(); }
		iterator	operator++()			{ p = p->next; moved = true; return *this;	}
		iterator	operator++(int)			{ iterator i = *this; p = p->next; moved = true; return i; }

		friend bool	operator==(const iterator &a, const iterator &b) { return a.p == b.p && a.moved == b.moved; }
		friend bool	operator!=(const iterator &a, const iterator &b) { return !(a == b); }
	};

	circular_list(L *_p = 0) : p(_p)		{}
	bool			empty()		const		{ return !p; }
	iterator		begin()					{ return iterator(p, !p); }
	iterator		end()					{ return iterator(p, true); }
	size_t			size()		const;
	uint32			size32()	const		{ return uint32(size()); }
};

template<typename L> size_t circular_list<L>::size() const {
	size_t	size = 0;
	if (L *i = p) do {
		++size;
		i = i->next;
	} while (i != p);
	return size;
}

//-----------------------------------------------------------------------------
// linked pointer - no list in pointee (so never pass pointee directly)
//-----------------------------------------------------------------------------

template<typename T> class linked_ptr : public link_base<linked_ptr<T> > {
	typedef link_base<linked_ptr<T> >	B;
	T	*t;
public:
	linked_ptr() : t(0)							{}
	explicit linked_ptr(T *_t) : t(_t)				{ B::next = this; B::prev = this; }
	linked_ptr(linked_ptr &p) : t(p.get())			{ p.insert_after(this);	}
	~linked_ptr()									{ B::unlink();	}

	linked_ptr& operator=(linked_ptr &p) {
		if (t)
			B::unlink();
		t = p.get();
		p.insert_after(this);
		return *this;
	}

	T*			get()		const	{ return t;		}
	T*			operator->()const	{ return t;		}
//	operator	T*()		const	{ return t;		}
	T&			operator*()	const	{ return *t;	}

	void		kill() {
		delete t;
		linked_ptr *p = this;
		do {
			p->t = 0;
			p = p->next;
		} while (p != this);
	}
	friend T*	get(const linked_ptr &a)			{ return a.get(); }
};

//-----------------------------------------------------------------------------
// ptr_list / ptr_link
//-----------------------------------------------------------------------------

template<typename T> class ptr_list;

template<typename T> class ptr_link : public link_base<ptr_link<T> > {
	typedef link_base<ptr_link<T> >	B;
	friend class ptr_list<T>;
	T	*t;
public:
	ptr_link() : t(0)				{}
	ptr_link(T *_t) : t(_t)			{ if (t) t->add(this);	}
	ptr_link(ptr_link &p) : t(p)	{ if (t) t->add(this);	}
	~ptr_link()						{ if (t) B::unlink();	}

	ptr_link& operator=(T *p) {
		if (t)
			B::unlink();
		if (t = p)
			p->add(this);
		return *this;
	}

	ptr_link& operator=(ptr_link &p) {
		if (t)
			B::unlink();
		if (t = p)
			p->add(this);
		return *this;
	}

	ptr_link*	data()				{ return this;	}
	T*			get()		const	{ return t;		}
	T*			operator->()const	{ return t;		}
	operator	T*()		const	{ return t;		}
	T&			operator*()	const	{ return *t;	}
};

template<typename T> class ptr_list : list_base<ptr_link<T>, ptr_link<T> > {
	typedef list_base<ptr_link<T>, ptr_link<T> >	B;
	friend class ptr_link<T>;
	void			add(ptr_link<T> *t)		{ B::head.insert_after(t);		}
protected:
	~ptr_list()	{
		for (typename B::iterator i = B::begin(); i != B::end(); ++i)
			i->t = 0;
	}
public:
	bool check_ptr_list(T *t)	{
		for (typename B::iterator i = B::begin(); i != B::end(); ++i)
			if (i->t != t)
				return false;
		return true;
	}
};

//-----------------------------------------------------------------------------
// referee/linked_ref
//-----------------------------------------------------------------------------

class referee;

template<typename T> class linked_ref : public e_link<linked_ref<void> > {
	T		*t;
public:
	linked_ref()				: t(0)		{}
	linked_ref(linked_ref &p)	: t(p.t)	{ if (t) p.insert_after(this);	}
	inline linked_ref(referee *r, T *_t);
	inline linked_ref(referee *r);
	inline linked_ref&	operator=(linked_ref &p);
	inline linked_ref&	operator=(referee *r);
	~linked_ref()							{ if (t) unlink();	}

	T*			get()				const	{ return t;		}
	T*			operator->()		const	{ return t;		}
	operator	T*()				const	{ return t;		}
	T&			operator*()			const	{ return *t;	}
	friend T*	get(const linked_ref &a)	{ return a; }
};

template<> class linked_ref<void> : public e_link<linked_ref<void> > {
	friend class referee;
	void	*t;
	linked_ref();//private (hidden)
};

class referee : private e_list<linked_ref<void> > {
	template<typename T> friend class linked_ref;
protected:
	~referee()	{
		for (iterator i = begin(); i != end(); ++i)
			i->t = 0;
	}
public:
	void	killrefs() {
		for (iterator i = begin(); i != end(); ++i)
			i->t = 0;
		head.init();
	}
};

template<typename T> linked_ref<T>::linked_ref(referee *r, T *_t)	: t(_t)	{ if (t) r->push_front((linked_ref<void>*)this);	}
template<typename T> linked_ref<T>::linked_ref(referee *r)		: t(static_cast<T*>(r))	{ if (t) r->push_front((linked_ref<void>*)this);	}
template<typename T> linked_ref<T>&	linked_ref<T>::operator=(linked_ref &p)	{
	if (t)
		unlink();
	if (t = p.t)
		p.insert_after(this);
	return *this;
}
template<typename T> linked_ref<T>&	linked_ref<T>::operator=(referee *r) {
	if (t)
		unlink();
	if (t = static_cast<T*>(r))
		r->push_front((linked_ref<void>*)this);
	return *this;
}

//-----------------------------------------------------------------------------
//	hierarchy
//-----------------------------------------------------------------------------

template<typename T> class breadth_first_iterator : public e_slist<T>::iterator {
	typedef typename e_slist<T>::iterator	B;
	using B::p;
public:
	breadth_first_iterator(T *t) : B(t) {}
	T*			skip() { return p = skip_children(p); }
	T*			operator++() {
		if (p->has_children())
			p = p->children.begin();
		else
			p = skip_children(p);
		return p;
	}
};

template<typename T> class depth_first_iterator : public e_slist<T>::iterator {
	typedef typename e_slist<T>::iterator	B;
	using B::p;
public:
	depth_first_iterator(T *t) : B(t) {}
	T*			operator++() {
		if (T *s = p->sibling())
			return p = last_generation(s);
		p = p->parent;
		return p;
	}
};

template<typename T> struct hierarchy_appender : slist_appender<T> {
	typedef slist_appender<T>	B;
	T	*parent;

	hierarchy_appender(T *_parent) : B(_parent->children), parent(_parent) {}

	void	add_child(T *child) {
		child->parent = parent;
		B::add_child(child);
	}
	template<typename T2> void	add_child(T2 &&child) {
		add_child(new T(move(child)));
	}
};

template<typename T> struct hierarchy : e_slink<T> {
	T			*parent;
	e_slist<T>	children;

	typedef breadth_first_iterator<T>		iterator;
	typedef breadth_first_iterator<const T>	const_iterator;

	friend int	get_depth(const T *t) {
		int	d = 0;
		while (t = t->parent)
			++d;
		return d;
	}
	friend int	get_ancestry(const T *t, const T **dest, int max) {
		const T	**end = dest + max;
		while (dest < end && (t = t->parent))
			*dest++ = t;
		return dest + max - end;
	}
	friend const T*	get_root(const T *t) {
		while (const T *p = t->parent)
			t = p;
		return t;
	}
	friend T*	get_root(T *t) {
		while (T *p = t->parent)
			t = p;
		return t;
	}

	friend const T*	last_generation(const T *t) {
		while (t->has_children())
			t = t->children.begin();
		return t;
	}
	friend T*	last_generation(T *t) {
		while (t->has_children())
			t = t->children.begin();
		return t;
	}

	friend const T*	skip_children(const T *t) {
		while (t) {
			if (const T *s = t->sibling())
				return s;
			t = t->parent;
		}
		return t;
	}
	friend T*	skip_children(T *t) {
		while (t) {
			if (T *s = t->sibling())
				return s;
			t = t->parent;
		}
		return t;
	}

	hierarchy() : parent(0)	{}
	hierarchy(const hierarchy &b)	{ ISO_ASSERT(0); }
#ifdef USE_RVALUE_REFS
	hierarchy(hierarchy &&b) : parent(0), children(move(b.children)) {
		for (auto &i : children)
			i.parent = me();
	}
#endif
	template<typename B> hierarchy(const hierarchy<B> &b) : parent(0) {
		hierarchy_appender<T>	a(me());
		for (auto &i : b.children)
			a.add_child(i);
	}
	template<typename B> hierarchy& operator=(const hierarchy<B> &b) {
		detach();
		children.removeall();
		hierarchy_appender<T>	a(me());
		for (auto &i : b.children)
			a.add_child(i);
		return *this;
	}

	T*			me()					{ return static_cast<T*>(this); }
	const T*	me()			const	{ return static_cast<const T*>(this); }
	const T*	root()			const	{ return get_root(me()); }
	T*			root()					{ return get_root(me()); }
	const T*	child()			const	{ T *c = children.begin(); return c == children.end() ? 0 : c; }
	T*			child()					{ T *c = children.begin(); return c == children.end() ? 0 : c; }
	bool		has_children()	const	{ return !children.empty(); }
	uint32		num_children()	const	{ return children.size32(); }
	T*			sibling()		const	{ return parent && this->next != parent->children.end() ? this->next : 0; }

	void		attach(T *t)			{ t->parent = me(); children.push_front(t); }
	void		push_back(T *t)			{ t->parent = me(); children.push_back(t); }
	void		push_front(T *t)		{ t->parent = me(); children.push_front(t); }

	void	attach(e_slist<T> &&list) {
		for (auto &i : list)
			i.parent = me();
		children.prepend(move(list));
	}
	void	attach(e_slist<T> &list) {
		attach(move(list));
	}
	void detach() {
		if (parent) {
			parent->children.prev(me())->unlink_next();
			parent	= 0;
		}
	}

	~hierarchy() {
		detach();
		while (!children.empty()) {
			T	*t = children.pop_front();
			t->parent	= 0;
			delete t;
		}
	}

	int			depth()										const	{ return get_depth(me()); }
	int			ancestry(const T **dest, int max)			const	{ return get_ancestry(me(), dest, max); }

	range<breadth_first_iterator<T> >		breadth_first()			{ return range<breadth_first_iterator<T> >(me(), skip_children(me())); }
	range<depth_first_iterator<T> >			depth_first()			{ return range<depth_first_iterator<T> >(last_generation(me()), skip_children(me())); }
	range<breadth_first_iterator<const T> >	breadth_first()	const	{ return range<breadth_first_iterator<const T> >(me(), skip_children(me())); }
	range<depth_first_iterator<const T> >	depth_first()	const	{ return range<depth_first_iterator<const T> >(last_generation(me()), skip_children(me())); }
};


}//namespace iso

#endif	// LIST_H
