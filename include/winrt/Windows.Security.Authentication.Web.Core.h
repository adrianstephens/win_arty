#pragma once
// generated by isopod tools
// namespaces:
// Windows.Security.Authentication.Web.Core

#include "Windows.Security.Authentication.Web.Core.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
template<typename K, typename V> struct IMap;
template<typename T> struct IIterable;
}}
namespace Security { namespace Credentials {
struct WebAccount;
struct WebAccountProvider;
}}
namespace System {
struct User;
}}

// defs

template<> struct def<Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType> : enum_type<int> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebTokenRequest> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebTokenRequest2> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebTokenRequest3> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebTokenRequestFactory> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::WebTokenRequest> : class_type<Platform::Object, Windows::Security::Authentication::Web::Core::IWebTokenRequest, Windows::Security::Authentication::Web::Core::IWebTokenRequest2, Windows::Security::Authentication::Web::Core::IWebTokenRequest3>, custom_activators {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebAccountEventArgs> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::WebAccountEventArgs> : class_type<Platform::Object, Windows::Security::Authentication::Web::Core::IWebAccountEventArgs> {};
template<> struct def<Windows::Security::Authentication::Web::Core::FindAllWebAccountsStatus> : enum_type<int> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IFindAllAccountsResult> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::FindAllAccountsResult> : class_type<Platform::Object, Windows::Security::Authentication::Web::Core::IFindAllAccountsResult> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2> : interface_type<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3> : interface_type<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebAccountMonitor> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::WebAccountMonitor> : class_type<Platform::Object, Windows::Security::Authentication::Web::Core::IWebAccountMonitor> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics4> : interface_type<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics> {};
template<> struct def<Windows::Security::Authentication::Web::Core::WebAuthenticationCoreManager> : class_type<Platform::Object, Platform::Object> {};
template<> struct def<Windows::Security::Authentication::Web::Core::WebTokenRequestStatus> : enum_type<int> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebProviderError> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebProviderErrorFactory> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::WebProviderError> : class_type<Platform::Object, Windows::Security::Authentication::Web::Core::IWebProviderError>, custom_activators {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebTokenRequestResult> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebTokenResponseFactory> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::IWebTokenResponse> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Web::Core::WebTokenResponse> : class_type<Platform::Object, Windows::Security::Authentication::Web::Core::IWebTokenResponse>, custom_activators {};
template<> struct def<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> : class_type<Platform::Object, Windows::Security::Authentication::Web::Core::IWebTokenRequestResult> {};

// uuids

template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebTokenRequest> { define_guid(0xB77B4D68, 0xADCB, 0x4673, 0xB3, 0x64, 0xC, 0xF7, 0xB3, 0x5C, 0xAF, 0x97);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebTokenRequest2> { define_guid(0xD700C079, 0x30C8, 0x4397, 0x96, 0x54, 0x96, 0x1C, 0x3B, 0xE8, 0xB8, 0x55);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebTokenRequest3> { define_guid(0x5A755B51, 0x3BB1, 0x41A5, 0xA6, 0x3D, 0x90, 0xBC, 0x32, 0xC7, 0xDB, 0x9A);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebTokenRequestFactory> { define_guid(0x6CF2141C, 0xFF0, 0x4C67, 0xB8, 0x4F, 0x99, 0xDD, 0xBE, 0x4A, 0x72, 0xC9);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebAccountEventArgs> { define_guid(0x6FB7037D, 0x424E, 0x44EC, 0x97, 0x7C, 0xEF, 0x24, 0x15, 0x46, 0x2A, 0x5A);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IFindAllAccountsResult> { define_guid(0xA5812B5D, 0xB72E, 0x420C, 0x86, 0xAB, 0xAA, 0xC0, 0xD7, 0xB7, 0x26, 0x1F);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics> { define_guid(0x6ACA7C92, 0xA581, 0x4479, 0x9C, 0x10, 0x75, 0x2E, 0xFF, 0x44, 0xFD, 0x34);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2> { define_guid(0xF584184A, 0x8B57, 0x4820, 0xB6, 0xA4, 0x70, 0xA5, 0xB6, 0xFC, 0xF4, 0x4A);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3> { define_guid(0x2404EEB2, 0x8924, 0x4D93, 0xAB, 0x3A, 0x99, 0x68, 0x8B, 0x41, 0x9D, 0x56);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebAccountMonitor> { define_guid(0x7445F5FD, 0xAA9D, 0x4619, 0x8D, 0x5D, 0xC1, 0x38, 0xA4, 0xED, 0xE3, 0xE5);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics4> { define_guid(0x54E633FE, 0x96E0, 0x41E8, 0x98, 0x32, 0x12, 0x98, 0x89, 0x7C, 0x2A, 0xAF);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebProviderError> { define_guid(0xDB191BB1, 0x50C5, 0x4809, 0x8D, 0xCA, 0x9, 0xC9, 0x94, 0x10, 0x24, 0x5C);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebProviderErrorFactory> { define_guid(0xE3C40A2D, 0x89EF, 0x4E37, 0x84, 0x7F, 0xA8, 0xB9, 0xD5, 0xA3, 0x29, 0x10);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebTokenRequestResult> { define_guid(0xC12A8305, 0xD1F8, 0x4483, 0x8D, 0x54, 0x38, 0xFE, 0x29, 0x27, 0x84, 0xFF);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebTokenResponseFactory> { define_guid(0xAB6BF7F8, 0x5450, 0x4EF6, 0x97, 0xF7, 0x5, 0x2B, 0x4, 0x31, 0xC0, 0xF0);};
template<> struct uuid<Windows::Security::Authentication::Web::Core::IWebTokenResponse> { define_guid(0x67A7C5CA, 0x83F6, 0x44C6, 0xA3, 0xB1, 0xE, 0xB6, 0x9E, 0x41, 0xFA, 0x8A);};

// types

namespace Windows { namespace Security { namespace Authentication { namespace Web { namespace Core {

// IWebTokenRequest
struct IWebTokenRequest_raw : IInspectable {
	virtual STDMETHODIMP _get_WebAccountProvider(Credentials::WebAccountProvider* *value);
	virtual STDMETHODIMP _get_Scope(HSTRING *value);
	virtual STDMETHODIMP _get_ClientId(HSTRING *value);
	virtual STDMETHODIMP _get_PromptType(WebTokenRequestPromptType *value);
	virtual STDMETHODIMP _get_Properties(Foundation::Collections::IMap<HSTRING, HSTRING>* *requestProperties);
};
template<typename X> struct IWebTokenRequest_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebTokenRequest_adaptor::ClientId)->_get_ClientId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ClientId;
		struct : property {
			WebTokenRequestPromptType get() { WebTokenRequestPromptType value; hrcheck(enc(&IWebTokenRequest_adaptor::PromptType)->_get_PromptType(&value)); return value; }
			WebTokenRequestPromptType operator()() { return get(); }
			operator WebTokenRequestPromptType () { return get(); }
		} PromptType;
		struct : property {
			ptr<Foundation::Collections::IMap<hstring, hstring>> get() { Foundation::Collections::IMap<HSTRING, HSTRING>* requestProperties; hrcheck(enc(&IWebTokenRequest_adaptor::Properties)->_get_Properties(&requestProperties)); return from_abi(requestProperties); }
			ptr<Foundation::Collections::IMap<hstring, hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IMap<hstring, hstring>> () { return get(); }
			ptr<Foundation::Collections::IMap<hstring, hstring>> operator->() { return get(); }
		} Properties;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebTokenRequest_adaptor::Scope)->_get_Scope(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Scope;
		struct : property {
			ptr<Credentials::WebAccountProvider> get() { Credentials::WebAccountProvider* value; hrcheck(enc(&IWebTokenRequest_adaptor::WebAccountProvider)->_get_WebAccountProvider(&value)); return from_abi(value); }
			ptr<Credentials::WebAccountProvider> operator()() { return get(); }
			operator ptr<Credentials::WebAccountProvider> () { return get(); }
			ptr<Credentials::WebAccountProvider> operator->() { return get(); }
		} WebAccountProvider;
	};
	IWebTokenRequest_adaptor() {}
};
template<typename X> struct adapt<IWebTokenRequest, X> : Windows::Security::Authentication::Web::Core::IWebTokenRequest_adaptor<X> { typedef adapt IWebTokenRequest; };
struct IWebTokenRequest : IWebTokenRequest_raw, generate<IWebTokenRequest> {};

// IWebTokenRequest2
struct IWebTokenRequest2_raw : IInspectable {
	virtual STDMETHODIMP _get_AppProperties(Foundation::Collections::IMap<HSTRING, HSTRING>* *requestProperties);
};
template<typename X> struct IWebTokenRequest2_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IMap<hstring, hstring>> get() { Foundation::Collections::IMap<HSTRING, HSTRING>* requestProperties; hrcheck(enc(&IWebTokenRequest2_adaptor::AppProperties)->_get_AppProperties(&requestProperties)); return from_abi(requestProperties); }
			ptr<Foundation::Collections::IMap<hstring, hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IMap<hstring, hstring>> () { return get(); }
			ptr<Foundation::Collections::IMap<hstring, hstring>> operator->() { return get(); }
		} AppProperties;
	};
	IWebTokenRequest2_adaptor() {}
};
template<typename X> struct adapt<IWebTokenRequest2, X> : Windows::Security::Authentication::Web::Core::IWebTokenRequest2_adaptor<X> { typedef adapt IWebTokenRequest2; };
struct IWebTokenRequest2 : IWebTokenRequest2_raw, generate<IWebTokenRequest2> {};

// IWebTokenRequest3
struct IWebTokenRequest3_raw : IInspectable {
	virtual STDMETHODIMP _get_CorrelationId(HSTRING *value);
	virtual STDMETHODIMP _put_CorrelationId(HSTRING value);
};
template<typename X> struct IWebTokenRequest3_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebTokenRequest3_adaptor::CorrelationId)->_get_CorrelationId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IWebTokenRequest3_adaptor::CorrelationId)->_put_CorrelationId(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} CorrelationId;
	};
	IWebTokenRequest3_adaptor() {}
};
template<typename X> struct adapt<IWebTokenRequest3, X> : Windows::Security::Authentication::Web::Core::IWebTokenRequest3_adaptor<X> { typedef adapt IWebTokenRequest3; };
struct IWebTokenRequest3 : IWebTokenRequest3_raw, generate<IWebTokenRequest3> {};

// IWebTokenRequestFactory
struct IWebTokenRequestFactory : IInspectable {
	virtual STDMETHODIMP _Create(Credentials::WebAccountProvider* provider, HSTRING scope, HSTRING clientId, WebTokenRequest* *webTokenRequest);
	virtual STDMETHODIMP _CreateWithPromptType(Credentials::WebAccountProvider* provider, HSTRING scope, HSTRING clientId, WebTokenRequestPromptType promptType, WebTokenRequest* *webTokenRequest);
	virtual STDMETHODIMP _CreateWithProvider(Credentials::WebAccountProvider* provider, WebTokenRequest* *webTokenRequest);
	virtual STDMETHODIMP _CreateWithScope(Credentials::WebAccountProvider* provider, HSTRING scope, WebTokenRequest* *webTokenRequest);
};

// WebTokenRequest
template<typename> struct WebTokenRequest_statics {
	static WebTokenRequest *activate(pptr<Credentials::WebAccountProvider> provider, hstring_ref scope, hstring_ref clientId) { WebTokenRequest *webTokenRequest; hrcheck(get_activation_factory<WebTokenRequest, IWebTokenRequestFactory>()->_Create(provider, scope, clientId, &webTokenRequest)); return webTokenRequest; }
	static WebTokenRequest *activate(pptr<Credentials::WebAccountProvider> provider, hstring_ref scope, hstring_ref clientId, WebTokenRequestPromptType promptType) { WebTokenRequest *webTokenRequest; hrcheck(get_activation_factory<WebTokenRequest, IWebTokenRequestFactory>()->_CreateWithPromptType(provider, scope, clientId, promptType, &webTokenRequest)); return webTokenRequest; }
	static WebTokenRequest *activate(pptr<Credentials::WebAccountProvider> provider) { WebTokenRequest *webTokenRequest; hrcheck(get_activation_factory<WebTokenRequest, IWebTokenRequestFactory>()->_CreateWithProvider(provider, &webTokenRequest)); return webTokenRequest; }
	static WebTokenRequest *activate(pptr<Credentials::WebAccountProvider> provider, hstring_ref scope) { WebTokenRequest *webTokenRequest; hrcheck(get_activation_factory<WebTokenRequest, IWebTokenRequestFactory>()->_CreateWithScope(provider, scope, &webTokenRequest)); return webTokenRequest; }
};

template<typename X> struct statics<WebTokenRequest, X> : X, Windows::Security::Authentication::Web::Core::WebTokenRequest_statics<void> {
	using Windows::Security::Authentication::Web::Core::WebTokenRequest_statics<void>::activate;
	typedef typename X::root_type WebTokenRequest;
};
struct WebTokenRequest : generate<WebTokenRequest> {};

// IWebAccountEventArgs
struct IWebAccountEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Account(Credentials::WebAccount* *value);
};
template<typename X> struct IWebAccountEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<Credentials::WebAccount> get() { Credentials::WebAccount* value; hrcheck(enc(&IWebAccountEventArgs_adaptor::Account)->_get_Account(&value)); return from_abi(value); }
			ptr<Credentials::WebAccount> operator()() { return get(); }
			operator ptr<Credentials::WebAccount> () { return get(); }
			ptr<Credentials::WebAccount> operator->() { return get(); }
		} Account;
	};
	IWebAccountEventArgs_adaptor() {}
};
template<typename X> struct adapt<IWebAccountEventArgs, X> : Windows::Security::Authentication::Web::Core::IWebAccountEventArgs_adaptor<X> { typedef adapt IWebAccountEventArgs; };
struct IWebAccountEventArgs : IWebAccountEventArgs_raw, generate<IWebAccountEventArgs> {};

// WebAccountEventArgs
template<typename X> struct statics<WebAccountEventArgs, X> : X {
	typedef typename X::root_type WebAccountEventArgs;
};
struct WebAccountEventArgs : generate<WebAccountEventArgs> {};

// IFindAllAccountsResult
struct IFindAllAccountsResult_raw : IInspectable {
	virtual STDMETHODIMP _get_Accounts(Foundation::Collections::IVectorView<Credentials::WebAccount*>* *value);
	virtual STDMETHODIMP _get_Status(FindAllWebAccountsStatus *value);
	virtual STDMETHODIMP _get_ProviderError(WebProviderError* *value);
};
template<typename X> struct IFindAllAccountsResult_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<Credentials::WebAccount>>> get() { Foundation::Collections::IVectorView<Credentials::WebAccount*>* value; hrcheck(enc(&IFindAllAccountsResult_adaptor::Accounts)->_get_Accounts(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<Credentials::WebAccount>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<Credentials::WebAccount>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<Credentials::WebAccount>>> operator->() { return get(); }
		} Accounts;
		struct : property {
			ptr<WebProviderError> get() { WebProviderError* value; hrcheck(enc(&IFindAllAccountsResult_adaptor::ProviderError)->_get_ProviderError(&value)); return from_abi(value); }
			ptr<WebProviderError> operator()() { return get(); }
			operator ptr<WebProviderError> () { return get(); }
			ptr<WebProviderError> operator->() { return get(); }
		} ProviderError;
		struct : property {
			FindAllWebAccountsStatus get() { FindAllWebAccountsStatus value; hrcheck(enc(&IFindAllAccountsResult_adaptor::Status)->_get_Status(&value)); return value; }
			FindAllWebAccountsStatus operator()() { return get(); }
			operator FindAllWebAccountsStatus () { return get(); }
		} Status;
	};
	IFindAllAccountsResult_adaptor() {}
};
template<typename X> struct adapt<IFindAllAccountsResult, X> : Windows::Security::Authentication::Web::Core::IFindAllAccountsResult_adaptor<X> { typedef adapt IFindAllAccountsResult; };
struct IFindAllAccountsResult : IFindAllAccountsResult_raw, generate<IFindAllAccountsResult> {};

// FindAllAccountsResult
template<typename X> struct statics<FindAllAccountsResult, X> : X {
	typedef typename X::root_type FindAllAccountsResult;
};
struct FindAllAccountsResult : generate<FindAllAccountsResult> {};

// IWebAuthenticationCoreManagerStatics
struct IWebAuthenticationCoreManagerStatics : IInspectable {
	virtual STDMETHODIMP _GetTokenSilentlyAsync(WebTokenRequest* request, Foundation::IAsyncOperation<WebTokenRequestResult*>* *asyncInfo);
	virtual STDMETHODIMP _GetTokenSilentlyWithWebAccountAsync(WebTokenRequest* request, Credentials::WebAccount* webAccount, Foundation::IAsyncOperation<WebTokenRequestResult*>* *asyncInfo);
	virtual STDMETHODIMP _RequestTokenAsync(WebTokenRequest* request, Foundation::IAsyncOperation<WebTokenRequestResult*>* *asyncInfo);
	virtual STDMETHODIMP _RequestTokenWithWebAccountAsync(WebTokenRequest* request, Credentials::WebAccount* webAccount, Foundation::IAsyncOperation<WebTokenRequestResult*>* *asyncInfo);
	virtual STDMETHODIMP _FindAccountAsync(Credentials::WebAccountProvider* provider, HSTRING webAccountId, Foundation::IAsyncOperation<Credentials::WebAccount*>* *asyncInfo);
	virtual STDMETHODIMP _FindAccountProviderAsync(HSTRING webAccountProviderId, Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* *asyncInfo);
	virtual STDMETHODIMP _FindAccountProviderWithAuthorityAsync(HSTRING webAccountProviderId, HSTRING authority, Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* *asyncInfo);
};

// IWebAuthenticationCoreManagerStatics2
struct IWebAuthenticationCoreManagerStatics2 : IInspectable {
	virtual STDMETHODIMP _FindAccountProviderWithAuthorityForUserAsync(HSTRING webAccountProviderId, HSTRING authority, System::User* user, Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* *asyncInfo);
};

// IWebAuthenticationCoreManagerStatics3
struct IWebAuthenticationCoreManagerStatics3 : IInspectable {
	virtual STDMETHODIMP _CreateWebAccountMonitor(Foundation::Collections::IIterable<Credentials::WebAccount*>* webAccounts, WebAccountMonitor* *result);
};

// IWebAccountMonitor
struct IWebAccountMonitor_raw : IInspectable {
	virtual STDMETHODIMP _add_Updated(Foundation::TypedEventHandler<WebAccountMonitor*, WebAccountEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_Updated(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_Removed(Foundation::TypedEventHandler<WebAccountMonitor*, WebAccountEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_Removed(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_DefaultSignInAccountChanged(Foundation::TypedEventHandler<WebAccountMonitor*, IInspectable*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_DefaultSignInAccountChanged(Foundation::EventRegistrationToken token);
};
template<typename X> struct IWebAccountMonitor_adaptor : X {
	union {
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<WebAccountMonitor>, object>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IWebAccountMonitor_adaptor::DefaultSignInAccountChanged)->_add_DefaultSignInAccountChanged(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IWebAccountMonitor_adaptor::DefaultSignInAccountChanged)->_remove_DefaultSignInAccountChanged(token)); }
		} DefaultSignInAccountChanged;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<WebAccountMonitor>, ptr<WebAccountEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IWebAccountMonitor_adaptor::Removed)->_add_Removed(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IWebAccountMonitor_adaptor::Removed)->_remove_Removed(token)); }
		} Removed;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<WebAccountMonitor>, ptr<WebAccountEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IWebAccountMonitor_adaptor::Updated)->_add_Updated(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IWebAccountMonitor_adaptor::Updated)->_remove_Updated(token)); }
		} Updated;
	};
	IWebAccountMonitor_adaptor() {}
};
template<typename X> struct adapt<IWebAccountMonitor, X> : Windows::Security::Authentication::Web::Core::IWebAccountMonitor_adaptor<X> { typedef adapt IWebAccountMonitor; };
struct IWebAccountMonitor : IWebAccountMonitor_raw, generate<IWebAccountMonitor> {};

// WebAccountMonitor
template<typename X> struct statics<WebAccountMonitor, X> : X {
	typedef typename X::root_type WebAccountMonitor;
};
struct WebAccountMonitor : generate<WebAccountMonitor> {};

// IWebAuthenticationCoreManagerStatics4
struct IWebAuthenticationCoreManagerStatics4 : IInspectable {
	virtual STDMETHODIMP _FindAllAccountsAsync(Credentials::WebAccountProvider* provider, Foundation::IAsyncOperation<FindAllAccountsResult*>* *operation);
	virtual STDMETHODIMP _FindAllAccountsWithClientIdAsync(Credentials::WebAccountProvider* provider, HSTRING clientId, Foundation::IAsyncOperation<FindAllAccountsResult*>* *operation);
	virtual STDMETHODIMP _FindSystemAccountProviderAsync(HSTRING webAccountProviderId, Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* *operation);
	virtual STDMETHODIMP _FindSystemAccountProviderWithAuthorityAsync(HSTRING webAccountProviderId, HSTRING authority, Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* *operation);
	virtual STDMETHODIMP _FindSystemAccountProviderWithAuthorityForUserAsync(HSTRING webAccountProviderId, HSTRING authority, System::User* user, Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* *operation);
};

// WebAuthenticationCoreManager
template<typename> struct WebAuthenticationCoreManager_statics {
	static ptr<Foundation::IAsyncOperation<ptr<FindAllAccountsResult>>> FindAllAccountsAsync(pptr<Credentials::WebAccountProvider> provider) { Foundation::IAsyncOperation<FindAllAccountsResult*>* operation; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics4>()->_FindAllAccountsAsync(provider, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<ptr<FindAllAccountsResult>>> FindAllAccountsAsync(pptr<Credentials::WebAccountProvider> provider, hstring_ref clientId) { Foundation::IAsyncOperation<FindAllAccountsResult*>* operation; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics4>()->_FindAllAccountsWithClientIdAsync(provider, clientId, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<ptr<Credentials::WebAccountProvider>>> FindSystemAccountProviderAsync(hstring_ref webAccountProviderId) { Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* operation; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics4>()->_FindSystemAccountProviderAsync(webAccountProviderId, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<ptr<Credentials::WebAccountProvider>>> FindSystemAccountProviderAsync(hstring_ref webAccountProviderId, hstring_ref authority) { Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* operation; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics4>()->_FindSystemAccountProviderWithAuthorityAsync(webAccountProviderId, authority, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<ptr<Credentials::WebAccountProvider>>> FindSystemAccountProviderAsync(hstring_ref webAccountProviderId, hstring_ref authority, pptr<System::User> user) { Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* operation; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics4>()->_FindSystemAccountProviderWithAuthorityForUserAsync(webAccountProviderId, authority, user, &operation)); return from_abi(operation); }
	static ptr<WebAccountMonitor> CreateWebAccountMonitor(pptr<Foundation::Collections::IIterable<ptr<Credentials::WebAccount>>> webAccounts) { WebAccountMonitor* result; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics3>()->_CreateWebAccountMonitor(to_abi(webAccounts), &result)); return from_abi(result); }
	static ptr<Foundation::IAsyncOperation<ptr<Credentials::WebAccountProvider>>> FindAccountProviderAsync(hstring_ref webAccountProviderId, hstring_ref authority, pptr<System::User> user) { Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* asyncInfo; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics2>()->_FindAccountProviderWithAuthorityForUserAsync(webAccountProviderId, authority, user, &asyncInfo)); return from_abi(asyncInfo); }
	static ptr<Foundation::IAsyncOperation<ptr<WebTokenRequestResult>>> GetTokenSilentlyAsync(pptr<WebTokenRequest> request) { Foundation::IAsyncOperation<WebTokenRequestResult*>* asyncInfo; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>()->_GetTokenSilentlyAsync(request, &asyncInfo)); return from_abi(asyncInfo); }
	static ptr<Foundation::IAsyncOperation<ptr<WebTokenRequestResult>>> GetTokenSilentlyAsync(pptr<WebTokenRequest> request, pptr<Credentials::WebAccount> webAccount) { Foundation::IAsyncOperation<WebTokenRequestResult*>* asyncInfo; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>()->_GetTokenSilentlyWithWebAccountAsync(request, webAccount, &asyncInfo)); return from_abi(asyncInfo); }
	static ptr<Foundation::IAsyncOperation<ptr<WebTokenRequestResult>>> RequestTokenAsync(pptr<WebTokenRequest> request) { Foundation::IAsyncOperation<WebTokenRequestResult*>* asyncInfo; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>()->_RequestTokenAsync(request, &asyncInfo)); return from_abi(asyncInfo); }
	static ptr<Foundation::IAsyncOperation<ptr<WebTokenRequestResult>>> RequestTokenAsync(pptr<WebTokenRequest> request, pptr<Credentials::WebAccount> webAccount) { Foundation::IAsyncOperation<WebTokenRequestResult*>* asyncInfo; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>()->_RequestTokenWithWebAccountAsync(request, webAccount, &asyncInfo)); return from_abi(asyncInfo); }
	static ptr<Foundation::IAsyncOperation<ptr<Credentials::WebAccount>>> FindAccountAsync(pptr<Credentials::WebAccountProvider> provider, hstring_ref webAccountId) { Foundation::IAsyncOperation<Credentials::WebAccount*>* asyncInfo; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>()->_FindAccountAsync(provider, webAccountId, &asyncInfo)); return from_abi(asyncInfo); }
	static ptr<Foundation::IAsyncOperation<ptr<Credentials::WebAccountProvider>>> FindAccountProviderAsync(hstring_ref webAccountProviderId) { Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* asyncInfo; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>()->_FindAccountProviderAsync(webAccountProviderId, &asyncInfo)); return from_abi(asyncInfo); }
	static ptr<Foundation::IAsyncOperation<ptr<Credentials::WebAccountProvider>>> FindAccountProviderAsync(hstring_ref webAccountProviderId, hstring_ref authority) { Foundation::IAsyncOperation<Credentials::WebAccountProvider*>* asyncInfo; hrcheck(get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>()->_FindAccountProviderWithAuthorityAsync(webAccountProviderId, authority, &asyncInfo)); return from_abi(asyncInfo); }
};

template<typename X> struct statics<WebAuthenticationCoreManager, X> : X, Windows::Security::Authentication::Web::Core::WebAuthenticationCoreManager_statics<void> {
	typedef typename X::root_type WebAuthenticationCoreManager;
};
struct WebAuthenticationCoreManager : generate<WebAuthenticationCoreManager> {};

// IWebProviderError
struct IWebProviderError_raw : IInspectable {
	virtual STDMETHODIMP _get_ErrorCode(unsigned *value);
	virtual STDMETHODIMP _get_ErrorMessage(HSTRING *value);
	virtual STDMETHODIMP _get_Properties(Foundation::Collections::IMap<HSTRING, HSTRING>* *value);
};
template<typename X> struct IWebProviderError_adaptor : X {
	union {
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IWebProviderError_adaptor::ErrorCode)->_get_ErrorCode(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} ErrorCode;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebProviderError_adaptor::ErrorMessage)->_get_ErrorMessage(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ErrorMessage;
		struct : property {
			ptr<Foundation::Collections::IMap<hstring, hstring>> get() { Foundation::Collections::IMap<HSTRING, HSTRING>* value; hrcheck(enc(&IWebProviderError_adaptor::Properties)->_get_Properties(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IMap<hstring, hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IMap<hstring, hstring>> () { return get(); }
			ptr<Foundation::Collections::IMap<hstring, hstring>> operator->() { return get(); }
		} Properties;
	};
	IWebProviderError_adaptor() {}
};
template<typename X> struct adapt<IWebProviderError, X> : Windows::Security::Authentication::Web::Core::IWebProviderError_adaptor<X> { typedef adapt IWebProviderError; };
struct IWebProviderError : IWebProviderError_raw, generate<IWebProviderError> {};

// IWebProviderErrorFactory
struct IWebProviderErrorFactory : IInspectable {
	virtual STDMETHODIMP _Create(unsigned errorCode, HSTRING errorMessage, WebProviderError* *webProviderError);
};

// WebProviderError
template<typename> struct WebProviderError_statics {
	static WebProviderError *activate(unsigned errorCode, hstring_ref errorMessage) { WebProviderError *webProviderError; hrcheck(get_activation_factory<WebProviderError, IWebProviderErrorFactory>()->_Create(errorCode, errorMessage, &webProviderError)); return webProviderError; }
};

template<typename X> struct statics<WebProviderError, X> : X, Windows::Security::Authentication::Web::Core::WebProviderError_statics<void> {
	using Windows::Security::Authentication::Web::Core::WebProviderError_statics<void>::activate;
	typedef typename X::root_type WebProviderError;
};
struct WebProviderError : generate<WebProviderError> {};

// IWebTokenRequestResult
struct IWebTokenRequestResult_raw : IInspectable {
	virtual STDMETHODIMP _get_ResponseData(Foundation::Collections::IVectorView<WebTokenResponse*>* *value);
	virtual STDMETHODIMP _get_ResponseStatus(WebTokenRequestStatus *value);
	virtual STDMETHODIMP _get_ResponseError(WebProviderError* *value);
	virtual STDMETHODIMP _InvalidateCacheAsync(Foundation::IAsyncAction* *asyncInfo);
};
template<typename X> struct IWebTokenRequestResult_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<WebTokenResponse>>> get() { Foundation::Collections::IVectorView<WebTokenResponse*>* value; hrcheck(enc(&IWebTokenRequestResult_adaptor::ResponseData)->_get_ResponseData(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<WebTokenResponse>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<WebTokenResponse>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<WebTokenResponse>>> operator->() { return get(); }
		} ResponseData;
		struct : property {
			ptr<WebProviderError> get() { WebProviderError* value; hrcheck(enc(&IWebTokenRequestResult_adaptor::ResponseError)->_get_ResponseError(&value)); return from_abi(value); }
			ptr<WebProviderError> operator()() { return get(); }
			operator ptr<WebProviderError> () { return get(); }
			ptr<WebProviderError> operator->() { return get(); }
		} ResponseError;
		struct : property {
			WebTokenRequestStatus get() { WebTokenRequestStatus value; hrcheck(enc(&IWebTokenRequestResult_adaptor::ResponseStatus)->_get_ResponseStatus(&value)); return value; }
			WebTokenRequestStatus operator()() { return get(); }
			operator WebTokenRequestStatus () { return get(); }
		} ResponseStatus;
	};
	ptr<Foundation::IAsyncAction> InvalidateCacheAsync() { Foundation::IAsyncAction* asyncInfo; hrcheck(X::get()->_InvalidateCacheAsync(&asyncInfo)); return from_abi(asyncInfo); }
	IWebTokenRequestResult_adaptor() {}
};
template<typename X> struct adapt<IWebTokenRequestResult, X> : Windows::Security::Authentication::Web::Core::IWebTokenRequestResult_adaptor<X> { typedef adapt IWebTokenRequestResult; };
struct IWebTokenRequestResult : IWebTokenRequestResult_raw, generate<IWebTokenRequestResult> {};

// IWebTokenResponseFactory
struct IWebTokenResponseFactory : IInspectable {
	virtual STDMETHODIMP _CreateWithToken(HSTRING token, WebTokenResponse* *webTokenResponse);
	virtual STDMETHODIMP _CreateWithTokenAndAccount(HSTRING token, Credentials::WebAccount* webAccount, WebTokenResponse* *webTokenResponse);
	virtual STDMETHODIMP _CreateWithTokenAccountAndError(HSTRING token, Credentials::WebAccount* webAccount, WebProviderError* error, WebTokenResponse* *webTokenResponse);
};

// IWebTokenResponse
struct IWebTokenResponse_raw : IInspectable {
	virtual STDMETHODIMP _get_Token(HSTRING *value);
	virtual STDMETHODIMP _get_ProviderError(WebProviderError* *value);
	virtual STDMETHODIMP _get_WebAccount(Credentials::WebAccount* *value);
	virtual STDMETHODIMP _get_Properties(Foundation::Collections::IMap<HSTRING, HSTRING>* *value);
};
template<typename X> struct IWebTokenResponse_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IMap<hstring, hstring>> get() { Foundation::Collections::IMap<HSTRING, HSTRING>* value; hrcheck(enc(&IWebTokenResponse_adaptor::Properties)->_get_Properties(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IMap<hstring, hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IMap<hstring, hstring>> () { return get(); }
			ptr<Foundation::Collections::IMap<hstring, hstring>> operator->() { return get(); }
		} Properties;
		struct : property {
			ptr<WebProviderError> get() { WebProviderError* value; hrcheck(enc(&IWebTokenResponse_adaptor::ProviderError)->_get_ProviderError(&value)); return from_abi(value); }
			ptr<WebProviderError> operator()() { return get(); }
			operator ptr<WebProviderError> () { return get(); }
			ptr<WebProviderError> operator->() { return get(); }
		} ProviderError;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebTokenResponse_adaptor::Token)->_get_Token(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Token;
		struct : property {
			ptr<Credentials::WebAccount> get() { Credentials::WebAccount* value; hrcheck(enc(&IWebTokenResponse_adaptor::WebAccount)->_get_WebAccount(&value)); return from_abi(value); }
			ptr<Credentials::WebAccount> operator()() { return get(); }
			operator ptr<Credentials::WebAccount> () { return get(); }
			ptr<Credentials::WebAccount> operator->() { return get(); }
		} WebAccount;
	};
	IWebTokenResponse_adaptor() {}
};
template<typename X> struct adapt<IWebTokenResponse, X> : Windows::Security::Authentication::Web::Core::IWebTokenResponse_adaptor<X> { typedef adapt IWebTokenResponse; };
struct IWebTokenResponse : IWebTokenResponse_raw, generate<IWebTokenResponse> {};

// WebTokenResponse
template<typename> struct WebTokenResponse_statics {
	static WebTokenResponse *activate() { WebTokenResponse *t; get_activation_factory<WebTokenResponse>()->ActivateInstance((IInspectable**)&t); return t; }
	static WebTokenResponse *activate(hstring_ref token) { WebTokenResponse *webTokenResponse; hrcheck(get_activation_factory<WebTokenResponse, IWebTokenResponseFactory>()->_CreateWithToken(token, &webTokenResponse)); return webTokenResponse; }
	static WebTokenResponse *activate(hstring_ref token, pptr<Credentials::WebAccount> webAccount) { WebTokenResponse *webTokenResponse; hrcheck(get_activation_factory<WebTokenResponse, IWebTokenResponseFactory>()->_CreateWithTokenAndAccount(token, webAccount, &webTokenResponse)); return webTokenResponse; }
	static WebTokenResponse *activate(hstring_ref token, pptr<Credentials::WebAccount> webAccount, pptr<WebProviderError> error) { WebTokenResponse *webTokenResponse; hrcheck(get_activation_factory<WebTokenResponse, IWebTokenResponseFactory>()->_CreateWithTokenAccountAndError(token, webAccount, error, &webTokenResponse)); return webTokenResponse; }
};

template<typename X> struct statics<WebTokenResponse, X> : X, Windows::Security::Authentication::Web::Core::WebTokenResponse_statics<void> {
	using Windows::Security::Authentication::Web::Core::WebTokenResponse_statics<void>::activate;
	typedef typename X::root_type WebTokenResponse;
};
struct WebTokenResponse : generate<WebTokenResponse> {};

// WebTokenRequestResult
template<typename X> struct statics<WebTokenRequestResult, X> : X {
	typedef typename X::root_type WebTokenRequestResult;
};
struct WebTokenRequestResult : generate<WebTokenRequestResult> {};
}}}}}
} // namespace iso_winrt
