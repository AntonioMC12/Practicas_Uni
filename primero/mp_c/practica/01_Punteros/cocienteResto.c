#include <stdio.h>

int CocienteEntero (int divdo, int divsor) {
  return divdo / divsor;
}


int RestoEntero (int divdo, int divsor) {
  return divdo % divsor;
}


void Division (int dividendo, int divisor, int *c, int *r) {
  *c = CocienteEntero (dividendo, divisor);
  *r = RestoEntero (dividendo, divisor);
}


int main()
{
  int a,b,z,w;

  a = 6;
  b = 3;
  Division(a, b, &z, &w);
  printf("%i entre %i = %i\n",a,b,z); 
  printf("y el resto es %i",w);
  return 0;
}




