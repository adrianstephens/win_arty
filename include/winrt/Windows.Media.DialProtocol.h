#pragma once
// generated by isopod tools
// namespaces:
// Windows.Media.DialProtocol

#include "Windows.Media.DialProtocol.0.h"
#include "Windows.UI.Popups.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Enumeration {
struct DeviceInformation;
struct DevicePickerAppearance;
}}
namespace Foundation { namespace Collections {
template<typename T> struct IVector;
template<typename K, typename V> struct IKeyValuePair;
template<typename T> struct IIterable;
template<typename K, typename V> struct IMap;
}}
namespace Storage { namespace Streams {
struct IRandomAccessStreamReference;
}}}

// defs

template<> struct def<Windows::Media::DialProtocol::DialAppState> : enum_type<int> {};
template<> struct def<Windows::Media::DialProtocol::DialAppLaunchResult> : enum_type<int> {};
template<> struct def<Windows::Media::DialProtocol::DialAppStopResult> : enum_type<int> {};
template<> struct def<Windows::Media::DialProtocol::DialDeviceDisplayStatus> : enum_type<int> {};
template<> struct def<Windows::Media::DialProtocol::IDialAppStateDetails> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::DialAppStateDetails> : class_type<Platform::Object, Windows::Media::DialProtocol::IDialAppStateDetails> {};
template<> struct def<Windows::Media::DialProtocol::IDialApp> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::DialApp> : class_type<Platform::Object, Windows::Media::DialProtocol::IDialApp> {};
template<> struct def<Windows::Media::DialProtocol::IDialDevice> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::IDialDevice2> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::IDialDeviceStatics> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::DialDevice> : class_type<Platform::Object, Windows::Media::DialProtocol::IDialDevice, Windows::Media::DialProtocol::IDialDevice2> {};
template<> struct def<Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::DialDeviceSelectedEventArgs> : class_type<Platform::Object, Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs> {};
template<> struct def<Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> : class_type<Platform::Object, Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs> {};
template<> struct def<Windows::Media::DialProtocol::IDialDevicePickerFilter> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::DialDevicePickerFilter> : class_type<Platform::Object, Windows::Media::DialProtocol::IDialDevicePickerFilter> {};
template<> struct def<Windows::Media::DialProtocol::IDialDevicePicker> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::DialDevicePicker> : class_type<Platform::Object, Windows::Media::DialProtocol::IDialDevicePicker> {};
template<> struct def<Windows::Media::DialProtocol::IDialReceiverAppStatics> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::IDialReceiverApp2> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::IDialReceiverApp> : interface_type<> {};
template<> struct def<Windows::Media::DialProtocol::DialReceiverApp> : class_type<Platform::Object, Windows::Media::DialProtocol::IDialReceiverApp, Windows::Media::DialProtocol::IDialReceiverApp2> {};

// uuids

template<> struct uuid<Windows::Media::DialProtocol::IDialAppStateDetails> { define_guid(0xDDC4A4A1, 0xF5DE, 0x400D, 0xBE, 0xA4, 0x8C, 0x84, 0x66, 0xBB, 0x29, 0x61);};
template<> struct uuid<Windows::Media::DialProtocol::IDialApp> { define_guid(0x555FFBD3, 0x45B7, 0x49F3, 0xBB, 0xD7, 0x30, 0x2D, 0xB6, 0x8, 0x46, 0x46);};
template<> struct uuid<Windows::Media::DialProtocol::IDialDevice> { define_guid(0xFFF0EDAF, 0x759F, 0x41D2, 0xA2, 0xA, 0x7F, 0x29, 0xCE, 0xB, 0x37, 0x84);};
template<> struct uuid<Windows::Media::DialProtocol::IDialDevice2> { define_guid(0xBAB7F3D5, 0x5BFB, 0x4EBA, 0x8B, 0x32, 0xB5, 0x7C, 0x5C, 0x5E, 0xE5, 0xC9);};
template<> struct uuid<Windows::Media::DialProtocol::IDialDeviceStatics> { define_guid(0xAA69CC95, 0x1F8, 0x4758, 0x84, 0x61, 0x2B, 0xBD, 0x1C, 0xDC, 0x3C, 0xF3);};
template<> struct uuid<Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs> { define_guid(0x480B92AD, 0xAC76, 0x47EB, 0x9C, 0x6, 0xA1, 0x93, 0x4, 0xDA, 0x2, 0x47);};
template<> struct uuid<Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs> { define_guid(0x52765152, 0x9C81, 0x4E55, 0xAD, 0xC2, 0xE, 0xBE, 0x99, 0xCD, 0xE3, 0xB6);};
template<> struct uuid<Windows::Media::DialProtocol::IDialDevicePickerFilter> { define_guid(0xC17C93BA, 0x86C0, 0x485D, 0xB8, 0xD6, 0xF, 0x9A, 0x8F, 0x64, 0x15, 0x90);};
template<> struct uuid<Windows::Media::DialProtocol::IDialDevicePicker> { define_guid(0xBA7E520A, 0xFF59, 0x4F4B, 0xBD, 0xAC, 0xD8, 0x9F, 0x49, 0x5A, 0xD6, 0xE1);};
template<> struct uuid<Windows::Media::DialProtocol::IDialReceiverAppStatics> { define_guid(0x53183A3C, 0x4C36, 0x4D02, 0xB2, 0x8A, 0xF2, 0xA9, 0xDA, 0x38, 0xEC, 0x52);};
template<> struct uuid<Windows::Media::DialProtocol::IDialReceiverApp2> { define_guid(0x530C5805, 0x9130, 0x42AC, 0xA5, 0x4, 0x19, 0x77, 0xDC, 0xB2, 0xEA, 0x8A);};
template<> struct uuid<Windows::Media::DialProtocol::IDialReceiverApp> { define_guid(0xFD3E7C57, 0x5045, 0x470E, 0xB3, 0x4, 0x4D, 0xD9, 0xB1, 0x3E, 0x7D, 0x11);};

// types

namespace Windows { namespace Media { namespace DialProtocol {

// IDialAppStateDetails
struct IDialAppStateDetails_raw : IInspectable {
	virtual STDMETHODIMP _get_State(DialAppState *value);
	virtual STDMETHODIMP _get_FullXml(HSTRING *value);
};
template<typename X> struct IDialAppStateDetails_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IDialAppStateDetails_adaptor::FullXml)->_get_FullXml(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} FullXml;
		struct : property {
			DialAppState get() { DialAppState value; hrcheck(enc(&IDialAppStateDetails_adaptor::State)->_get_State(&value)); return value; }
			DialAppState operator()() { return get(); }
			operator DialAppState () { return get(); }
		} State;
	};
	IDialAppStateDetails_adaptor() {}
};
template<typename X> struct adapt<IDialAppStateDetails, X> : Windows::Media::DialProtocol::IDialAppStateDetails_adaptor<X> { typedef adapt IDialAppStateDetails; };
struct IDialAppStateDetails : IDialAppStateDetails_raw, generate<IDialAppStateDetails> {};

// DialAppStateDetails
template<typename X> struct statics<DialAppStateDetails, X> : X {
	typedef typename X::root_type DialAppStateDetails;
};
struct DialAppStateDetails : generate<DialAppStateDetails> {};

// IDialApp
struct IDialApp_raw : IInspectable {
	virtual STDMETHODIMP _get_AppName(HSTRING *value);
	virtual STDMETHODIMP _RequestLaunchAsync(HSTRING appArgument, Foundation::IAsyncOperation<DialAppLaunchResult>* *value);
	virtual STDMETHODIMP _StopAsync(Foundation::IAsyncOperation<DialAppStopResult>* *value);
	virtual STDMETHODIMP _GetAppStateAsync(Foundation::IAsyncOperation<DialAppStateDetails*>* *value);
};
template<typename X> struct IDialApp_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IDialApp_adaptor::AppName)->_get_AppName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} AppName;
	};
	ptr<Foundation::IAsyncOperation<DialAppLaunchResult>> RequestLaunchAsync(hstring_ref appArgument) { Foundation::IAsyncOperation<DialAppLaunchResult>* value; hrcheck(X::get()->_RequestLaunchAsync(appArgument, &value)); return from_abi(value); }
	ptr<Foundation::IAsyncOperation<DialAppStopResult>> StopAsync() { Foundation::IAsyncOperation<DialAppStopResult>* value; hrcheck(X::get()->_StopAsync(&value)); return from_abi(value); }
	ptr<Foundation::IAsyncOperation<ptr<DialAppStateDetails>>> GetAppStateAsync() { Foundation::IAsyncOperation<DialAppStateDetails*>* value; hrcheck(X::get()->_GetAppStateAsync(&value)); return from_abi(value); }
	IDialApp_adaptor() {}
};
template<typename X> struct adapt<IDialApp, X> : Windows::Media::DialProtocol::IDialApp_adaptor<X> { typedef adapt IDialApp; };
struct IDialApp : IDialApp_raw, generate<IDialApp> {};

// DialApp
template<typename X> struct statics<DialApp, X> : X {
	typedef typename X::root_type DialApp;
};
struct DialApp : generate<DialApp> {};

// IDialDevice
struct IDialDevice_raw : IInspectable {
	virtual STDMETHODIMP _get_Id(HSTRING *value);
	virtual STDMETHODIMP _GetDialApp(HSTRING appName, DialApp* *value);
};
template<typename X> struct IDialDevice_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IDialDevice_adaptor::Id)->_get_Id(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Id;
	};
	ptr<DialApp> GetDialApp(hstring_ref appName) { DialApp* value; hrcheck(X::get()->_GetDialApp(appName, &value)); return from_abi(value); }
	IDialDevice_adaptor() {}
};
template<typename X> struct adapt<IDialDevice, X> : Windows::Media::DialProtocol::IDialDevice_adaptor<X> { typedef adapt IDialDevice; };
struct IDialDevice : IDialDevice_raw, generate<IDialDevice> {};

// IDialDevice2
struct IDialDevice2_raw : IInspectable {
	virtual STDMETHODIMP _get_FriendlyName(HSTRING *value);
	virtual STDMETHODIMP _get_Thumbnail(Storage::Streams::IRandomAccessStreamReference* *value);
};
template<typename X> struct IDialDevice2_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IDialDevice2_adaptor::FriendlyName)->_get_FriendlyName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} FriendlyName;
		struct : property {
			ptr<Storage::Streams::IRandomAccessStreamReference> get() { Storage::Streams::IRandomAccessStreamReference* value; hrcheck(enc(&IDialDevice2_adaptor::Thumbnail)->_get_Thumbnail(&value)); return from_abi(value); }
			ptr<Storage::Streams::IRandomAccessStreamReference> operator()() { return get(); }
			operator ptr<Storage::Streams::IRandomAccessStreamReference> () { return get(); }
			ptr<Storage::Streams::IRandomAccessStreamReference> operator->() { return get(); }
		} Thumbnail;
	};
	IDialDevice2_adaptor() {}
};
template<typename X> struct adapt<IDialDevice2, X> : Windows::Media::DialProtocol::IDialDevice2_adaptor<X> { typedef adapt IDialDevice2; };
struct IDialDevice2 : IDialDevice2_raw, generate<IDialDevice2> {};

// IDialDeviceStatics
struct IDialDeviceStatics : IInspectable {
	virtual STDMETHODIMP _GetDeviceSelector(HSTRING appName, HSTRING *selector);
	virtual STDMETHODIMP _FromIdAsync(HSTRING value, Foundation::IAsyncOperation<DialDevice*>* *operation);
	virtual STDMETHODIMP _DeviceInfoSupportsDialAsync(Windows::Devices::Enumeration::DeviceInformation* device, Foundation::IAsyncOperation<bool>* *operation);
};

// DialDevice
template<typename> struct DialDevice_statics {
	static hstring GetDeviceSelector(hstring_ref appName) { HSTRING selector; hrcheck(get_activation_factory<DialDevice, IDialDeviceStatics>()->_GetDeviceSelector(appName, &selector)); return from_abi(selector); }
	static ptr<Foundation::IAsyncOperation<ptr<DialDevice>>> FromIdAsync(hstring_ref value) { Foundation::IAsyncOperation<DialDevice*>* operation; hrcheck(get_activation_factory<DialDevice, IDialDeviceStatics>()->_FromIdAsync(value, &operation)); return from_abi(operation); }
	static ptr<Foundation::IAsyncOperation<bool>> DeviceInfoSupportsDialAsync(pptr<Windows::Devices::Enumeration::DeviceInformation> device) { Foundation::IAsyncOperation<bool>* operation; hrcheck(get_activation_factory<DialDevice, IDialDeviceStatics>()->_DeviceInfoSupportsDialAsync(device, &operation)); return from_abi(operation); }
};

template<typename X> struct statics<DialDevice, X> : X, Windows::Media::DialProtocol::DialDevice_statics<void> {
	typedef typename X::root_type DialDevice;
};
struct DialDevice : generate<DialDevice> {};

// IDialDeviceSelectedEventArgs
struct IDialDeviceSelectedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_SelectedDialDevice(DialDevice* *value);
};
template<typename X> struct IDialDeviceSelectedEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<DialDevice> get() { DialDevice* value; hrcheck(enc(&IDialDeviceSelectedEventArgs_adaptor::SelectedDialDevice)->_get_SelectedDialDevice(&value)); return from_abi(value); }
			ptr<DialDevice> operator()() { return get(); }
			operator ptr<DialDevice> () { return get(); }
			ptr<DialDevice> operator->() { return get(); }
		} SelectedDialDevice;
	};
	IDialDeviceSelectedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IDialDeviceSelectedEventArgs, X> : Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs_adaptor<X> { typedef adapt IDialDeviceSelectedEventArgs; };
struct IDialDeviceSelectedEventArgs : IDialDeviceSelectedEventArgs_raw, generate<IDialDeviceSelectedEventArgs> {};

// DialDeviceSelectedEventArgs
template<typename X> struct statics<DialDeviceSelectedEventArgs, X> : X {
	typedef typename X::root_type DialDeviceSelectedEventArgs;
};
struct DialDeviceSelectedEventArgs : generate<DialDeviceSelectedEventArgs> {};

// IDialDisconnectButtonClickedEventArgs
struct IDialDisconnectButtonClickedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Device(DialDevice* *value);
};
template<typename X> struct IDialDisconnectButtonClickedEventArgs_adaptor : X {
	union {
		struct : property {
			ptr<DialDevice> get() { DialDevice* value; hrcheck(enc(&IDialDisconnectButtonClickedEventArgs_adaptor::Device)->_get_Device(&value)); return from_abi(value); }
			ptr<DialDevice> operator()() { return get(); }
			operator ptr<DialDevice> () { return get(); }
			ptr<DialDevice> operator->() { return get(); }
		} Device;
	};
	IDialDisconnectButtonClickedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IDialDisconnectButtonClickedEventArgs, X> : Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs_adaptor<X> { typedef adapt IDialDisconnectButtonClickedEventArgs; };
struct IDialDisconnectButtonClickedEventArgs : IDialDisconnectButtonClickedEventArgs_raw, generate<IDialDisconnectButtonClickedEventArgs> {};

// DialDisconnectButtonClickedEventArgs
template<typename X> struct statics<DialDisconnectButtonClickedEventArgs, X> : X {
	typedef typename X::root_type DialDisconnectButtonClickedEventArgs;
};
struct DialDisconnectButtonClickedEventArgs : generate<DialDisconnectButtonClickedEventArgs> {};

// IDialDevicePickerFilter
struct IDialDevicePickerFilter_raw : IInspectable {
	virtual STDMETHODIMP _get_SupportedAppNames(Foundation::Collections::IVector<HSTRING>* *value);
};
template<typename X> struct IDialDevicePickerFilter_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVector<hstring>> get() { Foundation::Collections::IVector<HSTRING>* value; hrcheck(enc(&IDialDevicePickerFilter_adaptor::SupportedAppNames)->_get_SupportedAppNames(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVector<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVector<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVector<hstring>> operator->() { return get(); }
		} SupportedAppNames;
	};
	IDialDevicePickerFilter_adaptor() {}
};
template<typename X> struct adapt<IDialDevicePickerFilter, X> : Windows::Media::DialProtocol::IDialDevicePickerFilter_adaptor<X> { typedef adapt IDialDevicePickerFilter; };
struct IDialDevicePickerFilter : IDialDevicePickerFilter_raw, generate<IDialDevicePickerFilter> {};

// DialDevicePickerFilter
template<typename X> struct statics<DialDevicePickerFilter, X> : X {
	typedef typename X::root_type DialDevicePickerFilter;
};
struct DialDevicePickerFilter : generate<DialDevicePickerFilter> {};

// IDialDevicePicker
struct IDialDevicePicker_raw : IInspectable {
	virtual STDMETHODIMP _get_Filter(DialDevicePickerFilter* *value);
	virtual STDMETHODIMP _get_Appearance(Windows::Devices::Enumeration::DevicePickerAppearance* *value);
	virtual STDMETHODIMP _add_DialDeviceSelected(Foundation::TypedEventHandler<DialDevicePicker*, DialDeviceSelectedEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_DialDeviceSelected(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_DisconnectButtonClicked(Foundation::TypedEventHandler<DialDevicePicker*, DialDisconnectButtonClickedEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_DisconnectButtonClicked(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _add_DialDevicePickerDismissed(Foundation::TypedEventHandler<DialDevicePicker*, IInspectable*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_DialDevicePickerDismissed(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _Show(Foundation::Rect selection);
	virtual STDMETHODIMP _ShowWithPlacement(Foundation::Rect selection, UI::Popups::Placement preferredPlacement);
	virtual STDMETHODIMP _PickSingleDialDeviceAsync(Foundation::Rect selection, Foundation::IAsyncOperation<DialDevice*>* *operation);
	virtual STDMETHODIMP _PickSingleDialDeviceAsyncWithPlacement(Foundation::Rect selection, UI::Popups::Placement preferredPlacement, Foundation::IAsyncOperation<DialDevice*>* *operation);
	virtual STDMETHODIMP _Hide();
	virtual STDMETHODIMP _SetDisplayStatus(DialDevice* device, DialDeviceDisplayStatus status);
};
template<typename X> struct IDialDevicePicker_adaptor : X {
	union {
		struct : property {
			ptr<Windows::Devices::Enumeration::DevicePickerAppearance> get() { Windows::Devices::Enumeration::DevicePickerAppearance* value; hrcheck(enc(&IDialDevicePicker_adaptor::Appearance)->_get_Appearance(&value)); return from_abi(value); }
			ptr<Windows::Devices::Enumeration::DevicePickerAppearance> operator()() { return get(); }
			operator ptr<Windows::Devices::Enumeration::DevicePickerAppearance> () { return get(); }
			ptr<Windows::Devices::Enumeration::DevicePickerAppearance> operator->() { return get(); }
		} Appearance;
		struct : property {
			ptr<DialDevicePickerFilter> get() { DialDevicePickerFilter* value; hrcheck(enc(&IDialDevicePicker_adaptor::Filter)->_get_Filter(&value)); return from_abi(value); }
			ptr<DialDevicePickerFilter> operator()() { return get(); }
			operator ptr<DialDevicePickerFilter> () { return get(); }
			ptr<DialDevicePickerFilter> operator->() { return get(); }
		} Filter;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<DialDevicePicker>, object>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IDialDevicePicker_adaptor::DialDevicePickerDismissed)->_add_DialDevicePickerDismissed(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IDialDevicePicker_adaptor::DialDevicePickerDismissed)->_remove_DialDevicePickerDismissed(token)); }
		} DialDevicePickerDismissed;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<DialDevicePicker>, ptr<DialDeviceSelectedEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IDialDevicePicker_adaptor::DialDeviceSelected)->_add_DialDeviceSelected(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IDialDevicePicker_adaptor::DialDeviceSelected)->_remove_DialDeviceSelected(token)); }
		} DialDeviceSelected;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<DialDevicePicker>, ptr<DialDisconnectButtonClickedEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IDialDevicePicker_adaptor::DisconnectButtonClicked)->_add_DisconnectButtonClicked(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IDialDevicePicker_adaptor::DisconnectButtonClicked)->_remove_DisconnectButtonClicked(token)); }
		} DisconnectButtonClicked;
	};
	void Show(const Foundation::Rect& selection) { hrcheck(X::get()->_Show(selection)); }
	void Show(const Foundation::Rect& selection, UI::Popups::Placement preferredPlacement) { hrcheck(X::get()->_ShowWithPlacement(selection, preferredPlacement)); }
	ptr<Foundation::IAsyncOperation<ptr<DialDevice>>> PickSingleDialDeviceAsync(const Foundation::Rect& selection) { Foundation::IAsyncOperation<DialDevice*>* operation; hrcheck(X::get()->_PickSingleDialDeviceAsync(selection, &operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperation<ptr<DialDevice>>> PickSingleDialDeviceAsync(const Foundation::Rect& selection, UI::Popups::Placement preferredPlacement) { Foundation::IAsyncOperation<DialDevice*>* operation; hrcheck(X::get()->_PickSingleDialDeviceAsyncWithPlacement(selection, preferredPlacement, &operation)); return from_abi(operation); }
	void Hide() { hrcheck(X::get()->_Hide()); }
	void SetDisplayStatus(pptr<DialDevice> device, DialDeviceDisplayStatus status) { hrcheck(X::get()->_SetDisplayStatus(device, status)); }
	IDialDevicePicker_adaptor() {}
};
template<typename X> struct adapt<IDialDevicePicker, X> : Windows::Media::DialProtocol::IDialDevicePicker_adaptor<X> { typedef adapt IDialDevicePicker; };
struct IDialDevicePicker : IDialDevicePicker_raw, generate<IDialDevicePicker> {};

// DialDevicePicker
template<typename X> struct statics<DialDevicePicker, X> : X {
	typedef typename X::root_type DialDevicePicker;
};
struct DialDevicePicker : generate<DialDevicePicker> {
	using IDialDevicePicker::Show;
	using IDialDevicePicker::PickSingleDialDeviceAsync;
};

// IDialReceiverAppStatics
struct IDialReceiverAppStatics : IInspectable {
	virtual STDMETHODIMP _get_Current(DialReceiverApp* *value);
};

// IDialReceiverApp2
struct IDialReceiverApp2_raw : IInspectable {
	virtual STDMETHODIMP _GetUniqueDeviceNameAsync(Foundation::IAsyncOperation<HSTRING>* *operation);
};
template<typename X> struct IDialReceiverApp2_adaptor : X {
	ptr<Foundation::IAsyncOperation<hstring>> GetUniqueDeviceNameAsync() { Foundation::IAsyncOperation<HSTRING>* operation; hrcheck(X::get()->_GetUniqueDeviceNameAsync(&operation)); return from_abi(operation); }
};
template<typename X> struct adapt<IDialReceiverApp2, X> : Windows::Media::DialProtocol::IDialReceiverApp2_adaptor<X> { typedef adapt IDialReceiverApp2; };
struct IDialReceiverApp2 : IDialReceiverApp2_raw, generate<IDialReceiverApp2> {};

// IDialReceiverApp
struct IDialReceiverApp_raw : IInspectable {
	virtual STDMETHODIMP _GetAdditionalDataAsync(Foundation::IAsyncOperation<Foundation::Collections::IMap<HSTRING, HSTRING>*>* *operation);
	virtual STDMETHODIMP _SetAdditionalDataAsync(Foundation::Collections::IIterable<Foundation::Collections::IKeyValuePair<HSTRING, HSTRING>*>* additionalData, Foundation::IAsyncAction* *operation);
};
template<typename X> struct IDialReceiverApp_adaptor : X {
	ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IMap<hstring, hstring>>>> GetAdditionalDataAsync() { Foundation::IAsyncOperation<Foundation::Collections::IMap<HSTRING, HSTRING>*>* operation; hrcheck(X::get()->_GetAdditionalDataAsync(&operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncAction> SetAdditionalDataAsync(pptr<Foundation::Collections::IIterable<ptr<Foundation::Collections::IKeyValuePair<hstring, hstring>>>> additionalData) { Foundation::IAsyncAction* operation; hrcheck(X::get()->_SetAdditionalDataAsync(to_abi(additionalData), &operation)); return from_abi(operation); }
};
template<typename X> struct adapt<IDialReceiverApp, X> : Windows::Media::DialProtocol::IDialReceiverApp_adaptor<X> { typedef adapt IDialReceiverApp; };
struct IDialReceiverApp : IDialReceiverApp_raw, generate<IDialReceiverApp> {};

// DialReceiverApp
template<typename> struct DialReceiverApp_statics {
	static struct _Current : property {
		ptr<DialReceiverApp> get() { DialReceiverApp* value; hrcheck(get_activation_factory<DialReceiverApp, IDialReceiverAppStatics>()->_get_Current(&value)); return from_abi(value); }
		ptr<DialReceiverApp> operator()() { return get(); }
		operator ptr<DialReceiverApp> () { return get(); }
		ptr<DialReceiverApp> operator->() { return get(); }
	} Current;
};
template<typename X> typename DialReceiverApp_statics<X>::_Current DialReceiverApp_statics<X>::Current;

template<typename X> struct statics<DialReceiverApp, X> : X, Windows::Media::DialProtocol::DialReceiverApp_statics<void> {
	typedef typename X::root_type DialReceiverApp;
};
struct DialReceiverApp : generate<DialReceiverApp> {};
}}}
} // namespace iso_winrt
