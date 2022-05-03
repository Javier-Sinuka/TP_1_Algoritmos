#include "Lectura_Archivo.h"
#include "Declaracion_de_Variables.h"
#include "Salto.h"
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

    int valorASCII = splitted.at(0);
    if(valorASCII >= 97 && valorASCII <= 122 ){
        return 5;
    }
    return 6;
}

int  main(){
    Lectura_Archivo l1;
    Declaracion_de_Variables d;
    Salto s;
    bool banderaJump = true;
    Nodo_T<string>* czo_lista;

    czo_lista = l1.lista_texto->getComienzo();

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

                cout << "\nSe ejecuto una instruccion de condicion";//Instruccion de condicion
                break;
            case 3:

                cout << "\nSe ejecuto instruccion de show";//instruccion de show
                break;
            case 4: {
                Nodo_T<string> *nuevo_comienzo = s.ejecutar(instruccion, l1.lista_texto, czo_lista);
                if (nuevo_comienzo != nullptr) {
                    l1.lista_texto->setComienzo(nuevo_comienzo);
                    banderaJump = false;
                }
                cout << "\nSe ejecuto instruccion de jump";//instruccion de jump
                break;
            }
            case 5:
                cout << "\nSe ejecuto instruccion de asignacion";//Instruccion de asigancion
                break;
            case 6:
                cout<<"\nNo se reconoce la instruccion";
                break;
        }

        if(banderaJump){l1.lista_texto = l1.lista_texto->resto();}

        banderaJump = true;

    }


    return 0;
}