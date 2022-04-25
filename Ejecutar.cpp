#include "Ejecutar.h"

Ejecutar::Ejecutar() {}

void Ejecutar::ejecutar() {

}

void Ejecutar::almacenar_lectura_de_datos() {
        ifstream archivo;

        archivo.open("C:\\Users\\javie\\OneDrive\\Escritorio\\Proyectos-Varios\\TP-1-Algoritmos\\texto.txt",ios::in); //Abrimos el archivo en modo lectura

        if(archivo.fail()){
            cout << "No se pudo abrir el archivo" << endl;
            exit(1);
        }

        while(!archivo.eof()){//Mientras no sea el final del archivo, recorre todo el archivo el eof
            getline(archivo,linea); //Almacenamos el contenido del archivo en la constante string 'linea'
            texto = texto+linea+"\n"; // Pasamos el valor de linea a una variable string para despues poder leerla
        }

        archivo.close();
}

string Ejecutar::get_texto() {
    return texto;
}

void Ejecutar::imprimir_contenido_texto() {
    cout << texto << endl;
}
