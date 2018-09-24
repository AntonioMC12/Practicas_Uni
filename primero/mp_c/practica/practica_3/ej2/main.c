#include <stdio.h>

int aleu(int num1,int num2){

  //int mcd = 0; (antes lo tenia con esta variable, pero queda mejor sin ella.)
  //En el enunciado del ejercicio, nos daba estas condiciones.
  if(num2 == 0){
    return num1;
  }
  //En el enunciado del ejercicio, nos daba estas condiciones.
  //He sustituido la operacion mod(), por %, que viene a ser lo mismo.
  if ( num2 > 0 && num1 >= num1){
    return aleu(num2 , num1 % num2);
  }
  //return mcd; (Al quitar la variable mcd, retorno la funcion directamente)
}

int main(){

  int num1,num2,mcd;

  printf("Introduzca el primer valor\n");
  scanf("%d",&num1);
  printf("Introduzca el segundo valor\n");
  scanf("%d",&num2);

  mcd = aleu(num1,num2);
  printf("El mcd es: %d \n",mcd);


  return 0;
}
