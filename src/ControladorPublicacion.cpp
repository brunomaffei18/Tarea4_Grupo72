#include "../include/ControladorPublicacion.h"

  ControladorPublicacion* ControladorPublicacion::getInstancia(){
    if (Instancia==NULL){
        Instancia=new ControladorPublicacion();
    }
    return Instancia;
  };
    bool ControladorPublicacion::altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio){

    };
    std::set<DTPublicacion*> listarPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble){

    };
    DTPublicacion getPublicacion(int id){

    };
    DTInmueble detalleInmueblePublicacion(int codigoPublicacion){

    };
    ControladorPublicacion::~ControladorPublicacion(){

    };