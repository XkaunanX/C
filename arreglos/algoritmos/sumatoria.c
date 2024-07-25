#include "sumatoria.h"
#include <stdio.h>
#include <stdlib.h>

int sumatoriaVector(int *vector, int longitud)
{
    //LOCAL
    int i;
    int sumatoria=0;
    for(i=0; i < longitud; i++)
    {
        sumatoria+=vector[i];
    }
    return sumatoria;
}