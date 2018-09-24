#ifndef _FUNCIONES_
#define _FUNCIONES_



abrirfichero(char* fichero);
buscarlibro(FILE* fichero, char* titulo);
addlibro(FILE* fichero, libro *libros);

typedef struct DatosLibro{
  char titulo[15];
  char autor[15];
  int precio;
  int unidades;
}libro;

#endif
