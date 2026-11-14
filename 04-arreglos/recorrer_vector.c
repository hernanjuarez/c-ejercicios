/*
 * Recorrer un arreglo
 * Declara un arreglo de 5 enteros y muestra cada posición con su valor.
 */

#include <stdio.h>

#define TAMANO 5

int main(void) {   // void porque no recibimos ningún dato externo
    // Arreglo de enteros con valores iniciales
    int vector[TAMANO] = {10, 100, 94, 84, 11};
    int i;

    // Recorremos los índices de 0 a TAMANO - 1
    for (i = 0; i < TAMANO; i++) {
        printf("vector[%d] = %d\n", i, vector[i]);
    }

    return 0;
}
