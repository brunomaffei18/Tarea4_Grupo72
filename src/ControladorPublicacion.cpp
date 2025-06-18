#include "../include/ControladorPublicacion.h"
#include "../include/ManejadorPublicaciones.h"
#include "../include/Publicacion.h"
#include "../include/ControladorFechaActual.h"
#include "../include/DTFecha.h"
#include"../include/ManejadorUsuario.h"
#include "../include/ManejadorInmueble.h"
#include "../include/ControladorAdministrarInmueble.h"
#include <set>

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
    Inmobiliaria* inmobiliaria = ManejadorUsuario::getManejadorUsuario().getInmobiliaria(nicknameInmobiliaria);
    Inmueble* inmueble = ManejadorInmueble::getManejadorInmueble()->getInmueble(codigoInmueble);
    int nuevoCodigo=ManejadorPublicaciones::getManejadorPublicaciones()->generarCodigo();
    bool activa=true;

    Publicacion* nuevaPublicacion=new Publicacion(nuevoCodigo, &fecha,tipoPublicacion, texto, precio, activa);
    AdministraPropiedad * admin=new AdministraPropiedad(&fecha, inmueble, inmobiliaria);
    nuevaPublicacion->setAdministra(admin);
    manejador->agregarPublicacion(nuevaPublicacion);

    //falta agregar la parte de suscripciones 
    
    
    };
//     Se retorna el conjunto de los datavalue dtp del tipo DTPublicacion correspondientes a las instancias de Publicacion p que cumplen que 
// p.tipo = tipoPublicacion, p.precio > precioMinimo, 
// p.precio < precioMáximo y si tipoInmueble no es todos 
// entonces el Inmueble relacionado a la instancia AdministraPropiadad ap 
// relacionada a la Publicacion p es del tipo Casa si tipoInmueble = 
// casa o Apartamento si tipoInmueble = apartamento. Tal que 
// dtp.codigo = p.codigo, dtp.fecha = p.fecha, dtp.texto 
// = p.texto, dtp.precio = p.precio y dtp.inmobiliaria = 
// i.nombre donde i es la Inmobiliaria relacionada a AdministraPropiedad 
// relacionada a la Publicación p
    std::set<DTPublicacion*> listarPublicaciones(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble){
    std::set<DTPublicacion*> publicacionesFiltradas;
    std::list<Publicacion*> listaPublicaciones = ManejadorPublicaciones::getManejadorPublicaciones()->listarPublicaciones();
    for (std::list<Publicacion*>::iterator i = listaPublicaciones.begin(); i !=listaPublicaciones.end(); i++)
    {
      if ((*i)->getTipo()==tipoPublicacion && (*i)->getPrecio()>precioMinimo&& (*i)->getPrecio<precioMaximo
      {
        /* code */
      }
      
    }
    

    };
    DTPublicacion getPublicacion(int id){

    };
    DTInmueble detalleInmueblePublicacion(int codigoPublicacion){

    };
    ControladorPublicacion::~ControladorPublicacion(){

    };