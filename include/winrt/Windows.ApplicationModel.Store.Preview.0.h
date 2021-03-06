#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace ApplicationModel { namespace Store { namespace Preview {
enum class StorePreviewProductPurchaseStatus : int {
	Succeeded = 0,
	AlreadyPurchased = 1,
	NotFulfilled = 2,
	NotPurchased = 3,
};
enum class StoreSystemFeature : int {
	ArchitectureX86 = 0,
	ArchitectureX64 = 1,
	ArchitectureArm = 2,
	DirectX9 = 3,
	DirectX10 = 4,
	DirectX11 = 5,
	D3D12HardwareFL11 = 6,
	D3D12HardwareFL12 = 7,
	Memory300MB = 8,
	Memory750MB = 9,
	Memory1GB = 10,
	Memory2GB = 11,
	CameraFront = 12,
	CameraRear = 13,
	Gyroscope = 14,
	Hover = 15,
	Magnetometer = 16,
	Nfc = 17,
	Resolution720P = 18,
	ResolutionWvga = 19,
	ResolutionWvgaOr720P = 20,
	ResolutionWxga = 21,
	ResolutionWvgaOrWxga = 22,
	ResolutionWxgaOr720P = 23,
	Memory4GB = 24,
	Memory6GB = 25,
	Memory8GB = 26,
	Memory12GB = 27,
	Memory16GB = 28,
	Memory20GB = 29,
	VideoMemory2GB = 30,
	VideoMemory4GB = 31,
	VideoMemory6GB = 32,
	VideoMemory1GB = 33,
	ArchitectureArm64 = 34,
};
enum class StoreLogOptions : unsigned {
	None = 0x0,
	TryElevate = 0x1,
};
struct IStorePreviewProductInfo;
struct IStorePreviewSkuInfo;
struct StorePreviewSkuInfo;
struct IStorePreviewPurchaseResults;
struct IStorePreview;
struct StorePreviewPurchaseResults;
struct StorePreviewProductInfo;
struct IStoreHardwareManufacturerInfo;
struct IStoreConfigurationStatics;
struct StoreHardwareManufacturerInfo;
struct IStoreConfigurationStatics2;
struct IStoreConfigurationStatics3;
struct IStoreConfigurationStatics4;
struct IWebAuthenticationCoreManagerHelper;
struct StorePreview;
struct StoreConfiguration;
struct WebAuthenticationCoreManagerHelper;
}}}}
} // namespace iso_winrt
