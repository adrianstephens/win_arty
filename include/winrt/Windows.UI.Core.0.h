#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace UI { namespace Core {
struct ISystemNavigationManager;
struct IBackRequestedEventArgs;
struct BackRequestedEventArgs;
enum class AppViewBackButtonVisibility : int {
	Visible = 0,
	Collapsed = 1,
	Disabled = 2,
};
struct ISystemNavigationManager2;
struct ISystemNavigationManagerStatics;
struct SystemNavigationManager;
enum class CoreWindowActivationState : int {
	CodeActivated = 0,
	Deactivated = 1,
	PointerActivated = 2,
};
enum class CoreWindowActivationMode : int {
	None = 0,
	Deactivated = 1,
	ActivatedNotForeground = 2,
	ActivatedInForeground = 3,
};
enum class CoreCursorType : int {
	Arrow = 0,
	Cross = 1,
	Custom = 2,
	Hand = 3,
	Help = 4,
	IBeam = 5,
	SizeAll = 6,
	SizeNortheastSouthwest = 7,
	SizeNorthSouth = 8,
	SizeNorthwestSoutheast = 9,
	SizeWestEast = 10,
	UniversalNo = 11,
	UpArrow = 12,
	Wait = 13,
	Pin = 14,
	Person = 15,
};
enum class CoreDispatcherPriority : int {
	Idle = -2,
	Low = -1,
	Normal = 0,
	High = 1,
};
enum class CoreProcessEventsOption : int {
	ProcessOneAndAllPending = 0,
	ProcessOneIfPresent = 1,
	ProcessUntilQuit = 2,
	ProcessAllIfPresent = 3,
};
enum class CoreWindowFlowDirection : int {
	LeftToRight = 0,
	RightToLeft = 1,
};
enum class CoreVirtualKeyStates : unsigned {
	None = 0x0,
	Down = 0x1,
	Locked = 0x2,
};
enum class CoreAcceleratorKeyEventType : int {
	Character = 2,
	DeadCharacter = 3,
	KeyDown = 0,
	KeyUp = 1,
	SystemCharacter = 6,
	SystemDeadCharacter = 7,
	SystemKeyDown = 4,
	SystemKeyUp = 5,
	UnicodeCharacter = 8,
};
enum class CoreProximityEvaluationScore : int {
	Closest = 0,
	Farthest = 2147483647,
};
enum class CoreInputDeviceTypes : unsigned {
	None = 0x0,
	Touch = 0x1,
	Pen = 0x2,
	Mouse = 0x4,
};
struct CorePhysicalKeyStatus {
	unsigned RepeatCount;
	unsigned ScanCode;
	bool IsExtendedKey;
	bool IsMenuKeyDown;
	bool WasKeyDown;
	bool IsKeyReleased;
};
struct CoreProximityEvaluation {
	int Score;
	Foundation::Point AdjustedPoint;
};
struct ICoreWindowEventArgs;
struct IAutomationProviderRequestedEventArgs;
struct ICharacterReceivedEventArgs;
struct IInputEnabledEventArgs;
struct IKeyEventArgs;
struct IKeyEventArgs2;
struct IPointerEventArgs;
struct ITouchHitTestingEventArgs;
struct IClosestInteractiveBoundsRequestedEventArgs;
struct IWindowActivatedEventArgs;
struct IWindowSizeChangedEventArgs;
struct IVisibilityChangedEventArgs;
struct ICoreWindow;
struct ICoreDispatcher2;
struct ICoreDispatcherWithTaskPriority;
struct ICoreAcceleratorKeys;
struct ICoreDispatcher;
struct CoreDispatcher;
struct ICoreCursorFactory;
struct ICoreCursor;
struct CoreCursor;
struct ICoreWindowStatic;
struct ICoreWindow5;
struct ICoreWindow4;
struct ICoreWindow3;
struct ICorePointerRedirector;
struct ICoreWindow2;
struct CoreWindow;
struct WindowActivatedEventArgs;
struct AutomationProviderRequestedEventArgs;
struct CharacterReceivedEventArgs;
struct CoreWindowEventArgs;
struct InputEnabledEventArgs;
struct KeyEventArgs;
struct PointerEventArgs;
struct TouchHitTestingEventArgs;
struct WindowSizeChangedEventArgs;
struct VisibilityChangedEventArgs;
struct ClosestInteractiveBoundsRequestedEventArgs;
struct DispatchedHandler;
struct IdleDispatchedHandler;
struct IIdleDispatchedHandlerArgs;
struct IdleDispatchedHandlerArgs;
struct IAcceleratorKeyEventArgs;
struct IAcceleratorKeyEventArgs2;
struct AcceleratorKeyEventArgs;
struct CoreAcceleratorKeys;
struct IInitializeWithCoreWindow;
struct ICoreWindowResizeManager;
struct ICoreWindowResizeManagerLayoutCapability;
struct ICoreWindowResizeManagerStatics;
struct CoreWindowResizeManager;
struct ICoreInputSourceBase;
struct ICorePointerInputSource;
struct ICorePointerInputSource2;
struct ICoreKeyboardInputSource;
struct ICoreKeyboardInputSource2;
struct ICoreComponentFocusable;
struct ICoreTouchHitTesting;
struct ICoreClosestInteractiveBoundsRequested;
struct CoreComponentInputSource;
struct CoreIndependentInputSource;
struct CoreWindowDialogsContract {};
struct ICoreWindowPopupShowingEventArgs;
struct CoreWindowPopupShowingEventArgs;
struct ICoreWindowDialog;
struct ICoreWindowDialogFactory;
struct CoreWindowDialog;
struct ICoreWindowFlyout;
struct ICoreWindowFlyoutFactory;
struct CoreWindowFlyout;
}}}
} // namespace iso_winrt
