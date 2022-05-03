#ifndef TP_1_ALGORITMOS_LISTA_STRING_H
#define TP_1_ALGORITMOS_LISTA_STRING_H

// Listas_01.cpp
//
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class Nodo_T { //Defino un nodo generico en cuanto a la parte de datos
    //el tipo de la lista lo defino cuando comience la clase
private:
    T dato; //Dato
    Nodo_T* next; //Puntero
public:
    Nodo_T() { next = NULL; };//Primer nodo siempre es NULL, constructor 1
    Nodo_T(T a) { dato = a; next = NULL; }; //Creacion de nodo, constructor 2
    void set_dato(T a) { dato = a; };
    void set_next(Nodo_T* n) { next = n; };
    T get_dato() { return dato; };
    Nodo_T* get_next() { return next; };
    bool es_vacio() { return next == NULL; }
};

template <class T> class Lista_String {
private: Nodo_T<T>* czo; //Puntero comienzo, unica variable qeu voy a tener
public:
    Lista_String() { czo = new Nodo_T<T>(); }; //Le pedimos a new que me devuelva donde esta en la memoria, algo de tipo nodo
    Lista_String(Nodo_T<T>* n) { czo = n; }; //Posibilidad de pasarle un puntero a comienzo
    //~Lista(void);
    Nodo_T <T>* getComienzo();
    void setComienzo(Nodo_T<T>* n);
    void add(T d); //Agregar nodos,
    bool esvacia(void); //pregunta si esta vacia
    T cabeza(void); //me devuelve el dato que esta primero en la lista, no el primero puesto en la lista
    Lista_String* resto(void);//devuelve un puntero a lista
    string toPrint(string p); //una manera de imprimir el contenido de la lista
    T suma(T i); //chequeo de la suma de la lista
    int size();
    void borrar(void);
    void borrar_last();
};
template <class T>
Nodo_T<T>* Lista_String<T>::getComienzo(){
    return czo;
};

template <class T>
void Lista_String<T>::setComienzo(Nodo_T<T>* n){
    czo = n;
};

template <class T>
void Lista_String<T>::add(T d) //metodo de incorporacion de elementos a la listas
{
    Nodo_T<T>* nuevo = new Nodo_T<T>(d); // le pide a new que busque lugar en la memoria para guardar a 'd', crea un nodo nuevo
    nuevo->set_next(czo);
    czo = nuevo;
}
template <class T>
bool Lista_String<T>::esvacia(void)
{
    return czo->es_vacio();
}
template <class T>
T Lista_String<T>::cabeza(void)
{
    if (esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return NULL;
    }
    return czo->get_dato(); // retorna el valor al que aputa czo
}

template <class T>
Lista_String<T>* Lista_String<T>::resto(void)
{
    Lista_String* l = new Lista_String(czo->get_next()); //crea una lista con la direccion get_next y lo retornamos como el resto de la lista
    return (l);
}

template <class T>
string Lista_String<T>::toPrint(string p)
{
    if (this->esvacia()) { //una vez que este vacia, retorna p
        return p;
    }
    else {
        //std::ostringstream stm;
        ostringstream stm; // funciona como un cout, pero trabaja como buffer
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl; //me muevo recursivamente; this->resto es lo mismo
        //que escribir 'resto'
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str(); //retorna el buffer convertido en un string
    }
}

template <class T>
T Lista_String<T>::suma(T i)
{    //cout<<" i al entrar= "<<i<<endl;
    if (this->esvacia()) {
        return i;
    }
    else {
        //cout<<"this->cabeza()= "<<this->cabeza()<<endl;
        return this->resto()->suma(i + this->cabeza());
    }
}

template <class T>
int Lista_String<T>::size(){
    if(this->esvacia()){
        return 0;
    }else {
        int aux = this->resto()->size();
        return aux + 1;
    }
}

template <class T>
void Lista_String<T>::borrar(void){
    if(!this->esvacia()){
        Nodo_T<T>* tmp = czo;
        czo = czo->get_next(); //Borrado logico
        delete tmp; //Borrado fisico
    }
}

template <class T>
void Lista_String<T>::borrar_last(){
    if(this->esvacia()){

    }
}


#endif //TP_1_ALGORITMOS_LISTA_STRING_H
