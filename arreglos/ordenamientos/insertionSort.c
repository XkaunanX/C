#include "insertionSort.h"
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *vector, int longitud)
{
    //LOCAL
    int i,j,aux;
    for(i=0; i < longitud ;i++)
    {
        aux = vector[i];
        j= i-1;
        while (j >= 0 && vector[j] > aux)
        {
            vector[j+1] = vector[j];
            j--;
        }
        vector[j+1] = aux;
    }
}