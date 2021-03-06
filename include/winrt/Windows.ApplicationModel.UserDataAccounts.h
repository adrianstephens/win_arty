#pragma once
// generated by isopod tools
// namespaces:
// Windows.ApplicationModel.UserDataAccounts

#include "Windows.ApplicationModel.UserDataAccounts.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace Appointments {
struct AppointmentCalendar;
}
namespace Contacts {
struct ContactAnnotationList;
struct ContactGroup;
struct ContactList;
}
namespace Email {
struct EmailMailbox;
}
namespace UserDataTasks {
struct UserDataTaskList;
}}
namespace Foundation { namespace Collections {
struct IPropertySet;
template<typename T> struct IVectorView;
template<typename T> struct IVector;
}}
namespace Storage { namespace Streams {
struct IRandomAccessStreamReference;
}}
namespace System {
struct User;
}}

// defs

template<> struct def<Windows::ApplicationModel::UserDataAccounts::UserDataAccountOtherAppReadAccess> : enum_type<int> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType> : enum_type<int> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds> : enum_type<unsigned> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount2> : interface_type<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount3> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount4> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::UserDataAccount> : class_type<Platform::Object, Windows::ApplicationModel::UserDataAccounts::IUserDataAccount, Windows::ApplicationModel::UserDataAccounts::IUserDataAccount2, Windows::ApplicationModel::UserDataAccounts::IUserDataAccount3, Windows::ApplicationModel::UserDataAccounts::IUserDataAccount4> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore2> : interface_type<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore3> : interface_type<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore> : class_type<Platform::Object, Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore, Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore2, Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore3> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs> : class_type<Platform::Object, Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics2> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::UserDataAccountManagerForUser> : class_type<Platform::Object, Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::UserDataAccountManager> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount> { define_guid(0xB9C4367E, 0xB348, 0x4910, 0xBE, 0x94, 0x4A, 0xD4, 0xBB, 0xA6, 0xDE, 0xA7);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount2> { define_guid(0x78CD89F, 0xDE82, 0x404B, 0x81, 0x95, 0xC8, 0xA3, 0xAC, 0x19, 0x8F, 0x60);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount3> { define_guid(0x1533845, 0x6C43, 0x4286, 0x9D, 0x69, 0x3E, 0x17, 0x9, 0xA1, 0xF2, 0x66);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount4> { define_guid(0xC4315210, 0xEAE5, 0x4F0A, 0xA8, 0xB2, 0x1C, 0xCA, 0x11, 0x5E, 0x0, 0x8F);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore> { define_guid(0x2073B0AD, 0x7D0A, 0x4E76, 0xBF, 0x45, 0x23, 0x68, 0xF9, 0x78, 0xA5, 0x9A);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore2> { define_guid(0xB1E0AEF7, 0x9560, 0x4631, 0x8A, 0xF0, 0x6, 0x1D, 0x30, 0x16, 0x14, 0x69);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore3> { define_guid(0x8142C094, 0xF3C9, 0x478B, 0xB1, 0x17, 0x65, 0x85, 0xBE, 0xBB, 0x67, 0x89);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs> { define_guid(0x84E3E2E5, 0x8820, 0x4512, 0xB1, 0xF6, 0x2E, 0x3, 0x5B, 0xE1, 0x7, 0x2C);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics> { define_guid(0xD9B89EA, 0x1928, 0x4A20, 0x86, 0xD5, 0x3C, 0x73, 0x7F, 0x7D, 0xC3, 0xB0);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics2> { define_guid(0x6A3DED88, 0x316B, 0x435E, 0xB5, 0x34, 0xF7, 0xD4, 0xB4, 0xB7, 0xDB, 0xA6);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser> { define_guid(0x56A6E8DB, 0xDB8F, 0x41AB, 0xA6, 0x5F, 0x8C, 0x59, 0x71, 0xAA, 0xC9, 0x82);};

// types

namespace Windows { namespace ApplicationModel { namespace UserDataAccounts {

// IUserDataAccount
struct IUserDataAccount_raw : IInspectable {
	virtual STDMETHODIMP _get_Id(HSTRING *value);
	virtual STDMETHODIMP _get_UserDisplayName(HSTRING *value);
	virtual STDMETHODIMP _put_UserDisplayName(HSTRING value);
	virtual STDMETHODIMP _get_OtherAppReadAccess(UserDataAccountOtherAppReadAccess *value);
	virtual STDMETHODIMP _put_OtherAppReadAccess(UserDataAccountOtherAppReadAccess value);
	virtual STDMETHODIMP _get_Icon(Storage::Streams::IRandomAccessStreamReference* *value);
	virtual STDMETHODIMP _get_DeviceAccountTypeId(HSTRING *value);
	virtual STDMETHODIMP _get_PackageFamilyName(HSTRING *value);
	virtual STDMETHODIMP _SaveAsync(Foundation::IAsyncAction* *result);
	virtual STDMETHODIMP _DeleteAsync(Foundation::IAsyncAction* *result);
	virtual STDMETHODIMP _FindAppointmentCalendarsAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Appointments::AppointmentCalendar*>*>* *result);
	virtual STDMETHODIMP _FindEmailMailboxesAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Email::EmailMailbox*>*>* *result);
	virtual STDMETHODIMP _FindContactListsAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Contacts::ContactList*>*>* *result);
	virtual STDMETHODIMP _FindContactAnnotationListsAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Contacts::ContactAnnotationList*>*>* *result);
};
template<typename X> struct IUserDataAccount_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserDataAccount_adaptor::DeviceAccountTypeId)->_get_DeviceAccountTypeId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DeviceAccountTypeId;
		struct : property {
			ptr<Storage::Streams::IRandomAccessStreamReference> get() { Storage::Streams::IRandomAccessStreamReference* value; hrcheck(enc(&IUserDataAccount_adaptor::Icon)->_get_Icon(&value)); return from_abi(value); }
			ptr<Storage::Streams::IRandomAccessStreamReference> operator()() { return get(); }
			operator ptr<Storage::Streams::IRandomAccessStreamReference> () { return get(); }
			ptr<Storage::Streams::IRandomAccessStreamReference> operator->() { return get(); }
		} Icon;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserDataAccount_adaptor::Id)->_get_Id(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Id;
		struct : property {
			UserDataAccountOtherAppReadAccess get() { UserDataAccountOtherAppReadAccess value; hrcheck(enc(&IUserDataAccount_adaptor::OtherAppReadAccess)->_get_OtherAppReadAccess(&value)); return value; }
			UserDataAccountOtherAppReadAccess operator()() { return get(); }
			operator UserDataAccountOtherAppReadAccess () { return get(); }
			void put(UserDataAccountOtherAppReadAccess value) { hrcheck(enc(&IUserDataAccount_adaptor::OtherAppReadAccess)->_put_OtherAppReadAccess(value)); }
			void operator=(UserDataAccountOtherAppReadAccess value) { put(value); }
			void operator()(UserDataAccountOtherAppReadAccess value) { put(value); }
		} OtherAppReadAccess;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserDataAccount_adaptor::PackageFamilyName)->_get_PackageFamilyName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} PackageFamilyName;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserDataAccount_adaptor::UserDisplayName)->_get_UserDisplayName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IUserDataAccount_adaptor::UserDisplayName)->_put_UserDisplayName(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} UserDisplayName;
	};
	ptr<Foundation::IAsyncAction> SaveAsync() { Foundation::IAsyncAction* result; hrcheck(X::get()->_SaveAsync(&result)); return from_abi(result); }
	ptr<Foundation::IAsyncAction> DeleteAsync() { Foundation::IAsyncAction* result; hrcheck(X::get()->_DeleteAsync(&result)); return from_abi(result); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<Appointments::AppointmentCalendar>>>>> FindAppointmentCalendarsAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Appointments::AppointmentCalendar*>*>* result; hrcheck(X::get()->_FindAppointmentCalendarsAsync(&result)); return from_abi(result); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<Email::EmailMailbox>>>>> FindEmailMailboxesAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Email::EmailMailbox*>*>* result; hrcheck(X::get()->_FindEmailMailboxesAsync(&result)); return from_abi(result); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<Contacts::ContactList>>>>> FindContactListsAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Contacts::ContactList*>*>* result; hrcheck(X::get()->_FindContactListsAsync(&result)); return from_abi(result); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<Contacts::ContactAnnotationList>>>>> FindContactAnnotationListsAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Contacts::ContactAnnotationList*>*>* result; hrcheck(X::get()->_FindContactAnnotationListsAsync(&result)); return from_abi(result); }
	IUserDataAccount_adaptor() {}
};
template<typename X> struct adapt<IUserDataAccount, X> : Windows::ApplicationModel::UserDataAccounts::IUserDataAccount_adaptor<X> { typedef adapt IUserDataAccount; };
struct IUserDataAccount : IUserDataAccount_raw, generate<IUserDataAccount> {};

// IUserDataAccount2
struct IUserDataAccount2_raw : IInspectable {
	virtual STDMETHODIMP _get_EnterpriseId(HSTRING *value);
	virtual STDMETHODIMP _get_IsProtectedUnderLock(bool *value);
};
template<typename X> struct IUserDataAccount2_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserDataAccount2_adaptor::EnterpriseId)->_get_EnterpriseId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} EnterpriseId;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IUserDataAccount2_adaptor::IsProtectedUnderLock)->_get_IsProtectedUnderLock(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsProtectedUnderLock;
	};
	IUserDataAccount2_adaptor() {}
};
template<typename X> struct adapt<IUserDataAccount2, X> : Windows::ApplicationModel::UserDataAccounts::IUserDataAccount2_adaptor<X> { typedef adapt IUserDataAccount2; };
struct IUserDataAccount2 : IUserDataAccount2_raw, generate<IUserDataAccount2> {};

// IUserDataAccount3
struct IUserDataAccount3_raw : IInspectable {
	virtual STDMETHODIMP _get_ExplictReadAccessPackageFamilyNames(Foundation::Collections::IVector<HSTRING>* *value);
	virtual STDMETHODIMP _get_DisplayName(HSTRING *value);
	virtual STDMETHODIMP _put_DisplayName(HSTRING value);
};
template<typename X> struct IUserDataAccount3_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserDataAccount3_adaptor::DisplayName)->_get_DisplayName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IUserDataAccount3_adaptor::DisplayName)->_put_DisplayName(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} DisplayName;
		struct : property {
			ptr<Foundation::Collections::IVector<hstring>> get() { Foundation::Collections::IVector<HSTRING>* value; hrcheck(enc(&IUserDataAccount3_adaptor::ExplictReadAccessPackageFamilyNames)->_get_ExplictReadAccessPackageFamilyNames(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVector<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVector<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVector<hstring>> operator->() { return get(); }
		} ExplictReadAccessPackageFamilyNames;
	};
	IUserDataAccount3_adaptor() {}
};
template<typename X> struct adapt<IUserDataAccount3, X> : Windows::ApplicationModel::UserDataAccounts::IUserDataAccount3_adaptor<X> { typedef adapt IUserDataAccount3; };
struct IUserDataAccount3 : IUserDataAccount3_raw, generate<IUserDataAccount3> {};

// IUserDataAccount4
struct IUserDataAccount4_raw : IInspectable {
	virtual STDMETHODIMP _get_CanShowCreateContactGroup(bool *value);
	virtual STDMETHODIMP _put_CanShowCreateContactGroup(bool value);
	virtual STDMETHODIMP _get_ProviderProperties(Foundation::Collections::IPropertySet* *value);
	virtual STDMETHODIMP _FindUserDataTaskListsAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<UserDataTasks::UserDataTaskList*>*>* *operation);
	virtual STDMETHODIMP _FindContactGroupsAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Contacts::ContactGroup*>*>* *operation);
	virtual STDMETHODIMP _TryShowCreateContactGroupAsync(Foundation::IAsyncOperation<HSTRING>* *operation);
	virtual STDMETHODIMP _put_IsProtectedUnderLock(bool value);
	virtual STDMETHODIMP _put_Icon(Storage::Streams::IRandomAccessStreamReference* value);
};
template<typename X> struct IUserDataAccount4_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IUserDataAccount4_adaptor::CanShowCreateContactGroup)->_get_CanShowCreateContactGroup(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IUserDataAccount4_adaptor::CanShowCreateContactGroup)->_put_CanShowCreateContactGroup(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} CanShowCreateContactGroup;
		struct : property {
			void put(pptr<Storage::Streams::IRandomAccessStreamReference> value) { hrcheck(enc(&IUserDataAccount4_adaptor::Icon)->_put_Icon(value)); }
			void operator=(pptr<Storage::Streams::IRandomAccessStreamReference> value) { put(value); }
			void operator()(pptr<Storage::Streams::IRandomAccessStreamReference> value) { put(value); }
		} Icon;
		struct : property {
			void put(bool value) { hrcheck(enc(&IUserDataAccount4_adaptor::IsProtectedUnderLock)->_put_IsProtectedUnderLock(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} IsProtectedUnderLock;
		struct : property {
			ptr<Foundation::Collections::IPropertySet> get() { Foundation::Collections::IPropertySet* value; hrcheck(enc(&IUserDataAccount4_adaptor::ProviderProperties)->_get_ProviderProperties(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IPropertySet> operator()() { return get(); }
			operator ptr<Foundation::Collections::IPropertySet> () { return get(); }
			ptr<Foundation::Collections::IPropertySet> operator->() { return get(); }
		} ProviderProperties;
	};
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<UserDataTasks::UserDataTaskList>>>>> FindUserDataTaskListsAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<UserDataTasks::UserDataTaskList*>*>* operation; hrcheck(X::get()->_FindUserDataTaskListsAsync(&operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<Contacts::ContactGroup>>>>> FindContactGroupsAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Contacts::ContactGroup*>*>* operation; hrcheck(X::get()->_FindContactGroupsAsync(&operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<hstring>> TryShowCreateContactGroupAsync() { Foundation::IAsyncOperation<HSTRING>* operation; hrcheck(X::get()->_TryShowCreateContactGroupAsync(&operation)); return from_abi(operation); }
	IUserDataAccount4_adaptor() {}
};
template<typename X> struct adapt<IUserDataAccount4, X> : Windows::ApplicationModel::UserDataAccounts::IUserDataAccount4_adaptor<X> { typedef adapt IUserDataAccount4; };
struct IUserDataAccount4 : IUserDataAccount4_raw, generate<IUserDataAccount4> {};

// IUserDataAccountStore
struct IUserDataAccountStore_raw : IInspectable {
	virtual STDMETHODIMP _FindAccountsAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<UserDataAccount*>*>* *result);
	virtual STDMETHODIMP _GetAccountAsync(HSTRING id, Foundation::IAsyncOperation<UserDataAccount*>* *result);
	virtual STDMETHODIMP _CreateAccountAsync(HSTRING userDisplayName, Foundation::IAsyncOperation<UserDataAccount*>* *result);
};
template<typename X> struct IUserDataAccountStore_adaptor : X {
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<UserDataAccount>>>>> FindAccountsAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<UserDataAccount*>*>* result; hrcheck(X::get()->_FindAccountsAsync(&result)); return from_abi(result); }
	ptr<Foundation::IAsyncOperation<ptr<UserDataAccount>>> GetAccountAsync(hstring_ref id) { Foundation::IAsyncOperation<UserDataAccount*>* result; hrcheck(X::get()->_GetAccountAsync(id, &result)); return from_abi(result); }
	ptr<Foundation::IAsyncOperation<ptr<UserDataAccount>>> CreateAccountAsync(hstring_ref userDisplayName) { Foundation::IAsyncOperation<UserDataAccount*>* result; hrcheck(X::get()->_CreateAccountAsync(userDisplayName, &result)); return from_abi(result); }
};
template<typename X> struct adapt<IUserDataAccountStore, X> : Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore_adaptor<X> { typedef adapt IUserDataAccountStore; };
struct IUserDataAccountStore : IUserDataAccountStore_raw, generate<IUserDataAccountStore> {};

// UserDataAccount
template<typename X> struct statics<UserDataAccount, X> : X {
	typedef typename X::root_type UserDataAccount;
};
struct UserDataAccount : generate<UserDataAccount> {
	using IUserDataAccount2::IsProtectedUnderLock;
	using IUserDataAccount4::Icon;
};

// IUserDataAccountStore2
struct IUserDataAccountStore2_raw : IInspectable {
	virtual STDMETHODIMP _CreateAccountWithPackageRelativeAppIdAsync(HSTRING userDisplayName, HSTRING packageRelativeAppId, Foundation::IAsyncOperation<UserDataAccount*>* *result);
	virtual STDMETHODIMP _add_StoreChanged(Foundation::TypedEventHandler<UserDataAccountStore*, UserDataAccountStoreChangedEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_StoreChanged(Foundation::EventRegistrationToken token);
};
template<typename X> struct IUserDataAccountStore2_adaptor : X {
	union {
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<UserDataAccountStore>, ptr<UserDataAccountStoreChangedEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IUserDataAccountStore2_adaptor::StoreChanged)->_add_StoreChanged(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IUserDataAccountStore2_adaptor::StoreChanged)->_remove_StoreChanged(token)); }
		} StoreChanged;
	};
	ptr<Foundation::IAsyncOperation<ptr<UserDataAccount>>> CreateAccountAsync(hstring_ref userDisplayName, hstring_ref packageRelativeAppId) { Foundation::IAsyncOperation<UserDataAccount*>* result; hrcheck(X::get()->_CreateAccountWithPackageRelativeAppIdAsync(userDisplayName, packageRelativeAppId, &result)); return from_abi(result); }
	IUserDataAccountStore2_adaptor() {}
};
template<typename X> struct adapt<IUserDataAccountStore2, X> : Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore2_adaptor<X> { typedef adapt IUserDataAccountStore2; };
struct IUserDataAccountStore2 : IUserDataAccountStore2_raw, generate<IUserDataAccountStore2> {};

// IUserDataAccountStore3
struct IUserDataAccountStore3_raw : IInspectable {
	virtual STDMETHODIMP _CreateAccountWithPackageRelativeAppIdAndEnterpriseIdAsync(HSTRING userDisplayName, HSTRING packageRelativeAppId, HSTRING enterpriseId, Foundation::IAsyncOperation<UserDataAccount*>* *result);
};
template<typename X> struct IUserDataAccountStore3_adaptor : X {
	ptr<Foundation::IAsyncOperation<ptr<UserDataAccount>>> CreateAccountAsync(hstring_ref userDisplayName, hstring_ref packageRelativeAppId, hstring_ref enterpriseId) { Foundation::IAsyncOperation<UserDataAccount*>* result; hrcheck(X::get()->_CreateAccountWithPackageRelativeAppIdAndEnterpriseIdAsync(userDisplayName, packageRelativeAppId, enterpriseId, &result)); return from_abi(result); }
};
template<typename X> struct adapt<IUserDataAccountStore3, X> : Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore3_adaptor<X> { typedef adapt IUserDataAccountStore3; };
struct IUserDataAccountStore3 : IUserDataAccountStore3_raw, generate<IUserDataAccountStore3> {};

// UserDataAccountStore
template<typename X> struct statics<UserDataAccountStore, X> : X {
	typedef typename X::root_type UserDataAccountStore;
};
struct UserDataAccountStore : generate<UserDataAccountStore> {
	using IUserDataAccountStore3::CreateAccountAsync;
	using IUserDataAccountStore::CreateAccountAsync;
	using IUserDataAccountStore2::CreateAccountAsync;
};

// IUserDataAccountStoreChangedEventArgs
struct IUserDataAccountStoreChangedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _GetDeferral(Foundation::Deferral* *result);
};
template<typename X> struct IUserDataAccountStoreChangedEventArgs_adaptor : X {
	ptr<Foundation::Deferral> GetDeferral() { Foundation::Deferral* result; hrcheck(X::get()->_GetDeferral(&result)); return from_abi(result); }
};
template<typename X> struct adapt<IUserDataAccountStoreChangedEventArgs, X> : Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs_adaptor<X> { typedef adapt IUserDataAccountStoreChangedEventArgs; };
struct IUserDataAccountStoreChangedEventArgs : IUserDataAccountStoreChangedEventArgs_raw, generate<IUserDataAccountStoreChangedEventArgs> {};

// UserDataAccountStoreChangedEventArgs
template<typename X> struct statics<UserDataAccountStoreChangedEventArgs, X> : X {
	typedef typename X::root_type UserDataAccountStoreChangedEventArgs;
};
struct UserDataAccountStoreChangedEventArgs : generate<UserDataAccountStoreChangedEventArgs> {};

// IUserDataAccountManagerStatics
struct IUserDataAccountManagerStatics : IInspectable {
	virtual STDMETHODIMP _RequestStoreAsync(UserDataAccountStoreAccessType storeAccessType, Foundation::IAsyncOperation<UserDataAccountStore*>* *result);
	virtual STDMETHODIMP _ShowAddAccountAsync(UserDataAccountContentKinds contentKinds, Foundation::IAsyncOperation<HSTRING>* *result);
	virtual STDMETHODIMP _ShowAccountSettingsAsync(HSTRING id, Foundation::IAsyncAction* *result);
	virtual STDMETHODIMP _ShowAccountErrorResolverAsync(HSTRING id, Foundation::IAsyncAction* *result);
};

// IUserDataAccountManagerStatics2
struct IUserDataAccountManagerStatics2 : IInspectable {
	virtual STDMETHODIMP _GetForUser(System::User* user, UserDataAccountManagerForUser* *result);
};

// IUserDataAccountManagerForUser
struct IUserDataAccountManagerForUser_raw : IInspectable {
	virtual STDMETHODIMP _RequestStoreAsync(UserDataAccountStoreAccessType storeAccessType, Foundation::IAsyncOperation<UserDataAccountStore*>* *result);
	virtual STDMETHODIMP _get_User(System::User* *value);
};
template<typename X> struct IUserDataAccountManagerForUser_adaptor : X {
	union {
		struct : property {
			ptr<System::User> get() { System::User* value; hrcheck(enc(&IUserDataAccountManagerForUser_adaptor::User)->_get_User(&value)); return from_abi(value); }
			ptr<System::User> operator()() { return get(); }
			operator ptr<System::User> () { return get(); }
			ptr<System::User> operator->() { return get(); }
		} User;
	};
	ptr<Foundation::IAsyncOperation<ptr<UserDataAccountStore>>> RequestStoreAsync(UserDataAccountStoreAccessType storeAccessType) { Foundation::IAsyncOperation<UserDataAccountStore*>* result; hrcheck(X::get()->_RequestStoreAsync(storeAccessType, &result)); return from_abi(result); }
	IUserDataAccountManagerForUser_adaptor() {}
};
template<typename X> struct adapt<IUserDataAccountManagerForUser, X> : Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser_adaptor<X> { typedef adapt IUserDataAccountManagerForUser; };
struct IUserDataAccountManagerForUser : IUserDataAccountManagerForUser_raw, generate<IUserDataAccountManagerForUser> {};

// UserDataAccountManagerForUser
template<typename X> struct statics<UserDataAccountManagerForUser, X> : X {
	typedef typename X::root_type UserDataAccountManagerForUser;
};
struct UserDataAccountManagerForUser : generate<UserDataAccountManagerForUser> {};

// UserDataAccountManager
template<typename> struct UserDataAccountManager_statics {
	static ptr<UserDataAccountManagerForUser> GetForUser(pptr<System::User> user) { UserDataAccountManagerForUser* result; hrcheck(get_activation_factory<UserDataAccountManager, IUserDataAccountManagerStatics2>()->_GetForUser(user, &result)); return from_abi(result); }
	static ptr<Foundation::IAsyncOperation<ptr<UserDataAccountStore>>> RequestStoreAsync(UserDataAccountStoreAccessType storeAccessType) { Foundation::IAsyncOperation<UserDataAccountStore*>* result; hrcheck(get_activation_factory<UserDataAccountManager, IUserDataAccountManagerStatics>()->_RequestStoreAsync(storeAccessType, &result)); return from_abi(result); }
	static ptr<Foundation::IAsyncOperation<hstring>> ShowAddAccountAsync(UserDataAccountContentKinds contentKinds) { Foundation::IAsyncOperation<HSTRING>* result; hrcheck(get_activation_factory<UserDataAccountManager, IUserDataAccountManagerStatics>()->_ShowAddAccountAsync(contentKinds, &result)); return from_abi(result); }
	static ptr<Foundation::IAsyncAction> ShowAccountSettingsAsync(hstring_ref id) { Foundation::IAsyncAction* result; hrcheck(get_activation_factory<UserDataAccountManager, IUserDataAccountManagerStatics>()->_ShowAccountSettingsAsync(id, &result)); return from_abi(result); }
	static ptr<Foundation::IAsyncAction> ShowAccountErrorResolverAsync(hstring_ref id) { Foundation::IAsyncAction* result; hrcheck(get_activation_factory<UserDataAccountManager, IUserDataAccountManagerStatics>()->_ShowAccountErrorResolverAsync(id, &result)); return from_abi(result); }
};

template<typename X> struct statics<UserDataAccountManager, X> : X, Windows::ApplicationModel::UserDataAccounts::UserDataAccountManager_statics<void> {
	typedef typename X::root_type UserDataAccountManager;
};
struct UserDataAccountManager : generate<UserDataAccountManager> {};
}}}
} // namespace iso_winrt
