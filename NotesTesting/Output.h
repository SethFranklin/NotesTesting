
#pragma once

#include <vector>

namespace Output
{

	void PrintString(char StringToPrint[]);
	template <class Number> void PrintValue(char ValueName[], Number Value);
	void ContinuePrompt();
	void PrintVector(std::vector<int> List);

}