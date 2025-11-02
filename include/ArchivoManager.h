/**
 * @file ArchivoManager.h
 * @brief Gestor de operaciones de archivo para el sistema académico
 * @author Diego J D Arias, Noelia Sueldo.
 * @date 2025-11-02
 * @version 1.0
 * @copyright MIT License
 * @see Alumno, Doncente, Curso e Inscripcion.
 *
 * Clase utilitaria para manejar todas las operaciones de lectura/escritura
 * en archivos binarios del sistema. Proporciona métodos genéricos para
 * diferentes entidades del sistema académico.
 */

#ifndef ARCHIVOMANAGER_H
#define ARCHIVOMANAGER_H

#include "Inscripcion.h"


class ArchivoManager {
public:
    ArchivoManager() = default;
    /*bool grabarEnDisco(const char* nombreArchivo, const Alumno& objeto);
    bool grabarEnDisco(const char* nombreArchivo, const Docente& objeto);
    bool grabarEnDisco(const char* nombreArchivo, const Curso& objeto);*/
    bool grabarEnDisco(const char* nombreArchivo, const Inscripcion& objeto);

    /*bool leerDeDisco(const char* nombreArchivo, Alumno& objeto, int pos);
    bool leerDeDisco(const char* nombreArchivo, Docente& objeto, int pos);
    bool leerDeDisco(const char* nombreArchivo, Curso& objeto, int pos);*/
    bool leerDeDisco(const char* nombreArchivo, Inscripcion& objeto, int pos);

    /*bool sobrescribirRegistro(const char* nombreArchivo, const Alumno& objeto, int pos);
    bool sobrescribirRegistro(const char* nombreArchivo, const Docente& objeto, int pos);
    bool sobrescribirRegistro(const char* nombreArchivo, const Curso& objeto, int pos);*/
    bool sobrescribirRegistro(const char* nombreArchivo, const Inscripcion& objeto, int pos);

    /*int contarRegistrosAlumno(const char* nombreArchivo);
    int contarRegistrosDocente(const char* nombreArchivo);
    int contarRegistrosCurso(const char* nombreArchivo);*/
    int contarRegistrosInscripcion(const char* nombreArchivo);
};

#endif // ARCHIVOMANAGER_H
