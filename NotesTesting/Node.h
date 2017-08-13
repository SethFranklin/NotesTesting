
#pragma once

#include <vector>

namespace Tree
{

	template <class Type> struct Node
	{

		Node(Type InitialValue);
		~Node();

		Type Value;
		Node* Left;
		Node* Right;
		Node* Parent;

		Node* Insert(Type NewValue);
		Node* Search(Type SearchValue);
		unsigned int GetSize();
		unsigned int GetDepth();
		std::vector<Type> OrderedList();

	};

}

// Implementation

template <class Type> Tree::Node<Type>::Node(Type InitialValue) // Constructor
{

	Value = InitialValue;
	Left = nullptr;
	Right = nullptr;
	Parent = nullptr;

}

template <class Type> Tree::Node<Type>::~Node() // Deconstructor
{

	if (Parent != nullptr)
	{

		if (Value < Parent->Value) Parent->Left = nullptr; // Sets parent node's pointer to a null pointer
		else Parent->Right = nullptr;

	}

	if (Left != nullptr) delete Left; // Recursively deletes both left and right nodes
	if (Right != nullptr) delete Right;

}

template <class Type> Tree::Node<Type>* Tree::Node<Type>::Insert(Type NewValue)
{

	if (NewValue == Value) return this; // Equals
	else if (NewValue < Value) // Left Branch
	{

		if (Left == nullptr) // Create new node
		{

			Left = new Node(NewValue);
			Left->Parent = this;
			return Left;


		}
		else // Recursion
		{

			return Left->Insert(NewValue);

		}

	}
	else // Right branch
	{

		if (Right == nullptr) // Create new node
		{

			Right = new Node(NewValue);
			Right->Parent = this;
			return Right;


		}
		else // Recursion
		{

			return Right->Insert(NewValue);

		}

	}

}

template <class Type> Tree::Node<Type>* Tree::Node<Type>::Search(Type SearchValue)
{

	if (SearchValue == Value) return this;
	else if (SearchValue < Value) // Left branch
	{

		if (Left == nullptr) return nullptr;
		else return Left->Search(SearchValue); // Recursion

	}
	else // Right branch
	{

		if (Right == nullptr) return nullptr;
		else return Right->Search(SearchValue); // Recursion

	}

}

template <class Type> unsigned int Tree::Node<Type>::GetSize()
{

	unsigned int Size = 1; // 1 from current node

	if (Left != nullptr) Size += Left->GetSize();
	if (Right != nullptr) Size += Right->GetSize();

	return Size;

}

template <class Type> unsigned int Tree::Node<Type>::GetDepth()
{

	unsigned int LeftDepth = 0, RightDepth = 0;

	if (Left != nullptr)
	{

		LeftDepth = 1;
		LeftDepth += Left->GetDepth(); // Recursion

	}

	if (Right != nullptr)
	{

		RightDepth = 1;
		RightDepth += Right->GetDepth(); // Recursion

	}

	return (LeftDepth > RightDepth) ? LeftDepth : RightDepth;

}

template <class Type> std::vector<Type> Tree::Node<Type>::OrderedList()
{

	std::vector<Type> List;

	if (Left != nullptr)
	{

		std::vector<Type> LeftList = Left->OrderedList(); // Recursion

		List.insert(List.end(), LeftList.begin(), LeftList.end()); // Combines the two lists

	}

	List.push_back(Value); // Adds it's own value

	if (Right != nullptr)
	{

		std::vector<Type> RightList = Right->OrderedList(); // Recursion

		List.insert(List.end(), RightList.begin(), RightList.end()); // Combines the two lists

	}

	return List;

}