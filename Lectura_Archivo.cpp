#include "Lectura_Archivo.h"
Lectura_Archivo::Lectura_Archivo() {
    almacenar_contenido_archivo();
    almacenar_contenido_archivo_ppl();

}

void Lectura_Archivo::ejecutar() {

}

string Lectura_Archivo::get_texto() {
    return texto;
}

void Lectura_Archivo::almacenar_contenido_archivo() {
    ifstream archivo;

    archivo.open("C:\\Users\\javie\\OneDrive\\Escritorio\\Proyectos-Varios\\TP-1-Algoritmos\\texto.txt",ios::in); //Abrimos el archivo en modo lectura

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    while(!archivo.eof()){//Mientras no sea el final del archivo, recorre t0do el archivo el eof
        getline(archivo,linea); //Almacenamos el contenido del archivo en la constante string 'linea'
        texto = texto+linea+"\n"; // Pasamos el valor de linea a una variable string para despues poder leerla
    }
    archivo.close();
}

void Lectura_Archivo::almacenar_contenido_archivo_ppl() {
    ifstream archivo;

    archivo.open("C:\\Users\\javie\\OneDrive\\Escritorio\\Proyectos-Varios\\TP-1-Algoritmos\\texto.txt",ios::in); //Abrimos el archivo en modo lectura

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    //TODO: NO ALMACENA EL VALOR DEL STRING EN LA PILA
    while(!archivo.eof()){//Mientras no sea el final del archivo, recorre t0do el archivo el eof
        getline(archivo,linea); //Almacenamos el contenido del archivo en la constante string 'linea'
        contenido_archivo->apilar(linea); // Pasamos el valor de linea a una variable string para despues poder leerla
    }
    archivo.close();
}
