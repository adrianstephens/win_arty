#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace Activation {
struct ActivatedEventsContract {};
enum class ApplicationExecutionState : int {
	NotRunning = 0,
	Running = 1,
	Suspended = 2,
	Terminated = 3,
	ClosedByUser = 4,
};
enum class ActivationKind : int {
	Launch = 0,
	Search = 1,
	ShareTarget = 2,
	File = 3,
	Protocol = 4,
	FileOpenPicker = 5,
	FileSavePicker = 6,
	CachedFileUpdater = 7,
	ContactPicker = 8,
	Device = 9,
	PrintTaskSettings = 10,
	CameraSettings = 11,
	RestrictedLaunch = 12,
	AppointmentsProvider = 13,
	Contact = 14,
	LockScreenCall = 15,
	VoiceCommand = 16,
	LockScreen = 17,
	PickerReturned = 1000,
	WalletAction = 1001,
	PickFileContinuation = 1002,
	PickSaveFileContinuation = 1003,
	PickFolderContinuation = 1004,
	WebAuthenticationBrokerContinuation = 1005,
	WebAccountProvider = 1006,
	ComponentUI = 1007,
	ProtocolForResults = 1009,
	ToastNotification = 1010,
	Print3DWorkflow = 1011,
	DialReceiver = 1012,
	DevicePairing = 1013,
	UserDataAccountsProvider = 1014,
	FilePickerExperience = 1015,
	LockScreenComponent = 1016,
	ContactPanel = 1017,
	PrintWorkflowForegroundTask = 1018,
	GameUIProvider = 1019,
	StartupTask = 1020,
	CommandLineLaunch = 1021,
	BarcodeScannerProvider = 1022,
};
struct IActivatedEventArgs;
struct IPrintTaskSettingsActivatedEventArgs;
struct PrintTaskSettingsActivatedEventArgs;
struct IPrint3DWorkflowActivatedEventArgs;
struct Print3DWorkflowActivatedEventArgs;
struct IViewSwitcherProvider;
struct IApplicationViewActivatedEventArgs;
struct ILaunchActivatedEventArgs;
struct ILockScreenCallActivatedEventArgs;
struct LockScreenCallActivatedEventArgs;
struct ActivationCameraSettingsContract {};
struct ICameraSettingsActivatedEventArgs;
struct CameraSettingsActivatedEventArgs;
struct ContactActivatedEventsContract {};
struct IContactPickerActivatedEventArgs;
struct ContactPickerActivatedEventArgs;
struct IContactActivatedEventArgs;
struct IContactCallActivatedEventArgs;
struct ContactCallActivatedEventArgs;
struct IContactMessageActivatedEventArgs;
struct ContactMessageActivatedEventArgs;
struct IContactMapActivatedEventArgs;
struct ContactMapActivatedEventArgs;
struct IContactPostActivatedEventArgs;
struct ContactPostActivatedEventArgs;
struct IContactVideoCallActivatedEventArgs;
struct ContactVideoCallActivatedEventArgs;
struct WebUISearchActivatedEventsContract {};
struct IWalletActionActivatedEventArgs;
struct WalletActionActivatedEventArgs;
struct IActivatedEventArgsWithUser;
struct IAppointmentsProviderActivatedEventArgs;
struct IAppointmentsProviderAddAppointmentActivatedEventArgs;
struct AppointmentsProviderAddAppointmentActivatedEventArgs;
struct IAppointmentsProviderReplaceAppointmentActivatedEventArgs;
struct AppointmentsProviderReplaceAppointmentActivatedEventArgs;
struct IAppointmentsProviderRemoveAppointmentActivatedEventArgs;
struct AppointmentsProviderRemoveAppointmentActivatedEventArgs;
struct IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
struct AppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
struct IAppointmentsProviderShowTimeFrameActivatedEventArgs;
struct AppointmentsProviderShowTimeFrameActivatedEventArgs;
struct IBackgroundActivatedEventArgs;
struct BackgroundActivatedEventArgs;
struct IContactPanelActivatedEventArgs;
struct ContactPanelActivatedEventArgs;
struct IShareTargetActivatedEventArgs;
struct ShareTargetActivatedEventArgs;
struct IUserDataAccountProviderActivatedEventArgs;
struct UserDataAccountProviderActivatedEventArgs;
struct ISplashScreen;
struct SplashScreen;
struct IContactsProviderActivatedEventArgs;
struct IPrelaunchActivatedEventArgs;
struct ILaunchActivatedEventArgs2;
struct ITileActivatedInfo;
struct TileActivatedInfo;
struct LaunchActivatedEventArgs;
struct ISearchActivatedEventArgs;
struct ISearchActivatedEventArgsWithLinguisticDetails;
struct SearchActivatedEventArgs;
struct IFileActivatedEventArgs;
struct IFileActivatedEventArgsWithNeighboringFiles;
struct IFileActivatedEventArgsWithCallerPackageFamilyName;
struct FileActivatedEventArgs;
struct IProtocolActivatedEventArgs;
struct IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData;
struct ProtocolActivatedEventArgs;
struct IProtocolForResultsActivatedEventArgs;
struct ProtocolForResultsActivatedEventArgs;
struct IFileOpenPickerActivatedEventArgs;
struct IFileOpenPickerActivatedEventArgs2;
struct FileOpenPickerActivatedEventArgs;
struct IFileSavePickerActivatedEventArgs;
struct IFileSavePickerActivatedEventArgs2;
struct FileSavePickerActivatedEventArgs;
struct ICachedFileUpdaterActivatedEventArgs;
struct CachedFileUpdaterActivatedEventArgs;
struct IDeviceActivatedEventArgs;
struct DeviceActivatedEventArgs;
struct IPickerReturnedActivatedEventArgs;
struct PickerReturnedActivatedEventArgs;
struct IRestrictedLaunchActivatedEventArgs;
struct RestrictedLaunchActivatedEventArgs;
struct ILockScreenActivatedEventArgs;
struct LockScreenActivatedEventArgs;
struct IContinuationActivatedEventArgs;
struct IFileOpenPickerContinuationEventArgs;
struct FileOpenPickerContinuationEventArgs;
struct IFileSavePickerContinuationEventArgs;
struct FileSavePickerContinuationEventArgs;
struct IFolderPickerContinuationEventArgs;
struct FolderPickerContinuationEventArgs;
struct IWebAuthenticationBrokerContinuationEventArgs;
struct WebAuthenticationBrokerContinuationEventArgs;
struct IWebAccountProviderActivatedEventArgs;
struct WebAccountProviderActivatedEventArgs;
struct IToastNotificationActivatedEventArgs;
struct ToastNotificationActivatedEventArgs;
struct IDialReceiverActivatedEventArgs;
struct DialReceiverActivatedEventArgs;
struct LockScreenComponentActivatedEventArgs;
struct ICommandLineActivationOperation;
struct CommandLineActivationOperation;
struct ICommandLineActivatedEventArgs;
struct CommandLineActivatedEventArgs;
struct IStartupTaskActivatedEventArgs;
struct StartupTaskActivatedEventArgs;
struct IBarcodeScannerPreviewActivatedEventArgs;
struct BarcodeScannerPreviewActivatedEventArgs;
struct IDevicePairingActivatedEventArgs;
struct DevicePairingActivatedEventArgs;
struct IVoiceCommandActivatedEventArgs;
struct VoiceCommandActivatedEventArgs;
}}}
} // namespace iso_winrt
