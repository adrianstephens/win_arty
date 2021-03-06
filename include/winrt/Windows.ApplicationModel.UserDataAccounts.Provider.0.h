#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace UserDataAccounts { namespace Provider {
enum class UserDataAccountProviderOperationKind : int {
	AddAccount = 0,
	Settings = 1,
	ResolveErrors = 2,
};
enum class UserDataAccountProviderPartnerAccountKind : int {
	Exchange = 0,
	PopOrImap = 1,
};
struct IUserDataAccountProviderOperation;
struct IUserDataAccountProviderAddAccountOperation;
struct IUserDataAccountPartnerAccountInfo;
struct UserDataAccountPartnerAccountInfo;
struct IUserDataAccountProviderSettingsOperation;
struct IUserDataAccountProviderResolveErrorsOperation;
struct UserDataAccountProviderAddAccountOperation;
struct UserDataAccountProviderSettingsOperation;
struct UserDataAccountProviderResolveErrorsOperation;
}}}}
} // namespace iso_winrt
