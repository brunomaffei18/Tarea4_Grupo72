// ManejadorNotificaciones.h
#ifndef MANEJADORNOTIFICACIONES_H
#define MANEJADORNOTIFICACIONES_H

#include "../include/Subscriptor.h"
#include "../include/Inmobiliaria.h"
#include <string>
#include <map>
#include <list>

class ManejadorNotificaciones {
private:
    std::map<std::string, Subscriptor*> subscriptores;
    std::map<std::string, Inmobiliaria*> inmobiliarias;

    static ManejadorNotificaciones* instancia;
    ManejadorNotificaciones();

public:
    static ManejadorNotificaciones* getInstance();

    void agregarSubscriptor(Subscriptor* s);
    void agregarInmobiliaria(Inmobiliaria* i);

    Subscriptor* obtenerSubscriptor(const std::string& nickname);
    Inmobiliaria* obtenerInmobiliaria(const std::string& nickname);

    std::list<std::string> obtenerNicksSubscriptos();
    std::list<std::string> obtenerNicksInmobiliarias();
 
    ~ManejadorNotificaciones();
};

#endif
