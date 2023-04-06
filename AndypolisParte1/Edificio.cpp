#include "Edificio.h"
using namespace std;

Edificio::Edificio() {
}

Edificio::Edificio(string nombre, int construidos, int permitidos, int* materiales) {
    this -> nombre = nombre;
    this -> construidos = construidos;
    this -> permitidos = permitidos;
    for (int i = 0; i < 3; i++) {
        this -> materiales_necesarios[i] = materiales[i];
    }
}

string Edificio::obtener_nombre() {
    return this -> nombre;
}

int Edificio::obtener_construidos() {
    return this -> construidos;
}

int Edificio::obtener_permitidos() {
    return this -> permitidos;
}

int* Edificio::obtener_materiales() {
    return this -> materiales_necesarios;
}

void Edificio::mostrar_edificio() {
    int disponibles = this -> permitidos - this -> construidos;
    cout << "|" << setw(15) << this -> nombre;
    cout << "|" << setw(15) << this -> construidos;
    cout << "|" << setw(15) << disponibles;
    cout << "|" << setw(15) << this -> materiales_necesarios[1];
    cout << "|" << setw(15) << this -> materiales_necesarios[0];
    cout << "|" << setw(15) << this -> materiales_necesarios[2];
    cout << "|" << endl;
}

void Edificio::construir(Material materiales[], int numero_materiales) {
    if (this -> construidos == this -> permitidos) {
        cout << "Ya construiste la cantidad máxima de " << this -> nombre << endl;
        return;
    }

    int i = 0;
    bool materiales_suficientes, condicion1 = true, condicion2 = true, condicion3 = true;
    do {
        if (materiales[i].obtener_tipo() == "piedra") {
            condicion1 = materiales[i].obtener_cantidad() > this -> materiales_necesarios[0];
        }
        else if (materiales[i].obtener_tipo() == "madera") {
            condicion2 = materiales[i].obtener_cantidad() > this -> materiales_necesarios[1];
        }
        else if (materiales[i].obtener_tipo() == "metal") {
            condicion3 = materiales[i].obtener_cantidad() > this -> materiales_necesarios[2];
        }

        materiales_suficientes = condicion1 && condicion2 && condicion3;
        i++;
    } while (i < numero_materiales && materiales_suficientes);

    if (!materiales_suficientes) {
        cout << "No tienes suficientes materiales" << endl;
        return;
    }

    for (int j = 0; j < numero_materiales; j++) {
        if (materiales[j].obtener_tipo() == "piedra") {
            materiales[j].usar_material(this -> materiales_necesarios[0]);
        }
        else if (materiales[j].obtener_tipo() == "madera") {
            materiales[j].usar_material(this -> materiales_necesarios[1]);
        }
        else if (materiales[j].obtener_tipo() == "metal") {
            materiales[j].usar_material(this -> materiales_necesarios[2]);
        }
    }

    cout << "Se construyó " << this -> nombre << endl;
    this -> construidos++;
}

void Edificio::demoler(Material materiales[], int numero_materiales) {
    if (!this -> construidos) {
        cout << "Aún no has construido " << this -> nombre << endl;
        return;
    }
    for (int i = 0; i < numero_materiales; i++) {
        if (materiales[i].obtener_tipo() == "piedra") {
            materiales[i].devolver_material(this -> materiales_necesarios[0] / 2);
        }
        else if (materiales[i].obtener_tipo() == "madera") {
            materiales[i].devolver_material(this -> materiales_necesarios[1] / 2);
        }
        else if (materiales[i].obtener_tipo() == "metal") {
            materiales[i].devolver_material(this -> materiales_necesarios[2] / 2);
        }
    }

    cout << "Se demolió " << this -> nombre << endl;
    this -> construidos--;
}
