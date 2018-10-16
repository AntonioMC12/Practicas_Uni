//persona.h
//this file is the declaration of the class Persona.
//we set the private and public data.

#ifndef PERSONA_H
#define PERSONA_H

#include <string>


class Persona{
  private:

    std::string DNI_;
    std::string nombre_;
    std::string apellidos_;
    int edad_;
    std::string direccion_;
    std::string localidad_;
    std::string provincia_;
    std::string pais_;

  public:

    Persona(std::string DNI, std::string nombre = "", std::string apellidos = "", int edad = 0,
     std::string direccion = "", std::string localidad = "", std::string provincia = "", std::string pais = "");
    void setDNI(std::string s);
    void setNombre(std::string s);
    void setApellidos(std::string s);
    void setDireccion(std::string s);
    void setLocalidad(std::string s);
    void setProvincia(std::string s);
    void setPais(std::string s);
    bool setEdad(int n);
    std::string getDNI();
    std::string getNombre();
    std::string getApellidos();
    std::string getDireccion();
    std::string getLocalidad();
    std::string getProvincia();
    std::string getPais();
    int getEdad();
    std::string getApellidosyNombre();
    bool mayor();
};

#endif
