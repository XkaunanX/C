#include "longitud.h"
#include <stdio.h>
#include <stdlib.h>

int longitudVector(int *vector)
{
    return sizeof(vector)/sizeof(vector[0]);
}