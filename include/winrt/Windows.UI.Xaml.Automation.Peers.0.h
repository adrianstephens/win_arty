#pragma once
// generated by isopod tools

#include "pre_include.h"

namespace iso_winrt {

// forward types

namespace Windows { namespace UI { namespace Xaml { namespace Automation { namespace Peers {
struct IColorSpectrumAutomationPeer;
struct IColorSpectrumAutomationPeerFactory;
struct IColorPickerSliderAutomationPeer;
struct IColorPickerSliderAutomationPeerFactory;
struct INavigationViewItemAutomationPeer;
struct INavigationViewItemAutomationPeerFactory;
struct IPersonPictureAutomationPeer;
struct IPersonPictureAutomationPeerFactory;
struct IRatingControlAutomationPeer;
struct IRatingControlAutomationPeerFactory;
struct ITreeViewListAutomationPeer;
struct ITreeViewListAutomationPeerFactory;
struct ITreeViewItemAutomationPeer;
struct ITreeViewItemAutomationPeerFactory;
struct IItemAutomationPeer;
struct IItemAutomationPeerFactory;
struct IButtonBaseAutomationPeer;
struct IButtonBaseAutomationPeerFactory;
struct ICaptureElementAutomationPeer;
struct ICaptureElementAutomationPeerFactory;
struct IComboBoxItemAutomationPeer;
struct IComboBoxItemAutomationPeerFactory;
struct IFlipViewItemAutomationPeer;
struct IFlipViewItemAutomationPeerFactory;
struct IGroupItemAutomationPeer;
struct IGroupItemAutomationPeerFactory;
struct IImageAutomationPeer;
struct IImageAutomationPeerFactory;
struct IItemsControlAutomationPeer;
struct IItemsControlAutomationPeerFactory;
struct IItemsControlAutomationPeer2;
struct IItemsControlAutomationPeerOverrides2;
struct IListBoxItemAutomationPeer;
struct IListBoxItemAutomationPeerFactory;
struct IMediaTransportControlsAutomationPeer;
struct IMediaTransportControlsAutomationPeerFactory;
struct IPasswordBoxAutomationPeer;
struct IPasswordBoxAutomationPeerFactory;
struct IProgressRingAutomationPeer;
struct IProgressRingAutomationPeerFactory;
struct IRangeBaseAutomationPeer;
struct IRangeBaseAutomationPeerFactory;
struct IRichTextBlockAutomationPeer;
struct IRichTextBlockAutomationPeerFactory;
struct IRichTextBlockOverflowAutomationPeer;
struct IRichTextBlockOverflowAutomationPeerFactory;
struct ISelectorItemAutomationPeer;
struct ISelectorItemAutomationPeerFactory;
struct ISemanticZoomAutomationPeer;
struct ISemanticZoomAutomationPeerFactory;
struct ISettingsFlyoutAutomationPeer;
struct ISettingsFlyoutAutomationPeerFactory;
struct ITextBlockAutomationPeer;
struct ITextBlockAutomationPeerFactory;
struct ITextBoxAutomationPeer;
struct ITextBoxAutomationPeerFactory;
struct IThumbAutomationPeer;
struct IThumbAutomationPeerFactory;
struct IToggleSwitchAutomationPeer;
struct IToggleSwitchAutomationPeerFactory;
struct IButtonAutomationPeer;
struct IButtonAutomationPeerFactory;
struct IComboBoxItemDataAutomationPeer;
struct IComboBoxItemDataAutomationPeerFactory;
struct IFlipViewItemDataAutomationPeer;
struct IFlipViewItemDataAutomationPeerFactory;
struct IHyperlinkButtonAutomationPeer;
struct IHyperlinkButtonAutomationPeerFactory;
struct IListBoxItemDataAutomationPeer;
struct IListBoxItemDataAutomationPeerFactory;
struct IProgressBarAutomationPeer;
struct IProgressBarAutomationPeerFactory;
struct IRepeatButtonAutomationPeer;
struct IRepeatButtonAutomationPeerFactory;
struct IScrollBarAutomationPeer;
struct IScrollBarAutomationPeerFactory;
struct ISelectorAutomationPeer;
struct ISelectorAutomationPeerFactory;
struct ISliderAutomationPeer;
struct ISliderAutomationPeerFactory;
struct IToggleButtonAutomationPeer;
struct IToggleButtonAutomationPeerFactory;
struct ICheckBoxAutomationPeer;
struct ICheckBoxAutomationPeerFactory;
struct IComboBoxAutomationPeer;
struct IComboBoxAutomationPeerFactory;
struct IFlipViewAutomationPeer;
struct IFlipViewAutomationPeerFactory;
struct IListBoxAutomationPeer;
struct IListBoxAutomationPeerFactory;
struct IRadioButtonAutomationPeer;
struct IRadioButtonAutomationPeerFactory;
struct IAppBarAutomationPeer;
struct IAppBarAutomationPeerFactory;
struct IAutoSuggestBoxAutomationPeer;
struct IAutoSuggestBoxAutomationPeerFactory;
struct ICalendarDatePickerAutomationPeer;
struct ICalendarDatePickerAutomationPeerFactory;
struct IDatePickerAutomationPeer;
struct IDatePickerAutomationPeerFactory;
struct IFlyoutPresenterAutomationPeer;
struct IFlyoutPresenterAutomationPeerFactory;
struct IGridViewItemAutomationPeer;
struct IGridViewItemAutomationPeerFactory;
struct IHubAutomationPeer;
struct IHubAutomationPeerFactory;
struct IHubSectionAutomationPeer;
struct IHubSectionAutomationPeerFactory;
struct IListViewBaseHeaderItemAutomationPeer;
struct IListViewBaseHeaderItemAutomationPeerFactory;
struct IListViewItemAutomationPeer;
struct IListViewItemAutomationPeerFactory;
struct IMediaElementAutomationPeer;
struct IMediaElementAutomationPeerFactory;
struct IMediaPlayerElementAutomationPeer;
struct IMediaPlayerElementAutomationPeerFactory;
struct IMenuFlyoutItemAutomationPeer;
struct IMenuFlyoutItemAutomationPeerFactory;
struct IRichEditBoxAutomationPeer;
struct IRichEditBoxAutomationPeerFactory;
struct IScrollViewerAutomationPeer;
struct IScrollViewerAutomationPeerFactory;
struct ISearchBoxAutomationPeer;
struct ISearchBoxAutomationPeerFactory;
struct ITimePickerAutomationPeer;
struct ITimePickerAutomationPeerFactory;
struct IToggleMenuFlyoutItemAutomationPeer;
struct IToggleMenuFlyoutItemAutomationPeerFactory;
struct IGridViewHeaderItemAutomationPeer;
struct IGridViewHeaderItemAutomationPeerFactory;
struct IGridViewItemDataAutomationPeer;
struct IGridViewItemDataAutomationPeerFactory;
struct IListViewHeaderItemAutomationPeer;
struct IListViewHeaderItemAutomationPeerFactory;
struct IListViewItemDataAutomationPeer;
struct IListViewItemDataAutomationPeerFactory;
struct IMenuFlyoutPresenterAutomationPeer;
struct IMenuFlyoutPresenterAutomationPeerFactory;
struct IAppBarButtonAutomationPeer;
struct IAppBarButtonAutomationPeerFactory;
struct IAppBarToggleButtonAutomationPeer;
struct IAppBarToggleButtonAutomationPeerFactory;
struct IListViewBaseAutomationPeer;
struct IListViewBaseAutomationPeerFactory;
struct IGridViewAutomationPeer;
struct IGridViewAutomationPeerFactory;
struct IListViewAutomationPeer;
struct IListViewAutomationPeerFactory;
enum class AccessibilityView : int {
	Raw = 0,
	Control = 1,
	Content = 2,
};
enum class AutomationControlType : int {
	Button = 0,
	Calendar = 1,
	CheckBox = 2,
	ComboBox = 3,
	Edit = 4,
	Hyperlink = 5,
	Image = 6,
	ListItem = 7,
	List = 8,
	Menu = 9,
	MenuBar = 10,
	MenuItem = 11,
	ProgressBar = 12,
	RadioButton = 13,
	ScrollBar = 14,
	Slider = 15,
	Spinner = 16,
	StatusBar = 17,
	Tab = 18,
	TabItem = 19,
	Text = 20,
	ToolBar = 21,
	ToolTip = 22,
	Tree = 23,
	TreeItem = 24,
	Custom = 25,
	Group = 26,
	Thumb = 27,
	DataGrid = 28,
	DataItem = 29,
	Document = 30,
	SplitButton = 31,
	Window = 32,
	Pane = 33,
	Header = 34,
	HeaderItem = 35,
	Table = 36,
	TitleBar = 37,
	Separator = 38,
	SemanticZoom = 39,
	AppBar = 40,
};
enum class AutomationEvents : int {
	ToolTipOpened = 0,
	ToolTipClosed = 1,
	MenuOpened = 2,
	MenuClosed = 3,
	AutomationFocusChanged = 4,
	InvokePatternOnInvoked = 5,
	SelectionItemPatternOnElementAddedToSelection = 6,
	SelectionItemPatternOnElementRemovedFromSelection = 7,
	SelectionItemPatternOnElementSelected = 8,
	SelectionPatternOnInvalidated = 9,
	TextPatternOnTextSelectionChanged = 10,
	TextPatternOnTextChanged = 11,
	AsyncContentLoaded = 12,
	PropertyChanged = 13,
	StructureChanged = 14,
	DragStart = 15,
	DragCancel = 16,
	DragComplete = 17,
	DragEnter = 18,
	DragLeave = 19,
	Dropped = 20,
	LiveRegionChanged = 21,
	InputReachedTarget = 22,
	InputReachedOtherElement = 23,
	InputDiscarded = 24,
	WindowClosed = 25,
	WindowOpened = 26,
	ConversionTargetChanged = 27,
	TextEditTextChanged = 28,
	LayoutInvalidated = 29,
};
enum class AutomationHeadingLevel : int {
	None = 0,
	Level1 = 1,
	Level2 = 2,
	Level3 = 3,
	Level4 = 4,
	Level5 = 5,
	Level6 = 6,
	Level7 = 7,
	Level8 = 8,
	Level9 = 9,
};
enum class AutomationLandmarkType : int {
	None = 0,
	Custom = 1,
	Form = 2,
	Main = 3,
	Navigation = 4,
	Search = 5,
};
enum class AutomationLiveSetting : int {
	Off = 0,
	Polite = 1,
	Assertive = 2,
};
enum class AutomationNavigationDirection : int {
	Parent = 0,
	NextSibling = 1,
	PreviousSibling = 2,
	FirstChild = 3,
	LastChild = 4,
};
enum class AutomationNotificationKind : int {
	ItemAdded = 0,
	ItemRemoved = 1,
	ActionCompleted = 2,
	ActionAborted = 3,
	Other = 4,
};
enum class AutomationNotificationProcessing : int {
	ImportantAll = 0,
	ImportantMostRecent = 1,
	All = 2,
	MostRecent = 3,
	CurrentThenMostRecent = 4,
};
enum class AutomationOrientation : int {
	None = 0,
	Horizontal = 1,
	Vertical = 2,
};
enum class AutomationStructureChangeType : int {
	ChildAdded = 0,
	ChildRemoved = 1,
	ChildrenInvalidated = 2,
	ChildrenBulkAdded = 3,
	ChildrenBulkRemoved = 4,
	ChildrenReordered = 5,
};
enum class PatternInterface : int {
	Invoke = 0,
	Selection = 1,
	Value = 2,
	RangeValue = 3,
	Scroll = 4,
	ScrollItem = 5,
	ExpandCollapse = 6,
	Grid = 7,
	GridItem = 8,
	MultipleView = 9,
	Window = 10,
	SelectionItem = 11,
	Dock = 12,
	Table = 13,
	TableItem = 14,
	Toggle = 15,
	Transform = 16,
	Text = 17,
	ItemContainer = 18,
	VirtualizedItem = 19,
	Text2 = 20,
	TextChild = 21,
	TextRange = 22,
	Annotation = 23,
	Drag = 24,
	DropTarget = 25,
	ObjectModel = 26,
	Spreadsheet = 27,
	SpreadsheetItem = 28,
	Styles = 29,
	Transform2 = 30,
	SynchronizedInput = 31,
	TextEdit = 32,
	CustomNavigation = 33,
};
struct RawElementProviderRuntimeId {
	unsigned Part1;
	unsigned Part2;
};
struct IAutomationPeer;
struct IAutomationPeerOverrides;
struct IAutomationPeerProtected;
struct IAutomationPeerStatics;
struct IAutomationPeerFactory;
struct IAutomationPeer2;
struct IAutomationPeerOverrides2;
struct IAutomationPeer3;
struct IAutomationPeerOverrides3;
struct IAutomationPeerStatics3;
struct IAutomationPeer4;
struct IAutomationPeerOverrides4;
struct IAutomationPeer5;
struct IAutomationPeerOverrides5;
struct IAutomationPeer6;
struct IAutomationPeerOverrides6;
struct IAutomationPeer7;
struct IAutomationPeer8;
struct IAutomationPeerOverrides8;
struct AutomationPeer;
struct IAutomationPeerAnnotation;
struct IAutomationPeerAnnotationStatics;
struct IAutomationPeerAnnotationFactory;
struct AutomationPeerAnnotation;
struct IFrameworkElementAutomationPeer;
struct IFrameworkElementAutomationPeerStatics;
struct IFrameworkElementAutomationPeerFactory;
struct FrameworkElementAutomationPeer;
struct ColorSpectrumAutomationPeer;
struct PersonPictureAutomationPeer;
struct RatingControlAutomationPeer;
struct ButtonBaseAutomationPeer;
struct CaptureElementAutomationPeer;
struct ComboBoxItemAutomationPeer;
struct FlipViewItemAutomationPeer;
struct GroupItemAutomationPeer;
struct ImageAutomationPeer;
struct ListBoxItemAutomationPeer;
struct MediaTransportControlsAutomationPeer;
struct PasswordBoxAutomationPeer;
struct ProgressRingAutomationPeer;
struct RichTextBlockAutomationPeer;
struct RichTextBlockOverflowAutomationPeer;
struct SettingsFlyoutAutomationPeer;
struct TextBlockAutomationPeer;
struct TextBoxAutomationPeer;
struct ThumbAutomationPeer;
struct DatePickerAutomationPeer;
struct FlyoutPresenterAutomationPeer;
struct GridViewItemAutomationPeer;
struct HubAutomationPeer;
struct ListViewBaseHeaderItemAutomationPeer;
struct ListViewItemAutomationPeer;
struct NavigationViewItemAutomationPeer;
struct MediaElementAutomationPeer;
struct MediaPlayerElementAutomationPeer;
struct RichEditBoxAutomationPeer;
struct SearchBoxAutomationPeer;
struct TimePickerAutomationPeer;
struct GridViewHeaderItemAutomationPeer;
struct ListViewHeaderItemAutomationPeer;
struct TreeViewItemAutomationPeer;
struct ButtonAutomationPeer;
struct HyperlinkButtonAutomationPeer;
struct RepeatButtonAutomationPeer;
struct AutoSuggestBoxAutomationPeer;
struct MenuFlyoutItemAutomationPeer;
struct AppBarButtonAutomationPeer;
struct ItemsControlAutomationPeer;
struct MenuFlyoutPresenterAutomationPeer;
struct RangeBaseAutomationPeer;
struct ProgressBarAutomationPeer;
struct ScrollBarAutomationPeer;
struct SliderAutomationPeer;
struct ColorPickerSliderAutomationPeer;
struct HubSectionAutomationPeer;
struct ScrollViewerAutomationPeer;
struct SelectorAutomationPeer;
struct TreeViewListAutomationPeer;
struct FlipViewAutomationPeer;
struct ListBoxAutomationPeer;
struct ListViewBaseAutomationPeer;
struct GridViewAutomationPeer;
struct ListViewAutomationPeer;
struct SemanticZoomAutomationPeer;
struct ToggleSwitchAutomationPeer;
struct ToggleButtonAutomationPeer;
struct CheckBoxAutomationPeer;
struct RadioButtonAutomationPeer;
struct ToggleMenuFlyoutItemAutomationPeer;
struct AppBarToggleButtonAutomationPeer;
struct CalendarDatePickerAutomationPeer;
struct ItemAutomationPeer;
struct SelectorItemAutomationPeer;
struct ComboBoxItemDataAutomationPeer;
struct FlipViewItemDataAutomationPeer;
struct ListBoxItemDataAutomationPeer;
struct GridViewItemDataAutomationPeer;
struct ListViewItemDataAutomationPeer;
struct ComboBoxAutomationPeer;
struct AppBarAutomationPeer;
struct IInkToolbarAutomationPeer;
struct InkToolbarAutomationPeer;
struct IMapControlAutomationPeer;
struct MapControlAutomationPeer;
struct ILoopingSelectorItemDataAutomationPeer;
struct LoopingSelectorItemDataAutomationPeer;
struct IDatePickerFlyoutPresenterAutomationPeer;
struct DatePickerFlyoutPresenterAutomationPeer;
struct IListPickerFlyoutPresenterAutomationPeer;
struct ListPickerFlyoutPresenterAutomationPeer;
struct ILoopingSelectorAutomationPeer;
struct LoopingSelectorAutomationPeer;
struct ILoopingSelectorItemAutomationPeer;
struct LoopingSelectorItemAutomationPeer;
struct IPickerFlyoutPresenterAutomationPeer;
struct PickerFlyoutPresenterAutomationPeer;
struct IPivotItemAutomationPeer;
struct IPivotItemAutomationPeerFactory;
struct PivotItemAutomationPeer;
struct IPivotItemDataAutomationPeer;
struct IPivotItemDataAutomationPeerFactory;
struct PivotItemDataAutomationPeer;
struct ITimePickerFlyoutPresenterAutomationPeer;
struct TimePickerFlyoutPresenterAutomationPeer;
struct IPivotAutomationPeer;
struct IPivotAutomationPeerFactory;
struct PivotAutomationPeer;
}}}}}
} // namespace iso_winrt