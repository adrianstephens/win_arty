#pragma once
// generated by isopod tools
// namespaces:
// Windows.Devices.Scanners

#include "Windows.Devices.Scanners.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Graphics.Printing.0.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Foundation { namespace Collections {
template<typename T> struct IVectorView;
}}
namespace Storage { namespace Streams {
struct IRandomAccessStream;
}
struct StorageFolder;
struct StorageFile;
}}

// defs

template<> struct def<Windows::Devices::Scanners::ScannerDeviceContract> : value_type<> {};
template<> struct def<Windows::Devices::Scanners::ImageScannerFormat> : enum_type<int> {};
template<> struct def<Windows::Devices::Scanners::IImageScannerFormatConfiguration> : overridable_type<> {};
template<> struct def<Windows::Devices::Scanners::ImageScannerAutoConfiguration> : class_type<Platform::Object, Windows::Devices::Scanners::IImageScannerFormatConfiguration> {};
template<> struct def<Windows::Devices::Scanners::ImageScannerAutoCroppingMode> : enum_type<int> {};
template<> struct def<Windows::Devices::Scanners::ImageScannerColorMode> : enum_type<int> {};
template<> struct def<Windows::Devices::Scanners::ImageScannerResolution> : value_type<float, float> {};
template<> struct def<Windows::Devices::Scanners::IImageScannerSourceConfiguration> : overridable_type<Windows::Devices::Scanners::IImageScannerFormatConfiguration> {};
template<> struct def<Windows::Devices::Scanners::ImageScannerFlatbedConfiguration> : class_type<Platform::Object, Windows::Devices::Scanners::IImageScannerFormatConfiguration, Windows::Devices::Scanners::IImageScannerSourceConfiguration> {};
template<> struct def<Windows::Devices::Scanners::IImageScannerFeederConfiguration> : interface_type<Windows::Devices::Scanners::IImageScannerSourceConfiguration> {};
template<> struct def<Windows::Devices::Scanners::ImageScannerFeederConfiguration> : class_type<Platform::Object, Windows::Devices::Scanners::IImageScannerFormatConfiguration, Windows::Devices::Scanners::IImageScannerFeederConfiguration> {};
template<> struct def<Windows::Devices::Scanners::IImageScannerScanResult> : interface_type<> {};
template<> struct def<Windows::Devices::Scanners::ImageScannerScanResult> : class_type<Platform::Object, Windows::Devices::Scanners::IImageScannerScanResult> {};
template<> struct def<Windows::Devices::Scanners::IImageScannerPreviewResult> : interface_type<> {};
template<> struct def<Windows::Devices::Scanners::ImageScannerPreviewResult> : class_type<Platform::Object, Windows::Devices::Scanners::IImageScannerPreviewResult> {};
template<> struct def<Windows::Devices::Scanners::ImageScannerScanSource> : enum_type<int> {};
template<> struct def<Windows::Devices::Scanners::IImageScanner> : interface_type<> {};
template<> struct def<Windows::Devices::Scanners::IImageScannerStatics> : interface_type<> {};
template<> struct def<Windows::Devices::Scanners::ImageScanner> : class_type<Platform::Object, Windows::Devices::Scanners::IImageScanner> {};

// uuids

template<> struct uuid<Windows::Devices::Scanners::IImageScannerFormatConfiguration> { define_guid(0xAE275D11, 0xDADF, 0x4010, 0xBF, 0x10, 0xCC, 0xA5, 0xC8, 0x3D, 0xCB, 0xB0);};
template<> struct uuid<Windows::Devices::Scanners::IImageScannerSourceConfiguration> { define_guid(0xBFB50055, 0xB44, 0x4C82, 0x9E, 0x89, 0x20, 0x5F, 0x9C, 0x23, 0x4E, 0x59);};
template<> struct uuid<Windows::Devices::Scanners::IImageScannerFeederConfiguration> { define_guid(0x74BDACEE, 0xFA97, 0x4C17, 0x82, 0x80, 0x40, 0xE3, 0x9C, 0x6D, 0xCC, 0x67);};
template<> struct uuid<Windows::Devices::Scanners::IImageScannerScanResult> { define_guid(0xC91624CD, 0x9037, 0x4E48, 0x84, 0xC1, 0xAC, 0x9, 0x75, 0x7, 0x6B, 0xC5);};
template<> struct uuid<Windows::Devices::Scanners::IImageScannerPreviewResult> { define_guid(0x8B7FE8E, 0x8891, 0x441D, 0xBE, 0x9C, 0x17, 0x6F, 0xA1, 0x9, 0xC8, 0xBB);};
template<> struct uuid<Windows::Devices::Scanners::IImageScanner> { define_guid(0x53A88F78, 0x5298, 0x48A0, 0x8D, 0xA3, 0x80, 0x87, 0x51, 0x96, 0x65, 0xE0);};
template<> struct uuid<Windows::Devices::Scanners::IImageScannerStatics> { define_guid(0xBC57E70E, 0xD804, 0x4477, 0x9F, 0xB5, 0xB9, 0x11, 0xB5, 0x47, 0x38, 0x97);};

// types

namespace Windows { namespace Devices { namespace Scanners {

// IImageScannerFormatConfiguration
struct IImageScannerFormatConfiguration_raw : IInspectable {
	virtual STDMETHODIMP _get_DefaultFormat(ImageScannerFormat *value) = 0;
	virtual STDMETHODIMP _get_Format(ImageScannerFormat *value) = 0;
	virtual STDMETHODIMP _put_Format(ImageScannerFormat value) = 0;
	virtual STDMETHODIMP _IsFormatSupported(ImageScannerFormat value, bool *result) = 0;
};
template<typename X> struct IImageScannerFormatConfiguration_adaptor : X {
	union {
		struct : property {
			ImageScannerFormat get() { ImageScannerFormat value; hrcheck(enc(&IImageScannerFormatConfiguration_adaptor::DefaultFormat)->_get_DefaultFormat(&value)); return value; }
			ImageScannerFormat operator()() { return get(); }
			operator ImageScannerFormat () { return get(); }
		} DefaultFormat;
		struct : property {
			ImageScannerFormat get() { ImageScannerFormat value; hrcheck(enc(&IImageScannerFormatConfiguration_adaptor::Format)->_get_Format(&value)); return value; }
			ImageScannerFormat operator()() { return get(); }
			operator ImageScannerFormat () { return get(); }
			void put(ImageScannerFormat value) { hrcheck(enc(&IImageScannerFormatConfiguration_adaptor::Format)->_put_Format(value)); }
			void operator=(ImageScannerFormat value) { put(value); }
			void operator()(ImageScannerFormat value) { put(value); }
		} Format;
	};
	bool IsFormatSupported(ImageScannerFormat value) { bool result; hrcheck(X::get()->_IsFormatSupported(value, &result)); return result; }
	IImageScannerFormatConfiguration_adaptor() {}
};
template<typename X> struct adapt<IImageScannerFormatConfiguration, X> : Windows::Devices::Scanners::IImageScannerFormatConfiguration_adaptor<X> { typedef adapt IImageScannerFormatConfiguration; };
template<typename X> struct IImageScannerFormatConfiguration_unadaptor : X {
	STDMETHODIMP _get_DefaultFormat(ImageScannerFormat *value) { return hrtry([&, this] { get_prop(value, DefaultFormat); }); }
	STDMETHODIMP _get_Format(ImageScannerFormat *value) { return hrtry([&, this] { get_prop(value, Format); }); }
	STDMETHODIMP _put_Format(ImageScannerFormat value) { return hrtry([&, this] { put_prop(value, Format); }); }
	STDMETHODIMP _IsFormatSupported(ImageScannerFormat value, bool *result) { return hrtry([&, this] { *result = X::get()->IsFormatSupported(value); }); }
};
template<typename X> struct unadapt<IImageScannerFormatConfiguration, X> : Windows::Devices::Scanners::IImageScannerFormatConfiguration_unadaptor<X> {};
struct IImageScannerFormatConfiguration : IImageScannerFormatConfiguration_raw, generate<IImageScannerFormatConfiguration> {};

// ImageScannerAutoConfiguration
template<typename X> struct statics<ImageScannerAutoConfiguration, X> : X {
	typedef typename X::root_type ImageScannerAutoConfiguration;
};
struct ImageScannerAutoConfiguration : generate<ImageScannerAutoConfiguration> {};

// IImageScannerSourceConfiguration
struct IImageScannerSourceConfiguration_raw : IInspectable {
	virtual STDMETHODIMP _get_MinScanArea(Foundation::Size *value) = 0;
	virtual STDMETHODIMP _get_MaxScanArea(Foundation::Size *value) = 0;
	virtual STDMETHODIMP _get_SelectedScanRegion(Foundation::Rect *value) = 0;
	virtual STDMETHODIMP _put_SelectedScanRegion(Foundation::Rect value) = 0;
	virtual STDMETHODIMP _get_AutoCroppingMode(ImageScannerAutoCroppingMode *value) = 0;
	virtual STDMETHODIMP _put_AutoCroppingMode(ImageScannerAutoCroppingMode value) = 0;
	virtual STDMETHODIMP _IsAutoCroppingModeSupported(ImageScannerAutoCroppingMode value, bool *result) = 0;
	virtual STDMETHODIMP _get_MinResolution(ImageScannerResolution *value) = 0;
	virtual STDMETHODIMP _get_MaxResolution(ImageScannerResolution *value) = 0;
	virtual STDMETHODIMP _get_OpticalResolution(ImageScannerResolution *value) = 0;
	virtual STDMETHODIMP _get_DesiredResolution(ImageScannerResolution *value) = 0;
	virtual STDMETHODIMP _put_DesiredResolution(ImageScannerResolution value) = 0;
	virtual STDMETHODIMP _get_ActualResolution(ImageScannerResolution *value) = 0;
	virtual STDMETHODIMP _get_DefaultColorMode(ImageScannerColorMode *value) = 0;
	virtual STDMETHODIMP _get_ColorMode(ImageScannerColorMode *value) = 0;
	virtual STDMETHODIMP _put_ColorMode(ImageScannerColorMode value) = 0;
	virtual STDMETHODIMP _IsColorModeSupported(ImageScannerColorMode value, bool *result) = 0;
	virtual STDMETHODIMP _get_MinBrightness(int *value) = 0;
	virtual STDMETHODIMP _get_MaxBrightness(int *value) = 0;
	virtual STDMETHODIMP _get_BrightnessStep(unsigned *value) = 0;
	virtual STDMETHODIMP _get_DefaultBrightness(int *value) = 0;
	virtual STDMETHODIMP _get_Brightness(int *value) = 0;
	virtual STDMETHODIMP _put_Brightness(int value) = 0;
	virtual STDMETHODIMP _get_MinContrast(int *value) = 0;
	virtual STDMETHODIMP _get_MaxContrast(int *value) = 0;
	virtual STDMETHODIMP _get_ContrastStep(unsigned *value) = 0;
	virtual STDMETHODIMP _get_DefaultContrast(int *value) = 0;
	virtual STDMETHODIMP _get_Contrast(int *value) = 0;
	virtual STDMETHODIMP _put_Contrast(int value) = 0;
};
template<typename X> struct IImageScannerSourceConfiguration_adaptor : X {
	union {
		struct : property {
			ImageScannerResolution get() { ImageScannerResolution value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::ActualResolution)->_get_ActualResolution(&value)); return value; }
			ImageScannerResolution operator()() { return get(); }
			operator ImageScannerResolution () { return get(); }
		} ActualResolution;
		struct : property {
			ImageScannerAutoCroppingMode get() { ImageScannerAutoCroppingMode value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::AutoCroppingMode)->_get_AutoCroppingMode(&value)); return value; }
			ImageScannerAutoCroppingMode operator()() { return get(); }
			operator ImageScannerAutoCroppingMode () { return get(); }
			void put(ImageScannerAutoCroppingMode value) { hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::AutoCroppingMode)->_put_AutoCroppingMode(value)); }
			void operator=(ImageScannerAutoCroppingMode value) { put(value); }
			void operator()(ImageScannerAutoCroppingMode value) { put(value); }
		} AutoCroppingMode;
		struct : property {
			int get() { int value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::Brightness)->_get_Brightness(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
			void put(int value) { hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::Brightness)->_put_Brightness(value)); }
			void operator=(int value) { put(value); }
			void operator()(int value) { put(value); }
		} Brightness;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::BrightnessStep)->_get_BrightnessStep(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} BrightnessStep;
		struct : property {
			ImageScannerColorMode get() { ImageScannerColorMode value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::ColorMode)->_get_ColorMode(&value)); return value; }
			ImageScannerColorMode operator()() { return get(); }
			operator ImageScannerColorMode () { return get(); }
			void put(ImageScannerColorMode value) { hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::ColorMode)->_put_ColorMode(value)); }
			void operator=(ImageScannerColorMode value) { put(value); }
			void operator()(ImageScannerColorMode value) { put(value); }
		} ColorMode;
		struct : property {
			int get() { int value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::Contrast)->_get_Contrast(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
			void put(int value) { hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::Contrast)->_put_Contrast(value)); }
			void operator=(int value) { put(value); }
			void operator()(int value) { put(value); }
		} Contrast;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::ContrastStep)->_get_ContrastStep(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
		} ContrastStep;
		struct : property {
			int get() { int value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::DefaultBrightness)->_get_DefaultBrightness(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} DefaultBrightness;
		struct : property {
			ImageScannerColorMode get() { ImageScannerColorMode value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::DefaultColorMode)->_get_DefaultColorMode(&value)); return value; }
			ImageScannerColorMode operator()() { return get(); }
			operator ImageScannerColorMode () { return get(); }
		} DefaultColorMode;
		struct : property {
			int get() { int value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::DefaultContrast)->_get_DefaultContrast(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} DefaultContrast;
		struct : property {
			ImageScannerResolution get() { ImageScannerResolution value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::DesiredResolution)->_get_DesiredResolution(&value)); return value; }
			ImageScannerResolution operator()() { return get(); }
			operator ImageScannerResolution () { return get(); }
			void put(const ImageScannerResolution& value) { hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::DesiredResolution)->_put_DesiredResolution(value)); }
			void operator=(const ImageScannerResolution& value) { put(value); }
			void operator()(const ImageScannerResolution& value) { put(value); }
		} DesiredResolution;
		struct : property {
			int get() { int value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::MaxBrightness)->_get_MaxBrightness(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} MaxBrightness;
		struct : property {
			int get() { int value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::MaxContrast)->_get_MaxContrast(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} MaxContrast;
		struct : property {
			ImageScannerResolution get() { ImageScannerResolution value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::MaxResolution)->_get_MaxResolution(&value)); return value; }
			ImageScannerResolution operator()() { return get(); }
			operator ImageScannerResolution () { return get(); }
		} MaxResolution;
		struct : property {
			Foundation::Size get() { Foundation::Size value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::MaxScanArea)->_get_MaxScanArea(&value)); return value; }
			Foundation::Size operator()() { return get(); }
			operator Foundation::Size () { return get(); }
		} MaxScanArea;
		struct : property {
			int get() { int value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::MinBrightness)->_get_MinBrightness(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} MinBrightness;
		struct : property {
			int get() { int value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::MinContrast)->_get_MinContrast(&value)); return value; }
			int operator()() { return get(); }
			operator int () { return get(); }
		} MinContrast;
		struct : property {
			ImageScannerResolution get() { ImageScannerResolution value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::MinResolution)->_get_MinResolution(&value)); return value; }
			ImageScannerResolution operator()() { return get(); }
			operator ImageScannerResolution () { return get(); }
		} MinResolution;
		struct : property {
			Foundation::Size get() { Foundation::Size value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::MinScanArea)->_get_MinScanArea(&value)); return value; }
			Foundation::Size operator()() { return get(); }
			operator Foundation::Size () { return get(); }
		} MinScanArea;
		struct : property {
			ImageScannerResolution get() { ImageScannerResolution value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::OpticalResolution)->_get_OpticalResolution(&value)); return value; }
			ImageScannerResolution operator()() { return get(); }
			operator ImageScannerResolution () { return get(); }
		} OpticalResolution;
		struct : property {
			Foundation::Rect get() { Foundation::Rect value; hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::SelectedScanRegion)->_get_SelectedScanRegion(&value)); return value; }
			Foundation::Rect operator()() { return get(); }
			operator Foundation::Rect () { return get(); }
			void put(const Foundation::Rect& value) { hrcheck(enc(&IImageScannerSourceConfiguration_adaptor::SelectedScanRegion)->_put_SelectedScanRegion(value)); }
			void operator=(const Foundation::Rect& value) { put(value); }
			void operator()(const Foundation::Rect& value) { put(value); }
		} SelectedScanRegion;
	};
	bool IsAutoCroppingModeSupported(ImageScannerAutoCroppingMode value) { bool result; hrcheck(X::get()->_IsAutoCroppingModeSupported(value, &result)); return result; }
	bool IsColorModeSupported(ImageScannerColorMode value) { bool result; hrcheck(X::get()->_IsColorModeSupported(value, &result)); return result; }
	IImageScannerSourceConfiguration_adaptor() {}
};
template<typename X> struct adapt<IImageScannerSourceConfiguration, X> : Windows::Devices::Scanners::IImageScannerSourceConfiguration_adaptor<X> { typedef adapt IImageScannerSourceConfiguration; };
template<typename X> struct IImageScannerSourceConfiguration_unadaptor : X {
	STDMETHODIMP _get_MinScanArea(Foundation::Size *value) { return hrtry([&, this] { get_prop(value, MinScanArea); }); }
	STDMETHODIMP _get_MaxScanArea(Foundation::Size *value) { return hrtry([&, this] { get_prop(value, MaxScanArea); }); }
	STDMETHODIMP _get_SelectedScanRegion(Foundation::Rect *value) { return hrtry([&, this] { get_prop(value, SelectedScanRegion); }); }
	STDMETHODIMP _put_SelectedScanRegion(Foundation::Rect value) { return hrtry([&, this] { put_prop(value, SelectedScanRegion); }); }
	STDMETHODIMP _get_AutoCroppingMode(ImageScannerAutoCroppingMode *value) { return hrtry([&, this] { get_prop(value, AutoCroppingMode); }); }
	STDMETHODIMP _put_AutoCroppingMode(ImageScannerAutoCroppingMode value) { return hrtry([&, this] { put_prop(value, AutoCroppingMode); }); }
	STDMETHODIMP _IsAutoCroppingModeSupported(ImageScannerAutoCroppingMode value, bool *result) { return hrtry([&, this] { *result = X::get()->IsAutoCroppingModeSupported(value); }); }
	STDMETHODIMP _get_MinResolution(ImageScannerResolution *value) { return hrtry([&, this] { get_prop(value, MinResolution); }); }
	STDMETHODIMP _get_MaxResolution(ImageScannerResolution *value) { return hrtry([&, this] { get_prop(value, MaxResolution); }); }
	STDMETHODIMP _get_OpticalResolution(ImageScannerResolution *value) { return hrtry([&, this] { get_prop(value, OpticalResolution); }); }
	STDMETHODIMP _get_DesiredResolution(ImageScannerResolution *value) { return hrtry([&, this] { get_prop(value, DesiredResolution); }); }
	STDMETHODIMP _put_DesiredResolution(ImageScannerResolution value) { return hrtry([&, this] { put_prop(value, DesiredResolution); }); }
	STDMETHODIMP _get_ActualResolution(ImageScannerResolution *value) { return hrtry([&, this] { get_prop(value, ActualResolution); }); }
	STDMETHODIMP _get_DefaultColorMode(ImageScannerColorMode *value) { return hrtry([&, this] { get_prop(value, DefaultColorMode); }); }
	STDMETHODIMP _get_ColorMode(ImageScannerColorMode *value) { return hrtry([&, this] { get_prop(value, ColorMode); }); }
	STDMETHODIMP _put_ColorMode(ImageScannerColorMode value) { return hrtry([&, this] { put_prop(value, ColorMode); }); }
	STDMETHODIMP _IsColorModeSupported(ImageScannerColorMode value, bool *result) { return hrtry([&, this] { *result = X::get()->IsColorModeSupported(value); }); }
	STDMETHODIMP _get_MinBrightness(int *value) { return hrtry([&, this] { get_prop(value, MinBrightness); }); }
	STDMETHODIMP _get_MaxBrightness(int *value) { return hrtry([&, this] { get_prop(value, MaxBrightness); }); }
	STDMETHODIMP _get_BrightnessStep(unsigned *value) { return hrtry([&, this] { get_prop(value, BrightnessStep); }); }
	STDMETHODIMP _get_DefaultBrightness(int *value) { return hrtry([&, this] { get_prop(value, DefaultBrightness); }); }
	STDMETHODIMP _get_Brightness(int *value) { return hrtry([&, this] { get_prop(value, Brightness); }); }
	STDMETHODIMP _put_Brightness(int value) { return hrtry([&, this] { put_prop(value, Brightness); }); }
	STDMETHODIMP _get_MinContrast(int *value) { return hrtry([&, this] { get_prop(value, MinContrast); }); }
	STDMETHODIMP _get_MaxContrast(int *value) { return hrtry([&, this] { get_prop(value, MaxContrast); }); }
	STDMETHODIMP _get_ContrastStep(unsigned *value) { return hrtry([&, this] { get_prop(value, ContrastStep); }); }
	STDMETHODIMP _get_DefaultContrast(int *value) { return hrtry([&, this] { get_prop(value, DefaultContrast); }); }
	STDMETHODIMP _get_Contrast(int *value) { return hrtry([&, this] { get_prop(value, Contrast); }); }
	STDMETHODIMP _put_Contrast(int value) { return hrtry([&, this] { put_prop(value, Contrast); }); }
};
template<typename X> struct unadapt<IImageScannerSourceConfiguration, X> : Windows::Devices::Scanners::IImageScannerSourceConfiguration_unadaptor<X> {};
struct IImageScannerSourceConfiguration : IImageScannerSourceConfiguration_raw, generate<IImageScannerSourceConfiguration> {};

// ImageScannerFlatbedConfiguration
template<typename X> struct statics<ImageScannerFlatbedConfiguration, X> : X {
	typedef typename X::root_type ImageScannerFlatbedConfiguration;
};
struct ImageScannerFlatbedConfiguration : generate<ImageScannerFlatbedConfiguration> {};

// IImageScannerFeederConfiguration
struct IImageScannerFeederConfiguration_raw : IInspectable {
	virtual STDMETHODIMP _get_CanAutoDetectPageSize(bool *value);
	virtual STDMETHODIMP _get_AutoDetectPageSize(bool *value);
	virtual STDMETHODIMP _put_AutoDetectPageSize(bool value);
	virtual STDMETHODIMP _get_PageSize(Graphics::Printing::PrintMediaSize *value);
	virtual STDMETHODIMP _put_PageSize(Graphics::Printing::PrintMediaSize value);
	virtual STDMETHODIMP _get_PageOrientation(Graphics::Printing::PrintOrientation *value);
	virtual STDMETHODIMP _put_PageOrientation(Graphics::Printing::PrintOrientation value);
	virtual STDMETHODIMP _get_PageSizeDimensions(Foundation::Size *value);
	virtual STDMETHODIMP _IsPageSizeSupported(Graphics::Printing::PrintMediaSize pageSize, Graphics::Printing::PrintOrientation pageOrientation, bool *result);
	virtual STDMETHODIMP _get_MaxNumberOfPages(unsigned *value);
	virtual STDMETHODIMP _put_MaxNumberOfPages(unsigned value);
	virtual STDMETHODIMP _get_CanScanDuplex(bool *value);
	virtual STDMETHODIMP _get_Duplex(bool *value);
	virtual STDMETHODIMP _put_Duplex(bool value);
	virtual STDMETHODIMP _get_CanScanAhead(bool *value);
	virtual STDMETHODIMP _get_ScanAhead(bool *value);
	virtual STDMETHODIMP _put_ScanAhead(bool value);
};
template<typename X> struct IImageScannerFeederConfiguration_adaptor : X {
	union {
		struct : property {
			bool get() { bool value; hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::AutoDetectPageSize)->_get_AutoDetectPageSize(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::AutoDetectPageSize)->_put_AutoDetectPageSize(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} AutoDetectPageSize;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::CanAutoDetectPageSize)->_get_CanAutoDetectPageSize(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} CanAutoDetectPageSize;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::CanScanAhead)->_get_CanScanAhead(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} CanScanAhead;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::CanScanDuplex)->_get_CanScanDuplex(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} CanScanDuplex;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::Duplex)->_get_Duplex(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::Duplex)->_put_Duplex(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} Duplex;
		struct : property {
			unsigned get() { unsigned value; hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::MaxNumberOfPages)->_get_MaxNumberOfPages(&value)); return value; }
			unsigned operator()() { return get(); }
			operator unsigned () { return get(); }
			void put(unsigned value) { hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::MaxNumberOfPages)->_put_MaxNumberOfPages(value)); }
			void operator=(unsigned value) { put(value); }
			void operator()(unsigned value) { put(value); }
		} MaxNumberOfPages;
		struct : property {
			Graphics::Printing::PrintOrientation get() { Graphics::Printing::PrintOrientation value; hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::PageOrientation)->_get_PageOrientation(&value)); return value; }
			Graphics::Printing::PrintOrientation operator()() { return get(); }
			operator Graphics::Printing::PrintOrientation () { return get(); }
			void put(Graphics::Printing::PrintOrientation value) { hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::PageOrientation)->_put_PageOrientation(value)); }
			void operator=(Graphics::Printing::PrintOrientation value) { put(value); }
			void operator()(Graphics::Printing::PrintOrientation value) { put(value); }
		} PageOrientation;
		struct : property {
			Graphics::Printing::PrintMediaSize get() { Graphics::Printing::PrintMediaSize value; hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::PageSize)->_get_PageSize(&value)); return value; }
			Graphics::Printing::PrintMediaSize operator()() { return get(); }
			operator Graphics::Printing::PrintMediaSize () { return get(); }
			void put(Graphics::Printing::PrintMediaSize value) { hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::PageSize)->_put_PageSize(value)); }
			void operator=(Graphics::Printing::PrintMediaSize value) { put(value); }
			void operator()(Graphics::Printing::PrintMediaSize value) { put(value); }
		} PageSize;
		struct : property {
			Foundation::Size get() { Foundation::Size value; hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::PageSizeDimensions)->_get_PageSizeDimensions(&value)); return value; }
			Foundation::Size operator()() { return get(); }
			operator Foundation::Size () { return get(); }
		} PageSizeDimensions;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::ScanAhead)->_get_ScanAhead(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
			void put(bool value) { hrcheck(enc(&IImageScannerFeederConfiguration_adaptor::ScanAhead)->_put_ScanAhead(value)); }
			void operator=(bool value) { put(value); }
			void operator()(bool value) { put(value); }
		} ScanAhead;
	};
	bool IsPageSizeSupported(Graphics::Printing::PrintMediaSize pageSize, Graphics::Printing::PrintOrientation pageOrientation) { bool result; hrcheck(X::get()->_IsPageSizeSupported(pageSize, pageOrientation, &result)); return result; }
	IImageScannerFeederConfiguration_adaptor() {}
};
template<typename X> struct adapt<IImageScannerFeederConfiguration, X> : Windows::Devices::Scanners::IImageScannerFeederConfiguration_adaptor<X> { typedef adapt IImageScannerFeederConfiguration; };
struct IImageScannerFeederConfiguration : IImageScannerFeederConfiguration_raw, generate<IImageScannerFeederConfiguration> {};

// ImageScannerFeederConfiguration
template<typename X> struct statics<ImageScannerFeederConfiguration, X> : X {
	typedef typename X::root_type ImageScannerFeederConfiguration;
};
struct ImageScannerFeederConfiguration : generate<ImageScannerFeederConfiguration> {};

// IImageScannerScanResult
struct IImageScannerScanResult_raw : IInspectable {
	virtual STDMETHODIMP _get_ScannedFiles(Foundation::Collections::IVectorView<Storage::StorageFile*>* *value);
};
template<typename X> struct IImageScannerScanResult_adaptor : X {
	union {
		struct : property {
			ptr<Foundation::Collections::IVectorView<ptr<Storage::StorageFile>>> get() { Foundation::Collections::IVectorView<Storage::StorageFile*>* value; hrcheck(enc(&IImageScannerScanResult_adaptor::ScannedFiles)->_get_ScannedFiles(&value)); return from_abi(value); }
			ptr<Foundation::Collections::IVectorView<ptr<Storage::StorageFile>>> operator()() { return get(); }
			operator ptr<Foundation::Collections::IVectorView<ptr<Storage::StorageFile>>> () { return get(); }
			ptr<Foundation::Collections::IVectorView<ptr<Storage::StorageFile>>> operator->() { return get(); }
		} ScannedFiles;
	};
	IImageScannerScanResult_adaptor() {}
};
template<typename X> struct adapt<IImageScannerScanResult, X> : Windows::Devices::Scanners::IImageScannerScanResult_adaptor<X> { typedef adapt IImageScannerScanResult; };
struct IImageScannerScanResult : IImageScannerScanResult_raw, generate<IImageScannerScanResult> {};

// ImageScannerScanResult
template<typename X> struct statics<ImageScannerScanResult, X> : X {
	typedef typename X::root_type ImageScannerScanResult;
};
struct ImageScannerScanResult : generate<ImageScannerScanResult> {};

// IImageScannerPreviewResult
struct IImageScannerPreviewResult_raw : IInspectable {
	virtual STDMETHODIMP _get_Succeeded(bool *value);
	virtual STDMETHODIMP _get_Format(ImageScannerFormat *value);
};
template<typename X> struct IImageScannerPreviewResult_adaptor : X {
	union {
		struct : property {
			ImageScannerFormat get() { ImageScannerFormat value; hrcheck(enc(&IImageScannerPreviewResult_adaptor::Format)->_get_Format(&value)); return value; }
			ImageScannerFormat operator()() { return get(); }
			operator ImageScannerFormat () { return get(); }
		} Format;
		struct : property {
			bool get() { bool value; hrcheck(enc(&IImageScannerPreviewResult_adaptor::Succeeded)->_get_Succeeded(&value)); return value; }
			bool operator()() { return get(); }
			operator bool () { return get(); }
		} Succeeded;
	};
	IImageScannerPreviewResult_adaptor() {}
};
template<typename X> struct adapt<IImageScannerPreviewResult, X> : Windows::Devices::Scanners::IImageScannerPreviewResult_adaptor<X> { typedef adapt IImageScannerPreviewResult; };
struct IImageScannerPreviewResult : IImageScannerPreviewResult_raw, generate<IImageScannerPreviewResult> {};

// ImageScannerPreviewResult
template<typename X> struct statics<ImageScannerPreviewResult, X> : X {
	typedef typename X::root_type ImageScannerPreviewResult;
};
struct ImageScannerPreviewResult : generate<ImageScannerPreviewResult> {};

// IImageScanner
struct IImageScanner_raw : IInspectable {
	virtual STDMETHODIMP _get_DeviceId(HSTRING *value);
	virtual STDMETHODIMP _get_DefaultScanSource(ImageScannerScanSource *value);
	virtual STDMETHODIMP _IsScanSourceSupported(ImageScannerScanSource value, bool *result);
	virtual STDMETHODIMP _get_FlatbedConfiguration(ImageScannerFlatbedConfiguration* *value);
	virtual STDMETHODIMP _get_FeederConfiguration(ImageScannerFeederConfiguration* *value);
	virtual STDMETHODIMP _get_AutoConfiguration(ImageScannerAutoConfiguration* *value);
	virtual STDMETHODIMP _IsPreviewSupported(ImageScannerScanSource scanSource, bool *result);
	virtual STDMETHODIMP _ScanPreviewToStreamAsync(ImageScannerScanSource scanSource, Storage::Streams::IRandomAccessStream* targetStream, Foundation::IAsyncOperation<ImageScannerPreviewResult*>* *operation);
	virtual STDMETHODIMP _ScanFilesToFolderAsync(ImageScannerScanSource scanSource, Storage::StorageFolder* storageFolder, Foundation::IAsyncOperationWithProgress<ImageScannerScanResult*, unsigned>* *operation);
};
template<typename X> struct IImageScanner_adaptor : X {
	union {
		struct : property {
			ptr<ImageScannerAutoConfiguration> get() { ImageScannerAutoConfiguration* value; hrcheck(enc(&IImageScanner_adaptor::AutoConfiguration)->_get_AutoConfiguration(&value)); return from_abi(value); }
			ptr<ImageScannerAutoConfiguration> operator()() { return get(); }
			operator ptr<ImageScannerAutoConfiguration> () { return get(); }
			ptr<ImageScannerAutoConfiguration> operator->() { return get(); }
		} AutoConfiguration;
		struct : property {
			ImageScannerScanSource get() { ImageScannerScanSource value; hrcheck(enc(&IImageScanner_adaptor::DefaultScanSource)->_get_DefaultScanSource(&value)); return value; }
			ImageScannerScanSource operator()() { return get(); }
			operator ImageScannerScanSource () { return get(); }
		} DefaultScanSource;
		struct : property {
			hstring get() { HSTRING value; hrcheck(enc(&IImageScanner_adaptor::DeviceId)->_get_DeviceId(&value)); return from_abi(value); }
			hstring operator()() { return get(); }
			operator hstring_ref () { return get(); }
		} DeviceId;
		struct : property {
			ptr<ImageScannerFeederConfiguration> get() { ImageScannerFeederConfiguration* value; hrcheck(enc(&IImageScanner_adaptor::FeederConfiguration)->_get_FeederConfiguration(&value)); return from_abi(value); }
			ptr<ImageScannerFeederConfiguration> operator()() { return get(); }
			operator ptr<ImageScannerFeederConfiguration> () { return get(); }
			ptr<ImageScannerFeederConfiguration> operator->() { return get(); }
		} FeederConfiguration;
		struct : property {
			ptr<ImageScannerFlatbedConfiguration> get() { ImageScannerFlatbedConfiguration* value; hrcheck(enc(&IImageScanner_adaptor::FlatbedConfiguration)->_get_FlatbedConfiguration(&value)); return from_abi(value); }
			ptr<ImageScannerFlatbedConfiguration> operator()() { return get(); }
			operator ptr<ImageScannerFlatbedConfiguration> () { return get(); }
			ptr<ImageScannerFlatbedConfiguration> operator->() { return get(); }
		} FlatbedConfiguration;
	};
	bool IsScanSourceSupported(ImageScannerScanSource value) { bool result; hrcheck(X::get()->_IsScanSourceSupported(value, &result)); return result; }
	bool IsPreviewSupported(ImageScannerScanSource scanSource) { bool result; hrcheck(X::get()->_IsPreviewSupported(scanSource, &result)); return result; }
	ptr<Foundation::IAsyncOperation<ptr<ImageScannerPreviewResult>>> ScanPreviewToStreamAsync(ImageScannerScanSource scanSource, pptr<Storage::Streams::IRandomAccessStream> targetStream) { Foundation::IAsyncOperation<ImageScannerPreviewResult*>* operation; hrcheck(X::get()->_ScanPreviewToStreamAsync(scanSource, targetStream, &operation)); return from_abi(operation); }
	ptr<Foundation::IAsyncOperationWithProgress<ptr<ImageScannerScanResult>, unsigned>> ScanFilesToFolderAsync(ImageScannerScanSource scanSource, pptr<Storage::StorageFolder> storageFolder) { Foundation::IAsyncOperationWithProgress<ImageScannerScanResult*, unsigned>* operation; hrcheck(X::get()->_ScanFilesToFolderAsync(scanSource, storageFolder, &operation)); return from_abi(operation); }
	IImageScanner_adaptor() {}
};
template<typename X> struct adapt<IImageScanner, X> : Windows::Devices::Scanners::IImageScanner_adaptor<X> { typedef adapt IImageScanner; };
struct IImageScanner : IImageScanner_raw, generate<IImageScanner> {};

// IImageScannerStatics
struct IImageScannerStatics : IInspectable {
	virtual STDMETHODIMP _FromIdAsync(HSTRING deviceId, Foundation::IAsyncOperation<ImageScanner*>* *asyncInfo);
	virtual STDMETHODIMP _GetDeviceSelector(HSTRING *selector);
};

// ImageScanner
template<typename> struct ImageScanner_statics {
	static ptr<Foundation::IAsyncOperation<ptr<ImageScanner>>> FromIdAsync(hstring_ref deviceId) { Foundation::IAsyncOperation<ImageScanner*>* asyncInfo; hrcheck(get_activation_factory<ImageScanner, IImageScannerStatics>()->_FromIdAsync(deviceId, &asyncInfo)); return from_abi(asyncInfo); }
	static hstring GetDeviceSelector() { HSTRING selector; hrcheck(get_activation_factory<ImageScanner, IImageScannerStatics>()->_GetDeviceSelector(&selector)); return from_abi(selector); }
};

template<typename X> struct statics<ImageScanner, X> : X, Windows::Devices::Scanners::ImageScanner_statics<void> {
	typedef typename X::root_type ImageScanner;
};
struct ImageScanner : generate<ImageScanner> {};
}}}
} // namespace iso_winrt