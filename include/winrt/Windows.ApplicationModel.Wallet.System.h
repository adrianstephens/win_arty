#pragma once
// generated by isopod tools
// namespaces:
// Windows.ApplicationModel.Wallet.System

#include "Windows.ApplicationModel.Wallet.System.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace Wallet {
struct WalletItem;
}}
namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}
namespace Storage { namespace Streams {
struct IRandomAccessStreamReference;
}}}

// defs

template<> struct def<Windows::ApplicationModel::Wallet::System::WalletItemAppAssociation> : enum_type<int> {};
template<> struct def<Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore> : class_type<Platform::Object, Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore, Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2> {};
template<> struct def<Windows::ApplicationModel::Wallet::System::IWalletManagerSystemStatics> : interface_type<> {};
template<> struct def<Windows::ApplicationModel::Wallet::System::WalletManagerSystem> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore> { define_guid(0x522E2BFF, 0x96A2, 0x4A17, 0x8D, 0x19, 0xFE, 0x1D, 0x9F, 0x83, 0x75, 0x61);};
template<> struct uuid<Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2> { define_guid(0xF98D3A4E, 0xBE00, 0x4FDD, 0x97, 0x34, 0x6C, 0x11, 0x3C, 0x1A, 0xC1, 0xCB);};
template<> struct uuid<Windows::ApplicationModel::Wallet::System::IWalletManagerSystemStatics> { define_guid(0xBEE8EB89, 0x2634, 0x4B9A, 0x8B, 0x23, 0xEE, 0x89, 0x3, 0xC9, 0x1F, 0xE0);};

// types

namespace Windows { namespace ApplicationModel { namespace Wallet { namespace System {

// IWalletItemSystemStore
struct IWalletItemSystemStore_raw : IInspectable {
	virtual STDMETHODIMP _GetItemsAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<WalletItem*>*>* *operation);
	virtual STDMETHODIMP _DeleteAsync(WalletItem* item, Foundation::IAsyncAction* *operation);
	virtual STDMETHODIMP _ImportItemAsync(Storage::Streams::IRandomAccessStreamReference* stream, Foundation::IAsyncOperation<WalletItem*>* *operation);
	virtual STDMETHODIMP _GetAppStatusForItem(WalletItem* item, WalletItemAppAssociation *result);
	virtual STDMETHODIMP _LaunchAppForItemAsync(WalletItem* item, Foundation::IAsyncOperation<bool>* *operation);
};
template<typename X> struct IWalletItemSystemStore_adaptor : X {
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<WalletItem>>>>> GetItemsAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<WalletItem*>*>* operation; hrcheck(X::get()->_GetItemsAsync(&operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncAction> DeleteAsync(pptr<WalletItem> item) { Foundation::IAsyncAction* operation; hrcheck(X::get()->_DeleteAsync(item, &operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<WalletItem>>> ImportItemAsync(pptr<Storage::Streams::IRandomAccessStreamReference> stream) { Foundation::IAsyncOperation<WalletItem*>* operation; hrcheck(X::get()->_ImportItemAsync(stream, &operation)); return from_abi(operation); }
	WalletItemAppAssociation GetAppStatusForItem(pptr<WalletItem> item) { WalletItemAppAssociation result; hrcheck(X::get()->_GetAppStatusForItem(item, &result)); return result; }
	ptr<Foundation::IAsyncOperation<bool>> LaunchAppForItemAsync(pptr<WalletItem> item) { Foundation::IAsyncOperation<bool>* operation; hrcheck(X::get()->_LaunchAppForItemAsync(item, &operation)); return from_abi(operation); }
};
template<typename X> struct adapt<IWalletItemSystemStore, X> : Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore_adaptor<X> { typedef adapt IWalletItemSystemStore; };
struct IWalletItemSystemStore : IWalletItemSystemStore_raw, generate<IWalletItemSystemStore> {};

// IWalletItemSystemStore2
struct IWalletItemSystemStore2_raw : IInspectable {
	virtual STDMETHODIMP _add_ItemsChanged(Foundation::TypedEventHandler<WalletItemSystemStore*, IInspectable*>* handler, Foundation::EventRegistrationToken *cookie);
	virtual STDMETHODIMP _remove_ItemsChanged(Foundation::EventRegistrationToken cookie);
};
template<typename X> struct IWalletItemSystemStore2_adaptor : X {
	union {
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<WalletItemSystemStore>, object>> handler) { Foundation::EventRegistrationToken cookie; hrcheck(enc(&IWalletItemSystemStore2_adaptor::ItemsChanged)->_add_ItemsChanged(to_abi(handler), &cookie)); return cookie; }
			void operator-=(const Foundation::EventRegistrationToken& cookie) { hrcheck(enc(&IWalletItemSystemStore2_adaptor::ItemsChanged)->_remove_ItemsChanged(cookie)); }
		} ItemsChanged;
	};
	IWalletItemSystemStore2_adaptor() {}
};
template<typename X> struct adapt<IWalletItemSystemStore2, X> : Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2_adaptor<X> { typedef adapt IWalletItemSystemStore2; };
struct IWalletItemSystemStore2 : IWalletItemSystemStore2_raw, generate<IWalletItemSystemStore2> {};

// WalletItemSystemStore
template<typename X> struct statics<WalletItemSystemStore, X> : X {
	typedef typename X::root_type WalletItemSystemStore;
};
struct WalletItemSystemStore : generate<WalletItemSystemStore> {};

// IWalletManagerSystemStatics
struct IWalletManagerSystemStatics : IInspectable {
	virtual STDMETHODIMP _RequestStoreAsync(Foundation::IAsyncOperation<WalletItemSystemStore*>* *operation);
};

// WalletManagerSystem
template<typename> struct WalletManagerSystem_statics {
	static ptr<Foundation::IAsyncOperation<ptr<WalletItemSystemStore>>> RequestStoreAsync() { Foundation::IAsyncOperation<WalletItemSystemStore*>* operation; hrcheck(get_activation_factory<WalletManagerSystem, IWalletManagerSystemStatics>()->_RequestStoreAsync(&operation)); return from_abi(operation); }
};

template<typename X> struct statics<WalletManagerSystem, X> : X, Windows::ApplicationModel::Wallet::System::WalletManagerSystem_statics<void> {
	typedef typename X::root_type WalletManagerSystem;
};
struct WalletManagerSystem : generate<WalletManagerSystem> {};
}}}}
} // namespace iso_winrt
