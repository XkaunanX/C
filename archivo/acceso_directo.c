#include <stdio.h>
#include <string.h>

typedef struct {
    char calle[30];
    char nom[20];
    int cantDia;
    int cantRev;
} REG;

int main() {
    FILE *archivo;
    REG r;
    char nombre[20], nuevaDireccion[30];
    int maxDia = 0, maxRev = 0;
    char puestoMax[20];

    // Abrir el archivo en modo de lectura/escritura binario
    archivo = fopen("diarios.dat", "r+b");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Pedir al usuario el nombre del puesto a modificar y la nueva dirección
    printf("Ingrese el nombre del puesto a modificar: ");
    scanf("%s", nombre);
    printf("Ingrese la nueva dirección: ");
    scanf("%s", nuevaDireccion);

    // Recorrer el archivo para buscar el registro y actualizarlo
    while (fread(&r, sizeof(REG), 1, archivo)) {
        if (strcmp(r.nom, nombre) == 0) {
            // Modificar la dirección
            strcpy(r.calle, nuevaDireccion);

            // Reposicionar el archivo para actualizar el registro
            fseek(archivo, -sizeof(REG), SEEK_CUR);
            fwrite(&r, sizeof(REG), 1, archivo);
            printf("Dirección actualizada correctamente.\n");
        }

        // Verificar si es el puesto con la mayor cantidad de diarios y revistas
        if (r.cantDia > maxDia && r.cantRev > maxRev) {
            maxDia = r.cantDia;
            maxRev = r.cantRev;
            strcpy(puestoMax, r.nom);
        }
    }

    // Mostrar el puesto con la mayor entrega
    printf("Puesto con mayor entrega: %s\n", puestoMax);

    // Cerrar el archivo
    fclose(archivo);

    return 0;
}