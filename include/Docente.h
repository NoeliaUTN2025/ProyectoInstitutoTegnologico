#pragma once
#include "Persona.h"


class Docente: public Persona {
protected:
    int _legajoDocente ;

public:
    Docente();
    Docente (const char dni [], const char nombre [], const char apellido [], Fecha fechaNacimiento,  const char telefono [],
             const char email [], const char direccion [], bool eliminado, int legajoDocente);

    int  getLegajoDocente () const;
    void setLegajoDocente (int legajoDocente);

    void Mostrar() const;

};
