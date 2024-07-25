#include "mayor.h"
#include <stdio.h>
#include <stdlib.h>

int mayorVector(int *vector, int longitud)
{
    //LOCAL
    int i;
    int max=vector[0];
    for(i=1; i < longitud ;i++)
    {
        if(vector[i] > max)
        {
            max=vector[i];
        }
    }
    return max;
}