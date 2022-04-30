#ifndef TP_1_ALGORITMOS_DECLARACION_DE_VARIABLES_H
#define TP_1_ALGORITMOS_DECLARACION_DE_VARIABLES_H

#include "Instruccion.h"
#include "Lista_String.h"
#include "Lista_Variables.h"

class Declaracion_de_Variables : public Instruccion{
public:
    Declaracion_de_Variables();
    void ejecutar();
    //Lista_Variables <T> *lista_variables = new Lista_Variables <T>();
    //TODO: terminar lo empezado, en la parte de las variables, no me convencen un par de cosas

};


#endif //TP_1_ALGORITMOS_DECLARACION_DE_VARIABLES_H
