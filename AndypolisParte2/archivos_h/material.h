#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>

class Material{
    private:
        // Atributos
        std::string tipo_material;
        int cantidad;

    public:
        Material();
        Material(std::string tipo_material, int cantidad);
        // Métodos
        
        // PRE: Recibe un entero
        // POS: Le suma cantidad al material en cuestion
        void establecer_cantidad(int cantidad);

        // PRE: -
        // POS: Devuelve el tipo del material
        std::string obtener_tipo();

        // PRE: -
        // POS: Devuelve la cantidad del material
        int obtener_cantidad();

        // PRE: Recibe un entero positivo
        // POS: Le resta la cantidad recibida a la cantidad de material
        void usar_material(int cantidad_necesaria);

        // PRE: -
        // POS: Muestra por pantalla los atributos del material
        void mostrar_material();

        // PRE:
        // POS: muestra por pantalla el saludo del material
        void saludar();

        // PRE:
        // POS: devuelve la representacion del material
        char obtener_representacion();
};

#endif
