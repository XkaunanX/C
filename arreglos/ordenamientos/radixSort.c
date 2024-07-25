#include "radixSort.h"
#include <stdio.h>
#include <stdlib.h>

void RadixSort(int *vector, int longitud){
    //VARIABLES LOCALES
    int i;
    //VECTOR SEMIORDENADO
    int *semiSorted;
    //ASIGNO MEMORIA AL VECTOR
    semiSorted =(int*)malloc(longitud * sizeof(int));
    //DIGITO SIGNIFICATIVO
    int DigitoSignificativo = 1;
    int NumeroMayor = MayorVector(vector, longitud);
    
    //LOOP HASTA LLEGAR AL DIGITO SIGNIFICATIVO MAS GRANDE
    while (NumeroMayor / DigitoSignificativo > 0){
        
        //DEPOSITO
        int bucket[10] = { 0 };
        
        //CUENTA EL NUMERO DE "CLAVES" O DIGITOS QUE ENTRAR EN CADA
        for (i = 0; i < longitud; i++)
        bucket[(vector[i] / DigitoSignificativo) % 10]++;
        
        for (i = 1; i < 10; i++)
        bucket[i] += bucket[i - 1];
        
        // USO EL DEPOSITO PARA RELLENAR A "semiSorted" array
        for (i = longitud - 1; i >= 0; i--)
        semiSorted[--bucket[(vector[i] / DigitoSignificativo) % 10]] = vector[i];
        
        //REPETIR HASTA EL LIMITE
        for (i = 0; i < longitud; i++)
        vector[i] = semiSorted[i];
        
        // SE MUEVO AL SIGUIENTE DIGITO SIGNIFICATIVO
        DigitoSignificativo *= 10;
    }
}