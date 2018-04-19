#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Graphics { namespace Display {
enum class DisplayOrientations : unsigned {
	None = 0x0,
	Landscape = 0x1,
	Portrait = 0x2,
	LandscapeFlipped = 0x4,
	PortraitFlipped = 0x8,
};
struct IDisplayInformationStatics;
enum class ResolutionScale : int {
	Invalid = 0,
	Scale100Percent = 100,
	Scale120Percent = 120,
	Scale125Percent = 125,
	Scale140Percent = 140,
	Scale150Percent = 150,
	Scale160Percent = 160,
	Scale175Percent = 175,
	Scale180Percent = 180,
	Scale200Percent = 200,
	Scale225Percent = 225,
	Scale250Percent = 250,
	Scale300Percent = 300,
	Scale350Percent = 350,
	Scale400Percent = 400,
	Scale450Percent = 450,
	Scale500Percent = 500,
};
struct IDisplayInformation5;
struct IDisplayInformation4;
struct IDisplayInformation3;
struct IDisplayInformation;
struct IDisplayInformation2;
struct DisplayInformation;
enum class AdvancedColorKind : int {
	StandardDynamicRange = 0,
	WideColorGamut = 1,
	HighDynamicRange = 2,
};
enum class HdrMetadataFormat : int {
	Hdr10 = 0,
	Hdr10Plus = 1,
};
struct IAdvancedColorInfo;
struct AdvancedColorInfo;
struct DisplayPropertiesEventHandler;
struct IDisplayPropertiesStatics;
struct DisplayProperties;
enum class DisplayBrightnessScenario : int {
	DefaultBrightness = 0,
	IdleBrightness = 1,
	BarcodeReadingBrightness = 2,
	FullBrightness = 3,
};
enum class DisplayBrightnessOverrideOptions : unsigned {
	None = 0x0,
	UseDimmedPolicyWhenBatteryIsLow = 0x1,
};
struct IBrightnessOverrideStatics;
struct IBrightnessOverride;
struct BrightnessOverride;
struct NitRange {
	float MinNits;
	float MaxNits;
	float StepSizeNits;
};
enum class DisplayColorOverrideScenario : int {
	Accurate = 0,
};
enum class DisplayBrightnessOverrideScenario : int {
	IdleBrightness = 0,
	BarcodeReadingBrightness = 1,
	FullBrightness = 2,
};
struct IBrightnessOverrideSettingsStatics;
struct IBrightnessOverrideSettings;
struct BrightnessOverrideSettings;
struct IColorOverrideSettingsStatics;
struct IColorOverrideSettings;
struct ColorOverrideSettings;
struct IDisplayEnhancementOverrideCapabilitiesChangedEventArgs;
struct IDisplayEnhancementOverrideCapabilities;
struct DisplayEnhancementOverrideCapabilities;
struct DisplayEnhancementOverrideCapabilitiesChangedEventArgs;
struct IDisplayEnhancementOverrideStatics;
struct IDisplayEnhancementOverride;
struct DisplayEnhancementOverride;
}}}
} // namespace iso_winrt
