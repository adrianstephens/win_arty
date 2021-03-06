#pragma once
// generated by isopod tools
// namespaces:
// Windows.Phone.ApplicationModel

#include "Windows.Phone.ApplicationModel.0.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Phone::ApplicationModel::ApplicationProfileModes> : enum_type<unsigned> {};
template<> struct def<Windows::Phone::ApplicationModel::IApplicationProfileStatics> : interface_type<> {};
template<> struct def<Windows::Phone::ApplicationModel::ApplicationProfile> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::Phone::ApplicationModel::IApplicationProfileStatics> { define_guid(0xD5008AB4, 0x7E7A, 0x11E1, 0xA7, 0xF2, 0xB0, 0xA1, 0x48, 0x24, 0x1, 0x9B);};

// types

namespace Windows { namespace Phone { namespace ApplicationModel {

// IApplicationProfileStatics
struct IApplicationProfileStatics : IInspectable {
	virtual STDMETHODIMP _get_Modes(ApplicationProfileModes *value);
};

// ApplicationProfile
template<typename> struct ApplicationProfile_statics {
	static struct _Modes : property {
		ApplicationProfileModes get() { ApplicationProfileModes value; hrcheck(get_activation_factory<ApplicationProfile, IApplicationProfileStatics>()->_get_Modes(&value)); return value; }
		ApplicationProfileModes operator()() { return get(); }
		operator ApplicationProfileModes () { return get(); }
	} Modes;
};
template<typename X> typename ApplicationProfile_statics<X>::_Modes ApplicationProfile_statics<X>::Modes;

template<typename X> struct statics<ApplicationProfile, X> : X, Windows::Phone::ApplicationModel::ApplicationProfile_statics<void> {
	typedef typename X::root_type ApplicationProfile;
};
struct ApplicationProfile : generate<ApplicationProfile> {};
}}}
} // namespace iso_winrt
