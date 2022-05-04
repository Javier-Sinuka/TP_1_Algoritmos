#ifndef TP_1_ALGORITMOS_VARLIST_H
#define TP_1_ALGORITMOS_VARLIST_H


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

    // test->get_name()

    void print(Variable* HeadOfList);

    void set_IntVariable(char name,int NewValue);
    int get_IntVariable(char character);
};

#endif //TP_1_ALGORITMOS_VARLIST_H
