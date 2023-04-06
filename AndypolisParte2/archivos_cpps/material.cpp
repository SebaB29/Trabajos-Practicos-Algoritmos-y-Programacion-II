#include "../archivos_h/material.h"

using namespace std;

Material::Material(){}

Material::Material(string tipo_material, int cantidad){
    this -> tipo_material = tipo_material;
    this -> cantidad = cantidad;
}

string Material::obtener_tipo(){
    return this -> tipo_material;
}

int Material::obtener_cantidad(){
    return this -> cantidad;
}

void Material::establecer_cantidad(int cantidad_material) {
    this -> cantidad += cantidad_material;
}

void Material::usar_material(int cantidad_necesaria){
    this -> cantidad -= cantidad_necesaria;
}

void Material::mostrar_material(){
    cout << "--> Material: " << this -> tipo_material << ", cantidad: " << this -> cantidad << endl;
}

void Material::saludar(){
    cout << "Soy un/a " << this->tipo_material << " y me encuentro en el casillero consultado" << endl;
}

char Material::obtener_representacion(){
    char representacion = 'a';
    if(this -> tipo_material == "piedra"){
        representacion = 'S';
    }
    else if(this -> tipo_material == "madera"){
        representacion = 'W';
    }
    else if(this -> tipo_material == "metal"){
        representacion = 'I';
    }
    return representacion;
}