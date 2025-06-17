#include "../include/ControladorPublicacion.h"
#include "../include/ManejadorPublicaciones.h"
#include "../include/Publicacion.h"
#include "../include/ControladorFechaActual.h"
#include "../include/DTFecha.h"
#include"../include/ManejadorUsuario.h"
  ControladorPublicacion* ControladorPublicacion::getInstancia(){
    if (Instancia==NULL){
        Instancia=new ControladorPublicacion();
    }
    return Instancia;
  };
    bool ControladorPublicacion::altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio){
       std::list<Publicacion*> publicaciones=ManejadorPublicaciones::getManejadorPublicaciones()->listarPublicaciones();
      bool exist=false;
      DTFecha fecha= ControladorFechaActual::getInstance()->getFechaActual();
      for (std::list<Publicacion*>::iterator i=publicaciones.begin();i!=publicaciones.end() && exist==false ;i++){
        if( (*i)->getFecha()->operator==(&fecha) && (*i)->getTipo()==tipoPublicacion){
          Inmobiliaria* inmobiliaria=(*i)->getInmobiliaria();
          Inmueble* inmueble=(*i)->getInmueble();
          if(inmueble->getCodigo()==codigoInmueble && inmobiliaria->getNickname()==nicknameInmobiliaria){
            exist=true;
          }

        }
      }
      if (exist){
        return false;
      }
    Inmobiliaria* inmobiliaria = ManejadorUsuario::getManejadorUsuario().getInmobiliaria(nicknameInmobiliaria);
    Inmueble* inmueble = ManejadorUsuario::getManejadorUsuario().getInmueble(codigoInmueble);
    };
    std::set<DTPublicacion*> listarPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble){
     
    };
    DTPublicacion getPublicacion(int id){

    };
    DTInmueble detalleInmueblePublicacion(int codigoPublicacion){

    };
    ControladorPublicacion::~ControladorPublicacion(){

    };