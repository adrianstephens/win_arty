#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace UI { namespace StartScreen {
enum class JumpListSystemGroupKind : int {
	None = 0,
	Frequent = 1,
	Recent = 2,
};
enum class JumpListItemKind : int {
	Arguments = 0,
	Separator = 1,
};
struct IJumpListItem;
struct IJumpListItemStatics;
struct JumpListItem;
struct IJumpList;
struct IJumpListStatics;
struct JumpList;
enum class TileOptions : unsigned {
	None = 0x0,
	ShowNameOnLogo = 0x1,
	ShowNameOnWideLogo = 0x2,
	CopyOnDeployment = 0x4,
};
enum class TileSize : int {
	Default = 0,
	Square30x30 = 1,
	Square70x70 = 2,
	Square150x150 = 3,
	Wide310x150 = 4,
	Square310x310 = 5,
	Square71x71 = 6,
	Square44x44 = 7,
};
enum class ForegroundText : int {
	Dark = 0,
	Light = 1,
};
enum class TileMixedRealityModelActivationBehavior : int {
	Default = 0,
	None = 1,
};
struct ISecondaryTile;
struct ISecondaryTile2;
struct ISecondaryTileVisualElements4;
struct ISecondaryTileVisualElements3;
struct ISecondaryTileVisualElements2;
struct ISecondaryTileVisualElements;
struct SecondaryTileVisualElements;
struct ISecondaryTileStatics;
struct ISecondaryTileFactory;
struct ISecondaryTileFactory2;
struct SecondaryTile;
struct IVisualElementsRequestedEventArgs;
struct VisualElementsRequestedEventArgs;
struct ITileMixedRealityModel;
struct ITileMixedRealityModel2;
struct TileMixedRealityModel;
struct IVisualElementsRequest;
struct VisualElementsRequest;
struct IVisualElementsRequestDeferral;
struct VisualElementsRequestDeferral;
struct IStartScreenManager;
struct IStartScreenManagerStatics;
struct StartScreenManager;
}}}
} // namespace iso_winrt