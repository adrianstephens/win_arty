#pragma once
// generated by isopod tools
// namespaces:
// Windows.UI.Popups

#include "Windows.UI.Popups.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVector;
}}}

// defs

template<> struct def<Windows::UI::Popups::MessageDialogOptions> : enum_type<unsigned> {};
template<> struct def<Windows::UI::Popups::IMessageDialog> : interface_type<> {};
template<> struct def<Windows::UI::Popups::IMessageDialogFactory> : interface_type<> {};
template<> struct def<Windows::UI::Popups::MessageDialog> : class_type<Platform::Object, Windows::UI::Popups::IMessageDialog>, custom_activators {};
template<> struct def<Windows::UI::Popups::Placement> : enum_type<int> {};
template<> struct def<Windows::UI::Popups::UICommandInvokedHandler> : delegate_type {};
template<> struct def<Windows::UI::Popups::IUICommand> : overridable_type<> {};
template<> struct def<Windows::UI::Popups::IUICommandFactory> : interface_type<> {};
template<> struct def<Windows::UI::Popups::UICommand> : class_type<Platform::Object, Windows::UI::Popups::IUICommand>, custom_activators {};
template<> struct def<Windows::UI::Popups::UICommandSeparator> : class_type<Platform::Object, Windows::UI::Popups::IUICommand> {};
template<> struct def<Windows::UI::Popups::IPopupMenu> : interface_type<> {};
template<> struct def<Windows::UI::Popups::PopupMenu> : class_type<Platform::Object, Windows::UI::Popups::IPopupMenu> {};

// uuids

template<> struct uuid<Windows::UI::Popups::IMessageDialog> { define_guid(0x33F59B01, 0x5325, 0x43AB, 0x9A, 0xB3, 0xBD, 0xAE, 0x44, 0xE, 0x41, 0x21);};
template<> struct uuid<Windows::UI::Popups::IMessageDialogFactory> { define_guid(0x2D161777, 0xA66F, 0x4EA5, 0xBB, 0x87, 0x79, 0x3F, 0xFA, 0x49, 0x41, 0xF2);};
template<> struct uuid<Windows::UI::Popups::UICommandInvokedHandler> { define_guid(0xDAF77A4F, 0xC27A, 0x4298, 0x9A, 0xC6, 0x29, 0x22, 0xC4, 0x5E, 0x7D, 0xA6);};
template<> struct uuid<Windows::UI::Popups::IUICommand> { define_guid(0x4FF93A75, 0x4145, 0x47FF, 0xAC, 0x7F, 0xDF, 0xF1, 0xC1, 0xFA, 0x5B, 0xF);};
template<> struct uuid<Windows::UI::Popups::IUICommandFactory> { define_guid(0xA21A8189, 0x26B0, 0x4676, 0xAE, 0x94, 0x54, 0x4, 0x1B, 0xC1, 0x25, 0xE8);};
template<> struct uuid<Windows::UI::Popups::IPopupMenu> { define_guid(0x4E9BC6DC, 0x880D, 0x47FC, 0xA0, 0xA1, 0x72, 0xB6, 0x39, 0xE6, 0x25, 0x59);};

// types

namespace Windows { namespace UI { namespace Popups {

// IMessageDialog
struct IMessageDialog_raw : IInspectable {
	virtual STDMETHODIMP _get_Title(HSTRING *value);
	virtual STDMETHODIMP _put_Title(HSTRING value);
	virtual STDMETHODIMP _get_Commands(Foundation::Collections::IVector<IUICommand*>* *value);
	virtual STDMETHODIMP _get_DefaultCommandIndex(unsigned *value);
	virtual STDMETHODIMP _put_DefaultCommandIndex(unsigned value);
	virtual STDMETHODIMP _get_CancelCommandIndex(unsigned *value);
	virtual STDMETHODIMP _put_CancelCommandIndex(unsigned value);
	virtual STDMETHODIMP _get_Content(HSTRING *value);
	virtual STDMETHODIMP _put_Content(HSTRING value);
	virtual STDMETHODIMP _ShowAsync(Foundation::IAsyncOperation<IUICommand*>* *messageDialogAsyncOperation);
	virtual STDMETHODIMP _get_Options(MessageDialogOptions *value);
	virtual STDMETHODIMP _put_Options(MessageDialogOptions value);
};
template<typename X> struct IMessageDialog_adaptor : X {
	union {
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IMessageDialog_adaptor::CancelCommandIndex)->_get_CancelCommandIndex(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
			void put(unsigned value) { hrcheck(enc(&IMessageDialog_adaptor::CancelCommandIndex)->_put_CancelCommandIndex(value)); }
			void operator=(unsigned value) { put(value); }
			void operator()(unsigned value) { put(value); }
		} CancelCommandIndex;
		struct : property {
			ptr<Foundation::Collections::IVector<ptr<IUICommand>>> get() { Foundation::Collections::IVector<IUICommand*>* value; hrcheck(enc(&IMessageDialog_adaptor::Commands)->_get_Commands(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVector<ptr<IUICommand>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVector<ptr<IUICommand>>> () { return get(); }
			ptr<Foundation::Collections::IVector<ptr<IUICommand>>> operator->() { return get(); }
		} Commands;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IMessageDialog_adaptor::Content)->_get_Content(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IMessageDialog_adaptor::Content)->_put_Content(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} Content;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IMessageDialog_adaptor::DefaultCommandIndex)->_get_DefaultCommandIndex(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
			void put(unsigned value) { hrcheck(enc(&IMessageDialog_adaptor::DefaultCommandIndex)->_put_DefaultCommandIndex(value)); }
			void operator=(unsigned value) { put(value); }
			void operator()(unsigned value) { put(value); }
		} DefaultCommandIndex;
		struct : property {
			MessageDialogOptions get() { MessageDialogOptions value; hrcheck(enc(&IMessageDialog_adaptor::Options)->_get_Options(&value)); return value; }
			MessageDialogOptions operator()() { return get(); }
			operator MessageDialogOptions () { return get(); }
			void put(MessageDialogOptions value) { hrcheck(enc(&IMessageDialog_adaptor::Options)->_put_Options(value)); }
			void operator=(MessageDialogOptions value) { put(value); }
			void operator()(MessageDialogOptions value) { put(value); }
		} Options;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IMessageDialog_adaptor::Title)->_get_Title(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IMessageDialog_adaptor::Title)->_put_Title(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} Title;
	};
	ptr<Foundation::IAsyncOperation<ptr<IUICommand>>> ShowAsync() { Foundation::IAsyncOperation<IUICommand*>* messageDialogAsyncOperation; hrcheck(X::get()->_ShowAsync(&messageDialogAsyncOperation)); return from_abi(messageDialogAsyncOperation); }
	IMessageDialog_adaptor() {}
};
template<typename X> struct adapt<IMessageDialog, X> : Windows::UI::Popups::IMessageDialog_adaptor<X> { typedef adapt IMessageDialog; };
struct IMessageDialog : IMessageDialog_raw, generate<IMessageDialog> {};

// IMessageDialogFactory
struct IMessageDialogFactory : IInspectable {
	virtual STDMETHODIMP _Create(HSTRING content, MessageDialog* *messageDialog);
	virtual STDMETHODIMP _CreateWithTitle(HSTRING content, HSTRING title, MessageDialog* *messageDialog);
};

// MessageDialog
template<typename> struct MessageDialog_statics {
	static MessageDialog *activate(hstring_ref content) { MessageDialog *messageDialog; hrcheck(get_activation_factory<MessageDialog, IMessageDialogFactory>()->_Create(content, &messageDialog)); return messageDialog; }
	static MessageDialog *activate(hstring_ref content, hstring_ref title) { MessageDialog *messageDialog; hrcheck(get_activation_factory<MessageDialog, IMessageDialogFactory>()->_CreateWithTitle(content, title, &messageDialog)); return messageDialog; }
};

template<typename X> struct statics<MessageDialog, X> : X, Windows::UI::Popups::MessageDialog_statics<void> {
	using Windows::UI::Popups::MessageDialog_statics<void>::activate;
	typedef typename X::root_type MessageDialog;
};
struct MessageDialog : generate<MessageDialog> {};

// UICommandInvokedHandler
struct UICommandInvokedHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(IUICommand* command) = 0;
};

// IUICommand
struct IUICommand_raw : IInspectable {
	virtual STDMETHODIMP _get_Label(HSTRING *value) = 0;
	virtual STDMETHODIMP _put_Label(HSTRING value) = 0;
	virtual STDMETHODIMP _get_Invoked(UICommandInvokedHandler* *value) = 0;
	virtual STDMETHODIMP _put_Invoked(UICommandInvokedHandler* value) = 0;
	virtual STDMETHODIMP _get_Id(IInspectable* *value) = 0;
	virtual STDMETHODIMP _put_Id(IInspectable* value) = 0;
};
template<typename X> struct IUICommand_adaptor : X {
	union {
		struct : property {
			object get() { IInspectable* value; hrcheck(enc(&IUICommand_adaptor::Id)->_get_Id(&value)); return from_abi(value); }
			object operator()() { return get(); }
			operator object () { return get(); }
			void put(object_ref value) { hrcheck(enc(&IUICommand_adaptor::Id)->_put_Id(value)); }
			void operator=(object_ref value) { put(move(value)); }
			void operator()(object_ref value) { put(move(value)); }
		} Id;
		struct : property {
			ptr<UICommandInvokedHandler> get() { UICommandInvokedHandler* value; hrcheck(enc(&IUICommand_adaptor::Invoked)->_get_Invoked(&value)); return value; }
			ptr<UICommandInvokedHandler> operator()() { return get(); }
			operator ptr<UICommandInvokedHandler> () { return get(); }
			void put(handler_ref<UICommandInvokedHandler> value) { hrcheck(enc(&IUICommand_adaptor::Invoked)->_put_Invoked(value)); }
			void operator=(handler_ref<UICommandInvokedHandler> value) { put(move(value)); }
			void operator()(handler_ref<UICommandInvokedHandler> value) { put(move(value)); }
		} Invoked;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IUICommand_adaptor::Label)->_get_Label(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IUICommand_adaptor::Label)->_put_Label(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} Label;
	};
	IUICommand_adaptor() {}
};
template<typename X> struct adapt<IUICommand, X> : Windows::UI::Popups::IUICommand_adaptor<X> { typedef adapt IUICommand; };
template<typename X> struct IUICommand_unadaptor : X {
	STDMETHODIMP _get_Label(HSTRING *value) { return hrtry([&, this] { get_prop(value, Label); }); }
	STDMETHODIMP _put_Label(HSTRING value) { return hrtry([&, this] { put_prop(value, Label); }); }
	STDMETHODIMP _get_Invoked(UICommandInvokedHandler* *value) { return hrtry([&, this] { get_prop(value, Invoked); }); }
	STDMETHODIMP _put_Invoked(UICommandInvokedHandler* value) { return hrtry([&, this] { put_prop(value, Invoked); }); }
	STDMETHODIMP _get_Id(IInspectable* *value) { return hrtry([&, this] { get_prop(value, Id); }); }
	STDMETHODIMP _put_Id(IInspectable* value) { return hrtry([&, this] { put_prop(value, Id); }); }
};
template<typename X> struct unadapt<IUICommand, X> : Windows::UI::Popups::IUICommand_unadaptor<X> {};
struct IUICommand : IUICommand_raw, generate<IUICommand> {};

// IUICommandFactory
struct IUICommandFactory : IInspectable {
	virtual STDMETHODIMP _Create(HSTRING label, UICommand* *instance);
	virtual STDMETHODIMP _CreateWithHandler(HSTRING label, UICommandInvokedHandler* action, UICommand* *instance);
	virtual STDMETHODIMP _CreateWithHandlerAndId(HSTRING label, UICommandInvokedHandler* action, IInspectable* commandId, UICommand* *instance);
};

// UICommand
template<typename> struct UICommand_statics {
	static UICommand *activate() { UICommand *t; get_activation_factory<UICommand>()->ActivateInstance((IInspectable**)&t); return t; }
	static UICommand *activate(hstring_ref label) { UICommand *instance; hrcheck(get_activation_factory<UICommand, IUICommandFactory>()->_Create(label, &instance)); return instance; }
	static UICommand *activate(hstring_ref label, handler_ref<UICommandInvokedHandler> action) { UICommand *instance; hrcheck(get_activation_factory<UICommand, IUICommandFactory>()->_CreateWithHandler(label, action, &instance)); return instance; }
	static UICommand *activate(hstring_ref label, handler_ref<UICommandInvokedHandler> action, object_ref commandId) { UICommand *instance; hrcheck(get_activation_factory<UICommand, IUICommandFactory>()->_CreateWithHandlerAndId(label, action, commandId, &instance)); return instance; }
};

template<typename X> struct statics<UICommand, X> : X, Windows::UI::Popups::UICommand_statics<void> {
	using Windows::UI::Popups::UICommand_statics<void>::activate;
	typedef typename X::root_type UICommand;
};
struct UICommand : generate<UICommand> {};

// UICommandSeparator
template<typename X> struct statics<UICommandSeparator, X> : X {
	typedef typename X::root_type UICommandSeparator;
};
struct UICommandSeparator : generate<UICommandSeparator> {};

// IPopupMenu
struct IPopupMenu_raw : IInspectable {
	virtual STDMETHODIMP _get_Commands(Foundation::Collections::IVector<IUICommand*>* *value);
	virtual STDMETHODIMP _ShowAsync(Foundation::Point invocationPoint, Foundation::IAsyncOperation<IUICommand*>* *asyncOperation);
	virtual STDMETHODIMP _ShowAsyncWithRect(Foundation::Rect selection, Foundation::IAsyncOperation<IUICommand*>* *asyncOperation);
	virtual STDMETHODIMP _ShowAsyncWithRectAndPlacement(Foundation::Rect selection, Placement preferredPlacement, Foundation::IAsyncOperation<IUICommand*>* *asyncOperation);
};
template<typename X> struct IPopupMenu_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVector<ptr<IUICommand>>> get() { Foundation::Collections::IVector<IUICommand*>* value; hrcheck(enc(&IPopupMenu_adaptor::Commands)->_get_Commands(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVector<ptr<IUICommand>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVector<ptr<IUICommand>>> () { return get(); }
			ptr<Foundation::Collections::IVector<ptr<IUICommand>>> operator->() { return get(); }
		} Commands;
	};
	ptr<Foundation::IAsyncOperation<ptr<IUICommand>>> ShowAsync(const Foundation::Point& invocationPoint) { Foundation::IAsyncOperation<IUICommand*>* asyncOperation; hrcheck(X::get()->_ShowAsync(invocationPoint, &asyncOperation)); return from_abi(asyncOperation); }
	ptr<Foundation::IAsyncOperation<ptr<IUICommand>>> ShowForSelectionAsync(const Foundation::Rect& selection) { Foundation::IAsyncOperation<IUICommand*>* asyncOperation; hrcheck(X::get()->_ShowAsyncWithRect(selection, &asyncOperation)); return from_abi(asyncOperation); }
	ptr<Foundation::IAsyncOperation<ptr<IUICommand>>> ShowForSelectionAsync(const Foundation::Rect& selection, Placement preferredPlacement) { Foundation::IAsyncOperation<IUICommand*>* asyncOperation; hrcheck(X::get()->_ShowAsyncWithRectAndPlacement(selection, preferredPlacement, &asyncOperation)); return from_abi(asyncOperation); }
	IPopupMenu_adaptor() {}
};
template<typename X> struct adapt<IPopupMenu, X> : Windows::UI::Popups::IPopupMenu_adaptor<X> { typedef adapt IPopupMenu; };
struct IPopupMenu : IPopupMenu_raw, generate<IPopupMenu> {};

// PopupMenu
template<typename X> struct statics<PopupMenu, X> : X {
	typedef typename X::root_type PopupMenu;
};
struct PopupMenu : generate<PopupMenu> {
	using IPopupMenu::ShowForSelectionAsync;
};
}}}
} // namespace iso_winrt