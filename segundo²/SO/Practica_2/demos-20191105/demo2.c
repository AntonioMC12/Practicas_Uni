#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>	

void * inc_x(void *x_void_ptr)
{
	//incrementar x hasta 100
	int *x_ptr = (int *)x_void_ptr; 

	//Observe que hay punto y coma al final
	while(++(*x_ptr) < 100); 

	printf("Incremento de x finalizado...\n");
 
	return NULL; //O pthread_exit(NULL)
}

int main()
{
	int x = 0, y = 0;
	//Declaración de una hebra
	pthread_t inc_x_thread;

	printf("x: %d, y: %d\n", x, y);

	//Creación de la hebra
	if(pthread_create(&inc_x_thread, NULL, (void *) inc_x, (void*) &x)) 
	{
	  fprintf(stderr, "Error creating thread\n");
	  exit(EXIT_FAILURE); 
	}

	//Incremetar y hasta 100
	while(++y < 100);

	printf("Incremento de y finalizado...\n");

	//Espera de la hebra
	if(pthread_join(inc_x_thread, NULL)) 
	{
	  fprintf(stderr, "Error joining thread\n");
	  exit(EXIT_FAILURE);  
	}

	printf("x: %d, y: %d\n", x, y);
	exit(EXIT_SUCCESS);
}
