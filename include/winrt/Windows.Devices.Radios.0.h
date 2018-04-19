#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Radios {
enum class RadioKind : int {
	Other = 0,
	WiFi = 1,
	MobileBroadband = 2,
	Bluetooth = 3,
	FM = 4,
};
enum class RadioAccessStatus : int {
	Unspecified = 0,
	Allowed = 1,
	DeniedByUser = 2,
	DeniedBySystem = 3,
};
struct IRadioStatics;
enum class RadioState : int {
	Unknown = 0,
	On = 1,
	Off = 2,
	Disabled = 3,
};
struct IRadio;
struct Radio;
}}}
} // namespace iso_winrt
