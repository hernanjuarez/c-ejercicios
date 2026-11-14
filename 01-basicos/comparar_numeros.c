/*
 * Comparar dos números enteros
 * Pide dos números al usuario y muestra si son iguales o distintos.
 */

#include <stdio.h>

int main() {
    int v1, v2;

    printf("Ingrese 2 números para ver si son iguales.\n\n");

    printf("Ingrese el primer número: ");
    scanf("%d", &v1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &v2);

    if (v1 == v2) {
        printf("Los números %d y %d son iguales\n", v1, v2);
    } else {
        printf("Los números %d y %d son distintos\n", v1, v2);
    }

    return 0;
}
