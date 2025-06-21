#ifndef DTCASA_H
#define DTCASA_H
#include "DTInmueble.h"
#include "TipoTecho.h"
#include <iostream>

class DTCasa :public DTInmueble {
    private:
        bool esPH;
        TipoTecho techo;

    public:
        DTCasa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo);
        bool getEsPH();
        TipoTecho getTecho();
        virtual ~DTCasa();
};

 std::ostream& operator<<(std::ostream& os,  DTCasa dt);

#endif