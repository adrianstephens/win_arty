#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace UI { namespace Input { namespace Preview { namespace Injection {
enum class InjectedInputTouchParameters : unsigned {
	None = 0x0,
	Contact = 0x1,
	Orientation = 0x2,
	Pressure = 0x4,
};
enum class InjectedInputPointerOptions : unsigned {
	None = 0x0,
	New = 0x1,
	InRange = 0x2,
	InContact = 0x4,
	FirstButton = 0x10,
	SecondButton = 0x20,
	Primary = 0x2000,
	Confidence = 0x4000,
	Canceled = 0x8000,
	PointerDown = 0x10000,
	Update = 0x20000,
	PointerUp = 0x40000,
	CaptureChanged = 0x200000,
};
enum class InjectedInputButtonChangeKind : int {
	None = 0,
	FirstButtonDown = 1,
	FirstButtonUp = 2,
	SecondButtonDown = 3,
	SecondButtonUp = 4,
	ThirdButtonDown = 5,
	ThirdButtonUp = 6,
	FourthButtonDown = 7,
	FourthButtonUp = 8,
	FifthButtonDown = 9,
	FifthButtonUp = 10,
};
enum class InjectedInputPenButtons : unsigned {
	None = 0x0,
	Barrel = 0x1,
	Inverted = 0x2,
	Eraser = 0x4,
};
enum class InjectedInputPenParameters : unsigned {
	None = 0x0,
	Pressure = 0x1,
	Rotation = 0x2,
	TiltX = 0x4,
	TiltY = 0x8,
};
enum class InjectedInputMouseOptions : unsigned {
	None = 0x0,
	Move = 0x1,
	LeftDown = 0x2,
	LeftUp = 0x4,
	RightDown = 0x8,
	RightUp = 0x10,
	MiddleDown = 0x20,
	MiddleUp = 0x40,
	XDown = 0x80,
	XUp = 0x100,
	Wheel = 0x800,
	HWheel = 0x1000,
	MoveNoCoalesce = 0x2000,
	VirtualDesk = 0x4000,
	Absolute = 0x8000,
};
enum class InjectedInputKeyOptions : unsigned {
	None = 0x0,
	ExtendedKey = 0x1,
	KeyUp = 0x2,
	ScanCode = 0x8,
	Unicode = 0x4,
};
enum class InjectedInputShortcut : int {
	Back = 0,
	Start = 1,
	Search = 2,
};
enum class InjectedInputVisualizationMode : int {
	None = 0,
	Default = 1,
	Indirect = 2,
};
struct InjectedInputRectangle {
	int Left;
	int Top;
	int Bottom;
	int Right;
};
struct InjectedInputPoint {
	int PositionX;
	int PositionY;
};
struct InjectedInputPointerInfo {
	unsigned PointerId;
	InjectedInputPointerOptions PointerOptions;
	InjectedInputPoint PixelLocation;
	unsigned TimeOffsetInMilliseconds;
	unsigned __int64 PerformanceCount;
};
struct IInjectedInputTouchInfo;
struct IInjectedInputPenInfo;
struct IInjectedInputMouseInfo;
struct IInjectedInputKeyboardInfo;
struct IInjectedInputGamepadInfo;
struct IInjectedInputGamepadInfoFactory;
struct InjectedInputGamepadInfo;
struct IInputInjector;
struct InjectedInputKeyboardInfo;
struct InjectedInputMouseInfo;
struct InjectedInputTouchInfo;
struct InjectedInputPenInfo;
struct IInputInjector2;
struct IInputInjectorStatics;
struct IInputInjectorStatics2;
struct InputInjector;
}}}}}
} // namespace iso_winrt
