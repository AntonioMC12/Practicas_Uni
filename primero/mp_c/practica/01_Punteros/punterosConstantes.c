#include <stdio.h>
void main()
{
  int y;
  //Puntero constante
  int x;
  int* const p =&x;
  
  //Puntero a constante
  const int x1=25;
  const int* p1=&x;
  
  //Puntero constante a constante
  const int x2=25;
  const int* const p2=&x;

  //p=&y; warning: p es constante, no podemos cambiar su valor
  *p=30; //Si podemos cambiar *p
  
  //*p1=30;warning: *p1 es constante, no podemos cambiar su valor
  p1=&y; //Si podemos cambiar p1
  
  //*p2=30; warning: *p2 es constante, no podemos cambiar su valor;
  //p2=&y;  warning: p2 es constante, no podemos cambiar su valor; 
  
}