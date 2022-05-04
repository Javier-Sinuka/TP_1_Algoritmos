#ifndef TP_1_ALGORITMOS_SHOW_H
#define TP_1_ALGORITMOS_SHOW_H

#include "Instruccion.h"
#include "TP1_AyE.h"

class Show : public Instruccion{
public:
    Show();
    void ejecutar();
    char StringToCharArray(string);
    void set_string(string);

private:
    TP1_AyE estructura;
    string contenidoString;
};


#endif //TP_1_ALGORITMOS_SHOW_H
