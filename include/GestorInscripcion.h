/**
 * @file GestorInscripcion.h
 * @brief Definición de la clase GestorInscripcion para el sistema académico
 * @author Diego J D Arias, Noelia Sueldo.
 * @date 2025-11-07
 * @version 1.0
 * @copyright MIT License
 */


#ifndef GESTORINSCRIPCION_H
#define GESTORINSCRIPCION_H

#include "Inscripcion.h"
#include "ArchivoManager.h"


class GestorInscripcion {
private:
    const char* NOMBRE_ARCHIVO{ "inscripcion.dat" };

public:
    GestorInscripcion();
    void nuevaInscripcion();
    int obtenerUltimoId();
    void listarInscripciones() const;
};

#endif // GESTORINSCRIPCION_H
