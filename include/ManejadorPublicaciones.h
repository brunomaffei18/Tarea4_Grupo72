#ifndef MANEJADORPUBLICACIONES_H
#define MANEJADORPUBLICACIONES_H
#include <map>
#include "Publicacion.h"
#include <list>
#include "DTPublicacion.h"

class ManejadorPublicaciones {
    private:
        std::map<int,Publicacion*> publicaciones;

    public:
        void altaPublicacion(Publicacion* p);
        void eliminarPublicacion(int codigo);
        std::list<DTPublicacion*> listarPublicacionesAdministradas();
        ~ManejadorPublicaciones();
};

#endif