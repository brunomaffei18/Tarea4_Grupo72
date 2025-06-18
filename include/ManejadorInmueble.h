#ifndef MANEJADORINMUEBLE_H
#define MANEJADORINMUEBLE_H
#include "../include/DTInmueble.h"
#include "../include/Inmueble.h"
#include <list>
#include <map>

class ManejadorInmueble {
    private:
    std::map<int,Inmueble*> inmuebles;
    int codigoACtual=1;
    ManejadorInmueble();
    public:
        static ManejadorInmueble* getManejadorInmueble();
        ManejadorInmueble();
        int generarCodigo();
        void agregarInmueble(Inmueble* inmueble);
        Inmueble* getInmueble(int codigoInmueble);
        void eliminarInmueble(int codigoInmueble);
        std::list<DTInmueble*> listarInmuebles();
        ~ManejadorInmueble();
};

#endif