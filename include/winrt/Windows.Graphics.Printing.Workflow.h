#pragma once
// generated by isopod tools
// namespaces:
// Windows.Graphics.Printing.Workflow

#include "Windows.Graphics.Printing.Workflow.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.ApplicationModel.Activation.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Graphics { namespace Printing { namespace PrintTicket {
struct WorkflowPrintTicket;
}}}
namespace Storage { namespace Streams {
struct IInputStream;
struct IOutputStream;
}}
namespace System {
struct User;
}}

// defs

template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowSessionStatus> : enum_type<int> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowSubmittedStatus> : enum_type<int> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSession> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowBackgroundSession> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSession> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSetupRequestedEventArgs> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowBackgroundSetupRequestedEventArgs> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSetupRequestedEventArgs> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedEventArgs> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowSubmittedEventArgs> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedEventArgs> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSession> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowForegroundSession> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSession> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSetupRequestedEventArgs> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowForegroundSetupRequestedEventArgs> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSetupRequestedEventArgs> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowXpsDataAvailableEventArgs> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowXpsDataAvailableEventArgs> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowXpsDataAvailableEventArgs> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowConfiguration> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedOperation> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowSourceContent> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowSourceContent> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowSourceContent> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowSubmittedOperation> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedOperation> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowTarget> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowTarget> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowTarget> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowStreamTarget> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowStreamTarget> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowStreamTarget> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelTargetPackage> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowObjectModelTargetPackage> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelTargetPackage> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowUIActivatedEventArgs> : interface_type<Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowSpoolStreamContent> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowSpoolStreamContent> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowSpoolStreamContent> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelSourceFileContent> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowObjectModelSourceFileContent> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelSourceFileContent> {};
template<> struct def<Windows::Graphics::Printing::Workflow::IPrintWorkflowTriggerDetails> : interface_type<> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowUIActivatedEventArgs> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowUIActivatedEventArgs> {};
template<> struct def<Windows::Graphics::Printing::Workflow::PrintWorkflowTriggerDetails> : class_type<Platform::Object, Windows::Graphics::Printing::Workflow::IPrintWorkflowTriggerDetails> {};

// uuids

template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSession> { define_guid(0x5B7913BA, 0xC5E, 0x528A, 0x74, 0x58, 0x86, 0xA4, 0x6C, 0xBD, 0xDC, 0x45);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSetupRequestedEventArgs> { define_guid(0x43E97342, 0x1750, 0x59C9, 0x61, 0xFB, 0x38, 0x37, 0x48, 0xA2, 0x3, 0x62);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedEventArgs> { define_guid(0x3ADD0A41, 0x3794, 0x5569, 0x5C, 0x87, 0x40, 0xE8, 0xFF, 0x72, 0xF, 0x83);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration> { define_guid(0xD0AAC4ED, 0xFD4B, 0x5DF5, 0x4B, 0xB6, 0x8D, 0xD, 0x15, 0x9E, 0xBE, 0x3F);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSession> { define_guid(0xC79B63D0, 0xF8EC, 0x4CEB, 0x95, 0x3A, 0xC8, 0x87, 0x61, 0x57, 0xDD, 0x33);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSetupRequestedEventArgs> { define_guid(0xBBE38247, 0x9C1B, 0x4DD3, 0x9B, 0x2B, 0xC8, 0x4, 0x68, 0xD9, 0x41, 0xB3);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowXpsDataAvailableEventArgs> { define_guid(0x4D11C331, 0x54D1, 0x434E, 0xBE, 0xE, 0x82, 0xC5, 0xFA, 0x58, 0xE5, 0xB2);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedOperation> { define_guid(0x2E4E6216, 0x3BE1, 0x5F0F, 0x5C, 0x81, 0xA5, 0xA2, 0xBD, 0x4E, 0xAB, 0xE);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowSourceContent> { define_guid(0x1A28C641, 0xCEB1, 0x4533, 0xBB, 0x73, 0xFB, 0xE6, 0x3E, 0xEF, 0xDB, 0x18);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowTarget> { define_guid(0x29DA276C, 0xA73, 0x5AED, 0x4F, 0x3D, 0x97, 0xD, 0x32, 0x51, 0xF0, 0x57);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowStreamTarget> { define_guid(0xB23BBA84, 0x8565, 0x488B, 0x98, 0x39, 0x1C, 0x9E, 0x7C, 0x7A, 0xA9, 0x16);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelTargetPackage> { define_guid(0x7D96BC74, 0x9B54, 0x4CA1, 0xAD, 0x3A, 0x97, 0x9C, 0x3D, 0x44, 0xDD, 0xAC);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowUIActivatedEventArgs> { define_guid(0xBC8A844D, 0x9EB, 0x5746, 0x72, 0xA6, 0x8D, 0xC8, 0xB5, 0xED, 0xBE, 0x9B);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowSpoolStreamContent> { define_guid(0x72E55ECE, 0xE406, 0x4B74, 0x84, 0xE1, 0x3F, 0xF3, 0xFD, 0xCD, 0xAF, 0x70);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowObjectModelSourceFileContent> { define_guid(0xC36C8A6A, 0x8A2A, 0x419A, 0xB3, 0xC3, 0x20, 0x90, 0xE6, 0xBF, 0xAB, 0x2F);};
template<> struct uuid<Windows::Graphics::Printing::Workflow::IPrintWorkflowTriggerDetails> { define_guid(0x5739D868, 0x9D86, 0x4052, 0xB0, 0xCB, 0xF3, 0x10, 0xBE, 0xCD, 0x59, 0xBB);};

// types

namespace Windows { namespace Graphics { namespace Printing { namespace Workflow {

// IPrintWorkflowBackgroundSession
struct IPrintWorkflowBackgroundSession_raw : IInspectable {
	virtual STDMETHODIMP _add_SetupRequested(Foundation::TypedEventHandler<PrintWorkflowBackgroundSession*, PrintWorkflowBackgroundSetupRequestedEventArgs*>* setupEventHandler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_SetupRequested(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_Submitted(Foundation::TypedEventHandler<PrintWorkflowBackgroundSession*, PrintWorkflowSubmittedEventArgs*>* submittedEventHandler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_Submitted(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _get_Status(PrintWorkflowSessionStatus *value);
	virtual STDMETHODIMP _Start();
};
template<typename X> struct IPrintWorkflowBackgroundSession_adaptor : X {
	union {
		struct : property {
			PrintWorkflowSessionStatus get() { PrintWorkflowSessionStatus value; hrcheck(enc(&IPrintWorkflowBackgroundSession_adaptor::Status)->_get_Status(&value)); return value; }
			PrintWorkflowSessionStatus operator()() { return get(); }
			operator PrintWorkflowSessionStatus () { return get(); }
		} Status;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<PrintWorkflowBackgroundSession>, ptr<PrintWorkflowBackgroundSetupRequestedEventArgs>>> setupEventHandler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IPrintWorkflowBackgroundSession_adaptor::SetupRequested)->_add_SetupRequested(to_abi(setupEventHandler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IPrintWorkflowBackgroundSession_adaptor::SetupRequested)->_remove_SetupRequested(token)); }
		} SetupRequested;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<PrintWorkflowBackgroundSession>, ptr<PrintWorkflowSubmittedEventArgs>>> submittedEventHandler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IPrintWorkflowBackgroundSession_adaptor::Submitted)->_add_Submitted(to_abi(submittedEventHandler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IPrintWorkflowBackgroundSession_adaptor::Submitted)->_remove_Submitted(token)); }
		} Submitted;
	};
	void Start() { hrcheck(X::get()->_Start()); }
	IPrintWorkflowBackgroundSession_adaptor() {}
};
template<typename X> struct adapt<IPrintWorkflowBackgroundSession, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSession_adaptor<X> { typedef adapt IPrintWorkflowBackgroundSession; };
struct IPrintWorkflowBackgroundSession : IPrintWorkflowBackgroundSession_raw, generate<IPrintWorkflowBackgroundSession> {};

// PrintWorkflowBackgroundSession
template<typename X> struct statics<PrintWorkflowBackgroundSession, X> : X {
	typedef typename X::root_type PrintWorkflowBackgroundSession;
};
struct PrintWorkflowBackgroundSession : generate<PrintWorkflowBackgroundSession> {};

// IPrintWorkflowBackgroundSetupRequestedEventArgs
struct IPrintWorkflowBackgroundSetupRequestedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _GetUserPrintTicketAsync(Foundation::IAsyncOperation<PrintTicket::WorkflowPrintTicket*>* *operation);
	virtual STDMETHODIMP _get_Configuration(PrintWorkflowConfiguration* *configuration);
	virtual STDMETHODIMP _SetRequiresUI();
	virtual STDMETHODIMP _GetDeferral(Foundation::Deferral* *result);
};
template<typename X> struct IPrintWorkflowBackgroundSetupRequestedEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<PrintWorkflowConfiguration> get() { PrintWorkflowConfiguration* configuration; hrcheck(enc(&IPrintWorkflowBackgroundSetupRequestedEventArgs_adaptor::Configuration)->_get_Configuration(&configuration)); return from_abi(configuration); }
			ptr<PrintWorkflowConfiguration> operator()() { return get(); }
			operator ptr<PrintWorkflowConfiguration> () { return get(); }
			ptr<PrintWorkflowConfiguration> operator->() { return get(); }
		} Configuration;
	};
	ptr<Foundation::IAsyncOperation<ptr<PrintTicket::WorkflowPrintTicket>>> GetUserPrintTicketAsync() { Foundation::IAsyncOperation<PrintTicket::WorkflowPrintTicket*>* operation; hrcheck(X::get()->_GetUserPrintTicketAsync(&operation)); return from_abi(operation); }
	void SetRequiresUI() { hrcheck(X::get()->_SetRequiresUI()); }
	ptr<Foundation::Deferral> GetDeferral() { Foundation::Deferral* result; hrcheck(X::get()->_GetDeferral(&result)); return from_abi(result); }
	IPrintWorkflowBackgroundSetupRequestedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IPrintWorkflowBackgroundSetupRequestedEventArgs, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowBackgroundSetupRequestedEventArgs_adaptor<X> { typedef adapt IPrintWorkflowBackgroundSetupRequestedEventArgs; };
struct IPrintWorkflowBackgroundSetupRequestedEventArgs : IPrintWorkflowBackgroundSetupRequestedEventArgs_raw, generate<IPrintWorkflowBackgroundSetupRequestedEventArgs> {};

// PrintWorkflowBackgroundSetupRequestedEventArgs
template<typename X> struct statics<PrintWorkflowBackgroundSetupRequestedEventArgs, X> : X {
	typedef typename X::root_type PrintWorkflowBackgroundSetupRequestedEventArgs;
};
struct PrintWorkflowBackgroundSetupRequestedEventArgs : generate<PrintWorkflowBackgroundSetupRequestedEventArgs> {};

// IPrintWorkflowSubmittedEventArgs
struct IPrintWorkflowSubmittedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Operation(PrintWorkflowSubmittedOperation* *value);
	virtual STDMETHODIMP _GetTarget(PrintTicket::WorkflowPrintTicket* jobPrintTicket, PrintWorkflowTarget* *result);
	virtual STDMETHODIMP _GetDeferral(Foundation::Deferral* *result);
};
template<typename X> struct IPrintWorkflowSubmittedEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<PrintWorkflowSubmittedOperation> get() { PrintWorkflowSubmittedOperation* value; hrcheck(enc(&IPrintWorkflowSubmittedEventArgs_adaptor::Operation)->_get_Operation(&value)); return from_abi(value); }
			ptr<PrintWorkflowSubmittedOperation> operator()() { return get(); }
			operator ptr<PrintWorkflowSubmittedOperation> () { return get(); }
			ptr<PrintWorkflowSubmittedOperation> operator->() { return get(); }
		} Operation;
	};
	ptr<PrintWorkflowTarget> GetTarget(pptr<PrintTicket::WorkflowPrintTicket> jobPrintTicket) { PrintWorkflowTarget* result; hrcheck(X::get()->_GetTarget(jobPrintTicket, &result)); return from_abi(result); }
	ptr<Foundation::Deferral> GetDeferral() { Foundation::Deferral* result; hrcheck(X::get()->_GetDeferral(&result)); return from_abi(result); }
	IPrintWorkflowSubmittedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IPrintWorkflowSubmittedEventArgs, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedEventArgs_adaptor<X> { typedef adapt IPrintWorkflowSubmittedEventArgs; };
struct IPrintWorkflowSubmittedEventArgs : IPrintWorkflowSubmittedEventArgs_raw, generate<IPrintWorkflowSubmittedEventArgs> {};

// PrintWorkflowSubmittedEventArgs
template<typename X> struct statics<PrintWorkflowSubmittedEventArgs, X> : X {
	typedef typename X::root_type PrintWorkflowSubmittedEventArgs;
};
struct PrintWorkflowSubmittedEventArgs : generate<PrintWorkflowSubmittedEventArgs> {};

// IPrintWorkflowConfiguration
struct IPrintWorkflowConfiguration_raw : IInspectable {
	virtual STDMETHODIMP _get_SourceAppDisplayName(HSTRING *value);
	virtual STDMETHODIMP _get_JobTitle(HSTRING *value);
	virtual STDMETHODIMP _get_SessionId(HSTRING *value);
};
template<typename X> struct IPrintWorkflowConfiguration_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IPrintWorkflowConfiguration_adaptor::JobTitle)->_get_JobTitle(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} JobTitle;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IPrintWorkflowConfiguration_adaptor::SessionId)->_get_SessionId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} SessionId;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IPrintWorkflowConfiguration_adaptor::SourceAppDisplayName)->_get_SourceAppDisplayName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} SourceAppDisplayName;
	};
	IPrintWorkflowConfiguration_adaptor() {}
};
template<typename X> struct adapt<IPrintWorkflowConfiguration, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowConfiguration_adaptor<X> { typedef adapt IPrintWorkflowConfiguration; };
struct IPrintWorkflowConfiguration : IPrintWorkflowConfiguration_raw, generate<IPrintWorkflowConfiguration> {};

// IPrintWorkflowForegroundSession
struct IPrintWorkflowForegroundSession_raw : IInspectable {
	virtual STDMETHODIMP _add_SetupRequested(Foundation::TypedEventHandler<PrintWorkflowForegroundSession*, PrintWorkflowForegroundSetupRequestedEventArgs*>* setupEventHandler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_SetupRequested(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_XpsDataAvailable(Foundation::TypedEventHandler<PrintWorkflowForegroundSession*, PrintWorkflowXpsDataAvailableEventArgs*>* xpsDataAvailableEventHandler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_XpsDataAvailable(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _get_Status(PrintWorkflowSessionStatus *value);
	virtual STDMETHODIMP _Start();
};
template<typename X> struct IPrintWorkflowForegroundSession_adaptor : X {
	union {
		struct : property {
			PrintWorkflowSessionStatus get() { PrintWorkflowSessionStatus value; hrcheck(enc(&IPrintWorkflowForegroundSession_adaptor::Status)->_get_Status(&value)); return value; }
			PrintWorkflowSessionStatus operator()() { return get(); }
			operator PrintWorkflowSessionStatus () { return get(); }
		} Status;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<PrintWorkflowForegroundSession>, ptr<PrintWorkflowForegroundSetupRequestedEventArgs>>> setupEventHandler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IPrintWorkflowForegroundSession_adaptor::SetupRequested)->_add_SetupRequested(to_abi(setupEventHandler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IPrintWorkflowForegroundSession_adaptor::SetupRequested)->_remove_SetupRequested(token)); }
		} SetupRequested;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<PrintWorkflowForegroundSession>, ptr<PrintWorkflowXpsDataAvailableEventArgs>>> xpsDataAvailableEventHandler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IPrintWorkflowForegroundSession_adaptor::XpsDataAvailable)->_add_XpsDataAvailable(to_abi(xpsDataAvailableEventHandler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IPrintWorkflowForegroundSession_adaptor::XpsDataAvailable)->_remove_XpsDataAvailable(token)); }
		} XpsDataAvailable;
	};
	void Start() { hrcheck(X::get()->_Start()); }
	IPrintWorkflowForegroundSession_adaptor() {}
};
template<typename X> struct adapt<IPrintWorkflowForegroundSession, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSession_adaptor<X> { typedef adapt IPrintWorkflowForegroundSession; };
struct IPrintWorkflowForegroundSession : IPrintWorkflowForegroundSession_raw, generate<IPrintWorkflowForegroundSession> {};

// PrintWorkflowForegroundSession
template<typename X> struct statics<PrintWorkflowForegroundSession, X> : X {
	typedef typename X::root_type PrintWorkflowForegroundSession;
};
struct PrintWorkflowForegroundSession : generate<PrintWorkflowForegroundSession> {};

// IPrintWorkflowForegroundSetupRequestedEventArgs
struct IPrintWorkflowForegroundSetupRequestedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _GetUserPrintTicketAsync(Foundation::IAsyncOperation<PrintTicket::WorkflowPrintTicket*>* *operation);
	virtual STDMETHODIMP _get_Configuration(PrintWorkflowConfiguration* *value);
	virtual STDMETHODIMP _GetDeferral(Foundation::Deferral* *result);
};
template<typename X> struct IPrintWorkflowForegroundSetupRequestedEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<PrintWorkflowConfiguration> get() { PrintWorkflowConfiguration* value; hrcheck(enc(&IPrintWorkflowForegroundSetupRequestedEventArgs_adaptor::Configuration)->_get_Configuration(&value)); return from_abi(value); }
			ptr<PrintWorkflowConfiguration> operator()() { return get(); }
			operator ptr<PrintWorkflowConfiguration> () { return get(); }
			ptr<PrintWorkflowConfiguration> operator->() { return get(); }
		} Configuration;
	};
	ptr<Foundation::IAsyncOperation<ptr<PrintTicket::WorkflowPrintTicket>>> GetUserPrintTicketAsync() { Foundation::IAsyncOperation<PrintTicket::WorkflowPrintTicket*>* operation; hrcheck(X::get()->_GetUserPrintTicketAsync(&operation)); return from_abi(operation); }
	ptr<Foundation::Deferral> GetDeferral() { Foundation::Deferral* result; hrcheck(X::get()->_GetDeferral(&result)); return from_abi(result); }
	IPrintWorkflowForegroundSetupRequestedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IPrintWorkflowForegroundSetupRequestedEventArgs, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowForegroundSetupRequestedEventArgs_adaptor<X> { typedef adapt IPrintWorkflowForegroundSetupRequestedEventArgs; };
struct IPrintWorkflowForegroundSetupRequestedEventArgs : IPrintWorkflowForegroundSetupRequestedEventArgs_raw, generate<IPrintWorkflowForegroundSetupRequestedEventArgs> {};

// PrintWorkflowForegroundSetupRequestedEventArgs
template<typename X> struct statics<PrintWorkflowForegroundSetupRequestedEventArgs, X> : X {
	typedef typename X::root_type PrintWorkflowForegroundSetupRequestedEventArgs;
};
struct PrintWorkflowForegroundSetupRequestedEventArgs : generate<PrintWorkflowForegroundSetupRequestedEventArgs> {};

// IPrintWorkflowXpsDataAvailableEventArgs
struct IPrintWorkflowXpsDataAvailableEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Operation(PrintWorkflowSubmittedOperation* *value);
	virtual STDMETHODIMP _GetDeferral(Foundation::Deferral* *result);
};
template<typename X> struct IPrintWorkflowXpsDataAvailableEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<PrintWorkflowSubmittedOperation> get() { PrintWorkflowSubmittedOperation* value; hrcheck(enc(&IPrintWorkflowXpsDataAvailableEventArgs_adaptor::Operation)->_get_Operation(&value)); return from_abi(value); }
			ptr<PrintWorkflowSubmittedOperation> operator()() { return get(); }
			operator ptr<PrintWorkflowSubmittedOperation> () { return get(); }
			ptr<PrintWorkflowSubmittedOperation> operator->() { return get(); }
		} Operation;
	};
	ptr<Foundation::Deferral> GetDeferral() { Foundation::Deferral* result; hrcheck(X::get()->_GetDeferral(&result)); return from_abi(result); }
	IPrintWorkflowXpsDataAvailableEventArgs_adaptor() {}
};
template<typename X> struct adapt<IPrintWorkflowXpsDataAvailableEventArgs, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowXpsDataAvailableEventArgs_adaptor<X> { typedef adapt IPrintWorkflowXpsDataAvailableEventArgs; };
struct IPrintWorkflowXpsDataAvailableEventArgs : IPrintWorkflowXpsDataAvailableEventArgs_raw, generate<IPrintWorkflowXpsDataAvailableEventArgs> {};

// PrintWorkflowXpsDataAvailableEventArgs
template<typename X> struct statics<PrintWorkflowXpsDataAvailableEventArgs, X> : X {
	typedef typename X::root_type PrintWorkflowXpsDataAvailableEventArgs;
};
struct PrintWorkflowXpsDataAvailableEventArgs : generate<PrintWorkflowXpsDataAvailableEventArgs> {};

// PrintWorkflowConfiguration
template<typename X> struct statics<PrintWorkflowConfiguration, X> : X {
	typedef typename X::root_type PrintWorkflowConfiguration;
};
struct PrintWorkflowConfiguration : generate<PrintWorkflowConfiguration> {};

// IPrintWorkflowSubmittedOperation
struct IPrintWorkflowSubmittedOperation_raw : IInspectable {
	virtual STDMETHODIMP _Complete(PrintWorkflowSubmittedStatus status);
	virtual STDMETHODIMP _get_Configuration(PrintWorkflowConfiguration* *value);
	virtual STDMETHODIMP _get_XpsContent(PrintWorkflowSourceContent* *value);
};
template<typename X> struct IPrintWorkflowSubmittedOperation_adaptor : X {
	union {
		struct : property {
			ptr<PrintWorkflowConfiguration> get() { PrintWorkflowConfiguration* value; hrcheck(enc(&IPrintWorkflowSubmittedOperation_adaptor::Configuration)->_get_Configuration(&value)); return from_abi(value); }
			ptr<PrintWorkflowConfiguration> operator()() { return get(); }
			operator ptr<PrintWorkflowConfiguration> () { return get(); }
			ptr<PrintWorkflowConfiguration> operator->() { return get(); }
		} Configuration;
		struct : property {
			ptr<PrintWorkflowSourceContent> get() { PrintWorkflowSourceContent* value; hrcheck(enc(&IPrintWorkflowSubmittedOperation_adaptor::XpsContent)->_get_XpsContent(&value)); return from_abi(value); }
			ptr<PrintWorkflowSourceContent> operator()() { return get(); }
			operator ptr<PrintWorkflowSourceContent> () { return get(); }
			ptr<PrintWorkflowSourceContent> operator->() { return get(); }
		} XpsContent;
	};
	void Complete(PrintWorkflowSubmittedStatus status) { hrcheck(X::get()->_Complete(status)); }
	IPrintWorkflowSubmittedOperation_adaptor() {}
};
template<typename X> struct adapt<IPrintWorkflowSubmittedOperation, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowSubmittedOperation_adaptor<X> { typedef adapt IPrintWorkflowSubmittedOperation; };
struct IPrintWorkflowSubmittedOperation : IPrintWorkflowSubmittedOperation_raw, generate<IPrintWorkflowSubmittedOperation> {};

// IPrintWorkflowSourceContent
struct IPrintWorkflowSourceContent_raw : IInspectable {
	virtual STDMETHODIMP _GetJobPrintTicketAsync(Foundation::IAsyncOperation<PrintTicket::WorkflowPrintTicket*>* *operation);
	virtual STDMETHODIMP _GetSourceSpoolDataAsStreamContent(PrintWorkflowSpoolStreamContent* *result);
	virtual STDMETHODIMP _GetSourceSpoolDataAsXpsObjectModel(PrintWorkflowObjectModelSourceFileContent* *result);
};
template<typename X> struct IPrintWorkflowSourceContent_adaptor : X {
	ptr<Foundation::IAsyncOperation<ptr<PrintTicket::WorkflowPrintTicket>>> GetJobPrintTicketAsync() { Foundation::IAsyncOperation<PrintTicket::WorkflowPrintTicket*>* operation; hrcheck(X::get()->_GetJobPrintTicketAsync(&operation)); return from_abi(operation); }
	ptr<PrintWorkflowSpoolStreamContent> GetSourceSpoolDataAsStreamContent() { PrintWorkflowSpoolStreamContent* result; hrcheck(X::get()->_GetSourceSpoolDataAsStreamContent(&result)); return from_abi(result); }
	ptr<PrintWorkflowObjectModelSourceFileContent> GetSourceSpoolDataAsXpsObjectModel() { PrintWorkflowObjectModelSourceFileContent* result; hrcheck(X::get()->_GetSourceSpoolDataAsXpsObjectModel(&result)); return from_abi(result); }
};
template<typename X> struct adapt<IPrintWorkflowSourceContent, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowSourceContent_adaptor<X> { typedef adapt IPrintWorkflowSourceContent; };
struct IPrintWorkflowSourceContent : IPrintWorkflowSourceContent_raw, generate<IPrintWorkflowSourceContent> {};

// PrintWorkflowSourceContent
template<typename X> struct statics<PrintWorkflowSourceContent, X> : X {
	typedef typename X::root_type PrintWorkflowSourceContent;
};
struct PrintWorkflowSourceContent : generate<PrintWorkflowSourceContent> {};

// PrintWorkflowSubmittedOperation
template<typename X> struct statics<PrintWorkflowSubmittedOperation, X> : X {
	typedef typename X::root_type PrintWorkflowSubmittedOperation;
};
struct PrintWorkflowSubmittedOperation : generate<PrintWorkflowSubmittedOperation> {};

// IPrintWorkflowTarget
struct IPrintWorkflowTarget_raw : IInspectable {
	virtual STDMETHODIMP _get_TargetAsStream(PrintWorkflowStreamTarget* *value);
	virtual STDMETHODIMP _get_TargetAsXpsObjectModelPackage(PrintWorkflowObjectModelTargetPackage* *value);
};
template<typename X> struct IPrintWorkflowTarget_adaptor : X {
	union {
		struct : property {
			ptr<PrintWorkflowStreamTarget> get() { PrintWorkflowStreamTarget* value; hrcheck(enc(&IPrintWorkflowTarget_adaptor::TargetAsStream)->_get_TargetAsStream(&value)); return from_abi(value); }
			ptr<PrintWorkflowStreamTarget> operator()() { return get(); }
			operator ptr<PrintWorkflowStreamTarget> () { return get(); }
			ptr<PrintWorkflowStreamTarget> operator->() { return get(); }
		} TargetAsStream;
		struct : property {
			ptr<PrintWorkflowObjectModelTargetPackage> get() { PrintWorkflowObjectModelTargetPackage* value; hrcheck(enc(&IPrintWorkflowTarget_adaptor::TargetAsXpsObjectModelPackage)->_get_TargetAsXpsObjectModelPackage(&value)); return from_abi(value); }
			ptr<PrintWorkflowObjectModelTargetPackage> operator()() { return get(); }
			operator ptr<PrintWorkflowObjectModelTargetPackage> () { return get(); }
			ptr<PrintWorkflowObjectModelTargetPackage> operator->() { return get(); }
		} TargetAsXpsObjectModelPackage;
	};
	IPrintWorkflowTarget_adaptor() {}
};
template<typename X> struct adapt<IPrintWorkflowTarget, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowTarget_adaptor<X> { typedef adapt IPrintWorkflowTarget; };
struct IPrintWorkflowTarget : IPrintWorkflowTarget_raw, generate<IPrintWorkflowTarget> {};

// PrintWorkflowTarget
template<typename X> struct statics<PrintWorkflowTarget, X> : X {
	typedef typename X::root_type PrintWorkflowTarget;
};
struct PrintWorkflowTarget : generate<PrintWorkflowTarget> {};

// IPrintWorkflowStreamTarget
struct IPrintWorkflowStreamTarget_raw : IInspectable {
	virtual STDMETHODIMP _GetOutputStream(Storage::Streams::IOutputStream* *result);
};
template<typename X> struct IPrintWorkflowStreamTarget_adaptor : X {
	ptr<Storage::Streams::IOutputStream> GetOutputStream() { Storage::Streams::IOutputStream* result; hrcheck(X::get()->_GetOutputStream(&result)); return from_abi(result); }
};
template<typename X> struct adapt<IPrintWorkflowStreamTarget, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowStreamTarget_adaptor<X> { typedef adapt IPrintWorkflowStreamTarget; };
struct IPrintWorkflowStreamTarget : IPrintWorkflowStreamTarget_raw, generate<IPrintWorkflowStreamTarget> {};

// PrintWorkflowStreamTarget
template<typename X> struct statics<PrintWorkflowStreamTarget, X> : X {
	typedef typename X::root_type PrintWorkflowStreamTarget;
};
struct PrintWorkflowStreamTarget : generate<PrintWorkflowStreamTarget> {};

// IPrintWorkflowObjectModelTargetPackage
struct IPrintWorkflowObjectModelTargetPackage : IInspectable, generate<IPrintWorkflowObjectModelTargetPackage> {};

// PrintWorkflowObjectModelTargetPackage
template<typename X> struct statics<PrintWorkflowObjectModelTargetPackage, X> : X {
	typedef typename X::root_type PrintWorkflowObjectModelTargetPackage;
};
struct PrintWorkflowObjectModelTargetPackage : generate<PrintWorkflowObjectModelTargetPackage> {};

// IPrintWorkflowUIActivatedEventArgs
struct IPrintWorkflowUIActivatedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_PrintWorkflowSession(PrintWorkflowForegroundSession* *value);
};
template<typename X> struct IPrintWorkflowUIActivatedEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<PrintWorkflowForegroundSession> get() { PrintWorkflowForegroundSession* value; hrcheck(enc(&IPrintWorkflowUIActivatedEventArgs_adaptor::PrintWorkflowSession)->_get_PrintWorkflowSession(&value)); return from_abi(value); }
			ptr<PrintWorkflowForegroundSession> operator()() { return get(); }
			operator ptr<PrintWorkflowForegroundSession> () { return get(); }
			ptr<PrintWorkflowForegroundSession> operator->() { return get(); }
		} PrintWorkflowSession;
	};
	IPrintWorkflowUIActivatedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IPrintWorkflowUIActivatedEventArgs, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowUIActivatedEventArgs_adaptor<X> { typedef adapt IPrintWorkflowUIActivatedEventArgs; };
struct IPrintWorkflowUIActivatedEventArgs : IPrintWorkflowUIActivatedEventArgs_raw, generate<IPrintWorkflowUIActivatedEventArgs> {};

// IPrintWorkflowSpoolStreamContent
struct IPrintWorkflowSpoolStreamContent_raw : IInspectable {
	virtual STDMETHODIMP _GetInputStream(Storage::Streams::IInputStream* *result);
};
template<typename X> struct IPrintWorkflowSpoolStreamContent_adaptor : X {
	ptr<Storage::Streams::IInputStream> GetInputStream() { Storage::Streams::IInputStream* result; hrcheck(X::get()->_GetInputStream(&result)); return from_abi(result); }
};
template<typename X> struct adapt<IPrintWorkflowSpoolStreamContent, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowSpoolStreamContent_adaptor<X> { typedef adapt IPrintWorkflowSpoolStreamContent; };
struct IPrintWorkflowSpoolStreamContent : IPrintWorkflowSpoolStreamContent_raw, generate<IPrintWorkflowSpoolStreamContent> {};

// PrintWorkflowSpoolStreamContent
template<typename X> struct statics<PrintWorkflowSpoolStreamContent, X> : X {
	typedef typename X::root_type PrintWorkflowSpoolStreamContent;
};
struct PrintWorkflowSpoolStreamContent : generate<PrintWorkflowSpoolStreamContent> {};

// IPrintWorkflowObjectModelSourceFileContent
struct IPrintWorkflowObjectModelSourceFileContent : IInspectable, generate<IPrintWorkflowObjectModelSourceFileContent> {};

// PrintWorkflowObjectModelSourceFileContent
template<typename X> struct statics<PrintWorkflowObjectModelSourceFileContent, X> : X {
	typedef typename X::root_type PrintWorkflowObjectModelSourceFileContent;
};
struct PrintWorkflowObjectModelSourceFileContent : generate<PrintWorkflowObjectModelSourceFileContent> {};

// IPrintWorkflowTriggerDetails
struct IPrintWorkflowTriggerDetails_raw : IInspectable {
	virtual STDMETHODIMP _get_PrintWorkflowSession(PrintWorkflowBackgroundSession* *value);
};
template<typename X> struct IPrintWorkflowTriggerDetails_adaptor : X {
	union {
		struct : property {
			ptr<PrintWorkflowBackgroundSession> get() { PrintWorkflowBackgroundSession* value; hrcheck(enc(&IPrintWorkflowTriggerDetails_adaptor::PrintWorkflowSession)->_get_PrintWorkflowSession(&value)); return from_abi(value); }
			ptr<PrintWorkflowBackgroundSession> operator()() { return get(); }
			operator ptr<PrintWorkflowBackgroundSession> () { return get(); }
			ptr<PrintWorkflowBackgroundSession> operator->() { return get(); }
		} PrintWorkflowSession;
	};
	IPrintWorkflowTriggerDetails_adaptor() {}
};
template<typename X> struct adapt<IPrintWorkflowTriggerDetails, X> : Windows::Graphics::Printing::Workflow::IPrintWorkflowTriggerDetails_adaptor<X> { typedef adapt IPrintWorkflowTriggerDetails; };
struct IPrintWorkflowTriggerDetails : IPrintWorkflowTriggerDetails_raw, generate<IPrintWorkflowTriggerDetails> {};

// PrintWorkflowUIActivatedEventArgs
template<typename X> struct statics<PrintWorkflowUIActivatedEventArgs, X> : X {
	typedef typename X::root_type PrintWorkflowUIActivatedEventArgs;
};
struct PrintWorkflowUIActivatedEventArgs : generate<PrintWorkflowUIActivatedEventArgs> {};

// PrintWorkflowTriggerDetails
template<typename X> struct statics<PrintWorkflowTriggerDetails, X> : X {
	typedef typename X::root_type PrintWorkflowTriggerDetails;
};
struct PrintWorkflowTriggerDetails : generate<PrintWorkflowTriggerDetails> {};
}}}}
} // namespace iso_winrt
