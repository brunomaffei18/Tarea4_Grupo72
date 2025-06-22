#include "../include/ControladorPublicacion.h"
#include "../include/ManejadorPublicaciones.h"
#include "../include/Publicacion.h"
#include "../include/ControladorFechaActual.h"
#include "../include/DTFecha.h"
#include"../include/ManejadorUsuario.h"
#include "../include/ManejadorInmueble.h"

#include <set>
#include "../include/ManejadorNotificaciones.h"
#include"../include/Subscriptor.h"
#include "../include/DTPublicacion.h"
#include "../include/DTInmueble.h"
#include "../include/TipoInmueble.h"


ControladorPublicacion* ControladorPublicacion::Instancia=NULL;
ControladorPublicacion::ControladorPublicacion() {
    // ni idea
}


  ControladorPublicacion* ControladorPublicacion::getInstancia(){
    if (Instancia==NULL){
        Instancia=new ControladorPublicacion();
    }
    return Instancia;
  };
    bool ControladorPublicacion::altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio)
    {
      ManejadorPublicaciones* manejador=ManejadorPublicaciones::getManejadorPublicaciones(); 
      ManejadorInmueble* manejadorinmu=ManejadorInmueble::getManejadorInmueble();
      ManejadorUsuario* manejadorusu=ManejadorUsuario::getManejadorUsuario();
       
        if (!manejador || !manejadorusu || !manejadorinmu)
        throw std::runtime_error("Error al obtener algún manejador.");
      
   
    Inmobiliaria* inmobiliaria = manejadorusu->getInmobiliaria(nicknameInmobiliaria);
    Inmueble* inmueble = manejadorinmu->getInmueble(codigoInmueble);
      
    if (!inmobiliaria || !inmueble)
        throw std::runtime_error("Inmobiliaria o inmueble no encontrado.");

      std::list<Publicacion*> publicaciones=manejador->listarPublicaciones();
     
      DTFecha *fecha= new DTFecha(ControladorFechaActual::getInstance()->getFechaActual());

      for (auto pub: publicaciones){  
      if ((pub->getFecha()->operator== (fecha)) && pub->getTipo() == tipoPublicacion && pub->getInmueble()->getCodigo() == codigoInmueble && pub->getInmobiliaria()->getNickname() == nicknameInmobiliaria) {
            delete fecha;
            return false;
        }
      }
    
  
 
  int nuevoCodigo=manejador->generarCodigo();
  
    for (Publicacion* pub:publicaciones)
    {
      if (pub->getTipo()==tipoPublicacion && pub->getInmueble()->getCodigo()==codigoInmueble){
        if (tipoPublicacion==Venta && pub->getCodigo()==manejador->getCodigoUltimaPublicacionVenta()){
          pub->setActiva(false);
          manejadorpub->setCodigoUltimaPublicacionVenta(nuevoCodigo);
        }else{
          if(tipoPublicacion==Alquiler && pub->getCodigo()==manejador->getCodigoUltimaPublicacionAlquiler()){
            pub->setActiva(false);
            manejadorpub->setCodigoUltimaPublicacionAlquiler(nuevoCodigo);
        }
      }
    }
  }
    
   
    AdministraPropiedad * admin=new AdministraPropiedad(fecha, inmueble, inmobiliaria);
    Publicacion* nuevaPublicacion=new Publicacion(nuevoCodigo, fecha,tipoPublicacion, texto, precio, true);
   
    nuevaPublicacion->setAdministra(admin);
    manejador->agregarPublicacion(nuevaPublicacion);
    inmueble->AgregarAdministrados(admin);
    inmobiliaria->agregarAdministracion(admin);

    
for (Subscriptor* s:inmobiliaria->getSuscriptores()){
  if (s&&s->estaSuscriptoA(inmobiliaria)){
    s->notificar(nuevaPublicacion);
  }
}


    
    return true;// lo agregue por que tiraba warning de que no devolvia valor booleano
    
    
    
    }

  std::set<DTPublicacion> ControladorPublicacion::listarPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmuebleenum::TipoInmueble tipoInmueble){
    std::set<DTPublicacion> publicacionesFiltradas;
    std::list<Publicacion*> listaPublicaciones = ManejadorPublicaciones::getManejadorPublicaciones()->listarPublicaciones();
    for (std::list<Publicacion*>::iterator i = listaPublicaciones.begin(); i !=listaPublicaciones.end(); i++)
    {
      if ((*i)->getTipo()==tipoPublicacion && (*i)->getPrecio()>precioMinimo&& (*i)->getPrecio()<precioMaximo)
      if (tipoInmueble==TipoInmuebleenum::Todos)
      {
        DTPublicacion dtdupPlicacion= DTPublicacion((*i)->getCodigo(),(*i)->getFecha(),(*i)->getTexto(),(*i)->ConvertirPrecio(),(*i)->getInmobiliaria()->getNickname());
        publicacionesFiltradas.insert(dtdupPlicacion);
      }else {
        if( tipoInmueble==(*i)->getInmueble()->getTipoInmueble()){
          DTPublicacion dtdupPlicacion= DTPublicacion((*i)->getCodigo(),(*i)->getFecha(),(*i)->getTexto(),(*i)->ConvertirPrecio(),(*i)->getInmobiliaria()->getNickname());
          publicacionesFiltradas.insert(dtdupPlicacion);
        }
      }
      
    }
    return publicacionesFiltradas;

    }
    DTPublicacion ControladorPublicacion::getPublicacion(int id){
     

      std::list<Publicacion*> listaPublicaciones = ManejadorPublicaciones::getManejadorPublicaciones()->listarPublicaciones();
      for(std::list<Publicacion*>::iterator i=listaPublicaciones.begin();i!=listaPublicaciones.end();i++){
        if((*i)->getCodigo()==id){
         return DTPublicacion((*i)->getCodigo(),(*i)->getFecha(),(*i)->getTexto(),(*i)->ConvertirPrecio(),(*i)->getInmobiliaria()->getNickname());
          
        }
      }
      return DTPublicacion();
    }
    DTInmueble ControladorPublicacion::detalleInmueblePublicacion(int codigoPublicacion){
 std::list<Publicacion*> listaPublicaciones = ManejadorPublicaciones::getManejadorPublicaciones()->listarPublicaciones();
      for(std::list<Publicacion*>::iterator i=listaPublicaciones.begin();i!=listaPublicaciones.end();i++){
        if((*i)->getCodigo()==codigoPublicacion){
          return DTInmueble((*i)->getInmueble()->getCodigo(),(*i)->getInmueble()->getDireccion(),(*i)->getInmueble()->getNumeroPuerta(),(*i)->getInmueble()->getSuperficie(),(*i)->getInmueble()->getAnoConstruccion());
        }
      }
      return DTInmueble();
    }
    ControladorPublicacion::~ControladorPublicacion(){
      
    }