#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace UI { namespace Text { namespace Core {
enum class CoreTextInputScope : int {
	Default = 0,
	Url = 1,
	FilePath = 2,
	FileName = 3,
	EmailUserName = 4,
	EmailAddress = 5,
	UserName = 6,
	PersonalFullName = 7,
	PersonalNamePrefix = 8,
	PersonalGivenName = 9,
	PersonalMiddleName = 10,
	PersonalSurname = 11,
	PersonalNameSuffix = 12,
	Address = 13,
	AddressPostalCode = 14,
	AddressStreet = 15,
	AddressStateOrProvince = 16,
	AddressCity = 17,
	AddressCountryName = 18,
	AddressCountryShortName = 19,
	CurrencyAmountAndSymbol = 20,
	CurrencyAmount = 21,
	Date = 22,
	DateMonth = 23,
	DateDay = 24,
	DateYear = 25,
	DateMonthName = 26,
	DateDayName = 27,
	Number = 29,
	SingleCharacter = 30,
	Password = 31,
	TelephoneNumber = 32,
	TelephoneCountryCode = 33,
	TelephoneAreaCode = 34,
	TelephoneLocalNumber = 35,
	Time = 36,
	TimeHour = 37,
	TimeMinuteOrSecond = 38,
	NumberFullWidth = 39,
	AlphanumericHalfWidth = 40,
	AlphanumericFullWidth = 41,
	CurrencyChinese = 42,
	Bopomofo = 43,
	Hiragana = 44,
	KatakanaHalfWidth = 45,
	KatakanaFullWidth = 46,
	Hanja = 47,
	HangulHalfWidth = 48,
	HangulFullWidth = 49,
	Search = 50,
	Formula = 51,
	SearchIncremental = 52,
	ChineseHalfWidth = 53,
	ChineseFullWidth = 54,
	NativeScript = 55,
	Text = 57,
	Chat = 58,
	NameOrPhoneNumber = 59,
	EmailUserNameOrAddress = 60,
	Private = 61,
	Maps = 62,
	PasswordNumeric = 63,
	FormulaNumber = 67,
	ChatWithoutEmoji = 68,
	Digits = 28,
	PinNumeric = 64,
	PinAlphanumeric = 65,
};
enum class CoreTextInputPaneDisplayPolicy : int {
	Automatic = 0,
	Manual = 1,
};
enum class CoreTextTextUpdatingResult : int {
	Succeeded = 0,
	Failed = 1,
};
enum class CoreTextSelectionUpdatingResult : int {
	Succeeded = 0,
	Failed = 1,
};
enum class CoreTextFormatUpdatingResult : int {
	Succeeded = 0,
	Failed = 1,
};
enum class CoreTextFormatUpdatingReason : int {
	None = 0,
	CompositionUnconverted = 1,
	CompositionConverted = 2,
	CompositionTargetUnconverted = 3,
	CompositionTargetConverted = 4,
};
struct CoreTextRange {
	int StartCaretPosition;
	int EndCaretPosition;
};
struct ICoreTextTextRequest;
struct ICoreTextTextRequestedEventArgs;
struct CoreTextTextRequest;
struct ICoreTextSelectionRequest;
struct ICoreTextSelectionRequestedEventArgs;
struct CoreTextSelectionRequest;
struct ICoreTextLayoutBounds;
struct ICoreTextLayoutRequest;
struct CoreTextLayoutBounds;
struct ICoreTextLayoutRequestedEventArgs;
struct CoreTextLayoutRequest;
struct ICoreTextTextUpdatingEventArgs;
struct ICoreTextSelectionUpdatingEventArgs;
struct ICoreTextFormatUpdatingEventArgs;
struct ICoreTextCompositionStartedEventArgs;
struct ICoreTextCompositionCompletedEventArgs;
struct ICoreTextCompositionSegment;
struct CoreTextCompositionSegment;
struct ICoreTextEditContext2;
struct ICoreTextEditContext;
struct CoreTextEditContext;
struct CoreTextTextRequestedEventArgs;
struct CoreTextSelectionRequestedEventArgs;
struct CoreTextLayoutRequestedEventArgs;
struct CoreTextTextUpdatingEventArgs;
struct CoreTextSelectionUpdatingEventArgs;
struct CoreTextFormatUpdatingEventArgs;
struct CoreTextCompositionStartedEventArgs;
struct CoreTextCompositionCompletedEventArgs;
struct ICoreTextServicesManager;
struct ICoreTextServicesManagerStatics;
struct CoreTextServicesManager;
struct ICoreTextServicesStatics;
struct CoreTextServicesConstants;
}}}}
} // namespace iso_winrt
