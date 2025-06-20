#ifndef MANEJADORPUBLICACIONES_H
#define MANEJADORPUBLICACIONES_H
#include <map>
#include "../include/Publicacion.h"
#include <list>
#include "../include/DTPublicacion.h"

class ManejadorPublicaciones {
    private:
        static ManejadorPublicaciones* instancia;
        std::map<int,Publicacion*> publicaciones;
        int codigo;
        ManejadorPublicaciones();
    public:
        static ManejadorPublicaciones* getManejadorPublicaciones();
        int generarCodigo();
        void agregarPublicacion(Publicacion* publicacion);
        std::list<Publicacion*>listarPublicaciones();
        //ManejadorPublicaciones();
        std::list<DTPublicacion*> listarPublicacionesAdministradas();
        ~ManejadorPublicaciones();
};

#endif