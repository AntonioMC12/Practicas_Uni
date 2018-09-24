#include <stdio.h>

int es_sufijo(char* cadena, char* sufijo){
  char* aux = cadena;
  int lenght = strlen(sufijo);
  char* end = cadena+strlen(cadena);
  //este puntero nos apunta al final de la cadena, para mas tarde trabaja con ello
  char* ptr;
  //como la misma cadena de sufijo puede repetirse dentro de lal cadena principal
  //hacemos un while por si se repite y no es el ultimo elemento de la cadena

  while(aux<=(end-lenght)){
    ptr = strstr(aux, sufijo);
    // con esto mandamos un puntero a donde localizamos la cadena sufijo dentro de la cadena principal
    // si le restamos la longitud del sufijo y nos da el resultado de ptr, es un sufijo.
    if( ptr == (end - lenght)){
      return 1;
    }
    //para que si el puntero es nulo, lo descarte directamente...
    if( ptr == NULL ){
      return 0;
    }
    // por si detecta una cadena igual, hacemos que salte a la siguiente cadena
    aux = ptr + lenght;
  }
  return 0;

}
