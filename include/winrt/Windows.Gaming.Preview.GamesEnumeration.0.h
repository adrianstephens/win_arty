#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace Gaming { namespace Preview { namespace GamesEnumeration {
enum class GameListCategory : int {
	Candidate = 0,
	ConfirmedBySystem = 1,
	ConfirmedByUser = 2,
};
struct IGameListEntry;
struct IGameModeConfiguration;
enum class GameListEntryLaunchableState : int {
	NotLaunchable = 0,
	ByLastRunningFullPath = 1,
	ByUserProvidedPath = 2,
	ByTile = 3,
};
struct IGameListEntry2;
struct GameModeConfiguration;
struct IGameModeUserConfiguration;
struct GameListEntry;
struct IGameModeUserConfigurationStatics;
struct GameModeUserConfiguration;
struct GameListChangedEventHandler;
struct GameListRemovedEventHandler;
struct IGameListStatics;
struct IGameListStatics2;
struct GameList;
}}}}
} // namespace iso_winrt