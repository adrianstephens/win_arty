#pragma once

#include "pch.h"
#include "winrt/binding.h"
#include "ViewModel.h"

using namespace iso_winrt;
using namespace Platform;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Data;

namespace TreeViewControl {

	ViewModel::ViewModel() {
		flatVectorRealizedItems = new Platform::Collections::Vector<ptr<TreeNode>>();
		flatVectorRealizedItems->VectorChanged += {this, &ViewModel::UpdateTreeView};
	}

	void ViewModel::Append(ptr<Object> value) {
		ptr<TreeNode> targetNode = (ptr<TreeNode>)value;
		flatVectorRealizedItems->Append(targetNode);

		collectionChangedEventTokenVector.push_back(targetNode->VectorChanged += {this, &ViewModel::TreeNodeVectorChanged});
		propertyChangedEventTokenVector.push_back(targetNode->PropertyChanged += {this, &ViewModel::TreeNodePropertyChanged});
	}

	void ViewModel::Clear() {
		while (flatVectorRealizedItems->Size != 0)
			RemoveAtEnd();
	}

	ptr<IBindableIterator> ViewModel::First() {
		return ref_cast<ptr<IBindableIterator>>(flatVectorRealizedItems->First());
	}

	ptr<Object> ViewModel::GetAt(unsigned int index) {
		if (index < flatVectorRealizedItems->Size)
			return flatVectorRealizedItems->GetAt(index);

		return nullptr;
	}

	ptr<IBindableVectorView> ViewModel::GetView() {
		return safe_cast<ptr<IBindableVectorView>>(flatVectorRealizedItems->GetView());
	}

	bool ViewModel::IndexOf(ptr<Object> value, unsigned int* index) {
		return flatVectorRealizedItems->IndexOf((ptr<TreeNode>)value, index);
	}

	void ViewModel::InsertAt(unsigned int index, ptr<Object> value) {
		if ((int)index > -1 && (int)index <= flatVectorRealizedItems->Size) {
			ptr<TreeNode> targetNode = (ptr<TreeNode>)value;
			flatVectorRealizedItems->InsertAt(index, targetNode);

			auto eventIndex = collectionChangedEventTokenVector.begin() + index;
			collectionChangedEventTokenVector.insert(eventIndex, targetNode->VectorChanged += {this, &ViewModel::TreeNodeVectorChanged});

			eventIndex = propertyChangedEventTokenVector.begin() + index;
			propertyChangedEventTokenVector.insert(eventIndex, targetNode->PropertyChanged += {this, &ViewModel::TreeNodePropertyChanged}); 
		}
	}

	void ViewModel::RemoveAt(unsigned int index) {
		if ((int)index > -1 && (int)index < flatVectorRealizedItems->Size) {
			ptr<TreeNode> targetNode = flatVectorRealizedItems->GetAt(index);
			flatVectorRealizedItems->RemoveAt(index);

			auto eventIndex = collectionChangedEventTokenVector.begin() + index;
			targetNode->VectorChanged -= collectionChangedEventTokenVector[index];
			collectionChangedEventTokenVector.erase(eventIndex);

			eventIndex = propertyChangedEventTokenVector.begin() + index;
			targetNode->PropertyChanged -= propertyChangedEventTokenVector[index];
			propertyChangedEventTokenVector.erase(eventIndex);
		}
	}

	void ViewModel::RemoveAtEnd() {
		int index = flatVectorRealizedItems->Size - 1;

		if (index >= 0) {
			ptr<TreeNode> targetNode = flatVectorRealizedItems->GetAt(index);
			flatVectorRealizedItems->RemoveAt(index);

			auto eventIndex = collectionChangedEventTokenVector.begin() + index;
			targetNode->VectorChanged -= collectionChangedEventTokenVector[index];
			collectionChangedEventTokenVector.erase(eventIndex);

			eventIndex = propertyChangedEventTokenVector.begin() + index;
			targetNode->PropertyChanged -= propertyChangedEventTokenVector[index];
			propertyChangedEventTokenVector.erase(eventIndex);
		}
	}

	void ViewModel::SetAt(unsigned int index, ptr<Object> value) {
		if (index < flatVectorRealizedItems->Size) {
			ptr<TreeNode> targetNode = (ptr<TreeNode>)value;
			ptr<TreeNode> removeNode = flatVectorRealizedItems->GetAt(index);
			flatVectorRealizedItems->SetAt(index, targetNode);

			auto eventIndex = collectionChangedEventTokenVector.begin() + index;
			removeNode->VectorChanged -= collectionChangedEventTokenVector[index];
			collectionChangedEventTokenVector.erase(eventIndex);
			collectionChangedEventTokenVector.insert(eventIndex, targetNode->VectorChanged += {this, &ViewModel::TreeNodeVectorChanged});

			eventIndex = propertyChangedEventTokenVector.begin() + index;
			targetNode->PropertyChanged -= propertyChangedEventTokenVector[index];
			propertyChangedEventTokenVector.erase(eventIndex);
			propertyChangedEventTokenVector.insert(eventIndex, targetNode->PropertyChanged += {this, &ViewModel::TreeNodePropertyChanged});
		}
	}

	void ViewModel::ExpandNode(ptr<TreeNode> targetNode) {
		if (!targetNode->IsExpanded)
			targetNode->IsExpanded = true;
	}

	void ViewModel::CollapseNode(ptr<TreeNode> targetNode) {
		if (targetNode->IsExpanded)
			targetNode->IsExpanded = false;
	}

	void ViewModel::AddNodeToView(ptr<TreeNode> targetNode, int index) {
		InsertAt(index, targetNode);
	}

	int ViewModel::AddNodeDescendantsToView(ptr<TreeNode> targetNode, int index, int offset) {
		if (targetNode->IsExpanded) {
			for (int i = 0; i < (int)targetNode->Size(); i++) {
				ptr<TreeNode> childNode = (ptr<TreeNode>)targetNode->GetAt(i);
				offset++;
				AddNodeToView(childNode, index + offset);
				offset = AddNodeDescendantsToView(childNode, index, offset);
			}
		}

		return offset;
	}

	void ViewModel::RemoveNodeAndDescendantsFromView(ptr<TreeNode> targetNode) {
		if (targetNode->IsExpanded) {
			for (int i = 0; i < (int)targetNode->Size(); i++) {
				ptr<TreeNode> childNode = (ptr<TreeNode>)targetNode->GetAt(i);
				RemoveNodeAndDescendantsFromView(childNode);
			}
		}

		RemoveAt(IndexOf(targetNode));
	}

	int ViewModel::CountDescendants(ptr<TreeNode> targetNode) {
		int descendantCount = 0;

		for (int i = 0; i < (int)targetNode->Size(); i++) {
			ptr<TreeNode> childNode = (ptr<TreeNode>)targetNode->GetAt(i);
			descendantCount++;
			if (childNode->IsExpanded)
				descendantCount = descendantCount + CountDescendants(childNode);
		}

		return descendantCount;
	}

	int ViewModel::IndexOf(ptr<TreeNode> targetNode) {
		unsigned int index;
		return IndexOf(targetNode, &index) ? (int)index : -1;
	}

	void ViewModel::UpdateTreeView(ptr<IObservableVector<ptr<TreeNode>>> sender, ptr<IVectorChangedEventArgs> e) {
		VectorChanged(this, e);
	}

	void ViewModel::TreeNodeVectorChanged(ptr<IBindableObservableVector> sender, ptr<Platform::Object> e) {
		CollectionChange CC = ((ptr<IVectorChangedEventArgs>)e)->CollectionChange;
		switch (CC) {
			//Reset case, commonly seen when a TreeNode is cleared.
			//removes all nodes that need removing then 
			//toggles a collapse / expand to ensure order.
			case CollectionChange::Reset: {
				ptr<TreeNode>	resetNode	= (ptr<TreeNode>)sender;
				int				resetIndex	= IndexOf(resetNode);

				if (resetIndex != Size() - 1 && resetNode->IsExpanded) {
					ptr<TreeNode>	childNode	= resetNode;
					ptr<TreeNode>	parentNode	= resetNode->ParentNode;
					bool			isLastRelativeChild = true;

					while (parentNode != nullptr && isLastRelativeChild) {
						unsigned int relativeIndex;
						parentNode->IndexOf(childNode, &relativeIndex);
						if (parentNode->Size() - 1 != relativeIndex) {
							isLastRelativeChild = false;
						} else {
							childNode = parentNode;
							parentNode = parentNode->ParentNode;
						}
					}

					int stopIndex;
					if (parentNode != nullptr) {
						unsigned int siblingIndex;
						parentNode->IndexOf(childNode, &siblingIndex);
						ptr<TreeNode> siblingNode = (ptr<TreeNode>)parentNode->GetAt(siblingIndex + 1);
						stopIndex = IndexOf(siblingNode);
					} else {
						stopIndex = Size();
					}

					for (int i = stopIndex - 1; i > resetIndex; i--) {
						if ((flatVectorRealizedItems->GetAt(i))->ParentNode == nullptr)
							RemoveNodeAndDescendantsFromView(flatVectorRealizedItems->GetAt(i));
					}

					if (resetNode->IsExpanded) {
						CollapseNode(resetNode);
						ExpandNode(resetNode);
					}
				}

				break;
			}

			//Inserts the TreeNode into the correct index of the ViewModel
			case CollectionChange::ItemInserted: {
				//We will find the correct index of insertion by first checking if the
				//node we are inserting into is expanded. If it is we will start walking
				//down the tree and counting the open items. This is to ensure we place
				//the inserted item in the correct index. If along the way we bump into
				//the item being inserted, we insert there then return, because we don't
				//need to do anything further.
				unsigned int index = ((ptr<IVectorChangedEventArgs>)e)->Index;
				ptr<TreeNode>	targetNode	= (ptr<TreeNode>)sender->GetAt(index);
				ptr<TreeNode>	parentNode	= targetNode->ParentNode;
				int				parentIndex	= IndexOf(parentNode);
				int				allOpenedDescendantsCount = 0;

				if (parentNode->IsExpanded) {
					for (int i = 0; i < (int)parentNode->Size(); i++) {
						ptr<TreeNode>	childNode = (ptr<TreeNode>)parentNode->GetAt(i);

						if (childNode == targetNode) {
							AddNodeToView(targetNode, (parentIndex + i + 1 + allOpenedDescendantsCount));
							if (targetNode->IsExpanded)
								AddNodeDescendantsToView(targetNode, parentIndex + i + 1, allOpenedDescendantsCount);
							return;
						}

						if (childNode->IsExpanded)
							allOpenedDescendantsCount += CountDescendants(childNode);
					}

					AddNodeToView(targetNode, (parentIndex + parentNode->Size() + allOpenedDescendantsCount));
					if (targetNode->IsExpanded)
						AddNodeDescendantsToView(targetNode, parentIndex + parentNode->Size(), allOpenedDescendantsCount);
				}

				break;
			}

			//Removes a node from the ViewModel when a TreeNode removes a child.
			case CollectionChange::ItemRemoved: {
				ptr<TreeNode> removeNode = (ptr<TreeNode>)sender;
				int removeIndex = IndexOf(removeNode);

				if (removeIndex != Size() - 1 && removeNode->IsExpanded) {
					ptr<TreeNode>	childNode	= removeNode;
					ptr<TreeNode>	parentNode	= removeNode->ParentNode;
					bool			isLastRelativeChild = true;
					while (parentNode != nullptr && isLastRelativeChild) {
						unsigned int relativeIndex;
						parentNode->IndexOf(childNode, &relativeIndex);
						if (parentNode->Size() - 1 != relativeIndex) {
							isLastRelativeChild = false;
						} else {
							childNode = parentNode;
							parentNode = parentNode->ParentNode;
						}
					}

					int		stopIndex;
					if (parentNode != nullptr) {
						unsigned int siblingIndex;
						parentNode->IndexOf(childNode, &siblingIndex);
						ptr<TreeNode> siblingNode = (ptr<TreeNode>)parentNode->GetAt(siblingIndex + 1);
						stopIndex = IndexOf(siblingNode);
					} else {
						stopIndex = Size();
					}

					for (int i = stopIndex - 1; i > removeIndex; i--) {
						if ((flatVectorRealizedItems->GetAt(i))->ParentNode == nullptr)
							RemoveNodeAndDescendantsFromView(flatVectorRealizedItems->GetAt(i));
					}
				}

				break;
			}

			//Triggered by a replace such as SetAt.
			//Updates the TreeNode that changed in the ViewModel.
			case CollectionChange::ItemChanged: {
				unsigned int index = ((ptr<IVectorChangedEventArgs>)e)->Index;
				ptr<TreeNode>	targetNode = (ptr<TreeNode>)sender->GetAt(index);
				ptr<TreeNode>	parentNode = targetNode->ParentNode;
				int				allOpenedDescendantsCount = 0;
				int				parentIndex = IndexOf(parentNode);

				for (int i = 0; i < (int)parentNode->Size(); i++) {
					ptr<TreeNode> childNode = (ptr<TreeNode>)parentNode->GetAt(i);
					if (childNode->IsExpanded)
						allOpenedDescendantsCount += CountDescendants(childNode);
				}

				ptr<TreeNode> removeNode = (ptr<TreeNode>)GetAt(parentIndex + index + allOpenedDescendantsCount + 1);
				if (removeNode->IsExpanded)
					CollapseNode(removeNode);

				RemoveAt(parentIndex + index + allOpenedDescendantsCount + 1);
				InsertAt(parentIndex + index + allOpenedDescendantsCount + 1, targetNode);

				break;
			}

		}
	}

	void ViewModel::TreeNodePropertyChanged(ptr<Object> sender, ptr<PropertyChangedEventArgs> e) {
		if (e->PropertyName == L"IsExpanded") {
			ptr<TreeNode> targetNode = (ptr<TreeNode>)sender;
			if (targetNode->IsExpanded) {
				if (targetNode->Size() != 0) {
					int openedDescendantOffset = 0;
					int index	= IndexOf(targetNode) + 1;

					for (int i = 0; i < (int)targetNode->Size(); i++) {
						ptr<TreeNode>	childNode = (ptr<TreeNode>)targetNode->GetAt(i);
						AddNodeToView(childNode, ((int)index + i + openedDescendantOffset));
						openedDescendantOffset = AddNodeDescendantsToView(childNode, (index + i), openedDescendantOffset);
					}
				}
			} else {
				for (int i = 0; i < (int)targetNode->Size(); i++)
					RemoveNodeAndDescendantsFromView((ptr<TreeNode>)targetNode->GetAt(i));
			}
		}
	}
}