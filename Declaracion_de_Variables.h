#ifndef TP_1_ALGORITMOS_DECLARACION_DE_VARIABLES_H
#define TP_1_ALGORITMOS_DECLARACION_DE_VARIABLES_H

#include "Instruccion.h"
#include "Variable.h"
#include "Lista_String.h"
#include "Lista_Variables_Ppl.h"

class Declaracion_de_Variables{
private:
    //Lista_String<Variable> *lista_de_variables = new Lista_String<Variable>();
    Lista_Variables<Variable> *lista_de_variables = new Lista_Variables<Variable>();
    Variable v;

public:
    Declaracion_de_Variables();
    void ejecutar(string instruccion);
    void var_print();
    Lista_String<Variable> valores_lista();
    void cantidad_lista();
    void buscador(Lista_String<string> *stack);
    //IMPLEMENTAR METODO EZE RECORRER LISTA PARA VARIABLES
};


#endif //TP_1_ALGORITMOS_DECLARACION_DE_VARIABLES_H
