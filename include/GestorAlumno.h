#ifndef GESTORALUMNO_H_INCLUDED
#define GESTORALUMNO_H_INCLUDED

#include "Alumno.h"
#include "ArchivoManager.h"

class GestorAlumno {
private:
    const char* NOMBRE_ARCHIVO = "alumnos.dat";
    const char* ARCHIVO_BAK = "alumnos.bak";


public:
    int obtenerUltimoLegajo();
    void nuevoAlumno();
   // void listarAlumnos();
    //void buscarAlumnos();
    //void modificarAlumnos();
    //void darBajaAlumno();
    //void mostrarAlumnosDeBaja();


};


#endif // GESTORALUMNO_H_INCLUDED
