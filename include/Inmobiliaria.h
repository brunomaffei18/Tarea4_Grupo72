#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include <string>
#include <set>
#include "Usuario.h"
#include "Subscriptor.h"
#include "DTNotificacion.h"

class Inmobiliaria : public Usuario {
private:
    std::string direccion;
    std::string url;
    std::string telefono;
    std::set<Subscriptor*> suscriptores;
    std::set<AdministraPropiedad*>administra;

public:
    Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email,
        std::string direccion, std::string telefono, std::string url);
    void agregarSubscriptor(Subscriptor* s);
    void eliminarSubscriptor(Subscriptor* s);
    void notificar(const DTNotificacion& n);
        std::set<Subscriptor*> getSuscriptores() const;
    std::set<AdministraPropiedad*> getAdministraciones() const;
    ~Inmobiliaria();
    void agregarAdministracion(AdministraPropiedad* administracion);
    void eliminarAdministracion(AdministraPropiedad* administracion);
};

#endif