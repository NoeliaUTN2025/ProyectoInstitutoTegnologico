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
        std::cin >> option;

        switch (option) {
            case 1: menuStudent(); break;
            case 2: menuTeacher(); break;
            case 3: menuCourse(); break;
            case 4: menuRegistration(); break;
            case 5: menuReports(); break;
            case 6: menuBackup(); break;
            case 0: std::cout << "Saliendo...\n"; break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (option != 0);
}

void Menu::menuRegistration()const {
    int option;

    std::string menuOptions[]{
        "GESTION DE INCRIPCIONES", "1. Nueva inscripción",
        "2. Buscar inscripciones por alumno", "3. Buscar inscripciones por docente",
        "4. Buscar inscripciones por curso", "5. Dar de baja inscripción",
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
            case 5:
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
            case 1: //gestorR.listarAlumnosPorCurso(); break;
            case 2: // gestorR.listarCursosPorDocente(); break;
            case 3: gestor.listarInscripciones(); break;
            case 4: //gestorR.alumnosConMasInscripciones(); break;
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
