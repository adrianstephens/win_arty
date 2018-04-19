#pragma once
// generated by isopod tools
// namespaces:
// Windows.UI.WebUI.Core

#include "Windows.UI.WebUI.Core.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.UI.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IObservableVector;
}}}

// defs

template<> struct def<Windows::UI::WebUI::Core::WebUICommandBarContract> : value_type<> {};
template<> struct def<Windows::UI::WebUI::Core::WebUICommandBarClosedDisplayMode> : enum_type<int> {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs> : interface_type<> {};
template<> struct def<Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs> : class_type<Platform::Object, Windows::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs> {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBarElement> : overridable_type<> {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBarIcon> : overridable_type<> {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBarIconButton> : interface_type<Windows::UI::WebUI::Core::IWebUICommandBarElement> {};
template<> struct def<Windows::UI::WebUI::Core::WebUICommandBarIconButton> : class_type<Platform::Object, Windows::UI::WebUI::Core::IWebUICommandBarIconButton> {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton> : interface_type<Windows::UI::WebUI::Core::IWebUICommandBarElement> {};
template<> struct def<Windows::UI::WebUI::Core::WebUICommandBarConfirmationButton> : class_type<Platform::Object, Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton> {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon> : interface_type<Windows::UI::WebUI::Core::IWebUICommandBarIcon> {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBarBitmapIconFactory> : interface_type<> {};
template<> struct def<Windows::UI::WebUI::Core::WebUICommandBarBitmapIcon> : class_type<Platform::Object, Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon>, custom_activators {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon> : interface_type<Windows::UI::WebUI::Core::IWebUICommandBarIcon> {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBarSymbolIconFactory> : interface_type<> {};
template<> struct def<Windows::UI::WebUI::Core::WebUICommandBarSymbolIcon> : class_type<Platform::Object, Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon>, custom_activators {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs> : interface_type<> {};
template<> struct def<Windows::UI::WebUI::Core::WebUICommandBarSizeChangedEventArgs> : class_type<Platform::Object, Windows::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs> {};
template<> struct def<Windows::UI::WebUI::Core::MenuOpenedEventHandler> : delegate_type {};
template<> struct def<Windows::UI::WebUI::Core::MenuClosedEventHandler> : delegate_type {};
template<> struct def<Windows::UI::WebUI::Core::SizeChangedEventHandler> : delegate_type {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBar> : interface_type<> {};
template<> struct def<Windows::UI::WebUI::Core::IWebUICommandBarStatics> : interface_type<> {};
template<> struct def<Windows::UI::WebUI::Core::WebUICommandBar> : class_type<Platform::Object, Windows::UI::WebUI::Core::IWebUICommandBar> {};

// uuids

template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs> { define_guid(0x304EDBDD, 0xE741, 0x41EF, 0xBD, 0xC4, 0xA4, 0x5C, 0xEA, 0x2A, 0x4F, 0x70);};
template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBarElement> { define_guid(0xC9069EC2, 0x284A, 0x4633, 0x8A, 0xAD, 0x63, 0x7A, 0x27, 0xE2, 0x82, 0xC3);};
template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBarIcon> { define_guid(0xD587655D, 0x2014, 0x42BE, 0x96, 0x9A, 0x7D, 0x14, 0xCA, 0x6C, 0x8A, 0x49);};
template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBarIconButton> { define_guid(0x8F1BC93A, 0x3A7C, 0x4842, 0xA0, 0xCF, 0xAF, 0xF6, 0xEA, 0x30, 0x85, 0x86);};
template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton> { define_guid(0x86E7824A, 0xE3D5, 0x4EB6, 0xB2, 0xFF, 0x8F, 0x1, 0x8A, 0x17, 0x21, 0x5);};
template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon> { define_guid(0x858F4F45, 0x8D8, 0x4A46, 0x81, 0xEC, 0x0, 0x1, 0x5B, 0xB, 0x1C, 0x6C);};
template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBarBitmapIconFactory> { define_guid(0xF3F7D78A, 0x7673, 0x444A, 0xBE, 0x62, 0xAC, 0x12, 0xD3, 0x1C, 0x22, 0x31);};
template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon> { define_guid(0xD4935477, 0xFD26, 0x46ED, 0x86, 0x58, 0x1A, 0x3F, 0x44, 0x0, 0xE7, 0xB3);};
template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBarSymbolIconFactory> { define_guid(0x51BE1A1F, 0x3730, 0x429E, 0xB6, 0x22, 0x14, 0xE2, 0xB7, 0xBF, 0x6A, 0x7);};
template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs> { define_guid(0xFBF1E2F6, 0x3029, 0x4719, 0x83, 0x78, 0x92, 0xF8, 0x2B, 0x87, 0xAF, 0x1E);};
template<> struct uuid<Windows::UI::WebUI::Core::MenuOpenedEventHandler> { define_guid(0x18DC0AD3, 0x678F, 0x4C19, 0x89, 0x63, 0xCC, 0x1C, 0x49, 0xA5, 0xEF, 0x9E);};
template<> struct uuid<Windows::UI::WebUI::Core::MenuClosedEventHandler> { define_guid(0x435387C8, 0x4DD0, 0x4C52, 0x94, 0x89, 0xD3, 0x90, 0xCE, 0x77, 0x21, 0xD2);};
template<> struct uuid<Windows::UI::WebUI::Core::SizeChangedEventHandler> { define_guid(0xD49CFE3C, 0xDD2E, 0x4C28, 0xB6, 0x27, 0x30, 0x3A, 0x7F, 0x91, 0x1A, 0xF5);};
template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBar> { define_guid(0xA4FC0016, 0xDBE5, 0x41AD, 0x8D, 0x7B, 0x14, 0x69, 0x8B, 0xD6, 0x91, 0x1D);};
template<> struct uuid<Windows::UI::WebUI::Core::IWebUICommandBarStatics> { define_guid(0x1449CDB9, 0xA506, 0x45BE, 0x8F, 0x42, 0xB2, 0x83, 0x7E, 0x2F, 0xE0, 0xC9);};

// types

namespace Windows { namespace UI { namespace WebUI { namespace Core {

// IWebUICommandBarItemInvokedEventArgs
struct IWebUICommandBarItemInvokedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_IsPrimaryCommand(bool *value);
};
template<typename X> struct IWebUICommandBarItemInvokedEventArgs_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IWebUICommandBarItemInvokedEventArgs_adaptor::IsPrimaryCommand)->_get_IsPrimaryCommand(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} IsPrimaryCommand;
	};
	IWebUICommandBarItemInvokedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IWebUICommandBarItemInvokedEventArgs, X> : Windows::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs_adaptor<X> { typedef adapt IWebUICommandBarItemInvokedEventArgs; };
struct IWebUICommandBarItemInvokedEventArgs : IWebUICommandBarItemInvokedEventArgs_raw, generate<IWebUICommandBarItemInvokedEventArgs> {};

// WebUICommandBarItemInvokedEventArgs
template<typename X> struct statics<WebUICommandBarItemInvokedEventArgs, X> : X {
	typedef typename X::root_type WebUICommandBarItemInvokedEventArgs;
};
struct WebUICommandBarItemInvokedEventArgs : generate<WebUICommandBarItemInvokedEventArgs> {};

// IWebUICommandBarElement
struct IWebUICommandBarElement : IInspectable, generate<IWebUICommandBarElement> {};

// IWebUICommandBarIcon
struct IWebUICommandBarIcon : IInspectable, generate<IWebUICommandBarIcon> {};

// IWebUICommandBarIconButton
struct IWebUICommandBarIconButton_raw : IInspectable {
	virtual STDMETHODIMP _get_Enabled(bool *value);
	virtual STDMETHODIMP _put_Enabled(bool value);
	virtual STDMETHODIMP _get_Label(HSTRING *value);
	virtual STDMETHODIMP _put_Label(HSTRING value);
	virtual STDMETHODIMP _get_IsToggleButton(bool *value);
	virtual STDMETHODIMP _put_IsToggleButton(bool value);
	virtual STDMETHODIMP _get_IsChecked(bool *value);
	virtual STDMETHODIMP _put_IsChecked(bool value);
	virtual STDMETHODIMP _get_Icon(IWebUICommandBarIcon* *value);
	virtual STDMETHODIMP _put_Icon(IWebUICommandBarIcon* value);
	virtual STDMETHODIMP _add_ItemInvoked(Foundation::TypedEventHandler<WebUICommandBarIconButton*, WebUICommandBarItemInvokedEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_ItemInvoked(Foundation::EventRegistrationToken token);
};
template<typename X> struct IWebUICommandBarIconButton_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IWebUICommandBarIconButton_adaptor::Enabled)->_get_Enabled(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IWebUICommandBarIconButton_adaptor::Enabled)->_put_Enabled(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} Enabled;
		struct : property {
			ptr<IWebUICommandBarIcon> get() { IWebUICommandBarIcon* value; hrcheck(enc(&IWebUICommandBarIconButton_adaptor::Icon)->_get_Icon(&value)); return from_abi(value); }
			ptr<IWebUICommandBarIcon> operator()() { return get(); }
			operator ptr<IWebUICommandBarIcon> () { return get(); }
			ptr<IWebUICommandBarIcon> operator->() { return get(); }
			void put(pptr<IWebUICommandBarIcon> value) { hrcheck(enc(&IWebUICommandBarIconButton_adaptor::Icon)->_put_Icon(value)); }
			void operator=(pptr<IWebUICommandBarIcon> value) { put(value); }
			void operator()(pptr<IWebUICommandBarIcon> value) { put(value); }
		} Icon;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IWebUICommandBarIconButton_adaptor::IsChecked)->_get_IsChecked(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IWebUICommandBarIconButton_adaptor::IsChecked)->_put_IsChecked(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} IsChecked;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IWebUICommandBarIconButton_adaptor::IsToggleButton)->_get_IsToggleButton(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IWebUICommandBarIconButton_adaptor::IsToggleButton)->_put_IsToggleButton(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} IsToggleButton;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebUICommandBarIconButton_adaptor::Label)->_get_Label(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IWebUICommandBarIconButton_adaptor::Label)->_put_Label(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} Label;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<WebUICommandBarIconButton>, ptr<WebUICommandBarItemInvokedEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IWebUICommandBarIconButton_adaptor::ItemInvoked)->_add_ItemInvoked(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IWebUICommandBarIconButton_adaptor::ItemInvoked)->_remove_ItemInvoked(token)); }
		} ItemInvoked;
	};
	IWebUICommandBarIconButton_adaptor() {}
};
template<typename X> struct adapt<IWebUICommandBarIconButton, X> : Windows::UI::WebUI::Core::IWebUICommandBarIconButton_adaptor<X> { typedef adapt IWebUICommandBarIconButton; };
struct IWebUICommandBarIconButton : IWebUICommandBarIconButton_raw, generate<IWebUICommandBarIconButton> {};

// WebUICommandBarIconButton
template<typename X> struct statics<WebUICommandBarIconButton, X> : X {
	typedef typename X::root_type WebUICommandBarIconButton;
};
struct WebUICommandBarIconButton : generate<WebUICommandBarIconButton> {};

// IWebUICommandBarConfirmationButton
struct IWebUICommandBarConfirmationButton_raw : IInspectable {
	virtual STDMETHODIMP _get_Text(HSTRING *value);
	virtual STDMETHODIMP _put_Text(HSTRING value);
	virtual STDMETHODIMP _add_ItemInvoked(Foundation::TypedEventHandler<WebUICommandBarConfirmationButton*, WebUICommandBarItemInvokedEventArgs*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_ItemInvoked(Foundation::EventRegistrationToken token);
};
template<typename X> struct IWebUICommandBarConfirmationButton_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebUICommandBarConfirmationButton_adaptor::Text)->_get_Text(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IWebUICommandBarConfirmationButton_adaptor::Text)->_put_Text(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} Text;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<WebUICommandBarConfirmationButton>, ptr<WebUICommandBarItemInvokedEventArgs>>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IWebUICommandBarConfirmationButton_adaptor::ItemInvoked)->_add_ItemInvoked(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IWebUICommandBarConfirmationButton_adaptor::ItemInvoked)->_remove_ItemInvoked(token)); }
		} ItemInvoked;
	};
	IWebUICommandBarConfirmationButton_adaptor() {}
};
template<typename X> struct adapt<IWebUICommandBarConfirmationButton, X> : Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton_adaptor<X> { typedef adapt IWebUICommandBarConfirmationButton; };
struct IWebUICommandBarConfirmationButton : IWebUICommandBarConfirmationButton_raw, generate<IWebUICommandBarConfirmationButton> {};

// WebUICommandBarConfirmationButton
template<typename X> struct statics<WebUICommandBarConfirmationButton, X> : X {
	typedef typename X::root_type WebUICommandBarConfirmationButton;
};
struct WebUICommandBarConfirmationButton : generate<WebUICommandBarConfirmationButton> {};

// IWebUICommandBarBitmapIcon
struct IWebUICommandBarBitmapIcon_raw : IInspectable {
	virtual STDMETHODIMP _get_Uri(Foundation::Uri* *value);
	virtual STDMETHODIMP _put_Uri(Foundation::Uri* value);
};
template<typename X> struct IWebUICommandBarBitmapIcon_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Uri> get() { Foundation::Uri* value; hrcheck(enc(&IWebUICommandBarBitmapIcon_adaptor::Uri)->_get_Uri(&value)); return from_abi(value); }
			ptr<Foundation::Uri> operator()() { return get(); }
			operator ptr<Foundation::Uri> () { return get(); }
			ptr<Foundation::Uri> operator->() { return get(); }
			void put(pptr<Foundation::Uri> value) { hrcheck(enc(&IWebUICommandBarBitmapIcon_adaptor::Uri)->_put_Uri(value)); }
			void operator=(pptr<Foundation::Uri> value) { put(value); }
			void operator()(pptr<Foundation::Uri> value) { put(value); }
		} Uri;
	};
	IWebUICommandBarBitmapIcon_adaptor() {}
};
template<typename X> struct adapt<IWebUICommandBarBitmapIcon, X> : Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon_adaptor<X> { typedef adapt IWebUICommandBarBitmapIcon; };
struct IWebUICommandBarBitmapIcon : IWebUICommandBarBitmapIcon_raw, generate<IWebUICommandBarBitmapIcon> {};

// IWebUICommandBarBitmapIconFactory
struct IWebUICommandBarBitmapIconFactory : IInspectable {
	virtual STDMETHODIMP _Create(Foundation::Uri* uri, WebUICommandBarBitmapIcon* *instance);
};

// WebUICommandBarBitmapIcon
template<typename> struct WebUICommandBarBitmapIcon_statics {
	static WebUICommandBarBitmapIcon *activate(pptr<Foundation::Uri> uri) { WebUICommandBarBitmapIcon *instance; hrcheck(get_activation_factory<WebUICommandBarBitmapIcon, IWebUICommandBarBitmapIconFactory>()->_Create(uri, &instance)); return instance; }
};

template<typename X> struct statics<WebUICommandBarBitmapIcon, X> : X, Windows::UI::WebUI::Core::WebUICommandBarBitmapIcon_statics<void> {
	using Windows::UI::WebUI::Core::WebUICommandBarBitmapIcon_statics<void>::activate;
	typedef typename X::root_type WebUICommandBarBitmapIcon;
};
struct WebUICommandBarBitmapIcon : generate<WebUICommandBarBitmapIcon> {};

// IWebUICommandBarSymbolIcon
struct IWebUICommandBarSymbolIcon_raw : IInspectable {
	virtual STDMETHODIMP _get_Symbol(HSTRING *value);
	virtual STDMETHODIMP _put_Symbol(HSTRING value);
};
template<typename X> struct IWebUICommandBarSymbolIcon_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IWebUICommandBarSymbolIcon_adaptor::Symbol)->_get_Symbol(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IWebUICommandBarSymbolIcon_adaptor::Symbol)->_put_Symbol(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} Symbol;
	};
	IWebUICommandBarSymbolIcon_adaptor() {}
};
template<typename X> struct adapt<IWebUICommandBarSymbolIcon, X> : Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon_adaptor<X> { typedef adapt IWebUICommandBarSymbolIcon; };
struct IWebUICommandBarSymbolIcon : IWebUICommandBarSymbolIcon_raw, generate<IWebUICommandBarSymbolIcon> {};

// IWebUICommandBarSymbolIconFactory
struct IWebUICommandBarSymbolIconFactory : IInspectable {
	virtual STDMETHODIMP _Create(HSTRING symbol, WebUICommandBarSymbolIcon* *instance);
};

// WebUICommandBarSymbolIcon
template<typename> struct WebUICommandBarSymbolIcon_statics {
	static WebUICommandBarSymbolIcon *activate(hstring_ref symbol) { WebUICommandBarSymbolIcon *instance; hrcheck(get_activation_factory<WebUICommandBarSymbolIcon, IWebUICommandBarSymbolIconFactory>()->_Create(symbol, &instance)); return instance; }
};

template<typename X> struct statics<WebUICommandBarSymbolIcon, X> : X, Windows::UI::WebUI::Core::WebUICommandBarSymbolIcon_statics<void> {
	using Windows::UI::WebUI::Core::WebUICommandBarSymbolIcon_statics<void>::activate;
	typedef typename X::root_type WebUICommandBarSymbolIcon;
};
struct WebUICommandBarSymbolIcon : generate<WebUICommandBarSymbolIcon> {};

// IWebUICommandBarSizeChangedEventArgs
struct IWebUICommandBarSizeChangedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Size(Foundation::Size *value);
};
template<typename X> struct IWebUICommandBarSizeChangedEventArgs_adaptor : X {
	union {
		struct : property {
			Foundation::Size get() { Foundation::Size value; hrcheck(enc(&IWebUICommandBarSizeChangedEventArgs_adaptor::Size)->_get_Size(&value)); return value; }
			Foundation::Size operator()() { return get(); }
			operator Foundation::Size () { return get(); }
		} Size;
	};
	IWebUICommandBarSizeChangedEventArgs_adaptor() {}
};
template<typename X> struct adapt<IWebUICommandBarSizeChangedEventArgs, X> : Windows::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs_adaptor<X> { typedef adapt IWebUICommandBarSizeChangedEventArgs; };
struct IWebUICommandBarSizeChangedEventArgs : IWebUICommandBarSizeChangedEventArgs_raw, generate<IWebUICommandBarSizeChangedEventArgs> {};

// WebUICommandBarSizeChangedEventArgs
template<typename X> struct statics<WebUICommandBarSizeChangedEventArgs, X> : X {
	typedef typename X::root_type WebUICommandBarSizeChangedEventArgs;
};
struct WebUICommandBarSizeChangedEventArgs : generate<WebUICommandBarSizeChangedEventArgs> {};

// MenuOpenedEventHandler
struct MenuOpenedEventHandler : IUnknown {
	virtual STDMETHODIMP _Invoke() = 0;
};

// MenuClosedEventHandler
struct MenuClosedEventHandler : IUnknown {
	virtual STDMETHODIMP _Invoke() = 0;
};

// SizeChangedEventHandler
struct SizeChangedEventHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(WebUICommandBarSizeChangedEventArgs* eventArgs) = 0;
};

// IWebUICommandBar
struct IWebUICommandBar_raw : IInspectable {
	virtual STDMETHODIMP _get_Visible(bool *value);
	virtual STDMETHODIMP _put_Visible(bool value);
	virtual STDMETHODIMP _get_Opacity(double *value);
	virtual STDMETHODIMP _put_Opacity(double value);
	virtual STDMETHODIMP _get_ForegroundColor(Color *value);
	virtual STDMETHODIMP _put_ForegroundColor(Color value);
	virtual STDMETHODIMP _get_BackgroundColor(Color *value);
	virtual STDMETHODIMP _put_BackgroundColor(Color value);
	virtual STDMETHODIMP _get_ClosedDisplayMode(WebUICommandBarClosedDisplayMode *value);
	virtual STDMETHODIMP _put_ClosedDisplayMode(WebUICommandBarClosedDisplayMode value);
	virtual STDMETHODIMP _get_IsOpen(bool *value);
	virtual STDMETHODIMP _put_IsOpen(bool value);
	virtual STDMETHODIMP _get_Size(Foundation::Size *value);
	virtual STDMETHODIMP _get_PrimaryCommands(Foundation::Collections::IObservableVector<IWebUICommandBarElement*>* *value);
	virtual STDMETHODIMP _get_SecondaryCommands(Foundation::Collections::IObservableVector<IWebUICommandBarElement*>* *value);
	virtual STDMETHODIMP _add_MenuOpened(MenuOpenedEventHandler* handler, Foundation::EventRegistrationToken *value);
	virtual STDMETHODIMP _remove_MenuOpened(Foundation::EventRegistrationToken value);
	virtual STDMETHODIMP _add_MenuClosed(MenuClosedEventHandler* handler, Foundation::EventRegistrationToken *value);
	virtual STDMETHODIMP _remove_MenuClosed(Foundation::EventRegistrationToken value);
	virtual STDMETHODIMP _add_SizeChanged(SizeChangedEventHandler* handler, Foundation::EventRegistrationToken *value);
	virtual STDMETHODIMP _remove_SizeChanged(Foundation::EventRegistrationToken value);
};
template<typename X> struct IWebUICommandBar_adaptor : X {
	union {
		struct : property {
			Color get() { Color value; hrcheck(enc(&IWebUICommandBar_adaptor::BackgroundColor)->_get_BackgroundColor(&value)); return value; }
			Color operator()() { return get(); }
			operator Color () { return get(); }
			void put(const Color& value) { hrcheck(enc(&IWebUICommandBar_adaptor::BackgroundColor)->_put_BackgroundColor(value)); }
			void operator=(const Color& value) { put(value); }
			void operator()(const Color& value) { put(value); }
		} BackgroundColor;
		struct : property {
			WebUICommandBarClosedDisplayMode get() { WebUICommandBarClosedDisplayMode value; hrcheck(enc(&IWebUICommandBar_adaptor::ClosedDisplayMode)->_get_ClosedDisplayMode(&value)); return value; }
			WebUICommandBarClosedDisplayMode operator()() { return get(); }
			operator WebUICommandBarClosedDisplayMode () { return get(); }
			void put(WebUICommandBarClosedDisplayMode value) { hrcheck(enc(&IWebUICommandBar_adaptor::ClosedDisplayMode)->_put_ClosedDisplayMode(value)); }
			void operator=(WebUICommandBarClosedDisplayMode value) { put(value); }
			void operator()(WebUICommandBarClosedDisplayMode value) { put(value); }
		} ClosedDisplayMode;
		struct : property {
			Color get() { Color value; hrcheck(enc(&IWebUICommandBar_adaptor::ForegroundColor)->_get_ForegroundColor(&value)); return value; }
			Color operator()() { return get(); }
			operator Color () { return get(); }
			void put(const Color& value) { hrcheck(enc(&IWebUICommandBar_adaptor::ForegroundColor)->_put_ForegroundColor(value)); }
			void operator=(const Color& value) { put(value); }
			void operator()(const Color& value) { put(value); }
		} ForegroundColor;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IWebUICommandBar_adaptor::IsOpen)->_get_IsOpen(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IWebUICommandBar_adaptor::IsOpen)->_put_IsOpen(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} IsOpen;
		struct : property {
			double get() { double value; hrcheck(enc(&IWebUICommandBar_adaptor::Opacity)->_get_Opacity(&value)); return value; }
			double operator()() { return get(); }
			operator double () { return get(); }
			void put(double value) { hrcheck(enc(&IWebUICommandBar_adaptor::Opacity)->_put_Opacity(value)); }
			void operator=(double value) { put(value); }
			void operator()(double value) { put(value); }
		} Opacity;
		struct : property {
			ptr<Foundation::Collections::IObservableVector<ptr<IWebUICommandBarElement>>> get() { Foundation::Collections::IObservableVector<IWebUICommandBarElement*>* value; hrcheck(enc(&IWebUICommandBar_adaptor::PrimaryCommands)->_get_PrimaryCommands(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IObservableVector<ptr<IWebUICommandBarElement>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IObservableVector<ptr<IWebUICommandBarElement>>> () { return get(); }
			ptr<Foundation::Collections::IObservableVector<ptr<IWebUICommandBarElement>>> operator->() { return get(); }
		} PrimaryCommands;
		struct : property {
			ptr<Foundation::Collections::IObservableVector<ptr<IWebUICommandBarElement>>> get() { Foundation::Collections::IObservableVector<IWebUICommandBarElement*>* value; hrcheck(enc(&IWebUICommandBar_adaptor::SecondaryCommands)->_get_SecondaryCommands(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IObservableVector<ptr<IWebUICommandBarElement>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IObservableVector<ptr<IWebUICommandBarElement>>> () { return get(); }
			ptr<Foundation::Collections::IObservableVector<ptr<IWebUICommandBarElement>>> operator->() { return get(); }
		} SecondaryCommands;
		struct : property {
			Foundation::Size get() { Foundation::Size value; hrcheck(enc(&IWebUICommandBar_adaptor::Size)->_get_Size(&value)); return value; }
			Foundation::Size operator()() { return get(); }
			operator Foundation::Size () { return get(); }
		} Size;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IWebUICommandBar_adaptor::Visible)->_get_Visible(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IWebUICommandBar_adaptor::Visible)->_put_Visible(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} Visible;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<MenuClosedEventHandler> handler) { Foundation::EventRegistrationToken value; hrcheck(enc(&IWebUICommandBar_adaptor::MenuClosed)->_add_MenuClosed(handler, &value)); return value; }
			void operator-=(const Foundation::EventRegistrationToken& value) { hrcheck(enc(&IWebUICommandBar_adaptor::MenuClosed)->_remove_MenuClosed(value)); }
		} MenuClosed;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<MenuOpenedEventHandler> handler) { Foundation::EventRegistrationToken value; hrcheck(enc(&IWebUICommandBar_adaptor::MenuOpened)->_add_MenuOpened(handler, &value)); return value; }
			void operator-=(const Foundation::EventRegistrationToken& value) { hrcheck(enc(&IWebUICommandBar_adaptor::MenuOpened)->_remove_MenuOpened(value)); }
		} MenuOpened;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<SizeChangedEventHandler> handler) { Foundation::EventRegistrationToken value; hrcheck(enc(&IWebUICommandBar_adaptor::SizeChanged)->_add_SizeChanged(handler, &value)); return value; }
			void operator-=(const Foundation::EventRegistrationToken& value) { hrcheck(enc(&IWebUICommandBar_adaptor::SizeChanged)->_remove_SizeChanged(value)); }
		} SizeChanged;
	};
	IWebUICommandBar_adaptor() {}
};
template<typename X> struct adapt<IWebUICommandBar, X> : Windows::UI::WebUI::Core::IWebUICommandBar_adaptor<X> { typedef adapt IWebUICommandBar; };
struct IWebUICommandBar : IWebUICommandBar_raw, generate<IWebUICommandBar> {};

// IWebUICommandBarStatics
struct IWebUICommandBarStatics : IInspectable {
	virtual STDMETHODIMP _GetForCurrentView(WebUICommandBar* *commandBar);
};

// WebUICommandBar
template<typename> struct WebUICommandBar_statics {
	static ptr<WebUICommandBar> GetForCurrentView() { WebUICommandBar* commandBar; hrcheck(get_activation_factory<WebUICommandBar, IWebUICommandBarStatics>()->_GetForCurrentView(&commandBar)); return from_abi(commandBar); }
};

template<typename X> struct statics<WebUICommandBar, X> : X, Windows::UI::WebUI::Core::WebUICommandBar_statics<void> {
	typedef typename X::root_type WebUICommandBar;
};
struct WebUICommandBar : generate<WebUICommandBar> {};
}}}}
} // namespace iso_winrt