#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices.Adc

#include "Windows.Devices.Adc.0.h"
#include "Windows.Foundation.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Adc { namespace Provider {
struct IAdcProvider;
}}}
namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}}

// defs

template<> struct def<Windows::Devices::Adc::AdcChannelMode> : enum_type<int> {};
template<> struct def<Windows::Devices::Adc::IAdcController> : interface_type<> {};
template<> struct def<Windows::Devices::Adc::IAdcChannel> : interface_type<Windows::Foundation::IClosable> {};
template<> struct def<Windows::Devices::Adc::AdcChannel> : class_type<Platform::Object, Windows::Devices::Adc::IAdcChannel> {};
template<> struct def<Windows::Devices::Adc::IAdcControllerStatics> : interface_type<> {};
template<> struct def<Windows::Devices::Adc::IAdcControllerStatics2> : interface_type<> {};
template<> struct def<Windows::Devices::Adc::AdcController> : class_type<Platform::Object, Windows::Devices::Adc::IAdcController> {};

// uuids

template<> struct uuid<Windows::Devices::Adc::IAdcController> { define_guid(0x2A76E4B0, 0xA896, 0x4219, 0x86, 0xB6, 0xEA, 0x8C, 0xDC, 0xE9, 0x8F, 0x56);};
template<> struct uuid<Windows::Devices::Adc::IAdcChannel> { define_guid(0x40BF414, 0x2588, 0x4A56, 0xAB, 0xEF, 0x73, 0xA2, 0x60, 0xAC, 0xC6, 0xA);};
template<> struct uuid<Windows::Devices::Adc::IAdcControllerStatics> { define_guid(0xCCE98E0C, 0x1F8, 0x4891, 0xBC, 0x3B, 0xBE, 0x53, 0xEF, 0x27, 0x9C, 0xA4);};
template<> struct uuid<Windows::Devices::Adc::IAdcControllerStatics2> { define_guid(0xA2B93B1D, 0x977B, 0x4F5A, 0xA5, 0xFE, 0xA6, 0xAB, 0xAF, 0xFE, 0x64, 0x84);};

// types

namespace Windows { namespace Devices { namespace Adc {

// IAdcController
struct IAdcController_raw : IInspectable {
	virtual STDMETHODIMP _get_ChannelCount(int *value);
	virtual STDMETHODIMP _get_ResolutionInBits(int *value);
	virtual STDMETHODIMP _get_MinValue(int *value);
	virtual STDMETHODIMP _get_MaxValue(int *value);
	virtual STDMETHODIMP _get_ChannelMode(AdcChannelMode *value);
	virtual STDMETHODIMP _put_ChannelMode(AdcChannelMode value);
	virtual STDMETHODIMP _IsChannelModeSupported(AdcChannelMode channelMode, bool *result);
	virtual STDMETHODIMP _OpenChannel(int channelNumber, AdcChannel* *result);
};
template<typename X> struct IAdcController_adaptor : X {
	union {
		struct : property {
			int get() { int value; hrcheck(enc(&IAdcController_adaptor::ChannelCount)->_get_ChannelCount(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} ChannelCount;
		struct : property {
			AdcChannelMode get() { AdcChannelMode value; hrcheck(enc(&IAdcController_adaptor::ChannelMode)->_get_ChannelMode(&value)); return value; }
			AdcChannelMode operator()() { return get(); }
			operator AdcChannelMode () { return get(); }
			void put(AdcChannelMode value) { hrcheck(enc(&IAdcController_adaptor::ChannelMode)->_put_ChannelMode(value)); }
			void operator=(AdcChannelMode value) { put(value); }
			void operator()(AdcChannelMode value) { put(value); }
		} ChannelMode;
		struct : property {
			int get() { int value; hrcheck(enc(&IAdcController_adaptor::MaxValue)->_get_MaxValue(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} MaxValue;
		struct : property {
			int get() { int value; hrcheck(enc(&IAdcController_adaptor::MinValue)->_get_MinValue(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} MinValue;
		struct : property {
			int get() { int value; hrcheck(enc(&IAdcController_adaptor::ResolutionInBits)->_get_ResolutionInBits(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} ResolutionInBits;
	};
	bool IsChannelModeSupported(AdcChannelMode channelMode) { bool result; hrcheck(X::get()->_IsChannelModeSupported(channelMode, &result)); return result; }
	ptr<AdcChannel> OpenChannel(int channelNumber) { AdcChannel* result; hrcheck(X::get()->_OpenChannel(channelNumber, &result)); return from_abi(result); }
	IAdcController_adaptor() {}
};
template<typename X> struct adapt<IAdcController, X> : Windows::Devices::Adc::IAdcController_adaptor<X> { typedef adapt IAdcController; };
struct IAdcController : IAdcController_raw, generate<IAdcController> {};

// IAdcChannel
struct IAdcChannel_raw : IInspectable {
	virtual STDMETHODIMP _get_Controller(AdcController* *value);
	virtual STDMETHODIMP _ReadValue(int *result);
	virtual STDMETHODIMP _ReadRatio(double *result);
};
template<typename X> struct IAdcChannel_adaptor : X {
	union {
		struct : property {
			ptr<AdcController> get() { AdcController* value; hrcheck(enc(&IAdcChannel_adaptor::Controller)->_get_Controller(&value)); return from_abi(value); }
			ptr<AdcController> operator()() { return get(); }
			operator ptr<AdcController> () { return get(); }
			ptr<AdcController> operator->() { return get(); }
		} Controller;
	};
	int ReadValue() { int result; hrcheck(X::get()->_ReadValue(&result)); return result; }
	double ReadRatio() { double result; hrcheck(X::get()->_ReadRatio(&result)); return result; }
	IAdcChannel_adaptor() {}
};
template<typename X> struct adapt<IAdcChannel, X> : Windows::Devices::Adc::IAdcChannel_adaptor<X> { typedef adapt IAdcChannel; };
struct IAdcChannel : IAdcChannel_raw, generate<IAdcChannel> {};

// AdcChannel
template<typename X> struct statics<AdcChannel, X> : X {
	typedef typename X::root_type AdcChannel;
};
struct AdcChannel : generate<AdcChannel> {};

// IAdcControllerStatics
struct IAdcControllerStatics : IInspectable {
	virtual STDMETHODIMP _GetControllersAsync(Provider::IAdcProvider* provider, Foundation::IAsyncOperation<Foundation::Collections::IVectorView<AdcController*>*>* *operation);
};

// IAdcControllerStatics2
struct IAdcControllerStatics2 : IInspectable {
	virtual STDMETHODIMP _GetDefaultAsync(Foundation::IAsyncOperation<AdcController*>* *operation);
};

// AdcController
template<typename> struct AdcController_statics {
	static ptr<Foundation::IAsyncOperation<ptr<AdcController>>> GetDefaultAsync() { Foundation::IAsyncOperation<AdcController*>* operation; hrcheck(get_activation_factory<AdcController, IAdcControllerStatics2>()->_GetDefaultAsync(&operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<AdcController>>>>> GetControllersAsync(pptr<Provider::IAdcProvider> provider) { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<AdcController*>*>* operation; hrcheck(get_activation_factory<AdcController, IAdcControllerStatics>()->_GetControllersAsync(provider, &operation)); return from_abi(operation); }
};

template<typename X> struct statics<AdcController, X> : X, Windows::Devices::Adc::AdcController_statics<void> {
	typedef typename X::root_type AdcController;
};
struct AdcController : generate<AdcController> {};
}}}
} // namespace iso_winrt
