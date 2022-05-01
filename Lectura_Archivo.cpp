#include "Lectura_Archivo.h"

Lectura_Archivo::Lectura_Archivo() {
    almacenar_contenido_archivo();
}

void Lectura_Archivo::ejecutar() {

}

string Lectura_Archivo::get_texto() {
}


void Lectura_Archivo::almacenar_contenido_archivo() {
    ifstream archivo;

    archivo.open("/home/js/Escritorio/Facultad/TPs-Algoritmo/TP-1-Algoritmos/texto.txt",ios::in); //Abrimos el archivo en modo lectura

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    while(!archivo.eof()){//Mientras no sea el final del archivo, recorre t0do el archivo el eof
        getline(archivo,linea); //Almacenamos el contenido del archivo en la constante string 'linea'
        linea += "\n";
        lista_texto->add(linea); // Pasamos el valor de linea a una variable string para despues poder leerla
    }
    archivo.close();
}

string Lectura_Archivo::lista_ordenada() {
    if(this->lista_texto->esvacia()){
        return "";
    }
    else{
        ostringstream stm;
    }
}


