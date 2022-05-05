#include "Show.h"

Show::Show() {}

void Show::ejecutar() {}

void Show::ejecutar(VarList* lista, string instruccion){
    //string instruccion = contenidoString;
    int posInit = 0;
    int posFound = 0;
    string splitted;

    string tipoVar;
    string nombreVar;

    while(posFound >= 0){
        posFound = instruccion.find(" ", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        tipoVar = splitted;

        posFound = instruccion.find("\n", posInit);
        splitted = instruccion.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        nombreVar = splitted;
        posFound = -1;
    }
    if(nombreVar.length() == 1){
        Variable *aux = new Variable();
        aux = lista->get_head();
        while (!lista->estaVacia()){
            if(lista->get_head()->get_Name() == StringToCharArray(nombreVar) && lista->get_head()->get_Type() == "INT"){
                cout << "\n" << lista->get_IntVariable(StringToCharArray(nombreVar));
            }else if(lista->get_head()->get_Name() == StringToCharArray(nombreVar) && lista->get_head()->get_Type() == "BOOL"){
                if(lista->get_BoolVariable(StringToCharArray(nombreVar)) == 1){
                    cout << "\n" << "true";
                }else{
                    cout << "\n" << "false";
                }
            }
            lista = lista->resto_VarList();
        }
        lista->set_head_var(aux);

//        if(lista->get_head()->get_Type() == "INT"){
//            cout << "\n" << lista->get_IntVariable(StringToCharArray(nombreVar));
  //      }else{
    //        if(lista->get_BoolVariable(StringToCharArray(nombreVar)) == 1){
      //          cout << "\n" << "true";
        //    }else{
          //      cout << "\n" << "false";
            }

    else {
        CharStack cStack;
        IntStack iStack;
        Assign t;
        if(t.Calculate(t.to_postfix(nombreVar,&cStack),&cStack, lista, &iStack) == 1){
            cout << "\n" << "true";
        } else{
            cout << "\n" << "false";
        }
}

}

void Show::set_string(string nuevo) {
     contenidoString = nuevo;
}

char Show::StringToCharArray(string cadena) {
        int longitud = 1;
        string str = cadena;
        char nombre[1];
        longitud = str.length();

        for (int i = 0; i < longitud; i++)
        {
            nombre[i] = str[i];
        }
        return nombre[0];
}
