#pragma once
// generated by isopod tools
// namespaces:
// Windows.ApplicationModel.UserDataAccounts.Provider

#include "Windows.ApplicationModel.UserDataAccounts.Provider.0.h"
#include "Windows.ApplicationModel.UserDataAccounts.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}}

// defs

template<> struct def<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderOperationKind> : enum_type<int> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderPartnerAccountKind> : enum_type<int> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation> : overridable_type<> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation> : interface_type<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo> : class_type<Platform::Object, Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation> : interface_type<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation> : interface_type<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderAddAccountOperation> : class_type<Platform::Object, Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderSettingsOperation> : class_type<Platform::Object, Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation> {};
template<> struct def<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderResolveErrorsOperation> : class_type<Platform::Object, Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation> {};

// uuids

template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation> { define_guid(0xA20AAD63, 0x888C, 0x4A62, 0xA3, 0xDD, 0x34, 0xD0, 0x7A, 0x80, 0x2B, 0x2B);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation> { define_guid(0xB9C72530, 0x3F84, 0x4B5D, 0x8E, 0xAA, 0x45, 0xE9, 0x7A, 0xA8, 0x42, 0xED);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo> { define_guid(0x5F200037, 0xF6EF, 0x4EC3, 0x86, 0x30, 0x1, 0x2C, 0x59, 0xC1, 0x14, 0x9F);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation> { define_guid(0x92034DB7, 0x8648, 0x4F30, 0xAC, 0xFA, 0x30, 0x2, 0x65, 0x8C, 0xA8, 0xD);};
template<> struct uuid<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation> { define_guid(0x6235DC15, 0xBFCB, 0x41E1, 0x99, 0x57, 0x97, 0x59, 0xA2, 0x88, 0x46, 0xCC);};

// types

namespace Windows { namespace ApplicationModel { namespace UserDataAccounts { namespace Provider {

// IUserDataAccountProviderOperation
struct IUserDataAccountProviderOperation_raw : IInspectable {
	virtual STDMETHODIMP _get_Kind(UserDataAccountProviderOperationKind *value) = 0;
};
template<typename X> struct IUserDataAccountProviderOperation_adaptor : X {
	union {
		struct : property {
			UserDataAccountProviderOperationKind get() { UserDataAccountProviderOperationKind value; hrcheck(enc(&IUserDataAccountProviderOperation_adaptor::Kind)->_get_Kind(&value)); return value; }
			UserDataAccountProviderOperationKind operator()() { return get(); }
			operator UserDataAccountProviderOperationKind () { return get(); }
		} Kind;
	};
	IUserDataAccountProviderOperation_adaptor() {}
};
template<typename X> struct adapt<IUserDataAccountProviderOperation, X> : Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation_adaptor<X> { typedef adapt IUserDataAccountProviderOperation; };
template<typename X> struct IUserDataAccountProviderOperation_unadaptor : X {
	STDMETHODIMP _get_Kind(UserDataAccountProviderOperationKind *value) { return hrtry([&, this] { get_prop(value, Kind); }); }
};
template<typename X> struct unadapt<IUserDataAccountProviderOperation, X> : Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation_unadaptor<X> {};
struct IUserDataAccountProviderOperation : IUserDataAccountProviderOperation_raw, generate<IUserDataAccountProviderOperation> {};

// IUserDataAccountProviderAddAccountOperation
struct IUserDataAccountProviderAddAccountOperation_raw : IInspectable {
	virtual STDMETHODIMP _get_ContentKinds(UserDataAccountContentKinds *value);
	virtual STDMETHODIMP _get_PartnerAccountInfos(Foundation::Collections::IVectorView<UserDataAccountPartnerAccountInfo*>* *value);
	virtual STDMETHODIMP _ReportCompleted(HSTRING userDataAccountId);
};
template<typename X> struct IUserDataAccountProviderAddAccountOperation_adaptor : X {
	union {
		struct : property {
			UserDataAccountContentKinds get() { UserDataAccountContentKinds value; hrcheck(enc(&IUserDataAccountProviderAddAccountOperation_adaptor::ContentKinds)->_get_ContentKinds(&value)); return value; }
			UserDataAccountContentKinds operator()() { return get(); }
			operator UserDataAccountContentKinds () { return get(); }
		} ContentKinds;
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<UserDataAccountPartnerAccountInfo>>> get() { Foundation::Collections::IVectorView<UserDataAccountPartnerAccountInfo*>* value; hrcheck(enc(&IUserDataAccountProviderAddAccountOperation_adaptor::PartnerAccountInfos)->_get_PartnerAccountInfos(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<UserDataAccountPartnerAccountInfo>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<UserDataAccountPartnerAccountInfo>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<UserDataAccountPartnerAccountInfo>>> operator->() { return get(); }
		} PartnerAccountInfos;
	};
	void ReportCompleted(hstring_ref userDataAccountId) { hrcheck(X::get()->_ReportCompleted(userDataAccountId)); }
	IUserDataAccountProviderAddAccountOperation_adaptor() {}
};
template<typename X> struct adapt<IUserDataAccountProviderAddAccountOperation, X> : Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation_adaptor<X> { typedef adapt IUserDataAccountProviderAddAccountOperation; };
struct IUserDataAccountProviderAddAccountOperation : IUserDataAccountProviderAddAccountOperation_raw, generate<IUserDataAccountProviderAddAccountOperation> {};

// IUserDataAccountPartnerAccountInfo
struct IUserDataAccountPartnerAccountInfo_raw : IInspectable {
	virtual STDMETHODIMP _get_DisplayName(HSTRING *value);
	virtual STDMETHODIMP _get_Priority(unsigned *value);
	virtual STDMETHODIMP _get_AccountKind(UserDataAccountProviderPartnerAccountKind *value);
};
template<typename X> struct IUserDataAccountPartnerAccountInfo_adaptor : X {
	union {
		struct : property {
			UserDataAccountProviderPartnerAccountKind get() { UserDataAccountProviderPartnerAccountKind value; hrcheck(enc(&IUserDataAccountPartnerAccountInfo_adaptor::AccountKind)->_get_AccountKind(&value)); return value; }
			UserDataAccountProviderPartnerAccountKind operator()() { return get(); }
			operator UserDataAccountProviderPartnerAccountKind () { return get(); }
		} AccountKind;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserDataAccountPartnerAccountInfo_adaptor::DisplayName)->_get_DisplayName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DisplayName;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IUserDataAccountPartnerAccountInfo_adaptor::Priority)->_get_Priority(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} Priority;
	};
	IUserDataAccountPartnerAccountInfo_adaptor() {}
};
template<typename X> struct adapt<IUserDataAccountPartnerAccountInfo, X> : Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo_adaptor<X> { typedef adapt IUserDataAccountPartnerAccountInfo; };
struct IUserDataAccountPartnerAccountInfo : IUserDataAccountPartnerAccountInfo_raw, generate<IUserDataAccountPartnerAccountInfo> {};

// UserDataAccountPartnerAccountInfo
template<typename X> struct statics<UserDataAccountPartnerAccountInfo, X> : X {
	typedef typename X::root_type UserDataAccountPartnerAccountInfo;
};
struct UserDataAccountPartnerAccountInfo : generate<UserDataAccountPartnerAccountInfo> {};

// IUserDataAccountProviderSettingsOperation
struct IUserDataAccountProviderSettingsOperation_raw : IInspectable {
	virtual STDMETHODIMP _get_UserDataAccountId(HSTRING *value);
	virtual STDMETHODIMP _ReportCompleted();
};
template<typename X> struct IUserDataAccountProviderSettingsOperation_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserDataAccountProviderSettingsOperation_adaptor::UserDataAccountId)->_get_UserDataAccountId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} UserDataAccountId;
	};
	void ReportCompleted() { hrcheck(X::get()->_ReportCompleted()); }
	IUserDataAccountProviderSettingsOperation_adaptor() {}
};
template<typename X> struct adapt<IUserDataAccountProviderSettingsOperation, X> : Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation_adaptor<X> { typedef adapt IUserDataAccountProviderSettingsOperation; };
struct IUserDataAccountProviderSettingsOperation : IUserDataAccountProviderSettingsOperation_raw, generate<IUserDataAccountProviderSettingsOperation> {};

// IUserDataAccountProviderResolveErrorsOperation
struct IUserDataAccountProviderResolveErrorsOperation_raw : IInspectable {
	virtual STDMETHODIMP _get_UserDataAccountId(HSTRING *value);
	virtual STDMETHODIMP _ReportCompleted();
};
template<typename X> struct IUserDataAccountProviderResolveErrorsOperation_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUserDataAccountProviderResolveErrorsOperation_adaptor::UserDataAccountId)->_get_UserDataAccountId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} UserDataAccountId;
	};
	void ReportCompleted() { hrcheck(X::get()->_ReportCompleted()); }
	IUserDataAccountProviderResolveErrorsOperation_adaptor() {}
};
template<typename X> struct adapt<IUserDataAccountProviderResolveErrorsOperation, X> : Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation_adaptor<X> { typedef adapt IUserDataAccountProviderResolveErrorsOperation; };
struct IUserDataAccountProviderResolveErrorsOperation : IUserDataAccountProviderResolveErrorsOperation_raw, generate<IUserDataAccountProviderResolveErrorsOperation> {};

// UserDataAccountProviderAddAccountOperation
template<typename X> struct statics<UserDataAccountProviderAddAccountOperation, X> : X {
	typedef typename X::root_type UserDataAccountProviderAddAccountOperation;
};
struct UserDataAccountProviderAddAccountOperation : generate<UserDataAccountProviderAddAccountOperation> {};

// UserDataAccountProviderSettingsOperation
template<typename X> struct statics<UserDataAccountProviderSettingsOperation, X> : X {
	typedef typename X::root_type UserDataAccountProviderSettingsOperation;
};
struct UserDataAccountProviderSettingsOperation : generate<UserDataAccountProviderSettingsOperation> {};

// UserDataAccountProviderResolveErrorsOperation
template<typename X> struct statics<UserDataAccountProviderResolveErrorsOperation, X> : X {
	typedef typename X::root_type UserDataAccountProviderResolveErrorsOperation;
};
struct UserDataAccountProviderResolveErrorsOperation : generate<UserDataAccountProviderResolveErrorsOperation> {};
}}}}
} // namespace iso_winrt