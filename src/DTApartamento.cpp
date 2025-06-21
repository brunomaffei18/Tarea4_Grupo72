#include "../include/DTApartamento.h"

DTApartamento::DTApartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes)
    : DTInmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion) {
    this->piso = piso;
    this->tieneAscensor = tieneAscensor;
    this->gastosComunes = gastosComunes;
}

int DTApartamento::getPiso() {
    return piso;
}

bool DTApartamento::getTieneAscensor() {
    return tieneAscensor;
}

float DTApartamento::getGastosComunes() {
    return gastosComunes;
}

DTApartamento::~DTApartamento(){

}

 std::ostream& operator<<(std::ostream& os,  DTApartamento dt) {
   std::string ascensor;
    if (dt.getTieneAscensor())
    {
        ascensor= "Si";
    }else{
        ascensor="No";
    }
    
  os<<"Codigo: "<<dt.getCodigo()<<", direccion: "<<dt.getDireccion()<<", nro. puerta: "<<dt.getNumeroPuerta()<<", superficie: "<<dt.getSuperficie()<< "m2"<<", consturccion: "<<dt.getAnioConstruccion()<<", piso: "<<dt.getPiso()<<", ascensor: "<<ascensor<<", gastos comunes: "<<dt.getGastosComunes();
    return os;
}