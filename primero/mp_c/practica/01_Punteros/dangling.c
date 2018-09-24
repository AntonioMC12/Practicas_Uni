#include <stdio.h>
char * f1()
{ //Reserva de memoria estatica para variable local
   char buffer[128]; 
   printf("\nEscriba su nombre: ");
   scanf("%s", buffer);
   //Retorna como puntero de variable local
   return buffer;
}

int main()
{  char* ptr;
   //El puntero ptr recibe la direccion de 'buffer'
   ptr = f1();   
   printfr("\n<%s>", ptr);
}