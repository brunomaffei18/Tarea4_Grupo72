#include "../include/Usuario.h"
#include "../include/Subscriptor.h"
#include "../include/DTNotificacion.h"
#include "../include/Inmueble.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include <string>
#include <set>
#include <map>
#include "../include/Publicacion.h"

Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono):
    Usuario(nickname,contrasena,nombre,email),telefono(telefono),cuentaBancaria(cuentaBancaria){}

std::string Propietario::getCuentaBancaria(){
    return cuentaBancaria;
}
std::string Propietario::getTelefono(){
    return telefono;
}
std::set<DTNotificacion> Propietario::getNotificaciones()const{
    return notificaciones;
}
std::set<std::string> Propietario::getSuscripciones()const{
    return suscripciones;
}
std::map<int,Inmueble*> Propietario::getPropiedades()const{
    return propiedades;
}

std::map<std::string, Inmobiliaria*> Propietario::getAdministradores(){
    return administradores;
}

void Propietario::seSuscribe(const std::string& nickInmobiliaria, const std::string& nickSubscriptor){
    suscripciones.insert(nickInmobiliaria);
}

void Propietario::desvincularInmueble(int codigoInmueble){
    propiedades.erase(codigoInmueble);
}

void Propietario::vincularInmueble(Inmueble* propiedad){
    int code =propiedad->getCodigo();
    propiedades.insert({code,propiedad});
}

void Propietario::agregarRepresentante(Inmobiliaria* i){
    std::string nick = i->getNickname();
    this->administradores.insert({nick,i});
}

Inmueble* Propietario::getInmueble(int codigoInmueble) {
    std::map<int, Inmueble*>::iterator it = propiedades.find(codigoInmueble);
    if (it != propiedades.end()) {
        return it->second;
    }
    return NULL;
}

void Propietario::recibirNotificacion(const DTNotificacion& n){
    notificaciones.insert(n);
}

std::set<DTNotificacion> Propietario::consultarNotificaciones()const{
    return notificaciones;
}
void Propietario::limpiarNotificaciones(){
    notificaciones.clear();
}
std::list<std::string> Propietario::suscriptoActualmente() const{
    return std::list<std::string>(suscripciones.begin(), suscripciones.end());
}
void Propietario::seDesuscribe(const std::string& nicknameInmobiliaria){
    suscripciones.erase(nicknameInmobiliaria);
}
 bool Propietario::estaSuscriptoA(Inmobiliaria* inmo) const {
    return suscripciones.find(inmo->getNickname()) != suscripciones.end();
  }; 
     void Propietario::notificar(Publicacion*pub) {
        DTNotificacion n=DTNotificacion(pub->getInmueble()->getCodigo(), pub->getInmobiliaria()->getNickname(), pub->getTipo(), pub->getInmueble()->getTipoInmueble(), pub->getTexto());
     };

std::string Propietario::getNickname() const {
    return Usuario::getNickname();
}




Propietario::~Propietario() {}