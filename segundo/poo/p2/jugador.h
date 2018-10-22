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
    Jugador(const string DNI, const string codigo, const string nombre = "", const string apellidos = "",
            const int edad = 0, const string direccion = "", const string localidad = "", const string provincia = "",
            const string pais = "");

  inline  int getDinero(){ return dinero_; }
  inline  string getCodigo(){ return codigo_; }
  inline  std::list<Apuesta> getApuesta(){ return apuesta_; }
  inline  void setDinero();
  inline  void setCodigo();
  inline  void setApuesta();



  private:
    int dinero_;
    string codigo_
    std::list<Apuesta> apuesta_;

};

#endif
