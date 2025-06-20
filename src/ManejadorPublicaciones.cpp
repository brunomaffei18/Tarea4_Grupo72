#include "../include/ManejadorPublicaciones.h"

ManejadorPublicaciones* ManejadorPublicaciones::instancia = nullptr;

ManejadorPublicaciones* ManejadorPublicaciones::getManejadorPublicaciones(){
    if(instancia==nullptr)
        instancia= new ManejadorPublicaciones();
    return instancia;
}





ManejadorPublicaciones::~ManejadorPublicaciones(){
    delete instancia;
    instancia = nullptr;
}  