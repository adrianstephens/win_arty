#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Security { namespace Authentication { namespace Web { namespace Core {
enum class WebTokenRequestPromptType : int {
	Default = 0,
	ForceAuthentication = 1,
};
struct IWebTokenRequest;
struct IWebTokenRequest2;
struct IWebTokenRequest3;
struct IWebTokenRequestFactory;
struct WebTokenRequest;
struct IWebAccountEventArgs;
struct WebAccountEventArgs;
enum class FindAllWebAccountsStatus : int {
	Success = 0,
	NotAllowedByProvider = 1,
	NotSupportedByProvider = 2,
	ProviderError = 3,
};
struct IFindAllAccountsResult;
struct FindAllAccountsResult;
struct IWebAuthenticationCoreManagerStatics;
struct IWebAuthenticationCoreManagerStatics2;
struct IWebAuthenticationCoreManagerStatics3;
struct IWebAccountMonitor;
struct WebAccountMonitor;
struct IWebAuthenticationCoreManagerStatics4;
struct WebAuthenticationCoreManager;
enum class WebTokenRequestStatus : int {
	Success = 0,
	UserCancel = 1,
	AccountSwitch = 2,
	UserInteractionRequired = 3,
	AccountProviderNotAvailable = 4,
	ProviderError = 5,
};
struct IWebProviderError;
struct IWebProviderErrorFactory;
struct WebProviderError;
struct IWebTokenRequestResult;
struct IWebTokenResponseFactory;
struct IWebTokenResponse;
struct WebTokenResponse;
struct WebTokenRequestResult;
}}}}}
} // namespace iso_winrt