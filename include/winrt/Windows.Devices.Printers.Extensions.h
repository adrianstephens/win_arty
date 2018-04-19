#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices.Printers.Extensions

#include "Windows.Devices.Printers.Extensions.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Devices::Printers::Extensions::ExtensionsContract> : value_type<> {};
template<> struct def<Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedDeferral> : class_type<Platform::Object, Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral> {};
template<> struct def<Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequest> : class_type<Platform::Object, Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest> {};
template<> struct def<Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs> : class_type<Platform::Object, Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs> {};
template<> struct def<Windows::Devices::Printers::Extensions::IPrintTaskConfiguration> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::Extensions::PrintTaskConfiguration> : class_type<Platform::Object, Windows::Devices::Printers::Extensions::IPrintTaskConfiguration> {};
template<> struct def<Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::Extensions::PrintNotificationEventDetails> : class_type<Platform::Object, Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails> {};
template<> struct def<Windows::Devices::Printers::Extensions::IPrintExtensionContextStatic> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::Extensions::PrintExtensionContext> : class_type<Platform::Object, Platform::Object> {};
template<> struct def<Windows::Devices::Printers::Extensions::Print3DWorkflowStatus> : enum_type<int> {};
template<> struct def<Windows::Devices::Printers::Extensions::Print3DWorkflowDetail> : enum_type<int> {};
template<> struct def<Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs> : class_type<Platform::Object, Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs> {};
template<> struct def<Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs> : class_type<Platform::Object, Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs> {};
template<> struct def<Windows::Devices::Printers::Extensions::IPrint3DWorkflow> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::Extensions::IPrint3DWorkflow2> : interface_type<> {};
template<> struct def<Windows::Devices::Printers::Extensions::Print3DWorkflow> : class_type<Platform::Object, Windows::Devices::Printers::Extensions::IPrint3DWorkflow, Windows::Devices::Printers::Extensions::IPrint3DWorkflow2> {};

// uuids

template<> struct uuid<Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral> { define_guid(0xE959D568, 0xF729, 0x44A4, 0x87, 0x1D, 0xBD, 0x6, 0x28, 0x69, 0x6A, 0x33);};
template<> struct uuid<Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest> { define_guid(0xEEAF2FCB, 0x621E, 0x4B62, 0xAC, 0x77, 0xB2, 0x81, 0xCC, 0xE0, 0x8D, 0x60);};
template<> struct uuid<Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs> { define_guid(0xE06C2879, 0xD61, 0x4938, 0x91, 0xD0, 0x96, 0xA4, 0x5B, 0xEE, 0x84, 0x79);};
template<> struct uuid<Windows::Devices::Printers::Extensions::IPrintTaskConfiguration> { define_guid(0xE3C22451, 0x3AA4, 0x4885, 0x92, 0x40, 0x31, 0x1F, 0x5F, 0x8F, 0xBE, 0x9D);};
template<> struct uuid<Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails> { define_guid(0xE00E4C8A, 0x4828, 0x4DA1, 0x8B, 0xB8, 0x86, 0x72, 0xDF, 0x85, 0x15, 0xE7);};
template<> struct uuid<Windows::Devices::Printers::Extensions::IPrintExtensionContextStatic> { define_guid(0xE70D9FC1, 0xFF79, 0x4AA4, 0x8C, 0x9B, 0xC, 0x93, 0xAE, 0xDF, 0xDE, 0x8A);};
template<> struct uuid<Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs> { define_guid(0x19F8C858, 0x5AC8, 0x4B55, 0x8A, 0x5F, 0xE6, 0x15, 0x67, 0xDA, 0xFB, 0x4D);};
template<> struct uuid<Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs> { define_guid(0x45226402, 0x95FC, 0x4847, 0x93, 0xB3, 0x13, 0x4D, 0xBF, 0x5C, 0x60, 0xF7);};
template<> struct uuid<Windows::Devices::Printers::Extensions::IPrint3DWorkflow> { define_guid(0xC56F74BD, 0x3669, 0x4A66, 0xAB, 0x42, 0xC8, 0x15, 0x19, 0x30, 0xCD, 0x34);};
template<> struct uuid<Windows::Devices::Printers::Extensions::IPrint3DWorkflow2> { define_guid(0xA2A6C54F, 0x8AC1, 0x4918, 0x97, 0x41, 0xE3, 0x4F, 0x30, 0x4, 0x23, 0x9E);};

// types

namespace Windows { namespace Devices { namespace Printers { namespace Extensions {

// IPrintTaskConfigurationSaveRequestedDeferral
struct IPrintTaskConfigurationSaveRequestedDeferral_raw : IInspectable {
	virtual STDMETHODIMP _Complete();
};
template<typename X> struct IPrintTaskConfigurationSaveRequestedDeferral_adaptor : X {
	void Complete() { hrcheck(X::get()->_Complete()); }
};
template<typename X> struct adapt<IPrintTaskConfigurationSaveRequestedDeferral, X> : Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral_adaptor<X> { typedef adapt IPrintTaskConfigurationSaveRequestedDeferral; };
struct IPrintTaskConfigurationSaveRequestedDeferral : IPrintTaskConfigurationSaveRequestedDeferral_raw, generate<IPrintTaskConfigurationSaveRequestedDeferral> {};

// PrintTaskConfigurationSaveRequestedDeferral
template<typename X> struct statics<PrintTaskConfigurationSaveRequestedDeferral, X> : X {
	typedef typename X::root_type PrintTaskConfigurationSaveRequestedDeferral;
};
struct PrintTaskConfigurationSaveRequestedDeferral : generate<PrintTaskConfigurationSaveRequestedDeferral> {};

// IPrintTaskConfigurationSaveRequest
struct IPrintTaskConfigurationSaveRequest_raw : IInspectable {
	virtual STDMETHODIMP _Cancel();
	virtual STDMETHODIMP _Save(IInspectable* printerExtensionContext);
	virtual STDMETHODIMP _GetDeferral(PrintTaskConfigurationSaveRequestedDeferral* *deferral);
	virtual STDMETHODIMP _get_Deadline(Foundation::DateTime *value);
};
template<typename X> struct IPrintTaskConfigurationSaveRequest_adaptor : X {
	union {
		struct : property {
			Foundation::DateTime get() { Foundation::DateTime value; hrcheck(enc(&IPrintTaskConfigurationSaveRequest_adaptor::Deadline)->_get_Deadline(&value)); return value; }
			Foundation::DateTime operator()() { return get(); }
			operator Foundation::DateTime () { return get(); }
		} Deadline;
	};
	void Cancel() { hrcheck(X::get()->_Cancel()); }
	void Save(object_ref printerExtensionContext) { hrcheck(X::get()->_Save(printerExtensionContext)); }
	ptr<PrintTaskConfigurationSaveRequestedDeferral> GetDeferral() { PrintTaskConfigurationSaveRequestedDeferral* deferral; hrcheck(X::get()->_GetDeferral(&deferral)); return from_abi(deferral); }
	IPrintTaskConfigurationSaveRequest_adaptor() {}
};
template<typename X> struct adapt<IPrintTaskConfigurationSaveRequest, X> : Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest_adaptor<X> { typedef adapt IPrintTaskConfigurationSaveRequest; };
struct IPrintTaskConfigurationSaveRequest : IPrintTaskConfigurationSaveRequest_raw, generate<IPrintTaskConfigurationSaveRequest> {};

// PrintTaskConfigurationSaveRequest
template<typename X> struct statics<PrintTaskConfigurationSaveRequest, X> : X {
	typedef typename X::root_type PrintTaskConfigurationSaveRequest;
};
struct PrintTaskConfigurationSaveRequest : generate<PrintTaskConfigurationSaveRequest> {};

// IPrintTaskConfigurationSaveRequestedEventArgs
struct IPrintTaskConfigurationSaveRequestedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Request(PrintTaskConfigurationSaveRequest* *context);
};
template<typename X> struct IPrintTaskConfigurationSaveRequestedEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<PrintTaskConfigurationSaveRequest> get() { PrintTaskConfigurationSaveRequest* context; hrcheck(enc(&IPrintTaskConfigurationSaveRequestedEventArgs_adaptor::Request)->_get_Request(&context)); return from_abi(context); }
			ptr<PrintTaskConfigurationSaveRequest> operator()() { return get(); }
			operator ptr<PrintTaskConfigurationSaveRequest> () { return get(); }
			ptr<PrintTaskConfigurationSaveRequest> operator->() { return get(); }
		} Request;
	};
	IPrintTaskConfigurationSaveRequestedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IPrintTaskConfigurationSaveRequestedEventArgs, X> : Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs_adaptor<X> { typedef adapt IPrintTaskConfigurationSaveRequestedEventArgs; };
struct IPrintTaskConfigurationSaveRequestedEventArgs : IPrintTaskConfigurationSaveRequestedEventArgs_raw, generate<IPrintTaskConfigurationSaveRequestedEventArgs> {};

// PrintTaskConfigurationSaveRequestedEventArgs
template<typename X> struct statics<PrintTaskConfigurationSaveRequestedEventArgs, X> : X {
	typedef typename X::root_type PrintTaskConfigurationSaveRequestedEventArgs;
};
struct PrintTaskConfigurationSaveRequestedEventArgs : generate<PrintTaskConfigurationSaveRequestedEventArgs> {};

// IPrintTaskConfiguration
struct IPrintTaskConfiguration_raw : IInspectable {
	virtual STDMETHODIMP _get_PrinterExtensionContext(IInspectable* *context);
	virtual STDMETHODIMP _add_SaveRequested(Foundation::TypedEventHandler<PrintTaskConfiguration*, PrintTaskConfigurationSaveRequestedEventArgs*>* eventHandler, Foundation::EventRegistrationToken *eventCookie);
	virtual STDMETHODIMP _remove_SaveRequested(Foundation::EventRegistrationToken eventCookie);
};
template<typename X> struct IPrintTaskConfiguration_adaptor : X {
	union {
		struct : property {
			object get() { IInspectable* context; hrcheck(enc(&IPrintTaskConfiguration_adaptor::PrinterExtensionContext)->_get_PrinterExtensionContext(&context)); return from_abi(context); }
			object operator()() { return get(); }
			operator object () { return get(); }
		} PrinterExtensionContext;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<PrintTaskConfiguration>, ptr<PrintTaskConfigurationSaveRequestedEventArgs>>> eventHandler) { Foundation::EventRegistrationToken eventCookie; hrcheck(enc(&IPrintTaskConfiguration_adaptor::SaveRequested)->_add_SaveRequested(to_abi(eventHandler), &eventCookie)); return eventCookie; }
			void operator-=(const Foundation::EventRegistrationToken& eventCookie) { hrcheck(enc(&IPrintTaskConfiguration_adaptor::SaveRequested)->_remove_SaveRequested(eventCookie)); }
		} SaveRequested;
	};
	IPrintTaskConfiguration_adaptor() {}
};
template<typename X> struct adapt<IPrintTaskConfiguration, X> : Windows::Devices::Printers::Extensions::IPrintTaskConfiguration_adaptor<X> { typedef adapt IPrintTaskConfiguration; };
struct IPrintTaskConfiguration : IPrintTaskConfiguration_raw, generate<IPrintTaskConfiguration> {};

// PrintTaskConfiguration
template<typename X> struct statics<PrintTaskConfiguration, X> : X {
	typedef typename X::root_type PrintTaskConfiguration;
};
struct PrintTaskConfiguration : generate<PrintTaskConfiguration> {};

// IPrintNotificationEventDetails
struct IPrintNotificationEventDetails_raw : IInspectable {
	virtual STDMETHODIMP _get_PrinterName(HSTRING *value);
	virtual STDMETHODIMP _get_EventData(HSTRING *value);
	virtual STDMETHODIMP _put_EventData(HSTRING value);
};
template<typename X> struct IPrintNotificationEventDetails_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IPrintNotificationEventDetails_adaptor::EventData)->_get_EventData(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IPrintNotificationEventDetails_adaptor::EventData)->_put_EventData(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} EventData;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IPrintNotificationEventDetails_adaptor::PrinterName)->_get_PrinterName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} PrinterName;
	};
	IPrintNotificationEventDetails_adaptor() {}
};
template<typename X> struct adapt<IPrintNotificationEventDetails, X> : Windows::Devices::Printers::Extensions::IPrintNotificationEventDetails_adaptor<X> { typedef adapt IPrintNotificationEventDetails; };
struct IPrintNotificationEventDetails : IPrintNotificationEventDetails_raw, generate<IPrintNotificationEventDetails> {};

// PrintNotificationEventDetails
template<typename X> struct statics<PrintNotificationEventDetails, X> : X {
	typedef typename X::root_type PrintNotificationEventDetails;
};
struct PrintNotificationEventDetails : generate<PrintNotificationEventDetails> {};

// IPrintExtensionContextStatic
struct IPrintExtensionContextStatic : IInspectable {
	virtual STDMETHODIMP _FromDeviceId(HSTRING deviceId, IInspectable* *context);
};

// PrintExtensionContext
template<typename> struct PrintExtensionContext_statics {
	static object FromDeviceId(hstring_ref deviceId) { IInspectable* context; hrcheck(get_activation_factory<PrintExtensionContext, IPrintExtensionContextStatic>()->_FromDeviceId(deviceId, &context)); return from_abi(context); }
};

template<typename X> struct statics<PrintExtensionContext, X> : X, Windows::Devices::Printers::Extensions::PrintExtensionContext_statics<void> {
	typedef typename X::root_type PrintExtensionContext;
};
struct PrintExtensionContext : generate<PrintExtensionContext> {};

// IPrint3DWorkflowPrintRequestedEventArgs
struct IPrint3DWorkflowPrintRequestedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Status(Print3DWorkflowStatus *value);
	virtual STDMETHODIMP _SetExtendedStatus(Print3DWorkflowDetail value);
	virtual STDMETHODIMP _SetSource(IInspectable* source);
	virtual STDMETHODIMP _SetSourceChanged(bool value);
};
template<typename X> struct IPrint3DWorkflowPrintRequestedEventArgs_adaptor : X {
	union {
		struct : property {
			Print3DWorkflowStatus get() { Print3DWorkflowStatus value; hrcheck(enc(&IPrint3DWorkflowPrintRequestedEventArgs_adaptor::Status)->_get_Status(&value)); return value; }
			Print3DWorkflowStatus operator()() { return get(); }
			operator Print3DWorkflowStatus () { return get(); }
		} Status;
	};
	void SetExtendedStatus(Print3DWorkflowDetail value) { hrcheck(X::get()->_SetExtendedStatus(value)); }
	void SetSource(object_ref source) { hrcheck(X::get()->_SetSource(source)); }
	void SetSourceChanged(bool value) { hrcheck(X::get()->_SetSourceChanged(value)); }
	IPrint3DWorkflowPrintRequestedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IPrint3DWorkflowPrintRequestedEventArgs, X> : Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs_adaptor<X> { typedef adapt IPrint3DWorkflowPrintRequestedEventArgs; };
struct IPrint3DWorkflowPrintRequestedEventArgs : IPrint3DWorkflowPrintRequestedEventArgs_raw, generate<IPrint3DWorkflowPrintRequestedEventArgs> {};

// IPrint3DWorkflowPrinterChangedEventArgs
struct IPrint3DWorkflowPrinterChangedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_NewDeviceId(HSTRING *value);
};
template<typename X> struct IPrint3DWorkflowPrinterChangedEventArgs_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IPrint3DWorkflowPrinterChangedEventArgs_adaptor::NewDeviceId)->_get_NewDeviceId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} NewDeviceId;
	};
	IPrint3DWorkflowPrinterChangedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IPrint3DWorkflowPrinterChangedEventArgs, X> : Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs_adaptor<X> { typedef adapt IPrint3DWorkflowPrinterChangedEventArgs; };
struct IPrint3DWorkflowPrinterChangedEventArgs : IPrint3DWorkflowPrinterChangedEventArgs_raw, generate<IPrint3DWorkflowPrinterChangedEventArgs> {};

// Print3DWorkflowPrintRequestedEventArgs
template<typename X> struct statics<Print3DWorkflowPrintRequestedEventArgs, X> : X {
	typedef typename X::root_type Print3DWorkflowPrintRequestedEventArgs;
};
struct Print3DWorkflowPrintRequestedEventArgs : generate<Print3DWorkflowPrintRequestedEventArgs> {};

// Print3DWorkflowPrinterChangedEventArgs
template<typename X> struct statics<Print3DWorkflowPrinterChangedEventArgs, X> : X {
	typedef typename X::root_type Print3DWorkflowPrinterChangedEventArgs;
};
struct Print3DWorkflowPrinterChangedEventArgs : generate<Print3DWorkflowPrinterChangedEventArgs> {};

// IPrint3DWorkflow
struct IPrint3DWorkflow_raw : IInspectable {
	virtual STDMETHODIMP _get_DeviceID(HSTRING *value);
	virtual STDMETHODIMP _GetPrintModelPackage(IInspectable* *printModelPackage);
	virtual STDMETHODIMP _get_IsPrintReady(bool *value);
	virtual STDMETHODIMP _put_IsPrintReady(bool value);
	virtual STDMETHODIMP _add_PrintRequested(Foundation::TypedEventHandler<Print3DWorkflow*, Print3DWorkflowPrintRequestedEventArgs*>* eventHandler, Foundation::EventRegistrationToken *eventCookie);
	virtual STDMETHODIMP _remove_PrintRequested(Foundation::EventRegistrationToken eventCookie);
};
template<typename X> struct IPrint3DWorkflow_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IPrint3DWorkflow_adaptor::DeviceID)->_get_DeviceID(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DeviceID;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IPrint3DWorkflow_adaptor::IsPrintReady)->_get_IsPrintReady(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IPrint3DWorkflow_adaptor::IsPrintReady)->_put_IsPrintReady(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} IsPrintReady;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<Print3DWorkflow>, ptr<Print3DWorkflowPrintRequestedEventArgs>>> eventHandler) { Foundation::EventRegistrationToken eventCookie; hrcheck(enc(&IPrint3DWorkflow_adaptor::PrintRequested)->_add_PrintRequested(to_abi(eventHandler), &eventCookie)); return eventCookie; }
			void operator-=(const Foundation::EventRegistrationToken& eventCookie) { hrcheck(enc(&IPrint3DWorkflow_adaptor::PrintRequested)->_remove_PrintRequested(eventCookie)); }
		} PrintRequested;
	};
	object GetPrintModelPackage() { IInspectable* printModelPackage; hrcheck(X::get()->_GetPrintModelPackage(&printModelPackage)); return from_abi(printModelPackage); }
	IPrint3DWorkflow_adaptor() {}
};
template<typename X> struct adapt<IPrint3DWorkflow, X> : Windows::Devices::Printers::Extensions::IPrint3DWorkflow_adaptor<X> { typedef adapt IPrint3DWorkflow; };
struct IPrint3DWorkflow : IPrint3DWorkflow_raw, generate<IPrint3DWorkflow> {};

// IPrint3DWorkflow2
struct IPrint3DWorkflow2_raw : IInspectable {
	virtual STDMETHODIMP _add_PrinterChanged(Foundation::TypedEventHandler<Print3DWorkflow*, Print3DWorkflowPrinterChangedEventArgs*>* eventHandler, Foundation::EventRegistrationToken *eventCookie);
	virtual STDMETHODIMP _remove_PrinterChanged(Foundation::EventRegistrationToken eventCookie);
};
template<typename X> struct IPrint3DWorkflow2_adaptor : X {
	union {
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<Print3DWorkflow>, ptr<Print3DWorkflowPrinterChangedEventArgs>>> eventHandler) { Foundation::EventRegistrationToken eventCookie; hrcheck(enc(&IPrint3DWorkflow2_adaptor::PrinterChanged)->_add_PrinterChanged(to_abi(eventHandler), &eventCookie)); return eventCookie; }
			void operator-=(const Foundation::EventRegistrationToken& eventCookie) { hrcheck(enc(&IPrint3DWorkflow2_adaptor::PrinterChanged)->_remove_PrinterChanged(eventCookie)); }
		} PrinterChanged;
	};
	IPrint3DWorkflow2_adaptor() {}
};
template<typename X> struct adapt<IPrint3DWorkflow2, X> : Windows::Devices::Printers::Extensions::IPrint3DWorkflow2_adaptor<X> { typedef adapt IPrint3DWorkflow2; };
struct IPrint3DWorkflow2 : IPrint3DWorkflow2_raw, generate<IPrint3DWorkflow2> {};

// Print3DWorkflow
template<typename X> struct statics<Print3DWorkflow, X> : X {
	typedef typename X::root_type Print3DWorkflow;
};
struct Print3DWorkflow : generate<Print3DWorkflow> {};
}}}}
} // namespace iso_winrt