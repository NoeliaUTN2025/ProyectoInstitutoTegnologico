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
    std::string toString() const;
};

#endif // FECHA_H
