#ifndef ICONTROLADORINMUEBLE_H
#define ICONTROLADORINMUEBLE_H

#include <string>
#include <set>
#include "../include/DTInmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include "../include/TipoTecho.h"

class IControladorInmueble
{
public:
    virtual DTInmueble detalleInmueble(int codigoInmueble)=0;
     virtual void eliminarInmueble(int codigoInmueble)=0;
    virtual std::set<DTInmueble*> listarInmuebles()=0;
    virtual ~IControladorInmueble()=default;
    virtual void altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo)=0;
    virtual void altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes)=0;
};

#endif