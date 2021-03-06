#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices.Gpio

#include "Windows.Devices.Gpio.0.h"
#include "Windows.Foundation.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Gpio { namespace Provider {
struct IGpioProvider;
}}}
namespace Foundation { namespace Collections {
template<typename T> struct IVector;
template<typename T> struct IVectorView;
}}}

// defs

template<> struct def<Windows::Devices::Gpio::GpioSharingMode> : enum_type<int> {};
template<> struct def<Windows::Devices::Gpio::GpioOpenStatus> : enum_type<int> {};
template<> struct def<Windows::Devices::Gpio::GpioPinDriveMode> : enum_type<int> {};
template<> struct def<Windows::Devices::Gpio::GpioPinValue> : enum_type<int> {};
template<> struct def<Windows::Devices::Gpio::GpioPinEdge> : enum_type<int> {};
template<> struct def<Windows::Devices::Gpio::GpioChangePolarity> : enum_type<int> {};
template<> struct def<Windows::Devices::Gpio::GpioChangeRecord> : value_type<Windows::Foundation::TimeSpan, Windows::Devices::Gpio::GpioPinEdge> {};
template<> struct def<Windows::Devices::Gpio::GpioChangeCount> : value_type<unsigned __int64, Windows::Foundation::TimeSpan> {};
template<> struct def<Windows::Devices::Gpio::IGpioPinValueChangedEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::Gpio::GpioPinValueChangedEventArgs> : class_type<Platform::Object, Windows::Devices::Gpio::IGpioPinValueChangedEventArgs> {};
template<> struct def<Windows::Devices::Gpio::IGpioPin> : interface_type<Windows::Foundation::IClosable> {};
template<> struct def<Windows::Devices::Gpio::GpioPin> : class_type<Platform::Object, Windows::Devices::Gpio::IGpioPin> {};
template<> struct def<Windows::Devices::Gpio::IGpioController> : interface_type<> {};
template<> struct def<Windows::Devices::Gpio::IGpioControllerStatics> : interface_type<> {};
template<> struct def<Windows::Devices::Gpio::IGpioControllerStatics2> : interface_type<> {};
template<> struct def<Windows::Devices::Gpio::GpioController> : class_type<Platform::Object, Windows::Devices::Gpio::IGpioController> {};
template<> struct def<Windows::Devices::Gpio::IGpioChangeReaderFactory> : interface_type<> {};
template<> struct def<Windows::Devices::Gpio::IGpioChangeReader> : interface_type<Windows::Foundation::IClosable> {};
template<> struct def<Windows::Devices::Gpio::GpioChangeReader> : class_type<Platform::Object, Windows::Devices::Gpio::IGpioChangeReader>, custom_activators {};
template<> struct def<Windows::Devices::Gpio::IGpioChangeCounterFactory> : interface_type<> {};
template<> struct def<Windows::Devices::Gpio::IGpioChangeCounter> : interface_type<Windows::Foundation::IClosable> {};
template<> struct def<Windows::Devices::Gpio::GpioChangeCounter> : class_type<Platform::Object, Windows::Devices::Gpio::IGpioChangeCounter>, custom_activators {};

// uuids

template<> struct uuid<Windows::Devices::Gpio::IGpioPinValueChangedEventArgs> { define_guid(0x3137AAE1, 0x703D, 0x4059, 0xBD, 0x24, 0xB5, 0xB2, 0x5D, 0xFF, 0xB8, 0x4E);};
template<> struct uuid<Windows::Devices::Gpio::IGpioPin> { define_guid(0x11D9B087, 0xAFAE, 0x4790, 0x9E, 0xE9, 0xE0, 0xEA, 0xC9, 0x42, 0xD2, 0x1);};
template<> struct uuid<Windows::Devices::Gpio::IGpioController> { define_guid(0x284012E3, 0x7461, 0x469C, 0xA8, 0xBC, 0x61, 0xD6, 0x9D, 0x8, 0xA5, 0x3C);};
template<> struct uuid<Windows::Devices::Gpio::IGpioControllerStatics> { define_guid(0x2ED6F42E, 0x7AF7, 0x4116, 0x95, 0x33, 0xC4, 0x3D, 0x99, 0xA1, 0xFB, 0x64);};
template<> struct uuid<Windows::Devices::Gpio::IGpioControllerStatics2> { define_guid(0x912B7D20, 0x6CA4, 0x4106, 0xA3, 0x73, 0xFF, 0xFD, 0x34, 0x6B, 0xE, 0x5B);};
template<> struct uuid<Windows::Devices::Gpio::IGpioChangeReaderFactory> { define_guid(0xA9598EF3, 0x390E, 0x441A, 0x9D, 0x1C, 0xE8, 0xDE, 0xB, 0x2D, 0xF0, 0xDF);};
template<> struct uuid<Windows::Devices::Gpio::IGpioChangeReader> { define_guid(0xABC885F, 0xE031, 0x48E8, 0x85, 0x90, 0x70, 0xDE, 0x78, 0x36, 0x3C, 0x6D);};
template<> struct uuid<Windows::Devices::Gpio::IGpioChangeCounterFactory> { define_guid(0x147D94B6, 0xA9E, 0x410C, 0xB4, 0xFA, 0xF8, 0x9F, 0x40, 0x52, 0x8, 0x4D);};
template<> struct uuid<Windows::Devices::Gpio::IGpioChangeCounter> { define_guid(0xCB5EC0DE, 0x6801, 0x43FF, 0x80, 0x3D, 0x45, 0x76, 0x62, 0x8A, 0x8B, 0x26);};

// types

namespace Windows { namespace Devices { namespace Gpio {

// IGpioPinValueChangedEventArgs
struct IGpioPinValueChangedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Edge(GpioPinEdge *value);
};
template<typename X> struct IGpioPinValueChangedEventArgs_adaptor : X {
	union {
		struct : property {
			GpioPinEdge get() { GpioPinEdge value; hrcheck(enc(&IGpioPinValueChangedEventArgs_adaptor::Edge)->_get_Edge(&value)); return value; }
			GpioPinEdge operator()() { return get(); }
			operator GpioPinEdge () { return get(); }
		} Edge;
	};
	IGpioPinValueChangedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IGpioPinValueChangedEventArgs, X> : Windows::Devices::Gpio::IGpioPinValueChangedEventArgs_adaptor<X> { typedef adapt IGpioPinValueChangedEventArgs; };
struct IGpioPinValueChangedEventArgs : IGpioPinValueChangedEventArgs_raw, generate<IGpioPinValueChangedEventArgs> {};

// GpioPinValueChangedEventArgs
template<typename X> struct statics<GpioPinValueChangedEventArgs, X> : X {
	typedef typename X::root_type GpioPinValueChangedEventArgs;
};
struct GpioPinValueChangedEventArgs : generate<GpioPinValueChangedEventArgs> {};

// IGpioPin
struct IGpioPin_raw : IInspectable {
	virtual STDMETHODIMP _add_ValueChanged(Foundation::TypedEventHandler<GpioPin*, GpioPinValueChangedEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_ValueChanged(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _get_DebounceTimeout(Foundation::TimeSpan *value);
	virtual STDMETHODIMP _put_DebounceTimeout(Foundation::TimeSpan value);
	virtual STDMETHODIMP _get_PinNumber(int *value);
	virtual STDMETHODIMP _get_SharingMode(GpioSharingMode *value);
	virtual STDMETHODIMP _IsDriveModeSupported(GpioPinDriveMode driveMode, bool *supported);
	virtual STDMETHODIMP _GetDriveMode(GpioPinDriveMode *value);
	virtual STDMETHODIMP _SetDriveMode(GpioPinDriveMode value);
	virtual STDMETHODIMP _Write(GpioPinValue value);
	virtual STDMETHODIMP _Read(GpioPinValue *value);
};
template<typename X> struct IGpioPin_adaptor : X {
	union {
		struct : property {
			Foundation::TimeSpan get() { Foundation::TimeSpan value; hrcheck(enc(&IGpioPin_adaptor::DebounceTimeout)->_get_DebounceTimeout(&value)); return value; }
			Foundation::TimeSpan operator()() { return get(); }
			operator Foundation::TimeSpan () { return get(); }
			void put(const Foundation::TimeSpan& value) { hrcheck(enc(&IGpioPin_adaptor::DebounceTimeout)->_put_DebounceTimeout(value)); }
			void operator=(const Foundation::TimeSpan& value) { put(value); }
			void operator()(const Foundation::TimeSpan& value) { put(value); }
		} DebounceTimeout;
		struct : property {
			int get() { int value; hrcheck(enc(&IGpioPin_adaptor::PinNumber)->_get_PinNumber(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} PinNumber;
		struct : property {
			GpioSharingMode get() { GpioSharingMode value; hrcheck(enc(&IGpioPin_adaptor::SharingMode)->_get_SharingMode(&value)); return value; }
			GpioSharingMode operator()() { return get(); }
			operator GpioSharingMode () { return get(); }
		} SharingMode;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<GpioPin>, ptr<GpioPinValueChangedEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IGpioPin_adaptor::ValueChanged)->_add_ValueChanged(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IGpioPin_adaptor::ValueChanged)->_remove_ValueChanged(token)); }
		} ValueChanged;
	};
	bool IsDriveModeSupported(GpioPinDriveMode driveMode) { bool supported; hrcheck(X::get()->_IsDriveModeSupported(driveMode, &supported)); return supported; }
	GpioPinDriveMode GetDriveMode() { GpioPinDriveMode value; hrcheck(X::get()->_GetDriveMode(&value)); return value; }
	void SetDriveMode(GpioPinDriveMode value) { hrcheck(X::get()->_SetDriveMode(value)); }
	void Write(GpioPinValue value) { hrcheck(X::get()->_Write(value)); }
	GpioPinValue Read() { GpioPinValue value; hrcheck(X::get()->_Read(&value)); return value; }
	IGpioPin_adaptor() {}
};
template<typename X> struct adapt<IGpioPin, X> : Windows::Devices::Gpio::IGpioPin_adaptor<X> { typedef adapt IGpioPin; };
struct IGpioPin : IGpioPin_raw, generate<IGpioPin> {};

// GpioPin
template<typename X> struct statics<GpioPin, X> : X {
	typedef typename X::root_type GpioPin;
};
struct GpioPin : generate<GpioPin> {};

// IGpioController
struct IGpioController_raw : IInspectable {
	virtual STDMETHODIMP _get_PinCount(int *value);
	virtual STDMETHODIMP _OpenPin(int pinNumber, GpioPin* *pin);
	virtual STDMETHODIMP _OpenPinWithSharingMode(int pinNumber, GpioSharingMode sharingMode, GpioPin* *pin);
	virtual STDMETHODIMP _TryOpenPin(int pinNumber, GpioSharingMode sharingMode, GpioPin* *pin, GpioOpenStatus *openStatus, bool *succeeded);
};
template<typename X> struct IGpioController_adaptor : X {
	union {
		struct : property {
			int get() { int value; hrcheck(enc(&IGpioController_adaptor::PinCount)->_get_PinCount(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} PinCount;
	};
	ptr<GpioPin> OpenPin(int pinNumber) { GpioPin* pin; hrcheck(X::get()->_OpenPin(pinNumber, &pin)); return from_abi(pin); }
	ptr<GpioPin> OpenPin(int pinNumber, GpioSharingMode sharingMode) { GpioPin* pin; hrcheck(X::get()->_OpenPinWithSharingMode(pinNumber, sharingMode, &pin)); return from_abi(pin); }
	bool TryOpenPin(int pinNumber, GpioSharingMode sharingMode, pptr<GpioPin> *pin, GpioOpenStatus *openStatus) { bool succeeded; hrcheck(X::get()->_TryOpenPin(pinNumber, sharingMode, pin, openStatus, &succeeded)); return succeeded; }
	IGpioController_adaptor() {}
};
template<typename X> struct adapt<IGpioController, X> : Windows::Devices::Gpio::IGpioController_adaptor<X> { typedef adapt IGpioController; };
struct IGpioController : IGpioController_raw, generate<IGpioController> {};

// IGpioControllerStatics
struct IGpioControllerStatics : IInspectable {
	virtual STDMETHODIMP _GetDefault(GpioController* *value);
};

// IGpioControllerStatics2
struct IGpioControllerStatics2 : IInspectable {
	virtual STDMETHODIMP _GetControllersAsync(Provider::IGpioProvider* provider, Foundation::IAsyncOperation<Foundation::Collections::IVectorView<GpioController*>*>* *operation);
	virtual STDMETHODIMP _GetDefaultAsync(Foundation::IAsyncOperation<GpioController*>* *operation);
};

// GpioController
template<typename> struct GpioController_statics {
	static ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<GpioController>>>>> GetControllersAsync(pptr<Provider::IGpioProvider> provider) { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<GpioController*>*>* operation; hrcheck(get_activation_factory<GpioController, IGpioControllerStatics2>()->_GetControllersAsync(provider, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<ptr<GpioController>>> GetDefaultAsync() { Foundation::IAsyncOperation<GpioController*>* operation; hrcheck(get_activation_factory<GpioController, IGpioControllerStatics2>()->_GetDefaultAsync(&operation)); return from_abi(operation); }
	static ptr<GpioController> GetDefault() { GpioController* value; hrcheck(get_activation_factory<GpioController, IGpioControllerStatics>()->_GetDefault(&value)); return from_abi(value); }
};

template<typename X> struct statics<GpioController, X> : X, Windows::Devices::Gpio::GpioController_statics<void> {
	typedef typename X::root_type GpioController;
};
struct GpioController : generate<GpioController> {
	using IGpioController::OpenPin;
};

// IGpioChangeReaderFactory
struct IGpioChangeReaderFactory : IInspectable {
	virtual STDMETHODIMP _Create(GpioPin* pin, GpioChangeReader* *value);
	virtual STDMETHODIMP _CreateWithCapacity(GpioPin* pin, int minCapacity, GpioChangeReader* *value);
};

// IGpioChangeReader
struct IGpioChangeReader_raw : IInspectable {
	virtual STDMETHODIMP _get_Capacity(int *value);
	virtual STDMETHODIMP _get_Length(int *value);
	virtual STDMETHODIMP _get_IsEmpty(bool *value);
	virtual STDMETHODIMP _get_IsOverflowed(bool *value);
	virtual STDMETHODIMP _put_Polarity(GpioChangePolarity value);
	virtual STDMETHODIMP _get_Polarity(GpioChangePolarity *value);
	virtual STDMETHODIMP _get_IsStarted(bool *value);
	virtual STDMETHODIMP _Start();
	virtual STDMETHODIMP _Stop();
	virtual STDMETHODIMP _Clear();
	virtual STDMETHODIMP _GetNextItem(GpioChangeRecord *value);
	virtual STDMETHODIMP _PeekNextItem(GpioChangeRecord *value);
	virtual STDMETHODIMP _GetAllItems(Foundation::Collections::IVector<GpioChangeRecord>* *value);
	virtual STDMETHODIMP _WaitForItemsAsync(int count, Foundation::IAsyncAction* *operation);
};
template<typename X> struct IGpioChangeReader_adaptor : X {
	union {
		struct : property {
			int get() { int value; hrcheck(enc(&IGpioChangeReader_adaptor::Capacity)->_get_Capacity(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} Capacity;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IGpioChangeReader_adaptor::IsEmpty)->_get_IsEmpty(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsEmpty;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IGpioChangeReader_adaptor::IsOverflowed)->_get_IsOverflowed(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsOverflowed;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IGpioChangeReader_adaptor::IsStarted)->_get_IsStarted(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsStarted;
		struct : property {
			int get() { int value; hrcheck(enc(&IGpioChangeReader_adaptor::Length)->_get_Length(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} Length;
		struct : property {
			GpioChangePolarity get() { GpioChangePolarity value; hrcheck(enc(&IGpioChangeReader_adaptor::Polarity)->_get_Polarity(&value)); return value; }
			GpioChangePolarity operator()() { return get(); }
			operator GpioChangePolarity () { return get(); }
			void put(GpioChangePolarity value) { hrcheck(enc(&IGpioChangeReader_adaptor::Polarity)->_put_Polarity(value)); }
			void operator=(GpioChangePolarity value) { put(value); }
			void operator()(GpioChangePolarity value) { put(value); }
		} Polarity;
	};
	void Start() { hrcheck(X::get()->_Start()); }
	void Stop() { hrcheck(X::get()->_Stop()); }
	void Clear() { hrcheck(X::get()->_Clear()); }
	GpioChangeRecord GetNextItem() { GpioChangeRecord value; hrcheck(X::get()->_GetNextItem(&value)); return value; }
	GpioChangeRecord PeekNextItem() { GpioChangeRecord value; hrcheck(X::get()->_PeekNextItem(&value)); return value; }
	ptr<Foundation::Collections::IVector<GpioChangeRecord>> GetAllItems() { Foundation::Collections::IVector<GpioChangeRecord>* value; hrcheck(X::get()->_GetAllItems(&value)); return from_abi(value); }
	ptr<Foundation::IAsyncAction> WaitForItemsAsync(int count) { Foundation::IAsyncAction* operation; hrcheck(X::get()->_WaitForItemsAsync(count, &operation)); return from_abi(operation); }
	IGpioChangeReader_adaptor() {}
};
template<typename X> struct adapt<IGpioChangeReader, X> : Windows::Devices::Gpio::IGpioChangeReader_adaptor<X> { typedef adapt IGpioChangeReader; };
struct IGpioChangeReader : IGpioChangeReader_raw, generate<IGpioChangeReader> {};

// GpioChangeReader
template<typename> struct GpioChangeReader_statics {
	static GpioChangeReader *activate(pptr<GpioPin> pin) { GpioChangeReader *value; hrcheck(get_activation_factory<GpioChangeReader, IGpioChangeReaderFactory>()->_Create(pin, &value)); return value; }
	static GpioChangeReader *activate(pptr<GpioPin> pin, int minCapacity) { GpioChangeReader *value; hrcheck(get_activation_factory<GpioChangeReader, IGpioChangeReaderFactory>()->_CreateWithCapacity(pin, minCapacity, &value)); return value; }
};

template<typename X> struct statics<GpioChangeReader, X> : X, Windows::Devices::Gpio::GpioChangeReader_statics<void> {
	using Windows::Devices::Gpio::GpioChangeReader_statics<void>::activate;
	typedef typename X::root_type GpioChangeReader;
};
struct GpioChangeReader : generate<GpioChangeReader> {};

// IGpioChangeCounterFactory
struct IGpioChangeCounterFactory : IInspectable {
	virtual STDMETHODIMP _Create(GpioPin* pin, GpioChangeCounter* *value);
};

// IGpioChangeCounter
struct IGpioChangeCounter_raw : IInspectable {
	virtual STDMETHODIMP _put_Polarity(GpioChangePolarity value);
	virtual STDMETHODIMP _get_Polarity(GpioChangePolarity *value);
	virtual STDMETHODIMP _get_IsStarted(bool *value);
	virtual STDMETHODIMP _Start();
	virtual STDMETHODIMP _Stop();
	virtual STDMETHODIMP _Read(GpioChangeCount *value);
	virtual STDMETHODIMP _Reset(GpioChangeCount *value);
};
template<typename X> struct IGpioChangeCounter_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IGpioChangeCounter_adaptor::IsStarted)->_get_IsStarted(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsStarted;
		struct : property {
			GpioChangePolarity get() { GpioChangePolarity value; hrcheck(enc(&IGpioChangeCounter_adaptor::Polarity)->_get_Polarity(&value)); return value; }
			GpioChangePolarity operator()() { return get(); }
			operator GpioChangePolarity () { return get(); }
			void put(GpioChangePolarity value) { hrcheck(enc(&IGpioChangeCounter_adaptor::Polarity)->_put_Polarity(value)); }
			void operator=(GpioChangePolarity value) { put(value); }
			void operator()(GpioChangePolarity value) { put(value); }
		} Polarity;
	};
	void Start() { hrcheck(X::get()->_Start()); }
	void Stop() { hrcheck(X::get()->_Stop()); }
	GpioChangeCount Read() { GpioChangeCount value; hrcheck(X::get()->_Read(&value)); return value; }
	GpioChangeCount Reset() { GpioChangeCount value; hrcheck(X::get()->_Reset(&value)); return value; }
	IGpioChangeCounter_adaptor() {}
};
template<typename X> struct adapt<IGpioChangeCounter, X> : Windows::Devices::Gpio::IGpioChangeCounter_adaptor<X> { typedef adapt IGpioChangeCounter; };
struct IGpioChangeCounter : IGpioChangeCounter_raw, generate<IGpioChangeCounter> {};

// GpioChangeCounter
template<typename> struct GpioChangeCounter_statics {
	static GpioChangeCounter *activate(pptr<GpioPin> pin) { GpioChangeCounter *value; hrcheck(get_activation_factory<GpioChangeCounter, IGpioChangeCounterFactory>()->_Create(pin, &value)); return value; }
};

template<typename X> struct statics<GpioChangeCounter, X> : X, Windows::Devices::Gpio::GpioChangeCounter_statics<void> {
	using Windows::Devices::Gpio::GpioChangeCounter_statics<void>::activate;
	typedef typename X::root_type GpioChangeCounter;
};
struct GpioChangeCounter : generate<GpioChangeCounter> {};
}}}
} // namespace iso_winrt
