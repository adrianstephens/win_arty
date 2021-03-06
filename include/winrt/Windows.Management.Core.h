#pragma once
// generated by isopod tools
// namespaces:
// Windows.Management.Core

#include "Windows.Management.Core.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Storage {
struct ApplicationData;
}}

// defs

template<> struct def<Windows::Management::Core::IApplicationDataManager> : interface_type<> {};
template<> struct def<Windows::Management::Core::IApplicationDataManagerStatics> : interface_type<> {};
template<> struct def<Windows::Management::Core::ApplicationDataManager> : class_type<Platform::Object, Windows::Management::Core::IApplicationDataManager> {};

// uuids

template<> struct uuid<Windows::Management::Core::IApplicationDataManager> { define_guid(0x74D10432, 0x2E99, 0x4000, 0x9A, 0x3A, 0x64, 0x30, 0x7E, 0x85, 0x81, 0x29);};
template<> struct uuid<Windows::Management::Core::IApplicationDataManagerStatics> { define_guid(0x1E1862E3, 0x698E, 0x49A1, 0x97, 0x52, 0xDE, 0xE9, 0x49, 0x25, 0xB9, 0xB3);};

// types

namespace Windows { namespace Management { namespace Core {

// IApplicationDataManager
struct IApplicationDataManager : IInspectable, generate<IApplicationDataManager> {};

// IApplicationDataManagerStatics
struct IApplicationDataManagerStatics : IInspectable {
	virtual STDMETHODIMP _CreateForPackageFamily(HSTRING packageFamilyName, Storage::ApplicationData* *applicationData);
};

// ApplicationDataManager
template<typename> struct ApplicationDataManager_statics {
	static ptr<Storage::ApplicationData> CreateForPackageFamily(hstring_ref packageFamilyName) { Storage::ApplicationData* applicationData; hrcheck(get_activation_factory<ApplicationDataManager, IApplicationDataManagerStatics>()->_CreateForPackageFamily(packageFamilyName, &applicationData)); return from_abi(applicationData); }
};

template<typename X> struct statics<ApplicationDataManager, X> : X, Windows::Management::Core::ApplicationDataManager_statics<void> {
	typedef typename X::root_type ApplicationDataManager;
};
struct ApplicationDataManager : generate<ApplicationDataManager> {};
}}}
} // namespace iso_winrt
