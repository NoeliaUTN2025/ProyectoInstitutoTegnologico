#include "Alumno.h"
#include <iostream>
#include "Persona.h"

using namespace std;

Alumno:: Alumno () : Persona () {
    _legajoAlumno = 0 ;

}

Alumno:: Alumno (const char dni [], const char nombre [], const char apellido [], Fecha fechaNacimiento,  const char telefono [], const char email [], const char direccion [], bool eliminado, int legajoAlumno)
             :Persona (dni, nombre, apellido, fechaNacimiento, telefono, email, direccion, eliminado) {
                _legajoAlumno = legajoAlumno;
 }

 int Alumno::getLegajoAlumno() const {
     return _legajoAlumno;
 }

 void Alumno::setLegajoAlumno (int legajoAlumno) {
     _legajoAlumno = legajoAlumno;
 }

 void Alumno::Mostrar() const {
     cout << "-----------------------------------------------" << endl;
     cout << "Legajo Alumno: " << _legajoAlumno << endl;
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





