#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CONSOLA
void LimpiarConsola()
{
    system("CLS");
}

//VARIABLES
int EJECUCION;
char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//ESTRUCTURA DEL DATO

typedef struct Data
{
    int Numero;
    char Apodo;
    int Peso;
}Data;

//ESTRUCTURA DEL NODO

typedef struct Vertice
{
    Data Dato;
    struct Vertice *Sig;
    struct Arista *Adyacencia;
}Nodo;

//ESTRUCTURA DE LA ARISTA

typedef struct Arista
{
    Nodo *Vertice;
    struct Arista *Sig;
}Arista;

//ESTRUCTURA LISTA DE ADYACENCIA

typedef struct ListaAdyacencia
{
    Nodo *Inicio;
    Nodo *Final;
    int Longitud;
}ListaAdyacencia;

//FUNCIONES

Data DatoPseudoAleatorio(int i)
{
    srand(time(NULL));
    Data DatoGenerado;
    DatoGenerado.Numero = i;
    DatoGenerado.Apodo = ABC[i];
    DatoGenerado.Peso = rand()%100;
    return DatoGenerado;
}

Nodo *EncontrarVertice(char Apodo, ListaAdyacencia *PunterosLA);

//PROCEDIMIENTOS

void IniciarListaAdyacencia(ListaAdyacencia *PunterosLA);

void InsertarVertice(Data Dato, ListaAdyacencia *PunterosLA);

void ImprimirVertices(ListaAdyacencia *PunterosLA);

void DefinirArista(ListaAdyacencia *PunterosLA);

void InsertarArista(Nodo *Comienzo, Nodo *Fin, Arista *NuevaArista);

void ImprimirAdyacencias(Nodo *VerticePartida,ListaAdyacencia *PunterosLA);

void NumerarAdyacencias(Nodo *VerticeActual);

//MENUS

void MenuPrincipal(ListaAdyacencia *PunterosLA)
{
    LimpiarConsola();
    int INTERFAZ = 1, OPERACION;
    char Apodo;
    printf("          MENU OPERACIONES\n");
    printf("----------------------------------\n\n");
    printf("1. Agregar Vertice.\n");
    printf("2. Agregar Arista.\n");
    printf("3. Imprimir Vertices.\n");
    printf("4. Imprimir Adyacencia De Un Vertice.\n");
    printf("0. Volver Al Menu Principal.\n\n");
    printf("----------------------------------\n\n");
    printf("Ingrese La Operacion: ");
    scanf("%d", &OPERACION);
    INTERFAZ = 0;
    switch (OPERACION)
    {
    case 1:
        /* code */
        LimpiarConsola();
        printf("  INSERTAR VERTICE  \n\n");
        printf("--------------------\n\n");
        InsertarVertice(DatoPseudoAleatorio(PunterosLA->Longitud), PunterosLA);
        ImprimirVertices(PunterosLA);
        system("PAUSE");
        break;
    case 2:
        /* code */
        LimpiarConsola();
        printf("  INSERTAR ARISTA  \n\n");
        printf("--------------------\n\n");
        DefinirArista(PunterosLA);
        ImprimirVertices(PunterosLA);
        system("PAUSE");
        break;
    case 3:
        /* code */
        LimpiarConsola();
        printf("  IMPRIMIR VERTICES  \n\n");
        printf("---------------------\n\n");
        ImprimirVertices(PunterosLA);
        system("PAUSE");
        break;
    case 4:
        /* code */
        LimpiarConsola();
        printf("  IMPRIMIR ADYACENTES  \n\n");
        printf("-----------------------\n\n");
        printf("Ingrese Apodo Del Vertice: ");
        scanf("%c", &Apodo);
        EncontrarVertice(Apodo, PunterosLA);
        system("PAUSE");
        break;
    case 0:
        /* code */
        EJECUCION = 0;
        break;    
    default:
        INTERFAZ = 1;
        break;
    }
}

int main()
{
    EJECUCION = 1;
    ListaAdyacencia *PunterosLA;
    IniciarListaAdyacencia(PunterosLA);
    while (EJECUCION == 1)
    {
        MenuPrincipal(PunterosLA);
    }

    return 0;
}

void IniciarListaAdyacencia(ListaAdyacencia *PunterosLA)
{
    PunterosLA->Inicio = NULL;
    PunterosLA->Final = NULL;
    PunterosLA->Longitud = 0;
}

void InsertarVertice(Data Dato, ListaAdyacencia *PunterosLA)
{
    Nodo *NuevoVertice;
    NuevoVertice = malloc(sizeof(Nodo));
    NuevoVertice->Dato.Numero = Dato.Numero;
    NuevoVertice->Dato.Apodo = Dato.Apodo;
    NuevoVertice->Dato.Peso = Dato.Peso;
    NuevoVertice->Sig = NULL;
    NuevoVertice->Adyacencia = NULL;
    if (PunterosLA->Inicio == NULL)
    {
        PunterosLA->Inicio = NuevoVertice;
        PunterosLA->Final = NuevoVertice;
    }
    else
    {
        PunterosLA->Final->Sig = NuevoVertice;
        PunterosLA->Final = NuevoVertice;
    }
    PunterosLA->Longitud++;
}

void ImprimirVertices(ListaAdyacencia *PunterosLA)
{
    Nodo *NodoApuntado;
    if (PunterosLA->Inicio == NULL)
    {
        printf("\n\n--------------------\n\n");
        printf("-No Tiene Elementos-      \n");
        printf("\n\n--------------------\n\n");
    }
    else
    {
        NodoApuntado = PunterosLA->Inicio;
        printf("\n\n");
        printf("Cabeza: %p      \n", PunterosLA->Inicio);
        printf("\n\n--------------------\n\n");
        printf("          |            \n");
        while (NodoApuntado != NULL)
        {
            printf("---------------------\n");
            printf("Direccion Del Vertice %p\n\n", NodoApuntado);
            printf("    Datos:   \n");
            printf("    .Numero Del Vertice %d\n", NodoApuntado->Dato.Numero);
            printf("    .Nombre Del Vertice %c\n", NodoApuntado->Dato.Apodo);
            printf("    .Peso Del Vertice %d\n", NodoApuntado->Dato.Peso);
            printf("    .Adyacencias: ");
            NumerarAdyacencias(NodoApuntado);
            printf("El Nodo Apunta: %p\n", NodoApuntado->Sig);
            printf("      Fin Nodo\n");
            printf("---------------------\n");
            printf("          |          \n");
            NodoApuntado = NodoApuntado->Sig;
        }
        printf("\n");      
    }   
}

void DefinirArista(ListaAdyacencia *PunterosLa)
{
    char Partida, Meta;
    Nodo *Comienzo, *Fin;
    Arista *NuevaArista;
    NuevaArista = malloc(sizeof(Arista));
    NuevaArista->Sig = NULL;
    NuevaArista->Vertice = NULL;
    if (PunterosLa->Inicio == NULL)
    {
        printf("\n\n-----------------------\n\n");
        printf("-No Hay vertices-      \n");
        printf("\n\n-----------------------\n\n");
    }
    else
    {
        printf(".Ingrese El Nodo Partida: ");
        scanf(" %c", &Partida);
        printf("\nIngrese El Nodo Meta: ");
        scanf(" %c", &Meta);
        Comienzo = EncontrarVertice(Partida, PunterosLa);
        Fin = EncontrarVertice(Meta, PunterosLa);
        if (Comienzo == NULL || Fin == NULL)
        {
            printf("\nNO ENCONTRADOS\n");
            return;
        }
        else
        {
            InsertarArista(Comienzo, Fin, NuevaArista);
        }
    }
    
}

void InsertarArista(Nodo *Comienzo, Nodo *Fin, Arista *NuevaArista)
{
    Arista *AristaActual;
    if (Comienzo->Adyacencia == NULL)
    {
        Comienzo->Adyacencia = NuevaArista;
        NuevaArista->Vertice = Fin;
    }
    else
    {
        AristaActual = Comienzo->Adyacencia;
        while (AristaActual->Sig != NULL)
        {     
            AristaActual = AristaActual->Sig;
        }     
        NuevaArista->Vertice = Fin;   
        AristaActual->Sig = NuevaArista;
    }   
}

void ImprimirAdyacencias(Nodo *VerticePartida, ListaAdyacencia *PunterosLA)
{
    Arista *AristaActual;
    if (VerticePartida->Adyacencia = NULL)
    {
        printf("\n\n--------------------\n\n");
        printf("-No Tiene Adyacencias-    \n");
        printf("\n\n--------------------\n\n");
    }
    else
    {
        AristaActual = VerticePartida->Adyacencia;
        printf("----------------------\n");
        printf("Nodo Partida %c \n", VerticePartida->Dato.Apodo);
        printf("Nro %d\n", VerticePartida->Dato.Numero);
        printf("Peso: %d\n", VerticePartida->Dato.Peso);
        printf("---- ES ADYACENTE ----\n");
        printf("-----------|----------\n");
        while (AristaActual != NULL)
        {
            printf("******************\n");
            printf("Apodo %c \n", AristaActual->Vertice->Dato.Apodo);
            printf("Nro %d \n", AristaActual->Vertice->Dato.Numero);
            printf("Peso: %d \n", AristaActual->Vertice->Dato.Peso);
            printf("******************\n");
            printf("         |        \n");
            AristaActual = AristaActual->Sig;
        }
        printf("\n");
    }  
}

void NumerarAdyacencias(Nodo *VerticeActual)
{
    Arista *AristaActual;
    if (VerticeActual->Adyacencia == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        AristaActual = VerticeActual->Adyacencia;
        while (AristaActual != NULL)
        {
            printf("'%c', ", AristaActual->Vertice->Dato.Apodo);
            AristaActual = AristaActual->Sig;
        }
        printf("\n");
    }
}

Nodo *EncontrarVertice(char Apodo, ListaAdyacencia *PunterosLA)
{
    Nodo *VerticeActual;
    if (PunterosLA->Inicio == NULL)
    {
        return NULL;
    }
    else
    {
        VerticeActual = PunterosLA->Inicio;
        while (VerticeActual != NULL)
        {
            if (VerticeActual->Dato.Apodo == Apodo)
            {
                return VerticeActual;
            }
            else
            {
                VerticeActual = VerticeActual->Sig;
            }
        }       
    }
    return NULL;
}