#ifndef CG_H
#define CG_H

#include "base/array.h"
#include "base/list.h"

namespace iso { namespace cg {

template<class T, class E> struct edge : link_base<E> {
	typedef link_base<E>	B;
	E			*flip;
	T			*tri;

	struct iterator {
		E	*e;
		iterator(E *_e) : e(_e)					{}
		iterator&		operator++()			{ e = e->next; return *this; }
		iterator&		operator--()			{ e = e->prev; return *this; }
						operator E*()	const	{ return e;	}
		E*				operator->()	const	{ return e;	}
	};
	struct fan_iterator : iterator {
		using iterator::e;
		fan_iterator(E *_e) : iterator(_e)		{}
		fan_iterator&	operator++()			{ e = e->prev->flip; return *this; }
		fan_iterator&	operator--()			{ e = e->flip->next; return *this; }
	};

	void		set_flip(E *e) {
		if (flip = e)
			e->flip = (E*)this;
	}

	void		init_list()		{ B::init(); }
	edge() : flip(0)			{}
};

template<class T, class E> struct tri : fixed_array<E,3> {
	using fixed_array<E,3>::t;
	void init_links() {
		t[0].next = t[2].prev = t + 1;
		t[1].next = t[0].prev = t + 2;
		t[2].next = t[1].prev = t + 0;
	}
	tri()	{
		t[0].tri = t[1].tri = t[2].tri = static_cast<T*>(this);
		init_links();
	}
	int count_shared() const {
		return int(!!t[0].flip) + int(!!t[1].flip) + int(!!t[2].flip);
	}
};

//-----------------------------------------------------------------------------
//	welded_pair
//	pair of structures locked together (either with links, or address alignment)
//-----------------------------------------------------------------------------

template<typename T> struct welded_pair {
	T	h0, h1;
	welded_pair() : h0(&h1), h1(&h0) {}
	template<typename T2> welded_pair(const T2 &a, const T2 &b) : h0(&h1, a), h1(&h0, b) {}
};

template<typename T, bool LINK = (sizeof(T) > 16)> class welded_half;

template<typename T> class welded_half<T, false> {
	intptr_t _addr() const	{ return intptr_t(static_cast<const T*>(this)); }
public:
	typedef welded_pair<T> pair_t;
	welded_half(T *f)				{}
	T*			flip()				{ return (T*)(_addr() ^ sizeof(T)); }
	const T*	flip()		const	{ return (const T*)(_addr() ^ sizeof(T)); }
	int			side()		const	{ return int(!!(_addr() & sizeof(T))); }
	pair_t		get_pair()	const	{ return (pair_t*)(_addr() & ~sizeof(T)); }
};

template<typename T> struct welded_half<T, true> {
	T*		_flip;
public:
	typedef welded_pair<T> pair_t;
	welded_half(T *f)	: _flip(f)	{}
	T*			flip()				{ return _flip; }
	const T*	flip()		const	{ return _flip; }
	int			side()		const	{ return int(this > _flip); }
	pair_t*		get_pair()	const	{ return (pair_t*)(this < _flip ? static_cast<const T*>(this) : _flip); }
};

template<typename T> struct welded_pair<welded_half<T, false> > : aligner<sizeof(T) * 2> {
	T	h0, h1;
	welded_pair() : h0(&h1), h1(&h0) {}
	template<typename T2> welded_pair(const T2 &a, const T2 &b) : h0(&h1, a), h1(&h0, b) {}
};

} //namespace cg

template<typename T, bool LINK> struct e_link<cg::welded_half<T, LINK> > : slink_base<T> {
	typedef slink_base<T>	B;
	using B::next;

	void			unlink() {
		T	*h2						= data()->flip();
		data()->next->flip()->next	= h2->next;
		h2->next->flip()->next		= B::next;
	}

	void			insert_before(T *h) {
		T	*prev				= data()->flip()->next;
		h->flip()->next			= prev;
		prev->flip()->next		= h;
		h->next					= static_cast<T*>(this);
		data()->flip()->next	= h->flip();
	}

	void			insert_after(T *h) {
		data()->next->flip()->next	= h->flip();
		h->flip()->next				= data()->flip();
		h->next						= data()->next;
		data()->next				= h;
	}

	const T*		data()	const	{ return static_cast<T*>(this); }
	T*				data()			{ return static_cast<T*>(this); }

	~e_link()						{ unlink();		}

};

template<typename T, bool LINK> struct e_list<cg::welded_half<T, LINK> > : cg::welded_pair<T> {
	typedef cg::welded_pair<T>	B;
	typedef	T					element;
	using B::h0; using B::h1;

	class iterator : public slist_iterator_base<T, T> {
		typedef slist_iterator_base<T, T>	B;
		using B::p;
	public:
		typedef bidirectional_iterator_t	iterator_category;
		iterator(T *_p) : B(_p)	{}
		iterator(const B &b) : B(b)	{}
		iterator	operator++()			{ p = p->next; return *this;	}
		iterator	operator++(int)			{ iterator i = *this; p = p->next; return i; }
		iterator	operator--()			{ p = p->flip()->next; return *this;	}
		iterator	operator--(int)			{ iterator i = *this; p = p->flip()->next; return i; }
		T*			remove()				{ T *t = p; p = t->next; t->unlink(); return t; }
	};

	struct const_iterator : public slist_iterator_base<const T, const T> {
		typedef slist_iterator_base<const T, const T>	B;
		using B::p;
	public:
		typedef bidirectional_iterator_t	iterator_category;
		const_iterator(const T *_p) : B(_p)	{}
		const_iterator(const B &b) : B(b)	{}
		const_iterator	operator++()		{ p = p->next; return *this;	}
		const_iterator	operator++(int)		{ const_iterator i = *this; p = p->next; return i; }
		const_iterator	operator--()		{ p = p->flip()->next; return *this;	}
		const_iterator	operator--(int)		{ const_iterator i = *this; p = p->flip()->next; return i; }
	};

	e_list() {
		h0.next = &h0;
		h1.next = &h1;
	}
//	e_list(const T &a, const T &b) : B(a, b) {}

	const_iterator	begin()	const	{ return h0.next;	}
	const_iterator	end()	const	{ return &h0;		}
	iterator		begin()			{ return h0.next;	}
	iterator		end()			{ return &h0;		}
	size_t			size()	const {
		size_t	size = 0;
		for (const_iterator	i = begin(), e = end(); i != e; ++i)
			++size;
		return size;
	}
};

namespace cg {

//-----------------------------------------------------------------------------
//	edge2
//	generic half edge for traversing verts/faces
//-----------------------------------------------------------------------------

//	   \ v0_next                 / f0_next			   \ f0_prev                 / v1_prev
//	    ^          f0           ^					    v          f0           v
//	     \                     /					     \                     /
//	      \        this       /						      \        flip       /
//	-------v0-------->--------v1----------			-------v0--------<--------v1----------
//	      /                   \						      /                   \
//	     /         f1          \					     /         f1          \
//	    ^                       ^					    v                       v
//	   / f1_next                 \ v1_next			   / v0_prev                 \ f1_prev


template<typename E> struct edge2 : welded_half<E, true> {
	E*			vnext;	// next edge CCW around v0	(origin)
	E*			fnext;	// next edge CCW around f0	(left face)

	edge2(E *e) : welded_half<E, true>(e), vnext(static_cast<E*>(this)), fnext(e) {}

	E	*v0_next()	const	{ return vnext; }
	E	*f0_next()	const	{ return fnext; }
	E	*v1_next()	const	{ return this->flip()->vnext->flip(); }
	E	*f1_next()	const	{ return this->flip()->fnext->flip(); }

	E	*v0_prev()	const	{ return this->flip()->fnext; }
	E	*f0_prev()	const	{ return vnext->flip(); }
	E	*v1_prev()	const	{ return fnext->flip(); }
	E	*f1_prev()	const	{ return this->flip()->vnext; }

	// exchange a->vnext and b->vnext
	friend void splice(E *a, E *b) {
		E *anext = a->vnext;
		E *bnext = b->vnext;
		anext->flip()->fnext = b;
		bnext->flip()->fnext = a;
		a->vnext = bnext;
		b->vnext = anext;
	}

	bool validate() const {
		return this->flip()			!= this
			&& this->flip()->flip()	== this
			&& fnext->vnext->flip()	== this
			&& vnext->flip()->fnext	== this;
	}
};

//-----------------------------------------------------------------------------
//	mesh
//-----------------------------------------------------------------------------

template<typename V, typename E, typename F> struct mesh {
	struct vertex;
	struct face;
	
	struct edge : edge2<edge>, e_link<welded_half<edge, true> >, E {
		vertex*		v;		// origin vertex
		face*		f;		// left f
		edge(edge *e) : edge2<edge>(e), v(0), f(0) {}

		vertex	*v0()		const	{ return v; }
		vertex	*v1()		const	{ return this->flip()->v; }
		face	*f0()		const	{ return f; }
		face	*f1()		const	{ return this->flip()->f; }
	};

	struct vertex : V, e_link<vertex> {
		edge	*e;

		vertex(edge *_e) : e(_e) {
			edge	*i = e;
			do {
				i->v = this;
				i = i->vnext;
			} while (i != e);
		}
		void	kill(vertex *v = 0) {
			edge *i = e;
			do {
				i->v = v;
				i = i->vnext;
			} while (i != e);
			delete this;
		}
	};

	struct face : e_link<face>, F {
		edge	*e;

		face(edge *_e) : e(_e) {
			edge *i = e;
			do {
				i->f = this;
				i = i->fnext;
			} while (i != e);
		}
		void	kill(face *f = 0) {
			edge *i = e;
			do {
				i->f = f;
				i = i->fnext;
			} while (i != e);
			delete this;
		}

		void zap() {
			edge	*n = e->fnext, *i;
			do {
				i		= n;
				n		= i->fnext;
				i->f	= 0;

				// delete edges whose right face is also NULL
				if (!i->f1()) {
					if (i->vnext == i) {
						i->v->kill();
					} else {
						// Make sure that i->v points to a valid half-edge
						i->v->e = i->vnext;
						splice(i, i->v0_prev());
					}
					edge	*i2 = e->flip();
					if (i2->vnext == i2) {
						i2->v->kill();
					} else {
						// Make sure that i2->v points to a valid half-edge
						i2->v->e = i2->vnext;
						splice(i2, i2->v0_prev());
					}
					delete i;
				}
			} while (i != e);

			delete this;
		}
	};


	static void		splice_edges(edge *e0, edge *e1);
	static edge*	connect_edges(edge *e0, edge *e1);
	static void		delete_edge(edge *e);
	static edge*	split_edge(edge *e);
	edge*			make_edge();
	void			remove_degenerate_edges();
	bool			validate();

	e_list<vertex>						verts;
	e_list<face>						faces;
	e_list<welded_half<edge, true> >	edges;

	mesh() {
		edges.h0.next = &edges.h0;
		edges.h1.next = &edges.h1;
	}

	mesh& operator|=(mesh<V,E,F> &&mesh2);
};

// Create one edge, two vertices, and a face
template<typename V, typename E, typename F> typename mesh<V,E,F>::edge *mesh<V,E,F>::make_edge() {
	auto	*pair	= new typename edge::pair_t;
	edge	*ea		= &pair->h0;
	edge	*eb		= &pair->h1;
	edges.h0.insert_before(ea);

	vertex	*v0		= new vertex(ea);
	vertex	*v1		= new vertex(eb);
	face	*f		= new face(ea);

	verts.push_back(v0);
	verts.push_back(v1);
	faces.push_back(f);

	return ea;
}

// Remove an edge
// if e->f0() != e->f1(), we join two faces into one and e->f0() is deleted; else we split the face into two
template<typename V, typename E, typename F> void mesh<V,E,F>::delete_edge(edge *e) {
	face	*f1				= e->f1();
	bool	joining_faces	= e->f0() != f1;

	// disconnect the origin vertex v; we make all changes to get a consistent mesh in this "intermediate" state
	if (joining_faces)
		e->f0()->kill(f1);			// joining two faces into one -- remove the left face

	if (e->vnext == e) {
		e->v0()->kill();

	} else {
		// ensure that v0 and f1 point to valid half-edges
		f1->e		= e->flip()->fnext;
		e->v0()->e	= e->vnext;

		splice(e, e->flip()->fnext);
		if (!joining_faces)
			f1->insert_before(new face(e));	// splitting one face into two -- create new face (insert_before so algorithms don't see newly created face)
	}

	// Claim: the mesh is now in a consistent state, except that v may have been deleted. Now we disconnect v1
	if (e->flip()->vnext == e->flip()) {
		e->v1()->kill();
		e->f1()->kill();
	} else {
		e->f0()->e	= e->fnext;
		e->v1()->e	= e->flip()->vnext;
		splice(e->flip(), e->fnext);
	}
	
	delete e->get_pair();
}

// Change the mesh so that:
// e0->vnext = OLD(e1->vnext)
// e1->vnext = OLD(e0->vnext)
// if e0->v == e1->v, v is split into two, else the verts are merged together
// if e0->f == e1->f, f is split into two, else the faces are joined into one
template<typename V, typename E, typename F> void mesh<V,E,F>::splice_edges(edge *e0, edge *e1) {
	if (e0 != e1) {
		vertex	*v0				= e0->v;
		face	*f0				= e0->f;
		bool	joining_verts	= e1->v != v0;
		bool	joining_faces	= e1->f != f0;

		if (joining_verts)
			e1->v->kill(v0);	// merging two disjoint vertices -- destroy e1->v
		if (joining_faces)
			e1->f->kill(f0);	// connecting two disjoint faces -- destroy e1->f

		// Change the edge structure
		splice(e1, e0);

		if (!joining_verts) {
			v0->insert_before(new vertex(e1));	// split one vert into two -- new vert is e1->v (insert_before so algorithms don't see newly created vert)
			v0->e	= e0;
		}
		if (!joining_faces) {
			f0->insert_before(new face(e1));	// split one face into two -- new face is e1->f (insert_before so algorithms don't see newly created face)
			f0->e	= e0;
		}
	}
}

// Split e into two edges e and eb, such that eb == e->fnext
// the new vertex is e->v1() == eb->v0()
// e and eb will have the same left face
template<typename V, typename E, typename F> typename mesh<V,E,F>::edge *mesh<V,E,F>::split_edge(edge *e) {
	auto	*pair	= new typename edge::pair_t;
	edge	*ea		= &pair->h0;
	edge	*eb		= &pair->h1;
	e->insert_before(ea);

	// Connect the new edge appropriately
	splice(ea, e->fnext);

	// Set the vertex and f information
	ea->v	= e->v1();
	ea->v->insert_before(new vertex(eb));		// insert_before so algorithms don't see newly created vert
	eb->f	= e->f;
	ea->f	= e->flip()->f;

	// Disconnect e from e->v1() and connect it to eb->v
	splice(e->flip(), e->fnext);
	splice(e->flip(), eb);

	e->flip()->v	= eb->v;
	ea->v->e		= ea;	// may have pointed to e->flip()
	return eb;
}

// Create a new edge from e0->v1() to e1->v0(), and return the corresponding half-edge
// if e0->f == e1->f, this splits one face into two and the newly created face is eb->f
// otherwise, two disjoint faces are merged into one, and e1->f is destroyed
template<typename V, typename E, typename F> typename mesh<V,E,F>::edge *mesh<V,E,F>::connect_edges(edge *e0, edge *e1) {
	auto	*pair	= new typename edge::pair_t;
	edge	*ea		= &pair->h0;
	edge	*eb		= &pair->h1;
	e0->insert_before(ea);

	face	*f0		= e0->f;
	bool	joining_faces = e1->f != f0;
	if (joining_faces)
		e1->f->kill(f0);		// connecting two disjoint faces -- destroy e1->f

	// Connect the new edge appropriately
	splice(ea, e0->fnext);
	splice(eb, e1);

	// Set the vertex and f information
	ea->v	= e0->v1();
	eb->v	= e1->v0();
	ea->f	= eb->f = f0;

	// Make sure the old f points to a valid half-edge
	f0->e		= eb;

	if (!joining_faces)		// split one face into two -- new face is ea->Lface
		f0->insert_before(new face(ea));		// insert_before so algorithms don't see newly created face
	return ea;
}

// Remove zero-length edges, and contours with fewer than 3 vertices
// (requires verts have == operator)
template<typename V, typename E, typename F> void mesh<V,E,F>::remove_degenerate_edges() {
	for (edge *e = edges.h0.next, *enext, *fnext; e != &edges.h0; e = enext) {
		enext	= e->next;
		fnext	= e->fnext;

		if (*e->v0() == *e->v1() && fnext->fnext != e) {
			// zero-length edge, contour has at least 3 edges
			splice_edges(fnext, e);	// deletes e->v
			delete_edge(e);
			e		= fnext;
			fnext	= e->fnext;
		}

		if (fnext->fnext == e) {
			// degenerate contour (one or two edges)
			if (fnext != e) {
				if (fnext == enext || fnext == enext->flip())
					enext = enext->next;
				delete_edge(fnext);
			}
			if (e == enext || e == enext->flip())
				enext = enext->next;

			delete_edge(e);
		}
	}
}

template<typename V, typename E, typename F> bool mesh<V, E, F>::validate() {
	for (auto f = faces.begin(); f != faces.end(); ++f) {
		edge	*e = f->e;
		do {
			if (!e->validate())
				return false;
			if (e->f != f)
				return false;
			e = e->fnext;
		} while (e != f->e);
	}

	for (auto v = verts.begin(); v != verts.end(); ++v) {
		edge	*e = v->e;
		do {
			if (!e->validate())
				return false;
			if (e->v != v)
				return false;
			e = e->vnext;
		} while (e != v->e);
	}

	for (edge *e = edges.h0.next; e != &edges.h0; e = e->next) {
		if (!e->validate())
			return false;
		if (!e->v)
			return false;
		if (!e->f)
			return false;
	}
	return true;
}

template<typename V, typename E, typename F> mesh<V,E,F>& mesh<V,E,F>::operator|=(mesh<V,E,F> &&mesh2) {
	// Add the faces, vertices, and edges of mesh2 to those of mesh1
	faces.end().insert(mesh2.faces);
	verts.end().insert(mesh2.verts);
	edges.end().insert(mesh2.edges);
	return *this;
}


} } //namespace iso::cg
#endif // CG_H
