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
// Constructor copia
DTPublicacion::DTPublicacion(const DTPublicacion& other) {
    this->codigo = other.codigo;
    this->fecha = new DTFecha(*(other.fecha));  // deep copy
    this->texto = other.texto;
    this->precio = other.precio;
    this->inmobiliaria = other.inmobiliaria;
}

// Operador de asignación
DTPublicacion& DTPublicacion::operator=(const DTPublicacion& other) {
    if (this != &other) {
        // Limpiar lo que ya tengo
        delete this->fecha;

        // Copiar nuevo contenido
        this->codigo = other.codigo;
        this->fecha = new DTFecha(*(other.fecha));  // deep copy
        this->texto = other.texto;
        this->precio = other.precio;
        this->inmobiliaria = other.inmobiliaria;
    }
    return *this;
}

bool DTPublicacion::operator<(const DTPublicacion& a) const {
    return this->codigo < a.codigo; 
}
