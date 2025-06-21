#include "../include/DTInmuebleListado.h"

DTInmuebleListado::DTInmuebleListado(int codigo, std::string direccion, std::string propietario) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->propietario = propietario;
}

int DTInmuebleListado::getCodigo() {
    return codigo;
}

std::string DTInmuebleListado::getDireccion() {
    return direccion;
}

std::string DTInmuebleListado::getPropietario() {
    return propietario;
}

 std::ostream& operator<<(std::ostream& os,  DTInmuebleListado dt){
    os<<"- Codigo: "<<dt.getCodigo()<<", direccion: "<<dt.getDireccion()<<", propietario: "<<dt.getPropietario();
    return os;
 };

 bool DTInmuebleListado::operator<(const DTInmuebleListado& inmuebleB) const {
    return this->codigo < inmuebleB.codigo;
}