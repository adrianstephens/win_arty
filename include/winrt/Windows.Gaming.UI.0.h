#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Gaming { namespace UI {
struct IGameBarStatics;
struct GameBar;
enum class GameChatOverlayPosition : int {
	BottomCenter = 0,
	BottomLeft = 1,
	BottomRight = 2,
	MiddleRight = 3,
	MiddleLeft = 4,
	TopCenter = 5,
	TopLeft = 6,
	TopRight = 7,
};
enum class GameChatMessageOrigin : int {
	Voice = 0,
	Text = 1,
};
struct IGameChatOverlayStatics;
struct IGameChatOverlay;
struct GameChatOverlay;
enum class GameMonitoringPermission : int {
	Allowed = 0,
	DeniedByUser = 1,
	DeniedBySystem = 2,
};
struct IGameMonitor;
struct IGameMonitorStatics;
struct GameMonitor;
struct GameChatOverlayContract {};
struct IGameChatOverlayMessageSource;
struct GameChatOverlayMessageSource;
struct IGameChatMessageReceivedEventArgs;
struct GameChatMessageReceivedEventArgs;
struct GamingUIProviderContract {};
struct IGameUIProviderActivatedEventArgs;
struct GameUIProviderActivatedEventArgs;
}}}
} // namespace iso_winrt
