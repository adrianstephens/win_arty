#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Media { namespace Protection {
struct IMediaProtectionManager;
struct MediaProtectionManager;
struct IServiceRequestedEventArgs2;
struct IServiceRequestedEventArgs;
struct ServiceRequestedEventArgs;
struct IComponentLoadFailedEventArgs;
struct ComponentLoadFailedEventArgs;
struct IMediaProtectionServiceCompletion;
struct MediaProtectionServiceCompletion;
struct IRevocationAndRenewalInformation;
struct RevocationAndRenewalInformation;
enum class RevocationAndRenewalReasons : unsigned {
	UserModeComponentLoad = 0x1,
	KernelModeComponentLoad = 0x2,
	AppComponent = 0x4,
	GlobalRevocationListLoadFailed = 0x10,
	InvalidGlobalRevocationListSignature = 0x20,
	GlobalRevocationListAbsent = 0x1000,
	ComponentRevoked = 0x2000,
	InvalidComponentCertificateExtendedKeyUse = 0x4000,
	ComponentCertificateRevoked = 0x8000,
	InvalidComponentCertificateRoot = 0x10000,
	ComponentHighSecurityCertificateRevoked = 0x20000,
	ComponentLowSecurityCertificateRevoked = 0x40000,
	BootDriverVerificationFailed = 0x100000,
	ComponentSignedWithTestCertificate = 0x1000000,
	EncryptionFailure = 0x10000000,
};
struct IRevocationAndRenewalItem;
struct RevocationAndRenewalItem;
struct IMediaProtectionPMPServerFactory;
struct IMediaProtectionPMPServer;
struct MediaProtectionPMPServer;
struct ServiceRequestedEventHandler;
struct RebootNeededEventHandler;
struct ComponentLoadFailedEventHandler;
struct IMediaProtectionServiceRequest;
enum class GraphicsTrustStatus : int {
	TrustNotRequired = 0,
	TrustEstablished = 1,
	EnvironmentNotSupported = 2,
	DriverNotSupported = 3,
	DriverSigningFailure = 4,
	UnknownFailure = 5,
};
enum class ProtectionCapabilityResult : int {
	NotSupported = 0,
	Maybe = 1,
	Probably = 2,
};
struct IProtectionCapabilities;
struct ProtectionCapabilities;
enum class HdcpProtection : int {
	Off = 0,
	On = 1,
	OnWithTypeEnforcement = 2,
};
enum class HdcpSetProtectionResult : int {
	Success = 0,
	TimedOut = 1,
	NotSupported = 2,
	UnknownFailure = 3,
};
struct IHdcpSession;
struct HdcpSession;
struct ProtectionRenewalContract {};
enum class RenewalStatus : int {
	NotStarted = 0,
	UpdatesInProgress = 1,
	UserCancelled = 2,
	AppComponentsMayNeedUpdating = 3,
	NoComponentsFound = 4,
};
struct IComponentRenewalStatics;
struct ComponentRenewal;
}}}
} // namespace iso_winrt
