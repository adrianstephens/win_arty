#pragma once
// generated by isopod tools
// namespaces:
// Windows.Storage.Pickers

#include "Windows.Storage.Pickers.0.h"
#include "Windows.Foundation.Collections.h"
#include "Windows.Storage.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation {
template<typename TResult> struct IAsyncOperation;
}}

// defs

template<> struct def<Windows::Storage::Pickers::PickerViewMode> : enum_type<int> {};
template<> struct def<Windows::Storage::Pickers::PickerLocationId> : enum_type<int> {};
template<> struct def<Windows::Storage::Pickers::FilePickerSelectedFilesArray> : class_type<Platform::Object, Windows::Foundation::Collections::IVectorView<ptr<Windows::Storage::StorageFile>>, Windows::Foundation::Collections::IIterable<ptr<Windows::Storage::StorageFile>>> {};
template<> struct def<Windows::Storage::Pickers::FilePickerFileTypesOrderedMap> : class_type<Platform::Object, Windows::Foundation::Collections::IMap<HSTRING, ptr<Windows::Foundation::Collections::IVector<HSTRING>>>, Windows::Foundation::Collections::IIterable<ptr<Windows::Foundation::Collections::IKeyValuePair<HSTRING, ptr<Windows::Foundation::Collections::IVector<HSTRING>>>>>> {};
template<> struct def<Windows::Storage::Pickers::FileExtensionVector> : class_type<Platform::Object, Windows::Foundation::Collections::IVector<HSTRING>, Windows::Foundation::Collections::IIterable<HSTRING>> {};
template<> struct def<Windows::Storage::Pickers::IFileOpenPicker> : interface_type<> {};
template<> struct def<Windows::Storage::Pickers::IFileOpenPicker2> : interface_type<Windows::Storage::Pickers::IFileOpenPicker> {};
template<> struct def<Windows::Storage::Pickers::IFileOpenPickerWithOperationId> : interface_type<> {};
template<> struct def<Windows::Storage::Pickers::IFileOpenPickerStatics> : interface_type<> {};
template<> struct def<Windows::Storage::Pickers::IFileSavePicker> : interface_type<> {};
template<> struct def<Windows::Storage::Pickers::IFileSavePicker2> : interface_type<Windows::Storage::Pickers::IFileSavePicker> {};
template<> struct def<Windows::Storage::Pickers::IFileSavePicker3> : interface_type<Windows::Storage::Pickers::IFileSavePicker> {};
template<> struct def<Windows::Storage::Pickers::IFolderPicker> : interface_type<> {};
template<> struct def<Windows::Storage::Pickers::IFolderPicker2> : interface_type<Windows::Storage::Pickers::IFolderPicker> {};
template<> struct def<Windows::Storage::Pickers::FileOpenPicker> : class_type<Platform::Object, Windows::Storage::Pickers::IFileOpenPicker, Windows::Storage::Pickers::IFileOpenPickerWithOperationId, Windows::Storage::Pickers::IFileOpenPicker2> {};
template<> struct def<Windows::Storage::Pickers::FileSavePicker> : class_type<Platform::Object, Windows::Storage::Pickers::IFileSavePicker, Windows::Storage::Pickers::IFileSavePicker2, Windows::Storage::Pickers::IFileSavePicker3> {};
template<> struct def<Windows::Storage::Pickers::FolderPicker> : class_type<Platform::Object, Windows::Storage::Pickers::IFolderPicker, Windows::Storage::Pickers::IFolderPicker2> {};

// uuids

template<> struct uuid<Windows::Storage::Pickers::IFileOpenPicker> { define_guid(0x2CA8278A, 0x12C5, 0x4C5F, 0x89, 0x77, 0x94, 0x54, 0x77, 0x93, 0xC2, 0x41);};
template<> struct uuid<Windows::Storage::Pickers::IFileOpenPicker2> { define_guid(0x8CEB6CD2, 0xB446, 0x46F7, 0xB2, 0x65, 0x90, 0xF8, 0xE5, 0x5A, 0xD6, 0x50);};
template<> struct uuid<Windows::Storage::Pickers::IFileOpenPickerWithOperationId> { define_guid(0x3F57B569, 0x2522, 0x4CA5, 0xAA, 0x73, 0xA1, 0x55, 0x9, 0xF1, 0xFC, 0xBF);};
template<> struct uuid<Windows::Storage::Pickers::IFileOpenPickerStatics> { define_guid(0x6821573B, 0x2F02, 0x4833, 0x96, 0xD4, 0xAB, 0xBF, 0xAD, 0x72, 0xB6, 0x7B);};
template<> struct uuid<Windows::Storage::Pickers::IFileSavePicker> { define_guid(0x3286FFCB, 0x617F, 0x4CC5, 0xAF, 0x6A, 0xB3, 0xFD, 0xF2, 0x9A, 0xD1, 0x45);};
template<> struct uuid<Windows::Storage::Pickers::IFileSavePicker2> { define_guid(0xEC313A2, 0xD24B, 0x449A, 0x81, 0x97, 0xE8, 0x91, 0x4, 0xFD, 0x42, 0xCC);};
template<> struct uuid<Windows::Storage::Pickers::IFileSavePicker3> { define_guid(0x698AEC69, 0xBA3C, 0x4E51, 0xBD, 0x90, 0x4A, 0xBC, 0xBB, 0xF4, 0xCF, 0xAF);};
template<> struct uuid<Windows::Storage::Pickers::IFolderPicker> { define_guid(0x84F7799, 0xF3FB, 0x400A, 0x99, 0xB1, 0x7B, 0x4A, 0x77, 0x2F, 0xD6, 0xD);};
template<> struct uuid<Windows::Storage::Pickers::IFolderPicker2> { define_guid(0x8EB3BA97, 0xDC85, 0x4616, 0xBE, 0x94, 0x96, 0x60, 0x88, 0x1F, 0x2F, 0x5D);};

// types

namespace Windows { namespace Storage { namespace Pickers {

// FilePickerSelectedFilesArray
template<typename X> struct statics<FilePickerSelectedFilesArray, X> : X {
	typedef typename X::root_type FilePickerSelectedFilesArray;
};
struct FilePickerSelectedFilesArray : generate<FilePickerSelectedFilesArray> {};

// FilePickerFileTypesOrderedMap
template<typename X> struct statics<FilePickerFileTypesOrderedMap, X> : X {
	typedef typename X::root_type FilePickerFileTypesOrderedMap;
};
struct FilePickerFileTypesOrderedMap : generate<FilePickerFileTypesOrderedMap> {};

// FileExtensionVector
template<typename X> struct statics<FileExtensionVector, X> : X {
	typedef typename X::root_type FileExtensionVector;
};
struct FileExtensionVector : generate<FileExtensionVector> {};

// IFileOpenPicker
struct IFileOpenPicker_raw : IInspectable {
	virtual STDMETHODIMP _get_ViewMode(PickerViewMode *value);
	virtual STDMETHODIMP _put_ViewMode(PickerViewMode value);
	virtual STDMETHODIMP _get_SettingsIdentifier(HSTRING *value);
	virtual STDMETHODIMP _put_SettingsIdentifier(HSTRING value);
	virtual STDMETHODIMP _get_SuggestedStartLocation(PickerLocationId *value);
	virtual STDMETHODIMP _put_SuggestedStartLocation(PickerLocationId value);
	virtual STDMETHODIMP _get_CommitButtonText(HSTRING *value);
	virtual STDMETHODIMP _put_CommitButtonText(HSTRING value);
	virtual STDMETHODIMP _get_FileTypeFilter(Foundation::Collections::IVector<HSTRING>* *value);
	virtual STDMETHODIMP _PickSingleFileAsync(Foundation::IAsyncOperation<StorageFile*>* *pickSingleFileOperation);
	virtual STDMETHODIMP _PickMultipleFilesAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<StorageFile*>*>* *pickMultipleFilesOperation);
};
template<typename X> struct IFileOpenPicker_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IFileOpenPicker_adaptor::CommitButtonText)->_get_CommitButtonText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IFileOpenPicker_adaptor::CommitButtonText)->_put_CommitButtonText(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} CommitButtonText;
		struct : property {
			ptr<Foundation::Collections::IVector<hstring>> get() { Foundation::Collections::IVector<HSTRING>* value; hrcheck(enc(&IFileOpenPicker_adaptor::FileTypeFilter)->_get_FileTypeFilter(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVector<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVector<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVector<hstring>> operator->() { return get(); }
		} FileTypeFilter;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IFileOpenPicker_adaptor::SettingsIdentifier)->_get_SettingsIdentifier(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IFileOpenPicker_adaptor::SettingsIdentifier)->_put_SettingsIdentifier(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} SettingsIdentifier;
		struct : property {
			PickerLocationId get() { PickerLocationId value; hrcheck(enc(&IFileOpenPicker_adaptor::SuggestedStartLocation)->_get_SuggestedStartLocation(&value)); return value; }
			PickerLocationId operator()() { return get(); }
			operator PickerLocationId () { return get(); }
			void put(PickerLocationId value) { hrcheck(enc(&IFileOpenPicker_adaptor::SuggestedStartLocation)->_put_SuggestedStartLocation(value)); }
			void operator=(PickerLocationId value) { put(value); }
			void operator()(PickerLocationId value) { put(value); }
		} SuggestedStartLocation;
		struct : property {
			PickerViewMode get() { PickerViewMode value; hrcheck(enc(&IFileOpenPicker_adaptor::ViewMode)->_get_ViewMode(&value)); return value; }
			PickerViewMode operator()() { return get(); }
			operator PickerViewMode () { return get(); }
			void put(PickerViewMode value) { hrcheck(enc(&IFileOpenPicker_adaptor::ViewMode)->_put_ViewMode(value)); }
			void operator=(PickerViewMode value) { put(value); }
			void operator()(PickerViewMode value) { put(value); }
		} ViewMode;
	};
	ptr<Foundation::IAsyncOperation<ptr<StorageFile>>> PickSingleFileAsync() { Foundation::IAsyncOperation<StorageFile*>* pickSingleFileOperation; hrcheck(X::get()->_PickSingleFileAsync(&pickSingleFileOperation)); return from_abi(pickSingleFileOperation); }
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<StorageFile>>>>> PickMultipleFilesAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<StorageFile*>*>* pickMultipleFilesOperation; hrcheck(X::get()->_PickMultipleFilesAsync(&pickMultipleFilesOperation)); return from_abi(pickMultipleFilesOperation); }
	IFileOpenPicker_adaptor() {}
};
template<typename X> struct adapt<IFileOpenPicker, X> : Windows::Storage::Pickers::IFileOpenPicker_adaptor<X> { typedef adapt IFileOpenPicker; };
struct IFileOpenPicker : IFileOpenPicker_raw, generate<IFileOpenPicker> {};

// IFileOpenPicker2
struct IFileOpenPicker2_raw : IInspectable {
	virtual STDMETHODIMP _get_ContinuationData(Foundation::Collections::ValueSet* *value);
	virtual STDMETHODIMP _PickSingleFileAndContinue();
	virtual STDMETHODIMP _PickMultipleFilesAndContinue();
};
template<typename X> struct IFileOpenPicker2_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::ValueSet> get() { Foundation::Collections::ValueSet* value; hrcheck(enc(&IFileOpenPicker2_adaptor::ContinuationData)->_get_ContinuationData(&value)); return from_abi(value); }
			ptr<Foundation::Collections::ValueSet> operator()() { return get(); }
			operator ptr<Foundation::Collections::ValueSet> () { return get(); }
			ptr<Foundation::Collections::ValueSet> operator->() { return get(); }
		} ContinuationData;
	};
	void PickSingleFileAndContinue() { hrcheck(X::get()->_PickSingleFileAndContinue()); }
	void PickMultipleFilesAndContinue() { hrcheck(X::get()->_PickMultipleFilesAndContinue()); }
	IFileOpenPicker2_adaptor() {}
};
template<typename X> struct adapt<IFileOpenPicker2, X> : Windows::Storage::Pickers::IFileOpenPicker2_adaptor<X> { typedef adapt IFileOpenPicker2; };
struct IFileOpenPicker2 : IFileOpenPicker2_raw, generate<IFileOpenPicker2> {};

// IFileOpenPickerWithOperationId
struct IFileOpenPickerWithOperationId_raw : IInspectable {
	virtual STDMETHODIMP _PickSingleFileAsync(HSTRING pickerOperationId, Foundation::IAsyncOperation<StorageFile*>* *pickSingleFileOperation);
};
template<typename X> struct IFileOpenPickerWithOperationId_adaptor : X {
	ptr<Foundation::IAsyncOperation<ptr<StorageFile>>> PickSingleFileAsync(hstring_ref pickerOperationId) { Foundation::IAsyncOperation<StorageFile*>* pickSingleFileOperation; hrcheck(X::get()->_PickSingleFileAsync(pickerOperationId, &pickSingleFileOperation)); return from_abi(pickSingleFileOperation); }
};
template<typename X> struct adapt<IFileOpenPickerWithOperationId, X> : Windows::Storage::Pickers::IFileOpenPickerWithOperationId_adaptor<X> { typedef adapt IFileOpenPickerWithOperationId; };
struct IFileOpenPickerWithOperationId : IFileOpenPickerWithOperationId_raw, generate<IFileOpenPickerWithOperationId> {};

// IFileOpenPickerStatics
struct IFileOpenPickerStatics : IInspectable {
	virtual STDMETHODIMP _ResumePickSingleFileAsync(Foundation::IAsyncOperation<StorageFile*>* *pickSingleFileOperation);
};

// IFileSavePicker
struct IFileSavePicker_raw : IInspectable {
	virtual STDMETHODIMP _get_SettingsIdentifier(HSTRING *value);
	virtual STDMETHODIMP _put_SettingsIdentifier(HSTRING value);
	virtual STDMETHODIMP _get_SuggestedStartLocation(PickerLocationId *value);
	virtual STDMETHODIMP _put_SuggestedStartLocation(PickerLocationId value);
	virtual STDMETHODIMP _get_CommitButtonText(HSTRING *value);
	virtual STDMETHODIMP _put_CommitButtonText(HSTRING value);
	virtual STDMETHODIMP _get_FileTypeChoices(Foundation::Collections::IMap<HSTRING, Foundation::Collections::IVector<HSTRING>*>* *value);
	virtual STDMETHODIMP _get_DefaultFileExtension(HSTRING *value);
	virtual STDMETHODIMP _put_DefaultFileExtension(HSTRING value);
	virtual STDMETHODIMP _get_SuggestedSaveFile(StorageFile* *value);
	virtual STDMETHODIMP _put_SuggestedSaveFile(StorageFile* value);
	virtual STDMETHODIMP _get_SuggestedFileName(HSTRING *value);
	virtual STDMETHODIMP _put_SuggestedFileName(HSTRING value);
	virtual STDMETHODIMP _PickSaveFileAsync(Foundation::IAsyncOperation<StorageFile*>* *pickSaveFileOperation);
};
template<typename X> struct IFileSavePicker_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IFileSavePicker_adaptor::CommitButtonText)->_get_CommitButtonText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IFileSavePicker_adaptor::CommitButtonText)->_put_CommitButtonText(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} CommitButtonText;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IFileSavePicker_adaptor::DefaultFileExtension)->_get_DefaultFileExtension(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IFileSavePicker_adaptor::DefaultFileExtension)->_put_DefaultFileExtension(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} DefaultFileExtension;
		struct : property {
			ptr<Foundation::Collections::IMap<hstring, ptr<Foundation::Collections::IVector<hstring>>>> get() { Foundation::Collections::IMap<HSTRING, Foundation::Collections::IVector<HSTRING>*>* value; hrcheck(enc(&IFileSavePicker_adaptor::FileTypeChoices)->_get_FileTypeChoices(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IMap<hstring, ptr<Foundation::Collections::IVector<hstring>>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IMap<hstring, ptr<Foundation::Collections::IVector<hstring>>>> () { return get(); }
			ptr<Foundation::Collections::IMap<hstring, ptr<Foundation::Collections::IVector<hstring>>>> operator->() { return get(); }
		} FileTypeChoices;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IFileSavePicker_adaptor::SettingsIdentifier)->_get_SettingsIdentifier(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IFileSavePicker_adaptor::SettingsIdentifier)->_put_SettingsIdentifier(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} SettingsIdentifier;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IFileSavePicker_adaptor::SuggestedFileName)->_get_SuggestedFileName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IFileSavePicker_adaptor::SuggestedFileName)->_put_SuggestedFileName(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} SuggestedFileName;
		struct : property {
			ptr<StorageFile> get() { StorageFile* value; hrcheck(enc(&IFileSavePicker_adaptor::SuggestedSaveFile)->_get_SuggestedSaveFile(&value)); return from_abi(value); }
			ptr<StorageFile> operator()() { return get(); }
			operator ptr<StorageFile> () { return get(); }
			ptr<StorageFile> operator->() { return get(); }
			void put(pptr<StorageFile> value) { hrcheck(enc(&IFileSavePicker_adaptor::SuggestedSaveFile)->_put_SuggestedSaveFile(value)); }
			void operator=(pptr<StorageFile> value) { put(value); }
			void operator()(pptr<StorageFile> value) { put(value); }
		} SuggestedSaveFile;
		struct : property {
			PickerLocationId get() { PickerLocationId value; hrcheck(enc(&IFileSavePicker_adaptor::SuggestedStartLocation)->_get_SuggestedStartLocation(&value)); return value; }
			PickerLocationId operator()() { return get(); }
			operator PickerLocationId () { return get(); }
			void put(PickerLocationId value) { hrcheck(enc(&IFileSavePicker_adaptor::SuggestedStartLocation)->_put_SuggestedStartLocation(value)); }
			void operator=(PickerLocationId value) { put(value); }
			void operator()(PickerLocationId value) { put(value); }
		} SuggestedStartLocation;
	};
	ptr<Foundation::IAsyncOperation<ptr<StorageFile>>> PickSaveFileAsync() { Foundation::IAsyncOperation<StorageFile*>* pickSaveFileOperation; hrcheck(X::get()->_PickSaveFileAsync(&pickSaveFileOperation)); return from_abi(pickSaveFileOperation); }
	IFileSavePicker_adaptor() {}
};
template<typename X> struct adapt<IFileSavePicker, X> : Windows::Storage::Pickers::IFileSavePicker_adaptor<X> { typedef adapt IFileSavePicker; };
struct IFileSavePicker : IFileSavePicker_raw, generate<IFileSavePicker> {};

// IFileSavePicker2
struct IFileSavePicker2_raw : IInspectable {
	virtual STDMETHODIMP _get_ContinuationData(Foundation::Collections::ValueSet* *value);
	virtual STDMETHODIMP _PickSaveFileAndContinue();
};
template<typename X> struct IFileSavePicker2_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::ValueSet> get() { Foundation::Collections::ValueSet* value; hrcheck(enc(&IFileSavePicker2_adaptor::ContinuationData)->_get_ContinuationData(&value)); return from_abi(value); }
			ptr<Foundation::Collections::ValueSet> operator()() { return get(); }
			operator ptr<Foundation::Collections::ValueSet> () { return get(); }
			ptr<Foundation::Collections::ValueSet> operator->() { return get(); }
		} ContinuationData;
	};
	void PickSaveFileAndContinue() { hrcheck(X::get()->_PickSaveFileAndContinue()); }
	IFileSavePicker2_adaptor() {}
};
template<typename X> struct adapt<IFileSavePicker2, X> : Windows::Storage::Pickers::IFileSavePicker2_adaptor<X> { typedef adapt IFileSavePicker2; };
struct IFileSavePicker2 : IFileSavePicker2_raw, generate<IFileSavePicker2> {};

// IFileSavePicker3
struct IFileSavePicker3_raw : IInspectable {
	virtual STDMETHODIMP _get_EnterpriseId(HSTRING *value);
	virtual STDMETHODIMP _put_EnterpriseId(HSTRING value);
};
template<typename X> struct IFileSavePicker3_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IFileSavePicker3_adaptor::EnterpriseId)->_get_EnterpriseId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IFileSavePicker3_adaptor::EnterpriseId)->_put_EnterpriseId(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} EnterpriseId;
	};
	IFileSavePicker3_adaptor() {}
};
template<typename X> struct adapt<IFileSavePicker3, X> : Windows::Storage::Pickers::IFileSavePicker3_adaptor<X> { typedef adapt IFileSavePicker3; };
struct IFileSavePicker3 : IFileSavePicker3_raw, generate<IFileSavePicker3> {};

// IFolderPicker
struct IFolderPicker_raw : IInspectable {
	virtual STDMETHODIMP _get_ViewMode(PickerViewMode *value);
	virtual STDMETHODIMP _put_ViewMode(PickerViewMode value);
	virtual STDMETHODIMP _get_SettingsIdentifier(HSTRING *value);
	virtual STDMETHODIMP _put_SettingsIdentifier(HSTRING value);
	virtual STDMETHODIMP _get_SuggestedStartLocation(PickerLocationId *value);
	virtual STDMETHODIMP _put_SuggestedStartLocation(PickerLocationId value);
	virtual STDMETHODIMP _get_CommitButtonText(HSTRING *value);
	virtual STDMETHODIMP _put_CommitButtonText(HSTRING value);
	virtual STDMETHODIMP _get_FileTypeFilter(Foundation::Collections::IVector<HSTRING>* *value);
	virtual STDMETHODIMP _PickSingleFolderAsync(Foundation::IAsyncOperation<StorageFolder*>* *pickSingleFolderOperation);
};
template<typename X> struct IFolderPicker_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IFolderPicker_adaptor::CommitButtonText)->_get_CommitButtonText(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IFolderPicker_adaptor::CommitButtonText)->_put_CommitButtonText(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} CommitButtonText;
		struct : property {
			ptr<Foundation::Collections::IVector<hstring>> get() { Foundation::Collections::IVector<HSTRING>* value; hrcheck(enc(&IFolderPicker_adaptor::FileTypeFilter)->_get_FileTypeFilter(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVector<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVector<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVector<hstring>> operator->() { return get(); }
		} FileTypeFilter;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IFolderPicker_adaptor::SettingsIdentifier)->_get_SettingsIdentifier(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IFolderPicker_adaptor::SettingsIdentifier)->_put_SettingsIdentifier(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} SettingsIdentifier;
		struct : property {
			PickerLocationId get() { PickerLocationId value; hrcheck(enc(&IFolderPicker_adaptor::SuggestedStartLocation)->_get_SuggestedStartLocation(&value)); return value; }
			PickerLocationId operator()() { return get(); }
			operator PickerLocationId () { return get(); }
			void put(PickerLocationId value) { hrcheck(enc(&IFolderPicker_adaptor::SuggestedStartLocation)->_put_SuggestedStartLocation(value)); }
			void operator=(PickerLocationId value) { put(value); }
			void operator()(PickerLocationId value) { put(value); }
		} SuggestedStartLocation;
		struct : property {
			PickerViewMode get() { PickerViewMode value; hrcheck(enc(&IFolderPicker_adaptor::ViewMode)->_get_ViewMode(&value)); return value; }
			PickerViewMode operator()() { return get(); }
			operator PickerViewMode () { return get(); }
			void put(PickerViewMode value) { hrcheck(enc(&IFolderPicker_adaptor::ViewMode)->_put_ViewMode(value)); }
			void operator=(PickerViewMode value) { put(value); }
			void operator()(PickerViewMode value) { put(value); }
		} ViewMode;
	};
	ptr<Foundation::IAsyncOperation<ptr<StorageFolder>>> PickSingleFolderAsync() { Foundation::IAsyncOperation<StorageFolder*>* pickSingleFolderOperation; hrcheck(X::get()->_PickSingleFolderAsync(&pickSingleFolderOperation)); return from_abi(pickSingleFolderOperation); }
	IFolderPicker_adaptor() {}
};
template<typename X> struct adapt<IFolderPicker, X> : Windows::Storage::Pickers::IFolderPicker_adaptor<X> { typedef adapt IFolderPicker; };
struct IFolderPicker : IFolderPicker_raw, generate<IFolderPicker> {};

// IFolderPicker2
struct IFolderPicker2_raw : IInspectable {
	virtual STDMETHODIMP _get_ContinuationData(Foundation::Collections::ValueSet* *value);
	virtual STDMETHODIMP _PickFolderAndContinue();
};
template<typename X> struct IFolderPicker2_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::ValueSet> get() { Foundation::Collections::ValueSet* value; hrcheck(enc(&IFolderPicker2_adaptor::ContinuationData)->_get_ContinuationData(&value)); return from_abi(value); }
			ptr<Foundation::Collections::ValueSet> operator()() { return get(); }
			operator ptr<Foundation::Collections::ValueSet> () { return get(); }
			ptr<Foundation::Collections::ValueSet> operator->() { return get(); }
		} ContinuationData;
	};
	void PickFolderAndContinue() { hrcheck(X::get()->_PickFolderAndContinue()); }
	IFolderPicker2_adaptor() {}
};
template<typename X> struct adapt<IFolderPicker2, X> : Windows::Storage::Pickers::IFolderPicker2_adaptor<X> { typedef adapt IFolderPicker2; };
struct IFolderPicker2 : IFolderPicker2_raw, generate<IFolderPicker2> {};

// FileOpenPicker
template<typename> struct FileOpenPicker_statics {
	static ptr<Foundation::IAsyncOperation<ptr<StorageFile>>> ResumePickSingleFileAsync() { Foundation::IAsyncOperation<StorageFile*>* pickSingleFileOperation; hrcheck(get_activation_factory<FileOpenPicker, IFileOpenPickerStatics>()->_ResumePickSingleFileAsync(&pickSingleFileOperation)); return from_abi(pickSingleFileOperation); }
};

template<typename X> struct statics<FileOpenPicker, X> : X, Windows::Storage::Pickers::FileOpenPicker_statics<void> {
	typedef typename X::root_type FileOpenPicker;
};
struct FileOpenPicker : generate<FileOpenPicker> {
	using IFileOpenPicker::PickSingleFileAsync;
	using IFileOpenPickerWithOperationId::PickSingleFileAsync;
};

// FileSavePicker
template<typename X> struct statics<FileSavePicker, X> : X {
	typedef typename X::root_type FileSavePicker;
};
struct FileSavePicker : generate<FileSavePicker> {};

// FolderPicker
template<typename X> struct statics<FolderPicker, X> : X {
	typedef typename X::root_type FolderPicker;
};
struct FolderPicker : generate<FolderPicker> {};
}}}
} // namespace iso_winrt
