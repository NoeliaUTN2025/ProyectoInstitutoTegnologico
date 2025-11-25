#include "../include/Curso.h"
#include <iostream>
using namespace std;

Curso::Curso() {
    _idCurso =  0;
    _legajoDocente = 0;
    strcpy (_nombreCurso ,   "");
    _numeroAula = 0;
    _eliminado = false;

}

Curso::Curso(int idCurso, int legajoDocente,  const char nombreCurso [], int numeroAula, bool eliminado ) {
    _idCurso = idCurso;
    _legajoDocente = legajoDocente;
    strcpy (_nombreCurso, nombreCurso);
    _numeroAula = numeroAula;
    _eliminado = eliminado;

}

int Curso::getIdCurso()const{
    return _idCurso;
}

int Curso::getLegajoDocente()const{
    return _legajoDocente;
}

string  Curso::getNombreCurso()const{
    return _nombreCurso;
}

int Curso::getNumeroAula()const{
    return _numeroAula;
}

bool Curso::getEliminado()const{
    return _eliminado;
}

/////////////////////////////////

void Curso::setIdCurso(int idCurso){
    _idCurso= idCurso;
}

void Curso::setLegajoDocente(int legajoDocente){
    _legajoDocente = legajoDocente;
}

void  Curso::setNombreCurso( const std::string& nombreCurso){
    strcpy (_nombreCurso,  nombreCurso.c_str());
}

void Curso::setNumeroAula (int numeroAula){
    _numeroAula =   numeroAula;
}

void Curso::setEliminado(bool  eliminado){
    _eliminado = eliminado;
}

void Curso::Mostrar() const {
    cout << "Id Curso: " << _idCurso << endl;
    cout << "Legajo Docente: " << _legajoDocente << endl;
    cout << "Nombre del curso: " << _nombreCurso << endl;
    cout << "Numero del aula: " << _numeroAula << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO" ) << endl;
}


