/* -------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 8: Argumentos en línea de órdenes

  Ejercicio: Suma de los n números pasasdos como argumento
 --------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
   int i,nEle,aux;
   int suma;

   //Comprobar que el número de parámetro sea 
   //correcto
   if (argc == 1){
      printf("No hay números que sumar\n");
      exit(-1);
   }
 
   nEle = argc;
   suma = 0;

   for (i=1; i<nEle; i++){
      //Convertimos el argumento a número
      aux = atoi(argv[i]);
      suma=suma+aux;
   }

   printf("La suma de los %d elementos es %d\n",nEle, suma);

   return 0;

}
