/**
 * @file Fecha.h
 * @brief Definición de la clase Fecha para el manejo de la fecha en el sistema.
 * @author Diego J D Arias, Noelia Sueldo.
 * @date 2025-11-02
 * @version 1.0
 * @copyright MIT License
 *
 * Clase para representar y manipular fechas en el sistema académico.
 * Proporciona funcionalidades para validación, cálculo y formato de fechas.
 */

#ifndef FECHA_H
#define FECHA_H

#include <string>


class Fecha {
private:
    int m_dia;
    int m_mes;
    int m_anio;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    std::string mostrar() const;
    bool esFechaValida(int dia, int mes, int anio);
};

#endif // FECHA_H
