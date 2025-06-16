#ifndef ICONTROLADORNOTIFICACIONES_H
#define ICONTROLADORNOTIFICACIONES_H

#include "../include/Subscriptor.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTNotificacion.h"
#include "../include/ManejadorNotificaciones.h"
#include <string>
#include <map>
#include <set>

class IControladorNotificaciones {
public:

    virtual void subscribirse(const std::string& nickName, const std::list<std::string>& inmobiliarias);
    virtual std::set<DTNotificacion> consultarNotificaciones(const std::string& nickName);
    virtual void eliminarSubscripciones(const std::string& nickName, const std::list<std::string>& inmobiliarias);
    virtual std::list<std::string> nuevasSuscribciones(const std::string& nicknameInteresado);
    virtual void seSuscribe(const std::string& nicknameInmobiliaria, const std::string& nicknameInteresado);
    virtual std::list<std::string> listarInmobiliariasSuscriptas(const std::string& nicknameSubscriptor);
    virtual ~IControladorNotificaciones()=default;
};

#endif