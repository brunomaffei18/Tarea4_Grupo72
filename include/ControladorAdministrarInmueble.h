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
<<<<<<< HEAD
    static ControladorAdministrarInmueble* getInstancia();
    std:: set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria);
    std:: set<DTInmuebleListado> listarInmueblesAdministradosInmobiliaria(std::string nicknameInmobiliaria);
    void altaAdministrarPropiedad(std::string nickNameInmobiliaria,int codigoInmueble);
=======
        static ControladorAdministrarInmueble* getInstancia();
        std:: set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria);
        void altaAdministrarPropiedad(std::string nickNameInmobiliaria,int codigoInmueble);
>>>>>>> 5fa184e13005d46bc1616b01bc80675bd5676a36

};

#endif