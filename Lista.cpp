#include "Lista.h"

template <class T>
void Lista<T>::add(T d) //metodo de incorporacion de elementos a la listas
{
    Nodo<T> *nuevo = new Nodo<T>(d); // le pide a new que busque lugar en la memoria para guardar a 'd', crea un nodo nuevo
    nuevo->set_next(czo);
    czo = nuevo;
}
template <class T>
bool Lista<T>::esvacia(void)
{
    return czo->es_vacio();
}
template <class T>
T Lista<T>::cabeza(void)
{
    if (esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return NULL;
    }
    return czo->get_dato(); // retorna el valor al que aputa czo
}

template <class T>
Lista<T>* Lista<T>::resto(void)
{
    Lista* l = new Lista(czo->get_next()); //crea una lista con la direccion get_next y lo retornamos como el resto de la lista
    return (l);
}

template <class T>
string Lista<T>::toPrint(string p)
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
T Lista<T>::suma(T i)
{    //cout<<" i al entrar= "<<i<<endl;
    if (this->esvacia()) {
        return i;
    }
    else {
        //cout<<"this->cabeza()= "<<this->cabeza()<<endl;
        return this->resto()->suma(i + this->cabeza());
    }
}

template <class T> int Lista<T>::size()
{
    if (this->esvacia()) return 0;
    return 1 + this->resto()->size();
}



template <class T> void Lista<T>::borrar(void)
{ //borra el nodo cabeza
    if (!this->esvacia()) {
        Nodo<T>* tmp = czo;
        czo = czo->get_next();
        delete tmp;
    }
}

template <class T> void Lista<T>::borrar_last()
{ // borra el ultimo nodo
    if (!this->esvacia()) {
        if ((czo->get_next())->get_next() == NULL) {
            delete czo->get_next();
            czo->set_next(NULL);
        }
        else this->resto()->borrar_last();
    }
}

template <class T> void Lista<T>::concat(Lista<T>* l1)
{// le transfiere los datos de l1 a this
    if (!(l1->esvacia())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}

template <class T> Lista<T>* Lista<T>::copy(void)
{
    Lista<T>* aux = new Lista();
    aux->concat(this);
    return aux;
}

template <class T> void Lista<T>::tomar(int n)
{ //deja "vivos" los n primeros nodos y borra el resto
    if (this->size() > n) {
        this->borrar_last();
        this->tomar(n);
    }
}