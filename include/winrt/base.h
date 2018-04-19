#pragma once

#ifdef WINRT_DEBUG_REFS
#include "hook_stack.h"
#endif

#include "windows.foundation.h"
#include <typeinfo>

#pragma comment(lib, "runtimeobject.lib")

namespace iso_winrt {
using namespace iso;

/*

template<typename T, typename F = IActivationFactory> F *get_activation_factory() {
	struct factory : com_ptr<F> {
		factory() {
			HRESULT	hr = RoGetActivationFactory(hstring_ref(name<T>::s), uuidof<F>(), (void**)this);
		}
	};
	static factory f;
	return f;
}
template<typename T> com_ptr<T> activate_instance0() {
	com_ptr<T>	t;
	HRESULT		hr = RoActivateInstance(hstring_ref(name<T>::s), (IInspectable**)&t);
	return t;
}

template<typename T> com_ptr<T> activate_instance() {
	com_ptr<T>	t;
	HRESULT		hr = get_activation_factory<T>()->ActivateInstance((IInspectable**)&t);
	return t;
}

template<typename T, typename I> com_ptr<I> activate_instance() {
	com_ptr<T>	t;
	HRESULT		hr = get_activation_factory<T>()->ActivateInstance((IInspectable**)&t);
	return t.query<I>();
}

template<typename T, typename... TT> struct putter {
	static void f(string_accum &sa, const void *p) {
		sa << *(const T*)p << ", ";
		putter<TT...>::f(sa, (const T*)p + 1);
	}
};

template<typename T> struct putter<T> {
	static void f(string_accum &sa, const void *p) {
		sa << *(const T*)p;
	}
};

template<typename T, typename...TT> typename T_enable_if<T_inherits<iso_winrt::def<T>, value_type<TT...>>::value, string_accum&>::type operator<<(string_accum &sa, value_type<TT...> &x) {
	sa << "{ ";
	putter<TT...>::f(sa, &x);
	return sa << " }";
}
*/

struct bindable {};

template<TrustLevel tl> struct trust_level {
	static constexpr TrustLevel	get_trust_level() { return tl; }
};

template<typename T, typename V=void> struct trust_level_getter												{ static TrustLevel	f() { return FullTrust; } };
template<typename T> struct trust_level_getter<T, typename T_exists<decltype(&T::get_trust_level)>::type>	{ static TrustLevel	f() { return T::get_trust_level(); } };

template<typename T> static	TrustLevel get_trust_level() {
	return trust_level_getter<T>::f();
}

template<bool bindable> struct class_name_getter		{ template<typename T> static hstring	f() { static const hstring_ref class_name = name<T>::value; return class_name; } };
template<>				struct class_name_getter<true>	{ template<typename T> static hstring	f() { return type_id_t<T>::_type_id.name;; } };

template<typename T> static hstring		get_class_name() {
	return class_name_getter<T_inherits<T, bindable>::value>::f<T>();
}


struct _com_base {
#ifdef WINRT_DEBUG_REFS

	struct RefChange {
		static CallStacks call_stacks() {
			static CallStacks	call_stacks;
			return call_stacks;
		}
		struct Stack : dynamic_array<void*> {
			Stack() {}
			Stack(CallStacks &cs, const context &ctx) { init(cs, ctx); }
			void init(CallStacks &cs, const context &ctx) {
				void	**temp		= alloc_auto(void*, 256);
				int		len			= cs.GetStackTrace(ctx, temp, 256);
				append(temp, temp + len);
			}
		};
		int							diverge;
		Stack						add, rel;
		RefChange					*parent;
		dynamic_array<RefChange>	children;

		RefChange(const context &ctx, RefChange *_parent) : add(call_stacks(), ctx), parent(_parent) {}
		RefChange	*push(const context &ctx)	{
			return &children.emplace_back(ctx, this);
		}
		RefChange	*pop(const context &ctx)	{
			rel.init(call_stacks(), ctx);
			diverge = CallStacks::FindDivergence(add.begin(), add.end(), rel.begin(), rel.end());
			return parent;
		}
	};

	RefChange	root_changes;
	RefChange	*curr_changes;
#endif

	LONG		refs;
	_com_base() : refs(1)
#ifdef WINRT_DEBUG_REFS
		, root_changes(0, 0), curr_changes(&root_changes)
#endif
	{}
	~_com_base() {
		ISO_ASSERT(refs == 0);
		ISO_TRACEF("deleting: 0x%p\n", this);
	}
	ULONG add_ref() {
#ifdef WINRT_DEBUG_REFS
		curr_changes = curr_changes->push(0);
#endif
		return InterlockedIncrement(&refs);
	}
	ULONG release() {
#ifdef WINRT_DEBUG_REFS
		curr_changes = curr_changes->pop(0);
#endif
		return InterlockedDecrement(&refs);
	}
};

template<typename B, typename... I> struct com_base : _com_base, B {
protected:
	template<typename D> inline bool check_interface(REFIID riid, void **ppv) {
		if (riid == uuidof<D>()) {
			*ppv = static_cast<D*>(this);
			AddRef();
			return true;
		}
		return false;
	}
	template<> inline bool check_interface<IUnknown>(REFIID riid, void **ppv) {
		if (riid == __uuidof(IUnknown)) {
			*ppv = this;
			AddRef();
			return true;
		}
		return false;
	}
	template<typename D, typename...DD> inline bool check_interfaces1(REFIID riid, void **ppv)	{ return check_interface<D>(riid, ppv) || check_interfaces<DD...>(riid, ppv); }
	template<typename...DD> inline bool check_interfaces(REFIID riid, void **ppv)				{ return check_interfaces1<DD...>(riid, ppv); }
	template<> inline bool check_interfaces<>(REFIID riid, void **ppv)							{ return false; }

	bool query_interface(REFIID riid, void **ppv) {
		return check_interface<IUnknown>(riid, ppv) || check_interfaces<I...>(riid, ppv);
	}
public:
	com_base() {}
	template<typename... PP> com_base(PP&&... pp) : B(forward<PP>(pp)...)	{}
	virtual ~com_base()	{}

	ULONG STDMETHODCALLTYPE	AddRef() {
		return add_ref();
	}
	ULONG STDMETHODCALLTYPE	Release() {
		ULONG	n = release();
		if (!n)
			delete this;
		return n;
	}
	STDMETHODIMP QueryInterface(REFIID riid, void **ppv) {
		return query_interface(riid, ppv) ? S_OK : E_NOINTERFACE;
	}
};

template<typename B> struct com_class : com_base<B, B> {};

template<typename... I> HRESULT get_iids(ULONG *iidCount, IID **iids) {
	constexpr ULONG	count	= sizeof...(I);
	IID				*p		= nullptr;
	if (count) {
		p = static_cast<GUID*>(CoTaskMemAlloc(sizeof(GUID)* count));
		if (!p)
			return E_OUTOFMEMORY;
		*(constexpr_array<GUID, count>*)p = {{uuidof<I>()...}};
	}

	*iidCount	= count;
	*iids		= p;
	return S_OK;
}

template<typename T> struct get_iids_s;
template<typename...I> struct get_iids_s<types<I...>> { static HRESULT f(ULONG *iidCount, IID **iids) { return get_iids<I...>(iidCount, iids); } };

template<typename A, typename B, typename... I> struct inspectable : com_base<B, I...> {
	STDMETHODIMP QueryInterface(REFIID riid, void **ppv) {
		if (riid == uuidof<A>() || riid == __uuidof(IInspectable) || riid == __uuidof(IUnknown)) {
			*ppv = this;
			AddRef();
			return S_OK;
		}
		return this->check_interfaces<I...>(riid, ppv) ? S_OK : E_NOINTERFACE;
	}
	STDMETHODIMP GetRuntimeClassName(HSTRING *className) {
		WindowsDuplicateString(get_class_name<A>(), className);
		return S_OK;
	}
	STDMETHODIMP GetIids(ULONG *iidCount, IID **iids) {
		return get_iids<I...>(iidCount, iids);
	}
	STDMETHODIMP GetTrustLevel(TrustLevel *trustLevel) {
		*trustLevel = get_trust_level<A>();
		return S_OK;
	}
};

template<typename F> struct query_s<F, IInspectable, true> {
	template<typename B, typename I0, typename... I> static IInspectable* helper(com_base<B, I0, I...> *f)	{ return static_cast<I0*>(f); }
	static IInspectable* helper(void *f)	{ return (F*)f; }
	static IInspectable* safe(F *f)			{ return helper(f); }
	static IInspectable* ref(F *f)			{ return helper(f); }
};

template<typename F> struct query_s<F, IUnknown, true> {
	template<typename B, typename I0, typename... I> static IUnknown* helper(com_base<B, I0, I...> *f)	{ return static_cast<I0*>(f); }
	static IUnknown*	helper(void *f)	{ return (F*)f; }
	static IUnknown*	safe(F *f)			{ return helper(f); }
	static IUnknown*	ref(F *f)			{ return helper(f); }
};

template<typename T>	struct def_runtime<T, typename T_enable_if<T_inherits<T, _com_base>::value>::type> : basic_type {
	static constexpr auto sig = get_constexpr_name<T>();
};

//-----------------------------------------------------------------------------
//	weak_ref
//-----------------------------------------------------------------------------

struct weak_reference_imp : com_class<IWeakReference> {
	IInspectable *p;
	weak_reference_imp(IInspectable *_p) : p(_p) {}

	STDMETHODIMP Resolve(REFIID riid, IInspectable **pp) {
		if (p)
			return p->QueryInterface(riid, (void**)pp);
		*pp = 0;
		return S_OK;
	}
};

template<> struct ptr<weak_reference_imp> : ptr_base<weak_reference_imp> {
	~ptr() {
		if (t)
			t->p = 0;
	}
	IWeakReference *make(IInspectable *p) {
		if (!t)
			t = new weak_reference_imp(p);
		t->AddRef();
		return t;
	}
};

template<typename A> struct weak_reference_source : com_class<IWeakReferenceSource> {
	STDMETHODIMP GetWeakReference(IWeakReference **weakReference) {
		*weakReference	= new weak_reference_imp(query<IInspectable>(static_cast<A*>(this)));
		return S_OK;
	}
};

//-----------------------------------------------------------------------------
//	delegate & event
//-----------------------------------------------------------------------------

template<typename T> struct pass_abi_s			{ typedef const T &type; };
template<typename T> struct pass_abi_s<T*>		{ typedef pptr<T> type; };
template<typename T> struct pass_abi_s<ptr<T>>	{ typedef pptr<T> type; };
template<typename T> using pass_abi_t = typename pass_abi_s<T>::type;

template<typename T> inline auto				pass_abi(T &&t)					{ return forward<T>(t); }
template<typename T> inline pptr<T>				pass_abi(T *t)					{ return t; }
template<typename T> inline	szarray<ptr<T> >	pass_abi(szarray<T*> &a)		{ return {reinterpret_cast<ptr<T>*>(a.p), a.size}; }
template<template<typename> class T, typename U> inline auto pass_abi(T<U> *t)	{ return pptr<T<from_abi_t<U>>>(t); }

template<typename T> struct delegate;
template<typename...T> struct delegate<void(T...)> : com_base<IUnknown, delegate<void(T...)> > {
	virtual STDMETHODIMP _Invoke(T...) = 0;
};

template<typename T, typename F> struct event_helper;
template<typename T, typename...PP> struct event_helper<T, HRESULT (__stdcall T::*)(PP...)> {
	int		count;
	struct entry {
		int				c;
		handler_ref<T>	h;
		entry(int _c, handler_ref<T> &&_h) : c(_c), h(move(_h)) {}
	};
	dynamic_array<entry >	a;

	bool	any() const { return !a.empty(); }

	Platform::EventRegistrationToken	operator+=(handler_ref<T> h) {
		a.emplace_back(count, move(h));
		return Platform::EventRegistrationToken { count++ };
	}
	bool	operator-=(const Platform::EventRegistrationToken &c) {
		for (auto &i : a) {
			if (i.c == c.Value) {
				a.erase_unordered(&i);
				return true;
			}
		}
		return false;
	}
	void operator()(pass_abi_t<PP>... pp) {
		for (auto &i : a)
			i.h->_Invoke(pp...);
	}
};

template<typename T> struct event : event_helper<to_abi_t<T>, decltype(&to_abi_t<T>::_Invoke)> {};

template<typename T, typename L, typename F> struct handler_helper;
template<typename T, typename L, typename...PP> struct handler_helper<T, L, HRESULT (__stdcall T::*)(PP...)> : com_base<inherit<T, IAgileObject>, T, IAgileObject> {
	L	lambda;
	handler_helper() {}
	handler_helper(L &&_lambda) : lambda(move(_lambda)) {}
	handler_helper(handler_helper &&b) = default;

	STDMETHODIMP _Invoke(PP... pp) {
		lambda(pass_abi(pp)...);
		return S_OK;
	}
};

template<typename T, typename L> struct handler : handler_helper<T, L, decltype(&T::_Invoke)> {
	handler(L &&_lambda) : handler_helper<T, L, decltype(&T::_Invoke)>(move(_lambda)) {}
};

template<typename T> auto wait(const ptr<T> &p) {
	HANDLE	s = CreateEvent(NULL, FALSE, FALSE, NULL);
	p->Completed = [s](...) {
		SetEvent(s);
	};
	WaitForSingleObject(s, INFINITE);
	return from_abi(p->GetResults());
}

//-----------------------------------------------------------------------------
//	hstring
//-----------------------------------------------------------------------------

inline hstring	hstring_base::copy()								const	{ HSTRING h2; WindowsDuplicateString(h, &h2); return h2; }
inline hstring	hstring_base::substr(int i)							const	{ HSTRING h2; WindowsSubstring(h, i, &h2); return h2; }
inline hstring	hstring_base::substr(int i, int n)					const	{ HSTRING h2; WindowsSubstringWithSpecifiedLength(h, i, n, &h2); return h2; }
inline hstring	hstring_base::trim_start(const hstring_base &trim)	const	{ HSTRING h2; WindowsTrimStringStart(h, trim, &h2); return h2; }
inline hstring	hstring_base::trim_end(const hstring_base &trim)	const	{ HSTRING h2; WindowsTrimStringEnd(h, trim, &h2); return h2; }

inline hstring	add(const hstring_base &a, const hstring_base &b) {
	HSTRING h;
	WindowsConcatString(a, b, &h);
	return h;
}

inline hstring	replace(const hstring_base &s, const hstring_base &f, const hstring_base &t) {
	HSTRING h;
	WindowsReplaceString(s, f, t, &h);
	return h;
}

inline hstring	operator+(const hstring_base &a, const hstring_base &b) { return add(a, b); }
inline hstring	operator+(const hstring_base &a, const hstring_ref &b)	{ return add(a, b); }
inline hstring	operator+(const hstring_ref &a, const hstring_base &b)	{ return add(a, b); }

inline bool operator==(const hstring_ref &a, const hstring_ref &b)	{ return compare(a, b) == 0; }
inline bool operator!=(const hstring_ref &a, const hstring_ref &b)	{ return compare(a, b) != 0; }
inline bool operator< (const hstring_ref &a, const hstring_ref &b)	{ return compare(a, b) <  0; }
inline bool operator<=(const hstring_ref &a, const hstring_ref &b)	{ return compare(a, b) <= 0; }
inline bool operator> (const hstring_ref &a, const hstring_ref &b)	{ return compare(a, b) >  0; }
inline bool operator>=(const hstring_ref &a, const hstring_ref &b)	{ return compare(a, b) >= 0; }

inline bool operator==(const hstring &a, const hstring_ref &b)	{ return compare(a, b) == 0; }
inline bool operator!=(const hstring &a, const hstring_ref &b)	{ return compare(a, b) != 0; }
inline bool operator< (const hstring &a, const hstring_ref &b)	{ return compare(a, b) <  0; }
inline bool operator<=(const hstring &a, const hstring_ref &b)	{ return compare(a, b) <= 0; }
inline bool operator> (const hstring &a, const hstring_ref &b)	{ return compare(a, b) >  0; }
inline bool operator>=(const hstring &a, const hstring_ref &b)	{ return compare(a, b) >= 0; }

inline string_accum&	operator<<(string_accum &sa, const hstring &s)		{ return sa << to_string(s); }
inline string_accum&	operator<<(string_accum &sa, const hstring_ref &s)	{ return sa << to_string(s); }

//-----------------------------------------------------------------------------
//	runtime
//-----------------------------------------------------------------------------

template<typename A, typename I>	struct direct_imp : I { typedef A type; A *get() { return static_cast<A*>(this); } };
template<typename A, typename... I> struct unadapt_list : unadapt<I, direct_imp<A, I>>... {};

template<typename A, typename I> struct runtime1;
template<typename A, typename...I> struct runtime1<A, types<I...> > : com_base<unadapt_list<A, I...>, I...> {
	STDMETHODIMP GetIids(ULONG *iidCount, IID **iids) {
		return get_iids<I...>(iidCount, iids);
	}
};

struct is_runtime {};

template<typename A, typename... I> struct runtime : is_runtime, runtime1<A, typename unique_interfaces<I...>::type> {
	STDMETHODIMP QueryInterface(REFIID riid, void **ppv) {
		if (riid == __uuidof(IInspectable) || riid == uuidof<A>()) {
			*ppv = this;
			AddRef();
			return S_OK;
		}
		return this->query_interface(riid, ppv) ? S_OK : E_NOINTERFACE;
	}

	STDMETHODIMP GetRuntimeClassName(HSTRING *className) {
		WindowsDuplicateString(get_class_name<A>(), className);
		return S_OK;
	}
	STDMETHODIMP GetTrustLevel(TrustLevel *trustLevel) {
		*trustLevel = get_trust_level<A>();
		return S_OK;
	}
};

template<typename T> struct ref_new<T, typename T_enable_if<T_inherits<T, is_runtime>::value>::type> : ptr<T> {
	template<typename...P> ref_new(P&&... p) {
		t = new T(forward<P>(p)...);
	}
};

//-----------------------------------------------------------------------------
//	compose
//-----------------------------------------------------------------------------

template<class R, typename A, typename T>								struct compose_part;

template<class R, typename A, typename T, typename...I>	struct inner1		: compose_part<R, A, I>...	{ typedef T type; auto get() { return query<T>(static_cast<A*>(this)->inner); } };
template<class R, typename A, typename I>				struct inner		: I							{ typedef I type; auto get() { return query<I>(static_cast<A*>(this)->inner); } };
template<class R, typename A, typename T, typename...I>	struct adapt_inner	: adapt<T, inner<R, A, T> >, compose_part<R, A, I>... { typedef A type; auto get() { return static_cast<A*>(this); } };
template<class R, typename A, typename...I>				struct composer		: compose_part<R, A, I>...	{ typedef A type; typedef R root_type; auto get() { return static_cast<A*>(this); } };

template<class R, typename A, typename T, typename D>					struct compose_part1;
template<class R, typename A, typename T>								struct compose_part : compose_part1<R, A, T, typename def<T>::type> {};
template<class R, typename A>											struct compose_part<R, A, Platform::Object> {};
template<class R, typename A, typename T, typename E, typename... I>	struct compose_part1<R, A, T, class_type<E, I...> >		: statics<T, composer<R,A,E,I...>> {};
template<class R, typename A, typename T, typename... I>				struct compose_part1<R, A, T, overridable_type<I...> >	: unadapt<T, adapt_inner<R,A,T,I...>> {};
template<class R, typename A, typename T, typename... I>				struct compose_part1<R, A, T, interface_type<I...> >	: adapt<T, inner1<R,A,T,I...>> {};


template<typename B, typename I> struct compose1;
template<typename B, typename...I> struct compose1<B, types<I...>> : com_base<B, I...> {
	IInspectable	*inner;

	compose1() : inner(0) {}
	~compose1() {
		if (inner)
			inner->Release();
	}
};

struct is_composed {};

template<typename A, typename T, typename...I> struct compose : is_composed, compose1<
	inherit<compose_part<compose<A,T,I...>, A, T>, unadapt_list<A, I...>>,
	typename types_cat<typename collect_imp<T>::type, I...>::type
> {
	typedef T	base_type;
	T	*instance;

	template<typename...P> compose(P&&... p) {
		instance = T::activate(forward<P>(p)..., query<IInspectable>(this), &this->inner);
	}

	STDMETHODIMP QueryInterface(REFIID riid, void **ppv) {
		if (riid == uuidof<A>() || riid == __uuidof(IInspectable) || riid == __uuidof(IUnknown)) {
			*ppv = this;
			AddRef();
			return S_OK;
		}
		return this->query_interface(riid, ppv) ? S_OK : inner->QueryInterface(riid, ppv);
	}
	STDMETHODIMP GetRuntimeClassName(HSTRING *className) {
		WindowsDuplicateString(get_class_name<A>(), className);
		return S_OK;
	}
	STDMETHODIMP GetTrustLevel(TrustLevel *trustLevel) {
		*trustLevel = get_trust_level<A>();
		return S_OK;
	}
	STDMETHODIMP GetIids(ULONG *iidCount, IID **iids) {
		return get_iids_s<typename unique_interfaces<T, I...>::type>::f(iidCount, iids);
	}
};

template<typename T> struct ref_new<T, typename T_enable_if<T_inherits<T, is_composed>::value>::type> : ptr<typename T_deref<decltype(declval<T>().instance)>::type> {
	template<typename...P> ref_new(P&&... p) {
		auto	*i = new T(forward<P>(p)...);
		this->t = i->instance;
	}
};

//-----------------------------------------------------------------------------
//	Platform
//-----------------------------------------------------------------------------

namespace Windows { namespace Foundation {
	using IValueType	= IPropertyValue;
	using ValueType		= PropertyValue;
	template<typename T> using IBox			= IReference<T>;
	template<typename T> using IBoxArray	= IReferenceArray<T>;

	struct IMemoryBufferByteAccess : IUnknown {
		virtual STDMETHODIMP GetBuffer(BYTE **value, UINT32 *capacity);
	};

	struct WeakReference : ptr<IWeakReference> {
		WeakReference(nullptr_t = nullptr) {}
		WeakReference(IInspectable *p) {
			query<IWeakReferenceSource>(p)->GetWeakReference(&t);
		}
		template<typename T> T	*get() const { IInspectable *p; return t && SUCCEEDED(t->Resolve(uuidof<T>(), &p)) ? (T*)p : 0;}
	};

	template<typename T> struct Box : runtime<Box<T>, IBox<T>> {
		T	Value;
		bool						IsNumericScalar()		{ return false; }
		PropertyType				Type()					{ return PropertyType::OtherType; }
		unsigned char				GetUInt8()				{ throw NotImplementedException(); }
		short						GetInt16()				{ throw NotImplementedException(); }
		unsigned short				GetUInt16()				{ throw NotImplementedException(); }
		int							GetInt32()				{ throw NotImplementedException(); }
		unsigned					GetUInt32()				{ throw NotImplementedException(); }
		__int64						GetInt64()				{ throw NotImplementedException(); }
		unsigned __int64			GetUInt64()				{ throw NotImplementedException(); }
		float						GetSingle()				{ throw NotImplementedException(); }
		double						GetDouble()				{ throw NotImplementedException(); }
		char						GetChar16()				{ throw NotImplementedException(); }
		bool						GetBoolean()			{ throw NotImplementedException(); }
		hstring						GetString()				{ throw NotImplementedException(); }
		Guid						GetGuid()				{ throw NotImplementedException(); }
		DateTime					GetDateTime()			{ throw NotImplementedException(); }
		TimeSpan					GetTimeSpan()			{ throw NotImplementedException(); }
		Point						GetPoint()				{ throw NotImplementedException(); }
		Size						GetSize()				{ throw NotImplementedException(); }
		Rect						GetRect()				{ throw NotImplementedException(); }
		szarray<unsigned char>		GetUInt8Array()			{ throw NotImplementedException(); }
		szarray<short>				GetInt16Array()			{ throw NotImplementedException(); }
		szarray<unsigned short>		GetUInt16Array()		{ throw NotImplementedException(); }
		szarray<int>				GetInt32Array()			{ throw NotImplementedException(); }
		szarray<unsigned>			GetUInt32Array()		{ throw NotImplementedException(); }
		szarray<__int64>			GetInt64Array()			{ throw NotImplementedException(); }
		szarray<unsigned __int64>	GetUInt64Array()		{ throw NotImplementedException(); }
		szarray<float>				GetSingleArray()		{ throw NotImplementedException(); }
		szarray<double>				GetDoubleArray()		{ throw NotImplementedException(); }
		szarray<char>				GetChar16Array()		{ throw NotImplementedException(); }
		szarray<bool>				GetBooleanArray()		{ throw NotImplementedException(); }
		szarray<hstring>			GetStringArray()		{ throw NotImplementedException(); }
		szarray<object>				GetInspectableArray()	{ throw NotImplementedException(); }
		szarray<Guid>				GetGuidArray()			{ throw NotImplementedException(); }
		szarray<DateTime>			GetDateTimeArray()		{ throw NotImplementedException(); }
		szarray<TimeSpan>			GetTimeSpanArray()		{ throw NotImplementedException(); }
		szarray<Point>				GetPointArray()			{ throw NotImplementedException(); }
		szarray<Size>				GetSizeArray()			{ throw NotImplementedException(); }
		szarray<Rect>				GetRectArray()			{ throw NotImplementedException(); }

		Box(const T &v) : Value(v) {}
	};

	template<typename T> struct BoxArray : runtime<BoxArray<T>, IBoxArray<T>> {
		szarray<T>	Value;
		BoxArray(const szarray<T> &v) : Value(v)	{}
	};

	template<typename T>	inline object	make_value(const T &value) { return query<IInspectable>(new Box<T>(value)); }
	template<size_t N>		inline object	make_value(const wchar_t (&value)[N])	{ return ValueType::CreateString(value); }
	inline object	make_value(const wchar_t *value)					{ return ValueType::CreateString			(value); }
	inline object	make_value(unsigned char value)						{ return ValueType::CreateUInt8				(value); }
	inline object	make_value(short value)								{ return ValueType::CreateInt16				(value); }
	inline object	make_value(unsigned short value)					{ return ValueType::CreateUInt16			(value); }
	inline object	make_value(int value)								{ return ValueType::CreateInt32				(value); }
	inline object	make_value(unsigned value)							{ return ValueType::CreateUInt32			(value); }
	inline object	make_value(__int64 value)							{ return ValueType::CreateInt64				(value); }
	inline object	make_value(unsigned __int64 value)					{ return ValueType::CreateUInt64			(value); }
	inline object	make_value(float value)								{ return ValueType::CreateSingle			(value); }
	inline object	make_value(double value)							{ return ValueType::CreateDouble			(value); }
	inline object	make_value(char value)								{ return ValueType::CreateChar16			(value); }
	inline object	make_value(bool value)								{ return ValueType::CreateBoolean			(value); }
	inline object	make_value(hstring_ref value)						{ return ValueType::CreateString			(move(value)); }
	inline object	make_value(hstring value)							{ return ValueType::CreateString			(move(value)); }
	inline object	make_value(const Guid& value)						{ return ValueType::CreateGuid				(value); }
	inline object	make_value(const DateTime& value)					{ return ValueType::CreateDateTime			(value); }
	inline object	make_value(const TimeSpan& value)					{ return ValueType::CreateTimeSpan			(value); }
	inline object	make_value(const Point& value)						{ return ValueType::CreatePoint				(value); }
	inline object	make_value(const Size& value)						{ return ValueType::CreateSize				(value); }
	inline object	make_value(const Rect& value)						{ return ValueType::CreateRect				(value); }
	inline object	make_value(const szarray<unsigned char>& value)		{ return ValueType::CreateUInt8Array		(value); }
	inline object	make_value(const szarray<short>& value)				{ return ValueType::CreateInt16Array		(value); }
	inline object	make_value(const szarray<unsigned short>& value)	{ return ValueType::CreateUInt16Array		(value); }
	inline object	make_value(const szarray<int>& value)				{ return ValueType::CreateInt32Array		(value); }
	inline object	make_value(const szarray<unsigned>& value)			{ return ValueType::CreateUInt32Array		(value); }
	inline object	make_value(const szarray<__int64>& value)			{ return ValueType::CreateInt64Array		(value); }
	inline object	make_value(const szarray<unsigned __int64>& value)	{ return ValueType::CreateUInt64Array		(value); }
	inline object	make_value(const szarray<float>& value)				{ return ValueType::CreateSingleArray		(value); }
	inline object	make_value(const szarray<double>& value)			{ return ValueType::CreateDoubleArray		(value); }
	inline object	make_value(const szarray<char>& value)				{ return ValueType::CreateChar16Array		(value); }
	inline object	make_value(const szarray<bool>& value)				{ return ValueType::CreateBooleanArray		(value); }
	inline object	make_value(const szarray<hstring>& value)			{ return ValueType::CreateStringArray		(value); }
	inline object	make_value(const szarray<object>& value)			{ return ValueType::CreateInspectableArray	(value); }
	inline object	make_value(const szarray<Guid>& value)				{ return ValueType::CreateGuidArray			(value); }
	inline object	make_value(const szarray<DateTime>& value)			{ return ValueType::CreateDateTimeArray		(value); }
	inline object	make_value(const szarray<TimeSpan>& value)			{ return ValueType::CreateTimeSpanArray		(value); }
	inline object	make_value(const szarray<Point>& value)				{ return ValueType::CreatePointArray		(value); }
	inline object	make_value(const szarray<Size>& value)				{ return ValueType::CreateSizeArray			(value); }
	inline object	make_value(const szarray<Rect>& value)				{ return ValueType::CreateRectArray			(value); }

	template<typename T> inline	T	get_value(IValueType *p);
	template<> inline	unsigned char				get_value<unsigned char					>(IValueType *p) { return p->GetUInt8(); }
	template<> inline	short						get_value<short							>(IValueType *p) { return p->GetInt16(); }
	template<> inline	unsigned short				get_value<unsigned short				>(IValueType *p) { return p->GetUInt16(); }
	template<> inline	int							get_value<int							>(IValueType *p) { return p->GetInt32(); }
	template<> inline	unsigned					get_value<unsigned						>(IValueType *p) { return p->GetUInt32(); }
	template<> inline	__int64						get_value<__int64						>(IValueType *p) { return p->GetInt64(); }
	template<> inline	unsigned __int64			get_value<unsigned __int64				>(IValueType *p) { return p->GetUInt64(); }
	template<> inline	float						get_value<float							>(IValueType *p) { return p->GetSingle(); }
	template<> inline	double						get_value<double						>(IValueType *p) { return p->GetDouble(); }
	template<> inline	char						get_value<char							>(IValueType *p) { return p->GetChar16(); }
	template<> inline	bool						get_value<bool							>(IValueType *p) { return p->GetBoolean(); }
	template<> inline	hstring						get_value<hstring						>(IValueType *p) { return p->GetString(); }
	template<> inline	Guid						get_value<Guid							>(IValueType *p) { return p->GetGuid(); }
	template<> inline	DateTime					get_value<DateTime						>(IValueType *p) { return p->GetDateTime(); }
	template<> inline	TimeSpan					get_value<TimeSpan						>(IValueType *p) { return p->GetTimeSpan(); }
	template<> inline	Point						get_value<Point							>(IValueType *p) { return p->GetPoint(); }
	template<> inline	Size						get_value<Size							>(IValueType *p) { return p->GetSize(); }
	template<> inline	Rect						get_value<Rect							>(IValueType *p) { return p->GetRect(); }
	template<> inline	szarray<unsigned char>		get_value<szarray<unsigned char>		>(IValueType *p) { return p->GetUInt8Array(); }
	template<> inline	szarray<short>				get_value<szarray<short>				>(IValueType *p) { return p->GetInt16Array(); }
	template<> inline	szarray<unsigned short>		get_value<szarray<unsigned short>		>(IValueType *p) { return p->GetUInt16Array(); }
	template<> inline	szarray<int>				get_value<szarray<int>					>(IValueType *p) { return p->GetInt32Array(); }
	template<> inline	szarray<unsigned>			get_value<szarray<unsigned>				>(IValueType *p) { return p->GetUInt32Array(); }
	template<> inline	szarray<__int64>			get_value<szarray<__int64>				>(IValueType *p) { return p->GetInt64Array(); }
	template<> inline	szarray<unsigned __int64>	get_value<szarray<unsigned __int64>		>(IValueType *p) { return p->GetUInt64Array(); }
	template<> inline	szarray<float>				get_value<szarray<float>				>(IValueType *p) { return p->GetSingleArray(); }
	template<> inline	szarray<double>				get_value<szarray<double>				>(IValueType *p) { return p->GetDoubleArray(); }
	template<> inline	szarray<char>				get_value<szarray<char>					>(IValueType *p) { return p->GetChar16Array(); }
	template<> inline	szarray<bool>				get_value<szarray<bool>					>(IValueType *p) { return p->GetBooleanArray(); }
	template<> inline	szarray<hstring>			get_value<szarray<hstring>				>(IValueType *p) { return p->GetStringArray(); }
	template<> inline	szarray<object>				get_value<szarray<object>				>(IValueType *p) { return p->GetInspectableArray(); }
	template<> inline	szarray<Guid>				get_value<szarray<Guid>					>(IValueType *p) { return p->GetGuidArray(); }
	template<> inline	szarray<DateTime>			get_value<szarray<DateTime>				>(IValueType *p) { return p->GetDateTimeArray(); }
	template<> inline	szarray<TimeSpan>			get_value<szarray<TimeSpan>				>(IValueType *p) { return p->GetTimeSpanArray(); }
	template<> inline	szarray<Point>				get_value<szarray<Point>				>(IValueType *p) { return p->GetPointArray(); }
	template<> inline	szarray<Size>				get_value<szarray<Size>					>(IValueType *p) { return p->GetSizeArray(); }
	template<> inline	szarray<Rect>				get_value<szarray<Rect>					>(IValueType *p) { return p->GetRectArray(); }

} }

//template<>	struct uuid<Platform::IMemoryBufferByteAccess>	{ define_guid(0x5b0d3235, 0x4dba, 0x4d44, 0x86, 0x5e, 0x8f, 0x1d, 0x0e, 0x4f, 0xd0, 0x4d); };
template<>	struct uuid<Platform::IMemoryBufferByteAccess>	{ define_guid_s("5b0d3235-4dba-4d44-865e-8f1d0e4fd04d"); };

//-----------------------------------------------------------------------------
//	object
//-----------------------------------------------------------------------------

template<typename T> object	box(const T &t)	{ return (object)t; }
template<typename T> auto	unbox(object_ref obj);

template<typename A>	inline ptr<IInspectable>::ptr(A value)						: B(Platform::make_value(value)) {}
template<size_t N>		inline ptr<IInspectable>::ptr(const wchar_t (&value)[N])	: B(Platform::ValueType::CreateString(hstring_ref(value))) {}
inline ptr<IInspectable>::ptr(hstring value)										: B(Platform::make_value(move(value))) {}
inline ptr<IInspectable>::ptr(hstring_ref value)									: B(Platform::make_value(move(value))) {}

template<typename A>	inline pptr<IInspectable>::pptr(A value)					: B(Platform::make_value(value)) {}
template<size_t N>		inline pptr<IInspectable>::pptr(const wchar_t (&value)[N])	: B(Platform::ValueType::CreateString(hstring_ref(value))) {}
inline pptr<IInspectable>::pptr(hstring value)										: B(Platform::make_value(move(value))) {}
inline pptr<IInspectable>::pptr(hstring_ref value)									: B(Platform::make_value(move(value))) {}

template<typename T, typename U> U* unbox2(ptr<U>*, object_ref obj) {
	return query<U>(obj);
}
template<typename T> hstring unbox2(hstring*, object_ref obj) {
	return Platform::get_value<hstring>(ref_cast<ptr<Platform::IValueType>>(obj));
}
template<typename T> T unbox2(void*, object_ref obj) {
	return Platform::get_value<T>(ref_cast<ptr<Platform::IValueType>>(obj));
}

template<typename T> auto unbox(object_ref obj)	{
	return unbox2<T>((T*)0, obj);
}

//-----------------------------------------------------------------------------
//	iterators
//-----------------------------------------------------------------------------

template<typename T, bool getat> struct iterator;

template<typename T> struct iterator<T, false> {
	typedef	decltype(declval<T>().First())		P;
	typedef	decltype(declval<P>()->Current())	element;
	P				i;
	bool			done;

	static iterator begin(pptr<T> p)	{ return iterator(p->First()); }
	static iterator end(pptr<T> p)		{ return iterator(nullptr); }

	iterator(nullptr_t)		: done(true) {}
	iterator(P &&_i)		: i(move(_i)), done(!i->HasCurrent) {}
	iterator&	operator++()			{ done = !i->MoveNext(); return *this; }
	element		operator*()	const		{ return i->Current(); }
	friend bool operator==(const iterator &a, const iterator &b) { return a.done == b.done; }
	friend bool operator!=(const iterator &a, const iterator &b) { return a.done != b.done; }
};

template<typename T> struct iterator<T, true> {
	typedef	decltype(declval<T>().GetAt(0))		element;
	ptr<T>			p;
	unsigned		i;

	static iterator begin(pptr<T> p)	{ return iterator(p, 0); }
	static iterator end(pptr<T> p)		{ return iterator(p, p->Size); }

	iterator(ptr<T> &&_p, unsigned _i) : p(move(_p)), i(_i) {}
	iterator&	operator++()					{ ++i; return *this; }
	iterator&	operator--()					{ --i; return *this; }
	element		operator*()				const	{ return p->GetAt(i); }
	element		operator[](unsigned j)	const	{ return p->GetAt(i + j); }
	iterator&	operator+=(int j)				{ i += j; return *this; }
	iterator&	operator-=(int j)				{ i += j; return *this; }
	friend bool		operator==(const iterator &a, const iterator &b)	{ return a.i == b.i; }
	friend bool		operator!=(const iterator &a, const iterator &b)	{ return a.i != b.i; }
	friend iterator operator+(const iterator &a, int i)					{ return iterator(a.p, a.i + i); }
	friend iterator operator-(const iterator &a, int i)					{ return iterator(a.p, a.i - i); }
};

template<typename T> class iterator_type {
	template<typename U, typename = decltype(&U::First)> static iterator<T, false> first(int);
//	template<typename> static no bool first(...);

	template<typename U, typename = decltype(&U::GetAt)> static iterator<T, true> getat(int);
	template<typename U> static constexpr auto getat(...) { return first<U>(0); }
public:
	typedef decltype(getat<T>(0)) type;
};

template<typename T> typename iterator_type<T>::type begin(const ptr<T> &p) {
	typedef typename iterator_type<T>::type	I;
	return I::begin(p);
}
template<typename T> typename iterator_type<T>::type end(const ptr<T> &p) {
	typedef typename iterator_type<T>::type	I;
	return I::end(p);
}

template<typename T> typename iterator_type<T>::type begin(pptr<T> p) {
	typedef typename iterator_type<T>::type	I;
	return I::begin(p);
}
template<typename T> typename iterator_type<T>::type end(pptr<T> p) {
	typedef typename iterator_type<T>::type	I;
	return I::end(p);
}

} // namespace iso_winrt
