/**
 * @file GestorInscripcion.cpp
 * @brief Implementacion de la clase GestorInscripcion
 * @author Diego J D Arias, Noelia Sueldo.
 * @date 2025-11-07
 * @version 1.0
 * @copyright MIT License
 */


#include "GestorInscripcion.h"
#include <iostream>
#include <string>


GestorInscripcion::GestorInscripcion() {
}

int GestorInscripcion::obtenerUltimoId() {
    Inscripcion idInscripto;
    int pos{}, ultimoID{};
    ArchivoManager archivo;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, idInscripto, pos++))
    {
        if (idInscripto.getIdInscripcion() > ultimoID)
        {
            ultimoID = idInscripto.getIdInscripcion();
        }
    }
    return ultimoID + 1;
}


void GestorInscripcion::nuevaInscripcion() {
    system("cls");
    int legajo, idCurso;
    std::cout << "Ingrese legajo del alumno: "; std::cin >> legajo;
    std::cout << "Ingrese ID del curso: "; std::cin >> idCurso;

    float importe;
    std::cout << "Ingrese el importe a abornar: "; std::cin >> importe;

    std::string modalidad;
    std::cout << "Modalidad de pago: "; std::cin >> modalidad;

    int dia, mes, anio;
    std::cout << "Ingrese la fecha\nEl Dia: "; std::cin >> dia;
    std::cout << "El Mes: "; std::cin >> mes;
    std::cout << "El Anio: "; std::cin >> anio;
    // @TODO: Arreglar saldo de lineas - ////////////////////////////////////////////////////////////////////////////
    Fecha fechaRegistrada;
    fechaRegistrada.setDia(dia);
    fechaRegistrada.setMes(mes);
    fechaRegistrada.setAnio(anio);

    int m_idIscripcion{ obtenerUltimoId() };

    Inscripcion registro{ m_idIscripcion, legajo, idCurso, importe, modalidad, false, fechaRegistrada };

    ArchivoManager archivo;
    archivo.grabarEnDisco(NOMBRE_ARCHIVO, registro);

    std::cout << "Inscripcion realizada con exito. ID = " << m_idIscripcion << "\n";
    system("pause");
}
