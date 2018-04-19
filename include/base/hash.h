#ifndef HASH_H
#define HASH_H

#include "base/defs.h"
#include "base/array.h"

namespace iso {

//-----------------------------------------------------------------------------
//	hash_key
//-----------------------------------------------------------------------------

template<typename T, int N> struct xor_together	{ static inline T f(const T *p) { return xor_together<T, N/2>::f(p) ^ xor_together<T, (N + 1)/2>::f(p + N/2); } };
template<typename T> struct xor_together<T, 1>	{ static inline T f(const T *p) { return *p; } };

template<typename T, int N> struct get_bytes;
template<> struct get_bytes<uint32,1> { static inline uint32 f(const void *p) { return *(const uint8*) p; } };
template<> struct get_bytes<uint32,2> { static inline uint32 f(const void *p) { return *(const uint16*)p; } };
template<> struct get_bytes<uint32,3> { static inline uint32 f(const void *p) { return get_bytes<uint32,2>::f(p) | (get_bytes<uint32, 1>::f((const uint8*)p + 2) << 16); } };
template<> struct get_bytes<uint32,4> { static inline uint32 f(const void *p) { return *(const uint32*)p; } };

template<> struct get_bytes<uint64,1> { static inline uint64 f(const void *p) { return get_bytes<uint32,1>::f(p); } };
template<> struct get_bytes<uint64,2> { static inline uint64 f(const void *p) { return get_bytes<uint32,2>::f(p); } };
template<> struct get_bytes<uint64,3> { static inline uint64 f(const void *p) { return get_bytes<uint32,3>::f(p); } };
template<> struct get_bytes<uint64,4> { static inline uint64 f(const void *p) { return get_bytes<uint32,4>::f(p); } };
template<> struct get_bytes<uint64,5> { static inline uint64 f(const void *p) { return get_bytes<uint32,4>::f(p) + (get_bytes<uint64,1>::f((uint8*)p + 4) << 32); } };
template<> struct get_bytes<uint64,6> { static inline uint64 f(const void *p) { return get_bytes<uint32,4>::f(p) + (get_bytes<uint64,2>::f((uint8*)p + 4) << 32); } };
template<> struct get_bytes<uint64,7> { static inline uint64 f(const void *p) { return get_bytes<uint32,4>::f(p) + (get_bytes<uint64,3>::f((uint8*)p + 4) << 32); } };
template<> struct get_bytes<uint64,8> { static inline uint64 f(const void *p) { return *(const uint64*)p; } };

template<typename T, bool S32> struct hash_s64 {
	static inline uint64 f(const T &t) { return get_bytes<uint64, sizeof(T)>::f(&t); }
};
template<typename T> struct hash_s64<T, false> {
	static inline uint64 f(const T &t) { return xor_together<uint64, sizeof(T)/sizeof(uint64)>::f((const uint64*)&t); }
};
template<typename T, bool S32> struct hash_s32 {
	static inline uint32 f(const T &t) { return get_bytes<uint32, sizeof(T)>::f(&t); }
};
template<typename T> struct hash_s32<T, false>	: hash_s64<T, (sizeof(T) < 8)> {};
template<typename T> struct hash_s				: hash_s32<T, (sizeof(T) <= 4)> {};

template<typename T> struct hash_s<const T>	: hash_s<T> {};

template<typename T> struct hash_s<T*>	{
	static inline uintptr_t f(const T *t) { return (uintptr_t)t / alignof(T); }
};
template<> struct hash_s<void*> {
	static inline uintptr_t f(const void *t) { return (uintptr_t)t; }
};
template<> struct hash_s<const void*> {
	static inline uintptr_t f(const void *t) { return (uintptr_t)t; }
};
template<> struct hash_s<arbitrary> {
	template<typename T> static inline uintptr_t f(const T &t) { return hash((const T&)t); }
};

template<typename T> auto hash(const T &t) -> decltype(hash_s<T>::f(t)) {
	return hash_s<T>::f(t);
}

template<typename T> struct hash_type {
	typedef decltype(hash(*(const T*)0))	type;
};

//-----------------------------------------------------------------------------
//	hash_entry
//-----------------------------------------------------------------------------

template<typename K, typename T> struct hash_entry {
	typedef K	hash_t;
	K key;
	T val;

	hash_entry(K k = 0)				: key(k), val()					{}
	hash_entry(const hash_entry &b) : key(b.key), val(b.val)		{}
	hash_entry(hash_entry &&b)		: key(b.key), val(move(b.val))	{}

	bool	cas(K k0, K k1) {
		if (key == k0) {
			key = k1;
			return true;
		}
		return false;
	}
	bool	set(K k0, K k1) {
		key = k1;
		new(__builtin_addressof(val)) T();
		return true;
	}
	
	static const hash_entry	*as_entry(const T *t) {
		struct SK	{ K key; };
		struct ST	{ T val; };
		struct S : SK, ST	{};
		return (hash_entry*)static_cast<S*>((ST*)t);
	}
};

//-----------------------------------------------------------------------------
//	fixed_hash_map
//-----------------------------------------------------------------------------

template<typename E, int HASH_BITS> class fixed_hash_base {
protected:
	typedef typename E::hash_t	hash_t;
	enum {
		HASH_SIZE	= 1 << HASH_BITS,
		HASH_MASK	= HASH_SIZE - 1,
		HASH_CAP	= HASH_SIZE / 2,
		UNUSED		= 0,
		FREED		= ~hash_t(0),
	};

	uint32	curr_size;
	E		entries[HASH_SIZE];

	fixed_hash_base() : curr_size(0) {}

	static E	*next_valid(E *i, E *e) {
		while (i != e && (i->key == UNUSED || i->key == FREED))
			i++;
		return i;
	}
	const E *check(hash_t key) const {
		ISO_ASSERT(key != UNUSED && key != FREED);
		for (uint32 i = key; ; ++i) {
			const E *e	= &entries[i & HASH_MASK];
			if (e->key == key)
				return e;
			if (e->key == UNUSED)
				return 0;
		}
	}
	E* find(hash_t key) {
		ISO_ASSERT(key != UNUSED && key != FREED);
		E	*freed = 0;
		for (uint32 i = key; ; ++i) {
			E		*e	= &entries[i & HASH_MASK];
			uint32	k	= e->key;
			if (k == key)
				return e;
			if (k == UNUSED || k == FREED) {
				if (!freed)
					freed = e;
				if (k == UNUSED)
					return freed;
			}
		}
	}

	void set(E *e, hash_t key) {
		ISO_ASSERT(curr_size < HASH_CAP);
		e->key	= key;
		++curr_size;
	}

	E* get(hash_t key) {
		E		*e	= find(key);
		hash_t	ek	= e->key;
		if (ek != key) {
			ISO_ASSERT(curr_size < HASH_CAP);
			if (!e->set(ek, key))
				return 0;
			++curr_size;
		}
		return e;
	}

	E* remove(hash_t key) {
		E	*e	= find(key);
		if (e->cas(key, FREED)) {
			--curr_size;
			return e;
		}
		return 0;
	}
	int index_of(const E *e) const {
		return e ? uint32(e - entries) : -1;
	}

public:
	struct iterator {
		typedef	forward_iterator_t	iterator_category;
		E			*i, *e;
		iterator(E *_i) : i(_i)									{}
		iterator(E *_i, E *_e) : i(next_valid(_i, _e)), e(_e)	{}
		iterator&	operator++()					{ i = next_valid(i + 1, e); return *this; }
		bool operator==(const iterator &b)	const 	{ return i == b.i; }
		bool operator!=(const iterator &b)	const	{ return i != b.i; }
	};
	iterator	begin()	const	{ return iterator(entries, entries + HASH_SIZE); }
	iterator	end()	const	{ return iterator(entries + HASH_SIZE); }

	void		reset()			{
		for (auto &i : entries)
			i.key = UNUSED;
		curr_size = 0;
	}
	uint32		size()	const	{ return curr_size; }
};

template<typename K, typename T, int HASH_BITS> class fixed_hash_map : public fixed_hash_base<hash_entry<typename hash_type<K>::type, T>, HASH_BITS> {
	typedef typename hash_type<K>::type		H;
	typedef hash_entry<H, T>				E;
	typedef fixed_hash_base<E, HASH_BITS>	B;
public:
	const T* check(const K &k) const {
		if (const E *e = B::check(hash(k)))
			return &e->val;
		return 0;
	}
	T&	operator[](const K &key) {
		return B::get(hash(key))->val;
	}
	int index_of(const T *t) const {
		return t ? B::index_of(E::as_entry(t)) : -1;
	}
	T*	by_index(int i) const {
		return &B::entries[i].val;
	}
	K	key(const T *t) const {
		int	i = index_of(t);
		return i < 0 ? 0 : B::entries[i].key;
	}
	T*	remove(K k) {
		if (E *e = B::remove(hash(k)))
			return &e->val;
		return 0;
	}
	T*	remove(T *t) {
		int	i = index_of(t);
		return i < 0 ? 0 : B::remove(B::entries + i);
	}
};


//-----------------------------------------------------------------------------
//	hash_map_base
//-----------------------------------------------------------------------------

template<typename E, typename C> class hash_map_base0 {
protected:
	typedef typename E::hash_t	hash_t;

	static hash_t	UNUSED(hash_t i)			{ return i + 1; }
	static hash_t	FREED(hash_t i)				{ return i + 2; }
	static bool		IS_USED(hash_t i, hash_t k)	{ return k != UNUSED(i) && k != FREED(i); }
	
	E		*entries;
	uint32	max_size;
	C		curr_size, num_free;

	static E	*next_valid(E *b, E *e, E *i) {
		while (i != e && !IS_USED(i - b, i->key))
			i++;
		return i;
	}

	void	_remove(E *e);
	void	resize(uint32 newsize);

	E*	find(hash_t key) {
		E	*freed = 0;
		for (hash_t h = key, mask = max_size - 1; ; ++h) {
			hash_t	i	= h & mask;
			E		*e	= &entries[i];
			hash_t	k	= e->key;
			if (k == key)
				return e;
			if (k == UNUSED(i))
				return freed ? freed : e;
			if (!freed && k == FREED(i))
				freed = e;
		}
	}

	E*	check(hash_t key) const {
		for (hash_t h = key, mask = max_size - 1; ; ++h) {
			hash_t	i	= h & mask;
			E		*e	= &entries[i];
			if (e->key == key)
				return e;
			if ( e->key == UNUSED(i))
				return 0;
		}
	}

	E*	get0(E *e, hash_t key) {
		hash_t	ek	= e->key;
		if (ek != key) {
			if (!e->set(ek, key))
				return 0;
			++curr_size;
		}
		return e;
	}
	E*	remove0(E *e, hash_t key) {
		if (!e->cas(key, FREED(e - entries)))
			return 0;
		_remove(e);
		return e;
	}

	int		index_of(const E *e) const {
		return e ? uint32(e - entries) : -1;
	}

	void	init(uint32 n) {
		n = max(n, 1);
		while (n & (n - 1))
			n += (n & -int(n));

		max_size	= n;
		entries		= allocate<E>(n);
		for (E *i = entries, *e = i + n; i != e; ++i)
			i->key = UNUSED(i - entries);
	}

	hash_map_base0(uint32 n = 8) : curr_size(0), num_free(0) {
		init(n);
	}
	hash_map_base0(const hash_map_base0 &b) : curr_size(b.size()), num_free(0) {
		init(curr_size);
		E*		b_entries	= b.entries;
		for (int i = 0, n = b.max_size; i < n; i++) {
			hash_t key = b_entries[i].key;
			if (IS_USED(i, key))
				new(find(key)) E(b_entries[i]);
		}
	}
#ifdef USE_RVALUE_REFS
	hash_map_base0(hash_map_base0 &&b) : max_size(b.max_size), entries(b.entries), curr_size(b.curr_size), num_free(b.num_free) {
		b.entries = 0;
	}
#endif
	~hash_map_base0() {
		if (entries) {
			for (E *i = entries, *e = i + max_size; i != e; ++i) {
				if (IS_USED(i - entries, i->key))
					i->~E();
			}
			deallocate(entries, max_size);
		}
	}

public:
	struct iterator {
		typedef	forward_iterator_t	iterator_category;
		E			*b, *e, *i;
		iterator(E *_i) : i(_i)									{}
		iterator(E *_b, E *_e, E *_i) : b(_b), e(_e), i(next_valid(_b, _e, _i))	{}
		iterator&	operator++()					{ i = next_valid(b, e, i + 1); return *this; }
		bool operator==(const iterator &b)	const 	{ return i == b.i; }
		bool operator!=(const iterator &b)	const	{ return i != b.i; }
		operator E*()						const	{ return i; }
		E*	operator->()					const	{ return i; }
	};
	iterator	begin()	const		{ return iterator(entries, entries + max_size, entries); }
	iterator	end()	const		{ return iterator(entries + max_size); }

	bool		empty() const		{ return curr_size == 0; }
	uint32		size()	const		{ return curr_size;	}
	void		reserve(size_t i)	{ resize(i); }
	void		clear();
};

template<typename E, typename C> void hash_map_base0<E,C>::clear() {
	for (E *i = entries, *e = i + max_size; i != e; ++i) {
		if (IS_USED(i - entries, i->key)) {
			i->~E();
			i->key = UNUSED(i - entries);
		}
	}
	curr_size	= 0;
	num_free	= 0;
}

template<typename E, typename C> void hash_map_base0<E,C>::_remove(E *e) {
	e->~E();
//	e->key = B::FREED(e - B::entries);

	++num_free;
	--curr_size;

	// any FREED entry followed by an UNUSED entry can be marked UNUSED
	uint32	i		= uint32(e - entries);
	uint32	mask	= max_size - 1;
	uint32	i1		= (i + 1) & mask;

	if (entries[i1].key == UNUSED(i1)) {
		while (e->cas(FREED(i), UNUSED(i))) {
			--num_free;
			i = (i - 1) & mask;
			e = &entries[i];
		}
	}
}

template<typename E, typename C> void hash_map_base0<E,C>::resize(uint32 newsize) {
	hash_map_base0	new_map(newsize);

	for (int i = 0; i < max_size; i++) {
		auto k = entries[i].key;
		if (IS_USED(i, k))
			new(new_map.find(k)) E(move(entries[i]));
	}

	swap(max_size, new_map.max_size);
	swap(entries, new_map.entries);
	num_free	= 0;
}

template<typename E> class hash_map_base : public hash_map_base0<E, uint32> {
	typedef hash_map_base0<E,uint32> B;
	using typename B::hash_t;

protected:
//	using B::remove;

	void resize(uint32 newsize) {
		B::resize(newsize);
	}

	E*	get(hash_t key) {
		if (B::curr_size >= B::max_size / 2)
			resize(B::max_size * 2);
		return B::get0(B::find(key), key);
	}

	E* remove(hash_t key) {
		if (B::num_free >= B::max_size / 2)
			resize(B::curr_size);
		return B::remove0(B::find(key), key);
	}

	hash_map_base(uint32 n = 8)				: B(n) {}
	hash_map_base(const hash_map_base &b)	: B(b) {}
#ifdef USE_RVALUE_REFS
	hash_map_base(hash_map_base &&b)		: B(move(b)) {}
#endif
};


//-----------------------------------------------------------------------------
//	hash_map
//-----------------------------------------------------------------------------

template<typename K, typename T> class hash_map : public hash_map_base<hash_entry<typename hash_type<K>::type, T> > {
	typedef typename hash_type<K>::type	H;
	typedef hash_entry<H, T>			E;
	typedef hash_map_base<E>			B;
public:
	struct iterator : B::iterator {
		typedef		T	element, &reference;
		using B::iterator::i;
		iterator(const typename B::iterator &_i) : B::iterator(_i)	{}
		iterator&	operator++()			{ B::iterator::operator++(); return *this; }
		operator	T*()			const	{ return &i->val; }
		T*			operator->()	const	{ return &i->val; }
		T&			operator*()		const	{ return i->val; }
		H&			key()			const	{ return i->key; }
	};
	typedef iterator	const_iterator;
	typedef T			element, &reference;

	hash_map(int init = 8) : B(init) {}
	T* check(const K &key) const {
		if (E *e = B::check(hash(key)))
			return __builtin_addressof(e->val);
		return 0;
	}
	T&	operator[](const K &key) {
		return B::get(hash(key))->val;
	}
	optional<T&>	lookup(const K &key) const {
		if (E *e = B::check(hash(key)))
			return e->val;
		return none;
	}
	auto operator[](const K &key) const {
		return lookup(key).or_default();
	}
	int index_of(const T *t) const {
		return t ? B::index_of(E::as_entry(t)) : -1;
	}
	T*	by_index(int i) const {
		return &B::entries[i].val;
	}
	K	key(const T *t) const {
		int	i = index_of(t);
		return i < 0 ? 0 : B::entries[i].key;
	}
	T*	remove(K key) {
		if (E *e = B::remove(hash(key)))
			return &e->val;
		return 0;
	}
	T*	remove(T *t) {
		int	i = index_of(t);
		if (i >= 0) {
			E	*e	= B::entries + i;
			H	k	= e->key;
			if (B::remove0(e, k))
				return t;
		}
		return 0;
	}

	iterator	begin()		const	{ return B::begin(); }
	iterator	end()		const	{ return B::end(); }

	B&			with_keys()			{ return *this; }
	const B&	with_keys()	const	{ return *this; }
};

//-----------------------------------------------------------------------------
//	hash_set
//-----------------------------------------------------------------------------

template<typename E> class hash_set_base : public hash_map_base<E> {
protected:
	typedef typename E::key_t		K;
	typedef typename E::hash_t		H;
	typedef hash_map_base<E>		B;

	bool check_all(const hash_set_base &b) const	{
		for (auto i = B::begin(), e = B::end(); i != e; ++i) {
			if (!b.check(i->key))
				return false;
		}
		return true;
	}
	void intersect(const hash_set_base &b) {
		for (auto i = B::begin(), e = B::end(); i != e; ++i) {
			auto	k = i->key;
			if (!b.check(k))
				B::remove0(i, k);
		}
	}
	void difference(const hash_set_base &b) {
		for (auto i = B::begin(), e = B::end(); i != e; ++i) {
			auto	k = i->key;
			if (b.check(k))
				B::remove0(i, k);
		}
	}
	void onion(const hash_set_base &b) {
		for (auto i = b.begin(), e = b.end(); i != e; ++i)
			B::get(i->key)->set_val(i);
		return *this;
	}
	void exclusive(const hash_set_base &b) {
		for (auto i = b.begin(), e = b.end(); i != e; ++i) {
			auto	k = i->key;
			if (auto j = B::check(k))
				B::remove0(j, k);
			else
				B::get(k)->set_val(i);
		}
		return *this;
	}
public:
	hash_set_base(int init = 8) : B(init) {}

	bool		count(const K &key) const			{ return !!B::check(hash(key)); }
	void		insert(const K &key)				{ B::get(hash(key))->set_val(key); }
	bool		remove(const K &key)				{ return !!B::remove(hash(key)); }
	bool		check_insert(const K &key)			{ H h = hash(key); return B::check(h) || (B::get(h)->set_val(key), false); }
	template<typename I> void insert(I a, I b)		{ while (a != b) insert(*a++); }
	template<typename I> void remove(I a, I b)		{ while (a != b) remove(*a++); }

	bool operator==(const hash_set_base &b)	const	{ return B::size() == b.size() && check_all(b); }
	bool operator< (const hash_set_base &b)	const	{ return B::size() <  b.size() && check_all(b); }
	bool operator<=(const hash_set_base &b)	const	{ return B::size() <= b.size() && check_all(b); }
	bool operator> (const hash_set_base &b)	const	{ return b <  *this; }
	bool operator>=(const hash_set_base &b)	const	{ return b <= *this; }
};

// only store hash value
template<typename K> struct hash_set_entry {
	typedef K								key_t;
	typedef typename hash_type<K>::type		hash_t;
	hash_t		key;
//	hash_set_entry(hash_t k = 0) : key(k)		{}

	bool	cas(hash_t k0, hash_t k1) {
		if (key == k0) {
			key = k1;
			return true;
		}
		return false;
	}
	bool	set(hash_t k0, hash_t k1) {
		key = k1;
		return true;
	}

	void	set_val(const hash_set_entry *b)	{}
	void	set_val(const K &k)					{}
};

template<typename K> class hash_set : public hash_set_base<hash_set_entry<K> > {
	typedef hash_set_base<hash_set_entry<K> >	B;
public:
	hash_set(int init = 8) : B(init) {}

	_not<hash_set>	operator~() const				{ return *this; }
	hash_set& operator&=(const hash_set &b)			{ B::intersect(b); return *this; }
	hash_set& operator&=(const _not<hash_set> &b)	{ B::difference(b.t); return *this; }
	hash_set& operator|=(const hash_set &b)			{ B::onion(b); return *this; }
	hash_set& operator^=(const hash_set &b)			{ B::exclusive(b); return *this; }

	hash_set& operator*=(const hash_set &b)			{ return operator&=(b); }
	hash_set& operator+=(const hash_set &b)			{ return operator|=(b); }
	hash_set& operator-=(const hash_set &b)			{ return operator&=(~b); }

	friend hash_set operator&(const hash_set &a, const hash_set &b)			{ hash_set t(a); t &= b; return t; }
	friend hash_set operator&(const hash_set &a, const _not<hash_set> &b)	{ hash_set t(a); t &= b; return t; }
	friend hash_set operator|(const hash_set &a, const hash_set &b)			{ hash_set t(a); t &= b; return t; }
	friend hash_set operator^(const hash_set &a, const hash_set &b)			{ hash_set t(a); t ^= b; return t; }
};

template<typename K> struct _not<hash_set<K> > {
	const hash_set<K>	&t;
	_not(const hash_set<K> &_t) : t(_t) {}
	bool	count(const K &k) const		{ return !t.count(k); }
};

// hold hash and actual value, for iteration
template<typename K> struct hash_set_entry2 : hash_entry<typename hash_type<K>::type, K> {
	typedef hash_entry<typename hash_type<K>::type, K>	B;
	typedef K								key_t;
	typedef typename hash_type<K>::type		hash_t;
	hash_set_entry2()											{}
	hash_set_entry2(const hash_set_entry2 &b)	: B(b)			{}
	hash_set_entry2(hash_set_entry2 &&b)		: B(move(b))	{}

	void	set_val(const hash_set_entry2 *b)	{ B::val = b->val; }
	void	set_val(const key_t &k)				{ B::val = k; }
};

template<typename K> class hash_set2 : public hash_set_base<hash_set_entry2<K> > {
	typedef hash_set_base<hash_set_entry2<K> >	B;
public:
	struct iterator : B::iterator {
		using B::iterator::i;
		typedef		K	element, &reference;
		iterator(const typename B::iterator &_i) : B::iterator(_i)	{}
		iterator&	operator++()					{ B::iterator::operator++(); return *this; }
		operator	K*()					const	{ return &i->val; }
		K*			operator->()			const	{ return &i->val; }
		K&			operator*()				const	{ return i->val; }
	};

	hash_set2(int init = 8) : B(init) {}

	iterator	begin()	const	{ return B::begin(); }
	iterator	end()	const	{ return B::end(); }

	_not<hash_set2>	operator~() const				{ return *this; }
	hash_set2& operator&=(const hash_set2 &b)		{ B::intersect(b); return *this; }
	hash_set2& operator&=(const _not<hash_set2> &b)	{ B::difference(b.t); return *this; }
	hash_set2& operator|=(const hash_set2 &b)		{ B::onion(b); return *this; }
	hash_set2& operator^=(const hash_set2 &b)		{ B::exclusive(b); return *this; }

	hash_set2& operator*=(const hash_set2 &b)		{ return operator&=(b); }
	hash_set2& operator+=(const hash_set2 &b)		{ return operator|=(b); }
	hash_set2& operator-=(const hash_set2 &b)		{ return operator&=(~b); }

	friend hash_set2 operator&(const hash_set2 &a, const hash_set2 &b)		{ hash_set2 t(a); t &= b; return t; }
	friend hash_set2 operator&(const hash_set2 &a, const _not<hash_set2> &b){ hash_set2 t(a); t &= b; return t; }
	friend hash_set2 operator|(const hash_set2 &a, const hash_set2 &b)		{ hash_set2 t(a); t &= b; return t; }
	friend hash_set2 operator^(const hash_set2 &a, const hash_set2 &b)		{ hash_set2 t(a); t ^= b; return t; }
};

template<typename K> struct _not<hash_set2<K> > {
	const hash_set2<K>	&t;
	_not(const hash_set2<K> &_t) : t(_t) {}
	bool	count(const K &k) const		{ return !t.count(k); }
};

//-----------------------------------------------------------------------------
//	hash_multiset
//-----------------------------------------------------------------------------

template<typename B> struct hash_count : B {
	using typename B::key_t;
	using typename B::hash_t;
	uint32	count;
	hash_count(hash_t k = 0) : B(k), count(0)	{}
	void	add(const hash_count *b)			{ if (count == 0) B::set_val(b); count += b->count; }
	int		set_val(const key_t &k)				{ if (count == 0) B::set_val(k); return count++; }
};

template<typename E0> class hash_multiset_base : public hash_map_base<hash_count<E0> > {
protected:
	typedef hash_count<E0>						E;
	typedef typename E0::key_t					K;
	typedef typename E0::hash_t					H;
	typedef hash_map_base<hash_count<E0> >		B;

	bool check_all(const hash_multiset_base &b) const	{
		for (auto i = B::begin(), e = B::end(); i != e; ++i) {
			E	*x = b.check(i->key);
			if (!x || x->count < i->count)
				return false;
		}
		return true;
	}
	void add(const hash_multiset_base &b) {
		for (auto i = b.begin(), e = b.end(); i != e; ++i)
			B::get(i->key)->add(i);
		return *this;
	}
	void sub(const hash_multiset_base &b) {
		for (auto i = B::begin(), e = B::end(); i != e; ++i) {
			if (E *x = b.check(i->key)) {
				if (i->count <= x->count)
					remove(i);
				else
					i->count -= x->count;
			}
		}
		return *this;
	}
	void min(const hash_multiset_base &b) {
		for (auto i = B::begin(), e = B::end(); i != e; ++i) {
			if (E *x = b.check(i->key))
				x->count = iso::min(x->count, i->count);
			else
				remove(i);
		}
		return *this;
	}
	void max(const hash_multiset_base &b) {
		for (auto i = B::begin(), e = B::end(); i != e; ++i) {
			E *x		= b.get(i->key);
			x->count	= iso::max(e->count, i->count);
		}
		return *this;
	}
public:
	uint32		count(const K &key) const			{ E *e = B::check(hash(key)); return e ? e->count : 0; }
	int			insert(const K &key)				{ return B::get(hash(key))->set_val(key); }
	bool		remove(const K &key)				{
		if (E *e = B::check(hash(key))) {
			if (--e->count == 0)
				B::remove(e);
			return true;
		}
		return false;
	}
	template<typename I> void insert(I a, I b)	{ while (a != b) insert(*a++); }
	template<typename I> void remove(I a, I b)	{ while (a != b) remove(*a++); }

	bool operator==(const hash_multiset_base &b)	const	{ return B::size() == b.size() && check_all(b); }
	bool operator< (const hash_multiset_base &b)	const	{ return B::size() <  b.size() && check_all(b); }
	bool operator<=(const hash_multiset_base &b)	const	{ return B::size() <= b.size() && check_all(b); }
	bool operator> (const hash_multiset_base &b)	const	{ return b <  *this; }
	bool operator>=(const hash_multiset_base &b)	const	{ return b <= *this; }
};

// only store hash value
template<typename K> class hash_multiset : public hash_multiset_base<hash_set_entry<K> > {
	typedef hash_multiset_base<hash_set_entry<K> >	B;
public:
	hash_multiset& operator+=(const hash_multiset &b) { B::add(b); return *this; }
	hash_multiset& operator-=(const hash_multiset &b) { B::sub(b); return *this; }
	hash_multiset& operator*=(const hash_multiset &b) { B::min(b); return *this; }

	friend hash_multiset operator+(const hash_multiset &a, const hash_multiset &b)	{ hash_multiset t(a); t += b; return t; }
	friend hash_multiset operator-(const hash_multiset &a, const hash_multiset &b)	{ hash_multiset t(a); t -= b; return t; }
	friend hash_multiset operator*(const hash_multiset &a, const hash_multiset &b)	{ hash_multiset t(a); t *= b; return t; }
};

// hold hash and actual value, for iteration
template<typename K> class hash_multiset2 : public hash_multiset_base<hash_set_entry2<K> > {
	typedef hash_multiset_base<hash_set_entry2<K> >	B;
public:
	struct iterator : B::iterator {
		using B::iterator::i;
		typedef		K	element, &reference;
		iterator(const typename B::iterator &_i) : B::iterator(_i)	{}
		iterator&	operator++()					{ B::iterator::operator++(); return *this; }
		operator	K*()					const	{ return &i->val; }
		K*			operator->()			const	{ return &i->val; }
		K&			operator*()				const	{ return i->val; }
		uint32		count()					const	{ return i->count; }
	};
	iterator	begin()	const	{ return B::begin(); }
	iterator	end()	const	{ return B::end(); }

	hash_multiset2& operator+=(const hash_multiset2 &b) { B::add(b); return *this; }
	hash_multiset2& operator-=(const hash_multiset2 &b) { B::sub(b); return *this; }
	hash_multiset2& operator*=(const hash_multiset2 &b) { B::min(b); return *this; }

	friend hash_multiset2 operator+(const hash_multiset2 &a, const hash_multiset2 &b)	{ hash_multiset2 t(a); t += b; return t; }
	friend hash_multiset2 operator-(const hash_multiset2 &a, const hash_multiset2 &b)	{ hash_multiset2 t(a); t -= b; return t; }
	friend hash_multiset2 operator*(const hash_multiset2 &a, const hash_multiset2 &b)	{ hash_multiset2 t(a); t *= b; return t; }
};

//-----------------------------------------------------------------------------
//	sparse_set	- O(1) ops, including iteration
//-----------------------------------------------------------------------------

template<typename T> T sparse(const T &t) {
	return t;
}
template<typename T> struct sparse_type {
	typedef decltype(sparse(*(const T*)0))	type;
};

template<typename T, typename S = uint8> class sparse_set_base : dynamic_array<T> {
	S			*sparse;
	size_t		universe;
public:
	sparse_set_base(size_t u) : universe(u), sparse((S*)malloc(u * sizeof(S))) {}
	~sparse_set_base()	{ free(sparse); }

	bool		check(const T &k) {
		ISO_ASSERT(k < universe);
		S	s = sparse[k];
		return s < this->size() && at(s) == k;
	}
	bool		insert(const T &k) {
		ISO_ASSERT(k < universe);
		S	s = sparse[k];
		if (s >= this->size() || at(s) != k) {
			sparse[k] = this->size();
			push_back(k);
			return false;
		}
		return true;
	}
	bool		remove(const T &k) {
		ISO_ASSERT(k < universe);
		S	s = sparse[k];
		if (s < this->size() || at(s) == k) {
			sparse[*erase_unordered(this->begin() + s)] = s;
			return true;
		}
		return false;
	}
};

template<typename K, int MAX=256> class sparse_set : sparse_set_base<typename sparse_type<K>::type, uint_type(LOG2(MAX))> {
	typedef sparse_set_base<typename sparse_type<K>::type, uint_type(LOG2(MAX))> B;

	sparse_set(size_t u) : B(u) {}

	bool	check(const K &k)	{ return B::check(sparse(k)); }
	bool	insert(const K &k)	{ return B::insert(sparse(k)); }
	bool	remove(const K &k)	{ return B::remove(sparse(k)); }
};

//-----------------------------------------------------------------------------
//	small_set - uses array of N before switching to hash_map
//-----------------------------------------------------------------------------

template<typename T, int N = 8> struct small_set {
	array<T, N>		smll;
	hash_set<T>		hash;

	typedef	typename array<T, N>::iterator	iterator;

#ifdef USE_RVALUE_REFS
	small_set()	{}
	small_set(const small_set &b) : smll(b.smll), hash(b.hash) {}
	small_set(small_set &&b) : smll(move(b.smll)), hash(move(b.hash)) {}
#endif

	void		clear() {
		smll.clear();
		hash.clear();
	}
	const T*	in_small(const T&t) const {
		for (auto &i : smll) {
			if (i == t)
				return &i;
		}
		return 0;
	}

	bool		count(const T&t) const	{
		return hash.empty() ? in_small(smll, t) : hash.count(t);
	}
	void		insert(const T&t) {
		if (hash.empty()) {
			if (in_small(t))
				return;
			if (!smll.full()) {
				smll.push_back(t);
				return;
			}
			hash.insert(smll.begin(), smll.end());
		}
		hash.insert(t);
	}
	bool		remove(const T&t) {
		if (hash.empty()) {
			if (auto *i = in_small(t)) {
				smll.erase_unordered(i);
				return true;
			}
			return false;
		}
		return hash.remove(t);
	}
	bool		check_insert(const T&t)	{
		if (hash.empty()) {
			if (in_small(t))
				return true;
			if (!smll.full()) {
				smll.push_back(t);
				return false;
			}
			hash.insert(smll.begin(), smll.end());
		}
		return hash.check_insert(t);
	}

	iterator	begin() { return smll.begin(); }
	iterator	end()	{ return smll.end(); }
};

} // namespace iso

#endif // HASH_H

#if defined ATOMIC_H && !defined ATOMIC_HASH_H
#define ATOMIC_HASH_H

#include "thread.h"

//-----------------------------------------------------------------------------
//	atomic versions
//-----------------------------------------------------------------------------

namespace iso {

template<typename K, typename T> struct atomic<hash_entry<K,T> > {
	typedef K	hash_t;
	atomic<K>	key;
	T			val;

	atomic()	{}
	atomic(atomic &&b) : key(b.key), val(move(b.val))	{}

	bool	cas(K k0, K k1) {
		return key.cas(k0, k1);
	}
	bool	set(K k0, K k1) {
		if (!key.cas(k0, k1))
			return false;
		new(&val) T();
		return true;
	}

	static const atomic	*as_entry(const T *t) {
		struct ST					{ T val; };
		struct S : atomic<K>, ST	{};
		return (atomic*)static_cast<S*>((ST*)t);

	}
};

//-----------------------------------------------------------------------------
//	atomic fixed_hash_map
//-----------------------------------------------------------------------------

template<typename K, typename T, int HASH_BITS> class atomic<fixed_hash_map<K, T, HASH_BITS> > : public fixed_hash_base<atomic<hash_entry<typename hash_type<K>::type, T> >, HASH_BITS> {
	typedef typename hash_type<K>::type		H;
	typedef atomic<hash_entry<H, T> >		E;
	typedef fixed_hash_base<E, HASH_BITS>	B;
public:
	const T* check(const K &k) const {
		if (const E *e = B::check(hash(k)))
			return &e->val;
		return 0;
	}
	T&	operator[](const K &key) {
		H	k	= hash(key);
		for (;;) {
			if (E *e = B::get(k))
				return e->val;
		}
	}
	int index_of(const T *t) const {
		return t ? B::index_of(E::as_entry(t)) : -1;
	}
	T*	by_index(int i) const {
		return &B::entries[i].val;
	}
	K	key(const T *t) const {
		int	i = index_of(t);
		return i < 0 ? 0 : B::entries[i].key;
	}
	T*	remove(K k) {
		if (E *e = B::remove(hash(k)))
			return &e->val;
		return 0;
	}
	T*	remove(T *t) {
		int	i = index_of(t);
		return i < 0 ? 0 : B::remove(B::entries + i);
	}
};

//-----------------------------------------------------------------------------
//	atomic hash_map
//-----------------------------------------------------------------------------

template<typename E> class hash_map_base<atomic<E> > : public hash_map_base0<atomic<E>, atomic<uint32> > {
	typedef hash_map_base0<atomic<E>, atomic<uint32> >	B;
	using typename B::hash_t;

	atomic<int>		refs;
	Event			event;

protected:
	//using B::remove;

	void resize(uint32 newsize) {
		if (refs.cas(0, -1)) {
			event.Clear();
			B::resize(newsize);
			refs		= 0;
			event.Signal();
		}
	}

	atomic<int>* get_access() {
		for (;;) {
			int	r = refs;
			if (r < 0) {
				event.Wait();
				continue;
			}
			if (refs.cas(r, r + 1))
				break;
		}
		return &refs;
	}

	atomic<E>* get(hash_t key) {
		if (B::curr_size >= B::max_size / 2)
			resize(B::max_size * 2);
		return B::get0(B::find(key), key);
	}

	atomic<E>* remove(hash_t key) {
		if (B::num_free >= B::max_size / 2)
			resize(B::curr_size);
		return B::remove0(B::find(key), key);
	}

	hash_map_base(uint32 n = 8)				: B(n), refs(0), event(true)		{}
	hash_map_base(const hash_map_base &b)	: B(b), refs(0), event(true)		{}
#ifdef USE_RVALUE_REFS
	hash_map_base(hash_map_base &&b)		: B(move(b)), refs(0), event(true)	{}
#endif
};

struct ref_holder {
	atomic<int>	*refs;
	ref_holder()					: refs(0) {}
	ref_holder(atomic<int>	*_refs) : refs(_refs) {}
	~ref_holder()				{ if (refs) --*refs; }
};

template<typename T> struct val_ref : ref_holder {
	T			&t;
	val_ref(atomic<int> *_refs, T &_t) : ref_holder(_refs), t(_t) {}
//	operator const T&() const	{ return t; }
	operator T() const			{ return t; }
	template<typename T2> T& operator=(T2 t2) { return t = t2; }
};

template<typename T> struct ptr_ref : ref_holder {
	T			*t;
	ptr_ref() : t(0) {}
	ptr_ref(atomic<int> *_refs, T *_t) : ref_holder(_refs), t(_t) {}
//	operator T*() const			{ return t; }
	T*	operator->() const		{ return t; }
	T	operator*() const		{ return *t; }
	operator bool() const		{ return !!t; }
};

template<typename K, typename T> class atomic<hash_map<K, T> > : public hash_map_base<atomic<hash_entry<typename hash_type<K>::type, T> > > {
	typedef typename hash_type<K>::type	H;
	typedef atomic<hash_entry<H, T> >	E;
	typedef hash_map_base<E>			B;

	struct mutator {
		atomic	*a;
		H		h;
		mutator(atomic *_a, H _h) : a(_a), h(_h) {}

		operator T() const {
			for (;;) {
				if (a->curr_size >= a->max_size / 2)
					a->resize(a->max_size * 2);

				ref_holder	temp(a->get_access());
				if (E *e = a->get0(a->find(h), h))
					return e->val;
			}
		}
		template<typename T2> void operator=(T2 t2) {
			for (;;) {
				if (a->curr_size >= a->max_size / 2)
					a->resize(a->max_size * 2);

				ref_holder	temp(a->get_access());
				if (E *e = a->get0(a->find(h), h)) {
					e->val = t2;
					return;
				}
			}
		}
	};
public:

	atomic(int init = 8) : B(init) {}

#if 0
	ptr_ref<T> check(const K &key) {
		auto	refs	= B::get_access();
		if (E *e = B::check(hash(key)))
			return ptr_ref<T>(refs, &e->val);
		--*refs;
		return ptr_ref<T>();
	}
	val_ref<T>	operator[](const K &key) {
		H	k	= hash(key);
		for (;;) {
			if (B::curr_size >= B::max_size / 2)
				B::resize(B::max_size * 2);

			auto	refs	= B::get_access();
			if (E *e = B::get0(B::find(k), k))
				return val_ref<T>(refs, e->val);
			--*refs;
		}
	}
	ptr_ref<T>	remove(K key) {
		if (B::num_free >= B::max_size / 2)
			B::resize(B::curr_size);

		auto	refs	= B::get_access();
		H		k		= hash(key);
		if (E *e = B::remove0(B::find(k), k))
			return ptr_ref<T>(refs, &e->val);
		--*refs;
		return ptr_ref<T>();
	}
	ptr_ref<T>	remove(T *t) {
		auto	refs	= B::get_access();
		int		i		= index_of(t);
		if (i >= 0) {
			E	*e	= B::entries + i;
			H	k	= e->key;
			if (B::remove(e, k))
				return ptr_ref<T>(refs, t);
		}
		--*refs;
		return ptr_ref<T>();
	}
#else

	bool check(const K &key) {
		ref_holder	temp(B::get_access());
		return !!B::check(hash(key));
	}
	mutator	operator[](const K &key) {
		return mutator(this, hash(key));
	}
	bool	remove(K key) {
		if (B::num_free >= B::max_size / 2)
			B::resize(B::curr_size);

		ref_holder	temp(B::get_access());
		H		k		= hash(key);
		return !!B::remove0(B::find(k), k);
	}
	bool	remove(T *t) {
		ref_holder	temp(B::get_access());
		int		i		= index_of(t);
		if (i >= 0) {
			E	*e	= B::entries + i;
			H	k	= e->key;
			return B::remove(e, k);
		}
		return false;
	}
#endif
};

// only store hash value
template<typename K> struct atomic<hash_set_entry<K> > {
	typedef K								key_t;
	typedef typename hash_type<K>::type		hash_t;
	atomic<hash_t>		key;

	bool	cas(hash_t k0, hash_t k1) {
		return key.cas(k0, k1);
	}
	bool	set(hash_t k0, hash_t k1) {
		return key.cas(k0, k1);
	}
	void	set_val(const atomic *b)	{}
	void	set_val(const K &k)			{}
};

template<typename K> class atomic<hash_set<K> > : public hash_set_base<atomic<hash_set_entry<K> > > {
	typedef hash_set_base<atomic<hash_set_entry<K> > >	B;
public:
	atomic(int init = 8) : B(init) {}
};




}//namespace iso

#endif //ATOMIC_HASH_H
