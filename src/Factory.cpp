#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/IControladorAdministraInmueble.h"
#include "../include/IControladorInmueble.h"
#include "../include/IControladorPublicacion.h"
#include "../include/IControladorUsuario.h"
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

IControladorAdministraInmueble* Factory::ControladorAdministrarInmueble(){
    return ControladorAdministrarInmueble::getInstance();

IControladorInmueble* Factory::getControladorInmueble(){
    return ControladorInmueble::getInstance();

IControladorPublicacion* Factory::getControladorPublicacion(){
    return ControladorPublicacion::getInstance();
    
IControladorUsuario* Factory::getControladorUsuario(){
    return ControladorUsuario::getInstance();    
}