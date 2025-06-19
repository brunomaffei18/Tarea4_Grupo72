#include "../include/ControladorPublicacion.h"
#include "../include/ManejadorPublicaciones.h"
#include "../include/Publicacion.h"
#include "../include/ControladorFechaActual.h"
#include "../include/DTFecha.h"
#include"../include/ManejadorUsuario.h"
#include "../include/ManejadorInmueble.h"
#include "../include/ControladorAdministrarInmueble.h"
#include <set>
#include "../include/ManejadorNotificaciones.h"
#include"../include/Subscriptor.h"
#include "../include/DTPublicacion.h"
#include "../include/DTInmueble.h"
#include "../include/TipoInmueble.h"

  ControladorPublicacion* ControladorPublicacion::getInstancia(){
    if (Instancia==NULL){
        Instancia=new ControladorPublicacion();
    }
    return Instancia;
  };
    bool ControladorPublicacion::altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio){
      ManejadorPublicaciones* manejador=ManejadorPublicaciones::getManejadorPublicaciones(); 
      std::list<Publicacion*> publicaciones=manejador->listarPublicaciones();
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
    Inmobiliaria* inmobiliaria = ManejadorUsuario::getManejadorUsuario()->getInmobiliaria(nicknameInmobiliaria);
    Inmueble* inmueble = ManejadorInmueble::getManejadorInmueble()->getInmueble(codigoInmueble);
    int nuevoCodigo=ManejadorPublicaciones::getManejadorPublicaciones()->generarCodigo();
    bool activa=true;

    Publicacion* nuevaPublicacion=new Publicacion(nuevoCodigo, &fecha,tipoPublicacion, texto, precio, activa);
    AdministraPropiedad * admin=new AdministraPropiedad(&fecha, inmueble, inmobiliaria);
    nuevaPublicacion->setAdministra(admin);
    manejador->agregarPublicacion(nuevaPublicacion);

    for (std::list<Subscriptor*>::iterator i = ManejadorNotificaciones::getInstance()->getSubs().begin(); i != ManejadorNotificaciones::getInstance()->getSubs().end(); i++)
    {
      if((*i)->estaSuscriptoA(inmobiliaria)){
        (*i)->notificar(nuevaPublicacion);
      }
    }
    
    
    
    
    };

  std::set<DTPublicacion*> ControladorPublicacion::listarPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmuebleenum::TipoInmueble tipoInmueble){
    std::set<DTPublicacion*> publicacionesFiltradas;
    std::list<Publicacion*> listaPublicaciones = ManejadorPublicaciones::getManejadorPublicaciones()->listarPublicaciones();
    for (std::list<Publicacion*>::iterator i = listaPublicaciones.begin(); i !=listaPublicaciones.end(); i++)
    {
      if ((*i)->getTipo()==tipoPublicacion && (*i)->getPrecio()>precioMinimo&& (*i)->getPrecio()<precioMaximo)
      if (tipoInmueble==TipoInmuebleenum::Todos)
      {
        DTPublicacion* dtdupPlicacion=new DTPublicacion((*i)->getCodigo(),(*i)->getFecha(),(*i)->getTexto(),(*i)->ConvertirPrecio(),(*i)->getInmobiliaria()->getNickname());
        publicacionesFiltradas.insert(dtdupPlicacion);
      }else {
        if( tipoInmueble==(*i)->getTipo()){
          DTPublicacion* dtdupPlicacion=new DTPublicacion((*i)->getCodigo(),(*i)->getFecha(),(*i)->getTexto(),(*i)->ConvertirPrecio(),(*i)->getInmobiliaria()->getNickname());
          publicacionesFiltradas.insert(dtdupPlicacion);
        }
      }
      
    }
    return publicacionesFiltradas;

    };
    DTPublicacion ControladorPublicacion::getPublicacion(int id){
     

      std::list<Publicacion*> listaPublicaciones = ManejadorPublicaciones::getManejadorPublicaciones()->listarPublicaciones();
      for(std::list<Publicacion*>::iterator i=listaPublicaciones.begin();i!=listaPublicaciones.end();i++){
        if((*i)->getCodigo()==id){
         return DTPublicacion((*i)->getCodigo(),(*i)->getFecha(),(*i)->getTexto(),(*i)->ConvertirPrecio(),(*i)->getInmobiliaria()->getNickname());
          
        }
      }
      
    };
    DTInmueble ControladorPublicacion::detalleInmueblePublicacion(int codigoPublicacion){
 std::list<Publicacion*> listaPublicaciones = ManejadorPublicaciones::getManejadorPublicaciones()->listarPublicaciones();
      for(std::list<Publicacion*>::iterator i=listaPublicaciones.begin();i!=listaPublicaciones.end();i++){
        if((*i)->getCodigo()==codigoPublicacion){
          return DTInmueble((*i)->getInmueble()->getCodigo(),(*i)->getInmueble()->getDireccion(),(*i)->getInmueble()->getNumeroPuerta(),(*i)->getInmueble()->getSuperficie(),(*i)->getInmueble()->getAnoConstruccion());
        }
      }
      
    };
    ControladorPublicacion::~ControladorPublicacion(){
      
    };