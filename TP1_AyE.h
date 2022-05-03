#ifndef TP_1_ALGORITMOS_TP1_AYE_H
#define TP_1_ALGORITMOS_TP1_AYE_H
#include "Lectura_Archivo.h"
#include "Assign.h"
#include "Salto.h"

class TP1_AyE : public Instruccion{
private:
public:
    TP1_AyE();
    void ejecutar();
    int identificar_instruccion(string);

private:

};


#endif //TP_1_ALGORITMOS_TP1_AYE_H
