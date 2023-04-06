#include "Material.h"
using namespace std;

Material::Material(){
}

Material::Material(string material, int cantidad) {
    this -> material = material;
    this -> cantidad = cantidad;
}

string Material::obtener_tipo() {
    return this -> material;
}

int Material::obtener_cantidad() {
    return this -> cantidad;
}

void Material::usar_material(int cantidad_necesario) {
    this -> cantidad -= cantidad_necesario;
}

void Material::devolver_material(int cantidad_devuelta) {
    this -> cantidad += cantidad_devuelta;
}

void Material::mostrar_material() {
    cout << "|" << setw(10) << this -> material << "|" << setw(10) << this -> cantidad << "|" << endl;
}