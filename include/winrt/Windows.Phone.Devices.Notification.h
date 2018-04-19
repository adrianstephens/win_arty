#pragma once
// generated by isopod tools
// namespaces:
// Windows.Phone.Devices.Notification

#include "Windows.Phone.Devices.Notification.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Phone::Devices::Notification::IVibrationDeviceStatics> : interface_type<> {};
template<> struct def<Windows::Phone::Devices::Notification::IVibrationDevice> : interface_type<> {};
template<> struct def<Windows::Phone::Devices::Notification::VibrationDevice> : class_type<Platform::Object, Windows::Phone::Devices::Notification::IVibrationDevice> {};

// uuids

template<> struct uuid<Windows::Phone::Devices::Notification::IVibrationDeviceStatics> { define_guid(0x332FD2F1, 0x1C69, 0x4C91, 0x94, 0x9E, 0x4B, 0xB6, 0x7A, 0x85, 0xBD, 0xC7);};
template<> struct uuid<Windows::Phone::Devices::Notification::IVibrationDevice> { define_guid(0x1B4A6595, 0xCFCD, 0x4E08, 0x92, 0xFB, 0xC1, 0x90, 0x6D, 0x4, 0x49, 0x8C);};

// types

namespace Windows { namespace Phone { namespace Devices { namespace Notification {

// IVibrationDeviceStatics
struct IVibrationDeviceStatics : IInspectable {
	virtual STDMETHODIMP _GetDefault(VibrationDevice* *result);
};

// IVibrationDevice
struct IVibrationDevice_raw : IInspectable {
	virtual STDMETHODIMP _Vibrate(Foundation::TimeSpan duration);
	virtual STDMETHODIMP _Cancel();
};
template<typename X> struct IVibrationDevice_adaptor : X {
	void Vibrate(const Foundation::TimeSpan& duration) { hrcheck(X::get()->_Vibrate(duration)); }
	void Cancel() { hrcheck(X::get()->_Cancel()); }
};
template<typename X> struct adapt<IVibrationDevice, X> : Windows::Phone::Devices::Notification::IVibrationDevice_adaptor<X> { typedef adapt IVibrationDevice; };
struct IVibrationDevice : IVibrationDevice_raw, generate<IVibrationDevice> {};

// VibrationDevice
template<typename> struct VibrationDevice_statics {
	static ptr<VibrationDevice> GetDefault() { VibrationDevice* result; hrcheck(get_activation_factory<VibrationDevice, IVibrationDeviceStatics>()->_GetDefault(&result)); return from_abi(result); }
};

template<typename X> struct statics<VibrationDevice, X> : X, Windows::Phone::Devices::Notification::VibrationDevice_statics<void> {
	typedef typename X::root_type VibrationDevice;
};
struct VibrationDevice : generate<VibrationDevice> {};
}}}}
} // namespace iso_winrt