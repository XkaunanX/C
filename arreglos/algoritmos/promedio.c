#include "promedio.h"
#include <stdio.h>
#include <stdlib.h>

int promedioVector(int *vector, int longitud)
{
    //LOCAL
    int i;
    int sumatoria=0;
    for(i=0; i < longitud ;i++)
    {
        sumatoria+=vector[i];
    }
    int promedio = sumatoria/longitud;
    return promedio;
}