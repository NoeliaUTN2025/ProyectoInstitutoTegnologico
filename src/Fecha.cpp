/**
 * @file Fecha.cpp
 * @brief Implementación de la clase Fecha
 * @author Diego J D Arias, Noelia Sueldo.
 * @date 2025-11-02
 * @version 1.0
 * @copyright MIT License
 *
 * Implementación de los métodos de la clase Fecha.
 * Incluye validación de fechas, cálculos y manejo de formatos.
 */

#include "Fecha.h"
#include <iostream>


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

/**
 * @brief Encargado de formatear,
 *
 * @param funcion que se encarga de dar formato a la fecha del sistema de gestion
 * @return std::string
 */

std::string Fecha::mostrar() const {
    std::string fecha{
        std::to_string(m_dia) + "/" +
        std::to_string(m_mes) + "/" +
        std::to_string(m_anio)
        };

    return fecha;
}

bool Fecha::esFechaValida(int dia, int mes, int anio) {

    // Años razonables para tu sistema
    if (anio < 1900 || anio > 2100) {
        std::cout << "Error!: el anio debe estar entre 1900 y 2100.\n";
        system("pause");
        return false;
    }

    if (mes < 1 || mes > 12) {
        std::cout << "Error!: El mes no puede ser menor a 1 ni mayor a 12.\n";
        system("pause");
        return false;
    }

    int diasEnMes[]{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Año bisiesto
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        diasEnMes[2] = 29;
    }

    if (dia < 1 || dia > diasEnMes[mes]) {
        std::cout << "Error!: El día no puede ser menor a 1 ni mayor a "
                  << diasEnMes[mes] << ".\n";
                  system("pause");
        return false;
    }

    return true;
}
