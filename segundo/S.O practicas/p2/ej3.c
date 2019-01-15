
//Ejercicio 3.1 de la practica 2 de Sistemas Operativos

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

#define TAMBUFFER 5

int buffer[TAMBUFFER];

int suma_productor = 0, suma_consumidor = 0;

sem_t empty;
sem_t full;
sem_t mutex;

void * Productor();
void * Consumidor();

int main(){

  //inicializamos como nos dice el psudocodigo

  extern sem_t empty, full, mutex;
  //semilla del srand
  srand(time(NULL));

  //arrancamos los semaforos
  if((sem_init(&mutex, 0, 1)) == -1) perror("Error: Fallo al iniciar sem mutex\n");
  if((sem_init(&full, 0, 0)) == -1) perror("Error: Fallo al iniciar sem c_full\n");
  if((sem_init(&empty, 0, TAMBUFFER)) == -1) perror("Error: Fallo al iniciar sem p_empty\n");

  //Creamos los hilos
  pthread_t consumidor;
  pthread_t productor;
  int thread_status;

  int *consumidor_return = 0;
  int *productor_return = 0;

  //cramos tanto consumidor como productor

  if((thread_status = pthread_create(&consumidor, NULL, Consumidor, NULL))) {
    fprintf(stderr, "Fallo al crear consumidor\n");
    exit(thread_status);
  }

  if((thread_status = pthread_create(&productor, NULL, Productor, NULL))) {
    fprintf(stderr, "Fallo al crear productor\n");
    exit(thread_status);
  }


//creamos los waits
if(pthread_join(consumidor, (void *) &consumidor_return)) fprintf(stderr, "Error en pthread_join\n");
    if(*consumidor_return == suma_consumidor) {
        printf("La suma es (consumidor): %d\n", *consumidor_return);
}

pthread_join(productor, (void *) &productor_return);
printf("La suma ha sido (productor): %d\n", *productor_return);

}

void * Productor(){
    extern int buffer[TAMBUFFER], suma_productor;
    extern sem_t mutex, full, empty;
    int aux;
    int *to_return;

    for(int i = 0; i < 100; i++) {
        aux = ((rand() % 1000) + 1);
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[i % TAMBUFFER] = aux;
        suma_productor += buffer[i % TAMBUFFER];
        sem_post(&mutex);
        sem_post(&full);
    }

    to_return = malloc(sizeof(int));
    *to_return = suma_productor;
    pthread_exit((void *)to_return);
}

void * Consumidor(){

    extern int buffer[TAMBUFFER], suma_consumidor;
    extern sem_t mutex, full, empty;
    int *to_return;


    for(int i = 0; i < 100; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        suma_consumidor += buffer[i % TAMBUFFER];
        buffer[i % TAMBUFFER] = 0;
        sem_post(&mutex);
        sem_post(&empty);
    }

    to_return = malloc(sizeof(int));
    *to_return = suma_consumidor;
    pthread_exit((void *)to_return);
}
