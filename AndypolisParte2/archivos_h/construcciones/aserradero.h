#ifndef ASERRADERO_H
#define ASERRADERO_H
#include "../edificios.h"
#include "../constantes.h"

class Aserradero: public Edificio {
    private:
        static int cantidad_construidos;
        static int** ubicaciones;

    public:
        // Constructores
        Aserradero(std::string nombre, int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);
        
        Aserradero(std::string nombre, int coord_x, int coord_y);

        // PRE:
        // POS: devuelve los materiales porducidos por el edificio
        int brindar_materiales();

        // PRE:
        // POS: muestra por pantalla el saludo del edificio
        void mostrar_saludo();

        // PRE:
        // POS: devuelve la cantidad de edficios construidos
        int obtener_construidos();

        // PRE:
        // POS: muestra las caracteristicas del edificio(materiales, construidos, cuántos mas se puede construir y si brinda materiales o no)
        void mostrar_edificio();

        // PRE:
        // POS: devuelve un doble puntero al vector que contiene los subvectores donde estan las ubicaciones
        int** obtener_ubicaciones();

        // PRE: recibe dos coordenadas
        // POS: borra las coordenadas recibidas del arreglo de ubicaciones
        void demoler(int coordenada_x, int coordenada_y);

        // PRE:
        // POS: borra el vector de ubicaciones del edificio
        void borrar_ubicaciones();

        // PRE: recibe la nueva longitud del arreglo
        // POS: redimensiona el arreglo de ubicaciones
        void redimensionar_ubicaciones(int nueva_longitud);
};

#endif