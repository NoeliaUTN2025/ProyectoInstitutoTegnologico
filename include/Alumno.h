#pragma once
#include "Persona.h"

class Alumno: public Persona {
protected:
    int _legajoAlumno ;

public:
    Alumno();
    Alumno (const char dni [], const char nombre [], const char apellido [], Fecha fechaNacimiento,  const char telefono [],
             const char email [], const char direccion [], bool eliminado, int legajoAlumno);


    int getLegajoAlumno() const;
    void setLegajoAlumno (int legajoAlumno);
    void Mostrar() const;
};
