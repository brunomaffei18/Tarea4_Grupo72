#include "../include/ManejadorNotificaciones.h"

ManejadorNotificaciones* ManejadorNotificaciones::instancia = NULL;

ManejadorNotificaciones::ManejadorNotificaciones() {}

ManejadorNotificaciones* ManejadorNotificaciones::getInstance() {
    if (instancia == NULL){
        instancia = new ManejadorNotificaciones();
    }
    return instancia;
}
void ManejadorNotificaciones::agregarSubscriptor(Subscriptor* s) {
    if (s != NULL) {
        std::string nickname = s->getNickname();
        subscriptores[nickname] = s;
    }
}
void ManejadorNotificaciones::agregarInmobiliaria(Inmobiliaria* i) {
    if (i != NULL) {
        std::string nickname = i->getNickname();
        inmobiliarias[nickname] = i;
    }
}
Subscriptor* ManejadorNotificaciones::obtenerSubscriptor(const std::string& nickname) {
    if (subscriptores.count(nickname) > 0)
        return subscriptores[nickname];
    return NULL;
}
Inmobiliaria* ManejadorNotificaciones::obtenerInmobiliaria(const std::string& nickname) {
    if (inmobiliarias.count(nickname) > 0)
        return inmobiliarias[nickname];
    return NULL;
}
std::list<std::string> ManejadorNotificaciones::obtenerNicksInmobiliarias() {
    std::list<std::string> res;

    std::map<std::string, Inmobiliaria*>::const_iterator it;
    for (it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        res.push_back(it->first);
    }

    return res;
}
std::list<std::string> ManejadorNotificaciones::obtenerNicksSubscriptos() {
    std::list<std::string> res;
    std::map<std::string, Subscriptor*>::const_iterator it;

    for (it = subscriptores.begin(); it != subscriptores.end(); ++it) {
        res.push_back(it->first);
    }

    return res;
}
std::list<Subscriptor*> ManejadorNotificaciones::getSubs() {
    std::list<Subscriptor*> res;
    std::map<std::string, Subscriptor*>::const_iterator it;

    for (it = subscriptores.begin(); it != subscriptores.end(); ++it) {
        res.push_back(it->second);
    }

    return res;
}
ManejadorNotificaciones::~ManejadorNotificaciones() {}