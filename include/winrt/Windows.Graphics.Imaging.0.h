#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Graphics { namespace Imaging {
enum class BitmapInterpolationMode : int {
	NearestNeighbor = 0,
	Linear = 1,
	Cubic = 2,
	Fant = 3,
};
enum class BitmapFlip : int {
	None = 0,
	Horizontal = 1,
	Vertical = 2,
};
enum class BitmapRotation : int {
	None = 0,
	Clockwise90Degrees = 1,
	Clockwise180Degrees = 2,
	Clockwise270Degrees = 3,
};
struct BitmapSize {
	unsigned Width;
	unsigned Height;
};
enum class ColorManagementMode : int {
	DoNotColorManage = 0,
	ColorManageToSRgb = 1,
};
enum class ExifOrientationMode : int {
	IgnoreExifOrientation = 0,
	RespectExifOrientation = 1,
};
enum class PngFilterMode : int {
	Automatic = 0,
	None = 1,
	Sub = 2,
	Up = 3,
	Average = 4,
	Paeth = 5,
	Adaptive = 6,
};
enum class TiffCompressionMode : int {
	Automatic = 0,
	None = 1,
	Ccitt3 = 2,
	Ccitt4 = 3,
	Lzw = 4,
	Rle = 5,
	Zip = 6,
	LzwhDifferencing = 7,
};
enum class JpegSubsamplingMode : int {
	Default = 0,
	Y4Cb2Cr0 = 1,
	Y4Cb2Cr2 = 2,
	Y4Cb4Cr4 = 3,
};
struct BitmapBounds {
	unsigned X;
	unsigned Y;
	unsigned Width;
	unsigned Height;
};
struct IBitmapTransform;
struct BitmapTransform;
struct IBitmapTypedValue;
struct IBitmapTypedValueFactory;
struct BitmapTypedValue;
struct BitmapPropertySet;
struct IBitmapPropertiesView;
struct IBitmapProperties;
struct BitmapPropertiesView;
struct BitmapProperties;
struct IPixelDataProvider;
struct PixelDataProvider;
struct ImageStream;
enum class BitmapAlphaMode : int {
	Premultiplied = 0,
	Straight = 1,
	Ignore = 2,
};
enum class BitmapPixelFormat : int {
	Unknown = 0,
	Rgba16 = 12,
	Rgba8 = 30,
	Gray16 = 57,
	Gray8 = 62,
	Bgra8 = 87,
	Nv12 = 103,
	P010 = 104,
	Yuy2 = 107,
};
struct IBitmapFrame;
struct IBitmapFrameWithSoftwareBitmap;
struct BitmapFrame;
struct IBitmapCodecInformation;
struct BitmapCodecInformation;
struct IBitmapDecoderStatics;
struct IBitmapDecoder;
struct BitmapDecoder;
struct IBitmapEncoderStatics;
struct IBitmapEncoderWithSoftwareBitmap;
struct IBitmapEncoder;
struct BitmapEncoder;
enum class BitmapBufferAccessMode : int {
	Read = 0,
	ReadWrite = 1,
	Write = 2,
};
struct ISoftwareBitmap;
struct BitmapPlaneDescription {
	int StartIndex;
	int Width;
	int Height;
	int Stride;
};
struct IBitmapBuffer;
struct BitmapBuffer;
struct ISoftwareBitmapStatics;
struct ISoftwareBitmapFactory;
struct SoftwareBitmap;
}}}
} // namespace iso_winrt
