
#include <iostream>
#include "Variable.h"
#include "VarList.h"
#include "Character.h"
#include "CharStack.h"
#include "Integer.h"
#include "IntStack.h"
#include "Assign.h"
#include "Declaration.h"

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string


int main(){

    VarList list;
    CharStack stack;
    IntStack stack2;
    string operation = "ABBB";

   /** Declaration var1("a=5", &list);
    Declaration var2("b=4", &list);
    Declaration var3("c=3", &list); */

    Assign test(operation,&list,&stack,&stack2);
    

    test.ejecutar("4+4");
   


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
