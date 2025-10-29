#include "ArchivoManager.h"

/*
bool ArchivoManager::grabarEnDisco(const char* nombreArchivo, const Alumno& objeto) {

    FILE* p{ fopen(nombreArchivo, "ab") };

    if (p == nullptr)
        return false;

    size_t cantidadLeida{ fwrite(&objeto, sizeof(Alumno), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}

bool ArchivoManager::grabarEnDisco(const char* nombreArchivo, const Docente& objeto) {

    FILE* p{ fopen(nombreArchivo, "ab") };

    if (p == nullptr)
        return false;

    size_t cantidadLeida{ fwrite(&objeto, sizeof(Docente), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}

bool ArchivoManager::grabarEnDisco(const char* nombreArchivo, const Curso& objeto) {

    FILE* p{ fopen(nombreArchivo, "ab") };

    if (p == nullptr)
        return false;

    size_t cantidadLeida{ fwrite(&objeto, sizeof(Curso), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}*/

bool ArchivoManager::grabarEnDisco(const char* nombreArchivo, const Inscripcion& objeto) {

    FILE* p{ fopen(nombreArchivo, "ab") };

    if (p == nullptr)
        return false;

    size_t cantidadLeida{ fwrite(&objeto, sizeof(Inscripcion), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}

/*
bool ArchivoManager::leerDeDisco(const char* nombreArchivo, const Alumno& objeto, int pos) {

    FILE* p{ fopen(nombreArchivo, "rb") };

    if (p == nullptr)
        return false;

    fseek(p, pos * sizeof(Alumno), SEEK_SET);

    size_t cantidadLeida{ fread(&objeto, sizeof(Alumno), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}

bool ArchivoManager::leerDeDisco(const char* nombreArchivo, const Docente& objeto, int pos) {

    FILE* p{ fopen(nombreArchivo, "rb") };

    if (p == nullptr)
        return false;

    fseek(p, pos * sizeof(Docente), SEEK_SET);

    size_t cantidadLeida{ fread(&objeto, sizeof(Docente), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}

bool ArchivoManager::leerDeDisco(const char* nombreArchivo, const Curso& objeto, int pos) {

    FILE* p{ fopen(nombreArchivo, "rb") };

    if (p == nullptr)
        return false;

    fseek(p, pos * sizeof(Curso), SEEK_SET);

    size_t cantidadLeida{ fread(&objeto, sizeof(Curso), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}*/

bool ArchivoManager::leerDeDisco(const char* nombreArchivo, Inscripcion& objeto, int pos) {

    FILE* p{ fopen(nombreArchivo, "rb") };

    if (p == nullptr)
        return false;

    fseek(p, pos * sizeof(Inscripcion), SEEK_SET);

    size_t cantidadLeida{ fread(&objeto, sizeof(Inscripcion), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}

/*
bool ArchivoManager::sobrescribirRegistro(const char* nombreArchivo, const Alumno& objeto, int pos) {

    FILE* p{ fopen(nombreArchivo, "rb+") };

    if (p == nullptr)
        return false;

    fseek(p, sizeof(Alumno) * pos, SEEK_SET);
    size_t cantidadLeida{ fwrite(&objeto, sizeof(Alumno), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}

bool ArchivoManager::sobrescribirRegistro(const char* nombreArchivo, const Docente& objeto, int pos) {

    FILE* p{ fopen(nombreArchivo, "rb+") };

    if (p == nullptr)
        return false;

    fseek(p, sizeof(Docente) * pos, SEEK_SET);
    size_t cantidadLeida{ fwrite(&objeto, sizeof(Docente), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}

bool ArchivoManager::sobrescribirRegistro(const char* nombreArchivo, const Curso& objeto, int pos) {

    FILE* p{ fopen(nombreArchivo, "rb+") };

    if (p == nullptr)
        return false;

    fseek(p, sizeof(Curso) * pos, SEEK_SET);
    size_t cantidadLeida{ fwrite(&objeto, sizeof(Curso), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}*/

bool ArchivoManager::sobrescribirRegistro(const char* nombreArchivo, const Inscripcion& objeto, int pos) {

    FILE* p{ fopen(nombreArchivo, "rb+") };

    if (p == nullptr)
        return false;

    fseek(p, sizeof(Inscripcion) * pos, SEEK_SET);
    size_t cantidadLeida{ fwrite(&objeto, sizeof(Inscripcion), 1, p) };
    fclose(p);

    return (cantidadLeida == 1);
}

/*
int ArchivoManager::contarRegistrosAlumno(const char* nombreArchivo) {
    FILE* p{fopen(nombreArchivo, "rb")};

    if (p == nullptr) {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    size_t tamanio{ftell(p) / sizeof(Alumno)};

    fclose(p);
    return static_cast<int>(tamanio);
}

int ArchivoManager::contarRegistrosDocente(const char* nombreArchivo) {
    FILE* p{fopen(nombreArchivo, "rb")};

    if (p == nullptr) {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    size_t tamanio{ftell(p) / sizeof(Docente)};

    fclose(p);
    return static_cast<int>(tamanio);
}

int ArchivoManager::contarRegistrosCurso(const char* nombreArchivo) {
    FILE* p{fopen(nombreArchivo, "rb")};

    if (p == nullptr) {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    size_t tamanio{ftell(p) / sizeof(Curso)};

    fclose(p);
    return static_cast<int>(tamanio);
}*/

int ArchivoManager::contarRegistrosInscripcion(const char* nombreArchivo) {
    FILE* p{fopen(nombreArchivo, "rb")};

    if (p == nullptr) {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    size_t tamanio{ ftell(p) / sizeof(Inscripcion) };

    fclose(p);
    return static_cast<int>(tamanio);
}
