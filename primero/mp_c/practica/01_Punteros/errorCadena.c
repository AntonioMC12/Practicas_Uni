#include <string.h>
int main ()
{
  char cad[] = "abcde";
  char* ptr = cad;
  //error en tiempo de ejecucion, sobrepasamos el espacio reservado para cad
  strcpy(ptr,"Hasta luego, encantada de conocerte");
}
