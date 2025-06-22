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
    virtual bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio) =0;
    virtual std::set<DTPublicacion*> listarPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmuebleenum::TipoInmueble tipoInmueble) =0;
    virtual DTPublicacion getPublicacion(int id) =0;
    virtual DTInmueble detalleInmueblePublicacion(int codigoPublicacion) =0;
    virtual ~IControladorPublicacion() =0;

};

#endif