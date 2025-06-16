#include "TipoInmueble.h"
#include "TipoPublicacion.h"
#include <string>
#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion(int codigoInmueble, std::string nickNameInmobiliaria,TipoPublicacion tipoPubli, TipoInmueble tipoInmueble, std::string txt):
    codigoInmueble(codigoInmueble), nickNameInmobiliaria(nickNameInmobiliaria),tipoPubli(tipoPubli),tipoInmueble(tipoInmueble),txt(txt){}

int DTNotificacion::getCodigo() const {
    return codigoInmueble;
}
std::string DTNotificacion::getNickInmobiliaria() const {
    return nickNameInmobiliaria;
}
TipoPublicacion DTNotificacion::getTipoPubli() const {
    return tipoPubli;
}
TipoInmueble DTNotificacion::getTipoInmueble() const {
    return tipoInmueble;
}
std::string DTNotificacion::getTxt() const {
    return txt;
}

DTNotificacion::~DTNotificacion() {}


bool operator<(const DTNotificacion& a, const DTNotificacion& b) {
    if (a.getCodigo() != b.getCodigo())
        return a.getCodigo() < b.getCodigo();
    return a.getNickInmobiliaria() < b.getNickInmobiliaria();
}