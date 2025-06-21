#include "../include/DTCasa.h"

DTCasa::DTCasa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo)
    : DTInmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion) {
    this->esPH = esPH;
    this->techo = techo;
}

bool DTCasa::getEsPH() {
    return esPH;
}

TipoTecho DTCasa::getTecho() {
    return techo;
}

DTCasa::~DTCasa(){
    
}


 std::ostream& operator<<(std::ostream& os,  DTCasa dt){
    std::string esph;
    if (dt.getEsPH())
    {
        esph= "Si";
    }else{
        esph="No";
    }

   os<<"Codigo: "<<dt.getCodigo()<<", direccion: "<<dt.getDireccion()<<", nro. puerta: "<<dt.getNumeroPuerta()<<", superficie: "<<dt.getSuperficie()<< "m2, consturccion: "<<dt.getAnioConstruccion()<<", PH: "<<esph<<", Tipo de techo: "<<dt.getTecho()<< std::endl;;
    return os;
 }