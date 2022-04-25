#include "Lectora_AYED22.h"

Lectora_AYED22::Lectora_AYED22() {
}

void Lectora_AYED22::lectora() {
    ifstream archivo;
    string texto;

    archivo.open("C:\\Users\\javie\\OneDrive\\Escritorio\\Proyectos-Varios\\TP-1-Algoritmos\\texto.txt",ios::in); //Abrimos el archivo en modo lectura

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    while(!archivo.eof()){//Mientras no sea el final del archivo, recorre todo el archivo el eof
        getline(archivo,texto); //Almacenamos el contenido del archivo en la constante string
        cout << texto << endl;
    }

    archivo.close();
}
