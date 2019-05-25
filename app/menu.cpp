#include "menu.h"

char* obtener_entrada(char** matriz, int largo) {
    char* archivo = NULL;
    int i = 0, k = 0;

    if (largo > 0) {
        for (i = 0; i < largo; i++) {
            if (strcmp("-f", matriz[i]) == 0) {
                k = i + 1;
                archivo = (char *) calloc(strlen(matriz[k]) + 1, sizeof (char));

                snprintf(archivo, strlen(matriz[k]) + 1, "%s", matriz[k]);
                break;
            }
        }
    }

    return archivo;
}

char* obtener_salida(char** matriz, int largo) {
    char* archivo = NULL;
    int i = 0, k = 0;

    if (largo > 0) {
        for (i = 0; i < largo; i++) {
            if (strcmp("-o", matriz[i]) == 0) {
                k = i + 1;
                archivo = (char *) calloc(strlen(matriz[k]) + 1, sizeof (char));

                snprintf(archivo, strlen(matriz[k]) + 1, "%s", matriz[k]);
                break;
            }
        }
    }

    return archivo;
}