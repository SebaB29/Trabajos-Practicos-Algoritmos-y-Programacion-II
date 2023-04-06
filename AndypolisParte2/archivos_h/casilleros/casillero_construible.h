#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "casillero.h"

class Casillero_construible: public Casillero {
    private:
        Edificio* edificio;

    public:
        // Constructor
        Casillero_construible(char tipo);

        // PRE: recibe un puntero a edifcio y a material
        // POS: ubica en el casillero el puntero a edificio
        void usar_casillero(Edificio* edificio, Material* material);

        // PRE:
        // POS: vacia el casillero
        void vaciar_casillero();

        // PRE:
        // POS: devuelve verdadero si el casillero este ocupado, falso de lo contrario
        bool esta_ocupado();

        // PRE:
        // POS: devuelve el tipo del casillero
        char obtener_tipo();

        // PRE:
        // POS: devuelve un puntero al edifcio que se encuentra en el casillero
        Edificio* obtener_edificio();

        // PRE:
        // POS: muestra por pantalla el mensaje del del casillero
        void mostrar();

        // Destructor
        ~Casillero_construible();
};

#endif