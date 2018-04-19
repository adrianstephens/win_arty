#pragma once
// generated by isopod tools
// namespaces:
// Windows.Storage.BulkAccess

#include "Windows.Storage.BulkAccess.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.FileProperties.0.h"
#include "Windows.Storage.Streams.h"
#include "Windows.Storage.Search.h"
#include "Windows.Storage.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}}

// defs

template<> struct def<Windows::Storage::BulkAccess::IFileInformationFactoryFactory> : interface_type<> {};
template<> struct def<Windows::Storage::BulkAccess::IFileInformationFactory> : interface_type<> {};
template<> struct def<Windows::Storage::BulkAccess::FileInformationFactory> : class_type<Platform::Object, Windows::Storage::BulkAccess::IFileInformationFactory>, custom_activators {};
template<> struct def<Windows::Storage::BulkAccess::IStorageItemInformation> : overridable_type<> {};
template<> struct def<Windows::Storage::BulkAccess::FileInformation> : class_type<Platform::Object, Windows::Storage::BulkAccess::IStorageItemInformation, Windows::Storage::IStorageFile, Windows::Storage::Streams::IInputStreamReference, Windows::Storage::Streams::IRandomAccessStreamReference, Windows::Storage::IStorageItem, Windows::Storage::IStorageItemProperties, Windows::Storage::IStorageItem2, Windows::Storage::IStorageItemPropertiesWithProvider, Windows::Storage::IStorageFilePropertiesWithAvailability, Windows::Storage::IStorageFile2> {};
template<> struct def<Windows::Storage::BulkAccess::FolderInformation> : class_type<Platform::Object, Windows::Storage::BulkAccess::IStorageItemInformation, Windows::Storage::IStorageFolder, Windows::Storage::IStorageItem, Windows::Storage::IStorageItemProperties, Windows::Storage::Search::IStorageFolderQueryOperations, Windows::Storage::IStorageItem2, Windows::Storage::IStorageFolder2, Windows::Storage::IStorageItemPropertiesWithProvider> {};

// uuids

template<> struct uuid<Windows::Storage::BulkAccess::IFileInformationFactoryFactory> { define_guid(0x84EA0E7D, 0xE4A2, 0x4F00, 0x8A, 0xFA, 0xAF, 0x5E, 0xF, 0x82, 0x6B, 0xD5);};
template<> struct uuid<Windows::Storage::BulkAccess::IFileInformationFactory> { define_guid(0x401D88BE, 0x960F, 0x4D6D, 0xA7, 0xD0, 0x1A, 0x38, 0x61, 0xE7, 0x6C, 0x83);};
template<> struct uuid<Windows::Storage::BulkAccess::IStorageItemInformation> { define_guid(0x87A5CB8B, 0x8972, 0x4F40, 0x8D, 0xE0, 0xD8, 0x6F, 0xB1, 0x79, 0xD8, 0xFA);};

// types

namespace Windows { namespace Storage { namespace BulkAccess {

// IFileInformationFactoryFactory
struct IFileInformationFactoryFactory : IInspectable {
	virtual STDMETHODIMP _CreateWithMode(Search::IStorageQueryResultBase* queryResult, FileProperties::ThumbnailMode mode, FileInformationFactory* *value);
	virtual STDMETHODIMP _CreateWithModeAndSize(Search::IStorageQueryResultBase* queryResult, FileProperties::ThumbnailMode mode, unsigned requestedThumbnailSize, FileInformationFactory* *value);
	virtual STDMETHODIMP _CreateWithModeAndSizeAndOptions(Search::IStorageQueryResultBase* queryResult, FileProperties::ThumbnailMode mode, unsigned requestedThumbnailSize, FileProperties::ThumbnailOptions thumbnailOptions, FileInformationFactory* *value);
	virtual STDMETHODIMP _CreateWithModeAndSizeAndOptionsAndFlags(Search::IStorageQueryResultBase* queryResult, FileProperties::ThumbnailMode mode, unsigned requestedThumbnailSize, FileProperties::ThumbnailOptions thumbnailOptions, bool delayLoad, FileInformationFactory* *value);
};

// IFileInformationFactory
struct IFileInformationFactory_raw : IInspectable {
	virtual STDMETHODIMP _GetItemsAsync(unsigned startIndex, unsigned maxItemsToRetrieve, Foundation::IAsyncOperation<Foundation::Collections::IVectorView<IStorageItemInformation*>*>* *operation);
	virtual STDMETHODIMP _GetItemsAsyncDefaultStartAndCount(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<IStorageItemInformation*>*>* *operation);
	virtual STDMETHODIMP _GetFilesAsync(unsigned startIndex, unsigned maxItemsToRetrieve, Foundation::IAsyncOperation<Foundation::Collections::IVectorView<FileInformation*>*>* *operation);
	virtual STDMETHODIMP _GetFilesAsyncDefaultStartAndCount(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<FileInformation*>*>* *operation);
	virtual STDMETHODIMP _GetFoldersAsync(unsigned startIndex, unsigned maxItemsToRetrieve, Foundation::IAsyncOperation<Foundation::Collections::IVectorView<FolderInformation*>*>* *operation);
	virtual STDMETHODIMP _GetFoldersAsyncDefaultStartAndCount(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<FolderInformation*>*>* *operation);
	virtual STDMETHODIMP _GetVirtualizedItemsVector(IInspectable* *vector);
	virtual STDMETHODIMP _GetVirtualizedFilesVector(IInspectable* *vector);
	virtual STDMETHODIMP _GetVirtualizedFoldersVector(IInspectable* *vector);
};
template<typename X> struct IFileInformationFactory_adaptor : X {
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<IStorageItemInformation>>>>> GetItemsAsync(unsigned startIndex, unsigned maxItemsToRetrieve) { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<IStorageItemInformation*>*>* operation; hrcheck(X::get()->_GetItemsAsync(startIndex, maxItemsToRetrieve, &operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<IStorageItemInformation>>>>> GetItemsAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<IStorageItemInformation*>*>* operation; hrcheck(X::get()->_GetItemsAsyncDefaultStartAndCount(&operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<FileInformation>>>>> GetFilesAsync(unsigned startIndex, unsigned maxItemsToRetrieve) { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<FileInformation*>*>* operation; hrcheck(X::get()->_GetFilesAsync(startIndex, maxItemsToRetrieve, &operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<FileInformation>>>>> GetFilesAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<FileInformation*>*>* operation; hrcheck(X::get()->_GetFilesAsyncDefaultStartAndCount(&operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<FolderInformation>>>>> GetFoldersAsync(unsigned startIndex, unsigned maxItemsToRetrieve) { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<FolderInformation*>*>* operation; hrcheck(X::get()->_GetFoldersAsync(startIndex, maxItemsToRetrieve, &operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<FolderInformation>>>>> GetFoldersAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<FolderInformation*>*>* operation; hrcheck(X::get()->_GetFoldersAsyncDefaultStartAndCount(&operation)); return from_abi(operation); }
	object GetVirtualizedItemsVector() { IInspectable* vector; hrcheck(X::get()->_GetVirtualizedItemsVector(&vector)); return from_abi(vector); }
	object GetVirtualizedFilesVector() { IInspectable* vector; hrcheck(X::get()->_GetVirtualizedFilesVector(&vector)); return from_abi(vector); }
	object GetVirtualizedFoldersVector() { IInspectable* vector; hrcheck(X::get()->_GetVirtualizedFoldersVector(&vector)); return from_abi(vector); }
};
template<typename X> struct adapt<IFileInformationFactory, X> : Windows::Storage::BulkAccess::IFileInformationFactory_adaptor<X> { typedef adapt IFileInformationFactory; };
struct IFileInformationFactory : IFileInformationFactory_raw, generate<IFileInformationFactory> {};

// FileInformationFactory
template<typename> struct FileInformationFactory_statics {
	static FileInformationFactory *activate(pptr<Search::IStorageQueryResultBase> queryResult, FileProperties::ThumbnailMode mode) { FileInformationFactory *value; hrcheck(get_activation_factory<FileInformationFactory, IFileInformationFactoryFactory>()->_CreateWithMode(queryResult, mode, &value)); return value; }
	static FileInformationFactory *activate(pptr<Search::IStorageQueryResultBase> queryResult, FileProperties::ThumbnailMode mode, unsigned requestedThumbnailSize) { FileInformationFactory *value; hrcheck(get_activation_factory<FileInformationFactory, IFileInformationFactoryFactory>()->_CreateWithModeAndSize(queryResult, mode, requestedThumbnailSize, &value)); return value; }
	static FileInformationFactory *activate(pptr<Search::IStorageQueryResultBase> queryResult, FileProperties::ThumbnailMode mode, unsigned requestedThumbnailSize, FileProperties::ThumbnailOptions thumbnailOptions) { FileInformationFactory *value; hrcheck(get_activation_factory<FileInformationFactory, IFileInformationFactoryFactory>()->_CreateWithModeAndSizeAndOptions(queryResult, mode, requestedThumbnailSize, thumbnailOptions, &value)); return value; }
	static FileInformationFactory *activate(pptr<Search::IStorageQueryResultBase> queryResult, FileProperties::ThumbnailMode mode, unsigned requestedThumbnailSize, FileProperties::ThumbnailOptions thumbnailOptions, bool delayLoad) { FileInformationFactory *value; hrcheck(get_activation_factory<FileInformationFactory, IFileInformationFactoryFactory>()->_CreateWithModeAndSizeAndOptionsAndFlags(queryResult, mode, requestedThumbnailSize, thumbnailOptions, delayLoad, &value)); return value; }
};

template<typename X> struct statics<FileInformationFactory, X> : X, Windows::Storage::BulkAccess::FileInformationFactory_statics<void> {
	using Windows::Storage::BulkAccess::FileInformationFactory_statics<void>::activate;
	typedef typename X::root_type FileInformationFactory;
};
struct FileInformationFactory : generate<FileInformationFactory> {
	using IFileInformationFactory::GetFoldersAsync;
	using IFileInformationFactory::GetItemsAsync;
	using IFileInformationFactory::GetFilesAsync;
};

// IStorageItemInformation
struct IStorageItemInformation_raw : IInspectable {
	virtual STDMETHODIMP _get_MusicProperties(FileProperties::MusicProperties* *value) = 0;
	virtual STDMETHODIMP _get_VideoProperties(FileProperties::VideoProperties* *value) = 0;
	virtual STDMETHODIMP _get_ImageProperties(FileProperties::ImageProperties* *value) = 0;
	virtual STDMETHODIMP _get_DocumentProperties(FileProperties::DocumentProperties* *value) = 0;
	virtual STDMETHODIMP _get_BasicProperties(FileProperties::BasicProperties* *value) = 0;
	virtual STDMETHODIMP _get_Thumbnail(FileProperties::StorageItemThumbnail* *value) = 0;
	virtual STDMETHODIMP _add_ThumbnailUpdated(Foundation::TypedEventHandler<IStorageItemInformation*, IInspectable*>* changedHandler, Foundation::EventRegistrationToken *eventCookie) = 0;
	virtual STDMETHODIMP _remove_ThumbnailUpdated(Foundation::EventRegistrationToken eventCookie) = 0;
	virtual STDMETHODIMP _add_PropertiesUpdated(Foundation::TypedEventHandler<IStorageItemInformation*, IInspectable*>* changedHandler, Foundation::EventRegistrationToken *eventCookie) = 0;
	virtual STDMETHODIMP _remove_PropertiesUpdated(Foundation::EventRegistrationToken eventCookie) = 0;
};
template<typename X> struct IStorageItemInformation_adaptor : X {
	union {
		struct : property {
			ptr<FileProperties::BasicProperties> get() { FileProperties::BasicProperties* value; hrcheck(enc(&IStorageItemInformation_adaptor::BasicProperties)->_get_BasicProperties(&value)); return from_abi(value); }
			ptr<FileProperties::BasicProperties> operator()() { return get(); }
			operator ptr<FileProperties::BasicProperties> () { return get(); }
			ptr<FileProperties::BasicProperties> operator->() { return get(); }
		} BasicProperties;
		struct : property {
			ptr<FileProperties::DocumentProperties> get() { FileProperties::DocumentProperties* value; hrcheck(enc(&IStorageItemInformation_adaptor::DocumentProperties)->_get_DocumentProperties(&value)); return from_abi(value); }
			ptr<FileProperties::DocumentProperties> operator()() { return get(); }
			operator ptr<FileProperties::DocumentProperties> () { return get(); }
			ptr<FileProperties::DocumentProperties> operator->() { return get(); }
		} DocumentProperties;
		struct : property {
			ptr<FileProperties::ImageProperties> get() { FileProperties::ImageProperties* value; hrcheck(enc(&IStorageItemInformation_adaptor::ImageProperties)->_get_ImageProperties(&value)); return from_abi(value); }
			ptr<FileProperties::ImageProperties> operator()() { return get(); }
			operator ptr<FileProperties::ImageProperties> () { return get(); }
			ptr<FileProperties::ImageProperties> operator->() { return get(); }
		} ImageProperties;
		struct : property {
			ptr<FileProperties::MusicProperties> get() { FileProperties::MusicProperties* value; hrcheck(enc(&IStorageItemInformation_adaptor::MusicProperties)->_get_MusicProperties(&value)); return from_abi(value); }
			ptr<FileProperties::MusicProperties> operator()() { return get(); }
			operator ptr<FileProperties::MusicProperties> () { return get(); }
			ptr<FileProperties::MusicProperties> operator->() { return get(); }
		} MusicProperties;
		struct : property {
			ptr<FileProperties::StorageItemThumbnail> get() { FileProperties::StorageItemThumbnail* value; hrcheck(enc(&IStorageItemInformation_adaptor::Thumbnail)->_get_Thumbnail(&value)); return from_abi(value); }
			ptr<FileProperties::StorageItemThumbnail> operator()() { return get(); }
			operator ptr<FileProperties::StorageItemThumbnail> () { return get(); }
			ptr<FileProperties::StorageItemThumbnail> operator->() { return get(); }
		} Thumbnail;
		struct : property {
			ptr<FileProperties::VideoProperties> get() { FileProperties::VideoProperties* value; hrcheck(enc(&IStorageItemInformation_adaptor::VideoProperties)->_get_VideoProperties(&value)); return from_abi(value); }
			ptr<FileProperties::VideoProperties> operator()() { return get(); }
			operator ptr<FileProperties::VideoProperties> () { return get(); }
			ptr<FileProperties::VideoProperties> operator->() { return get(); }
		} VideoProperties;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<IStorageItemInformation>, object>> changedHandler) { Foundation::EventRegistrationToken eventCookie; hrcheck(enc(&IStorageItemInformation_adaptor::PropertiesUpdated)->_add_PropertiesUpdated(to_abi(changedHandler), &eventCookie)); return eventCookie; }
			void operator-=(const Foundation::EventRegistrationToken& eventCookie) { hrcheck(enc(&IStorageItemInformation_adaptor::PropertiesUpdated)->_remove_PropertiesUpdated(eventCookie)); }
		} PropertiesUpdated;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<IStorageItemInformation>, object>> changedHandler) { Foundation::EventRegistrationToken eventCookie; hrcheck(enc(&IStorageItemInformation_adaptor::ThumbnailUpdated)->_add_ThumbnailUpdated(to_abi(changedHandler), &eventCookie)); return eventCookie; }
			void operator-=(const Foundation::EventRegistrationToken& eventCookie) { hrcheck(enc(&IStorageItemInformation_adaptor::ThumbnailUpdated)->_remove_ThumbnailUpdated(eventCookie)); }
		} ThumbnailUpdated;
	};
	IStorageItemInformation_adaptor() {}
};
template<typename X> struct adapt<IStorageItemInformation, X> : Windows::Storage::BulkAccess::IStorageItemInformation_adaptor<X> { typedef adapt IStorageItemInformation; };
template<typename X> struct IStorageItemInformation_unadaptor : X {
	STDMETHODIMP _get_MusicProperties(FileProperties::MusicProperties* *value) { return hrtry([&, this] { get_prop(value, MusicProperties); }); }
	STDMETHODIMP _get_VideoProperties(FileProperties::VideoProperties* *value) { return hrtry([&, this] { get_prop(value, VideoProperties); }); }
	STDMETHODIMP _get_ImageProperties(FileProperties::ImageProperties* *value) { return hrtry([&, this] { get_prop(value, ImageProperties); }); }
	STDMETHODIMP _get_DocumentProperties(FileProperties::DocumentProperties* *value) { return hrtry([&, this] { get_prop(value, DocumentProperties); }); }
	STDMETHODIMP _get_BasicProperties(FileProperties::BasicProperties* *value) { return hrtry([&, this] { get_prop(value, BasicProperties); }); }
	STDMETHODIMP _get_Thumbnail(FileProperties::StorageItemThumbnail* *value) { return hrtry([&, this] { get_prop(value, Thumbnail); }); }
	STDMETHODIMP _add_ThumbnailUpdated(Foundation::TypedEventHandler<IStorageItemInformation*, IInspectable*>* changedHandler, Foundation::EventRegistrationToken *eventCookie) { return hrtry([&, this] { *eventCookie = X::get()->ThumbnailUpdated+=changedHandler; }); }
	STDMETHODIMP _remove_ThumbnailUpdated(Foundation::EventRegistrationToken eventCookie) { return hrtry([&, this] { X::get()->ThumbnailUpdated-=eventCookie; }); }
	STDMETHODIMP _add_PropertiesUpdated(Foundation::TypedEventHandler<IStorageItemInformation*, IInspectable*>* changedHandler, Foundation::EventRegistrationToken *eventCookie) { return hrtry([&, this] { *eventCookie = X::get()->PropertiesUpdated+=changedHandler; }); }
	STDMETHODIMP _remove_PropertiesUpdated(Foundation::EventRegistrationToken eventCookie) { return hrtry([&, this] { X::get()->PropertiesUpdated-=eventCookie; }); }
};
template<typename X> struct unadapt<IStorageItemInformation, X> : Windows::Storage::BulkAccess::IStorageItemInformation_unadaptor<X> {};
struct IStorageItemInformation : IStorageItemInformation_raw, generate<IStorageItemInformation> {};

// FileInformation
template<typename X> struct statics<FileInformation, X> : X {
	typedef typename X::root_type FileInformation;
};
struct FileInformation : generate<FileInformation> {
	using IStorageFile::MoveAsync;
	using IStorageFile::CopyAsync;
	using IStorageItemProperties::GetThumbnailAsync;
	using IStorageItem::DeleteAsync;
	using IStorageFile::OpenTransactedWriteAsync;
	using IStorageFile2::OpenTransactedWriteAsync;
	using IStorageItem::RenameAsync;
	using IStorageFile::OpenAsync;
	using IStorageFile2::OpenAsync;
};

// FolderInformation
template<typename X> struct statics<FolderInformation, X> : X {
	typedef typename X::root_type FolderInformation;
};
struct FolderInformation : generate<FolderInformation> {
	using IStorageFolderQueryOperations::GetFilesAsync;
	using IStorageFolder::GetFilesAsync;
	using IStorageFolder::CreateFolderAsync;
	using IStorageItemProperties::GetThumbnailAsync;
	using IStorageItem::DeleteAsync;
	using IStorageFolder::CreateFileAsync;
	using IStorageFolderQueryOperations::CreateFileQuery;
	using IStorageFolderQueryOperations::GetFoldersAsync;
	using IStorageFolder::GetFoldersAsync;
	using IStorageFolderQueryOperations::GetItemsAsync;
	using IStorageFolder::GetItemsAsync;
	using IStorageItem::RenameAsync;
	using IStorageFolderQueryOperations::CreateFolderQuery;
};
}}}
} // namespace iso_winrt
