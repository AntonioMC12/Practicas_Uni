#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


void main(void)
{
	pid_t pid, childpid;
	int status;
	pid = fork();
	switch(pid)
	{
		case -1: /* error del fork() */
			perror("fork error");
			printf("errno value= %d\n", errno);
			exit(EXIT_FAILURE);

		case 0: /* proceso hijo */
			printf("Proceso hijo %d; padre = %d \n", getpid(), getppid());
			if(execlp("ls","ls","-l",NULL)==-1)
			{
				perror("Falla en la ejecucion exec de ls -l");
				printf("errno value= %d\n", errno);
				exit(EXIT_FAILURE);
			}
	
		default: /* padre */
		  printf("padre con pid: %ld\n", (long)getpid());

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
	//La ejecutará en este caso solo el padre, el hijo tiene una 	llamada a exec()
	printf("Fin del programa. PID del que ejecuta esta linea: %ld\n", (long)getpid());
	exit(EXIT_SUCCESS);
}
