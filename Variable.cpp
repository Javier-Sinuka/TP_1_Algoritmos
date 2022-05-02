#include "Variable.h"

Variable::Variable(){};
Variable::Variable(string nombre_var, string tipo_var, int valor_var, bool valor_bool){
    declaracion_variable(nombre_var,tipo_var,valor_var,valor_bool);
}

void Variable::declaracion_variable(string nombre_var, string tipo_var, int valor_var, bool valor_bool){
    nombre = nombre_var;
    tipo = tipo_var;
    valor = valor_var;
    v_bool = valor_bool;
}

string Variable::getNombre(){
    return nombre;
}

void Variable::setNombre(string nombre) {
    Variable::nombre = nombre;
}

string Variable::getTipo() {
    return tipo;
}

void Variable::setTipo(string tipo) {
    Variable::tipo = tipo;
}

int Variable::getValor(){
    return valor;
}

void Variable::setValor(int valor) {
    Variable::valor = valor;
}

bool Variable::getVBool(){
    return v_bool;
}

void Variable::setVBool(bool vBool) {
    v_bool = vBool;
}