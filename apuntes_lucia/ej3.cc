/* 3. Codifique un programa en C que sume los n primeros múltiplos de un número entero
positivo introducido por el usuario. El programa ha de controlar que el número
introducido es positivo. Por ejemplo ejemplo, si el número es x, ha de calcular
x+2x+3x+ ...+nx.
*/

#include <iostream>

int main(){

int numero;
int multiplos;
int suma = 0;

  std::cout << "Introduzca un numero" << '\n';
  std::cin >> numero;

  while (numero < 0) {
    std::cout << "Introduzca un numero positivo, por favor..." << '\n';
    std::cin >> numero;
  }

  std::cout << "Introduzca cuantos multiplos quiere calcular" << '\n';
  std::cin >> multiplos;

  for( int i = 1 ; i < multiplos+1 ; i++){
    suma = suma + numero*i;
  }

  std::cout << "La suma es... " << suma <<'\n';
  
}
