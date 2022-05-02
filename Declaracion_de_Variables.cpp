#include "Declaracion_de_Variables.h"
#include "Variable.h"
Declaracion_de_Variables::Declaracion_de_Variables() {}

void Declaracion_de_Variables::ejecutar(string instruccion) {

    int posInit = 0;
    int posFound = 0;
    string splitted;

    string tipoVar;
    string nombreVar;

    while(posFound >= 0){
        posFound = instruccion.find(" ", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        tipoVar = splitted;

        posFound = instruccion.find("\n", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        nombreVar = splitted;
        posFound = -1;
    }

    //crear objeto de tipo Variable con tipoVar y nombreVar
    //v.declaracion_variable(nombreVar,tipoVar,0,false);
    lista_de_variables ->add(nombreVar, tipoVar,0, false);
}

void Declaracion_de_Variables::var_print() {
    cout << "Nombre: " << v.getNombre() << " Tipo: " << v.getTipo() << endl;
}

Lista_String<Variable> Declaracion_de_Variables::valores_lista() {

}

void Declaracion_de_Variables::cantidad_lista() {
    cout << lista_de_variables->size() << endl;
}

void Declaracion_de_Variables::buscador(Lista_String<string> *stack) {
    if ( stack == nullptr) { cout << "Final del stack"; return; }

    cout << stack->cabeza() << endl;



}
