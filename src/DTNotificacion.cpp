#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
#include <string>
#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion(int codigoInmueble, std::string nickNameInmobiliaria,TipoPublicacion tipoPubli, TipoInmuebleenum::TipoInmueble tipoInmueble, std::string txt):
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
TipoInmuebleenum::TipoInmueble DTNotificacion::getTipoInmueble() const {
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

std::ostream& operator<<(std::ostream& os, const DTNotificacion& dt) {
    os << "Código Inmueble: " << dt.getCodigo()<< ", Inmobiliaria: " << dt.getNickInmobiliaria()<< ", Tipo Publicación: " << dt.getTipoPubli()<< ", Tipo Inmueble: " << dt.getTipoInmueble()<< ", Texto: " << dt.getTxt()<<std::endl;
        
    return os;
}