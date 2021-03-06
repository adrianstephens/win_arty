#pragma once
// generated by isopod tools
// namespaces:
// Windows.ApplicationModel.CommunicationBlocking

#include "Windows.ApplicationModel.CommunicationBlocking.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IIterable;
}
template<typename TResult> struct IAsyncOperation;
}}

// defs

template<> struct def<Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2> : interface_type<Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics> {};
template<> struct def<Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::CommunicationBlocking::CommunicationBlockingAppManager> : class_type<Platform::Object, Platform::Object> {};
template<> struct def<Windows::ApplicationModel::CommunicationBlocking::CommunicationBlockingAccessManager> : class_type<Platform::Object, Platform::Object> {};
template<> struct def<Windows::ApplicationModel::CommunicationBlocking::CommunicationBlockingContract> : value_type<> {};

// uuids

template<> struct uuid<Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics> { define_guid(0x77DB58EC, 0x14A6, 0x4BAA, 0x94, 0x2A, 0x6A, 0x67, 0x3D, 0x99, 0x9B, 0xF2);};
template<> struct uuid<Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2> { define_guid(0x14A68EDD, 0xED88, 0x457A, 0xA3, 0x64, 0xA3, 0x63, 0x4D, 0x6F, 0x16, 0x6D);};
template<> struct uuid<Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics> { define_guid(0x1C969998, 0x9D2A, 0x5DB7, 0xED, 0xD5, 0xC, 0xE4, 0x7, 0xFC, 0x25, 0x95);};

// types

namespace Windows { namespace ApplicationModel { namespace CommunicationBlocking {

// ICommunicationBlockingAppManagerStatics
struct ICommunicationBlockingAppManagerStatics : IInspectable {
	virtual STDMETHODIMP _get_IsCurrentAppActiveBlockingApp(bool *value);
	virtual STDMETHODIMP _ShowCommunicationBlockingSettingsUI();
};

// ICommunicationBlockingAppManagerStatics2
struct ICommunicationBlockingAppManagerStatics2 : IInspectable {
	virtual STDMETHODIMP _RequestSetAsActiveBlockingAppAsync(Foundation::IAsyncOperation<bool>* *result);
};

// ICommunicationBlockingAccessManagerStatics
struct ICommunicationBlockingAccessManagerStatics : IInspectable {
	virtual STDMETHODIMP _get_IsBlockingActive(bool *value);
	virtual STDMETHODIMP _IsBlockedNumberAsync(HSTRING number, Foundation::IAsyncOperation<bool>* *result);
	virtual STDMETHODIMP _ShowBlockNumbersUI(Foundation::Collections::IIterable<HSTRING>* phoneNumbers, bool *value);
	virtual STDMETHODIMP _ShowUnblockNumbersUI(Foundation::Collections::IIterable<HSTRING>* phoneNumbers, bool *value);
	virtual STDMETHODIMP _ShowBlockedCallsUI();
	virtual STDMETHODIMP _ShowBlockedMessagesUI();
};

// CommunicationBlockingAppManager
template<typename> struct CommunicationBlockingAppManager_statics {
	static struct _IsCurrentAppActiveBlockingApp : property {
		bool get() { bool value; hrcheck(get_activation_factory<CommunicationBlockingAppManager, ICommunicationBlockingAppManagerStatics>()->_get_IsCurrentAppActiveBlockingApp(&value)); return value; }
		bool operator()() { return get(); }
		operator bool () { return get(); }
	} IsCurrentAppActiveBlockingApp;
	static ptr<Foundation::IAsyncOperation<bool>> RequestSetAsActiveBlockingAppAsync() { Foundation::IAsyncOperation<bool>* result; hrcheck(get_activation_factory<CommunicationBlockingAppManager, ICommunicationBlockingAppManagerStatics2>()->_RequestSetAsActiveBlockingAppAsync(&result)); return from_abi(result); }
	static void ShowCommunicationBlockingSettingsUI() { hrcheck(get_activation_factory<CommunicationBlockingAppManager, ICommunicationBlockingAppManagerStatics>()->_ShowCommunicationBlockingSettingsUI()); }
};
template<typename X> typename CommunicationBlockingAppManager_statics<X>::_IsCurrentAppActiveBlockingApp CommunicationBlockingAppManager_statics<X>::IsCurrentAppActiveBlockingApp;

template<typename X> struct statics<CommunicationBlockingAppManager, X> : X, Windows::ApplicationModel::CommunicationBlocking::CommunicationBlockingAppManager_statics<void> {
	typedef typename X::root_type CommunicationBlockingAppManager;
};
struct CommunicationBlockingAppManager : generate<CommunicationBlockingAppManager> {};

// CommunicationBlockingAccessManager
template<typename> struct CommunicationBlockingAccessManager_statics {
	static struct _IsBlockingActive : property {
		bool get() { bool value; hrcheck(get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>()->_get_IsBlockingActive(&value)); return value; }
		bool operator()() { return get(); }
		operator bool () { return get(); }
	} IsBlockingActive;
	static ptr<Foundation::IAsyncOperation<bool>> IsBlockedNumberAsync(hstring_ref number) { Foundation::IAsyncOperation<bool>* result; hrcheck(get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>()->_IsBlockedNumberAsync(number, &result)); return from_abi(result); }
	static bool ShowBlockNumbersUI(pptr<Foundation::Collections::IIterable<hstring>> phoneNumbers) { bool value; hrcheck(get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>()->_ShowBlockNumbersUI(to_abi(phoneNumbers), &value)); return value; }
	static bool ShowUnblockNumbersUI(pptr<Foundation::Collections::IIterable<hstring>> phoneNumbers) { bool value; hrcheck(get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>()->_ShowUnblockNumbersUI(to_abi(phoneNumbers), &value)); return value; }
	static void ShowBlockedCallsUI() { hrcheck(get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>()->_ShowBlockedCallsUI()); }
	static void ShowBlockedMessagesUI() { hrcheck(get_activation_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>()->_ShowBlockedMessagesUI()); }
};
template<typename X> typename CommunicationBlockingAccessManager_statics<X>::_IsBlockingActive CommunicationBlockingAccessManager_statics<X>::IsBlockingActive;

template<typename X> struct statics<CommunicationBlockingAccessManager, X> : X, Windows::ApplicationModel::CommunicationBlocking::CommunicationBlockingAccessManager_statics<void> {
	typedef typename X::root_type CommunicationBlockingAccessManager;
};
struct CommunicationBlockingAccessManager : generate<CommunicationBlockingAccessManager> {};
}}}
} // namespace iso_winrt
