#pragma once
// generated by isopod tools
// namespaces:
// Windows.Security.ExchangeActiveSyncProvisioning

#include "Windows.Security.ExchangeActiveSyncProvisioning.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation> : interface_type<> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2> : interface_type<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation> : class_type<Platform::Object, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasContract> : value_type<> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult> : enum_type<int> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType> : enum_type<int> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult> : enum_type<int> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult> : enum_type<int> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult> : enum_type<int> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult> : enum_type<int> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult> : enum_type<int> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult> : enum_type<int> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult> : enum_type<int> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy> : interface_type<> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> : interface_type<> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2> : interface_type<Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> : class_type<Platform::Object, Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults, Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2> {};
template<> struct def<Windows::Security::ExchangeActiveSyncProvisioning::EasClientSecurityPolicy> : class_type<Platform::Object, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy> {};

// uuids

template<> struct uuid<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation> { define_guid(0x54DFD981, 0x1968, 0x4CA3, 0xB9, 0x58, 0xE5, 0x95, 0xD1, 0x65, 0x5, 0xEB);};
template<> struct uuid<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2> { define_guid(0xFFB35923, 0xBB26, 0x4D6A, 0x81, 0xBC, 0x16, 0x5A, 0xEE, 0xA, 0xD7, 0x54);};
template<> struct uuid<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy> { define_guid(0x45B72362, 0xDFBA, 0x4A9B, 0xAC, 0xED, 0x6F, 0xE2, 0xAD, 0xCB, 0x64, 0x20);};
template<> struct uuid<Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> { define_guid(0x463C299C, 0x7F19, 0x4C66, 0xB4, 0x3, 0xCB, 0x45, 0xDD, 0x57, 0xA2, 0xB3);};
template<> struct uuid<Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2> { define_guid(0x2FBE60C9, 0x1AA8, 0x47F5, 0x88, 0xBB, 0xCB, 0x3E, 0xF0, 0xBF, 0xFB, 0x15);};

// types

namespace Windows { namespace Security { namespace ExchangeActiveSyncProvisioning {

// IEasClientDeviceInformation
struct IEasClientDeviceInformation_raw : IInspectable {
	virtual STDMETHODIMP _get_Id(Platform::Guid *value);
	virtual STDMETHODIMP _get_OperatingSystem(HSTRING *value);
	virtual STDMETHODIMP _get_FriendlyName(HSTRING *value);
	virtual STDMETHODIMP _get_SystemManufacturer(HSTRING *value);
	virtual STDMETHODIMP _get_SystemProductName(HSTRING *value);
	virtual STDMETHODIMP _get_SystemSku(HSTRING *value);
};
template<typename X> struct IEasClientDeviceInformation_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IEasClientDeviceInformation_adaptor::FriendlyName)->_get_FriendlyName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} FriendlyName;
		struct : property {
			Platform::Guid get() { Platform::Guid value; hrcheck(enc(&IEasClientDeviceInformation_adaptor::Id)->_get_Id(&value)); return value; }
			Platform::Guid operator()() { return get(); }
			operator Platform::Guid () { return get(); }
		} Id;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IEasClientDeviceInformation_adaptor::OperatingSystem)->_get_OperatingSystem(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} OperatingSystem;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IEasClientDeviceInformation_adaptor::SystemManufacturer)->_get_SystemManufacturer(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} SystemManufacturer;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IEasClientDeviceInformation_adaptor::SystemProductName)->_get_SystemProductName(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} SystemProductName;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IEasClientDeviceInformation_adaptor::SystemSku)->_get_SystemSku(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} SystemSku;
	};
	IEasClientDeviceInformation_adaptor() {}
};
template<typename X> struct adapt<IEasClientDeviceInformation, X> : Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation_adaptor<X> { typedef adapt IEasClientDeviceInformation; };
struct IEasClientDeviceInformation : IEasClientDeviceInformation_raw, generate<IEasClientDeviceInformation> {};

// IEasClientDeviceInformation2
struct IEasClientDeviceInformation2_raw : IInspectable {
	virtual STDMETHODIMP _get_SystemHardwareVersion(HSTRING *value);
	virtual STDMETHODIMP _get_SystemFirmwareVersion(HSTRING *value);
};
template<typename X> struct IEasClientDeviceInformation2_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IEasClientDeviceInformation2_adaptor::SystemFirmwareVersion)->_get_SystemFirmwareVersion(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} SystemFirmwareVersion;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IEasClientDeviceInformation2_adaptor::SystemHardwareVersion)->_get_SystemHardwareVersion(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} SystemHardwareVersion;
	};
	IEasClientDeviceInformation2_adaptor() {}
};
template<typename X> struct adapt<IEasClientDeviceInformation2, X> : Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2_adaptor<X> { typedef adapt IEasClientDeviceInformation2; };
struct IEasClientDeviceInformation2 : IEasClientDeviceInformation2_raw, generate<IEasClientDeviceInformation2> {};

// EasClientDeviceInformation
template<typename X> struct statics<EasClientDeviceInformation, X> : X {
	typedef typename X::root_type EasClientDeviceInformation;
};
struct EasClientDeviceInformation : generate<EasClientDeviceInformation> {};

// IEasClientSecurityPolicy
struct IEasClientSecurityPolicy_raw : IInspectable {
	virtual STDMETHODIMP _get_RequireEncryption(bool *value);
	virtual STDMETHODIMP _put_RequireEncryption(bool value);
	virtual STDMETHODIMP _get_MinPasswordLength(unsigned char *value);
	virtual STDMETHODIMP _put_MinPasswordLength(unsigned char value);
	virtual STDMETHODIMP _get_DisallowConvenienceLogon(bool *value);
	virtual STDMETHODIMP _put_DisallowConvenienceLogon(bool value);
	virtual STDMETHODIMP _get_MinPasswordComplexCharacters(unsigned char *value);
	virtual STDMETHODIMP _put_MinPasswordComplexCharacters(unsigned char value);
	virtual STDMETHODIMP _get_PasswordExpiration(Foundation::TimeSpan *value);
	virtual STDMETHODIMP _put_PasswordExpiration(Foundation::TimeSpan value);
	virtual STDMETHODIMP _get_PasswordHistory(unsigned *value);
	virtual STDMETHODIMP _put_PasswordHistory(unsigned value);
	virtual STDMETHODIMP _get_MaxPasswordFailedAttempts(unsigned char *value);
	virtual STDMETHODIMP _put_MaxPasswordFailedAttempts(unsigned char value);
	virtual STDMETHODIMP _get_MaxInactivityTimeLock(Foundation::TimeSpan *value);
	virtual STDMETHODIMP _put_MaxInactivityTimeLock(Foundation::TimeSpan value);
	virtual STDMETHODIMP _CheckCompliance(EasComplianceResults* *result);
	virtual STDMETHODIMP _ApplyAsync(Foundation::IAsyncOperation<EasComplianceResults*>* *operation);
};
template<typename X> struct IEasClientSecurityPolicy_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IEasClientSecurityPolicy_adaptor::DisallowConvenienceLogon)->_get_DisallowConvenienceLogon(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IEasClientSecurityPolicy_adaptor::DisallowConvenienceLogon)->_put_DisallowConvenienceLogon(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} DisallowConvenienceLogon;
		struct : property {
			Foundation::TimeSpan get() { Foundation::TimeSpan value; hrcheck(enc(&IEasClientSecurityPolicy_adaptor::MaxInactivityTimeLock)->_get_MaxInactivityTimeLock(&value)); return value; }
			Foundation::TimeSpan operator()() { return get(); }
			operator Foundation::TimeSpan () { return get(); }
			void put(const Foundation::TimeSpan& value) { hrcheck(enc(&IEasClientSecurityPolicy_adaptor::MaxInactivityTimeLock)->_put_MaxInactivityTimeLock(value)); }
			void operator=(const Foundation::TimeSpan& value) { put(value); }
			void operator()(const Foundation::TimeSpan& value) { put(value); }
		} MaxInactivityTimeLock;
		struct : property {
			unsigned char get() { unsigned char value; hrcheck(enc(&IEasClientSecurityPolicy_adaptor::MaxPasswordFailedAttempts)->_get_MaxPasswordFailedAttempts(&value)); return value; }
			unsigned char operator()() { return get(); }
			operator unsigned char () { return get(); }
			void put(unsigned char value) { hrcheck(enc(&IEasClientSecurityPolicy_adaptor::MaxPasswordFailedAttempts)->_put_MaxPasswordFailedAttempts(value)); }
			void operator=(unsigned char value) { put(value); }
			void operator()(unsigned char value) { put(value); }
		} MaxPasswordFailedAttempts;
		struct : property {
			unsigned char get() { unsigned char value; hrcheck(enc(&IEasClientSecurityPolicy_adaptor::MinPasswordComplexCharacters)->_get_MinPasswordComplexCharacters(&value)); return value; }
			unsigned char operator()() { return get(); }
			operator unsigned char () { return get(); }
			void put(unsigned char value) { hrcheck(enc(&IEasClientSecurityPolicy_adaptor::MinPasswordComplexCharacters)->_put_MinPasswordComplexCharacters(value)); }
			void operator=(unsigned char value) { put(value); }
			void operator()(unsigned char value) { put(value); }
		} MinPasswordComplexCharacters;
		struct : property {
			unsigned char get() { unsigned char value; hrcheck(enc(&IEasClientSecurityPolicy_adaptor::MinPasswordLength)->_get_MinPasswordLength(&value)); return value; }
			unsigned char operator()() { return get(); }
			operator unsigned char () { return get(); }
			void put(unsigned char value) { hrcheck(enc(&IEasClientSecurityPolicy_adaptor::MinPasswordLength)->_put_MinPasswordLength(value)); }
			void operator=(unsigned char value) { put(value); }
			void operator()(unsigned char value) { put(value); }
		} MinPasswordLength;
		struct : property {
			Foundation::TimeSpan get() { Foundation::TimeSpan value; hrcheck(enc(&IEasClientSecurityPolicy_adaptor::PasswordExpiration)->_get_PasswordExpiration(&value)); return value; }
			Foundation::TimeSpan operator()() { return get(); }
			operator Foundation::TimeSpan () { return get(); }
			void put(const Foundation::TimeSpan& value) { hrcheck(enc(&IEasClientSecurityPolicy_adaptor::PasswordExpiration)->_put_PasswordExpiration(value)); }
			void operator=(const Foundation::TimeSpan& value) { put(value); }
			void operator()(const Foundation::TimeSpan& value) { put(value); }
		} PasswordExpiration;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IEasClientSecurityPolicy_adaptor::PasswordHistory)->_get_PasswordHistory(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
			void put(unsigned value) { hrcheck(enc(&IEasClientSecurityPolicy_adaptor::PasswordHistory)->_put_PasswordHistory(value)); }
			void operator=(unsigned value) { put(value); }
			void operator()(unsigned value) { put(value); }
		} PasswordHistory;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IEasClientSecurityPolicy_adaptor::RequireEncryption)->_get_RequireEncryption(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IEasClientSecurityPolicy_adaptor::RequireEncryption)->_put_RequireEncryption(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} RequireEncryption;
	};
	ptr<EasComplianceResults> CheckCompliance() { EasComplianceResults* result; hrcheck(X::get()->_CheckCompliance(&result)); return from_abi(result); }
	ptr<Foundation::IAsyncOperation<ptr<EasComplianceResults>>> ApplyAsync() { Foundation::IAsyncOperation<EasComplianceResults*>* operation; hrcheck(X::get()->_ApplyAsync(&operation)); return from_abi(operation); }
	IEasClientSecurityPolicy_adaptor() {}
};
template<typename X> struct adapt<IEasClientSecurityPolicy, X> : Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy_adaptor<X> { typedef adapt IEasClientSecurityPolicy; };
struct IEasClientSecurityPolicy : IEasClientSecurityPolicy_raw, generate<IEasClientSecurityPolicy> {};

// IEasComplianceResults
struct IEasComplianceResults_raw : IInspectable {
	virtual STDMETHODIMP _get_Compliant(bool *value);
	virtual STDMETHODIMP _get_RequireEncryptionResult(EasRequireEncryptionResult *value);
	virtual STDMETHODIMP _get_MinPasswordLengthResult(EasMinPasswordLengthResult *value);
	virtual STDMETHODIMP _get_DisallowConvenienceLogonResult(EasDisallowConvenienceLogonResult *value);
	virtual STDMETHODIMP _get_MinPasswordComplexCharactersResult(EasMinPasswordComplexCharactersResult *value);
	virtual STDMETHODIMP _get_PasswordExpirationResult(EasPasswordExpirationResult *value);
	virtual STDMETHODIMP _get_PasswordHistoryResult(EasPasswordHistoryResult *value);
	virtual STDMETHODIMP _get_MaxPasswordFailedAttemptsResult(EasMaxPasswordFailedAttemptsResult *value);
	virtual STDMETHODIMP _get_MaxInactivityTimeLockResult(EasMaxInactivityTimeLockResult *value);
};
template<typename X> struct IEasComplianceResults_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IEasComplianceResults_adaptor::Compliant)->_get_Compliant(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} Compliant;
		struct : property {
			EasDisallowConvenienceLogonResult get() { EasDisallowConvenienceLogonResult value; hrcheck(enc(&IEasComplianceResults_adaptor::DisallowConvenienceLogonResult)->_get_DisallowConvenienceLogonResult(&value)); return value; }
			EasDisallowConvenienceLogonResult operator()() { return get(); }
			operator EasDisallowConvenienceLogonResult () { return get(); }
		} DisallowConvenienceLogonResult;
		struct : property {
			EasMaxInactivityTimeLockResult get() { EasMaxInactivityTimeLockResult value; hrcheck(enc(&IEasComplianceResults_adaptor::MaxInactivityTimeLockResult)->_get_MaxInactivityTimeLockResult(&value)); return value; }
			EasMaxInactivityTimeLockResult operator()() { return get(); }
			operator EasMaxInactivityTimeLockResult () { return get(); }
		} MaxInactivityTimeLockResult;
		struct : property {
			EasMaxPasswordFailedAttemptsResult get() { EasMaxPasswordFailedAttemptsResult value; hrcheck(enc(&IEasComplianceResults_adaptor::MaxPasswordFailedAttemptsResult)->_get_MaxPasswordFailedAttemptsResult(&value)); return value; }
			EasMaxPasswordFailedAttemptsResult operator()() { return get(); }
			operator EasMaxPasswordFailedAttemptsResult () { return get(); }
		} MaxPasswordFailedAttemptsResult;
		struct : property {
			EasMinPasswordComplexCharactersResult get() { EasMinPasswordComplexCharactersResult value; hrcheck(enc(&IEasComplianceResults_adaptor::MinPasswordComplexCharactersResult)->_get_MinPasswordComplexCharactersResult(&value)); return value; }
			EasMinPasswordComplexCharactersResult operator()() { return get(); }
			operator EasMinPasswordComplexCharactersResult () { return get(); }
		} MinPasswordComplexCharactersResult;
		struct : property {
			EasMinPasswordLengthResult get() { EasMinPasswordLengthResult value; hrcheck(enc(&IEasComplianceResults_adaptor::MinPasswordLengthResult)->_get_MinPasswordLengthResult(&value)); return value; }
			EasMinPasswordLengthResult operator()() { return get(); }
			operator EasMinPasswordLengthResult () { return get(); }
		} MinPasswordLengthResult;
		struct : property {
			EasPasswordExpirationResult get() { EasPasswordExpirationResult value; hrcheck(enc(&IEasComplianceResults_adaptor::PasswordExpirationResult)->_get_PasswordExpirationResult(&value)); return value; }
			EasPasswordExpirationResult operator()() { return get(); }
			operator EasPasswordExpirationResult () { return get(); }
		} PasswordExpirationResult;
		struct : property {
			EasPasswordHistoryResult get() { EasPasswordHistoryResult value; hrcheck(enc(&IEasComplianceResults_adaptor::PasswordHistoryResult)->_get_PasswordHistoryResult(&value)); return value; }
			EasPasswordHistoryResult operator()() { return get(); }
			operator EasPasswordHistoryResult () { return get(); }
		} PasswordHistoryResult;
		struct : property {
			EasRequireEncryptionResult get() { EasRequireEncryptionResult value; hrcheck(enc(&IEasComplianceResults_adaptor::RequireEncryptionResult)->_get_RequireEncryptionResult(&value)); return value; }
			EasRequireEncryptionResult operator()() { return get(); }
			operator EasRequireEncryptionResult () { return get(); }
		} RequireEncryptionResult;
	};
	IEasComplianceResults_adaptor() {}
};
template<typename X> struct adapt<IEasComplianceResults, X> : Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults_adaptor<X> { typedef adapt IEasComplianceResults; };
struct IEasComplianceResults : IEasComplianceResults_raw, generate<IEasComplianceResults> {};

// IEasComplianceResults2
struct IEasComplianceResults2_raw : IInspectable {
	virtual STDMETHODIMP _get_EncryptionProviderType(EasEncryptionProviderType *value);
};
template<typename X> struct IEasComplianceResults2_adaptor : X {
	union {
		struct : property {
			EasEncryptionProviderType get() { EasEncryptionProviderType value; hrcheck(enc(&IEasComplianceResults2_adaptor::EncryptionProviderType)->_get_EncryptionProviderType(&value)); return value; }
			EasEncryptionProviderType operator()() { return get(); }
			operator EasEncryptionProviderType () { return get(); }
		} EncryptionProviderType;
	};
	IEasComplianceResults2_adaptor() {}
};
template<typename X> struct adapt<IEasComplianceResults2, X> : Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2_adaptor<X> { typedef adapt IEasComplianceResults2; };
struct IEasComplianceResults2 : IEasComplianceResults2_raw, generate<IEasComplianceResults2> {};

// EasComplianceResults
template<typename X> struct statics<EasComplianceResults, X> : X {
	typedef typename X::root_type EasComplianceResults;
};
struct EasComplianceResults : generate<EasComplianceResults> {};

// EasClientSecurityPolicy
template<typename X> struct statics<EasClientSecurityPolicy, X> : X {
	typedef typename X::root_type EasClientSecurityPolicy;
};
struct EasClientSecurityPolicy : generate<EasClientSecurityPolicy> {};
}}}
} // namespace iso_winrt