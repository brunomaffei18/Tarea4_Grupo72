#ifndef MANEJADORINMUEBLE_H
#define MANEJADORINMUEBLE_H

#include "Inmueble.h"
#include <list>

class ManejadorInmueble {
    private:
        std::list<Inmueble*> inmuebles;

    public:
       
        void eliminarInmueble(int codigoInmueble);
        std::list<Inmueble*> listarInmuebles();
        ~ManejadorInmueble();
};

#endif