/*
 * Gestión de horas de analistas por proyecto
 * Hay 10 analistas y 15 proyectos. El usuario carga las horas trabajadas
 * (analista, proyecto, horas) hasta ingresar analista = -1. Con esos datos el
 * programa calcula:
 *   1. Total de horas por analista
 *   2. Horas de cada analista en cada proyecto
 *   3. Total de horas por proyecto
 *   4. Analista que menos trabajó en el proyecto 1
 *   5. Sueldo de cada analista (horas x valor hora)
 *   6. Analista que más cobró
 *   7. Cantidad de analistas con menos de 5 horas en algún proyecto en el que trabajaron
 *   8. Listado de analistas ordenado por sueldo, de mayor a menor
 */

#include <stdio.h>
#include <string.h>

#define ANALISTAS 10
#define PROYECTOS 15

int main(void) {
    // Datos en memoria
    char nombres[ANALISTAS][30] = {"Analia", "Brian", "Carlos", "Diego", "Evelin",
                                   "Federico", "Gaston", "Hugo", "Ivan", "Julieta"};
    float valor_hora[ANALISTAS] = {500, 480, 470, 520, 510, 490, 495, 500, 505, 500};

    // Matriz de horas: filas = analistas, columnas = proyectos
    float horas_trabajadas[ANALISTAS][PROYECTOS] = {0};

    int analista, proyecto;
    float horas;
    int i, j;

    // Carga de las horas trabajadas
    printf("Ingrese las horas trabajadas por cada analista y proyecto.\n");
    printf("Para terminar ingrese analista = -1\n");

    while (1) {
        printf("\nNúmero de analista (1-%d, -1 para terminar): ", ANALISTAS);
        scanf("%d", &analista);
        if (analista == -1) {
            break;
        }

        // Validamos los datos antes de guardarlos para no salirnos de la matriz
        if (analista < 1 || analista > ANALISTAS) {
            printf("Analista inválido. Debe estar entre 1 y %d.\n", ANALISTAS);
            continue;
        }

        printf("Número de proyecto (1-%d): ", PROYECTOS);
        scanf("%d", &proyecto);
        if (proyecto < 1 || proyecto > PROYECTOS) {
            printf("Proyecto inválido. Debe estar entre 1 y %d.\n", PROYECTOS);
            continue;
        }

        printf("Cantidad de horas trabajadas: ");
        scanf("%f", &horas);
        if (horas < 0) {
            printf("Las horas no pueden ser negativas.\n");
            continue;
        }

        // Restamos 1 porque los índices empiezan en 0
        horas_trabajadas[analista - 1][proyecto - 1] += horas;
    }

    // 1) Total de horas por analista
    float total_analista[ANALISTAS] = {0};
    printf("\nTotal de horas por analista:\n");
    for (i = 0; i < ANALISTAS; i++) {
        for (j = 0; j < PROYECTOS; j++) {
            total_analista[i] += horas_trabajadas[i][j];
        }
        printf("%s: %.2f\n", nombres[i], total_analista[i]);
    }

    // 2) Horas de cada analista en cada proyecto
    printf("\nHoras por analista y proyecto:\n");
    for (i = 0; i < ANALISTAS; i++) {
        printf("%s: ", nombres[i]);
        for (j = 0; j < PROYECTOS; j++) {
            printf("%.1f ", horas_trabajadas[i][j]);
        }
        printf("\n");
    }

    // 3) Total de horas por proyecto
    float total_proyecto[PROYECTOS] = {0};
    printf("\nTotal de horas por proyecto:\n");
    for (j = 0; j < PROYECTOS; j++) {
        for (i = 0; i < ANALISTAS; i++) {
            total_proyecto[j] += horas_trabajadas[i][j];
        }
        printf("Proyecto %d: %.2f\n", j + 1, total_proyecto[j]);
    }

    // 4) Analista que menos trabajó en el proyecto 1 (en un empate, el primero)
    int pos_menos = 0;
    float menos = horas_trabajadas[0][0];
    for (i = 1; i < ANALISTAS; i++) {
        if (horas_trabajadas[i][0] < menos) {
            menos = horas_trabajadas[i][0];
            pos_menos = i;
        }
    }
    printf("\nAnalista que menos trabajó en el proyecto 1: %s (%.2f hs)\n",
           nombres[pos_menos], menos);

    // 5) Sueldo de cada analista
    float sueldo[ANALISTAS];
    printf("\nSueldo de cada analista:\n");
    for (i = 0; i < ANALISTAS; i++) {
        sueldo[i] = total_analista[i] * valor_hora[i];
        printf("%s: $%.2f\n", nombres[i], sueldo[i]);
    }

    // 6) Analista que cobró más
    int pos_mayor = 0;
    float mayor = sueldo[0];
    for (i = 1; i < ANALISTAS; i++) {
        if (sueldo[i] > mayor) {
            mayor = sueldo[i];
            pos_mayor = i;
        }
    }
    printf("\nAnalista que cobró más: %s ($%.2f)\n", nombres[pos_mayor], mayor);

    // 7) Analistas con menos de 5 horas en algún proyecto en el que trabajaron
    // (se exige > 0 para no contar los proyectos en los que no participaron)
    int cant_menos_5 = 0;
    for (i = 0; i < ANALISTAS; i++) {
        for (j = 0; j < PROYECTOS; j++) {
            if (horas_trabajadas[i][j] > 0 && horas_trabajadas[i][j] < 5) {
                cant_menos_5++;
                break;  // contamos una sola vez por analista
            }
        }
    }
    printf("Analistas con menos de 5 hs en algún proyecto: %d\n", cant_menos_5);

    // 8) Ordenamos por sueldo, de mayor a menor (burbuja).
    // Intercambiamos sueldo, nombre y valor hora a la vez para que sigan juntos.
    // Esto reordena esos arreglos, así que debe quedar al final del programa.
    for (i = 0; i < ANALISTAS - 1; i++) {
        for (j = 0; j < ANALISTAS - 1 - i; j++) {
            if (sueldo[j] < sueldo[j + 1]) {
                float aux_sueldo = sueldo[j];
                sueldo[j] = sueldo[j + 1];
                sueldo[j + 1] = aux_sueldo;

                char aux_nombre[30];
                strcpy(aux_nombre, nombres[j]);
                strcpy(nombres[j], nombres[j + 1]);
                strcpy(nombres[j + 1], aux_nombre);

                float aux_valor = valor_hora[j];
                valor_hora[j] = valor_hora[j + 1];
                valor_hora[j + 1] = aux_valor;
            }
        }
    }

    printf("\nAnalistas ordenados por sueldo (de mayor a menor):\n");
    for (i = 0; i < ANALISTAS; i++) {
        printf("%s - Valor hora: $%.2f - Sueldo: $%.2f\n", nombres[i], valor_hora[i], sueldo[i]);
    }

    return 0;
}
