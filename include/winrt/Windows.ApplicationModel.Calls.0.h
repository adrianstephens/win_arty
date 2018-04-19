#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace Calls {
struct CallsPhoneContract {};
enum class PhoneNetworkState : int {
	Unknown = 0,
	NoSignal = 1,
	Deregistered = 2,
	Denied = 3,
	Searching = 4,
	Home = 5,
	RoamingInternational = 6,
	RoamingDomestic = 7,
};
enum class PhoneVoicemailType : int {
	None = 0,
	Traditional = 1,
	Visual = 2,
};
enum class PhoneCallMedia : int {
	Audio = 0,
	AudioAndVideo = 1,
	AudioAndRealTimeText = 2,
};
enum class PhoneLineTransport : int {
	Cellular = 0,
	VoipApp = 1,
};
enum class PhoneSimState : int {
	Unknown = 0,
	PinNotRequired = 1,
	PinUnlocked = 2,
	PinLocked = 3,
	PukLocked = 4,
	NotInserted = 5,
	Invalid = 6,
	Disabled = 7,
};
enum class PhoneAudioRoutingEndpoint : int {
	Default = 0,
	Bluetooth = 1,
	Speakerphone = 2,
};
enum class PhoneLineWatcherStatus : int {
	Created = 0,
	Started = 1,
	EnumerationCompleted = 2,
	Stopped = 3,
};
enum class PhoneLineNetworkOperatorDisplayTextLocation : int {
	Default = 0,
	Tile = 1,
	Dialer = 2,
	InCallUI = 3,
};
enum class CellularDtmfMode : int {
	Continuous = 0,
	Burst = 1,
};
struct IPhoneVoicemail;
struct IPhoneDialOptions;
struct IPhoneLineCellularDetails;
struct IPhoneLine;
struct IPhoneLineStatics;
struct PhoneLine;
struct PhoneVoicemail;
struct PhoneLineCellularDetails;
struct IPhoneCallVideoCapabilities;
struct PhoneCallVideoCapabilities;
struct IPhoneLineConfiguration;
struct PhoneLineConfiguration;
struct PhoneDialOptions;
struct IPhoneCallStore;
struct IPhoneLineWatcher;
struct PhoneLineWatcher;
struct IPhoneLineWatcherEventArgs;
struct PhoneLineWatcherEventArgs;
struct IPhoneCallManagerStatics;
struct IPhoneCallManagerStatics2;
struct PhoneCallStore;
struct IPhoneCallVideoCapabilitiesManagerStatics;
struct IPhoneCallBlockingStatics;
struct PhoneCallManager;
struct PhoneCallVideoCapabilitiesManager;
struct PhoneCallBlocking;
struct CallsVoipContract {};
enum class VoipPhoneCallMedia : unsigned {
	None = 0x0,
	Audio = 0x1,
	Video = 0x2,
};
enum class VoipPhoneCallRejectReason : int {
	UserIgnored = 0,
	TimedOut = 1,
	OtherIncomingCall = 2,
	EmergencyCallExists = 3,
	InvalidCallState = 4,
};
enum class VoipPhoneCallState : int {
	Ended = 0,
	Held = 1,
	Active = 2,
	Incoming = 3,
	Outgoing = 4,
};
enum class VoipPhoneCallResourceReservationStatus : int {
	Success = 0,
	ResourcesNotAvailable = 1,
};
struct ICallStateChangeEventArgs;
struct CallStateChangeEventArgs;
struct ICallAnswerEventArgs;
struct CallAnswerEventArgs;
struct ICallRejectEventArgs;
struct CallRejectEventArgs;
struct IVoipPhoneCall;
struct IVoipPhoneCall2;
struct IVoipPhoneCall3;
struct VoipPhoneCall;
struct IMuteChangeEventArgs;
struct MuteChangeEventArgs;
struct IVoipCallCoordinator;
struct IVoipCallCoordinatorStatics;
struct IVoipCallCoordinator3;
struct IVoipCallCoordinator2;
struct VoipCallCoordinator;
struct LockScreenCallContract {};
struct ILockScreenCallEndCallDeferral;
struct ILockScreenCallEndRequestedEventArgs;
struct LockScreenCallEndCallDeferral;
struct ILockScreenCallUI;
struct LockScreenCallUI;
struct LockScreenCallEndRequestedEventArgs;
enum class PhoneCallHistoryEntryOtherAppReadAccess : int {
	Full = 0,
	SystemOnly = 1,
};
enum class PhoneCallHistoryEntryMedia : int {
	Audio = 0,
	Video = 1,
};
enum class PhoneCallHistoryEntryRawAddressKind : int {
	PhoneNumber = 0,
	Custom = 1,
};
enum class PhoneCallHistoryEntryQueryDesiredMedia : unsigned {
	None = 0x0,
	Audio = 0x1,
	Video = 0x2,
	All = 0xFFFFFFFF,
};
enum class PhoneCallHistoryStoreAccessType : int {
	AppEntriesReadWrite = 0,
	AllEntriesLimitedReadWrite = 1,
	AllEntriesReadWrite = 2,
};
enum class PhoneCallHistorySourceIdKind : int {
	CellularPhoneLineId = 0,
	PackageFamilyName = 1,
};
struct IPhoneCallHistoryEntry;
struct IPhoneCallHistoryEntryAddressFactory;
struct IPhoneCallHistoryEntryAddress;
struct PhoneCallHistoryEntryAddress;
struct IPhoneCallHistoryEntryQueryOptions;
struct IPhoneCallHistoryEntryReader;
struct PhoneCallHistoryEntry;
struct IPhoneCallHistoryStore;
struct PhoneCallHistoryEntryReader;
struct PhoneCallHistoryEntryQueryOptions;
struct IPhoneCallHistoryManagerStatics;
struct PhoneCallHistoryStore;
struct IPhoneCallHistoryManagerStatics2;
struct IPhoneCallHistoryManagerForUser;
struct PhoneCallHistoryManagerForUser;
struct PhoneCallHistoryManager;
}}}
} // namespace iso_winrt
