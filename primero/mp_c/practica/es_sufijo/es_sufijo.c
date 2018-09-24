#include <stdio.h>
#include <string.h>

int es_sufijo(char *cadena, char *sufijo){
  if( strstr(*cadena, *sufijo) == NULL ){
    return 0;
  }
  else{
    int sizesuf = strlen(sufijo);
    int sizecad = strlen(cadena);
    for( ; sizesuf >= 0 ; sizecad-- , sizesuf--){
        if(sufijo[sizesuf]== cadena[sizecad]){
        }
        else{
          return 0;
        }
    }
    return 1;
  }
}

int main(){
  char cadena[] = "chiquito";
  char sufijo[] = "ito";
  printf("Introduzca la cadena donde desea buscar:\n");
  /*scanf("%c\n", &cadena );*/
  printf("Introduzca su sufijo o prefijo a localizar:\n");
  /*scanf("%c\n", &sufijo );*/

  if(es_sufijo == 1){
    printf("%c es sufijo de la cadena %c\n",sufijo,cadena );
  }
  else{
    printf("%c no es sufijo de la cadena %c\n", sufijo,cadena);
  }
  return 0;
}
