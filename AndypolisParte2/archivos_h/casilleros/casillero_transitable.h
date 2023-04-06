#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO_TRANSITABLE_H

#include "casillero.h"

class Casillero_transitable: public Casillero {
    private:
        Material* material;

    public:
        // Construcor
        Casillero_transitable(char tipo);

        // PRE: recibe un puntero a edifcio y a material
        // POS: ubica en el casillero el puntero a material
        void usar_casillero(Edificio* edificio, Material* material);

        // PRE:
        // POS: vacia el casillero
        void vaciar_casillero();

        // PRE:
        // POS: devuelve verdadero en caso que el casillero este ocupado, falso de lo contrario
        bool esta_ocupado();

        // PRE:
        // POS: devuelve el tipo del casillero
        char obtener_tipo();

        // PRE:
        // POS: devuelve un puntero al material que se encuentra en el casillero
        Material* obtener_material();

        // PRE:
        // POS: muestra por pantalla el mensaje del del casillero
        void mostrar();

        // Destructor
        ~Casillero_transitable();
};

#endif