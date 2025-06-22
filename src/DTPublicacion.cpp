#include "../include/DTPublicacion.h"
DTPublicacion::DTPublicacion(){
this->codigo = -1;                      
    this->fecha = new DTFecha();           
    this->texto = "";
    this->precio = "";
    this->inmobiliaria = "";
}
DTPublicacion::DTPublicacion(int codigo, DTFecha* fecha, std::string texto, std::string precio, std::string inmobiliaria) {
    this->codigo = codigo;
    this->fecha = new DTFecha(fecha);
    this->texto = texto;
    this->precio = precio;
    this->inmobiliaria = inmobiliaria;
}

int DTPublicacion::getCodigo() {
    return codigo;
}

DTFecha* DTPublicacion::getFecha() {
    return fecha;
}

std::string DTPublicacion::getTexto() {
    return texto;
}

std::string DTPublicacion::getPrecio() {
    return precio;
}

std::string DTPublicacion::getInmobiliaria() {
    return inmobiliaria;
}

DTPublicacion::~DTPublicacion(){
    delete fecha;
}

std::ostream& operator<<(std::ostream& os,  DTPublicacion& dt){
os<<"- Codigo: "<<dt.getCodigo()<<", fecha: "<<dt.getFecha()<<", texto: "<<dt.getTexto()<<", precio: "<<dt.getPrecio()<<", inmobiliaria: "<<dt.getInmobiliaria()<< std::endl;
    return os;
};