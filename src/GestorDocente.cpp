//Nombre: Noelia Sueldo
//TP N°:
//EJ N°:
//Comentario:
#include <iostream>
#include <GestorDocente.h>
#include <Docente.h>
#include "ArchivoManager.h"
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

void GestorDocente::nuevoDocente(){
    Docente nuevoD;
    ArchivoManager archivo;

    int legajo = obtenerUltimoLegajoDocente();
    cout << "--------------------------------------------------------" << endl;
    cout << "-----------ALTA DE NUEVO DOCENTE -----------"<< endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Legajo Asignado: " << legajo << endl;
    cout << endl;

   string  dni, nombre, apellido, telefono, email, direccion;
    int dia, mes, anio;

    cout << "Ingrese DNI del Docente:";
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
    int pos =0;

    ArchivoManager archivo;

    cout << "------------LISTADO DE DOCENTES--------------" << endl;
    cout << endl;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, docente, pos)){
        if (!docente.getEliminado()){
            docente.Mostrar();

            cout << "--------------------------------------------------------------" << endl;
        }
    }

}


void  GestorDocente::buscarDocentesPorLegajo() {
     Docente docente;
    int pos =0;
    int legajo;


    ArchivoManager archivo;

    cout << "------------ BUSCAR DOCENTRD POR LEGAJO--------------" << endl;
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
                    cout << "Docente no enconcontrado"<< endl;

}

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

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, docente, pos)) {
        if (!docente.getEliminado() && docente.getDni() ==  std::string (dni)){

        cout << "------------------Docente encontrado--------------------";
        docente.Mostrar();

        encontrado = true;
        break;
    }
    }
                if (!encontrado){
                    cout << "Docente no enconcontrado"<< endl;

}

}


void GestorDocente::modificarDocentes(){
    Docente docente;
    int pos =0;
    std::string  dni;

    ArchivoManager archivo;

    cout << "------------ MODIFICAR DOCENTE --------------" << endl;
    cout << endl;
    cout << "Ingrese el DNI del docente que desea modificar";
    cin >> dni;


    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, docente, pos)){
        if (docente.getDni() ==  std::string (dni) && !docente.getEliminado()) {

        cout << "----------DATOS ACTUALES--------------" << endl;
        docente.Mostrar();

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
            archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, docente, pos);

            cout << "Docente modificado con exito.";
            system("pause");
            return;

        }
        pos ++;

        }
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


    cout << "-----------DOCENTES DADOS DE BAJA-------------"<< endl;

while (archivo.leerDeDisco(NOMBRE_ARCHIVO, docente, pos)){
    if (docente.getEliminado() ){
            docente.Mostrar();
    cout << "------------------------------------------------------------";

        }
    }
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

