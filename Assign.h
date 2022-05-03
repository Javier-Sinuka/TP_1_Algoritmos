#ifndef TP_1_ALGORITMOS_ASSIGN_H
#define TP_1_ALGORITMOS_ASSIGN_H

#pragma once

#include <iostream>
#include "VarList.h"
#include "CharStack.h"
#include "IntStack.h"

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string

using namespace std;

class Assign{

private:

    string instruction;
    VarList* list;
    CharStack* stack;
    IntStack* StackInt;

public:

    Assign(string, VarList*, CharStack*,IntStack*);

    void ejecutar(string instruction);

    string to_postfix(string operation, CharStack* stack);

    int HasHigherPrecedence(char op1, char op2);

    // Function to verify whether a character is operator symbol or not.
    bool IsOperator(char C);

    // Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
    bool IsOperand(char C);

    int IsRightAssociative(char op);


    int GetOperatorWeight(char op);

    int Calculate(string operation, CharStack* stack,VarList* list,IntStack* Stackint);
    //int

    int PerformOperation(char operation, int operand1, int operand2);

    bool IsNumericDigit(char C);

    bool IsVariable(char C);




};


#endif //TP_1_ALGORITMOS_ASSIGN_H
