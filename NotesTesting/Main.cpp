
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "Main.h"
#include "Output.h"
#include "Node.h"

void Main::Start()
{

	std::vector<int> Unrandomized, Randomized;

	for (int Index = 1; Index <= 100; Index++)
	{

		Unrandomized.push_back(Index);

	}

	while (Unrandomized.size() > 0)
	{

		int Number = Unrandomized[rand() % int(Unrandomized.size())];

		Randomized.push_back(Number);
		Unrandomized.erase(std::remove(Unrandomized.begin(), Unrandomized.end(), Number), Unrandomized.end());

	}

	Output::PrintString("Unsorted random numbers");
	Output::PrintVector(Randomized);
	Output::ContinuePrompt();
	Output::PrintString("Sorted random numbers");

	Tree::Node RootNode = Tree::Node(Randomized[0]);

	for (int Index = 1; Index < int(Randomized.size()); Index++)
	{

		RootNode.Insert(Randomized[Index]);

	}

	Output::PrintVector(RootNode.OrderedList());

	Output::ContinuePrompt();

}
