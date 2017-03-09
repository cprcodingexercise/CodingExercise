#include <iostream>
#include "InputStringParser.h"
#include "TypeDef.h"

using std::cout;
using std::endl;

bool InputStringParser::parse(const string& inputString, deque< deque<int> >& algebraicExpressions)
{
	const char* inStr = inputString.c_str();  // a pointer to the character array
	size_t strLen = inputString.length();  // number of characters

	size_t i = 0; // the character array index
	size_t leftOperand, rightOperand; // start position of operands on left- and right-hand side of a operator (+,-,*,and / only) in the input string
	size_t curOperator, nxtOperator; // position of current and next operator (+,-,*,and / only) in the input string
	size_t newExpPos = 0; // position of a new algebraic expression sub-string in the input string
	bool isNewExpression = true; // a new algebraic expression sub-string?
	deque<int> dqOperatorsOperands; // a queue of all parsed operators and operands from a single algebraic expression
	while (i < strLen)
	{
		// locate current operator and operand on the left
		if (isNewExpression)
		{
			while (('+' != inStr[i]) && ('-' != inStr[i]) && ('*' != inStr[i]) && ('/' != inStr[i]) && (i < strLen))
			{
				i++;
			}

			if (i < strLen)
			{
				curOperator = i;
			}
			else
			{
				cout << "Invalid input string: not a single operator." << endl;
				return false;
			}

			//check if there is an operand on the left-hand side of this first operator
			if (curOperator > newExpPos)
			{
				leftOperand = newExpPos;
			}
			else
			{
				cout << "Invalid input string: missing operand on the left-hand side of operator '" << inStr[curOperator] << "'." << endl;
				return false;
			}

			isNewExpression = false;
		}
		else
		{
			curOperator = nxtOperator;
			leftOperand = rightOperand;
		}

		rightOperand = curOperator + 1;  // there should be an operand on the right-hand side of current operator

		// locate next operator
		i++;  // skip current operator		
		while (('+' != inStr[i]) && ('-' != inStr[i]) && ('*' != inStr[i]) && ('/' != inStr[i]) && (',' != inStr[i]) && (i < strLen))
		{
			i++;
		}
		nxtOperator = i;

		// check if there indeed is an operand on the right-hand side of current operator
		if (rightOperand == nxtOperator)
		{
			cout << "Invalid input string: missing operand on the right-hand side of operator '" << inStr[curOperator] << "'." << endl;
			return false;
		}

		// add left operand at the end of the queue
		dqOperatorsOperands.push_back(atoi((char*)&inStr[leftOperand]));

		// add current operator at the end of the queue
		switch (inStr[curOperator])
		{
		case '+':
			dqOperatorsOperands.push_back(ADD);
			break;
		case '-':
			dqOperatorsOperands.push_back(SUB);
			break;
		case '*':
			dqOperatorsOperands.push_back(MUL);
			break;
		case '/':
			// check potential division by 0 error
			if (0 != atoi((char*)&inStr[rightOperand]))
			{
				dqOperatorsOperands.push_back(DIV);
			}
			else
			{
				cout << "Invalid input string: division by 0." << endl;
				return false;
			}
			break;
		default:
			break;
		}

		// done parsing the current single calculation input sub-string?
		if ((',' == inStr[i]) || (i == strLen))  
		{
			dqOperatorsOperands.push_back(atoi((char*)&inStr[rightOperand])); // add the last operand at the end of the queue
			algebraicExpressions.push_back(dqOperatorsOperands); // add the currrent algebraic expression at the end

			// get ready for parsing next single calculation input sub-string
			i++;  // skip ','
			newExpPos = i;
			dqOperatorsOperands.clear();
			isNewExpression = true;			
		}
	}

	return true;
}
