#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <iostream>

const int MATERIALES_DISPONIBLES_MINIMO = 3;
const int EDIFICIOS_DISPONIBLES_MINIMO = 4;
const int BRINDAR_MATERIALES_MINA = 15;//piedras
const int BRINDAR_MATERIALES_ASERRADERO = 25;//maderas
const int BRINDAR_MATERIALES_FABRICA = 40;//metales

const char DELIMITADOR = ' ';

const std::string RUTA_MATERIALES = "archivos_de_texto/materiales.txt";
const std::string RUTA_EDIFICIOS = "archivos_de_texto/edificios.txt";
const std::string RUTA_MAPA = "archivos_de_texto/mapa.txt";
const std::string RUTA_UBICACIONES = "archivos_de_texto/ubicaciones.txt";
const std::string LINEA_DIVISORIA = "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550";

const std::string COLOR_ROJO = "\033[38;5;196m";
const std::string COLOR_POR_DEFECTO = "\033[0m";
const std::string COLOR_VERDE = "\033[38;5;46m";
const std::string COLOR_VERDE_AGUA = "\033[38;5;35m";
const std::string COLOR_MARRON = "\033[38;5;136m";
const std::string FONDO_AZUL = "\033[48;5;27m";
const std::string FONDO_VERDE = "\033[48;5;2m";
const std::string FONDO_GRIS = "\033[48;5;240m";

const std::string LOGO_ESCUELA = "\U0001f3eb";
const std::string LOGO_FABRICA = "\U0001f3ed";
const std::string LOGO_GUARDAR = "\U0001f4be";
const std::string LOGO_DEMOLER = "\U0001f6a7";
const std::string LOGO_CONSTRUIR = "\U0001f3d7";
const std::string LOGO_LISTAR_CONSTRUIDOS = "\u2705";
const std::string LOGO_LISTAR_TODOS_EDIFICIOS = "\U0001f3d9";
const std::string LOGO_LLUVIA_RECURSOS = "\U0001f327";
const std::string LOGO_CONSULTAR_COORDENADAS = "\U0001f5fa";
const std::string LOGO_MAPA = "\U0001f30e";
const std::string LOGO_RECOLECTAR_RECURSOS = "\U0001f6e0";
const std::string LOGO_INVENTARIO = "\U0001f9f0";
#endif