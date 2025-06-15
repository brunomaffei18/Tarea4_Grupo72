#ifndef MANEJADORPUBLICACIONES_H
#define MANEJADORPUBLICACIONES_H
#include <map>
#include "../include/Publicacion.h"
#include <list>
#include "../include/DTPublicacion.h"

class ManejadorPublicaciones {
    private:
        std::map<int,Publicacion*> publicaciones;

    public:
        
        std::list<DTPublicacion*> listarPublicacionesAdministradas();
        ~ManejadorPublicaciones();
};

#endif