#include "countingSort.h"
#include <stdio.h>
#include <stdlib.h>

void countingSort(int *vector, int  *SortedVec, int max, int longitud){
    //VARIABLES LOCALES
    int *c = (int*)malloc(sizeof(int)*(1+max));
	int i;
    //ALGORTIMO
	for(i = 0; i <= max; i++)
	{
		c[i] = 0;
	}
	for(i = 1; i <= longitud; i++)
	{
		c[vector[i]]++;
	}
	for(i = 1; i <= max; i++)
	{
		c[i] = c[i-1]+c[i];
	}
	for(i = 1; i <= longitud; i++)
	{
		SortedVec[c[vector[i]]] = vector[i];
		c[vector[i]]--;
	}
	return;
}