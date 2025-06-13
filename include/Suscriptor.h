#ifndef SUSCRIPTOR_H
#define SUSCRIPTOR_H

#include <set>
#include <list>
#include <string>
#include "DTNotificacion.h"

class Suscriptor {
public:
    virtual void recibirNotificacion(const DTNotificacion& n) = 0;
    virtual std::set<DTNotificacion> consultarNotificaciones() const = 0;
    virtual void limpiarNotificaciones() = 0;
    virtual std::list<std::string> suscriptoActualmente() const = 0;
    virtual void seDesuscribe(const std::string& nicknameInmobiliaria) = 0;

    virtual ~Suscriptor() {}
};

#endif
