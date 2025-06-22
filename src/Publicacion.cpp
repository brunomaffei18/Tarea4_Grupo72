#include "../include/DTFecha.h"
#include "../include/Publicacion.h"
#include "../include/AdministraPropiedad.h" 
#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include "../include/TipoPublicacion.h"

Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa)
    : codigo(codigo), fecha(fecha), tipo(tipo), texto(texto), precio(precio), activa(activa), adminProp(nullptr) {}
    
int Publicacion::getCodigo(){return this->codigo;}
TipoPublicacion Publicacion::getTipo(){return this->tipo;}

DTFecha* Publicacion::getFecha() {return this->fecha;}

std::string Publicacion::getTexto(){return this->texto;}

float Publicacion::getPrecio(){return this->precio;}

Inmobiliaria* Publicacion::getInmobiliaria(){return this->adminProp->getInmobiliaria();}
Inmueble* Publicacion::getInmueble(){return this->adminProp->getInmueble();}
AdministraPropiedad* Publicacion::getAdministra(){return this->adminProp;}

bool Publicacion::esActiva(){return this->activa;}

bool Publicacion::verificarInmobiiaria(int codigoInmbo,int codigoInmueble,std::string nickNameInmobiliaria,std::string nickNameInmob){
    return ((codigoInmbo==codigoInmueble) && (nickNameInmob==nickNameInmobiliaria));
}

/*std::string Publicacion::ConvertirPrecio(Publicacion* p) {
    std::string precioSTR = std::to_string(p->getPrecio());
    return precioSTR;
}*/

std::string Publicacion::ConvertirPrecio() {
    return std::to_string(this->precio);
}

Publicacion::~Publicacion(){
    delete this->fecha;
}

void Publicacion::setAdministra(AdministraPropiedad* admin) {
    this->adminProp = admin;
}

void Publicacion::setActiva(bool activa) {
    this->activa = activa;
}


