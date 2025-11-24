//Nombre: Noelia Sueldo
//TP N°:
//EJ N°:
//Comentario:
#include <iostream>
#include "GestorReportes.h"
#include "ArchivoManager.h"
using namespace std;
/*
void GestorReportes::listarAlumnosPorCurso() {
    int idCurso;

    cout << "Ingrese el ID del curso";
    cin >> idCurso;

    Inscripcion ins;
    Alumno alum;
    ArchivoManager archivo;
    int pos = 0;

    cout << "--------------LISTADO DE ALUMNOS DEL CURSO----------" << endl;

    while (archivo.leerDeDisco("inscripcion.dat", ins, pos++)) {
        if (!ins.getEliminado() && ins.getCurso() == idCurso) {

            int posAlum = 0;
            while(archivo.leerDeDisco("alumnos.dat" , alum, posAlum++))  {
                if (!alum.getEliminado() && alum.getLegajoAlumno() == ins.getLegajoAlumno()){
                    alum.Mostrar();
                    cout << "---------------------------------------------------------" << endl;
                }
            }
        }
    }
    system("pause");

}


void GestorReportes::listarCursosPorDocente() {
    int legajo;
    cout << "Ingrese el legajo del docente: ";
    cin >> legajo;

    Curso curso;
    ArchivoManager archivo;
    int pos = 0;

    cout << "------ CURSOS DISCTADOS POR EL DOCENTE" << legajo << "------";

    while (archivo.leerDeDisco("cursos.dat", curso, pos++)) {
        if (!curso.getEliminado() && curso.getLegajoDocente() == legajo) {
            curso.Mostrar();
            cout << "------------------------------------------------------------------------------" << endl;
        }
    }
      system("pause");

}

void GestorReportes::listarInscripcionesEntreFechas() {

}

void GestorReportes::alumnosConMasInscripciones() {
    Inscripcion insc;
    ArchivoManager archivo;
    int pos = 0;

    int conteo [5000] = {};

    while (archivo.leerDeDisco("inscripcion.dat", insc, pos++)) {
        if (!insc.getEliminado()) conteo[insc.getLegajoAlumno()++];
    }

    int Max = 0;
    for (int i = 0; i < 5000; i++) {
        if (conteo[i] > Max ){
            Max = conteo [i];
        }
        Alumno alu;
        pos = 0;
        cout << "ALumnos con mas inscripciones (" << Max <<  ") : ";

        while (archivo.leerDeDisco("alumnos.dat", alu, pos++)){
            if (conteo [alu.getLegajoAlumno()] == Max) {
                alu.Mostrar();
                cout << "Inscripciones: " << Max  << endl;
                cout << "--------------------------------------------------------";
            }
        }
    }
          system("pause");

}*/
