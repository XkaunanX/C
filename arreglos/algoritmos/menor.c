#include "menor.h"
#include <stdio.h>
#include <stdlib.h>

int menorVector(int *vector, int longitud)
{
    //LOCAL
    int i;
    int min=vector[0];
    for(i=1; i < longitud ;i++)
    {
        if(vector[i] < min)
        {
            min=vector[i];
        }
    }
    return min;
}