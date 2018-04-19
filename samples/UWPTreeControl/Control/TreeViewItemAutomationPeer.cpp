#include "pch.h"
#include "winrt/binding.h"
#include "TreeViewItemAutomationPeer.h"
#include "TreeNode.h"

using namespace iso_winrt;
using namespace Platform;
using namespace Windows::UI::Xaml;

namespace TreeViewControl {
	//IExpandCollapseProvider
	Automation::ExpandCollapseState TreeViewItemAutomationPeer::ExpandCollapseState() {
		Automation::ExpandCollapseState currentState = Automation::ExpandCollapseState::Collapsed;

		if (ptr<Controls::ListView> listview = GetParentListView((ptr<DependencyObject>)Owner)) {
			ptr<TreeView> ancestorTreeView = (ptr<TreeView>)listview;
			auto	temp = ancestorTreeView->ItemFromContainer((ptr<TreeViewItem>)Owner);
			ptr<TreeNode>	targetNode = (ptr<TreeNode>)temp;
			//targetNode = (ptr<TreeNode>)ancestorTreeView->ItemFromContainer((ptr<TreeViewItem>)Owner());

			if (Owner->AllowDrop) {
				if (targetNode->IsExpanded)
					currentState = Automation::ExpandCollapseState::Expanded;
				else
					currentState = Automation::ExpandCollapseState::Collapsed;
			} else {
				currentState = Automation::ExpandCollapseState::LeafNode;
			}
		}

		return currentState;
	}

	void TreeViewItemAutomationPeer::Collapse() {
		ptr<Controls::ListView> listview = GetParentListView((ptr<DependencyObject>)Owner);

		if (listview) {
			ptr<TreeView> ancestorTreeView	= (ptr<TreeView>)listview;
			ptr<TreeNode> targetNode		= (ptr<TreeNode>)ancestorTreeView->ItemFromContainer((ptr<TreeViewItem>)Owner);
			ancestorTreeView->CollapseNode(targetNode);
			RaiseExpandCollapseAutomationEvent(Automation::ExpandCollapseState::Collapsed);
		}
	}

	void TreeViewItemAutomationPeer::Expand() {
		ptr<Controls::ListView> listview = GetParentListView((ptr<DependencyObject>)Owner);

		if (listview) {
			ptr<TreeView> ancestorTreeView = (ptr<TreeView>)listview;
			ptr<TreeNode> targetNode = (ptr<TreeNode>)ancestorTreeView->ItemFromContainer((ptr<TreeViewItem>)Owner);
			ancestorTreeView->ExpandNode(targetNode);
			RaiseExpandCollapseAutomationEvent(Automation::ExpandCollapseState::Expanded);
		}
	}

	void TreeViewItemAutomationPeer::RaiseExpandCollapseAutomationEvent(Automation::ExpandCollapseState newState) {
		Automation::ExpandCollapseState oldState = newState == Automation::ExpandCollapseState::Expanded
			? Automation::ExpandCollapseState::Collapsed
			: Automation::ExpandCollapseState::Expanded;

		RaisePropertyChangedEvent(Automation::ExpandCollapsePatternIdentifiers::ExpandCollapseStateProperty(), (object)(int)oldState, (object)(int)newState);
	}

	//Position override

	//These methods are being overridden so that the TreeView under narrator reads out
	//the position of an item as compared to it's children, not it's overall position
	//in the listview. I've included an override for level as well, to give context on
	//how deep in the tree an item is.
	int TreeViewItemAutomationPeer::GetSizeOfSetCore() {
		int setSize = 0;

		if (ptr<Controls::ListView> listview = GetParentListView((ptr<DependencyObject>)Owner)) {
			ptr<TreeView>	ancestorTreeView	= (ptr<TreeView>)listview;
			ptr<TreeNode>	targetNode			= (ptr<TreeNode>)ancestorTreeView->ItemFromContainer((ptr<TreeViewItem>)Owner);
			ptr<TreeNode>	targetParentNode	= targetNode->ParentNode;
			setSize = targetParentNode->Size();
		}

		return setSize;
	}

	int TreeViewItemAutomationPeer::GetPositionInSetCore() {
		int positionInSet = 0;

		if (ptr<Controls::ListView> listview = GetParentListView((ptr<DependencyObject>)Owner)) {
			ptr<TreeView>	ancestorTreeView	= (ptr<TreeView>)listview;
			ptr<TreeNode>	targetNode			= (ptr<TreeNode>)ancestorTreeView->ItemFromContainer((ptr<TreeViewItem>)Owner);
			ptr<TreeNode>	targetParentNode	= targetNode->ParentNode;
			unsigned positionInt;
			targetParentNode->IndexOf(targetNode, &positionInt);
			positionInSet = (int)positionInt + 1;
		}

		return positionInSet;
	}

	int TreeViewItemAutomationPeer::GetLevelCore() {
		int levelValue = 0;

		if (ptr<Controls::ListView> listview = GetParentListView((ptr<DependencyObject>)Owner)) {
			ptr<TreeView>	ancestorTreeView	= (ptr<TreeView>)listview;
			ptr<TreeNode>	targetNode			= (ptr<TreeNode>)ancestorTreeView->ItemFromContainer((ptr<TreeViewItem>)Owner);
			levelValue = targetNode->Depth() + 1;
		}

		return levelValue;
	}

	ptr<Platform::Object> TreeViewItemAutomationPeer::GetPatternCore(Automation::Peers::PatternInterface patternInterface) {
		if (patternInterface == Automation::Peers::PatternInterface::ExpandCollapse)
			return (ptr<Platform::Object>)this;

		return IAutomationPeerOverrides::GetPatternCore(patternInterface);
	}

	ptr<Controls::ListView> TreeViewItemAutomationPeer::GetParentListView(ptr<DependencyObject> Owner) {
		ptr<Controls::ListView> listview = nullptr;
		for (ptr<DependencyObject> ancestor = Owner; ancestor != nullptr && listview == nullptr; listview = ref_cast<ptr<Controls::ListView>>(ancestor))
			ancestor = Media::VisualTreeHelper::GetParent(ancestor);

		return listview;
	}
}