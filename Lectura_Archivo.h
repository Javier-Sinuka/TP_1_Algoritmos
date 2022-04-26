#ifndef TP_1_ALGORITMOS_LECTURA_ARCHIVO_H
#define TP_1_ALGORITMOS_LECTURA_ARCHIVO_H

#include "Instruccion.h"

#include <iostream>
#include <fstream>
using namespace std;

class Lectura_Archivo : public Instruccion{
public:
    Lectura_Archivo();

    void ejecutar();
    string get_texto();
    void almacenar_contenido_archivo();

private:
    string texto;
    string linea;
};


#endif //TP_1_ALGORITMOS_LECTURA_ARCHIVO_H
