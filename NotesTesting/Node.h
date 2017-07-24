
#pragma once

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

	};

}