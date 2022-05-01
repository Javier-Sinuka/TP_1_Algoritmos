#ifndef TP_1_ALGORITMOS_VARIABLE_H
#define TP_1_ALGORITMOS_VARIABLE_H
#include <iostream>
#include <sstream>
using namespace std;

class Variable {
    private:
        string nombre;
        string tipo;
        int valor;
        bool v_bool;

    public:
        Variable();

        Variable(string nombre_var, string tipo_var, int valor_var, bool valor_bool);

        void declaracion_variable(string nombre_var, string tipo_var, int valor_var, bool valor_bool);

        string getNombre();

        void setNombre(string nombre);

        string getTipo();

        void setTipo(string tipo);

        int getValor();

        void setValor(int valor);

        bool getVBool();

        void setVBool(bool vBool);
};

#endif //TP_1_ALGORITMOS_VARIABLE_H
