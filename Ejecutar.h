#ifndef TP_1_ALGORITMOS_EJECUTAR_H
#define TP_1_ALGORITMOS_EJECUTAR_H

#include "Lectora_AYED22.h"
#include <iostream>
#include <fstream>
using namespace std;


class Ejecutar {
public:
    Ejecutar();

    //Method
    void ejecutar();
    void almacenar_lectura_de_datos();
    string get_texto();
    void imprimir_contenido_texto();

private:
    string texto;
    string linea;
};


#endif //TP_1_ALGORITMOS_EJECUTAR_H
