#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Web { namespace UI { namespace Interop {
enum class WebViewControlMoveFocusReason : int {
	Programmatic = 0,
	Next = 1,
	Previous = 2,
};
enum class WebViewControlProcessCapabilityState : int {
	Default = 0,
	Disabled = 1,
	Enabled = 2,
};
enum class WebViewControlAcceleratorKeyRoutingStage : int {
	Tunneling = 0,
	Bubbling = 1,
};
struct IWebViewControlSite;
struct IWebViewControlProcessFactory;
struct IWebViewControlProcess;
struct WebViewControlProcess;
struct WebViewControl;
struct IWebViewControlMoveFocusRequestedEventArgs;
struct WebViewControlMoveFocusRequestedEventArgs;
struct IWebViewControlAcceleratorKeyPressedEventArgs;
struct WebViewControlAcceleratorKeyPressedEventArgs;
struct IWebViewControlProcessOptions;
struct WebViewControlProcessOptions;
}}}}
} // namespace iso_winrt
