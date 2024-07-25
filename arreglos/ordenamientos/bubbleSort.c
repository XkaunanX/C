#include "bubbleSort.h"
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *vector, int longitud)
{
    //LOCAL
    int i,j,aux;
    for(i=1; i < longitud ;i++)
    {
        for(j=0; j < longitud-1 ;j++)
        {
            if(vector[j] > vector[j+1])
            {
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}