#include "../../archivos_h/casilleros/casillero_transitable.h"

using namespace std;

Casillero_transitable::Casillero_transitable(char tipo) {
    this -> material = 0;
    this -> tipo = tipo;
}

void Casillero_transitable::usar_casillero(Edificio* edificio, Material* material) {
    this -> material = material;
}

void Casillero_transitable::vaciar_casillero() {
    delete [] this -> material;
    this -> material = 0;
}

bool Casillero_transitable::esta_ocupado() {
    return this -> material != 0;
}

char Casillero_transitable::obtener_tipo() {
    return this -> tipo;
}

Material* Casillero_transitable::obtener_material() {
    return this -> material;
}

void Casillero_transitable::mostrar() {
    if (this -> esta_ocupado()) {
        cout << COLOR_VERDE_AGUA << "Soy un casillero transitable y no me encuentro vacio" << COLOR_POR_DEFECTO << endl;
        cout << endl;
        this -> material-> saludar();
    }
    else {
        cout << COLOR_VERDE << "Soy un casillero transitable y me encuentro vacío" << COLOR_POR_DEFECTO << endl;
    }
}
Casillero_transitable::~Casillero_transitable() {
    if(this -> material) {
        delete this -> material;
    }
    this -> material = 0;
}