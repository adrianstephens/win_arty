#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace I2c {
enum class I2cBusSpeed : int {
	StandardMode = 0,
	FastMode = 1,
};
enum class I2cTransferStatus : int {
	FullTransfer = 0,
	PartialTransfer = 1,
	SlaveAddressNotAcknowledged = 2,
	ClockStretchTimeout = 3,
	UnknownError = 4,
};
enum class I2cSharingMode : int {
	Exclusive = 0,
	Shared = 1,
};
struct I2cTransferResult {
	I2cTransferStatus Status;
	unsigned BytesTransferred;
};
struct II2cConnectionSettingsFactory;
struct II2cConnectionSettings;
struct I2cConnectionSettings;
struct II2cDeviceStatics;
struct II2cDevice;
struct I2cDevice;
struct II2cController;
struct II2cControllerStatics;
struct I2cController;
}}}
} // namespace iso_winrt