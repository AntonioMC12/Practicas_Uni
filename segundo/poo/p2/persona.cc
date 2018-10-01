//persona.cc
//the code for the funtion of Persona

#ifndef FILE_INCLUDED
#define FILE_INCLUDED

#include <string>
#include <cstdlib>
#include <persona.h>

Persona::Persona(){
  //the body of the class
  dni_ = getDni(std::string s);
  nombre_ = "";
  apellidos_ = "";
  edad_ = 0;
  direccion_ = "";
  localidad_ = "";
  provincia_ = "";
  pais_ = "";

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

inline int Persona::setEdad(int n){
  edad_ = s;
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

inline std::string Persona::getEdad(){
  return edad_;
}

std::string Persona::getApellidosyNombre(std::string nombre,std::string apellidos){

  std::string apellidosynombre;
  apellidosynombre = apellidos + ','' ' + nombre;
  return apellidosynombre;

}

bool Persona::mayor(){
  if (edad_ => 18) {
    return true;
  }
  return false;
}





}





#endif
