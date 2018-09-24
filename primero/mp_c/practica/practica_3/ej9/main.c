#include <stdio.h>

int main(void){

 int opcion;
 char titulo[50];
 
 do
 {
   printf("********************************************************\n");
   printf("** 1.  Buscar libro por su nombre. *********************\n");
   printf("** 2.  Añadir libro.               *********************\n");
   printf("** 3.  Ver numero de libros.       *********************\n");
   printf("** 4.  Listar libros.              *********************\n");
   printf("** 5.  Vender libro                *********************\n");
   printf("** 6.  Borrar Libros sin stock     *********************\n");
   printf("** 7.  Salir                       *********************\n");
   printf("********************************************************\n");
   printf(" \n Introduzca una opcion: ");
   scanf("%d", &opcion);
 }while((opcion<0)||(opcion>7));
 return opcion;
}

if (opcion == 1) {
  printf("Introduzca el nombre del libro a buscar\n");
  scanf("%s", titulo );
  buscarlibro(fichero,titulo);
}

if (opcion == 2) {
  addlibro();
}

if (opcion == 3) {
  contlibros();
}
