#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IControladorAdministrarInmueble.h" 
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
        IControladorAdministrarInmueble* getControladorAdministraInmueble();
        IControladorInmueble* getControladorInmueble();
        IControladorPublicacion* getControladorPublicacion();
        IControladorUsuario* getControladorUsuario();
        IControladorNotificaciones* getControladorNotificaciones();
        IControladorAdministrarInmueble* ControladorAdministrarInmueble();
       
        ~Factory();
};

#endif