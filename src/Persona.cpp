#include <iostream>
#include <cstring>
 #include "Persona.h"

using namespace std;

Persona::Persona(){
    strcpy (_dni,  "") ;
    strcpy (_nombre ,   "");
    strcpy (_apellido ,   "");
    _fechaNacimiento = Fecha();
    strcpy (_telefono ,   "");
    strcpy (_email ,   "");
    strcpy (_direccion ,   "");
    _eliminado = false;

}

Persona::Persona(const char dni [], const char nombre [], const char apellido [], Fecha fechaNacimiento,  const char telefono [],
             const char email [], const char direccion [], bool eliminado){
              strcpy (_dni, dni) ;
             strcpy (_nombre, nombre);
             strcpy (_apellido, apellido);
             _fechaNacimiento = fechaNacimiento;
             strcpy (_telefono, telefono);
             strcpy (_email, email);
             strcpy (_direccion, direccion);
             _eliminado = eliminado;

}

string Persona::getDni() const{
    return _dni;
}

string Persona::getNombre() const{
    return _nombre;
}

string Persona::getApellido() const{
    return _apellido;
}

Fecha Persona::getFechaNacimiento() const{
    return _fechaNacimiento;
}

string Persona::getTelefono() const{
    return _telefono;
}

string Persona::getEmail() const{
    return _email;
}

string Persona::getDireccion() const{
    return _direccion;
}

bool Persona::getEliminado() const{
    return _eliminado;
}


////SETTERS

void Persona::setDni(const std::string& dni){
    strcpy (_dni,  dni.c_str());
}

void Persona::setNombre(const std::string& nombre){
    strcpy (_nombre,  nombre.c_str());
}

void  Persona::setApellido( const std::string& apellido){
    strcpy (_apellido,  apellido.c_str());
}

void Persona::setFechaNacimiento (Fecha fechaNacimiento){
    _fechaNacimiento =   fechaNacimiento;
}

void Persona::setTelefono (const std::string& telefono){
    strcpy (_telefono,  telefono.c_str());
}

void Persona::setEmail (const std::string& email){
    strcpy (_email,  email.c_str());
}

void Persona::setDireccion(const std::string& direccion){
    strcpy (_direccion,  direccion.c_str());
}

void Persona::setEliminado (bool eliminado){
    _eliminado = eliminado;
}



