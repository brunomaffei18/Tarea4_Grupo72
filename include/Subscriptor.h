#ifndef SUBSCRIPTOR_H
#define SUBSCRIPTOR_H

#include <set>
#include <list>
#include <string>
#include "DTNotificacion.h"
class Inmobiliaria;
class Publicacion;

class Subscriptor {
public:
    virtual void recibirNotificacion(const DTNotificacion& n) = 0;
    virtual std::set<DTNotificacion> consultarNotificaciones() const = 0;
    virtual void limpiarNotificaciones() = 0;
    virtual std::list<std::string> suscriptoActualmente() const = 0;
    virtual void seSuscribe(const std::string& nickInmobiliaria, const std::string& nickSubscriptor) = 0;
    virtual void seDesuscribe(const std::string& nicknameInmobiliaria) = 0;
    virtual std::string getNickname()const = 0;
    virtual ~Subscriptor() {}
    virtual bool estaSuscriptoA(Inmobiliaria* inmo) const=0;
    virtual void notificar(Publicacion*pub) =0;
};

#endif
