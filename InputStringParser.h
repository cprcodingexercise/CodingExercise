#ifndef INPUTSTRINGPARSER_H
#define INPUTSTRINGPARSER_H

#include <string>
#include <deque>

using std::string;
using std::deque;

// The business logic layer class for parsing input string.
// It works with v1.1 format input string of operators (+,-,*, and / only) and operands (integers only). 
// It can also work with the batch input, which is a comma separated string of single inputs.
// Input string example: Single calculation input: 2*3+4
//                       Batch calculations input: 2*5+4,6*9-3

class InputStringParser
{
public:
	// @brief: parse input string
	// @param: inputString: a input string of operators (+,-,*, and / only) and operands (integers only)
	//         algebraicExpressions: output queue of parsed algebraic expression(s)
	// @return: status
	virtual bool parse(const string& inputString, deque<deque<int> >& algebraicExpressions);

private:

};

#endif  // INPUTSTRINGPARSER_H