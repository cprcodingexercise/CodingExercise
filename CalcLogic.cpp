#include "CalcLogic.h"

void CalcLogic::calculate(deque< deque<int> >& algebraicExpressions, OutputNumberList& outputNumberList)
{	
	size_t numAlgeExps = algebraicExpressions.size();
	for (size_t i = 0; i < numAlgeExps; i++)
	{
		deque<int>& algeExp = algebraicExpressions[i];

		float leftOperand = (float)algeExp.front();
		algeExp.pop_front();

		Operator curOperator = (Operator)algeExp.front();
		algeExp.pop_front();

		float rightOperand = (float)algeExp.front();
		algeExp.pop_front();

		while (!algeExp.empty())
		{
			if ((MUL == curOperator) || (DIV == curOperator))
			{
				leftOperand = evaAlgeExp(leftOperand, curOperator, rightOperand);

				curOperator = (Operator)algeExp.front();
				algeExp.pop_front();

				rightOperand = (float)algeExp.front();
				algeExp.pop_front();
			}
			else // if ((ADD == curOperator) || (SUB == curOperator))
			{
				// need to check next operator
				Operator nxtOperator = (Operator)algeExp.front();
				algeExp.pop_front();

				if ((ADD == nxtOperator) || (SUB == nxtOperator))
				{
					// next operator has the same priority
					leftOperand = evaAlgeExp(leftOperand, curOperator, rightOperand);

					curOperator = nxtOperator;

					rightOperand = (float)algeExp.front();
					algeExp.pop_front();
				}
				else // (MUL == nxtOperator) || (DIV == nxtOperator)
				{
					// next operator has higher priority
					float tempOperand = (float)algeExp.front();
					algeExp.pop_front();
					
					rightOperand = evaAlgeExp(rightOperand, nxtOperator, tempOperand);
				}
			}
		}
		
		float result = evaAlgeExp(leftOperand, curOperator, rightOperand);

		if (result == (int)result)
		{
			// integer
			outputNumberList.push_back(new TypedOutputNumber<int>((int)result));
		}
		else
		{
			// float, round to 1 decimal point
			float rnum = (float)(roundf(result * 10) / 10.0);
			outputNumberList.push_back(new TypedOutputNumber<float>(rnum));
		}
	}
}

float CalcLogic::evaAlgeExp(float leftOperand, Operator anOperator, float rightOperand)
{
	float result;

	switch (anOperator)
	{
	case ADD:
		result = leftOperand + rightOperand;
		break;
	case SUB:
		result = leftOperand - rightOperand;
		break;
	case MUL:
		result = leftOperand * rightOperand;
		break;
	case DIV:
		result = leftOperand / rightOperand;
		break;
	default:
		break;
	}

	return result;
}