#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Crear una rutina en lenguaje C, donde se cree un proceso hijo, además de imprimir los PID del
//padre e hijo, el hijo debe ejecutar el comando listar directorio y mostrar la salida del mismo por
//pantalla.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main()
{
    //CREO UN HIJO DEL PROCESO QUE EJECUTA ESTE SCRIPT C
    int pid = fork();

    //Si devuelve -1 ocurrio un error
    if (pid == -1)
    {
        printf("Error en el fork\n");
        //Finalizar script
        exit(-1);
    }

    if (pid == 0)
    {
        printf("Proceso hijo del proceso que ejecuta el script abuelo.c\n");
        printf("Hijo - id: %d\n", getpid());
        printf("El id del proceso que ejecuta el script abuelo.c\n");
        printf("Padre - id: %d\n", getppid());
        system("/bin/echo 'Imprimiendo desde el hijo\n'");
        system("/bin/ls");
    }

    //En c no hay manera de ver eñ pid del proceso abuelo
    printf("El id del proceso que llamo al script abuelo.c\n");
    printf("Padre del padre - id: %d\n", getppid());
    return 0;
}