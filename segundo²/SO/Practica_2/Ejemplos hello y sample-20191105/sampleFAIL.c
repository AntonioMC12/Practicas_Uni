/*
Programa que imprime un supuesto valor devuelto por una hebra y asignado a un long en el hijo principal.
Observe la salida y saque las conclusiones oportunas.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * th (void *arg)
{
     long y = 10;
	  /*Tenemos que devolver un puntero, es decir, una direccion de memoria a un tipo de dato,
	  y castearla a void * */
     pthread_exit((void *)&y); 
}

int main(int argn, char ** argp)
{
	int s;
	long nm;
	long *ret; //No inicializado, continene basura
	pthread_t thread;

	pthread_create(&thread, NULL, th, NULL);

	//Recogemos el resultado devuelto por  pthread_exit() en ret.
	s=pthread_join(thread,(void**) &ret);      
	if(s!=0)
	{
	  perror("Fallo en el join...\n");		
	  exit(EXIT_FAILURE);
	}

	nm = *(long *)ret; 
	printf("Imprimiendo basura:%ld\n", nm);
	  
	exit(EXIT_SUCCESS);
}
