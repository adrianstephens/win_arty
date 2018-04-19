//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "FileSystemData.h"

using namespace UWPTreeControl;
using namespace TreeViewControl;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

object Find(object obj, hstring_ref name) {
	for (int i = 0; i < VisualTreeHelper::GetChildrenCount(obj); i++) {
		ptr<Windows::UI::Xaml::FrameworkElement> child = VisualTreeHelper::GetChild(obj, i);
		hstring	childname = child->Name;
		ISO_TRACEF(childname) << '\n';

		if (childname == name)
			return child;

		if (auto p = Find(child, name))
			return p;
	}
	return nullptr;
}

TreeNode	*cci;

MainPage::MainPage() : _contentLoaded(false) {
	InitializeComponent();

	ptr<TreeNode> workFolder = CreateFolderNode(L"Work Documents");
	workFolder->Append(CreateFileNode(L"Feature Functional Spec"));
	workFolder->Append(CreateFileNode(L"Feature Schedule"));
	workFolder->Append(CreateFileNode(L"Overall Project Plan"));
	workFolder->Append(CreateFileNode(L"Feature Resource allocation"));
	if (!sampleTreeView) {
//		for (auto &i : Resources()) {
//			hstring	name = ((ptr<IPropertyValue>)i->Key())->GetString();
//			ISO_TRACEF(name) << '\n';
//		}

		sampleTreeView	= Find((object)this, L"sampleTreeView");
	}

	sampleTreeView->RootNode->Append(workFolder);

	auto remodelFolder = CreateFolderNode(L"Home Remodel");
//	remodelFolder->IsExpanded = true;
	auto	p = CreateFileNode(L"Contactor Contact Information");
	cci = p;
	remodelFolder->Append(p);
//	remodelFolder->Append(CreateFileNode(L"Contactor Contact Information"));
	remodelFolder->Append(CreateFileNode(L"Paint Color Scheme"));
	remodelFolder->Append(CreateFileNode(L"Flooring woodgrain types"));
	remodelFolder->Append(CreateFileNode(L"Kitchen cabinet styles"));

	auto personalFolder = CreateFolderNode(L"Personal Documents");
	personalFolder->IsExpanded = true;
	personalFolder->Append(remodelFolder);
	sampleTreeView->RootNode->Append(personalFolder);

	sampleTreeView->ContainerContentChanging += [](ptr<ListViewBase> sender, ptr<ContainerContentChangingEventArgs> args) {
		if (auto node = ref_cast<ptr<TreeNode>>(args->Item())) {
			if (auto data = ref_cast<ptr<FileSystemData>>(node->Data))
				args->ItemContainer->AllowDrop = data->IsFolder;
		}
	};
}

ptr<TreeNode> MainPage::CreateFileNode(ptr<String> name) {
	auto data = new FileSystemData(name);
	auto treeNode = new TreeNode();
	treeNode->Data = (object)data;
	return treeNode;
}

ptr<TreeNode> MainPage::CreateFolderNode(ptr<String> name) {
	auto data = new FileSystemData(name);
	data->IsFolder = true;
	auto treeNode = new TreeNode();
	treeNode->Data = (object)data;
	return treeNode;
}

uint8	bytes[256];
uint32	ints[256], flag_ints[32];
void MainPage::InitializeComponent() {
	for (int i = 0; i < 256; i++)
		ints[i] = bytes[i] = i;
	for (int i = 0; i < 32; i++)
		flag_ints[i] = 1 << i;

	if (!_contentLoaded) {
		_contentLoaded = true;
		ptr<Windows::Foundation::Uri> resourceLocator = ref_new<Windows::Foundation::Uri>(L"ms-appx:///MainPage.xaml");
		Application::LoadComponent((ptr<Object>)this, resourceLocator, Primitives::ComponentResourceLocation::Application);
	}
}

void MainPage::Connect(int connectionId, ptr<Platform::Object> target) {
	switch (connectionId) {
		case 1:
			sampleTreeView = safe_cast<ptr<TreeViewControl::TreeView>>(target);
		break;
	}
}
ptr<Windows::UI::Xaml::Markup::IComponentConnector> MainPage::GetBindingConnector(int connectionId, ptr<Platform::Object> target) {
	return nullptr;
}

