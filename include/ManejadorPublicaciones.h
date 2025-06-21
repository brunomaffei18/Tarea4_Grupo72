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
        int codigoUltimaPUblicacionVenta;
        int codigoUltimaPUblicacionAlquiler;
        ManejadorPublicaciones();
    public:
        static ManejadorPublicaciones* getManejadorPublicaciones();
        int generarCodigo();
        void agregarPublicacion(Publicacion* publicacion);
        std::list<Publicacion*>listarPublicaciones();
        //ManejadorPublicaciones();
        void setCodigoUltimaPublicacionVenta(int codigo);
        int getCodigoUltimaPublicacionVenta() const ;
        void setCodigoUltimaPublicacionAlquiler(int codigo);
        int getCodigoUltimaPublicacionAlquiler() const ;
    
        ~ManejadorPublicaciones();
};

#endif