#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include <iostream>
#include <algorithm>
#include "constantes.h"

class Edificio{
    protected:
        // Atributos
        std::string nombre;
        int* materiales_necesarios;
        int cantidad_permitida;
        std::string representacion;

    public:
        // Constructor
        Edificio();
        //Metodos

        // PRE:
        // POS: devuelve el nombre del edificio
        std::string obtener_nombre();

        // PRE:
        // POS: devuelve la cantidad permitida del edificio en cuestion
        int obtener_cantidad_permitida();

        // PRE:
        // POS: devuelve un puntero a los materiales necesario del edificio en cuestion
        int* obtener_materiales_necesarios();
        
        // PRE:
        // POS: devuelve la representacion del edificio en cuestion
        std::string obtener_representacion();
        
        // PRE:
        // POS: devuelve los materiales porducidos por el edificio
        virtual int brindar_materiales();

        // PRE:
        // POS: muestra por pantalla el saludo del edificio
        virtual void mostrar_saludo() = 0;
        
        // PRE:
        // POS: devuelve la cantidad de edficios en cuestion construidos
        virtual int obtener_construidos() = 0;

        // PRE:
        // POS: devuelve un doble puntero a las ubicaciones del edificio en cuestion
        virtual int** obtener_ubicaciones() = 0;

        // PRE: recibe dos coordenadas
        // POS: borra las coordenadas recibidas del arreglo de ubicaciones
        virtual void demoler(int coordenada_x, int coordenada_y) = 0;

        // PRE:
        // POS: muestra las caractersiticas del edificio
        virtual void mostrar_edificio() = 0;

        // PRE:
        // POS: borra el vector de ubicaciones del edificio en cuestion
        virtual void borrar_ubicaciones() = 0;

        // PRE: recibe la nueva longitud del arreglo
        // POS: redimensiona el arreglo de ubicaciones
        virtual void redimensionar_ubicaciones(int nueva_longitud) = 0;

        // Destructor
        virtual ~Edificio();
};

#endif