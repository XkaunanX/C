#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    printf("Valor en la posicion 0: %d\n", *ptr);  // 1
    ptr++;  // Incrementa, ahora apunta a la posicion 1
    printf("Valor en la posicion 1: %d\n", *ptr);  // 2

    ptr += 2;  // Avanza 2 posiciones, ahora apunta a la posicion 3
    printf("Valor en la posicion 3: %d\n", *ptr);  // 4

    ptr--;  // Decrementa, ahora apunta a la posicion 2
    printf("Valor en la posicion 2: %d\n", *ptr);  // 3

    return 0;
}
