#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace WiFiDirect {
enum class WiFiDirectConnectionStatus : int {
	Disconnected = 0,
	Connected = 1,
};
enum class WiFiDirectError : int {
	Success = 0,
	RadioNotAvailable = 1,
	ResourceInUse = 2,
};
enum class WiFiDirectDeviceSelectorType : int {
	DeviceInterface = 0,
	AssociationEndpoint = 1,
};
enum class WiFiDirectAdvertisementListenStateDiscoverability : int {
	None = 0,
	Normal = 1,
	Intensive = 2,
};
enum class WiFiDirectAdvertisementPublisherStatus : int {
	Created = 0,
	Started = 1,
	Stopped = 2,
	Aborted = 3,
};
enum class WiFiDirectConfigurationMethod : int {
	ProvidePin = 0,
	DisplayPin = 1,
	PushButton = 2,
};
enum class WiFiDirectPairingProcedure : int {
	GroupOwnerNegotiation = 0,
	Invitation = 1,
};
struct IWiFiDirectDeviceStatics;
struct IWiFiDirectDeviceStatics2;
struct IWiFiDirectDevice;
struct WiFiDirectDevice;
struct IWiFiDirectConnectionParametersStatics;
struct IWiFiDirectConnectionParameters2;
struct IWiFiDirectConnectionParameters;
struct WiFiDirectConnectionParameters;
struct IWiFiDirectInformationElementStatics;
struct IWiFiDirectInformationElement;
struct WiFiDirectInformationElement;
struct IWiFiDirectLegacySettings;
struct WiFiDirectLegacySettings;
struct IWiFiDirectAdvertisement;
struct IWiFiDirectAdvertisement2;
struct WiFiDirectAdvertisement;
struct IWiFiDirectAdvertisementPublisherStatusChangedEventArgs;
struct WiFiDirectAdvertisementPublisherStatusChangedEventArgs;
struct IWiFiDirectAdvertisementPublisher;
struct WiFiDirectAdvertisementPublisher;
struct IWiFiDirectConnectionRequest;
struct WiFiDirectConnectionRequest;
struct IWiFiDirectConnectionRequestedEventArgs;
struct WiFiDirectConnectionRequestedEventArgs;
struct IWiFiDirectConnectionListener;
struct WiFiDirectConnectionListener;
}}}
} // namespace iso_winrt
