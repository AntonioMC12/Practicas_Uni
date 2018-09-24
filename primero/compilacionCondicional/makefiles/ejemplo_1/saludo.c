#include <stdio.h>

int main(){
   char nombre[256];

   printf("Hola como te llamas: ");
   scanf("%s",nombre);
   printf("%s --> bienvenid@ a la historia de los makefiles\n", nombre);

   return 0;
}
