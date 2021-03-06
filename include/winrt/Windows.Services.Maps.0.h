#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Services { namespace Maps {
enum class MapRouteOptimization : int {
	Time = 0,
	Distance = 1,
	TimeWithTraffic = 2,
	Scenic = 3,
};
enum class MapRouteRestrictions : unsigned {
	None = 0x0,
	Highways = 0x1,
	TollRoads = 0x2,
	Ferries = 0x4,
	Tunnels = 0x8,
	DirtRoads = 0x10,
	Motorail = 0x20,
};
enum class MapRouteManeuverKind : int {
	None = 0,
	Start = 1,
	Stopover = 2,
	StopoverResume = 3,
	End = 4,
	GoStraight = 5,
	UTurnLeft = 6,
	UTurnRight = 7,
	TurnKeepLeft = 8,
	TurnKeepRight = 9,
	TurnLightLeft = 10,
	TurnLightRight = 11,
	TurnLeft = 12,
	TurnRight = 13,
	TurnHardLeft = 14,
	TurnHardRight = 15,
	FreewayEnterLeft = 16,
	FreewayEnterRight = 17,
	FreewayLeaveLeft = 18,
	FreewayLeaveRight = 19,
	FreewayContinueLeft = 20,
	FreewayContinueRight = 21,
	TrafficCircleLeft = 22,
	TrafficCircleRight = 23,
	TakeFerry = 24,
};
enum class MapManeuverNotices : unsigned {
	None = 0x0,
	Toll = 0x1,
	Unpaved = 0x2,
};
enum class MapLocationFinderStatus : int {
	Success = 0,
	UnknownError = 1,
	InvalidCredentials = 2,
	BadLocation = 3,
	IndexFailure = 4,
	NetworkFailure = 5,
	NotSupported = 6,
};
enum class MapRouteFinderStatus : int {
	Success = 0,
	UnknownError = 1,
	InvalidCredentials = 2,
	NoRouteFound = 3,
	NoRouteFoundWithGivenOptions = 4,
	StartPointNotFound = 5,
	EndPointNotFound = 6,
	NoPedestrianRouteFound = 7,
	NetworkFailure = 8,
	NotSupported = 9,
};
enum class MapLocationDesiredAccuracy : int {
	High = 0,
	Low = 1,
};
enum class WaypointKind : int {
	Stop = 0,
	Via = 1,
};
enum class MapServiceDataUsagePreference : int {
	Default = 0,
	OfflineMapDataOnly = 1,
};
enum class TrafficCongestion : int {
	Unknown = 0,
	Light = 1,
	Mild = 2,
	Medium = 3,
	Heavy = 4,
};
enum class ManeuverWarningKind : int {
	None = 0,
	Accident = 1,
	AdministrativeDivisionChange = 2,
	Alert = 3,
	BlockedRoad = 4,
	CheckTimetable = 5,
	Congestion = 6,
	Construction = 7,
	CountryChange = 8,
	DisabledVehicle = 9,
	GateAccess = 10,
	GetOffTransit = 11,
	GetOnTransit = 12,
	IllegalUTurn = 13,
	MassTransit = 14,
	Miscellaneous = 15,
	NoIncident = 16,
	Other = 17,
	OtherNews = 18,
	OtherTrafficIncidents = 19,
	PlannedEvent = 20,
	PrivateRoad = 21,
	RestrictedTurn = 22,
	RoadClosures = 23,
	RoadHazard = 24,
	ScheduledConstruction = 25,
	SeasonalClosures = 26,
	Tollbooth = 27,
	TollRoad = 28,
	TollZoneEnter = 29,
	TollZoneExit = 30,
	TrafficFlow = 31,
	TransitLineChange = 32,
	UnpavedRoad = 33,
	UnscheduledConstruction = 34,
	Weather = 35,
};
enum class ManeuverWarningSeverity : int {
	None = 0,
	LowImpact = 1,
	Minor = 2,
	Moderate = 3,
	Serious = 4,
};
struct IMapRouteDrivingOptions;
struct IMapRouteDrivingOptions2;
struct IMapAddress;
struct IMapAddress2;
struct IMapLocation;
struct MapAddress;
struct IMapLocationFinderResult;
struct MapLocation;
struct IMapRouteManeuver;
struct IMapRouteManeuver2;
struct IMapRouteManeuver3;
struct IManeuverWarning;
struct ManeuverWarning;
struct IMapRouteLeg;
struct MapRouteManeuver;
struct IMapRouteLeg2;
struct IMapRoute;
struct MapRouteLeg;
struct IMapRoute2;
struct IMapRoute3;
struct IMapRoute4;
struct IMapRouteFinderResult;
struct MapRoute;
struct IMapRouteFinderResult2;
struct IEnhancedWaypoint;
struct IEnhancedWaypointFactory;
struct EnhancedWaypoint;
struct IMapLocationFinderStatics;
struct MapLocationFinderResult;
struct IMapLocationFinderStatics2;
struct IMapRouteFinderStatics;
struct MapRouteFinderResult;
struct IMapRouteFinderStatics2;
struct MapRouteDrivingOptions;
struct IMapRouteFinderStatics3;
struct IMapServiceStatics;
struct IMapManagerStatics;
struct IMapServiceStatics2;
struct IMapServiceStatics3;
struct IMapServiceStatics4;
struct IPlaceInfoCreateOptions;
struct IPlaceInfoStatics;
struct IPlaceInfoStatics2;
struct IPlaceInfo;
struct PlaceInfo;
struct PlaceInfoCreateOptions;
struct MapLocationFinder;
struct MapRouteFinder;
struct MapService;
struct MapManager;
struct GuidanceContract {};
struct LocalSearchContract {};
}}}
} // namespace iso_winrt
