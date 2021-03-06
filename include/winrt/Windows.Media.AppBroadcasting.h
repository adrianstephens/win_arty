#pragma once
// generated by isopod tools
// namespaces:
// Windows.Media.AppBroadcasting

#include "Windows.Media.AppBroadcasting.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace System {
struct User;
}}

// defs

template<> struct def<Windows::Media::AppBroadcasting::AppBroadcastingContract> : value_type<> {};
template<> struct def<Windows::Media::AppBroadcasting::IAppBroadcastingUI> : interface_type<> {};
template<> struct def<Windows::Media::AppBroadcasting::IAppBroadcastingStatus> : interface_type<> {};
template<> struct def<Windows::Media::AppBroadcasting::AppBroadcastingStatus> : class_type<Platform::Object, Windows::Media::AppBroadcasting::IAppBroadcastingStatus> {};
template<> struct def<Windows::Media::AppBroadcasting::IAppBroadcastingUIStatics> : interface_type<> {};
template<> struct def<Windows::Media::AppBroadcasting::AppBroadcastingUI> : class_type<Platform::Object, Windows::Media::AppBroadcasting::IAppBroadcastingUI> {};
template<> struct def<Windows::Media::AppBroadcasting::IAppBroadcastingMonitor> : interface_type<> {};
template<> struct def<Windows::Media::AppBroadcasting::AppBroadcastingMonitor> : class_type<Platform::Object, Windows::Media::AppBroadcasting::IAppBroadcastingMonitor> {};
template<> struct def<Windows::Media::AppBroadcasting::IAppBroadcastingStatusDetails> : interface_type<> {};
template<> struct def<Windows::Media::AppBroadcasting::AppBroadcastingStatusDetails> : class_type<Platform::Object, Windows::Media::AppBroadcasting::IAppBroadcastingStatusDetails> {};

// uuids

template<> struct uuid<Windows::Media::AppBroadcasting::IAppBroadcastingUI> { define_guid(0xE56F9F8F, 0xEE99, 0x4DCA, 0xA3, 0xC3, 0x70, 0xAF, 0x3D, 0xB4, 0x4F, 0x5F);};
template<> struct uuid<Windows::Media::AppBroadcasting::IAppBroadcastingStatus> { define_guid(0x1225E4DF, 0x3A1, 0x42F8, 0x8B, 0x80, 0xC9, 0x22, 0x8C, 0xD9, 0xCF, 0x2E);};
template<> struct uuid<Windows::Media::AppBroadcasting::IAppBroadcastingUIStatics> { define_guid(0x55A8A79D, 0x23CB, 0x4579, 0x9C, 0x34, 0x88, 0x6F, 0xE0, 0x2C, 0x4, 0x5A);};
template<> struct uuid<Windows::Media::AppBroadcasting::IAppBroadcastingMonitor> { define_guid(0xF95A68, 0x8907, 0x48A0, 0xB8, 0xEF, 0x24, 0xD2, 0x8, 0x13, 0x75, 0x42);};
template<> struct uuid<Windows::Media::AppBroadcasting::IAppBroadcastingStatusDetails> { define_guid(0x69DADA4, 0xB573, 0x4E3C, 0x8E, 0x19, 0x1B, 0xAF, 0xAC, 0xD0, 0x97, 0x13);};

// types

namespace Windows { namespace Media { namespace AppBroadcasting {

// IAppBroadcastingUI
struct IAppBroadcastingUI_raw : IInspectable {
	virtual STDMETHODIMP _GetStatus(AppBroadcastingStatus* *result);
	virtual STDMETHODIMP _ShowBroadcastUI();
};
template<typename X> struct IAppBroadcastingUI_adaptor : X {
	ptr<AppBroadcastingStatus> GetStatus() { AppBroadcastingStatus* result; hrcheck(X::get()->_GetStatus(&result)); return from_abi(result); }
	void ShowBroadcastUI() { hrcheck(X::get()->_ShowBroadcastUI()); }
};
template<typename X> struct adapt<IAppBroadcastingUI, X> : Windows::Media::AppBroadcasting::IAppBroadcastingUI_adaptor<X> { typedef adapt IAppBroadcastingUI; };
struct IAppBroadcastingUI : IAppBroadcastingUI_raw, generate<IAppBroadcastingUI> {};

// IAppBroadcastingStatus
struct IAppBroadcastingStatus_raw : IInspectable {
	virtual STDMETHODIMP _get_CanStartBroadcast(bool *value);
	virtual STDMETHODIMP _get_Details(AppBroadcastingStatusDetails* *value);
};
template<typename X> struct IAppBroadcastingStatus_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IAppBroadcastingStatus_adaptor::CanStartBroadcast)->_get_CanStartBroadcast(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} CanStartBroadcast;
		struct : property {
			ptr<AppBroadcastingStatusDetails> get() { AppBroadcastingStatusDetails* value; hrcheck(enc(&IAppBroadcastingStatus_adaptor::Details)->_get_Details(&value)); return from_abi(value); }
			ptr<AppBroadcastingStatusDetails> operator()() { return get(); }
			operator ptr<AppBroadcastingStatusDetails> () { return get(); }
			ptr<AppBroadcastingStatusDetails> operator->() { return get(); }
		} Details;
	};
	IAppBroadcastingStatus_adaptor() {}
};
template<typename X> struct adapt<IAppBroadcastingStatus, X> : Windows::Media::AppBroadcasting::IAppBroadcastingStatus_adaptor<X> { typedef adapt IAppBroadcastingStatus; };
struct IAppBroadcastingStatus : IAppBroadcastingStatus_raw, generate<IAppBroadcastingStatus> {};

// AppBroadcastingStatus
template<typename X> struct statics<AppBroadcastingStatus, X> : X {
	typedef typename X::root_type AppBroadcastingStatus;
};
struct AppBroadcastingStatus : generate<AppBroadcastingStatus> {};

// IAppBroadcastingUIStatics
struct IAppBroadcastingUIStatics : IInspectable {
	virtual STDMETHODIMP _GetDefault(AppBroadcastingUI* *result);
	virtual STDMETHODIMP _GetForUser(System::User* user, AppBroadcastingUI* *result);
};

// AppBroadcastingUI
template<typename> struct AppBroadcastingUI_statics {
	static ptr<AppBroadcastingUI> GetDefault() { AppBroadcastingUI* result; hrcheck(get_activation_factory<AppBroadcastingUI, IAppBroadcastingUIStatics>()->_GetDefault(&result)); return from_abi(result); }
	static ptr<AppBroadcastingUI> GetForUser(pptr<System::User> user) { AppBroadcastingUI* result; hrcheck(get_activation_factory<AppBroadcastingUI, IAppBroadcastingUIStatics>()->_GetForUser(user, &result)); return from_abi(result); }
};

template<typename X> struct statics<AppBroadcastingUI, X> : X, Windows::Media::AppBroadcasting::AppBroadcastingUI_statics<void> {
	typedef typename X::root_type AppBroadcastingUI;
};
struct AppBroadcastingUI : generate<AppBroadcastingUI> {};

// IAppBroadcastingMonitor
struct IAppBroadcastingMonitor_raw : IInspectable {
	virtual STDMETHODIMP _get_IsCurrentAppBroadcasting(bool *value);
	virtual STDMETHODIMP _add_IsCurrentAppBroadcastingChanged(Foundation::TypedEventHandler<AppBroadcastingMonitor*, IInspectable*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_IsCurrentAppBroadcastingChanged(Foundation::EventRegistrationToken token);
};
template<typename X> struct IAppBroadcastingMonitor_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IAppBroadcastingMonitor_adaptor::IsCurrentAppBroadcasting)->_get_IsCurrentAppBroadcasting(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsCurrentAppBroadcasting;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<AppBroadcastingMonitor>, object>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IAppBroadcastingMonitor_adaptor::IsCurrentAppBroadcastingChanged)->_add_IsCurrentAppBroadcastingChanged(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IAppBroadcastingMonitor_adaptor::IsCurrentAppBroadcastingChanged)->_remove_IsCurrentAppBroadcastingChanged(token)); }
		} IsCurrentAppBroadcastingChanged;
	};
	IAppBroadcastingMonitor_adaptor() {}
};
template<typename X> struct adapt<IAppBroadcastingMonitor, X> : Windows::Media::AppBroadcasting::IAppBroadcastingMonitor_adaptor<X> { typedef adapt IAppBroadcastingMonitor; };
struct IAppBroadcastingMonitor : IAppBroadcastingMonitor_raw, generate<IAppBroadcastingMonitor> {};

// AppBroadcastingMonitor
template<typename X> struct statics<AppBroadcastingMonitor, X> : X {
	typedef typename X::root_type AppBroadcastingMonitor;
};
struct AppBroadcastingMonitor : generate<AppBroadcastingMonitor> {};

// IAppBroadcastingStatusDetails
struct IAppBroadcastingStatusDetails_raw : IInspectable {
	virtual STDMETHODIMP _get_IsAnyAppBroadcasting(bool *value);
	virtual STDMETHODIMP _get_IsCaptureResourceUnavailable(bool *value);
	virtual STDMETHODIMP _get_IsGameStreamInProgress(bool *value);
	virtual STDMETHODIMP _get_IsGpuConstrained(bool *value);
	virtual STDMETHODIMP _get_IsAppInactive(bool *value);
	virtual STDMETHODIMP _get_IsBlockedForApp(bool *value);
	virtual STDMETHODIMP _get_IsDisabledByUser(bool *value);
	virtual STDMETHODIMP _get_IsDisabledBySystem(bool *value);
};
template<typename X> struct IAppBroadcastingStatusDetails_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IAppBroadcastingStatusDetails_adaptor::IsAnyAppBroadcasting)->_get_IsAnyAppBroadcasting(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsAnyAppBroadcasting;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IAppBroadcastingStatusDetails_adaptor::IsAppInactive)->_get_IsAppInactive(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsAppInactive;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IAppBroadcastingStatusDetails_adaptor::IsBlockedForApp)->_get_IsBlockedForApp(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsBlockedForApp;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IAppBroadcastingStatusDetails_adaptor::IsCaptureResourceUnavailable)->_get_IsCaptureResourceUnavailable(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsCaptureResourceUnavailable;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IAppBroadcastingStatusDetails_adaptor::IsDisabledBySystem)->_get_IsDisabledBySystem(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsDisabledBySystem;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IAppBroadcastingStatusDetails_adaptor::IsDisabledByUser)->_get_IsDisabledByUser(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsDisabledByUser;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IAppBroadcastingStatusDetails_adaptor::IsGameStreamInProgress)->_get_IsGameStreamInProgress(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsGameStreamInProgress;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IAppBroadcastingStatusDetails_adaptor::IsGpuConstrained)->_get_IsGpuConstrained(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsGpuConstrained;
	};
	IAppBroadcastingStatusDetails_adaptor() {}
};
template<typename X> struct adapt<IAppBroadcastingStatusDetails, X> : Windows::Media::AppBroadcasting::IAppBroadcastingStatusDetails_adaptor<X> { typedef adapt IAppBroadcastingStatusDetails; };
struct IAppBroadcastingStatusDetails : IAppBroadcastingStatusDetails_raw, generate<IAppBroadcastingStatusDetails> {};

// AppBroadcastingStatusDetails
template<typename X> struct statics<AppBroadcastingStatusDetails, X> : X {
	typedef typename X::root_type AppBroadcastingStatusDetails;
};
struct AppBroadcastingStatusDetails : generate<AppBroadcastingStatusDetails> {};
}}}
} // namespace iso_winrt
