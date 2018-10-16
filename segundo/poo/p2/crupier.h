// crupier.h
// here is define the class crupier

#ifndef _CRUPIER_H
#define _CRUPIER_H
//include the persona.h to heredate the class
#include "persona.h"
#include <string>
using std::string;

class Crupier : public Persona{
  public:
  Crupier(const string DNI, const string codigo, const string nombre = "", const string apellidos = "",
          const int edad = 0, const string direccion = "", const string localidad = "", const string provincia = "",
          const string pais = "");

//including getCodigo and setCodigo.

   string getCodigo(){
    return codigo_;
  }

   void setCodigo(string c){
    codigo_ = c ;
  }

  private:
  string codigo_;
};

#endif
