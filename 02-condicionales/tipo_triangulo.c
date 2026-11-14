/*
 * Tipo de triángulo
 * Pide los tres lados de un triángulo y muestra si es equilátero, isósceles o escaleno.
 * Antes de clasificarlo, comprueba que los lados realmente formen un triángulo.
 */

#include <stdio.h>

int main() {
    float lado1, lado2, lado3;

    printf("Tipo de triángulo.\n\n");
    printf("Ingrese a continuación los 3 lados de su triángulo en cm.\n\n");

    printf("Lado 1 en cm: ");
    scanf("%f", &lado1);

    printf("Lado 2 en cm: ");
    scanf("%f", &lado2);

    printf("Lado 3 en cm: ");
    scanf("%f", &lado3);

    // Un triángulo existe si cada lado es menor que la suma de los otros dos
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {

        if (lado1 == lado2 && lado2 == lado3) {
            printf("Su triángulo es equilátero.\n");
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            printf("Su triángulo es isósceles.\n");
        } else {
            printf("Su triángulo es escaleno.\n");
        }

    } else {
        printf("Los lados ingresados no forman un triángulo.\n");
    }

    return 0;
}
