#ifndef TP_1_ALGORITMOS_LECTURA_ARCHIVO_H
#define TP_1_ALGORITMOS_LECTURA_ARCHIVO_H

#include "Instruccion.h"
#include "Lista.h"
#include "Pila.h"

#include <iostream>
#include <fstream>
using namespace std;

class Lectura_Archivo : public Instruccion{
public:
    Lectura_Archivo();

    Pila<string> *contenido_archivo = new Pila<string>();

    void ejecutar();
    string get_texto();
    void almacenar_contenido_archivo();
    void almacenar_contenido_archivo_ppl();

private:
    string texto;
    string linea;
};


#endif //TP_1_ALGORITMOS_LECTURA_ARCHIVO_H
