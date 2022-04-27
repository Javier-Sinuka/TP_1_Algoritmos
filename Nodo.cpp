#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T> class Nodo{ //Defino un nodo generico en cuanto a la parte de datos
    //el tipo de la lista lo defino cuando comience la clase
private:
    T dato; //Dato
    Nodo* next; //Puntero
public:
    Nodo() { next = NULL; };//Primer nodo siempre es NULL, constructor 1
    Nodo(T a) { dato = a; next = NULL; }; //Creacion de nodo, constructor 2
    void set_dato(T a) { dato = a; };
    void set_next(Nodo* n) { next = n; };
    T get_dato() { return dato; };
    Nodo* get_next() { return next; };
    bool es_vacio() { return next == NULL; }
};