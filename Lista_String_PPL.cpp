#include "Lista_String_PPL.h"
Lista_String_PPL::Lista_String_PPL() {}

void Lista_String_PPL::add_string(string linea) {
    Nodo* NuevoNodo = new Nodo(linea, nullptr);
    if(head == nullptr){
        head = NuevoNodo;
    } else{
        NuevoNodo->set_Next(head);
        head = NuevoNodo;
    }
}


string Lista_String_PPL::get_content(string palab) {
    cout << head-> << endl;
}