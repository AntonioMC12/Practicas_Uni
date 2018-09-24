/* -----------------------------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 8: Argumentos en línea de órdenes

  Ejercicio: Programa que recibe 3 argumentos (operación y dos numeros).
             El programa realizará la operación indicada con los
             dos numeros
 --------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
float num1, num2, res;
   int opcion;

   //Comprobar que el número de parámetro sea 
   //correcto
   if (argc !=4){
      printf("Sintaxis incorrecta: \n");
      printf("%s operacion num1, num2\n",argv[0]);
      printf(" Suma -> operación = 0\n");
      printf(" Producto -> operación = 1\n");
      exit(-1);
   }
   opcion = atoi(argv[1]);

//Comprobamos que se haya introducido una opción correcta
   if ((opcion !=0) && (opcion !=1)){
      printf("Opcion incorrecta: 0(suma) \n 1 (producto)\n");
      exit(-1);
   }
  
   //Convertimos los números
   num1 = atof(argv[2]);   
   num2 = atof(argv[3]);

   if (opcion ==0) 
      res = num1+num2;
   else 
      res = num1*num2;

   printf("El resultado de %s %f y %f es %f\n",
          opcion==0?"sumar":"multiplicar", num1, 
          num2, res);
   
   return(0);
} 
