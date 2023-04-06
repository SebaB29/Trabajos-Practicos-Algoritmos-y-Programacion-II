#ifndef CASILLERO_H
#define CASILLERO_H

#include "../material.h"
#include "../edificios.h"

class Casillero{
    protected:
        char tipo;

    public:
        // Constructor
        Casillero();

        // PRE: recibe un puntero a edificio y uno a material
        // POS: ocupa el casillero con el objeto que corresponda
        virtual void usar_casillero(Edificio* edificio, Material* material);

        // PRE:
        // POS: vacia el casillero
        virtual void vaciar_casillero();

        // PRE:
        // POS: devuelve verdadero si el casillero esta ocupado, falso de lo contrario
        virtual bool esta_ocupado();

        // PRE:
        // POS: muestra el mensaje del casillero
        virtual void mostrar() = 0;

        // PRE:
        // POS: devuelve el tipo del casillero
        virtual char obtener_tipo() = 0;

        // PRE:
        // POS: devuelve un puntero al edificio que se encuentra en el casillero
        virtual Edificio* obtener_edificio();

        // PRE:
        // POS: devuelve un puntero al material que se encuentra en el casillero
        virtual Material* obtener_material();

        // Destructor
        virtual ~Casillero();
};

#endif