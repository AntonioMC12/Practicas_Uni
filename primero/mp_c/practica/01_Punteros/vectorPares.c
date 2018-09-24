/*Lee desde teclado el numero de componentes
  utiles y los valores de un vector y crea otro
  vector con las componentes del primero que sean
  pares
*/
#include <stdio.h>
#define MAX_ELE 6

void lecturaVector(int Vector[], int* utiles)
{
   int i;
   
   printf("Introduzca el numero de componentes: ");
   scanf("%d", utiles);
   
   for(i=0; i<*utiles; i++)
   {
      printf("Posicion [%d]: ", i);
      scanf("%d", &Vector[i]);
   }  
   
}

void lecturaVectorPtr(int * Vector, int* utiles)
{
   int* ptr, *ptrFinal;
   int i;
   
   printf("Introduzca el numero de componentes: ");
   scanf("%d", utiles);
   ptrFinal=Vector+(*utiles)-1;
   
   for(ptr=Vector; ptr<=ptrFinal; ptr++)
   {
      printf("Posicion [%d]: ", ptr-Vector);
      scanf("%d", ptr);
   }  
   
}

void pintaVector(int Vector[], int utiles)
{
   int i;
   for(i=0; i<utiles; i++)
   {
     printf("\nElemento[%d]: %d", i, Vector[i]);
   }	
}

void eliminaPares(int VectorOrigen[], int VectorDestino[], int utilesOrigen, int* utilesDestino)
{
   int i;
   *utilesDestino = 0;
   for(i=0; i<utilesOrigen; i++)
   {
      if((VectorOrigen[i]%2)!=0)
      {
      	VectorDestino[*utilesDestino]=VectorOrigen[i];
      	(*utilesDestino)++;   
      }
   }
}

int eliminaPares2(int VectorOrigen[], int VectorDestino[], int utilesOrigen)
{
   int i, utilesDestino=0;
   
   for (i=0; i<utilesOrigen; i++)
   {
      if((VectorOrigen[i]%2)!=0)
      {
        VectorDestino[utilesDestino]=VectorOrigen[i];
        utilesDestino++;
      }
   }
   return(utilesDestino);   	
} 

void main()
{
   int Vector[MAX_ELE];
   int VectorPares[MAX_ELE];
   
   int utiles, utilesPares;
   	
   //lecturaVector(Vector, &utiles);	
   lecturaVectorPtr(Vector, &utiles);	
   printf("\nVector con pares: ");
   pintaVector(Vector, utiles);
   //eliminaPares(Vector, VectorPares, utiles, &utilesPares);
   utilesPares= eliminaPares2(Vector, VectorPares, utiles);
   printf("\nVector sin pares: ");     
   pintaVector(VectorPares, utilesPares);

}