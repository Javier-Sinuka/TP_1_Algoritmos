#include "Declaracion_de_Variables.h"
#include "Variable.h"
Declaracion_de_Variables::Declaracion_de_Variables() {}

void Declaracion_de_Variables::ejecutar(string instruccion) {

    int posInit = 0;
    int posFound = 0;
    string splitted;

    string tipoVar;
    char nombreVar;

    while(posFound >= 0){
        posFound = instruccion.find(" ", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        tipoVar = splitted;

        posFound = instruccion.find("\n", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        nombreVar = splitted.at(0);
        posFound = -1;
    }

    //Compruebo que el nombre de la variable
    int valorASCII = nombreVar;

    if(valorASCII >= 97 && valorASCII <= 122 ){
        //Creacion de objeto de tipo Variable con tipoVar y nombreVar
        agregarObjetoVariable(tipoVar,nombreVar);
        return;
    }

    cout << "\nDeclaracion de variable incorrecta";
    return;
}

Lista_String<Variable> *Declaracion_de_Variables::getListaDeVariables(){
    return lista_de_variables;
}

void Declaracion_de_Variables::agregarObjetoVariable (string tipo, char nombre){
    //Creo objeto variable y lo agrego a la lista
    Variable v (nombre,tipo,0,false);
    lista_de_variables->add(v);
}
