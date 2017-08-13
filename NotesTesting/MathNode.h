
#pragma once

#include <string>

enum NodeType
{

	EXPRESSION,
	OPERATION,
	NUMBER

};

class MathNode
{

public:

	MathNode(std::string Expression);
	~MathNode();

	void FormTree();
	float SimplifyTree();

private:

	class Impl_;
	Impl_* Impl;

};