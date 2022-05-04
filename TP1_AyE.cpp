#include "TP1_AyE.h"
TP1_AyE::TP1_AyE() {ejecutar();}

int TP1_AyE::identificar_instruccion(string instruccion) {
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

void TP1_AyE::ejecutar() {
    Lectura_Archivo l1;
   // Assign d;
    Salto s;
    bool banderaJump = true;
    Nodo* czo_lista;

    czo_lista = l1.lista_de_variables->get_head();

    while (!l1.lista_de_variables->get_EstaVacia()) {
        string instruccion = l1.lista_de_variables->get_Contenido();
        int tipo_instruccion = identificar_instruccion(instruccion);


        switch (tipo_instruccion) {
            case 1: {
               // d.ejecutar(instruccion);
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
                Nodo* nuevo_comienzo = s.ejecutar(instruccion, l1.lista_de_variables, czo_lista);
                if (nuevo_comienzo != nullptr) {
                    l1.lista_de_variables->set_head(nuevo_comienzo);
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

        if(banderaJump){
            l1.lista_de_variables = l1.lista_de_variables->resto();
        }
        banderaJump = true;
    }
}
