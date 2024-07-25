#include "duplicados.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void duplicadosVector(int *vector, int longitud, int Maximo)
{
    //LOCAL
    int i,j;
    int repeticiones;
    srand(time(NULL));
    while (repeticiones==1)
    {
        repeticiones=0;
        for(i=0; i < longitud ;i++)
        {
            for(j=i+1; j < longitud ;j++)
            {
                if(vector[i]==vector[j]&&vector[i]!=Maximo)
                {
                    vector[i]=vector[i]+1;
                    repeticiones=1;
                }
            }
        }
    }
    
}