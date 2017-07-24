
#include <iostream>

#include "Output.h"

void Output::PrintString(char StringToPrint[])
{

	std::cout << StringToPrint << std::endl;

}



template <class Number> void Output::PrintValue(char ValueName[], Number Value)
{

	std::cout << ValueName << ": " << Value << std::endl;

}

template void Output::PrintValue<int>(char ValueName[], int Value); // Workaround for template functions in headers. Other fix is to put implementation in header, which would increase executable size and compile time
template void Output::PrintValue<float>(char ValueName[], float Value);
template void Output::PrintValue<double>(char ValueName[], double Value);

void Output::ContinuePrompt()
{

	std::cout << "Press enter to continue..." << std::endl;
	std::cin.get();

}