#ifndef TP_1_ALGORITMOS_LISTA_H
#define TP_1_ALGORITMOS_LISTA_H

#include "Nodo.cpp"

using namespace std;

template <class T> class Lista {
private: Nodo<T>* czo; //Puntero comienzo, unica variable qeu voy a tener
public:
    Lista() { czo = new Nodo<T>(); }; //Le pedimos a new que me devuelva donde esta en la memoria, algo de tipo nodo
    Lista(Nodo<T>* n) { czo = n; }; //Posibilidad de pasarle un puntero a comienzo
    //~Lista(void);
    void add(T d); //Agregar nodos,
    bool esvacia(void); //pregunta si esta vacia
    T cabeza(void); //me devuelve el dato que esta primero en la lista, no el primero puesto en la lista
    Lista* resto(void);//devuelve un puntero a lista
    string toPrint(string p); //una manera de imprimir el contenido de la lista
    T suma(T i); //chequeo de la suma de la lista
    int size();
    void borrar(void);
    void borrar_last();
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
};

#endif //TP_1_ALGORITMOS_LISTA_H
