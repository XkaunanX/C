#ifndef LISTA_H
#define LISTA_H

// Definimos el tipo de dato que almacenará la lista (en este caso, int)
typedef int TipoElemento;

// Estructura del nodo
typedef struct Nodo {
    TipoElemento dato;
    struct Nodo *siguiente;
} Nodo;

// Estructura de la lista
typedef struct {
    Nodo *cabeza;
} Lista;

// Funciones del TAD Lista
void crearLista(Lista *lista);
void insertarInicio(Lista *lista, TipoElemento dato);
void insertarFinal(Lista *lista, TipoElemento dato);
void eliminar(Lista *lista, TipoElemento dato);
Nodo* buscar(Lista *lista, TipoElemento dato);
void mostrarLista(Lista *lista);
void destruirLista(Lista *lista);

#endif