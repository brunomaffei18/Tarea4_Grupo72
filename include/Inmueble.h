#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "../include/DTInmueble.h"
#include <set>
#include "../include/DTInmuebleAdministrado.h"
#include "../include/AdministraPropiedad.h"

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        std::set<AdministraPropiedad*> InmueblesAdministrados;
    public:
     int getCodigo();
     std::string getDireccion();
     int getNumeroPuerta();
     int getSuperficie();
     int getAnoConstruccion();
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        void AgragarAdministrados(AdministraPropiedad*Administrados);
        void EliminarPublicaciones();
        std::set<AdministraPropiedad*>getInmueblesAdministrados();
        void eliminarAdministrados(AdministraPropiedad* administrados);
        ~Inmueble();
};

#endif