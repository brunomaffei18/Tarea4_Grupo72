#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include <string>
#include "AdministraPropiedad.h"

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad * adminProp;    //Link a su unica AdministraPropiedad

public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa);
    int getCodigo();
    DTFecha* getFecha();
    std::string getTexto();
    std::string getPrecio();
    std::string getInmobiliaria();
    AdministraPropiedad* getAdministra();
    bool esActiva();
    bool verificarInmobiiaria(int codigoInmbo,int codigoInmueble,std::string nickNameInmobiliaria,std::string nickNameInmob);
    ~Publicacion();
};

#endif