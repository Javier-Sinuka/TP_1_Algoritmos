#pragma once

#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string


class Variable{
private:

    int IntValue;
    bool BoolValue;
    char Name;
    string Type;
    Variable* Next;

public:

    Variable(char Name, string Type, int IntValue, Variable* Next);
     

    Variable(char Name, string Type, bool BoolValue, Variable* Next);

    //getters
    int get_IntValue();
    int get_BoolValue();
    char get_Name();
    Variable* get_Next();

    //setters
    void set_IntValue(int value);
    void set_BoolValue(int value);
    void set_Name(char name);
    void set_Next(Variable* Next);

};

