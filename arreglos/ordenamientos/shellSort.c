#include "shellSort.h"
#include <stdio.h>
#include <stdlib.h>

void shellSort(int *vector, int longitud){
    //VARIABLES LOCALES
    int i,x,y,temp;
    //LA IDEA ES QUE SOLO SE INCREMENTE EL INDICE A RAZON DE i*3+1 EN CADA REPETICION
    for (i = 0; i < longitud; i = i*3+1){}
    //MIENTRAS i > 0
    while (i > 0)
    {
        //PARA X = I HASTA QUE X > LONGITUD INCREMENTO EN 1
        for (x = i; x < longitud; x++)
        {
            y = x;
            temp = vector[x];
            //MIENTRAS Y SEA MAYOR IGUAL A I Y VEC[Y - I] SEA MAYOR A TEMP
            while (y >= i && vector[y - i] > temp)
            {
                vector[y] = vector[y - i];
                y = y - i;  
            }  
            vector[y] = temp;
        }
        i = i / 2;      
    }   
}