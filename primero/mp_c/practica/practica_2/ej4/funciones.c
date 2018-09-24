#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** reservarMemoria(int nFil, int nCol){
  //haccemos el codigo para reservar memoria dinamica para la matriz
  int **matriz;
    matriz = (int **)malloc (nFil*sizeof(int *));

    for (int i=0;i<nFil;i++)
      matriz[i] = (int *) malloc (nCol*sizeof(int));

}

void rellenaMatriz(int **matriz, int nFil, int nCol){
  srand(time(NULL));
  for(int i = 0 ; i < nCol ; i++){
    for(int j = 0 ; j < nFil ; j++){
      matriz[i][j] = rand()%50;
    }
  }
}

void imprimeMatriz(int **matriz, int nFil, int nCol){
  for(int i = 0 ; i < nFil ; i++){
    for(int j = 0 ; j < nCol ; j++){
      printf("%d\n",matriz[i][j] );
      printf("\n");

    }
  }
}

/*int *minCol(int *(matriz)[5], int nFil, int nCol){

  int* vector = (int*)malloc(nCol*sizeof(int));
  int min;

    for (int i = 0; i < nCol ; i++){
     min = matriz[0][i];
    //min = *(matriz + i);

      for (int j = 1 ; j < nFil ; j++){
         if (matriz[i][j] < min);
        //if (*((matriz)+j) < min) {
          min = matriz[i][j];
          //min = *((matriz) + j));

        }


      vector[i] = min;
    } //*(vector + i) = min;
      return vector;
  }
*/
void liberarMemoria(int **matriz, int nFil){
  for( int i = 0 ; i < nFil ; i++){
    free (matriz[i]);
  }
}
