#include "DTFecha.h"
#include "../include/Publicacion.h"
#include "../include/AdministraPropiedad.h" 

Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa)
    : codigo(codigo), fecha(fecha), tipo(tipo), texto(texto), precio(precio), activa(activa), adminProp(nullptr) {}
    
int Publicacion::getCodigo(){return this->codigo;}

DTFecha* Publicacion::getFecha() {return this->fecha;}

std::string Publicacion::getTexto(){return this->texto;}

float Publicacion::getPrecio(){return this->precio;}

//std::string Publicacion::getInmobiliaria(); No figura en nuestro diagrama

AdministraPropiedad* Publicacion::getAdministra(){this->adminProp;}

bool Publicacion::esActiva(){return this->activa;}

bool Publicacion::verificarInmobiiaria(int codigoInmbo,int codigoInmueble,std::string nickNameInmobiliaria,std::string nickNameInmob){
    return ((codigoInmbo==codigoInmueble) && (nickNameInmob==nickNameInmobiliaria));
}

Publicacion::~Publicacion(){
    delete this->fecha;
}


