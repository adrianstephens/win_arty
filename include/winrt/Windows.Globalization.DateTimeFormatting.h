#pragma once
// generated by isopod tools
// namespaces:
// Windows.Globalization.DateTimeFormatting

#include "Windows.Globalization.DateTimeFormatting.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IIterable;
template<typename T> struct IVectorView;
}}}

// defs

template<> struct def<Windows::Globalization::DateTimeFormatting::YearFormat> : enum_type<int> {};
template<> struct def<Windows::Globalization::DateTimeFormatting::MonthFormat> : enum_type<int> {};
template<> struct def<Windows::Globalization::DateTimeFormatting::DayOfWeekFormat> : enum_type<int> {};
template<> struct def<Windows::Globalization::DateTimeFormatting::DayFormat> : enum_type<int> {};
template<> struct def<Windows::Globalization::DateTimeFormatting::HourFormat> : enum_type<int> {};
template<> struct def<Windows::Globalization::DateTimeFormatting::MinuteFormat> : enum_type<int> {};
template<> struct def<Windows::Globalization::DateTimeFormatting::SecondFormat> : enum_type<int> {};
template<> struct def<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> : interface_type<> {};
template<> struct def<Windows::Globalization::DateTimeFormatting::IDateTimeFormatterFactory> : interface_type<> {};
template<> struct def<Windows::Globalization::DateTimeFormatting::IDateTimeFormatterStatics> : interface_type<> {};
template<> struct def<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter2> : interface_type<> {};
template<> struct def<Windows::Globalization::DateTimeFormatting::DateTimeFormatter> : class_type<Platform::Object, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter, Windows::Globalization::DateTimeFormatting::IDateTimeFormatter2>, custom_activators {};

// uuids

template<> struct uuid<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter> { define_guid(0x95EECA10, 0x73E0, 0x4E4B, 0xA1, 0x83, 0x3D, 0x6A, 0xD0, 0xBA, 0x35, 0xEC);};
template<> struct uuid<Windows::Globalization::DateTimeFormatting::IDateTimeFormatterFactory> { define_guid(0xEC8D8A53, 0x1A2E, 0x412D, 0x88, 0x15, 0x3B, 0x74, 0x5F, 0xB1, 0xA2, 0xA0);};
template<> struct uuid<Windows::Globalization::DateTimeFormatting::IDateTimeFormatterStatics> { define_guid(0xBFCDE7C0, 0xDF4C, 0x4A2E, 0x90, 0x12, 0xF4, 0x7D, 0xAF, 0x3F, 0x12, 0x12);};
template<> struct uuid<Windows::Globalization::DateTimeFormatting::IDateTimeFormatter2> { define_guid(0x27C91A86, 0xBDAA, 0x4FD0, 0x9E, 0x36, 0x67, 0x1D, 0x5A, 0xA5, 0xEE, 0x3);};

// types

namespace Windows { namespace Globalization { namespace DateTimeFormatting {

// IDateTimeFormatter
struct IDateTimeFormatter_raw : IInspectable {
	virtual STDMETHODIMP _get_Languages(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _get_GeographicRegion(HSTRING *value);
	virtual STDMETHODIMP _get_Calendar(HSTRING *value);
	virtual STDMETHODIMP _get_Clock(HSTRING *value);
	virtual STDMETHODIMP _get_NumeralSystem(HSTRING *value);
	virtual STDMETHODIMP _put_NumeralSystem(HSTRING value);
	virtual STDMETHODIMP _get_Patterns(Foundation::Collections::IVectorView<HSTRING>* *value);
	virtual STDMETHODIMP _get_Template(HSTRING *value);
	virtual STDMETHODIMP _Format(Foundation::DateTime value, HSTRING *result);
	virtual STDMETHODIMP _get_IncludeYear(YearFormat *value);
	virtual STDMETHODIMP _get_IncludeMonth(MonthFormat *value);
	virtual STDMETHODIMP _get_IncludeDayOfWeek(DayOfWeekFormat *value);
	virtual STDMETHODIMP _get_IncludeDay(DayFormat *value);
	virtual STDMETHODIMP _get_IncludeHour(HourFormat *value);
	virtual STDMETHODIMP _get_IncludeMinute(MinuteFormat *value);
	virtual STDMETHODIMP _get_IncludeSecond(SecondFormat *value);
	virtual STDMETHODIMP _get_ResolvedLanguage(HSTRING *value);
	virtual STDMETHODIMP _get_ResolvedGeographicRegion(HSTRING *value);
};
template<typename X> struct IDateTimeFormatter_adaptor : X {
	union {
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IDateTimeFormatter_adaptor::Calendar)->_get_Calendar(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Calendar;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IDateTimeFormatter_adaptor::Clock)->_get_Clock(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Clock;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IDateTimeFormatter_adaptor::GeographicRegion)->_get_GeographicRegion(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} GeographicRegion;
		struct : property {
			DayFormat get() { DayFormat value; hrcheck(enc(&IDateTimeFormatter_adaptor::IncludeDay)->_get_IncludeDay(&value)); return value; }
			DayFormat operator()() { return get(); }
			operator DayFormat () { return get(); }
		} IncludeDay;
		struct : property {
			DayOfWeekFormat get() { DayOfWeekFormat value; hrcheck(enc(&IDateTimeFormatter_adaptor::IncludeDayOfWeek)->_get_IncludeDayOfWeek(&value)); return value; }
			DayOfWeekFormat operator()() { return get(); }
			operator DayOfWeekFormat () { return get(); }
		} IncludeDayOfWeek;
		struct : property {
			HourFormat get() { HourFormat value; hrcheck(enc(&IDateTimeFormatter_adaptor::IncludeHour)->_get_IncludeHour(&value)); return value; }
			HourFormat operator()() { return get(); }
			operator HourFormat () { return get(); }
		} IncludeHour;
		struct : property {
			MinuteFormat get() { MinuteFormat value; hrcheck(enc(&IDateTimeFormatter_adaptor::IncludeMinute)->_get_IncludeMinute(&value)); return value; }
			MinuteFormat operator()() { return get(); }
			operator MinuteFormat () { return get(); }
		} IncludeMinute;
		struct : property {
			MonthFormat get() { MonthFormat value; hrcheck(enc(&IDateTimeFormatter_adaptor::IncludeMonth)->_get_IncludeMonth(&value)); return value; }
			MonthFormat operator()() { return get(); }
			operator MonthFormat () { return get(); }
		} IncludeMonth;
		struct : property {
			SecondFormat get() { SecondFormat value; hrcheck(enc(&IDateTimeFormatter_adaptor::IncludeSecond)->_get_IncludeSecond(&value)); return value; }
			SecondFormat operator()() { return get(); }
			operator SecondFormat () { return get(); }
		} IncludeSecond;
		struct : property {
			YearFormat get() { YearFormat value; hrcheck(enc(&IDateTimeFormatter_adaptor::IncludeYear)->_get_IncludeYear(&value)); return value; }
			YearFormat operator()() { return get(); }
			operator YearFormat () { return get(); }
		} IncludeYear;
		struct : property {
			ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(enc(&IDateTimeFormatter_adaptor::Languages)->_get_Languages(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
		} Languages;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IDateTimeFormatter_adaptor::NumeralSystem)->_get_NumeralSystem(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
			void put(hstring_ref value) { hrcheck(enc(&IDateTimeFormatter_adaptor::NumeralSystem)->_put_NumeralSystem(value)); }
			void operator=(hstring_ref value) { put(value); }
			void operator()(hstring_ref value) { put(value); }
		} NumeralSystem;
		struct : property {
			ptr<Foundation::Collections::IVectorView<hstring>> get() { Foundation::Collections::IVectorView<HSTRING>* value; hrcheck(enc(&IDateTimeFormatter_adaptor::Patterns)->_get_Patterns(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<hstring>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<hstring>> operator->() { return get(); }
		} Patterns;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IDateTimeFormatter_adaptor::ResolvedGeographicRegion)->_get_ResolvedGeographicRegion(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ResolvedGeographicRegion;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IDateTimeFormatter_adaptor::ResolvedLanguage)->_get_ResolvedLanguage(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} ResolvedLanguage;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IDateTimeFormatter_adaptor::Template)->_get_Template(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} Template;
	};
	hstring Format(const Foundation::DateTime& value) { HSTRING result; hrcheck(X::get()->_Format(value, &result)); return from_abi(result); }
	IDateTimeFormatter_adaptor() {}
};
template<typename X> struct adapt<IDateTimeFormatter, X> : Windows::Globalization::DateTimeFormatting::IDateTimeFormatter_adaptor<X> { typedef adapt IDateTimeFormatter; };
struct IDateTimeFormatter : IDateTimeFormatter_raw, generate<IDateTimeFormatter> {};

// IDateTimeFormatterFactory
struct IDateTimeFormatterFactory : IInspectable {
	virtual STDMETHODIMP _CreateDateTimeFormatter(HSTRING formatTemplate, DateTimeFormatter* *result);
	virtual STDMETHODIMP _CreateDateTimeFormatterLanguages(HSTRING formatTemplate, Foundation::Collections::IIterable<HSTRING>* languages, DateTimeFormatter* *result);
	virtual STDMETHODIMP _CreateDateTimeFormatterContext(HSTRING formatTemplate, Foundation::Collections::IIterable<HSTRING>* languages, HSTRING geographicRegion, HSTRING calendar, HSTRING clock, DateTimeFormatter* *result);
	virtual STDMETHODIMP _CreateDateTimeFormatterDate(YearFormat yearFormat, MonthFormat monthFormat, DayFormat dayFormat, DayOfWeekFormat dayOfWeekFormat, DateTimeFormatter* *result);
	virtual STDMETHODIMP _CreateDateTimeFormatterTime(HourFormat hourFormat, MinuteFormat minuteFormat, SecondFormat secondFormat, DateTimeFormatter* *result);
	virtual STDMETHODIMP _CreateDateTimeFormatterDateTimeLanguages(YearFormat yearFormat, MonthFormat monthFormat, DayFormat dayFormat, DayOfWeekFormat dayOfWeekFormat, HourFormat hourFormat, MinuteFormat minuteFormat, SecondFormat secondFormat, Foundation::Collections::IIterable<HSTRING>* languages, DateTimeFormatter* *result);
	virtual STDMETHODIMP _CreateDateTimeFormatterDateTimeContext(YearFormat yearFormat, MonthFormat monthFormat, DayFormat dayFormat, DayOfWeekFormat dayOfWeekFormat, HourFormat hourFormat, MinuteFormat minuteFormat, SecondFormat secondFormat, Foundation::Collections::IIterable<HSTRING>* languages, HSTRING geographicRegion, HSTRING calendar, HSTRING clock, DateTimeFormatter* *result);
};

// IDateTimeFormatterStatics
struct IDateTimeFormatterStatics : IInspectable {
	virtual STDMETHODIMP _get_LongDate(DateTimeFormatter* *value);
	virtual STDMETHODIMP _get_LongTime(DateTimeFormatter* *value);
	virtual STDMETHODIMP _get_ShortDate(DateTimeFormatter* *value);
	virtual STDMETHODIMP _get_ShortTime(DateTimeFormatter* *value);
};

// IDateTimeFormatter2
struct IDateTimeFormatter2_raw : IInspectable {
	virtual STDMETHODIMP _FormatUsingTimeZone(Foundation::DateTime datetime, HSTRING timeZoneId, HSTRING *result);
};
template<typename X> struct IDateTimeFormatter2_adaptor : X {
	hstring Format(const Foundation::DateTime& datetime, hstring_ref timeZoneId) { HSTRING result; hrcheck(X::get()->_FormatUsingTimeZone(datetime, timeZoneId, &result)); return from_abi(result); }
};
template<typename X> struct adapt<IDateTimeFormatter2, X> : Windows::Globalization::DateTimeFormatting::IDateTimeFormatter2_adaptor<X> { typedef adapt IDateTimeFormatter2; };
struct IDateTimeFormatter2 : IDateTimeFormatter2_raw, generate<IDateTimeFormatter2> {};

// DateTimeFormatter
template<typename> struct DateTimeFormatter_statics {
	static struct _LongDate : property {
		ptr<DateTimeFormatter> get() { DateTimeFormatter* value; hrcheck(get_activation_factory<DateTimeFormatter, IDateTimeFormatterStatics>()->_get_LongDate(&value)); return from_abi(value); }
		ptr<DateTimeFormatter> operator()() { return get(); }
		operator ptr<DateTimeFormatter> () { return get(); }
		ptr<DateTimeFormatter> operator->() { return get(); }
	} LongDate;
	static struct _LongTime : property {
		ptr<DateTimeFormatter> get() { DateTimeFormatter* value; hrcheck(get_activation_factory<DateTimeFormatter, IDateTimeFormatterStatics>()->_get_LongTime(&value)); return from_abi(value); }
		ptr<DateTimeFormatter> operator()() { return get(); }
		operator ptr<DateTimeFormatter> () { return get(); }
		ptr<DateTimeFormatter> operator->() { return get(); }
	} LongTime;
	static struct _ShortDate : property {
		ptr<DateTimeFormatter> get() { DateTimeFormatter* value; hrcheck(get_activation_factory<DateTimeFormatter, IDateTimeFormatterStatics>()->_get_ShortDate(&value)); return from_abi(value); }
		ptr<DateTimeFormatter> operator()() { return get(); }
		operator ptr<DateTimeFormatter> () { return get(); }
		ptr<DateTimeFormatter> operator->() { return get(); }
	} ShortDate;
	static struct _ShortTime : property {
		ptr<DateTimeFormatter> get() { DateTimeFormatter* value; hrcheck(get_activation_factory<DateTimeFormatter, IDateTimeFormatterStatics>()->_get_ShortTime(&value)); return from_abi(value); }
		ptr<DateTimeFormatter> operator()() { return get(); }
		operator ptr<DateTimeFormatter> () { return get(); }
		ptr<DateTimeFormatter> operator->() { return get(); }
	} ShortTime;
	static DateTimeFormatter *activate(hstring_ref formatTemplate) { DateTimeFormatter *result; hrcheck(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>()->_CreateDateTimeFormatter(formatTemplate, &result)); return result; }
	static DateTimeFormatter *activate(hstring_ref formatTemplate, pptr<Foundation::Collections::IIterable<hstring>> languages) { DateTimeFormatter *result; hrcheck(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>()->_CreateDateTimeFormatterLanguages(formatTemplate, to_abi(languages), &result)); return result; }
	static DateTimeFormatter *activate(hstring_ref formatTemplate, pptr<Foundation::Collections::IIterable<hstring>> languages, hstring_ref geographicRegion, hstring_ref calendar, hstring_ref clock) { DateTimeFormatter *result; hrcheck(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>()->_CreateDateTimeFormatterContext(formatTemplate, to_abi(languages), geographicRegion, calendar, clock, &result)); return result; }
	static DateTimeFormatter *activate(YearFormat yearFormat, MonthFormat monthFormat, DayFormat dayFormat, DayOfWeekFormat dayOfWeekFormat) { DateTimeFormatter *result; hrcheck(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>()->_CreateDateTimeFormatterDate(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, &result)); return result; }
	static DateTimeFormatter *activate(HourFormat hourFormat, MinuteFormat minuteFormat, SecondFormat secondFormat) { DateTimeFormatter *result; hrcheck(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>()->_CreateDateTimeFormatterTime(hourFormat, minuteFormat, secondFormat, &result)); return result; }
	static DateTimeFormatter *activate(YearFormat yearFormat, MonthFormat monthFormat, DayFormat dayFormat, DayOfWeekFormat dayOfWeekFormat, HourFormat hourFormat, MinuteFormat minuteFormat, SecondFormat secondFormat, pptr<Foundation::Collections::IIterable<hstring>> languages) { DateTimeFormatter *result; hrcheck(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>()->_CreateDateTimeFormatterDateTimeLanguages(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, hourFormat, minuteFormat, secondFormat, to_abi(languages), &result)); return result; }
	static DateTimeFormatter *activate(YearFormat yearFormat, MonthFormat monthFormat, DayFormat dayFormat, DayOfWeekFormat dayOfWeekFormat, HourFormat hourFormat, MinuteFormat minuteFormat, SecondFormat secondFormat, pptr<Foundation::Collections::IIterable<hstring>> languages, hstring_ref geographicRegion, hstring_ref calendar, hstring_ref clock) { DateTimeFormatter *result; hrcheck(get_activation_factory<DateTimeFormatter, IDateTimeFormatterFactory>()->_CreateDateTimeFormatterDateTimeContext(yearFormat, monthFormat, dayFormat, dayOfWeekFormat, hourFormat, minuteFormat, secondFormat, to_abi(languages), geographicRegion, calendar, clock, &result)); return result; }
};
template<typename X> typename DateTimeFormatter_statics<X>::_LongDate DateTimeFormatter_statics<X>::LongDate;
template<typename X> typename DateTimeFormatter_statics<X>::_LongTime DateTimeFormatter_statics<X>::LongTime;
template<typename X> typename DateTimeFormatter_statics<X>::_ShortDate DateTimeFormatter_statics<X>::ShortDate;
template<typename X> typename DateTimeFormatter_statics<X>::_ShortTime DateTimeFormatter_statics<X>::ShortTime;

template<typename X> struct statics<DateTimeFormatter, X> : X, Windows::Globalization::DateTimeFormatting::DateTimeFormatter_statics<void> {
	using Windows::Globalization::DateTimeFormatting::DateTimeFormatter_statics<void>::activate;
	typedef typename X::root_type DateTimeFormatter;
};
struct DateTimeFormatter : generate<DateTimeFormatter> {
	using IDateTimeFormatter2::Format;
	using IDateTimeFormatter::Format;
};
}}}
} // namespace iso_winrt
