#pragma once
// generated by isopod tools
// namespaces:
// Windows.UI.Xaml.Navigation

#include "Windows.UI.Xaml.Navigation.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.UI.Xaml.Interop.0.h"
#include "Windows.UI.Xaml.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace UI { namespace Xaml { namespace Media { namespace Animation {
struct NavigationTransitionInfo;
}}}}}

// defs

template<> struct def<Windows::UI::Xaml::Navigation::NavigationCacheMode> : enum_type<int> {};
template<> struct def<Windows::UI::Xaml::Navigation::NavigationMode> : enum_type<int> {};
template<> struct def<Windows::UI::Xaml::Navigation::LoadCompletedEventHandler> : delegate_type {};
template<> struct def<Windows::UI::Xaml::Navigation::INavigationEventArgs2> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Navigation::INavigationEventArgs> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Navigation::NavigationEventArgs> : class_type<Platform::Object, Windows::UI::Xaml::Navigation::INavigationEventArgs, Windows::UI::Xaml::Navigation::INavigationEventArgs2> {};
template<> struct def<Windows::UI::Xaml::Navigation::NavigatedEventHandler> : delegate_type {};
template<> struct def<Windows::UI::Xaml::Navigation::NavigatingCancelEventHandler> : delegate_type {};
template<> struct def<Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs2> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs> : class_type<Platform::Object, Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs, Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs2> {};
template<> struct def<Windows::UI::Xaml::Navigation::NavigationFailedEventHandler> : delegate_type {};
template<> struct def<Windows::UI::Xaml::Navigation::INavigationFailedEventArgs> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Navigation::NavigationFailedEventArgs> : class_type<Platform::Object, Windows::UI::Xaml::Navigation::INavigationFailedEventArgs> {};
template<> struct def<Windows::UI::Xaml::Navigation::NavigationStoppedEventHandler> : delegate_type {};
template<> struct def<Windows::UI::Xaml::Navigation::IPageStackEntry> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Navigation::IPageStackEntryStatics> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Navigation::IPageStackEntryFactory> : interface_type<> {};
template<> struct def<Windows::UI::Xaml::Navigation::PageStackEntry> : class_type<Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Navigation::IPageStackEntry>, custom_activators {};

// uuids

template<> struct uuid<Windows::UI::Xaml::Navigation::LoadCompletedEventHandler> { define_guid(0xAEBAF785, 0x43FC, 0x4E2C, 0x95, 0xC3, 0x97, 0xAE, 0x84, 0xEA, 0xBC, 0x8E);};
template<> struct uuid<Windows::UI::Xaml::Navigation::INavigationEventArgs2> { define_guid(0xDBFF71D9, 0x979A, 0x4B2E, 0xA4, 0x9B, 0x3B, 0xB1, 0x7F, 0xDE, 0xF5, 0x74);};
template<> struct uuid<Windows::UI::Xaml::Navigation::INavigationEventArgs> { define_guid(0xB6AA9834, 0x6691, 0x44D1, 0xBD, 0xF7, 0x58, 0x82, 0xC, 0x27, 0xB0, 0xD0);};
template<> struct uuid<Windows::UI::Xaml::Navigation::NavigatedEventHandler> { define_guid(0x7BD1CF54, 0x23CF, 0x4CCE, 0xB2, 0xF5, 0x4C, 0xE7, 0x8D, 0x96, 0x89, 0x6E);};
template<> struct uuid<Windows::UI::Xaml::Navigation::NavigatingCancelEventHandler> { define_guid(0x75D6A78F, 0xA302, 0x4489, 0x98, 0x98, 0x24, 0xEA, 0x49, 0x18, 0x29, 0x10);};
template<> struct uuid<Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs2> { define_guid(0x5407B704, 0x8147, 0x4343, 0x83, 0x8F, 0xDD, 0x1E, 0xE9, 0x8, 0xC1, 0x37);};
template<> struct uuid<Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs> { define_guid(0xFD1D67AE, 0xEAFB, 0x4079, 0xBE, 0x80, 0x6D, 0xC9, 0x2A, 0x3, 0xAE, 0xDF);};
template<> struct uuid<Windows::UI::Xaml::Navigation::NavigationFailedEventHandler> { define_guid(0x4DAB4671, 0x12B2, 0x43C7, 0xB8, 0x92, 0x9B, 0xE2, 0xDC, 0xD3, 0xE8, 0x8D);};
template<> struct uuid<Windows::UI::Xaml::Navigation::INavigationFailedEventArgs> { define_guid(0x11C1DFF7, 0x36C2, 0x4102, 0xB2, 0xEF, 0x2, 0x17, 0xA9, 0x72, 0x89, 0xB3);};
template<> struct uuid<Windows::UI::Xaml::Navigation::NavigationStoppedEventHandler> { define_guid(0xF0117DDB, 0x12FA, 0x4D8D, 0x8B, 0x26, 0xB3, 0x83, 0xD0, 0x9C, 0x2B, 0x3C);};
template<> struct uuid<Windows::UI::Xaml::Navigation::IPageStackEntry> { define_guid(0xEF8814A6, 0x9388, 0x4ACA, 0x85, 0x72, 0x40, 0x51, 0x94, 0x6, 0x90, 0x80);};
template<> struct uuid<Windows::UI::Xaml::Navigation::IPageStackEntryStatics> { define_guid(0xACEFF8E3, 0x246C, 0x4033, 0x9F, 0x1, 0x1, 0xCB, 0xD, 0xA5, 0x25, 0x4E);};
template<> struct uuid<Windows::UI::Xaml::Navigation::IPageStackEntryFactory> { define_guid(0x4454048A, 0xA8B9, 0x4F78, 0x9B, 0x84, 0x1F, 0x51, 0xF5, 0x88, 0x51, 0xFF);};

// types

namespace Windows { namespace UI { namespace Xaml { namespace Navigation {

// LoadCompletedEventHandler
struct LoadCompletedEventHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(IInspectable* sender, NavigationEventArgs* e) = 0;
};

// INavigationEventArgs2
struct INavigationEventArgs2_raw : IInspectable {
	virtual STDMETHODIMP _get_NavigationTransitionInfo(Media::Animation::NavigationTransitionInfo* *value);
};
template<typename X> struct INavigationEventArgs2_adaptor : X {
	union {
		struct : property {
			ptr<Media::Animation::NavigationTransitionInfo> get() { Media::Animation::NavigationTransitionInfo* value; hrcheck(enc(&INavigationEventArgs2_adaptor::NavigationTransitionInfo)->_get_NavigationTransitionInfo(&value)); return from_abi(value); }
			ptr<Media::Animation::NavigationTransitionInfo> operator()() { return get(); }
			operator ptr<Media::Animation::NavigationTransitionInfo> () { return get(); }
			ptr<Media::Animation::NavigationTransitionInfo> operator->() { return get(); }
		} NavigationTransitionInfo;
	};
	INavigationEventArgs2_adaptor() {}
};
template<typename X> struct adapt<INavigationEventArgs2, X> : Windows::UI::Xaml::Navigation::INavigationEventArgs2_adaptor<X> { typedef adapt INavigationEventArgs2; };
struct INavigationEventArgs2 : INavigationEventArgs2_raw, generate<INavigationEventArgs2> {};

// INavigationEventArgs
struct INavigationEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Content(IInspectable* *value);
	virtual STDMETHODIMP _get_Parameter(IInspectable* *value);
	virtual STDMETHODIMP _get_SourcePageType(Interop::TypeName *value);
	virtual STDMETHODIMP _get_NavigationMode(Navigation::NavigationMode *value);
	virtual STDMETHODIMP _get_Uri(Foundation::Uri* *value);
	virtual STDMETHODIMP _put_Uri(Foundation::Uri* value);
};
template<typename X> struct INavigationEventArgs_adaptor : X {
	union {
		struct : property {
			object get() { IInspectable* value; hrcheck(enc(&INavigationEventArgs_adaptor::Content)->_get_Content(&value)); return from_abi(value); }
			object operator()() { return get(); }
			operator object () { return get(); }
		} Content;
		struct : property {
			Navigation::NavigationMode get() { Navigation::NavigationMode value; hrcheck(enc(&INavigationEventArgs_adaptor::NavigationMode)->_get_NavigationMode(&value)); return value; }
			Navigation::NavigationMode operator()() { return get(); }
			operator Navigation::NavigationMode () { return get(); }
		} NavigationMode;
		struct : property {
			object get() { IInspectable* value; hrcheck(enc(&INavigationEventArgs_adaptor::Parameter)->_get_Parameter(&value)); return from_abi(value); }
			object operator()() { return get(); }
			operator object () { return get(); }
		} Parameter;
		struct : property {
			Interop::TypeName get() { Interop::TypeName value; hrcheck(enc(&INavigationEventArgs_adaptor::SourcePageType)->_get_SourcePageType(&value)); return value; }
			Interop::TypeName operator()() { return get(); }
			operator Interop::TypeName () { return get(); }
		} SourcePageType;
		struct : property {
			ptr<Foundation::Uri> get() { Foundation::Uri* value; hrcheck(enc(&INavigationEventArgs_adaptor::Uri)->_get_Uri(&value)); return from_abi(value); }
			ptr<Foundation::Uri> operator()() { return get(); }
			operator ptr<Foundation::Uri> () { return get(); }
			ptr<Foundation::Uri> operator->() { return get(); }
			void put(pptr<Foundation::Uri> value) { hrcheck(enc(&INavigationEventArgs_adaptor::Uri)->_put_Uri(value)); }
			void operator=(pptr<Foundation::Uri> value) { put(value); }
			void operator()(pptr<Foundation::Uri> value) { put(value); }
		} Uri;
	};
	INavigationEventArgs_adaptor() {}
};
template<typename X> struct adapt<INavigationEventArgs, X> : Windows::UI::Xaml::Navigation::INavigationEventArgs_adaptor<X> { typedef adapt INavigationEventArgs; };
struct INavigationEventArgs : INavigationEventArgs_raw, generate<INavigationEventArgs> {};

// NavigationEventArgs
template<typename X> struct statics<NavigationEventArgs, X> : X {
	typedef typename X::root_type NavigationEventArgs;
};
struct NavigationEventArgs : generate<NavigationEventArgs> {};

// NavigatedEventHandler
struct NavigatedEventHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(IInspectable* sender, NavigationEventArgs* e) = 0;
};

// NavigatingCancelEventHandler
struct NavigatingCancelEventHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(IInspectable* sender, NavigatingCancelEventArgs* e) = 0;
};

// INavigatingCancelEventArgs2
struct INavigatingCancelEventArgs2_raw : IInspectable {
	virtual STDMETHODIMP _get_Parameter(IInspectable* *value);
	virtual STDMETHODIMP _get_NavigationTransitionInfo(Media::Animation::NavigationTransitionInfo* *value);
};
template<typename X> struct INavigatingCancelEventArgs2_adaptor : X {
	union {
		struct : property {
			ptr<Media::Animation::NavigationTransitionInfo> get() { Media::Animation::NavigationTransitionInfo* value; hrcheck(enc(&INavigatingCancelEventArgs2_adaptor::NavigationTransitionInfo)->_get_NavigationTransitionInfo(&value)); return from_abi(value); }
			ptr<Media::Animation::NavigationTransitionInfo> operator()() { return get(); }
			operator ptr<Media::Animation::NavigationTransitionInfo> () { return get(); }
			ptr<Media::Animation::NavigationTransitionInfo> operator->() { return get(); }
		} NavigationTransitionInfo;
		struct : property {
			object get() { IInspectable* value; hrcheck(enc(&INavigatingCancelEventArgs2_adaptor::Parameter)->_get_Parameter(&value)); return from_abi(value); }
			object operator()() { return get(); }
			operator object () { return get(); }
		} Parameter;
	};
	INavigatingCancelEventArgs2_adaptor() {}
};
template<typename X> struct adapt<INavigatingCancelEventArgs2, X> : Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs2_adaptor<X> { typedef adapt INavigatingCancelEventArgs2; };
struct INavigatingCancelEventArgs2 : INavigatingCancelEventArgs2_raw, generate<INavigatingCancelEventArgs2> {};

// INavigatingCancelEventArgs
struct INavigatingCancelEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Cancel(bool *value);
	virtual STDMETHODIMP _put_Cancel(bool value);
	virtual STDMETHODIMP _get_NavigationMode(Navigation::NavigationMode *value);
	virtual STDMETHODIMP _get_SourcePageType(Interop::TypeName *value);
};
template<typename X> struct INavigatingCancelEventArgs_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&INavigatingCancelEventArgs_adaptor::Cancel)->_get_Cancel(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&INavigatingCancelEventArgs_adaptor::Cancel)->_put_Cancel(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} Cancel;
		struct : property {
			Navigation::NavigationMode get() { Navigation::NavigationMode value; hrcheck(enc(&INavigatingCancelEventArgs_adaptor::NavigationMode)->_get_NavigationMode(&value)); return value; }
			Navigation::NavigationMode operator()() { return get(); }
			operator Navigation::NavigationMode () { return get(); }
		} NavigationMode;
		struct : property {
			Interop::TypeName get() { Interop::TypeName value; hrcheck(enc(&INavigatingCancelEventArgs_adaptor::SourcePageType)->_get_SourcePageType(&value)); return value; }
			Interop::TypeName operator()() { return get(); }
			operator Interop::TypeName () { return get(); }
		} SourcePageType;
	};
	INavigatingCancelEventArgs_adaptor() {}
};
template<typename X> struct adapt<INavigatingCancelEventArgs, X> : Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs_adaptor<X> { typedef adapt INavigatingCancelEventArgs; };
struct INavigatingCancelEventArgs : INavigatingCancelEventArgs_raw, generate<INavigatingCancelEventArgs> {};

// NavigatingCancelEventArgs
template<typename X> struct statics<NavigatingCancelEventArgs, X> : X {
	typedef typename X::root_type NavigatingCancelEventArgs;
};
struct NavigatingCancelEventArgs : generate<NavigatingCancelEventArgs> {};

// NavigationFailedEventHandler
struct NavigationFailedEventHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(IInspectable* sender, NavigationFailedEventArgs* e) = 0;
};

// INavigationFailedEventArgs
struct INavigationFailedEventArgs_raw : IInspectable {
	virtual STDMETHODIMP _get_Exception(Foundation::HResult *value);
	virtual STDMETHODIMP _get_Handled(bool *value);
	virtual STDMETHODIMP _put_Handled(bool value);
	virtual STDMETHODIMP _get_SourcePageType(Interop::TypeName *value);
};
template<typename X> struct INavigationFailedEventArgs_adaptor : X {
	union {
		struct : property {
			Foundation::HResult get() { Foundation::HResult value; hrcheck(enc(&INavigationFailedEventArgs_adaptor::Exception)->_get_Exception(&value)); return value; }
			Foundation::HResult operator()() { return get(); }
			operator Foundation::HResult () { return get(); }
		} Exception;
		struct : property {
			bool get() { bool value; hrcheck(enc(&INavigationFailedEventArgs_adaptor::Handled)->_get_Handled(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&INavigationFailedEventArgs_adaptor::Handled)->_put_Handled(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} Handled;
		struct : property {
			Interop::TypeName get() { Interop::TypeName value; hrcheck(enc(&INavigationFailedEventArgs_adaptor::SourcePageType)->_get_SourcePageType(&value)); return value; }
			Interop::TypeName operator()() { return get(); }
			operator Interop::TypeName () { return get(); }
		} SourcePageType;
	};
	INavigationFailedEventArgs_adaptor() {}
};
template<typename X> struct adapt<INavigationFailedEventArgs, X> : Windows::UI::Xaml::Navigation::INavigationFailedEventArgs_adaptor<X> { typedef adapt INavigationFailedEventArgs; };
struct INavigationFailedEventArgs : INavigationFailedEventArgs_raw, generate<INavigationFailedEventArgs> {};

// NavigationFailedEventArgs
template<typename X> struct statics<NavigationFailedEventArgs, X> : X {
	typedef typename X::root_type NavigationFailedEventArgs;
};
struct NavigationFailedEventArgs : generate<NavigationFailedEventArgs> {};

// NavigationStoppedEventHandler
struct NavigationStoppedEventHandler : IUnknown {
	virtual STDMETHODIMP _Invoke(IInspectable* sender, NavigationEventArgs* e) = 0;
};

// IPageStackEntry
struct IPageStackEntry_raw : IInspectable {
	virtual STDMETHODIMP _get_SourcePageType(Interop::TypeName *value);
	virtual STDMETHODIMP _get_Parameter(IInspectable* *value);
	virtual STDMETHODIMP _get_NavigationTransitionInfo(Media::Animation::NavigationTransitionInfo* *value);
};
template<typename X> struct IPageStackEntry_adaptor : X {
	union {
		struct : property {
			ptr<Media::Animation::NavigationTransitionInfo> get() { Media::Animation::NavigationTransitionInfo* value; hrcheck(enc(&IPageStackEntry_adaptor::NavigationTransitionInfo)->_get_NavigationTransitionInfo(&value)); return from_abi(value); }
			ptr<Media::Animation::NavigationTransitionInfo> operator()() { return get(); }
			operator ptr<Media::Animation::NavigationTransitionInfo> () { return get(); }
			ptr<Media::Animation::NavigationTransitionInfo> operator->() { return get(); }
		} NavigationTransitionInfo;
		struct : property {
			object get() { IInspectable* value; hrcheck(enc(&IPageStackEntry_adaptor::Parameter)->_get_Parameter(&value)); return from_abi(value); }
			object operator()() { return get(); }
			operator object () { return get(); }
		} Parameter;
		struct : property {
			Interop::TypeName get() { Interop::TypeName value; hrcheck(enc(&IPageStackEntry_adaptor::SourcePageType)->_get_SourcePageType(&value)); return value; }
			Interop::TypeName operator()() { return get(); }
			operator Interop::TypeName () { return get(); }
		} SourcePageType;
	};
	IPageStackEntry_adaptor() {}
};
template<typename X> struct adapt<IPageStackEntry, X> : Windows::UI::Xaml::Navigation::IPageStackEntry_adaptor<X> { typedef adapt IPageStackEntry; };
struct IPageStackEntry : IPageStackEntry_raw, generate<IPageStackEntry> {};

// IPageStackEntryStatics
struct IPageStackEntryStatics : IInspectable {
	virtual STDMETHODIMP _get_SourcePageTypeProperty(DependencyProperty* *value);
};

// IPageStackEntryFactory
struct IPageStackEntryFactory : IInspectable {
	virtual STDMETHODIMP _CreateInstance(Interop::TypeName sourcePageType, IInspectable* parameter, Media::Animation::NavigationTransitionInfo* navigationTransitionInfo, PageStackEntry* *instance);
};

// PageStackEntry
template<typename> struct PageStackEntry_statics {
	static struct _SourcePageTypeProperty : property {
		ptr<DependencyProperty> get() { DependencyProperty* value; hrcheck(get_activation_factory<PageStackEntry, IPageStackEntryStatics>()->_get_SourcePageTypeProperty(&value)); return from_abi(value); }
		ptr<DependencyProperty> operator()() { return get(); }
		operator ptr<DependencyProperty> () { return get(); }
		ptr<DependencyProperty> operator->() { return get(); }
	} SourcePageTypeProperty;
	static PageStackEntry *activate(const Interop::TypeName& sourcePageType, object_ref parameter, pptr<Media::Animation::NavigationTransitionInfo> navigationTransitionInfo) { PageStackEntry *instance; hrcheck(get_activation_factory<PageStackEntry, IPageStackEntryFactory>()->_CreateInstance(sourcePageType, parameter, navigationTransitionInfo, &instance)); return instance; }
};
template<typename X> typename PageStackEntry_statics<X>::_SourcePageTypeProperty PageStackEntry_statics<X>::SourcePageTypeProperty;

template<typename X> struct statics<PageStackEntry, X> : X, Windows::UI::Xaml::Navigation::PageStackEntry_statics<void> {
	using Windows::UI::Xaml::Navigation::PageStackEntry_statics<void>::activate;
	typedef typename X::root_type PageStackEntry;
};
struct PageStackEntry : generate<PageStackEntry> {};
}}}}
} // namespace iso_winrt
