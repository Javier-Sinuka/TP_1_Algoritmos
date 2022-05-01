#ifndef TP_1_ALGORITMOS_SHOW_H
#define TP_1_ALGORITMOS_SHOW_H

#include "Instruccion.h"

class Show : public Instruccion{
public:
    Show();
    void ejecutar(string posicion);
    void get_show(string posicion); //Tener en cuenta que va ser una varible
    //de tipo VARIABLE

private:
    string texto; //Tener en cuenta que en realidad es una variable de tipo
    //VARIABLE, para poder almacenar las variables que hayamos leido

};


#endif //TP_1_ALGORITMOS_SHOW_H
