#include <stdio.h>

// Calcular el factorial de un numero usando recursion
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n = 5;
    printf("El factorial de %d es %d\n", n, factorial(n));
    return 0;
}
