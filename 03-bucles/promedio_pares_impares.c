/*
 * Promedios de números y cantidad de mayores a 15
 * Pide 8 números enteros y calcula:
 *   - el promedio de todos los números
 *   - el promedio de los pares
 *   - el promedio de los impares
 *   - cuántos números son mayores a 15
 * El 0 se considera par.
 */

#include <stdio.h>

#define CANTIDAD 8

int main(void) {
    int num, i;
    int cant_pares = 0, cant_impares = 0, cant_mayores_15 = 0;
    float suma_total = 0, suma_pares = 0, suma_impares = 0;

    printf("Promedios de %d números (total, pares e impares).\n\n", CANTIDAD);

    for (i = 1; i <= CANTIDAD; i++) {
        printf("Ingrese el número %d: ", i);
        scanf("%d", &num);

        suma_total += num;

        // Contamos los mayores a 15
        if (num > 15) {
            cant_mayores_15++;
        }

        // Separamos pares e impares (también funciona con negativos)
        if (num % 2 == 0) {
            suma_pares += num;
            cant_pares++;
        } else {
            suma_impares += num;
            cant_impares++;
        }
    }

    // Resultados
    printf("\nPromedio total de los %d números: %.2f\n", CANTIDAD, suma_total / CANTIDAD);

    if (cant_pares > 0) {
        printf("Promedio de los números pares: %.2f\n", suma_pares / cant_pares);
    } else {
        printf("No se ingresaron números pares.\n");
    }

    if (cant_impares > 0) {
        printf("Promedio de los números impares: %.2f\n", suma_impares / cant_impares);
    } else {
        printf("No se ingresaron números impares.\n");
    }

    printf("Cantidad de números mayores a 15: %d\n", cant_mayores_15);

    return 0;
}
