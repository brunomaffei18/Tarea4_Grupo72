#ifndef CARGADATOS_H
#define CARGADATOS_H

#include "../include/IControladorUsuario.h"
#include "../include/IControladorPublicacion.h"
#include "../include/IControladorFechaActual.h"
#include "../include/IControladorNotificaciones.h"
#include "../include/IControladorInmueble.h"
#include "../include/Factory.h"
class CargaDatos {
    private:
        static CargaDatos* instance;
        CargaDatos();

        IControladorUsuario* cu;
        IControladorPublicacion* cp;
        IControladorFechaActual* cf;
        IControladorNotificaciones* cn;
        IControladorInmueble* ci;

    public:
        static CargaDatos* getInstance();
        ~CargaDatos();
};

#endif