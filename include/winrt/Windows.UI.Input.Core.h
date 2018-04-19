#pragma once
// generated by isopod tools
// namespaces:
// Windows.UI.Input.Core

#include "Windows.UI.Input.Core.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace Core {
struct CoreApplicationView;
}}
namespace System {
struct DispatcherQueue;
}
namespace UI { namespace Core {
struct CoreDispatcher;
}
namespace Input {
struct RadialController;
}}}

// defs

template<> struct def<Windows::UI::Input::Core::IRadialControllerIndependentInputSourceStatics> : interface_type<> {};
template<> struct def<Windows::UI::Input::Core::IRadialControllerIndependentInputSource2> : interface_type<> {};
template<> struct def<Windows::UI::Input::Core::IRadialControllerIndependentInputSource> : interface_type<> {};
template<> struct def<Windows::UI::Input::Core::RadialControllerIndependentInputSource> : class_type<Platform::Object, Windows::UI::Input::Core::IRadialControllerIndependentInputSource, Windows::UI::Input::Core::IRadialControllerIndependentInputSource2> {};

// uuids

template<> struct uuid<Windows::UI::Input::Core::IRadialControllerIndependentInputSourceStatics> { define_guid(0x3D577EF5, 0x4CEE, 0x11E6, 0xB5, 0x35, 0x0, 0x1B, 0xDC, 0x6, 0xAB, 0x3B);};
template<> struct uuid<Windows::UI::Input::Core::IRadialControllerIndependentInputSource2> { define_guid(0x7073AAD8, 0x35F3, 0x4EEB, 0x87, 0x51, 0xBE, 0x4D, 0xA, 0x66, 0xFA, 0xF4);};
template<> struct uuid<Windows::UI::Input::Core::IRadialControllerIndependentInputSource> { define_guid(0x3D577EF6, 0x4CEE, 0x11E6, 0xB5, 0x35, 0x0, 0x1B, 0xDC, 0x6, 0xAB, 0x3B);};

// types

namespace Windows { namespace UI { namespace Input { namespace Core {

// IRadialControllerIndependentInputSourceStatics
struct IRadialControllerIndependentInputSourceStatics : IInspectable {
	virtual STDMETHODIMP _CreateForView(ApplicationModel::Core::CoreApplicationView* view, RadialControllerIndependentInputSource* *result);
};

// IRadialControllerIndependentInputSource2
struct IRadialControllerIndependentInputSource2_raw : IInspectable {
	virtual STDMETHODIMP _get_DispatcherQueue(System::DispatcherQueue* *value);
};
template<typename X> struct IRadialControllerIndependentInputSource2_adaptor : X {
	union {
		struct : property {
			ptr<System::DispatcherQueue> get() { System::DispatcherQueue* value; hrcheck(enc(&IRadialControllerIndependentInputSource2_adaptor::DispatcherQueue)->_get_DispatcherQueue(&value)); return from_abi(value); }
			ptr<System::DispatcherQueue> operator()() { return get(); }
			operator ptr<System::DispatcherQueue> () { return get(); }
			ptr<System::DispatcherQueue> operator->() { return get(); }
		} DispatcherQueue;
	};
	IRadialControllerIndependentInputSource2_adaptor() {}
};
template<typename X> struct adapt<IRadialControllerIndependentInputSource2, X> : Windows::UI::Input::Core::IRadialControllerIndependentInputSource2_adaptor<X> { typedef adapt IRadialControllerIndependentInputSource2; };
struct IRadialControllerIndependentInputSource2 : IRadialControllerIndependentInputSource2_raw, generate<IRadialControllerIndependentInputSource2> {};

// IRadialControllerIndependentInputSource
struct IRadialControllerIndependentInputSource_raw : IInspectable {
	virtual STDMETHODIMP _get_Controller(RadialController* *value);
	virtual STDMETHODIMP _get_Dispatcher(UI::Core::CoreDispatcher* *value);
};
template<typename X> struct IRadialControllerIndependentInputSource_adaptor : X {
	union {
		struct : property {
			ptr<RadialController> get() { RadialController* value; hrcheck(enc(&IRadialControllerIndependentInputSource_adaptor::Controller)->_get_Controller(&value)); return from_abi(value); }
			ptr<RadialController> operator()() { return get(); }
			operator ptr<RadialController> () { return get(); }
			ptr<RadialController> operator->() { return get(); }
		} Controller;
		struct : property {
			ptr<UI::Core::CoreDispatcher> get() { UI::Core::CoreDispatcher* value; hrcheck(enc(&IRadialControllerIndependentInputSource_adaptor::Dispatcher)->_get_Dispatcher(&value)); return from_abi(value); }
			ptr<UI::Core::CoreDispatcher> operator()() { return get(); }
			operator ptr<UI::Core::CoreDispatcher> () { return get(); }
			ptr<UI::Core::CoreDispatcher> operator->() { return get(); }
		} Dispatcher;
	};
	IRadialControllerIndependentInputSource_adaptor() {}
};
template<typename X> struct adapt<IRadialControllerIndependentInputSource, X> : Windows::UI::Input::Core::IRadialControllerIndependentInputSource_adaptor<X> { typedef adapt IRadialControllerIndependentInputSource; };
struct IRadialControllerIndependentInputSource : IRadialControllerIndependentInputSource_raw, generate<IRadialControllerIndependentInputSource> {};

// RadialControllerIndependentInputSource
template<typename> struct RadialControllerIndependentInputSource_statics {
	static ptr<RadialControllerIndependentInputSource> CreateForView(pptr<ApplicationModel::Core::CoreApplicationView> view) { RadialControllerIndependentInputSource* result; hrcheck(get_activation_factory<RadialControllerIndependentInputSource, IRadialControllerIndependentInputSourceStatics>()->_CreateForView(view, &result)); return from_abi(result); }
};

template<typename X> struct statics<RadialControllerIndependentInputSource, X> : X, Windows::UI::Input::Core::RadialControllerIndependentInputSource_statics<void> {
	typedef typename X::root_type RadialControllerIndependentInputSource;
};
struct RadialControllerIndependentInputSource : generate<RadialControllerIndependentInputSource> {};
}}}}
} // namespace iso_winrt
