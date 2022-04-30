#include "Lectura_Archivo.h"

int identificar_instruccion (string instruccion){
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

    return 5;
}

int  main(){
    Lectura_Archivo l1;

    l1.almacenar_contenido_archivo();

    string instruccion = l1.lista_texto->cabeza();

    //Repetir para cada instruccion
   int tipo_instruccion = identificar_instruccion(instruccion);

    switch (tipo_instruccion) {
        case 1: cout<< "Es una instruccion de declaracion";//Instruccion de declaracion
            break;
        case 2: cout<< "Es una instruccion de condicion";//Instruccion de condicion
            break;
        case 3: cout<< "Es una instruccion de show";//instruccion de show
            break;
        case 4: cout<< "Es una instruccion de jump";//instruccion de jump
            break;
        case 5: cout<< "Es una instruccion de asignacion";//Instruccion de asigancion
            break;
    }

    return 0;
}