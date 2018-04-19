#pragma once
// generated by isopod tools
// namespaces:
// Windows.System.UserProfile

#include "Windows.System.UserProfile.0.h"
#include "Windows.Globalization.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Storage { namespace Streams {
struct IRandomAccessStream;
}
struct IStorageFile;
struct StorageFile;
}
namespace System {
struct User;
}}

// defs

template<> struct def<Windows::System::UserProfile::IAdvertisingManagerStatics> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::IAdvertisingManagerForUser> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::IAdvertisingManagerStatics2> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::AdvertisingManagerForUser> : class_type<Platform::Object, Windows::System::UserProfile::IAdvertisingManagerForUser> {};
template<> struct def<Windows::System::UserProfile::AdvertisingManager> : class_type<Platform::Object, Platform::Object> {};
template<> struct def<Windows::System::UserProfile::IDiagnosticsSettingsStatics> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::IDiagnosticsSettings> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::DiagnosticsSettings> : class_type<Platform::Object, Windows::System::UserProfile::IDiagnosticsSettings> {};
template<> struct def<Windows::System::UserProfile::IUserProfilePersonalizationSettings> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::IUserProfilePersonalizationSettingsStatics> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::UserProfilePersonalizationSettings> : class_type<Platform::Object, Windows::System::UserProfile::IUserProfilePersonalizationSettings> {};
template<> struct def<Windows::System::UserProfile::IGlobalizationPreferencesStatics> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::IGlobalizationPreferencesStatics2> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::IGlobalizationPreferencesStatics3> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::IGlobalizationPreferencesForUser> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::GlobalizationPreferencesForUser> : class_type<Platform::Object, Windows::System::UserProfile::IGlobalizationPreferencesForUser> {};
template<> struct def<Windows::System::UserProfile::GlobalizationPreferences> : class_type<Platform::Object, Platform::Object> {};
template<> struct def<Windows::System::UserProfile::IFirstSignInSettings> : interface_type<Windows::Foundation::Collections::IMapView<HSTRING, object>, Windows::Foundation::Collections::IIterable<ptr<Windows::Foundation::Collections::IKeyValuePair<HSTRING, object>>>> {};
template<> struct def<Windows::System::UserProfile::IFirstSignInSettingsStatics> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::FirstSignInSettings> : class_type<Platform::Object, Windows::System::UserProfile::IFirstSignInSettings> {};
template<> struct def<Windows::System::UserProfile::UserProfileContract> : value_type<> {};
template<> struct def<Windows::System::UserProfile::AccountPictureKind> : enum_type<int> {};
template<> struct def<Windows::System::UserProfile::SetAccountPictureResult> : enum_type<int> {};
template<> struct def<Windows::System::UserProfile::SetImageFeedResult> : enum_type<int> {};
template<> struct def<Windows::System::UserProfile::IUserInformationStatics> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::UserInformation> : class_type<Platform::Object, Platform::Object> {};
template<> struct def<Windows::System::UserProfile::UserProfileLockScreenContract> : value_type<> {};
template<> struct def<Windows::System::UserProfile::ILockScreenStatics> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::ILockScreenImageFeedStatics> : interface_type<> {};
template<> struct def<Windows::System::UserProfile::LockScreen> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::System::UserProfile::IAdvertisingManagerStatics> { define_guid(0xADD3468C, 0xA273, 0x48CB, 0xB3, 0x46, 0x35, 0x44, 0x52, 0x2D, 0x55, 0x81);};
template<> struct uuid<Windows::System::UserProfile::IAdvertisingManagerForUser> { define_guid(0x928BF3D0, 0xCF7C, 0x4AB0, 0xA7, 0xDC, 0x6D, 0xC5, 0xBC, 0xD4, 0x42, 0x52);};
template<> struct uuid<Windows::System::UserProfile::IAdvertisingManagerStatics2> { define_guid(0xDD0947AF, 0x1A6D, 0x46B0, 0x95, 0xBC, 0xF3, 0xF9, 0xD6, 0xBE, 0xB9, 0xFB);};
template<> struct uuid<Windows::System::UserProfile::IDiagnosticsSettingsStatics> { define_guid(0x72D2E80F, 0x5390, 0x4793, 0x99, 0xB, 0x3C, 0xCC, 0x7D, 0x6A, 0xC9, 0xC8);};
template<> struct uuid<Windows::System::UserProfile::IDiagnosticsSettings> { define_guid(0xE5E9ECCD, 0x2711, 0x44E0, 0x97, 0x3C, 0x49, 0x1D, 0x78, 0x4, 0x8D, 0x24);};
template<> struct uuid<Windows::System::UserProfile::IUserProfilePersonalizationSettings> { define_guid(0x8CEDDAB4, 0x7998, 0x46D5, 0x8D, 0xD3, 0x18, 0x4F, 0x1C, 0x5F, 0x9A, 0xB9);};
template<> struct uuid<Windows::System::UserProfile::IUserProfilePersonalizationSettingsStatics> { define_guid(0x91ACB841, 0x5037, 0x454B, 0x98, 0x83, 0xBB, 0x77, 0x2D, 0x8, 0xDD, 0x16);};
template<> struct uuid<Windows::System::UserProfile::IGlobalizationPreferencesStatics> { define_guid(0x1BF4326, 0xED37, 0x4E96, 0xB0, 0xE9, 0xC1, 0x34, 0xD, 0x1E, 0xA1, 0x58);};
template<> struct uuid<Windows::System::UserProfile::IGlobalizationPreferencesStatics2> { define_guid(0xFCCE85F1, 0x4300, 0x4CD0, 0x9C, 0xAC, 0x1A, 0x8E, 0x7B, 0x7E, 0x18, 0xF4);};
template<> struct uuid<Windows::System::UserProfile::IGlobalizationPreferencesStatics3> { define_guid(0x1E059733, 0x35F5, 0x40D8, 0xB9, 0xE8, 0xAE, 0xF3, 0xEF, 0x85, 0x6F, 0xCE);};
template<> struct uuid<Windows::System::UserProfile::IGlobalizationPreferencesForUser> { define_guid(0x150F0795, 0x4F6E, 0x40BA, 0xA0, 0x10, 0xE2, 0x7D, 0x81, 0xBD, 0xA7, 0xF5);};
template<> struct uuid<Windows::System::UserProfile::IFirstSignInSettings> { define_guid(0x3E945153, 0x3A5E, 0x452E, 0xA6, 0x1, 0xF5, 0xBA, 0xAD, 0x2A, 0x48, 0x70);};
template<> struct uuid<Windows::System::UserProfile::IFirstSignInSettingsStatics> { define_guid(0x1CE18F0F, 0x1C41, 0x4EA0, 0xB7, 0xA2, 0x6F, 0xC, 0x1C, 0x7E, 0x84, 0x38);};
template<> struct uuid<Windows::System::UserProfile::IUserInformationStatics> { define_guid(0x77F3A910, 0x48FA, 0x489C, 0x93, 0x4E, 0x2A, 0xE8, 0x5B, 0xA8, 0xF7, 0x72);};
template<> struct uuid<Windows::System::UserProfile::ILockScreenStatics> { define_guid(0x3EE9D3AD, 0xB607, 0x40AE, 0xB4, 0x26, 0x76, 0x31, 0xD9, 0x82, 0x12, 0x69);};
template<> struct uuid<Windows::System::UserProfile::ILockScreenImageFeedStatics> { define_guid(0x2C0D73F6, 0x3A9, 0x41A6, 0x9B, 0x1, 0x49, 0x52, 0x51, 0xFF, 0x51, 0xD5);};

// types

namespace Windows { namespace System { namespace UserProfile {

// IAdvertisingManagerStatics
struct IAdvertisingManagerStatics : IInspectable {
	virtual STDMETHODIMP _get_AdvertisingId(HSTRING *value);
};

// IAdvertisingManagerForUser
struct IAdvertisingManagerForUser_raw : IInspectable {
	virtual STDMETHODIMP _get_AdvertisingId(HSTRING *value);
	virtual STDMETHODIMP _get_User(System::User* *value);
};
template<typename X> struct IAdvertisingManagerForUser_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IAdvertisingManagerForUser_adaptor::AdvertisingId)->_get_AdvertisingId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} AdvertisingId;
		struct : property {
			ptr<System::User> get() { System::User* value; hrcheck(enc(&IAdvertisingManagerForUser_adaptor::User)->_get_User(&value)); return from_abi(value); }
			ptr<System::User> operator()() { return get(); }
			operator ptr<System::User> () { return get(); }
			ptr<System::User> operator->() { return get(); }
		} User;
	};
	IAdvertisingManagerForUser_adaptor() {}
};
template<typename X> struct adapt<IAdvertisingManagerForUser, X> : Windows::System::UserProfile::IAdvertisingManagerForUser_adaptor<X> { typedef adapt IAdvertisingManagerForUser; };
struct IAdvertisingManagerForUser : IAdvertisingManagerForUser_raw, generate<IAdvertisingManagerForUser> {};

// IAdvertisingManagerStatics2
struct IAdvertisingManagerStatics2 : IInspectable {
	virtual STDMETHODIMP _GetForUser(User* user, AdvertisingManagerForUser* *value);
};

// AdvertisingManagerForUser
template<typename X> struct statics<AdvertisingManagerForUser, X> : X {
	typedef typename X::root_type AdvertisingManagerForUser;
};
struct AdvertisingManagerForUser : generate<AdvertisingManagerForUser> {};

// AdvertisingManager
template<typename> struct AdvertisingManager_statics {
	static struct _AdvertisingId : property {
		hstring get() { HSTRING value; hrcheck(get_activation_factory<AdvertisingManager, IAdvertisingManagerStatics>()->_get_AdvertisingId(&value)); return from_abi(value); }
		hstring operator()() { return get(); }
		operator hstring_ref () { return get(); }
	} AdvertisingId;
	static ptr<AdvertisingManagerForUser> GetForUser(pptr<User> user) { AdvertisingManagerForUser* value; hrcheck(get_activation_factory<AdvertisingManager, IAdvertisingManagerStatics2>()->_GetForUser(user, &value)); return from_abi(value); }
};
template<typename X> typename AdvertisingManager_statics<X>::_AdvertisingId AdvertisingManager_statics<X>::AdvertisingId;

template<typename X> struct statics<AdvertisingManager, X> : X, Windows::System::UserProfile::AdvertisingManager_statics<void> {
	typedef typename X::root_type AdvertisingManager;
};
struct AdvertisingManager : generate<AdvertisingManager> {};

// IDiagnosticsSettingsStatics
struct IDiagnosticsSettingsStatics : IInspectable {
	virtual STDMETHODIMP _GetDefault(DiagnosticsSettings* *value);
	virtual STDMETHODIMP _GetForUser(User* user, DiagnosticsSettings* *value);
};

// IDiagnosticsSettings
struct IDiagnosticsSettings_raw : IInspectable {
	virtual STDMETHODIMP _get_CanUseDiagnosticsToTailorExperiences(bool *value);
	virtual STDMETHODIMP _get_User(System::User* *value);
};
template<typename X> struct IDiagnosticsSettings_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IDiagnosticsSettings_adaptor::CanUseDiagnosticsToTailorExperiences)->_get_CanUseDiagnosticsToTailorExperiences(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} CanUseDiagnosticsToTailorExperiences;
		struct : property {
			ptr<System::User> get() { System::User* value; hrcheck(enc(&IDiagnosticsSettings_adaptor::User)->_get_User(&value)); return from_abi(value); }
			ptr<System::User> operator()() { return get(); }
			operator ptr<System::User> () { return get(); }
			ptr<System::User> operator->() { return get(); }
		} User;
	};
	IDiagnosticsSettings_adaptor() {}
};
template<typename X> struct adapt<IDiagnosticsSettings, X> : Windows::System::UserProfile::IDiagnosticsSettings_adaptor<X> { typedef adapt IDiagnosticsSettings; };
struct IDiagnosticsSettings : IDiagnosticsSettings_raw, generate<IDiagnosticsSettings> {};

// DiagnosticsSettings
template<typename> struct DiagnosticsSettings_statics {
	static ptr<DiagnosticsSettings> GetDefault() { DiagnosticsSettings* value; hrcheck(get_activation_factory<DiagnosticsSettings, IDiagnosticsSettingsStatics>()->_GetDefault(&value)); return from_abi(value); }
	static ptr<DiagnosticsSettings> GetForUser(pptr<System::User> user) { DiagnosticsSettings* value; hrcheck(get_activation_factory<DiagnosticsSettings, IDiagnosticsSettingsStatics>()->_GetForUser(user, &value)); return from_abi(value); }
};

template<typename X> struct statics<DiagnosticsSettings, X> : X, Windows::System::UserProfile::DiagnosticsSettings_statics<void> {
	typedef typename X::root_type DiagnosticsSettings;
};
struct DiagnosticsSettings : generate<DiagnosticsSettings> {};

// IUserProfilePersonalizationSettings
struct IUserProfilePersonalizationSettings_raw : IInspectable {
	virtual STDMETHODIMP _TrySetLockScreenImageAsync(Storage::StorageFile* imageFile, Foundation::IAsyncOperation<bool>* *operation);
	virtual STDMETHODIMP _TrySetWallpaperImageAsync(Storage::StorageFile* imageFile, Foundation::IAsyncOperation<bool>* *operation);
};
template<typename X> struct IUserProfilePersonalizationSettings_adaptor : X {
	ptr<Foundation::IAsyncOperation<bool>> TrySetLockScreenImageAsync(pptr<Storage::StorageFile> imageFile) { Foundation::IAsyncOperation<bool>* operation; hrcheck(X::get()->_TrySetLockScreenImageAsync(imageFile, &operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<bool>> TrySetWallpaperImageAsync(pptr<Storage::StorageFile> imageFile) { Foundation::IAsyncOperation<bool>* operation; hrcheck(X::get()->_TrySetWallpaperImageAsync(imageFile, &operation)); return from_abi(operation); }
};
template<typename X> struct adapt<IUserProfilePersonalizationSettings, X> : Windows::System::UserProfile::IUserProfilePersonalizationSettings_adaptor<X> { typedef adapt IUserProfilePersonalizationSettings; };
struct IUserProfilePersonalizationSettings : IUserProfilePersonalizationSettings_raw, generate<IUserProfilePersonalizationSettings> {};

// IUserProfilePersonalizationSettingsStatics
struct IUserProfilePersonalizationSettingsStatics : IInspectable {
	virtual STDMETHODIMP _get_Current(UserProfilePersonalizationSettings* *value);
	virtual STDMETHODIMP _IsSupported(bool *result);
};

// UserProfilePersonalizationSettings
template<typename> struct UserProfilePersonalizationSettings_statics {
	static struct _Current : property {
		ptr<UserProfilePersonalizationSettings> get() { UserProfilePersonalizationSettings* value; hrcheck(get_activation_factory<UserProfilePersonalizationSettings, IUserProfilePersonalizationSettingsStatics>()->_get_Current(&value)); return from_abi(value); }
		ptr<UserProfilePersonalizationSettings> operator()() { return get(); }
		operator ptr<UserProfilePersonalizationSettings> () { return get(); }
		ptr<UserProfilePersonalizationSettings> operator->() { return get(); }
	} Current;
	static bool IsSupported() { bool result; hrcheck(get_activation_factory<UserProfilePersonalizationSettings, IUserProfilePersonalizationSettingsStatics>()->_IsSupported(&result)); return result; }
};
template<typename X> typename UserProfilePersonalizationSettings_statics<X>::_Current UserProfilePersonalizationSettings_statics<X>::Current;

template<typename X> struct statics<UserProfilePersonalizationSettings, X> : X, Windows::System::UserProfile::UserProfilePersonalizationSettings_statics<void> {
	typedef typename X::root_type UserProfilePersonalizationSettings;
};
struct UserProfilePersonalizationSettings : generate<UserProfilePersonalizationSettings> {};

// IGlobalizationPreferencesStatics
struct IGlobalizationPreferencesStatics : IInspectable {
	virtual STDMETHODIMP _get_Calendars(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _get_Clocks(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _get_Currencies(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _get_Languages(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _get_HomeGeographicRegion(HSTRING *value);
	virtual STDMETHODIMP _get_WeekStartsOn(Globalization::DayOfWeek *value);
};

// IGlobalizationPreferencesStatics2
struct IGlobalizationPreferencesStatics2 : IInspectable {
	virtual STDMETHODIMP _TrySetHomeGeographicRegion(HSTRING region, bool *result);
	virtual STDMETHODIMP _TrySetLanguages(Foundation::Collections::IIterable<HSTRING>* languageTags, bool *result);
};

// IGlobalizationPreferencesStatics3
struct IGlobalizationPreferencesStatics3 : IInspectable {
	virtual STDMETHODIMP _GetForUser(User* user, GlobalizationPreferencesForUser* *value);
};

// IGlobalizationPreferencesForUser
struct IGlobalizationPreferencesForUser_raw : IInspectable {
	virtual STDMETHODIMP _get_User(System::User* *value);
	virtual STDMETHODIMP _get_Calendars(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _get_Clocks(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _get_Currencies(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _get_Languages(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _get_HomeGeographicRegion(HSTRING *value);
	virtual STDMETHODIMP _get_WeekStartsOn(Globalization::DayOfWeek *value);
};
template<typename X> struct IGlobalizationPreferencesForUser_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(enc(&IGlobalizationPreferencesForUser_adaptor::Calendars)->_get_Calendars(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
		} Calendars;
		struct : property {
			ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(enc(&IGlobalizationPreferencesForUser_adaptor::Clocks)->_get_Clocks(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
		} Clocks;
		struct : property {
			ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(enc(&IGlobalizationPreferencesForUser_adaptor::Currencies)->_get_Currencies(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
		} Currencies;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IGlobalizationPreferencesForUser_adaptor::HomeGeographicRegion)->_get_HomeGeographicRegion(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} HomeGeographicRegion;
		struct : property {
			ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(enc(&IGlobalizationPreferencesForUser_adaptor::Languages)->_get_Languages(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
		} Languages;
		struct : property {
			ptr<System::User> get() { System::User* value; hrcheck(enc(&IGlobalizationPreferencesForUser_adaptor::User)->_get_User(&value)); return from_abi(value); }
			ptr<System::User> operator()() { return get(); }
			operator ptr<System::User> () { return get(); }
			ptr<System::User> operator->() { return get(); }
		} User;
		struct : property {
			Globalization::DayOfWeek get() { Globalization::DayOfWeek value; hrcheck(enc(&IGlobalizationPreferencesForUser_adaptor::WeekStartsOn)->_get_WeekStartsOn(&value)); return value; }
			Globalization::DayOfWeek operator()() { return get(); }
			operator Globalization::DayOfWeek () { return get(); }
		} WeekStartsOn;
	};
	IGlobalizationPreferencesForUser_adaptor() {}
};
template<typename X> struct adapt<IGlobalizationPreferencesForUser, X> : Windows::System::UserProfile::IGlobalizationPreferencesForUser_adaptor<X> { typedef adapt IGlobalizationPreferencesForUser; };
struct IGlobalizationPreferencesForUser : IGlobalizationPreferencesForUser_raw, generate<IGlobalizationPreferencesForUser> {};

// GlobalizationPreferencesForUser
template<typename X> struct statics<GlobalizationPreferencesForUser, X> : X {
	typedef typename X::root_type GlobalizationPreferencesForUser;
};
struct GlobalizationPreferencesForUser : generate<GlobalizationPreferencesForUser> {};

// GlobalizationPreferences
template<typename> struct GlobalizationPreferences_statics {
	static struct _Calendars : property {
		ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>()->_get_Calendars(&value)); return from_abi(value); }
		ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
		operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
		ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
	} Calendars;
	static struct _Clocks : property {
		ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>()->_get_Clocks(&value)); return from_abi(value); }
		ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
		operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
		ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
	} Clocks;
	static struct _Currencies : property {
		ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>()->_get_Currencies(&value)); return from_abi(value); }
		ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
		operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
		ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
	} Currencies;
	static struct _HomeGeographicRegion : property {
		hstring get() { HSTRING value; hrcheck(get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>()->_get_HomeGeographicRegion(&value)); return from_abi(value); }
		hstring operator()() { return get(); }
		operator hstring_ref () { return get(); }
	} HomeGeographicRegion;
	static struct _Languages : property {
		ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>()->_get_Languages(&value)); return from_abi(value); }
		ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
		operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
		ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
	} Languages;
	static struct _WeekStartsOn : property {
		Globalization::DayOfWeek get() { Globalization::DayOfWeek value; hrcheck(get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics>()->_get_WeekStartsOn(&value)); return value; }
		Globalization::DayOfWeek operator()() { return get(); }
		operator Globalization::DayOfWeek () { return get(); }
	} WeekStartsOn;
	static ptr<GlobalizationPreferencesForUser> GetForUser(pptr<User> user) { GlobalizationPreferencesForUser* value; hrcheck(get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics3>()->_GetForUser(user, &value)); return from_abi(value); }
	static bool TrySetHomeGeographicRegion(hstring_ref region) { bool result; hrcheck(get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics2>()->_TrySetHomeGeographicRegion(region, &result)); return result; }
	static bool TrySetLanguages(pptr<Foundation::Collections::IIterable<hstring>> languageTags) { bool result; hrcheck(get_activation_factory<GlobalizationPreferences, IGlobalizationPreferencesStatics2>()->_TrySetLanguages(to_abi(languageTags), &result)); return result; }
};
template<typename X> typename GlobalizationPreferences_statics<X>::_Calendars GlobalizationPreferences_statics<X>::Calendars;
template<typename X> typename GlobalizationPreferences_statics<X>::_Clocks GlobalizationPreferences_statics<X>::Clocks;
template<typename X> typename GlobalizationPreferences_statics<X>::_Currencies GlobalizationPreferences_statics<X>::Currencies;
template<typename X> typename GlobalizationPreferences_statics<X>::_HomeGeographicRegion GlobalizationPreferences_statics<X>::HomeGeographicRegion;
template<typename X> typename GlobalizationPreferences_statics<X>::_Languages GlobalizationPreferences_statics<X>::Languages;
template<typename X> typename GlobalizationPreferences_statics<X>::_WeekStartsOn GlobalizationPreferences_statics<X>::WeekStartsOn;

template<typename X> struct statics<GlobalizationPreferences, X> : X, Windows::System::UserProfile::GlobalizationPreferences_statics<void> {
	typedef typename X::root_type GlobalizationPreferences;
};
struct GlobalizationPreferences : generate<GlobalizationPreferences> {};

// IFirstSignInSettings
struct IFirstSignInSettings : IInspectable, generate<IFirstSignInSettings> {};

// IFirstSignInSettingsStatics
struct IFirstSignInSettingsStatics : IInspectable {
	virtual STDMETHODIMP _GetDefault(FirstSignInSettings* *result);
};

// FirstSignInSettings
template<typename> struct FirstSignInSettings_statics {
	static ptr<FirstSignInSettings> GetDefault() { FirstSignInSettings* result; hrcheck(get_activation_factory<FirstSignInSettings, IFirstSignInSettingsStatics>()->_GetDefault(&result)); return from_abi(result); }
};

template<typename X> struct statics<FirstSignInSettings, X> : X, Windows::System::UserProfile::FirstSignInSettings_statics<void> {
	typedef typename X::root_type FirstSignInSettings;
};
struct FirstSignInSettings : generate<FirstSignInSettings> {};

// IUserInformationStatics
struct IUserInformationStatics : IInspectable {
	virtual STDMETHODIMP _get_AccountPictureChangeEnabled(bool *value);
	virtual STDMETHODIMP _get_NameAccessAllowed(bool *value);
	virtual STDMETHODIMP _GetAccountPicture(AccountPictureKind kind, Storage::IStorageFile* *storageFile);
	virtual STDMETHODIMP _SetAccountPictureAsync(Storage::IStorageFile* image, Foundation::IAsyncOperation<SetAccountPictureResult>* *operation);
	virtual STDMETHODIMP _SetAccountPicturesAsync(Storage::IStorageFile* smallImage, Storage::IStorageFile* largeImage, Storage::IStorageFile* video, Foundation::IAsyncOperation<SetAccountPictureResult>* *operation);
	virtual STDMETHODIMP _SetAccountPictureFromStreamAsync(Storage::Streams::IRandomAccessStream* image, Foundation::IAsyncOperation<SetAccountPictureResult>* *operation);
	virtual STDMETHODIMP _SetAccountPicturesFromStreamsAsync(Storage::Streams::IRandomAccessStream* smallImage, Storage::Streams::IRandomAccessStream* largeImage, Storage::Streams::IRandomAccessStream* video, Foundation::IAsyncOperation<SetAccountPictureResult>* *operation);
	virtual STDMETHODIMP _add_AccountPictureChanged(Foundation::EventHandler<IInspectable*>* changeHandler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_AccountPictureChanged(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _GetDisplayNameAsync(Foundation::IAsyncOperation<HSTRING>* *operation);
	virtual STDMETHODIMP _GetFirstNameAsync(Foundation::IAsyncOperation<HSTRING>* *operation);
	virtual STDMETHODIMP _GetLastNameAsync(Foundation::IAsyncOperation<HSTRING>* *operation);
	virtual STDMETHODIMP _GetPrincipalNameAsync(Foundation::IAsyncOperation<HSTRING>* *operation);
	virtual STDMETHODIMP _GetSessionInitiationProtocolUriAsync(Foundation::IAsyncOperation<Foundation::Uri*>* *operation);
	virtual STDMETHODIMP _GetDomainNameAsync(Foundation::IAsyncOperation<HSTRING>* *operation);
};

// UserInformation
template<typename> struct UserInformation_statics {
	static struct _AccountPictureChangeEnabled : property {
		bool get() { bool value; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_get_AccountPictureChangeEnabled(&value)); return value; }
		bool operator()() { return get(); }
		operator bool () { return get(); }
	} AccountPictureChangeEnabled;
	static struct _NameAccessAllowed : property {
		bool get() { bool value; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_get_NameAccessAllowed(&value)); return value; }
		bool operator()() { return get(); }
		operator bool () { return get(); }
	} NameAccessAllowed;
	static struct _AccountPictureChanged : property {
		Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::EventHandler<object>> changeHandler) { Foundation::EventRegistrationToken token; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_add_AccountPictureChanged(to_abi(changeHandler), &token)); return token; }
		void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_remove_AccountPictureChanged(token)); }
	} AccountPictureChanged;
	static ptr<Storage::IStorageFile> GetAccountPicture(AccountPictureKind kind) { Storage::IStorageFile* storageFile; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_GetAccountPicture(kind, &storageFile)); return from_abi(storageFile); }
	static ptr<Foundation::IAsyncOperation<SetAccountPictureResult>> SetAccountPictureAsync(pptr<Storage::IStorageFile> image) { Foundation::IAsyncOperation<SetAccountPictureResult>* operation; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_SetAccountPictureAsync(image, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<SetAccountPictureResult>> SetAccountPicturesAsync(pptr<Storage::IStorageFile> smallImage, pptr<Storage::IStorageFile> largeImage, pptr<Storage::IStorageFile> video) { Foundation::IAsyncOperation<SetAccountPictureResult>* operation; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_SetAccountPicturesAsync(smallImage, largeImage, video, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<SetAccountPictureResult>> SetAccountPictureFromStreamAsync(pptr<Storage::Streams::IRandomAccessStream> image) { Foundation::IAsyncOperation<SetAccountPictureResult>* operation; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_SetAccountPictureFromStreamAsync(image, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<SetAccountPictureResult>> SetAccountPicturesFromStreamsAsync(pptr<Storage::Streams::IRandomAccessStream> smallImage, pptr<Storage::Streams::IRandomAccessStream> largeImage, pptr<Storage::Streams::IRandomAccessStream> video) { Foundation::IAsyncOperation<SetAccountPictureResult>* operation; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_SetAccountPicturesFromStreamsAsync(smallImage, largeImage, video, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<hstring>> GetDisplayNameAsync() { Foundation::IAsyncOperation<HSTRING>* operation; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_GetDisplayNameAsync(&operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<hstring>> GetFirstNameAsync() { Foundation::IAsyncOperation<HSTRING>* operation; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_GetFirstNameAsync(&operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<hstring>> GetLastNameAsync() { Foundation::IAsyncOperation<HSTRING>* operation; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_GetLastNameAsync(&operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<hstring>> GetPrincipalNameAsync() { Foundation::IAsyncOperation<HSTRING>* operation; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_GetPrincipalNameAsync(&operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<ptr<Foundation::Uri>>> GetSessionInitiationProtocolUriAsync() { Foundation::IAsyncOperation<Foundation::Uri*>* operation; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_GetSessionInitiationProtocolUriAsync(&operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<hstring>> GetDomainNameAsync() { Foundation::IAsyncOperation<HSTRING>* operation; hrcheck(get_activation_factory<UserInformation, IUserInformationStatics>()->_GetDomainNameAsync(&operation)); return from_abi(operation); }
};
template<typename X> typename UserInformation_statics<X>::_AccountPictureChangeEnabled UserInformation_statics<X>::AccountPictureChangeEnabled;
template<typename X> typename UserInformation_statics<X>::_NameAccessAllowed UserInformation_statics<X>::NameAccessAllowed;
template<typename X> typename UserInformation_statics<X>::_AccountPictureChanged UserInformation_statics<X>::AccountPictureChanged;

template<typename X> struct statics<UserInformation, X> : X, Windows::System::UserProfile::UserInformation_statics<void> {
	typedef typename X::root_type UserInformation;
};
struct UserInformation : generate<UserInformation> {};

// ILockScreenStatics
struct ILockScreenStatics : IInspectable {
	virtual STDMETHODIMP _get_OriginalImageFile(Foundation::Uri* *value);
	virtual STDMETHODIMP _GetImageStream(Storage::Streams::IRandomAccessStream* *value);
	virtual STDMETHODIMP _SetImageFileAsync(Storage::IStorageFile* value, Foundation::IAsyncAction* *Operation);
	virtual STDMETHODIMP _SetImageStreamAsync(Storage::Streams::IRandomAccessStream* value, Foundation::IAsyncAction* *Operation);
};

// ILockScreenImageFeedStatics
struct ILockScreenImageFeedStatics : IInspectable {
	virtual STDMETHODIMP _RequestSetImageFeedAsync(Foundation::Uri* syndicationFeedUri, Foundation::IAsyncOperation<SetImageFeedResult>* *value);
	virtual STDMETHODIMP _TryRemoveImageFeed(bool *result);
};

// LockScreen
template<typename> struct LockScreen_statics {
	static struct _OriginalImageFile : property {
		ptr<Foundation::Uri> get() { Foundation::Uri* value; hrcheck(get_activation_factory<LockScreen, ILockScreenStatics>()->_get_OriginalImageFile(&value)); return from_abi(value); }
		ptr<Foundation::Uri> operator()() { return get(); }
		operator ptr<Foundation::Uri> () { return get(); }
		ptr<Foundation::Uri> operator->() { return get(); }
	} OriginalImageFile;
	static ptr<Foundation::IAsyncOperation<SetImageFeedResult>> RequestSetImageFeedAsync(pptr<Foundation::Uri> syndicationFeedUri) { Foundation::IAsyncOperation<SetImageFeedResult>* value; hrcheck(get_activation_factory<LockScreen, ILockScreenImageFeedStatics>()->_RequestSetImageFeedAsync(syndicationFeedUri, &value)); return from_abi(value); }
	static bool TryRemoveImageFeed() { bool result; hrcheck(get_activation_factory<LockScreen, ILockScreenImageFeedStatics>()->_TryRemoveImageFeed(&result)); return result; }
	static ptr<Storage::Streams::IRandomAccessStream> GetImageStream() { Storage::Streams::IRandomAccessStream* value; hrcheck(get_activation_factory<LockScreen, ILockScreenStatics>()->_GetImageStream(&value)); return from_abi(value); }
	static ptr<Foundation::IAsyncAction> SetImageFileAsync(pptr<Storage::IStorageFile> value) { Foundation::IAsyncAction* Operation; hrcheck(get_activation_factory<LockScreen, ILockScreenStatics>()->_SetImageFileAsync(value, &Operation)); return from_abi(Operation); }
	static ptr<Foundation::IAsyncAction> SetImageStreamAsync(pptr<Storage::Streams::IRandomAccessStream> value) { Foundation::IAsyncAction* Operation; hrcheck(get_activation_factory<LockScreen, ILockScreenStatics>()->_SetImageStreamAsync(value, &Operation)); return from_abi(Operation); }
};
template<typename X> typename LockScreen_statics<X>::_OriginalImageFile LockScreen_statics<X>::OriginalImageFile;

template<typename X> struct statics<LockScreen, X> : X, Windows::System::UserProfile::LockScreen_statics<void> {
	typedef typename X::root_type LockScreen;
};
struct LockScreen : generate<LockScreen> {};
}}}
} // namespace iso_winrt