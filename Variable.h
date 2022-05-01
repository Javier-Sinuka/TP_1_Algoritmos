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
    string Name;
    string Type;
    Variable* Next;

public:

    Variable(string Name, string Type, int IntValue, Variable* Next);
     

    Variable(string Name, string Type, bool BoolValue, Variable* Next);

    //getters
    int get_IntValue();
    int get_BoolValue();
    string get_Name();
    Variable* get_Next();

    //setters
    void set_IntValue(int value);
    void set_BoolValue(int value);
    void set_Name(string name);
    void set_Next(Variable* Next);

};

