#include "Lectura_Archivo.h"
#include "Declaracion_de_Variables.h"

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
    Declaracion_de_Variables d;

    l1.almacenar_contenido_archivo();

    //Repetir para cada instruccion (cada nodo de lista de instrucciones)
    while (!l1.lista_texto->esvacia()) {
        string instruccion = l1.lista_texto->cabeza();
        int tipo_instruccion = identificar_instruccion(instruccion);


        switch (tipo_instruccion) {
            case 1: {
                d.ejecutar(instruccion);
                cout << "\nSe ejecuto una instruccion de declaracion";//Instruccion de declaracion
                break;
            }
            case 2:
                cout << "\nEs una instruccion de condicion";//Instruccion de condicion
                break;
            case 3:
                cout << "\nEs una instruccion de show";//instruccion de show
                break;
            case 4:
                cout << "\nEs una instruccion de jump";//instruccion de jump
                break;
            case 5:
                cout << "\nEs una instruccion de asignacion";//Instruccion de asigancion
                break;
        }

        l1.lista_texto = l1.lista_texto->resto();
    }
    return 0;
}