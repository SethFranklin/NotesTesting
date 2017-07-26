
#pragma once

#include <vector>
#include <string>

#include "Vector3.h"

namespace Output
{

	void PrintString(char StringToPrint[]);
	void PrintString(std::string StringToPrint);
	void PrintChar(char CharToPrint);
	template <class Number> void PrintValue(char ValueName[], Number Value);
	void ContinuePrompt();
	void PrintVector(std::vector<int> List);
	void PrintVector(Math::Vector3 VectorToPrint);
	std::string GetString(std::string Name);

}