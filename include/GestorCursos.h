#ifndef GESTORCURSOS_H_INCLUDED
#define GESTORCURSOS_H_INCLUDED

#include "Curso.h"
#include "ArchivoManager.h"

class GestorCursos {
private:
     const char* NOMBRE_ARCHIVO = "cursos.dat";
     const char* ARCHIVO_BAK = "cursos.bak";

public:

    GestorCursos() = default;

    int obtenerUltimoIdCurso();
    void nuevoCurso();
    void listarCursos();
    void buscarCursosPorID();
    void modificarCursos();
    void darBajaCurso();
    void mostrarCursosDeBaja();

    void backup() const;
    void restaurar() const;

};

#endif // GESTORCURSOS_H_INCLUDED
