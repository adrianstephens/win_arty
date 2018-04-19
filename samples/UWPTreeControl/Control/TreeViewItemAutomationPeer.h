#pragma once
#include "TreeViewItem.h"
#include "TreeView.h"

#include "winrt/Windows.UI.Xaml.Automation.h"
#include "winrt/Windows.UI.Xaml.Automation.Peers.h"

namespace TreeViewControl {
	using namespace iso_winrt;

//	[Windows::Foundation::Metadata::WebHostHidden]
	class TreeViewItemAutomationPeer : public compose<TreeViewItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider> {
		typedef Windows::UI::Xaml::DependencyObject	DependencyObject;
	internal:
		TreeViewItemAutomationPeer(ptr<TreeViewItem> owner) : ListViewItemAutomationPeer(owner) {};

	public:
		//IExpandCollapseProvider
		void Collapse();
		void Expand();

		Windows::UI::Xaml::Automation::ExpandCollapseState ExpandCollapseState();

		void RaiseExpandCollapseAutomationEvent(Windows::UI::Xaml::Automation::ExpandCollapseState newState);

		//Position override
		int GetSizeOfSetCore();
		int GetPositionInSetCore();
		int GetLevelCore();

		ptr<Platform::Object> GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface);

	private:
		ptr<Windows::UI::Xaml::Controls::ListView> GetParentListView(ptr<DependencyObject> Owner);
	};
}
