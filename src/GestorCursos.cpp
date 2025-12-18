//Nombre: Noelia Sueldo
//TP N°:
//EJ N°:
//Comentario:
#include <iostream>
#include "GestorCursos.h"
#include "ArchivoManager.h"
#include "Curso.h"
using namespace std;

int GestorCursos::obtenerUltimoIdCurso(){

    Curso curso;
    int pos = 0;
    int ultimo = 0;

    ArchivoManager archivo;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, curso, pos)){
        if (curso.getIdCurso() > ultimo){
            ultimo = curso.getIdCurso();
    }
    pos++;
}
    return ultimo + 1;
}


void GestorCursos::nuevoCurso() {
    Curso nuevoC;
    ArchivoManager archivo;

    int id = obtenerUltimoIdCurso();
    cout << "ID asignado: " << id << endl;

    string nombreCurso;
    int aula, legajoDocente;

    cout << "Ingrese el nombre del curso: ";
    cin.ignore();
    getline (cin, nombreCurso);
    cout << "Ingrese numero de aula: ";
    cin >> aula;
    cout << "Ingrese el Legajo del docente asignado: ";
    cin  >> legajoDocente;

    nuevoC.setIdCurso(id);
    nuevoC.setNombreCurso(nombreCurso);
    nuevoC.setNumeroAula(aula);
    nuevoC.setLegajoDocente(legajoDocente);
    nuevoC.setEliminado(false);

    archivo.grabarEnDisco(NOMBRE_ARCHIVO, nuevoC);

    cout << "Curso registrado correctamente.";
    system ("pause");

}

void GestorCursos::listarCursos() {
    Curso listar;
    ArchivoManager archivo;
    int pos = 0;

    cout << "-----------------------------------------------" << endl;
    cout << "LISTADO DE CURSOS "<< endl;
    cout << "-----------------------------------------------" << endl;


    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, listar, pos++)) {
        if (!listar.getEliminado()) {
             listar.Mostrar();
    cout << "-----------------------------------------------" << endl;
        }

    }
         system ("pause");
}

void GestorCursos::buscarCursosPorID() {
    Curso buscarCurso;
    ArchivoManager archivo;
    int  pos = 0;
    int id;

    cout << "Ingrese el ID del curso: ";
    cin  >> id;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, buscarCurso ,pos++)) {
        if (!buscarCurso.getEliminado() && buscarCurso.getIdCurso() == id) {
            cout << "Curso encontrado: "<< endl;
            cout << "-----------------------------------------------" << endl;
            buscarCurso.Mostrar();
            system ("pause");
            return;
        }
    }

    cout << "ID no encontrado" << endl;
      system ("pause");
}

void GestorCursos::modificarCursos() {
    Curso ModCurso;
    ArchivoManager archivo;
    int pos = 0;
    int IDBuscar;

    cout << " Ingrese el ID del curso a modificar: ";
    cin  >> IDBuscar;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, ModCurso, pos)) {
        if (ModCurso.getIdCurso() == IDBuscar && !ModCurso.getEliminado()) {
            cout << "DATOS DEL CURSO A MODIFICAR "<< endl;
            ModCurso.Mostrar();

            cout << endl;
            cout << endl;
            cout << "Seleccione el dato a modificar: " << endl;
            cout << "1. Nombre del curso"<< endl;
            cout << "2. Numero de aula " << endl;
            cout << "3. Legajo del Docente"<< endl;
            cout << "0. Cancelar"<< endl;
            cout << "Elija una Opcion: "<< endl;
            cout << endl;

            int opcion;
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
        case 1: {
            string nombre;
            cout << "Ingrese el nuevo nombre del curso: ";
            getline(cin, nombre);
            ModCurso.setNombreCurso(nombre);
        } break;

        case 2: {
            int aula;
            cout << "Ingrese el nuevo numero de aula: ";
            cin >> aula;
            ModCurso.setNumeroAula(aula);
        } break;

        case 3: {
            int legajo;
            cout << "Ingrese el nuevo legajo del docente: ";
            cin >> legajo;
            ModCurso.setLegajoDocente(legajo);
        } break;

        case 0:
            cout << "Modificacion canelada";
            return;

        default:
            cout << "Opcion Invalida";
            return;
            }

            archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, ModCurso, pos);
            cout << "Curso modificado con exito";
            system ("pause");
            return;
        }
        pos++;
    }

    cout << "Curso no encontrado";
    system ("pause");
}

void GestorCursos::darBajaCurso()  {
    Curso bajaCurso;
    ArchivoManager archivo;
    int pos;
    int cursoID;

    cout << "Ingrese el ID del curso a dar de baja: ";
    cin >> cursoID;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO,bajaCurso,pos)) {
        if (bajaCurso.getIdCurso() == cursoID &&  !bajaCurso.getEliminado()) {
            bajaCurso.setEliminado(true);
            archivo.sobrescribirRegistro(NOMBRE_ARCHIVO,bajaCurso, pos);

            cout << "Curso dado de baja correctamente";
            system ("pause");
            return;
        }
        pos++;
    }
    cout << "Id no encontrado";
    system ("pause");
}

void  GestorCursos::mostrarCursosDeBaja() {
    Curso MostarCursoBaja;
    ArchivoManager archivo;
    int pos =0;

    cout << "-----------------------------------------------" << endl;
    cout << "CURSOS DADOS DE BAJA "<< endl;
    cout << "-----------------------------------------------" << endl;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, MostarCursoBaja, pos++)) {
        if (MostarCursoBaja.getEliminado()){
            MostarCursoBaja.Mostrar();
    cout << "-----------------------------------------------" << endl;
        }
    }
    system ("pause");
}

void GestorCursos::backup() const {
    system("cls");
    ArchivoManager archivo;

    if (archivo.hacerBackup(NOMBRE_ARCHIVO, ARCHIVO_BAK)) {
        std::cout << "BackUp realizado con exito!: \n"; system("pause");
    } else {
        std::cerr << "No se pudo realizar el BackUp!: \n"; system("pause");
    }
}

void GestorCursos::restaurar() const {
    system("cls");
    ArchivoManager archivo;

    if (archivo.hacerBackup(ARCHIVO_BAK, NOMBRE_ARCHIVO)) {
        std::cout << "La Restauracion fue exitosa!: \n"; system("pause");
    } else {
        std::cerr << "No se pudo realizar la Restauracion!: \n"; system("pause");
    }
}
