#include <stdio.h>

int main(){
   char name[256];

   printf("Hi, what's your name: ");
   scanf("%s",name);
   printf("%s welcome to makefile lecture\n", name);

   return 0;
}
