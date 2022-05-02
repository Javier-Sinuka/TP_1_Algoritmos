#ifndef TP_1_ALGORITMOS_LISTA_VARIABLES_PPL_H
#define TP_1_ALGORITMOS_LISTA_VARIABLES_PPL_H


#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class Nodo {
private:
    string nombreVariable;
    string tipoVariable;
    int valorVariableInt;
    bool valorVariableBool;
    Nodo* next;
public:
    Nodo() { next = NULL; };
    Nodo(string nombre, string tipo, int valorVariableI, bool valorVariablB) { nombreVariable = nombre; tipoVariable = tipo; valorVariableInt = valorVariableI; valorVariableBool = valorVariablB; next = NULL; };
    void set_dato(string nombre, string tipo, int valorI, bool valorB) { nombreVariable = nombre; tipoVariable = tipo; valorVariableInt = valorI; valorVariableBool = valorB;};
    void set_next(Nodo* n) { next = n; };
    T get_dato() { return nombreVariable,tipoVariable,valorVariableInt,valorVariableBool; };
    Nodo* get_next() { return next; };
    bool es_vacio() { return next == NULL; }
};

template <class T> class Lista_Variables {
private: Nodo<T>* czo;

public:
    Lista_Variables() { czo = new Nodo<T>(); };
    Lista_Variables(Nodo<T>* n) { czo = n; };
    //~Lista(void);
    void add(string nombreVar, string tipoVar, int valorInt, bool valorBool); //sumar nodos a la lista
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodo
    Lista_Variables* resto(void); //retorna el puntero al "resto" de la lista
    //resto= lo que queda de la lista sin la cabeza
    string toPrint(string p);
    int size();
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista_Variables<T>* l1);// le transfiere los datos de l1 a this
    Lista_Variables<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    //string get(){return czo->get_dato();};

};
template <class T>
void Lista_Variables<T>::add(string nombreVar, string tipoVar, int valorInt, bool valorBool) //100
{
    Nodo<T>* nuevo = new Nodo<T>(nombreVar,tipoVar,valorInt,valorBool);
    nuevo->set_next(czo);
    czo = nuevo;
}
template <class T>
bool Lista_Variables<T>::esvacia(void)
{
    return czo->es_vacio();
}
template <class T>
T Lista_Variables<T>::cabeza(void)
{
    if (this->esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return NULL;
    }
    return czo->get_dato();
}

template <class T>
Lista_Variables<T>* Lista_Variables<T>::resto(void)
{
    Lista_Variables* l = new Lista_Variables(czo->get_next());
    return (l);
}

template <class T>
string Lista_Variables<T>::toPrint(string p)
{
    if (this->esvacia()) {
        return p;
    }
    else {
        //std::ostringstream stm;
        ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl;
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str();
    }
}

template <class T> int Lista_Variables<T>::size()
{
    if (this->esvacia()) return 0;
    return 1 + this->resto()->size();
}



template <class T> void Lista_Variables<T>::borrar(void)
{ //borra el nodo cabeza
    if (!this->esvacia()) {
        Nodo<T>* tmp = czo;
        czo = czo->get_next();
        delete tmp;
    }
}

template <class T> void Lista_Variables<T>::borrar_last()
{ // borra el ultimo nodo
    if (!this->esvacia()) {
        if ((czo->get_next())->get_next() == NULL) {
            delete czo->get_next();
            czo->set_next(NULL);
        }
        else this->resto()->borrar_last();
    }
}

template <class T> void Lista_Variables<T>::concat(Lista_Variables<T>* l1)
{// le transfiere los datos de l1 a this
    if (!(l1->esvacia())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}

template <class T> Lista_Variables<T>* Lista_Variables<T>::copy(void)
{
    Lista_Variables<T>* aux = new Lista_Variables();
    aux->concat(this);
    return aux;
}

template <class T> void Lista_Variables<T>::tomar(int n)
{ //deja "vivos" los n primeros nodos y borra el resto
    if (this->size() > n) {
        this->borrar_last();
        this->tomar(n);
    }
}

#endif //TP_1_ALGORITMOS_LISTA_VARIABLES_PPL_H
