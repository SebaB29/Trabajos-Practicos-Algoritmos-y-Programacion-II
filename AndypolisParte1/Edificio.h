#ifndef EDIFICIO_H_INCLUDED
#define EDIFICIO_H_INCLUDED

#include "Material.h"

class Edificio {
    private:
    // Atributos

        std::string nombre;
        int construidos, permitidos, materiales_necesarios[3];

    public:
    // Métodos

        // PRE: -
        // POS: Construye un objeto Edificio
        Edificio();

        // PRE: Recibe un string con el nombre, la cantidad que se construyeron, la cantidad que se permiten (enteros positivos) y un puntero de enteros
        // POS: Construye un objeto Edificio
        Edificio(std::string nombre, int construidos, int permitidos, int* materiales);

        // PRE: -
        // POS: Devuelve el nombre del edficio
        std::string obtener_nombre();

        // PRE: -
        // POS: Devuelve la cantidad que están construidos
        int obtener_construidos();

        // PRE: -
        // POS: Devuelve la cantidad que se permiten construir
        int obtener_permitidos();

        // PRE: -
        // POS: Devuelve la cantidad de materiales necesarios
        int* obtener_materiales();

        // PRE: -
        // POS: Muestra por pantalla los atributos del edificio
        void mostrar_edificio();

        //PRE: Recibe un arreglo de objetos Material y el número de materiales disponibles
        // POS: Si es posible construir suma 1 a la cantidad construidos y muestra un mensaje por pantella
        // si no es posible muestra un mensaje por pantalla diciendo porque no se pudo
        void construir(Material materiales[], int numero_materiales);

        // PRE: Recibe un arreglo de objetos Material y el número de materiales disponibles
        // POS: Si hay al menos uno construido decrementa la cantidad construida y muestra un mensaje por pantalla
        // si no hay ninguno construido muestra por pantalla otro mesaje
        void demoler(Material materiales[], int numero_materiales);
};

#endif