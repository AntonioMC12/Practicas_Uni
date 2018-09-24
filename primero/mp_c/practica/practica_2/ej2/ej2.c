#include <stdio.h>
#include "funciones.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int num = 5;
  int longi = 10;

  int* vector;
  vector = (int *) calloc(10,sizeof(int));
  int **vmax;
  vmax = (int **) calloc(10,sizeof(int*));
  int **vmin;
  vmin = (int **) calloc(10,sizeof(int*));


    if (vector==NULL)
    {
        printf("Problemas reservando memoria");
        exit (1);
    }
  printf("imprimimos el vector\n");
  randomnum(vector, longi);
  draw_vector(vector, 10);
  returnvectores(vector, longi, num);

  draw_vector(vmin,10);
  draw_vector(vmax,10);

  free(vector);
  free(vmax);
  free(vmin);

  return 0;
}
