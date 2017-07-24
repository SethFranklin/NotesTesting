
#include "Node.h"

Tree::Node::Node(int InitialValue) // Constructor
{

	Value = InitialValue;
	Left = nullptr;
	Right = nullptr;
	Parent = nullptr;

}

Tree::Node::~Node() // Deconstructor
{

	if (Parent != nullptr)
	{

		if (Value < Parent->Value) Parent->Left = nullptr; // Sets parent node's pointer to a null pointer
		else Parent->Right = nullptr;

	}

	if (Left != nullptr) delete Left; // Recursively deletes both left and right nodes
	if (Right != nullptr) delete Right;

}

Tree::Node* Tree::Node::Insert(int NewValue)
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

Tree::Node* Tree::Node::Search(int SearchValue)
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

unsigned int Tree::Node::GetSize()
{

	unsigned int Size = 1; // 1 from current node

	if (Left != nullptr) Size += Left->GetSize();
	if (Right != nullptr) Size += Right->GetSize();

	return Size;

}

unsigned int Tree::Node::GetDepth()
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

std::vector<int> Tree::Node::OrderedList()
{

	std::vector<int> List;

	if (Left != nullptr)
	{

		std::vector<int> LeftList = Left->OrderedList(); // Recursion

		List.insert(List.end(), LeftList.begin(), LeftList.end()); // Combines the two lists

	}

	List.push_back(Value); // Adds it's own value

	if (Right != nullptr)
	{

		std::vector<int> RightList = Right->OrderedList(); // Recursion

		List.insert(List.end(), RightList.begin(), RightList.end()); // Combines the two lists

	}

	return List;

}