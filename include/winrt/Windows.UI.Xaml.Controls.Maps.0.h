#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace UI { namespace Xaml { namespace Controls { namespace Maps {
struct IMapStyleSheetEntriesStatics;
struct MapStyleSheetEntries;
struct IMapStyleSheetEntryStatesStatics;
struct MapStyleSheetEntryStates;
enum class MapAnimationKind : int {
	Default = 0,
	None = 1,
	Linear = 2,
	Bow = 3,
};
enum class MapCameraChangeReason : int {
	System = 0,
	UserInteraction = 1,
	Programmatic = 2,
};
enum class MapColorScheme : int {
	Light = 0,
	Dark = 1,
};
enum class MapElementCollisionBehavior : int {
	Hide = 0,
	RemainVisible = 1,
};
enum class MapInteractionMode : int {
	Auto = 0,
	Disabled = 1,
	GestureOnly = 2,
	PointerAndKeyboard = 2,
	ControlOnly = 3,
	GestureAndControl = 4,
	PointerKeyboardAndControl = 4,
	PointerOnly = 5,
};
enum class MapLoadingStatus : int {
	Loading = 0,
	Loaded = 1,
	DataUnavailable = 2,
};
enum class MapModel3DShadingOption : int {
	Default = 0,
	Flat = 1,
	Smooth = 2,
};
enum class MapPanInteractionMode : int {
	Auto = 0,
	Disabled = 1,
};
enum class MapProjection : int {
	WebMercator = 0,
	Globe = 1,
};
enum class MapStyle : int {
	None = 0,
	Road = 1,
	Aerial = 2,
	AerialWithRoads = 3,
	Terrain = 4,
	Aerial3D = 5,
	Aerial3DWithRoads = 6,
	Custom = 7,
};
enum class MapTileLayer : int {
	LabelOverlay = 0,
	RoadOverlay = 1,
	AreaOverlay = 2,
	BackgroundOverlay = 3,
	BackgroundReplacement = 4,
};
enum class MapVisibleRegionKind : int {
	Near = 0,
	Full = 1,
};
enum class MapWatermarkMode : int {
	Automatic = 0,
	On = 1,
};
struct MapZoomLevelRange {
	double Min;
	double Max;
};
struct IMapActualCameraChangedEventArgs;
struct IMapActualCameraChangedEventArgs2;
struct MapActualCameraChangedEventArgs;
struct IMapActualCameraChangingEventArgs;
struct IMapActualCameraChangingEventArgs2;
struct MapActualCameraChangingEventArgs;
struct IMapContextRequestedEventArgs;
struct MapContextRequestedEventArgs;
struct IMapCustomExperienceChangedEventArgs;
struct MapCustomExperienceChangedEventArgs;
struct IMapElementClickEventArgs;
struct MapElementClickEventArgs;
struct IMapElementPointerEnteredEventArgs;
struct MapElementPointerEnteredEventArgs;
struct IMapElementPointerExitedEventArgs;
struct MapElementPointerExitedEventArgs;
struct IMapElementsLayerClickEventArgs;
struct MapElementsLayerClickEventArgs;
struct IMapElementsLayerContextRequestedEventArgs;
struct MapElementsLayerContextRequestedEventArgs;
struct IMapElementsLayerPointerEnteredEventArgs;
struct MapElementsLayerPointerEnteredEventArgs;
struct IMapElementsLayerPointerExitedEventArgs;
struct MapElementsLayerPointerExitedEventArgs;
struct IMapRightTappedEventArgs;
struct MapRightTappedEventArgs;
struct IMapTargetCameraChangedEventArgs;
struct IMapTargetCameraChangedEventArgs2;
struct MapTargetCameraChangedEventArgs;
struct IMapTileBitmapRequest;
struct IMapTileBitmapRequestDeferral;
struct MapTileBitmapRequestDeferral;
struct MapTileBitmapRequest;
struct IMapTileBitmapRequestedEventArgs;
struct MapTileBitmapRequestedEventArgs;
struct IMapTileUriRequest;
struct IMapTileUriRequestDeferral;
struct MapTileUriRequestDeferral;
struct MapTileUriRequest;
struct IMapTileUriRequestedEventArgs;
struct MapTileUriRequestedEventArgs;
struct IMapCamera;
struct IMapCameraFactory;
struct MapCamera;
struct IMapCustomExperience;
struct IMapCustomExperienceFactory;
struct MapCustomExperience;
struct IMapElement;
struct IMapElementStatics;
struct IMapElementFactory;
struct IMapElement2;
struct IMapElementStatics2;
struct IMapElement3;
struct IMapElementStatics3;
struct IMapElement4;
struct IMapElementStatics4;
struct MapElement;
struct IMapInputEventArgs;
struct MapInputEventArgs;
struct IMapItemsControl;
struct IMapItemsControlStatics;
struct MapItemsControl;
struct IMapLayer;
struct IMapLayerStatics;
struct IMapLayerFactory;
struct MapLayer;
struct IMapModel3D;
struct IMapModel3DStatics;
struct IMapModel3DFactory;
struct MapModel3D;
struct IMapRouteView;
struct IMapRouteViewFactory;
struct MapRouteView;
struct IMapScene;
struct IMapSceneStatics;
struct MapScene;
struct IMapStyleSheet;
struct IMapStyleSheetStatics;
struct MapStyleSheet;
struct IMapTileDataSource;
struct IMapTileDataSourceFactory;
struct MapTileDataSource;
struct IMapTileSource;
struct IMapTileSourceStatics;
struct IMapTileSourceFactory;
struct MapTileSource;
struct IStreetsidePanorama;
struct IStreetsidePanoramaStatics;
struct StreetsidePanorama;
struct ICustomMapTileDataSource;
struct ICustomMapTileDataSourceFactory;
struct CustomMapTileDataSource;
struct IHttpMapTileDataSource;
struct IHttpMapTileDataSourceFactory;
struct HttpMapTileDataSource;
struct ILocalMapTileDataSource;
struct ILocalMapTileDataSourceFactory;
struct LocalMapTileDataSource;
struct IMapBillboard;
struct IMapBillboardStatics;
struct IMapBillboardFactory;
struct MapBillboard;
struct IMapElement3D;
struct IMapElement3DStatics;
struct MapElement3D;
struct IMapElementsLayer;
struct IMapElementsLayerStatics;
struct MapElementsLayer;
struct IMapIcon;
struct IMapIconStatics;
struct IMapIcon2;
struct IMapIconStatics2;
struct MapIcon;
struct IMapPolygon;
struct IMapPolygonStatics;
struct IMapPolygon2;
struct MapPolygon;
struct IMapPolyline;
struct IMapPolylineStatics;
struct MapPolyline;
struct IStreetsideExperience;
struct IStreetsideExperienceFactory;
struct StreetsideExperience;
struct IMapControl;
struct IMapControlStatics;
struct IMapControl2;
struct IMapControlStatics2;
struct IMapControl3;
struct IMapControl4;
struct IMapControlStatics4;
struct IMapControl5;
struct IMapControlStatics5;
struct IMapControl6;
struct IMapControlStatics6;
struct IMapControl7;
struct IMapControlStatics7;
struct MapControl;
struct IMapControlDataHelper;
struct IMapControlBusinessLandmarkClickEventArgs;
struct MapControlBusinessLandmarkClickEventArgs;
struct IMapControlTransitFeatureClickEventArgs;
struct MapControlTransitFeatureClickEventArgs;
struct IMapControlBusinessLandmarkRightTappedEventArgs;
struct MapControlBusinessLandmarkRightTappedEventArgs;
struct IMapControlTransitFeatureRightTappedEventArgs;
struct MapControlTransitFeatureRightTappedEventArgs;
struct IMapControlDataHelper2;
struct IMapControlBusinessLandmarkPointerEnteredEventArgs;
struct MapControlBusinessLandmarkPointerEnteredEventArgs;
struct IMapControlTransitFeaturePointerEnteredEventArgs;
struct MapControlTransitFeaturePointerEnteredEventArgs;
struct IMapControlBusinessLandmarkPointerExitedEventArgs;
struct MapControlBusinessLandmarkPointerExitedEventArgs;
struct IMapControlTransitFeaturePointerExitedEventArgs;
struct MapControlTransitFeaturePointerExitedEventArgs;
struct IMapControlDataHelperStatics;
struct IMapControlDataHelperFactory;
struct MapControlDataHelper;
}}}}}
} // namespace iso_winrt
