//Nombre: Noelia Sueldo
//TP N°:
//EJ N°:
//Comentario:
#include <iostream>
#include "GestorAlumno.h"
#include "Alumno.h"
#include "ArchivoManager.h"
using namespace std;

int GestorAlumno::obtenerUltimoLegajo(){
    Alumno alumno;
    int pos =0;
    int ultimoLejago =0;

    ArchivoManager archivo;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos++)){
        if (alumno.getLegajoAlumno() > ultimoLejago){
            ultimoLejago = alumno.getLegajoAlumno();
        }
    }
        return ultimoLejago + 1;

}

void GestorAlumno::nuevoAlumno(){
    Alumno nuevo;
    ArchivoManager archivo;

    int legajo = obtenerUltimoLegajo();
    cout << "--------------------------------------------------------" << endl;
    cout << "-----------ALTA DE NUEVO ALUMNO -----------"<< endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Legajo Asignado: " << legajo << endl;
    cout << endl;

   string  dni, nombre, apellido, telefono, email, direccion;
    int dia, mes, anio;

    cout << "Ingrese DNI del alumno:";
    cin >> dni;
    cout << "Ingrese el nombre:";
    cin >> nombre;
    cout << "Ingrese el apellido:";
    cin >> apellido;

    cout << "Ingrese la fecha de nacimiento: ";
    cout << "Dia:";
    cin >> dia;
    cout << "Mes:";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;

    Fecha f;
    f.setDia(dia);
    f.setMes(mes);
    f.setAnio(anio);

    cout << "Ingresel telefono: ";
    cin >> telefono;
    cout << "Ingrese el email: ";
    cin >> email;
    cout <<  "Ingrese la direccion: ";
    cin  >> direccion;

    nuevo.setLegajoAlumno(legajo);
    nuevo.setDni(dni);
    nuevo.setNombre(nombre);
    nuevo.setApellido(apellido);
    nuevo.setFechaNacimiento(f);
    nuevo.setTelefono(telefono);
    nuevo.setEmail(email);
    nuevo.setDireccion(direccion);
    nuevo.setEliminado(false);

    archivo.grabarEnDisco(NOMBRE_ARCHIVO, nuevo);

    cout << "Alumno registrado con exito.";
    system("pause");

}

void  GestorAlumno::listarAlumnos() {
    Alumno alumno;
    int pos = 0;

    ArchivoManager archivo;

    cout << "------------LISTADO DE ALUMNOS--------------" << endl;
    cout << endl;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos)){
        if (!alumno.getEliminado()){
            alumno.Mostrar();

            cout << "--------------------------------------------------------------" << endl;
        }
    }

}


void  GestorAlumno::buscarAlumnosPorLegajo() {
    Alumno alumno;
    int pos = 0;
    int legajo;


    ArchivoManager archivo;

    cout << "------------ BUSCAR ALUMNOS POR LEGAJO--------------" << endl;
    cout << endl;
    cout << "Ingrese el Legajo del alumno:";
    cin  >> legajo;

    bool encontrado = false;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos++)){
        if (!alumno.getEliminado() && alumno.getLegajoAlumno() == legajo)

            cout << "------------------Alumno encontrado--------------------";
        alumno.Mostrar();

        encontrado = true;
        break;
    }
                if (!encontrado){
                    cout << "Alumno no enconcontrado"<< endl;

}

}


void GestorAlumno::buscarAlumnosPorDNI() {

    Alumno alumno;
    int pos = 0;
    std::string  dni;


    ArchivoManager archivo;

    cout << "------------ BUSCAR ALUMNOS POR DNI--------------" << endl;
    cout << endl;
    cout << "Ingrese el DNI del alumno:";
    cin  >> dni;

    bool encontrado = false;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos)) {
        if (!alumno.getEliminado() && alumno.getDni() ==  std::string (dni)){

        cout << "------------------Alumno encontrado--------------------";
        alumno.Mostrar();

        encontrado = true;
        break;
    }
    }
                if (!encontrado){
                    cout << "Alumno no enconcontrado"<< endl;

}

}


void GestorAlumno::modificarAlumno(){
    Alumno alumno;
    int pos = 0;
    std::string  dni;

    ArchivoManager archivo;

    cout << "------------ MODIFICAR ALUMNO --------------" << endl;
    cout << endl;
    cout << "Ingrese el DNI del alumno que desea modificar";
    cin >> dni;


    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos)){
        if (alumno.getDni() ==  std::string (dni) && !alumno.getEliminado()) {

        cout << "----------DATOS ACTUALES--------------" << endl;
        alumno.Mostrar();

        cout << "¿Que datos desea modificar?";
        cout << "1. Nombre";
        cout << "2. Apellido";
        cout << "3. DNI";
        cout << "4. Fecha de Nacimiento";
        cout << "5. Telefono";
        cout << "6. Email";
        cout << "7. Direccion";
        cout << "0. Cancelar";
        cout << "Elija una opcion:";

        int opcion;
        cin  >> opcion;

        cin.ignore();

        switch(opcion){
        case 1: {
            char nombre [50];
            cout << "Ingrese el nuevo Nombre: ";
            cin.getline(nombre, 50);
            alumno.setNombre(nombre);
        } break;

        case 2:{
            char apellido [50];
            cout << "Ingrese el nuevo Apellido: ";
            cin.getline(apellido, 50);
            alumno.setApellido(apellido);
        } break;

        case 3: {
            char dni [20];
            cout << "Ingrese el nuevo DNI: ";
            cin.getline(dni, 20);
            alumno.setDni(dni);
        } break;

        case 4: {
            Fecha f;
            int dia, mes, anio;
            cout << "Ingrese el dia: ";
            cin >> dia;
            cout << "Ingrese el mes: ";
            cin >> mes;
            cout << "Ingrese el Año: ";
            cin >> anio;
            f.setDia(dia);
            f.setMes(mes);
            f.setAnio(anio);

            alumno.setFechaNacimiento(f);
        } break;

        case 5: {
            char telefono [20];
            cout << "Ingrese el nuevo telefono: ";
            cin.getline(telefono, 20);
            alumno.setTelefono(telefono);
        } break;

        case 6: {
            char email [50];
            cout << "Ingrese el nuevo email: ";
            cin.getline(email, 50);
            alumno.setEmail(email);
        } break;

        case 7: {
            char direccion [100];
            cout << "Ingrese la nueva direccion: ";
            cin.getline(direccion, 100);
            alumno.setDireccion(direccion);
        } break;

        case 0: {
            cout << "Modificacion cancelada" << endl;
            system("pause");
            return;
        }

        default:{
            cout << "Opcion Invalida.";
            system("pause");
            return;
        }
            archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, alumno, pos);

            cout << "Alumno modificado con exito.";
            system("pause");
            return;

        }
        pos ++;

        }
                cout << "Alumno no encontrado" << endl;
                system("pause");
    }
}


void GestorAlumno::darBajaAlumno(){
    std::string  dni;

    cout << "Ingrese el dni del alumno que desea dar de baja: ";
    cin  >>  dni;

    Alumno bajaAlumno;

ArchivoManager archivo;
int pos = 0;
bool encontrado = false;

while (archivo.leerDeDisco(NOMBRE_ARCHIVO, bajaAlumno, pos)) {
    if (bajaAlumno.getDni() == dni && !bajaAlumno.getEliminado()){

        bajaAlumno.setEliminado(true);
        archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, bajaAlumno, pos);

        cout << "Alumno dado de baja correctamente";
        system ("pause");

        encontrado = true;
        break;

    }
    pos++;
}
        if (!encontrado){
        cout << "DNI no encontrado";
        system ("pause");
        }

    }


void GestorAlumno::mostrarAlumnosDeBaja(){
    Alumno alumno;
    ArchivoManager archivo;
    int pos = 0;

    cout << "-----------ALUMNOS DADOS DE BAJA-------------"<< endl;

while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos)){
    if (alumno.getEliminado() ){
            alumno.Mostrar();
    cout << "------------------------------------------------------------";

        }
    }
}
