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
    v.declaracion_variable(nombreVar,tipoVar,0,false);
    lista_de_variables ->add(v);
    cout << "Declaracion correcta?" << endl;
}

void Declaracion_de_Variables::print_content() {
    cout << "Nombre: " << v.getNombre() << " " <<
    "Tipo: " <<v.getTipo() << " " << "Valor: " << v.getValor() << endl;
}