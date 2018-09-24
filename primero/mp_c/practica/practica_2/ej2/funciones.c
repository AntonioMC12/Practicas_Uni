#include <stdio.h>
#include "funciones.h"
#include <time.h>
#include <stdlib.h>

//esta funcion distribuye las cifras de los vectores en vector1 y vector2
void returnvectores(int *vector, int longi,int  num){
  //int* vmin;
  //int* vmax;  

  for(int i = 0, j = 0 ; i < longi ; i++){
    if (*(vector + i) < num) {
      *(vmin + j) = *(vector + i);
      j++;
    }
  }

  for(int i = 0, j = 0 ; i < longi ; i++){
    if (*(vector + i) > num) {
      *(vmax + j) = *(vector + i);
      j++;
    }
  }
}

//funcion para imprimir el vector
int draw_vector(int *vector,int  longi){
  for(int i = 0 ; i < longi ; i++ ){
    printf("%d ",vector[i] );
  }
  printf("\n \n");

}
int randomnum(int *vector,int max){
//hacemos una funcion para llenar el vector con 20 numeros
  srand (time(NULL));
  for (int i=0; i < max ; i++) {
    *(vector + i) = rand()%23;
  }
}
