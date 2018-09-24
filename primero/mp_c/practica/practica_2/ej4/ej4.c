#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define Filas 3
#define Columnas 5

int main(void) {
int **matriz;
int nFil = 3;
int nCol = 3;

//reservarMemoria(nFil,nCol);

rellenaMatriz(matriz, nFil, nCol);

imprimeMatriz(matriz, nFil, nCol);

//minCol(**matriz, nFil, nCol);

//liberarMemoria(matriz, nFil);

  return 0;
}
