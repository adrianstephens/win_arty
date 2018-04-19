#pragma once
// generated by isopod tools
// namespaces:
// Windows.Gaming.UI

#include "Windows.Gaming.UI.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.ApplicationModel.Activation.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
struct ValueSet;
}}}

// defs

template<> struct def<Windows::Gaming::UI::IGameBarStatics> : interface_type<> {};
template<> struct def<Windows::Gaming::UI::GameBar> : class_type<Platform::Object, Platform::Object> {};
template<> struct def<Windows::Gaming::UI::GameChatOverlayPosition> : enum_type<int> {};
template<> struct def<Windows::Gaming::UI::GameChatMessageOrigin> : enum_type<int> {};
template<> struct def<Windows::Gaming::UI::IGameChatOverlayStatics> : interface_type<> {};
template<> struct def<Windows::Gaming::UI::IGameChatOverlay> : interface_type<> {};
template<> struct def<Windows::Gaming::UI::GameChatOverlay> : class_type<Platform::Object, Windows::Gaming::UI::IGameChatOverlay> {};
template<> struct def<Windows::Gaming::UI::GameMonitoringPermission> : enum_type<int> {};
template<> struct def<Windows::Gaming::UI::IGameMonitor> : interface_type<> {};
template<> struct def<Windows::Gaming::UI::IGameMonitorStatics> : interface_type<> {};
template<> struct def<Windows::Gaming::UI::GameMonitor> : class_type<Platform::Object, Windows::Gaming::UI::IGameMonitor> {};
template<> struct def<Windows::Gaming::UI::GameChatOverlayContract> : value_type<> {};
template<> struct def<Windows::Gaming::UI::IGameChatOverlayMessageSource> : interface_type<> {};
template<> struct def<Windows::Gaming::UI::GameChatOverlayMessageSource> : class_type<Platform::Object, Windows::Gaming::UI::IGameChatOverlayMessageSource> {};
template<> struct def<Windows::Gaming::UI::IGameChatMessageReceivedEventArgs> : interface_type<> {};
template<> struct def<Windows::Gaming::UI::GameChatMessageReceivedEventArgs> : class_type<Platform::Object, Windows::Gaming::UI::IGameChatMessageReceivedEventArgs> {};
template<> struct def<Windows::Gaming::UI::GamingUIProviderContract> : value_type<> {};
template<> struct def<Windows::Gaming::UI::IGameUIProviderActivatedEventArgs> : interface_type<Windows::ApplicationModel::Activation::IActivatedEventArgs> {};
template<> struct def<Windows::Gaming::UI::GameUIProviderActivatedEventArgs> : class_type<Platform::Object, Windows::Gaming::UI::IGameUIProviderActivatedEventArgs> {};

// uuids

template<> struct uuid<Windows::Gaming::UI::IGameBarStatics> { define_guid(0x1DB9A292, 0xCC78, 0x4173, 0xBE, 0x45, 0xB6, 0x1E, 0x67, 0x28, 0x3E, 0xA7);};
template<> struct uuid<Windows::Gaming::UI::IGameChatOverlayStatics> { define_guid(0x89ACF614, 0x7867, 0x49F7, 0x96, 0x87, 0x25, 0xD9, 0xDB, 0xF4, 0x44, 0xD1);};
template<> struct uuid<Windows::Gaming::UI::IGameChatOverlay> { define_guid(0xFBC64865, 0xF6FC, 0x4A48, 0xAE, 0x7, 0x3, 0xAC, 0x6E, 0xD4, 0x37, 0x4);};
template<> struct uuid<Windows::Gaming::UI::IGameMonitor> { define_guid(0x12234358, 0xDD09, 0x4511, 0xAD, 0xCD, 0x8D, 0x59, 0x75, 0xD8, 0x10, 0x28);};
template<> struct uuid<Windows::Gaming::UI::IGameMonitorStatics> { define_guid(0x11674B34, 0x5AE0, 0x4BB4, 0xB9, 0x1F, 0x8A, 0xCB, 0x48, 0x15, 0x9A, 0x71);};
template<> struct uuid<Windows::Gaming::UI::IGameChatOverlayMessageSource> { define_guid(0x1E177397, 0x59FB, 0x4F4F, 0x8E, 0x9A, 0x80, 0xAC, 0xF8, 0x17, 0x74, 0x3C);};
template<> struct uuid<Windows::Gaming::UI::IGameChatMessageReceivedEventArgs> { define_guid(0xA28201F1, 0x3FB9, 0x4E42, 0xA4, 0x3, 0x7A, 0xFC, 0xE2, 0x2, 0x3B, 0x1E);};
template<> struct uuid<Windows::Gaming::UI::IGameUIProviderActivatedEventArgs> { define_guid(0xA7B3203E, 0xCAF7, 0x4DED, 0xBB, 0xD2, 0x47, 0xDE, 0x43, 0xBB, 0x6D, 0xD5);};

// types

namespace Windows { namespace Gaming { namespace UI {

// IGameBarStatics
struct IGameBarStatics : IInspectable {
	virtual STDMETHODIMP _add_VisibilityChanged(Foundation::EventHandler<IInspectable*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_VisibilityChanged(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_IsInputRedirectedChanged(Foundation::EventHandler<IInspectable*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_IsInputRedirectedChanged(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _get_Visible(bool *value);
	virtual STDMETHODIMP _get_IsInputRedirected(bool *value);
};

// GameBar
template<typename> struct GameBar_statics {
	static struct _IsInputRedirected : property {
		bool get() { bool value; hrcheck(get_activation_factory<GameBar, IGameBarStatics>()->_get_IsInputRedirected(&value)); return value; }
		bool operator()() { return get(); }
		operator bool () { return get(); }
	} IsInputRedirected;
	static struct _Visible : property {
		bool get() { bool value; hrcheck(get_activation_factory<GameBar, IGameBarStatics>()->_get_Visible(&value)); return value; }
		bool operator()() { return get(); }
		operator bool () { return get(); }
	} Visible;
	static struct _IsInputRedirectedChanged : property {
		Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::EventHandler<object>> handler) { Foundation::EventRegistrationToken token; hrcheck(get_activation_factory<GameBar, IGameBarStatics>()->_add_IsInputRedirectedChanged(to_abi(handler), &token)); return token; }
		void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(get_activation_factory<GameBar, IGameBarStatics>()->_remove_IsInputRedirectedChanged(token)); }
	} IsInputRedirectedChanged;
	static struct _VisibilityChanged : property {
		Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::EventHandler<object>> handler) { Foundation::EventRegistrationToken token; hrcheck(get_activation_factory<GameBar, IGameBarStatics>()->_add_VisibilityChanged(to_abi(handler), &token)); return token; }
		void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(get_activation_factory<GameBar, IGameBarStatics>()->_remove_VisibilityChanged(token)); }
	} VisibilityChanged;
};
template<typename X> typename GameBar_statics<X>::_IsInputRedirected GameBar_statics<X>::IsInputRedirected;
template<typename X> typename GameBar_statics<X>::_Visible GameBar_statics<X>::Visible;
template<typename X> typename GameBar_statics<X>::_IsInputRedirectedChanged GameBar_statics<X>::IsInputRedirectedChanged;
template<typename X> typename GameBar_statics<X>::_VisibilityChanged GameBar_statics<X>::VisibilityChanged;

template<typename X> struct statics<GameBar, X> : X, Windows::Gaming::UI::GameBar_statics<void> {
	typedef typename X::root_type GameBar;
};
struct GameBar : generate<GameBar> {};

// IGameChatOverlayStatics
struct IGameChatOverlayStatics : IInspectable {
	virtual STDMETHODIMP _GetDefault(GameChatOverlay* *value);
};

// IGameChatOverlay
struct IGameChatOverlay_raw : IInspectable {
	virtual STDMETHODIMP _get_DesiredPosition(GameChatOverlayPosition *value);
	virtual STDMETHODIMP _put_DesiredPosition(GameChatOverlayPosition value);
	virtual STDMETHODIMP _AddMessage(HSTRING sender, HSTRING message, GameChatMessageOrigin origin);
};
template<typename X> struct IGameChatOverlay_adaptor : X {
	union {
		struct : property {
			GameChatOverlayPosition get() { GameChatOverlayPosition value; hrcheck(enc(&IGameChatOverlay_adaptor::DesiredPosition)->_get_DesiredPosition(&value)); return value; }
			GameChatOverlayPosition operator()() { return get(); }
			operator GameChatOverlayPosition () { return get(); }
			void put(GameChatOverlayPosition value) { hrcheck(enc(&IGameChatOverlay_adaptor::DesiredPosition)->_put_DesiredPosition(value)); }
			void operator=(GameChatOverlayPosition value) { put(value); }
			void operator()(GameChatOverlayPosition value) { put(value); }
		} DesiredPosition;
	};
	void AddMessage(hstring_ref sender, hstring_ref message, GameChatMessageOrigin origin) { hrcheck(X::get()->_AddMessage(sender, message, origin)); }
	IGameChatOverlay_adaptor() {}
};
template<typename X> struct adapt<IGameChatOverlay, X> : Windows::Gaming::UI::IGameChatOverlay_adaptor<X> { typedef adapt IGameChatOverlay; };
struct IGameChatOverlay : IGameChatOverlay_raw, generate<IGameChatOverlay> {};

// GameChatOverlay
template<typename> struct GameChatOverlay_statics {
	static ptr<GameChatOverlay> GetDefault() { GameChatOverlay* value; hrcheck(get_activation_factory<GameChatOverlay, IGameChatOverlayStatics>()->_GetDefault(&value)); return from_abi(value); }
};

template<typename X> struct statics<GameChatOverlay, X> : X, Windows::Gaming::UI::GameChatOverlay_statics<void> {
	typedef typename X::root_type GameChatOverlay;
};
struct GameChatOverlay : generate<GameChatOverlay> {};

// IGameMonitor
struct IGameMonitor_raw : IInspectable {
	virtual STDMETHODIMP _RequestPermissionAsync(Foundation::IAsyncOperation<GameMonitoringPermission>* *operation);
};
template<typename X> struct IGameMonitor_adaptor : X {
	ptr<Foundation::IAsyncOperation<GameMonitoringPermission>> RequestPermissionAsync() { Foundation::IAsyncOperation<GameMonitoringPermission>* operation; hrcheck(X::get()->_RequestPermissionAsync(&operation)); return from_abi(operation); }
};
template<typename X> struct adapt<IGameMonitor, X> : Windows::Gaming::UI::IGameMonitor_adaptor<X> { typedef adapt IGameMonitor; };
struct IGameMonitor : IGameMonitor_raw, generate<IGameMonitor> {};

// IGameMonitorStatics
struct IGameMonitorStatics : IInspectable {
	virtual STDMETHODIMP _GetDefault(GameMonitor* *gameMonitor);
};

// GameMonitor
template<typename> struct GameMonitor_statics {
	static ptr<GameMonitor> GetDefault() { GameMonitor* gameMonitor; hrcheck(get_activation_factory<GameMonitor, IGameMonitorStatics>()->_GetDefault(&gameMonitor)); return from_abi(gameMonitor); }
};

template<typename X> struct statics<GameMonitor, X> : X, Windows::Gaming::UI::GameMonitor_statics<void> {
	typedef typename X::root_type GameMonitor;
};
struct GameMonitor : generate<GameMonitor> {};

// IGameChatOverlayMessageSource
struct IGameChatOverlayMessageSource_raw : IInspectable {
	virtual STDMETHODIMP _add_MessageReceived(Foundation::TypedEventHandler<GameChatOverlayMessageSource*, GameChatMessageReceivedEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_MessageReceived(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _SetDelayBeforeClosingAfterMessageReceived(Foundation::TimeSpan value);
};
template<typename X> struct IGameChatOverlayMessageSource_adaptor : X {
	union {
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<GameChatOverlayMessageSource>, ptr<GameChatMessageReceivedEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IGameChatOverlayMessageSource_adaptor::MessageReceived)->_add_MessageReceived(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IGameChatOverlayMessageSource_adaptor::MessageReceived)->_remove_MessageReceived(token)); }
		} MessageReceived;
	};
	void SetDelayBeforeClosingAfterMessageReceived(const Foundation::TimeSpan& value) { hrcheck(X::get()->_SetDelayBeforeClosingAfterMessageReceived(value)); }
	IGameChatOverlayMessageSource_adaptor() {}
};
template<typename X> struct adapt<IGameChatOverlayMessageSource, X> : Windows::Gaming::UI::IGameChatOverlayMessageSource_adaptor<X> { typedef adapt IGameChatOverlayMessageSource; };
struct IGameChatOverlayMessageSource : IGameChatOverlayMessageSource_raw, generate<IGameChatOverlayMessageSource> {};

// GameChatOverlayMessageSource
template<typename X> struct statics<GameChatOverlayMessageSource, X> : X {
	typedef typename X::root_type GameChatOverlayMessageSource;
};
struct GameChatOverlayMessageSource : generate<GameChatOverlayMessageSource> {};

// IGameChatMessageReceivedEventArgs
struct IGameChatMessageReceivedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_AppId(HSTRING *value);
	virtual STDMETHODIMP _get_AppDisplayName(HSTRING *value);
	virtual STDMETHODIMP _get_SenderName(HSTRING *value);
	virtual STDMETHODIMP _get_Message(HSTRING *value);
	virtual STDMETHODIMP _get_Origin(GameChatMessageOrigin *value);
};
template<typename X> struct IGameChatMessageReceivedEventArgs_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IGameChatMessageReceivedEventArgs_adaptor::AppDisplayName)->_get_AppDisplayName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} AppDisplayName;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IGameChatMessageReceivedEventArgs_adaptor::AppId)->_get_AppId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} AppId;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IGameChatMessageReceivedEventArgs_adaptor::Message)->_get_Message(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Message;
		struct : property {
			GameChatMessageOrigin get() { GameChatMessageOrigin value; hrcheck(enc(&IGameChatMessageReceivedEventArgs_adaptor::Origin)->_get_Origin(&value)); return value; }
			GameChatMessageOrigin operator()() { return get(); }
			operator GameChatMessageOrigin () { return get(); }
		} Origin;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IGameChatMessageReceivedEventArgs_adaptor::SenderName)->_get_SenderName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} SenderName;
	};
	IGameChatMessageReceivedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IGameChatMessageReceivedEventArgs, X> : Windows::Gaming::UI::IGameChatMessageReceivedEventArgs_adaptor<X> { typedef adapt IGameChatMessageReceivedEventArgs; };
struct IGameChatMessageReceivedEventArgs : IGameChatMessageReceivedEventArgs_raw, generate<IGameChatMessageReceivedEventArgs> {};

// GameChatMessageReceivedEventArgs
template<typename X> struct statics<GameChatMessageReceivedEventArgs, X> : X {
	typedef typename X::root_type GameChatMessageReceivedEventArgs;
};
struct GameChatMessageReceivedEventArgs : generate<GameChatMessageReceivedEventArgs> {};

// IGameUIProviderActivatedEventArgs
struct IGameUIProviderActivatedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_GameUIArgs(Foundation::Collections::ValueSet* *value);
	virtual STDMETHODIMP _ReportCompleted(Foundation::Collections::ValueSet* results);
};
template<typename X> struct IGameUIProviderActivatedEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::ValueSet> get() { Foundation::Collections::ValueSet* value; hrcheck(enc(&IGameUIProviderActivatedEventArgs_adaptor::GameUIArgs)->_get_GameUIArgs(&value)); return from_abi(value); }
			ptr<Foundation::Collections::ValueSet> operator()() { return get(); }
			operator ptr<Foundation::Collections::ValueSet> () { return get(); }
			ptr<Foundation::Collections::ValueSet> operator->() { return get(); }
		} GameUIArgs;
	};
	void ReportCompleted(pptr<Foundation::Collections::ValueSet> results) { hrcheck(X::get()->_ReportCompleted(results)); }
	IGameUIProviderActivatedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IGameUIProviderActivatedEventArgs, X> : Windows::Gaming::UI::IGameUIProviderActivatedEventArgs_adaptor<X> { typedef adapt IGameUIProviderActivatedEventArgs; };
struct IGameUIProviderActivatedEventArgs : IGameUIProviderActivatedEventArgs_raw, generate<IGameUIProviderActivatedEventArgs> {};

// GameUIProviderActivatedEventArgs
template<typename X> struct statics<GameUIProviderActivatedEventArgs, X> : X {
	typedef typename X::root_type GameUIProviderActivatedEventArgs;
};
struct GameUIProviderActivatedEventArgs : generate<GameUIProviderActivatedEventArgs> {};
}}}
} // namespace iso_winrt