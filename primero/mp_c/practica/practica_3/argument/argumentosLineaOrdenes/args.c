/* -------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 8: Argumentos en línea de órdenes

  Ejercicio: Imprime por pantalla el número de argumentos
              y el el nombre del programa y los argumentos
 --------------------------------------------------------*/
#include <stdio.h>

int main(int argc, char ** argv) {
   //int main(int argc, char * argv[])
   int i;
   printf("Número de argumentos (incluido el nombre del programa)= %d \n", argc);

   printf("Argumentos,incluido el programa: \n");
   for (i=0;i<argc;i++){
      printf("Argumento[%d] = %s\n",i,argv[i]);
   }

   return(0);
}
