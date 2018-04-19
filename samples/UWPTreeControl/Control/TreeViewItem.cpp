#include "pch.h"
#include "winrt/binding.h"
#include "TreeViewItem.h"
#include "TreeViewItemAutomationPeer.h"

using namespace iso_winrt;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::ApplicationModel::DataTransfer;

namespace TreeViewControl {

	ptr<Controls::ListView> TreeViewItem::GetAncestorListView(ptr<TreeViewItem> targetItem) {
		ptr<Controls::ListView> listview = nullptr;
		for (ptr<DependencyObject> ancestor = ptr<DependencyObject>(this); ancestor != nullptr && listview == nullptr; listview = ref_cast<ptr<Controls::ListView>>(ancestor))
			ancestor = Media::VisualTreeHelper::GetParent(ancestor);
		return listview;
	}

	void TreeViewItem::OnDrop(ptr<DragEventArgs> e) {
		if (e->AcceptedOperation == DataPackageOperation::Move) {
			ptr<TreeViewItem> droppedOnItem = (ptr<TreeViewItem>)this;

			ptr<Controls::ListView> listview = GetAncestorListView(droppedOnItem);

			if (listview) {
				ptr<TreeView>		ancestorTreeView	= (ptr<TreeView>)listview;
				ptr<TreeViewItem>	droppedItem			= ancestorTreeView->draggedTreeViewItem;
				ptr<TreeNode>		droppedNode			= (ptr<TreeNode>)ancestorTreeView->ItemFromContainer(droppedItem);
				ptr<TreeNode>		droppedOnNode		= (ptr<TreeNode>)ancestorTreeView->ItemFromContainer(droppedOnItem);

				//Remove the item that was dragged
				unsigned removeIndex;
				droppedNode->ParentNode->IndexOf(droppedNode, &removeIndex);

				if (droppedNode != droppedOnNode) {
					droppedNode->ParentNode->RemoveAt(removeIndex);

					//Append the dragged dropped item as a child of the node it was dropped onto
					droppedOnNode->Append(droppedNode);

					//If not set to true then the Reorder code of listview wil override what is being done here.
					e->Handled = true;
				} else {
					e->AcceptedOperation = DataPackageOperation::None;
				}
			}
		}
	}

	void TreeViewItem::OnDragEnter(ptr<DragEventArgs> e) {
		ptr<TreeViewItem> draggedOverItem = (ptr<TreeViewItem>)this;

		e->AcceptedOperation = DataPackageOperation::None;

		ptr<Controls::ListView> listview = GetAncestorListView(draggedOverItem);

		if (listview) {
			ptr<TreeView>		ancestorTreeView	= (ptr<TreeView>)listview;
			ptr<TreeViewItem>	draggedTreeViewItem	= ancestorTreeView->draggedTreeViewItem;
			ptr<TreeNode>		draggedNode			= (ptr<TreeNode>)ancestorTreeView->ItemFromContainer(draggedTreeViewItem);
			ptr<TreeNode>		draggedOverNode		= (ptr<TreeNode>)ancestorTreeView->ItemFromContainer(draggedOverItem);
			ptr<TreeNode>		walkNode			= draggedOverNode->ParentNode;

			while (walkNode != nullptr && walkNode != draggedNode)
				walkNode = walkNode->ParentNode;

			if (walkNode != draggedNode && draggedNode != draggedOverNode)
				e->AcceptedOperation = DataPackageOperation::Move;
		}
	}

	void TreeViewItem::OnDragOver(ptr<DragEventArgs> e) {
		e->DragUIOverride->IsGlyphVisible = true;

		e->AcceptedOperation = DataPackageOperation::None;

		ptr<TreeViewItem> draggedOverItem = (ptr<TreeViewItem>)this;

		ptr<Controls::ListView> listview = GetAncestorListView(draggedOverItem);
		if (listview) {
			ptr<TreeView>		ancestorTreeView	= (ptr<TreeView>)listview;
			ptr<TreeViewItem>	draggedTreeViewItem	= ancestorTreeView->draggedTreeViewItem;
			ptr<TreeNode>		draggedNode			= (ptr<TreeNode>)ancestorTreeView->ItemFromContainer(draggedTreeViewItem);
			ptr<TreeNode>		draggedOverNode		= (ptr<TreeNode>)ancestorTreeView->ItemFromContainer(draggedOverItem);
			ptr<TreeNode>		walkNode			= draggedOverNode->ParentNode;

			while (walkNode != nullptr && walkNode != draggedNode)
				walkNode = walkNode->ParentNode;

			if (walkNode != draggedNode && draggedNode != draggedOverNode)
				e->AcceptedOperation = DataPackageOperation::Move;
		}
	}

	ptr<Automation::Peers::AutomationPeer> TreeViewItem::OnCreateAutomationPeer() {
		return new TreeViewItemAutomationPeer(this);
	}
}