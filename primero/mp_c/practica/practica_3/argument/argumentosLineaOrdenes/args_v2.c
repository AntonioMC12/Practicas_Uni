/* -------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 8: Argumentos en línea de órdenes

  Ejercicio: Imprime por pantalla el número de argumentos
              y el nombre de los argumentos (no cuenta el 
              nombre del programa).
 --------------------------------------------------------*/
#include <stdio.h>

int main(int argc, char ** argv) {
   //int main(int argc, char * argv[])
   int i;
   printf("Número de argumentos (sin incluir el nombre del programa)= %d \n", argc-1);

   printf("Argumentos,sin incluir el programa: \n");
   for (i=1;i<argc;i++){
      printf("Argumento[%d] = %s\n",i,argv[i]);
   }

   return(0);
}
