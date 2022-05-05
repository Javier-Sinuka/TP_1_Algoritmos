#pragma once

#include "Variable.h"


class VarList{
private:

    
    Variable* head;

public:
    VarList();

    Variable* get_head();

    void add_variable(char Name, string Type, int IntValue);     // Variable* test
    void add_variable(char Name, string Type, bool BoolValue);

    void print(Variable* HeadOfList);

    void set_IntVariable(char name,int NewValue);
    void set_BoolVariable(char name, bool NeWValue);
    int get_IntVariable(char character);
};

