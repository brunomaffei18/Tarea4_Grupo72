#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "DTInmueble.h"
class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
 
    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        void EliminarPublicaciones();
        ~Inmueble();
};

#endif