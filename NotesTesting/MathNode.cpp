
#include <string>

#include "MathNode.h"
#include "Output.h"

MathNode::MathNode(std::string Expression)
{

	Left = nullptr;
	Right = nullptr;

	Type = EXPRESSION;
	Contents = Expression;
	Number = NULL;

}

MathNode::~MathNode()
{



}

void MathNode::FormTree()
{

	// Parse addition / subtraction

	int BracketLevel = 0; // ( adds, ) subtracts

	for (int i = 0; i < Contents.length(); i++)
	{

		switch (Contents[i])
		{

			case '(':

				BracketLevel++;
				break;

			case ')':

				BracketLevel--;

				if (BracketLevel < 0)
				{

					Output::PrintString("Brackets error");
					return;

				}
				
				break;

			case '+':

				if (BracketLevel == 0)
				{

					Type = OPERATION;

					Left = new MathNode(Contents.substr(0, i));
					Right = new MathNode(Contents.substr(i + 1, Contents.length() - i));

					Contents = "+";

					Left->FormTree();
					Right->FormTree();

					return;

				}

				break;

			case '-':

				if (BracketLevel == 0)
				{

					Type = OPERATION;

					Left = new MathNode(Contents.substr(0, i));
					Right = new MathNode(Contents.substr(i + 1, Contents.length() - i));

					Contents = "-";

					Left->FormTree();
					Right->FormTree();

					return;

				}

				break;

		}

	}

	if (BracketLevel != 0)
	{

		Output::PrintString("Brackets error");
		return;

	}

	BracketLevel = 0;

	// Parse multiplication / division

	for (int i = 0; i < Contents.length(); i++)
	{

		switch (Contents[i])
		{

		case '(':

			BracketLevel++;
			break;

		case ')':

			BracketLevel--;

			if (BracketLevel < 0)
			{

				Output::PrintString("Brackets error");
				return;

			}

			break;

		case '*':

			if (BracketLevel == 0)
			{

				Type = OPERATION;

				Left = new MathNode(Contents.substr(0, i));
				Right = new MathNode(Contents.substr(i + 1, Contents.length() - i));

				Contents = "*";

				Left->FormTree();
				Right->FormTree();

				return;

			}

			break;

		case '/':

			if (BracketLevel == 0)
			{

				Type = OPERATION;

				Left = new MathNode(Contents.substr(0, i));
				Right = new MathNode(Contents.substr(i + 1, Contents.length() - i));

				Contents = "/";

				Left->FormTree();
				Right->FormTree();

				return;

			}

			break;

		}

	}

	// Check for begining and end brackets, remove and redo function if it's there

	if (Contents[0] == '(' && Contents[Contents.length() - 1] == ')')
	{

		Contents = Contents.substr(1, Contents.length() - 2);

		FormTree();

		return;

	}

	// Final error checking

	int DecimalCount = 0;

	for (int i = 0; i < Contents.length(); i++)
	{

		switch (Contents[i])
		{

			case '(':

				Output::PrintString("Brackets error");
				return;
				break;

			case ')':

				Output::PrintString("Brackets error");
				return;
				break;

			case '.':

				DecimalCount++;

				if (DecimalCount > 1)
				{

					Output::PrintString("Decimal place error");
					return;

				}

				break;

		}

	}

	// If no brackets, turn into numbers, end recursion

	float NewNumber = strtof((Contents).c_str(), 0);

	Type = NUMBER;
	Number = NewNumber;

}

void MathNode::SimplifyTree()
{

	if (Type == EXPRESSION)
	{

		Output::PrintString("Tree not formed completely");
		return;

	}

	if (Type == NUMBER) return;

	Left->SimplifyTree();
	Right->SimplifyTree();

	switch (Contents[0])
	{

	case '+':
		Number = Left->Number + Right->Number;
		break;
	case '-':
		Number = Left->Number - Right->Number;
		break;
	case '*':
		Number = Left->Number * Right->Number;
		break;
	case '/':
		Number = Left->Number / Right->Number;
		break;


	}

	Type = NUMBER;

	delete Left;
	delete Right;

	return;

}