#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include <string>
#include <set>
#include <map>
#include "Usuario.h"
#include "Subscriptor.h"
#include "DTNotificacion.h"
#include "Propietario.h"

class AdministraPropiedad;
class Inmobiliaria : public Usuario {
private:
    std::string direccion;
    std::string url;
    std::string telefono;
    std::set<Subscriptor*> suscriptores;
    std::set<AdministraPropiedad*>administrados;
    std::map<std::string, Propietario*>representados;

public:
    Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email,
        std::string direccion, std::string telefono, std::string url);

    void agregarSubscriptor(Subscriptor* s);
    void eliminarSubscriptor(Subscriptor* s);
    void notificar(const DTNotificacion& n);
    std::set<Subscriptor*> getSuscriptores() const;

    std::map<std::string, Propietario*> getRepresentados() const;
    void agregarRepresentado(Propietario* p);

    std::set<AdministraPropiedad*> getAdministraciones() const;
    void agregarAdministracion(AdministraPropiedad* administracion);
    void eliminarAdministracion(AdministraPropiedad* administracion);
    
    ~Inmobiliaria();
};

#endif