//persona.cc
//the code for the funtion of Persona


#include <string>
#include <cstdlib>
#include <iostream>
#include "persona.h"


Persona::Persona(std::string dni, std::string nombre, std::string apellidos, int edad, std::string direccion,
                 std::string localidad , std::string provincia, std::string pais){
  //the body of the class
  dni_ = dni;
  nombre_ = nombre;
  apellidos_ = apellidos;
  edad_ = edad;
  direccion_ = direccion;
  localidad_ = localidad;
  provincia_ = provincia;
  pais_ = pais;

}

inline void Persona::setDni(std::string s){
  dni_ = s;
}

inline void Persona::setNombre(std::string s){
  nombre_ = s;
}

inline void Persona::setApellidos(std::string s){
  apellidos_ = s;
}

inline void Persona::setDireccion(std::string s){
  direccion_ = s;
}

inline void Persona::setLocalidad(std::string s){
  localidad_ = s;
}

inline void Persona::setProvincia(std::string s){
  provincia_ = s;
}

inline void Persona::setPais(std::string s){
  pais_ = s;
}

inline void Persona::setEdad(int n){
  edad_ = n;
}

inline std::string Persona::getDni(){
  return dni_;
}

inline std::string Persona::getNombre(){
  return nombre_;
}

inline std::string Persona::getApellidos(){
  return apellidos_;
}

inline std::string Persona::getDireccion(){
  return direccion_;
}

inline std::string Persona::getLocalidad(){
  return localidad_;
}

inline std::string Persona::getProvincia(){
  return provincia_;
}

inline std::string Persona::getPais(){
  return pais_;
}

inline int Persona::getEdad(){
  return edad_;
}

std::string Persona::getApellidosyNombre(){

  std::string apellidosynombre;
  apellidosynombre = apellidos_ + ", " + nombre_;
  return apellidosynombre;

}

bool Persona::mayor(){
  if (edad_ >= 18) {
    return true;
  }
  return false;
}
