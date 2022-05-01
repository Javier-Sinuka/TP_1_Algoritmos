#include "Assign.h"



Assign::Assign(string instruction /**VarList* list, CharStack* stack*/) {

	this->instruction = instruction;
	cout << "Hola soy el constructor del orto" << endl;
	//this->list = list;
	//this->stack = stack;
} 



string Assign::to_postfix(string operation, CharStack* stack) {

	// Declaring a Stack from Standard template library in C++. 

	string postfix = ""; // Initialize postfix as empty string.
	for (int i = 0; i < operation.length(); i++) {

		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if (operation[i] == ' ' || operation[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if (IsOperator(operation[i]))
		{
			while (!stack->is_empty() && stack->get_top()->get_Value() != '(' && HasHigherPrecedence(stack->get_top()->get_Value(), operation[i]))
			{
				postfix += stack->get_top()->get_Value();
				stack->pop();
			}
			stack->push(operation[i]);
		}
		// Else if character is an operand
		else if (IsOperand(operation[i]))
		{
			postfix += operation[i];
		}

		else if (operation[i] == '(')
		{
			stack->push(operation[i]);
		}

		else if (operation[i] == ')')
		{
			while (!stack->is_empty() && stack->get_top()->get_Value() != '(') {
				postfix += stack->get_top()->get_Value();
				stack->pop();
			}
			stack->pop();
		}
	}

	while (!stack->is_empty()) {
		postfix += stack->get_top()->get_Value();
		stack->pop();
	}

	return postfix;


}

int Assign::HasHigherPrecedence(char op1, char op2) {

	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative. 
	// return false, if right associative. 
	// if operator is left-associative, left one should be given priority. 
	if (op1Weight == op2Weight)
	{
		if (IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ? true : false;


}

// Function to verify whether a character is operator symbol or not. 
bool Assign::IsOperator(char C) {

	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$') {

		return true;
	}

	return false;

};

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not. 
bool Assign::IsOperand(char C) {

	if (C >= '0' && C <= '9') { return true; }
	if (C >= 'a' && C <= 'z') { return true; }
	if (C >= 'A' && C <= 'Z') { return true; }
	return false;


};

int Assign::IsRightAssociative(char op) {

	if (op == '$') { return true; };
	return false;
}

int Assign::GetOperatorWeight(char op) {

	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;

};
