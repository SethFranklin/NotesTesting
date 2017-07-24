
#pragma once

namespace Output
{

	void PrintString(char StringToPrint[]);
	template <class Number> void PrintValue(char ValueName[], Number Value);
	void ContinuePrompt();

}