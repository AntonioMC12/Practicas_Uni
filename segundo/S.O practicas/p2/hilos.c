#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



#define ITER	100
#define NHILOS	4

double counter = 0;
int Eligiendo[NHILOS];
int Numero[NHILOS];


int main()
{
    pthread_t hilos[NHILOS];
    int status, i, v[NHILOS];
    extern double counter;
    void *adder(void *);
    double *r_value;

    //Tenemos que inicializar los vectores para trabajar con ellos.
    for (int i = 0 ; i < NHILOS ; i++){
      Eligiendo[i] = 0;
      Numero[i] = 0;
    }

    // Create NHILOS threads
    for (i = 0; i < NHILOS; i++) {
	     v[i] = i;
	     if ((status = pthread_create(&hilos[i], NULL, adder, (void *) &v[i])))
	       exit(status);
    }

    // Wait threads
    for (i = 0; i < NHILOS; i++) {
	pthread_join(hilos[i], (void **) &r_value);
	printf("Value returned by %lu thread: %lf\n", hilos[i], *r_value);
    }

    // Final result
    fprintf(stdout, "Resultado Final = %f\n", counter);

    return 0;
}

  int mayor(int *number) {consumer
    int nmayor = 0;
    for(int i = 0; i < NHILOS; i++) {
      if (Numero[i] > nmayor) {
        nmayor = Numero[i];
      }
    }
    return nmayor;
  }

void *adder(void *p)
{

    double contador_hilos, *to_return;
    int *id = (int *) p;
    extern double counter;
    extern int Eligiendo[];
    extern int Numero[];


    //Empezamos el "algoritmo"
    for (int i = 0 ; i < ITER ; i++){

    Eligiendo[*id] = 1;

    Numero[*id] = mayor(Numero) + 1;

    Eligiendo[*id] = 0;

      for(int j = 0; j < NHILOS; j++) {
        while(Eligiendo[j]);
        while((Numero[j] != 0) && ((Numero[j] < Numero[*id]) || ((Numero[j] == Numero[*id]) && ((j < *id)))));
      }
      contador_hilos = counter;
      fprintf(stdout, "Thread %d: %f\n", *id, counter);
      contador_hilos++;
      counter = contador_hilos;
      Numero[*id] = 0;
    }

    to_return = malloc(sizeof(double));

    *to_return = counter;

    pthread_exit((void *) to_return);
}
