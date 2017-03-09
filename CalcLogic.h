#ifndef CALCLOGIC_H
#define CALCLOGIC_H

#include "TypeDef.h"
#include "TypedOutputNumber.h"
#include <deque>

using std::deque;

// The business logic layer class for evaluating parsed algebraic expression(s).

class CalcLogic
{
public:
	// @brief: evaluate all input algebraic expressions
	// @param: algebraicExpressions: input queue of parsed algebraic expression(s)
	//         outputNumberList: output queue of calculated number(s)
	// @return: void
	virtual void calculate(deque< deque<int> >& algebraicExpressions, OutputNumberList& outputNumberList);

private:
	// @brief: evaluate a algebraic expression
	// @param: leftOperand: input left operand
	//         anOperator: input operator
	//         rightOperand: input right operand
	// @return: calculation result
	float evaAlgeExp(float leftOperand, Operator anOperator, float rightOperand);
};

#endif // CALCLOGIC_H
