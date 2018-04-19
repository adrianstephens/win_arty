#ifndef GRAPH_H
#define GRAPH_H

#include "base/defs.h"
#include "base/hash.h"
#include "base/list.h"
#include "base/algorithm.h"
#include "comp_geom.h"

namespace iso {

//-----------------------------------------------------------------------------
//	graph_edges
//-----------------------------------------------------------------------------

#if 1

template<class E> struct graph_edges0 {
	struct edge : slink_base<edge>, cg::welded_half<edge, true> {
		E			e;
		edge(edge *f)				: cg::welded_half<edge, true>(f) {}
		edge(edge *f, const E &_e)	: cg::welded_half<edge, true>(f), e(_e) {}
		const E*	data()	const	{ return &e; }
		E*			data()			{ return &e; }
	};

	typedef	slist_base<E, edge>		edges_t;
	typedef typename edge::pair_t	edge_pair_t;
	
	edges_t outgoing, incoming;

	friend edge_pair_t *add(graph_edges0 *from, graph_edges0 *to) {
		auto	*pair	= new typename edge::pair_t;
		from->outgoing.push_front(&pair->h0);
		to->incoming.push_front(&pair->h1);
		return pair;
	}
	friend edge_pair_t *add(graph_edges0 *from, graph_edges0 *to, const E &a, const E &b) {
		auto	*pair	= new edge_pair_t(a, b);
		from->outgoing.push_front(&pair->h0);
		to->incoming.push_front(&pair->h1);
		return pair;
	}

	friend bool remove(edge *e, graph_edges0 *from, graph_edges0 *to) {
		if (auto prev = from->outgoing.prev(e)) {
			prev->unlink_next();
			if (auto prev = to->incoming.prev(e->flip())) {
				prev->unlink_next();
				delete e;
				return true;
			}
		}
		return false;
	}

	~graph_edges0() {
		while (!outgoing.empty())
			outgoing.pop_front();
		while (!incoming.empty())
			incoming.pop_front();
	}

	friend edges_t&			outgoing(graph_edges0 &p)		{ return p.outgoing; }
	friend edges_t&			incoming(graph_edges0 &p)		{ return p.incoming; }
	friend const edges_t&	outgoing(const graph_edges0 &p)	{ return p.outgoing; }
	friend const edges_t&	incoming(const graph_edges0 &p)	{ return p.incoming; }
};


template<class N> struct graph_edges : graph_edges0<N*> {
	typedef graph_edges0<N*>	B;
	using typename B::edges_t;
	using B::outgoing;
	using B::incoming;

	~graph_edges() {
#if 1
#elif 1
		while (!outgoing.empty()) {
			auto	j = outgoing.begin();
			if (!remove(j.link(), this, *j))
				break;
		}
		while (!incoming.empty()) {
			auto	j = incoming.begin();
			if (!remove(j.link(), this, *j))
				break;
		}
#else
		for (auto i = outgoing.begin(); i != outgoing.end();) {
			auto	j = i++;
			remove(j.link(), this, *j);
		}
		for (auto i = incoming.begin(); i != incoming.end();) {
			auto	j = i++;
			remove(j.link(), *j, this);
		}
#endif
	}

	void	add_edge(N *to) {
		add(this, to, to, static_cast<N*>(this));
	}
	bool	remove_edge(N *to) {
		auto	e	= find(outgoing, to);
		return remove(e.link(), this, to);
	}

	void	merge(edges_t &dest, edges_t &srce) {
		while (!srce.empty()) {
			auto i			= srce.pop_front();
			i->flip()->e	= static_cast<N*>(this);
			dest.push_front(i);
		}
	}
	void merge(N *srce) {
		remove_edge(srce);
		merge(outgoing, srce->outgoing);
		merge(incoming, srce->incoming);
	}
};

#else

template<class N> struct graph_edges {
	typedef slink<N*>							link_t;
	typedef	slist_iterator_basep<N*, link_t>	iteratorp;

	struct edge : aligner<sizeof(link_t) * 2> {
		link_t	h0, h1;
		edge(N *a, N *b) : h0(b), h1(a) {}
	};

	class iterator : public slist_iterator_base<N*, link_t> {
		typedef slist_iterator_base<N*, link_t> B;
	public:
		iterator(link_t *p)			: B(p) {}
		iterator(const B &b)		: B(b) {}
		iterator		flip()			const	{ return (link_t*)(intptr_t(B::p) ^ sizeof(link_t)); }
		int				side()			const	{ return int(!!(intptr_t(B::p) & sizeof(link_t))); }
		edge*			get_edge()		const	{ return (edge*)(intptr_t(B::p) & ~sizeof(link_t)); }
		link_t*			get_link()		const	{ return B::p; }
	};

	typedef slist_iterator_base<N *const, const link_t> const_iterator;
	/*
	class const_iterator : public slist_iterator_base<N *const, const link_t> {
		typedef slist_iterator_base<N *const, const link_t> B;
	public:
		const_iterator(link_t *p)	: B(p) {}
		const_iterator(const B &b)	: B(b) {}
		const_iterator	flip()			const	{ return (const link_t*)(intptr_t(B::p) ^ sizeof(link_t)); }
		int				side()			const	{ return int(!!(intptr_t(B::p) & sizeof(link_t))); }
		const edge*		get_edge()		const	{ return (const edge*)(intptr_t(B::p) & ~sizeof(link_t)); }
	};
	*/
	struct edges_t : slist_base<N*, link_t> {
		typedef slist_base<N*, link_t>	B;
		typedef typename graph_edges::iterator	iterator;
		const_iterator	begin()		const	{ return B::begin(); }
		const_iterator	end()		const	{ return B::end(); }
		iterator		begin()				{ return B::begin(); }
		iterator		end()				{ return B::end(); }

		void		remove(iterator x) {
			auto	e	= end();
			for (iteratorp i = B::beginp(); i != e; ++i) {
				if (i == x) {
					i.unlink();
					break;
				}
			}
		}

		void		remove_all(int other) {
			while (!B::empty()) {
				iterator	i = B::pop_front();
				(*i)->edges[other].remove(i.flip());
			}
		}

		iteratorp	find(const N *to) {
			auto		e	= end();
			iteratorp	i	= B::beginp();
			while (i != e && *i != to)
				++i;
			return i;
		}

		void		merge(edges_t &srce, N *n) {
			while (!srce.empty()) {
				iterator i = srce.pop_front();
				*i.flip() = n;
				B::push_front(i.get_link());
			}
		}
	};

	edges_t	edges[2];

	~graph_edges() {
		edges[0].remove_all(1);
		edges[1].remove_all(0);
	}

	void add_edge(N *to) {
		edge *e = new edge(static_cast<N*>(this), to);
		edges[0].push_front(&e->h0);
		to->edges[1].push_front(&e->h1);
	}
	void remove_edge(iteratorp ip) const {
		iterator	i	= ip.unlink();
		(*i)->edges[1].remove(i.flip());
		delete i.get_edge();
	}

	bool remove_edge(const N *to) {
		iteratorp	ip	= edges[0].find(to);
		if (ip == edges[0].end())
			return false;
		remove_edge(ip);
		return true;
	}

	void merge(N *srce) {
		remove_edge(srce);
		edges[0].merge(srce->edges[0], static_cast<N*>(this));
		edges[1].merge(srce->edges[1], static_cast<N*>(this));
	}

	friend edges_t& outgoing(graph_edges &p) { return p.edges[0]; }
	friend edges_t& incoming(graph_edges &p) { return p.edges[1]; }
	friend const edges_t& outgoing(const graph_edges &p) { return p.edges[0]; }
	friend const edges_t& incoming(const graph_edges &p) { return p.edges[1]; }
};
#endif

template<typename T> const typename T::edges_t& outgoing(const _not<T> &p) { return incoming(p.t); }
template<typename T> const typename T::edges_t& incoming(const _not<T> &p) { return outgoing(p.t); }

//-----------------------------------------------------------------------------
//	union_find
//	efficient technique for	tracking equivalence classes as	pairs of elements are incrementally	unified	into the same class.
//	Uses path compression but without weight-balancing -> worst case O(nlogn), good case O(n)
//-----------------------------------------------------------------------------
template<typename T> class union_find {
	hash_map<T, T>	m;

	bool	irep(T e, T &representative) {
		if (T *p = m.check(e)) {
			T	r	= *p;
			T	t	= e;

			while (r !=	t)
				r = m[t = r];

			while (e !=	r) {
				swap(t = r, m[e]);
				e = t;
			}
			representative = r;
			return true;
		}
		return false;
	}
public:
	void clear() { m.clear(); }
	// put these two elements in the same class; returns true if were different
	bool unify(T e1, T e2) {
		if (e1 == e2)
			return false;

		T	r1, r2;
		if (!irep(e1, r1))
			m[r1 = e1] = e1;

		if (!irep(e2, r2))
			m[r2 = e2] = e2;

		if (r1 == r2)
			return false;

		m[r1] = r2;
		return true;
	}
	// are two elements	in the same	equivalence	class?
	bool equal(T e1, T e2) {
		T	r1, r2;
		return	e1 == e2
			||	(irep(e1, r1) && irep(e2, r2) && r1 == r2);
	}
	// only	valid until	next unify()
	T	representative(T e) {
		T	r;
		return irep(e, r) ? r : e;
	}
};

//-----------------------------------------------------------------------------
//	graph
//-----------------------------------------------------------------------------

template<typename N> struct graph_base {
	typedef N				node_t;
	dynamic_array<N*>		nodes;

	N *add_node(N *n) {
		nodes.push_back(n);
		return n;
	}
};

template<typename T> struct graph_node : graph_edges<graph_node<T> > {
	T	t;
	graph_node(const T &_t) : t(_t) {}
};

template<typename T, typename N = graph_node<T> > struct graph : graph_base<N> {
	typedef graph_base<N> B;
	using typename B::node_t;

	graph() {}

	graph(T *p, size_t n) {
		B::nodes.reserve(n);
		while (n--)
			add_node(*p++);
	}
	template<typename I> graph(I begin, I end) {
		B::nodes.reserve(distance(begin, end));
		while (begin != end) {
			add_node(*begin);
			++begin;
		}
	}

	node_t *add_node(const T &t) {
		return B::add_node(new node_t(t));
	}
};

//-----------------------------------------------------------------------------
// Kruskal MinimumSpanningTree
// Given a graph gnew consisting solely of vertices, computes the minimum spanning tree of undirected over the vertices in unconnected under the cost metric f
// Kruskal's algorithm, O(e log(e)) (Prim's algorithm is recommended when e=~n^2, see below)
//-----------------------------------------------------------------------------
#if 0
template<typename T, typename F=float(const T&, const T&)> bool kruskal_mst(graph<T> &undirected, graph<T> &unconnected, F f) {
	struct Edge {
		T		v1, v2;
		float	w;
		Edge(T &_v1, T &_v2, float _w) : v1(_v1), v2(_v2), w(_w) {}
	};

	dynamic_array<Edge> edges;
	for (auto &v1 : unconnected.nodes) {
		for (auto &v2 : outgoing(v1)) {
			if (v1 >= v2)
				new(edges) Edge(v1, v2, f(v1, v2));
		}
	}

	sort(edges, [](const Edge &a, const Edge &b) { return a.w < b.w; });
    
	union_find<T>	uf;
	int				added = 0;
	for (const Edge &i : edges) {
		if (uf.unify(i.v1, i.v2)) {
			i.v1.add_edge(i.v2);
			if (++added == num_vertices - 1)
				return true;
		}
	}
	return false;
}
#endif
// Returns an undirected graph that is the MST of undirected, or empty if g is not connected.
template<typename T, typename F=float(const T&, const T&)> graph<T> graph_mst(const graph<T> &undirected, F f) {
	graph<T>	g;
	for (const T& v : undirected.vertices())
		g.add(v);

	if (!graph_mst(undirected, f, g))
		g.clear();
	return g;
}


//-----------------------------------------------------------------------------
// Prim MinimumSpanningTree
// Returns a undirected graph that is the minimum spanning tree of the full graph between the num points, where the cost metric between two points v1 and v2 is f(v1, v2)
// Prim's algorithm, complexity O(n^2)
//-----------------------------------------------------------------------------

template<typename I> struct min_s_it {
	I										besti;
	typename iterator_traits<I>::element	bestv;
	min_s_it(I i) : besti(i), bestv(*i) {}
	void operator()(I i)	{
		if (*i < bestv) {
			besti	= i;
			bestv	= *i;
		}
	}
	operator I() const {
		return besti;
	}
};

template<template<class> class F, class I> inline F<I> for_each_it(I i, I end) {
	F<I>	f(i);
	for (++i; i != end; ++i)
		f(i);
	return f;
}
template<template<class> class F, class C> inline F<typename container_traits<C>::iterator> for_each_it(const C &c) {
	typedef typename container_traits<C>::iterator I;
	I		i	= c.begin(), end = c.end();
	F<I>	f(i);
	for (++i; i != end; ++i)
		f(i);
	return f;
}
template<typename F=float(int, int)> graph<int> prim_mst(int num, F f) {
	const float k_inf = 1e30f;
	dynamic_array<float>	lowcost(num);
	dynamic_array<int>		closest(num);

	graph<int> g(int_iterator<int>(0), int_iterator<int>(num));

	for (int i = 1; i < num; i++) {
		lowcost[i] = f(0, i);
		closest[i] = 0;
	}

	for (int i = 1; i < num; i++) {
		auto	minj	= for_each_it<min_s_it>(sub_range(lowcost, 1));
		ISO_ASSERT(*minj < k_inf);
		*minj = k_inf;

		int		mini	= lowcost.index_of(minj);
		g.nodes[mini]->add_edge(g.nodes[closest[mini]]);

		for (int j = 1; i < num; i++) {
			if (lowcost[j] != k_inf) {
				float pnd = f(mini, j);
				if (pnd < lowcost[j]) {
					lowcost[j] = pnd;
					closest[j] = mini;
				}
			}
		}
	}
	return g;
}

// Colour a graph (heuristically since optimal is NP-hard)
template<typename T> int graph_colour(const graph_base<T> &g, hash_map<T, int> &colours) {
	int num_colors = 0;

	colours.clear();
	for (const T& vv : g.nodes) {
		if (colours.check(vv))
			continue;

		colours[vv] = 0;

		dynamic_circular_buffer<T> queue;
		queue.push_back(vv);
		while (!queue.empty()) {
			T v = queue.front();
			queue.pop_front();
			ISO_ASSERT(colours[v] == 0);

			hash_set<int> setcol;
			for (const T& v2 : outgoing(v)) {
				if (T *col2 = colours.check(v2)) {
					if (*col2)
						setcol.insert(*col2);
				} else {
					queue.push_back(v2);
				}
			}

			int col = 1;
			while (setcol.count(col))
				col++;
			colours[v] = col;

			if (col > num_colors)
				num_colors = col;
		}
	}
	return num_colors;
}

//-----------------------------------------------------------------------------
//	postorder - container adapter for postorder traversal
//-----------------------------------------------------------------------------

template<class T, class S = small_set<const T*, 8> > struct postorder {
	typedef	typename T_noref<decltype(outgoing(*(T*)0))>::type	C;
	typedef typename container_traits<C>::const_iterator		I;
public:
	struct iterators {
		I		i, e;
		iterators(const C &c) : i(iso::begin(c)), e(iso::end(c)) {}
		bool	empty()	const	{ return i == e; }
	};
	struct entry : iterators {
		const T	*t;
		entry(const T *_t) : iterators(outgoing(*_t)), t(_t) {}
	};
	dynamic_array<entry>	stack;
	S						visited;

	void traverse_child() {
		while (!stack.back().empty()) {
			T *t = *stack.back().i++;
			if (!visited.check_insert(t))
				stack.push_back(t);
		}
	}
	size_t next() {
		stack.pop_back();
		if (!stack.empty())
			traverse_child();
		return stack.size();
	}
	const T* get() const {
		return stack.back().t;
	}

	struct iterator {
		typedef T					*element, *&reference;
		typedef forward_iterator_t	iterator_category;
		postorder	&p;
		size_t		depth;
		iterator(postorder &_p, size_t _depth) : p(_p), depth(_depth) {}
		bool operator==(const iterator &b)	const	{ return depth == b.depth; }
		bool operator!=(const iterator &b)	const	{ return !(*this == b); }
		const T*	operator*()				const	{ return p.get(); }
		const T*	operator->()			const	{ return p.get(); }
		iterator&	operator++()					{ depth = p.next(); return *this; }
	};

	postorder(const T *t) {
		visited.insert(t);
		stack.push_back(t);
		traverse_child();
	}

	iterator	begin() { return iterator(*this, stack.size()); }
	iterator	end()	{ return iterator(*this, 0); }
};

template<typename C> constexpr inline size_t num_elements(C &&c) {
	return distance(begin(c), end(c));
}

template<class T> postorder<T> make_postorder(T *t) {
	return postorder<T>(t);
}

template<class N> void assign_graph_orders(N *n, uint32 &k) {
	n->order = 1;
	for (auto i = n->edges; i; ++i) {
		if (i->order == 0)
			assign_graph_orders(*i, k);
	}
	n->order = ++k;
}
template<class N> void assign_graph_orders(const dynamic_array<N*> &nodes) {
	for (auto i : nodes)
		i->order = 0;
	uint32		k = 0;
	for (auto i : nodes) {
		if (i->order == 0)
			assign_graph_orders(*i, k);
	}
}
template<class N> void topologic_sort(const dynamic_array<N*> &nodes, dynamic_array<N*> &sorted) {
	assign_graph_orders(nodes);
	uint32	n = nodes.size();
	for (auto i : nodes)
		sorted[n - i->order] = i;
}

template<class N> bool test_acyclic(const dynamic_array<N*> &nodes) {
	assign_graph_orders(nodes);
	for (auto i : nodes) {
		uint32	iorder = i->order;
		for (auto j = i->edges; j; ++j) {
			if (iorder >= j->order)
				return false;
		}
	}
	return true;
}

template<class N> void dijkstra(const dynamic_array<N*> &nodes) {
	priority_queue<N*, dynamic_array<N*> >	q;

	struct node {
		float	dist;
		N		*node;
		int		potnode;
	};

}

//-----------------------------------------------------------------------------
//	DominatorTree
//	Based on: "A Simple, Fast Dominance Algorithm" by Cooper, Harvey and Kennedy
//-----------------------------------------------------------------------------
template<typename N> class DominatorTree {
public:
	struct Info {
		const N					*node;
		int						pre_order;
		int						post_order;
		Info					*idom;	// Immediate dominator
		dynamic_array<Info*>	preds;	// predecessor blocks (in CFG)
		dynamic_array<Info*>	doms;	// dominated blocks

		Info(const N *_node) : node(_node), idom(0) {}

		friend const dynamic_array<Info*>& outgoing(const Info &t) { return t.doms; }
	};

	hash_map<const N*, Info*>	info_map;
	dynamic_array<Info*>		infos;
	Info*						info_root;

private:
	static size_t count_nodes(const N *n) {
		return num_elements(make_postorder(n));
	}
	void init_info(const N *n, Info *info, uint32 &order) {
		info->pre_order = ++order;
		for (auto &i : outgoing(*n)) {
			Info *info2	= info_map[i];
			if (!info2) {
				info_map[i]	= info2 = new Info(i);
				init_info(i, info2, order);
			}
			info2->preds.push_back(info);
		}
		info->post_order = ++order;
		infos.push_back(info);
	}

	Info *intersect(Info *info1, Info *info2) {
		if (info1) {
			while (info1 != info2) {
				while (info1->post_order < info2->post_order) {
					info1 = info1->idom;
					if (!info1)
						return info2;
				}
				while (info2->post_order < info1->post_order) {
					info2 = info2->idom;
					if (!info2)
						return info1;
				}
			}
		}
		return info2;
	}

	void find_dominators(uint32 &order) {
		info_root->idom	= info_root;
		bool changed;
		do {
			changed = false;
			// Iterate over the list in reverse order, i.e., forward on CFG edges.
			for (auto &i : make_reversed(infos)) {
				Info *new_idom = 0;

				for (auto &p : i->preds)
					new_idom = intersect(new_idom, p);

				// Check if the idom value has changed.
				if (new_idom && new_idom != i->idom) {
					i->idom = new_idom;
					changed = true;
				}
			}
		} while (changed);
		info_root->idom	= 0;
	}

	static bool _dominates(const Info *a, const Info *b) {
	#if 0
		return a->pre_order <= b->pre_order && a->post_order >= b->post_order;
	#else
		if (a->post_order >= b->post_order) {
			for (const Info *i = b; i; i = i->idom) {
				if (i == a)
					return true;
			}
		}
		return false;
	#endif
	}

	void create(const N *root) {
		uint32	order	= 0;
		info_map[root]	= info_root = new Info(root);
		init_info(root, info_root, order);
		find_dominators(order);

		for (auto i : infos) {
			if (Info *idom = i->idom)
				idom->doms.push_back(i);
		}
	}

public:
	DominatorTree(const N *root) {
		size_t n0 = count_nodes(root);
		create(root);
		ISO_ASSERT(n0 == infos.size());
	}

	void	recreate(const N *root) {
		infos.clear();
		info_map.clear();
		create(root);
	}

	const Info	*get_info(const N *n) const {
		auto	*p = info_map.check(n);
		return p ? *p : 0;
	}
	static const N	*get_node(const Info *i) {
		return i ? i->node : 0;
	}

	const Info	*operator[](const N *n) const {
		return get_info(n);
	}

	bool is_acyclic() const {
		for (auto i : infos) {
			uint32	iorder = i->post_order;
			for (auto j : outgoing(*i->node)) {
				if (iorder >= get_info(j)->post_order)
					return false;
			}
		}
		return true;
	}

	static bool dominates(const Info *a, const Info *b) {
		return !b || a == b || (a && _dominates(a, b));
	}
	static bool properly_dominates(const Info *a, const Info *b) {
		return a && b && a != b && _dominates(a, b);
	}
	bool dominates(const N *a, const N *b) const {
		return a == b || dominates(get_info(a), get_info(b));
	}
	bool properly_dominates(const N *a, const N *b) {
		return a != b && dominates(get_info(a), get_info(b));
	}

	const Info *nearest_common_dominator(const Info *a, const Info *b) const {
		if (a == info_root || b == info_root)
			return info_root;

		for (const Info *i = a; i; i = i->idom) {
			if (_dominates(i, b))
				return i;
		}
		return 0;
	}
	const N *nearest_common_dominator(const N *a, const N *b) const {
		return get_node(nearest_common_dominator(get_info(a), get_info(b)));
	}
	const N *idom(const N *a) const {
		return get_node(get_info(a)->idom);
	}
	bool single_entering_block(Info *n) const {
		return count(n->preds, [this, n](Info *i) { return !dominates(n, i); }) == 1;
	}
	bool single_entering_block(const N *n) const {
		return single_entering_block(get_info(n));
	}

	hash_set2<const N*> dominated_nodes(N *head) const {
		hash_set2<const N*>		result;

		if (const Info *i = get_info(head)) {
			dynamic_array<const Info*>	work_list;
			work_list.push_back(i);

			while (!work_list.empty()) {
				const Info	*i	= work_list.pop_back_retref();
				for (auto &j : i->doms) {
					result.insert(j->node);
					work_list.push_back(j);
				}
			}
		}
		return result;
	}
	
	hash_set2<const N*> dominance_frontier(const N *head) const {
		hash_set2<const N*>		result;

		if (const Info *i = get_info(head)) {
			dynamic_array<const Info*>	work_list;
			work_list.push_back(i);

			while (!work_list.empty()) {
				const Info	*i	= work_list.pop_back_retref();
				for (auto &j : i->doms)
					work_list.push_back(j);

				for (auto &j : outgoing(*i->node)) {
					if (!dominates(i, get_info(j)))
						result.insert(j);
				}
			}
		}
		return result;
	}

	hash_set2<const N*> back_edges(const N *head) const {
		hash_set2<const N*>		result;

		if (const Info *i = get_info(head)) {
			for (auto &j : i->preds) {
				if (dominates(i, j))
					result.insert(j->node);
			}
		}
		return result;
	}
	hash_set2<const N*> back_edges2(const N *head) const {
		hash_set2<const N*>		result;
		for (auto &j : incoming(*head)) {
			if (dominates(head, j))
				result.insert(j);
		}
		return result;
	}
};

}

#endif
