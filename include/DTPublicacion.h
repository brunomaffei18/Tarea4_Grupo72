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
        DTPublicacion(const DTPublicacion& other);             // Constructor copia
        DTPublicacion& operator=(const DTPublicacion& other);
        int getCodigo();
        DTFecha* getFecha();
        std::string getTexto();
        std::string getPrecio();
        std::string getInmobiliaria();
        ~DTPublicacion();

        bool operator<(const DTPublicacion& a) const;
};

std::ostream& operator<<(std::ostream& os,  DTPublicacion& dt);

#endif