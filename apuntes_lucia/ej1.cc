#include <iostream>

int main(){

//guardamos una variable de tipo int para seleccionar la tabla de multiplicar.
  int seleccionador;

//introducimos el numero a mostrar su tabla
  std::cout << "Introduzca un numero para mostrar su tabla" << '\n';
  std::cin >> seleccionador;

/* ahora hacemos un bucle que nos sirva para imprimir por pantalla la tabla del
numero introducido anteriormente.
Inicializamos el contador i a 1 para empezar por 3x1 y establecemos el limite
hasta 3x10 haciendo i < 11 para que no se ejecute el programa sobrepasado el valor
de 10.
Despues simplemente implementamos un cout para imprimir por pantalla la operacion
 */

  for (int i = 1 ; i < 11 ; i++){
    std::cout << seleccionador <<" x "<< i <<" = " << seleccionador*i << '\n';
  }
}
