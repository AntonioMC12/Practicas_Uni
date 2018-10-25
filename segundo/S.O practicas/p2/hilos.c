#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

double counter = 0;
bool Eligiendo[] = ;
int Numero = ;

#define ITER	100
#define NHILOS	4

int main()
{
    pthread_t hilos[NHILOS];
    int status, i, v[NHILOS];
    extern double counter;
    void *adder(void *);
    double *r_value;

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
    fprintf(stdout, "%f\n", counter);

    return 0;
}

void *adder(void *p)
{
    double l, *to_return;
    extern double counter;
    int *id, i;
    extern bool Eligiendo[];
    extern int Numero[];

    //inicializamos las variables
    Eligiendo[] = false;
    Numero[] = 0;

    id = (int *) p;
    int j;

    while(true){
      Eligiendo[id*] = true;
      Numero = max()+1;
      Eligiendo[id*] = false;
      for ( j = 0; j < N; j++) {
        Eligiendo[j];
        
      }

      Numero[id*] = 0;
    }



    }

    to_return = malloc(sizeof(double));

    *to_return = counter;

    pthread_exit((void *) to_return);
}
