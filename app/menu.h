#ifndef MENU_H
#define MENU_H

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdio>
#include <cstdlib>
#include <cstring>


    /**
     * 
     * @param matriz Argumentos a comprobar
     * @param largo cantidad de argumentos
     * @return La ruta del archivo de entrada.
     */
    char* obtener_entrada(char** matriz, int largo);

    /**
     * 
     * @param matriz Argumentos a comprobar
     * @param largo cantidad de argumento
     * @return La ruta del archivo de salida
     */
    char* obtener_salida(char** matriz, int largo);


#ifdef __cplusplus
}
#endif

#endif /* MENU_H */

