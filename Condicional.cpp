#include "Condicional.h"
Condicional::Condicional() {}

void Condicional::ejecutar() {}

string Condicional::ejecutar_condicional(string instruccion, VarList* lista) {
    int posInit = 0;
    int posFound = 0;
    string splitted;
    string condicional;
    string guardar = instruccion;
    bool bandera; //TODO: CREACION BANDERA

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
        cout << "\n" << "true" << endl;
        bandera = true;
    } else{
        cout << "\n" << "false" << endl;
        bandera = false;
    }

    if(bandera == true){
        //cout << "Entra en bandera" << endl;
        return ejecutar_post_condicional(guardar,lista,bandera);
    } else{
        return "";
    }
}

string Condicional::ejecutar_post_condicional(string instruccion, VarList *list, bool bandera) {
    int posInit = 0;
    int posFound = 0;
    string splitted;
    string condicional;

    while(posFound >= 0){
        posFound = instruccion.find("N", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        posInit = posFound + 1;

        posFound = instruccion.find("\n", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        condicional = splitted;
        posFound = -1;
    }
    //cout << "Esta imprimiendo?" << condicional << endl;
    return condicional;
}

int Condicional::identificar_instruccion_condicional(string instruccion) {
    int posInit = 0;
    int posFound = 0;
    string splitted;

    while(posFound >= 0){
        posFound = instruccion.find(" ", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        break;
    }

    if(splitted == "INT" || splitted == "BOOL"){return 1;}
    if(splitted == "IF"){return 2;}
    if(splitted == "SHOW"){return 3;}
    if(splitted == "JUMP"){return 4;}

    int valorASCII = splitted.at(0);
    if(valorASCII >= 97 && valorASCII <= 122 ){
        return 5;
    }
    return 6;
}