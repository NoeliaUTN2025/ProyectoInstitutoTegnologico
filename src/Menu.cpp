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
#include <iostream>

void Menu::start()const {
    int option;
    std::string menuOptions[]{
        "SISTEMA DE GESTION - INSTITUTO TECNOLOGICO", "1. Gestion de Alumnos",
        "2. Gestion de Docentes", "3. Gestion de Cursos",
        "4. Gestion de Inscripciones", "5. Reportes y Consultas"
        "6. Copias de Seguridad", "0. Salir", "Seleccione una opcion: "};

        int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

    do {
        system("cls");
        draw(menuOptions, arrayLength);
        std::cin >> option;

        switch (option) {
            case 1: //menuAlumno(); break;
            case 2: //menuDocente(); break;
            case 3: //menuCurso(); break;
            case 4: menuRegistration(); break;
            case 5: //menuReporteInforme(); break;
            case 6: //menuBackupRestauracion(); break;
            case 0: std::cout << "Saliendo...\n"; break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (option != 0);
}

void Menu::menuRegistration()const {
    int option;

    std::string menuOptions[]{
        "GESTION - INCRIPCION", "1. Nueva inscripción",
        "2. Buscar inscripciones por alumno", "3. Buscar inscripciones por docente",
        "4. Buscar inscripciones por curso", "5. Dar de baja inscripción",
        "0. Volver al menú principal" };

        int arrayLength{ sizeof(menuOptions) / sizeof(std::string) };

    do {
        system("cls");
        draw(menuOptions, arrayLength);
        std::cin >> option;

        switch (option) {
            case 1: //@TODO: definir
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 0: break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (option != 0);
}

void Menu::draw(const std::string* options, int arrayLength) const {

    std::cout << "================================================" << '\n';
    for(int i{0}; i < arrayLength; ++i){
        std::cout << options[i] << '\n';
        if (i == 0){
            std::cout << "================================================\n" << '\n';
        }
    }
}
