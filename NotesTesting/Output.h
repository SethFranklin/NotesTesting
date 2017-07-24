
#pragma once

#include <vector>

#include "Vector3.h"

namespace Output
{

	void PrintString(char StringToPrint[]);
	template <class Number> void PrintValue(char ValueName[], Number Value);
	void ContinuePrompt();
	void PrintVector(std::vector<int> List);
	void PrintVector(Math::Vector3 VectorToPrint);

}