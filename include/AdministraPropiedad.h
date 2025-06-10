#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"
#include "Inmueble.h"
#include "Inmobiliaria.h"
#include "Publicacion.h"

class AdministraPropiedad {
    private:
        DTFecha* fecha;

    public:
        AdministraPropiedad(DTFecha* fecha);
    Inmueble getInmueble();
    Inmobiliaria getInmobiliaria();
    void DarBajaPubicaciones(); 
    void borrarOublicaciones(Publicacion p); 
        ~AdministraPropiedad();
};

#endif