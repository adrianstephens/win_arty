#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Storage { namespace Pickers { namespace Provider {
struct IFileRemovedEventArgs;
struct FileRemovedEventArgs;
enum class AddFileResult : int {
	Added = 0,
	AlreadyAdded = 1,
	NotAllowed = 2,
	Unavailable = 3,
};
enum class FileSelectionMode : int {
	Single = 0,
	Multiple = 1,
};
struct IFileOpenPickerUI;
struct FileOpenPickerUI;
struct IPickerClosingEventArgs;
struct PickerClosingEventArgs;
struct IPickerClosingOperation;
struct PickerClosingOperation;
struct IPickerClosingDeferral;
struct PickerClosingDeferral;
enum class SetFileNameResult : int {
	Succeeded = 0,
	NotAllowed = 1,
	Unavailable = 2,
};
struct IFileSavePickerUI;
struct FileSavePickerUI;
struct ITargetFileRequestedEventArgs;
struct TargetFileRequestedEventArgs;
struct ITargetFileRequest;
struct TargetFileRequest;
struct ITargetFileRequestDeferral;
struct TargetFileRequestDeferral;
}}}}
} // namespace iso_winrt
