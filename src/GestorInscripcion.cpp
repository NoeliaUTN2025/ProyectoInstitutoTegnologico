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
    while(true)
    {
        system("cls");
        int legajo;
        std::cout << "Ingrese legajo del alumno: "; std::cin >> legajo;

        int idCurso;
        std::cout << "Ingrese ID del curso: "; std::cin >> idCurso;

        float importe;
        std::cout << "Ingrese el importe a abornar: "; std::cin >> importe;

        std::string modalidad;
        std::cout << "Modalidad de pago: "; std::cin >> modalidad;

        int dia, mes, anio;
        std::cout << "Ingrese la fecha\nEl Dia: "; std::cin >> dia;
        std::cout << "El Mes: "; std::cin >> mes;
        std::cout << "El Anio: "; std::cin >> anio;

        Fecha fechaRegistrada;
        if (!fechaRegistrada.esFechaValida(dia, mes, anio)){
            continue;
        }

        fechaRegistrada.setDia(dia);
        fechaRegistrada.setMes(mes);
        fechaRegistrada.setAnio(anio);

        int m_idIscripcion{ obtenerUltimoId() };

        Inscripcion registro{ m_idIscripcion, legajo, idCurso, importe, modalidad, false, fechaRegistrada };

        ArchivoManager archivo;
        archivo.grabarEnDisco(NOMBRE_ARCHIVO, registro);

        std::cout << "Inscripcion realizada con exito. ID = " << m_idIscripcion << "\n";
        std::cout << "Presione ENTER para continuar...";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        break;
    }
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

void GestorInscripcion::darDeBaja() {
    system("cls");
    std::cout << "Ingrese el N de Inscripcion: ";
    int idBuscado{validation()};

    if (idBuscado == -1){
        system("cls");
        std::cout << "Opcion invalidad!...\n"; system("pause");
        return;
    }

    ArchivoManager archivo;
    Inscripcion registro;
    int pos{0};
    bool encontrado{false};

    //int cantidad{archivo.contarRegistrosInscripcion(NOMBRE_ARCHIVO)};

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, registro, ++pos)) {
        std::cout << registro.getIdInscripcion() << '\n';
        if (registro.getIdInscripcion() == idBuscado) {
            registro.setEliminado(true);
            std::cout << "Estas seguro que quieres dar de baja Inscripcion S/N: \n";
            std::cout << "ID: " << registro.getIdInscripcion()
            << " | Alumno: " << registro.getLegajoAlumno()
            << " | Curso: "  << std::setfill('0') << std::setw(4) << registro.getCurso()
            << " | Fecha: " << registro.getFechaInscripcion().mostrar()
            << "\n";

            while(true)
            {
                char letra;
                std::cin >> letra;
                if(std::toupper(letra) == 'S'){
                   archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, registro, pos);
                   std::cout << "Inscripcion " << idBuscado << " dada de baja correctamente.\n";
                   system("pause");
                   return;
                }
                else if (letra == 'N') {
                    std::cout << "Accion Cancelada!\n"; system("pause");
                    return;
                }
                std::cout << "Ingreso no valido\nIntentelo otra vez\n";
            }
        }
    }
    std::cout << "No se encontro el N de Inscripcion buscado\n";
    std::cout << "Presione ENTER continuar...";
    std::cin.ignore(1000, '\n');
}

int GestorInscripcion::validation() const {

    std::string entry;
    std::getline(std::cin, entry);

    /**
     * @brief Uso de empty(), para verificar string vacios.
     *
     * @see https://en.cppreference.com/w/cpp/string/basic_string/empty.html
     */
    bool isNumber = !entry.empty();

    for (size_t i{0}; i < entry.size(); ++i) {
        if (entry[i] < '0' || entry[i] > '9') {
            isNumber = false;
            break;
        }
    }

    int option;

    /**
     *  @brief Uso de substr(), para evitar overflow.
     *  @brief Uso de stoi(), para convertir a entero.
     *
     *  @see https://en.cppreference.com/w/cpp/string/basic_string/substr.html
     *  @see https://en.cppreference.com/w/cpp/string/basic_string/stol.html
     */

    if (isNumber) {
        std::string fiveDigit = entry.substr(0, 5);
        option = std::stoi(fiveDigit);
    }
    else {
        option = -1;
    }
    return option;
}
