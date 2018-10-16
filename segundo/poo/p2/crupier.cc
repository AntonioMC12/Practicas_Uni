//crupier.cc
//the code for the class Crupier

#include <string>
#include "crupier.h"
using std::string;

Crupier::Crupier(const string DNI, const string codigo, const string nombre, const string apellidos,
                 const int edad, const string direccion, const string localidad, const string provincia,
                 const string pais) : Persona(DNI, nombre, apellidos, edad, direccion,
                 localidad, provincia, pais){
                   codigo_ = codigo;
                 }
