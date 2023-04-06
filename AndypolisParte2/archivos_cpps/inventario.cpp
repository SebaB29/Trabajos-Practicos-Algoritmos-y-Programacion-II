#include "../archivos_h/inventario.h"
#include <fstream>

using namespace std;

Inventario::Inventario() {
    this -> cantidad_materiales = 0;
    this -> inventario = new Material[MATERIALES_DISPONIBLES_MINIMO];
}

void Inventario::cargar_inventario() {
    ifstream archivo_materiales(RUTA_MATERIALES);
    if (!archivo_materiales) {
        cout << COLOR_ROJO << "El archivo de materiales no existe. Para continuar, crealos y volve a correr el programa." << COLOR_POR_DEFECTO << endl;
        exit(1);
    }
    string tipo_material;
    int cantidad = 0;
    while (archivo_materiales >> tipo_material >> cantidad) {
        this -> inventario[this -> cantidad_materiales] = Material(tipo_material, cantidad);
        this -> cantidad_materiales++;

        if (this -> cantidad_materiales == MATERIALES_DISPONIBLES_MINIMO) {
            this -> redimensionar_inventario(this -> cantidad_materiales * 2);
        }
    }
    archivo_materiales.close();
    this -> redimensionar_inventario(this -> cantidad_materiales);
}

void Inventario::redimensionar_inventario(int nueva_longitud) {
    Material* nuevo_inventario = new Material[nueva_longitud];
    for (int i = 0; i < this -> cantidad_materiales; i++) {
        nuevo_inventario[i] = this -> inventario[i];
    }
    delete [] this -> inventario;
    this -> inventario = nuevo_inventario;
}

void Inventario::guardar_inventario() {
    ofstream archivo_materiales(RUTA_MATERIALES);
    for (int i = 0; i < this -> cantidad_materiales; i++) {
        string nombre_material = this -> inventario[i].obtener_tipo();
        int cantidad = this -> inventario[i].obtener_cantidad();
        archivo_materiales << nombre_material << DELIMITADOR << cantidad << endl;
    }
    archivo_materiales.close();
}

int Inventario::obtener_cantidad_materiales() {
    return this -> cantidad_materiales;
}

Material* Inventario::obtener_inventario() {
    return this -> inventario;
}

int Inventario::posicion_del_material(string material) {
    int indice = 0;
    while (this -> inventario[indice].obtener_tipo() != material) {
        indice++;
    }
    return indice;
}

void Inventario::mostrar_inventario() {
    for (int i = 0; i < this -> cantidad_materiales; i++) {
        this -> inventario[i].mostrar_material();
        cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
    }
}

Inventario::~Inventario() {
    delete [] this -> inventario;
    this -> inventario = 0;
}