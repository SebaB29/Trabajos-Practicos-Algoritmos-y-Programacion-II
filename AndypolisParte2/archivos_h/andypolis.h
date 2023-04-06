#ifndef ANDYPOLIS_H
#define ANDYPOLIS_H
#include "constantes.h"
#include "system.h"
#include "inventario.h"
#include "edificios.h"
#include "mapa.h"
#include "construcciones/aserradero.h"
#include "construcciones/fabrica.h"
#include "construcciones/mina.h"
#include "construcciones/obelisco.h"
#include "construcciones/escuela.h"
#include "construcciones/planta_electrica.h"

class Andypolis{
    private:
        Mapa mapa;
        Inventario inventario;
        Edificio** edificios_disponibles;
        int cantidad_edificios;

    public:
    
        // PRE:
        // POS: Construye un Objeto Andypolis
        Andypolis();
        
        // PRE:
        // POS: carga en un vector los edificios disponibles para construir
        void cargar_edificios_disponibles();

        //PRE:
        // POS: Guarda los nuevos edificios construidos en el archivo ubicaciones
        void guardar_edificios();

        // PRE: 
        // POS: guarda los datos actualizando ubicaciones.txt y materiales.txt
        void guardar_y_salir();
        
        // PRE:
        // POS: redimensiona el arreglo de edificios
        void redimensionar_arreglo_edificios(int nueva_longitud);

        // PRE: recibe el nombre de un edificio
        // POS: devuelve verdadero en caso que el edificio exista, false de lo contrario
        bool existe_el_edificio(std::string edificio);

        // PRE: recibe un numero de edificio, un nombre, y la cantidad de piedra, madera, metal y los permitidos
        // POS: agrega el edificio recibido al vector de edificios disponibles para construir
        void agregar_edificio_a_vector(int numero_edificio, std::string nombre, int piedra, int madera, int metal, int permitidos);

        // PRE:
        // POS: le pide al usuario las coordenadas a consultar
        void consultar_coordenada();

        // PRE:
        // POS: muestra el mapa
        void mostrar_mapa();

        // PRE: recibe el nombre de un edificio
        // POS: actualiza los materiales y le suma la mitad de los materiales requeridos para constuir el edifcio pasado por parametro
        void devolver_mitad_materiales(std::string nombre_edificio);

        // PRE:
        // POS: lee el archivo ubicaciones.txt, crea los edificios construidos y los agrega al mapa
        void cargar_construidos();

        // PRE: recibe la cantidad de piedras que tiene que llover
        // POS: llueven la cantidad de piedras recibidas por parametro
        void llueve_piedra(int cantidad);

        // PRE: recibe la cantidad de maderas que tiene que llover
        // POS: llueven la cantidad de maderas recibidas por parametro
        void llueve_madera(int cantidad);

        // PRE: recibe la cantidad de metales que tiene que llover
        // POS: llueven la cantidad de metales recibidos por parametro
        void llueve_metal(int cantidad);

        // PRE:
        // POS: muestra el inventario
        void mostrar_inventario();
        
        // PRE:
        // POS: muestra los nombres de los edificios posibles para construir
        void mostrar_nombres_de_edificios();
        
        // PRE: recibe un nombre de un edificio a construir
        // POS: devuelve verdadero en caso que haya materiales suficientes para construir el edificio recibido por parametro, falso de lo contrario
        bool hay_materiales_suficientes(std::string edificio_a_construir);
        
        // PRE: recibe el nombre del edificio a construir
        // POS: devuelve la posicion donde se encuentra el edificio recibido por parametro en el vector de edificios disponibles para construir
        int posicion_del_edifcio(std::string edificio_a_construir);
        
        // PRE: recibe el nombre del edificio a construir
        // POS: le pide al usuario confirmacion para construir el edificio
        bool confirmar_construccion(std::string edificio_a_construir);
        
        // PRE:
        // POS: devuelve un puntero a las coordenadas ingresadas
        int* pedir_coordenadas();
        
        // PRE: recibe un nombre de edificio y las coordenadas donde crearlo
        // POS: crea el edificio y devuelve un puntero a edificio
        Edificio* crear_edificio(std::string nombre_edificio, int coord_x, int coord_y);
        
        // PRE: recibe dos coordenadas
        // POS: devuelve veradero en caso que se puede construir en las coordenadas recibidas
        bool se_puede_construir(int coord_x, int coord_y);
        
        // PRE: recibe la posicion del edifcio construido en el vector de edificios
        // POS: actualiza los materiales, restandole los materiales requeridos para la construccion del edificio
        void actualizar_cant_materiales(int pos_edificio);

        // PRE: recibe la posicion del edifcio a construir en el vector de edificios
        // POS: devuelve un puntero al vector de los materiales necesarios
        int* obtener_materiales_necesarios(int pos_edificio);
        
        // PRE: recibe el nombre del edificio a construir
        // POS: devuelve verdadero en caso que se haya alcanzado la maxima cantidad de construidos posibles del edificio recibido
        bool se_alcanzo_maximo_permitido(std::string edificio_a_construir);

        // PRE: 
        // POS: muestra el menú de opciones
        void mostrar_menu();

        // PRE:
        // POS: construye el edificio
        void construir_edificio_por_nombre();

        // PRE:
        // POS: pide el nombre del edifcio
        std::string pedir_nombre_de_edificio();

        // POS:
        // PRE: devuelve un puntero a un vector que contiene las posiciones de cada material dentro del vector de materiales 
        int* obtener_posiciones_de_materiales();

        // PRE: recibe el nombre del edificio a construir
        // POS: verifica que se pueda construir el nombre del edificio recibido
        void validar_nombre_de_edificio(std::string edificio_a_construir);

        // PRE: recibe dos coordenadas
        // POS: verifica que se pueda demoler en las coordenadas recibidas
        void validar_entrada_para_demoler(int coord_x, int coord_y);

        // PRE: recibe la cantidad de edificios permitidos y un doble puntero a entero donde estan las ubicaciones
        // POS: muestra las ubicaciones donde hay edificios construidos
        void mostrar_ubicaciones(int permitidos, int** ubicaciones);

        // PRE: -
        // POS: Muetra por pantalla la lista de edificios construidos
        void listar_edificios_construidos();

        // PRE: -
        // POS: Muestra por pantalla la lista de edficios disponibles y sus características
        void listar_todos_edificios();
        
        // PRE:
        // POS: demuele un edifcio por coordenadas
        void demoler_edificio_por_coordenada();

        // PRE:
        // POS: recolecta los recursos producidos
        void recolectar_recursos_producidos();

        // PRE:
        // POS: llama a las funciones de lluvia de cada material
        void lluvia_de_recursos();

        // PRE:
        // POS: determina qué funcion debe ejecutarse
        void elegir_opcion();

        // PRE:
        // POS: libera la memoria utilizada en la clase
        ~Andypolis();
};

#endif
