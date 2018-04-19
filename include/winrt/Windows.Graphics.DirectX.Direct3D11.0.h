#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Graphics { namespace DirectX { namespace Direct3D11 {
struct Direct3DMultisampleDescription {
	int Count;
	int Quality;
};
struct Direct3DSurfaceDescription {
	int Width;
	int Height;
	DirectXPixelFormat Format;
	Direct3DMultisampleDescription MultisampleDescription;
};
enum class Direct3DUsage : int {
	Default = 0,
	Immutable = 1,
	Dynamic = 2,
	Staging = 3,
};
enum class Direct3DBindings : unsigned {
	VertexBuffer = 0x1,
	IndexBuffer = 0x2,
	ConstantBuffer = 0x4,
	ShaderResource = 0x8,
	StreamOutput = 0x10,
	RenderTarget = 0x20,
	DepthStencil = 0x40,
	UnorderedAccess = 0x80,
	Decoder = 0x200,
	VideoEncoder = 0x400,
};
struct IDirect3DDevice;
struct IDirect3DSurface;
}}}}
} // namespace iso_winrt
