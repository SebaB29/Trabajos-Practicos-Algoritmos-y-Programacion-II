# Trabajo práctico N°2 de la materia Algortimos y programacion 2 (95.14) de FIUBA.

**Integrantes**

Franco Losardo

Sebastian Brizuela --> [Github](https://github.com/SebaB29)


## Compilacion
Una vez descomprimido el zip, posicionado en el directorio AndypolisParte2, se debera correr el comando `make main` o `make`. Este comando compilara el programa con los flags correspondientes, para ejecutarlo ingresar `./Andypolis`.

En caso de querer correrlo con valgrind, podra hacerlo una vez compilado el progama como se menciono previamente y corriendo el comando `make valgrind`.

Los archivos `materiales.txt`, `ubicaciones.txt`, `edificios.txt` y `mapa.txt` tienen que ir dentro de la carpeta `archivos_de_texto` para el correcto funcionamiento del programa.

## Aclaraciones
Hemos decidido crear una sola clase de Material dado que no nos parecia razon suficiente el hecho de que cada material salude cuando es muy parecido para todos solo con una letra de diferencia.

Por otra parte, en cada hijo de la clase Edificio, implementamos un metodo para borrar las ubicaciones de dicho hijo ya que todos los objetos de un mismo tipo de edificio comparten un arreglo de subarreglos de ubicaciones. 
Por lo tanto, de haberlo hecho con el destructor de cada hijo, al destruir ese edificio se ejecuta su destructor eliminando TODAS las ubicaciones de los objetos de ese tipo de edificio. Se debera compilar en linux para el correcto funcionamiento.
