#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Media { namespace MediaProperties {
enum class StereoscopicVideoPackingMode : int {
	None = 0,
	SideBySide = 1,
	TopBottom = 2,
};
enum class SphericalVideoFrameFormat : int {
	None = 0,
	Unsupported = 1,
	Equirectangular = 2,
};
struct IMediaRatio;
struct MediaRatio;
struct MediaPropertySet;
struct IMediaEncodingProperties;
struct IAudioEncodingProperties;
struct IAudioEncodingPropertiesWithFormatUserData;
struct IAudioEncodingProperties2;
struct IAudioEncodingProperties3;
struct IAudioEncodingPropertiesStatics2;
struct IAudioEncodingPropertiesStatics;
struct AudioEncodingProperties;
struct IVideoEncodingProperties;
struct IMediaEncodingSubtypesStatics;
struct IMediaEncodingSubtypesStatics2;
struct IMediaEncodingSubtypesStatics3;
struct IMediaEncodingSubtypesStatics4;
struct MediaEncodingSubtypes;
struct IH264ProfileIdsStatics;
struct H264ProfileIds;
struct IMpeg2ProfileIdsStatics;
struct Mpeg2ProfileIds;
struct IVideoEncodingProperties2;
struct IVideoEncodingProperties3;
struct IVideoEncodingProperties4;
struct IVideoEncodingProperties5;
struct IVideoEncodingPropertiesStatics2;
struct IVideoEncodingPropertiesStatics;
struct VideoEncodingProperties;
struct ITimedMetadataEncodingProperties;
struct TimedMetadataEncodingProperties;
struct IImageEncodingProperties;
struct IImageEncodingProperties2;
enum class MediaPixelFormat : int {
	Nv12 = 0,
	Bgra8 = 1,
	P010 = 2,
};
struct IImageEncodingPropertiesStatics2;
struct IImageEncodingPropertiesStatics;
struct ImageEncodingProperties;
enum class MediaThumbnailFormat : int {
	Bmp = 0,
	Bgra8 = 1,
};
struct IContainerEncodingProperties;
struct IContainerEncodingProperties2;
struct ContainerEncodingProperties;
enum class AudioEncodingQuality : int {
	Auto = 0,
	High = 1,
	Medium = 2,
	Low = 3,
};
enum class VideoEncodingQuality : int {
	Auto = 0,
	HD1080p = 1,
	HD720p = 2,
	Wvga = 3,
	Ntsc = 4,
	Pal = 5,
	Vga = 6,
	Qvga = 7,
	Uhd2160p = 8,
	Uhd4320p = 9,
};
struct IMediaEncodingProfileStatics;
struct IMediaEncodingProfileStatics3;
struct IMediaEncodingProfileStatics2;
struct IMediaEncodingProfile3;
struct IMediaEncodingProfile2;
struct IMediaEncodingProfile;
struct MediaEncodingProfile;
enum class MediaRotation : int {
	None = 0,
	Clockwise90Degrees = 1,
	Clockwise180Degrees = 2,
	Clockwise270Degrees = 3,
};
enum class MediaMirroringOptions : unsigned {
	None = 0x0,
	Horizontal = 0x1,
	Vertical = 0x2,
};
}}}
} // namespace iso_winrt