#ifndef FACTORY_H
#define FACTORY_H

#include "../include/IControladorAdministraInmueble.h"
#include "../include/IControladorFechaActual.h"
#include "../include/IControladorInmueble.h"
#include "../include/IControladorPublicacion.h"
#include "../include/IControladorUsuario.h"


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