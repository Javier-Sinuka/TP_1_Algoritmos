#ifndef TP_1_ALGORITMOS_TP1_AYE_H
#define TP_1_ALGORITMOS_TP1_AYE_H
#include "Lectura_Archivo.h"
#include "Declaration.h"
#include "Salto.h"
#include "Show.h"

class TP1_AyE : public Instruccion{
private:
public:
    TP1_AyE();
    void ejecutar();
    int identificar_instruccion(string);
    VarList *lista_variables = new VarList();
private:

};


#endif //TP_1_ALGORITMOS_TP1_AYE_H
