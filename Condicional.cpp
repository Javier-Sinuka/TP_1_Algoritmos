#include "Condicional.h"
Condicional::Condicional() {}

void Condicional::ejecutar() {}

void Condicional::ejecutar_condicional(string instruccion, VarList* lista) {
    int posInit = 0;
    int posFound = 0;
    string splitted;

    string condicional;

    while(posFound >= 0){
        posFound = instruccion.find("(", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        posInit = posFound + 1;

        posFound = instruccion.find(")", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        condicional = splitted;
        posFound = -1;
    }

    CharStack cStack;
    IntStack iStack;
    Assign t;
    //t.ejecutar(condicional);
    if(t.Calculate(t.to_postfix(condicional,&cStack),&cStack, lista, &iStack) == 1){
        cout << "\n" << "true";
    } else{
        cout << "\n" << "false";
    }
}
