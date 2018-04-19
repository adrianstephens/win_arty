template<typename T, T... VV>		struct value_list { enum {count = sizeof...(VV)}; typedef value_list type; };

template<typename T, typename S, size_t len, T... VV>	struct explode : explode<T, S, len - 1, S::array[len - 1], VV...> {};
template<typename T, typename S, T... VV>				struct explode<T, S, 0, VV...> : value_list<T, VV...> {};

template<typename U, typename V = value_list<char> >	struct fix_constexpr_name;
template<char u, char... uu, char... vv>	struct fix_constexpr_name<value_list<char, u, uu...>,			value_list<char, vv...> >	: fix_constexpr_name<value_list<char, uu...>, value_list<char, vv..., u> >		{};
template<char... uu, char... vv>			struct fix_constexpr_name<value_list<char, ':', ':', uu...>,	value_list<char, vv...> >	: fix_constexpr_name<value_list<char, uu...>, value_list<char, vv...> >	{};
template<char u0, char u1, char... vv>		struct fix_constexpr_name<value_list<char, u0, u1>,				value_list<char, vv...> >	: value_list<char, vv..., u0, u1>		{};
template<char... vv>						struct fix_constexpr_name<value_list<char>,						value_list<char, vv...> >	: value_list<char, vv...>		{};


template<typename T, size_t N> struct constexpr_array {
	T t[N];
	constexpr size_t	size()					const	noexcept { return N; }
	constexpr const T&	operator[](size_t i)	const	noexcept { return t[i]; }
	constexpr T&		operator[](size_t i)			noexcept { return t[i]; }
	constexpr const T*	data()					const	noexcept { return t; }
};

template<typename T, T... v>							constexpr constexpr_array<T, sizeof...(v)>				make_constexpr_array(const value_list<T, v...> &vals)	{ return {{v...}}; }


template<typename T> struct get_constexpr_name_s {
	constexpr static auto f() { return __FUNCSIG__; }//make_constexpr_string(__FUNCSIG__); };
	constexpr static auto array{f()};
};
template<class T> constexpr auto get_constexpr_name() {
	return make_constexpr_array(
		fix_constexpr_name<typename explode<char, get_constexpr_name_s<T>, sizeof(get_constexpr_name_s<T>::array)>::type>()
	);
}

struct Test {
	static constexpr auto name = get_constexpr_name<Test>();
	Test() {
	}
} test;