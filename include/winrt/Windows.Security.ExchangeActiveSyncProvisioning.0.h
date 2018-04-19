#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Security { namespace ExchangeActiveSyncProvisioning {
struct IEasClientDeviceInformation;
struct IEasClientDeviceInformation2;
struct EasClientDeviceInformation;
struct EasContract {};
enum class EasRequireEncryptionResult : int {
	NotEvaluated = 0,
	Compliant = 1,
	CanBeCompliant = 2,
	NotProvisionedOnAllVolumes = 3,
	DeFixedDataNotSupported = 4,
	FixedDataNotSupported = 4,
	DeHardwareNotCompliant = 5,
	HardwareNotCompliant = 5,
	DeWinReNotConfigured = 6,
	LockNotConfigured = 6,
	DeProtectionSuspended = 7,
	ProtectionSuspended = 7,
	DeOsVolumeNotProtected = 8,
	OsVolumeNotProtected = 8,
	DeProtectionNotYetEnabled = 9,
	ProtectionNotYetEnabled = 9,
	NoFeatureLicense = 10,
	OsNotProtected = 11,
	UnexpectedFailure = 12,
};
enum class EasEncryptionProviderType : int {
	NotEvaluated = 0,
	WindowsEncryption = 1,
	OtherEncryption = 2,
};
enum class EasMinPasswordLengthResult : int {
	NotEvaluated = 0,
	Compliant = 1,
	CanBeCompliant = 2,
	RequestedPolicyIsStricter = 3,
	RequestedPolicyNotEnforceable = 4,
	InvalidParameter = 5,
	CurrentUserHasBlankPassword = 6,
	AdminsHaveBlankPassword = 7,
	UserCannotChangePassword = 8,
	AdminsCannotChangePassword = 9,
	LocalControlledUsersCannotChangePassword = 10,
	ConnectedAdminsProviderPolicyIsWeak = 11,
	ConnectedUserProviderPolicyIsWeak = 12,
	ChangeConnectedAdminsPassword = 13,
	ChangeConnectedUserPassword = 14,
};
enum class EasDisallowConvenienceLogonResult : int {
	NotEvaluated = 0,
	Compliant = 1,
	CanBeCompliant = 2,
	RequestedPolicyIsStricter = 3,
};
enum class EasMinPasswordComplexCharactersResult : int {
	NotEvaluated = 0,
	Compliant = 1,
	CanBeCompliant = 2,
	RequestedPolicyIsStricter = 3,
	RequestedPolicyNotEnforceable = 4,
	InvalidParameter = 5,
	CurrentUserHasBlankPassword = 6,
	AdminsHaveBlankPassword = 7,
	UserCannotChangePassword = 8,
	AdminsCannotChangePassword = 9,
	LocalControlledUsersCannotChangePassword = 10,
	ConnectedAdminsProviderPolicyIsWeak = 11,
	ConnectedUserProviderPolicyIsWeak = 12,
	ChangeConnectedAdminsPassword = 13,
	ChangeConnectedUserPassword = 14,
};
enum class EasPasswordExpirationResult : int {
	NotEvaluated = 0,
	Compliant = 1,
	CanBeCompliant = 2,
	RequestedPolicyIsStricter = 3,
	RequestedExpirationIncompatible = 4,
	InvalidParameter = 5,
	UserCannotChangePassword = 6,
	AdminsCannotChangePassword = 7,
	LocalControlledUsersCannotChangePassword = 8,
};
enum class EasPasswordHistoryResult : int {
	NotEvaluated = 0,
	Compliant = 1,
	CanBeCompliant = 2,
	RequestedPolicyIsStricter = 3,
	InvalidParameter = 4,
};
enum class EasMaxPasswordFailedAttemptsResult : int {
	NotEvaluated = 0,
	Compliant = 1,
	CanBeCompliant = 2,
	RequestedPolicyIsStricter = 3,
	InvalidParameter = 4,
};
enum class EasMaxInactivityTimeLockResult : int {
	NotEvaluated = 0,
	Compliant = 1,
	CanBeCompliant = 2,
	RequestedPolicyIsStricter = 3,
	InvalidParameter = 4,
};
struct IEasClientSecurityPolicy;
struct IEasComplianceResults;
struct IEasComplianceResults2;
struct EasComplianceResults;
struct EasClientSecurityPolicy;
}}}
} // namespace iso_winrt