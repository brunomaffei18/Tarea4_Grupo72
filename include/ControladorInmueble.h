#ifndef CONTROLADORINMUEBLE_H
#define CONTROLADORINMUEBLE_H

#include <string>
#include <set>
#include "../include/DTInmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include "../include/ManejadorInmueble.h"

class ControladorInmueble: public IControladorInmueble
{
private:
    static ControladorInmueble* Instancia;
    ControladorInmueble();
public:
    static ControladorInmueble* getInstancia();
    DTInmueble detalleInmueble(int codigoInmueble);
    void eliminarInmueble(int codigoInmueble);
    std::set<DTInmueble*> listarInmuebles();

    ~ControladorInmueble();
};

#endif