#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices.SerialCommunication

#include "Windows.Devices.SerialCommunication.0.h"
#include "Windows.Foundation.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Storage { namespace Streams {
struct IInputStream;
struct IOutputStream;
}}}

// defs

template<> struct def<Windows::Devices::SerialCommunication::SerialParity> : enum_type<int> {};
template<> struct def<Windows::Devices::SerialCommunication::SerialHandshake> : enum_type<int> {};
template<> struct def<Windows::Devices::SerialCommunication::SerialStopBitCount> : enum_type<int> {};
template<> struct def<Windows::Devices::SerialCommunication::SerialError> : enum_type<int> {};
template<> struct def<Windows::Devices::SerialCommunication::SerialPinChange> : enum_type<int> {};
template<> struct def<Windows::Devices::SerialCommunication::ISerialDeviceStatics> : interface_type<> {};
template<> struct def<Windows::Devices::SerialCommunication::ISerialDevice> : interface_type<Windows::Foundation::IClosable> {};
template<> struct def<Windows::Devices::SerialCommunication::SerialDevice> : class_type<Platform::Object, Windows::Devices::SerialCommunication::ISerialDevice> {};
template<> struct def<Windows::Devices::SerialCommunication::IErrorReceivedEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::SerialCommunication::ErrorReceivedEventArgs> : class_type<Platform::Object, Windows::Devices::SerialCommunication::IErrorReceivedEventArgs> {};
template<> struct def<Windows::Devices::SerialCommunication::IPinChangedEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::SerialCommunication::PinChangedEventArgs> : class_type<Platform::Object, Windows::Devices::SerialCommunication::IPinChangedEventArgs> {};

// uuids

template<> struct uuid<Windows::Devices::SerialCommunication::ISerialDeviceStatics> { define_guid(0x58C4A70, 0x836, 0x4993, 0xAE, 0x1A, 0xB6, 0x1A, 0xE3, 0xBE, 0x5, 0x6B);};
template<> struct uuid<Windows::Devices::SerialCommunication::ISerialDevice> { define_guid(0xE187CCC6, 0x2210, 0x414F, 0xB6, 0x5A, 0xF5, 0x55, 0x3A, 0x3, 0x37, 0x2A);};
template<> struct uuid<Windows::Devices::SerialCommunication::IErrorReceivedEventArgs> { define_guid(0xFCC6BF59, 0x1283, 0x4D8A, 0xBF, 0xDF, 0x56, 0x6B, 0x33, 0xDD, 0xB2, 0x8F);};
template<> struct uuid<Windows::Devices::SerialCommunication::IPinChangedEventArgs> { define_guid(0xA2BF1DB0, 0xFC9C, 0x4607, 0x93, 0xD0, 0xFA, 0x5E, 0x83, 0x43, 0xEE, 0x22);};

// types

namespace Windows { namespace Devices { namespace SerialCommunication {

// ISerialDeviceStatics
struct ISerialDeviceStatics : IInspectable {
	virtual STDMETHODIMP _GetDeviceSelector(HSTRING *value);
	virtual STDMETHODIMP _GetDeviceSelectorFromPortName(HSTRING portName, HSTRING *result);
	virtual STDMETHODIMP _GetDeviceSelectorFromUsbVidPid(unsigned short vendorId, unsigned short productId, HSTRING *result);
	virtual STDMETHODIMP _FromIdAsync(HSTRING deviceId, Foundation::IAsyncOperation<SerialDevice*>* *result);
};

// ISerialDevice
struct ISerialDevice_raw : IInspectable {
	virtual STDMETHODIMP _get_BaudRate(unsigned *value);
	virtual STDMETHODIMP _put_BaudRate(unsigned value);
	virtual STDMETHODIMP _get_BreakSignalState(bool *value);
	virtual STDMETHODIMP _put_BreakSignalState(bool value);
	virtual STDMETHODIMP _get_BytesReceived(unsigned *value);
	virtual STDMETHODIMP _get_CarrierDetectState(bool *value);
	virtual STDMETHODIMP _get_ClearToSendState(bool *value);
	virtual STDMETHODIMP _get_DataBits(unsigned short *value);
	virtual STDMETHODIMP _put_DataBits(unsigned short value);
	virtual STDMETHODIMP _get_DataSetReadyState(bool *value);
	virtual STDMETHODIMP _get_Handshake(SerialHandshake *value);
	virtual STDMETHODIMP _put_Handshake(SerialHandshake value);
	virtual STDMETHODIMP _get_IsDataTerminalReadyEnabled(bool *value);
	virtual STDMETHODIMP _put_IsDataTerminalReadyEnabled(bool value);
	virtual STDMETHODIMP _get_IsRequestToSendEnabled(bool *value);
	virtual STDMETHODIMP _put_IsRequestToSendEnabled(bool value);
	virtual STDMETHODIMP _get_Parity(SerialParity *value);
	virtual STDMETHODIMP _put_Parity(SerialParity value);
	virtual STDMETHODIMP _get_PortName(HSTRING *value);
	virtual STDMETHODIMP _get_ReadTimeout(Foundation::TimeSpan *value);
	virtual STDMETHODIMP _put_ReadTimeout(Foundation::TimeSpan value);
	virtual STDMETHODIMP _get_StopBits(SerialStopBitCount *value);
	virtual STDMETHODIMP _put_StopBits(SerialStopBitCount value);
	virtual STDMETHODIMP _get_UsbVendorId(unsigned short *value);
	virtual STDMETHODIMP _get_UsbProductId(unsigned short *value);
	virtual STDMETHODIMP _get_WriteTimeout(Foundation::TimeSpan *value);
	virtual STDMETHODIMP _put_WriteTimeout(Foundation::TimeSpan value);
	virtual STDMETHODIMP _get_InputStream(Storage::Streams::IInputStream* *value);
	virtual STDMETHODIMP _get_OutputStream(Storage::Streams::IOutputStream* *value);
	virtual STDMETHODIMP _add_ErrorReceived(Foundation::TypedEventHandler<SerialDevice*, ErrorReceivedEventArgs*>* reportHandler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_ErrorReceived(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_PinChanged(Foundation::TypedEventHandler<SerialDevice*, PinChangedEventArgs*>* reportHandler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_PinChanged(Foundation::EventRegistrationToken token);
};
template<typename X> struct ISerialDevice_adaptor : X {
	union {
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&ISerialDevice_adaptor::BaudRate)->_get_BaudRate(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
			void put(unsigned value) { hrcheck(enc(&ISerialDevice_adaptor::BaudRate)->_put_BaudRate(value)); }
			void operator=(unsigned value) { put(value); }
			void operator()(unsigned value) { put(value); }
		} BaudRate;
		struct : property {
			bool get() { bool value; hrcheck(enc(&ISerialDevice_adaptor::BreakSignalState)->_get_BreakSignalState(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&ISerialDevice_adaptor::BreakSignalState)->_put_BreakSignalState(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} BreakSignalState;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&ISerialDevice_adaptor::BytesReceived)->_get_BytesReceived(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} BytesReceived;
		struct : property {
			bool get() { bool value; hrcheck(enc(&ISerialDevice_adaptor::CarrierDetectState)->_get_CarrierDetectState(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} CarrierDetectState;
		struct : property {
			bool get() { bool value; hrcheck(enc(&ISerialDevice_adaptor::ClearToSendState)->_get_ClearToSendState(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} ClearToSendState;
		struct : property {
			unsigned short get() { unsigned short value; hrcheck(enc(&ISerialDevice_adaptor::DataBits)->_get_DataBits(&value)); return value; }
			unsigned short operator()() { return get(); }
			operator unsigned short () { return get(); }
			void put(unsigned short value) { hrcheck(enc(&ISerialDevice_adaptor::DataBits)->_put_DataBits(value)); }
			void operator=(unsigned short value) { put(value); }
			void operator()(unsigned short value) { put(value); }
		} DataBits;
		struct : property {
			bool get() { bool value; hrcheck(enc(&ISerialDevice_adaptor::DataSetReadyState)->_get_DataSetReadyState(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} DataSetReadyState;
		struct : property {
			SerialHandshake get() { SerialHandshake value; hrcheck(enc(&ISerialDevice_adaptor::Handshake)->_get_Handshake(&value)); return value; }
			SerialHandshake operator()() { return get(); }
			operator SerialHandshake () { return get(); }
			void put(SerialHandshake value) { hrcheck(enc(&ISerialDevice_adaptor::Handshake)->_put_Handshake(value)); }
			void operator=(SerialHandshake value) { put(value); }
			void operator()(SerialHandshake value) { put(value); }
		} Handshake;
		struct : property {
			ptr<Storage::Streams::IInputStream> get() { Storage::Streams::IInputStream* value; hrcheck(enc(&ISerialDevice_adaptor::InputStream)->_get_InputStream(&value)); return from_abi(value); }
			ptr<Storage::Streams::IInputStream> operator()() { return get(); }
			operator ptr<Storage::Streams::IInputStream> () { return get(); }
			ptr<Storage::Streams::IInputStream> operator->() { return get(); }
		} InputStream;
		struct : property {
			bool get() { bool value; hrcheck(enc(&ISerialDevice_adaptor::IsDataTerminalReadyEnabled)->_get_IsDataTerminalReadyEnabled(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&ISerialDevice_adaptor::IsDataTerminalReadyEnabled)->_put_IsDataTerminalReadyEnabled(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} IsDataTerminalReadyEnabled;
		struct : property {
			bool get() { bool value; hrcheck(enc(&ISerialDevice_adaptor::IsRequestToSendEnabled)->_get_IsRequestToSendEnabled(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&ISerialDevice_adaptor::IsRequestToSendEnabled)->_put_IsRequestToSendEnabled(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} IsRequestToSendEnabled;
		struct : property {
			ptr<Storage::Streams::IOutputStream> get() { Storage::Streams::IOutputStream* value; hrcheck(enc(&ISerialDevice_adaptor::OutputStream)->_get_OutputStream(&value)); return from_abi(value); }
			ptr<Storage::Streams::IOutputStream> operator()() { return get(); }
			operator ptr<Storage::Streams::IOutputStream> () { return get(); }
			ptr<Storage::Streams::IOutputStream> operator->() { return get(); }
		} OutputStream;
		struct : property {
			SerialParity get() { SerialParity value; hrcheck(enc(&ISerialDevice_adaptor::Parity)->_get_Parity(&value)); return value; }
			SerialParity operator()() { return get(); }
			operator SerialParity () { return get(); }
			void put(SerialParity value) { hrcheck(enc(&ISerialDevice_adaptor::Parity)->_put_Parity(value)); }
			void operator=(SerialParity value) { put(value); }
			void operator()(SerialParity value) { put(value); }
		} Parity;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ISerialDevice_adaptor::PortName)->_get_PortName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} PortName;
		struct : property {
			Foundation::TimeSpan get() { Foundation::TimeSpan value; hrcheck(enc(&ISerialDevice_adaptor::ReadTimeout)->_get_ReadTimeout(&value)); return value; }
			Foundation::TimeSpan operator()() { return get(); }
			operator Foundation::TimeSpan () { return get(); }
			void put(const Foundation::TimeSpan& value) { hrcheck(enc(&ISerialDevice_adaptor::ReadTimeout)->_put_ReadTimeout(value)); }
			void operator=(const Foundation::TimeSpan& value) { put(value); }
			void operator()(const Foundation::TimeSpan& value) { put(value); }
		} ReadTimeout;
		struct : property {
			SerialStopBitCount get() { SerialStopBitCount value; hrcheck(enc(&ISerialDevice_adaptor::StopBits)->_get_StopBits(&value)); return value; }
			SerialStopBitCount operator()() { return get(); }
			operator SerialStopBitCount () { return get(); }
			void put(SerialStopBitCount value) { hrcheck(enc(&ISerialDevice_adaptor::StopBits)->_put_StopBits(value)); }
			void operator=(SerialStopBitCount value) { put(value); }
			void operator()(SerialStopBitCount value) { put(value); }
		} StopBits;
		struct : property {
			unsigned short get() { unsigned short value; hrcheck(enc(&ISerialDevice_adaptor::UsbProductId)->_get_UsbProductId(&value)); return value; }
			unsigned short operator()() { return get(); }
			operator unsigned short () { return get(); }
		} UsbProductId;
		struct : property {
			unsigned short get() { unsigned short value; hrcheck(enc(&ISerialDevice_adaptor::UsbVendorId)->_get_UsbVendorId(&value)); return value; }
			unsigned short operator()() { return get(); }
			operator unsigned short () { return get(); }
		} UsbVendorId;
		struct : property {
			Foundation::TimeSpan get() { Foundation::TimeSpan value; hrcheck(enc(&ISerialDevice_adaptor::WriteTimeout)->_get_WriteTimeout(&value)); return value; }
			Foundation::TimeSpan operator()() { return get(); }
			operator Foundation::TimeSpan () { return get(); }
			void put(const Foundation::TimeSpan& value) { hrcheck(enc(&ISerialDevice_adaptor::WriteTimeout)->_put_WriteTimeout(value)); }
			void operator=(const Foundation::TimeSpan& value) { put(value); }
			void operator()(const Foundation::TimeSpan& value) { put(value); }
		} WriteTimeout;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<SerialDevice>, ptr<ErrorReceivedEventArgs>>> reportHandler) { Foundation::EventRegistrationToken token; hrcheck(enc(&ISerialDevice_adaptor::ErrorReceived)->_add_ErrorReceived(to_abi(reportHandler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&ISerialDevice_adaptor::ErrorReceived)->_remove_ErrorReceived(token)); }
		} ErrorReceived;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<SerialDevice>, ptr<PinChangedEventArgs>>> reportHandler) { Foundation::EventRegistrationToken token; hrcheck(enc(&ISerialDevice_adaptor::PinChanged)->_add_PinChanged(to_abi(reportHandler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&ISerialDevice_adaptor::PinChanged)->_remove_PinChanged(token)); }
		} PinChanged;
	};
	ISerialDevice_adaptor() {}
};
template<typename X> struct adapt<ISerialDevice, X> : Windows::Devices::SerialCommunication::ISerialDevice_adaptor<X> { typedef adapt ISerialDevice; };
struct ISerialDevice : ISerialDevice_raw, generate<ISerialDevice> {};

// SerialDevice
template<typename> struct SerialDevice_statics {
	static hstring GetDeviceSelector() { HSTRING value; hrcheck(get_activation_factory<SerialDevice, ISerialDeviceStatics>()->_GetDeviceSelector(&value)); return from_abi(value); }
	static hstring GetDeviceSelector(hstring_ref portName) { HSTRING result; hrcheck(get_activation_factory<SerialDevice, ISerialDeviceStatics>()->_GetDeviceSelectorFromPortName(portName, &result)); return from_abi(result); }
	static hstring GetDeviceSelectorFromUsbVidPid(unsigned short vendorId, unsigned short productId) { HSTRING result; hrcheck(get_activation_factory<SerialDevice, ISerialDeviceStatics>()->_GetDeviceSelectorFromUsbVidPid(vendorId, productId, &result)); return from_abi(result); }
	static ptr<Foundation::IAsyncOperation<ptr<SerialDevice>>> FromIdAsync(hstring_ref deviceId) { Foundation::IAsyncOperation<SerialDevice*>* result; hrcheck(get_activation_factory<SerialDevice, ISerialDeviceStatics>()->_FromIdAsync(deviceId, &result)); return from_abi(result); }
};

template<typename X> struct statics<SerialDevice, X> : X, Windows::Devices::SerialCommunication::SerialDevice_statics<void> {
	typedef typename X::root_type SerialDevice;
};
struct SerialDevice : generate<SerialDevice> {};

// IErrorReceivedEventArgs
struct IErrorReceivedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Error(SerialError *value);
};
template<typename X> struct IErrorReceivedEventArgs_adaptor : X {
	union {
		struct : property {
			SerialError get() { SerialError value; hrcheck(enc(&IErrorReceivedEventArgs_adaptor::Error)->_get_Error(&value)); return value; }
			SerialError operator()() { return get(); }
			operator SerialError () { return get(); }
		} Error;
	};
	IErrorReceivedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IErrorReceivedEventArgs, X> : Windows::Devices::SerialCommunication::IErrorReceivedEventArgs_adaptor<X> { typedef adapt IErrorReceivedEventArgs; };
struct IErrorReceivedEventArgs : IErrorReceivedEventArgs_raw, generate<IErrorReceivedEventArgs> {};

// ErrorReceivedEventArgs
template<typename X> struct statics<ErrorReceivedEventArgs, X> : X {
	typedef typename X::root_type ErrorReceivedEventArgs;
};
struct ErrorReceivedEventArgs : generate<ErrorReceivedEventArgs> {};

// IPinChangedEventArgs
struct IPinChangedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_PinChange(SerialPinChange *value);
};
template<typename X> struct IPinChangedEventArgs_adaptor : X {
	union {
		struct : property {
			SerialPinChange get() { SerialPinChange value; hrcheck(enc(&IPinChangedEventArgs_adaptor::PinChange)->_get_PinChange(&value)); return value; }
			SerialPinChange operator()() { return get(); }
			operator SerialPinChange () { return get(); }
		} PinChange;
	};
	IPinChangedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IPinChangedEventArgs, X> : Windows::Devices::SerialCommunication::IPinChangedEventArgs_adaptor<X> { typedef adapt IPinChangedEventArgs; };
struct IPinChangedEventArgs : IPinChangedEventArgs_raw, generate<IPinChangedEventArgs> {};

// PinChangedEventArgs
template<typename X> struct statics<PinChangedEventArgs, X> : X {
	typedef typename X::root_type PinChangedEventArgs;
};
struct PinChangedEventArgs : generate<PinChangedEventArgs> {};
}}}
} // namespace iso_winrt
