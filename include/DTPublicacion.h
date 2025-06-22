#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H
#include "DTFecha.h"
#include <string>
#include <iostream>

class DTPublicacion {
    private:
        int codigo;
        DTFecha* fecha;
        std::string texto;
        std::string precio;
        std::string inmobiliaria;

    public:
        DTPublicacion();
        DTPublicacion(int codigo, DTFecha* fecha, std::string texto, std::string precio, std::string inmobiliaria);
        int getCodigo();
        DTFecha* getFecha();
        std::string getTexto();
        std::string getPrecio();
        std::string getInmobiliaria();
        ~DTPublicacion();
};

std::ostream& operator<<(std::ostream& os,  DTPublicacion& dt);
bool operator<(const DTPublicacion& a, const DTPublicacion& b);

#endif