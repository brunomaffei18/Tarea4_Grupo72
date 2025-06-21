#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "Subscriptor.h"
#include "DTNotificacion.h"
#include <string>
#include <set>
#include <map>

class Inmueble;

class Propietario : public Usuario, public Subscriptor{
    private:
        std::set<DTNotificacion> notificaciones;
        std::set<std::string> suscripciones; 
        std::map<int,Inmueble*> propiedades;
        std::string cuentaBancaria;
        std::string telefono; 
        std::map<std::string, Inmobiliaria*> administradores;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        std::string getCuentaBancaria();
        std::string getTelefono();
        std::set<DTNotificacion> getNotificaciones()const;
        std::set<std::string> getSuscripciones()const; 
        std::map<int,Inmueble*> getPropiedades()const;
        Inmueble* getInmueble(int codigoInmueble);
        std::map<std::string, Inmobiliaria*> getAdministradores();

        void vincularInmueble(Inmueble* propiedad);
        void desvincularInmueble(int codigoInmueble);

        void agregarRepresentante(Inmobiliaria* i);
        
        void recibirNotificacion(const DTNotificacion& n) override;
        std::set<DTNotificacion> consultarNotificaciones() const override;
        void limpiarNotificaciones() override;
        std::string getNickname() const override;
        bool estaSuscriptoA(Inmobiliaria* inmo) const override;
        void notificar(Publicacion* pub) override;
        std::list<std::string> suscriptoActualmente() const override;
        void seSuscribe(const std::string& nickInmobiliaria, const std::string& nickSubscriptor) override;
        void seDesuscribe(const std::string& nicknameInmobiliaria) override;
          virtual bool estaSuscriptoA(Inmobiliaria* inmo) const override; 
        virtual void notificar(Publicacion*pub) override;
        virtual ~Propietario();

};

#endif