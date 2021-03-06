#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Gpio { namespace Provider {
enum class ProviderGpioSharingMode : int {
	Exclusive = 0,
	SharedReadOnly = 1,
};
enum class ProviderGpioPinDriveMode : int {
	Input = 0,
	Output = 1,
	InputPullUp = 2,
	InputPullDown = 3,
	OutputOpenDrain = 4,
	OutputOpenDrainPullUp = 5,
	OutputOpenSource = 6,
	OutputOpenSourcePullDown = 7,
};
enum class ProviderGpioPinValue : int {
	Low = 0,
	High = 1,
};
enum class ProviderGpioPinEdge : int {
	FallingEdge = 0,
	RisingEdge = 1,
};
struct IGpioPinProviderValueChangedEventArgsFactory;
struct IGpioPinProviderValueChangedEventArgs;
struct GpioPinProviderValueChangedEventArgs;
struct IGpioPinProvider;
struct IGpioControllerProvider;
struct IGpioProvider;
}}}}
} // namespace iso_winrt
