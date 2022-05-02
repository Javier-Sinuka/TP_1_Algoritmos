#ifndef TP_1_ALGORITMOS_DECLARACION_DE_VARIABLES_H
#define TP_1_ALGORITMOS_DECLARACION_DE_VARIABLES_H

#include "Instruccion.h"
#include "Variable.h"
#include "Lista_String.h"

class Declaracion_de_Variables{
private:
    Lista_String<Variable> *lista_de_variables = new Lista_String<Variable>();
public:
    Declaracion_de_Variables();
    void ejecutar(string instruccion);
    void agregarObjetoVariable (string tipo, char nombre);

    Lista_String<Variable> *getListaDeVariables();
};


#endif //TP_1_ALGORITMOS_DECLARACION_DE_VARIABLES_H
