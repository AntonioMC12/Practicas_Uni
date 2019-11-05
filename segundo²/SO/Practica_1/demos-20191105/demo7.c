#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*Pruebe por ejemplo: 
./a.out tar -cf prueba.tar demo1 demo2 demoN 
donde file1 hasta fileN son ficheros que desea comprimir en el fichero prueba.tar
-Pruébelo también sin usar nada en la linea de argumentos.
-Por ultimo pruébelo usando un "file1" que no exista.
*/

int main(int argc, char **argv) 
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
			if (execvp(argv[1], &argv[1])<0) //Exec devuelve -1 en caso de error 
			{
			   	perror("exec");
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
	printf("Programa finalizado, compruebe el contenido de su fichero .tar\n");
	exit(EXIT_SUCCESS);
}
