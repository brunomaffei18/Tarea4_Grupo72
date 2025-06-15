#ifndef ICONTROLADORPUBLICACION_H
#define ICONTROLADORPUBLICACION_H
#include "../include/TipoPublicacion.h"
#include "../include/TipoInmueble.h"
#include <string>
#include <set>
#include "../include/DTInmueble.h"
#include "../include/DTPublicacion.h"
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"


class IControladorPublicacion
{
public:
    virtual bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);
    virtual std::set<DTPublicacion*> listarPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);
    virtual DTPublicacion getPublicacion(int id);
    virtual DTInmueble detalleInmueblePublicacion(int codigoPublicacion);
};

#endif