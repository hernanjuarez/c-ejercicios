/*
 * Suma y promedio de sueldos
 * Pide la cantidad de sueldos a cargar, los lee uno por uno
 * y muestra la suma y el promedio.
 */

#include <stdio.h>

int main() {
    int cantidad, i;
    float sueldo, suma = 0, promedio;

    printf("Suma y promedio de sueldos.\n\n");

    printf("Ingrese la cantidad de sueldos a cargar: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0) {
        printf("La cantidad debe ser mayor a 0.\n");
        return 0;
    }

    // Lectura de los sueldos
    for (i = 1; i <= cantidad; i++) {
        printf("Ingrese el sueldo %d: ", i);
        scanf("%f", &sueldo);

        if (sueldo < 0) {
            printf("El sueldo no puede ser negativo. Se toma como 0.\n");
            sueldo = 0;
        }

        suma += sueldo;
    }

    // Cálculo del promedio
    promedio = suma / cantidad;

    // Resultados
    printf("\nLa suma de los sueldos es: %.2f\n", suma);
    printf("El promedio de los sueldos es: %.2f\n", promedio);

    return 0;
}
