#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorAdministraInmueble.h"
#include "IControladorFechaActual.h"
#include "IControladorInmueble.h"
#include "IControladorPublicacion.h"
#include "IControladorUsuario.h"


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
        ~Factory();
};

#endif