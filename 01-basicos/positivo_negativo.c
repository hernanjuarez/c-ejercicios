/*
 * Positivo, negativo o cero
 * Pide un número entero y muestra si es positivo, negativo o cero.
 */

#include <stdio.h>

int main() {
    int numero;

    printf("Ver si un número es positivo, negativo o cero.\n\n");

    printf("Ingrese el número: ");
    scanf("%d", &numero);

    if (numero == 0) {
        printf("El número ingresado es cero.\n");
    } else if (numero < 0) {
        printf("El número ingresado es negativo.\n");
    } else {
        printf("El número ingresado es positivo.\n");
    }

    return 0;
}
