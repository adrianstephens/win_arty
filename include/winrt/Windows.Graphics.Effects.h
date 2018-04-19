#pragma once
// generated by isopod tools
// namespaces:
// Windows.Graphics.Effects

#include "Windows.Graphics.Effects.0.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Graphics::Effects::IGraphicsEffectSource> : overridable_type<> {};
template<> struct def<Windows::Graphics::Effects::IGraphicsEffect> : overridable_type<Windows::Graphics::Effects::IGraphicsEffectSource> {};

// uuids

template<> struct uuid<Windows::Graphics::Effects::IGraphicsEffectSource> { define_guid(0x2D8F9DDC, 0x4339, 0x4EB9, 0x92, 0x16, 0xF9, 0xDE, 0xB7, 0x56, 0x58, 0xA2);};
template<> struct uuid<Windows::Graphics::Effects::IGraphicsEffect> { define_guid(0xCB51C0CE, 0x8FE6, 0x4636, 0xB2, 0x2, 0x86, 0x1F, 0xAA, 0x7, 0xD8, 0xF3);};

// types

namespace Windows { namespace Graphics { namespace Effects {

// IGraphicsEffectSource
struct IGraphicsEffectSource : IInspectable, generate<IGraphicsEffectSource> {};

// IGraphicsEffect
struct IGraphicsEffect_raw : IInspectable {
	virtual STDMETHODIMP _get_Name(HSTRING *name) = 0;
	virtual STDMETHODIMP _put_Name(HSTRING name) = 0;
};
template<typename X> struct IGraphicsEffect_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING name; hrcheck(enc(&IGraphicsEffect_adaptor::Name)->_get_Name(&name)); return from_abi(name); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref name) { hrcheck(enc(&IGraphicsEffect_adaptor::Name)->_put_Name(name)); }
			void operator=(hstring_ref name) { put(name); }
			void operator()(hstring_ref name) { put(name); }
		} Name;
	};
	IGraphicsEffect_adaptor() {}
};
template<typename X> struct adapt<IGraphicsEffect, X> : Windows::Graphics::Effects::IGraphicsEffect_adaptor<X> { typedef adapt IGraphicsEffect; };
template<typename X> struct IGraphicsEffect_unadaptor : X {
	STDMETHODIMP _get_Name(HSTRING *name) { return hrtry([&, this] { get_prop(name, Name); }); }
	STDMETHODIMP _put_Name(HSTRING name) { return hrtry([&, this] { put_prop(name, Name); }); }
};
template<typename X> struct unadapt<IGraphicsEffect, X> : Windows::Graphics::Effects::IGraphicsEffect_unadaptor<X> {};
struct IGraphicsEffect : IGraphicsEffect_raw, generate<IGraphicsEffect> {};
}}}
} // namespace iso_winrt