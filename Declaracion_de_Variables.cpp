#include "Declaracion_de_Variables.h"
Declaracion_de_Variables::Declaracion_de_Variables() {}

void Declaracion_de_Variables::ejecutar() {

    string instruccion = "INT a";

    int posInit = 0;
    int posFound = 0;
    string splitted;
    int cont = 1;

    string tipoVar;
    string nombreVar;

    while(posFound >= 0){
        posFound = instruccion.find(" ", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        posInit = posFound + 1;

        if (cont == 1){
            tipoVar = splitted;
            ++cont;

        }else{
            nombreVar = splitted;
        }
    }

    //crear objeto de tipo Variable con tipoVar y nombreVar
}