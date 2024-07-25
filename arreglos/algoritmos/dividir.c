#include "dividir.h"
#include <stdio.h>
#include <stdlib.h>

int dividir(int vector[], int inicio, int final)
{
    int pivot=vector[final];
    int i=(inicio-1);
    for(int j=inicio; j <= final-1 ;j++)
    {
        if(vector[j] < pivot)
        {
            i++;
            Swap(&vector[i], &vector[j]);
        }
    }
    Swap(&vector[i+1], &vector[final]);
    return(i+1);
}