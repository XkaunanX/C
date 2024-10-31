#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

//Declaro semaforo
sem_t sem;
//Declaro hilo
pthread_t hilo1, hilo2;
//Firmas
static void *function_hilo_1();
static void *function_hilo_2();

int main(){
    //INICIALIZO SEMAFORO
    sem_init(&sem, 0, 0);
    //CREO LOS HILOS
    pthread_create(&hilo1, NULL, *function_hilo_1, NULL);
    pthread_create(&hilo2, NULL, *function_hilo_2, NULL);
    // Esperar a que los hilos terminen
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    return 0;
}

//FUNCIONES

static void *function_hilo_1(){
    printf("Primero aprendo el lenguaje C\n");
    sleep(1); // Simula algún trabajo
    sem_wait(&sem); // Espera a que el semáforo esté disponible
}

static void *function_hilo_2(){
    printf("Segundo aprendo hilos C\n");
    sem_post(&sem); // Libera el semáforo
}