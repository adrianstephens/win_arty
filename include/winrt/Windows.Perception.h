#pragma once
// generated by isopod tools
// namespaces:
// Windows.Perception

#include "Windows.Perception.0.h"
#include "Windows.Foundation.0.h"

namespace iso_winrt {

// forward types


// defs

template<> struct def<Windows::Perception::IPerceptionTimestamp> : interface_type<> {};
template<> struct def<Windows::Perception::PerceptionTimestamp> : class_type<Platform::Object, Windows::Perception::IPerceptionTimestamp> {};
template<> struct def<Windows::Perception::IPerceptionTimestampHelperStatics> : interface_type<> {};
template<> struct def<Windows::Perception::PerceptionTimestampHelper> : class_type<Platform::Object, Platform::Object> {};

// uuids

template<> struct uuid<Windows::Perception::IPerceptionTimestamp> { define_guid(0x87C24804, 0xA22E, 0x4ADB, 0xBA, 0x26, 0xD7, 0x8E, 0xF6, 0x39, 0xBC, 0xF4);};
template<> struct uuid<Windows::Perception::IPerceptionTimestampHelperStatics> { define_guid(0x47A611D4, 0xA9DF, 0x4EDC, 0x85, 0x5D, 0xF4, 0xD3, 0x39, 0xD9, 0x67, 0xAC);};

// types

namespace Windows { namespace Perception {

// IPerceptionTimestamp
struct IPerceptionTimestamp_raw : IInspectable {
	virtual STDMETHODIMP _get_TargetTime(Foundation::DateTime *value);
	virtual STDMETHODIMP _get_PredictionAmount(Foundation::TimeSpan *value);
};
template<typename X> struct IPerceptionTimestamp_adaptor : X {
	union {
		struct : property {
			Foundation::TimeSpan get() { Foundation::TimeSpan value; hrcheck(enc(&IPerceptionTimestamp_adaptor::PredictionAmount)->_get_PredictionAmount(&value)); return value; }
			Foundation::TimeSpan operator()() { return get(); }
			operator Foundation::TimeSpan () { return get(); }
		} PredictionAmount;
		struct : property {
			Foundation::DateTime get() { Foundation::DateTime value; hrcheck(enc(&IPerceptionTimestamp_adaptor::TargetTime)->_get_TargetTime(&value)); return value; }
			Foundation::DateTime operator()() { return get(); }
			operator Foundation::DateTime () { return get(); }
		} TargetTime;
	};
	IPerceptionTimestamp_adaptor() {}
};
template<typename X> struct adapt<IPerceptionTimestamp, X> : Windows::Perception::IPerceptionTimestamp_adaptor<X> { typedef adapt IPerceptionTimestamp; };
struct IPerceptionTimestamp : IPerceptionTimestamp_raw, generate<IPerceptionTimestamp> {};

// PerceptionTimestamp
template<typename X> struct statics<PerceptionTimestamp, X> : X {
	typedef typename X::root_type PerceptionTimestamp;
};
struct PerceptionTimestamp : generate<PerceptionTimestamp> {};

// IPerceptionTimestampHelperStatics
struct IPerceptionTimestampHelperStatics : IInspectable {
	virtual STDMETHODIMP _FromHistoricalTargetTime(Foundation::DateTime targetTime, PerceptionTimestamp* *value);
};

// PerceptionTimestampHelper
template<typename> struct PerceptionTimestampHelper_statics {
	static ptr<PerceptionTimestamp> FromHistoricalTargetTime(const Foundation::DateTime& targetTime) { PerceptionTimestamp* value; hrcheck(get_activation_factory<PerceptionTimestampHelper, IPerceptionTimestampHelperStatics>()->_FromHistoricalTargetTime(targetTime, &value)); return from_abi(value); }
};

template<typename X> struct statics<PerceptionTimestampHelper, X> : X, Windows::Perception::PerceptionTimestampHelper_statics<void> {
	typedef typename X::root_type PerceptionTimestampHelper;
};
struct PerceptionTimestampHelper : generate<PerceptionTimestampHelper> {};
}}
} // namespace iso_winrt
