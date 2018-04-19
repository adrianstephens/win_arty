#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Services { namespace Maps { namespace Guidance {
struct IGuidanceRoadSignpost;
struct GuidanceRoadSignpost;
enum class GuidanceManeuverKind : int {
	None = 0,
	GoStraight = 1,
	UTurnRight = 2,
	UTurnLeft = 3,
	TurnKeepRight = 4,
	TurnLightRight = 5,
	TurnRight = 6,
	TurnHardRight = 7,
	KeepMiddle = 8,
	TurnKeepLeft = 9,
	TurnLightLeft = 10,
	TurnLeft = 11,
	TurnHardLeft = 12,
	FreewayEnterRight = 13,
	FreewayEnterLeft = 14,
	FreewayLeaveRight = 15,
	FreewayLeaveLeft = 16,
	FreewayKeepRight = 17,
	FreewayKeepLeft = 18,
	TrafficCircleRight1 = 19,
	TrafficCircleRight2 = 20,
	TrafficCircleRight3 = 21,
	TrafficCircleRight4 = 22,
	TrafficCircleRight5 = 23,
	TrafficCircleRight6 = 24,
	TrafficCircleRight7 = 25,
	TrafficCircleRight8 = 26,
	TrafficCircleRight9 = 27,
	TrafficCircleRight10 = 28,
	TrafficCircleRight11 = 29,
	TrafficCircleRight12 = 30,
	TrafficCircleLeft1 = 31,
	TrafficCircleLeft2 = 32,
	TrafficCircleLeft3 = 33,
	TrafficCircleLeft4 = 34,
	TrafficCircleLeft5 = 35,
	TrafficCircleLeft6 = 36,
	TrafficCircleLeft7 = 37,
	TrafficCircleLeft8 = 38,
	TrafficCircleLeft9 = 39,
	TrafficCircleLeft10 = 40,
	TrafficCircleLeft11 = 41,
	TrafficCircleLeft12 = 42,
	Start = 43,
	End = 44,
	TakeFerry = 45,
	PassTransitStation = 46,
	LeaveTransitStation = 47,
};
enum class GuidanceMode : int {
	None = 0,
	Simulation = 1,
	Navigation = 2,
	Tracking = 3,
};
enum class GuidanceAudioMeasurementSystem : int {
	Meters = 0,
	MilesAndYards = 1,
	MilesAndFeet = 2,
};
enum class GuidanceAudioNotifications : unsigned {
	None = 0x0,
	Maneuver = 0x1,
	Route = 0x2,
	Gps = 0x4,
	SpeedLimit = 0x8,
	Traffic = 0x10,
	TrafficCamera = 0x20,
};
enum class GuidanceAudioNotificationKind : int {
	Maneuver = 0,
	Route = 1,
	Gps = 2,
	SpeedLimit = 3,
	Traffic = 4,
	TrafficCamera = 5,
};
enum class GuidanceLaneMarkers : unsigned {
	None = 0x0,
	LightRight = 0x1,
	Right = 0x2,
	HardRight = 0x4,
	Straight = 0x8,
	UTurnLeft = 0x10,
	HardLeft = 0x20,
	Left = 0x40,
	LightLeft = 0x80,
	UTurnRight = 0x100,
	Unknown = 0xFFFFFFFF,
};
struct IGuidanceManeuver;
struct GuidanceManeuver;
struct IGuidanceUpdatedEventArgs;
struct IGuidanceRouteStatics;
struct IGuidanceRoute;
struct GuidanceRoute;
struct IGuidanceMapMatchedCoordinate;
struct GuidanceMapMatchedCoordinate;
struct IGuidanceLaneInfo;
struct GuidanceLaneInfo;
struct GuidanceUpdatedEventArgs;
struct IGuidanceReroutedEventArgs;
struct GuidanceReroutedEventArgs;
struct IGuidanceAudioNotificationRequestedEventArgs;
struct GuidanceAudioNotificationRequestedEventArgs;
struct IGuidanceNavigator;
struct IGuidanceNavigatorStatics2;
struct IGuidanceNavigatorStatics;
struct IGuidanceNavigator2;
struct GuidanceNavigator;
struct IGuidanceRoadSegment;
struct IGuidanceRoadSegment2;
struct GuidanceRoadSegment;
struct IGuidanceTelemetryCollectorStatics;
struct IGuidanceTelemetryCollector;
struct GuidanceTelemetryCollector;
}}}}
} // namespace iso_winrt