#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// IMPRIMO HIJOS

//Crear una rutina en lenguaje C, donde me permita ejecutar varias sentencias fork(), para eso
//deberá ingresar por teclado la cantidad que desea ejecutar.
//a) Que muestre solamente por pantalla todos los procesos hijos
//b) Que muestre solamente por pantalla todos los procesos padres
//c) Que muestre por pantalla ambos (Padres e Hijos)
//Nota: para que las salidas no sean engorrosas no ejecutar más de 4 fork()

main (){
    //ENTRADA
    int cantidad = 0;
    printf("Ingrese la cantidad de forks: \n");
    scanf("%d", &cantidad);

    //REPITO LA BIFURCACION
    for(int i = 0; i < cantidad; i++){

        int return_fork = fork();

        //ESTOY EN EL HIJO
        if (return_fork == 0){
            printf("hijo %d\n ", i);
            break;
        }  

    }

    sleep(3000);

    return 0;
}