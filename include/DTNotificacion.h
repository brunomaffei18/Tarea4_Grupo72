#ifndef DTNotificacion_H
#define DTNotificacion_H

#include "TipoInmueble.h"
#include "TipoPublicacion.h"
#include <string>

class DTNotificacion
{
private:
 int codigoInmueble;
 std::string nickNameInmobiliaria;
 TipoPublicacion tipoPubli;
 TipoInmueble tipoInmueble;
 std::string txt;
public:
    DTNotificacion(int codigoInmueble, std::string nickNameInmobiliaria,
        TipoPublicacion tipoPubli, TipoInmueble tipoInmueble, std::string txt);
    
    int getCodigo() const;
    std::string getNickInmobiliaria() const;
    TipoPublicacion getTipoPubli() const;
    TipoInmueble getTipoInmueble() const;
    std::string getTxt() const;
    
    ~DTNotificacion();
};



#endif