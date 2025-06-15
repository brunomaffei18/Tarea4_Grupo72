#ifndef CONTROLADORNOTIFICACIONES_H
#define CONTROLADORNOTIFICACIONES_H

#include "Subscriptor.h"
#include "Inmobiliaria.h"
#include "DTNotificacion.h"
#include <string>
#include <map>
#include <set>

class ControladorNotificaciones {
private:
    std::map<std::string, Subscriptor*> subscriptores;

    ControladorNotificaciones();
    static ControladorNotificaciones* instancia;

public:     //Ta todo mal el uml :)
    static ControladorNotificaciones* getInstance();

    void registrarSubscriptor(Subscriptor* s);
    void registrarInmobiliaria(Inmobiliaria* i);    //Mi amigo

    void suscribirse(std::string nickSub, std::string nickInmo);
    void desuscribirse(std::string nickSub, std::string nickInmo);

    std::set<DTNotificacion> consultarNotificaciones(std::string nickSub);
    void limpiarNotificaciones(std::string nickSub);    //Mi amigo

    void notificar(std::string nickInmo, const DTNotificacion& noti);    //Mi amigo

    ~ControladorNotificaciones();
};
#endif
