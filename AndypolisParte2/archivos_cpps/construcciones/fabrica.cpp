#include "../../archivos_h/construcciones/fabrica.h"

using namespace std;

int Fabrica::cantidad_construidos = 0;
int** Fabrica::ubicaciones = 0;

Fabrica::Fabrica(string nombre, int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos) {
    this -> nombre = nombre;
    this -> cantidad_permitida = permitidos;
    this -> materiales_necesarios = new int[3];
    this -> materiales_necesarios[0] = piedra_necesaria;
    this -> materiales_necesarios[1] = madera_necesaria;
    this -> materiales_necesarios[2] = metal_necesario;
    this -> ubicaciones = new int* [this -> cantidad_construidos];
}

Fabrica::Fabrica(string nombre, int coord_x, int coord_y) {
    this -> nombre = nombre;
    this -> representacion = nombre[0];
    this -> redimensionar_ubicaciones(this -> cantidad_construidos + 1);
    this -> ubicaciones[this -> cantidad_construidos] = new int[2];
    this -> ubicaciones[this -> cantidad_construidos][0] = coord_x;
    this -> ubicaciones[this -> cantidad_construidos][1] = coord_y;
    this -> cantidad_construidos++;
}

int Fabrica::obtener_construidos() {
    return this -> cantidad_construidos;
}

int** Fabrica::obtener_ubicaciones() {
    return this -> ubicaciones;
}

int Fabrica::brindar_materiales() {
    return BRINDAR_MATERIALES_FABRICA;
}

void Fabrica::demoler(int coordenada_x, int coordenada_y) {
    int indice = 0;
    bool eliminada = false;
    while (!eliminada) {
        if (this -> ubicaciones[indice][0] == coordenada_x && this -> ubicaciones[indice][1] == coordenada_y) {
            delete [] this -> ubicaciones[indice];
            this -> ubicaciones[indice] = 0;
            eliminada = true;
        }
        indice++;
    }
    this -> redimensionar_ubicaciones(this -> cantidad_construidos - 1);
    this -> cantidad_construidos--;
}

void Fabrica::redimensionar_ubicaciones(int nueva_longitud) {
    int** nuevo_vector_ubicaciones = new int *[nueva_longitud];
    int* coordenadas = 0;
    int indice = 0;
    for (int i = 0; i < this -> cantidad_construidos; i++) {
        coordenadas = this -> ubicaciones[i];
        if (coordenadas) {
            nuevo_vector_ubicaciones[indice] = this -> ubicaciones[i];
            indice++;
        }
    }
    delete [] this -> ubicaciones;
    this -> ubicaciones = nuevo_vector_ubicaciones;
}

void Fabrica::mostrar_edificio() {
    cout << "--> " << COLOR_VERDE_AGUA << this -> nombre << COLOR_POR_DEFECTO << endl;
    cout << endl;
    cout << "Piedra requerida: " << this -> materiales_necesarios[0] << endl;
    cout << "Madera requerida: " << this -> materiales_necesarios[1] << endl;
    cout << "Metal requerido: " << this -> materiales_necesarios[2] << endl;
    cout << "Construidos hasta el momento: " << this -> cantidad_construidos << endl;
    cout << "Puede construir " << this -> cantidad_permitida - this -> cantidad_construidos << " mas" << endl;
    cout << "Brinda material: SI" << endl;
    cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
}

void Fabrica::mostrar_saludo() {
    cout << COLOR_MARRON <<"Soy una fabrica y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO <<endl;
}

void Fabrica::borrar_ubicaciones() {
    for (int i = 0; i < this -> cantidad_construidos; i++) {
        delete[] this->ubicaciones[i];
        this -> ubicaciones[i] = 0;
    }
    delete [] this -> ubicaciones;
    this -> ubicaciones = 0;
}