
#pragma once

#include <cstring>
#include <string>

class Curso {
private:
    int _idCurso;
    int _legajoDocente;
    char _nombreCurso [100];
    int _numeroAula;
    bool _eliminado;

public:
    Curso ();
    Curso(int idCurso, int legajoDocente,  const char nombreCurso [], int numeroAula, bool eliminado);

    int getIdCurso () const;
    int getLegajoDocente() const;
    std::string  getNombreCurso () const;
    int getNumeroAula() const;
    bool getEliminado() const;


    void setIdCurso (int idCurso);
    void setLegajoDocente(int legajoDocente);
    void setNombreCurso ( const std::string& nombreCurso);
    void setNumeroAula(int numeroAula);
    void setEliminado(bool eliminado);

};

