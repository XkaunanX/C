#include "selectionSort.h"
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *vector, int longitud)
{
    //LOCAL
    int i,j;
    for(i=0; i < longitud-1 ;i++)
    {
        for(j = i; j < longitud; j++)
        {
            if (vector[i] > vector[j])
            {
                Swap(&vector[i], &vector[j]);
            }         
        }       
    }
}