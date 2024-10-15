#include <iostream>
#include <fstream>
#include <string>
#include "clases.hpp"

using namespace std;

enum Opcion{
    wifi = 1,
    pac,
    tut,
    salir
};

template<typename T>
void ingresarDatosGenericos(const string& mensaje, T& dato) {
    cout << mensaje;
    cin >> dato;
}

void ingresarDatosWiFi() {
    string ssid, pss;
    ingresarDatosGenericos("Ingrese el SSID: ", ssid);
    ingresarDatosGenericos("Ingrese la contraseña de la red WiFi: ", pss);
    ofstream archivoConfig("config.txt");
    if (!archivoConfig.is_open()) {
        throw runtime_error("Error al abrir el archivo config.txt.");
    }
    archivoConfig << "SSID: " << ssid << "\n";
    archivoConfig << "Contraseña: " << pss << "\n";
    archivoConfig.close();
    cout << "Datos del WiFi guardados en config.txt\n";
}

void ingresarDatosPersonales(Persona& persona){
    persona.ingresarDatos();
}

void guardarDatosPersonales(Persona& persona){
    persona.guardarDatos();
}


int main() {
    int opcion;
    Paciente paciente;
    Tutor tutor;

    do {
        cout << "\nMenu Principal:\n";
        cout << "1. Cargar datos del WiFi\n";
        cout << "2. Agregar datos del paciente\n";
        cout << "3. Agregar datos de tutores\n";
        cout << "4. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        try{
            switch (opcion) {
                case Opcion::wifi:
                    ingresarDatosWiFi();
                    break;
                case Opcion::pac:
                    ingresarDatosPersonales(paciente);
                    guardarDatosPersonales(paciente);
                    break;
                case Opcion::tut:
                    ingresarDatosPersonales(tutor);
                    guardarDatosPersonales(tutor);
                    break;
                case Opcion::salir:
                    cout << "Lulu\n";
                    break;
                default:
                    cout << "Opcion invalida. Intente nuevamente.\n";
            }
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
    } while (opcion != 4);

    return 0;
}
