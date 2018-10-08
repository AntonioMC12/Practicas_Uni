//dados.cc
//the body of the class "Dados".

#include <ctime>
#include <cstdlib>
#include "dados.h"

Dados::Dados(){
  //the body of the class, set the seed and set both dice = 1.

  srand(time(NULL));
  d1_ = 1;
  d2_ = 1;

}

inline int Dados::getDado1(){
  //return the value of dice1.

  return d1_;
}

int Dados::getDado2(){
  //return the value of dice2.

  return d2_;
}

void Dados::lanzamiento(){
  //set a rand value for both dice

  d1_ = ((rand()%6)+1);
  d2_ = ((rand()%6)+1);
}

bool Dados::setDado1(int num){
  //recieve a value and set this value to the dice1.
  if(num > 0 && num < 7){
    d1_ = num;
    return true;
  }
  else{
    return false;
  }
}

bool Dados::setDado2(int num){
  //recieve a value and set this value to the dice2.
  if(num > 0 && num < 7){
    d2_ = num;
    return true;
  }
  else{
    return false;
  }
}

int Dados::getSuma(){
  //return the add of both dice.

  return(d1_ + d2_ );
}

int Dados::getDiferencia(){
  //return the diference of botch dice.

  return(d1_ - d2_ );
}
