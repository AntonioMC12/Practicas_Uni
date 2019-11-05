#include <sys/types.h> //Para tipo pid_t 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Para fork()
#include <errno.h>
#include <sys/wait.h>

int main(void) 
{
    pid_t pid, childpid;
    int status;
    
    pid = fork(); 
    switch(pid)
    {
        case -1:
            perror("fork error");
            printf("errno value= %d\n", errno);
				exit(EXIT_FAILURE); //Necesaria la librería <stdlib.h>  
            //return (-1);
            
        case 0: /* proceso hijo */
            printf("Proceso hijo %d; mi padre = %d \n", getpid(), getppid()); 
            exit(EXIT_SUCCESS);
            
        default: /* padre */
            printf("Proceso padre %d; mi padre = %d \n", getpid(), getppid());
				/*Averigue quien es el padre del proceso padre*/

				//Se espera al hijo
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
            exit(EXIT_SUCCESS); //return 0;
    }
}
