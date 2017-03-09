#ifndef OUTPUTNUMBER_H
#define OUTPUTNUMBER_H

enum NumberType { INT, FLOAT };

// The superclass for storing different type (int/float) of output number in one list.

class OutputNumber
{
public:
	// @brief: constructor
	OutputNumber() {};

	// @brief: destructor
	virtual ~OutputNumber() {};

	// @brief: get the data type of the stored output number
	// @param: void
	// @return: number data type (int/float)
	NumberType getNumberType()
	{
		return numberType;
	}

	// @brief: set the data type  of the stored output number
	// @param: number data type (int/float)
	// @return: void	
	void setNumberType(NumberType numType)
	{
		numberType = numType;
	}

private:
	NumberType numberType;  // data type of the output number (int/float)
};

#endif // OUTPUTNUMBER_H