#pragma once
// generated by isopod tools
// namespaces:
// Windows.Media.Core.Preview

#include "Windows.Media.Core.Preview.0.h"
#include "Windows.Media.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Media::Core::Preview::ISoundLevelBrokerStatics> : interface_type<> {};
template<> struct def<Windows::Media::Core::Preview::SoundLevelBroker> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::Media::Core::Preview::ISoundLevelBrokerStatics> { define_guid(0x6A633961, 0xDBED, 0x464C, 0xA0, 0x9A, 0x33, 0x41, 0x2F, 0x5C, 0xAA, 0x3F);};

// types

namespace Windows { namespace Media { namespace Core { namespace Preview {

// ISoundLevelBrokerStatics
struct ISoundLevelBrokerStatics : IInspectable {
	virtual STDMETHODIMP _get_SoundLevel(Media::SoundLevel *value);
	virtual STDMETHODIMP _add_SoundLevelChanged(Foundation::EventHandler<IInspectable*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_SoundLevelChanged(Foundation::EventRegistrationToken token);
};

// SoundLevelBroker
template<typename> struct SoundLevelBroker_statics {
	static struct _SoundLevel : property {
		Media::SoundLevel get() { Media::SoundLevel value; hrcheck(get_activation_factory<SoundLevelBroker, ISoundLevelBrokerStatics>()->_get_SoundLevel(&value)); return value; }
		Media::SoundLevel operator()() { return get(); }
		operator Media::SoundLevel () { return get(); }
	} SoundLevel;
	static struct _SoundLevelChanged : property {
		Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::EventHandler<object>> handler) { Foundation::EventRegistrationToken token; hrcheck(get_activation_factory<SoundLevelBroker, ISoundLevelBrokerStatics>()->_add_SoundLevelChanged(to_abi(handler), &token)); return token; }
		void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(get_activation_factory<SoundLevelBroker, ISoundLevelBrokerStatics>()->_remove_SoundLevelChanged(token)); }
	} SoundLevelChanged;
};
template<typename X> typename SoundLevelBroker_statics<X>::_SoundLevel SoundLevelBroker_statics<X>::SoundLevel;
template<typename X> typename SoundLevelBroker_statics<X>::_SoundLevelChanged SoundLevelBroker_statics<X>::SoundLevelChanged;

template<typename X> struct statics<SoundLevelBroker, X> : X, Windows::Media::Core::Preview::SoundLevelBroker_statics<void> {
	typedef typename X::root_type SoundLevelBroker;
};
struct SoundLevelBroker : generate<SoundLevelBroker> {};
}}}}
} // namespace iso_winrt
