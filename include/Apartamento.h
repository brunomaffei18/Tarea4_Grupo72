#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "../include/Inmueble.h"


class Apartamento : public Inmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        Apartamento(int piso, bool tieneAscensor, float gastosComunes,int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
       int getPiso();
       bool getTieneAscensor();
       float getGastosComunes();
       TipoInmuebleenum::TipoInmueble getTipoInmueble() const override;
        ~Apartamento();
};

#endif