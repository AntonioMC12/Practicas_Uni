#include <stdio.h>
#include <stdlib.h>

//Tenemos que hacer una funcion que compare parametros.
int compare(int a, int b){
  if( a < b){
    return a;
  }
    else{
      return b;
    }
}

int compare_reference(int a, int b, int* res){
  if(a < b){
    *res = a;
  }
  else{
    *res = b;
  }
}

int main(){
  int a ;
  int b ;
  int res;

  printf("Introduce el valor del primer numero\n");
  scanf("%d",&a);

  printf("Introduce el valor del segundo numero\n");
  scanf("%d",&b);

  printf("--Pasado por valor--\n %d \n",compare(a,b) );
  printf("---------------------\n");
  printf("--Pasando por referencia\n",compare_reference(a,b,&res) );
  printf("--El minimo es %d\n",res );

}
