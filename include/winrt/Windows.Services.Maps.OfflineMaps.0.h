#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Services { namespace Maps { namespace OfflineMaps {
enum class OfflineMapPackageQueryStatus : int {
	Success = 0,
	UnknownError = 1,
	InvalidCredentials = 2,
	NetworkFailure = 3,
};
enum class OfflineMapPackageStatus : int {
	NotDownloaded = 0,
	Downloading = 1,
	Downloaded = 2,
	Deleting = 3,
};
enum class OfflineMapPackageStartDownloadStatus : int {
	Success = 0,
	UnknownError = 1,
	InvalidCredentials = 2,
	DeniedWithoutCapability = 3,
};
struct IOfflineMapPackageQueryResult;
struct IOfflineMapPackageStatics;
struct IOfflineMapPackage;
struct OfflineMapPackage;
struct IOfflineMapPackageStartDownloadResult;
struct OfflineMapPackageStartDownloadResult;
struct OfflineMapPackageQueryResult;
}}}}
} // namespace iso_winrt
