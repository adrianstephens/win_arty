#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices.Radios

#include "Windows.Devices.Radios.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}}

// defs

template<> struct def<Windows::Devices::Radios::RadioKind> : enum_type<int> {};
template<> struct def<Windows::Devices::Radios::RadioAccessStatus> : enum_type<int> {};
template<> struct def<Windows::Devices::Radios::IRadioStatics> : interface_type<> {};
template<> struct def<Windows::Devices::Radios::RadioState> : enum_type<int> {};
template<> struct def<Windows::Devices::Radios::IRadio> : interface_type<> {};
template<> struct def<Windows::Devices::Radios::Radio> : class_type<Platform::Object, Windows::Devices::Radios::IRadio> {};

// uuids

template<> struct uuid<Windows::Devices::Radios::IRadioStatics> { define_guid(0x5FB6A12E, 0x67CB, 0x46AE, 0xAA, 0xE9, 0x65, 0x91, 0x9F, 0x86, 0xEF, 0xF4);};
template<> struct uuid<Windows::Devices::Radios::IRadio> { define_guid(0x252118DF, 0xB33E, 0x416A, 0x87, 0x5F, 0x1C, 0xF3, 0x8A, 0xE2, 0xD8, 0x3E);};

// types

namespace Windows { namespace Devices { namespace Radios {

// IRadioStatics
struct IRadioStatics : IInspectable {
	virtual STDMETHODIMP _GetRadiosAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Radio*>*>* *value);
	virtual STDMETHODIMP _GetDeviceSelector(HSTRING *deviceSelector);
	virtual STDMETHODIMP _FromIdAsync(HSTRING deviceId, Foundation::IAsyncOperation<Radio*>* *value);
	virtual STDMETHODIMP _RequestAccessAsync(Foundation::IAsyncOperation<RadioAccessStatus>* *value);
};

// IRadio
struct IRadio_raw : IInspectable {
	virtual STDMETHODIMP _SetStateAsync(RadioState value, Foundation::IAsyncOperation<RadioAccessStatus>* *retval);
	virtual STDMETHODIMP _add_StateChanged(Foundation::TypedEventHandler<Radio*, IInspectable*>* handler, Foundation::EventRegistrationToken *eventCookie);
	virtual STDMETHODIMP _remove_StateChanged(Foundation::EventRegistrationToken eventCookie);
	virtual STDMETHODIMP _get_State(RadioState *value);
	virtual STDMETHODIMP _get_Name(HSTRING *value);
	virtual STDMETHODIMP _get_Kind(RadioKind *value);
};
template<typename X> struct IRadio_adaptor : X {
	union {
		struct : property {
			RadioKind get() { RadioKind value; hrcheck(enc(&IRadio_adaptor::Kind)->_get_Kind(&value)); return value; }
			RadioKind operator()() { return get(); }
			operator RadioKind () { return get(); }
		} Kind;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IRadio_adaptor::Name)->_get_Name(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Name;
		struct : property {
			RadioState get() { RadioState value; hrcheck(enc(&IRadio_adaptor::State)->_get_State(&value)); return value; }
			RadioState operator()() { return get(); }
			operator RadioState () { return get(); }
		} State;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<Radio>, object>> handler) { Foundation::EventRegistrationToken eventCookie; hrcheck(enc(&IRadio_adaptor::StateChanged)->_add_StateChanged(to_abi(handler), &eventCookie)); return eventCookie; }
			void operator-=(const Foundation::EventRegistrationToken& eventCookie) { hrcheck(enc(&IRadio_adaptor::StateChanged)->_remove_StateChanged(eventCookie)); }
		} StateChanged;
	};
	ptr<Foundation::IAsyncOperation<RadioAccessStatus>> SetStateAsync(RadioState value) { Foundation::IAsyncOperation<RadioAccessStatus>* retval; hrcheck(X::get()->_SetStateAsync(value, &retval)); return from_abi(retval); }
	IRadio_adaptor() {}
};
template<typename X> struct adapt<IRadio, X> : Windows::Devices::Radios::IRadio_adaptor<X> { typedef adapt IRadio; };
struct IRadio : IRadio_raw, generate<IRadio> {};

// Radio
template<typename> struct Radio_statics {
	static ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<Radio>>>>> GetRadiosAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Radio*>*>* value; hrcheck(get_activation_factory<Radio, IRadioStatics>()->_GetRadiosAsync(&value)); return from_abi(value); }
	static hstring GetDeviceSelector() { HSTRING deviceSelector; hrcheck(get_activation_factory<Radio, IRadioStatics>()->_GetDeviceSelector(&deviceSelector)); return from_abi(deviceSelector); }
	static ptr<Foundation::IAsyncOperation<ptr<Radio>>> FromIdAsync(hstring_ref deviceId) { Foundation::IAsyncOperation<Radio*>* value; hrcheck(get_activation_factory<Radio, IRadioStatics>()->_FromIdAsync(deviceId, &value)); return from_abi(value); }
	static ptr<Foundation::IAsyncOperation<RadioAccessStatus>> RequestAccessAsync() { Foundation::IAsyncOperation<RadioAccessStatus>* value; hrcheck(get_activation_factory<Radio, IRadioStatics>()->_RequestAccessAsync(&value)); return from_abi(value); }
};

template<typename X> struct statics<Radio, X> : X, Windows::Devices::Radios::Radio_statics<void> {
	typedef typename X::root_type Radio;
};
struct Radio : generate<Radio> {};
}}}
} // namespace iso_winrt