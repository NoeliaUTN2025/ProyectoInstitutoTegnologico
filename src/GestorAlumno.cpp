//Nombre: Noelia Sueldo
//TP N°:
//EJ N°:
//Comentario:
#include <iostream>
#include "GestorAlumno.h"
#include "Alumno.h"
#include "ArchivoManager.h"
#include<limits>
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

bool GestorAlumno::existeDNI(const std::string &dni) {
    Alumno alumno;
    ArchivoManager archivo;
    int pos = 0;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos++)){
        if (!alumno.getEliminado() && alumno.getDni() == dni){
            return true;
        }
    }
    return false;
}

void GestorAlumno::nuevoAlumno(){
    Alumno nuevo;
    ArchivoManager archivo;

    int legajo = obtenerUltimoLegajo();
    cout << "-----------------------------------------------" << endl;
    cout << "ALTA DE NUEVO ALUMNO "<< endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Legajo Asignado: " << legajo << endl;
    cout << endl;

   string  dni, nombre, apellido, telefono, email, direccion;
    int dia, mes, anio;

    /// validar DNI

    while (true){
    cout << "Ingrese DNI del alumno:";
    cin >> dni;
    if (dni.size() == 0){
        cout << "ERROR: el DNI no puede estar vacio";
        continue;
    }
    bool soloNumeros = true;
    for (int i=0; i <dni.size(); i++){
        if (dni[i] < '0' || dni[i] > '9'){
            soloNumeros = false;
            break;
        }
    }
    if (!soloNumeros) {
        cout << "ERROR: El DNI debe contener solo numeros";
        continue;
    }
    if (existeDNI(dni)){
        cout << "ERROR: Ya existe un alumno registrado con ese DNI" ;
        continue;
    }
    break;
    }

    /// validar nombre

    while (true){
    cout << "Ingrese el nombre:";
    cin >> nombre;
    if (nombre.size() == 0){
        cout << "ERROR: El nombre no puede estar vacio.";
    }
    else break;

    }

   /// validad apellido

    while (true){
    cout << "Ingrese el apellido:";
    cin >> apellido;
    if (apellido.size() == 0){
        cout << "ERROR: El nombre no puede estar vacio.";
    }
    else break;

}

    /// validar fecha
    while (true){
    cout << "Ingrese la fecha de nacimiento: ";
    cout << "Dia:";
    cin >> dia;
    cout << "Mes:";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;

    if (anio < 1900 || anio > 2025){
        cout << "ERROR: Año fuera de rango";
        continue;
    }
    if (mes < 1 || mes > 12){
        cout << "ERROR; Mes invalido";
        continue;
    }
    int diasMes;
    switch (mes) {
    case 1: case 3: case 5: case 7:  case 8: case 10: case 12:
        diasMes = 31; break;
    case 4: case 6: case 9: case 11:
        diasMes =30; break;
    case 2:
        diasMes = 29; break;

    }
    if (dia < 1 || dia > diasMes){
        cout << "Dia invalido para ese mes, ingrese un dia correcto.";
        continue;
    }
    break;
}


    Fecha f;
    f.setDia(dia);
    f.setMes(mes);
    f.setAnio(anio);

        ///validar telefono
        while (true){
            cout << "Ingrese el telefono: ";
            cin >> telefono;
        if (telefono.size() == 0) cout << "ERROR: Debe ingresar un telefono";
        else break;
        }

        /// validar email
        while (true){
            cout << "Ingrese el Email: ";
            cin >> email;
        if (email.size() == 0) cout << "ERROR: Debe ingresar un email";
        else break;
        }

        /// validar direccion
        while (true){
            cout << "Ingrese la direccion: ";
            cin >> direccion;
        if (direccion.size() == 0) cout << "ERROR: Debe ingresar un direccion";
        else break;
        }


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

    cout << "-----------------------------------------------" << endl;
    cout << "LISTADO DE ALUMNOS" << endl;
     cout << "-----------------------------------------------" << endl;
    cout << endl;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos)){
        if (!alumno.getEliminado()){
            alumno.Mostrar();

            cout << "-----------------------------------------------" << endl;
        }
        pos++;
    }
     system("pause");
}


void  GestorAlumno::buscarAlumnosPorLegajo() {
    Alumno alumno;
    int pos = 0;
    int legajo;


    ArchivoManager archivo;

    cout << "-----------------------------------------------" << endl;
    cout << " BUSCAR ALUMNOS POR LEGAJO" << endl;
     cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << "Ingrese el Legajo del alumno:";
    cin  >> legajo;

    bool encontrado = false;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos++)){
        if (!alumno.getEliminado() && alumno.getLegajoAlumno() == legajo){

    cout << "-----------------------------------------------" << endl;
        alumno.Mostrar();

        encontrado = true;
        break;
    }
}
                if (!encontrado){
                    cout << "Alumno no enconcontrado"<< endl;

}
     system("pause");
}


void GestorAlumno::buscarAlumnosPorDNI() {

    Alumno alumno;
    int pos = 0;
    std::string  dni;


    ArchivoManager archivo;

    cout << "-----------------------------------------------" << endl;
    cout << "BUSCAR ALUMNOS POR DNI" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << "Ingrese el DNI del alumno:" << endl;
    cin  >> dni;

    bool encontrado = false;
    bool eliminado = false;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos)) {
            if (alumno.getDni()== dni){
                if (alumno.getEliminado()){
                    eliminado = true;
                } else{
        cout << "-----------------------------------------------" << endl;
        cout << "Alumno encontrado"<< endl;
        cout << "-----------------------------------------------" << endl;
                    alumno.Mostrar();
                }

        encontrado = true;
        break;
    }
    pos++;
    }
                if (!encontrado){
                    cout << "No existe ningun alumno con  ese DNI"<< endl;

}
    else  if (eliminado) {
            cout << "El alumno se encuentra DADO DE BAJA" << endl;
    }
     system("pause");
}


void GestorAlumno::modificarAlumno(){
    Alumno alumno;
    int pos = 0;
    std::string  dni;

    ArchivoManager archivo;

    cout << "-----------------------------------------------" << endl;
    cout << "MODIFICAR ALUMNO " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << "Ingrese el DNI del alumno que desea modificar" << endl;
    cin >> dni;

    bool encontrado = false;


    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos)){
        if (alumno.getDni() ==  std::string (dni) && !alumno.getEliminado()) {

    encontrado = true;

    cout << "-----------------------------------------------" << endl;
    cout << "DATOS ACTUALES " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;

        alumno.Mostrar();
        cout << "-----------------------------------------------" << endl;
        cout << "¿Que datos desea modificar?"<< endl;
        cout << "1. Nombre"<< endl;
        cout << "2. Apellido"<< endl;
        cout << "3. DNI"<< endl;
        cout << "4. Fecha de Nacimiento"<< endl;
        cout << "5. Telefono"<< endl;
        cout << "6. Email"<< endl;
        cout << "7. Direccion"<< endl;
        cout << "0. Cancelar"<< endl;
        cout << "Elija una opcion:"<< endl;

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
    }
            archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, alumno, pos);

            cout << "Alumno modificado con exito.";
            system("pause");
            return;

    }
        pos ++;
    }
            if (!encontrado){
                     cout << "Alumno no encontrado" << endl;
                        system("pause");
        }
}


void GestorAlumno::darBajaAlumno(){
    int opcion;
    cout << "-----------------------------------------------" << endl;
    cout << "BAJA DE ALUMNO " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Como deseas buscar al alumno?" << endl;
    cout << "1. por DNI" << endl;
    cout << "2. Por Legajo" << endl;
    cout << "Opcion: " << endl;
    cin  >> opcion;

ArchivoManager archivo;
Alumno bajaAlumno;
int pos = 0;
bool encontrado = false;

    std::string  dni;
    int legajo;

    ////////////POR DNI////////////

    if (opcion == 1){
    cout << "Ingrese el dni del alumno que desea dar de baja: ";
    cin  >>  dni;


while (archivo.leerDeDisco(NOMBRE_ARCHIVO, bajaAlumno, pos)) {
    if (bajaAlumno.getDni() == dni && !bajaAlumno.getEliminado()){
        encontrado = true;

    cout << "-----------------------------------------------" << endl;
    cout << "DATOS ACTUALES " << endl;
    cout << "-----------------------------------------------" << endl;
        bajaAlumno.Mostrar();

        char confirmar;
        cout << "¿Confirma la baja del alumno? (S/N: )";
        cin >> confirmar;

        if (confirmar == 'S' || confirmar == 's'){
            bajaAlumno.setEliminado(true);
            archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, bajaAlumno, pos);
            cout << "Alumno dado de baja correctamente"<< endl;
        } else {
            cout << "Baja cancelada por el usuario" << endl;
        }

        system ("pause");
       return;

    }
    pos++;
}

        cout << "ERROR: DNI no encontrado"<< endl;
        system ("pause");
       return;
}


    /////////////POR LEGAJO///////////

else if (opcion == 2){
    cout << "Ingrese el legajo del alumno que desea dar de baja: ";
    cin  >>  legajo;


while (archivo.leerDeDisco(NOMBRE_ARCHIVO, bajaAlumno, pos)) {
    if (bajaAlumno.getLegajoAlumno() == legajo && !bajaAlumno.getEliminado()){
        encontrado = true;

    cout << "-----------------------------------------------" << endl;
    cout << "DATOS ACTUALES " << endl;
    cout << "-----------------------------------------------" << endl;
        bajaAlumno.Mostrar();

        char confirmar;
        cout << "¿Confirma la baja del alumno? (S/N: )";
        cin >> confirmar;

        if (confirmar == 'S' || confirmar == 's'){
            bajaAlumno.setEliminado(true);
            archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, bajaAlumno, pos);
            cout << "Alumno dado de baja correctamente"<< endl;
        } else {
            cout << "Baja cancelada por el usuario" << endl;
        }

        system ("pause");
       return;

    }
    pos++;
}
        cout << "ERROR: Legajo no encontrado"<< endl;
        system ("pause");
       return;
        }
        else {
            cout << "Opcion inválida." << endl;
        system ("pause");
       return;
        }
}



void GestorAlumno::mostrarAlumnosDeBaja(){
    Alumno alumno;
    ArchivoManager archivo;
    int pos = 0;

    cout << "-----------------------------------------------" << endl;
    cout << "ALUMNOS DADOS DE BAJA " << endl;
    cout << "-----------------------------------------------" << endl;

while (archivo.leerDeDisco(NOMBRE_ARCHIVO, alumno, pos)){
    if (alumno.getEliminado() ){
            alumno.Mostrar();
    cout << "-----------------------------------------------" << endl;

        }
        pos++;
    }
         system("pause");
}

void GestorAlumno::backup() const {
    system("cls");
    ArchivoManager archivo;

    if (archivo.hacerBackup(NOMBRE_ARCHIVO, ARCHIVO_BAK)) {
        std::cout << "BackUp realizado con exito!: \n"; system("pause");
    } else {
        std::cerr << "No se pudo realizar el BackUp!: \n"; system("pause");
    }
}

void GestorAlumno::restaurar() const {
    system("cls");
    ArchivoManager archivo;

    if (archivo.hacerBackup(ARCHIVO_BAK, NOMBRE_ARCHIVO)) {
        std::cout << "La Restauracion fue exitosa!: \n"; system("pause");
    } else {
        std::cerr << "No se pudo realizar la Restauracion!: \n"; system("pause");
    }
}
