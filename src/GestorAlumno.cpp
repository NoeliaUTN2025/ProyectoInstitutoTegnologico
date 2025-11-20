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
    Alumno aux;
    int pos =0;
    int ultimoLejago =0;

    ArchivoManager archivo;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, aux, pos++)){
        if (aux.getLegajoAlumno() > ultimoLejago){
            ultimoLejago = aux.getLegajoAlumno();
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
