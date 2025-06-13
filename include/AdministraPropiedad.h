#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include <map>

class Publicacion;
class Inmobiliaria;
class Inmueble;
class DTFecha;

class AdministraPropiedad {
    private:
        DTFecha* fecha;
        Inmueble* inmuebleAdmin;
        Inmobiliaria* InmobiliariaResponsable;
        std::map<int, Publicacion*> Publicaciones;

    public:
        AdministraPropiedad(DTFecha* fecha, Inmueble* inmueble, Inmobiliaria* inmobiliaria);


    Inmueble* getInmueble();
    Inmobiliaria* getInmobiliaria();
    void DarBajaPublicaciones(); 
    void borrarPublicaciones(Publicacion p);

        ~AdministraPropiedad();
};

#endif