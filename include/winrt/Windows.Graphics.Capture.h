#pragma once
// generated by isopod tools
// namespaces:
// Windows.Graphics.Capture

#include "Windows.Graphics.Capture.0.h"
#include "Windows.Graphics.DirectX.0.h"
#include "Windows.Graphics.0.h"
#include "Windows.Foundation.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Graphics { namespace DirectX { namespace Direct3D11 {
struct IDirect3DDevice;
struct IDirect3DSurface;
}}}
namespace System {
struct DispatcherQueue;
}}

// defs

template<> struct def<Windows::Graphics::Capture::IDirect3D11CaptureFrame> : interface_type<> {};
template<> struct def<Windows::Graphics::Capture::IGraphicsCaptureItem> : interface_type<> {};
template<> struct def<Windows::Graphics::Capture::GraphicsCaptureItem> : class_type<Platform::Object, Windows::Graphics::Capture::IGraphicsCaptureItem> {};
template<> struct def<Windows::Graphics::Capture::IGraphicsCapturePicker> : interface_type<> {};
template<> struct def<Windows::Graphics::Capture::IGraphicsCaptureSession> : interface_type<> {};
template<> struct def<Windows::Graphics::Capture::IGraphicsCaptureSessionStatics> : interface_type<> {};
template<> struct def<Windows::Graphics::Capture::IDirect3D11CaptureFramePool> : interface_type<> {};
template<> struct def<Windows::Graphics::Capture::Direct3D11CaptureFrame> : class_type<Platform::Object, Windows::Graphics::Capture::IDirect3D11CaptureFrame, Windows::Foundation::IClosable> {};
template<> struct def<Windows::Graphics::Capture::IDirect3D11CaptureFramePoolStatics> : interface_type<> {};
template<> struct def<Windows::Graphics::Capture::Direct3D11CaptureFramePool> : class_type<Platform::Object, Windows::Graphics::Capture::IDirect3D11CaptureFramePool, Windows::Foundation::IClosable> {};
template<> struct def<Windows::Graphics::Capture::GraphicsCaptureSession> : class_type<Platform::Object, Windows::Graphics::Capture::IGraphicsCaptureSession, Windows::Foundation::IClosable> {};
template<> struct def<Windows::Graphics::Capture::GraphicsCapturePicker> : class_type<Platform::Object, Windows::Graphics::Capture::IGraphicsCapturePicker> {};

// uuids

template<> struct uuid<Windows::Graphics::Capture::IDirect3D11CaptureFrame> { define_guid(0xFA50C623, 0x38DA, 0x4B32, 0xAC, 0xF3, 0xFA, 0x97, 0x34, 0xAD, 0x80, 0xE);};
template<> struct uuid<Windows::Graphics::Capture::IGraphicsCaptureItem> { define_guid(0x79C3F95B, 0x31F7, 0x4EC2, 0xA4, 0x64, 0x63, 0x2E, 0xF5, 0xD3, 0x7, 0x60);};
template<> struct uuid<Windows::Graphics::Capture::IGraphicsCapturePicker> { define_guid(0x5A1711B3, 0xAD79, 0x4B4A, 0x93, 0x36, 0x13, 0x18, 0xFD, 0xDE, 0x35, 0x39);};
template<> struct uuid<Windows::Graphics::Capture::IGraphicsCaptureSession> { define_guid(0x814E42A9, 0xF70F, 0x4AD7, 0x93, 0x9B, 0xFD, 0xDC, 0xC6, 0xEB, 0x88, 0xD);};
template<> struct uuid<Windows::Graphics::Capture::IGraphicsCaptureSessionStatics> { define_guid(0x2224A540, 0x5974, 0x49AA, 0xB2, 0x32, 0x8, 0x82, 0x53, 0x6F, 0x4C, 0xB5);};
template<> struct uuid<Windows::Graphics::Capture::IDirect3D11CaptureFramePool> { define_guid(0x24EB6D22, 0x1975, 0x422E, 0x82, 0xE7, 0x78, 0xD, 0xBD, 0x8D, 0xDF, 0x24);};
template<> struct uuid<Windows::Graphics::Capture::IDirect3D11CaptureFramePoolStatics> { define_guid(0x7784056A, 0x67AA, 0x4D53, 0xAE, 0x54, 0x10, 0x88, 0xD5, 0xA8, 0xCA, 0x21);};

// types

namespace Windows { namespace Graphics { namespace Capture {

// IDirect3D11CaptureFrame
struct IDirect3D11CaptureFrame_raw : IInspectable {
	virtual STDMETHODIMP _get_Surface(DirectX::Direct3D11::IDirect3DSurface* *value);
	virtual STDMETHODIMP _get_SystemRelativeTime(Foundation::TimeSpan *value);
	virtual STDMETHODIMP _get_ContentSize(SizeInt32 *value);
};
template<typename X> struct IDirect3D11CaptureFrame_adaptor : X {
	union {
		struct : property {
			SizeInt32 get() { SizeInt32 value; hrcheck(enc(&IDirect3D11CaptureFrame_adaptor::ContentSize)->_get_ContentSize(&value)); return value; }
			SizeInt32 operator()() { return get(); }
			operator SizeInt32 () { return get(); }
		} ContentSize;
		struct : property {
			ptr<DirectX::Direct3D11::IDirect3DSurface> get() { DirectX::Direct3D11::IDirect3DSurface* value; hrcheck(enc(&IDirect3D11CaptureFrame_adaptor::Surface)->_get_Surface(&value)); return from_abi(value); }
			ptr<DirectX::Direct3D11::IDirect3DSurface> operator()() { return get(); }
			operator ptr<DirectX::Direct3D11::IDirect3DSurface> () { return get(); }
			ptr<DirectX::Direct3D11::IDirect3DSurface> operator->() { return get(); }
		} Surface;
		struct : property {
			Foundation::TimeSpan get() { Foundation::TimeSpan value; hrcheck(enc(&IDirect3D11CaptureFrame_adaptor::SystemRelativeTime)->_get_SystemRelativeTime(&value)); return value; }
			Foundation::TimeSpan operator()() { return get(); }
			operator Foundation::TimeSpan () { return get(); }
		} SystemRelativeTime;
	};
	IDirect3D11CaptureFrame_adaptor() {}
};
template<typename X> struct adapt<IDirect3D11CaptureFrame, X> : Windows::Graphics::Capture::IDirect3D11CaptureFrame_adaptor<X> { typedef adapt IDirect3D11CaptureFrame; };
struct IDirect3D11CaptureFrame : IDirect3D11CaptureFrame_raw, generate<IDirect3D11CaptureFrame> {};

// IGraphicsCaptureItem
struct IGraphicsCaptureItem_raw : IInspectable {
	virtual STDMETHODIMP _get_DisplayName(HSTRING *value);
	virtual STDMETHODIMP _get_Size(SizeInt32 *value);
	virtual STDMETHODIMP _add_Closed(Foundation::TypedEventHandler<GraphicsCaptureItem*, IInspectable*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_Closed(Foundation::EventRegistrationToken token);
};
template<typename X> struct IGraphicsCaptureItem_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IGraphicsCaptureItem_adaptor::DisplayName)->_get_DisplayName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DisplayName;
		struct : property {
			SizeInt32 get() { SizeInt32 value; hrcheck(enc(&IGraphicsCaptureItem_adaptor::Size)->_get_Size(&value)); return value; }
			SizeInt32 operator()() { return get(); }
			operator SizeInt32 () { return get(); }
		} Size;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<GraphicsCaptureItem>, object>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IGraphicsCaptureItem_adaptor::Closed)->_add_Closed(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IGraphicsCaptureItem_adaptor::Closed)->_remove_Closed(token)); }
		} Closed;
	};
	IGraphicsCaptureItem_adaptor() {}
};
template<typename X> struct adapt<IGraphicsCaptureItem, X> : Windows::Graphics::Capture::IGraphicsCaptureItem_adaptor<X> { typedef adapt IGraphicsCaptureItem; };
struct IGraphicsCaptureItem : IGraphicsCaptureItem_raw, generate<IGraphicsCaptureItem> {};

// GraphicsCaptureItem
template<typename X> struct statics<GraphicsCaptureItem, X> : X {
	typedef typename X::root_type GraphicsCaptureItem;
};
struct GraphicsCaptureItem : generate<GraphicsCaptureItem> {};

// IGraphicsCapturePicker
struct IGraphicsCapturePicker_raw : IInspectable {
	virtual STDMETHODIMP _PickSingleItemAsync(Foundation::IAsyncOperation<GraphicsCaptureItem*>* *result);
};
template<typename X> struct IGraphicsCapturePicker_adaptor : X {
	ptr<Foundation::IAsyncOperation<ptr<GraphicsCaptureItem>>> PickSingleItemAsync() { Foundation::IAsyncOperation<GraphicsCaptureItem*>* result; hrcheck(X::get()->_PickSingleItemAsync(&result)); return from_abi(result); }
};
template<typename X> struct adapt<IGraphicsCapturePicker, X> : Windows::Graphics::Capture::IGraphicsCapturePicker_adaptor<X> { typedef adapt IGraphicsCapturePicker; };
struct IGraphicsCapturePicker : IGraphicsCapturePicker_raw, generate<IGraphicsCapturePicker> {};

// IGraphicsCaptureSession
struct IGraphicsCaptureSession_raw : IInspectable {
	virtual STDMETHODIMP _StartCapture();
};
template<typename X> struct IGraphicsCaptureSession_adaptor : X {
	void StartCapture() { hrcheck(X::get()->_StartCapture()); }
};
template<typename X> struct adapt<IGraphicsCaptureSession, X> : Windows::Graphics::Capture::IGraphicsCaptureSession_adaptor<X> { typedef adapt IGraphicsCaptureSession; };
struct IGraphicsCaptureSession : IGraphicsCaptureSession_raw, generate<IGraphicsCaptureSession> {};

// IGraphicsCaptureSessionStatics
struct IGraphicsCaptureSessionStatics : IInspectable {
	virtual STDMETHODIMP _IsSupported(bool *value);
};

// IDirect3D11CaptureFramePool
struct IDirect3D11CaptureFramePool_raw : IInspectable {
	virtual STDMETHODIMP _Recreate(DirectX::Direct3D11::IDirect3DDevice* device, DirectX::DirectXPixelFormat pixelFormat, int numberOfBuffers, SizeInt32 size);
	virtual STDMETHODIMP _TryGetNextFrame(Direct3D11CaptureFrame* *value);
	virtual STDMETHODIMP _add_FrameArrived(Foundation::TypedEventHandler<Direct3D11CaptureFramePool*, IInspectable*>* handler, Foundation::EventRegistrationToken *token);
	virtual STDMETHODIMP _remove_FrameArrived(Foundation::EventRegistrationToken token);
	virtual STDMETHODIMP _CreateCaptureSession(GraphicsCaptureItem* item, GraphicsCaptureSession* *value);
	virtual STDMETHODIMP _get_DispatcherQueue(System::DispatcherQueue* *value);
};
template<typename X> struct IDirect3D11CaptureFramePool_adaptor : X {
	union {
		struct : property {
			ptr<System::DispatcherQueue> get() { System::DispatcherQueue* value; hrcheck(enc(&IDirect3D11CaptureFramePool_adaptor::DispatcherQueue)->_get_DispatcherQueue(&value)); return from_abi(value); }
			ptr<System::DispatcherQueue> operator()() { return get(); }
			operator ptr<System::DispatcherQueue> () { return get(); }
			ptr<System::DispatcherQueue> operator->() { return get(); }
		} DispatcherQueue;
		struct : property {
			Foundation::EventRegistrationToken operator+=(handler_ref<Foundation::TypedEventHandler<ptr<Direct3D11CaptureFramePool>, object>> handler) { Foundation::EventRegistrationToken token; hrcheck(enc(&IDirect3D11CaptureFramePool_adaptor::FrameArrived)->_add_FrameArrived(to_abi(handler), &token)); return token; }
			void operator-=(const Foundation::EventRegistrationToken& token) { hrcheck(enc(&IDirect3D11CaptureFramePool_adaptor::FrameArrived)->_remove_FrameArrived(token)); }
		} FrameArrived;
	};
	void Recreate(pptr<DirectX::Direct3D11::IDirect3DDevice> device, DirectX::DirectXPixelFormat pixelFormat, int numberOfBuffers, const SizeInt32& size) { hrcheck(X::get()->_Recreate(device, pixelFormat, numberOfBuffers, size)); }
	ptr<Direct3D11CaptureFrame> TryGetNextFrame() { Direct3D11CaptureFrame* value; hrcheck(X::get()->_TryGetNextFrame(&value)); return from_abi(value); }
	ptr<GraphicsCaptureSession> CreateCaptureSession(pptr<GraphicsCaptureItem> item) { GraphicsCaptureSession* value; hrcheck(X::get()->_CreateCaptureSession(item, &value)); return from_abi(value); }
	IDirect3D11CaptureFramePool_adaptor() {}
};
template<typename X> struct adapt<IDirect3D11CaptureFramePool, X> : Windows::Graphics::Capture::IDirect3D11CaptureFramePool_adaptor<X> { typedef adapt IDirect3D11CaptureFramePool; };
struct IDirect3D11CaptureFramePool : IDirect3D11CaptureFramePool_raw, generate<IDirect3D11CaptureFramePool> {};

// Direct3D11CaptureFrame
template<typename X> struct statics<Direct3D11CaptureFrame, X> : X {
	typedef typename X::root_type Direct3D11CaptureFrame;
};
struct Direct3D11CaptureFrame : generate<Direct3D11CaptureFrame> {};

// IDirect3D11CaptureFramePoolStatics
struct IDirect3D11CaptureFramePoolStatics : IInspectable {
	virtual STDMETHODIMP _Create(DirectX::Direct3D11::IDirect3DDevice* device, DirectX::DirectXPixelFormat pixelFormat, int numberOfBuffers, SizeInt32 size, Direct3D11CaptureFramePool* *result);
};

// Direct3D11CaptureFramePool
template<typename> struct Direct3D11CaptureFramePool_statics {
	static ptr<Direct3D11CaptureFramePool> Create(pptr<DirectX::Direct3D11::IDirect3DDevice> device, DirectX::DirectXPixelFormat pixelFormat, int numberOfBuffers, const SizeInt32& size) { Direct3D11CaptureFramePool* result; hrcheck(get_activation_factory<Direct3D11CaptureFramePool, IDirect3D11CaptureFramePoolStatics>()->_Create(device, pixelFormat, numberOfBuffers, size, &result)); return from_abi(result); }
};

template<typename X> struct statics<Direct3D11CaptureFramePool, X> : X, Windows::Graphics::Capture::Direct3D11CaptureFramePool_statics<void> {
	typedef typename X::root_type Direct3D11CaptureFramePool;
};
struct Direct3D11CaptureFramePool : generate<Direct3D11CaptureFramePool> {};

// GraphicsCaptureSession
template<typename> struct GraphicsCaptureSession_statics {
	static bool IsSupported() { bool value; hrcheck(get_activation_factory<GraphicsCaptureSession, IGraphicsCaptureSessionStatics>()->_IsSupported(&value)); return value; }
};

template<typename X> struct statics<GraphicsCaptureSession, X> : X, Windows::Graphics::Capture::GraphicsCaptureSession_statics<void> {
	typedef typename X::root_type GraphicsCaptureSession;
};
struct GraphicsCaptureSession : generate<GraphicsCaptureSession> {};

// GraphicsCapturePicker
template<typename X> struct statics<GraphicsCapturePicker, X> : X {
	typedef typename X::root_type GraphicsCapturePicker;
};
struct GraphicsCapturePicker : generate<GraphicsCapturePicker> {};
}}}
} // namespace iso_winrt