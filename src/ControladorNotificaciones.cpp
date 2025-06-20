#include "../include/Subscriptor.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTNotificacion.h"
#include "../include/ManejadorNotificaciones.h"
#include "../include/IControladorNotificaciones.h"
#include "../include/ControladorNotificaciones.h"
#include <string>
#include <map>
#include <set>
#include <algorithm>

ControladorNotificaciones* ControladorNotificaciones::instancia = NULL;

ControladorNotificaciones* ControladorNotificaciones::getInstance(){
    if (instancia == NULL)
    instancia = new ControladorNotificaciones();
    return instancia;
}

ControladorNotificaciones::ControladorNotificaciones(){}

void ControladorNotificaciones::subscribirse(const std::string& nickName, const std::list<std::string>& inmobiliarias){
    ManejadorNotificaciones* manejador = ManejadorNotificaciones::getInstance();
    Subscriptor* sub = manejador->obtenerSubscriptor(nickName);
    std::list<std::string>::const_iterator it;
    for (it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        Inmobiliaria* inmo = manejador->obtenerInmobiliaria(*it);
        if (inmo != NULL && sub != NULL && !estaSubscripto(nickName, *it)) {
            inmo->agregarSubscriptor(sub);
            sub->seSuscribe(*it, nickName);
        }
    }
}
std::set<DTNotificacion> ControladorNotificaciones::consultarNotificaciones(const std::string& nickName){
    ManejadorNotificaciones* manejador = ManejadorNotificaciones::getInstance();
    Subscriptor* sub = manejador->obtenerSubscriptor(nickName);
    if (sub != NULL)
        return sub->consultarNotificaciones();
    return std::set<DTNotificacion>();
}
void ControladorNotificaciones::eliminarSubscripciones(const std::string& nickName, const std::list<std::string>& inmobiliarias){
    ManejadorNotificaciones* manejador = ManejadorNotificaciones::getInstance();
    Subscriptor* sub = manejador->obtenerSubscriptor(nickName);

    if (sub != NULL)
    {
        std::list<std::string>::const_iterator it;
        for (it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it)
        {
            Inmobiliaria* inmobiliaria = manejador->obtenerInmobiliaria(*it);
            if (inmobiliaria != NULL)
            {
                inmobiliaria->eliminarSubscriptor(sub);
                sub->seDesuscribe(*it);
            }
            
        }
        
    }
    
}
std::list<std::string> ControladorNotificaciones::nuevasSuscribciones(const std::string& nicknameInteresado){
    ManejadorNotificaciones* manejador = ManejadorNotificaciones::getInstance();
    Subscriptor* sub =manejador->obtenerSubscriptor(nicknameInteresado);
    std::list<std::string> resultado;

    if (sub != NULL)
    {
        std::list<std::string> todas = manejador->obtenerNicksInmobiliarias();
        std::list<std::string> actuales = sub->suscriptoActualmente();

        std::list<std::string>::const_iterator it;
        for (it = todas.begin(); it != todas.end(); ++it) {
            if (std::find(actuales.begin(), actuales.end(), *it) == actuales.end()) {
                resultado.push_back(*it);
            }
        }
    }
    return resultado;
}
void ControladorNotificaciones::seSuscribe(const std::string& nicknameInmobiliaria, const std::string& nicknameInteresado){
    ManejadorNotificaciones* manejador = ManejadorNotificaciones::getInstance();
    Subscriptor* sub = manejador->obtenerSubscriptor(nicknameInteresado);
    Inmobiliaria* inmobiliaria = manejador->obtenerInmobiliaria(nicknameInmobiliaria);

    if (inmobiliaria != NULL && sub != NULL && !estaSubscripto(nicknameInteresado, nicknameInmobiliaria)) {
        inmobiliaria->agregarSubscriptor(sub);
        sub->seSuscribe(nicknameInmobiliaria, nicknameInteresado);
    }
}
bool ControladorNotificaciones::estaSubscripto(std::string nickSub, std::string nickInmobiliaria){
    ManejadorNotificaciones* manejador = ManejadorNotificaciones::getInstance();
    Subscriptor* sub = manejador->obtenerSubscriptor(nickSub);
    if (sub == NULL){
        return false;
    }
    else{
        std::list<std::string> actuales = sub->suscriptoActualmente();
        return std::find(actuales.begin(), actuales.end(), nickInmobiliaria) != actuales.end();
    }
}
std::list<std::string> ControladorNotificaciones::listarInmobiliariasSuscriptas(const std::string& nicknameSubscriptor){
    ManejadorNotificaciones* manejador = ManejadorNotificaciones::getInstance();
    Subscriptor* sub = manejador->obtenerSubscriptor(nicknameSubscriptor);
    if (sub == NULL){
        return std::list<std::string>();
    }
    else{
        return sub->suscriptoActualmente();
    }
}

ControladorNotificaciones::~ControladorNotificaciones(){}