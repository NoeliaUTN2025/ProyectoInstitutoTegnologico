#include "Inscripcion.h"
#include <cstring>


Inscripcion::Inscripcion()
    : m_idInscripcion{}, m_legajoAlumno{}, m_idCurso{}, m_importeAbonado{}
    , m_formaDePago{}, m_eliminado{false}, m_fechaInscripcion{} {}

Inscripcion::Inscripcion(int idInscripcion, int legajoAlumno, int idCurso, float importeAbonado,
    const std::string& formaDePago, bool eliminado, const Fecha& fechaInscripcion) {
    setIdInscripcion(idInscripcion);
    setLegajoAlumno(legajoAlumno);
    setCurso(idCurso);
    setImporteAbonado(importeAbonado);
    setFormaDePago(formaDePago);
    setEliminado(eliminado);
    setFechaInscripcion(fechaInscripcion);
}

int Inscripcion::getIdInscripcion() const {
    return m_idInscripcion;
}

int Inscripcion::getLegajoAlumno() const {
    return m_legajoAlumno;
}

int Inscripcion::getCurso() const {
    return m_idCurso;
}

float Inscripcion::getImporteAbonado() const {
    return m_importeAbonado;
}

std::string Inscripcion::getFormaDePago() const {
    return m_formaDePago;
}

bool Inscripcion::getEliminado() const {
    return m_eliminado;
}

Fecha Inscripcion::getFechaInscripcion() const {
    return m_fechaInscripcion;
}

void Inscripcion::setIdInscripcion(int idInscripcion) {
    m_idInscripcion = idInscripcion;
}

void Inscripcion::setLegajoAlumno(int legajoAlumno) {
    m_legajoAlumno = legajoAlumno;
}

void Inscripcion::setCurso(int idCurso) {
    m_idCurso = idCurso;
}

void Inscripcion::setImporteAbonado(float importeAbonado) {
    m_importeAbonado = importeAbonado;
}

void Inscripcion::setFormaDePago(const std::string& formaDePago) {
    strcpy(m_formaDePago, formaDePago.c_str());
}

void Inscripcion::setEliminado(bool eliminado) {
    m_eliminado = eliminado;
}

void Inscripcion::setFechaInscripcion(const Fecha& fechaInscripcion) {
    m_fechaInscripcion = fechaInscripcion;
}
