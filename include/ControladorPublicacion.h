#ifndef CONTROLADORPUBLICACION_H
#define CONTROLADORPUBLICACION_H
#include "../include/TipoPublicacion.h"
#include "../include/TipoInmueble.h"
#include <string>
#include <set>
#include "../include/DTInmueble.h"
#include "../include/DTPublicacion.h"
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include "../include/IControladorPublicacion.h"
#include "ManejadorPublicaciones.h"


class ControladorPublicacion :public:IControladorPublicacion
{
private:
    static ControladorPublicacion* Instancia;
    ControladorPublicacion();
    ManejadorPublicaciones* manejadorpub;
public:
    static ControladorPublicacion* getInstancia();
    bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);
    std::set<DTPublicacion*> listarPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);
    DTPublicacion getPublicacion(int id);
    DTInmueble detalleInmueblePublicacion(int codigoPublicacion);
    ~ControladorPublicacion();
};

#endif