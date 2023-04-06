#ifndef MINA_H
#define MINA_H
#include "../edificios.h"
#include "../constantes.h"

class Mina: public Edificio{
    private:
        static int cantidad_construidos;
        static int** ubicaciones;

    public:
        // Constructores
        Mina(std::string nombre, int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);
        
        Mina(std::string nombre, int coord_x, int coord_y);

        // PRE:
        // POS: devuelve los materiales porducidos por el edificio
        int brindar_materiales();

        // PRE:
        // POS: muestra el saludo del edificio
        void mostrar_saludo();

        // PRE: 
        // POS: devuelve la cantidad de edificios construidos
        int obtener_construidos();

        // PRE:
        // POS: muestra las caracteristicas del edificio(materiales, construidos, cuántos mas se puede construir y si brinda materiales o no)
        void mostrar_edificio();

        // PRE:
        // POS: muestra las caracteristicas del edificio(materiales, construidos, cuántos mas se puede construir y si brinda materiales o no)
        int** obtener_ubicaciones();

        // PRE: recibe dos coordenadas
        // POS: borra las coordenadas recibidas del arreglo de ubicaciones
        void demoler(int coordenada_x, int coordenada_y);

        // PRE:
        // POS: borra las ubicaciones del edificio en cuestion
        void borrar_ubicaciones();

        // PRE: recibe la nueva longitud del arreglo
        // POS: redimensiona el arreglo de ubicaciones
        void redimensionar_ubicaciones(int nueva_longitud);
};

#endif