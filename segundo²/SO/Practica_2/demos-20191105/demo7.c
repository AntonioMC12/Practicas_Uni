#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//Prototipos
void * message_print (void *);

int main(void)
{
   int error = 0;
   char mess[] = "Esto es una prueba...";
   pthread_t thr;
   void *ret;
   long aux = 7;

   ret = &aux;

   error = pthread_create( &thr, NULL, message_print, (void  *) mess);
   /* Manejar el error */
   //...

   printf("Soy el main():%s\n", mess);

   /*
Si el join se ejecuta una vez haya terminado la hebra detach, dará un error y el valor de retorno será 7, pues ya se habrá liberado el estado, variables y demás, de la hebra detach; en caso contrario si el join se ejecuta antes de que termine la hebra detach, el join no dará error y devolverá el valor 10. De ahí que no se deba utilizar el join con una hebra detach para evitar inconsistencias. */
   error=pthread_join(thr,(void **) &ret);
   //Si la hebra ya ha terminado recibirá este error, ya que su estado se ha liberado porque invocó previamente a detach
   if(error!=0)
      printf("Se ha producido un error en pthread_join()\n");

   printf("Soy el main(), valor de retorno de la hebra: %ld\n",*(long *)ret);
   pthread_exit(NULL);
}

void * message_print (void * ptr)
{
   long * y = malloc(sizeof(long));
   *y = 10;
   int error = 0;
   char *msg;

   /* Desconexión del hilo cuando finalice.
	   pthread_self() devuelve el ID de la hebra que invoca esta función.*/
   error = pthread_detach(pthread_self());
   if(error!=0)
       printf("Se ha producido un error en pthread_detach()\n");
   // Complételo con las macros de error convenientes
   //...

   msg = (char *) ptr;
   printf("Soy la hebra: %s\n", msg);
   pthread_exit((void *)y);
}
