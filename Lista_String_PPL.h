#ifndef TP_1_ALGORITMOS_LISTA_STRING_PPL_H
#define TP_1_ALGORITMOS_LISTA_STRING_PPL_H
#include "Nodo.h"

class Lista_String_PPL {
public:
    Lista_String_PPL();

    //Getters
    void add_string(string);
    Nodo* get_ValorPosicionNodo(string);
    string get_content(string); //Retorna el contenido si es que esta en la lista
    Nodo* get_head();
    bool get_EstaVacia();
    string get_Contenido();
    void set_head(Nodo*);
    int size();
    Nodo* resto();

private:
    Nodo* head;
};


#endif //TP_1_ALGORITMOS_LISTA_STRING_PPL_H
