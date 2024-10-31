#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 1 PADRE MULTIPLES HIJOS INMEDIATOS

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
    for (int i=0; i<cantidad; i++)
    {
        //BIFURCO EL PROCESO
        int pid = fork();

        //OCURRIO UN ERROR
        if(pid == -1)
        {
            printf("Ocurrio un error inesperado\n");
            return -1;
        }

        //ESTOY INDICANDO AL HIJO DEL PROCESO
        if(pid == 0)
        {
            printf("Soy el hijo (PID: %d) de mi padre (PID: %d)\n", getpid(), getppid());
            break;
        }
        else //ESTOY INDICANDO AL PROCESO PADRE
        {
            printf("Soy el padre (PID: %d) y he creado un hijo (PID: %d)\n", getpid(), pid);
        }

    }
    
    sleep(3000);

    return 0;
}