#include <stdio.h>
#include <string.h>

FILE* openfichero(char* fichero){

FILE* f = fopen(fichero, 'r');

  if( f == NULL){
    printf("Error abriendo el fichero\n");
    exit(-1);
  }
  else{
    return f;
  }
}

void scantxt(char* fichero, libros *datos){

  FILE* f = openfichero(fichero);
  libros aux;
  



  }


}
