
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

	if (Value < Parent->Value) Parent->Left == nullptr; // Sets parent node's pointer to a null pointer
	else Parent->Right == nullptr;

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
		else return (*Left).Search(SearchValue); // Recursion

	}
	else // Right branch
	{

		if (Right == nullptr) return nullptr;
		else return (*Right).Search(SearchValue); // Recursion

	}

}