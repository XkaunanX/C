#include "mergeSort.h"
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *vec, int inicio ,int longitud){
    //CASO BASE
    if (inicio < longitud){
        //ENCUENTRO EL INDICE MEDIO
        int mitad = (inicio + longitud) / 2;
        //RESOLVER EL PROBLEMA DE MANERA RECURSIVA HASTA LLEGAR A UNA SOLUCION TRIVIAL
        //RECURSIVAMENTE ORDENO EL SUBVECTOR IZQUIERDO
        mergeSort(vec, inicio, mitad);
        //RECURSIVAMENTE ORDENO EL SUBVECTOR DERECHO
        mergeSort(vec, mitad + 1, longitud);
        //UNIR SUBVECTORES L[] Y R[] EN VECTOR DEJANDOLO ORDENADO
        merge(vec, inicio, mitad, longitud);
    } 
}

void merge(int *vec, int inicio, int mitad, int longitud){
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
