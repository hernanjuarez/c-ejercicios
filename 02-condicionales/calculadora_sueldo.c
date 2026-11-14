/*
 * Calculadora de sueldo según la categoría
 * Pide las horas trabajadas y la categoría (1, 2 o 3) de un empleado
 * y calcula su sueldo según el valor de la hora de cada categoría.
 */

#include <stdio.h>
#include <stdbool.h>

// Valor de la hora para cada categoría
#define VALOR_HORA_CAT1 50
#define VALOR_HORA_CAT2 70
#define VALOR_HORA_CAT3 80

int main() {
    int categoria;
    float horas, sueldo, valor_hora = 0;
    bool valido = true;

    printf("Calculadora de sueldo según la categoría.\n\n");

    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%f", &horas);

    printf("Ingrese la categoría (1, 2 o 3): ");
    scanf("%d", &categoria);

    // Validamos las horas y asignamos el valor de la hora según la categoría
    if (horas < 0) {
        printf("Las horas trabajadas no pueden ser negativas.\n");
        valido = false;
    } else {
        switch (categoria) {
            case 1:
                valor_hora = VALOR_HORA_CAT1;
                break;
            case 2:
                valor_hora = VALOR_HORA_CAT2;
                break;
            case 3:
                valor_hora = VALOR_HORA_CAT3;
                break;
            default:
                printf("La categoría ingresada es incorrecta.\n");
                valido = false;
        }
    }

    // Calculamos el sueldo solo si los datos son válidos
    if (valido) {
        sueldo = valor_hora * horas;
        printf("El sueldo del empleado de la categoría %d es de: $%.2f\n", categoria, sueldo);
    }

    return 0;
}
