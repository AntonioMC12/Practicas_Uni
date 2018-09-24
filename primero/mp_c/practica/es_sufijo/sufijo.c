#include <stdio.h>
#include "funcion.h"

int main(int argc, char const *argv[]){
  char* a = "PatuPePe";
  char* b = "Pe";

  int resultado = es_sufijo(a, b);

  printf("%d\n",resultado );

  return 0;
}
