#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Crear una rutina en lenguaje C donde se crea un proceso hijo, esta rutina debe tener como
//salida lo siguiente:
//Soy el hijo, “Nro de mi ProcessID”, Mi Padre es “ProcessID del Padre”
//Soy el padre, “Nro de mi ProcessID”, Mi Padre es “ProcessID del Padre del Padre”

int main()
{
    //Inicio de la concurrencia
    int cod = fork();

    //Si devuelve -1 ocurrio un error
    if (cod == -1)
    {
        printf("Error en el fork\n");
        //Finalizar script
        exit(-1);
    }

    //Cuando el cod es 0 - Estoy en el hijo
    if (cod == 0)
    {
        printf("Estoy en el hijo.\n");
        printf("cod: %d\n", cod);
        //Consulto el ProcessID
        printf("PADRE - pid: %d\n", getpid());
    }
    //Cuando el cod es mayor que 0 - Estoy en el padre o abuelo ...
    else if (cod > 0)
    {
        //Como solo hay un fork. Solo es posible estar en el padre
        printf("Estoy en el padre.\n");
        printf("cod: %d\n", cod);
        //Consulto el ProcessID
        printf("HIJO - pid: %d\n", getpid());
    }
    
    return 0;
}