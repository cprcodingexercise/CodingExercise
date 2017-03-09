#ifndef TYPEDOUTPUTNUMBER_H
#define TYPEDOUTPUTNUMBER_H

#include "OutputNumber.h"
#include <deque>

// The template subclass for storing different type (int/float) of output number in one list.

template< class T >
class TypedOutputNumber : public OutputNumber
{
public:
	// @brief: constructor
	TypedOutputNumber(const T& num) : number(num) 
	{		
		if (number == (int)number)
		{
			setNumberType(INT);			
		}
		else
		{
			setNumberType(FLOAT);			
		}
	};

	// @brief: get the stored output number
	// @param: void
	// @return: output number
	T getNumber()
	{
		return number;
	}

private:
	T number;  // output number
};

typedef std::deque< OutputNumber* > OutputNumberList;

#endif // TYPEDOUTPUTNUMBER_H
