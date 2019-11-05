#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h>
#include <sys/wait.h>

int main () 
{
	 int i, j, status; 
	 pid_t rf, childpid;
	 
	 rf = fork(); 
	 switch (rf) 
	 {
		  case -1:
		      perror("fork error");
		      printf("errno value= %d\n", errno); 
		      exit(EXIT_FAILURE);

		  case 0:
		      i = 0;
		      printf("Soy el hijo, mi PID es %d y mi variable i (inicialmente a %d) es par.\n",getpid( ),i);
				for (j=0; j<5; j++)
		      {
		          i++;
		          i++;
		          printf ("Soy el hijo, mi variable i es %d\n", i);
		      }
		      break; 

			default:
		      i = 1;
		      printf("Soy el padre, mi PID es %d y mi variable i (inicialmente a %d) es impar.\n", getpid( ), i);
		      for (j=0; j<5; j++) 
				{
		          i++;
		          i++;
		          printf ("Soy el padre, mi variable i es %d\n", i);
		      }
		      
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
	 //Esta linea la ejecuta tanto el padre como el hijo 
	printf ("Final de ejecucion...\n"); 
	exit(EXIT_SUCCESS);
}
