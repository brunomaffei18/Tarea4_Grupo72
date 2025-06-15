#include "../include/Usuario.h"
#include "../include/DTNotificacion.h"
#include "../include/Subscriptor.h"
#include "../include/Cliente.h"
#include <string>
#include <set>

Cliente::Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento):
    Usuario(nickname,contrasena,nombre,email),apellido(apellido),documento(documento){}

std::string Cliente::getApellido(){
    return apellido;
}
std::string Cliente::getDocumento(){
    return documento;
}
std::set<DTNotificacion> Cliente::getNotificaciones()const{
    return notificaciones;
}
std::set<std::string> Cliente::getSuscripciones()const{
    return suscripciones;
}

void Cliente::recibirNotificacion(const DTNotificacion& n){
    notificaciones.insert(n);
}
std::set<DTNotificacion> Cliente::consultarNotificaciones() const{
    return notificaciones;
}
void Cliente::limpiarNotificaciones(){
    notificaciones.clear();
}
std::list<std::string> Cliente::suscriptoActualmente() const{
    return std::list<std::string>(suscripciones.begin(), suscripciones.end());
}
void Cliente::seDesuscribe(const std::string& nicknameInmobiliaria){
    suscripciones.erase(nicknameInmobiliaria);
}

Cliente::~Cliente(){}