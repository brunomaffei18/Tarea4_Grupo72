#ifndef CONTROLADORINMUEBLE_H
#define CONTROLADORINMUEBLE_H

#include "../include/Casa.h"
#include <string>
#include <set>
#include "../include/DTInmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include "../include/ManejadorInmueble.h"
#include "../include/IControladorInmueble.h"
#include "../include/ManejadorInmueble.h"
#include "../include/TipoTecho.h"


class ControladorInmueble: public IControladorInmueble
{
private:
    static ControladorInmueble* Instancia;
    ControladorInmueble();
    ManejadorInmueble* manejadorinm;
public:
    static ControladorInmueble* getInstancia();
    void altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo);
    void altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);
    DTInmueble detalleInmueble(int codigoInmueble);

    std::set<DTInmueble*> listarInmuebles();
//    void eliminarInmueble(int codigoInmueble);
    ~ControladorInmueble();
};

#endif