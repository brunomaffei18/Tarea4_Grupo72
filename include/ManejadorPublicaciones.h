#ifndef MANEJADORPUBLICACIONES_H
#define MANEJADORPUBLICACIONES_H

#include "Publicacion.h"
#include <list>

class ManejadorPublicaciones {
    private:
        std::list<Publicacion*> publicaciones;

    public:
        void altaPublicacion(Publicacion* p);
        void eliminarPublicacion(int codigo);
        std::list<Publicacion*> listarPublicacionesAdministradas();
        ~ManejadorPublicaciones();
};

#endif