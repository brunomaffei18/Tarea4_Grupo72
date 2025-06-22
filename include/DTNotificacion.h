#ifndef DTNotificacion_H
#define DTNotificacion_H

#include "TipoInmueble.h"
#include "TipoPublicacion.h"
#include <string>
#include <iostream>

class DTNotificacion
{
private:
 int codigoInmueble;
 std::string nickNameInmobiliaria;
 TipoPublicacion tipoPubli;
 TipoInmuebleenum::TipoInmueble tipoInmueble;
 std::string txt;
public:
    DTNotificacion(int codigoInmueble, std::string nickNameInmobiliaria,
        TipoPublicacion tipoPubli, TipoInmuebleenum::TipoInmueble tipoInmueble, std::string txt);
    
    int getCodigo() const;
    std::string getNickInmobiliaria() const;
    TipoPublicacion getTipoPubli() const;
    TipoInmuebleenum:: TipoInmueble getTipoInmueble() const;
    std::string getTxt() const;
    
    ~DTNotificacion();
};

bool operator<(const DTNotificacion& a,const DTNotificacion& b);
std::ostream& operator<<(std::ostream& os, const DTNotificacion& dt);


#endif