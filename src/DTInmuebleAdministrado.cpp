#include "../include/DTInmuebleAdministrado.h"

DTInmuebleAdministrado::DTInmuebleAdministrado(int codigo, std::string direccion, DTFecha* fechaComienzo)
    : codigo(codigo), direccion(direccion), fechaComienzo(fechaComienzo) {}

int DTInmuebleAdministrado::getCodigo() {
    return codigo;
}

std::string DTInmuebleAdministrado::getDireccion() {
    return direccion;
}

DTFecha DTInmuebleAdministrado::getFechaComienzo() {
    return fechaComienzo;
}

DTInmuebleAdministrado::~DTInmuebleAdministrado(){
}

bool DTInmuebleAdministrado::operator<(const DTInmuebleAdministrado& other) const {
    return codigo < other.codigo;
}


std::ostream& operator<<(std::ostream& os,  DTInmuebleAdministrado& dt){
 os<<"- Codigo: "<<dt.getCodigo()<<", Direccion: "<<dt.getDireccion()<<", Propietario: ";
    return os;

};