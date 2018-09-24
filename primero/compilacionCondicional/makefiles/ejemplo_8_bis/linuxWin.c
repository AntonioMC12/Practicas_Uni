#include <stdio.h>
#include <stdlib.h>

#ifdef _WINDOWS_
   #define Directorio "dir"
   #define Fecha "time"
   #define Limpia "cls"
#endif

#ifdef _LINUX_
   #define Directorio "ls"
   #define Fecha "date"
   #define Limpia "clear"
#endif

int main(int argc, char ** argv){
  
  system(Limpia);
  system(Directorio);
  system(Fecha);

  return 0;
}
