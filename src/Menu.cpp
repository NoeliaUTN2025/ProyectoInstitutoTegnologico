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
    int opcion;
    do {
        system("cls");
        std::cout << "================================================\n";
        std::cout << "   SISTEMA DE GESTION - INSTITUTO TECNOLOGICO\n";
        std::cout << "================================================\n";
        std::cout << "1. Gestion de Alumnos\n";
        std::cout << "2. Gestion de Docentes\n";
        std::cout << "3. Gestion de Cursos\n";
        std::cout << "4. Gestion de Inscripciones\n";
        std::cout << "5. Reportes y Consultas\n";
        std::cout << "6. Copias de Seguridad\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: //menuAlumno(); break;
            case 2: //menuDocente(); break;
            case 3: //menuCurso(); break;
            case 4: menuRegistration(); break;
            case 5: //menuReporteInforme(); break;
            case 6: //menuBackupRestauracion(); break;
            case 0: std::cout << "Saliendo...\n"; break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (opcion != 0);
}

void Menu::menuRegistration()const {
    int opcion;
    do {
        system("cls");
        std::cout << "================================================\n";
        std::cout << "            GESTION - INCRIPCION\n";
        std::cout << "================================================\n";
        std::cout << "1. Nueva inscripción\n";
        std::cout << "2. Buscar inscripciones por alumno\n";  //@TODO: definir
        std::cout << "3. Buscar inscripciones por docente\n";
        std::cout << "4. Buscar inscripciones por curso\n";
        std::cout << "5. Dar de baja inscripción\n";
        std::cout << "0. Volver al menú principal\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1: //@TODO: definir
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 0: break;
            default: std::cout << "Opcion invalida!\n"; system("pause");
        }
    } while (opcion != 0);
}
