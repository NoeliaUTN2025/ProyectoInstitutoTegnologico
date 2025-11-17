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
#include <iomanip>


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

void GestorInscripcion::listarInscripciones() const {
    system("cls");
    Inscripcion inscripto;
    int pos{};

    ArchivoManager archivo;
    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, inscripto, pos++))
    {
        if (!inscripto.getEliminado()) {
            std::cout << "ID: " << inscripto.getIdInscripcion()
            << " | Alumno: " << inscripto.getLegajoAlumno()
            << " | Curso: "  << std::setfill('0') << std::setw(4) << inscripto.getCurso()
            << " | Fecha: " << inscripto.getFechaInscripcion().mostrar()
            << "\n";
        }
    }
    std::cout << std::endl;
    system("pause");
}

void GestorInscripcion::backup() const {
    system("cls");
    ArchivoManager archivo;

    if (archivo.hacerBackup(NOMBRE_ARCHIVO, ARCHIVO_BAK)) {
        std::cout << "BackUp realizado con exito!: \n"; system("pause");
    } else {
        std::cerr << "No se pudo realizar el BackUp!: \n"; system("pause");
    }
}

void GestorInscripcion::restaurar() const {
    system("cls");
    ArchivoManager archivo;

    if (archivo.hacerBackup(ARCHIVO_BAK, NOMBRE_ARCHIVO)) {
        std::cout << "La Restauracion fue exitosa!: \n"; system("pause");
    } else {
        std::cerr << "No se pudo realizar la Restauracion!: \n"; system("pause");
    }
}

