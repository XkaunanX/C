#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Crear una rutina en lenguaje C donde se crea un proceso, como salida imprima el siguiente
//mensaje:
//Soy el padre, si estoy en proceso padre
//Soy el hijo , si estoy en proceso hijo

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
    }
    //Cuando el cod es mayor que 0 - Estoy en el padre o abuelo ...
    else if (cod > 0)
    {
        //Como solo hay un fork. Solo es posible estar en el padre
        printf("Estoy en el padre.\n");
        printf("cod: %d\n", cod);
    }
    return 0;
}