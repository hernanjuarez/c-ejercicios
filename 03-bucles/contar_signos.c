/*
 * Cantidad de positivos, negativos y ceros
 * Pide 10 números enteros y cuenta cuántos son positivos,
 * cuántos negativos y cuántos son cero.
 */

#include <stdio.h>

#define CANTIDAD 10

int main(void) {
    int num, cant_negativos = 0, cant_positivos = 0, cant_ceros = 0;
    int i;

    printf("Cantidad de positivos, negativos y ceros.\n\n");

    for (i = 1; i <= CANTIDAD; i++) {
        printf("Ingrese el número %d: ", i);
        scanf("%d", &num);

        // Clasificamos cada número y sumamos al contador que corresponde
        if (num < 0) {
            cant_negativos++;
        } else if (num > 0) {
            cant_positivos++;
        } else {
            cant_ceros++;
        }
    }

    printf("\nLa cantidad de positivos es: %d\n", cant_positivos);
    printf("La cantidad de negativos es: %d\n", cant_negativos);
    printf("La cantidad de ceros es: %d\n", cant_ceros);

    return 0;
}
