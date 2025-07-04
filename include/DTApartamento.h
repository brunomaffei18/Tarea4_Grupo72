#ifndef DTAPARTAMENTO_H
#define DTAPARTAMENTO_H
#include "DTInmueble.h"
#include <iostream>

class DTApartamento : public DTInmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        DTApartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes);
        int getPiso();
        bool getTieneAscensor();
        float getGastosComunes();
        virtual ~DTApartamento();
};

 std::ostream& operator<<(std::ostream& os,  DTApartamento dt);

#endif