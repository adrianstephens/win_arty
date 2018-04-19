#pragma once
// generated by isopod tools
// namespaces:
// Windows.Graphics

#include "Windows.Graphics.0.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Graphics::SizeInt32> : value_type<int, int> {};
template<> struct def<Windows::Graphics::RectInt32> : value_type<int, int, int, int> {};
template<> struct def<Windows::Graphics::IGeometrySource2D> : overridable_type<> {};
template<> struct def<Windows::Graphics::DisplayAdapterId> : value_type<unsigned, int> {};
template<> struct def<Windows::Graphics::PointInt32> : value_type<int, int> {};

// uuids

template<> struct uuid<Windows::Graphics::IGeometrySource2D> { define_guid(0xCAFF7902, 0x670C, 0x4181, 0xA6, 0x24, 0xDA, 0x97, 0x72, 0x3, 0xB8, 0x45);};

// types

namespace Windows { namespace Graphics {

// IGeometrySource2D
struct IGeometrySource2D : IInspectable, generate<IGeometrySource2D> {};
}}
} // namespace iso_winrt