#ifndef ANDYPOLIS_H_INCLUDED
#define ANDYPOLIS_H_INCLUDED

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "cls"
#endif // __MINGW32__

#include "Edificio.h"
#include <fstream>

#define ARCHIVO_MATERIALES "materiales.txt"
#define ARCHIVO_EDIFICIOS "edificios.txt"
const int MATERIALES_DISPONIBLES_MINIMO = 3;
const int EDIFICIOS_DISPONIBLES_MINIMO = 4;

class Andypolis {
    private:
    // Atributos
        int numero_materiales, numero_edificios;
        Material* materiales;
        Edificio* edificios;
    
    // Métodos
        // PRE: -
        // POS: Carga los materiales del archivo ARCHIVO_MATERIALES
        void cargar_materiales();

        // PRE: -
        // POS: Carga los edificios del archivo ARCHIVO_EDIFICIOS
        void cargar_edificios();

        // PRE: Recibe un entero positivo
        // POS: Redimensiona el arreglo de materiales
        void redimensionar_materiales(int nueva_longitud);

        // PRE: Recibe un entero positivo
        // POS: Redimensiona el arreglo de edificios
        void redimensionar_edificios(int nueva_longitud);

        //PRE: -
        // POS: Guarda los nuevos datos de los materiales
        void guardar_materiales();

        //PRE: -
        // POS: Guarda los nuevos datos de los edificios
        void guardar_edificios();

    public:
        // PRE: -
        // POS: Construye un Objeto Andypolis
        Andypolis();

        // PRE: -
        // POS: Muestra por pantala el menú de opciónes
        void mostrar_menu();

        // PRE: Recibe un entero positivo y un puntero a una variable booleana
        // POS: Realiza una acción según el número recibido y modifica la variable
        // booleana en caso de que la opción sea salir (número 6)
        void leer_entrada(int opcion, bool* salir);

        // PRE: -
        // POS: Muetra por pantalla la lista de edificios construidos
        void listar_edificios_construidos();

        // PRE: -
        // POS: Muestra por pantalla la lista de materiales disponibles
        void listar_materiales();

        // PRE: -
        // POS: Muestra por pantalla la lista de edficios disponibles y sus características
        void listar_edificios();
};

#endif