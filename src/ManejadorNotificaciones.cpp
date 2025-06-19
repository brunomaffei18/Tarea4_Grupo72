#include "../include/ManejadorNotificaciones.h"

ManejadorNotificaciones* ManejadorNotificaciones::instancia = nullptr;

ManejadorNotificaciones* ManejadorNotificaciones::getManejadorNotificaciones(){
    if(instancia==nullptr)
        instancia= new ManejadorNotificaciones();
    return instancia;
}