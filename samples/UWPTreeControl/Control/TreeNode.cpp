
#include "pch.h"
#include "winrt/binding.h"
#include "TreeNode.h"

using namespace iso_winrt;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

namespace TreeViewControl {

	TreeNode::TreeNode() {
		childrenVector = new Platform::Collections::Vector<ptr<TreeNode>>;
		childrenVector->VectorChanged += [this](ptr<IObservableVector<ptr<TreeNode>>> sender, ptr<IVectorChangedEventArgs> e) {
			VectorChanged(this, e);
		};
		//for (int i = 0; i < 256; i++)
		//	AddRef();
	}

	void TreeNode::Append(ptr<Object> value) {
		int				count		= childrenVector->Size;
		ptr<TreeNode>	targetNode	= ref_cast<ptr<TreeNode>>(value);
		targetNode->ParentNode		= this;
		childrenVector->Append(targetNode);

		//If the count was 0 before we appended, then the HasItems property needs to change.
		if (count == 0)
			PropertyChanged((ptr<Object>)this, ref_new<PropertyChangedEventArgs>(L"HasItems"));

		PropertyChanged((ptr<Object>)this, ref_new<PropertyChangedEventArgs>(L"Size"));
	}

	void TreeNode::Clear() {
		int count = childrenVector->Size;
		ptr<TreeNode> childNode;
		for (int i = 0; i < (int)Size(); i++) {
			childNode = ref_cast<ptr<TreeNode>>(GetAt(i));
			childNode->ParentNode = nullptr;
		}

		childrenVector->Clear();

		//If the count was not 0 before we cleared, then the HasItems property needs to change.
		if (count != 0)
			PropertyChanged((ptr<Object>)this, ref_new<PropertyChangedEventArgs>(L"HasItems"));

		PropertyChanged((ptr<Object>)this, ref_new<PropertyChangedEventArgs>(L"Size"));
	}

	ptr<IBindableIterator> TreeNode::First() {
		//ptr<Platform::Collections::IObservableVector<ptr<TreeNode>>> childrenVector;
		return ref_cast<ptr<IBindableIterator>>(childrenVector->First());
	}

	ptr<Object> TreeNode::GetAt(unsigned int index) {
		if ((int)index > -1 && index < childrenVector->Size)
			return ref_cast<ptr<Object>>(childrenVector->GetAt(index));

		return nullptr;
	}

	ptr<IBindableVectorView> TreeNode::GetView() {
		//ptr<Platform::Collections::IObservableVector<ptr<TreeNode>>> childrenVector;
		return safe_cast<ptr<IBindableVectorView>>(childrenVector->GetView());
	}

	bool TreeNode::IndexOf(ptr<Object> value, unsigned int* index) {
		return childrenVector->IndexOf(ref_cast<ptr<TreeNode>>(value), index);
	}

	void TreeNode::InsertAt(unsigned int index, ptr<Object> value) {
		if ((int)index > -1 && index <= childrenVector->Size) {
			int				count		= childrenVector->Size;
			ptr<TreeNode>	targetNode	= ref_cast<ptr<TreeNode>>(value);
			targetNode->ParentNode	= this;
			childrenVector->InsertAt(index, ref_cast<ptr<TreeNode>>(value));

			//If the count was 0 before we insert, then the HasItems property needs to change.
			if (count == 0)
				PropertyChanged((ptr<Object>)this, ref_new<PropertyChangedEventArgs>(L"HasItems"));

			PropertyChanged((ptr<Object>)this, ref_new<PropertyChangedEventArgs>(L"Size"));
		}
	}

	void TreeNode::RemoveAt(unsigned int index) {
		if ((int)index > -1 && index < childrenVector->Size) {
			int				count		= childrenVector->Size;
			ptr<TreeNode>	targetNode	= childrenVector->GetAt(index);
			targetNode->ParentNode		= nullptr;
			childrenVector->RemoveAt(index);

			//If the count was 1 before we remove, then the HasItems property needs to change.
			if (count == 1)
				PropertyChanged((ptr<Object>)this, ref_new<PropertyChangedEventArgs>(L"HasItems"));

			PropertyChanged((ptr<Object>)this, ref_new<PropertyChangedEventArgs>(L"Size"));
		}
	}

	void TreeNode::RemoveAtEnd() {
		int				count		= childrenVector->Size;
		ptr<TreeNode>	targetNode	= childrenVector->GetAt(childrenVector->Size - 1);
		targetNode->ParentNode		= nullptr;
		childrenVector->RemoveAtEnd();

		//If the count was 1 before we remove, then the HasItems property needs to change.
		if (count == 1)
			PropertyChanged((ptr<Object>)this, ref_new<PropertyChangedEventArgs>(L"HasItems"));

		PropertyChanged((ptr<Object>)this, ref_new<PropertyChangedEventArgs>(L"Size"));
	}

	void TreeNode::SetAt(unsigned int index, ptr<Object> value) {
		if ((int)index > -1 && index <= childrenVector->Size) {
			childrenVector->GetAt(index)->ParentNode	= nullptr;
			ptr<TreeNode> targetNode					= ref_cast<ptr<TreeNode>>(value);
			targetNode->ParentNode						= this;
			return childrenVector->SetAt(index, targetNode);
		}
	}

	int TreeNode::Depth() {
		ptr<TreeNode>	ancestorNode	= this;
		int				depth			= -1;
		while (ancestorNode->ParentNode != nullptr) {
			depth++;
			ancestorNode = ancestorNode->ParentNode;
		}

		return depth;
	}

}