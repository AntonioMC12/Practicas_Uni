#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h>
#include <sys/wait.h>


int main(void) 
{
    pid_t hijo_pid, childpid; 
    int status;
    
    hijo_pid= fork(); 
    
    if (hijo_pid == -1) 
    {
        perror("fork error");
        printf("errno value= %d\n", errno); 
        exit(EXIT_FAILURE);
    }
    else if (hijo_pid == 0) //hijo
    {
        printf("hijo con pid: %ld\n", (long)getpid());
        exit(EXIT_SUCCESS); 
    }
    else /* padre */ 
    {
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
         exit(EXIT_SUCCESS); //return 0; 
    }
}
