/*
 * Menú de ordenamientos con funciones
 * Pide 20 números enteros y muestra un menú para ordenarlos de menor a mayor
 * con burbuja o con QuickSort, o para mostrar el vector.
 * Cada tarea (cargar, mostrar, ordenar) está en su propia función.
 * Nota: ambos ordenamientos trabajan sobre el mismo vector.
 */

#include <stdio.h>

#define TAMANO 20

// Ordena el vector de menor a mayor con el método de burbuja
void burbujeo(int vector[], int n) {
    int i, j, aux;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}

// Ordena el vector de menor a mayor con QuickSort (recursivo)
// Elige un pivote en el medio y deja a su izquierda los menores y a su derecha los mayores
void quickSort(int vector[], int inicio, int fin) {
    int i = inicio;
    int j = fin;
    int pivote = vector[(inicio + fin) / 2];
    int aux;

    while (i <= j) {
        while (vector[i] < pivote) {
            i++;
        }
        while (vector[j] > pivote) {
            j--;
        }

        if (i <= j) {
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i++;
            j--;
        }
    }

    // Ordenamos las dos mitades por separado
    if (inicio < j) {
        quickSort(vector, inicio, j);
    }
    if (i < fin) {
        quickSort(vector, i, fin);
    }
}

// Pide al usuario los valores del vector
void cargarVector(int vector[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Ingrese valor %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
}

// Muestra cada posición del vector con su valor
void mostrarVector(int vector[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Pos %d = %d\n", i + 1, vector[i]);
    }
}

int main(void) {
    int vector[TAMANO];
    int opcion;

    printf("Ingrese %d números enteros:\n", TAMANO);
    cargarVector(vector, TAMANO);

    do {
        printf("\n======== MENÚ ========\n");
        printf("1 - Ordenar con burbuja\n");
        printf("2 - Ordenar con QuickSort\n");
        printf("3 - Mostrar vector\n");
        printf("0 - Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                burbujeo(vector, TAMANO);
                printf("\nVector ordenado con burbuja.\n");
                break;
            case 2:
                quickSort(vector, 0, TAMANO - 1);
                printf("\nVector ordenado con QuickSort.\n");
                break;
            case 3:
                mostrarVector(vector, TAMANO);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 0);

    return 0;
}
