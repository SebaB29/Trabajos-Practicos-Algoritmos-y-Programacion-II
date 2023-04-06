#include "Andypolis.h"
using namespace std;

int main() {
    Andypolis juego;
    bool salir = false;
    char continuar, tecla;
    int opcion;

    while (!salir) {
        system(CLR_SCREEN);
        continuar = ' ';
        juego.mostrar_menu();
        cout << "Elija una opción: "; cin >> tecla;
        opcion = atoi(&tecla);
        while (continuar != 'c' && continuar != 'C') {
            system(CLR_SCREEN);
            juego.leer_entrada(opcion, &salir);
            cout << "\nIngrese 'c' para continuar: "; cin >> continuar;
        }
    }
    return 0;
}