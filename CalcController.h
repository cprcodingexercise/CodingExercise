#ifndef CALCCONTROLLER_H
#define CALCCONTROLLER_H

#include "TypeDef.h"
#include "TypedOutputNumber.h"
#include <string>
#include <deque>

using std::string;
using std::deque;

// The presentation layer controller class.

class CalcController
{
public:
	// @brief: default constructor
	CalcController();

	// @brief: destructor
	~CalcController();
	
	// @brief: run a new operation
	// @param: inputString: a input string of operators (+,-,*, and / only) and operands (integers only)
	// @return: status 
	bool run(const string& inputString);

	// @brief: reset the object for a new operation
	// @param: void
	// @return: void
	void reset();

	// @brief: return the output number list
	// @param: void
	// @return: reference to output number list 
	const OutputNumberList& getOutputNumberList() const;

	// @brief: print the output number(s) in a row (comma separated if applicable) on a console
	// @param: void
	// @return: void
	void printOutputNumberList();

private:
	// @brief: verify a input string only contains '+', '-', '*', '/' and number ('0'-'9') characters
	// @param: inputString: a input string of operators and operands
	// @return: status
	bool verifyInputString(const string& inputString);

	// @brief: clear the output number list for a new operation
	// @param: void
	// @return: void
	void clearOutputNumberList();

	// @brief: clear the algebraic expressions queue for a new operation
	// @param: void
	// @return: void
	void clearAlgebraicExpressions();	
	
	// @brief: disallow the assignment operator
	CalcController& operator=(CalcController&) {}

	// @brief: disallow the copy constructor
	CalcController(const CalcController&) {}
	

	deque< deque<int> > algebraicExpressions;  // the parsed algebraic expression queue
	OutputNumberList outputNumberList;  // the output number list
};

#endif // CALCCONTROLLER_H