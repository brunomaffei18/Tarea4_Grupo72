#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IControladorInmueble.h"
#include "IControladorPublicacion.h"
#include "IControladorUsuario.h"
#include "IControladorNotificaciones.h"

class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        //Controladores
        IControladorFechaActual* getControladorFechaActual();//Esto es solo si son singleton
        IControladorInmueble* getControladorInmueble();
        IControladorPublicacion* getControladorPublicacion();
        IControladorUsuario* getControladorUsuario();
        IControladorNotificaciones* getControladorNotificaciones();
       
        ~Factory();
};

#endif