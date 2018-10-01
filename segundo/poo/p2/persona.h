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

    void setDni(strin s);
    void setNombre(string s);
    void setApellidos(string s);
    void setDireccion(string s);
    void setLocalidad(string s);
    void setProvincia(string s);
    void setPais(string s);
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
