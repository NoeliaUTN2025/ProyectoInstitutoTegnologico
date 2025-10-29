#include "Fecha.h"


Fecha::Fecha() : m_dia(1), m_mes(1), m_anio(1900) {}

Fecha::Fecha(int dia, int mes, int anio) {
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

int Fecha::getDia() const {
    return m_dia;
}

int Fecha::getMes() const {
    return m_mes;
}

int Fecha::getAnio() const {
    return m_anio;
}

void Fecha::setDia(int dia) {
    m_dia = dia;
}

void Fecha::setMes(int mes) {
    m_mes = mes;
}

void Fecha::setAnio(int anio) {
    m_anio = anio;
}

std::string Fecha::toString() const {
    return std::to_string(m_dia) + "/" + std::to_string(m_mes) + "/" + std::to_string(m_anio);
}
