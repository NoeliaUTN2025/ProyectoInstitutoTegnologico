#pragma once
#include <Fecha.h>

#include <cstring>
#include <string>



class Persona {
protected:
   char  _dni [15];
   char  _nombre [50];
   char _apellido [50];
   Fecha _fechaNacimiento;
   char _telefono [15];
   char _email [50];
   char _direccion [100];
   bool _eliminado;

public:
    Persona();
    Persona (const char dni [], const char nombre [], const char apellido [], Fecha fechaNacimiento,  const char telefono [],
             const char email [], const char direccion [], bool eliminado);

    std::string getDni() const;
    std::string getNombre() const;
    std::string getApellido() const;
    Fecha getFechaNacimiento () const;
    std::string getTelefono() const;
    std::string getEmail() const;
    std::string getDireccion() const;
    bool getEliminado () const;

    void setDni (const std::string& dni);
    void setNombre (const std::string& nombre);
    void setApellido (const std::string& apellido);
    void setFechaNacimiento (Fecha fechaNacimiento);
    void setTelefono (const std::string& telefono);
    void setEmail (const std::string&  email);
    void setDireccion (const std::string& direccion);
    void setEliminado (bool eliminado);


};
