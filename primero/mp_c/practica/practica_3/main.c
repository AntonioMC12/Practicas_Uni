#include <stdio.h>
#include <stdlib.h>

  int avalor(int num){
    if( num < 0 ){
      return -num;
    }
    return num;
  }

  int division(int dividendo, int divisor){

    if(divisor == 0){
      printf("No se puede dividir entre 0\n");
      exit(-1);
    }

    dividendo = avalor(dividendo);
    divisor = avalor(divisor);

    if(dividendo < divisor){
      return 0;
    }

    return (1 + division(dividendo-divisor,divisor));
  }

  int main() {

    int dividendo, divisor, aux;
    printf("Introduzca el valor a dividir\n");
    scanf("%d",&dividendo);
    printf("Introduzca tu divisor\n");
    scanf("%d",&divisor);

    aux = division(dividendo,divisor);
    printf("El resultado es %d \n",aux);

  return 0;
}
