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

//ESTRUCTURA DE LA LISTA

typedef struct Lista
{
    Nodo *Cabeza;
    Nodo *Final;
    int Longitud;
}Lista;

//FUNCIONES

Data DatoAleatorio(){//GENERA UN DATO CON VALORES ALEATORIOS
    srand(time(NULL));
    Data DatoGenerado;
    DatoGenerado.Id = rand()%100;
    DatoGenerado.Valor = rand()%1000;
    DatoGenerado.Estado = rand()%2;
    return DatoGenerado;
}

Nodo *EncontrarNodo(int Id, Lista *PunterosLista);//DEVUELVE EL NODO BUSCADO POR SU ID

//PROCEDIMIENTOS

void Swap(Nodo *a, Nodo *b){
    Data aux;
    aux.Id = a->Dato.Id;
    aux.Valor = a->Dato.Valor;
    aux.Estado = a->Dato.Estado;
    a->Dato.Id = b->Dato.Id;
    a->Dato.Valor = b->Dato.Valor;
    a->Dato.Estado = b->Dato.Estado;
    b->Dato.Id = aux.Id;
    b->Dato.Valor = aux.Valor;
    b->Dato.Estado = aux.Estado;
}

void IniciarLista(Lista *PunterosLista);//INICIALISTA LA ESTRUCTURA LISTA

void InsertarElemento(Data Dato, Lista *PunterosLista);//INSERTA AL FINAL DE LA LISTA

void ImprimirLista(Lista *PunterosLista);//IMPRIME LA LISTA

void EliminarElemento(int Id, Lista *PunterosLista);//ELIMINA EL ELEMENTO POR SU ID

void ActualizarNodo(Data NuevoDato, Lista *PunterosLista);//ACTUALIZA LOS DATOS DEL NODO

void BubbleSort(Lista *PunterosLista);

//MENUS

void MenuOperaciones(Lista *PunterosLista)
{
    int INTERFAZ = 1, OPERACION, Aux;
    Nodo *NodoDevuelto;
    Data NodoActualizado;
    while (INTERFAZ == 1)
    {
        LimpiarConsola();
        printf("          MENU OPERACIONES\n");
        printf("----------------------------------\n\n");
        printf("1. Agregar Nodo.\n");
        printf("2. Eliminar Nodo.\n");
        printf("3. Buscar Nodo.\n");
        printf("4. Actualizar Nodo.\n");
        printf("5. Imprimir Lista.\n");
        printf("6. Determinar Longitud De Lista.\n");
        printf("7. Ordenar La Lista\n");
        printf("0. Volver Al Menu Principal.\n\n");
        printf("----------------------------------\n\n");
        printf("Ingrese La Operacion: ");
        scanf("%d", &OPERACION);
        INTERFAZ = 0;
        switch (OPERACION)
        {
        case 1:
            system("CLS");           
            InsertarElemento(DatoAleatorio(), PunterosLista);
            ImprimirLista(PunterosLista);
            system("PAUSE");
            break;
        case 2:
            system("CLS");
            printf("Ingresar Id: ");
            scanf("%d", &Aux);
            printf("\n\n");
            EliminarElemento(Aux, PunterosLista);
            ImprimirLista(PunterosLista);
            system("PAUSE");
            break;
        case 3:
            system("CLS");
            printf("Ingresar Id: ");
            scanf("%d", &Aux);
            NodoDevuelto = EncontrarNodo(Aux, PunterosLista);
            printf("\n\nDireccion En Memoria: %p\n\n", NodoDevuelto);
            printf("    Datos:\n");
            printf("        Id: %d\n", NodoDevuelto->Dato.Id);
            printf("        Valor: %d\n", NodoDevuelto->Dato.Valor);
            printf("        Estado: %d\n", NodoDevuelto->Dato.Estado);
            printf("        Apunta Hacia: %p\n\n", NodoDevuelto->Sig);
            system("PAUSE");
            break;
        case 4:
            system("CLS");
            printf("Ingresar Id: ");
            scanf("%d", &NodoActualizado.Id);
            printf("Ingresar Valor: ");
            scanf("%d", &NodoActualizado.Valor);
            printf("Ingresar Estado: ");
            scanf("%d", &NodoActualizado.Estado);
            ActualizarNodo(NodoActualizado, PunterosLista);
            ImprimirLista(PunterosLista);
            system("PAUSE");
            break;  
        case 5:
            system("CLS");
            ImprimirLista(PunterosLista);
            system("PAUSE");  
            break;
        case 6:
        system("CLS");
        printf("Longitud De Lista: %d\n", PunterosLista->Longitud);
        system("PAUSE");
            break;           
        case 7:
            system("CLS");
            printf("BUBBLE SORT\n\n");
            BubbleSort(PunterosLista);
            ImprimirLista(PunterosLista);
            system("PAUSE");
            break;
        default:
            INTERFAZ = 1;
            break;
        }
    }   
}

void MenuPrincipal(Lista *PunterosLista)
{
    int INTERFAZ = 1, OPERACION;
    while (INTERFAZ == 1)
    {
        LimpiarConsola();
        printf("          MENU PRINCIPAL\n");
        printf("----------------------------------\n\n");
        printf("1. Menu De Operaciones.\n");
        printf("0. Cerrar El Programa.\n\n");
        printf("----------------------------------\n\n");
        printf("Ingrese La Operacion: ");
        scanf("%d", &OPERACION);
        INTERFAZ = 0;
        switch (OPERACION)
        {
        case 1:
            /* code */
            MenuOperaciones(PunterosLista);
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
}

//MODULO PRINCIPAL

int main()
{
    EJECUCION = 1;
    Lista *PunterosLista; 
    IniciarLista(PunterosLista);

    while (EJECUCION == 1)
    {
        MenuPrincipal(PunterosLista);
    }   
    
    return 0;
}

void IniciarLista(Lista *PunterosLista)
{
    PunterosLista->Cabeza= NULL;
    PunterosLista->Final = NULL;
    PunterosLista->Longitud = 0;
}

void InsertarElemento(Data Dato, Lista *PunterosLista)
{
    Nodo *NuevoNodo;
    NuevoNodo = malloc(sizeof(Nodo));
    NuevoNodo->Dato.Id = Dato.Id;
    NuevoNodo->Dato.Valor = Dato.Valor;
    NuevoNodo->Dato.Estado = Dato.Estado;
    NuevoNodo->Sig = NULL;
    if (PunterosLista->Cabeza == NULL)
    {
        PunterosLista->Cabeza = NuevoNodo;
        PunterosLista->Final = NuevoNodo;
    }
    else
    {
        PunterosLista->Final->Sig = NuevoNodo;
        PunterosLista->Final = NuevoNodo;
    }
    PunterosLista->Longitud++;
}

void ImprimirLista(Lista *PunterosLista)
{
    Nodo *NodoApuntado;
    if (PunterosLista->Cabeza == NULL)
    {   
        printf("\n\n--------------------\n\n");
        printf("-No Tiene Elementos-      \n");
        printf("\n\n--------------------\n\n");
    }
    else
    {
        NodoApuntado = PunterosLista->Cabeza;
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

void EliminarElemento(int Id, Lista *PunterosLista)
{
    Nodo *NodoAnterior = PunterosLista->Cabeza;
    Nodo *NodoActual;
    if (PunterosLista->Cabeza == NULL)
    {
        printf("\n\n-----------------------\n\n");
        printf("-No Hay Que Eliminarar-      \n");
        printf("\n\n-----------------------\n\n");
    }
    else if(PunterosLista->Cabeza->Sig == NULL)
    {
        NodoActual = PunterosLista->Cabeza;
        PunterosLista->Cabeza == NULL;
        free(NodoActual);
    }
    else
    {
        NodoActual = NodoAnterior->Sig;
        while (NodoActual != NULL)
        {
            if (NodoActual->Dato.Id == Id)
            {
                NodoAnterior->Sig = NodoActual->Sig;
                free(NodoActual);
                return;
            }
            else
            {
                NodoAnterior = NodoActual;
                NodoActual = NodoAnterior->Sig;
            }
        }  
    }
    PunterosLista->Longitud--;
}

Nodo *EncontrarNodo(int Id, Lista *PunterosLista)
{
    Nodo *NodoActual;
    if (PunterosLista->Cabeza == NULL)
    {
        return NULL;
    }
    else
    {
        NodoActual = PunterosLista->Cabeza;
        while (NodoActual != NULL)
        {
            if (NodoActual->Dato.Id == Id)
            {
                return NodoActual;
            }
            else
            {
                NodoActual = NodoActual->Sig;
            }           
        }       
    }
    return NULL;
}

void ActualizarNodo(Data NuevoDato, Lista *PunterosLista)
{
    Nodo *NodoApuntado;
    if (PunterosLista->Cabeza == NULL)
    {
        printf("\n\n-----------------------\n\n");
        printf("-No Hay Que Actualizar-      \n");
        printf("\n\n-----------------------\n\n");
    }
    else
    {
        Nodo *NodoApuntado = PunterosLista->Cabeza;
        while (NodoApuntado != NULL)
        {
            if (NodoApuntado->Dato.Id == NuevoDato.Id)
            {
                NodoApuntado->Dato.Valor = NuevoDato.Valor;
                NodoApuntado->Dato.Estado = NuevoDato.Estado;
                return;
            }
            else
            {
                NodoApuntado = NodoApuntado->Sig;
            }          
        }      
    }
}

void BubbleSort(Lista *PunterosLista)
{
    int swapped, i;
    Nodo *NodoActual;
    Nodo *NodoAux = NULL;
    if (PunterosLista->Cabeza == NULL)
    {
        printf("\n\n-----------------------\n\n");
        printf("- No Hay Que Ordenar-      \n");
        printf("\n\n-----------------------\n\n");
    }
    else
    {
        do{
            swapped = 0;
            NodoActual = PunterosLista->Cabeza;
            while (NodoActual->Sig != NodoAux)
            {
                if (NodoActual->Dato.Valor > NodoActual->Sig->Dato.Valor)
                {
                    Swap(NodoActual, NodoActual->Sig);
                    swapped = 1;
                }
                NodoActual = NodoActual->Sig;
            }
            NodoAux = NodoActual;
        }
        while (swapped);      
    }
}
