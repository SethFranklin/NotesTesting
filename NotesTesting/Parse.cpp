
#include <string>

#include "Parse.h"
#include "MathNode.h"

float Parse::MathExpression(std::string Expression)
{

	MathNode Root = MathNode(Expression);

	Root.FormTree();

	return Root.SimplifyTree();

}