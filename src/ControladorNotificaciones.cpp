#include "../include/Subscriptor.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTNotificacion.h"
#include "../include/ManejadorNotificaciones.h"
#include "../include/IControladorNotificaciones.h"
#include "../include/ControladorNotificaciones.h"
#include <string>
#include <map>
#include <set>

ControladorNotificaciones* ControladorNotificaciones::instance = NULL;

static ControladorNotificaciones* ControladorNotificaciones::getInstance(){
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
            Inmobiliaria inmobiliaria = manejador->obtenerInmobiliaria(*it);
            if (inmobiliaria != NULL)
            {
                inmobiliaria->eliminarSubscriptor(nickName);
                sub->seDesuscribe(*it);
            }
            
        }
        
    }
    
}
std::list<std::string> ControladorNotificaciones::nuevasSuscribciones(const std::string& nicknameInteresado){
    
}
void ControladorNotificaciones::seSuscribe(const std::string& nicknameInmobiliaria, const std::string& nicknameInteresado){}
bool ControladorNotificaciones::estaSubscripto(std::string nickSub, std::string nickInmobiliaria){}
std::list<std::string> ControladorNotificaciones::listarInmobiliariasSuscriptas(const std::string& nicknameSubscriptor){}

ControladorNotificaciones::~ControladorNotificaciones(){}