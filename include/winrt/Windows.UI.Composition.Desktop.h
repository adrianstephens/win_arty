#pragma once
// generated by isopod tools
// namespaces:
// Windows.UI.Composition.Desktop

#include "Windows.UI.Composition.Desktop.0.h"
#include "Windows.UI.Composition.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::UI::Composition::Desktop::IDesktopWindowTarget> : interface_type<> {};
template<> struct def<Windows::UI::Composition::Desktop::DesktopWindowTarget> : class_type<Windows::UI::Composition::CompositionTarget, Windows::UI::Composition::Desktop::IDesktopWindowTarget> {};

// uuids

template<> struct uuid<Windows::UI::Composition::Desktop::IDesktopWindowTarget> { define_guid(0x6329D6CA, 0x3366, 0x490E, 0x9D, 0xB3, 0x25, 0x31, 0x29, 0x29, 0xAC, 0x51);};

// types

namespace Windows { namespace UI { namespace Composition { namespace Desktop {

// IDesktopWindowTarget
struct IDesktopWindowTarget_raw : IInspectable {
	virtual STDMETHODIMP _get_IsTopmost(bool *value);
};
template<typename X> struct IDesktopWindowTarget_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IDesktopWindowTarget_adaptor::IsTopmost)->_get_IsTopmost(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsTopmost;
	};
	IDesktopWindowTarget_adaptor() {}
};
template<typename X> struct adapt<IDesktopWindowTarget, X> : Windows::UI::Composition::Desktop::IDesktopWindowTarget_adaptor<X> { typedef adapt IDesktopWindowTarget; };
struct IDesktopWindowTarget : IDesktopWindowTarget_raw, generate<IDesktopWindowTarget> {};

// DesktopWindowTarget
template<typename X> struct statics<DesktopWindowTarget, X> : X {
	typedef typename X::root_type DesktopWindowTarget;
};
struct DesktopWindowTarget : generate<DesktopWindowTarget> {};
}}}}
} // namespace iso_winrt
