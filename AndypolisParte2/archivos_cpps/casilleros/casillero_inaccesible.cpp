#include "../../archivos_h/casilleros/casillero_inaccesible.h"

using namespace std;

Casillero_inaccesible::Casillero_inaccesible(char tipo){
    this -> tipo = tipo;
}

void Casillero_inaccesible::mostrar(){
    cout << COLOR_ROJO << "Soy un casillero inaccesible y no es posible construir aqui" << COLOR_POR_DEFECTO << endl;
}

char Casillero_inaccesible::obtener_tipo(){
    return this -> tipo;
}