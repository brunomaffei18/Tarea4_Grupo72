#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorAdministrarInmueble.h"
#include "../include/ControladorInmueble.h"
#include "../include/ControladorPublicacion.h"
#include "../include/ControladorUsuario.h"
#include "../include/ControladorNotificaciones.h"
#include "../include/IControladorAdministrarInmueble.h"

#include <cstddef>

Factory* Factory::instance = NULL;

Factory::Factory() {
}

Factory* Factory::getInstance() {
    if (instance == NULL) {
        instance = new Factory();
    }
    return instance;
}

IControladorFechaActual* Factory::getControladorFechaActual(){
    return ControladorFechaActual::getInstance();
}

IControladorAdministrarInmueble* Factory::ControladorAdministrarInmueble(){
    return ControladorAdministrarInmueble::getInstancia();
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
    instance = NULL;
}   
