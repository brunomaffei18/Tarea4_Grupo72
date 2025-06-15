#ifndef ICONTROLADORINMUEBLE_H
#define ICONTROLADORINMUEBLE_H

#include <string>
#include <set>
#include "../include/DTInmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"

class IControladorInmueble
{
public:
    virtual DTInmueble detalleInmueble(int codigoInmueble)=0;
    virtual void eliminarInmueble(int codigoInmueble)=0;
    virtual std::set<DTInmueble*> listarInmuebles()=0;
};

#endif