#include <stdio.h>
#include <string.h>

FILE* openfichero(char* fichero);
void scantxt(FILE* fichero, libros datos);



typedef struct DatosFichero{

  char titulo[100];
  char autor[100];
  float precio;
  int unidades;

}libros;
