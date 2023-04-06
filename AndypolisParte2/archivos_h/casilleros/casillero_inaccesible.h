#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H

#include "casillero.h"

class Casillero_inaccesible: public Casillero {
    public:
        // Constructor
        Casillero_inaccesible(char tipo);

        // PRE:
        // POS: devuelve el tipo del casillero
        char obtener_tipo();

        // PRE:
        // POS: muestra por pantalla el mensaje del del casillero
        void mostrar();
};

#endif