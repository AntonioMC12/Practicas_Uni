#include <errno.h>
#include <stdio.h> 
#include <string.h>

/**
PROGRAMA DE PRUEBA PARA COMPROBAR EL TRATAMIENTO DE ERRORES EN C

perror() y stderror() son funciones similares, se mantienen ambas porque
hay sistemas que pueden que no implementen stderror()
**/

int main ()
{
FILE * pf;
//int errnum;
pf = fopen ("prueba.txt", "rb");
if (pf == NULL)
{
	//errnum = errno;
   perror("Texto propio seguido del tipo de error");	
   printf("Valor entero de variable errno: %d\n", errno);
	printf("Significado del tipo de error guardado en errno: %s\n", strerror(errno));
}
else
	fclose (pf);

return 0;
}

