
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "Main.h"
#include "Output.h"
#include "Node.h"
#include "Vector3.h"
#include "Parse.h"

void OrderTest();
void VectorTest();
void MathTest();

void Main::Start()
{

	OrderTest();

}

void MathTest()
{

	while (true)
	{

		Output::PrintValue("Simplified", Parse::MathExpression(Output::GetString("Expression")));

		Output::ContinuePrompt();

	};

}

void VectorTest()
{

	Math::Vector3 test1 = Math::Vector3(0, 1, 2);
	Math::Vector3 test2 = Math::Vector3(3, 6, -9);

	Math::Vector3 test3 = 5.0f * -test2;

	Output::PrintVector(test3);
	Output::PrintVector(test1.Cross(test2));

	Output::PrintValue("Dot", test1 * test2);
	Output::PrintValue("Magnitude", test2.Magnitude());
	Output::PrintValue("Distance", test2.Distance(test1));
	Output::PrintValue("Normalize test", test2.Normalize().Magnitude());
	Output::PrintValue("Angle", test1.Angle(test2));

	test1 = test2;
	test2 += Math::Vector3(1, 1, 1);
	Output::PrintVector(test2);

}

void OrderTest()
{

	std::vector<float> Unrandomized, Randomized;

	for (float Index = 0.0; Index <= 1.0; Index += 0.001)
	{

		Unrandomized.push_back(Index);

	}

	while (Unrandomized.size() > 0)
	{

		float Number = Unrandomized[rand() % int(Unrandomized.size())];

		Randomized.push_back(Number);
		Unrandomized.erase(std::remove(Unrandomized.begin(), Unrandomized.end(), Number), Unrandomized.end());

	}

	Output::PrintString("Unsorted random numbers");
	Output::PrintVector(Randomized);
	Output::PrintString("Unsorted random numbers");
	Output::ContinuePrompt();
	Output::PrintString("Sorted random numbers");

	Tree::Node<float> RootNode = Tree::Node<float>(Randomized[0]);

	for (int Index = 1; Index < int(Randomized.size()); Index++)
	{

		RootNode.Insert(Randomized[Index]);

	}

	Output::PrintVector(RootNode.OrderedList());

	Output::PrintString("Sorted random numbers");
	Output::ContinuePrompt();

}