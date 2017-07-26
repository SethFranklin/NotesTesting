
#include <string>
#include <vector>

#include "Parse.h"
#include "MathNode.h"
#include "Output.h"

std::string FilterExpression(std::string Expression);

std::string Allowed = "1234567890.()+-*/";

float Parse::MathExpression(std::string Expression)
{

	std::string Filtered = FilterExpression(Expression);

	MathNode Root = MathNode(Filtered);

	Root.FormTree();
	Root.SimplifyTree();

	return Root.Number;

}

std::string FilterExpression(std::string Expression)
{

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