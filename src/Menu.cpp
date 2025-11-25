/**
 * @file Menu.cpp
 * @brief Implementación de la clase Menu
 * @author Diego J D Arias, Noelia Sueldo.
 * @date 2025-11-06
 * @version 1.0
 * @copyright MIT License
 *
 * Implementación de los métodos de la clase Menu.
 * Incluye las opciones de los diferentes menus del sistema.
 */


#include "Menu.h"
#include <GestorInscripcion.h>
#include <iostream>
#include "GestorAlumno.h"
#include "GestorDocente.h"
#include "GestorCursos.h"
#include "GestorReportes.h"

void Menu::start() const{
    int option;
    std::string menuOptions[]{
        "SISTEMA DE GESTION - INSTITUTO TECNOLOGICO", "1. Gestion de Alumnos",
        "2. Gestion de Docentes", "3. Gestion de Cursos",
        "4. Gestion de Inscripciones", "5. Reportes y Consultas",
        "6. Copias de Seguridad", "0. Salir", "Seleccione una opcion: "};

        int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

    do {
        system("cls");
        draw(menuOptions, arrayLength);

        /**
         * @brief Solucion a limpiado del Buffer, uso de std::cin.ignore()
         *
         * Previene problemas de entrada cuando se mezclan std::cin >> y std::getline()
         *
         * @see https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
         * @see https://stackoverflow.com/a/25476169 Respuesta de: user4581301
         */

        option = validation();

        switch (option) {
            case 1: menuStudent(); break;
            case 2: menuTeacher(); break;
            case 3: menuCourse(); break;
            case 4: menuRegistration(); break;
            case 5: menuReports(); break;
            case 6: menuBackup(); break;
            case 0: std::cout << "Saliendo...\n"; break;
            default: std::cout << "Opcion invalida!\n";
            std::cout << "Presione ENTER continuar...";
            std::cin.ignore(1000, '\n');
        }
    } while (option != 0);
}

void Menu::menuRegistration()const {
    int option;

    std::string menuOptions[]{
        "GESTION DE INCRIPCIONES", "1. Nueva inscripción",
        "2. Buscar Inscripcion", "3. Modificar Inscripcion",
        "4. Dar de Baja Inscripcion", "5. Recuperar Inscripción",
        "0. Volver al menú principal" };

        int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

    do {
        system("cls");
        draw(menuOptions, arrayLength);
        std::cin >> option;
        GestorInscripcion gestor;

        switch (option) {
            case 1: gestor.nuevaInscripcion();
            case 2:
            case 3:
            case 4:
            case 5: menuBaja();
            case 0: break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (option != 0);
}

void Menu::menuStudent()const {
    int option;

    std::string menuOptions[]{
        "GESTIÓN DE ALUMNOS", "1. Alta de alumno",
        "2. Listar alumnos", "3. Buscar alumno por legajo","4. Buscar alumno por DNI",
        "5. Modificar datos de alumno", "6. Dar de baja alumno",
        "7. Mostrar alumnos dados de baja", "0. Volver al menú principal" };

        int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

    do {
        system("cls");
        draw(menuOptions, arrayLength);
        std::cin >> option;

        GestorAlumno gestor;

        switch (option) {
            case 1: gestor.nuevoAlumno() ;break;
            case 2: gestor.listarAlumnos(); break;
            case 3: gestor.buscarAlumnosPorLegajo(); break;
            case 4: gestor.buscarAlumnosPorDNI() ;break;
            case 5: gestor.modificarAlumno(); break;
            case 6: gestor.darBajaAlumno(); break;
            case 7: gestor.mostrarAlumnosDeBaja(); break;
            case 0: break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (option != 0);
}

void Menu::menuTeacher()const {
    int option;



    std::string menuOptions[]{
        "GESTIÓN DE DOCENTES", "1. Alta de docente",
        "2. Listar docente", "3. Buscar docente por legajo","4. Buscar docente por DNI",
        "5. Modificar datos de docente", "6. Dar de baja docente",
        "7. Mostrar docentes dados de baja", "0. Volver al menú principal" };

        int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

    do {
        system("cls");
        draw(menuOptions, arrayLength);
        std::cin >> option;

    GestorDocente gestor;

        switch (option) {
            case 1: gestor.nuevoDocente(); break;
            case 2: gestor.listarDocentes(); break;
            case 3: gestor.buscarDocentesPorLegajo(); break;
            case 4: gestor.buscarDocentesPorDNI(); break;
            case 5: gestor.modificarDocentes(); break;
            case 6: gestor.darBajaDocentes(); break;
            case 7: gestor.mostrarDocentesDeBaja(); break;
            case 0: break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (option != 0);
}

void Menu::menuCourse()const {
    int option;

    std::string menuOptions[]{
        "GESTIÓN DE CURSOS", "1. Alta de curso",
        "2. Listar cursos", "3. Buscar curso por id",
        "4. Modificar datos de curso", "5. Dar de baja curso",
        "6. Mostrar cursos dados de baja", "0. Volver al menú principal" };

        int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

    do {
        system("cls");
        draw(menuOptions, arrayLength);
        std::cin >> option;

        GestorCursos gestor;

        switch (option) {
            case 1: gestor.nuevoCurso(); break;
            case 2: gestor.listarCursos(); break;
            case 3: gestor.buscarCursosPorID(); break;
            case 4: gestor.modificarCursos (); break;
            case 5: gestor.darBajaCurso(); break;
            case 6: gestor.mostrarCursosDeBaja(); break;
            case 0: break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (option != 0);
}

void Menu::menuReports()const {

    int option;

    std::string menuOptions[]{
        "REPORTES Y CONSULTAS", "1. Listar alumnos por curso",
        "2. Listar cursos por docente", "3. Listar inscripciones entre fechas",
        "4. Alumnos con más inscripciones", "0. Volver al menú principal" };

        int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

    do {
        system("cls");
        draw(menuOptions, arrayLength);
        std::cin >> option;

        GestorInscripcion gestor;
        GestorReportes gestorR;
        switch (option) {
            case 1: gestorR.listarAlumnosPorCurso(); break;
            case 2: gestorR.listarCursosPorDocente(); break;
            case 3: gestor.listarInscripciones(); break;
            case 4: gestorR.alumnosConMasInscripciones(); break;
            case 0: break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (option != 0);
}

void Menu::menuBackup() const {
    int option;

    std::string menuOptions[]{
        "COPIAS DE SEGURIDAD Y BACKUP", "1. Hacer backup de archivos",
        "2. Restaurar desde backup", "0. Volver al menú principal" };

        int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

    do {
        system("cls");
        draw(menuOptions, arrayLength);
        std::cin >> option;

        switch (option) {
            case 1: menuRealizarBackup(); break;
            case 2: menuRestaurar(); break;
            case 0: break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (option != 0);
}

/**
 * @brief Dibuja los menus,
 *
 * @param funcion que se encarga de acomodar las opciones de los diferentes menus.
 * @return void
 */

void Menu::draw(const std::string* options, int arrayLength) const {

    std::cout << "================================================" << '\n';
    for(int i{0}; i < arrayLength; ++i){
        std::cout << options[i] << '\n';
        if (i == 0){
            std::cout << "================================================\n" << '\n';
        }
    }
}

void Menu::menuRealizarBackup() const {
    int option;

    std::string menuOptions[]{
        "Elige la opcion que quieras realizar: ", "1. BackUp Alumno: ",
        "2. BackUp Docente: ", "3. BackUp Curso: ",
        "4. BackUp Inscripcion: ", "0. Volver al menu anterior: " };

    int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

    do {
        system("cls");
        draw(menuOptions, arrayLength);
        std::cin >> option;

        switch (option) {
            case 1:
                {
                GestorAlumno gestor;
                gestor.backup (); break;
            }
            case 2: {
                GestorDocente gestor;
                gestor.backup(); break;
            }
            case 3: {
                GestorCursos gestor;
                gestor.backup(); break;
            }
            case 4: {
                GestorInscripcion gestor;
                gestor.backup(); break;
            }
            case 0: break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (option != 0);
}

void Menu::menuRestaurar() const {
    int option;

    std::string menuOptions[]{
        "Elige la opcion que quieras realizar: ", "1. Restaurar BackUp Alumno: ",
        "2. Restaurar BackUp Docente: ", "3. Restaurar BackUp Curso: ",
        "4. Restaurar BackUp Inscripcion: ", "0. Volver al menu anterior: " };

    int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

    do {

        system("cls");
        draw(menuOptions, arrayLength);
        std::cin >> option;

        switch (option)
        {
        case 1: {
            GestorAlumno gestor;
            gestor.restaurar(); break;
        }
        case 2: {
            GestorDocente gestor;
            gestor.restaurar(); break;
        }
        case 3: {
            GestorCursos gestor;
            gestor.restaurar(); break;
        }
        case 4: {
            GestorInscripcion gestor;
            gestor.restaurar(); break;
        }
        case 0: break;
        default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (option != 0);
}


int Menu::validation() const {

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
        std::string twoDigit = entry.substr(0, 2);
        option = std::stoi(twoDigit);
    }
    else {
        option = -1;
    }
    return option;
}

void Menu::menuBaja() const {
    int option;

    std::string menuOptions[]{
        "OPCIONES DE BAJA DE INSCRIPCION", "1. Ingresar el ID Inscripcion a Dar de Baja",
        "\n** Si no recuerda el Id de Inscripcion, busquelo por: **", "2. Legajo del Alumno",
        "3. DNI", "4. Id Del Curso",
        "0. Atras" };

        int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

        do {
        system("cls");
        draw(menuOptions, arrayLength);
        option = validation();

        GestorInscripcion gestor;
        switch (option) {
            case 1: gestor.darDeBaja(); break;
            case 2: //menuRestaurar(); break;
            case 3: //realizarBackup(); break;  /// nota noe 19/11ESTE NO COMPLIABA
            case 4: //menuRestaurar(); break;
            case 0: break;
            default: std::cout << "Opcion invalida!\n";
            std::cout << "Presione ENTER continuar...";
            std::cin.ignore(1000, '\n');
        }
    } while (option != 0);
}

