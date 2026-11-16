/*
 * Resta del mayor menos el menor
 * Pide dos enteros y resta el menor al mayor, de modo que el resultado sea siempre positivo.
 */

#include <stdio.h>

int main() {
    int num1, num2, resultado;

    printf("Resta de mayor menos menor.\n\n");

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    if (num1 > num2) {
        resultado = num1 - num2;
        printf("%d es más grande que %d.\n", num1, num2);
        printf("Si le restamos %d a %d, el resultado es %d\n", num2, num1, resultado);
    } else if (num1 < num2) {
        resultado = num2 - num1;
        printf("%d es más grande que %d.\n", num2, num1);
        printf("Si le restamos %d a %d, el resultado es %d\n", num1, num2, resultado);
    } else {
        printf("%d y %d son iguales, su resta es 0\n", num1, num2);
    }

    return 0;
}
