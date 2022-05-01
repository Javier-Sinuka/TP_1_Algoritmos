#pragma once

#include "Variable.h"


class VarList{
private:
    Variable* head;

public:
    VarList();

    Variable* get_head();

    void add_variable(string Name, string Type, int IntValue);
    void add_variable(string Name, string Type, bool BoolValue);

    void print(Variable* HeadOfList);
};

