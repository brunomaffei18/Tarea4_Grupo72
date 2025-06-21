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
        int codigoUltimaPUblicacion;
        ManejadorPublicaciones();
    public:
        static ManejadorPublicaciones* getManejadorPublicaciones();
        int generarCodigo();
        void agregarPublicacion(Publicacion* publicacion);
        std::list<Publicacion*>listarPublicaciones();
        //ManejadorPublicaciones();
        void setCodigoUltimaPublicacion(int codigo);
        int getCodigoUltimaPublicacion() const ;
    
        ~ManejadorPublicaciones();
};

#endif