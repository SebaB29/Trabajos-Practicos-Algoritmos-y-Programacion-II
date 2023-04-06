#include "Andypolis.h"
using namespace std;

Andypolis::Andypolis() {
    this -> materiales = new Material[MATERIALES_DISPONIBLES_MINIMO];
    this -> edificios = new Edificio[EDIFICIOS_DISPONIBLES_MINIMO];
    this -> numero_materiales = 0;
    this -> numero_edificios = 0;
    cargar_materiales();
    cargar_edificios();
}

void Andypolis::cargar_materiales() {
    string material;
    int cantidad_material;

    ifstream archivo(ARCHIVO_MATERIALES);
    while (archivo >> material >> cantidad_material) {
        this -> materiales[this -> numero_materiales] = Material(material, cantidad_material);
        this -> numero_materiales++;

        if (this -> numero_materiales == MATERIALES_DISPONIBLES_MINIMO) {
            redimensionar_materiales(this -> numero_materiales * 2);
        }
    }
    archivo.close();
    redimensionar_materiales(this -> numero_materiales);
}

void Andypolis::cargar_edificios() {
    string nombre;
    int construidos, permitidos, materiales_necesarios[3];

    ifstream archivo(ARCHIVO_EDIFICIOS);
    while (archivo >> nombre) {
        for (int i = 0; i < 3; i++) {
            archivo >> materiales_necesarios[i];
        }
        archivo >> construidos >> permitidos;
        this -> edificios[this -> numero_edificios] = Edificio(nombre, construidos, permitidos, materiales_necesarios);
        this -> numero_edificios++;

        if (this -> numero_edificios == EDIFICIOS_DISPONIBLES_MINIMO) {
            redimensionar_edificios(this -> numero_edificios * 2);
        }
    }
    archivo.close();
    redimensionar_edificios(this -> numero_edificios);
}

void Andypolis::redimensionar_materiales(int nueva_longitud) {
    Material* nuevo_arreglo_materiales = new Material[nueva_longitud];
    for (int i = 0; i < this -> numero_materiales; i++) {
        nuevo_arreglo_materiales[i] = this -> materiales[i];
    }

    delete [] this -> materiales;
    this -> materiales = nuevo_arreglo_materiales;
}

void Andypolis::redimensionar_edificios(int nueva_longitud) {
    Edificio* nuevo_arreglo_edificios = new Edificio[nueva_longitud];
    for (int i = 0; i < this -> numero_edificios; i++) {
        nuevo_arreglo_edificios[i] = this -> edificios[i];
    }

    delete [] this -> edificios;
    this -> edificios = nuevo_arreglo_edificios;
}

void Andypolis::mostrar_menu() {
    cout << string(31, '-') << endl;
    cout << "|" << 1 << " |" << left << setw(26) << " Ver Materiales"            << "|" << endl;
    cout << "|" << 2 << " |" << left << setw(26) << " Ver Todos Los Edificios"   << "|" << endl;
    cout << "|" << 3 << " |" << left << setw(26) << " Construir Edificio"        << "|" << endl;
    cout << "|" << 4 << " |" << left << setw(26) << " Demoler Edificio"          << "|" << endl;
    cout << "|" << 5 << " |" << left << setw(26) << " Ver Edificios Construidos" << "|" << endl;
    cout << "|" << 6 << " |" << left << setw(26) << " Guardar y Salir"           << "|" << endl;
    cout << string(31, '-') << endl;
}

void Andypolis::leer_entrada(int opcion, bool* salir) {
    string nombre_edificio;
    bool nombre_valido;
    int i = -1;

    switch (opcion) {
        case 1:
            listar_materiales();
        break;

        case 2:
            listar_edificios();
        break;

        case 3: case 4:
            listar_edificios();
            cout << "Ingrese el nombre del edificio: "; cin >> nombre_edificio;
            cout << endl;
            do {
                i++;
                nombre_valido = this -> edificios[i].obtener_nombre() == nombre_edificio;
            } while (i < this -> numero_edificios && !nombre_valido);

            if (!nombre_valido) {
                cout << "No existe el edificio: " << nombre_edificio << endl;
            }
            else if (opcion == 3) {
                this -> edificios[i].construir(this -> materiales, this -> numero_materiales);
            }
            else {
                this -> edificios[i].demoler(this -> materiales, this -> numero_materiales);
            }
        break;

        case 5:
            listar_edificios_construidos();
        break;

        case 6:
            guardar_materiales();
            guardar_edificios();
            delete [] this -> materiales;
            delete [] this -> edificios;
            *salir = true;
        break;

        default:
            cout << "OPCIÓN INVÁLIDA" << endl;
    }
}

void Andypolis::listar_materiales() {
    cout << string(23, '-') << endl;
    cout << "|" << setw(10) << "Material" << "|" << setw(10) << "Cantidad" << "|" << endl;
    cout << string(23, '-') << endl;

    for (int i = 0; i < this -> numero_materiales; i++) {
        this -> materiales[i].mostrar_material();
    }

    cout << string(23, '-') << endl;
}

void Andypolis::listar_edificios() {
    cout << string(97, '-') << endl;
    cout << "|" << setw(15) << "Edificio" << "|" << setw(15) << "Construidos" << "|" << setw(15) << "Disponibles";
    cout << "|" << setw(15) << "Madera" << "|" << setw(15) << "Piedra" << "|" << setw(15) << "Metal" << "|" << endl;
    cout << string(97, '-') << endl;

    for (int i = 0; i < this -> numero_edificios; i++) {
        this -> edificios[i].mostrar_edificio();
    }

    cout << string(97, '-') << endl;
}

void Andypolis::listar_edificios_construidos() {
    cout << string(33, '-') << endl;
    cout << "|" << setw(15) << "Edificio" << "|" << setw(15) << "Construidos" << "|" << endl;
    cout << string(33, '-') << endl;

    int construidos;
    for (int i = 0; i < this -> numero_edificios; i++) {
        construidos = this -> edificios[i].obtener_construidos();
        if (construidos > 0) {
            cout << "|" << setw(15) << this -> edificios[i].obtener_nombre() << "|" << setw(15) << construidos << "|" << endl;
        }
    }

    cout << string(33, '-') << endl;
}

void Andypolis::guardar_materiales() {
    ofstream archivo(ARCHIVO_MATERIALES);
    for (int i = 0; i < this -> numero_materiales; i++) {
        archivo << this -> materiales[i].obtener_tipo() << " " << this -> materiales[i].obtener_cantidad() << endl;
    }
}

void Andypolis::guardar_edificios() {
    ofstream archivo(ARCHIVO_EDIFICIOS);
    for (int i = 0; i < this -> numero_edificios; i++) {
        archivo << this -> edificios[i].obtener_nombre();
        archivo << " " << this -> edificios[i].obtener_materiales()[0];
        archivo << " " << this -> edificios[i].obtener_materiales()[1];
        archivo << " " << this -> edificios[i].obtener_materiales()[2];
        archivo << " " << this -> edificios[i].obtener_construidos();
        archivo << " " << this -> edificios[i].obtener_permitidos() << endl;
    }
}