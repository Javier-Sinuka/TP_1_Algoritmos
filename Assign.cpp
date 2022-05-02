#include "Assign.h"
#include <iostream>


/**#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string */ 



Assign::Assign(string instruct,VarList* list,CharStack* stack,IntStack* Stackint) {

	
	instruction = instruct;
	cout << "Hola soy el constructor del orto" << endl;
	this->list = list;
	this->stack = stack;
} 



string Assign::to_postfix(string operation, CharStack* stack) {

	string postfix = ""; // Initialize postfix as empty string.
	for (int i = 0; i < operation.length(); i++) {

		// Scanning each character from left.If character is a delimitter, move on. 
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

	if (C == '+' || C == '-' || C == '*' || C == '/') {

		return true;
	}

	return false;

}

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not. 
bool Assign::IsOperand(char C) {

	if (C >= '0' && C <= '9') { return true; }
	if (C >= 'a' && C <= 'z') { return true; }
	if (C >= 'A' && C <= 'Z') { return true; }
	return false;


}
bool Assign::IsVariable(char C) {

	if (C >= 'a' && C <= 'z') { return true; }
	return false;

}

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
	/**case '$':
		weight = 3; */
	}
	return weight;

}

void Assign::ejecutar(string instruction) {

	//string operation;
	
	/**for (int i = instruction.find("=") + 1; i < instruction.length(); i++) { // getting the operation that needs
		                                                                     // to be evaluated from string
		operation += instruction[i];
	} */
	// remember to replace instruction with operation once it works
	string PostfixOp = to_postfix(instruction,stack); // hasta acá aparentemente funciona

	Calculate(PostfixOp, stack, list,Intstack);
	
	stack->print(stack->get_top());

	
}

void Assign::Calculate(string operation, CharStack* stack,VarList* list,IntStack* Stackint ) {

	for (int i = 0; i < operation.length(); i++) {

		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if (operation[i] == ' ' || operation[i] == ',') { continue; }

		// If character is operator, pop two elements from stack, perform operation and push the result back.
		// the exception apparently is thrown due to this function
		else if (IsOperator(operation[i])) {
			// Pop two operands. 
			int operand2 = int(stack->get_top()->get_Value()); stack->pop();
			int operand1 = int(stack->get_top()->get_Value()); stack->pop();
			// Perform operation
			int result = PerformOperation(operation[i], operand1, operand2);
			//Push back result of operation on stack. 
			stack->push(char(result));
		} 

		else if (IsNumericDigit(operation[i])) {
			// Extract the numeric operand from the string
			// Keep incrementing i as long as you are getting a numeric digit. 
			int operand = 0;
			while (i < operation.length() && IsNumericDigit(operation[i])) {
				// For a number with more than one digits, as we are scanning from left to right. 
				// Everytime , we get a digit towards right, we can multiply current total in operand by 10 
				// and add the new digit. 
				operand = (operand * 10) + (operation[i] - '0');
				i++;
			}
			// Finally, you will come out of while loop with i set to a non-numeric character or end of string
			// decrement i because it will be incremented in increment section of loop once again. 
			// We do not want to skip the non-numeric character by incrementing i twice. 
			i--;

			// Push operand on stack. 
			stack->push((char)operand);
		}

		else if (IsVariable(operation[i])) {

			int Variable_value = list->get_IntVariable(operation[i]);
			 
			stack->push(char(Variable_value));

		}  
	
	}

	// return int (stack->get_top()->get_Value() );
}


int Assign::PerformOperation(char operation, int operand1, int operand2){
	if (operation == '+') { return operand1 + operand2; }
	else if (operation == '-') { return operand1 - operand2; }
	else if (operation == '*') { return operand1 * operand2; }
	else if (operation == '/') { return operand1 / operand2; }

	else cout << "Unexpected Error \n";
	return -1;
}

bool Assign::IsNumericDigit(char C){
	if (C >= '0' && C <= '9') return true;
	return false;
}




