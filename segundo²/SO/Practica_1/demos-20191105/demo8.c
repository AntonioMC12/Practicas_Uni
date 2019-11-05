#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 

int main()
{

    pid_t idProceso, childpid;
    int status;
    /* Variable para comprobar que se copia inicialmente en cada proceso y
	 que luego puede cambiarse independientemente en cada uno de ellos. */
    int variable = 1;

    idProceso = fork();
    if (idProceso == -1)
    {
		perror("fork error");
		printf("errno value= %d\n", errno); 
		exit(EXIT_FAILURE);
    }
    else if (idProceso == 0)
    {
		/* El hijo escribe su pid en pantalla y el valor de variable */
		printf ("Hijo : Mi pid es %d. El pid de mi padre es %d\n", getpid(), getppid());
		/* Escribe valor de variable y la cambia */
		printf ("Hijo : variable = %d. La cambio por variable = 2\n", variable); 
		variable = 2;
		/* Espera 5 segundos, saca en pantalla el valor de variable y sale */ 
		sleep (5);
		printf ("Hijo : variable = %d y salgo\n", variable);
		exit (33);
    }
    else //Padre
    {
		/* Espera un segundo (para dar tiempo al hijo a hacer sus cosas y no entremezclar salida en la pantalla) y escribe su pid y el de su hijo */
		sleep (1);
		printf ("Padre : Mi pid es %d. El pid de mi hijo es %d\n",getpid(), idProceso);

		childpid=wait(&status); 
		if(childpid>0)
		{
		 	if (WIFEXITED(status)) 
			{
				  printf("child %d exited, status=%d\n",childpid, WEXITSTATUS(status));
			} 
			else if (WIFSIGNALED(status)) 
			{
				  printf("child %d killed (signal %d)\n", childpid, WTERMSIG(status));
			} 
			else if (WIFSTOPPED(status)) 
			{
				  printf("child %d stopped (signal %d)\n", childpid, WSTOPSIG(status));
			} 
		}
		else 
		{
			 printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
			 exit(EXIT_FAILURE);
		} 
    }
	 exit(EXIT_SUCCESS);
}
