/**
 * @file Menu.h
 * @brief Definición de la clase Menu para el manejo de todos los menus del sistema.
 * @author Diego J D Arias, Noelia Sueldo.
 * @date 2025-11-06
 * @version 1.0
 * @copyright MIT License
 *
 * Clase para representar y manipular los menus del sistema académico.
 */


#ifndef MENU_H
#define MENU_H
#include <string>


class Menu{
public:
    Menu() = default;
    void start() const;
    void menuStudent()const;
    void menuTeacher() const;
    void menuCourse() const;
    void menuRegistration()const;
    void menuReports() const;
    void menuBackup() const;
    void draw(const std::string* options, int arrayLength) const;
    void menuRealizarBackup() const;
    void menuRestaurar()const;
    int validation() const;
    void menuBaja() const;
};

#endif // MENU_H
