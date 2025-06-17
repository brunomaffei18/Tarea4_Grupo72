#ifndef FACTORY_H
#define FACTORY_H

#include "../include/IControladorAdministraInmueble.h"
#include "../include/IControladorFechaActual.h"
#include "../include/IControladorInmueble.h"
#include "../include/IControladorPublicacion.h"
#include "../include/IControladorUsuario.h"
#include "../include/IControladorNotificaciones.h"



class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        //Controladores
        IControladorFechaActual* getControladorFechaActual();//Esto es solo si son singleton
        IControladorAdministraInmueble* getControladorAdministraInmueble();
        IControladorInmueble* getControladorInmueble();
        IControladorPublicacion* getControladorPublicacion();
        IControladorUsuario* getControladorUsuario();
        IControladorNotificaciones* getControladorNotificaciones();
        ~Factory();
};

#endif