/*
 * Contador de facturas
 * Pide el número y el importe de cada factura hasta que se ingresa 0.
 * Al final muestra el importe total y cuántas facturas hay en cada tramo:
 *   - de $1.000 a menos de $10.000
 *   - de $10.000 o más
 *   - de $400 a $600 (ambos incluidos)
 */

#include <stdio.h>

int main() {
    int cont_400_600 = 0, cont_diez_mil = 0, cont_mil = 0, num_factura;
    float importe_total = 0, importe;

    printf("Contador de facturas.\n\n");

    do {
        printf("Ingrese el número de la factura (0 para terminar): ");
        scanf("%d", &num_factura);

        if (num_factura != 0) {
            printf("Ingrese el importe de la factura n.° %d en pesos: ", num_factura);
            scanf("%f", &importe);

            if (importe <= 0) {
                printf("El importe debe ser mayor a 0. Se ignora esta factura.\n");
            } else {
                importe_total = importe_total + importe;

                if (importe >= 1000 && importe < 10000) {
                    cont_mil++;
                }
                if (importe >= 10000) {
                    cont_diez_mil++;
                }
                if (importe >= 400 && importe <= 600) {
                    cont_400_600++;
                }
            }
        }
    } while (num_factura != 0);

    printf("\nImporte total de las facturas: $%.2f\n", importe_total);
    printf("Facturas de $1.000 a menos de $10.000: %d\n", cont_mil);
    printf("Facturas de $10.000 o más: %d\n", cont_diez_mil);
    printf("Facturas entre $400 y $600: %d\n", cont_400_600);

    return 0;
}
