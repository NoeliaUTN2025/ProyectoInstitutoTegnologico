/**
 * @file Inscripcion.h
 * @brief Definición de la clase Inscripcion para el sistema académico
 * @author Diego J D Arias, Noelia Sueldo.
 * @date 2025-11-02
 * @version 1.0
 * @copyright MIT License
 * @see GestorInscripcion para la clase que gestiona estas instancias.
 */

#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Fecha.h"
#include <string>


class Inscripcion {
private:
    int m_idInscripcion;
    int m_legajoAlumno;
    int m_idCurso;
    float m_importeAbonado;
    char m_formaDePago[50]; // @TODO: Definir largo maximo posible admitido.
    bool m_eliminado;
    Fecha m_fechaInscripcion;

public:
    Inscripcion();
    Inscripcion(int idInscripcion, int legajoAlumno, int idCurso, float importeAbonado
                , const std::string& formaDePago, bool eliminado, const Fecha& fechaInscripcion);
    int getIdInscripcion() const;
    int getLegajoAlumno() const;
    int getCurso() const;
    float getImporteAbonado() const;
    std::string getFormaDePago() const;
    bool getEliminado() const;
    Fecha getFechaInscripcion() const;

    void setIdInscripcion(int idInscripcion);
    void setLegajoAlumno(int legajoAlumno);
    void setCurso(int idCurso);
    void setImporteAbonado(float importeAbonado);
    void setFormaDePago(const std::string& formaDePago);
    void setEliminado(bool eliminado);
    void setFechaInscripcion(const Fecha& fechaInscripcion);

};

#endif // INSCRIPCION_H
