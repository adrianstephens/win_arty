#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Enumeration {
struct IDeviceConnectionChangeTriggerDetails;
struct DeviceConnectionChangeTriggerDetails;
enum class DevicePickerDisplayStatusOptions : unsigned {
	None = 0x0,
	ShowProgress = 0x1,
	ShowDisconnectButton = 0x2,
	ShowRetryButton = 0x4,
};
struct IDevicePickerAppearance;
struct DevicePickerAppearance;
struct IDeviceSelectedEventArgs;
struct DeviceSelectedEventArgs;
struct IDeviceDisconnectButtonClickedEventArgs;
struct DeviceDisconnectButtonClickedEventArgs;
enum class DeviceClass : int {
	All = 0,
	AudioCapture = 1,
	AudioRender = 2,
	PortableStorageDevice = 3,
	VideoCapture = 4,
	ImageScanner = 5,
	Location = 6,
};
struct IDevicePickerFilter;
struct DevicePickerFilter;
struct IDevicePicker;
struct DevicePicker;
enum class DeviceWatcherStatus : int {
	Created = 0,
	Started = 1,
	EnumerationCompleted = 2,
	Stopping = 3,
	Stopped = 4,
	Aborted = 5,
};
struct DeviceThumbnail;
enum class Panel : int {
	Unknown = 0,
	Front = 1,
	Back = 2,
	Top = 3,
	Bottom = 4,
	Left = 5,
	Right = 6,
};
struct IEnclosureLocation;
struct IEnclosureLocation2;
struct EnclosureLocation;
enum class DeviceInformationKind : int {
	Unknown = 0,
	DeviceInterface = 1,
	DeviceContainer = 2,
	Device = 3,
	DeviceInterfaceClass = 4,
	AssociationEndpoint = 5,
	AssociationEndpointContainer = 6,
	AssociationEndpointService = 7,
};
struct IDeviceInformationUpdate;
struct IDeviceInformationUpdate2;
struct DeviceInformationUpdate;
struct IDeviceInformationStatics2;
struct IDeviceInformationStatics;
struct IDeviceInformation2;
struct IDeviceInformation;
struct DeviceInformation;
struct DeviceInformationCollection;
struct IDeviceWatcher;
enum class DeviceWatcherEventKind : int {
	Add = 0,
	Update = 1,
	Remove = 2,
};
struct IDeviceWatcher2;
struct DeviceWatcher;
enum class DevicePairingKinds : unsigned {
	None = 0x0,
	ConfirmOnly = 0x1,
	DisplayPin = 0x2,
	ProvidePin = 0x4,
	ConfirmPinMatch = 0x8,
};
enum class DevicePairingResultStatus : int {
	Paired = 0,
	NotReadyToPair = 1,
	NotPaired = 2,
	AlreadyPaired = 3,
	ConnectionRejected = 4,
	TooManyConnections = 5,
	HardwareFailure = 6,
	AuthenticationTimeout = 7,
	AuthenticationNotAllowed = 8,
	AuthenticationFailure = 9,
	NoSupportedProfiles = 10,
	ProtectionLevelCouldNotBeMet = 11,
	AccessDenied = 12,
	InvalidCeremonyData = 13,
	PairingCanceled = 14,
	OperationAlreadyInProgress = 15,
	RequiredHandlerNotRegistered = 16,
	RejectedByHandler = 17,
	RemoteDeviceHasAssociation = 18,
	Failed = 19,
};
enum class DeviceUnpairingResultStatus : int {
	Unpaired = 0,
	AlreadyUnpaired = 1,
	OperationAlreadyInProgress = 2,
	AccessDenied = 3,
	Failed = 4,
};
enum class DevicePairingProtectionLevel : int {
	Default = 0,
	None = 1,
	Encryption = 2,
	EncryptionAndAuthentication = 3,
};
struct IDevicePairingResult;
struct DevicePairingResult;
struct IDeviceUnpairingResult;
struct DeviceUnpairingResult;
struct IDevicePairingSettings;
struct IDevicePairingRequestedEventArgs;
struct DevicePairingRequestedEventArgs;
struct IDeviceInformationCustomPairing;
struct DeviceInformationCustomPairing;
struct IDeviceInformationPairing;
struct IDeviceInformationPairing2;
struct IDeviceInformationPairingStatics;
struct DeviceInformationPairing;
enum class DeviceAccessStatus : int {
	Unspecified = 0,
	Allowed = 1,
	DeniedByUser = 2,
	DeniedBySystem = 3,
};
struct IDeviceAccessChangedEventArgs;
struct IDeviceAccessChangedEventArgs2;
struct DeviceAccessChangedEventArgs;
struct IDeviceAccessInformation;
struct IDeviceAccessInformationStatics;
struct DeviceAccessInformation;
struct IDeviceWatcherEvent;
struct DeviceWatcherEvent;
struct IDeviceWatcherTriggerDetails;
struct DeviceWatcherTriggerDetails;
}}}
} // namespace iso_winrt
