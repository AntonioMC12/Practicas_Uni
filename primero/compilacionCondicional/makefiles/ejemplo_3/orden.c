/* -----------------------------------
   Fichero: ordena.c
   Contiene la definición de la función
    de ordenación (burbuja) y de la
    funcion swap
   -----------------------------------*/

#include "orden.h"

/* --------------------------------------------------
   Funcion: ordena_vector
   Ordena un vector de forma ascendente (burbuja)
   Recibe: p -> vector a ordenar
           tope -> numero de elementos del vector
   Devuelve: el vector p ordenado
   -------------------------------------------------*/
void ordena_vector(int * p, int tope){
  int i,j;
  
  for (i=0;i<tope-1;i++){
    for  (j=0;j<tope-1;j++){
      if (p[j] >p[j+1]){
	swap(&p[j],&p[j+1]);
      }
    }
  }
    
}


/* --------------------------------------------------
   Función: swap
   Intercambia los valores de dos variables enteras
   Recibe: a,b -> valore  a intercambiar (referencia)
   Devuelve: valores intercambiados
   --------------------------------------------------*/
void swap (int *a, int * b){
  int tmp;

  tmp=*a;
  *a = *b;
  *b = tmp;
}
