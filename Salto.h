#ifndef TP_1_ALGORITMOS_SALTO_H
#define TP_1_ALGORITMOS_SALTO_H

#include "Lista_String.h"
#include "Instruccion.h"

class Salto{
public:
    Salto();
    Nodo_T<string>* ejecutar(string instruccion, Lista_String<string>*,Nodo_T<string>* czo_lista);
    int numeroDeInstruccion(string instruccion);
};


#endif //TP_1_ALGORITMOS_SALTO_H
