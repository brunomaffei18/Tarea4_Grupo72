#include <string>
#include "../include/Usuario.h"
#include "../include/Subscriptor.h"
#include "../include/DTNotificacion.h"
#include "../include/Inmobiliaria.h"

Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email,
            std::string direccion, std::string telefono, std::string url):
    Usuario(nickname,contrasena,nombre,email),direccion(direccion),telefono(telefono),url(url){}

void Inmobiliaria::agregarSubscriptor(Subscriptor *s){
    suscriptores.insert(s);
}

void Inmobiliaria::eliminarSubscriptor(Subscriptor* s){
    suscriptores.erase(s);
}

void Inmobiliaria::notificar(const DTNotificacion& n){
    std::set<Subscriptor*>::iterator it;
    for (it = suscriptores.begin(); it != suscriptores.end(); ++it){
        (*it)->recibirNotificacion(n);
    }
}

void Inmobiliaria::agregarAdministracion(AdministraPropiedad* administracion){
    administrados.insert(administracion);
}
void Inmobiliaria::eliminarAdministracion(AdministraPropiedad*admin){
    administrados.erase(admin);
}

std::set<Subscriptor*> Inmobiliaria::getSuscriptores() const{
    return this->suscriptores;
}

std::set<AdministraPropiedad*> Inmobiliaria::getAdministraciones() const{
    return this->administrados;
}
std::map<std::string, Propietario*> Inmobiliaria::getRepresentados() const{
    return this->representados;
}
void Inmobiliaria::agregarRepresentado(Propietario* p){
    std::string nick = p->getNickname();
    representados.insert({nick,p});
}
Inmobiliaria::~Inmobiliaria(){
    suscriptores.clear();
}