#pragma once
// generated by isopod tools
// namespaces:
// Windows.ApplicationModel.SocialInfo.Provider

#include "Windows.ApplicationModel.SocialInfo.Provider.0.h"
#include "Windows.ApplicationModel.SocialInfo.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVector;
}}}

// defs

template<> struct def<Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> : class_type<Platform::Object, Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater> {};
template<> struct def<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> : class_type<Platform::Object, Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater> {};
template<> struct def<Windows::ApplicationModel::SocialInfo::Provider::SocialInfoProviderManager> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater> { define_guid(0x3CDE9DC9, 0x4800, 0x46CD, 0x86, 0x9B, 0x19, 0x73, 0xEC, 0x68, 0x5B, 0xDE);};
template<> struct uuid<Windows::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics> { define_guid(0x1B88E52B, 0x7787, 0x48D6, 0xAA, 0x12, 0xD8, 0xE8, 0xF4, 0x7A, 0xB8, 0x5A);};
template<> struct uuid<Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater> { define_guid(0x7A0C0AA7, 0xED89, 0x4BD5, 0xA8, 0xD9, 0x15, 0xF4, 0xD9, 0x86, 0x1C, 0x10);};

// types

namespace Windows { namespace ApplicationModel { namespace SocialInfo { namespace Provider {

// ISocialDashboardItemUpdater
struct ISocialDashboardItemUpdater_raw : IInspectable {
	virtual STDMETHODIMP _get_OwnerRemoteId(HSTRING *value);
	virtual STDMETHODIMP _get_Content(SocialFeedContent* *value);
	virtual STDMETHODIMP _get_Timestamp(Foundation::DateTime *value);
	virtual STDMETHODIMP _put_Timestamp(Foundation::DateTime value);
	virtual STDMETHODIMP _put_Thumbnail(SocialItemThumbnail* value);
	virtual STDMETHODIMP _get_Thumbnail(SocialItemThumbnail* *value);
	virtual STDMETHODIMP _CommitAsync(Foundation::IAsyncAction* *operation);
	virtual STDMETHODIMP _get_TargetUri(Foundation::Uri* *value);
	virtual STDMETHODIMP _put_TargetUri(Foundation::Uri* value);
};
template<typename X> struct ISocialDashboardItemUpdater_adaptor : X {
	union {
		struct : property {
			ptr<SocialFeedContent> get() { SocialFeedContent* value; hrcheck(enc(&ISocialDashboardItemUpdater_adaptor::Content)->_get_Content(&value)); return from_abi(value); }
			ptr<SocialFeedContent> operator()() { return get(); }
			operator ptr<SocialFeedContent> () { return get(); }
			ptr<SocialFeedContent> operator->() { return get(); }
		} Content;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ISocialDashboardItemUpdater_adaptor::OwnerRemoteId)->_get_OwnerRemoteId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} OwnerRemoteId;
		struct : property {
			ptr<Foundation::Uri> get() { Foundation::Uri* value; hrcheck(enc(&ISocialDashboardItemUpdater_adaptor::TargetUri)->_get_TargetUri(&value)); return from_abi(value); }
			ptr<Foundation::Uri> operator()() { return get(); }
			operator ptr<Foundation::Uri> () { return get(); }
			ptr<Foundation::Uri> operator->() { return get(); }
			void put(pptr<Foundation::Uri> value) { hrcheck(enc(&ISocialDashboardItemUpdater_adaptor::TargetUri)->_put_TargetUri(value)); }
			void operator=(pptr<Foundation::Uri> value) { put(value); }
			void operator()(pptr<Foundation::Uri> value) { put(value); }
		} TargetUri;
		struct : property {
			ptr<SocialItemThumbnail> get() { SocialItemThumbnail* value; hrcheck(enc(&ISocialDashboardItemUpdater_adaptor::Thumbnail)->_get_Thumbnail(&value)); return from_abi(value); }
			ptr<SocialItemThumbnail> operator()() { return get(); }
			operator ptr<SocialItemThumbnail> () { return get(); }
			ptr<SocialItemThumbnail> operator->() { return get(); }
			void put(pptr<SocialItemThumbnail> value) { hrcheck(enc(&ISocialDashboardItemUpdater_adaptor::Thumbnail)->_put_Thumbnail(value)); }
			void operator=(pptr<SocialItemThumbnail> value) { put(value); }
			void operator()(pptr<SocialItemThumbnail> value) { put(value); }
		} Thumbnail;
		struct : property {
			Foundation::DateTime get() { Foundation::DateTime value; hrcheck(enc(&ISocialDashboardItemUpdater_adaptor::Timestamp)->_get_Timestamp(&value)); return value; }
			Foundation::DateTime operator()() { return get(); }
			operator Foundation::DateTime () { return get(); }
			void put(const Foundation::DateTime& value) { hrcheck(enc(&ISocialDashboardItemUpdater_adaptor::Timestamp)->_put_Timestamp(value)); }
			void operator=(const Foundation::DateTime& value) { put(value); }
			void operator()(const Foundation::DateTime& value) { put(value); }
		} Timestamp;
	};
	ptr<Foundation::IAsyncAction> CommitAsync() { Foundation::IAsyncAction* operation; hrcheck(X::get()->_CommitAsync(&operation)); return from_abi(operation); }
	ISocialDashboardItemUpdater_adaptor() {}
};
template<typename X> struct adapt<ISocialDashboardItemUpdater, X> : Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater_adaptor<X> { typedef adapt ISocialDashboardItemUpdater; };
struct ISocialDashboardItemUpdater : ISocialDashboardItemUpdater_raw, generate<ISocialDashboardItemUpdater> {};

// ISocialInfoProviderManagerStatics
struct ISocialInfoProviderManagerStatics : IInspectable {
	virtual STDMETHODIMP _CreateSocialFeedUpdaterAsync(SocialFeedKind kind, SocialFeedUpdateMode mode, HSTRING ownerRemoteId, Foundation::IAsyncOperation<SocialFeedUpdater*>* *operation);
	virtual STDMETHODIMP _CreateDashboardItemUpdaterAsync(HSTRING ownerRemoteId, Foundation::IAsyncOperation<SocialDashboardItemUpdater*>* *operation);
	virtual STDMETHODIMP _UpdateBadgeCountValue(HSTRING itemRemoteId, int newCount);
	virtual STDMETHODIMP _ReportNewContentAvailable(HSTRING contactRemoteId, SocialFeedKind kind);
	virtual STDMETHODIMP _ProvisionAsync(Foundation::IAsyncOperation<bool>* *operation);
	virtual STDMETHODIMP _DeprovisionAsync(Foundation::IAsyncAction* *operation);
};

// ISocialFeedUpdater
struct ISocialFeedUpdater_raw : IInspectable {
	virtual STDMETHODIMP _get_OwnerRemoteId(HSTRING *value);
	virtual STDMETHODIMP _get_Kind(SocialFeedKind *value);
	virtual STDMETHODIMP _get_Items(Foundation::Collections::IVector<SocialFeedItem*>* *value);
	virtual STDMETHODIMP _CommitAsync(Foundation::IAsyncAction* *operation);
};
template<typename X> struct ISocialFeedUpdater_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVector<ptr<SocialFeedItem>>> get() { Foundation::Collections::IVector<SocialFeedItem*>* value; hrcheck(enc(&ISocialFeedUpdater_adaptor::Items)->_get_Items(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVector<ptr<SocialFeedItem>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVector<ptr<SocialFeedItem>>> () { return get(); }
			ptr<Foundation::Collections::IVector<ptr<SocialFeedItem>>> operator->() { return get(); }
		} Items;
		struct : property {
			SocialFeedKind get() { SocialFeedKind value; hrcheck(enc(&ISocialFeedUpdater_adaptor::Kind)->_get_Kind(&value)); return value; }
			SocialFeedKind operator()() { return get(); }
			operator SocialFeedKind () { return get(); }
		} Kind;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&ISocialFeedUpdater_adaptor::OwnerRemoteId)->_get_OwnerRemoteId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} OwnerRemoteId;
	};
	ptr<Foundation::IAsyncAction> CommitAsync() { Foundation::IAsyncAction* operation; hrcheck(X::get()->_CommitAsync(&operation)); return from_abi(operation); }
	ISocialFeedUpdater_adaptor() {}
};
template<typename X> struct adapt<ISocialFeedUpdater, X> : Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater_adaptor<X> { typedef adapt ISocialFeedUpdater; };
struct ISocialFeedUpdater : ISocialFeedUpdater_raw, generate<ISocialFeedUpdater> {};

// SocialFeedUpdater
template<typename X> struct statics<SocialFeedUpdater, X> : X {
	typedef typename X::root_type SocialFeedUpdater;
};
struct SocialFeedUpdater : generate<SocialFeedUpdater> {};

// SocialDashboardItemUpdater
template<typename X> struct statics<SocialDashboardItemUpdater, X> : X {
	typedef typename X::root_type SocialDashboardItemUpdater;
};
struct SocialDashboardItemUpdater : generate<SocialDashboardItemUpdater> {};

// SocialInfoProviderManager
template<typename> struct SocialInfoProviderManager_statics {
	static ptr<Foundation::IAsyncOperation<ptr<SocialFeedUpdater>>> CreateSocialFeedUpdaterAsync(SocialFeedKind kind, SocialFeedUpdateMode mode, hstring_ref ownerRemoteId) { Foundation::IAsyncOperation<SocialFeedUpdater*>* operation; hrcheck(get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>()->_CreateSocialFeedUpdaterAsync(kind, mode, ownerRemoteId, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<ptr<SocialDashboardItemUpdater>>> CreateDashboardItemUpdaterAsync(hstring_ref ownerRemoteId) { Foundation::IAsyncOperation<SocialDashboardItemUpdater*>* operation; hrcheck(get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>()->_CreateDashboardItemUpdaterAsync(ownerRemoteId, &operation)); return from_abi(operation); }
	static void UpdateBadgeCountValue(hstring_ref itemRemoteId, int newCount) { hrcheck(get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>()->_UpdateBadgeCountValue(itemRemoteId, newCount)); }
	static void ReportNewContentAvailable(hstring_ref contactRemoteId, SocialFeedKind kind) { hrcheck(get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>()->_ReportNewContentAvailable(contactRemoteId, kind)); }
	static ptr<Foundation::IAsyncOperation<bool>> ProvisionAsync() { Foundation::IAsyncOperation<bool>* operation; hrcheck(get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>()->_ProvisionAsync(&operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncAction> DeprovisionAsync() { Foundation::IAsyncAction* operation; hrcheck(get_activation_factory<SocialInfoProviderManager, ISocialInfoProviderManagerStatics>()->_DeprovisionAsync(&operation)); return from_abi(operation); }
};

template<typename X> struct statics<SocialInfoProviderManager, X> : X, Windows::ApplicationModel::SocialInfo::Provider::SocialInfoProviderManager_statics<void> {
	typedef typename X::root_type SocialInfoProviderManager;
};
struct SocialInfoProviderManager : generate<SocialInfoProviderManager> {};
}}}}
} // namespace iso_winrt
