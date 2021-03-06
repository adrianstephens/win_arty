#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Security { namespace EnterpriseData {
enum class ProtectionPolicyEvaluationResult : int {
	Allowed = 0,
	Blocked = 1,
	ConsentRequired = 2,
};
struct EnterpriseDataContract {};
enum class FileProtectionStatus : int {
	Undetermined = 0,
	Unknown = 0,
	Unprotected = 1,
	Revoked = 2,
	Protected = 3,
	ProtectedByOtherUser = 4,
	ProtectedToOtherEnterprise = 5,
	NotProtectable = 6,
	ProtectedToOtherIdentity = 7,
	LicenseExpired = 8,
	AccessSuspended = 9,
	FileInUse = 10,
};
enum class ProtectedImportExportStatus : int {
	Ok = 0,
	Undetermined = 1,
	Unprotected = 2,
	Revoked = 3,
	NotRoamable = 4,
	ProtectedToOtherIdentity = 5,
	LicenseExpired = 6,
	AccessSuspended = 7,
};
enum class DataProtectionStatus : int {
	ProtectedToOtherIdentity = 0,
	Protected = 1,
	Revoked = 2,
	Unprotected = 3,
	LicenseExpired = 4,
	AccessSuspended = 5,
};
struct IFileRevocationManagerStatics;
struct IFileProtectionManagerStatics;
struct IFileProtectionInfo2;
struct IFileProtectionInfo;
struct FileProtectionInfo;
struct IProtectedContainerExportResult;
struct ProtectedContainerExportResult;
struct IProtectedContainerImportResult;
struct ProtectedContainerImportResult;
struct IProtectedFileCreateResult;
struct ProtectedFileCreateResult;
struct IFileProtectionManagerStatics2;
struct IFileUnprotectOptionsFactory;
struct IFileUnprotectOptions;
struct FileUnprotectOptions;
struct IFileProtectionManagerStatics3;
struct IDataProtectionManagerStatics;
struct IBufferProtectUnprotectResult;
struct BufferProtectUnprotectResult;
struct IDataProtectionInfo;
struct DataProtectionInfo;
enum class ProtectionPolicyAuditAction : int {
	Decrypt = 0,
	CopyToLocation = 1,
	SendToRecipient = 2,
	Other = 3,
};
enum class ProtectionPolicyRequestAccessBehavior : int {
	Decrypt = 0,
	TreatOverridePolicyAsBlock = 1,
};
struct IProtectionPolicyAuditInfoFactory;
struct IProtectionPolicyAuditInfo;
struct ProtectionPolicyAuditInfo;
struct IProtectionPolicyManager;
struct IProtectionPolicyManager2;
struct IProtectionPolicyManagerStatics;
struct IThreadNetworkContext;
struct ThreadNetworkContext;
struct IProtectionPolicyManagerStatics4;
struct IProtectionPolicyManagerStatics3;
enum class EnforcementLevel : int {
	NoProtection = 0,
	Silent = 1,
	Override = 2,
	Block = 3,
};
struct IProtectionPolicyManagerStatics2;
struct ProtectionPolicyManager;
struct IProtectedAccessSuspendingEventArgs;
struct ProtectedAccessSuspendingEventArgs;
struct IProtectedAccessResumedEventArgs;
struct ProtectedAccessResumedEventArgs;
struct IProtectedContentRevokedEventArgs;
struct ProtectedContentRevokedEventArgs;
struct FileRevocationManager;
struct FileProtectionManager;
struct DataProtectionManager;
}}}
} // namespace iso_winrt
