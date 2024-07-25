#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//VARIABLES
int EJECUCION;
clock_t inicial, final;
double cpu_tiempo_de_uso;

//ESTRUCTURADOS
int VECTOR[100];

//CONSOLA
void FINPROGRAMA();
void ERRORENTRADA();
void LIMPIARCONSOLA();
void PAUSARCONSOLA();
void DOBLESALTODELINEA();

//FIRMAS FUNCIONES
int Partition(int vec[], int inicio, int longitud);
int SumatoriaVector(int *vec, int longitud);
int PromedioVector(int *vec, int longitud);
int MayorVector(int *vec, int longitud);
int MenorVector(int *vec, int longitud);

//FIRMAS PROCEDIMIENTOS
void MenuPrincipal();
void MenuOrdenamientos();
void MenuOperaciones();
void AgregarElemento(int *vec, int longitud);
void SeleccionarElemento(int *vec, int longitud);
void EncontrarElemento(int *vec, int longitud);
void ImprimirVector(int *vec, int longitud);
void RandomEnVector(int *vec, int longitud,int Max);
void DuplicadosVector(int *vec, int longitud, int Max);
void Swap(int *a, int *b);
void BubbleSort(int *vec, int longitud);
void InsertionSort(int *vec, int longitud);
void SelectionSort(int *vec, int longitud);
void MergeSort(int *vec, int inicio ,int longitud);
void Merge(int *vec, int inicio, int mitad, int longitud);
void QuickSort(int vec[], int inicio, int longitud);
void RadixSort(int *vec, int longitud);
void CountingSort(int *vec, int  *SortedVec, int max, int longitud);
void ShellSort();

//MODULO PRINCIPAL
int main(int argc, char const *argv[])
{
    EJECUCION = 0;
    //INICIALIZO ELEMENTOS DEL VECTOR
    RandomEnVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]), 9999);
    while (EJECUCION == 0)
    {
        //INICIALIZO INTERFAZ DE USUARIO
        MenuPrincipal();
    }   
    return 0;
}

//CONSOLA
void FINPROGRAMA(){
    EJECUCION = 0;
    LIMPIARCONSOLA();
    printf("Saliendo Del programa. ");
    PAUSARCONSOLA();
    DOBLESALTODELINEA();    
}

void ERRORENTRADA(){
    printf("El Valor Es Incorrecto");
    DOBLESALTODELINEA();
    printf("Vuelva a intentarlo. ");
    PAUSARCONSOLA();
    LIMPIARCONSOLA();
}

void PAUSARCONSOLA(){
    system("PAUSE");
}

void LIMPIARCONSOLA(){
    system("CLS");
}

void DOBLESALTODELINEA(){
    printf("\n\n");
}

//MENUS
void MenuPrincipal(){
    int INTERFAZ = 0;
    int OPERACION = 0;
    while (INTERFAZ == 0)
    {
        //INTERFAZ DE USUARIO
        LIMPIARCONSOLA();
        printf("              MENU              \n");
        printf("---------------------------------\n\n");        
        printf("1.Menu Operaciones\n\n");
        printf("2.Menu Ordenamientos\n\n");
        printf("3.Reasignar Valores\n\n");
        printf("4.Imprimir Vector\n\n");
        printf("0.Salir Del Programa\n\n");
        printf("---------------------------------\n\n"); 
        printf("Igresar Operacion: ");
        scanf("%d", &OPERACION);
        INTERFAZ = 1;
        //RAMIFICACION
        switch (OPERACION)
        {
        case 1:
            /*MENU DE OPERACIONES*/
            MenuOperaciones();
            break;
        case 2:
            /*MENU DE ORDENAMIENTOS*/
            MenuOrdenamientos();
            break;
        case 3:
            /*VOLVER A ASIGNAR VALORES*/
            RandomEnVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]), 9999);
            break;
        case 4:
            /*IMPRIMIR VALORES*/
            ImprimirVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            PAUSARCONSOLA();
            break; 
        case 0:
            /*FIN*/
            FINPROGRAMA();
            EJECUCION = 1;
            break;       
        default:
            /*ERROR ENTRADA*/
            ERRORENTRADA();
            INTERFAZ = 1;
            break;
        }
    }  
}

void MenuOperaciones(){
    //VARIABLES LOCALES
    int INTERFAZ = 0;
    int OPERACION;
    int POS1 = 0, POS2 = 0;
    while (INTERFAZ == 0)
    {
        //INTERFAZ DE USUARIO
        LIMPIARCONSOLA();
        printf("            OPERACIONES            \n");
        printf("---------------------------------\n\n");
        printf("1.Modificar Elemento Individual\n\n");
        printf("2.Acceder Elemento Individual\n\n");        
        printf("3.Encontrar Elemento\n\n");
        printf("4.Maximo\n\n");
        printf("5.Minimo\n\n");
        printf("6.Sumatoria De Elementos\n\n");
        printf("7.Promedio De Elementos\n\n");
        printf("8.Eliminar Duplicados\n\n");
        printf("9.SWAP Elementos\n\n");
        printf("0.Volver atras\n\n");
        printf("---------------------------------\n\n"); 
        printf("Igresar Operaricion: ");
        scanf("%d", &OPERACION);
        //RAMIFICACION
        switch (OPERACION)
        {
        case 1:
            /*MODIFICAR ELEMENTO*/
            AgregarElemento(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            PAUSARCONSOLA();
            break;
        case 2:
            /*ACCEDER ELEMENTO*/
            SeleccionarElemento(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            PAUSARCONSOLA();
            break;
        case 3:
            /*BUSCAR ELEMENTO*/
            EncontrarElemento(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            PAUSARCONSOLA();
            break;
        case 4:
            /*DETERMINAR MAXIMO*/
            LIMPIARCONSOLA();
            printf("3.Maximo\n\n");
            printf("---------------------------------\n\n");
            DOBLESALTODELINEA();
            inicial = clock();
            //CALL
            int resultadoMayor = MayorVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            final = clock();
            printf("El Maximo Es: %d \n", resultadoMayor);
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f \n", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 5:
            /*DETERMINAR MINIMO*/
            LIMPIARCONSOLA();
            printf("3.Minimo\n\n");
            printf("---------------------------------\n\n");
            DOBLESALTODELINEA();
            inicial = clock();
            //CALL
            int resultadoMenor = MenorVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            final = clock();
            printf("El Minimo Es: %d \n", resultadoMenor);
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f \n", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 6:
            /*SUMATORIA*/
            LIMPIARCONSOLA();
            printf("3.Sumatoria\n\n");
            printf("---------------------------------\n\n");
            DOBLESALTODELINEA();
            inicial = clock();
            //CALL
            int resultadoSumatoria = SumatoriaVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            final = clock();
            printf("La Suma De Los Elementos Es: %d \n", resultadoSumatoria);
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f \n", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 7:
            /*PROMEDIO*/
            LIMPIARCONSOLA();
            printf("3.Promedio\n\n");
            printf("---------------------------------\n\n");
            DOBLESALTODELINEA();
            inicial = clock();
            //CALL
            int resultadoPromedio = PromedioVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            final = clock();
            printf("El Promedio De Los Elementos Es: %d \n", resultadoPromedio);
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f \n", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 8:
            /*DUPLICADOS*/
            DuplicadosVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]), 9999);
            PAUSARCONSOLA();
            break;
        case 9:
            /*SWAP*/
            //INTERFAZ USUARIO
            LIMPIARCONSOLA();
            printf("3.SWAP Elementos\n\n");
            printf("---------------------------------\n\n");
            DOBLESALTODELINEA();
            printf("Ingrese 1ra posicion: ");      
            scanf("%d", &POS1);
            printf("\nIngrese 2da posicion: ");
            scanf("%d", &POS2);
            //TOMO TIEMPO
            inicial = clock();
            //INTERCAMBIO
            Swap(&VECTOR[POS1], &VECTOR[POS2]);
            //TOMO TIEMPO
            final = clock();
            ImprimirVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 0:
            /*VOLVER MENU PRINCIPAL*/
             INTERFAZ = 1;
            break;        
        default:
            /*ERROR ENTRADA*/
            ERRORENTRADA();
            INTERFAZ = 1;
            break;
        }
    }    
}

void MenuOrdenamientos(){
    int INTERFAZ = 0;
    int OPERACION;
    while (INTERFAZ == 0)
    {
        //INTERFAZ DE USUARIO
        LIMPIARCONSOLA();
        printf("           ORDENAMIENTOS          \n");
        printf("---------------------------------\n\n");
        printf("1.Bubble Sort\n\n");
        printf("2.Insertion Sort\n\n");        
        printf("3.Selection Sort\n\n");
        printf("4.Merge Sort\n\n");
        printf("5.Quick Sort\n\n");
        printf("6.Radix Sort\n\n");
        printf("7.Count Sort\n\n");
        printf("8.Shell Sort\n\n");
        printf("0.Volver atras\n\n");
        printf("---------------------------------\n\n"); 
        printf("Igresar Operaricion: ");
        scanf("%d", &OPERACION);
        //RAMIFICACION
        switch (OPERACION)
        {
        case 1:
            /*BURBUJA*/
            LIMPIARCONSOLA();
            printf("1.Bubble Sort\n\n");
            printf("---------------------------------\n\n");
            //TOMO TIEMPO
            inicial = clock();
            //CALL
            BubbleSort(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            //TOMO TIEMPO
            final = clock();
            //IMPRIMIR
            ImprimirVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 2:
            /*INSERCION*/
            LIMPIARCONSOLA();
            printf("2.Insertion Sort\n\n");
            printf("---------------------------------\n\n");
            //TOMO TIEMPO
            inicial = clock();
            //CALL
            InsertionSort(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            //TOMO TIEMPO
            final = clock();
            //IMPRIMIR
            ImprimirVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 3:
            /*SELECCION*/
            LIMPIARCONSOLA();
            printf("3.Selection Sort\n\n");
            printf("---------------------------------\n\n");
            //TOMO TIEMPO
            inicial = clock();
            //CALL
            SelectionSort(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            //TOMO TIEMPO
            final = clock();
            //IMPRIMIR
            ImprimirVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 4:
            /*MERGE*/
            LIMPIARCONSOLA();
            printf("4.Merge Sort\n\n");
            printf("---------------------------------\n\n");
            //TOMO TIEMPO
            inicial = clock();
            //CALL
            MergeSort(VECTOR, 0,sizeof(VECTOR)/sizeof(VECTOR[0]));
            //TOMO TIEMPO
            final = clock();
            //IMPRIMIR
            ImprimirVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 5:
            /*QUICK*/
            LIMPIARCONSOLA();
            printf("5.Quick Sort\n\n");
            printf("---------------------------------\n\n");
            //TOMO TIEMPO
            inicial = clock();
            //CALL
            QuickSort(VECTOR, 0,sizeof(VECTOR)/sizeof(VECTOR[0]) - 1);
            //TOMO TIEMPO
            final = clock();
            //IMPRIMIR
            ImprimirVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 6:
            /*RADIX*/
            LIMPIARCONSOLA();
            printf("5.Radix Sort\n\n");
            printf("---------------------------------\n\n");
            //TOMO TIEMPO
            inicial = clock();
            //CALL
            RadixSort(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            //TOMO TIEMPO
            final = clock();
            //IMPRIMIR
            ImprimirVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 7:
            /*COUNT*/
            LIMPIARCONSOLA();
            printf("5.Count Sort\n\n");
            printf("---------------------------------\n\n");
            //TOMO TIEMPO
            inicial = clock();
            //VARIABLE
            int longitud = sizeof(VECTOR)/sizeof(int) - 1;//REDUCIDA EN UNO
            int *SortedVec = (int*)malloc(sizeof(int)*(longitud +1));//CREO UN VECTOR DE IGUAL TAMAÑO QUE ESTARA ORDENADO
            int max = MayorVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));//GUARDO EL MAYOR DEL VECTOR
            //RELLENO EL VECTOR ORDENADO CON 0
            for (int i = 0; i <  longitud; i++)
            {
                SortedVec[i] = 0;
            }         
            //CALL
            CountingSort(VECTOR, SortedVec, max, longitud);
            //TOMO TIEMPO
            final = clock();
            //IMPRIMIR
            ImprimirVector(SortedVec, longitud);
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 8:
            /*SHELL*/
            LIMPIARCONSOLA();
            printf("5.Shell Sort\n\n");
            printf("---------------------------------\n\n");
            //TOMO TIEMPO
            inicial = clock();
            //CALL
            ShellSort(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            //TOMO TIEMPO
            final = clock();
            //IMPRIMIR
            ImprimirVector(VECTOR, sizeof(VECTOR)/sizeof(VECTOR[0]));
            cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
            //TIEMPO DE LA OPERACION
            printf("La Operacion Tardo: %f", cpu_tiempo_de_uso);
            DOBLESALTODELINEA();
            PAUSARCONSOLA();
            break;
        case 0:
            /*VOLVER AL MENU PRINCIPAL*/
            INTERFAZ = 1;
            break;       
        default:
            /*ERROR ENTRADA*/
            ERRORENTRADA();
            INTERFAZ = 1;
            break;
        }
    }  
}

//FUNCIONES
int MayorVector(int *vec, int longitud){
    //VARIABLES LOCALES
    int i;
    int temp = vec[0];
    //MAPEAO
    for (i = 1; i < longitud; i++)
    {
        if(vec[i] > temp){
            temp = vec[i];
        }
    }
    return temp;
}

int MenorVector(int *vec, int longitud){
    //VARIABLES LOCALES
    int i;
    int temp = vec[0];
    //MAPEAO
    for (i = 1; i < longitud; i++)
    {
        if(vec[i] < temp){
            temp = vec[i];
        }
    }
    return temp;
}

int SumatoriaVector(int *vec, int longitud){
    //VARIABLES LOCALES
    int i;
    int SUMATORIA = 0;
    //MAPEAO
    for (i = 0; i < longitud; i++)
    {       
        SUMATORIA += vec[i];
    }
    return SUMATORIA;
}

int PromedioVector(int *vec, int longitud){
    //VARIABLES LOCALES
    int i;
    int SUMATORIA = 0;
    //MAPEAO
    for (i = 0; i < longitud; i++)
    {       
        SUMATORIA += vec[i];
    }    
    return SUMATORIA = SUMATORIA / longitud;
}

//PROCEDIMIENTOS
void RandomEnVector(int vec[], int longitud,int Max){
    //TOMO EL TIEMPO
    inicial = clock();
    //VARIABLES LOCALES
    int i,j;
    int REPETICIONES = 0;
    //SEMILLA DEL GENERADOR
    srand(time(NULL));
    //1RA PASADA - ASIGNO ELEMENTOS
    for (i = 0; i < longitud; i++)
    {
        //OBTENER NUMERO PSEUDOALEATORIO [0,Max]
        vec[i] = rand()%Max;
    }
    final = clock();
    cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
    //TIEMPO DE LA OPERACION
    printf("La Operacion Tardo: %f", cpu_tiempo_de_uso);
    DOBLESALTODELINEA();
}

void ImprimirVector(int *vec, int longitud){
    //TOMO EL TIEMPO
    inicial = clock();
    //VARIABLES LOCALES
    int i;
    //MSGJ
    DOBLESALTODELINEA();
    printf("Estado Actual: ");
    DOBLESALTODELINEA();
    //ALGORITMO
    for (size_t i = 0; i < longitud; i++)
    {
        printf("%d; ", vec[i]);
    }
    //TOMO TIEMPO
    DOBLESALTODELINEA();
    final = clock();
    cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
    //TIEMPO DE LA OPERACION
    printf("La Operacion Imprimir Vector Tardo: %f ", cpu_tiempo_de_uso);
    DOBLESALTODELINEA();
}

void AgregarElemento(int *vec, int longitud){
    //VARIABLES LOCALES
    int POSICION, VALOR;
    //INTERFAZ USUARIO
    LIMPIARCONSOLA();
    printf("1.Modificar Elemento Individual\n\n");
    printf("---------------------------------\n\n");
    printf("Ingrese Posicion: ");
    scanf("%d", &POSICION);   
    //POSICION [0,100]
    if (POSICION <= longitud && POSICION > -1)
    {
        DOBLESALTODELINEA();
        printf("Ingrese Valor: ");      
        scanf("%d", &VALOR);
        //TOMO EL TIEMPO
        inicial = clock();
        vec[POSICION] = VALOR;
        //TOMO EL TIEMPO
        final = clock();
    }
    //FALLO DE ENTRADA
    else{
        DOBLESALTODELINEA();
        printf("ERROR: overflow");
        DOBLESALTODELINEA();
    } 
    ImprimirVector(vec, longitud);
    cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
    //TIEMPO DE LA OPERACION
    printf("La Operacion Agregar Elemento Tardo: %f ", cpu_tiempo_de_uso);
    DOBLESALTODELINEA();
}

void SeleccionarElemento(int *vec, int longitud){
    //VARIABLES LOCALES
    int POSICION, VALOR;
    //INTERFAZ USUARIO
    LIMPIARCONSOLA();
    printf("2.Acceder Elemento Individual\n\n");
    printf("---------------------------------\n\n");
    printf("Ingrese Posicion: ");
    scanf("%d", &POSICION);   
    //POSICION [0,100]
    if (POSICION <= longitud && POSICION > -1)
    {
        DOBLESALTODELINEA();
        //TOMO EL TIEMPO
        inicial = clock();
        printf("Index %d Valor: %d \n\n", POSICION, vec[POSICION]);
        //TOMO EL TIEMPO
        final = clock();
    }
    //FALLO DE ENTRADA
    else{
        DOBLESALTODELINEA();
        printf("ERROR: overflow");
        DOBLESALTODELINEA();
    } 
    cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
    //TIEMPO DE LA OPERACION
    printf("La Operacion Seleccionar Elemento Tardo: %f ", cpu_tiempo_de_uso);
    DOBLESALTODELINEA();
}

void EncontrarElemento(int *vec, int longitud){
    //VARIABLES LOCALES
    int POSICION, VALOR, i;
    int CONTADOR = 0;
    //INTERFAZ USUARIO
    LIMPIARCONSOLA();
    printf("3.Encontrar Elemento\n\n");
    printf("---------------------------------\n\n");
    DOBLESALTODELINEA();
    printf("Ingrese Valor: ");      
    scanf("%d", &VALOR);
    //TOMO EL TIEMPO
    inicial = clock();
    //SI SON IGUALES 
    for (i = 0; i < longitud; i++)
    {
        if (VALOR == vec[i])
        {
                CONTADOR++;
        }
    }  
    //TOMO EL TIEMPO
    final = clock();  
    printf("Fue Encontrado %d Veces \n\n", CONTADOR);
    cpu_tiempo_de_uso = ((double) (final - inicial)) / CLOCKS_PER_SEC;
    //TIEMPO DE LA OPERACION
    printf("La Operacion Encontrar Elemento Tardo: %f ", cpu_tiempo_de_uso);
    DOBLESALTODELINEA();
}

void DuplicadosVector(int *vec, int longitud, int Max){
    //TOMO EL TIEMPO
    inicial = clock();
    //VARIABLES LOCALES
    int i,j;
    int REPETICIONES = 1;     
    //SEMILLA DEL GENERADOR
    srand(time(NULL));
    //INTERFAZ USUARIO
    LIMPIARCONSOLA();
    printf("8.Eliminar Duplicados\n\n");
    printf("---------------------------------\n\n");
    DOBLESALTODELINEA();
    //ELIMINA REPETIDOS
    while (REPETICIONES == 1)
    {
        REPETICIONES = 0;
        for (i = 0; i < longitud; i++)
        {
            for (j = i + 1; j < longitud; j++)
            {
                if (vec[i] == vec[j] && vec[i]!=Max)
                {
                    printf("%d = %d | Hay repeticion cambio de %d por %d\n", vec[i], vec[j] ,vec[i], vec[i]+1);
                    vec[i] = vec[i]+1;
                    REPETICIONES = 1;
                }
            }           
        }   
    }
}

void Swap(int *a, int *b){
    //VARIABLE LOCAL
    int TEMPORAL = *a;
    //SWAP
    *a = *b;
    *b = TEMPORAL;
}

void BubbleSort(int *vec, int longitud){
    //VARIABLES LOCALES
    int i,j;
    int aux;
    //ALGORTIMO BUBBLE SORT
    for (i = 1; i < longitud; i++)
    {
        for (j = 0; j < longitud - 1; j++)
        {
            if(vec[j] > vec[j+1])
            {
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }   
}

void InsertionSort(int *vec, int longitud){
    //VARIABLES LOCALES
    int i,j;
    int aux;
    //ALGORITMO INSERTION SORT
    for (i = 0; i < longitud; i++)
    {
        aux = vec[i];
        j= i-1;
        //MIENTRAS J menor igual a 0 y vec[j] > auxiliar
        while (j >= 0 && vec[j] > aux)
        {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = aux;
    }    
}

void SelectionSort(int *vec, int longitud){
    //VARIABLES LOCALES
    int i,j;
    //ALGORITMO SELECTION SORT
    for (i = 0; i < longitud -1; i++)
    {
        for (j = i; j < longitud; j++)
        {
            if (vec[i] > vec[j])
            {
                Swap(&vec[i], &vec[j]);
            }         
        }       
    }   
}

void MergeSort(int *vec, int inicio ,int longitud){
    //CASO BASE
    if (inicio < longitud){
        //ENCUENTRO EL INDICE MEDIO
        int mitad = (inicio + longitud) / 2;
        //RESOLVER EL PROBLEMA DE MANERA RECURSIVA HASTA LLEGAR A UNA SOLUCION TRIVIAL
        //RECURSIVAMENTE ORDENO EL SUBVECTOR IZQUIERDO
        MergeSort(vec, inicio, mitad);
        //RECURSIVAMENTE ORDENO EL SUBVECTOR DERECHO
        MergeSort(vec, mitad + 1, longitud);
        //UNIR SUBVECTORES L[] Y R[] EN VECTOR DEJANDOLO ORDENADO
        Merge(vec, inicio, mitad, longitud);
    } 
}

void Merge(int *vec, int inicio, int mitad, int longitud){
    //VARIABLES LOCALES
    int i;  //i - para marcar el indice de subvector (L)
    int j;  //j - para marcar el indice de subvector (R)
    int k;  //k - para marcar el indice de la union de los subvectores (VECTOR)
    //RECUENTO CANTIDAD DE ELEMEMENTOS EN LA IZQ 
    int recuento_izq = (mitad - inicio) + 1;
    //RECUENTO CANTIDAD DE ELEMEMENTOS EN LA DER
    int recuento_der = (longitud - mitad);
    //DECLARO LOS SUB VECTORES IZQUIERDO Y DERECHO
    int *L, *R;
    //LE ASIGNO ESPACIO EN MEMORIA
    L = (int*)malloc(recuento_izq * sizeof(int));
    R = (int*)malloc(recuento_der * sizeof(int));
    //COPIA DE LOS DATOS DEL VECTOR EN EL SUBARREGLO (L)
    for (i = 0; i < recuento_izq; i++)
    {
        L[i] = *(vec + inicio + i);
    }
    //COPIA DE LOS DATOS DEL VECTOR EN EL SUBARREGLO (R)
    for (j = 0; j < recuento_der; j++)
    {
        R[j] = *(vec + mitad + j + 1);
    }
    //BLANQUEO i,j
    i = 0;
    j = 0;
    //UNO LOS DATOS RESPETANDO EL VALOR MINIMO ENTRE DOS ARREGLOS
    for (k = inicio; k < longitud + 1; k++)
    {
        if (i == recuento_izq)
        {
            *(vec + k) = *(R + j);
            j =  j + 1;
        }
        else if(j == recuento_der)
        {
            *(vec + k) = *(L + i);
            i = i + 1;
        }
        else
        {
            if (*(L + i) <= *(R + j))
            {
                *(vec + k) = *(L + i);
                i = i + 1;
            }
            else
            {
                *(vec + k) = *(R + j);
                j = j + 1;
            }
        }
    }
}

int Partition(int vec[], int bajo, int alto)
{
	int pivot = vec[alto]; // pivot
	int i = (bajo - 1);	   // INDICE DE ELEMENTO MAS PEQUEÑO

	for (int j = bajo; j <= alto - 1; j++)
	{
        //SI EL ELEMENTO ACTUAS ES MENOR QUE EL PIVOT
		if (vec[j] < pivot)
		{
			i++; //INCREMENTO EL INDICE DE PARTICION
			Swap(&vec[i], &vec[j]);
		}
	}
	Swap(&vec[i + 1], &vec[alto]);
	return (i + 1);
}

/* 
LA FUNCION PRINCIPAL QUE IMPLEMENTA QUICKSORT
vec[] --> MATRIZ A ORDENAR
bajo --> INDICE INICIAL
alto --> INDICE FINAL
*/

void QuickSort(int vec[], int bajo, int alto)
{
	if (bajo < alto)
	{
        //pi ES EL INDICE DE PARTICION, vec[pi] AHORA ES EN EL LUGAR CORRECTO
		int pi = Partition(vec, bajo, alto);

        //ORDENAR ELEMENTOS POR SEPARADO ANTES DE LA PARTICION Y DESPUES DE LA PARTICION
		QuickSort(vec, bajo, pi - 1);
		QuickSort(vec, pi + 1, alto);
	}
}

void RadixSort(int *vec, int longitud){
    //VARIABLES LOCALES
    int i;
    //VECTOR SEMIORDENADO
    int *semiSorted;
    //ASIGNO MEMORIA AL VECTOR
    semiSorted =(int*)malloc(longitud * sizeof(int));
    //DIGITO SIGNIFICATIVO
    int DigitoSignificativo = 1;
    int NumeroMayor = MayorVector(vec, longitud);
    
    //LOOP HASTA LLEGAR AL DIGITO SIGNIFICATIVO MAS GRANDE
    while (NumeroMayor / DigitoSignificativo > 0){
        
        //DEPOSITO
        int bucket[10] = { 0 };
        
        //CUENTA EL NUMERO DE "CLAVES" O DIGITOS QUE ENTRAR EN CADA
        for (i = 0; i < longitud; i++)
        bucket[(vec[i] / DigitoSignificativo) % 10]++;
        
        for (i = 1; i < 10; i++)
        bucket[i] += bucket[i - 1];
        
        // USO EL DEPOSITO PARA RELLENAR A "semiSorted" array
        for (i = longitud - 1; i >= 0; i--)
        semiSorted[--bucket[(vec[i] / DigitoSignificativo) % 10]] = vec[i];
        
        //REPETIR HASTA EL LIMITE
        for (i = 0; i < longitud; i++)
        vec[i] = semiSorted[i];
        
        // SE MUEVO AL SIGUIENTE DIGITO SIGNIFICATIVO
        DigitoSignificativo *= 10;
    }
}

void CountingSort(int *vec, int  *SortedVec, int max, int longitud){
    //VARIABLES LOCALES
    int *c = (int*)malloc(sizeof(int)*(1+max));
	int i;
    //ALGORTIMO
	for(i = 0; i <= max; i++)
	{
		c[i] = 0;
	}
	for(i = 1; i <= longitud; i++)
	{
		c[vec[i]]++;
	}
	for(i = 1; i <= max; i++)
	{
		c[i] = c[i-1]+c[i];
	}
	for(i = 1; i <= longitud; i++)
	{
		SortedVec[c[vec[i]]] = vec[i];
		c[vec[i]]--;
	}
	return;
}

void ShellSort(int *vec, int longitud){
    //VARIABLES LOCALES
    int i,x,y,temp;
    //LA IDEA ES QUE SOLO SE INCREMENTE EL INDICE A RAZON DE i*3+1 EN CADA REPETICION
    for (i = 0; i < longitud; i = i*3+1){}
    //MIENTRAS i > 0
    while (i > 0)
    {
        //PARA X = I HASTA QUE X > LONGITUD INCREMENTO EN 1
        for (x = i; x < longitud; x++)
        {
            y = x;
            temp = vec[x];
            //MIENTRAS Y SEA MAYOR IGUAL A I Y VEC[Y - I] SEA MAYOR A TEMP
            while (y >= i && vec[y - i] > temp)
            {
                vec[y] = vec[y - i];
                y = y - i;  
            }  
            vec[y] = temp;
        }
        i = i / 2;      
    }   
}