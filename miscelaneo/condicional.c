#include <stdio.h>

int main() {
    int numero = -5;
    const char* resultado;

    // Usamos el operador condicional para verificar si el numero es positivo o negativo
    resultado = (numero >= 0) ? "Positivo" : "Negativo";

    printf("El numero es: %s\n", resultado);

    return 0;
}
