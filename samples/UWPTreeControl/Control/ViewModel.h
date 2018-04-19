#pragma once
#include "TreeNode.h"
#include "base/array.h"

namespace TreeViewControl {
	using namespace iso_winrt;

	/// <summary>
	/// The ViewModel is responsible for flattening the heirarchical data into a flat list.
	/// It also tracks changes to the underlying data and updates the flat list accordingly.
	/// </summary>
//	[Windows::Foundation::Metadata::WebHostHidden]
	class ViewModel : public runtime<ViewModel, Windows::UI::Xaml::Interop::IBindableObservableVector> {
	internal:
		ViewModel();

	public:
		/// <summary>
		/// Add root to the view model. In other cases the app should not 
		/// use this api.
		/// </summary>
		virtual void Append(ptr<Platform::Object> value);

		virtual void Clear();

		virtual ptr<Windows::UI::Xaml::Interop::IBindableIterator> First();

		virtual ptr<Platform::Object> GetAt(unsigned int index);

		virtual ptr<Windows::UI::Xaml::Interop::IBindableVectorView> GetView();

		virtual bool IndexOf(ptr<Platform::Object> value, unsigned int* index);

		virtual void InsertAt(unsigned int index, ptr<Platform::Object> value);

		virtual void RemoveAt(unsigned int index);

		virtual void RemoveAtEnd();

		virtual void SetAt(unsigned int index, ptr<Platform::Object> value);

		virtual unsigned int Size() {
			return flatVectorRealizedItems->Size;
		};
		event<Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler> VectorChanged;
		/// <summary>
		/// ExpandNode adds the children and all open descendants of the targetNode 
		/// to the ViewModel in their correct flattened index.
		/// </summary>
		void ExpandNode(ptr<TreeNode> targetNode);

		/// <summary>
		/// Collapse node removes all the descendants of the targetNode from the ViewModel.
		/// </summary>
		void CollapseNode(ptr<TreeNode> targetNode);

		/// <summary>
		/// This is the collection changed handler for individual TreeNodes. The collection changes
		/// from the hierarchical TreeNodes need to be flattened so that we can keep our current 
		/// flat list in sync.
		/// </summary>
		/// <param name="sender">TreeNode that has already been changed</param>
		void TreeNodeVectorChanged(ptr<Windows::UI::Xaml::Interop::IBindableObservableVector> sender, ptr<Platform::Object> e);

		void TreeNodePropertyChanged(ptr<Platform::Object> sender, ptr<Windows::UI::Xaml::Data::PropertyChangedEventArgs> e);

	private:
		//event ptr<Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler> ViewModelChanged;

		ptr<Platform::Collections::Vector<ptr<TreeNode>>> flatVectorRealizedItems;// = ref new Platform::Collections::Vector<ptr<TreeNode>>();

		dynamic_array<Windows::Foundation::EventRegistrationToken> collectionChangedEventTokenVector;

		dynamic_array<Windows::Foundation::EventRegistrationToken> propertyChangedEventTokenVector;

		void AddNodeToView(ptr<TreeNode> targetNode, int index);

		int AddNodeDescendantsToView(ptr<TreeNode> targetNode, int start, int offset);

		void RemoveNodeAndDescendantsFromView(ptr<TreeNode> targetNode);

		int CountDescendants(ptr<TreeNode> targetNode);

		int IndexOf(ptr<TreeNode> targetNode);

		void UpdateTreeView(ptr<Windows::Foundation::Collections::IObservableVector<ptr<TreeNode>>> sender, ptr<Windows::Foundation::Collections::IVectorChangedEventArgs> e);
	};
}