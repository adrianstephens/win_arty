//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "Control/TreeView.h"

namespace UWPTreeControl
{
	using namespace iso_winrt;
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>

	//[::Windows::Foundation::Metadata::WebHostHidden]
	class MainPage : public bindable, public compose<MainPage, Windows::UI::Xaml::Controls::Page,
		Windows::UI::Xaml::Markup::IComponentConnector,
		Windows::UI::Xaml::Markup::IComponentConnector2
	> {
	public:
		MainPage();
		void InitializeComponent();
		void Connect(int connectionId, ptr<Platform::Object> target);
		ptr<Windows::UI::Xaml::Markup::IComponentConnector> GetBindingConnector(int connectionId, ptr<Platform::Object> target);

	private:
		void SampleTreeView_ContainerContentChanging(ptr<Windows::UI::Xaml::Controls::ListViewBase> sender, ptr<Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs> args);
		ptr<TreeViewControl::TreeNode> CreateFileNode(ptr<Platform::String> name);
		ptr<TreeViewControl::TreeNode> CreateFolderNode(ptr<Platform::String> name);

		void UnloadObject(ptr<Windows::UI::Xaml::DependencyObject> dependencyObject);
		void DisconnectUnloadedObject(int connectionId);

		bool _contentLoaded;
		ptr<TreeViewControl::TreeView> sampleTreeView;
	};
}
