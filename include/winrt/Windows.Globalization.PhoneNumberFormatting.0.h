#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Globalization { namespace PhoneNumberFormatting {
enum class PhoneNumberFormat : int {
	E164 = 0,
	International = 1,
	National = 2,
	Rfc3966 = 3,
};
enum class PredictedPhoneNumberKind : int {
	FixedLine = 0,
	Mobile = 1,
	FixedLineOrMobile = 2,
	TollFree = 3,
	PremiumRate = 4,
	SharedCost = 5,
	Voip = 6,
	PersonalNumber = 7,
	Pager = 8,
	UniversalAccountNumber = 9,
	Voicemail = 10,
	Unknown = 11,
};
enum class PhoneNumberParseResult : int {
	Valid = 0,
	NotANumber = 1,
	InvalidCountryCode = 2,
	TooShort = 3,
	TooLong = 4,
};
enum class PhoneNumberMatchResult : int {
	NoMatch = 0,
	ShortNationalSignificantNumberMatch = 1,
	NationalSignificantNumberMatch = 2,
	ExactMatch = 3,
};
struct IPhoneNumberInfo;
struct IPhoneNumberInfoStatics;
struct IPhoneNumberInfoFactory;
struct PhoneNumberInfo;
struct IPhoneNumberFormatter;
struct IPhoneNumberFormatterStatics;
struct PhoneNumberFormatter;
}}}
} // namespace iso_winrt
