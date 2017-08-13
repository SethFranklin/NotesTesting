
#include <string>
#include <vector>

#include "MathNode.h"
#include "Output.h"

struct MathNode::Impl_
{

	Impl_(std::string Expression)
	{

		Left = nullptr;
		Right = nullptr;

		Type = EXPRESSION;
		Contents = FilterExpression(Expression);
		Number = NULL;

	}

	std::string FilterExpression(std::string Expression);

	NodeType Type;
	std::string Contents;
	float Number;

	MathNode* Left; // Binary tree
	MathNode* Right;

};

MathNode::MathNode(std::string Expression)
{

	Impl = new Impl_(Expression);

}

MathNode::~MathNode()
{

	if (Impl != nullptr) delete Impl;

}

void MathNode::FormTree()
{

	// Parse addition / subtraction

	int BracketLevel = 0; // ( adds, ) subtracts

	for (int i = 0; i < Impl->Contents.length(); i++)
	{

		switch (Impl->Contents[i])
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

					Impl->Type = OPERATION;

					Impl->Left = new MathNode(Impl->Contents.substr(0, i));
					Impl->Right = new MathNode(Impl->Contents.substr(i + 1, Impl->Contents.length() - i));

					Impl->Contents = "+";

					Impl->Left->FormTree();
					Impl->Right->FormTree();

					return;

				}

				break;

			case '-':

				if (BracketLevel == 0)
				{

					Impl->Type = OPERATION;

					Impl->Left = new MathNode(Impl->Contents.substr(0, i));
					Impl->Right = new MathNode(Impl->Contents.substr(i + 1, Impl->Contents.length() - i));

					Impl->Contents = "-";

					Impl->Left->FormTree();
					Impl->Right->FormTree();

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

	for (int i = 0; i < Impl->Contents.length(); i++)
	{

		switch (Impl->Contents[i])
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

				Impl->Type = OPERATION;

				Impl->Left = new MathNode(Impl->Contents.substr(0, i));
				Impl->Right = new MathNode(Impl->Contents.substr(i + 1, Impl->Contents.length() - i));

				Impl->Contents = "*";

				Impl->Left->FormTree();
				Impl->Right->FormTree();

				return;

			}

			break;

		case '/':

			if (BracketLevel == 0)
			{

				Impl->Type = OPERATION;

				Impl->Left = new MathNode(Impl->Contents.substr(0, i));
				Impl->Right = new MathNode(Impl->Contents.substr(i + 1, Impl->Contents.length() - i));

				Impl->Contents = "/";

				Impl->Left->FormTree();
				Impl->Right->FormTree();

				return;

			}

			break;

		}

	}

	// Check for begining and end brackets, remove and redo function if it's there

	if (Impl->Contents[0] == '(' && Impl->Contents[Impl->Contents.length() - 1] == ')')
	{

		Impl->Contents = Impl->Contents.substr(1, Impl->Contents.length() - 2);

		FormTree();

		return;

	}

	// Final error checking

	int DecimalCount = 0;

	for (int i = 0; i < Impl->Contents.length(); i++)
	{

		switch (Impl->Contents[i])
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

	float NewNumber = strtof((Impl->Contents).c_str(), 0);

	Impl->Type = NUMBER;
	Impl->Number = NewNumber;

}

float MathNode::SimplifyTree()
{

	if (Impl->Type == EXPRESSION)
	{

		Output::PrintString("Tree not formed completely");
		return 0.0;

	}

	if (Impl->Type == NUMBER) return Impl->Number;

	float LeftNum = Impl->Left->SimplifyTree();
	float RightNum = Impl->Right->SimplifyTree();

	switch (Impl->Contents[0])
	{

	case '+':
		Impl->Number = LeftNum + RightNum;
		break;
	case '-':
		Impl->Number = LeftNum - RightNum;
		break;
	case '*':
		Impl->Number = LeftNum * RightNum;
		break;
	case '/':
		Impl->Number = LeftNum / RightNum;
		break;

	}

	Impl->Type = NUMBER;

	delete Impl->Left;
	delete Impl->Right;

	return Impl->Number;

}

std::string MathNode::Impl_::FilterExpression(std::string Expression)
{

	const std::string Allowed = "1234567890.()+-*/";

	std::vector<char> FilteredCharacters;

	for (int i = 0; i < int(Expression.length()); i++)
	{

		for (int j = 0; j < int(Allowed.length()); j++)
		{

			if (Expression[i] == Allowed[j]) FilteredCharacters.push_back(Expression[i]);

		}

	}

	std::string Return;

	Return.resize(FilteredCharacters.size());

	for (int i = 0; i < int(FilteredCharacters.size()); i++)
	{

		Return[i] = FilteredCharacters[i];

	}

	return Return;

}