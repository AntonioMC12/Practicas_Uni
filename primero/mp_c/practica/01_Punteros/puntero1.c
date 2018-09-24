#include <stdio.h>
#include <stdlib.h>

void main()
{
  char y = '5';
  char z ='3';
  char* nptr;
  char* mptr;
  
  //nptr almacena la dirección de y
  nptr=&y;
  printf("1. nptr almacena la dirección de y:\n");
  printf("\tdireccion de y:%lu\n", &y);
  printf("\tvalor de nptr :%lu\n", nptr);  
  
  //z toma el valor del objeto apuntado por nptr 
  z=*nptr;
  printf("2.z toma el valor del objeto apuntado por nptr\n");
  printf("\tvalor de z:%1c\n", z);
  printf("\t*nptr     :%1c\n", *nptr);
  
  //El valor del objeto apuntado por nptr cambia a 7
  *nptr='7';
  printf("3.El valor del objeto apuntado por nptr cambia a 7\n");
  printf("\t*nptr:%c\n", *nptr);
  
  //mptr apunta al mismo objeto al que apunta nptr
  mptr = nptr;
  printf("4.mptr apunta al mismo objeto al que apunta nptr\n");
  printf("\tmptr: %p\n", mptr);
  printf("\tnptr: %p\n", mptr);
  
  //mptr apunta al objeto z
  mptr=&z;
  printf("5.mptr apunta al objeto z\n");
  printf("\tdireccion de z:%p\n", &z);
  printf("\tmptr          :%p\n", mptr);
  
  //el contenido del objeto apuntado por mptr se sustituye
  //por el contenido del objeto apuntado por nptr  
  *mptr = *nptr;
  printf("6.el contenido del objeto apuntado por mptr se sustituye por\n");
  printf("  el contenido del objeto apuntado por nptr\n");
  printf("\t*mptr: %1c\n", *mptr);
  printf("\t*nptr: %1c\n", *nptr);
  
  //y toma el valor del contenido del objeto apuntado por mptr +1
  y=(*mptr)+1;
  printf("7.y toma el valor del contenido del objeto apuntado por mptr +1\n");
  printf("\tvalor de y: %1c\n", y);
  printf("\t(*mptr)+1 : %1c\n", (*mptr)+1); 
  
  printf("valor final de y: %1c\n", y);
  printf("valor final de z: %1c\n", z);   
  
}