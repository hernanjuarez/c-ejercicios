/*
 * Búsqueda secuencial y búsqueda binaria
 * Pide 10 números enteros, permite elegir el tipo de búsqueda
 * y muestra en qué posición se encuentra el valor buscado.
 * La búsqueda binaria necesita el vector ordenado, por eso se ordena antes con burbuja.
 */

#include <stdio.h>

#define TAMANO 10

int main(void) {
    int vector[TAMANO];
    int i, j, aux;
    int opcion, buscado;
    int encontrado = -1;
    int inicio = 0;
    int fin = TAMANO - 1;
    int medio;

    printf("Ingrese %d valores.\n", TAMANO);

    // Carga de los valores
    for (i = 0; i < TAMANO; i++) {
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    // Menú de opciones
    printf("\nElija el tipo de búsqueda:\n");
    printf("1 - Búsqueda secuencial\n");
    printf("2 - Búsqueda binaria\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    if (opcion != 1 && opcion != 2) {
        printf("\nOpción inválida.\n");
        return 0;
    }

    printf("\nIngrese el número a buscar: ");
    scanf("%d", &buscado);

    if (opcion == 1) {
        // Búsqueda secuencial: recorre el vector hasta encontrar el valor
        for (i = 0; i < TAMANO; i++) {
            if (vector[i] == buscado) {
                encontrado = i;
                break;
            }
        }
    } else {
        // Búsqueda binaria: primero ordenamos el vector con burbuja
        for (i = 0; i < TAMANO - 1; i++) {
            for (j = 0; j < TAMANO - 1 - i; j++) {
                if (vector[j] > vector[j + 1]) {
                    aux = vector[j];
                    vector[j] = vector[j + 1];
                    vector[j + 1] = aux;
                }
            }
        }

        printf("\nVector ordenado: ");
        for (i = 0; i < TAMANO; i++) {
            printf("%d ", vector[i]);
        }
        printf("\n");

        // Vamos descartando la mitad del vector en cada paso
        while (inicio <= fin) {
            medio = (inicio + fin) / 2;

            if (vector[medio] == buscado) {
                encontrado = medio;
                break;
            } else if (buscado < vector[medio]) {
                fin = medio - 1;      // seguimos en la mitad izquierda
            } else {
                inicio = medio + 1;   // seguimos en la mitad derecha
            }
        }
    }

    // Resultado
    if (encontrado != -1) {
        printf("\nNúmero encontrado en la posición %d", encontrado);
        if (opcion == 2) {
            printf(" del vector ordenado");
        }
        printf(".\n");
    } else {
        printf("\nNúmero NO encontrado.\n");
    }

    return 0;
}
