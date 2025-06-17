#ifndef MANEJADORINMUEBLE_H
#define MANEJADORINMUEBLE_H
#include "../include/DTInmueble.h"
#include "../include/Inmueble.h"
#include <list>
#include <map>

class ManejadorInmueble {
    private:
    std::map<int,Inmueble*> inmuebles;

    public:
        ManejadorInmueble();
        Inmueble* getInmueble(int codigoInmueble);
        void eliminarInmueble(int codigoInmueble);
        std::list<DTInmueble*> listarInmuebles();
        ~ManejadorInmueble();
};

#endif