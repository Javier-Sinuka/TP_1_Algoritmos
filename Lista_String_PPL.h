#ifndef TP_1_ALGORITMOS_LISTA_STRING_PPL_H
#define TP_1_ALGORITMOS_LISTA_STRING_PPL_H
#include "Nodo.h"

class Lista_String_PPL {
public:
    Lista_String_PPL();

    //Getters
    void add_string(string);
    Nodo* get_ValorPosicionNodo(string);
    string get_content(string);



private:
    Nodo* head;
};


#endif //TP_1_ALGORITMOS_LISTA_STRING_PPL_H
