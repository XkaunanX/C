#include "ocurrencias.h"
#include <stdio.h>
#include <stdlib.h>

int ocurrenciasElemento(int *vector, int elemento, int longitud)
{
    //LOCAL
    int i, contador;
    for(i=0; i < longitud ;i++)
    {
        if(vector[i]==elemento){
            contador++;
        }
    }
    return contador;
}