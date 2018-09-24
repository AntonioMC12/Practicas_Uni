#include <stdio.h>
#define TOPE 30

int main()
{
   char cadena[TOPE] = "Hola";
   int longitud;
   char* ptr;
   
   /*Primera version, con indices*/
   for(longitud=0; cadena[longitud]!='\0'; longitud++);
   //No hacemos nada, solo nos interesa
   //incrementar el valor de longitud
      
   printf("\nLongitud (primera version): %d", longitud);
   
   /*Segunda version, con un puntero para recorrer el vector*/
   for(ptr=cadena; *ptr!='\0'; ptr++);
   printf("\nLongitud (segunda version): %d", ptr-cadena);  
      
   return (0);
   	
}
