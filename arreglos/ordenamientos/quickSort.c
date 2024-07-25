#include "quickSort.h"
#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
    //LOCAL
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int partition(int vector[], int bajo, int alto)
{
	int pivot=vector[alto]; // pivot
	int i=(bajo-1);	   // INDICE DE ELEMENTO MAS PEQUEÑO

	for (int j=bajo; j <= alto-1 ;j++)
	{
        //SI EL ELEMENTO ACTUAS ES MENOR QUE EL PIVOT
		if (vector[j] < pivot)
		{
			i++; //INCREMENTO EL INDICE DE PARTICION
			Swap(&vector[i], &vector[j]);
		}
	}
	Swap(&vector[i + 1], &vector[alto]);
	return (i + 1);
}

void quickSort(int vector[], int bajo, int alto)
{
	if (bajo < alto)
	{
        //pi ES EL INDICE DE PARTICION, vector[pi] AHORA ES EN EL LUGAR CORRECTO
		int pi = partition(vector, bajo, alto);

        //ORDENAR ELEMENTOS POR SEPARADO ANTES DE LA PARTICION Y DESPUES DE LA PARTICION
		quickSort(vector, bajo, pi - 1);
		quickSort(vector, pi + 1, alto);
	}
}

