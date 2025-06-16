#ifndef CONTROLADORNOTIFICACIONES_H
#define CONTROLADORNOTIFICACIONES_H

#include "../include/Subscriptor.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTNotificacion.h"
#include "../include/ManejadorNotificaciones.h"
#include <string>
#include <map>
#include <set>

class ControladorNotificaciones {
private:
    ControladorNotificaciones();
    static ControladorNotificaciones* instancia;
    ManejadorNotificaciones* manejador;

public:
    static ControladorNotificaciones* getInstance();

    void subscribirse(const std::string& nickName, const std::list<std::string>& inmobiliarias);
    std::set<DTNotificacion> consultarNotificaciones(const std::string& nickName);
    void eliminarSubscripciones(const std::string& nickName, const std::list<std::string>& inmobiliarias);
    std::list<std::string> nuevasSuscribciones(const std::string& nicknameInteresado);
    void seSuscribe(const std::string& nicknameInmobiliaria, const std::string& nicknameInteresado);
    std::list<std::string> listarInmobiliariasSuscriptas(const std::string& nicknameSubscriptor);

    ~ControladorNotificaciones();
};

#endif