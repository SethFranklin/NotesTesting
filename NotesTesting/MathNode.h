
#pragma once

#include <string>

enum NodeType
{

	EXPRESSION,
	OPERATION,
	NUMBER

};

struct MathNode
{

	MathNode(std::string Expression);
	~MathNode();

	void FormTree();
	void SimplifyTree();

	NodeType Type;
	std::string Contents;
	float Number;

	MathNode* Left; // Binary tree
	MathNode* Right;

};