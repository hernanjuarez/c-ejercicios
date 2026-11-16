/*
 * Gestión de horas de analistas por proyecto (versión con funciones)
 * Hay 10 analistas y 15 proyectos. El usuario carga el nombre y el valor hora
 * de cada analista, y después las planillas (analista, proyecto, horas)
 * hasta ingresar analista = 0. Con esos datos el programa calcula:
 *   1. Total de horas por analista
 *   2. Total de horas por proyecto
 *   3. Analista que menos trabajó en el proyecto 1
 *   4. Analista que más cobró
 *   5. Cantidad de analistas con menos de 5 horas en algún proyecto en el que trabajaron
 *   6. Listado de analistas ordenado por sueldo, de mayor a menor
 */

#include <stdio.h>
#include <string.h>

#define ANALISTAS 10
#define PROYECTOS 15

// Pide el nombre y el valor hora de cada analista
void cargarAnalistas(char analistasNombre[][30], float valorHora[]) {
    printf("Carga de datos de analistas (nombre + valor hora)\n\n");

    for (int i = 0; i < ANALISTAS; i++) {
        printf("Nombre del analista %d: ", i + 1);
        // No lleva & porque el nombre del arreglo ya es una dirección
        scanf("%29s", analistasNombre[i]);

        printf("Valor hora del analista %d: ", i + 1);
        scanf("%f", &valorHora[i]);
    }
}

// Pide las planillas y acumula las horas hasta que el analista sea 0
void procesarPlanillas(int horasAnalista[], int horasProyecto[],
                       int horasAnaProy[][PROYECTOS]) {
    int analista, proyecto, horas;

    printf("\nCarga de planillas (analista + proyecto + horas)\n");

    while (1) {
        printf("\nNúmero de analista (1-%d, 0 para terminar): ", ANALISTAS);
        scanf("%d", &analista);
        if (analista == 0) {
            break;
        }

        // Validamos los datos antes de guardarlos para no salirnos de las tablas
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
        scanf("%d", &horas);
        if (horas < 0) {
            printf("Las horas no pueden ser negativas.\n");
            continue;
        }

        // El usuario ingresa desde 1, pero los índices empiezan en 0
        analista--;
        proyecto--;

        horasAnalista[analista] += horas;
        horasProyecto[proyecto] += horas;
        horasAnaProy[analista][proyecto] += horas;
    }
}

// Devuelve el índice del analista con menos horas en el proyecto 1
// (si hay empate, el primero)
int analistaMenosEnProyecto1(int horasAnaProy[][PROYECTOS]) {
    int min = horasAnaProy[0][0];
    int pos = 0;

    for (int i = 1; i < ANALISTAS; i++) {
        if (horasAnaProy[i][0] < min) {
            min = horasAnaProy[i][0];
            pos = i;
        }
    }

    return pos;
}

// Calcula el sueldo de cada analista: horas x valor hora
void calcularSueldos(float sueldos[], int horasAnalista[], float valorHora[]) {
    for (int i = 0; i < ANALISTAS; i++) {
        sueldos[i] = horasAnalista[i] * valorHora[i];
    }
}

// Devuelve el índice del analista con el sueldo más alto
int buscarMayorSueldo(float sueldos[]) {
    int pos = 0;

    for (int i = 1; i < ANALISTAS; i++) {
        if (sueldos[i] > sueldos[pos]) {
            pos = i;
        }
    }

    return pos;
}

// Cuenta los analistas con menos de 5 horas en algún proyecto en el que trabajaron
// (se exige > 0 para no contar los proyectos en los que no participaron)
int analistasConMenosDe5(int horasAnaProy[][PROYECTOS]) {
    int contador = 0;

    for (int i = 0; i < ANALISTAS; i++) {
        for (int j = 0; j < PROYECTOS; j++) {
            if (horasAnaProy[i][j] > 0 && horasAnaProy[i][j] < 5) {
                contador++;
                break;  // se cuenta una sola vez por analista
            }
        }
    }

    return contador;
}

// Ordena por sueldo de mayor a menor, intercambiando sueldo, valor hora y nombre
// a la vez para que sigan juntos. Reordena estos tres arreglos, así que
// debe usarse al final del programa.
void ordenarPorSueldo(char nombres[][30], float valorHora[], float sueldos[]) {
    for (int i = 0; i < ANALISTAS - 1; i++) {
        for (int j = i + 1; j < ANALISTAS; j++) {
            if (sueldos[i] < sueldos[j]) {
                float auxS = sueldos[i];
                sueldos[i] = sueldos[j];
                sueldos[j] = auxS;

                float auxV = valorHora[i];
                valorHora[i] = valorHora[j];
                valorHora[j] = auxV;

                char auxN[30];
                strcpy(auxN, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxN);
            }
        }
    }
}

int main(void) {
    char nombres[ANALISTAS][30];
    float valorHora[ANALISTAS];

    int horasAnalista[ANALISTAS] = {0};
    int horasProyecto[PROYECTOS] = {0};
    int horasAnaProy[ANALISTAS][PROYECTOS] = {0};

    float sueldos[ANALISTAS];

    cargarAnalistas(nombres, valorHora);
    procesarPlanillas(horasAnalista, horasProyecto, horasAnaProy);
    calcularSueldos(sueldos, horasAnalista, valorHora);

    // 1) Horas totales por analista
    printf("\nHoras totales por analista:\n");
    for (int i = 0; i < ANALISTAS; i++) {
        printf("%s: %d hs\n", nombres[i], horasAnalista[i]);
    }

    // 2) Horas totales por proyecto
    printf("\nHoras totales por proyecto:\n");
    for (int j = 0; j < PROYECTOS; j++) {
        printf("Proyecto %d: %d hs\n", j + 1, horasProyecto[j]);
    }

    // 3) Analista que menos trabajó en el proyecto 1
    int posMenos = analistaMenosEnProyecto1(horasAnaProy);
    printf("\nAnalista que menos trabajó en el proyecto 1: %s\n", nombres[posMenos]);

    // 4) Analista que más cobró
    int posMayor = buscarMayorSueldo(sueldos);
    printf("Analista que más cobró: %s con $%.2f\n", nombres[posMayor], sueldos[posMayor]);

    // 5) Analistas con pocas horas en algún proyecto
    printf("Analistas con menos de 5 hs en algún proyecto: %d\n",
           analistasConMenosDe5(horasAnaProy));

    // 6) Ranking por sueldo (debe ir al final: reordena los arreglos)
    ordenarPorSueldo(nombres, valorHora, sueldos);

    printf("\nAnalistas ordenados por sueldo (de mayor a menor):\n");
    for (int i = 0; i < ANALISTAS; i++) {
        printf("%s - $%.2f/hora - Sueldo: $%.2f\n", nombres[i], valorHora[i], sueldos[i]);
    }

    return 0;
}
