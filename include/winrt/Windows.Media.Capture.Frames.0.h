#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Media { namespace Capture { namespace Frames {
enum class MediaFrameSourceKind : int {
	Custom = 0,
	Color = 1,
	Infrared = 2,
	Depth = 3,
	Audio = 4,
	Image = 5,
};
struct IMediaFrameSourceInfo2;
struct IMediaFrameSourceInfo;
struct MediaFrameSourceInfo;
struct IMediaFrameSourceGroupStatics;
struct IMediaFrameSourceGroup;
struct MediaFrameSourceGroup;
struct IMediaFrameSource;
struct MediaFrameSource;
enum class MediaFrameReaderAcquisitionMode : int {
	Realtime = 0,
	Buffered = 1,
};
enum class MediaFrameReaderStartStatus : int {
	Success = 0,
	UnknownFailure = 1,
	DeviceNotAvailable = 2,
	OutputFormatNotSupported = 3,
	ExclusiveControlNotAvailable = 4,
};
struct IMediaFrameReader2;
struct IMediaFrameReader;
struct MediaFrameReader;
enum class MultiSourceMediaFrameReaderStartStatus : int {
	Success = 0,
	NotSupported = 1,
	InsufficientResources = 2,
	DeviceNotAvailable = 3,
	UnknownFailure = 4,
};
struct IMultiSourceMediaFrameReader2;
struct IMultiSourceMediaFrameReader;
struct MultiSourceMediaFrameReader;
enum class MediaFrameSourceSetPropertyStatus : int {
	Success = 0,
	UnknownFailure = 1,
	NotSupported = 2,
	InvalidValue = 3,
	DeviceNotAvailable = 4,
	NotInControl = 5,
};
enum class MediaFrameSourceGetPropertyStatus : int {
	Success = 0,
	UnknownFailure = 1,
	NotSupported = 2,
	DeviceNotAvailable = 3,
	MaxPropertyValueSizeTooSmall = 4,
	MaxPropertyValueSizeRequired = 5,
};
struct IMediaFrameSourceController3;
struct IMediaFrameSourceController2;
struct IMediaFrameSourceController;
struct MediaFrameSourceController;
struct IMediaFrameFormat2;
struct IMediaFrameFormat;
struct MediaFrameFormat;
struct IMediaFrameArrivedEventArgs;
struct MediaFrameArrivedEventArgs;
struct IMediaFrameReference2;
struct IMediaFrameReference;
struct MediaFrameReference;
struct IMultiSourceMediaFrameArrivedEventArgs;
struct MultiSourceMediaFrameArrivedEventArgs;
struct IMultiSourceMediaFrameReference;
struct MultiSourceMediaFrameReference;
struct IMediaFrameSourceGetPropertyResult;
struct MediaFrameSourceGetPropertyResult;
struct IVideoMediaFrameFormat;
struct VideoMediaFrameFormat;
struct IDepthMediaFrameFormat;
struct DepthMediaFrameFormat;
struct IBufferMediaFrame;
struct BufferMediaFrame;
struct IVideoMediaFrame;
struct VideoMediaFrame;
struct IAudioMediaFrame;
struct AudioMediaFrame;
struct IInfraredMediaFrame;
struct InfraredMediaFrame;
struct IDepthMediaFrame2;
struct IDepthMediaFrame;
struct DepthMediaFrame;
}}}}
} // namespace iso_winrt
