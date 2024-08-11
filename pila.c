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

//ESTRUCTURA DEL DATO

typedef struct Data{
    int Id;
    int Valor;
    int Estado;
}Data;

//ESTRUCTURA DEL NODO

typedef struct Elemento
{
    Data Dato;
    struct Elemento *Sig;
}Nodo;

typedef struct Pila
{
    Nodo *Cabeza;
    int Longitud;
}Pila;

//FUNCIONES

Data DatoAleatorio(){//GENERA UN DATO CON VALORES ALEATORIOS
    srand(time(NULL));
    Data DatoGenerado;
    DatoGenerado.Id = rand()%100;
    DatoGenerado.Valor = rand()%1000;
    DatoGenerado.Estado = rand()%2;
    return DatoGenerado;
}

Data Pop(Pila *PunterosPila);

int IsEmpty(Pila *PunterosPila)
{
    if(PunterosPila->Cabeza == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//PROCEDIMIENTOS

void IniciarPila(Pila *PunterosPila);

void Push(Data Dato, Pila *PunterosPila);

void Top(Pila *PunterosPila);

void ImprimirPila(Pila *PunterosPila);//IMPRIME LA LISTA

//MENUS

void MenuPrincipal(Pila *PunterosPila)
{
    int INTERFAZ = 1, OPERACION;
    Data Dato;
    while (INTERFAZ == 1)
    {
        LimpiarConsola();
        printf("        MENU        \n\n");
        printf("--------------------\n\n");
        printf("1. Apilar (PUSH)\n");
        printf("2. Desapilar (POP)\n");
        printf("3. Consultar Elemento Superior\n");
        printf("0. Cerrar Programa\n");
        printf("--------------------\n\n");
        printf("Ingrese La Operacion: ");
        scanf("%d", &OPERACION);
        INTERFAZ = 0;
        switch (OPERACION)
        {
        case 1:
            /*PUSH*/
            LimpiarConsola();
            printf("        PUSH        \n\n");
            printf("--------------------\n\n");
            Push(DatoAleatorio(),PunterosPila);
            ImprimirPila(PunterosPila);
            system("PAUSE");
            break;
        case 2:
            /*POP*/
            LimpiarConsola();
            printf("         POP        \n\n");
            printf("--------------------\n\n");
            Dato = Pop(PunterosPila);
            printf("ID: %d\n",Dato.Id);
            printf("VALOR: %d\n", Dato.Valor);
            printf("ESTADO: %d\n", Dato.Estado);
            ImprimirPila(PunterosPila);
            system("PAUSE");
            break;
        case 3:
            /*TOP*/
            LimpiarConsola();
            Top(PunterosPila);
            ImprimirPila(PunterosPila);
            system("PAUSE");
            break;
        case 0:
            /*CLOSE*/
            LimpiarConsola();
            EJECUCION = 0;
            printf("CERRANDO EL PROGRAMA.\n");
            printf("---------------------\n\n");
            system("PAUSE");
            break;     
        default:
            /*EXCEPTION*/
            LimpiarConsola();
            printf("ERROR DE ENTRADA\n\n");
            system("PAUSE");
            break;
        }
    }
    
}

int main()
{
    EJECUCION = 1;
    Pila *PunterosPila;
    IniciarPila(PunterosPila);
    while (EJECUCION == 1)
    {
        MenuPrincipal(PunterosPila);
    }
    
    return 0;
}

void IniciarPila(Pila *PunterosPila)
{
    PunterosPila->Cabeza = NULL;
    PunterosPila->Longitud = 0;
}

void Push(Data Dato, Pila *PunterosPila)
{
    Nodo *NuevoApilado;
    NuevoApilado = malloc(sizeof(Nodo));
    NuevoApilado->Dato.Id = Dato.Id;
    NuevoApilado->Dato.Valor = Dato.Valor;
    NuevoApilado->Dato.Estado = Dato.Estado;
    NuevoApilado->Sig = NULL;
    if (PunterosPila->Cabeza == NULL)
    {
        PunterosPila->Cabeza = NuevoApilado;
    }
    else
    {
        NuevoApilado->Sig = PunterosPila->Cabeza;
        PunterosPila->Cabeza = NuevoApilado;
    }
    PunterosPila->Longitud++;    
}

Data Pop(Pila *PunterosPila)
{
    Nodo *Desapilado;
    Data Dato;
    Dato.Id = -1;
    Dato.Valor = -1;
    Dato.Estado = -1;
    if (PunterosPila->Cabeza == NULL)
    {
        printf("\n\n-----------------------\n\n");
        printf("-No Hay Que Desapilar-      \n");
        printf("\n\n-----------------------\n\n");
    }
    else
    {
        Desapilado = PunterosPila->Cabeza;
        Dato.Id = Desapilado->Dato.Id;
        Dato.Valor = Desapilado->Dato.Valor;
        Dato.Estado = Desapilado->Dato.Estado;
        PunterosPila->Cabeza = Desapilado->Sig;
        free(Desapilado);
        return Dato;
    }
    PunterosPila->Longitud--;
    return Dato;
}

void Top(Pila *PunterosPila)
{
    Nodo *Ojeada;
    Ojeada = PunterosPila->Cabeza;
    printf("Direccion: %p\n", Ojeada);
    printf("Id: %d\n", Ojeada->Dato.Id);
    printf("Valor: %d\n", Ojeada->Dato.Valor);
    printf("Estado: %d\n", Ojeada->Dato.Estado);
    printf("Apunta hacia %p\n", Ojeada->Sig);
}

void ImprimirPila(Pila *PunterosPila)
{
    Nodo *NodoApuntado;
    if (PunterosPila->Cabeza == NULL)
    {   
        printf("\n\n--------------------\n\n");
        printf("-No Tiene Elementos-      \n");
        printf("\n\n--------------------\n\n");
    }
    else
    {
        NodoApuntado = PunterosPila->Cabeza;
        printf("\n\n--------------------\n\n");
        printf("Cabeza: %p      \n", PunterosPila->Cabeza);
        printf("\n\n--------------------\n\n");
        while (NodoApuntado != NULL)
        {
            printf("---------------------\n");
            printf("Direccion Del Nodo %p\n", NodoApuntado);
            printf("    Datos:   \n");
            printf("    .Id Del Nodo %d\n", NodoApuntado->Dato.Id);
            printf("    .Valor Del Nodo %d\n", NodoApuntado->Dato.Valor);
            printf("    .Estado Del Nodo %d\n", NodoApuntado->Dato.Estado);
            printf("El Nodo Apunta: %p\n", NodoApuntado->Sig);
            printf("      Fin Nodo\n");
            printf("---------------------\n");
            printf("          |          \n");
            NodoApuntado = NodoApuntado->Sig;
        }
        printf("\n");       
    }   
}