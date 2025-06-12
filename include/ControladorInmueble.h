#ifndef CONTROLADORINMUEBLE_H
#define CONTROLADORINMUEBLE_H

#include <string>
#include <set>
#include "DTInmueble.h"
#include "Inmobiliaria.h"
#include "Propietario.h"
#include "Cliente.h"

class ControladorInmueble
{
private:
    static ControladorInmueble* Instancia;
    ControladorInmueble();
public:
    static ControladorInmueble* getInstancia();
    DTInmueble detalleInmueble(int codigoInmueble);
    void eliminarInmueble(int codigoInmueble);
    std::set<DTInmueble*> listarInmuebles();
    DTInmueble getInmueble(int codigo);
    ~ControladorInmueble();
};

#endif