#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "constantes.h"
#include "material.h"

class Inventario {
    private:
        int cantidad_materiales;
        Material* inventario;
    
    public:
        // Constructor
        Inventario();

        // PRE:
        // POS: devuelve la cantidad de materiales
        int obtener_cantidad_materiales();

        // PRE:
        // POS: devuelve un puntero al inventario
        Material* obtener_inventario();

        // PRE: recibe el nombre del material
        // POS: devuelve la posicion del material recibido
        int posicion_del_material(std::string material);

        // PRE: recibe un entero
        // POS: redimensiona el vector de materiales con la longitud recibida por parametro
        void redimensionar_inventario(int nueva_longitud);

        // PRE:
        // POS: muestra el inventario
        void mostrar_inventario();

        // PRE:
        // POS: carga el inventario
        void cargar_inventario();

        // PRE:
        // POS: guarda en materiales.txt los valores de los materiales actualizado al finalizar el programa
        void guardar_inventario();

        // Destructor
        ~Inventario();
};

#endif