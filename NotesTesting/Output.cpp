
#include <iostream>

#include "Output.h"
#include "Vector3.h"
#include <string>

void Output::PrintString(char StringToPrint[])
{

	std::cout << StringToPrint << std::endl;

}

void Output::PrintString(std::string StringToPrint)
{

	std::cout << StringToPrint << std::endl;

}

void Output::PrintChar(char CharToPrint)
{

	std::cout << CharToPrint << std::endl;

}

template <class Number> void Output::PrintValue(char ValueName[], Number Value)
{

	std::cout << ValueName << ": " << Value << std::endl;

}

template void Output::PrintValue<int>(char ValueName[], int Value); // Workaround for template functions in headers. Other fix is to put implementation in header, which would increase executable size and compile time
template void Output::PrintValue<float>(char ValueName[], float Value);
template void Output::PrintValue<double>(char ValueName[], double Value);
template void Output::PrintValue<unsigned int>(char ValueName[], unsigned int Value);

void Output::ContinuePrompt()
{

	std::cout << "Press enter to continue..." << std::endl;
	std::cin.get();

}

void Output::PrintVector(std::vector<int> List)
{

	for (int Index = 0; Index < List.size(); Index++)
	{

		std::cout << List[Index];
		if (Index != List.size() - 1) std::cout << ", ";

	}

	std::cout << std::endl;

}

void Output::PrintVector(std::vector<float> List)
{

	for (int Index = 0; Index < List.size(); Index++)
	{

		std::cout << List[Index];
		if (Index != List.size() - 1) std::cout << ", ";

	}

	std::cout << std::endl;

}

void Output::PrintVector(Math::Vector3 VectorToPrint)
{

	std::cout << "(" << VectorToPrint.X << ", " << VectorToPrint.Y << ", " << VectorToPrint.Z << ")" << std::endl;

}

std::string Output::GetString(std::string Name)
{

	std::cout << Name << ": ";

	std::string Return;

	std::getline(std::cin, Return);

	return Return;

}