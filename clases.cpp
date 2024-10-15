#include <iostream>
#include <fstream>
#include <string>
#include "clases.hpp"

using namespace std;

void Paciente::ingresarDatos(){
        cout << "Ingrese el nombre del paciente: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese la edad del paciente: ";
        getline(cin, edad);
    }

void Paciente::guardarDatos() const{
    ofstream archivoPaciente("paciente.csv");
    if (!archivoPaciente.is_open()) {
        throw runtime_error("Error al abrir el archivo paciente.csv.");
    }
    archivoPaciente << "Nombre" << ";" << "Edad\n";
    archivoPaciente << nombre << ";" << edad << "\n";
    archivoPaciente.close();
    cout << "Datos del paciente guardados en paciente.csv\n";
}

void Tutor::ingresarDatos(){
    cout << "Ingrese el nombre del tutor: ";
    cin.ignore();
    getline(cin, nombre);
    bool esNumeroValido = false;
    do {
        cout << "Ingrese el numero de celular del tutor: ";
        cin >> celular;
        esNumeroValido = true;
        for (char c : celular) {
            if (!isdigit(c)) {
                esNumeroValido = false;
                break;
            }
        }
        if (!esNumeroValido) {
            cout << "El numero de celular debe contener solo digitos. Intente nuevamente.\n";
        }
    } while (!esNumeroValido);
    celular = "+54" + celular;
}

    void Tutor::guardarDatos() const{
    ofstream archivoTutor("tutor.csv", ios::app);
    if (!archivoTutor.is_open()) {
        throw runtime_error("Error al abrir el archivo tutor.csv.");
    }
    archivoTutor << "Nombre" << ";" << "Celular\n";
    archivoTutor << nombre << ";" << celular << "\n";
    archivoTutor.close();
    cout << "Datos del tutor guardados en tutor.csv\n";
}