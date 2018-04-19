#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices.Pwm.Provider

#include "Windows.Devices.Pwm.Provider.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Pwm { namespace Provider {
struct IPwmControllerProvider;
}}}
namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}}

// defs

template<> struct def<Windows::Devices::Pwm::Provider::IPwmProvider> : overridable_type<> {};
template<> struct def<Windows::Devices::Pwm::Provider::IPwmControllerProvider> : overridable_type<> {};

// uuids

template<> struct uuid<Windows::Devices::Pwm::Provider::IPwmProvider> { define_guid(0xA3301228, 0x52F1, 0x47B0, 0x93, 0x49, 0x66, 0xBA, 0x43, 0xD2, 0x59, 0x2);};
template<> struct uuid<Windows::Devices::Pwm::Provider::IPwmControllerProvider> { define_guid(0x1300593B, 0xE2E3, 0x40A4, 0xB7, 0xD9, 0x48, 0xDF, 0xF0, 0x37, 0x7A, 0x52);};

// types

namespace Windows { namespace Devices { namespace Pwm { namespace Provider {

// IPwmProvider
struct IPwmProvider_raw : IInspectable {
	virtual STDMETHODIMP _GetControllers(Foundation::Collections::IVectorView<IPwmControllerProvider*>* *result) = 0;
};
template<typename X> struct IPwmProvider_adaptor : X {
	ptr<Foundation::Collections::IVectorView<ptr<IPwmControllerProvider>>> GetControllers() { Foundation::Collections::IVectorView<IPwmControllerProvider*>* result; hrcheck(X::get()->_GetControllers(&result)); return from_abi(result); }
};
template<typename X> struct adapt<IPwmProvider, X> : Windows::Devices::Pwm::Provider::IPwmProvider_adaptor<X> { typedef adapt IPwmProvider; };
template<typename X> struct IPwmProvider_unadaptor : X {
	STDMETHODIMP _GetControllers(Foundation::Collections::IVectorView<IPwmControllerProvider*>* *result) { return hrtry([&, this] { *result = to_abi(X::get()->GetControllers()); }); }
};
template<typename X> struct unadapt<IPwmProvider, X> : Windows::Devices::Pwm::Provider::IPwmProvider_unadaptor<X> {};
struct IPwmProvider : IPwmProvider_raw, generate<IPwmProvider> {};

// IPwmControllerProvider
struct IPwmControllerProvider_raw : IInspectable {
	virtual STDMETHODIMP _get_PinCount(int *value) = 0;
	virtual STDMETHODIMP _get_ActualFrequency(double *value) = 0;
	virtual STDMETHODIMP _SetDesiredFrequency(double frequency, double *result) = 0;
	virtual STDMETHODIMP _get_MaxFrequency(double *value) = 0;
	virtual STDMETHODIMP _get_MinFrequency(double *value) = 0;
	virtual STDMETHODIMP _AcquirePin(int pin) = 0;
	virtual STDMETHODIMP _ReleasePin(int pin) = 0;
	virtual STDMETHODIMP _EnablePin(int pin) = 0;
	virtual STDMETHODIMP _DisablePin(int pin) = 0;
	virtual STDMETHODIMP _SetPulseParameters(int pin, double dutyCycle, bool invertPolarity) = 0;
};
template<typename X> struct IPwmControllerProvider_adaptor : X {
	union {
		struct : property {
			double get() { double value; hrcheck(enc(&IPwmControllerProvider_adaptor::ActualFrequency)->_get_ActualFrequency(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
		} ActualFrequency;
		struct : property {
			double get() { double value; hrcheck(enc(&IPwmControllerProvider_adaptor::MaxFrequency)->_get_MaxFrequency(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
		} MaxFrequency;
		struct : property {
			double get() { double value; hrcheck(enc(&IPwmControllerProvider_adaptor::MinFrequency)->_get_MinFrequency(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
		} MinFrequency;
		struct : property {
			int get() { int value; hrcheck(enc(&IPwmControllerProvider_adaptor::PinCount)->_get_PinCount(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} PinCount;
	};
	double SetDesiredFrequency(double frequency) { double result; hrcheck(X::get()->_SetDesiredFrequency(frequency, &result)); return result; }
	void AcquirePin(int pin) { hrcheck(X::get()->_AcquirePin(pin)); }
	void ReleasePin(int pin) { hrcheck(X::get()->_ReleasePin(pin)); }
	void EnablePin(int pin) { hrcheck(X::get()->_EnablePin(pin)); }
	void DisablePin(int pin) { hrcheck(X::get()->_DisablePin(pin)); }
	void SetPulseParameters(int pin, double dutyCycle, bool invertPolarity) { hrcheck(X::get()->_SetPulseParameters(pin, dutyCycle, invertPolarity)); }
	IPwmControllerProvider_adaptor() {}
};
template<typename X> struct adapt<IPwmControllerProvider, X> : Windows::Devices::Pwm::Provider::IPwmControllerProvider_adaptor<X> { typedef adapt IPwmControllerProvider; };
template<typename X> struct IPwmControllerProvider_unadaptor : X {
	STDMETHODIMP _get_PinCount(int *value) { return hrtry([&, this] { get_prop(value, PinCount); }); }
	STDMETHODIMP _get_ActualFrequency(double *value) { return hrtry([&, this] { get_prop(value, ActualFrequency); }); }
	STDMETHODIMP _SetDesiredFrequency(double frequency, double *result) { return hrtry([&, this] { *result = X::get()->SetDesiredFrequency(frequency); }); }
	STDMETHODIMP _get_MaxFrequency(double *value) { return hrtry([&, this] { get_prop(value, MaxFrequency); }); }
	STDMETHODIMP _get_MinFrequency(double *value) { return hrtry([&, this] { get_prop(value, MinFrequency); }); }
	STDMETHODIMP _AcquirePin(int pin) { return hrtry([&, this] { X::get()->AcquirePin(pin); }); }
	STDMETHODIMP _ReleasePin(int pin) { return hrtry([&, this] { X::get()->ReleasePin(pin); }); }
	STDMETHODIMP _EnablePin(int pin) { return hrtry([&, this] { X::get()->EnablePin(pin); }); }
	STDMETHODIMP _DisablePin(int pin) { return hrtry([&, this] { X::get()->DisablePin(pin); }); }
	STDMETHODIMP _SetPulseParameters(int pin, double dutyCycle, bool invertPolarity) { return hrtry([&, this] { X::get()->SetPulseParameters(pin, dutyCycle, invertPolarity); }); }
};
template<typename X> struct unadapt<IPwmControllerProvider, X> : Windows::Devices::Pwm::Provider::IPwmControllerProvider_unadaptor<X> {};
struct IPwmControllerProvider : IPwmControllerProvider_raw, generate<IPwmControllerProvider> {};
}}}}
} // namespace iso_winrt
