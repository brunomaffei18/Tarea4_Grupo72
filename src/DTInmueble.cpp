#include "../include/DTInmueble.h"

DTInmueble::DTInmueble()
{
    this->codigo = -1;
    this->direccion = "";
    this->numeroPuerta = 0;
    this->superficie = 0;
    this->anioConstruccion = 0;
}
DTInmueble::DTInmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anioConstruccion = anioConstruccion;
}

int DTInmueble::getCodigo() {
    return codigo;
}

std::string DTInmueble::getDireccion() {
    return direccion;
}

int DTInmueble::getNumeroPuerta() {
    return numeroPuerta;
}

int DTInmueble::getSuperficie() {
    return superficie;
}

int DTInmueble::getAnioConstruccion() {
    return anioConstruccion;
}

/*std::ostream& operator<<(std::ostream& os, DTInmueble& dt) {
    os << "Código: " << dt.getCodigo() << ", Dirección: " << dt.getDireccion();
    return os;
}*/

std::ostream& operator<<(std::ostream& os, DTInmueble dt) {
    os << "Código: " << dt.getCodigo() << ", Dirección: " << dt.getDireccion()
       << ", Número de Puerta: " << dt.getNumeroPuerta() << ", Superficie: " << dt.getSuperficie()
       << ", Año de Construcción: " << dt.getAnioConstruccion();
    return os;
}


DTInmueble::~DTInmueble(){
    
}