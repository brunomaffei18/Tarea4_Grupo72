#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include <string>
#include "Suscriptor.h"

class Inmobiliaria : public Usuario {
private:
    std::string direccion;
    std::string url;
    std::string telefono;

public:
    Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);

    void agregarSubscriptor(Subscriptor s);
    void eliminarSubscriptor(Subscriptor s);
    void notificar(Publicacion p);

    ~Inmobiliaria();
};

#endif