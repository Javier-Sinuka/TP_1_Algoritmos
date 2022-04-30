#ifndef TP_1_ALGORITMOS_LECTURA_ARCHIVO_H
#define TP_1_ALGORITMOS_LECTURA_ARCHIVO_H

#include "Instruccion.h"
#include "Lista_String.h"


#include <iostream>
#include <fstream>
using namespace std;

class Lectura_Archivo : public Instruccion{
public:
    Lectura_Archivo();
    Lista_String<string> *lista_texto = new Lista_String<string>();

    void ejecutar();
    string get_texto();
    void almacenar_contenido_archivo();
    string lista_ordenada();

private:
    string texto;
    string linea;
};


#endif //TP_1_ALGORITMOS_LECTURA_ARCHIVO_H
