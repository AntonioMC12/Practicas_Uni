/* 4. Codifique un programa en C que calcule la suma de los n primeras potencias de 2
(2 0 + 2 1 + 2 2 + ..+ 2 n ), donde n es un número entero positivo que el usuario introducirá
por teclado. Después de mostrar el resultado, comprobar con un esquema
condicional que se cumple que la suma es 2 n+1 -1, y que el programa muestre si se
cumple o no se cumple.
*/

#include <iostream>
#include <cmath>

int main(){

  int n;
  int suma = 0;

  std::cout << "Introduzca el valor de n" << '\n';
  std::cin >> n;

  for(int i = 0 ; i < n+1 ; i++){
    suma = suma + pow(2,i);
  }

  std::cout << "La suma es... " << suma << '\n';

  int condicional = 0;

  condicional = pow(2, n+1) - 1;

  if(condicional = suma){
    std::cout << "Se cumple la condicion (2^n1)-1..." << '\n';
  }
  else{
    std::cout << "No se cumple la condicion (2^n1)-1..." << '\n';
  }
}
