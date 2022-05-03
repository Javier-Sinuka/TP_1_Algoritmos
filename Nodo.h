#ifndef TP_1_ALGORITMOS_NODO_H
#define TP_1_ALGORITMOS_NODO_H

#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Nodo{
private:
    string lineaLeida;
    Nodo* Next;

public:
    Nodo(string lineaLeida, Nodo* Next);

    //Getter
    string get_ContenidoNodo();
    Nodo* get_Next();
    bool get_EsVacio();

    //Setter
    void set_LineaNueva(string linea_leida);
    void set_Next(Nodo* Next);
};

#endif //TP_1_ALGORITMOS_NODO_H
