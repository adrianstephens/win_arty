#pragma once
// generated by isopod tools
// namespaces:
// Windows.System.Inventory

#include "Windows.System.Inventory.0.h"
#include "Windows.Foundation.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}}

// defs

template<> struct def<Windows::System::Inventory::IInstalledDesktopAppStatics> : interface_type<> {};
template<> struct def<Windows::System::Inventory::IInstalledDesktopApp> : interface_type<> {};
template<> struct def<Windows::System::Inventory::InstalledDesktopApp> : class_type<Platform::Object, Windows::System::Inventory::IInstalledDesktopApp, Windows::Foundation::IStringable> {};

// uuids

template<> struct uuid<Windows::System::Inventory::IInstalledDesktopAppStatics> { define_guid(0x264CF74E, 0x21CD, 0x5F9B, 0x60, 0x56, 0x78, 0x66, 0xAD, 0x72, 0x48, 0x9A);};
template<> struct uuid<Windows::System::Inventory::IInstalledDesktopApp> { define_guid(0x75EAB8ED, 0xC0BC, 0x5364, 0x4C, 0x28, 0x16, 0x6E, 0x5, 0x45, 0x16, 0x7A);};

// types

namespace Windows { namespace System { namespace Inventory {

// IInstalledDesktopAppStatics
struct IInstalledDesktopAppStatics : IInspectable {
	virtual STDMETHODIMP _GetInventoryAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<InstalledDesktopApp*>*>* *operation);
};

// IInstalledDesktopApp
struct IInstalledDesktopApp_raw : IInspectable {
	virtual STDMETHODIMP _get_Id(HSTRING *value);
	virtual STDMETHODIMP _get_DisplayName(HSTRING *value);
	virtual STDMETHODIMP _get_Publisher(HSTRING *value);
	virtual STDMETHODIMP _get_DisplayVersion(HSTRING *value);
};
template<typename X> struct IInstalledDesktopApp_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IInstalledDesktopApp_adaptor::DisplayName)->_get_DisplayName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DisplayName;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IInstalledDesktopApp_adaptor::DisplayVersion)->_get_DisplayVersion(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DisplayVersion;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IInstalledDesktopApp_adaptor::Id)->_get_Id(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Id;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IInstalledDesktopApp_adaptor::Publisher)->_get_Publisher(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Publisher;
	};
	IInstalledDesktopApp_adaptor() {}
};
template<typename X> struct adapt<IInstalledDesktopApp, X> : Windows::System::Inventory::IInstalledDesktopApp_adaptor<X> { typedef adapt IInstalledDesktopApp; };
struct IInstalledDesktopApp : IInstalledDesktopApp_raw, generate<IInstalledDesktopApp> {};

// InstalledDesktopApp
template<typename> struct InstalledDesktopApp_statics {
	static ptr<Foundation::IAsyncOperation<ptr<Foundation::Collections::IVectorView<ptr<InstalledDesktopApp>>>>> GetInventoryAsync() { Foundation::IAsyncOperation<Foundation::Collections::IVectorView<InstalledDesktopApp*>*>* operation; hrcheck(get_activation_factory<InstalledDesktopApp, IInstalledDesktopAppStatics>()->_GetInventoryAsync(&operation)); return from_abi(operation); }
};

template<typename X> struct statics<InstalledDesktopApp, X> : X, Windows::System::Inventory::InstalledDesktopApp_statics<void> {
	typedef typename X::root_type InstalledDesktopApp;
};
struct InstalledDesktopApp : generate<InstalledDesktopApp> {};
}}}
} // namespace iso_winrt
