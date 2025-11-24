#ifndef GESTORDOCENTE_H_INCLUDED
#define GESTORDOCENTE_H_INCLUDED

#include <Docente.h>
#include "ArchivoManager.h"


class GestorDocente {
private:
    const char* NOMBRE_ARCHIVO = "docentes.dat";
    const char* ARCHIVO_BAK = "docentes.bak";


public:
    GestorDocente() = default;

    int obtenerUltimoLegajoDocente();
    void nuevoDocente();
    void listarDocentes() ;
    void  buscarDocentesPorLegajo();
     void buscarDocentesPorDNI();
    void modificarDocentes();
    void darBajaDocentes();
    void mostrarDocentesDeBaja() ;

    void backup() const;
    void restaurar() const;

};


#endif // GESTORDOCENTE_H_INCLUDED
