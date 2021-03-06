#pragma once
// generated by isopod tools
// namespaces:
// Windows.Graphics.DirectX.Direct3D11

#include "Windows.Graphics.DirectX.Direct3D11.0.h"
#include "Windows.Graphics.DirectX.0.h"
#include "Windows.Foundation.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription> : value_type<int, int> {};
template<> struct def<Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription> : value_type<int, int, Windows::Graphics::DirectX::DirectXPixelFormat, Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription> {};
template<> struct def<Windows::Graphics::DirectX::Direct3D11::Direct3DUsage> : enum_type<int> {};
template<> struct def<Windows::Graphics::DirectX::Direct3D11::Direct3DBindings> : enum_type<unsigned> {};
template<> struct def<Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice> : overridable_type<Windows::Foundation::IClosable> {};
template<> struct def<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> : overridable_type<Windows::Foundation::IClosable> {};

// uuids

template<> struct uuid<Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice> { define_guid(0xA37624AB, 0x8D5F, 0x4650, 0x9D, 0x3E, 0x9E, 0xAE, 0x3D, 0x9B, 0xC6, 0x70);};
template<> struct uuid<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> { define_guid(0xBF4A146, 0x13C1, 0x4694, 0xBE, 0xE3, 0x7A, 0xBF, 0x15, 0xEA, 0xF5, 0x86);};

// types

namespace Windows { namespace Graphics { namespace DirectX { namespace Direct3D11 {

// IDirect3DDevice
struct IDirect3DDevice_raw : IInspectable {
	virtual STDMETHODIMP _Trim() = 0;
};
template<typename X> struct IDirect3DDevice_adaptor : X {
	void Trim() { hrcheck(X::get()->_Trim()); }
};
template<typename X> struct adapt<IDirect3DDevice, X> : Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice_adaptor<X> { typedef adapt IDirect3DDevice; };
template<typename X> struct IDirect3DDevice_unadaptor : X {
	STDMETHODIMP _Trim() { return hrtry([&, this] { X::get()->Trim(); }); }
};
template<typename X> struct unadapt<IDirect3DDevice, X> : Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice_unadaptor<X> {};
struct IDirect3DDevice : IDirect3DDevice_raw, generate<IDirect3DDevice> {};

// IDirect3DSurface
struct IDirect3DSurface_raw : IInspectable {
	virtual STDMETHODIMP _get_Description(Direct3DSurfaceDescription *value) = 0;
};
template<typename X> struct IDirect3DSurface_adaptor : X {
	union {
		struct : property {
			Direct3DSurfaceDescription get() { Direct3DSurfaceDescription value; hrcheck(enc(&IDirect3DSurface_adaptor::Description)->_get_Description(&value)); return value; }
			Direct3DSurfaceDescription operator()() { return get(); }
			operator Direct3DSurfaceDescription () { return get(); }
		} Description;
	};
	IDirect3DSurface_adaptor() {}
};
template<typename X> struct adapt<IDirect3DSurface, X> : Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface_adaptor<X> { typedef adapt IDirect3DSurface; };
template<typename X> struct IDirect3DSurface_unadaptor : X {
	STDMETHODIMP _get_Description(Direct3DSurfaceDescription *value) { return hrtry([&, this] { get_prop(value, Description); }); }
};
template<typename X> struct unadapt<IDirect3DSurface, X> : Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface_unadaptor<X> {};
struct IDirect3DSurface : IDirect3DSurface_raw, generate<IDirect3DSurface> {};
}}}}
} // namespace iso_winrt
