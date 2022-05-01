#include "Show.h"

Show::Show() {}

void Show::ejecutar(string posicion) {
    get_show(posicion);
}

void Show::get_show(string posicion) {
    cout << posicion << endl;
}
