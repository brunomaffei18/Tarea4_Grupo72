#include "../include/ManejadorInmueble.h"

ManejadorInmueble* ManejadorInmueble::instancia = nullptr;

ManejadorInmueble* ManejadorInmueble::getManejadorInmueble(){
    if(instancia==nullptr)
        instancia= new ManejadorInmueble();
    return instancia
}
