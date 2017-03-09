#include <iostream>
#include "CalcController.h"
#include "CalcLogic.h"
#include "InputStringParser.h"

using std::cout;
using std::endl;

CalcController::CalcController()
{
}

CalcController::~CalcController()
{
	clearOutputNumberList();
}

bool CalcController::run(const string& inputString)
{	
	bool status = verifyInputString(inputString);
	if (false == status)
	{
		return false;
	}

	reset();

	InputStringParser inStrParser;
	status = inStrParser.parse(inputString, algebraicExpressions);
	if (false == status)
	{
		return false;
	}

	CalcLogic calcLogic;
	calcLogic.calculate(algebraicExpressions, outputNumberList);

	return true;
}

const OutputNumberList& CalcController::getOutputNumberList() const
{
	return outputNumberList;
}

void CalcController::printOutputNumberList()
{
	size_t n = outputNumberList.size(); // number of output numbers
	for (size_t i = 0; i < n; i++)
	{
		if (outputNumberList[i]->getNumberType() == INT)
		{
			cout << ((TypedOutputNumber<int>*)outputNumberList[i])->getNumber();
		}
		else // if (outputNumberList[i]->getNumberType() == FLOAT)
		{
			cout << ((TypedOutputNumber<float>*)outputNumberList[i])->getNumber();
		}

		if (i < n - 1)
		{
			cout << ","; // numbers are separated by comma
		}
	}

	cout << endl;
}

bool CalcController::verifyInputString(const string& inputString)
{
	const char* inStr = inputString.c_str();  // a pointer to the character array
	size_t strLen = inputString.length();  // number of characters
	for (size_t i = 0; i < strLen; i++)
	{
		char ch = inStr[i];
		if (! (((ch > '0') && (ch < '9')) || ('+' == ch) || ('-' == ch) || ('*' == ch) || ('/' == ch) || (',' == ch)))
		{
			cout << "Invalid input string: has invalid character '" << ch << "'." << endl;
			return false;
		}
	}

	return true;
}

void CalcController::reset()
{
	clearAlgebraicExpressions();
	clearOutputNumberList();
}

void CalcController::clearOutputNumberList()
{
	if (!outputNumberList.empty())
	{
		size_t n = outputNumberList.size();
		for (size_t i = 0; i < n; i++)
		{
			delete outputNumberList[i];
		}

		outputNumberList.clear();
	}
}

void CalcController::clearAlgebraicExpressions()
{
	if (!algebraicExpressions.empty())
	{
		algebraicExpressions.clear();
	}
}