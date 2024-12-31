#include <stdio.h>

extern int x;  // Declaracion de la variable global definida en otro archivo
extern void mostrar();  // Declaracion de la funcion mostrar

int main() {
    printf("Valor de x desde main: %d\n", x);  // Acceso a la variable global
    mostrar();  // Llamada a la funcion definida en variable.c
    return 0;
}
