#pragma once

namespace TreeViewControl {
	using namespace iso_winrt;

	/// <summary>
	/// The TreeNode class implements the hierarchical layout for the TreeView.
	/// It also holds the data that will be bound to in the item template.
	/// </summary>
	//[Windows::UI::Xaml::Data::Bindable]
	//[Windows::Foundation::Metadata::WebHostHidden]
	class TreeNode : public bindable, public runtime<TreeNode, Windows::UI::Xaml::Interop::IBindableObservableVector, Windows::UI::Xaml::Data::INotifyPropertyChanged> {
	public:
		TreeNode();
		~TreeNode()	{}

		// IBindableVector

		ptr<Platform::Object>									GetAt(unsigned int index);
		unsigned												Size() { return childrenVector->Size; }
		ptr<Windows::UI::Xaml::Interop::IBindableVectorView>	GetView();
		bool													IndexOf(ptr<Platform::Object> value, unsigned int* index);
		void													SetAt(unsigned int index, ptr<Platform::Object> value);
		void													InsertAt(unsigned int index, ptr<Platform::Object> value);
		void													RemoveAt(unsigned int index);
		void													Append(ptr<Platform::Object> value);
		void													RemoveAtEnd();
		void													Clear();
		
		//IBindableObservableVector
		
		event<Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler>	VectorChanged;
		
		//IBindableIterable
		
		ptr<Windows::UI::Xaml::Interop::IBindableIterator>		First();

		//INotifyPropertyChanged
		
		event<Windows::UI::Xaml::Data::PropertyChangedEventHandler>				PropertyChanged;


		struct : ptr<Platform::Object> {
			void operator=(pptr<Platform::Object> value) {
				set(value);
				auto	*enc = encloser(this, &TreeNode::Data);
				enc->PropertyChanged((object)enc, ref_new<Windows::UI::Xaml::Data::PropertyChangedEventArgs>(L"Data"));
			}
		} Data;

		struct : ptr<TreeNode> {
			void operator=(pptr<TreeNode> value) {
				set(value);
				auto	*enc = encloser(this, &TreeNode::ParentNode);
				enc->PropertyChanged((object)enc, ref_new<Windows::UI::Xaml::Data::PropertyChangedEventArgs>(L"ParentNode"));
				enc->PropertyChanged((object)enc, ref_new<Windows::UI::Xaml::Data::PropertyChangedEventArgs>(L"Depth"));
			}
		} ParentNode;

		struct {
			bool v;
			operator bool() { return v; }
			void operator=(bool value) {
				auto	*enc = encloser(this, &TreeNode::IsExpanded);
				v = value;
				enc->PropertyChanged((object)enc, ref_new<Windows::UI::Xaml::Data::PropertyChangedEventArgs>(L"IsExpanded"));
			}
		} IsExpanded;

		bool HasItems() {
			return Size() != 0;
		}

		//A lone TreeNode will have a depth of -1, this is to show that it is not appended under the TreeView's invisible root node. Once added into the TreeView via that method, the depth of the node will be calculated appropriately.
		int Depth();

		//event ptr<Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler> TreeNodeChanged;

	private:
		ptr<Platform::Collections::Vector<ptr<TreeNode>>> childrenVector;
	};
}

template<> iso_winrt::member iso_winrt::members<TreeViewControl::TreeNode>::a[] = {
	make_member("Depth",			&TreeViewControl::TreeNode::Depth),
	make_member("HasItems",			&TreeViewControl::TreeNode::HasItems),
	make_member2("IsExpanded",		&TreeViewControl::TreeNode::IsExpanded, bool),
	make_member2("ParentNode",		&TreeViewControl::TreeNode::ParentNode, ptr<TreeViewControl::TreeNode>),
	make_member2("Data",			&TreeViewControl::TreeNode::Data,		ptr<Platform::Object>),
	make_member("Size",				&TreeViewControl::TreeNode::Size),
};
