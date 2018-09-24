/* -------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 8: Bibliotecas

  Ejercicio: Creación de una biblioteca
             (fichero con la funcion factorial (caso 2))
 --------------------------------------------------------*/
#include <stdio.h>
#include "operaciones.h"


/*-----------------------------------------
   Funcion que calcula el factorial de un número
   Se le pasa: a -> numero
   Devuelve: el factorial de a
  ---------------------------------------*/
int factorial(int a){
  if (a == 0) 
     return 1;
  else 
     return(a*factorial(a-1));
}
