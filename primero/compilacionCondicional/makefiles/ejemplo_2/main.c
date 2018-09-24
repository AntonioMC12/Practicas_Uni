/* ---------------------
   Programa principal
   ---------------------*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "vector.h"
#include "orden.h"

#define MAX 15
int main(){
  int m[MAX];

  srand(time(NULL));

  //Rellenamos completamente el vector m
  llena_vector(m,MAX);

  //Muestra el vector
  printf("\n\n Vector original (Antes de ordenar):   ");
  pinta_vector(m,MAX);

  // Ordena el vector m
  ordena_vector(m,MAX);

  //Muestra el vector m después de ordenarlo */
  printf("Vector final (Depués de ordenarlo): ");
  pinta_vector(m,MAX);

  return(0);
}
