#include <stdio.h>
#include <string.h>

typedef struct {
    int prod1;
    int stockAc;
    float precio;
} MAES;

typedef struct {
    int prod2;
    int cantVen;
} DET;

int main() {
    FILE *stock, *ventas, *stockNuevo;
    MAES ma, sa;
    DET deta;
    char sigue;

    // Abrir los archivos
    stock = fopen("kiosco.dat", "rb");
    ventas = fopen("movimientos.dat", "rb");
    stockNuevo = fopen("salida.dat", "wb");

    if (stock == NULL || ventas == NULL || stockNuevo == NULL) {
        printf("Error al abrir los archivos.\n");
        return 1;
    }

    // Leer el archivo de stock
    while (fread(&ma, sizeof(MAES), 1, stock)) {
        sigue = 'S';
        rewind(ventas); // Volver al inicio del archivo de ventas

        // Leer el archivo de ventas
        while (fread(&deta, sizeof(DET), 1, ventas) && sigue == 'S') {
            if (ma.prod1 == deta.prod2) {
                // Actualizar el registro de stock
                sa.prod1 = ma.prod1;
                sa.stockAc = ma.stockAc - deta.cantVen;
                sa.precio = ma.precio;
                fwrite(&sa, sizeof(MAES), 1, stockNuevo);
                sigue = 'N';
            }
        }

        // Si no se encontró venta, grabar el registro sin modificar
        if (sigue == 'S') {
            fwrite(&ma, sizeof(MAES), 1, stockNuevo);
        }
    }

    // Cerrar los archivos
    fclose(stock);
    fclose(ventas);
    fclose(stockNuevo);

    printf("Archivo actualizado y guardado en 'salida.dat'.\n");

    return 0;
}