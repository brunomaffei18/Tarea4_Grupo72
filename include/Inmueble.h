#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include <set>
#include "Propietario.h"
#include "DTInmueble.h"
#include "DTInmuebleAdministrado.h"
#include "AdministraPropiedad.h"

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        Propietario* propietario;
        std::set<AdministraPropiedad*> InmueblesAdministrados;
    public:
    Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
    int getCodigo();
    std::string getDireccion();
    int getNumeroPuerta();
    int getSuperficie();
    int getAnoConstruccion();
    std::set<AdministraPropiedad*>getInmueblesAdministrados();
    Propietario* getPropietario();

    void setPropietario(Propietario* p);
    virtual TipoInmuebleenum::TipoInmueble getTipoInmueble() const=0; 
    void AgragarAdministrados(AdministraPropiedad*Administrados);
    void EliminarPublicaciones();
    void eliminarAdministrados(AdministraPropiedad* administrados);
    ~Inmueble();
};

#endif