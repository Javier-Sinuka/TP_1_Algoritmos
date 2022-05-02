//
// Created by Tomas on 29/4/2022.
//

#ifndef TP_1_ALGORITMOS_VARIABLE_H
#define TP_1_ALGORITMOS_VARIABLE_H
#include <iostream>
#include <sstream>
using namespace std;

class Variable {
    private:
        char nombre;
        string tipo;
        int valor;
        bool v_bool;

    public:
        Variable();

        Variable(char nombre_var, string tipo_var, int valor_var, bool valor_bool);

        char getNombre();

        void setNombre(string nombre);

        string getTipo();

        void setTipo(string tipo);

        int getValor();

        void setValor(int valor);

        bool getVBool();

        void setVBool(bool vBool);
};


#endif //TP_1_ALGORITMOS_VARIABLE_H
