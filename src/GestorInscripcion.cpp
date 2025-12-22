/**
 * @file GestorInscripcion.cpp
 * @brief Implementacion de la clase GestorInscripcion
 * @author Diego J D Arias, Noelia Sueldo.
 * @date 2025-11-07
 * @version 1.0
 * @copyright MIT License
 */


#include "GestorInscripcion.h"
#include <iostream>
#include <string>
#include <iomanip>


int GestorInscripcion::obtenerUltimoId() {
    Inscripcion idInscripto;
    int pos{}, ultimoID{};
    ArchivoManager archivo;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, idInscripto, pos++))
    {
        if (idInscripto.getIdInscripcion() > ultimoID)
        {
            ultimoID = idInscripto.getIdInscripcion();
        }
    }
    return ultimoID + 1;
}

bool GestorInscripcion::existeAlumno(int legajo)  {
    Alumno Alumn;
    ArchivoManager archivo;
    int pos = 0;


    while (archivo.leerDeDisco("alumnos.dat", Alumn, pos++)){
        if (Alumn.getLegajoAlumno () == legajo && ! Alumn.getEliminado()){
            return true;
        }
    }
 return false;
}

bool GestorInscripcion::existeCurso(int idCurso)  {
    Curso Curs;
    ArchivoManager archivo;
    int pos = 0;



    while (archivo.leerDeDisco("cursos.dat", Curs, pos++)){
        if (Curs.getIdCurso() == idCurso && ! Curs.getEliminado()){
            return true;
        }
    }
return false;
}

   bool GestorInscripcion::existeInscripcion(int legajo, int idCurso)  {
    Inscripcion Insc;
    ArchivoManager archivo;
    int pos = 0;


    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, Insc, pos++)){
        if (!Insc.getEliminado() && Insc.getLegajoAlumno() == legajo && Insc.getCurso() == idCurso){
            return true;
        }
    }
return false;
}

void GestorInscripcion::nuevaInscripcion() {
    while(true)
    {
        system("cls");
        int legajo;
        std::cout << "Ingrese legajo del alumno: "; std::cin >> legajo;
        //validar alumno exista

        if (!existeAlumno(legajo)){
            std::cout << "Alumno insexistente o dado de baja";
            system("pause");
            continue;
        }

        int idCurso;
        std::cout << "Ingrese ID del curso: "; std::cin >> idCurso;
        //validar si existe el curso

        if (!existeCurso(idCurso)){
            std::cout << "Curso insexistente o dado de baja";
            system("pause");
            continue;
        }
            if (existeInscripcion(legajo, idCurso)){
            std::cout << "El Alumno ya se ha inscripto a este curso";
            system("pause");
            continue;
        }

        float importe;
        std::cout << "Ingrese el importe a abornar: "; std::cin >> importe;

        if (importe <= 0){
            std::cout << "El importe debe ser mayor a cero";
            system("pause");
            continue;
        }
        int opcion;

        std::string modalidad;
        std::cout << "Modalidad de pago: " <<std::endl;
        std::cout << "1. Efectivo"<<std::endl;
        std::cout << "2. Tarjeta Debito"<<std::endl;
        std::cout << "3. Tarjeta Credito"<<std::endl;
        std::cout << "Seleccione una opcion: "<<std::endl;
        std::cin >> opcion;

       switch (opcion){
        case 1:
            modalidad = "Efectivo";
            break;
        case 2:
            modalidad = "Tarjeta Debito";
            break;

        case 3:
            modalidad = "Tarjeta Credito";
            break;
            default:
            std::cout << "Opcion de pago Invalida, seleccione la opcion correcta.";
            system ("pause");
            continue;
       }

        int dia, mes, anio;
        std::cout << "Ingrese la fecha\nEl Dia: "; std::cin >> dia;
        std::cout << "El Mes: "; std::cin >> mes;
        std::cout << "El Anio: "; std::cin >> anio;

        Fecha fechaRegistrada;
        if (!fechaRegistrada.esFechaValida(dia, mes, anio)){
            continue;
        }

        fechaRegistrada.setDia(dia);
        fechaRegistrada.setMes(mes);
        fechaRegistrada.setAnio(anio);

        int m_idIscripcion{ obtenerUltimoId() };

        Inscripcion registro{ m_idIscripcion, legajo, idCurso, importe, modalidad, false, fechaRegistrada };

        ArchivoManager archivo;
        archivo.grabarEnDisco(NOMBRE_ARCHIVO, registro);

        std::cout << "Inscripcion realizada con exito. ID = " << m_idIscripcion << "\n";
        std::cout << "Presione ENTER para continuar...";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        break;
    }
}

void GestorInscripcion::listarInscripciones() const {
    system("cls");
    Inscripcion inscripto;
    int pos{};

    ArchivoManager archivo;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, inscripto, pos++))
    {
        if (!inscripto.getEliminado()) {
            std::cout << "ID: " << inscripto.getIdInscripcion()
            << " | Alumno: " << inscripto.getLegajoAlumno()
            << " | Curso: "  << std::setfill('0') << std::setw(4) << inscripto.getCurso()
            << " | Fecha: " << inscripto.getFechaInscripcion().mostrar()
            << " | Importe: $ " << inscripto.getImporteAbonado()
            << "\n";
        }
    }
    std::cout << std::endl;
    system("pause");
}


 void  GestorInscripcion::modificarInscripciones(){
     system("cls");
      std::cout << "Ingrese el ID de la inscripcion a modificar: ";
      int idBuscado = validation();

      if (idBuscado == -1){
        std::cout << "ID Invalido";
        system("pause");
        return;
      }

      ArchivoManager archivo;
      Inscripcion registro;
      int pos = 0;

      while (archivo.leerDeDisco(NOMBRE_ARCHIVO,registro, pos )){
        if (registro.getIdInscripcion() == idBuscado && !registro.getEliminado()){

            std::cout << "Inscripcion encontrada: ";
            std::cout << "Alumno: " << registro.getLegajoAlumno() << std::endl;
            std::cout << "Curso: " << registro.getCurso() << std::endl;
            std::cout << "Inporte actual: " << registro.getImporteAbonado() << std::endl;
            std::cout << "Forma de pago: " << registro.getFormaDePago() << std::endl;

            float nuevoImporte;
            std::cout << "Nuevo Importe: ";
            std::cin >> nuevoImporte;

            if (nuevoImporte <= 0){
                std::cout << " Importe invalido";
                system ("pause");
                return;
            }
            int opcion;
            std::string modalidad;

        std::cout << "Nueva forma de pago: " <<std::endl;
        std::cout << "1. Efectivo"<<std::endl;
        std::cout << "2. Tarjeta Debito"<<std::endl;
        std::cout << "3. Tarjeta Credito"<<std::endl;
        std::cout << "Seleccione una opcion: "<<std::endl;
        std::cin >> opcion;

        switch (opcion){
        case 1:
            modalidad = "Efectivo";
            break;
        case 2:
            modalidad = "Tarjeta Debito";
            break;

        case 3:
            modalidad = "Tarjeta Credito";
            break;
            default:
            std::cout << "Opcion de pago Invalida, seleccione la opcion correcta.";
            system ("pause");
            continue;
        }
        registro.setImporteAbonado(nuevoImporte);
        registro.setFormaDePago(modalidad);

        archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, registro, pos);

       std::cout << "Inscripcion modificada con exito!";
       system ("pause");
        return;

      }
      pos++;
 }
        std::cout << "Inscripcion no encontrada!";
       system ("pause");
 }

//////////////////////

void GestorInscripcion::buscarInscripcionPorId()const {
    system ("cls");

    std::cout << "Ingrese el ID de la inscripcion a buscar: ";
    int idBuscado = validation();

    if (idBuscado == -1 ){
        std::cout << "ID invalido";
        system ("pause");
        return;
    }

    ArchivoManager archivo;
    Inscripcion inscripto;
    int pos = 0;
    bool encontrado = false;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, inscripto, pos++)){
        if (!inscripto.getEliminado() && inscripto.getIdInscripcion() == idBuscado){

            std::cout << "INSCRIPCION ENCONTRADA"<< std::endl;
            std::cout << "----------------------------------------"<< std::endl;
            std::cout << "ID: " << inscripto.getIdInscripcion()<< std::endl;
            std::cout << "Alumno (Legajo): " << inscripto.getLegajoAlumno()<< std::endl;
            std::cout << "Curso ID: " << inscripto.getCurso()<< std::endl;
            std::cout << "Fecha: " << inscripto.getFechaInscripcion().mostrar()<< std::endl;
            std::cout << "Importe: $ " << inscripto.getImporteAbonado()<< std::endl;
            std::cout << "Forma de pago: " << inscripto.getFormaDePago()<< std::endl;
            std::cout << "----------------------------------------"<< std::endl;

            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cout << "No se encontro la inscripcion con ese ID";
    }

    system ("pause");
}


void GestorInscripcion::backup() const {
    system("cls");
    ArchivoManager archivo;

    if (archivo.hacerBackup(NOMBRE_ARCHIVO, ARCHIVO_BAK)) {
        std::cout << "BackUp realizado con exito!: \n"; system("pause");
    } else {
        std::cerr << "No se pudo realizar el BackUp!: \n"; system("pause");
    }
}

///////

void GestorInscripcion::recuperarInscripcion(){
    system("cls");
    std::cout << "Ingrese el ID de la Inscripcion a recuperar: ";
    int idBuscado = validation();

    if (idBuscado == -1){
        std::cout << "ID invalido";
        system("pause");
        return;
    }

    ArchivoManager archivo;
    Inscripcion registro;
    int pos =0;

    while (archivo.leerDeDisco(NOMBRE_ARCHIVO, registro, pos)){
        if (registro.getIdInscripcion() == idBuscado && registro.getEliminado()){

            std::cout << "Inscripcion encontrada: ";
            std::cout << "Alumno: " << registro.getLegajoAlumno();
            std::cout << "Curso: " << registro.getCurso();

            char confirmacion;
            std::cout << "Desea Recuerar la inscripcion? (S/N): ";
            std::cin  >> confirmacion;

            if (std::toupper(confirmacion) == 'S'){
                registro.setEliminado (false);
                archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, registro, pos);
                std::cout << "Inscripcion recuperada con exito!";
            } else {
                std::cout << "Operacion cancelada";
            }
                system("pause");
        return;
    }
    pos++;
        }
        std::cout << "No se encontro inscripcion con ese ID";
          system("pause");
    }


void GestorInscripcion::restaurar() const {
    system("cls");
    ArchivoManager archivo;

    if (archivo.hacerBackup(ARCHIVO_BAK, NOMBRE_ARCHIVO)) {
        std::cout << "La Restauracion fue exitosa!: \n"; system("pause");
    } else {
        std::cerr << "No se pudo realizar la Restauracion!: \n"; system("pause");
    }
}

void GestorInscripcion::darDeBaja() {
    system("cls");
    std::cout << "Ingrese el N de Inscripcion: ";
    int idBuscado{validation()};

    if (idBuscado == -1){
        system("cls");
        std::cout << "Opcion invalidad!...\n"; system("pause");
        return;
    }

    ArchivoManager archivo;
    Inscripcion registro;
    int pos{0};
    bool encontrado{false};

  int cantidad{archivo.contarRegistrosInscripcion(NOMBRE_ARCHIVO)};

    for (int pos =0; pos < cantidad; pos++) {

            archivo.leerDeDisco(NOMBRE_ARCHIVO, registro, pos);
        std::cout << registro.getIdInscripcion() << '\n';
        if (registro.getIdInscripcion() == idBuscado) {
            registro.setEliminado(true);
            std::cout << "Estas seguro que quieres dar de baja Inscripcion S/N: \n";
            std::cout << "ID: " << registro.getIdInscripcion()
            << " | Alumno: " << registro.getLegajoAlumno()
            << " | Curso: "  << std::setfill('0') << std::setw(4) << registro.getCurso()
            << " | Fecha: " << registro.getFechaInscripcion().mostrar()
            << "\n";

            while(true)
            {
                char letra;
                std::cin >> letra;
                if(std::toupper(letra) == 'S'){
                   archivo.sobrescribirRegistro(NOMBRE_ARCHIVO, registro, pos);
                   std::cout << "Inscripcion " << idBuscado << " dada de baja correctamente.\n";
                   system("pause");
                   return;
                }
                else if (letra == 'N') {
                    std::cout << "Accion Cancelada!\n"; system("pause");
                    return;
                }
                std::cout << "Ingreso no valido\nIntentelo otra vez\n";
            }
        }
    }
    std::cout << "No se encontro el N de Inscripcion buscado\n";
    std::cout << "Presione ENTER continuar...";
    std::cin.ignore(1000, '\n');
}

int GestorInscripcion::validation() const {

    std::string entry;
    std::getline(std::cin, entry);

    /**
     * @brief Uso de empty(), para verificar string vacios.
     *
     * @see https://en.cppreference.com/w/cpp/string/basic_string/empty.html
     */
    bool isNumber = !entry.empty();

    for (size_t i{0}; i < entry.size(); ++i) {
        if (entry[i] < '0' || entry[i] > '9') {
            isNumber = false;
            break;
        }
    }

    int option;

    /**
     *  @brief Uso de substr(), para evitar overflow.
     *  @brief Uso de stoi(), para convertir a entero.
     *
     *  @see https://en.cppreference.com/w/cpp/string/basic_string/substr.html
     *  @see https://en.cppreference.com/w/cpp/string/basic_string/stol.html
     */

    if (isNumber) {
        std::string fiveDigit = entry.substr(0, 5);
        option = std::stoi(fiveDigit);
    }
    else {
        option = -1;
    }
    return option;
}
