#ifndef CLASES
#define CLASES

#include <iostream>

using namespace std;

class Persona {
public:
    virtual void ingresarDatos() = 0;
    virtual void guardarDatos() const = 0;

protected:
    string nombre;
};

class Paciente : public Persona{
public:
    void ingresarDatos() override;
    void guardarDatos() const override;

private:
    string edad;
};

class Tutor : public Persona{
public:
    void ingresarDatos() override;
    void guardarDatos() const override;

private:
    string celular;
};

#endif