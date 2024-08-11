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

typedef struct Cola
{
    Nodo *Cabeza;
    Nodo *Tail;
    int Longitud;
}Cola;

//FUNCIONES

Data DatoAleatorio(){//GENERA UN DATO CON VALORES ALEATORIOS
    srand(time(NULL));
    Data DatoGenerado;
    DatoGenerado.Id = rand()%100;
    DatoGenerado.Valor = rand()%1000;
    DatoGenerado.Estado = rand()%2;
    return DatoGenerado;
}

Data DeQueue(Cola *PunterosCola);

Nodo *Front(Cola *PunterosCola);

int Longitud(Cola *PunterosCola);

int IsEmpty(Cola *PunterosCola);

//PROCEDIMIENTOS

void IniciarCola(Cola *PunterosCola);

void EnQueue(Data Dato, Cola *PunterosCola);

void Clear(Cola *PunterosCola);

void ImprimirCola(Cola *PunterosCola);

//MENUS

void MenuPrincipal(Cola *PunterosCola)
{
    int INTERFAZ = 1, OPERACION;
    Data Dato;
    Nodo *NodoDevuelto;
    while (INTERFAZ == 1)
    {
        LimpiarConsola();
        printf("        MENU        \n\n");
        printf("--------------------\n\n");
        printf("1. Encola (EnQueue).\n");
        printf("2. Desencolar (DeQueue).\n");
        printf("3. Front.\n");
        printf("4. Clear.\n");
        printf("5. Longitud.\n");
        printf("6. IsEmpty.\n");
        printf("0. Cerrar El Programa.\n");
        printf("--------------------\n\n");
        printf("Ingrese La Operacion: ");
        scanf("%d", &OPERACION);
        INTERFAZ = 0;
        switch (OPERACION)
        {
        case 1:
            /*EnQueue*/
            LimpiarConsola();
            printf("        ENQUEUE    \n\n");
            printf("--------------------\n\n");
            EnQueue(DatoAleatorio(), PunterosCola);
            ImprimirCola(PunterosCola);
            system("PAUSE");
            break;
        case 2:
            /*DeQueue*/
            LimpiarConsola();
            printf("        DEQUEUE        \n\n");
            printf("--------------------\n\n");
            Dato = DeQueue(PunterosCola);
            printf("Desencolado:\n");
            printf("    .Id:%d\n", Dato.Id);
            printf("    .Valor:%d\n", Dato.Valor);
            printf("    .Estado:%d\n", Dato.Estado);
            system("PAUSE");
            break;
        case 3:
            /*Front*/
            LimpiarConsola();
            printf("        FRONT        \n\n");
            printf("--------------------\n\n");
            NodoDevuelto = Front(PunterosCola);
            printf("---------------------\n");
            printf("Direccion Del Nodo %p\n", NodoDevuelto);
            printf("    Datos:   \n");
            printf("    .Id Del Nodo %d\n", NodoDevuelto->Dato.Id);
            printf("    .Valor Del Nodo %d\n", NodoDevuelto->Dato.Valor);
            printf("    .Estado Del Nodo %d\n", NodoDevuelto->Dato.Estado);
            printf("El Nodo Apunta: %p\n", NodoDevuelto->Sig);
            printf("      Fin Nodo\n");
            printf("---------------------\n");
            system("PAUSE");
            break;
        case 4:
            /*Clear*/
            LimpiarConsola();
            printf("        CLEAR        \n\n");
            printf("--------------------\n\n");
            Clear(PunterosCola);
            ImprimirCola(PunterosCola);
            system("PAUSE");
            break;
        case 5:
            /*Longitud*/
            LimpiarConsola();
            printf("        LONGITUD        \n\n");
            printf("--------------------\n\n");
            printf("La Longitud Es De: %d\n", Longitud(PunterosCola));
            system("PAUSE");
            break;
        case 6:
            /*IsEmpty*/
            LimpiarConsola();
            printf("        ISEMPTY?        \n\n");
            printf("--------------------\n\n");
            printf("0 Esta Vacia | 1 Tiene Elementos: %d", IsEmpty(PunterosCola));
            system("PAUSE");
            break;
        case 0:
            /*Exit*/
            LimpiarConsola();
            printf("        EXIT        \n\n");
            printf("--------------------\n\n");
            EJECUCION = 0;
            printf("Cerrando Programa\n");
            system("PAUSE");
            break;   
        default:
            /*ERROR*/
            LimpiarConsola();
            printf("        ERROR        \n\n");
            printf("--------------------\n\n");
            INTERFAZ = 1;
            printf("Fallo En La Entrada\n");
            system("PAUSE");
            break;
        }
    }      
}

//MODULO PRINCIPAL

int main()
{
    EJECUCION = 1;
    Cola *PunterosCola;
    IniciarCola(PunterosCola);
    while (EJECUCION == 1)
    {
        MenuPrincipal(PunterosCola);
    }
    
    return 0;
}

void IniciarCola(Cola *PunterosCola)
{
    PunterosCola->Cabeza = NULL;
    PunterosCola->Tail = NULL;
    PunterosCola->Longitud = 0;
}

void EnQueue(Data Dato, Cola *PunterosCola)
{
    Nodo *NuevoNodo;
    NuevoNodo = malloc(sizeof(Nodo));
    NuevoNodo->Dato.Id = Dato.Id;
    NuevoNodo->Dato.Valor = Dato.Valor;
    NuevoNodo->Dato.Estado = Dato.Estado;
    NuevoNodo->Sig = NULL;
    if (PunterosCola->Cabeza == NULL)
    {
        PunterosCola->Cabeza = NuevoNodo;
        PunterosCola->Tail = NuevoNodo;
    }
    else
    {
        PunterosCola->Tail->Sig = NuevoNodo;
        PunterosCola->Tail = NuevoNodo;
    }
    PunterosCola->Longitud++;
}

Data DeQueue(Cola *PunterosCola)
{
    Nodo *Desencolado;
    Data Dato;
    Dato.Id = -1;
    Dato.Valor = -1;
    Dato.Estado = -1;
    if (PunterosCola->Cabeza == NULL)
    {
        printf("\n\n-----------------------\n\n");
        printf("-No Hay Que Desencolar-      \n");
        printf("\n\n-----------------------\n\n");   
    }
    else
    {
        Desencolado = PunterosCola->Cabeza;
        Dato.Id = Desencolado->Dato.Id;
        Dato.Valor = Desencolado->Dato.Valor;
        Dato.Estado = Desencolado->Dato.Estado;
        PunterosCola->Cabeza = Desencolado->Sig;
        free(Desencolado);
        return Dato;
    }
    PunterosCola->Longitud--;
    return Dato;
}

Nodo *Front(Cola *PunterosCola)
{
    if (PunterosCola->Cabeza == NULL)
    {
        return NULL;
    }
    else
    {
        return PunterosCola->Cabeza;
    }
}

int Longitud(Cola *PunterosCola)
{
    return PunterosCola->Longitud;
}

int IsEmpty(Cola *PunterosCola)
{
    if (PunterosCola->Cabeza == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void Clear(Cola *PunterosCola)
{
    Nodo *Actual;
    Nodo *Siguiente;
    if (PunterosCola->Cabeza == NULL)
    {
        printf("\n\n--------------------\n\n");
        printf("-No Tiene Elementos-      \n");
        printf("\n\n--------------------\n\n");
    }
    else
    {
        Actual = PunterosCola->Cabeza;
        while (Actual != NULL)
        {
            Siguiente = Actual->Sig;
            free(Actual);
            Actual = Siguiente;
        }
        
    }
    PunterosCola->Cabeza = NULL;
}

void ImprimirCola(Cola *PunterosCola)
{
    Nodo *NodoApuntado;
    if (PunterosCola->Cabeza == NULL)
    {   
        printf("\n\n--------------------\n\n");
        printf("-No Tiene Elementos-      \n");
        printf("\n\n--------------------\n\n");
    }
    else
    {
        NodoApuntado = PunterosCola->Cabeza;
        printf("\n\n--------------------\n\n");
        printf("Cabeza: %p      \n", PunterosCola->Cabeza);
        printf("\n\n--------------------\n\n");
        printf("           |            \n");
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