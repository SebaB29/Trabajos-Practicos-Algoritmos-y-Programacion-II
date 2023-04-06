#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include <iostream>
#include <iomanip>

class Material {
    private:
    // Atributos

        std::string material; // Tipo de material
        int cantidad;

    public:
    // Métodos

        // PRE: -
        // POS: Construye un objeto Material
        Material();

        // PRE: Recibe el tipo de material y la cantidad del material (entero positivo)
        // POS: Construye un objeto Material
        Material(std::string material, int cantidad);

        // PRE: -
        // POS: Devuelve el tipo del material
        std::string obtener_tipo();

        // PRE: -
        // POS: Devuelve la cantidad del material
        int obtener_cantidad();

        // PRE: Recibe un entero positivo
        // POS: Le resta la cantidad recibida a la cantidad de material
        void usar_material(int cantidad_necesario);

        // PRE: Recibe un entero positivo
        // POS: Le suma la cantidad reibida a la cantidad de material
        void devolver_material(int cantidad_devuelta);

        // PRE: -
        // POS: Muestra por pantalla los atributos del material
        void mostrar_material();
};

#endif