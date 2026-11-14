/*
 * Comparar dos números y calcular su producto
 * Pide dos enteros, muestra su producto y dice cuál es mayor, menor o si son iguales.
 */

#include <stdio.h>

int main() {
    int num1, num2, producto;

    printf("Comparar dos números y calcular su producto.\n\n");

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    producto = num1 * num2;
    printf("%d multiplicado por %d es %d\n", num1, num2, producto);

    if (num1 < num2) {
        printf("%d es menor que %d\n", num1, num2);
    } else if (num1 > num2) {
        printf("%d es mayor que %d\n", num1, num2);
    } else {
        printf("Los números son iguales\n");
    }

    return 0;
}
