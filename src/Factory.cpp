#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorInmueble.h"
#include "../include/ControladorPublicacion.h"
#include "../include/ControladorUsuario.h"
#include "../include/ControladorNotificaciones.h"


#include <cstddef>

Factory* Factory::instance = nullptr;

Factory::Factory() {
}

Factory* Factory::getInstance() {
    if (instance == nullptr) {
        instance = new Factory();
    }
    return instance;
}

IControladorFechaActual* Factory::getControladorFechaActual(){
    return ControladorFechaActual::getInstance();
}

IControladorInmueble* Factory::getControladorInmueble(){
    return ControladorInmueble::getInstancia();
}

IControladorPublicacion* Factory::getControladorPublicacion(){
    return ControladorPublicacion::getInstancia();
}

IControladorUsuario* Factory::getControladorUsuario(){
    return ControladorUsuario::getInstancia();
}

IControladorNotificaciones* Factory::getControladorNotificaciones(){
    return ControladorNotificaciones::getInstance();  
}
    
Factory::~Factory(){
    delete instance;
    instance = nullptr;
}   
