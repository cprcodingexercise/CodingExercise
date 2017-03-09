//
// A simple calculator console application.
//
// Author: Wei Huang
// Date:   March 2017
//

#include <iostream>
#include <string>
#include "CalcController.h"

using std::string;
using std::cout;
using std::endl;

void usage()
{
	cout << "usage: Calculator [InputString]" << endl;
	cout << "       The calculator program takes as input a string of operators(+, -, *, and" << endl;
	cout << "       / only), parses the string and returns a number as the output(rounded to" << endl;
	cout << "       1 decimal point). The program is also able to perform batch calculations" << endl;	
	cout << "       as well; the batch input is a comma separated string of single inputs." << endl;
	cout << "       The program asks user to input string if not specified on command-line." << endl << endl;
	cout << "Example:" << endl;
	cout << "       Single calculation input:  Input(string): 2*3+4        Output: 10" << endl;
	cout << "       Batch calculation input:   Input(string): 2*5+4,6*9-3  Output: 14,51" << endl;

	exit(-1);
}

int main(int argc, char*argv[]) 
{
	string inputString;
	if (argc > 1) 
	{
		string arg = string(argv[1]);
		if (0 == arg.compare("/?"))
		{
			usage();
		}
		else
		{
			inputString = arg; // input string from command line argument
		}
	}
	else
	{		
		std::cout << "Please input a string of operators (+,-,*,and / only) and operands (integers only): ";
		std::cin >> inputString;
	}

	CalcController calcController;
	if (calcController.run(inputString))
	{
		cout << "Output: ";
		calcController.printOutputNumberList();
		cout << endl;

		return 0;
	}
	else
	{
		return -1;
	}
}