#include <stdio.h>
void main()
{
  int* ptr[10]; 
  int vector[10];
  int i;
  
  //Inicializar contenido;
  for (i=0; i<10; i++)
  {
    //Inicializar vector de enteros
    vector[i]=i;
    //Inicializar vector de punteros
    ptr[i]=&vector[i];
    *(ptr[i])=vector[i];
    //Imprimir
    printf("\n*(ptr[%d]): %d", i, *(ptr[i]));
  } 

}