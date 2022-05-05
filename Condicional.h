#ifndef TP_1_ALGORITMOS_CONDICIONAL_H
#define TP_1_ALGORITMOS_CONDICIONAL_H

#include "Instruccion.h"
#include "Assign.h"
#include "Declaration.h" //TODO: CREACION
#include "Show.h" //TODO: CREACION
#include "Salto.h"


class Condicional : public Instruccion{
public:
    Condicional();
    void ejecutar();
    string ejecutar_condicional(string, VarList*);
    string ejecutar_post_condicional(string, VarList*,bool); //TODO: CREACION EJECUTAR
    int identificar_instruccion_condicional(string);  //TODO: creacion metodo lectura de instruccion
};


#endif //TP_1_ALGORITMOS_CONDICIONAL_H