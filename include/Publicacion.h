#ifndef PUBLICACION_H 
#define PUBLICACION_H
#include "../include/DTFecha.h"
#include "../include/TipoPublicacion.h"
#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include <string>



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
    float getPrecio();
    Inmobiliaria* getInmobiliaria();
    Inmueble* getInmueble();
    AdministraPropiedad* getAdministra();
    bool esActiva();
    void setAdministra(AdministraPropiedad* admin);
    bool verificarInmobiiaria(int codigoInmbo,int codigoInmueble,std::string nickNameInmobiliaria,std::string nickNameInmob);
    ~Publicacion();
    TipoPublicacion getTipo();
    void setActiva(bool activa);
    std::string ConvertirPrecio();
};

#endif