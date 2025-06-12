#ifndef CONTROLADORPUBLICACION_H
#define CONTROLADORPUBLICACION_H
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include <string>
#include <set>
#include "DTInmueble.h"
#include "DTPublicacion.h"
#include "Inmobiliaria.h"
#include "Propietario.h"
#include "Cliente.h"


class ControladorPublicacion
{
private:
    static ControladorPublicacion* Instancia;
    ControladorPublicacion();
public:
    static ControladorPublicacion* getInstancia();
    bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);
    std::set<DTPublicacion*> listarPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);
    DTPublicacion getPublicacion(int id);
    DTInmueble detalleInmueblePublicacion(int codigoPublicacion);
    ~ControladorPublicacion();
};

#endif