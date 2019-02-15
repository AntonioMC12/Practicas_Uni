/*
2.-
 Hacer un programa (guess.cc) que genere un n�mero aleatorio entre 1 y 10, y
 solicite al usuario un n�mero por teclado para posteriormente adivinarlo indicando
 al usuario si el n�mero generado es menor, mayor o es correcto. Usar para la entrada
 por teclado el objeto de entrada estandar cin para lo que tendr�s que incluir la
 misma cabecera que con cout del ejercicio anterior.


incluimos las librerias de entrada y salida, junto con la libreria para generar la
semilla del srand y stdlib para rand
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
  //para generar el numero aleatorio debemos inicializar la semilla

  int rand_num , guess;
  srand(time(NULL)); //semilla inicializada

  rand_num = (rand() % 10+1); //genera un numero entre 1 y 10

  std::cout << "Adivine el numero generado" << '\n';
  std::cin >> guess;

  while (guess != rand_num){
    if (guess < rand_num){
      std::cout << "El numero introducido es menor, pruebe otra vez:" << '\n';
      std::cin >> guess;
    }
    if (guess > rand_num){
      std::cout << "El numero introducido es mayor, pruebe otra vez" << '\n';
      std::cin >> guess;
    }
  }

  std::cout << " ¡Enhorabuena!, has adivinado el numero. " << '\n';
}