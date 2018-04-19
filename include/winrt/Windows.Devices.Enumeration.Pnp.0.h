#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Enumeration { namespace Pnp {
enum class PnpObjectType : int {
	Unknown = 0,
	DeviceInterface = 1,
	DeviceContainer = 2,
	Device = 3,
	DeviceInterfaceClass = 4,
	AssociationEndpoint = 5,
	AssociationEndpointContainer = 6,
	AssociationEndpointService = 7,
};
struct IPnpObjectUpdate;
struct PnpObjectUpdate;
struct IPnpObjectStatics;
struct IPnpObject;
struct PnpObject;
struct PnpObjectCollection;
struct IPnpObjectWatcher;
struct PnpObjectWatcher;
}}}}
} // namespace iso_winrt
