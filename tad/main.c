#include <stdio.h>
#include "lista.h"

int main() {
    Lista miLista;
    crearLista(&miLista);

    insertarInicio(&miLista, 10);
    insertarInicio(&miLista, 20);
    insertarFinal(&miLista, 30);

    mostrarLista(&miLista);

    Nodo *encontrado = buscar(&miLista, 20);
    if (encontrado != NULL) {
        printf("Elemento %d encontrado.\n", encontrado->dato);
    } else {
        printf("Elemento no encontrado.\n");
    }

    eliminar(&miLista, 20);
    mostrarLista(&miLista);

    destruirLista(&miLista);
    mostrarLista(&miLista);

    return 0;
}