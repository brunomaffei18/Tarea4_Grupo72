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
        std::string getCuentaBancaria();
        std::string getTelefono();
        std::set<DTNotificacion> getNotificaciones()const;
        std::set<std::string> getSuscripciones()const; 
        std::map<int,Inmueble*> getPropiedades()const;

        std::string getNickname() const override;
        bool estaSuscriptoA(Inmobiliaria* inmo) const override;
        void notificar(Publicacion* pub) override;
        void desvincularInmueble(int codigoInmueble);
        void vincularInmueble(Inmueble* propiedad);
        Inmueble*getInmueble(int codigoInmueble);
        void recibirNotificacion(const DTNotificacion& n) override;
        std::set<DTNotificacion> consultarNotificaciones() const override;
        void limpiarNotificaciones() override;
        std::list<std::string> suscriptoActualmente() const override;
        void seDesuscribe(const std::string& nicknameInmobiliaria) override;

        virtual ~Propietario();

};

#endif