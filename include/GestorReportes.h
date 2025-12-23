#ifndef GESTORREPORTES_H_INCLUDED
#define GESTORREPORTES_H_INCLUDED

#include "Alumno.h"
#include "Docente.h"
#include "Curso.h"
#include "Docente.h"
#include "Inscripcion.h"
#include "Fecha.h"

class GestorReportes {
public:

     void listarAlumnosPorCurso();
     void listarCursosPorDocente();
     void listarInscripcionesEntreFechas();
    void alumnosConMasInscripciones();

};


#endif // GESTORREPORTES_H_INCLUDED
