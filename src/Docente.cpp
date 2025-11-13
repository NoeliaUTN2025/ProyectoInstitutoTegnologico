#include <Docente.h>
#include <iostream>
#include "Persona.h"

using namespace std;


Docente:: Docente () : Persona () {
    _legajoDocente = 0 ;

}

Docente:: Docente (const char dni [], const char nombre [], const char apellido [], Fecha fechaNacimiento,  const char telefono [],
             const char email [], const char direccion [], bool eliminado, int legajoDocente)
             : Persona (dni, nombre, apellido, fechaNacimiento, telefono, email, direccion, eliminado) {
                _legajoDocente = legajoDocente;
 }

 int Docente::getLegajoDocente() const {
     return _legajoDocente;
 }

 void Docente::setLegajoDocente (int legajoDocente) {
     _legajoDocente = legajoDocente;
 }

 void Docente::Mostrar() const {
     cout << "---------------------------------------------------" << endl;
     cout << "Legajo Docente: " << _legajoDocente << endl;
     cout << "Nombre y Apellido: " << _nombre << " " << _apellido << endl;
     cout << "Dni: " << _dni << endl;
     cout << "Fecha de Nacimiento: "
            << _fechaNacimiento.getDia()  << "/"
            << _fechaNacimiento.getMes()  << "/"
            << _fechaNacimiento.getAnio()  <<  endl;
     cout << "Telefono: " << _telefono << endl;
     cout << "Email: " << _email << endl;
     cout << "Direccion: " << _direccion << endl;
 }
