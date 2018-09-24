//juego.cc
//the main program of the class Dice.

#include "dados.h"
#include <iostream>

int main(){
Dados d;
int num;

std::cout<<"¡COMIENZA EL JUEGO!"<<'\n';
std::cout<<"Vamos a lanzar los dados"<<'\n';

d.lanzamiento();

std::cout<<"Los dados han sido lanzados..."<<'\n';
std::cout<< '\n';
std::cout<<"  DADO 1 = "<<d.getDado1()<<'\n';
std::cout<<"  DADO 2 = "<<d.getDado2()<<'\n';

//----------------------set the value of dice 1-----------------------------

std::cout<<"introduce un valor para asignar al dado 1... "<<'\n';
do {
  std::cin>>num;
  d.setDado1(num);
  if (d.setDado1(num) == false) {
    std::cout << "El numero introducido no esta entre 1 y 6" << '\n';
    std::cout << "Introduzca un nuevo numero" << '\n';
  }
} while(d.setDado1(num == false));
std::cout << "El valor se ha guardado en el dado 1 correctamente" << '\n';

//----------------------set the value of dice 2------------------------------

std::cout<<"introduce un valor para asignar al dado 1... "<<'\n';
do {
  std::cin>>num;
  d.setDado2(num);
  if (d.setDado2(num) == false) {
    std::cout << "El numero introducido no esta entre 1 y 6" << '\n';
    std::cout << "Introduzca un nuevo numero" << '\n';
  }
} while(d.setDado2(num == false));
std::cout << "El valor se ha guardado en el dado 2 correctamente" << '\n';


//----------------------------------------------------------------------------

std::cout << "La suma del valor de los dados es " <<d.getSuma()<< '\n';

//----------------------------------------------------------------------------

//implementamos la funcion Diferencia

std::cout << "La diferencia entre los dados es " <<d.getDiferencia()<< '\n';

}
