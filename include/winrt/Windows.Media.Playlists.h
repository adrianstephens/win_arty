#pragma once
// generated by isopod tools
// namespaces:
// Windows.Media.Playlists

#include "Windows.Media.Playlists.0.h"
#include "Windows.Storage.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVector;
}
template<typename TResult> struct IAsyncOperation;
struct IAsyncAction;
}}

// defs

template<> struct def<Windows::Media::Playlists::PlaylistFormat> : enum_type<int> {};
template<> struct def<Windows::Media::Playlists::IPlaylist> : interface_type<> {};
template<> struct def<Windows::Media::Playlists::IPlaylistStatics> : interface_type<> {};
template<> struct def<Windows::Media::Playlists::Playlist> : class_type<Platform::Object, Windows::Media::Playlists::IPlaylist> {};
template<> struct def<Windows::Media::Playlists::PlaylistsContract> : value_type<> {};

// uuids

template<> struct uuid<Windows::Media::Playlists::IPlaylist> { define_guid(0x803736F5, 0xCF44, 0x4D97, 0x83, 0xB3, 0x7A, 0x8, 0x9E, 0x9A, 0xB6, 0x63);};
template<> struct uuid<Windows::Media::Playlists::IPlaylistStatics> { define_guid(0xC5C331CD, 0x81F9, 0x4FF3, 0x95, 0xB9, 0x70, 0xB6, 0xFF, 0x4, 0x6B, 0x68);};

// types

namespace Windows { namespace Media { namespace Playlists {

// IPlaylist
struct IPlaylist_raw : IInspectable {
	virtual STDMETHODIMP _get_Files(Foundation::Collections::IVector<Storage::StorageFile*>* *value);
	virtual STDMETHODIMP _SaveAsync(Foundation::IAsyncAction* *operation);
	virtual STDMETHODIMP _SaveAsAsync(Storage::IStorageFolder* saveLocation, HSTRING desiredName, Storage::NameCollisionOption option, Foundation::IAsyncOperation<Storage::StorageFile*>* *operation);
	virtual STDMETHODIMP _SaveAsWithFormatAsync(Storage::IStorageFolder* saveLocation, HSTRING desiredName, Storage::NameCollisionOption option, PlaylistFormat playlistFormat, Foundation::IAsyncOperation<Storage::StorageFile*>* *operation);
};
template<typename X> struct IPlaylist_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVector<ptr<Storage::StorageFile>>> get() { Foundation::Collections::IVector<Storage::StorageFile*>* value; hrcheck(enc(&IPlaylist_adaptor::Files)->_get_Files(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVector<ptr<Storage::StorageFile>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVector<ptr<Storage::StorageFile>>> () { return get(); }
			ptr<Foundation::Collections::IVector<ptr<Storage::StorageFile>>> operator->() { return get(); }
		} Files;
	};
	ptr<Foundation::IAsyncAction> SaveAsync() { Foundation::IAsyncAction* operation; hrcheck(X::get()->_SaveAsync(&operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<Storage::StorageFile>>> SaveAsAsync(pptr<Storage::IStorageFolder> saveLocation, hstring_ref desiredName, Storage::NameCollisionOption option) { Foundation::IAsyncOperation<Storage::StorageFile*>* operation; hrcheck(X::get()->_SaveAsAsync(saveLocation, desiredName, option, &operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<Storage::StorageFile>>> SaveAsAsync(pptr<Storage::IStorageFolder> saveLocation, hstring_ref desiredName, Storage::NameCollisionOption option, PlaylistFormat playlistFormat) { Foundation::IAsyncOperation<Storage::StorageFile*>* operation; hrcheck(X::get()->_SaveAsWithFormatAsync(saveLocation, desiredName, option, playlistFormat, &operation)); return from_abi(operation); }
	IPlaylist_adaptor() {}
};
template<typename X> struct adapt<IPlaylist, X> : Windows::Media::Playlists::IPlaylist_adaptor<X> { typedef adapt IPlaylist; };
struct IPlaylist : IPlaylist_raw, generate<IPlaylist> {};

// IPlaylistStatics
struct IPlaylistStatics : IInspectable {
	virtual STDMETHODIMP _LoadAsync(Storage::IStorageFile* file, Foundation::IAsyncOperation<Playlist*>* *operation);
};

// Playlist
template<typename> struct Playlist_statics {
	static ptr<Foundation::IAsyncOperation<ptr<Playlist>>> LoadAsync(pptr<Storage::IStorageFile> file) { Foundation::IAsyncOperation<Playlist*>* operation; hrcheck(get_activation_factory<Playlist, IPlaylistStatics>()->_LoadAsync(file, &operation)); return from_abi(operation); }
};

template<typename X> struct statics<Playlist, X> : X, Windows::Media::Playlists::Playlist_statics<void> {
	typedef typename X::root_type Playlist;
};
struct Playlist : generate<Playlist> {
	using IPlaylist::SaveAsAsync;
};
}}}
} // namespace iso_winrt
