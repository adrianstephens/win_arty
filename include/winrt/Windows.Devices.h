#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices

#include "Windows.Devices.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Adc { namespace Provider {
struct IAdcControllerProvider;
}}
namespace Gpio { namespace Provider {
struct IGpioControllerProvider;
}}
namespace I2c { namespace Provider {
struct II2cControllerProvider;
}}
namespace Pwm { namespace Provider {
struct IPwmControllerProvider;
}}
namespace Spi { namespace Provider {
struct ISpiControllerProvider;
}}}}

// defs

template<> struct def<Windows::Devices::ILowLevelDevicesAggregateProvider> : overridable_type<> {};
template<> struct def<Windows::Devices::ILowLevelDevicesAggregateProviderFactory> : interface_type<> {};
template<> struct def<Windows::Devices::LowLevelDevicesAggregateProvider> : class_type<Platform::Object, Windows::Devices::ILowLevelDevicesAggregateProvider>, custom_activators {};
template<> struct def<Windows::Devices::ILowLevelDevicesController> : interface_type<> {};
template<> struct def<Windows::Devices::ILowLevelDevicesControllerStatics> : interface_type<> {};
template<> struct def<Windows::Devices::LowLevelDevicesController> : class_type<Platform::Object, Windows::Devices::ILowLevelDevicesController> {};
template<> struct def<Windows::Devices::DevicesLowLevelContract> : value_type<> {};

// uuids

template<> struct uuid<Windows::Devices::ILowLevelDevicesAggregateProvider> { define_guid(0xA73E561C, 0xAAC1, 0x4EC7, 0xA8, 0x52, 0x47, 0x9F, 0x70, 0x60, 0xD0, 0x1F);};
template<> struct uuid<Windows::Devices::ILowLevelDevicesAggregateProviderFactory> { define_guid(0x9AC4AAF6, 0x3473, 0x465E, 0x96, 0xD5, 0x36, 0x28, 0x1A, 0x2C, 0x57, 0xAF);};
template<> struct uuid<Windows::Devices::ILowLevelDevicesController> { define_guid(0x2EC23DD4, 0x179B, 0x45DE, 0x9B, 0x39, 0x3A, 0xE0, 0x25, 0x27, 0xDE, 0x52);};
template<> struct uuid<Windows::Devices::ILowLevelDevicesControllerStatics> { define_guid(0x93E926A, 0xFCCB, 0x4394, 0xA6, 0x97, 0x19, 0xDE, 0x63, 0x7C, 0x2D, 0xB3);};

// types

namespace Windows { namespace Devices {

// ILowLevelDevicesAggregateProvider
struct ILowLevelDevicesAggregateProvider_raw : IInspectable {
	virtual STDMETHODIMP _get_AdcControllerProvider(Adc::Provider::IAdcControllerProvider* *value) = 0;
	virtual STDMETHODIMP _get_PwmControllerProvider(Pwm::Provider::IPwmControllerProvider* *value) = 0;
	virtual STDMETHODIMP _get_GpioControllerProvider(Gpio::Provider::IGpioControllerProvider* *value) = 0;
	virtual STDMETHODIMP _get_I2cControllerProvider(I2c::Provider::II2cControllerProvider* *value) = 0;
	virtual STDMETHODIMP _get_SpiControllerProvider(Spi::Provider::ISpiControllerProvider* *value) = 0;
};
template<typename X> struct ILowLevelDevicesAggregateProvider_adaptor : X {
	union {
		struct : property {
			ptr<Adc::Provider::IAdcControllerProvider> get() { Adc::Provider::IAdcControllerProvider* value; hrcheck(enc(&ILowLevelDevicesAggregateProvider_adaptor::AdcControllerProvider)->_get_AdcControllerProvider(&value)); return from_abi(value); }
			ptr<Adc::Provider::IAdcControllerProvider> operator()() { return get(); }
			operator ptr<Adc::Provider::IAdcControllerProvider> () { return get(); }
			ptr<Adc::Provider::IAdcControllerProvider> operator->() { return get(); }
		} AdcControllerProvider;
		struct : property {
			ptr<Gpio::Provider::IGpioControllerProvider> get() { Gpio::Provider::IGpioControllerProvider* value; hrcheck(enc(&ILowLevelDevicesAggregateProvider_adaptor::GpioControllerProvider)->_get_GpioControllerProvider(&value)); return from_abi(value); }
			ptr<Gpio::Provider::IGpioControllerProvider> operator()() { return get(); }
			operator ptr<Gpio::Provider::IGpioControllerProvider> () { return get(); }
			ptr<Gpio::Provider::IGpioControllerProvider> operator->() { return get(); }
		} GpioControllerProvider;
		struct : property {
			ptr<I2c::Provider::II2cControllerProvider> get() { I2c::Provider::II2cControllerProvider* value; hrcheck(enc(&ILowLevelDevicesAggregateProvider_adaptor::I2cControllerProvider)->_get_I2cControllerProvider(&value)); return from_abi(value); }
			ptr<I2c::Provider::II2cControllerProvider> operator()() { return get(); }
			operator ptr<I2c::Provider::II2cControllerProvider> () { return get(); }
			ptr<I2c::Provider::II2cControllerProvider> operator->() { return get(); }
		} I2cControllerProvider;
		struct : property {
			ptr<Pwm::Provider::IPwmControllerProvider> get() { Pwm::Provider::IPwmControllerProvider* value; hrcheck(enc(&ILowLevelDevicesAggregateProvider_adaptor::PwmControllerProvider)->_get_PwmControllerProvider(&value)); return from_abi(value); }
			ptr<Pwm::Provider::IPwmControllerProvider> operator()() { return get(); }
			operator ptr<Pwm::Provider::IPwmControllerProvider> () { return get(); }
			ptr<Pwm::Provider::IPwmControllerProvider> operator->() { return get(); }
		} PwmControllerProvider;
		struct : property {
			ptr<Spi::Provider::ISpiControllerProvider> get() { Spi::Provider::ISpiControllerProvider* value; hrcheck(enc(&ILowLevelDevicesAggregateProvider_adaptor::SpiControllerProvider)->_get_SpiControllerProvider(&value)); return from_abi(value); }
			ptr<Spi::Provider::ISpiControllerProvider> operator()() { return get(); }
			operator ptr<Spi::Provider::ISpiControllerProvider> () { return get(); }
			ptr<Spi::Provider::ISpiControllerProvider> operator->() { return get(); }
		} SpiControllerProvider;
	};
	ILowLevelDevicesAggregateProvider_adaptor() {}
};
template<typename X> struct adapt<ILowLevelDevicesAggregateProvider, X> : Windows::Devices::ILowLevelDevicesAggregateProvider_adaptor<X> { typedef adapt ILowLevelDevicesAggregateProvider; };
template<typename X> struct ILowLevelDevicesAggregateProvider_unadaptor : X {
	STDMETHODIMP _get_AdcControllerProvider(Adc::Provider::IAdcControllerProvider* *value) { return hrtry([&, this] { get_prop(value, AdcControllerProvider); }); }
	STDMETHODIMP _get_PwmControllerProvider(Pwm::Provider::IPwmControllerProvider* *value) { return hrtry([&, this] { get_prop(value, PwmControllerProvider); }); }
	STDMETHODIMP _get_GpioControllerProvider(Gpio::Provider::IGpioControllerProvider* *value) { return hrtry([&, this] { get_prop(value, GpioControllerProvider); }); }
	STDMETHODIMP _get_I2cControllerProvider(I2c::Provider::II2cControllerProvider* *value) { return hrtry([&, this] { get_prop(value, I2cControllerProvider); }); }
	STDMETHODIMP _get_SpiControllerProvider(Spi::Provider::ISpiControllerProvider* *value) { return hrtry([&, this] { get_prop(value, SpiControllerProvider); }); }
};
template<typename X> struct unadapt<ILowLevelDevicesAggregateProvider, X> : Windows::Devices::ILowLevelDevicesAggregateProvider_unadaptor<X> {};
struct ILowLevelDevicesAggregateProvider : ILowLevelDevicesAggregateProvider_raw, generate<ILowLevelDevicesAggregateProvider> {};

// ILowLevelDevicesAggregateProviderFactory
struct ILowLevelDevicesAggregateProviderFactory : IInspectable {
	virtual STDMETHODIMP _Create(Adc::Provider::IAdcControllerProvider* adc, Pwm::Provider::IPwmControllerProvider* pwm, Gpio::Provider::IGpioControllerProvider* gpio, I2c::Provider::II2cControllerProvider* i2c, Spi::Provider::ISpiControllerProvider* spi, LowLevelDevicesAggregateProvider* *value);
};

// LowLevelDevicesAggregateProvider
template<typename> struct LowLevelDevicesAggregateProvider_statics {
	static LowLevelDevicesAggregateProvider *activate(pptr<Adc::Provider::IAdcControllerProvider> adc, pptr<Pwm::Provider::IPwmControllerProvider> pwm, pptr<Gpio::Provider::IGpioControllerProvider> gpio, pptr<I2c::Provider::II2cControllerProvider> i2c, pptr<Spi::Provider::ISpiControllerProvider> spi) { LowLevelDevicesAggregateProvider *value; hrcheck(get_activation_factory<LowLevelDevicesAggregateProvider, ILowLevelDevicesAggregateProviderFactory>()->_Create(adc, pwm, gpio, i2c, spi, &value)); return value; }
};

template<typename X> struct statics<LowLevelDevicesAggregateProvider, X> : X, Windows::Devices::LowLevelDevicesAggregateProvider_statics<void> {
	using Windows::Devices::LowLevelDevicesAggregateProvider_statics<void>::activate;
	typedef typename X::root_type LowLevelDevicesAggregateProvider;
};
struct LowLevelDevicesAggregateProvider : generate<LowLevelDevicesAggregateProvider> {};

// ILowLevelDevicesController
struct ILowLevelDevicesController : IInspectable, generate<ILowLevelDevicesController> {};

// ILowLevelDevicesControllerStatics
struct ILowLevelDevicesControllerStatics : IInspectable {
	virtual STDMETHODIMP _get_DefaultProvider(ILowLevelDevicesAggregateProvider* *value);
	virtual STDMETHODIMP _put_DefaultProvider(ILowLevelDevicesAggregateProvider* value);
};

// LowLevelDevicesController
template<typename> struct LowLevelDevicesController_statics {
	static struct _DefaultProvider : property {
		ptr<ILowLevelDevicesAggregateProvider> get() { ILowLevelDevicesAggregateProvider* value; hrcheck(get_activation_factory<LowLevelDevicesController, ILowLevelDevicesControllerStatics>()->_get_DefaultProvider(&value)); return from_abi(value); }
		ptr<ILowLevelDevicesAggregateProvider> operator()() { return get(); }
		operator ptr<ILowLevelDevicesAggregateProvider> () { return get(); }
		ptr<ILowLevelDevicesAggregateProvider> operator->() { return get(); }
		void put(pptr<ILowLevelDevicesAggregateProvider> value) { hrcheck(get_activation_factory<LowLevelDevicesController, ILowLevelDevicesControllerStatics>()->_put_DefaultProvider(value)); }
		void operator=(pptr<ILowLevelDevicesAggregateProvider> value) { put(value); }
		void operator()(pptr<ILowLevelDevicesAggregateProvider> value) { put(value); }
	} DefaultProvider;
};
template<typename X> typename LowLevelDevicesController_statics<X>::_DefaultProvider LowLevelDevicesController_statics<X>::DefaultProvider;

template<typename X> struct statics<LowLevelDevicesController, X> : X, Windows::Devices::LowLevelDevicesController_statics<void> {
	typedef typename X::root_type LowLevelDevicesController;
};
struct LowLevelDevicesController : generate<LowLevelDevicesController> {};
}}
} // namespace iso_winrt