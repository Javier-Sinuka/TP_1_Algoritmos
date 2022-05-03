#include "Salto.h"

Salto::Salto() {}

Nodo_T<string>* Salto::ejecutar(string instruccion, Lista_String<string> *l,Nodo_T<string>* czo_lista) {

    int cantidad = numeroDeInstruccion(instruccion);
    Nodo_T<string> *aux = l->getComienzo();

    l->setComienzo(czo_lista);

    if(cantidad > 0 && cantidad <= l->size()) {
        Nodo_T<string> *czo_nuevo;

        for (int i = 0; i < cantidad; i++) {
            czo_nuevo = l->getComienzo();
            l = l->resto();
        }
        return czo_nuevo;
    }
    l->setComienzo(aux);
    cout<< "\nNumero de instruccion invalida";
    return nullptr;
}
int Salto::numeroDeInstruccion(string instruccion){

    int posInit = 0;
    int posFound = 0;
    int splitted;

    while(posFound >= 0){
        posFound = instruccion.find(" ", posInit);
        posInit = posFound + 1;
        posFound = instruccion.find(" ", posInit);
        splitted = stoi(instruccion.substr(posInit,posFound-posInit));

        break;
    }

    return splitted;
}