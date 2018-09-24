#include <string.h>
#include <stdio.h>
int main()
{
   char ptr[]="Hola";
   
   printf("\n<%s>", ptr);
   strcpy(ptr, "Adios");
   printf("\n<%s>", ptr);
}