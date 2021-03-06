#pragma once
// generated by isopod tools
// namespaces:
// Windows.Security.Credentials

#include "Windows.Security.Credentials.0.h"
#include "Windows.Security.Cryptography.Core.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Storage { namespace Streams {
struct IRandomAccessStream;
struct IBuffer;
}}
namespace System {
struct User;
}}

// defs

template<> struct def<Windows::Security::Credentials::KeyCredentialStatus> : enum_type<int> {};
template<> struct def<Windows::Security::Credentials::KeyCredentialAttestationStatus> : enum_type<int> {};
template<> struct def<Windows::Security::Credentials::KeyCredentialCreationOption> : enum_type<int> {};
template<> struct def<Windows::Security::Credentials::IKeyCredentialManagerStatics> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::IKeyCredentialRetrievalResult> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::KeyCredentialRetrievalResult> : class_type<Platform::Object, Windows::Security::Credentials::IKeyCredentialRetrievalResult> {};
template<> struct def<Windows::Security::Credentials::IKeyCredential> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::IKeyCredentialOperationResult> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::KeyCredentialOperationResult> : class_type<Platform::Object, Windows::Security::Credentials::IKeyCredentialOperationResult> {};
template<> struct def<Windows::Security::Credentials::IKeyCredentialAttestationResult> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::KeyCredentialAttestationResult> : class_type<Platform::Object, Windows::Security::Credentials::IKeyCredentialAttestationResult> {};
template<> struct def<Windows::Security::Credentials::KeyCredential> : class_type<Platform::Object, Windows::Security::Credentials::IKeyCredential> {};
template<> struct def<Windows::Security::Credentials::KeyCredentialManager> : class_type<Platform::Object, Platform::Object> {};
template<> struct def<Windows::Security::Credentials::WebAccountState> : enum_type<int> {};
template<> struct def<Windows::Security::Credentials::WebAccountPictureSize> : enum_type<int> {};
template<> struct def<Windows::Security::Credentials::IWebAccountFactory> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::IWebAccountProviderFactory> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::IWebAccountProvider4> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::IWebAccountProvider> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::IWebAccountProvider2> : interface_type<Windows::Security::Credentials::IWebAccountProvider> {};
template<> struct def<Windows::Security::Credentials::IWebAccountProvider3> : interface_type<Windows::Security::Credentials::IWebAccountProvider2> {};
template<> struct def<Windows::Security::Credentials::WebAccountProvider> : class_type<Platform::Object, Windows::Security::Credentials::IWebAccountProvider, Windows::Security::Credentials::IWebAccountProvider4, Windows::Security::Credentials::IWebAccountProvider3>, custom_activators {};
template<> struct def<Windows::Security::Credentials::IWebAccount> : overridable_type<> {};
template<> struct def<Windows::Security::Credentials::IWebAccount2> : interface_type<Windows::Security::Credentials::IWebAccount> {};
template<> struct def<Windows::Security::Credentials::WebAccount> : class_type<Platform::Object, Windows::Security::Credentials::IWebAccount, Windows::Security::Credentials::IWebAccount2>, custom_activators {};
template<> struct def<Windows::Security::Credentials::IPasswordCredential> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::ICredentialFactory> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::PasswordCredential> : class_type<Platform::Object, Windows::Security::Credentials::IPasswordCredential>, custom_activators {};
template<> struct def<Windows::Security::Credentials::IPasswordVault> : interface_type<> {};
template<> struct def<Windows::Security::Credentials::PasswordVault> : class_type<Platform::Object, Windows::Security::Credentials::IPasswordVault> {};
template<> struct def<Windows::Security::Credentials::PasswordCredentialPropertyStore> : class_type<Platform::Object, Windows::Foundation::Collections::IPropertySet, Windows::Foundation::Collections::IObservableMap<HSTRING, object>, Windows::Foundation::Collections::IMap<HSTRING, object>, Windows::Foundation::Collections::IIterable<ptr<Windows::Foundation::Collections::IKeyValuePair<HSTRING, object>>>> {};

// uuids

template<> struct uuid<Windows::Security::Credentials::IKeyCredentialManagerStatics> { define_guid(0x6AAC468B, 0xEF1, 0x4CE0, 0x82, 0x90, 0x41, 0x6, 0xDA, 0x6A, 0x63, 0xB5);};
template<> struct uuid<Windows::Security::Credentials::IKeyCredentialRetrievalResult> { define_guid(0x58CD7703, 0x8D87, 0x4249, 0x9B, 0x58, 0xF6, 0x59, 0x8C, 0xC9, 0x64, 0x4E);};
template<> struct uuid<Windows::Security::Credentials::IKeyCredential> { define_guid(0x9585EF8D, 0x457B, 0x4847, 0xB1, 0x1A, 0xFA, 0x96, 0xB, 0xBD, 0xB1, 0x38);};
template<> struct uuid<Windows::Security::Credentials::IKeyCredentialOperationResult> { define_guid(0xF53786C1, 0x5261, 0x4CDD, 0x97, 0x6D, 0xCC, 0x90, 0x9A, 0xC7, 0x16, 0x20);};
template<> struct uuid<Windows::Security::Credentials::IKeyCredentialAttestationResult> { define_guid(0x78AAB3A1, 0xA3C1, 0x4103, 0xB6, 0xCC, 0x47, 0x2C, 0x44, 0x17, 0x1C, 0xBB);};
template<> struct uuid<Windows::Security::Credentials::IWebAccountFactory> { define_guid(0xAC9AFB39, 0x1DE9, 0x4E92, 0xB7, 0x8F, 0x5, 0x81, 0xA8, 0x7F, 0x6E, 0x5C);};
template<> struct uuid<Windows::Security::Credentials::IWebAccountProviderFactory> { define_guid(0x1D767DF1, 0xE1E1, 0x4B9A, 0xA7, 0x74, 0x5C, 0x7C, 0x7E, 0x3B, 0xF3, 0x71);};
template<> struct uuid<Windows::Security::Credentials::IWebAccountProvider4> { define_guid(0x718FD8DB, 0xE796, 0x4210, 0xB7, 0x4E, 0x84, 0xD2, 0x98, 0x94, 0xB0, 0x80);};
template<> struct uuid<Windows::Security::Credentials::IWebAccountProvider> { define_guid(0x29DCC8C3, 0x7AB9, 0x4A7C, 0xA3, 0x36, 0xB9, 0x42, 0xF9, 0xDB, 0xF7, 0xC7);};
template<> struct uuid<Windows::Security::Credentials::IWebAccountProvider2> { define_guid(0x4A01EB05, 0x4E42, 0x41D4, 0xB5, 0x18, 0xE0, 0x8, 0xA5, 0x16, 0x36, 0x14);};
template<> struct uuid<Windows::Security::Credentials::IWebAccountProvider3> { define_guid(0xDA1C518B, 0x970D, 0x4D49, 0x82, 0x5C, 0xF2, 0x70, 0x6F, 0x8C, 0xA7, 0xFE);};
template<> struct uuid<Windows::Security::Credentials::IWebAccount> { define_guid(0x69473EB2, 0x8031, 0x49BE, 0x80, 0xBB, 0x96, 0xCB, 0x46, 0xD9, 0x9A, 0xBA);};
template<> struct uuid<Windows::Security::Credentials::IWebAccount2> { define_guid(0x7B56D6F8, 0x990B, 0x4EB5, 0x94, 0xA7, 0x56, 0x21, 0xF3, 0xA8, 0xB8, 0x24);};
template<> struct uuid<Windows::Security::Credentials::IPasswordCredential> { define_guid(0x6AB18989, 0xC720, 0x41A7, 0xA6, 0xC1, 0xFE, 0xAD, 0xB3, 0x63, 0x29, 0xA0);};
template<> struct uuid<Windows::Security::Credentials::ICredentialFactory> { define_guid(0x54EF13A1, 0xBF26, 0x47B5, 0x97, 0xDD, 0xDE, 0x77, 0x9B, 0x7C, 0xAD, 0x58);};
template<> struct uuid<Windows::Security::Credentials::IPasswordVault> { define_guid(0x61FD2C0B, 0xC8D4, 0x48C1, 0xA5, 0x4F, 0xBC, 0x5A, 0x64, 0x20, 0x5A, 0xF2);};

// types

namespace Windows { namespace Security { namespace Credentials {

// IKeyCredentialManagerStatics
struct IKeyCredentialManagerStatics : IInspectable {
	virtual STDMETHODIMP _IsSupportedAsync(Foundation::IAsyncOperation<bool>* *value);
	virtual STDMETHODIMP _RenewAttestationAsync(Foundation::IAsyncAction* *operation);
	virtual STDMETHODIMP _RequestCreateAsync(HSTRING name, KeyCredentialCreationOption option, Foundation::IAsyncOperation<KeyCredentialRetrievalResult*>* *value);
	virtual STDMETHODIMP _OpenAsync(HSTRING name, Foundation::IAsyncOperation<KeyCredentialRetrievalResult*>* *value);
	virtual STDMETHODIMP _DeleteAsync(HSTRING name, Foundation::IAsyncAction* *operation);
};

// IKeyCredentialRetrievalResult
struct IKeyCredentialRetrievalResult_raw : IInspectable {
	virtual STDMETHODIMP _get_Credential(KeyCredential* *value);
	virtual STDMETHODIMP _get_Status(KeyCredentialStatus *value);
};
template<typename X> struct IKeyCredentialRetrievalResult_adaptor : X {
	union {
		struct : property {
			ptr<KeyCredential> get() { KeyCredential* value; hrcheck(enc(&IKeyCredentialRetrievalResult_adaptor::Credential)->_get_Credential(&value)); return from_abi(value); }
			ptr<KeyCredential> operator()() { return get(); }
			operator ptr<KeyCredential> () { return get(); }
			ptr<KeyCredential> operator->() { return get(); }
		} Credential;
		struct : property {
			KeyCredentialStatus get() { KeyCredentialStatus value; hrcheck(enc(&IKeyCredentialRetrievalResult_adaptor::Status)->_get_Status(&value)); return value; }
			KeyCredentialStatus operator()() { return get(); }
			operator KeyCredentialStatus () { return get(); }
		} Status;
	};
	IKeyCredentialRetrievalResult_adaptor() {}
};
template<typename X> struct adapt<IKeyCredentialRetrievalResult, X> : Windows::Security::Credentials::IKeyCredentialRetrievalResult_adaptor<X> { typedef adapt IKeyCredentialRetrievalResult; };
struct IKeyCredentialRetrievalResult : IKeyCredentialRetrievalResult_raw, generate<IKeyCredentialRetrievalResult> {};

// KeyCredentialRetrievalResult
template<typename X> struct statics<KeyCredentialRetrievalResult, X> : X {
	typedef typename X::root_type KeyCredentialRetrievalResult;
};
struct KeyCredentialRetrievalResult : generate<KeyCredentialRetrievalResult> {};

// IKeyCredential
struct IKeyCredential_raw : IInspectable {
	virtual STDMETHODIMP _get_Name(HSTRING *value);
	virtual STDMETHODIMP _RetrievePublicKeyWithDefaultBlobType(Storage::Streams::IBuffer* *value);
	virtual STDMETHODIMP _RetrievePublicKeyWithBlobType(Cryptography::Core::CryptographicPublicKeyBlobType blobType, Storage::Streams::IBuffer* *value);
	virtual STDMETHODIMP _RequestSignAsync(Storage::Streams::IBuffer* data, Foundation::IAsyncOperation<KeyCredentialOperationResult*>* *value);
	virtual STDMETHODIMP _GetAttestationAsync(Foundation::IAsyncOperation<KeyCredentialAttestationResult*>* *value);
};
template<typename X> struct IKeyCredential_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IKeyCredential_adaptor::Name)->_get_Name(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Name;
	};
	ptr<Storage::Streams::IBuffer> RetrievePublicKey() { Storage::Streams::IBuffer* value; hrcheck(X::get()->_RetrievePublicKeyWithDefaultBlobType(&value)); return from_abi(value); }
	ptr<Storage::Streams::IBuffer> RetrievePublicKey(Cryptography::Core::CryptographicPublicKeyBlobType blobType) { Storage::Streams::IBuffer* value; hrcheck(X::get()->_RetrievePublicKeyWithBlobType(blobType, &value)); return from_abi(value); }
	ptr<Foundation::IAsyncOperation<ptr<KeyCredentialOperationResult>>> RequestSignAsync(pptr<Storage::Streams::IBuffer> data) { Foundation::IAsyncOperation<KeyCredentialOperationResult*>* value; hrcheck(X::get()->_RequestSignAsync(data, &value)); return from_abi(value); }
	ptr<Foundation::IAsyncOperation<ptr<KeyCredentialAttestationResult>>> GetAttestationAsync() { Foundation::IAsyncOperation<KeyCredentialAttestationResult*>* value; hrcheck(X::get()->_GetAttestationAsync(&value)); return from_abi(value); }
	IKeyCredential_adaptor() {}
};
template<typename X> struct adapt<IKeyCredential, X> : Windows::Security::Credentials::IKeyCredential_adaptor<X> { typedef adapt IKeyCredential; };
struct IKeyCredential : IKeyCredential_raw, generate<IKeyCredential> {};

// IKeyCredentialOperationResult
struct IKeyCredentialOperationResult_raw : IInspectable {
	virtual STDMETHODIMP _get_Result(Storage::Streams::IBuffer* *value);
	virtual STDMETHODIMP _get_Status(KeyCredentialStatus *value);
};
template<typename X> struct IKeyCredentialOperationResult_adaptor : X {
	union {
		struct : property {
			ptr<Storage::Streams::IBuffer> get() { Storage::Streams::IBuffer* value; hrcheck(enc(&IKeyCredentialOperationResult_adaptor::Result)->_get_Result(&value)); return from_abi(value); }
			ptr<Storage::Streams::IBuffer> operator()() { return get(); }
			operator ptr<Storage::Streams::IBuffer> () { return get(); }
			ptr<Storage::Streams::IBuffer> operator->() { return get(); }
		} Result;
		struct : property {
			KeyCredentialStatus get() { KeyCredentialStatus value; hrcheck(enc(&IKeyCredentialOperationResult_adaptor::Status)->_get_Status(&value)); return value; }
			KeyCredentialStatus operator()() { return get(); }
			operator KeyCredentialStatus () { return get(); }
		} Status;
	};
	IKeyCredentialOperationResult_adaptor() {}
};
template<typename X> struct adapt<IKeyCredentialOperationResult, X> : Windows::Security::Credentials::IKeyCredentialOperationResult_adaptor<X> { typedef adapt IKeyCredentialOperationResult; };
struct IKeyCredentialOperationResult : IKeyCredentialOperationResult_raw, generate<IKeyCredentialOperationResult> {};

// KeyCredentialOperationResult
template<typename X> struct statics<KeyCredentialOperationResult, X> : X {
	typedef typename X::root_type KeyCredentialOperationResult;
};
struct KeyCredentialOperationResult : generate<KeyCredentialOperationResult> {};

// IKeyCredentialAttestationResult
struct IKeyCredentialAttestationResult_raw : IInspectable {
	virtual STDMETHODIMP _get_CertificateChainBuffer(Storage::Streams::IBuffer* *value);
	virtual STDMETHODIMP _get_AttestationBuffer(Storage::Streams::IBuffer* *value);
	virtual STDMETHODIMP _get_Status(KeyCredentialAttestationStatus *value);
};
template<typename X> struct IKeyCredentialAttestationResult_adaptor : X {
	union {
		struct : property {
			ptr<Storage::Streams::IBuffer> get() { Storage::Streams::IBuffer* value; hrcheck(enc(&IKeyCredentialAttestationResult_adaptor::AttestationBuffer)->_get_AttestationBuffer(&value)); return from_abi(value); }
			ptr<Storage::Streams::IBuffer> operator()() { return get(); }
			operator ptr<Storage::Streams::IBuffer> () { return get(); }
			ptr<Storage::Streams::IBuffer> operator->() { return get(); }
		} AttestationBuffer;
		struct : property {
			ptr<Storage::Streams::IBuffer> get() { Storage::Streams::IBuffer* value; hrcheck(enc(&IKeyCredentialAttestationResult_adaptor::CertificateChainBuffer)->_get_CertificateChainBuffer(&value)); return from_abi(value); }
			ptr<Storage::Streams::IBuffer> operator()() { return get(); }
			operator ptr<Storage::Streams::IBuffer> () { return get(); }
			ptr<Storage::Streams::IBuffer> operator->() { return get(); }
		} CertificateChainBuffer;
		struct : property {
			KeyCredentialAttestationStatus get() { KeyCredentialAttestationStatus value; hrcheck(enc(&IKeyCredentialAttestationResult_adaptor::Status)->_get_Status(&value)); return value; }
			KeyCredentialAttestationStatus operator()() { return get(); }
			operator KeyCredentialAttestationStatus () { return get(); }
		} Status;
	};
	IKeyCredentialAttestationResult_adaptor() {}
};
template<typename X> struct adapt<IKeyCredentialAttestationResult, X> : Windows::Security::Credentials::IKeyCredentialAttestationResult_adaptor<X> { typedef adapt IKeyCredentialAttestationResult; };
struct IKeyCredentialAttestationResult : IKeyCredentialAttestationResult_raw, generate<IKeyCredentialAttestationResult> {};

// KeyCredentialAttestationResult
template<typename X> struct statics<KeyCredentialAttestationResult, X> : X {
	typedef typename X::root_type KeyCredentialAttestationResult;
};
struct KeyCredentialAttestationResult : generate<KeyCredentialAttestationResult> {};

// KeyCredential
template<typename X> struct statics<KeyCredential, X> : X {
	typedef typename X::root_type KeyCredential;
};
struct KeyCredential : generate<KeyCredential> {
	using IKeyCredential::RetrievePublicKey;
};

// KeyCredentialManager
template<typename> struct KeyCredentialManager_statics {
	static ptr<Foundation::IAsyncOperation<bool>> IsSupportedAsync() { Foundation::IAsyncOperation<bool>* value; hrcheck(get_activation_factory<KeyCredentialManager, IKeyCredentialManagerStatics>()->_IsSupportedAsync(&value)); return from_abi(value); }
	static ptr<Foundation::IAsyncAction> RenewAttestationAsync() { Foundation::IAsyncAction* operation; hrcheck(get_activation_factory<KeyCredentialManager, IKeyCredentialManagerStatics>()->_RenewAttestationAsync(&operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<ptr<KeyCredentialRetrievalResult>>> RequestCreateAsync(hstring_ref name, KeyCredentialCreationOption option) { Foundation::IAsyncOperation<KeyCredentialRetrievalResult*>* value; hrcheck(get_activation_factory<KeyCredentialManager, IKeyCredentialManagerStatics>()->_RequestCreateAsync(name, option, &value)); return from_abi(value); }
	static ptr<Foundation::IAsyncOperation<ptr<KeyCredentialRetrievalResult>>> OpenAsync(hstring_ref name) { Foundation::IAsyncOperation<KeyCredentialRetrievalResult*>* value; hrcheck(get_activation_factory<KeyCredentialManager, IKeyCredentialManagerStatics>()->_OpenAsync(name, &value)); return from_abi(value); }
	static ptr<Foundation::IAsyncAction> DeleteAsync(hstring_ref name) { Foundation::IAsyncAction* operation; hrcheck(get_activation_factory<KeyCredentialManager, IKeyCredentialManagerStatics>()->_DeleteAsync(name, &operation)); return from_abi(operation); }
};

template<typename X> struct statics<KeyCredentialManager, X> : X, Windows::Security::Credentials::KeyCredentialManager_statics<void> {
	typedef typename X::root_type KeyCredentialManager;
};
struct KeyCredentialManager : generate<KeyCredentialManager> {};

// IWebAccountFactory
struct IWebAccountFactory : IInspectable {
	virtual STDMETHODIMP _CreateWebAccount(WebAccountProvider* webAccountProvider, HSTRING userName, WebAccountState state, WebAccount* *instance);
};

// IWebAccountProviderFactory
struct IWebAccountProviderFactory : IInspectable {
	virtual STDMETHODIMP _CreateWebAccountProvider(HSTRING id, HSTRING displayName, Foundation::Uri* iconUri, WebAccountProvider* *instance);
};

// IWebAccountProvider4
struct IWebAccountProvider4_raw : IInspectable {
	virtual STDMETHODIMP _get_IsSystemProvider(bool *value);
};
template<typename X> struct IWebAccountProvider4_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IWebAccountProvider4_adaptor::IsSystemProvider)->_get_IsSystemProvider(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsSystemProvider;
	};
	IWebAccountProvider4_adaptor() {}
};
template<typename X> struct adapt<IWebAccountProvider4, X> : Windows::Security::Credentials::IWebAccountProvider4_adaptor<X> { typedef adapt IWebAccountProvider4; };
struct IWebAccountProvider4 : IWebAccountProvider4_raw, generate<IWebAccountProvider4> {};

// IWebAccountProvider
struct IWebAccountProvider_raw : IInspectable {
	virtual STDMETHODIMP _get_Id(HSTRING *value);
	virtual STDMETHODIMP _get_DisplayName(HSTRING *value);
	virtual STDMETHODIMP _get_IconUri(Foundation::Uri* *value);
};
template<typename X> struct IWebAccountProvider_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebAccountProvider_adaptor::DisplayName)->_get_DisplayName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DisplayName;
		struct : property {
			ptr<Foundation::Uri> get() { Foundation::Uri* value; hrcheck(enc(&IWebAccountProvider_adaptor::IconUri)->_get_IconUri(&value)); return from_abi(value); }
			ptr<Foundation::Uri> operator()() { return get(); }
			operator ptr<Foundation::Uri> () { return get(); }
			ptr<Foundation::Uri> operator->() { return get(); }
		} IconUri;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebAccountProvider_adaptor::Id)->_get_Id(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Id;
	};
	IWebAccountProvider_adaptor() {}
};
template<typename X> struct adapt<IWebAccountProvider, X> : Windows::Security::Credentials::IWebAccountProvider_adaptor<X> { typedef adapt IWebAccountProvider; };
struct IWebAccountProvider : IWebAccountProvider_raw, generate<IWebAccountProvider> {};

// IWebAccountProvider2
struct IWebAccountProvider2_raw : IInspectable {
	virtual STDMETHODIMP _get_DisplayPurpose(HSTRING *value);
	virtual STDMETHODIMP _get_Authority(HSTRING *value);
};
template<typename X> struct IWebAccountProvider2_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebAccountProvider2_adaptor::Authority)->_get_Authority(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Authority;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebAccountProvider2_adaptor::DisplayPurpose)->_get_DisplayPurpose(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DisplayPurpose;
	};
	IWebAccountProvider2_adaptor() {}
};
template<typename X> struct adapt<IWebAccountProvider2, X> : Windows::Security::Credentials::IWebAccountProvider2_adaptor<X> { typedef adapt IWebAccountProvider2; };
struct IWebAccountProvider2 : IWebAccountProvider2_raw, generate<IWebAccountProvider2> {};

// IWebAccountProvider3
struct IWebAccountProvider3_raw : IInspectable {
	virtual STDMETHODIMP _get_User(System::User* *user);
};
template<typename X> struct IWebAccountProvider3_adaptor : X {
	union {
		struct : property {
			ptr<System::User> get() { System::User* user; hrcheck(enc(&IWebAccountProvider3_adaptor::User)->_get_User(&user)); return from_abi(user); }
			ptr<System::User> operator()() { return get(); }
			operator ptr<System::User> () { return get(); }
			ptr<System::User> operator->() { return get(); }
		} User;
	};
	IWebAccountProvider3_adaptor() {}
};
template<typename X> struct adapt<IWebAccountProvider3, X> : Windows::Security::Credentials::IWebAccountProvider3_adaptor<X> { typedef adapt IWebAccountProvider3; };
struct IWebAccountProvider3 : IWebAccountProvider3_raw, generate<IWebAccountProvider3> {};

// WebAccountProvider
template<typename> struct WebAccountProvider_statics {
	static WebAccountProvider *activate(hstring_ref id, hstring_ref displayName, pptr<Foundation::Uri> iconUri) { WebAccountProvider *instance; hrcheck(get_activation_factory<WebAccountProvider, IWebAccountProviderFactory>()->_CreateWebAccountProvider(id, displayName, iconUri, &instance)); return instance; }
};

template<typename X> struct statics<WebAccountProvider, X> : X, Windows::Security::Credentials::WebAccountProvider_statics<void> {
	using Windows::Security::Credentials::WebAccountProvider_statics<void>::activate;
	typedef typename X::root_type WebAccountProvider;
};
struct WebAccountProvider : generate<WebAccountProvider> {};

// IWebAccount
struct IWebAccount_raw : IInspectable {
	virtual STDMETHODIMP _get_WebAccountProvider(Credentials::WebAccountProvider* *value) = 0;
	virtual STDMETHODIMP _get_UserName(HSTRING *value) = 0;
	virtual STDMETHODIMP _get_State(WebAccountState *value) = 0;
};
template<typename X> struct IWebAccount_adaptor : X {
	union {
		struct : property {
			WebAccountState get() { WebAccountState value; hrcheck(enc(&IWebAccount_adaptor::State)->_get_State(&value)); return value; }
			WebAccountState operator()() { return get(); }
			operator WebAccountState () { return get(); }
		} State;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebAccount_adaptor::UserName)->_get_UserName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} UserName;
		struct : property {
			ptr<Credentials::WebAccountProvider> get() { Credentials::WebAccountProvider* value; hrcheck(enc(&IWebAccount_adaptor::WebAccountProvider)->_get_WebAccountProvider(&value)); return from_abi(value); }
			ptr<Credentials::WebAccountProvider> operator()() { return get(); }
			operator ptr<Credentials::WebAccountProvider> () { return get(); }
			ptr<Credentials::WebAccountProvider> operator->() { return get(); }
		} WebAccountProvider;
	};
	IWebAccount_adaptor() {}
};
template<typename X> struct adapt<IWebAccount, X> : Windows::Security::Credentials::IWebAccount_adaptor<X> { typedef adapt IWebAccount; };
template<typename X> struct IWebAccount_unadaptor : X {
	STDMETHODIMP _get_WebAccountProvider(Credentials::WebAccountProvider* *value) { return hrtry([&, this] { get_prop(value, WebAccountProvider); }); }
	STDMETHODIMP _get_UserName(HSTRING *value) { return hrtry([&, this] { get_prop(value, UserName); }); }
	STDMETHODIMP _get_State(WebAccountState *value) { return hrtry([&, this] { get_prop(value, State); }); }
};
template<typename X> struct unadapt<IWebAccount, X> : Windows::Security::Credentials::IWebAccount_unadaptor<X> {};
struct IWebAccount : IWebAccount_raw, generate<IWebAccount> {};

// IWebAccount2
struct IWebAccount2_raw : IInspectable {
	virtual STDMETHODIMP _get_Id(HSTRING *value);
	virtual STDMETHODIMP _get_Properties(Foundation::Collections::IMapView<HSTRING, HSTRING>* *value);
	virtual STDMETHODIMP _GetPictureAsync(WebAccountPictureSize desizedSize, Foundation::IAsyncOperation<Storage::Streams::IRandomAccessStream*>* *asyncInfo);
	virtual STDMETHODIMP _SignOutAsync(Foundation::IAsyncAction* *asyncInfo);
	virtual STDMETHODIMP _SignOutWithClientIdAsync(HSTRING clientId, Foundation::IAsyncAction* *asyncInfo);
};
template<typename X> struct IWebAccount2_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebAccount2_adaptor::Id)->_get_Id(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Id;
		struct : property {
			ptr<Foundation::Collections::IMapView<hstring, hstring>> get() { Foundation::Collections::IMapView<HSTRING, HSTRING>* value; hrcheck(enc(&IWebAccount2_adaptor::Properties)->_get_Properties(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IMapView<hstring, hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IMapView<hstring, hstring>> () { return get(); }
			ptr<Foundation::Collections::IMapView<hstring, hstring>> operator->() { return get(); }
		} Properties;
	};
	ptr<Foundation::IAsyncOperation<ptr<Storage::Streams::IRandomAccessStream>>> GetPictureAsync(WebAccountPictureSize desizedSize) { Foundation::IAsyncOperation<Storage::Streams::IRandomAccessStream*>* asyncInfo; hrcheck(X::get()->_GetPictureAsync(desizedSize, &asyncInfo)); return from_abi(asyncInfo); }
	ptr<Foundation::IAsyncAction> SignOutAsync() { Foundation::IAsyncAction* asyncInfo; hrcheck(X::get()->_SignOutAsync(&asyncInfo)); return from_abi(asyncInfo); }
	ptr<Foundation::IAsyncAction> SignOutAsync(hstring_ref clientId) { Foundation::IAsyncAction* asyncInfo; hrcheck(X::get()->_SignOutWithClientIdAsync(clientId, &asyncInfo)); return from_abi(asyncInfo); }
	IWebAccount2_adaptor() {}
};
template<typename X> struct adapt<IWebAccount2, X> : Windows::Security::Credentials::IWebAccount2_adaptor<X> { typedef adapt IWebAccount2; };
struct IWebAccount2 : IWebAccount2_raw, generate<IWebAccount2> {};

// WebAccount
template<typename> struct WebAccount_statics {
	static WebAccount *activate(pptr<Credentials::WebAccountProvider> webAccountProvider, hstring_ref userName, WebAccountState state) { WebAccount *instance; hrcheck(get_activation_factory<WebAccount, IWebAccountFactory>()->_CreateWebAccount(webAccountProvider, userName, state, &instance)); return instance; }
};

template<typename X> struct statics<WebAccount, X> : X, Windows::Security::Credentials::WebAccount_statics<void> {
	using Windows::Security::Credentials::WebAccount_statics<void>::activate;
	typedef typename X::root_type WebAccount;
};
struct WebAccount : generate<WebAccount> {
	using IWebAccount2::SignOutAsync;
};

// IPasswordCredential
struct IPasswordCredential_raw : IInspectable {
	virtual STDMETHODIMP _get_Resource(HSTRING *resource);
	virtual STDMETHODIMP _put_Resource(HSTRING resource);
	virtual STDMETHODIMP _get_UserName(HSTRING *userName);
	virtual STDMETHODIMP _put_UserName(HSTRING userName);
	virtual STDMETHODIMP _get_Password(HSTRING *password);
	virtual STDMETHODIMP _put_Password(HSTRING password);
	virtual STDMETHODIMP _RetrievePassword();
	virtual STDMETHODIMP _get_Properties(Foundation::Collections::IPropertySet* *props);
};
template<typename X> struct IPasswordCredential_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING password; hrcheck(enc(&IPasswordCredential_adaptor::Password)->_get_Password(&password)); return from_abi(password); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref password) { hrcheck(enc(&IPasswordCredential_adaptor::Password)->_put_Password(password)); }
			void operator=(hstring_ref password) { put(password); }
			void operator()(hstring_ref password) { put(password); }
		} Password;
		struct : property {
			ptr<Foundation::Collections::IPropertySet> get() { Foundation::Collections::IPropertySet* props; hrcheck(enc(&IPasswordCredential_adaptor::Properties)->_get_Properties(&props)); return from_abi(props); }
			ptr<Foundation::Collections::IPropertySet> operator()() { return get(); }
			operator ptr<Foundation::Collections::IPropertySet> () { return get(); }
			ptr<Foundation::Collections::IPropertySet> operator->() { return get(); }
		} Properties;
		struct : property {
			hstring get() { HSTRING resource; hrcheck(enc(&IPasswordCredential_adaptor::Resource)->_get_Resource(&resource)); return from_abi(resource); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref resource) { hrcheck(enc(&IPasswordCredential_adaptor::Resource)->_put_Resource(resource)); }
			void operator=(hstring_ref resource) { put(resource); }
			void operator()(hstring_ref resource) { put(resource); }
		} Resource;
		struct : property {
			hstring get() { HSTRING userName; hrcheck(enc(&IPasswordCredential_adaptor::UserName)->_get_UserName(&userName)); return from_abi(userName); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref userName) { hrcheck(enc(&IPasswordCredential_adaptor::UserName)->_put_UserName(userName)); }
			void operator=(hstring_ref userName) { put(userName); }
			void operator()(hstring_ref userName) { put(userName); }
		} UserName;
	};
	void RetrievePassword() { hrcheck(X::get()->_RetrievePassword()); }
	IPasswordCredential_adaptor() {}
};
template<typename X> struct adapt<IPasswordCredential, X> : Windows::Security::Credentials::IPasswordCredential_adaptor<X> { typedef adapt IPasswordCredential; };
struct IPasswordCredential : IPasswordCredential_raw, generate<IPasswordCredential> {};

// ICredentialFactory
struct ICredentialFactory : IInspectable {
	virtual STDMETHODIMP _CreatePasswordCredential(HSTRING resource, HSTRING userName, HSTRING password, PasswordCredential* *credential);
};

// PasswordCredential
template<typename> struct PasswordCredential_statics {
	static PasswordCredential *activate(hstring_ref resource, hstring_ref userName, hstring_ref password) { PasswordCredential *credential; hrcheck(get_activation_factory<PasswordCredential, ICredentialFactory>()->_CreatePasswordCredential(resource, userName, password, &credential)); return credential; }
	static PasswordCredential *activate() { PasswordCredential *t; get_activation_factory<PasswordCredential>()->ActivateInstance((IInspectable**)&t); return t; }
};

template<typename X> struct statics<PasswordCredential, X> : X, Windows::Security::Credentials::PasswordCredential_statics<void> {
	using Windows::Security::Credentials::PasswordCredential_statics<void>::activate;
	typedef typename X::root_type PasswordCredential;
};
struct PasswordCredential : generate<PasswordCredential> {};

// IPasswordVault
struct IPasswordVault_raw : IInspectable {
	virtual STDMETHODIMP _Add(PasswordCredential* credential);
	virtual STDMETHODIMP _Remove(PasswordCredential* credential);
	virtual STDMETHODIMP _Retrieve(HSTRING resource, HSTRING userName, PasswordCredential* *credential);
	virtual STDMETHODIMP _FindAllByResource(HSTRING resource, Foundation::Collections::IVectorView<PasswordCredential*>* *credentials);
	virtual STDMETHODIMP _FindAllByUserName(HSTRING userName, Foundation::Collections::IVectorView<PasswordCredential*>* *credentials);
	virtual STDMETHODIMP _RetrieveAll(Foundation::Collections::IVectorView<PasswordCredential*>* *credentials);
};
template<typename X> struct IPasswordVault_adaptor : X {
	void Add(pptr<PasswordCredential> credential) { hrcheck(X::get()->_Add(credential)); }
	void Remove(pptr<PasswordCredential> credential) { hrcheck(X::get()->_Remove(credential)); }
	ptr<PasswordCredential> Retrieve(hstring_ref resource, hstring_ref userName) { PasswordCredential* credential; hrcheck(X::get()->_Retrieve(resource, userName, &credential)); return from_abi(credential); }
	ptr<Foundation::Collections::IVectorView<ptr<PasswordCredential>>> FindAllByResource(hstring_ref resource) { Foundation::Collections::IVectorView<PasswordCredential*>* credentials; hrcheck(X::get()->_FindAllByResource(resource, &credentials)); return from_abi(credentials); }
	ptr<Foundation::Collections::IVectorView<ptr<PasswordCredential>>> FindAllByUserName(hstring_ref userName) { Foundation::Collections::IVectorView<PasswordCredential*>* credentials; hrcheck(X::get()->_FindAllByUserName(userName, &credentials)); return from_abi(credentials); }
	ptr<Foundation::Collections::IVectorView<ptr<PasswordCredential>>> RetrieveAll() { Foundation::Collections::IVectorView<PasswordCredential*>* credentials; hrcheck(X::get()->_RetrieveAll(&credentials)); return from_abi(credentials); }
};
template<typename X> struct adapt<IPasswordVault, X> : Windows::Security::Credentials::IPasswordVault_adaptor<X> { typedef adapt IPasswordVault; };
struct IPasswordVault : IPasswordVault_raw, generate<IPasswordVault> {};

// PasswordVault
template<typename X> struct statics<PasswordVault, X> : X {
	typedef typename X::root_type PasswordVault;
};
struct PasswordVault : generate<PasswordVault> {};

// PasswordCredentialPropertyStore
template<typename X> struct statics<PasswordCredentialPropertyStore, X> : X {
	typedef typename X::root_type PasswordCredentialPropertyStore;
};
struct PasswordCredentialPropertyStore : generate<PasswordCredentialPropertyStore> {};
}}}
} // namespace iso_winrt
