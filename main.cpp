/**
 * @file main.cpp
 * @brief Punto de entrada principal del Sistema de Gestión
 * @author Diego J D Arias, Noelia Sueldo
 * @date 2025-11-06
 * @version 1.0
 * @copyright MIT License
 *
 * @mainpage Sistema de Gestión - Documentación Principal
 * Este es el sistema principal de gestión desarrollado en C++.
 * El flujo de ejecución comienza en este archivo y delega
 * inmediatamente a la clase Menu para el control de la aplicación.
 */


#include <iostream>
#include <Menu.h>


int main(){
    Menu menu;

    // Se lanza el menu principal del sistema.
    menu.start();

    return 0;
}
