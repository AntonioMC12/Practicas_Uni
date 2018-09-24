#ifndef _MATRICES_H_
#define _METRICES_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//int *minCol(int *(matriz)[5], int nFil, int nCol);
int ** reservarMemoria(int nFil, int nCol);
void rellenaMatriz(int **matriz, int nFil, int nCol);
void imprimeMatriz(int **matriz, int nFil, int nCol);
void liberarMemoria(int **matriz, int nFil);



#endif
