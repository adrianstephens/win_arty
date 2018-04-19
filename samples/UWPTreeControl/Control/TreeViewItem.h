#pragma once
#define override

namespace TreeViewControl {
	using namespace iso_winrt;

//	[Windows::Foundation::Metadata::WebHostHidden]
//	[Windows::UI::Xaml::Data::Bindable]
	class TreeViewItem : public bindable, public compose<TreeViewItem, Windows::UI::Xaml::Controls::ListViewItem> {
	public:
		TreeViewItem()	{}
		~TreeViewItem()	{}

	//private:
		ptr<Windows::UI::Xaml::Controls::ListView> GetAncestorListView(ptr<TreeViewItem> targetItem);

	//protected:
		void OnDrop(ptr<Windows::UI::Xaml::DragEventArgs> e) override;
		void OnDragEnter(ptr<Windows::UI::Xaml::DragEventArgs> e) override;
		void OnDragOver(ptr<Windows::UI::Xaml::DragEventArgs> e) override;
		ptr<Windows::UI::Xaml::Automation::Peers::AutomationPeer> OnCreateAutomationPeer() override;
	};
}

#undef override
