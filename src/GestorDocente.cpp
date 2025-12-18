//Nombre: Noelia Sueldo
//TP N°:
//EJ N°:
//Comentario:
#include <iostream>
#include <GestorDocente.h>
#include <Docente.h>
#include "ArchivoManager.h"
#include<limits>
using namespace std;

int GestorDocente::obtenerUltimoLegajoDocente(){
    Docente docente;
    int pos =0;
    int ultimoLejago =0;

    ArchivoManager archivo;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, docente, pos++)){
        if (docente.getLegajoDocente() > ultimoLejago){
            ultimoLejago = docente.getLegajoDocente();
        }
    }
        return ultimoLejago + 1;

}

bool GestorDocente::existeDNI(const std::string &dni) {
    Docente  docente;
    ArchivoManager archivo;
    int pos = 0;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, docente, pos++)){
        if (!docente.getEliminado() && docente.getDni() == dni){
            return true;
        }
    }
    return false;
}

bool GestorDocente::ValidarTexto (const std::string &texto)  {
    if (texto.length() == 0) return false;

    for (int i=0;i < texto.length(); i++){
        char c = texto[i];

        bool esMayus = (c >= 'A' && c <= 'Z');
        bool esMinus = (c >= 'a' && c <= 'z');
        bool esEspacio = (c = ' ');

        if (!esMayus && !esMinus && esEspacio){

            return false;
        }
    }
    return true;
}


void GestorDocente::nuevoDocente(){
    Docente nuevoD;
    ArchivoManager archivo;

    int legajo = obtenerUltimoLegajoDocente();
    cout << "--------------------------------------------------------" << endl;
    cout << "ALTA DE NUEVO DOCENTE "<< endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Legajo Asignado: " << legajo << endl;
    cout << endl;


   string  dni, nombre, apellido, telefono, email, direccion;
    int dia, mes, anio;


    /// validar DNI

    while (true){
    cout << "Ingrese DNI del docente:";
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
        cout << "ERROR: Ya existe un docente registrado con ese DNI" << endl;
        continue;
    }
    break;
    }
       cin.ignore(numeric_limits<streamsize>::max(), '\n');

    /// validar nombre

    while (true){
    cout << "Ingrese el nombre: " << endl;
    getline (cin, nombre);


    if (!ValidarTexto(nombre)){
        cout << "ERROR: El nombre solo puede contener letras y espacios" << endl;
        continue;
    }
    break;
   }


   /// validad apellido

   while (true){
    cout << "Ingrese el apellido: " << endl;
    getline (cin, apellido);

    if (!ValidarTexto(apellido)){
        cout << "ERROR: El apellido solo puede contener letras y espacios" << endl;
        continue;
    }
    break;
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


    nuevoD.setLegajoDocente(legajo);
    nuevoD.setDni(dni);
    nuevoD.setNombre(nombre);
    nuevoD.setApellido(apellido);
    nuevoD.setFechaNacimiento(f);
    nuevoD.setTelefono(telefono);
    nuevoD.setEmail(email);
    nuevoD.setDireccion(direccion);
    nuevoD.setEliminado(false);

    archivo.grabarEnDisco(NOMBRE_ARCHIVO, nuevoD);

    cout << "Docente registrado con exito.";
    system("pause");

}


void  GestorDocente::listarDocentes() {
    Docente docente;
    int pos = 0;

    ArchivoManager archivo;

    cout << "-----------------------------------------------" << endl;
    cout << "LISTADO DE DOCENTES" << endl;
     cout << "-----------------------------------------------" << endl;
    cout << endl;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, docente, pos++)){
        if (!docente.getEliminado()){
            docente.Mostrar();

            cout << "-----------------------------------------------" << endl;
        }
        pos++;
    }
     system("pause");
}



void  GestorDocente::buscarDocentesPorLegajo() {
     Docente docente;
    int pos =0;
    int legajo;


    ArchivoManager archivo;

    cout << "------------ BUSCAR DOCENTE POR LEGAJO--------------" << endl;
    cout << endl;
    cout << "Ingrese el Legajo del docente:";
    cin  >> legajo;

    bool encontrado = false;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, docente, pos++)){
        if (!docente.getEliminado() && docente.getLegajoDocente() == legajo)

            cout << "------------------Docente encontrado--------------------";
        docente.Mostrar();

        encontrado = true;
        break;
    }
                if (!encontrado){
                    cout << "Docente no encontrado"<< endl;

}
     system("pause");
}


void GestorDocente::buscarDocentesPorDNI() {

     Docente docente;
    int pos =0;
    std::string  dni;


    ArchivoManager archivo;

    cout << "------------ BUSCAR DOCENTES POR DNI--------------" << endl;
    cout << endl;
    cout << "Ingrese el DNI del docente:";
    cin  >> dni;

    bool encontrado = false;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, docente, pos++)) {
        if (!docente.getEliminado() && docente.getDni() ==  std::string (dni)){

        cout << "------------------Docente encontrado--------------------" <<endl;
        docente.Mostrar();

        encontrado = true;
        break;
    }
    }
                if (!encontrado){
                    cout << "Docente no enconcontrado"<< endl;

}
     system("pause");
}


void GestorDocente::modificarDocentes(){
    Docente docente;
    int pos = 0;
    std::string  dni;

    ArchivoManager archivo;

    cout << "-----------------------------------------------" << endl;
    cout << "MODIFICAR DOCENTE " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << "Ingrese el DNI del docente que desea modificar" << endl;
    cin >> dni;

    bool encontrado = false;


    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, docente, pos)){
        if (docente.getDni() ==  std::string (dni) && !docente.getEliminado()) {

    encontrado = true;

    cout << "-----------------------------------------------" << endl;
    cout << "DATOS ACTUALES " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;

        docente.Mostrar();
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
            docente.setNombre(nombre);
        } break;

        case 2:{
            char apellido [50];
            cout << "Ingrese el nuevo Apellido: ";
            cin.getline(apellido, 50);
            docente.setApellido(apellido);
        } break;

        case 3: {
            char dni [20];
            cout << "Ingrese el nuevo DNI: ";
            cin.getline(dni, 20);
            docente.setDni(dni);
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

            docente.setFechaNacimiento(f);
        } break;

        case 5: {
            char telefono [20];
            cout << "Ingrese el nuevo telefono: ";
            cin.getline(telefono, 20);
            docente.setTelefono(telefono);
        } break;

        case 6: {
            char email [50];
            cout << "Ingrese el nuevo email: ";
            cin.getline(email, 50);
            docente.setEmail(email);
        } break;

        case 7: {
            char direccion [100];
            cout << "Ingrese la nueva direccion: ";
            cin.getline(direccion, 100);
            docente.setDireccion(direccion);
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
            archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, docente, pos);

            cout << "Docente modificado con exito.";
            system("pause");
            return;

    }
        pos ++;
    }
            if (!encontrado){
                     cout << "Docente no encontrado" << endl;
                        system("pause");
        }
}



void GestorDocente::darBajaDocentes(){
    std::string  dni;

    cout << "Ingrese el dni del docente que desea dar de baja: ";
    cin  >>  dni;

    Docente cajaDocente;

ArchivoManager archivo;
int pos = 0;
bool encontrado = false;

while (archivo.leerDeDisco(NOMBRE_ARCHIVO, cajaDocente, pos)) {
    if (cajaDocente.getDni() == dni && !cajaDocente.getEliminado()){

        cajaDocente.setEliminado(true);
        archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, cajaDocente, pos);

        cout << "Docente dado de baja correctamente";
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


void GestorDocente::mostrarDocentesDeBaja(){
     Docente docente;
    int pos =0;
    ArchivoManager archivo;
    bool hayBaja = false;

    cout << "-----------DOCENTES DADOS DE BAJA-------------"<< endl;

while (archivo.leerDeDisco(NOMBRE_ARCHIVO, docente, pos++)){
    if (docente.getEliminado() ){
            docente.Mostrar();
    cout << "------------------------------------------------------------";
     hayBaja = true;

        }
}
        if (!hayBaja) {
            cout << "No hay Docentes dados de baja" << endl;
        }
        system("pause");
}

void GestorDocente::backup() const {
    system("cls");
    ArchivoManager archivo;

    if (archivo.hacerBackup(NOMBRE_ARCHIVO, ARCHIVO_BAK)) {
        std::cout << "BackUp realizado con exito!: \n"; system("pause");
    } else {
        std::cerr << "No se pudo realizar el BackUp!: \n"; system("pause");
    }
}

void GestorDocente::restaurar() const {
    system("cls");
    ArchivoManager archivo;

    if (archivo.hacerBackup(ARCHIVO_BAK, NOMBRE_ARCHIVO)) {
        std::cout << "La Restauracion fue exitosa!: \n"; system("pause");
    } else {
        std::cerr << "No se pudo realizar la Restauracion!: \n"; system("pause");
    }
}

