#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Crear una lista vacía
void crearLista(Lista *lista) {
    lista->cabeza = NULL;
}

// Insertar un elemento al inicio de la lista
void insertarInicio(Lista *lista, TipoElemento dato) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    nuevo->dato = dato;
    nuevo->siguiente = lista->cabeza;
    lista->cabeza = nuevo;
}

// Insertar un elemento al final de la lista
void insertarFinal(Lista *lista, TipoElemento dato) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    if (lista->cabeza == NULL) {
        lista->cabeza = nuevo;
    } else {
        Nodo *actual = lista->cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

// Eliminar un elemento por valor
void eliminar(Lista *lista, TipoElemento dato) {
    Nodo *actual = lista->cabeza;
    Nodo *anterior = NULL;

    while (actual != NULL && actual->dato != dato) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Elemento no encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        lista->cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    printf("Elemento %d eliminado.\n", dato);
}

// Buscar un elemento en la lista
Nodo* buscar(Lista *lista, TipoElemento dato) {
    Nodo *actual = lista->cabeza;
    while (actual != NULL) {
        if (actual->dato == dato) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

// Mostrar los elementos de la lista
void mostrarLista(Lista *lista) {
    Nodo *actual = lista->cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Destruir la lista y liberar memoria
void destruirLista(Lista *lista) {
    Nodo *actual = lista->cabeza;
    Nodo *temp;
    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    lista->cabeza = NULL;
}