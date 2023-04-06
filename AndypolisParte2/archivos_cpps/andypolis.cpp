#include <fstream>
#include <algorithm>
#include <cstdlib>
#include "../archivos_h/andypolis.h"

using namespace std;

Andypolis::Andypolis() {
    this -> cantidad_edificios = EDIFICIOS_DISPONIBLES_MINIMO;
    this -> edificios_disponibles = new Edificio*[this -> cantidad_edificios];
    this -> cargar_edificios_disponibles();
    this -> inventario.cargar_inventario();
    this -> mapa.cargar_mapa();
    this -> cargar_construidos();
}

void Andypolis::cargar_edificios_disponibles() {
    ifstream archivo_edificios(RUTA_EDIFICIOS);
    if (!archivo_edificios) {
        cout << COLOR_ROJO << "El archivo de edificios no existe. Para continuar, crealo y vuelve a correr el programa." << COLOR_POR_DEFECTO << endl;
        exit(1);
    }
    string nombre;
    string nombre2;
    int piedra;
    int madera;
    int metal;
    int permitidos;
    int numero_edificio = 0;
    while (archivo_edificios >> nombre) {
        if (nombre == "planta") {
            archivo_edificios >> nombre2;
            nombre += ' ' + nombre2;
        }
        archivo_edificios >> piedra;
        archivo_edificios >> madera;
        archivo_edificios >> metal;
        archivo_edificios >> permitidos;
        this -> agregar_edificio_a_vector(numero_edificio, nombre, piedra, madera, metal, permitidos);
        numero_edificio++;
    }
    archivo_edificios.close();
    this -> cantidad_edificios = numero_edificio;
    this -> redimensionar_arreglo_edificios(this -> cantidad_edificios);
}

void Andypolis::cargar_construidos() {
    ifstream archivo_ubicaciones(RUTA_UBICACIONES);
    if (!archivo_ubicaciones) {
        cout << COLOR_ROJO << "El archivo de ubicaciones no existe. Para continuar, crealo y vuelve a correr el programa." << COLOR_POR_DEFECTO << endl;
        exit(1);
    }
    string nombre;
    string nombre2;
    char basura;
    int coordenada_x;
    int coordenada_y;
    while (archivo_ubicaciones >> nombre) {
        if (nombre == "planta") {
            archivo_ubicaciones >> nombre2;
            nombre += ' ' + nombre2;
        }
        archivo_ubicaciones >> basura;
        archivo_ubicaciones >> coordenada_x;
        archivo_ubicaciones >> basura;
        archivo_ubicaciones >> coordenada_y;
        archivo_ubicaciones >> basura;
        Edificio* edificio = crear_edificio(nombre, coordenada_x, coordenada_y);
        this -> mapa.ocupar_casillero(edificio, 0, coordenada_x, coordenada_y);
    }
    archivo_ubicaciones.close();
}

void Andypolis::agregar_edificio_a_vector(int numero_edificio, string nombre, int piedra, int madera, int metal, int permitidos) {
    if (numero_edificio == this -> cantidad_edificios) {
        this -> redimensionar_arreglo_edificios(this -> cantidad_edificios * 2);
    }
    Edificio* edificio = 0;
    if (nombre == "aserradero") {
        edificio = new Aserradero(nombre, piedra, madera, metal, permitidos);
    }
    else if (nombre == "escuela") {
        edificio = new Escuela(nombre, piedra, madera, metal, permitidos);
    }
    else if (nombre == "fabrica") {
        edificio = new Fabrica(nombre, piedra, madera, metal, permitidos);
    }
    else if (nombre == "mina") {
        edificio = new Mina(nombre, piedra, madera, metal, permitidos);
    }
    else if (nombre == "obelisco") {
        edificio = new Obelisco(nombre, piedra, madera, metal, permitidos);
    }
    else if (nombre == "planta electrica") {
        edificio = new Planta_electrica(nombre, piedra, madera, metal, permitidos);
    }
    this -> edificios_disponibles[numero_edificio] = edificio;
}

void Andypolis::redimensionar_arreglo_edificios(int nueva_longitud) {
    Edificio** nuevo_vector_edificios = new Edificio*[nueva_longitud];
    for (int i = 0; i < this -> cantidad_edificios; i++) {
        nuevo_vector_edificios[i] = this -> edificios_disponibles[i];
    }
    delete [] this -> edificios_disponibles;
    this -> edificios_disponibles = nuevo_vector_edificios;
}

void Andypolis::guardar_edificios() {
    ofstream archivo(RUTA_UBICACIONES);
    int** ubicaciones = 0;
    for (int i = 0; i < this -> cantidad_edificios; i++) {
        ubicaciones = this -> edificios_disponibles[i] -> obtener_ubicaciones();
        for (int j = 0; j < this -> edificios_disponibles[i] -> obtener_construidos(); j++) {
            if (this->edificios_disponibles[i]->obtener_construidos()) {
                archivo << this->edificios_disponibles[i]->obtener_nombre();
                archivo << " (" << ubicaciones[j][0] << ", " << ubicaciones[j][1] << ")" << endl; 
            }
        }
    }   
}

bool Andypolis::existe_el_edificio(string edificio) {
    int indice = 0;
    bool existe = false;
    while (!existe && indice < this -> cantidad_edificios) {
        existe = this -> edificios_disponibles[indice] -> obtener_nombre() == edificio;
        indice++;
    }
    return existe;
}

void Andypolis::mostrar_nombres_de_edificios() {
    for (int i = 0; i < this -> cantidad_edificios; i++) {
        cout << ". " << this -> edificios_disponibles[i] -> obtener_nombre() << endl;
        cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
    }
}

int Andypolis::posicion_del_edifcio(string edificio) {
    int indice = 0;
    bool se_encontro = false;
    while (!se_encontro) {
        se_encontro = this -> edificios_disponibles[indice] -> obtener_nombre() == edificio;
        if (!se_encontro) {
            indice++;
        }
    }
    return indice;
}

int* Andypolis::obtener_materiales_necesarios(int pos_edificio) {
    int* materiales_necesarios = this -> edificios_disponibles[pos_edificio] -> obtener_materiales_necesarios();
    return materiales_necesarios;
}

int* Andypolis::obtener_posiciones_de_materiales() {
    int* posiciones = new int[3];
    int indice_piedra = this -> inventario.posicion_del_material("piedra");
    int indice_madera = this -> inventario.posicion_del_material("madera");
    int indice_metal = this -> inventario.posicion_del_material("metal");
    posiciones[0] = indice_piedra;
    posiciones[1] = indice_madera;
    posiciones[2] = indice_metal;
    return posiciones;
}

bool Andypolis::hay_materiales_suficientes(string edificio_a_construir) {
    int indice_edificio = posicion_del_edifcio(edificio_a_construir);
    Material* materiales_actuales = this -> inventario.obtener_inventario();
    int* materiales_necesarios = this -> edificios_disponibles[indice_edificio] -> obtener_materiales_necesarios();
    int* posiciones = obtener_posiciones_de_materiales();
    bool hay_piedra_suficiente = materiales_actuales[posiciones[0]].obtener_cantidad() > materiales_necesarios[0];
    bool hay_madera_suficiente = materiales_actuales[posiciones[1]].obtener_cantidad() > materiales_necesarios[1];
    bool hay_metal_suficiente = materiales_actuales[posiciones[2]].obtener_cantidad() > materiales_necesarios[2];
    delete [] posiciones;
    return hay_piedra_suficiente && hay_madera_suficiente && hay_metal_suficiente;
}

bool Andypolis::se_alcanzo_maximo_permitido(string edificio_a_construir) {
    int indice_edificio = posicion_del_edifcio(edificio_a_construir);
    return this -> edificios_disponibles[indice_edificio] -> obtener_construidos() == this -> edificios_disponibles[indice_edificio] -> obtener_cantidad_permitida();
}

bool Andypolis::confirmar_construccion(string edificio_a_construir) {
    string decision;
    cout << "Está seguro que quiere construir un/a " << edificio_a_construir << " ?(s/n): ";
    cin >> decision;
    transform(decision.begin(), decision.end(), decision.begin(), ::tolower);
    return (decision == "s");
}

int* Andypolis::pedir_coordenadas() {
    string coordenada_x;
    string coordenada_y;
    cout << "Ingrese la coordenada x(fila): ";
    cin >> coordenada_x;
    cout << "Ingrese la coordenada y(columna): ";
    cin >> coordenada_y;
    int* coordenadas = new int[2];
    coordenadas[0] = stoi(coordenada_x);
    coordenadas[1] = stoi(coordenada_y);
    return coordenadas;
}

void Andypolis::actualizar_cant_materiales(int pos_edificio) {
    int* materiales_necesarios = obtener_materiales_necesarios(pos_edificio);
    int piedra_necesaria = materiales_necesarios[0];
    int madera_necesaria = materiales_necesarios[1];
    int metal_necesario = materiales_necesarios[2];
    Material* materiales_actuales = this -> inventario.obtener_inventario();
    int* posiciones = obtener_posiciones_de_materiales();
    materiales_actuales[posiciones[0]].usar_material(piedra_necesaria);
    materiales_actuales[posiciones[1]].usar_material(madera_necesaria);
    materiales_actuales[posiciones[2]].usar_material(metal_necesario);
    delete [] posiciones;
}


bool Andypolis::se_puede_construir(int coordenada_x, int coordenada_y) {
    return this -> mapa.se_puede_construir(coordenada_x, coordenada_y) && !this -> mapa.esta_ocupado(coordenada_x, coordenada_y);
}

Edificio* Andypolis::crear_edificio(string nombre_edificio, int coordenada_x, int coordenada_y) {
    Edificio* edificio_creado = 0;
    if (nombre_edificio == "aserradero") {
        edificio_creado = new Aserradero(nombre_edificio, coordenada_x, coordenada_y);
    }
    else if (nombre_edificio == "escuela") {
        edificio_creado = new Escuela(nombre_edificio, coordenada_x, coordenada_y);
    }
    else if (nombre_edificio == "fabrica") {
        edificio_creado = new Fabrica(nombre_edificio, coordenada_x, coordenada_y);
    }
    else if (nombre_edificio == "mina") {
        edificio_creado = new Mina(nombre_edificio, coordenada_x, coordenada_y);
    }
    else if (nombre_edificio == "obelisco") {
        edificio_creado = new Obelisco(nombre_edificio, coordenada_x, coordenada_y);
    }
    else if (nombre_edificio == "planta electrica") {
        edificio_creado = new Planta_electrica(nombre_edificio, coordenada_x, coordenada_y);
    }
    return edificio_creado;
}

string Andypolis::pedir_nombre_de_edificio() {
    string edificio_a_construir;
    cout << "Edificios disponibles para construir" << endl;
    cout << COLOR_VERDE_AGUA << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
    mostrar_nombres_de_edificios();
    cout << "Ingrese el nombre del edificio que desea construir: ";
    getline(cin.ignore(), edificio_a_construir);
    transform(edificio_a_construir.begin(), edificio_a_construir.end(), edificio_a_construir.begin(), ::tolower);
    return edificio_a_construir;
}

void Andypolis::validar_nombre_de_edificio(string edificio_a_construir) {
    if (!this -> existe_el_edificio(edificio_a_construir)) {
        cout << COLOR_ROJO << "El edificio ingresado no existe, intente nuevamente" << COLOR_POR_DEFECTO << endl;
    }
    else if (!this -> hay_materiales_suficientes(edificio_a_construir)) {
        cout << COLOR_ROJO << "No hay materiales suficientes para construir " << edificio_a_construir << COLOR_POR_DEFECTO << endl;
    }
    else if (this -> se_alcanzo_maximo_permitido(edificio_a_construir)) {
        cout << COLOR_ROJO << "Ya estan construidos la cantidad maxima de " << edificio_a_construir << " posibles" << COLOR_POR_DEFECTO << endl;
    }
    else {
        if (!this -> confirmar_construccion(edificio_a_construir)) {
            cout << COLOR_VERDE << "Operacion cancelada" << COLOR_POR_DEFECTO << endl;
        }
        else {
            int* coordenadas = pedir_coordenadas();
            if (this -> mapa.coordenadas_fuera_de_rango(coordenadas[0], coordenadas[1])) {
                cout << COLOR_ROJO << "Las coordenadas son inválidas, intente nuevamente" << COLOR_POR_DEFECTO << endl;
            }
            else if (!se_puede_construir(coordenadas[0], coordenadas[1])) {
                cout << COLOR_ROJO << "No es posible construir en esas coordenadas" << COLOR_POR_DEFECTO << endl;
            }
            else {
                int indice_edificio = this -> posicion_del_edifcio(edificio_a_construir);
                Edificio* nuevo_edificio = this -> crear_edificio(edificio_a_construir, coordenadas[0], coordenadas[1]);
                this -> actualizar_cant_materiales(indice_edificio);
                this -> mapa.ocupar_casillero(nuevo_edificio, 0, coordenadas[0], coordenadas[1]);
                cout << COLOR_VERDE << "El edificio fue construido statisfactoriamente" << COLOR_POR_DEFECTO << endl;
            }
            delete [] coordenadas;
        }
    }
}

void Andypolis::construir_edificio_por_nombre() {
    string edificio_a_construir = pedir_nombre_de_edificio();
    validar_nombre_de_edificio(edificio_a_construir);
}

void Andypolis::mostrar_ubicaciones(int construidos, int** ubicaciones) {
    for (int j = 0; j < construidos; j++) {
        cout << "(" << ubicaciones[j][0] << ", " << ubicaciones[j][1] << ") ";
    }
}

void Andypolis::listar_edificios_construidos() {
    int construidos = 0;
    int** ubicaciones = 0;
    for (int i = 0; i < this -> cantidad_edificios; i++) {
        construidos = this -> edificios_disponibles[i] -> obtener_construidos();
        if (construidos) {
            ubicaciones = this -> edificios_disponibles[i] -> obtener_ubicaciones();
            cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
            cout << "--> " << COLOR_VERDE_AGUA << this -> edificios_disponibles[i] -> obtener_nombre() << COLOR_POR_DEFECTO << endl;
            cout << "Construidos: " << construidos << endl;
            cout << "Ubicaciones: ";
            this -> mostrar_ubicaciones(this -> edificios_disponibles[i] -> obtener_construidos(), ubicaciones);
            cout << endl;
        }
    }
}

void Andypolis::listar_todos_edificios() {
    for (int i = 0; i < this -> cantidad_edificios; i++) {
        this -> edificios_disponibles[i] -> mostrar_edificio();
        cout << endl;
    }
}

void Andypolis::demoler_edificio_por_coordenada() {
    int* coordenadas = pedir_coordenadas();
    validar_entrada_para_demoler(coordenadas[0], coordenadas[1]);
    delete [] coordenadas;
    coordenadas = 0;
}

void Andypolis::validar_entrada_para_demoler(int coordenada_x, int coordenada_y) {
    if (this -> mapa.coordenadas_fuera_de_rango(coordenada_x, coordenada_y)) {
        cout << COLOR_ROJO << "Oops, intentaste acceder a una coordenada fuera de rango, intenta nuevamente" << COLOR_POR_DEFECTO << endl;
    }
    else if (!this -> mapa.esta_ocupado(coordenada_x, coordenada_y)) {
        cout << COLOR_ROJO << "En las coordenadas ingresadas no hay nada para demoler" << COLOR_POR_DEFECTO << endl;
    }
    else if (this -> mapa.obtener_casillero(coordenada_x, coordenada_y) != 'T'){
        cout << COLOR_ROJO << "En las coordenadas ingresadas no se puede demoler dado que no es un casillero de tipo Terreno" << COLOR_POR_DEFECTO << endl;
    }
    else {
        Edificio* edificio = this -> mapa.obtener_elemento(coordenada_x, coordenada_y);
        edificio -> demoler(coordenada_x, coordenada_y);
        string edificio_demolido = edificio -> obtener_nombre();
        this -> devolver_mitad_materiales(edificio_demolido);
        this -> mapa.liberar_posicion(coordenada_x, coordenada_y);
        cout << COLOR_VERDE << edificio_demolido << " fue demolido statisfactoriamente!" << COLOR_POR_DEFECTO << endl;
    }
}

void Andypolis::devolver_mitad_materiales(string nombre_edificio) {
    int pos_edificio = posicion_del_edifcio(nombre_edificio);
    int* materiales_necesarios = obtener_materiales_necesarios(pos_edificio);
    int piedra_necesaria = materiales_necesarios[0];
    int madera_necesaria = materiales_necesarios[1];
    int metal_necesario = materiales_necesarios[2];
    Material* materiales_actuales = this -> inventario.obtener_inventario();
    int* posiciones = obtener_posiciones_de_materiales();
    materiales_actuales[posiciones[0]].establecer_cantidad(piedra_necesaria / 2);
    materiales_actuales[posiciones[1]].establecer_cantidad(madera_necesaria / 2);
    materiales_actuales[posiciones[2]].establecer_cantidad(metal_necesario / 2);
    delete [] posiciones;
    posiciones = 0;
}

void Andypolis::mostrar_mapa() {
    this -> mapa.mostrar_mapa();
}

void Andypolis::consultar_coordenada() {
    int coordenada_x;
    int coordenada_y;
    cout << "Ingrese la coordenada x(fila): ";
    cin >> coordenada_x;
    cout << "Ingrese la coordenada y(columna): ";
    cin >> coordenada_y;
    cout << endl;
    this -> mapa.consultar_coordenada(coordenada_x, coordenada_y);
}

void Andypolis::mostrar_inventario() {
    this -> inventario.mostrar_inventario();
}

void Andypolis::recolectar_recursos_producidos() {
    Material* inventario = this -> inventario.obtener_inventario();
    int* posiciones = obtener_posiciones_de_materiales();
    int contador = 0;
    for (int i = 0; i < this -> cantidad_edificios; i++) {
        if (this -> edificios_disponibles[i] -> obtener_construidos() && this -> edificios_disponibles[i] -> brindar_materiales()) {
            int material = this -> edificios_disponibles[i] -> brindar_materiales();
            if (this -> edificios_disponibles[i] -> obtener_nombre() == "aserradero") {
                int cantidad = this -> edificios_disponibles[i] -> obtener_construidos();
                inventario[posiciones[1]].establecer_cantidad(material * cantidad);
                contador++;
            }
            else if (this -> edificios_disponibles[i] -> obtener_nombre() == "fabrica") {
                int cantidad = this -> edificios_disponibles[i] -> obtener_construidos();
                inventario[posiciones[2]].establecer_cantidad(material * cantidad);
                contador++;
            }
            else if (this -> edificios_disponibles[i] -> obtener_nombre() == "mina") {
                int cantidad = this -> edificios_disponibles[i] -> obtener_construidos();
                inventario[posiciones[0]].establecer_cantidad(material * cantidad);
                contador++;
            }
        }
    }
    delete [] posiciones;
    posiciones = 0;
    cout << COLOR_VERDE_AGUA << contador << " edificios brindarion materiales. Verifique cuáles con la opcion 3" << COLOR_POR_DEFECTO << endl;
}

void Andypolis::lluvia_de_recursos() {
    int piedra_a_generar = 1 + (rand() % 2);
    int madera_a_generar = (rand() % 2);
    int metal_a_generar = 2 + (rand() % 3);
    llueve_piedra(piedra_a_generar);
    llueve_madera(madera_a_generar);
    llueve_metal(metal_a_generar);
}

void Andypolis::llueve_piedra(int cantidad) {
    if(!this -> mapa.es_posible_insertar_materiales(cantidad)) {
        cout << COLOR_ROJO << "No hay suficientes casilleros disponibles para generar piedras" << COLOR_POR_DEFECTO << endl;
    }
    else {
        cout << "Se generaron piedras en: " << endl;
        for (int i = 0; i < cantidad; i++) {
            int* coordenadas = this -> mapa.generar_coordenadas_validas();
            this -> mapa.ocupar_casillero(0, new Material("piedra", 1), coordenadas[0], coordenadas[1]);
            cout << '(' << coordenadas[0] << ',' << coordenadas[1] << ')' << endl;
            delete [] coordenadas;
            coordenadas = 0;
        }
        cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
    }
}

void Andypolis::llueve_madera(int cantidad) {
    if(!this -> mapa.es_posible_insertar_materiales(cantidad)) {
        cout << COLOR_ROJO << "No hay suficientes casilleros disponibles para generar madera" << COLOR_POR_DEFECTO << endl;
    }
    else {
        cout << "Se genero madera en: " << endl;
        for (int i = 0; i < cantidad; i++) {
            int* coordenadas = this -> mapa.generar_coordenadas_validas();
            this -> mapa.ocupar_casillero(0, new Material("madera", 1), coordenadas[0], coordenadas[1]);
            cout << '(' << coordenadas[0] << ',' << coordenadas[1] << ')' << endl;
            delete [] coordenadas;
            coordenadas = 0;
        }
        cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
    }
}

void Andypolis::llueve_metal(int cantidad) {
    if(!this -> mapa.es_posible_insertar_materiales(cantidad)) {
        cout << COLOR_ROJO << "No hay suficientes casilleros disponibles para generar metales" << COLOR_POR_DEFECTO << endl;
    }
    else {
        cout << "Se generaron metales en: " << endl;
        for (int i = 0; i < cantidad; i++) {
            int* coordenadas = this -> mapa.generar_coordenadas_validas();
            this -> mapa.ocupar_casillero(0, new Material("metal", 1), coordenadas[0], coordenadas[1]);
            cout << '(' << coordenadas[0] << ',' << coordenadas[1] << ')' << endl;
            delete [] coordenadas;
            coordenadas = 0;
        }
        cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
    }
}

void Andypolis::guardar_y_salir() {
    this -> inventario.guardar_inventario();
    this -> guardar_edificios();
}

void Andypolis::mostrar_menu() {
    cout << endl;
    cout << "𝕄𝔼ℕ𝕌" << endl;
    cout << "╔═══════════════════════════════════════════╗" << endl;
    cout << "║ 1. Construir edificio por nombre  "  << LOGO_CONSTRUIR  << "       ║" << endl;
    cout << "║                                           ║"  << endl;
    cout << "║ 2. Listar los edificios construidos  " << LOGO_LISTAR_CONSTRUIDOS << "   ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 3. Listar todos los edificios  " << LOGO_LISTAR_TODOS_EDIFICIOS << "          ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 4. Demoler un edificio por coordenada  " << LOGO_DEMOLER << " ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 5. Mostrar mapa  " << LOGO_MAPA << "                       ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 6. Consultar coordenada  " << LOGO_CONSULTAR_COORDENADAS << "                ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 7. Mostrar inventario  " << LOGO_INVENTARIO << "                 ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 8. Recolectar recursos producidos  " << LOGO_RECOLECTAR_RECURSOS << "      ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 9. Lluvia de recursos  " << LOGO_LLUVIA_RECURSOS << "                  ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 10. Guardar y salir  " << LOGO_GUARDAR << "                   ║" << endl;
    cout << "╚═══════════════════════════════════════════╝" << endl;
}

void Andypolis::elegir_opcion() {
    this -> mostrar_menu();
    int opcion_ingresada;
    cout << "Ingrese la opcion deseada: ";
    cin >> opcion_ingresada;
    system(CLR_SCREEN);
    switch (opcion_ingresada) {
        case 1:
            construir_edificio_por_nombre();
            break;
        case 2:
            listar_edificios_construidos();
            break;
        case 3:
            listar_todos_edificios();
            break;
        case 4:
            demoler_edificio_por_coordenada();
            break;
        case 5:
            mostrar_mapa();
            break;
        case 6:
            consultar_coordenada();
            break;
        case 7:
            mostrar_inventario();
            break;
        case 8:
            recolectar_recursos_producidos();
            break;
        case 9:
            lluvia_de_recursos();
            break;
        case 10:
            guardar_y_salir();
            break;
        default:
            cout << COLOR_ROJO << "Oops, opcion incorrecta. Intenta nuevamente" << COLOR_POR_DEFECTO << endl;
            break;
    }
    if(opcion_ingresada != 10){
        this -> elegir_opcion();
    }
}

Andypolis::~Andypolis() {
    for(int i = 0; i < this -> cantidad_edificios; i++) {
        this -> edificios_disponibles[i] -> borrar_ubicaciones();
        delete this -> edificios_disponibles[i];
    }
    delete [] this -> edificios_disponibles;
    this -> edificios_disponibles = 0;
}