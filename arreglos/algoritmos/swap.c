#include "swap.h"
#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
    //LOCAL
    int tmp=*a;
    *a=*b;
    *b=tmp;
}