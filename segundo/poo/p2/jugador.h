// jugador.h
// here is the define the class jugador

#ifndef _JUGADOR_H
#define _JUGADOR_H
//including persona.h to heredate the class
#include "persona.h"
#include <string>
#include <list>
using std::string;

class Apuesta{
  public:
    int tipo,cantidad;
    string valor;
}

class Jugador : public Persona{

  public:
    Jugador()



  private:
    int dinero_;
    string codigo_
    std::list<Apuesta> apuesta_;

};

#endif
