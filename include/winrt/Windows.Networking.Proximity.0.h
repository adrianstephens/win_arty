#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Networking { namespace Proximity {
struct IProximityMessage;
struct ProximityMessage;
struct MessageReceivedHandler;
struct IProximityDeviceStatics;
struct IProximityDevice;
struct ProximityDevice;
struct MessageTransmittedHandler;
struct DeviceArrivedEventHandler;
struct DeviceDepartedEventHandler;
enum class TriggeredConnectState : int {
	PeerFound = 0,
	Listening = 1,
	Connecting = 2,
	Completed = 3,
	Canceled = 4,
	Failed = 5,
};
struct ITriggeredConnectionStateChangedEventArgs;
struct TriggeredConnectionStateChangedEventArgs;
struct IPeerInformation;
struct IPeerInformationWithHostAndService;
struct IPeerInformation3;
struct PeerInformation;
struct IConnectionRequestedEventArgs;
struct ConnectionRequestedEventArgs;
enum class PeerWatcherStatus : int {
	Created = 0,
	Started = 1,
	EnumerationCompleted = 2,
	Stopping = 3,
	Stopped = 4,
	Aborted = 5,
};
struct IPeerWatcher;
struct PeerWatcher;
enum class PeerDiscoveryTypes : unsigned {
	None = 0x0,
	Browse = 0x1,
	Triggered = 0x2,
};
enum class PeerRole : int {
	Peer = 0,
	Host = 1,
	Client = 2,
};
struct IPeerFinderStatics;
struct IPeerFinderStatics2;
struct PeerFinder;
}}}
} // namespace iso_winrt