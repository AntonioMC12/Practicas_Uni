/* -------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 8: Argumentos en línea de órdenes

  Ejercicio: Lectura de un fichero de enteros
 --------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
   FILE * f;
   int n;

   //Comprobar que el número de parámetro sea correcto
   if (argc !=2){
      printf("Sintaxis incorrecta: %s <fichero>\n", argv[0]);
      exit(-1);
   }

   f = fopen(argv[1],"r");
   if (f==NULL){
     printf("Error al abrir el fichero %s\n",argv[1]);
     exit(-1);
   }

   fscanf(f,"%d",&n);
   while(!feof(f)) {
      printf("%d\n",n);
      fscanf(f,"%d",&n);
   }
   
   fclose (f);
   
   return(0);
}
