#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices.Input

#include "Windows.Devices.Input.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}}

// defs

template<> struct def<Windows::Devices::Input::PointerDeviceType> : enum_type<int> {};
template<> struct def<Windows::Devices::Input::PointerDeviceUsage> : value_type<unsigned, unsigned, int, int, int, int, unsigned, float> {};
template<> struct def<Windows::Devices::Input::MouseDelta> : value_type<int, int> {};
template<> struct def<Windows::Devices::Input::IMouseCapabilities> : interface_type<> {};
template<> struct def<Windows::Devices::Input::IKeyboardCapabilities> : interface_type<> {};
template<> struct def<Windows::Devices::Input::ITouchCapabilities> : interface_type<> {};
template<> struct def<Windows::Devices::Input::IPointerDeviceStatics> : interface_type<> {};
template<> struct def<Windows::Devices::Input::IPointerDevice2> : interface_type<> {};
template<> struct def<Windows::Devices::Input::IPointerDevice> : interface_type<> {};
template<> struct def<Windows::Devices::Input::PointerDevice> : class_type<Platform::Object, Windows::Devices::Input::IPointerDevice, Windows::Devices::Input::IPointerDevice2> {};
template<> struct def<Windows::Devices::Input::IMouseEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::Input::IMouseDevice> : interface_type<> {};
template<> struct def<Windows::Devices::Input::IMouseDeviceStatics> : interface_type<> {};
template<> struct def<Windows::Devices::Input::MouseDevice> : class_type<Platform::Object, Windows::Devices::Input::IMouseDevice> {};
template<> struct def<Windows::Devices::Input::MouseEventArgs> : class_type<Platform::Object, Windows::Devices::Input::IMouseEventArgs> {};
template<> struct def<Windows::Devices::Input::MouseCapabilities> : class_type<Platform::Object, Windows::Devices::Input::IMouseCapabilities> {};
template<> struct def<Windows::Devices::Input::KeyboardCapabilities> : class_type<Platform::Object, Windows::Devices::Input::IKeyboardCapabilities> {};
template<> struct def<Windows::Devices::Input::TouchCapabilities> : class_type<Platform::Object, Windows::Devices::Input::ITouchCapabilities> {};

// uuids

template<> struct uuid<Windows::Devices::Input::IMouseCapabilities> { define_guid(0xBCA5E023, 0x7DD9, 0x4B6B, 0x9A, 0x92, 0x55, 0xD4, 0x3C, 0xB3, 0x8F, 0x73);};
template<> struct uuid<Windows::Devices::Input::IKeyboardCapabilities> { define_guid(0x3A3F9B56, 0x6798, 0x4BBC, 0x83, 0x3E, 0xF, 0x34, 0xB1, 0x7C, 0x65, 0xFF);};
template<> struct uuid<Windows::Devices::Input::ITouchCapabilities> { define_guid(0x20DD55F9, 0x13F1, 0x46C8, 0x92, 0x85, 0x2C, 0x5, 0xFA, 0x3E, 0xDA, 0x6F);};
template<> struct uuid<Windows::Devices::Input::IPointerDeviceStatics> { define_guid(0xD8B89AA1, 0xD1C6, 0x416E, 0xBD, 0x8D, 0x57, 0x90, 0x91, 0x4D, 0xC5, 0x63);};
template<> struct uuid<Windows::Devices::Input::IPointerDevice2> { define_guid(0xF8A6D2A0, 0xC484, 0x489F, 0xAE, 0x3E, 0x30, 0xD2, 0xEE, 0x1F, 0xFD, 0x3E);};
template<> struct uuid<Windows::Devices::Input::IPointerDevice> { define_guid(0x93C9BAFC, 0xEBCB, 0x467E, 0x82, 0xC6, 0x27, 0x6F, 0xEA, 0xE3, 0x6B, 0x5A);};
template<> struct uuid<Windows::Devices::Input::IMouseEventArgs> { define_guid(0xF625AA5D, 0x2354, 0x4CC7, 0x92, 0x30, 0x96, 0x94, 0x1C, 0x96, 0x9F, 0xDE);};
template<> struct uuid<Windows::Devices::Input::IMouseDevice> { define_guid(0x88EDF458, 0xF2C8, 0x49F4, 0xBE, 0x1F, 0xC2, 0x56, 0xB3, 0x88, 0xBC, 0x11);};
template<> struct uuid<Windows::Devices::Input::IMouseDeviceStatics> { define_guid(0x484A9045, 0x6D70, 0x49DB, 0x8E, 0x68, 0x46, 0xFF, 0xBD, 0x17, 0xD3, 0x8D);};

// types

namespace Windows { namespace Devices { namespace Input {

// IMouseCapabilities
struct IMouseCapabilities_raw : IInspectable {
	virtual STDMETHODIMP _get_MousePresent(int *value);
	virtual STDMETHODIMP _get_VerticalWheelPresent(int *value);
	virtual STDMETHODIMP _get_HorizontalWheelPresent(int *value);
	virtual STDMETHODIMP _get_SwapButtons(int *value);
	virtual STDMETHODIMP _get_NumberOfButtons(unsigned *value);
};
template<typename X> struct IMouseCapabilities_adaptor : X {
	union {
		struct : property {
			int get() { int value; hrcheck(enc(&IMouseCapabilities_adaptor::HorizontalWheelPresent)->_get_HorizontalWheelPresent(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} HorizontalWheelPresent;
		struct : property {
			int get() { int value; hrcheck(enc(&IMouseCapabilities_adaptor::MousePresent)->_get_MousePresent(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} MousePresent;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IMouseCapabilities_adaptor::NumberOfButtons)->_get_NumberOfButtons(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} NumberOfButtons;
		struct : property {
			int get() { int value; hrcheck(enc(&IMouseCapabilities_adaptor::SwapButtons)->_get_SwapButtons(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} SwapButtons;
		struct : property {
			int get() { int value; hrcheck(enc(&IMouseCapabilities_adaptor::VerticalWheelPresent)->_get_VerticalWheelPresent(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} VerticalWheelPresent;
	};
	IMouseCapabilities_adaptor() {}
};
template<typename X> struct adapt<IMouseCapabilities, X> : Windows::Devices::Input::IMouseCapabilities_adaptor<X> { typedef adapt IMouseCapabilities; };
struct IMouseCapabilities : IMouseCapabilities_raw, generate<IMouseCapabilities> {};

// IKeyboardCapabilities
struct IKeyboardCapabilities_raw : IInspectable {
	virtual STDMETHODIMP _get_KeyboardPresent(int *value);
};
template<typename X> struct IKeyboardCapabilities_adaptor : X {
	union {
		struct : property {
			int get() { int value; hrcheck(enc(&IKeyboardCapabilities_adaptor::KeyboardPresent)->_get_KeyboardPresent(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} KeyboardPresent;
	};
	IKeyboardCapabilities_adaptor() {}
};
template<typename X> struct adapt<IKeyboardCapabilities, X> : Windows::Devices::Input::IKeyboardCapabilities_adaptor<X> { typedef adapt IKeyboardCapabilities; };
struct IKeyboardCapabilities : IKeyboardCapabilities_raw, generate<IKeyboardCapabilities> {};

// ITouchCapabilities
struct ITouchCapabilities_raw : IInspectable {
	virtual STDMETHODIMP _get_TouchPresent(int *value);
	virtual STDMETHODIMP _get_Contacts(unsigned *value);
};
template<typename X> struct ITouchCapabilities_adaptor : X {
	union {
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&ITouchCapabilities_adaptor::Contacts)->_get_Contacts(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} Contacts;
		struct : property {
			int get() { int value; hrcheck(enc(&ITouchCapabilities_adaptor::TouchPresent)->_get_TouchPresent(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} TouchPresent;
	};
	ITouchCapabilities_adaptor() {}
};
template<typename X> struct adapt<ITouchCapabilities, X> : Windows::Devices::Input::ITouchCapabilities_adaptor<X> { typedef adapt ITouchCapabilities; };
struct ITouchCapabilities : ITouchCapabilities_raw, generate<ITouchCapabilities> {};

// IPointerDeviceStatics
struct IPointerDeviceStatics : IInspectable {
	virtual STDMETHODIMP _GetPointerDevice(unsigned pointerId, PointerDevice* *pointerDevice);
	virtual STDMETHODIMP _GetPointerDevices(Foundation::Collections::IVectorView<PointerDevice*>* *pointerDevices);
};

// IPointerDevice2
struct IPointerDevice2_raw : IInspectable {
	virtual STDMETHODIMP _get_MaxPointersWithZDistance(unsigned *value);
};
template<typename X> struct IPointerDevice2_adaptor : X {
	union {
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IPointerDevice2_adaptor::MaxPointersWithZDistance)->_get_MaxPointersWithZDistance(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} MaxPointersWithZDistance;
	};
	IPointerDevice2_adaptor() {}
};
template<typename X> struct adapt<IPointerDevice2, X> : Windows::Devices::Input::IPointerDevice2_adaptor<X> { typedef adapt IPointerDevice2; };
struct IPointerDevice2 : IPointerDevice2_raw, generate<IPointerDevice2> {};

// IPointerDevice
struct IPointerDevice_raw : IInspectable {
	virtual STDMETHODIMP _get_PointerDeviceType(Input::PointerDeviceType *value);
	virtual STDMETHODIMP _get_IsIntegrated(bool *value);
	virtual STDMETHODIMP _get_MaxContacts(unsigned *value);
	virtual STDMETHODIMP _get_PhysicalDeviceRect(Foundation::Rect *value);
	virtual STDMETHODIMP _get_ScreenRect(Foundation::Rect *value);
	virtual STDMETHODIMP _get_SupportedUsages(Foundation::Collections::IVectorView<PointerDeviceUsage>* *value);
};
template<typename X> struct IPointerDevice_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IPointerDevice_adaptor::IsIntegrated)->_get_IsIntegrated(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsIntegrated;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IPointerDevice_adaptor::MaxContacts)->_get_MaxContacts(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} MaxContacts;
		struct : property {
			Foundation::Rect get() { Foundation::Rect value; hrcheck(enc(&IPointerDevice_adaptor::PhysicalDeviceRect)->_get_PhysicalDeviceRect(&value)); return value; }
			Foundation::Rect operator()() { return get(); }
			operator Foundation::Rect () { return get(); }
		} PhysicalDeviceRect;
		struct : property {
			Input::PointerDeviceType get() { Input::PointerDeviceType value; hrcheck(enc(&IPointerDevice_adaptor::PointerDeviceType)->_get_PointerDeviceType(&value)); return value; }
			Input::PointerDeviceType operator()() { return get(); }
			operator Input::PointerDeviceType () { return get(); }
		} PointerDeviceType;
		struct : property {
			Foundation::Rect get() { Foundation::Rect value; hrcheck(enc(&IPointerDevice_adaptor::ScreenRect)->_get_ScreenRect(&value)); return value; }
			Foundation::Rect operator()() { return get(); }
			operator Foundation::Rect () { return get(); }
		} ScreenRect;
		struct : property {
			ptr<Foundation::Collections::IVectorView<PointerDeviceUsage>> get() { Foundation::Collections::IVectorView<PointerDeviceUsage>* value; hrcheck(enc(&IPointerDevice_adaptor::SupportedUsages)->_get_SupportedUsages(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<PointerDeviceUsage>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<PointerDeviceUsage>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<PointerDeviceUsage>> operator->() { return get(); }
		} SupportedUsages;
	};
	IPointerDevice_adaptor() {}
};
template<typename X> struct adapt<IPointerDevice, X> : Windows::Devices::Input::IPointerDevice_adaptor<X> { typedef adapt IPointerDevice; };
struct IPointerDevice : IPointerDevice_raw, generate<IPointerDevice> {};

// PointerDevice
template<typename> struct PointerDevice_statics {
	static ptr<PointerDevice> GetPointerDevice(unsigned pointerId) { PointerDevice* pointerDevice; hrcheck(get_activation_factory<PointerDevice, IPointerDeviceStatics>()->_GetPointerDevice(pointerId, &pointerDevice)); return from_abi(pointerDevice); }
	static ptr<Foundation::Collections::IVectorView<ptr<PointerDevice>>> GetPointerDevices() { Foundation::Collections::IVectorView<PointerDevice*>* pointerDevices; hrcheck(get_activation_factory<PointerDevice, IPointerDeviceStatics>()->_GetPointerDevices(&pointerDevices)); return from_abi(pointerDevices); }
};

template<typename X> struct statics<PointerDevice, X> : X, Windows::Devices::Input::PointerDevice_statics<void> {
	typedef typename X::root_type PointerDevice;
};
struct PointerDevice : generate<PointerDevice> {};

// IMouseEventArgs
struct IMouseEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_MouseDelta(Input::MouseDelta *value);
};
template<typename X> struct IMouseEventArgs_adaptor : X {
	union {
		struct : property {
			Input::MouseDelta get() { Input::MouseDelta value; hrcheck(enc(&IMouseEventArgs_adaptor::MouseDelta)->_get_MouseDelta(&value)); return value; }
			Input::MouseDelta operator()() { return get(); }
			operator Input::MouseDelta () { return get(); }
		} MouseDelta;
	};
	IMouseEventArgs_adaptor() {}
};
template<typename X> struct adapt<IMouseEventArgs, X> : Windows::Devices::Input::IMouseEventArgs_adaptor<X> { typedef adapt IMouseEventArgs; };
struct IMouseEventArgs : IMouseEventArgs_raw, generate<IMouseEventArgs> {};

// IMouseDevice
struct IMouseDevice_raw : IInspectable {
	virtual STDMETHODIMP _add_MouseMoved(Foundation::TypedEventHandler<MouseDevice*, MouseEventArgs*>* handler, Foundation::EventRegistrationToken *cookie);
	virtual STDMETHODIMP _remove_MouseMoved(Foundation::EventRegistrationToken cookie);
};
template<typename X> struct IMouseDevice_adaptor : X {
	union {
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<MouseDevice>, ptr<MouseEventArgs>>> handler) { Foundation::EventRegistrationToken cookie; hrcheck(enc(&IMouseDevice_adaptor::MouseMoved)->_add_MouseMoved(to_abi(handler), &cookie)); return cookie; }
			void operator-=(const Foundation::EventRegistrationToken& cookie) { hrcheck(enc(&IMouseDevice_adaptor::MouseMoved)->_remove_MouseMoved(cookie)); }
		} MouseMoved;
	};
	IMouseDevice_adaptor() {}
};
template<typename X> struct adapt<IMouseDevice, X> : Windows::Devices::Input::IMouseDevice_adaptor<X> { typedef adapt IMouseDevice; };
struct IMouseDevice : IMouseDevice_raw, generate<IMouseDevice> {};

// IMouseDeviceStatics
struct IMouseDeviceStatics : IInspectable {
	virtual STDMETHODIMP _GetForCurrentView(MouseDevice* *mouseDevice);
};

// MouseDevice
template<typename> struct MouseDevice_statics {
	static ptr<MouseDevice> GetForCurrentView() { MouseDevice* mouseDevice; hrcheck(get_activation_factory<MouseDevice, IMouseDeviceStatics>()->_GetForCurrentView(&mouseDevice)); return from_abi(mouseDevice); }
};

template<typename X> struct statics<MouseDevice, X> : X, Windows::Devices::Input::MouseDevice_statics<void> {
	typedef typename X::root_type MouseDevice;
};
struct MouseDevice : generate<MouseDevice> {};

// MouseEventArgs
template<typename X> struct statics<MouseEventArgs, X> : X {
	typedef typename X::root_type MouseEventArgs;
};
struct MouseEventArgs : generate<MouseEventArgs> {};

// MouseCapabilities
template<typename X> struct statics<MouseCapabilities, X> : X {
	typedef typename X::root_type MouseCapabilities;
};
struct MouseCapabilities : generate<MouseCapabilities> {};

// KeyboardCapabilities
template<typename X> struct statics<KeyboardCapabilities, X> : X {
	typedef typename X::root_type KeyboardCapabilities;
};
struct KeyboardCapabilities : generate<KeyboardCapabilities> {};

// TouchCapabilities
template<typename X> struct statics<TouchCapabilities, X> : X {
	typedef typename X::root_type TouchCapabilities;
};
struct TouchCapabilities : generate<TouchCapabilities> {};
}}}
} // namespace iso_winrt
