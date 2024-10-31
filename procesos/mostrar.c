#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mostrarHijos(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        int pid = fork();
        if (pid == -1) {
            perror("Error al crear el proceso");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) { // Proceso hijo
            printf("Soy el hijo (PID: %d) de mi padre (PID: %d)\n", getpid(), getppid());
            exit(0); // Salir del hijo
        }
    }
}

void mostrarPadres(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        int pid = fork();
        if (pid == -1) {
            perror("Error al crear el proceso");
            exit(EXIT_FAILURE);
        }

        if (pid > 0) { // Proceso padre
            printf("Soy el padre (PID: %d) y he creado un hijo (PID: %d)\n", getpid(), pid);
        }
    }
}

void mostrarAmbos(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        int pid = fork();
        if (pid == -1) {
            perror("Error al crear el proceso");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) { // Proceso hijo
            printf("Soy el hijo (PID: %d) de mi padre (PID: %d)\n", getpid(), getppid());
            exit(0); // Salir del hijo
        } else { // Proceso padre
            printf("Soy el padre (PID: %d) y he creado un hijo (PID: %d)\n", getpid(), pid);
        }
    }
}

int main() {
    int cantidad = 0;
    int opcion = 0;

    printf("Ingrese la cantidad de forks (máximo 4): \n");
    scanf("%d", &cantidad);

    if (cantidad > 4) {
        printf("Por favor, ingrese un número menor o igual a 4.\n");
        return 1;
    }

    printf("Seleccione una opción:\n");
    printf("1. Mostrar solo hijos\n");
    printf("2. Mostrar solo padres\n");
    printf("3. Mostrar ambos (padres e hijos)\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            mostrarHijos(cantidad);
            break;
        case 2:
            mostrarPadres(cantidad);
            break;
        case 3:
            mostrarAmbos(cantidad);
            break;
        default:
            printf("Opción no válida.\n");
            return 1;
    }

    return 0;
}
