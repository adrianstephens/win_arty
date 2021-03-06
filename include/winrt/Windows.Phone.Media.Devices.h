#pragma once
// generated by isopod tools
// namespaces:
// Windows.Phone.Media.Devices

#include "Windows.Phone.Media.Devices.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Phone::Media::Devices::AvailableAudioRoutingEndpoints> : enum_type<unsigned> {};
template<> struct def<Windows::Phone::Media::Devices::AudioRoutingEndpoint> : enum_type<int> {};
template<> struct def<Windows::Phone::Media::Devices::IAudioRoutingManager> : interface_type<> {};
template<> struct def<Windows::Phone::Media::Devices::IAudioRoutingManagerStatics> : interface_type<> {};
template<> struct def<Windows::Phone::Media::Devices::AudioRoutingManager> : class_type<Platform::Object, Windows::Phone::Media::Devices::IAudioRoutingManager> {};

// uuids

template<> struct uuid<Windows::Phone::Media::Devices::IAudioRoutingManager> { define_guid(0x79340D20, 0x71CC, 0x4526, 0x9F, 0x29, 0xFC, 0x8D, 0x24, 0x86, 0x41, 0x8B);};
template<> struct uuid<Windows::Phone::Media::Devices::IAudioRoutingManagerStatics> { define_guid(0x977FB2A4, 0x5590, 0x4A6F, 0xAD, 0xDE, 0x6A, 0x3D, 0xA, 0xD5, 0x82, 0x50);};

// types

namespace Windows { namespace Phone { namespace Media { namespace Devices {

// IAudioRoutingManager
struct IAudioRoutingManager_raw : IInspectable {
	virtual STDMETHODIMP _GetAudioEndpoint(AudioRoutingEndpoint *endpoint);
	virtual STDMETHODIMP _SetAudioEndpoint(AudioRoutingEndpoint endpoint);
	virtual STDMETHODIMP _add_AudioEndpointChanged(Foundation::TypedEventHandler<AudioRoutingManager*, IInspectable*>* endpointChangeHandler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_AudioEndpointChanged(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _get_AvailableAudioEndpoints(AvailableAudioRoutingEndpoints *value);
};
template<typename X> struct IAudioRoutingManager_adaptor : X {
	union {
		struct : property {
			AvailableAudioRoutingEndpoints get() { AvailableAudioRoutingEndpoints value; hrcheck(enc(&IAudioRoutingManager_adaptor::AvailableAudioEndpoints)->_get_AvailableAudioEndpoints(&value)); return value; }
			AvailableAudioRoutingEndpoints operator()() { return get(); }
			operator AvailableAudioRoutingEndpoints () { return get(); }
		} AvailableAudioEndpoints;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<AudioRoutingManager>, object>> endpointChangeHandler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IAudioRoutingManager_adaptor::AudioEndpointChanged)->_add_AudioEndpointChanged(to_abi(endpointChangeHandler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IAudioRoutingManager_adaptor::AudioEndpointChanged)->_remove_AudioEndpointChanged(token)); }
		} AudioEndpointChanged;
	};
	AudioRoutingEndpoint GetAudioEndpoint() { AudioRoutingEndpoint endpoint; hrcheck(X::get()->_GetAudioEndpoint(&endpoint)); return endpoint; }
	void SetAudioEndpoint(AudioRoutingEndpoint endpoint) { hrcheck(X::get()->_SetAudioEndpoint(endpoint)); }
	IAudioRoutingManager_adaptor() {}
};
template<typename X> struct adapt<IAudioRoutingManager, X> : Windows::Phone::Media::Devices::IAudioRoutingManager_adaptor<X> { typedef adapt IAudioRoutingManager; };
struct IAudioRoutingManager : IAudioRoutingManager_raw, generate<IAudioRoutingManager> {};

// IAudioRoutingManagerStatics
struct IAudioRoutingManagerStatics : IInspectable {
	virtual STDMETHODIMP _GetDefault(AudioRoutingManager* *audioRoutingManager);
};

// AudioRoutingManager
template<typename> struct AudioRoutingManager_statics {
	static ptr<AudioRoutingManager> GetDefault() { AudioRoutingManager* audioRoutingManager; hrcheck(get_activation_factory<AudioRoutingManager, IAudioRoutingManagerStatics>()->_GetDefault(&audioRoutingManager)); return from_abi(audioRoutingManager); }
};

template<typename X> struct statics<AudioRoutingManager, X> : X, Windows::Phone::Media::Devices::AudioRoutingManager_statics<void> {
	typedef typename X::root_type AudioRoutingManager;
};
struct AudioRoutingManager : generate<AudioRoutingManager> {};
}}}}
} // namespace iso_winrt
