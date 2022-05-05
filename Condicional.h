#ifndef TP_1_ALGORITMOS_CONDICIONAL_H
#define TP_1_ALGORITMOS_CONDICIONAL_H

#include "Instruccion.h"
#include "Assign.h"

class Condicional : public Instruccion{
public:
    Condicional();
    void ejecutar();
    void ejecutar_condicional(string, VarList*);

};


#endif //TP_1_ALGORITMOS_CONDICIONAL_H
