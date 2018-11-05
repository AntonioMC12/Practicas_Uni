#include <iostream>

int main(){

/*guardamos una variable de tipo int para seleccionar la tabla de multiplicar.
empezamos por la tabla del 1, por eso la igualamos
ahora hacemos un bucle que nos sirva para imprimir por pantalla la tabla del
numero introducido anteriormente.
Inicializamos el contador i a 1 para empezar por 3x1 y establecemos el limite
hasta 3x10 haciendo i < 11 para que no se ejecute el programa sobrepasado el valor
de 10.
Despues simplemente implementamos un cout para imprimir por pantalla la operacion
*/
std::cout << "El programa va a mostrar las tablas de multiplicar del 1 al 10" << '\n' << "Pulse 'intro' para continuar..." << '\n';
std::cin.ignore();

  for ( int seleccionador = 1 ; seleccionador < 11 ; seleccionador++ ){

    for ( int i = 1 ; i < 11 ; i++){

      std::cout << seleccionador <<" x "<< i <<" = " << seleccionador*i << '\n';

    }
  std::cout << '\n' <<"Pulse 'intro' para continuar..." << '\n';
  std::cin.ignore();
  }
}

// la funcion cin.ignore() hace que el programa continue cuando pulsas intro
