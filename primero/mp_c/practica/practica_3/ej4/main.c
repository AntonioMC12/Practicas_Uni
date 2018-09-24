#include <stdio.h>
#include <string.h>

int findchar(int cont,int nveces,char *pcadena, char *letra){

//declaramos la condición incial...
//Al final de un char viene un "/n", por tanto...

  if (pcadena[cont] == '\n')
    return nveces;

//Ahora hacemos la funcion para encontrar el caracter.

  else{
//Si encuentra el caracter, sumamos contador y numero de veces que aparece "letra".
    if(pcadena[cont] == *letra){
      cont++;
      nveces++;
      return findchar(cont,nveces,pcadena,letra);//Retornamos la funcion (recursividad).
    }
//Si no encontramos el caracter, sumamos contador.
    else{
      cont++;
      return findchar(cont,nveces,pcadena,letra);//Retornamos la funcion (recursividad).
    }
  }
}


int main(){
//iniciamos las cadenas.
  char pcadena[50];
  char letra[2];
//iniciamos los contadores a 0.
  int cont = 0, nveces = 0;

  printf("Introduzca la cadena\n");
  fgets(pcadena, 50, stdin);
  printf("Introduzca el caracter a buscar\n");
  scanf("%s",letra);
  nveces = findchar(cont,nveces,pcadena,letra);
  printf("El numero de veces que se repite < %s > en la cadena es: %d\n",letra,nveces );
}
