//Nombre: Noelia Sueldo
//TP N°:
//EJ N°:
//Comentario:
#include <iostream>
#include "GestorReportes.h"
#include "ArchivoManager.h"
using namespace std;

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

    cout << "------ CURSOS DISCTADOS POR EL DOCENTE " << legajo << "-------"<< endl ;

    while (archivo.leerDeDisco("cursos.dat", curso, pos++)) {
        if (!curso.getEliminado() && curso.getLegajoDocente() == legajo) {
            curso.Mostrar();
            cout << "------------------------------------------------------------------------------" << endl;
        }
    }
      system("pause");

}

void GestorReportes::listarInscripcionesEntreFechas() {
    int d1,m1,a1;
    int d2,m2,a2;

    Fecha desde, hasta;

    cout << "Ingrese la fecha DESDE: ";
    cout << "Dia: ";
    cin  >> d1;
    cout << "Mes: ";
    cin  >> m1;
    cout << "Año: ";
    cin  >> a1;

    if (!desde.esFechaValida(d1,m1,a1)){
        cout << "Fecha DESDE invalida";
        system ("pause");
        return;
    }

    desde.setDia(d1);
    desde.setMes(m1);
    desde.setAnio(a1);

    cout << "Ingrese la fecha HASTA: ";
    cout << "Dia: ";
    cin  >> d2;
    cout << "Mes: ";
    cin  >> m2;
    cout << "Año: ";
    cin  >> a2;

    if (!hasta.esFechaValida(d2,m2,a2)){
        cout << "Fecha HASTA invalida";
        system ("pause");
        return;
    }
    hasta.setDia(d2);
    hasta.setMes(m2);
    hasta.setAnio(a2);

    int fDesde = desde.getAnio() * 10000 + desde.getMes() *100 + desde.getDia();
    int fHasta = hasta.getAnio() * 10000 + hasta.getMes() *100 + hasta.getDia();

    if (fDesde > fHasta){
        cout << "La fecha DESDE no pued ser mayor que HASTA ";
        system ("pause");
        return;
    }
    ArchivoManager archivo;
    Inscripcion insc;
    int pos =0;
    bool hayResultados = false;

    cout << "INSCRIPCIONES ENTRE FECHAS" << endl;
    cout << "-------------------------------------------" << endl;

    while (archivo.leerDeDisco("inscripcion.dat", insc, pos++)){
        if (!insc.getEliminado()){
            Fecha f = insc.getFechaInscripcion();
            int fIns = f.getAnio() * 10000 + f.getMes() *100 +  f.getDia();

            if (fIns >= fDesde && fIns <= fHasta){
                hayResultados = true;

                cout << "ID: " << insc.getIdInscripcion()
                        << "| Alumno: " << insc.getLegajoAlumno()
                        << "| Curso: " << insc.getCurso()
                        << "| Fecha: ";
                        insc.getFechaInscripcion().mostrar();
             cout  << "| Importe:  $" << insc.getImporteAbonado()
                        << endl;
            }
        }
    }
    if (!hayResultados){
        cout << "No hay inscripciones en ese rango de fechas";
    }
     system ("pause");
    }



void GestorReportes::alumnosConMasInscripciones() {
    Inscripcion insc;
    ArchivoManager archivo;
    int pos = 0;

    int conteo [5000] = {};

    while (archivo.leerDeDisco("inscripcion.dat", insc, pos++)) {
        if (!insc.getEliminado()) {
            int leg =insc.getLegajoAlumno();
            if (leg > 0 && leg < 5000) {
                    conteo[leg] ++;
            }
        }
    }

    int Max = 0;
    for (int i = 0; i < 5000; i++) {
        if (conteo[i] > Max ){
            Max = conteo [i];
        }
    }
        if (Max == 0){
            cout << "No hay inscripciones registrada" << endl;
            system ("pause");
            return;
        }

        cout << "ALumnos con mas inscripciones (" << Max <<  ") : " << endl;
        cout << endl;

        Alumno alu;
        pos = 0;

        while (archivo.leerDeDisco("alumnos.dat", alu, pos++)){
                int leg = alu.getLegajoAlumno();

                if (!alu.getEliminado() && leg > 0 && leg < 5000 && conteo [leg ] == Max) {

                alu.Mostrar();
                cout << "Cantidad de Inscripciones: " << Max  << endl;
                cout << endl;
            }
        }

          system("pause");

}
