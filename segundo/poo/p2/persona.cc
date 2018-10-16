//persona.cc
//the code for the funtion of Persona


#include <string>
#include <cstdlib>
#include <iostream>
#include "persona.h"


Persona::Persona(std::string DNI, std::string nombre, std::string apellidos, int edad, std::string direccion,
                 std::string localidad , std::string provincia, std::string pais){
  //the body of the class
  DNI_ = DNI;
  nombre_ = nombre;
  apellidos_ = apellidos;
  edad_ = edad;
  direccion_ = direccion;
  localidad_ = localidad;
  provincia_ = provincia;
  pais_ = pais;

}

 void Persona::setDNI(std::string s){
  DNI_ = s;
}

 void Persona::setNombre(std::string s){
  nombre_ = s;
}

 void Persona::setApellidos(std::string s){
  apellidos_ = s;
}

 void Persona::setDireccion(std::string s){
  direccion_ = s;
}

 void Persona::setLocalidad(std::string s){
  localidad_ = s;
}

 void Persona::setProvincia(std::string s){
  provincia_ = s;
}

 void Persona::setPais(std::string s){
  pais_ = s;
}

 bool Persona::setEdad(int n){
  if (n > -1) {
    edad_ = n ;
    return true;
  }
  return false;
}

 std::string Persona::getDNI(){
  return DNI_;
}

 std::string Persona::getNombre(){
  return nombre_;
}

 std::string Persona::getApellidos(){
  return apellidos_;
}

 std::string Persona::getDireccion(){
  return direccion_;
}

 std::string Persona::getLocalidad(){
  return localidad_;
}

 std::string Persona::getProvincia(){
  return provincia_;
}

 std::string Persona::getPais(){
  return pais_;
}

 int Persona::getEdad(){
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
