#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Security { namespace Credentials {
enum class KeyCredentialStatus : int {
	Success = 0,
	UnknownError = 1,
	NotFound = 2,
	UserCanceled = 3,
	UserPrefersPassword = 4,
	CredentialAlreadyExists = 5,
	SecurityDeviceLocked = 6,
};
enum class KeyCredentialAttestationStatus : int {
	Success = 0,
	UnknownError = 1,
	NotSupported = 2,
	TemporaryFailure = 3,
};
enum class KeyCredentialCreationOption : int {
	ReplaceExisting = 0,
	FailIfExists = 1,
};
struct IKeyCredentialManagerStatics;
struct IKeyCredentialRetrievalResult;
struct KeyCredentialRetrievalResult;
struct IKeyCredential;
struct IKeyCredentialOperationResult;
struct KeyCredentialOperationResult;
struct IKeyCredentialAttestationResult;
struct KeyCredentialAttestationResult;
struct KeyCredential;
struct KeyCredentialManager;
enum class WebAccountState : int {
	None = 0,
	Connected = 1,
	Error = 2,
};
enum class WebAccountPictureSize : int {
	Size64x64 = 64,
	Size208x208 = 208,
	Size424x424 = 424,
	Size1080x1080 = 1080,
};
struct IWebAccountFactory;
struct IWebAccountProviderFactory;
struct IWebAccountProvider4;
struct IWebAccountProvider;
struct IWebAccountProvider2;
struct IWebAccountProvider3;
struct WebAccountProvider;
struct IWebAccount;
struct IWebAccount2;
struct WebAccount;
struct IPasswordCredential;
struct ICredentialFactory;
struct PasswordCredential;
struct IPasswordVault;
struct PasswordVault;
struct PasswordCredentialPropertyStore;
}}}
} // namespace iso_winrt
