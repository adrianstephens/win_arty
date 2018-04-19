#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices.Adc.Provider

#include "Windows.Devices.Adc.Provider.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}}

// defs

template<> struct def<Windows::Devices::Adc::Provider::ProviderAdcChannelMode> : enum_type<int> {};
template<> struct def<Windows::Devices::Adc::Provider::IAdcControllerProvider> : overridable_type<> {};
template<> struct def<Windows::Devices::Adc::Provider::IAdcProvider> : overridable_type<> {};

// uuids

template<> struct uuid<Windows::Devices::Adc::Provider::IAdcControllerProvider> { define_guid(0xBE545828, 0x816D, 0x4DE5, 0xA0, 0x48, 0xAB, 0xA0, 0x69, 0x58, 0xAA, 0xA8);};
template<> struct uuid<Windows::Devices::Adc::Provider::IAdcProvider> { define_guid(0x28953668, 0x9359, 0x4C57, 0xBC, 0x88, 0xE2, 0x75, 0xE8, 0x16, 0x38, 0xC9);};

// types

namespace Windows { namespace Devices { namespace Adc { namespace Provider {

// IAdcControllerProvider
struct IAdcControllerProvider_raw : IInspectable {
	virtual STDMETHODIMP _get_ChannelCount(int *value) = 0;
	virtual STDMETHODIMP _get_ResolutionInBits(int *value) = 0;
	virtual STDMETHODIMP _get_MinValue(int *value) = 0;
	virtual STDMETHODIMP _get_MaxValue(int *value) = 0;
	virtual STDMETHODIMP _get_ChannelMode(ProviderAdcChannelMode *value) = 0;
	virtual STDMETHODIMP _put_ChannelMode(ProviderAdcChannelMode value) = 0;
	virtual STDMETHODIMP _IsChannelModeSupported(ProviderAdcChannelMode channelMode, bool *result) = 0;
	virtual STDMETHODIMP _AcquireChannel(int channel) = 0;
	virtual STDMETHODIMP _ReleaseChannel(int channel) = 0;
	virtual STDMETHODIMP _ReadValue(int channelNumber, int *result) = 0;
};
template<typename X> struct IAdcControllerProvider_adaptor : X {
	union {
		struct : property {
			int get() { int value; hrcheck(enc(&IAdcControllerProvider_adaptor::ChannelCount)->_get_ChannelCount(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} ChannelCount;
		struct : property {
			ProviderAdcChannelMode get() { ProviderAdcChannelMode value; hrcheck(enc(&IAdcControllerProvider_adaptor::ChannelMode)->_get_ChannelMode(&value)); return value; }
			ProviderAdcChannelMode operator()() { return get(); }
			operator ProviderAdcChannelMode () { return get(); }
			void put(ProviderAdcChannelMode value) { hrcheck(enc(&IAdcControllerProvider_adaptor::ChannelMode)->_put_ChannelMode(value)); }
			void operator=(ProviderAdcChannelMode value) { put(value); }
			void operator()(ProviderAdcChannelMode value) { put(value); }
		} ChannelMode;
		struct : property {
			int get() { int value; hrcheck(enc(&IAdcControllerProvider_adaptor::MaxValue)->_get_MaxValue(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} MaxValue;
		struct : property {
			int get() { int value; hrcheck(enc(&IAdcControllerProvider_adaptor::MinValue)->_get_MinValue(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} MinValue;
		struct : property {
			int get() { int value; hrcheck(enc(&IAdcControllerProvider_adaptor::ResolutionInBits)->_get_ResolutionInBits(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} ResolutionInBits;
	};
	bool IsChannelModeSupported(ProviderAdcChannelMode channelMode) { bool result; hrcheck(X::get()->_IsChannelModeSupported(channelMode, &result)); return result; }
	void AcquireChannel(int channel) { hrcheck(X::get()->_AcquireChannel(channel)); }
	void ReleaseChannel(int channel) { hrcheck(X::get()->_ReleaseChannel(channel)); }
	int ReadValue(int channelNumber) { int result; hrcheck(X::get()->_ReadValue(channelNumber, &result)); return result; }
	IAdcControllerProvider_adaptor() {}
};
template<typename X> struct adapt<IAdcControllerProvider, X> : Windows::Devices::Adc::Provider::IAdcControllerProvider_adaptor<X> { typedef adapt IAdcControllerProvider; };
template<typename X> struct IAdcControllerProvider_unadaptor : X {
	STDMETHODIMP _get_ChannelCount(int *value) { return hrtry([&, this] { get_prop(value, ChannelCount); }); }
	STDMETHODIMP _get_ResolutionInBits(int *value) { return hrtry([&, this] { get_prop(value, ResolutionInBits); }); }
	STDMETHODIMP _get_MinValue(int *value) { return hrtry([&, this] { get_prop(value, MinValue); }); }
	STDMETHODIMP _get_MaxValue(int *value) { return hrtry([&, this] { get_prop(value, MaxValue); }); }
	STDMETHODIMP _get_ChannelMode(ProviderAdcChannelMode *value) { return hrtry([&, this] { get_prop(value, ChannelMode); }); }
	STDMETHODIMP _put_ChannelMode(ProviderAdcChannelMode value) { return hrtry([&, this] { put_prop(value, ChannelMode); }); }
	STDMETHODIMP _IsChannelModeSupported(ProviderAdcChannelMode channelMode, bool *result) { return hrtry([&, this] { *result = X::get()->IsChannelModeSupported(channelMode); }); }
	STDMETHODIMP _AcquireChannel(int channel) { return hrtry([&, this] { X::get()->AcquireChannel(channel); }); }
	STDMETHODIMP _ReleaseChannel(int channel) { return hrtry([&, this] { X::get()->ReleaseChannel(channel); }); }
	STDMETHODIMP _ReadValue(int channelNumber, int *result) { return hrtry([&, this] { *result = X::get()->ReadValue(channelNumber); }); }
};
template<typename X> struct unadapt<IAdcControllerProvider, X> : Windows::Devices::Adc::Provider::IAdcControllerProvider_unadaptor<X> {};
struct IAdcControllerProvider : IAdcControllerProvider_raw, generate<IAdcControllerProvider> {};

// IAdcProvider
struct IAdcProvider_raw : IInspectable {
	virtual STDMETHODIMP _GetControllers(Foundation::Collections::IVectorView<IAdcControllerProvider*>* *result) = 0;
};
template<typename X> struct IAdcProvider_adaptor : X {
	ptr<Foundation::Collections::IVectorView<ptr<IAdcControllerProvider>>> GetControllers() { Foundation::Collections::IVectorView<IAdcControllerProvider*>* result; hrcheck(X::get()->_GetControllers(&result)); return from_abi(result); }
};
template<typename X> struct adapt<IAdcProvider, X> : Windows::Devices::Adc::Provider::IAdcProvider_adaptor<X> { typedef adapt IAdcProvider; };
template<typename X> struct IAdcProvider_unadaptor : X {
	STDMETHODIMP _GetControllers(Foundation::Collections::IVectorView<IAdcControllerProvider*>* *result) { return hrtry([&, this] { *result = to_abi(X::get()->GetControllers()); }); }
};
template<typename X> struct unadapt<IAdcProvider, X> : Windows::Devices::Adc::Provider::IAdcProvider_unadaptor<X> {};
struct IAdcProvider : IAdcProvider_raw, generate<IAdcProvider> {};
}}}}
} // namespace iso_winrt
