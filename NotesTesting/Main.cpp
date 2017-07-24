
#include <iostream>

#include "Main.h"
#include "Output.h"
#include "Node.h"

void Main::Start()
{

	Output::PrintString("test");
	Output::PrintValue<float>("value", 25.4f);
	Output::PrintValue<int>("value", 23);

	Tree::Node RootNode = Tree::Node(5);
	RootNode.Insert(3);
	RootNode.Insert(2);
	RootNode.Insert(1);

	//delete RootNode.Search(1);

	Output::PrintValue<int>("a", RootNode.Search(1)->Value);

	Output::ContinuePrompt();

}
