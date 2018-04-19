#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices.Input.Preview

#include "Windows.Devices.Input.Preview.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace HumanInterfaceDevice {
struct HidInputReport;
struct HidNumericControlDescription;
struct HidBooleanControlDescription;
}}
namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
template<typename T> struct IVector;
}}}

// defs

template<> struct def<Windows::Devices::Input::Preview::GazeDeviceConfigurationStatePreview> : enum_type<int> {};
template<> struct def<Windows::Devices::Input::Preview::IGazeInputSourcePreviewStatics> : interface_type<> {};
template<> struct def<Windows::Devices::Input::Preview::IGazeInputSourcePreview> : interface_type<> {};
template<> struct def<Windows::Devices::Input::Preview::GazeInputSourcePreview> : class_type<Platform::Object, Windows::Devices::Input::Preview::IGazeInputSourcePreview> {};
template<> struct def<Windows::Devices::Input::Preview::IGazeDeviceWatcherPreview> : interface_type<> {};
template<> struct def<Windows::Devices::Input::Preview::GazeDeviceWatcherPreview> : class_type<Platform::Object, Windows::Devices::Input::Preview::IGazeDeviceWatcherPreview> {};
template<> struct def<Windows::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::Input::Preview::GazeDeviceWatcherAddedPreviewEventArgs> : class_type<Platform::Object, Windows::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs> {};
template<> struct def<Windows::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::Input::Preview::GazeDeviceWatcherRemovedPreviewEventArgs> : class_type<Platform::Object, Windows::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs> {};
template<> struct def<Windows::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::Input::Preview::GazeDeviceWatcherUpdatedPreviewEventArgs> : class_type<Platform::Object, Windows::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs> {};
template<> struct def<Windows::Devices::Input::Preview::IGazeMovedPreviewEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::Input::Preview::GazeMovedPreviewEventArgs> : class_type<Platform::Object, Windows::Devices::Input::Preview::IGazeMovedPreviewEventArgs> {};
template<> struct def<Windows::Devices::Input::Preview::IGazeEnteredPreviewEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::Input::Preview::GazeEnteredPreviewEventArgs> : class_type<Platform::Object, Windows::Devices::Input::Preview::IGazeEnteredPreviewEventArgs> {};
template<> struct def<Windows::Devices::Input::Preview::IGazeExitedPreviewEventArgs> : interface_type<> {};
template<> struct def<Windows::Devices::Input::Preview::GazeExitedPreviewEventArgs> : class_type<Platform::Object, Windows::Devices::Input::Preview::IGazeExitedPreviewEventArgs> {};
template<> struct def<Windows::Devices::Input::Preview::IGazeDevicePreview> : interface_type<> {};
template<> struct def<Windows::Devices::Input::Preview::GazeDevicePreview> : class_type<Platform::Object, Windows::Devices::Input::Preview::IGazeDevicePreview> {};
template<> struct def<Windows::Devices::Input::Preview::IGazePointPreview> : interface_type<> {};
template<> struct def<Windows::Devices::Input::Preview::GazePointPreview> : class_type<Platform::Object, Windows::Devices::Input::Preview::IGazePointPreview> {};

// uuids

template<> struct uuid<Windows::Devices::Input::Preview::IGazeInputSourcePreviewStatics> { define_guid(0xE79E7EE6, 0xB389, 0x11E7, 0xB2, 0x1, 0xC8, 0xD3, 0xFF, 0xB7, 0x57, 0x21);};
template<> struct uuid<Windows::Devices::Input::Preview::IGazeInputSourcePreview> { define_guid(0xE79E7EE8, 0xB389, 0x11E7, 0xB2, 0x1, 0xC8, 0xD3, 0xFF, 0xB7, 0x57, 0x21);};
template<> struct uuid<Windows::Devices::Input::Preview::IGazeDeviceWatcherPreview> { define_guid(0xE79E7EE7, 0xB389, 0x11E7, 0xB2, 0x1, 0xC8, 0xD3, 0xFF, 0xB7, 0x57, 0x21);};
template<> struct uuid<Windows::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs> { define_guid(0xE79E7EED, 0xB389, 0x11E7, 0xB2, 0x1, 0xC8, 0xD3, 0xFF, 0xB7, 0x57, 0x21);};
template<> struct uuid<Windows::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs> { define_guid(0xF2631F08, 0xE3F, 0x431F, 0xA6, 0x6, 0x50, 0xB3, 0x5A, 0xF9, 0x4A, 0x1C);};
template<> struct uuid<Windows::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs> { define_guid(0x7FE830EF, 0x7F08, 0x4737, 0x88, 0xE1, 0x4A, 0x83, 0xAE, 0x4E, 0x48, 0x85);};
template<> struct uuid<Windows::Devices::Input::Preview::IGazeMovedPreviewEventArgs> { define_guid(0xE79E7EEB, 0xB389, 0x11E7, 0xB2, 0x1, 0xC8, 0xD3, 0xFF, 0xB7, 0x57, 0x21);};
template<> struct uuid<Windows::Devices::Input::Preview::IGazeEnteredPreviewEventArgs> { define_guid(0x2567BF43, 0x1225, 0x489F, 0x9D, 0xD1, 0xDA, 0xA7, 0xC5, 0xF, 0xBF, 0x4B);};
template<> struct uuid<Windows::Devices::Input::Preview::IGazeExitedPreviewEventArgs> { define_guid(0x5D0AF07E, 0x7D83, 0x40EF, 0x9F, 0xA, 0xFB, 0xC1, 0xBB, 0xDC, 0xC5, 0xAC);};
template<> struct uuid<Windows::Devices::Input::Preview::IGazeDevicePreview> { define_guid(0xE79E7EE9, 0xB389, 0x11E7, 0xB2, 0x1, 0xC8, 0xD3, 0xFF, 0xB7, 0x57, 0x21);};
template<> struct uuid<Windows::Devices::Input::Preview::IGazePointPreview> { define_guid(0xE79E7EEA, 0xB389, 0x11E7, 0xB2, 0x1, 0xC8, 0xD3, 0xFF, 0xB7, 0x57, 0x21);};

// types

namespace Windows { namespace Devices { namespace Input { namespace Preview {

// IGazeInputSourcePreviewStatics
struct IGazeInputSourcePreviewStatics : IInspectable {
	virtual STDMETHODIMP _GetForCurrentView(GazeInputSourcePreview* *result);
	virtual STDMETHODIMP _CreateWatcher(GazeDeviceWatcherPreview* *result);
};

// IGazeInputSourcePreview
struct IGazeInputSourcePreview_raw : IInspectable {
	virtual STDMETHODIMP _add_GazeMoved(Foundation::TypedEventHandler<GazeInputSourcePreview*, GazeMovedPreviewEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_GazeMoved(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_GazeEntered(Foundation::TypedEventHandler<GazeInputSourcePreview*, GazeEnteredPreviewEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_GazeEntered(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_GazeExited(Foundation::TypedEventHandler<GazeInputSourcePreview*, GazeExitedPreviewEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_GazeExited(Foundation::EventRegistrationToken token);
};
template<typename X> struct IGazeInputSourcePreview_adaptor : X {
	union {
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<GazeInputSourcePreview>, ptr<GazeEnteredPreviewEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IGazeInputSourcePreview_adaptor::GazeEntered)->_add_GazeEntered(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IGazeInputSourcePreview_adaptor::GazeEntered)->_remove_GazeEntered(token)); }
		} GazeEntered;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<GazeInputSourcePreview>, ptr<GazeExitedPreviewEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IGazeInputSourcePreview_adaptor::GazeExited)->_add_GazeExited(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IGazeInputSourcePreview_adaptor::GazeExited)->_remove_GazeExited(token)); }
		} GazeExited;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<GazeInputSourcePreview>, ptr<GazeMovedPreviewEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IGazeInputSourcePreview_adaptor::GazeMoved)->_add_GazeMoved(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IGazeInputSourcePreview_adaptor::GazeMoved)->_remove_GazeMoved(token)); }
		} GazeMoved;
	};
	IGazeInputSourcePreview_adaptor() {}
};
template<typename X> struct adapt<IGazeInputSourcePreview, X> : Windows::Devices::Input::Preview::IGazeInputSourcePreview_adaptor<X> { typedef adapt IGazeInputSourcePreview; };
struct IGazeInputSourcePreview : IGazeInputSourcePreview_raw, generate<IGazeInputSourcePreview> {};

// GazeInputSourcePreview
template<typename> struct GazeInputSourcePreview_statics {
	static ptr<GazeInputSourcePreview> GetForCurrentView() { GazeInputSourcePreview* result; hrcheck(get_activation_factory<GazeInputSourcePreview, IGazeInputSourcePreviewStatics>()->_GetForCurrentView(&result)); return from_abi(result); }
	static ptr<GazeDeviceWatcherPreview> CreateWatcher() { GazeDeviceWatcherPreview* result; hrcheck(get_activation_factory<GazeInputSourcePreview, IGazeInputSourcePreviewStatics>()->_CreateWatcher(&result)); return from_abi(result); }
};

template<typename X> struct statics<GazeInputSourcePreview, X> : X, Windows::Devices::Input::Preview::GazeInputSourcePreview_statics<void> {
	typedef typename X::root_type GazeInputSourcePreview;
};
struct GazeInputSourcePreview : generate<GazeInputSourcePreview> {};

// IGazeDeviceWatcherPreview
struct IGazeDeviceWatcherPreview_raw : IInspectable {
	virtual STDMETHODIMP _add_Added(Foundation::TypedEventHandler<GazeDeviceWatcherPreview*, GazeDeviceWatcherAddedPreviewEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_Added(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_Removed(Foundation::TypedEventHandler<GazeDeviceWatcherPreview*, GazeDeviceWatcherRemovedPreviewEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_Removed(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_Updated(Foundation::TypedEventHandler<GazeDeviceWatcherPreview*, GazeDeviceWatcherUpdatedPreviewEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_Updated(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_EnumerationCompleted(Foundation::TypedEventHandler<GazeDeviceWatcherPreview*, IInspectable*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_EnumerationCompleted(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _Start();
	virtual STDMETHODIMP _Stop();
};
template<typename X> struct IGazeDeviceWatcherPreview_adaptor : X {
	union {
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<GazeDeviceWatcherPreview>, ptr<GazeDeviceWatcherAddedPreviewEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IGazeDeviceWatcherPreview_adaptor::Added)->_add_Added(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IGazeDeviceWatcherPreview_adaptor::Added)->_remove_Added(token)); }
		} Added;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<GazeDeviceWatcherPreview>, object>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IGazeDeviceWatcherPreview_adaptor::EnumerationCompleted)->_add_EnumerationCompleted(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IGazeDeviceWatcherPreview_adaptor::EnumerationCompleted)->_remove_EnumerationCompleted(token)); }
		} EnumerationCompleted;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<GazeDeviceWatcherPreview>, ptr<GazeDeviceWatcherRemovedPreviewEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IGazeDeviceWatcherPreview_adaptor::Removed)->_add_Removed(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IGazeDeviceWatcherPreview_adaptor::Removed)->_remove_Removed(token)); }
		} Removed;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<GazeDeviceWatcherPreview>, ptr<GazeDeviceWatcherUpdatedPreviewEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IGazeDeviceWatcherPreview_adaptor::Updated)->_add_Updated(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IGazeDeviceWatcherPreview_adaptor::Updated)->_remove_Updated(token)); }
		} Updated;
	};
	void Start() { hrcheck(X::get()->_Start()); }
	void Stop() { hrcheck(X::get()->_Stop()); }
	IGazeDeviceWatcherPreview_adaptor() {}
};
template<typename X> struct adapt<IGazeDeviceWatcherPreview, X> : Windows::Devices::Input::Preview::IGazeDeviceWatcherPreview_adaptor<X> { typedef adapt IGazeDeviceWatcherPreview; };
struct IGazeDeviceWatcherPreview : IGazeDeviceWatcherPreview_raw, generate<IGazeDeviceWatcherPreview> {};

// GazeDeviceWatcherPreview
template<typename X> struct statics<GazeDeviceWatcherPreview, X> : X {
	typedef typename X::root_type GazeDeviceWatcherPreview;
};
struct GazeDeviceWatcherPreview : generate<GazeDeviceWatcherPreview> {};

// IGazeDeviceWatcherAddedPreviewEventArgs
struct IGazeDeviceWatcherAddedPreviewEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Device(GazeDevicePreview* *value);
};
template<typename X> struct IGazeDeviceWatcherAddedPreviewEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<GazeDevicePreview> get() { GazeDevicePreview* value; hrcheck(enc(&IGazeDeviceWatcherAddedPreviewEventArgs_adaptor::Device)->_get_Device(&value)); return from_abi(value); }
			ptr<GazeDevicePreview> operator()() { return get(); }
			operator ptr<GazeDevicePreview> () { return get(); }
			ptr<GazeDevicePreview> operator->() { return get(); }
		} Device;
	};
	IGazeDeviceWatcherAddedPreviewEventArgs_adaptor() {}
};
template<typename X> struct adapt<IGazeDeviceWatcherAddedPreviewEventArgs, X> : Windows::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs_adaptor<X> { typedef adapt IGazeDeviceWatcherAddedPreviewEventArgs; };
struct IGazeDeviceWatcherAddedPreviewEventArgs : IGazeDeviceWatcherAddedPreviewEventArgs_raw, generate<IGazeDeviceWatcherAddedPreviewEventArgs> {};

// GazeDeviceWatcherAddedPreviewEventArgs
template<typename X> struct statics<GazeDeviceWatcherAddedPreviewEventArgs, X> : X {
	typedef typename X::root_type GazeDeviceWatcherAddedPreviewEventArgs;
};
struct GazeDeviceWatcherAddedPreviewEventArgs : generate<GazeDeviceWatcherAddedPreviewEventArgs> {};

// IGazeDeviceWatcherRemovedPreviewEventArgs
struct IGazeDeviceWatcherRemovedPreviewEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Device(GazeDevicePreview* *value);
};
template<typename X> struct IGazeDeviceWatcherRemovedPreviewEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<GazeDevicePreview> get() { GazeDevicePreview* value; hrcheck(enc(&IGazeDeviceWatcherRemovedPreviewEventArgs_adaptor::Device)->_get_Device(&value)); return from_abi(value); }
			ptr<GazeDevicePreview> operator()() { return get(); }
			operator ptr<GazeDevicePreview> () { return get(); }
			ptr<GazeDevicePreview> operator->() { return get(); }
		} Device;
	};
	IGazeDeviceWatcherRemovedPreviewEventArgs_adaptor() {}
};
template<typename X> struct adapt<IGazeDeviceWatcherRemovedPreviewEventArgs, X> : Windows::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs_adaptor<X> { typedef adapt IGazeDeviceWatcherRemovedPreviewEventArgs; };
struct IGazeDeviceWatcherRemovedPreviewEventArgs : IGazeDeviceWatcherRemovedPreviewEventArgs_raw, generate<IGazeDeviceWatcherRemovedPreviewEventArgs> {};

// GazeDeviceWatcherRemovedPreviewEventArgs
template<typename X> struct statics<GazeDeviceWatcherRemovedPreviewEventArgs, X> : X {
	typedef typename X::root_type GazeDeviceWatcherRemovedPreviewEventArgs;
};
struct GazeDeviceWatcherRemovedPreviewEventArgs : generate<GazeDeviceWatcherRemovedPreviewEventArgs> {};

// IGazeDeviceWatcherUpdatedPreviewEventArgs
struct IGazeDeviceWatcherUpdatedPreviewEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Device(GazeDevicePreview* *value);
};
template<typename X> struct IGazeDeviceWatcherUpdatedPreviewEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<GazeDevicePreview> get() { GazeDevicePreview* value; hrcheck(enc(&IGazeDeviceWatcherUpdatedPreviewEventArgs_adaptor::Device)->_get_Device(&value)); return from_abi(value); }
			ptr<GazeDevicePreview> operator()() { return get(); }
			operator ptr<GazeDevicePreview> () { return get(); }
			ptr<GazeDevicePreview> operator->() { return get(); }
		} Device;
	};
	IGazeDeviceWatcherUpdatedPreviewEventArgs_adaptor() {}
};
template<typename X> struct adapt<IGazeDeviceWatcherUpdatedPreviewEventArgs, X> : Windows::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs_adaptor<X> { typedef adapt IGazeDeviceWatcherUpdatedPreviewEventArgs; };
struct IGazeDeviceWatcherUpdatedPreviewEventArgs : IGazeDeviceWatcherUpdatedPreviewEventArgs_raw, generate<IGazeDeviceWatcherUpdatedPreviewEventArgs> {};

// GazeDeviceWatcherUpdatedPreviewEventArgs
template<typename X> struct statics<GazeDeviceWatcherUpdatedPreviewEventArgs, X> : X {
	typedef typename X::root_type GazeDeviceWatcherUpdatedPreviewEventArgs;
};
struct GazeDeviceWatcherUpdatedPreviewEventArgs : generate<GazeDeviceWatcherUpdatedPreviewEventArgs> {};

// IGazeMovedPreviewEventArgs
struct IGazeMovedPreviewEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Handled(bool *value);
	virtual STDMETHODIMP _put_Handled(bool value);
	virtual STDMETHODIMP _get_CurrentPoint(GazePointPreview* *value);
	virtual STDMETHODIMP _GetIntermediatePoints(Foundation::Collections::IVector<GazePointPreview*>* *result);
};
template<typename X> struct IGazeMovedPreviewEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<GazePointPreview> get() { GazePointPreview* value; hrcheck(enc(&IGazeMovedPreviewEventArgs_adaptor::CurrentPoint)->_get_CurrentPoint(&value)); return from_abi(value); }
			ptr<GazePointPreview> operator()() { return get(); }
			operator ptr<GazePointPreview> () { return get(); }
			ptr<GazePointPreview> operator->() { return get(); }
		} CurrentPoint;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IGazeMovedPreviewEventArgs_adaptor::Handled)->_get_Handled(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IGazeMovedPreviewEventArgs_adaptor::Handled)->_put_Handled(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} Handled;
	};
	ptr<Foundation::Collections::IVector<ptr<GazePointPreview>>> GetIntermediatePoints() { Foundation::Collections::IVector<GazePointPreview*>* result; hrcheck(X::get()->_GetIntermediatePoints(&result)); return from_abi(result); }
	IGazeMovedPreviewEventArgs_adaptor() {}
};
template<typename X> struct adapt<IGazeMovedPreviewEventArgs, X> : Windows::Devices::Input::Preview::IGazeMovedPreviewEventArgs_adaptor<X> { typedef adapt IGazeMovedPreviewEventArgs; };
struct IGazeMovedPreviewEventArgs : IGazeMovedPreviewEventArgs_raw, generate<IGazeMovedPreviewEventArgs> {};

// GazeMovedPreviewEventArgs
template<typename X> struct statics<GazeMovedPreviewEventArgs, X> : X {
	typedef typename X::root_type GazeMovedPreviewEventArgs;
};
struct GazeMovedPreviewEventArgs : generate<GazeMovedPreviewEventArgs> {};

// IGazeEnteredPreviewEventArgs
struct IGazeEnteredPreviewEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Handled(bool *value);
	virtual STDMETHODIMP _put_Handled(bool value);
	virtual STDMETHODIMP _get_CurrentPoint(GazePointPreview* *value);
};
template<typename X> struct IGazeEnteredPreviewEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<GazePointPreview> get() { GazePointPreview* value; hrcheck(enc(&IGazeEnteredPreviewEventArgs_adaptor::CurrentPoint)->_get_CurrentPoint(&value)); return from_abi(value); }
			ptr<GazePointPreview> operator()() { return get(); }
			operator ptr<GazePointPreview> () { return get(); }
			ptr<GazePointPreview> operator->() { return get(); }
		} CurrentPoint;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IGazeEnteredPreviewEventArgs_adaptor::Handled)->_get_Handled(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IGazeEnteredPreviewEventArgs_adaptor::Handled)->_put_Handled(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} Handled;
	};
	IGazeEnteredPreviewEventArgs_adaptor() {}
};
template<typename X> struct adapt<IGazeEnteredPreviewEventArgs, X> : Windows::Devices::Input::Preview::IGazeEnteredPreviewEventArgs_adaptor<X> { typedef adapt IGazeEnteredPreviewEventArgs; };
struct IGazeEnteredPreviewEventArgs : IGazeEnteredPreviewEventArgs_raw, generate<IGazeEnteredPreviewEventArgs> {};

// GazeEnteredPreviewEventArgs
template<typename X> struct statics<GazeEnteredPreviewEventArgs, X> : X {
	typedef typename X::root_type GazeEnteredPreviewEventArgs;
};
struct GazeEnteredPreviewEventArgs : generate<GazeEnteredPreviewEventArgs> {};

// IGazeExitedPreviewEventArgs
struct IGazeExitedPreviewEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Handled(bool *value);
	virtual STDMETHODIMP _put_Handled(bool value);
	virtual STDMETHODIMP _get_CurrentPoint(GazePointPreview* *value);
};
template<typename X> struct IGazeExitedPreviewEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<GazePointPreview> get() { GazePointPreview* value; hrcheck(enc(&IGazeExitedPreviewEventArgs_adaptor::CurrentPoint)->_get_CurrentPoint(&value)); return from_abi(value); }
			ptr<GazePointPreview> operator()() { return get(); }
			operator ptr<GazePointPreview> () { return get(); }
			ptr<GazePointPreview> operator->() { return get(); }
		} CurrentPoint;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IGazeExitedPreviewEventArgs_adaptor::Handled)->_get_Handled(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IGazeExitedPreviewEventArgs_adaptor::Handled)->_put_Handled(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} Handled;
	};
	IGazeExitedPreviewEventArgs_adaptor() {}
};
template<typename X> struct adapt<IGazeExitedPreviewEventArgs, X> : Windows::Devices::Input::Preview::IGazeExitedPreviewEventArgs_adaptor<X> { typedef adapt IGazeExitedPreviewEventArgs; };
struct IGazeExitedPreviewEventArgs : IGazeExitedPreviewEventArgs_raw, generate<IGazeExitedPreviewEventArgs> {};

// GazeExitedPreviewEventArgs
template<typename X> struct statics<GazeExitedPreviewEventArgs, X> : X {
	typedef typename X::root_type GazeExitedPreviewEventArgs;
};
struct GazeExitedPreviewEventArgs : generate<GazeExitedPreviewEventArgs> {};

// IGazeDevicePreview
struct IGazeDevicePreview_raw : IInspectable {
	virtual STDMETHODIMP _get_Id(unsigned *value);
	virtual STDMETHODIMP _get_CanTrackEyes(bool *value);
	virtual STDMETHODIMP _get_CanTrackHead(bool *value);
	virtual STDMETHODIMP _get_ConfigurationState(GazeDeviceConfigurationStatePreview *value);
	virtual STDMETHODIMP _RequestCalibrationAsync(Foundation::IAsyncOperation<bool>* *operation);
	virtual STDMETHODIMP _GetNumericControlDescriptions(unsigned short usagePage, unsigned short usageId, Foundation::Collections::IVectorView<HumanInterfaceDevice::HidNumericControlDescription*>* *result);
	virtual STDMETHODIMP _GetBooleanControlDescriptions(unsigned short usagePage, unsigned short usageId, Foundation::Collections::IVectorView<HumanInterfaceDevice::HidBooleanControlDescription*>* *result);
};
template<typename X> struct IGazeDevicePreview_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IGazeDevicePreview_adaptor::CanTrackEyes)->_get_CanTrackEyes(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} CanTrackEyes;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IGazeDevicePreview_adaptor::CanTrackHead)->_get_CanTrackHead(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} CanTrackHead;
		struct : property {
			GazeDeviceConfigurationStatePreview get() { GazeDeviceConfigurationStatePreview value; hrcheck(enc(&IGazeDevicePreview_adaptor::ConfigurationState)->_get_ConfigurationState(&value)); return value; }
			GazeDeviceConfigurationStatePreview operator()() { return get(); }
			operator GazeDeviceConfigurationStatePreview () { return get(); }
		} ConfigurationState;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IGazeDevicePreview_adaptor::Id)->_get_Id(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} Id;
	};
	ptr<Foundation::IAsyncOperation<bool>> RequestCalibrationAsync() { Foundation::IAsyncOperation<bool>* operation; hrcheck(X::get()->_RequestCalibrationAsync(&operation)); return from_abi(operation); }
	ptr<Foundation::Collections::IVectorView<ptr<HumanInterfaceDevice::HidNumericControlDescription>>> GetNumericControlDescriptions(unsigned short usagePage, unsigned short usageId) { Foundation::Collections::IVectorView<HumanInterfaceDevice::HidNumericControlDescription*>* result; hrcheck(X::get()->_GetNumericControlDescriptions(usagePage, usageId, &result)); return from_abi(result); }
	ptr<Foundation::Collections::IVectorView<ptr<HumanInterfaceDevice::HidBooleanControlDescription>>> GetBooleanControlDescriptions(unsigned short usagePage, unsigned short usageId) { Foundation::Collections::IVectorView<HumanInterfaceDevice::HidBooleanControlDescription*>* result; hrcheck(X::get()->_GetBooleanControlDescriptions(usagePage, usageId, &result)); return from_abi(result); }
	IGazeDevicePreview_adaptor() {}
};
template<typename X> struct adapt<IGazeDevicePreview, X> : Windows::Devices::Input::Preview::IGazeDevicePreview_adaptor<X> { typedef adapt IGazeDevicePreview; };
struct IGazeDevicePreview : IGazeDevicePreview_raw, generate<IGazeDevicePreview> {};

// GazeDevicePreview
template<typename X> struct statics<GazeDevicePreview, X> : X {
	typedef typename X::root_type GazeDevicePreview;
};
struct GazeDevicePreview : generate<GazeDevicePreview> {};

// IGazePointPreview
struct IGazePointPreview_raw : IInspectable {
	virtual STDMETHODIMP _get_SourceDevice(GazeDevicePreview* *value);
	virtual STDMETHODIMP _get_EyeGazePosition(Foundation::IReference<Foundation::Point>* *value);
	virtual STDMETHODIMP _get_HeadGazePosition(Foundation::IReference<Foundation::Point>* *value);
	virtual STDMETHODIMP _get_Timestamp(unsigned __int64 *value);
	virtual STDMETHODIMP _get_HidInputReport(HumanInterfaceDevice::HidInputReport* *value);
};
template<typename X> struct IGazePointPreview_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::IReference<Foundation::Point>> get() { Foundation::IReference<Foundation::Point>* value; hrcheck(enc(&IGazePointPreview_adaptor::EyeGazePosition)->_get_EyeGazePosition(&value)); return from_abi(value); }
			ptr<Foundation::IReference<Foundation::Point>> operator()() { return get(); }
			operator ptr<Foundation::IReference<Foundation::Point>> () { return get(); }
			ptr<Foundation::IReference<Foundation::Point>> operator->() { return get(); }
		} EyeGazePosition;
		struct : property {
			ptr<Foundation::IReference<Foundation::Point>> get() { Foundation::IReference<Foundation::Point>* value; hrcheck(enc(&IGazePointPreview_adaptor::HeadGazePosition)->_get_HeadGazePosition(&value)); return from_abi(value); }
			ptr<Foundation::IReference<Foundation::Point>> operator()() { return get(); }
			operator ptr<Foundation::IReference<Foundation::Point>> () { return get(); }
			ptr<Foundation::IReference<Foundation::Point>> operator->() { return get(); }
		} HeadGazePosition;
		struct : property {
			ptr<HumanInterfaceDevice::HidInputReport> get() { HumanInterfaceDevice::HidInputReport* value; hrcheck(enc(&IGazePointPreview_adaptor::HidInputReport)->_get_HidInputReport(&value)); return from_abi(value); }
			ptr<HumanInterfaceDevice::HidInputReport> operator()() { return get(); }
			operator ptr<HumanInterfaceDevice::HidInputReport> () { return get(); }
			ptr<HumanInterfaceDevice::HidInputReport> operator->() { return get(); }
		} HidInputReport;
		struct : property {
			ptr<GazeDevicePreview> get() { GazeDevicePreview* value; hrcheck(enc(&IGazePointPreview_adaptor::SourceDevice)->_get_SourceDevice(&value)); return from_abi(value); }
			ptr<GazeDevicePreview> operator()() { return get(); }
			operator ptr<GazeDevicePreview> () { return get(); }
			ptr<GazeDevicePreview> operator->() { return get(); }
		} SourceDevice;
		struct : property {
			unsigned __int64 get() { unsigned __int64 value; hrcheck(enc(&IGazePointPreview_adaptor::Timestamp)->_get_Timestamp(&value)); return value; }
			unsigned __int64 operator()() { return get(); }
			operator unsigned __int64 () { return get(); }
		} Timestamp;
	};
	IGazePointPreview_adaptor() {}
};
template<typename X> struct adapt<IGazePointPreview, X> : Windows::Devices::Input::Preview::IGazePointPreview_adaptor<X> { typedef adapt IGazePointPreview; };
struct IGazePointPreview : IGazePointPreview_raw, generate<IGazePointPreview> {};

// GazePointPreview
template<typename X> struct statics<GazePointPreview, X> : X {
	typedef typename X::root_type GazePointPreview;
};
struct GazePointPreview : generate<GazePointPreview> {};
}}}}
} // namespace iso_winrt
