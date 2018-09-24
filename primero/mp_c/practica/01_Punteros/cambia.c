#include <stdio.h>

void cambiaMal(char a,char b)
{
   char aux;
  
   printf("\nDentro antes: a=%d b=%d", a,b);

   aux = a;
   a = b;
   b = aux;
   printf("\nDentro despues: a=%d b=%d", a,b);
}

void cambiaBien(char *a, char *b)
{
   char aux;
   aux = *a;
   *a = *b;
   *b = aux;
}


int main()
{
   char x=0, y=1;

   printf("\ncambiaMal : x=%d  y=%d => ", x, y);
   cambiaMal(x,y);
   printf("\nx=%d  y=%d", x, y);
  
   printf("\ncambiaBien: x=%d  y=%d => ", x, y);
   cambiaBien(&x,&y);
   printf("\nx=%d  y=%d", x, y); 
  
   return 0;
}
