/*
 * Ganador y último de una carrera
 * Pide el número y el tiempo de cada auto hasta que se ingresa 0.
 * Al final muestra el auto ganador (menor tiempo) y el último en llegar (mayor tiempo).
 * Si hay empate de tiempos, se queda con el primer auto ingresado.
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    int auto_ganador = 0, auto_ultimo = 0, num_auto;
    float mejor_tiempo = 0, peor_tiempo = 0, tiempo;
    bool primero = true;

    printf("Ganador y último de la carrera.\n\n");

    do {
        printf("Ingrese el número del auto (0 para terminar): ");
        scanf("%d", &num_auto);

        if (num_auto != 0) {
            printf("Ingrese el tiempo del auto %d en segundos: ", num_auto);
            scanf("%f", &tiempo);

            if (tiempo <= 0) {
                printf("El tiempo debe ser mayor a 0. Se ignora este auto.\n");
            } else if (primero) {
                // El primer auto válido es, por ahora, el ganador y el último
                mejor_tiempo = tiempo;
                peor_tiempo = tiempo;
                auto_ganador = num_auto;
                auto_ultimo = num_auto;
                primero = false;
            } else {
                if (tiempo < mejor_tiempo) {
                    mejor_tiempo = tiempo;
                    auto_ganador = num_auto;
                }
                if (tiempo > peor_tiempo) {
                    peor_tiempo = tiempo;
                    auto_ultimo = num_auto;
                }
            }
        }
    } while (num_auto != 0);

    if (primero) {
        printf("\nNo se ingresó ningún auto.\n");
    } else {
        printf("\nEl auto ganador es el n.° %d\n", auto_ganador);
        printf("El tiempo del auto ganador fue: %.3f segundos.\n", mejor_tiempo);
        printf("El último auto en llegar fue el n.° %d\n", auto_ultimo);
        printf("El tiempo del último auto fue: %.3f segundos.\n", peor_tiempo);
    }

    return 0;
}
