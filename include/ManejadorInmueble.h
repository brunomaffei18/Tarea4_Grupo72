#ifndef MANEJADORINMUEBLE_H
#define MANEJADORINMUEBLE_H
#include "../include/DTInmueble.h"
#include "../include/Inmueble.h"
#include <list>
#include <map>

class ManejadorInmueble {
    private:
    static ManejadorInmueble* instancia;
    std::map<int,Inmueble*> inmuebles;
   
    ManejadorInmueble();
    public:
        static ManejadorInmueble* getManejadorInmueble();
        int generarCodigo();
        void agregarInmueble(Inmueble* inmueble);
        Inmueble* getInmueble(int codigoInmueble);
        void eliminarInmueble(int codigoInmueble);
        //std::list<DTInmueble> listarInmueblesAdministrados(Inmobiliaria* inmobiliaria);
        std::list<DTInmueble> listarInmuebles();
        // std::list<DTInmuebleListado>ListarInmueblesListados();
        std::map<int,Inmueble*> getInmuebles();
        ~ManejadorInmueble();
};

#endif