#include <stdio.h>
#include <string.h>


buscarlibro(FILE* fichero, char* titulo){
  char aux[100];
  while(feof(fichero) == NULL){
    fgets(aux,100,fichero);
    if(aux == titulo){
      printf("Encontrado\n");
    }
    else{
      printf("No encontrado\n");
    }
  }
}

addirlibro(FILE* fichero, libro *datos){

  FILE *pFichero;
  pFichero = fopen(fichero, "a");
  fprintf(pFichero, "%s %s %d %d\n", datos.titulo, datos.autor,
     datos.precio, datos.unidades);

  fclose(pFichero);
}

FILE* abrirfichero(char* fichero){
  FILE* file;
  file = fopen(fichero,file);
  if(file == NULL){
    printf("Fallo al abrir al fichero\n");
    exit(-1);
  }
  return file;
}

contlibros(char *fichero){
  FILE *pFichero;
  int nRegistros=0;
  libros datos;

  pFichero = fopen(fichero, "r"); /* abre fichero paa lectura */
  /* Comienza a leer datos del fichero hasta que llega al final */
  //Hacer con getline.
  while ( fscanf(pFichero, "%s %s %d %d" , datos.titulo, datos.autor,&datos.precio, &datos.unidades) != EOF ){

   nRegistros++;
 }
 nRegistros = nRegistros/3;
 fclose(pFichero);
 return(nRegistros);
}

void lee(char* nombreFichero)
{
   FILE* fich;
   char cadena[30];

   fich=fopen(nombreFichero, "r");
   while(fgets(cadena, 30, fich)!=NULL)
   {
     if(cadena[strlen(cadena)-1]=='\n')
       cadena[strlen(cadena)-1]='\0';
     printf("\ntitulo: <%s>\n", cadena);

     fgets(cadena, 30, fich);
     if(cadena[strlen(cadena)-1]=='\n')
       cadena[strlen(cadena)-1]='\0';
     printf("\nAutor: <%s>\n", cadena);

     fgets(cadena, 30, fich);
     if(cadena[strlen(cadena)-1]=='\n')
       cadena[strlen(cadena)-1]='\0';
     printf("\nPrecio y unidades: <%s>\n", cadena);

   }
   fclose(fich);

}

void escribirRegristros(libros aux){
 printf("  Titulo: %s  Autor: %s  Precio: %d  Unidades: %d \n",
         aux.titulo, aux.autor, aux.precio, aux.unidades);
}
