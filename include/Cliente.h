#ifndef CLIENTE_H
#define CLIENTE_H
#include "../include/Usuario.h"
#include "../include/DTNotificacion.h"
#include "../include/Subscriptor.h"
#include <string>
#include <set>

class Cliente : public Usuario, public Subscriptor{
    private:
        std::string apellido;
        std::string documento;
        std::set<DTNotificacion> notificaciones;
        std::set<std::string> suscripciones; 

    public:
        Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
        std::string getApellido();
        std::string getDocumento();
        std::set<DTNotificacion> getNotificaciones()const;
        std::set<std::string> getSuscripciones()const; 

        std::string getNickname() const override;
        bool estaSuscriptoA(Inmobiliaria* inmo) const override;
        void notificar(Publicacion* pub) override;
        void recibirNotificacion(const DTNotificacion& n) override;
        std::set<DTNotificacion> consultarNotificaciones() const override;
        void limpiarNotificaciones() override;
        std::list<std::string> suscriptoActualmente() const override;
        void seDesuscribe(const std::string& nicknameInmobiliaria) override;

        ~Cliente();
};
 
#endif