#ifndef CONTROLADORADMINTRARINMUEBLE_H
#define CONTROLADORADMINTRARINMUEBLE_H

#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include"../include/DTInmuebleListado.h"
#include <set>
#include <string>
#include"../include/IControladorAdministrarInmueble.h"
class ControladorAdministrarInmueble: public IControladorAdministrarInmueble {
    private:
       static ControladorAdministrarInmueble* instancia;
       ControladorAdministrarInmueble();

    public:
    static ControladorAdministrarInmueble* getInstancia();
    std:: set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria);
    void altaAdministrarPropiedad(std::string nickNameInmobiliaria,int codigoInmueble);

};

#endif