#include <stdio.h>

void incremento(int *n)
{
   *n = *n +1;
}

void B(int *vb)
{
   *vb = *vb * 5;
}



void A(int *va)
{
   *va = *va + 1;
   B(va);
}



int main()
{
   int h;
   int valor = 5;
   
   incremento(&valor);
   printf("\nincremento: %d", valor);
   
   h = 5;
   A(&h);
   printf("\nA(h): %i", h);
   return 0;
}
    