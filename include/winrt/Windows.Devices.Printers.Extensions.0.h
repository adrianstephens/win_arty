#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Devices { namespace Printers { namespace Extensions {
struct ExtensionsContract {};
struct IPrintTaskConfigurationSaveRequestedDeferral;
struct PrintTaskConfigurationSaveRequestedDeferral;
struct IPrintTaskConfigurationSaveRequest;
struct PrintTaskConfigurationSaveRequest;
struct IPrintTaskConfigurationSaveRequestedEventArgs;
struct PrintTaskConfigurationSaveRequestedEventArgs;
struct IPrintTaskConfiguration;
struct PrintTaskConfiguration;
struct IPrintNotificationEventDetails;
struct PrintNotificationEventDetails;
struct IPrintExtensionContextStatic;
struct PrintExtensionContext;
enum class Print3DWorkflowStatus : int {
	Abandoned = 0,
	Canceled = 1,
	Failed = 2,
	Slicing = 3,
	Submitted = 4,
};
enum class Print3DWorkflowDetail : int {
	Unknown = 0,
	ModelExceedsPrintBed = 1,
	UploadFailed = 2,
	InvalidMaterialSelection = 3,
	InvalidModel = 4,
	ModelNotManifold = 5,
	InvalidPrintTicket = 6,
};
struct IPrint3DWorkflowPrintRequestedEventArgs;
struct IPrint3DWorkflowPrinterChangedEventArgs;
struct Print3DWorkflowPrintRequestedEventArgs;
struct Print3DWorkflowPrinterChangedEventArgs;
struct IPrint3DWorkflow;
struct IPrint3DWorkflow2;
struct Print3DWorkflow;
}}}}
} // namespace iso_winrt
