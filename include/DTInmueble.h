#ifndef DTINMUEBLE_H
#define DTINMUEBLE_H
#include <string>
#include <iostream>

class DTInmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anioConstruccion;

    public:
        DTInmueble();
        DTInmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion);
        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnioConstruccion();
        friend std::ostream& operator<<(std::ostream& os, DTInmueble dt);
        virtual ~DTInmueble();
};



#endif