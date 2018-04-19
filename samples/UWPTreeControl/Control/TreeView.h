#pragma once

#include "winrt/binding.h"
#include "TreeNode.h"
#include "ViewModel.h"
#include "TreeViewItem.h"
#include "TreeView.h"
#include "TreeViewItemAutomationPeer.h"
//#include "IntegerToIndentationConverter.h"

#define override

namespace TreeViewControl {
	using namespace iso_winrt;

	//[Windows::Foundation::Metadata::WebHostHidden]
	class TreeView : public bindable, public compose<TreeView, Windows::UI::Xaml::Controls::ListView> {
		typedef Windows::UI::Xaml::DependencyObject	DependencyObject;
	public:
		class ItemClickEventArgs : public runtime<ItemClickEventArgs, Platform::Object> {
		public:
			ItemClickEventArgs(ptr<Platform::Object> item) : ClickedItem(item) {}

			ptr<Platform::Object> ClickedItem;
			bool IsHandled = false;
		};


		typedef delegate<void(ptr<TreeView> sender, ptr<ItemClickEventArgs> args)> ItemClickHandler;

		TreeView();

		//This event is used to expose an alternative to itemclick to developers.
		event<ItemClickHandler> ItemClick;

		//This RootNode property is used by the TreeView to handle additions into the TreeView and
		//accurate VectorChange with multiple 'root level nodes'. This node will not be placed
		//in the flatViewModel, but has it's vectorchanged event hooked up to flatViewModel's
		//handler.
		ptr<TreeNode> RootNode;

		void ExpandNode(ptr<TreeNode> targetNode);
		void CollapseNode(ptr<TreeNode> targetNode);

	//protected:
		void PrepareContainerForItemOverride(ptr<DependencyObject> element, ptr<Platform::Object> item) override;
		ptr<DependencyObject> GetContainerForItemOverride() override;

		void OnDrop(ptr<Windows::UI::Xaml::DragEventArgs> e) override;
		void OnDragOver(ptr<Windows::UI::Xaml::DragEventArgs> e) override;

	private:
		ptr<ViewModel> flatViewModel;

	internal:
		ptr<TreeViewItem> draggedTreeViewItem;
	};
}

template<> iso_winrt::member iso_winrt::members<TreeViewControl::TreeView>::a[] = {
	make_member2("RootNode",			&TreeViewControl::TreeView::RootNode, ptr<TreeViewControl::TreeNode>),
};

#undef override
