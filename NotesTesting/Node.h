
#pragma once

#include <vector>

namespace Tree
{

	struct Node
	{

		Node(int InitialValue);
		~Node();

		int Value;
		Node* Left;
		Node* Right;
		Node* Parent;

		Node* Insert(int NewValue);
		Node* Search(int SearchValue);
		unsigned int GetSize();
		unsigned int GetDepth();
		std::vector<int> OrderedList();

	};

}