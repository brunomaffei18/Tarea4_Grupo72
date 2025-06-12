#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "Publicacion.h"
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include <string>
#include "AdministraPropiedad.h"
#include "../include/Publicacion.h"

Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa)
    : codigo(codigo), fecha(fecha), tipo(tipo), texto(texto), precio(precio), activa(activa), adminProp(nullptr) {}
    
int Publicacion::getCodigo();{return this.}
DTFecha* getFecha();
std::string getTexto();
std::string getPrecio();
std::string getInmobiliaria();
AdministraPropiedad* getAdministra();
bool Publicacion::esActiva();{return this.}
bool verificarInmobiiaria(int codigoInmbo,int codigoInmueble,std::string nickNameInmobiliaria,std::string nickNameInmob);
~Publicacion();





#endif