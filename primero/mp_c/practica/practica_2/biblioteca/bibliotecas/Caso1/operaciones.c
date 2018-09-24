/* -------------------------------------------------------
  Códigos de los ejemplos de las transparencias
  y de los vistos en clase
  
  Tema 8: Bibliotecas

  Ejercicio: Creación de una biblioteca
             (fichero con las funciones (caso 1))
 --------------------------------------------------------*/
#include <stdio.h>
#include "operaciones.h"

/* ------------------------------------
   Funcion que resta dos numeros
   Se le pasa:a,b -> numeros a restar
   Devuelve:la resta de los dos numeros
   -----------------------------------*/
int resta(int a, int b){
  return (a+b);
}

/* ------------------------------------
   Funcion que suma dos numeros
   Se le pasa:a,b -> numeros a sumar
   Devuelve:la suma de los dos numeros
   -----------------------------------*/
int suma(int a, int b){
  return (a+b);
}

/* ----------------------------------------
   Funcion que multiplica dos numeros
   Se le pasa:a,b -> numeros a multiplicar
   Devuelve:el producto de los dos numeros
   ----------------------------------------*/
int producto(int a, int b){
  return (a*b);
}

/* ----------------------------------------
   Funcion que divide dos numeros
   Se le pasa:a,b -> numeros a dividir
   Devuelve:la división entera de los 2 numeros
   ----------------------------------------*/
int divisionEntera(int a, int b){
  return (a/b);
}

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
