//persona.h
//this file is the declaration of the class Persona.
//we set the private and public data.

#include <cstring>


class Persona{
  private:

    std::string dni_;
    std::string nombre_;
    std::string apellidos_;
    int edad_;
    std::string direccion_;
    std::string localidad_;
    std::string provincia_;
    std::string pais_;

  public:

    void setDni(std::string s);
    void setNombre(std::string s);
    void setApellidos(std::string s);
    void setDireccion(std::string s);
    void setLocalidad(std::string s);
    void setProvincia(std::string s);
    void setPais(std::string s);
    void setEdad(int n);
    std::string getDni();
    std::string getNombre();
    std::string getApellidos();
    std::string getDireccion();
    std::string getLocalidad();
    std::string getProvincia();
    std::string getPais();
    int getEdad();

}
