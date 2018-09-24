/* ---------------------------------------------------------
   Fichero: vec_ES.c
   Definición de las funciones de E/S de vectores
   usadas por "main()" y de las constantes locales
   MAX_LINE y MY_MAX_RAND
   Los prototipos estan declarados en el fichero vec_ES.h
   --------------------------------------------------------*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "vector.h"

#define MY_MAX_RAND 12

/* ------------------------------------------------
   Funcion: Llena vector
   Rellena un vector de enteros con numeros
   aleatorios.
   Recibe: p -> vector a rellenar
           tope -> numero de elementos del vector
   Devuelve: el vector con tope numeros aleatorios
   -----------------------------------------------*/
void llena_vector(int * p, int tope){
  int i;

  for (i=0;i<tope;i++){
    p[i]=rand()%MY_MAX_RAND;
  }
}


/* ------------------------------------------------
   Funcion: pinta_vector
   Muestra (tabulado), un vector con MAX_LINE
   números por línea
   Recibe: p -> vector a mostrar
           tope -> numero de elementos del vector
   Devuelve: nada
   -----------------------------------------------*/
void pinta_vector(int * p, int tope){
  int i;
  
  printf("\n\n");
  
  for (i=0;i<tope;i++){
    printf("%5d%c",p[i], (((i+1)%MAX_LINE) == 0 || i == tope -1) ? '\n':' ');
  }

  printf("\n\n\n");
}
