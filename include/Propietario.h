#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "../include/Usuario.h"
#include "../include/Subscriptor.h"
#include "../include/DTNotificacion.h"
#include "../include/Inmueble.h"
#include <string>
#include <set>
#include <map>

class Propietario : public Usuario, public Subscriptor{
    private:
       std::set<DTNotificacion> notificaciones;
        std::set<std::string> suscripciones; 
        std::map<int,Inmueble*> propiedades;
        std::string cuentaBancaria;
        std::string telefono; 

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        void DesvincularInmueble();
};

#endif