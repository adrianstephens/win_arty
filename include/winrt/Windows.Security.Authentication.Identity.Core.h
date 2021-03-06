#pragma once
// generated by isopod tools
// namespaces:
// Windows.Security.Authentication.Identity.Core

#include "Windows.Security.Authentication.Identity.Core.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
template<typename T> struct IIterable;
}}}

// defs

template<> struct def<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> : enum_type<int> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus> : enum_type<int> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType> : enum_type<int> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus> : enum_type<int> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> : class_type<Platform::Object, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo> : class_type<Platform::Object, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult> : class_type<Platform::Object, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> : class_type<Platform::Object, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager> : class_type<Platform::Object, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager> {};

// uuids

template<> struct uuid<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo> { define_guid(0x5F7EABB4, 0xA278, 0x4635, 0xB7, 0x65, 0xB4, 0x94, 0xEB, 0x26, 0xA, 0xF4);};
template<> struct uuid<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult> { define_guid(0x4E23A9A0, 0xE9FA, 0x497A, 0x95, 0xDE, 0x6D, 0x57, 0x47, 0xBF, 0x97, 0x4C);};
template<> struct uuid<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> { define_guid(0xAA7EC5FB, 0xDA3F, 0x4088, 0xA2, 0xD, 0x56, 0x18, 0xAF, 0xAD, 0xB2, 0xE5);};
template<> struct uuid<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo> { define_guid(0x82BA264B, 0xD87C, 0x4668, 0xA9, 0x76, 0x40, 0xCF, 0xAE, 0x54, 0x7D, 0x8);};
template<> struct uuid<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager> { define_guid(0xFD340A5, 0xF574, 0x4320, 0xA0, 0x8E, 0xA, 0x19, 0xA8, 0x23, 0x22, 0xAA);};
template<> struct uuid<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics> { define_guid(0xD964C2E6, 0xF446, 0x4C71, 0x8B, 0x79, 0x6E, 0xA4, 0x2, 0x4A, 0xA9, 0xB8);};

// types

namespace Windows { namespace Security { namespace Authentication { namespace Identity { namespace Core {

// IMicrosoftAccountMultiFactorSessionInfo
struct IMicrosoftAccountMultiFactorSessionInfo_raw : IInspectable {
	virtual STDMETHODIMP _get_UserAccountId(HSTRING *value);
	virtual STDMETHODIMP _get_SessionId(HSTRING *value);
	virtual STDMETHODIMP _get_DisplaySessionId(HSTRING *value);
	virtual STDMETHODIMP _get_ApprovalStatus(MicrosoftAccountMultiFactorSessionApprovalStatus *value);
	virtual STDMETHODIMP _get_AuthenticationType(MicrosoftAccountMultiFactorAuthenticationType *value);
	virtual STDMETHODIMP _get_RequestTime(Foundation::DateTime *value);
	virtual STDMETHODIMP _get_ExpirationTime(Foundation::DateTime *value);
};
template<typename X> struct IMicrosoftAccountMultiFactorSessionInfo_adaptor : X {
	union {
		struct : property {
			MicrosoftAccountMultiFactorSessionApprovalStatus get() { MicrosoftAccountMultiFactorSessionApprovalStatus value; hrcheck(enc(&IMicrosoftAccountMultiFactorSessionInfo_adaptor::ApprovalStatus)->_get_ApprovalStatus(&value)); return value; }
			MicrosoftAccountMultiFactorSessionApprovalStatus operator()() { return get(); }
			operator MicrosoftAccountMultiFactorSessionApprovalStatus () { return get(); }
		} ApprovalStatus;
		struct : property {
			MicrosoftAccountMultiFactorAuthenticationType get() { MicrosoftAccountMultiFactorAuthenticationType value; hrcheck(enc(&IMicrosoftAccountMultiFactorSessionInfo_adaptor::AuthenticationType)->_get_AuthenticationType(&value)); return value; }
			MicrosoftAccountMultiFactorAuthenticationType operator()() { return get(); }
			operator MicrosoftAccountMultiFactorAuthenticationType () { return get(); }
		} AuthenticationType;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IMicrosoftAccountMultiFactorSessionInfo_adaptor::DisplaySessionId)->_get_DisplaySessionId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DisplaySessionId;
		struct : property {
			Foundation::DateTime get() { Foundation::DateTime value; hrcheck(enc(&IMicrosoftAccountMultiFactorSessionInfo_adaptor::ExpirationTime)->_get_ExpirationTime(&value)); return value; }
			Foundation::DateTime operator()() { return get(); }
			operator Foundation::DateTime () { return get(); }
		} ExpirationTime;
		struct : property {
			Foundation::DateTime get() { Foundation::DateTime value; hrcheck(enc(&IMicrosoftAccountMultiFactorSessionInfo_adaptor::RequestTime)->_get_RequestTime(&value)); return value; }
			Foundation::DateTime operator()() { return get(); }
			operator Foundation::DateTime () { return get(); }
		} RequestTime;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IMicrosoftAccountMultiFactorSessionInfo_adaptor::SessionId)->_get_SessionId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} SessionId;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IMicrosoftAccountMultiFactorSessionInfo_adaptor::UserAccountId)->_get_UserAccountId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} UserAccountId;
	};
	IMicrosoftAccountMultiFactorSessionInfo_adaptor() {}
};
template<typename X> struct adapt<IMicrosoftAccountMultiFactorSessionInfo, X> : Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo_adaptor<X> { typedef adapt IMicrosoftAccountMultiFactorSessionInfo; };
struct IMicrosoftAccountMultiFactorSessionInfo : IMicrosoftAccountMultiFactorSessionInfo_raw, generate<IMicrosoftAccountMultiFactorSessionInfo> {};

// IMicrosoftAccountMultiFactorGetSessionsResult
struct IMicrosoftAccountMultiFactorGetSessionsResult_raw : IInspectable {
	virtual STDMETHODIMP _get_Sessions(Foundation::Collections::IVectorView<MicrosoftAccountMultiFactorSessionInfo*>* *value);
	virtual STDMETHODIMP _get_ServiceResponse(MicrosoftAccountMultiFactorServiceResponse *value);
};
template<typename X> struct IMicrosoftAccountMultiFactorGetSessionsResult_adaptor : X {
	union {
		struct : property {
			MicrosoftAccountMultiFactorServiceResponse get() { MicrosoftAccountMultiFactorServiceResponse value; hrcheck(enc(&IMicrosoftAccountMultiFactorGetSessionsResult_adaptor::ServiceResponse)->_get_ServiceResponse(&value)); return value; }
			MicrosoftAccountMultiFactorServiceResponse operator()() { return get(); }
			operator MicrosoftAccountMultiFactorServiceResponse () { return get(); }
		} ServiceResponse;
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<MicrosoftAccountMultiFactorSessionInfo>>> get() { Foundation::Collections::IVectorView<MicrosoftAccountMultiFactorSessionInfo*>* value; hrcheck(enc(&IMicrosoftAccountMultiFactorGetSessionsResult_adaptor::Sessions)->_get_Sessions(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<MicrosoftAccountMultiFactorSessionInfo>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<MicrosoftAccountMultiFactorSessionInfo>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<MicrosoftAccountMultiFactorSessionInfo>>> operator->() { return get(); }
		} Sessions;
	};
	IMicrosoftAccountMultiFactorGetSessionsResult_adaptor() {}
};
template<typename X> struct adapt<IMicrosoftAccountMultiFactorGetSessionsResult, X> : Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult_adaptor<X> { typedef adapt IMicrosoftAccountMultiFactorGetSessionsResult; };
struct IMicrosoftAccountMultiFactorGetSessionsResult : IMicrosoftAccountMultiFactorGetSessionsResult_raw, generate<IMicrosoftAccountMultiFactorGetSessionsResult> {};

// MicrosoftAccountMultiFactorSessionInfo
template<typename X> struct statics<MicrosoftAccountMultiFactorSessionInfo, X> : X {
	typedef typename X::root_type MicrosoftAccountMultiFactorSessionInfo;
};
struct MicrosoftAccountMultiFactorSessionInfo : generate<MicrosoftAccountMultiFactorSessionInfo> {};

// IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo
struct IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo_raw : IInspectable {
	virtual STDMETHODIMP _get_Sessions(Foundation::Collections::IVectorView<MicrosoftAccountMultiFactorSessionInfo*>* *value);
	virtual STDMETHODIMP _get_UnregisteredAccounts(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _get_ServiceResponse(MicrosoftAccountMultiFactorServiceResponse *value);
};
template<typename X> struct IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo_adaptor : X {
	union {
		struct : property {
			MicrosoftAccountMultiFactorServiceResponse get() { MicrosoftAccountMultiFactorServiceResponse value; hrcheck(enc(&IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo_adaptor::ServiceResponse)->_get_ServiceResponse(&value)); return value; }
			MicrosoftAccountMultiFactorServiceResponse operator()() { return get(); }
			operator MicrosoftAccountMultiFactorServiceResponse () { return get(); }
		} ServiceResponse;
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<MicrosoftAccountMultiFactorSessionInfo>>> get() { Foundation::Collections::IVectorView<MicrosoftAccountMultiFactorSessionInfo*>* value; hrcheck(enc(&IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo_adaptor::Sessions)->_get_Sessions(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<MicrosoftAccountMultiFactorSessionInfo>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<MicrosoftAccountMultiFactorSessionInfo>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<MicrosoftAccountMultiFactorSessionInfo>>> operator->() { return get(); }
		} Sessions;
		struct : property {
			ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(enc(&IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo_adaptor::UnregisteredAccounts)->_get_UnregisteredAccounts(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
		} UnregisteredAccounts;
	};
	IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo_adaptor() {}
};
template<typename X> struct adapt<IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo, X> : Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo_adaptor<X> { typedef adapt IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo; };
struct IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo : IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo_raw, generate<IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> {};

// IMicrosoftAccountMultiFactorOneTimeCodedInfo
struct IMicrosoftAccountMultiFactorOneTimeCodedInfo_raw : IInspectable {
	virtual STDMETHODIMP _get_Code(HSTRING *value);
	virtual STDMETHODIMP _get_TimeInterval(Foundation::TimeSpan *value);
	virtual STDMETHODIMP _get_TimeToLive(Foundation::TimeSpan *value);
	virtual STDMETHODIMP _get_ServiceResponse(MicrosoftAccountMultiFactorServiceResponse *value);
};
template<typename X> struct IMicrosoftAccountMultiFactorOneTimeCodedInfo_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IMicrosoftAccountMultiFactorOneTimeCodedInfo_adaptor::Code)->_get_Code(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Code;
		struct : property {
			MicrosoftAccountMultiFactorServiceResponse get() { MicrosoftAccountMultiFactorServiceResponse value; hrcheck(enc(&IMicrosoftAccountMultiFactorOneTimeCodedInfo_adaptor::ServiceResponse)->_get_ServiceResponse(&value)); return value; }
			MicrosoftAccountMultiFactorServiceResponse operator()() { return get(); }
			operator MicrosoftAccountMultiFactorServiceResponse () { return get(); }
		} ServiceResponse;
		struct : property {
			Foundation::TimeSpan get() { Foundation::TimeSpan value; hrcheck(enc(&IMicrosoftAccountMultiFactorOneTimeCodedInfo_adaptor::TimeInterval)->_get_TimeInterval(&value)); return value; }
			Foundation::TimeSpan operator()() { return get(); }
			operator Foundation::TimeSpan () { return get(); }
		} TimeInterval;
		struct : property {
			Foundation::TimeSpan get() { Foundation::TimeSpan value; hrcheck(enc(&IMicrosoftAccountMultiFactorOneTimeCodedInfo_adaptor::TimeToLive)->_get_TimeToLive(&value)); return value; }
			Foundation::TimeSpan operator()() { return get(); }
			operator Foundation::TimeSpan () { return get(); }
		} TimeToLive;
	};
	IMicrosoftAccountMultiFactorOneTimeCodedInfo_adaptor() {}
};
template<typename X> struct adapt<IMicrosoftAccountMultiFactorOneTimeCodedInfo, X> : Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo_adaptor<X> { typedef adapt IMicrosoftAccountMultiFactorOneTimeCodedInfo; };
struct IMicrosoftAccountMultiFactorOneTimeCodedInfo : IMicrosoftAccountMultiFactorOneTimeCodedInfo_raw, generate<IMicrosoftAccountMultiFactorOneTimeCodedInfo> {};

// IMicrosoftAccountMultiFactorAuthenticationManager
struct IMicrosoftAccountMultiFactorAuthenticationManager_raw : IInspectable {
	virtual STDMETHODIMP _GetOneTimePassCodeAsync(HSTRING userAccountId, unsigned codeLength, Foundation::IAsyncOperation<MicrosoftAccountMultiFactorOneTimeCodedInfo*>* *asyncOperation);
	virtual STDMETHODIMP _AddDeviceAsync(HSTRING userAccountId, HSTRING authenticationToken, HSTRING wnsChannelId, Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* *asyncOperation);
	virtual STDMETHODIMP _RemoveDeviceAsync(HSTRING userAccountId, Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* *asyncOperation);
	virtual STDMETHODIMP _UpdateWnsChannelAsync(HSTRING userAccountId, HSTRING channelUri, Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* *asyncOperation);
	virtual STDMETHODIMP _GetSessionsAsync(Foundation::Collections::IIterable<HSTRING>* userAccountIdList, Foundation::IAsyncOperation<MicrosoftAccountMultiFactorGetSessionsResult*>* *asyncOperation);
	virtual STDMETHODIMP _GetSessionsAndUnregisteredAccountsAsync(Foundation::Collections::IIterable<HSTRING>* userAccountIdList, Foundation::IAsyncOperation<MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo*>* *asyncOperation);
	virtual STDMETHODIMP _ApproveSessionUsingAuthSessionInfoAsync(MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, MicrosoftAccountMultiFactorSessionInfo* authenticationSessionInfo, Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* *asyncOperation);
	virtual STDMETHODIMP _ApproveSessionAsync(MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, HSTRING userAccountId, HSTRING sessionId, MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType, Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* *asyncOperation);
	virtual STDMETHODIMP _DenySessionUsingAuthSessionInfoAsync(MicrosoftAccountMultiFactorSessionInfo* authenticationSessionInfo, Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* *asyncOperation);
	virtual STDMETHODIMP _DenySessionAsync(HSTRING userAccountId, HSTRING sessionId, MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType, Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* *asyncOperation);
};
template<typename X> struct IMicrosoftAccountMultiFactorAuthenticationManager_adaptor : X {
	ptr<Foundation::IAsyncOperation<ptr<MicrosoftAccountMultiFactorOneTimeCodedInfo>>> GetOneTimePassCodeAsync(hstring_ref userAccountId, unsigned codeLength) { Foundation::IAsyncOperation<MicrosoftAccountMultiFactorOneTimeCodedInfo*>* asyncOperation; hrcheck(X::get()->_GetOneTimePassCodeAsync(userAccountId, codeLength, &asyncOperation)); return from_abi(asyncOperation); }
	ptr<Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>> AddDeviceAsync(hstring_ref userAccountId, hstring_ref authenticationToken, hstring_ref wnsChannelId) { Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* asyncOperation; hrcheck(X::get()->_AddDeviceAsync(userAccountId, authenticationToken, wnsChannelId, &asyncOperation)); return from_abi(asyncOperation); }
	ptr<Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>> RemoveDeviceAsync(hstring_ref userAccountId) { Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* asyncOperation; hrcheck(X::get()->_RemoveDeviceAsync(userAccountId, &asyncOperation)); return from_abi(asyncOperation); }
	ptr<Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>> UpdateWnsChannelAsync(hstring_ref userAccountId, hstring_ref channelUri) { Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* asyncOperation; hrcheck(X::get()->_UpdateWnsChannelAsync(userAccountId, channelUri, &asyncOperation)); return from_abi(asyncOperation); }
	ptr<Foundation::IAsyncOperation<ptr<MicrosoftAccountMultiFactorGetSessionsResult>>> GetSessionsAsync(pptr<Foundation::Collections::IIterable<hstring>> userAccountIdList) { Foundation::IAsyncOperation<MicrosoftAccountMultiFactorGetSessionsResult*>* asyncOperation; hrcheck(X::get()->_GetSessionsAsync(to_abi(userAccountIdList), &asyncOperation)); return from_abi(asyncOperation); }
	ptr<Foundation::IAsyncOperation<ptr<MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>>> GetSessionsAndUnregisteredAccountsAsync(pptr<Foundation::Collections::IIterable<hstring>> userAccountIdList) { Foundation::IAsyncOperation<MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo*>* asyncOperation; hrcheck(X::get()->_GetSessionsAndUnregisteredAccountsAsync(to_abi(userAccountIdList), &asyncOperation)); return from_abi(asyncOperation); }
	ptr<Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>> ApproveSessionAsync(MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, pptr<MicrosoftAccountMultiFactorSessionInfo> authenticationSessionInfo) { Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* asyncOperation; hrcheck(X::get()->_ApproveSessionUsingAuthSessionInfoAsync(sessionAuthentictionStatus, authenticationSessionInfo, &asyncOperation)); return from_abi(asyncOperation); }
	ptr<Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>> ApproveSessionAsync(MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, hstring_ref userAccountId, hstring_ref sessionId, MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType) { Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* asyncOperation; hrcheck(X::get()->_ApproveSessionAsync(sessionAuthentictionStatus, userAccountId, sessionId, sessionAuthenticationType, &asyncOperation)); return from_abi(asyncOperation); }
	ptr<Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>> DenySessionAsync(pptr<MicrosoftAccountMultiFactorSessionInfo> authenticationSessionInfo) { Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* asyncOperation; hrcheck(X::get()->_DenySessionUsingAuthSessionInfoAsync(authenticationSessionInfo, &asyncOperation)); return from_abi(asyncOperation); }
	ptr<Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>> DenySessionAsync(hstring_ref userAccountId, hstring_ref sessionId, MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType) { Foundation::IAsyncOperation<MicrosoftAccountMultiFactorServiceResponse>* asyncOperation; hrcheck(X::get()->_DenySessionAsync(userAccountId, sessionId, sessionAuthenticationType, &asyncOperation)); return from_abi(asyncOperation); }
};
template<typename X> struct adapt<IMicrosoftAccountMultiFactorAuthenticationManager, X> : Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager_adaptor<X> { typedef adapt IMicrosoftAccountMultiFactorAuthenticationManager; };
struct IMicrosoftAccountMultiFactorAuthenticationManager : IMicrosoftAccountMultiFactorAuthenticationManager_raw, generate<IMicrosoftAccountMultiFactorAuthenticationManager> {};

// MicrosoftAccountMultiFactorOneTimeCodedInfo
template<typename X> struct statics<MicrosoftAccountMultiFactorOneTimeCodedInfo, X> : X {
	typedef typename X::root_type MicrosoftAccountMultiFactorOneTimeCodedInfo;
};
struct MicrosoftAccountMultiFactorOneTimeCodedInfo : generate<MicrosoftAccountMultiFactorOneTimeCodedInfo> {};

// MicrosoftAccountMultiFactorGetSessionsResult
template<typename X> struct statics<MicrosoftAccountMultiFactorGetSessionsResult, X> : X {
	typedef typename X::root_type MicrosoftAccountMultiFactorGetSessionsResult;
};
struct MicrosoftAccountMultiFactorGetSessionsResult : generate<MicrosoftAccountMultiFactorGetSessionsResult> {};

// MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo
template<typename X> struct statics<MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo, X> : X {
	typedef typename X::root_type MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo;
};
struct MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo : generate<MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> {};

// IMicrosoftAccountMultiFactorAuthenticatorStatics
struct IMicrosoftAccountMultiFactorAuthenticatorStatics : IInspectable {
	virtual STDMETHODIMP _get_Current(MicrosoftAccountMultiFactorAuthenticationManager* *value);
};

// MicrosoftAccountMultiFactorAuthenticationManager
template<typename> struct MicrosoftAccountMultiFactorAuthenticationManager_statics {
	static struct _Current : property {
		ptr<MicrosoftAccountMultiFactorAuthenticationManager> get() { MicrosoftAccountMultiFactorAuthenticationManager* value; hrcheck(get_activation_factory<MicrosoftAccountMultiFactorAuthenticationManager, IMicrosoftAccountMultiFactorAuthenticatorStatics>()->_get_Current(&value)); return from_abi(value); }
		ptr<MicrosoftAccountMultiFactorAuthenticationManager> operator()() { return get(); }
		operator ptr<MicrosoftAccountMultiFactorAuthenticationManager> () { return get(); }
		ptr<MicrosoftAccountMultiFactorAuthenticationManager> operator->() { return get(); }
	} Current;
};
template<typename X> typename MicrosoftAccountMultiFactorAuthenticationManager_statics<X>::_Current MicrosoftAccountMultiFactorAuthenticationManager_statics<X>::Current;

template<typename X> struct statics<MicrosoftAccountMultiFactorAuthenticationManager, X> : X, Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager_statics<void> {
	typedef typename X::root_type MicrosoftAccountMultiFactorAuthenticationManager;
};
struct MicrosoftAccountMultiFactorAuthenticationManager : generate<MicrosoftAccountMultiFactorAuthenticationManager> {
	using IMicrosoftAccountMultiFactorAuthenticationManager::DenySessionAsync;
	using IMicrosoftAccountMultiFactorAuthenticationManager::ApproveSessionAsync;
};
}}}}}
} // namespace iso_winrt
