#ifndef DTINMUEBLEADMINISTRADO_H
#define DTINMUEBLEADMINISTRADO_H
#include "DTFecha.h"
#include <string>
#include <iostream>

class DTInmuebleAdministrado {
    private:
        int codigo;
        std::string direccion;
        DTFecha* fechaComienzo;

    public:
        DTInmuebleAdministrado(int codigo, std::string direccion, DTFecha* fechaComienzo);
        int getCodigo();
        std::string getDireccion();
        DTFecha* getFechaComienzo();
        ~DTInmuebleAdministrado();
};

std::ostream& operator<<(std::ostream& os, const DTInmuebleAdministrado& dt);

#endif