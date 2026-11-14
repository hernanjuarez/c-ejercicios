/*
 * Contador de números y promedio
 * Pide números al usuario hasta que decida terminar.
 * Muestra el promedio de los positivos, el promedio de los negativos
 * y la cantidad de ceros ingresados.
 */

#include <stdio.h>

int main() {
    float num, suma_pos = 0, suma_neg = 0;
    int cont_pos = 0, cont_neg = 0, cont_cero = 0;
    char continuar;

    printf("Contador de números y promedio.\n\n");

    do {
        printf("Ingrese un número: ");
        scanf("%f", &num);

        if (num > 0) {
            cont_pos++;
            suma_pos += num;
        } else if (num < 0) {
            cont_neg++;
            suma_neg += num;
        } else {
            cont_cero++;
        }

        // El espacio antes de %c ignora el salto de línea que quedó pendiente
        printf("¿Desea ingresar otro número? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar != 'n' && continuar != 'N');

    // Resultados de los positivos
    if (cont_pos > 0) {
        printf("\nEl promedio de positivos es: %.2f\n", suma_pos / cont_pos);
    } else {
        printf("\nNo se ingresaron números positivos.\n");
    }

    // Resultados de los negativos
    if (cont_neg > 0) {
        printf("El promedio de negativos es: %.2f\n", suma_neg / cont_neg);
    } else {
        printf("No se ingresaron números negativos.\n");
    }

    // Cantidad de ceros
    printf("La cantidad de ceros es: %d\n", cont_cero);

    return 0;
}
