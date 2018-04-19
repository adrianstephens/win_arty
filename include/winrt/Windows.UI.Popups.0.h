#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace UI { namespace Popups {
enum class MessageDialogOptions : unsigned {
	None = 0x0,
	AcceptUserInputAfterDelay = 0x1,
};
struct IMessageDialog;
struct IMessageDialogFactory;
struct MessageDialog;
enum class Placement : int {
	Default = 0,
	Above = 1,
	Below = 2,
	Left = 3,
	Right = 4,
};
struct UICommandInvokedHandler;
struct IUICommand;
struct IUICommandFactory;
struct UICommand;
struct UICommandSeparator;
struct IPopupMenu;
struct PopupMenu;
}}}
} // namespace iso_winrt