/*
 * Mostrar un vector en orden inverso
 * Pide 10 números enteros, los guarda en un arreglo y los muestra
 * recorriéndolo desde la última posición hasta la primera.
 */

#include <stdio.h>

#define TAMANO 10

int main(void) {
    int vector[TAMANO];
    int i;

    printf("Ingrese %d números enteros.\n\n", TAMANO);

    // Carga de los valores
    for (i = 0; i < TAMANO; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    // Recorremos el arreglo desde el último índice hasta el 0
    printf("\nLos valores en orden inverso son:\n");
    for (i = TAMANO - 1; i >= 0; i--) {
        printf("vector[%d] = %d\n", i, vector[i]);
    }

    return 0;
}
