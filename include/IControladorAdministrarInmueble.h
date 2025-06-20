#ifndef ICONTROLADORADMINTRARINMUEBLE_H
#define ICONTROLADORADMINTRARINMUEBLE_H

#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include"../include/DTInmuebleListado.h"
#include <set>
#include <string>

class IControladorAdministrarInmueble {
    public:
        virtual std:: set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria)=0;
        virtual void altaAdministrarPropiedad(std::string nickNameInmobiliaria,int codigoInmueble)=0;
        virtual ~IControladorAdministrarInmueble()=default;

};

#endif