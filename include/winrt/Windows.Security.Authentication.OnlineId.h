#pragma once
// generated by isopod tools
// namespaces:
// Windows.Security.Authentication.OnlineId

#include "Windows.Security.Authentication.OnlineId.0.h"
#include "Windows.Foundation.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
template<typename T> struct IIterable;
}}
namespace System {
struct User;
}}

// defs

template<> struct def<Windows::Security::Authentication::OnlineId::CredentialPromptType> : enum_type<int> {};
template<> struct def<Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest> : class_type<Platform::Object, Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest>, custom_activators {};
template<> struct def<Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicket> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::OnlineId::IUserIdentity> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::OnlineId::OnlineIdServiceTicket> : class_type<Platform::Object, Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicket> {};
template<> struct def<Windows::Security::Authentication::OnlineId::IOnlineIdAuthenticator> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::OnlineId::UserIdentity> : class_type<Platform::Object, Windows::Security::Authentication::OnlineId::IUserIdentity> {};
template<> struct def<Windows::Security::Authentication::OnlineId::UserAuthenticationOperation> : class_type<Platform::Object, Windows::Foundation::IAsyncOperation<ptr<Windows::Security::Authentication::OnlineId::UserIdentity>>, Windows::Foundation::IAsyncInfo> {};
template<> struct def<Windows::Security::Authentication::OnlineId::SignOutUserOperation> : class_type<Platform::Object, Windows::Foundation::IAsyncAction, Windows::Foundation::IAsyncInfo> {};
template<> struct def<Windows::Security::Authentication::OnlineId::OnlineIdAuthenticator> : class_type<Platform::Object, Windows::Security::Authentication::OnlineId::IOnlineIdAuthenticator> {};
template<> struct def<Windows::Security::Authentication::OnlineId::OnlineIdSystemTicketStatus> : enum_type<int> {};
template<> struct def<Windows::Security::Authentication::OnlineId::IOnlineIdSystemIdentity> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::OnlineId::OnlineIdSystemIdentity> : class_type<Platform::Object, Windows::Security::Authentication::OnlineId::IOnlineIdSystemIdentity> {};
template<> struct def<Windows::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::OnlineId::OnlineIdSystemTicketResult> : class_type<Platform::Object, Windows::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult> {};
template<> struct def<Windows::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics> : interface_type<> {};
template<> struct def<Windows::Security::Authentication::OnlineId::OnlineIdSystemAuthenticatorForUser> : class_type<Platform::Object, Windows::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser> {};
template<> struct def<Windows::Security::Authentication::OnlineId::OnlineIdSystemAuthenticator> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest> { define_guid(0x297445D3, 0xFB63, 0x4135, 0x89, 0x9, 0x4E, 0x35, 0x4C, 0x6, 0x14, 0x66);};
template<> struct uuid<Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory> { define_guid(0xBEBB0A08, 0x9E73, 0x4077, 0x96, 0x14, 0x8, 0x61, 0x4C, 0xB, 0xC2, 0x45);};
template<> struct uuid<Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicket> { define_guid(0xC95C547F, 0xD781, 0x4A94, 0xAC, 0xB8, 0xC5, 0x98, 0x74, 0x23, 0x8C, 0x26);};
template<> struct uuid<Windows::Security::Authentication::OnlineId::IUserIdentity> { define_guid(0x2146D9CD, 0x742, 0x4BE3, 0x8A, 0x1C, 0x7C, 0x7A, 0xE6, 0x79, 0xAA, 0x88);};
template<> struct uuid<Windows::Security::Authentication::OnlineId::IOnlineIdAuthenticator> { define_guid(0xA003F58A, 0x29AB, 0x4817, 0xB8, 0x84, 0xD7, 0x51, 0x6D, 0xAD, 0x18, 0xB9);};
template<> struct uuid<Windows::Security::Authentication::OnlineId::IOnlineIdSystemIdentity> { define_guid(0x743CD20D, 0xB6CA, 0x434D, 0x81, 0x24, 0x53, 0xEA, 0x12, 0x68, 0x53, 0x7);};
template<> struct uuid<Windows::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult> { define_guid(0xDB0A5FF8, 0xB098, 0x4ACD, 0x9D, 0x13, 0x9E, 0x64, 0x6, 0x52, 0xB5, 0xB6);};
template<> struct uuid<Windows::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser> { define_guid(0x5798BEFB, 0x1DE4, 0x4186, 0xA2, 0xE6, 0xB5, 0x63, 0xF8, 0x6A, 0xAF, 0x44);};
template<> struct uuid<Windows::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorStatics> { define_guid(0x85047792, 0xF634, 0x41E3, 0x96, 0xA4, 0x51, 0x64, 0xE9, 0x2, 0xC7, 0x40);};

// types

namespace Windows { namespace Security { namespace Authentication { namespace OnlineId {

// IOnlineIdServiceTicketRequest
struct IOnlineIdServiceTicketRequest_raw : IInspectable {
	virtual STDMETHODIMP _get_Service(HSTRING *value);
	virtual STDMETHODIMP _get_Policy(HSTRING *value);
};
template<typename X> struct IOnlineIdServiceTicketRequest_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IOnlineIdServiceTicketRequest_adaptor::Policy)->_get_Policy(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Policy;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IOnlineIdServiceTicketRequest_adaptor::Service)->_get_Service(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Service;
	};
	IOnlineIdServiceTicketRequest_adaptor() {}
};
template<typename X> struct adapt<IOnlineIdServiceTicketRequest, X> : Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest_adaptor<X> { typedef adapt IOnlineIdServiceTicketRequest; };
struct IOnlineIdServiceTicketRequest : IOnlineIdServiceTicketRequest_raw, generate<IOnlineIdServiceTicketRequest> {};

// IOnlineIdServiceTicketRequestFactory
struct IOnlineIdServiceTicketRequestFactory : IInspectable {
	virtual STDMETHODIMP _CreateOnlineIdServiceTicketRequest(HSTRING service, HSTRING policy, OnlineIdServiceTicketRequest* *onlineIdServiceTicketRequest);
	virtual STDMETHODIMP _CreateOnlineIdServiceTicketRequestAdvanced(HSTRING service, OnlineIdServiceTicketRequest* *onlineIdServiceTicketRequest);
};

// OnlineIdServiceTicketRequest
template<typename> struct OnlineIdServiceTicketRequest_statics {
	static OnlineIdServiceTicketRequest *activate(hstring_ref service, hstring_ref policy) { OnlineIdServiceTicketRequest *onlineIdServiceTicketRequest; hrcheck(get_activation_factory<OnlineIdServiceTicketRequest, IOnlineIdServiceTicketRequestFactory>()->_CreateOnlineIdServiceTicketRequest(service, policy, &onlineIdServiceTicketRequest)); return onlineIdServiceTicketRequest; }
	static OnlineIdServiceTicketRequest *activate(hstring_ref service) { OnlineIdServiceTicketRequest *onlineIdServiceTicketRequest; hrcheck(get_activation_factory<OnlineIdServiceTicketRequest, IOnlineIdServiceTicketRequestFactory>()->_CreateOnlineIdServiceTicketRequestAdvanced(service, &onlineIdServiceTicketRequest)); return onlineIdServiceTicketRequest; }
};

template<typename X> struct statics<OnlineIdServiceTicketRequest, X> : X, Windows::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest_statics<void> {
	using Windows::Security::Authentication::OnlineId::OnlineIdServiceTicketRequest_statics<void>::activate;
	typedef typename X::root_type OnlineIdServiceTicketRequest;
};
struct OnlineIdServiceTicketRequest : generate<OnlineIdServiceTicketRequest> {};

// IOnlineIdServiceTicket
struct IOnlineIdServiceTicket_raw : IInspectable {
	virtual STDMETHODIMP _get_Value(HSTRING *value);
	virtual STDMETHODIMP _get_Request(OnlineIdServiceTicketRequest* *value);
	virtual STDMETHODIMP _get_ErrorCode(int *value);
};
template<typename X> struct IOnlineIdServiceTicket_adaptor : X {
	union {
		struct : property {
			int get() { int value; hrcheck(enc(&IOnlineIdServiceTicket_adaptor::ErrorCode)->_get_ErrorCode(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} ErrorCode;
		struct : property {
			ptr<OnlineIdServiceTicketRequest> get() { OnlineIdServiceTicketRequest* value; hrcheck(enc(&IOnlineIdServiceTicket_adaptor::Request)->_get_Request(&value)); return from_abi(value); }
			ptr<OnlineIdServiceTicketRequest> operator()() { return get(); }
			operator ptr<OnlineIdServiceTicketRequest> () { return get(); }
			ptr<OnlineIdServiceTicketRequest> operator->() { return get(); }
		} Request;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IOnlineIdServiceTicket_adaptor::Value)->_get_Value(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Value;
	};
	IOnlineIdServiceTicket_adaptor() {}
};
template<typename X> struct adapt<IOnlineIdServiceTicket, X> : Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicket_adaptor<X> { typedef adapt IOnlineIdServiceTicket; };
struct IOnlineIdServiceTicket : IOnlineIdServiceTicket_raw, generate<IOnlineIdServiceTicket> {};

// IUserIdentity
struct IUserIdentity_raw : IInspectable {
	virtual STDMETHODIMP _get_Tickets(Foundation::Collections::IVectorView<OnlineIdServiceTicket*>* *value);
	virtual STDMETHODIMP _get_Id(HSTRING *value);
	virtual STDMETHODIMP _get_SafeCustomerId(HSTRING *value);
	virtual STDMETHODIMP _get_SignInName(HSTRING *value);
	virtual STDMETHODIMP _get_FirstName(HSTRING *value);
	virtual STDMETHODIMP _get_LastName(HSTRING *value);
	virtual STDMETHODIMP _get_IsBetaAccount(bool *value);
	virtual STDMETHODIMP _get_IsConfirmedPC(bool *value);
};
template<typename X> struct IUserIdentity_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserIdentity_adaptor::FirstName)->_get_FirstName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} FirstName;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserIdentity_adaptor::Id)->_get_Id(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Id;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IUserIdentity_adaptor::IsBetaAccount)->_get_IsBetaAccount(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsBetaAccount;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IUserIdentity_adaptor::IsConfirmedPC)->_get_IsConfirmedPC(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsConfirmedPC;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserIdentity_adaptor::LastName)->_get_LastName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} LastName;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserIdentity_adaptor::SafeCustomerId)->_get_SafeCustomerId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} SafeCustomerId;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserIdentity_adaptor::SignInName)->_get_SignInName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} SignInName;
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<OnlineIdServiceTicket>>> get() { Foundation::Collections::IVectorView<OnlineIdServiceTicket*>* value; hrcheck(enc(&IUserIdentity_adaptor::Tickets)->_get_Tickets(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<OnlineIdServiceTicket>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<OnlineIdServiceTicket>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<OnlineIdServiceTicket>>> operator->() { return get(); }
		} Tickets;
	};
	IUserIdentity_adaptor() {}
};
template<typename X> struct adapt<IUserIdentity, X> : Windows::Security::Authentication::OnlineId::IUserIdentity_adaptor<X> { typedef adapt IUserIdentity; };
struct IUserIdentity : IUserIdentity_raw, generate<IUserIdentity> {};

// OnlineIdServiceTicket
template<typename X> struct statics<OnlineIdServiceTicket, X> : X {
	typedef typename X::root_type OnlineIdServiceTicket;
};
struct OnlineIdServiceTicket : generate<OnlineIdServiceTicket> {};

// IOnlineIdAuthenticator
struct IOnlineIdAuthenticator_raw : IInspectable {
	virtual STDMETHODIMP _AuthenticateUserAsync(OnlineIdServiceTicketRequest* request, UserAuthenticationOperation* *authenticationOperation);
	virtual STDMETHODIMP _AuthenticateUserAsyncAdvanced(Foundation::Collections::IIterable<OnlineIdServiceTicketRequest*>* requests, CredentialPromptType credentialPromptType, UserAuthenticationOperation* *authenticationOperation);
	virtual STDMETHODIMP _SignOutUserAsync(SignOutUserOperation* *signOutUserOperation);
	virtual STDMETHODIMP _put_ApplicationId(Platform::Guid value);
	virtual STDMETHODIMP _get_ApplicationId(Platform::Guid *value);
	virtual STDMETHODIMP _get_CanSignOut(bool *value);
	virtual STDMETHODIMP _get_AuthenticatedSafeCustomerId(HSTRING *value);
};
template<typename X> struct IOnlineIdAuthenticator_adaptor : X {
	union {
		struct : property {
			Platform::Guid get() { Platform::Guid value; hrcheck(enc(&IOnlineIdAuthenticator_adaptor::ApplicationId)->_get_ApplicationId(&value)); return value; }
			Platform::Guid operator()() { return get(); }
			operator Platform::Guid () { return get(); }
			void put(const Platform::Guid& value) { hrcheck(enc(&IOnlineIdAuthenticator_adaptor::ApplicationId)->_put_ApplicationId(value)); }
			void operator=(const Platform::Guid& value) { put(value); }
			void operator()(const Platform::Guid& value) { put(value); }
		} ApplicationId;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IOnlineIdAuthenticator_adaptor::AuthenticatedSafeCustomerId)->_get_AuthenticatedSafeCustomerId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} AuthenticatedSafeCustomerId;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IOnlineIdAuthenticator_adaptor::CanSignOut)->_get_CanSignOut(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} CanSignOut;
	};
	ptr<UserAuthenticationOperation> AuthenticateUserAsync(pptr<OnlineIdServiceTicketRequest> request) { UserAuthenticationOperation* authenticationOperation; hrcheck(X::get()->_AuthenticateUserAsync(request, &authenticationOperation)); return from_abi(authenticationOperation); }
	ptr<UserAuthenticationOperation> AuthenticateUserAsync(pptr<Foundation::Collections::IIterable<ptr<OnlineIdServiceTicketRequest>>> requests, CredentialPromptType credentialPromptType) { UserAuthenticationOperation* authenticationOperation; hrcheck(X::get()->_AuthenticateUserAsyncAdvanced(to_abi(requests), credentialPromptType, &authenticationOperation)); return from_abi(authenticationOperation); }
	ptr<SignOutUserOperation> SignOutUserAsync() { SignOutUserOperation* signOutUserOperation; hrcheck(X::get()->_SignOutUserAsync(&signOutUserOperation)); return from_abi(signOutUserOperation); }
	IOnlineIdAuthenticator_adaptor() {}
};
template<typename X> struct adapt<IOnlineIdAuthenticator, X> : Windows::Security::Authentication::OnlineId::IOnlineIdAuthenticator_adaptor<X> { typedef adapt IOnlineIdAuthenticator; };
struct IOnlineIdAuthenticator : IOnlineIdAuthenticator_raw, generate<IOnlineIdAuthenticator> {};

// UserIdentity
template<typename X> struct statics<UserIdentity, X> : X {
	typedef typename X::root_type UserIdentity;
};
struct UserIdentity : generate<UserIdentity> {};

// UserAuthenticationOperation
template<typename X> struct statics<UserAuthenticationOperation, X> : X {
	typedef typename X::root_type UserAuthenticationOperation;
};
struct UserAuthenticationOperation : generate<UserAuthenticationOperation> {};

// SignOutUserOperation
template<typename X> struct statics<SignOutUserOperation, X> : X {
	typedef typename X::root_type SignOutUserOperation;
};
struct SignOutUserOperation : generate<SignOutUserOperation> {};

// OnlineIdAuthenticator
template<typename X> struct statics<OnlineIdAuthenticator, X> : X {
	typedef typename X::root_type OnlineIdAuthenticator;
};
struct OnlineIdAuthenticator : generate<OnlineIdAuthenticator> {
	using IOnlineIdAuthenticator::AuthenticateUserAsync;
};

// IOnlineIdSystemIdentity
struct IOnlineIdSystemIdentity_raw : IInspectable {
	virtual STDMETHODIMP _get_Ticket(OnlineIdServiceTicket* *value);
	virtual STDMETHODIMP _get_Id(HSTRING *value);
};
template<typename X> struct IOnlineIdSystemIdentity_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IOnlineIdSystemIdentity_adaptor::Id)->_get_Id(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Id;
		struct : property {
			ptr<OnlineIdServiceTicket> get() { OnlineIdServiceTicket* value; hrcheck(enc(&IOnlineIdSystemIdentity_adaptor::Ticket)->_get_Ticket(&value)); return from_abi(value); }
			ptr<OnlineIdServiceTicket> operator()() { return get(); }
			operator ptr<OnlineIdServiceTicket> () { return get(); }
			ptr<OnlineIdServiceTicket> operator->() { return get(); }
		} Ticket;
	};
	IOnlineIdSystemIdentity_adaptor() {}
};
template<typename X> struct adapt<IOnlineIdSystemIdentity, X> : Windows::Security::Authentication::OnlineId::IOnlineIdSystemIdentity_adaptor<X> { typedef adapt IOnlineIdSystemIdentity; };
struct IOnlineIdSystemIdentity : IOnlineIdSystemIdentity_raw, generate<IOnlineIdSystemIdentity> {};

// IOnlineIdSystemTicketResult
struct IOnlineIdSystemTicketResult_raw : IInspectable {
	virtual STDMETHODIMP _get_Identity(OnlineIdSystemIdentity* *value);
	virtual STDMETHODIMP _get_Status(OnlineIdSystemTicketStatus *value);
	virtual STDMETHODIMP _get_ExtendedError(Foundation::HResult *value);
};
template<typename X> struct IOnlineIdSystemTicketResult_adaptor : X {
	union {
		struct : property {
			Foundation::HResult get() { Foundation::HResult value; hrcheck(enc(&IOnlineIdSystemTicketResult_adaptor::ExtendedError)->_get_ExtendedError(&value)); return value; }
			Foundation::HResult operator()() { return get(); }
			operator Foundation::HResult () { return get(); }
		} ExtendedError;
		struct : property {
			ptr<OnlineIdSystemIdentity> get() { OnlineIdSystemIdentity* value; hrcheck(enc(&IOnlineIdSystemTicketResult_adaptor::Identity)->_get_Identity(&value)); return from_abi(value); }
			ptr<OnlineIdSystemIdentity> operator()() { return get(); }
			operator ptr<OnlineIdSystemIdentity> () { return get(); }
			ptr<OnlineIdSystemIdentity> operator->() { return get(); }
		} Identity;
		struct : property {
			OnlineIdSystemTicketStatus get() { OnlineIdSystemTicketStatus value; hrcheck(enc(&IOnlineIdSystemTicketResult_adaptor::Status)->_get_Status(&value)); return value; }
			OnlineIdSystemTicketStatus operator()() { return get(); }
			operator OnlineIdSystemTicketStatus () { return get(); }
		} Status;
	};
	IOnlineIdSystemTicketResult_adaptor() {}
};
template<typename X> struct adapt<IOnlineIdSystemTicketResult, X> : Windows::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult_adaptor<X> { typedef adapt IOnlineIdSystemTicketResult; };
struct IOnlineIdSystemTicketResult : IOnlineIdSystemTicketResult_raw, generate<IOnlineIdSystemTicketResult> {};

// OnlineIdSystemIdentity
template<typename X> struct statics<OnlineIdSystemIdentity, X> : X {
	typedef typename X::root_type OnlineIdSystemIdentity;
};
struct OnlineIdSystemIdentity : generate<OnlineIdSystemIdentity> {};

// IOnlineIdSystemAuthenticatorForUser
struct IOnlineIdSystemAuthenticatorForUser_raw : IInspectable {
	virtual STDMETHODIMP _GetTicketAsync(OnlineIdServiceTicketRequest* request, Foundation::IAsyncOperation<OnlineIdSystemTicketResult*>* *operation);
	virtual STDMETHODIMP _put_ApplicationId(Platform::Guid value);
	virtual STDMETHODIMP _get_ApplicationId(Platform::Guid *value);
	virtual STDMETHODIMP _get_User(System::User* *user);
};
template<typename X> struct IOnlineIdSystemAuthenticatorForUser_adaptor : X {
	union {
		struct : property {
			Platform::Guid get() { Platform::Guid value; hrcheck(enc(&IOnlineIdSystemAuthenticatorForUser_adaptor::ApplicationId)->_get_ApplicationId(&value)); return value; }
			Platform::Guid operator()() { return get(); }
			operator Platform::Guid () { return get(); }
			void put(const Platform::Guid& value) { hrcheck(enc(&IOnlineIdSystemAuthenticatorForUser_adaptor::ApplicationId)->_put_ApplicationId(value)); }
			void operator=(const Platform::Guid& value) { put(value); }
			void operator()(const Platform::Guid& value) { put(value); }
		} ApplicationId;
		struct : property {
			ptr<System::User> get() { System::User* user; hrcheck(enc(&IOnlineIdSystemAuthenticatorForUser_adaptor::User)->_get_User(&user)); return from_abi(user); }
			ptr<System::User> operator()() { return get(); }
			operator ptr<System::User> () { return get(); }
			ptr<System::User> operator->() { return get(); }
		} User;
	};
	ptr<Foundation::IAsyncOperation<ptr<OnlineIdSystemTicketResult>>> GetTicketAsync(pptr<OnlineIdServiceTicketRequest> request) { Foundation::IAsyncOperation<OnlineIdSystemTicketResult*>* operation; hrcheck(X::get()->_GetTicketAsync(request, &operation)); return from_abi(operation); }
	IOnlineIdSystemAuthenticatorForUser_adaptor() {}
};
template<typename X> struct adapt<IOnlineIdSystemAuthenticatorForUser, X> : Windows::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser_adaptor<X> { typedef adapt IOnlineIdSystemAuthenticatorForUser; };
struct IOnlineIdSystemAuthenticatorForUser : IOnlineIdSystemAuthenticatorForUser_raw, generate<IOnlineIdSystemAuthenticatorForUser> {};

// OnlineIdSystemTicketResult
template<typename X> struct statics<OnlineIdSystemTicketResult, X> : X {
	typedef typename X::root_type OnlineIdSystemTicketResult;
};
struct OnlineIdSystemTicketResult : generate<OnlineIdSystemTicketResult> {};

// IOnlineIdSystemAuthenticatorStatics
struct IOnlineIdSystemAuthenticatorStatics : IInspectable {
	virtual STDMETHODIMP _get_Default(OnlineIdSystemAuthenticatorForUser* *value);
	virtual STDMETHODIMP _GetForUser(System::User* user, OnlineIdSystemAuthenticatorForUser* *value);
};

// OnlineIdSystemAuthenticatorForUser
template<typename X> struct statics<OnlineIdSystemAuthenticatorForUser, X> : X {
	typedef typename X::root_type OnlineIdSystemAuthenticatorForUser;
};
struct OnlineIdSystemAuthenticatorForUser : generate<OnlineIdSystemAuthenticatorForUser> {};

// OnlineIdSystemAuthenticator
template<typename> struct OnlineIdSystemAuthenticator_statics {
	static struct _Default : property {
		ptr<OnlineIdSystemAuthenticatorForUser> get() { OnlineIdSystemAuthenticatorForUser* value; hrcheck(get_activation_factory<OnlineIdSystemAuthenticator, IOnlineIdSystemAuthenticatorStatics>()->_get_Default(&value)); return from_abi(value); }
		ptr<OnlineIdSystemAuthenticatorForUser> operator()() { return get(); }
		operator ptr<OnlineIdSystemAuthenticatorForUser> () { return get(); }
		ptr<OnlineIdSystemAuthenticatorForUser> operator->() { return get(); }
	} Default;
	static ptr<OnlineIdSystemAuthenticatorForUser> GetForUser(pptr<System::User> user) { OnlineIdSystemAuthenticatorForUser* value; hrcheck(get_activation_factory<OnlineIdSystemAuthenticator, IOnlineIdSystemAuthenticatorStatics>()->_GetForUser(user, &value)); return from_abi(value); }
};
template<typename X> typename OnlineIdSystemAuthenticator_statics<X>::_Default OnlineIdSystemAuthenticator_statics<X>::Default;

template<typename X> struct statics<OnlineIdSystemAuthenticator, X> : X, Windows::Security::Authentication::OnlineId::OnlineIdSystemAuthenticator_statics<void> {
	typedef typename X::root_type OnlineIdSystemAuthenticator;
};
struct OnlineIdSystemAuthenticator : generate<OnlineIdSystemAuthenticator> {};
}}}}
} // namespace iso_winrt