/*
 * Promedio de 25 números
 * Pide 25 números por teclado, los suma con un bucle for
 * y muestra su promedio.
 */

#include <stdio.h>

#define CANTIDAD 25

int main(void) {
    float num, suma = 0, promedio;
    int i;

    printf("Promedio de %d números.\n\n", CANTIDAD);

    // Pedimos los números y los vamos acumulando
    for (i = 1; i <= CANTIDAD; i++) {
        printf("Ingrese el número %d: ", i);
        scanf("%f", &num);
        suma += num;
    }

    promedio = suma / CANTIDAD;
    printf("\nEl promedio de los %d números es: %.2f\n", CANTIDAD, promedio);

    return 0;
}
