#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Perception {
enum class PerceptionFrameSourceAccessStatus : int {
	Unspecified = 0,
	Allowed = 1,
	DeniedByUser = 2,
	DeniedBySystem = 3,
};
enum class PerceptionFrameSourcePropertyChangeStatus : int {
	Unknown = 0,
	Accepted = 1,
	LostControl = 2,
	PropertyNotSupported = 3,
	PropertyReadOnly = 4,
	ValueOutOfRange = 5,
};
struct IPerceptionColorFrameSourceWatcher;
struct PerceptionColorFrameSourceWatcher;
struct IPerceptionColorFrameSourceAddedEventArgs;
struct PerceptionColorFrameSourceAddedEventArgs;
struct IPerceptionColorFrameSourceRemovedEventArgs;
struct PerceptionColorFrameSourceRemovedEventArgs;
struct IPerceptionDepthFrameSourceWatcher;
struct PerceptionDepthFrameSourceWatcher;
struct IPerceptionDepthFrameSourceAddedEventArgs;
struct PerceptionDepthFrameSourceAddedEventArgs;
struct IPerceptionDepthFrameSourceRemovedEventArgs;
struct PerceptionDepthFrameSourceRemovedEventArgs;
struct IPerceptionInfraredFrameSourceWatcher;
struct PerceptionInfraredFrameSourceWatcher;
struct IPerceptionInfraredFrameSourceAddedEventArgs;
struct PerceptionInfraredFrameSourceAddedEventArgs;
struct IPerceptionInfraredFrameSourceRemovedEventArgs;
struct PerceptionInfraredFrameSourceRemovedEventArgs;
struct IPerceptionColorFrameSourceStatics;
struct IPerceptionColorFrameSource2;
struct IPerceptionColorFrameSource;
struct PerceptionColorFrameSource;
struct IPerceptionDepthFrameSourceStatics;
struct IPerceptionDepthFrameSource2;
struct IPerceptionDepthFrameSource;
struct PerceptionDepthFrameSource;
struct IPerceptionInfraredFrameSourceStatics;
struct IPerceptionInfraredFrameSource2;
struct IPerceptionInfraredFrameSource;
struct PerceptionInfraredFrameSource;
struct IKnownPerceptionFrameSourcePropertiesStatics;
struct IKnownPerceptionFrameSourcePropertiesStatics2;
struct IKnownPerceptionVideoFrameSourcePropertiesStatics;
struct IKnownPerceptionInfraredFrameSourcePropertiesStatics;
struct IKnownPerceptionDepthFrameSourcePropertiesStatics;
struct IKnownPerceptionColorFrameSourcePropertiesStatics;
struct IKnownPerceptionVideoProfilePropertiesStatics;
struct IKnownCameraIntrinsicsPropertiesStatics;
struct IPerceptionFrameSourcePropertyChangeResult;
struct IPerceptionControlSession;
struct PerceptionControlSession;
struct PerceptionFrameSourcePropertyChangeResult;
struct IPerceptionFrameSourcePropertiesChangedEventArgs;
struct PerceptionFrameSourcePropertiesChangedEventArgs;
struct IPerceptionVideoProfile;
struct PerceptionVideoProfile;
struct IPerceptionDepthCorrelatedCameraIntrinsics;
struct PerceptionDepthCorrelatedCameraIntrinsics;
struct IPerceptionDepthCorrelatedCoordinateMapper;
struct PerceptionDepthCorrelatedCoordinateMapper;
struct IPerceptionColorFrameReader;
struct PerceptionColorFrameReader;
struct IPerceptionDepthFrameReader;
struct PerceptionDepthFrameReader;
struct IPerceptionInfraredFrameReader;
struct PerceptionInfraredFrameReader;
struct IPerceptionColorFrameArrivedEventArgs;
struct PerceptionColorFrameArrivedEventArgs;
struct IPerceptionColorFrame;
struct PerceptionColorFrame;
struct IPerceptionDepthFrameArrivedEventArgs;
struct PerceptionDepthFrameArrivedEventArgs;
struct IPerceptionDepthFrame;
struct PerceptionDepthFrame;
struct IPerceptionInfraredFrameArrivedEventArgs;
struct PerceptionInfraredFrameArrivedEventArgs;
struct IPerceptionInfraredFrame;
struct PerceptionInfraredFrame;
struct KnownPerceptionFrameSourceProperties;
struct KnownPerceptionVideoFrameSourceProperties;
struct KnownPerceptionInfraredFrameSourceProperties;
struct KnownPerceptionDepthFrameSourceProperties;
struct KnownPerceptionColorFrameSourceProperties;
struct KnownPerceptionVideoProfileProperties;
struct KnownCameraIntrinsicsProperties;
}}}
} // namespace iso_winrt