/*-------------------------------------------------------------------*/
//DISTINTAS FORMAS DE SUMAR LOS ELEMENTOS DE UN VECTOR
/*-------------------------------------------------------------------*/

#include <stdio.h>
#define Dim 5

void main()
{
  int i, suma;
  int* ptr, *ptrfin;
  int V[Dim]={1, 2, 3, 4, 5};
  
  /*------------------------------*/
  suma=0;
  for(i=0; i<Dim; i++)
  {
    suma = suma+V[i];
  }
  printf("1. Resultado para suma=suma+V[i]:%d\n", suma);

  /*------------------------------*/
  suma=0;
  for(i=0; i<Dim; i++)
  {
    suma = suma+(*(V+i));
  }
  printf("2. Resultado para suma = suma+(*(V+i)):%d\n", suma);

  /*------------------------------*/
  suma=0;
  ptr=V;
  for(i=0; i<Dim; i++)
  {
    suma = suma+ptr[i];
  }
  printf("3. Resultado para suma = suma+ptr[i]:%d\n", suma);

  /*------------------------------*/
  suma=0;
  ptr=V;
  for(i=0; i<Dim; i++)
  {
    suma = suma+*ptr++;
  }
  printf("4. Resultado para suma = suma+*ptr++:%d\n", suma);

  /*------------------------------*/
  suma=0;
  ptrfin=V+Dim;
  for(ptr=V; ptr<ptrfin; ptr++)
  {
    suma = suma+*ptr;
  }
  printf("5. Resultado para suma = suma+*ptr:%d\n", suma);

 /*------------------------------*/
  suma=0;
  ptr=V;
  for(i=0; i<Dim; i++)
  {
    suma = suma+*(ptr+i);
  }
  printf("6. Resultado para suma = suma+*(ptr+i):%d\n", suma);


}
 
