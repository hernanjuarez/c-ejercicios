/*
 * Ordenamiento de burbuja
 * Pide 20 números enteros, los guarda en un arreglo y los ordena
 * de menor a mayor con el método de burbuja.
 */

#include <stdio.h>

#define TAMANO 20

int main(void) {
    int vector[TAMANO];
    int i, j, aux;

    printf("Ingrese %d valores.\n", TAMANO);

    // Carga de los valores
    for (i = 0; i < TAMANO; i++) {
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    // Ordenamiento de burbuja: en cada pasada, el mayor valor "sube" hasta el final
    for (i = 0; i < TAMANO - 1; i++) {
        for (j = 0; j < TAMANO - 1 - i; j++) {
            // Si el valor actual es mayor que el siguiente, los intercambiamos
            if (vector[j] > vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }

    // Mostramos el vector ordenado
    printf("\nVector ordenado de menor a mayor:\n");
    for (i = 0; i < TAMANO; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}
