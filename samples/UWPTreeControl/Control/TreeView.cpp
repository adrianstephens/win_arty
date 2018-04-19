#include "pch.h"
#include "TreeView.h"

using namespace iso_winrt;
using namespace Platform;
using namespace Windows;
using namespace UI::Xaml;
using namespace UI::Xaml::Interop;
using namespace UI::Xaml::Controls;

namespace TreeViewControl {

	TreeView::TreeView() {
		flatViewModel	= new ViewModel;
		RootNode		= new TreeNode();

		flatViewModel->ExpandNode(RootNode);

		CanReorderItems = true;
		AllowDrop		= true;
		CanDragItems	= true;

		RootNode->VectorChanged += [this](ptr<IBindableObservableVector> sender, ptr<Object> e) {flatViewModel->TreeNodeVectorChanged(sender, e); };
		ListView::ItemClick += [this](ptr<Object> sender, ptr<Controls::ItemClickEventArgs> args) {
			ptr<ItemClickEventArgs> treeViewArgs = new ItemClickEventArgs(args->ClickedItem());
			ItemClick(this, treeViewArgs);

			if (!treeViewArgs->IsHandled) {
				ptr<TreeNode> targetNode = (ptr<TreeNode>)args->ClickedItem;
				if (targetNode->IsExpanded)
					flatViewModel->CollapseNode(targetNode);
				else
					flatViewModel->ExpandNode(targetNode);
			}
		};

		DragItemsStarting += [this](ptr<Object> sender, ptr<DragItemsStartingEventArgs> e) {
			draggedTreeViewItem = (ptr<TreeViewItem>)ContainerFromItem(e->Items->GetAt(0));
		};

		DragItemsCompleted += [this](ptr<Controls::ListViewBase> sender, ptr<DragItemsCompletedEventArgs> args) {
			draggedTreeViewItem = nullptr;
		};

		ItemsSource = flatViewModel;
	}

	void TreeView::OnDrop(ptr<Windows::UI::Xaml::DragEventArgs> e) {
		if (e->AcceptedOperation == Windows::ApplicationModel::DataTransfer::DataPackageOperation::Move) {
			ptr<Panel> panel = ItemsPanelRoot;
			Windows::Foundation::Point point = e->GetPosition(panel);

			int aboveIndex = -1;
			int belowIndex = -1;
			unsigned relativeIndex;

			ptr<IInsertionPanel> insertionPanel = (ptr<IInsertionPanel>)panel;

			if (insertionPanel != nullptr) {
				belowIndex = insertionPanel->GetInsertionIndexes(point, &aboveIndex);

				ptr<TreeNode> aboveNode = (ptr<TreeNode>)flatViewModel->GetAt(aboveIndex);
				ptr<TreeNode> belowNode = (ptr<TreeNode>)flatViewModel->GetAt(belowIndex);
				ptr<TreeNode> targetNode = (ptr<TreeNode>)ItemFromContainer(draggedTreeViewItem);

				//Between two items
				if (aboveNode && belowNode) {
					targetNode->ParentNode->IndexOf(targetNode, &relativeIndex);
					targetNode->ParentNode->RemoveAt(relativeIndex);

					if (belowNode->ParentNode == aboveNode) {
						aboveNode->InsertAt(0, targetNode);
					} else {
						aboveNode->ParentNode->IndexOf(aboveNode, &relativeIndex);
						aboveNode->ParentNode->InsertAt(relativeIndex + 1, targetNode);
					}
				}
				//Bottom of the list
				else if (aboveNode && !belowNode) {
					targetNode->ParentNode->IndexOf(targetNode, &relativeIndex);
					targetNode->ParentNode->RemoveAt(relativeIndex);

					aboveNode->ParentNode->IndexOf(aboveNode, &relativeIndex);
					aboveNode->ParentNode->InsertAt(relativeIndex + 1, targetNode);
				}
				//Top of the list
				else if (!aboveNode && belowNode) {
					targetNode->ParentNode->IndexOf(targetNode, &relativeIndex);
					targetNode->ParentNode->RemoveAt(relativeIndex);

					RootNode->InsertAt(0, targetNode);
				}
			}
		}

		e->Handled = true;
		IControlOverrides::OnDrop(e);
	}

	void TreeView::OnDragOver(ptr<Windows::UI::Xaml::DragEventArgs> e) {
		Windows::ApplicationModel::DataTransfer::DataPackageOperation savedOperation = Windows::ApplicationModel::DataTransfer::DataPackageOperation::None;

		e->AcceptedOperation = Windows::ApplicationModel::DataTransfer::DataPackageOperation::None;

		ptr<Panel> panel = ItemsPanelRoot;
		Windows::Foundation::Point point = e->GetPosition(panel);

		int aboveIndex = -1;
		int belowIndex = -1;

		ptr<IInsertionPanel> insertionPanel = (ptr<IInsertionPanel>)panel;

		if (insertionPanel != nullptr) {
			belowIndex = insertionPanel->GetInsertionIndexes(point, &aboveIndex);

			if (aboveIndex > -1) {
				ptr<TreeNode> aboveNode = (ptr<TreeNode>)flatViewModel->GetAt(aboveIndex);
				ptr<TreeNode> targetNode = (ptr<TreeNode>)ItemFromContainer(draggedTreeViewItem);

				ptr<TreeNode> ancestorNode = aboveNode;
				while (ancestorNode != nullptr && ancestorNode != targetNode)
					ancestorNode = ancestorNode->ParentNode;

				if (ancestorNode == nullptr) {
					savedOperation = Windows::ApplicationModel::DataTransfer::DataPackageOperation::Move;
					e->AcceptedOperation = Windows::ApplicationModel::DataTransfer::DataPackageOperation::Move;
				}
			} else {
				savedOperation = Windows::ApplicationModel::DataTransfer::DataPackageOperation::Move;
				e->AcceptedOperation = Windows::ApplicationModel::DataTransfer::DataPackageOperation::Move;
			}
		}

		IControlOverrides::OnDragOver(e);
		e->AcceptedOperation = savedOperation;
	}

	void TreeView::ExpandNode(ptr<TreeNode> targetNode) {
		flatViewModel->ExpandNode(targetNode);
	}

	void TreeView::CollapseNode(ptr<TreeNode> targetNode) {
		flatViewModel->CollapseNode(targetNode);
	}

	void TreeView::PrepareContainerForItemOverride(ptr<DependencyObject> element, ptr<Object> item) {
		((ptr<Windows::UI::Xaml::UIElement>)element)->AllowDrop = true;

		IItemsControlOverrides::PrepareContainerForItemOverride(element, item);
	}

	ptr<DependencyObject> TreeView::GetContainerForItemOverride() {
//		ptr<TreeViewItem> targetItem = new TreeViewItem();
		ptr<TreeViewItem> targetItem = ref_new<TreeViewItem>();
		return (ptr<DependencyObject>)targetItem;
	}
}