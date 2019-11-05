#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define NUM 5

void * message_print (void *);

int main(void) 
{
    int error = 0;
    int i = 0;
    int j;
    int mess[NUM];
    
    /* Creación de un Array de hebras */ 
    pthread_t thr [NUM]; 
    
    for(i=0;i<NUM;i++) 
		mess[i]=i+1;
    
    for(i = 0; i < NUM; i++) 
	 {
        error = pthread_create( &(thr[i]), NULL, (void *) message_print, (void *) &mess[i]); 
        /* Manejar el error */
        //...
    }
    
    printf("Soy el main()...\n"); 
    pthread_exit(NULL);
    printf("Esta linea no se ejecuta!!!\n");
}

void * message_print (void * ptr) 
{
    int error = 0;
    /* Desconexión del hilo cuando finalice. 
	 pthread_self() devuelve el ID de la hebra que invoca esta función.*/

    error = pthread_detach(pthread_self());
    /* Manejo del error si lo hubiera */
    //...

    printf("Soy la hebra: %d\n", *(int *) ptr);
    pthread_exit(NULL); 
}

