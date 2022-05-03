#include "Nodo.h"
Nodo::Nodo(string lineaLeida, Nodo *Next) {
    this->lineaLeida = lineaLeida;
    this->Next = Next;
}

string Nodo::get_ContenidoNodo() {return lineaLeida;}

Nodo* Nodo::get_Next() {return Next;}

void Nodo::set_LineaNueva(string lineaLeida) { this->lineaLeida = lineaLeida;}

void Nodo::set_Next(Nodo *Next) {this->Next = Next;}
