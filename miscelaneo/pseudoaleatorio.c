#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializar la semilla para la generacion de numeros aleatorios
    srand(time(NULL));

    // Definir el rango
    int min = 10, max = 50;

    // Generar un numero aleatorio entre min y max
    int random_number = rand() % (max - min + 1) + min;

    printf("Numero aleatorio entre %d y %d: %d\n", min, max, random_number);

    return 0;
}
