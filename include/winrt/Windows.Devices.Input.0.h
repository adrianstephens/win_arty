#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Input {
enum class PointerDeviceType : int {
	Touch = 0,
	Pen = 1,
	Mouse = 2,
};
struct PointerDeviceUsage {
	unsigned UsagePage;
	unsigned Usage;
	int MinLogical;
	int MaxLogical;
	int MinPhysical;
	int MaxPhysical;
	unsigned Unit;
	float PhysicalMultiplier;
};
struct MouseDelta {
	int X;
	int Y;
};
struct IMouseCapabilities;
struct IKeyboardCapabilities;
struct ITouchCapabilities;
struct IPointerDeviceStatics;
struct IPointerDevice2;
struct IPointerDevice;
struct PointerDevice;
struct IMouseEventArgs;
struct IMouseDevice;
struct IMouseDeviceStatics;
struct MouseDevice;
struct MouseEventArgs;
struct MouseCapabilities;
struct KeyboardCapabilities;
struct TouchCapabilities;
}}}
} // namespace iso_winrt
