#ifndef CASA_H
#define CASA_H
#include "../include/Inmueble.h"
#include "../include/TipoTecho.h"
#include <string>

class Casa : public Inmueble {
    private:
        bool esPH;
        TipoTecho techo;

    public:
        Casa(bool esPH, TipoTecho techo,int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        bool getEsPH();
        TipoTecho getTecho();
        TipoInmuebleenum::TipoInmueble getTipoInmueble() const override;
        ~Casa();
};

#endif