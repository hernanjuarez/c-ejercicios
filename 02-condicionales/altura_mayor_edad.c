/*
 * Altura de la persona de mayor edad
 * Pide la edad y la altura de dos personas y muestra la altura de la de mayor edad.
 */

#include <stdio.h>

int main() {
    int edad1, edad2, altura1, altura2;

    printf("Altura de la persona de mayor edad.\n\n");

    // Datos de la primera persona
    printf("Datos de la primera persona.\n");
    printf("Ingrese la edad: ");
    scanf("%d", &edad1);
    printf("Ingrese la altura en cm: ");
    scanf("%d", &altura1);

    // Datos de la segunda persona
    printf("\nDatos de la segunda persona.\n");
    printf("Ingrese la edad: ");
    scanf("%d", &edad2);
    printf("Ingrese la altura en cm: ");
    scanf("%d", &altura2);

    // Comparamos las edades
    if (edad1 > edad2) {
        printf("\nLa altura de la persona de mayor edad es de %d cm\n", altura1);
    } else if (edad1 < edad2) {
        printf("\nLa altura de la persona de mayor edad es de %d cm\n", altura2);
    } else {
        printf("\nAmbas personas tienen la misma edad: %d años\n", edad1);
        printf("Sus alturas son %d cm y %d cm\n", altura1, altura2);
    }

    return 0;
}
