#include "../archivos_h/edificios.h"

using namespace std;

Edificio::Edificio() {
    this -> materiales_necesarios = 0;
}

string Edificio::obtener_nombre() {
    return this -> nombre;
}

int Edificio::obtener_cantidad_permitida() {
    return this -> cantidad_permitida;
}

string Edificio::obtener_representacion(){
    transform(this->representacion.begin(), this->representacion.end(), this->representacion.begin(), ::toupper);
    return this->representacion;
}

int* Edificio::obtener_materiales_necesarios() { 
    return this -> materiales_necesarios;
}

int Edificio::brindar_materiales() {
    return 0;
}

Edificio::~Edificio(){
    if (this -> materiales_necesarios) {
        delete [] this -> materiales_necesarios;        
    }
    this -> materiales_necesarios = 0;
}
