#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void crearHijosLineales(int cantidad, int nivel) {
    if (nivel >= cantidad) return;

    int pid = fork();
    if (pid == -1) {
        perror("Error al crear el proceso");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Proceso hijo
        printf("Soy el hijo (PID: %d), creado por mi padre (PID: %d)\n", getpid(), getppid());
        crearHijosLineales(cantidad, nivel + 1); // El hijo crea otro hijo
        exit(0); // Salir del hijo
    } else { // Proceso padre
        printf("Soy el padre (PID: %d) y he creado un hijo (PID: %d)\n", getpid(), pid);
        // El padre no crea más procesos aquí
    }
}

int main() {
    int cantidad = 0;

    printf("Ingrese la cantidad de hijos a crear (máximo 4): \n");
    scanf("%d", &cantidad);

    if (cantidad > 4) {
        printf("Por favor, ingrese un número menor o igual a 4.\n");
        return 1;
    }

    printf("Soy el padre (PID: %d)\n", getpid());
    crearHijosLineales(cantidad, 0); // Iniciar la creación de hijos en forma lineal

    return 0;
}