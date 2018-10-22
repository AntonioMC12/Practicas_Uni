// jugador.cc
// the body of jugador

#include "jugador.h"
#include <string>
using std::string;

Jugador::Jugador(const string DNI, const string codigo, const string nombre, const string apellidos,
                 const int edad, const string direccion, const string localidad, const string provincia,
                 const string pais) : Persona(DNI, nombre, apellidos, edad, direccion, localidad,
                 provincia, pais){
                   codigo_ = codigo;
                   dinero_ = 1000;
                 }
