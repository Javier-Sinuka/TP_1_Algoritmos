#pragma once

#include "VarList.h"
#include "CharStack.h"

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string


class Assign{

private:

	string instruction;
	//VarList* list;
	//CharStack* stack;

public:

	Assign( string instruction /** VarList* list, CharStack* stack */ );

	string to_postfix(string operation, CharStack* stack);

	int HasHigherPrecedence(char op1, char op2);

	// Function to verify whether a character is operator symbol or not. 
	bool IsOperator(char C);

	// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not. 
	bool IsOperand(char C);

	int IsRightAssociative(char op);


	int GetOperatorWeight(char op);

	




};

