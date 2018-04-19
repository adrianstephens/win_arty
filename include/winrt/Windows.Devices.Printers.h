#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices.Printers

#include "Windows.Devices.Printers.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation {
template<typename TResult> struct IAsyncOperation;
}
namespace Storage { namespace Streams {
struct IRandomAccessStreamWithContentType;
}}}

// defs

template<> struct def<Windows::Devices::Printers::IPrint3DDeviceStatics> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::IPrint3DDevice> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::Print3DDevice> : class_type<Platform::Object, Windows::Devices::Printers::IPrint3DDevice> {};
template<> struct def<Windows::Devices::Printers::IPrintSchema> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::PrintSchema> : class_type<Platform::Object, Windows::Devices::Printers::IPrintSchema> {};
template<> struct def<Windows::Devices::Printers::PrintersContract> : value_type<> {};

// uuids

template<> struct uuid<Windows::Devices::Printers::IPrint3DDeviceStatics> { define_guid(0xFDE3620A, 0x67CD, 0x41B7, 0xA3, 0x44, 0x51, 0x50, 0xA1, 0xFD, 0x75, 0xB5);};
template<> struct uuid<Windows::Devices::Printers::IPrint3DDevice> { define_guid(0x41C3D19, 0x9713, 0x42A2, 0x98, 0x13, 0x7D, 0xC3, 0x33, 0x74, 0x28, 0xD3);};
template<> struct uuid<Windows::Devices::Printers::IPrintSchema> { define_guid(0xC2B98316, 0x26B8, 0x4BFB, 0x81, 0x38, 0x9F, 0x96, 0x2C, 0x22, 0xA3, 0x5B);};

// types

namespace Windows { namespace Devices { namespace Printers {

// IPrint3DDeviceStatics
struct IPrint3DDeviceStatics : IInspectable {
	virtual STDMETHODIMP _FromIdAsync(HSTRING deviceId, Foundation::IAsyncOperation<Print3DDevice*>* *operation);
	virtual STDMETHODIMP _GetDeviceSelector(HSTRING *result);
};

// IPrint3DDevice
struct IPrint3DDevice_raw : IInspectable {
	virtual STDMETHODIMP _get_PrintSchema(Printers::PrintSchema* *value);
};
template<typename X> struct IPrint3DDevice_adaptor : X {
	union {
		struct : property {
			ptr<Printers::PrintSchema> get() { Printers::PrintSchema* value; hrcheck(enc(&IPrint3DDevice_adaptor::PrintSchema)->_get_PrintSchema(&value)); return from_abi(value); }
			ptr<Printers::PrintSchema> operator()() { return get(); }
			operator ptr<Printers::PrintSchema> () { return get(); }
			ptr<Printers::PrintSchema> operator->() { return get(); }
		} PrintSchema;
	};
	IPrint3DDevice_adaptor() {}
};
template<typename X> struct adapt<IPrint3DDevice, X> : Windows::Devices::Printers::IPrint3DDevice_adaptor<X> { typedef adapt IPrint3DDevice; };
struct IPrint3DDevice : IPrint3DDevice_raw, generate<IPrint3DDevice> {};

// Print3DDevice
template<typename> struct Print3DDevice_statics {
	static ptr<Foundation::IAsyncOperation<ptr<Print3DDevice>>> FromIdAsync(hstring_ref deviceId) { Foundation::IAsyncOperation<Print3DDevice*>* operation; hrcheck(get_activation_factory<Print3DDevice, IPrint3DDeviceStatics>()->_FromIdAsync(deviceId, &operation)); return from_abi(operation); }
	static hstring GetDeviceSelector() { HSTRING result; hrcheck(get_activation_factory<Print3DDevice, IPrint3DDeviceStatics>()->_GetDeviceSelector(&result)); return from_abi(result); }
};

template<typename X> struct statics<Print3DDevice, X> : X, Windows::Devices::Printers::Print3DDevice_statics<void> {
	typedef typename X::root_type Print3DDevice;
};
struct Print3DDevice : generate<Print3DDevice> {};

// IPrintSchema
struct IPrintSchema_raw : IInspectable {
	virtual STDMETHODIMP _GetDefaultPrintTicketAsync(Foundation::IAsyncOperation<Storage::Streams::IRandomAccessStreamWithContentType*>* *operation);
	virtual STDMETHODIMP _GetCapabilitiesAsync(Storage::Streams::IRandomAccessStreamWithContentType* constrainTicket, Foundation::IAsyncOperation<Storage::Streams::IRandomAccessStreamWithContentType*>* *operation);
	virtual STDMETHODIMP _MergeAndValidateWithDefaultPrintTicketAsync(Storage::Streams::IRandomAccessStreamWithContentType* deltaTicket, Foundation::IAsyncOperation<Storage::Streams::IRandomAccessStreamWithContentType*>* *operation);
};
template<typename X> struct IPrintSchema_adaptor : X {
	ptr<Foundation::IAsyncOperation<ptr<Storage::Streams::IRandomAccessStreamWithContentType>>> GetDefaultPrintTicketAsync() { Foundation::IAsyncOperation<Storage::Streams::IRandomAccessStreamWithContentType*>* operation; hrcheck(X::get()->_GetDefaultPrintTicketAsync(&operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<Storage::Streams::IRandomAccessStreamWithContentType>>> GetCapabilitiesAsync(pptr<Storage::Streams::IRandomAccessStreamWithContentType> constrainTicket) { Foundation::IAsyncOperation<Storage::Streams::IRandomAccessStreamWithContentType*>* operation; hrcheck(X::get()->_GetCapabilitiesAsync(constrainTicket, &operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<Storage::Streams::IRandomAccessStreamWithContentType>>> MergeAndValidateWithDefaultPrintTicketAsync(pptr<Storage::Streams::IRandomAccessStreamWithContentType> deltaTicket) { Foundation::IAsyncOperation<Storage::Streams::IRandomAccessStreamWithContentType*>* operation; hrcheck(X::get()->_MergeAndValidateWithDefaultPrintTicketAsync(deltaTicket, &operation)); return from_abi(operation); }
};
template<typename X> struct adapt<IPrintSchema, X> : Windows::Devices::Printers::IPrintSchema_adaptor<X> { typedef adapt IPrintSchema; };
struct IPrintSchema : IPrintSchema_raw, generate<IPrintSchema> {};

// PrintSchema
template<typename X> struct statics<PrintSchema, X> : X {
	typedef typename X::root_type PrintSchema;
};
struct PrintSchema : generate<PrintSchema> {};
}}}
} // namespace iso_winrt
