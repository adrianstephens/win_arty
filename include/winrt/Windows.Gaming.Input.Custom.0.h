#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Gaming { namespace Input { namespace Custom {
enum class GipFirmwareUpdateStatus : int {
	Completed = 0,
	UpToDate = 1,
	Failed = 2,
};
enum class GipMessageClass : int {
	Command = 0,
	LowLatency = 1,
	StandardLatency = 2,
};
enum class XusbDeviceType : int {
	Unknown = 0,
	Gamepad = 1,
};
enum class XusbDeviceSubtype : int {
	Unknown = 0,
	Gamepad = 1,
	ArcadePad = 2,
	ArcadeStick = 3,
	FlightStick = 4,
	Wheel = 5,
	Guitar = 6,
	GuitarAlternate = 7,
	GuitarBass = 8,
	DrumKit = 9,
	DancePad = 10,
};
struct GameControllerVersionInfo {
	unsigned short Major;
	unsigned short Minor;
	unsigned short Build;
	unsigned short Revision;
};
struct GipFirmwareUpdateProgress {
	double PercentCompleted;
	unsigned CurrentComponentId;
};
struct IGameControllerInputSink;
struct IGipGameControllerInputSink;
struct IHidGameControllerInputSink;
struct IXusbGameControllerInputSink;
struct IGipFirmwareUpdateResult;
struct IGameControllerProvider;
struct IGipGameControllerProvider;
struct GipFirmwareUpdateResult;
struct IHidGameControllerProvider;
struct IXusbGameControllerProvider;
struct ICustomGameControllerFactory;
struct IGameControllerFactoryManagerStatics;
struct IGameControllerFactoryManagerStatics2;
struct GipGameControllerProvider;
struct HidGameControllerProvider;
struct XusbGameControllerProvider;
struct GameControllerFactoryManager;
}}}}
} // namespace iso_winrt
