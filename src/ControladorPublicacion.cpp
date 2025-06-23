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
bool ControladorPublicacion::altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, 
                                             TipoPublicacion tipoPublicacion, std::string texto, float precio)
{
    ManejadorPublicaciones* manejador = ManejadorPublicaciones::getManejadorPublicaciones(); 
    ManejadorInmueble* manejadorinmu = ManejadorInmueble::getManejadorInmueble();
    ManejadorUsuario* manejadorusu = ManejadorUsuario::getManejadorUsuario();

    if (!manejador || !manejadorusu || !manejadorinmu)
        return false;

    Inmobiliaria* inmobiliaria = manejadorusu->getInmobiliaria(nicknameInmobiliaria);
    Inmueble* inmueble = manejadorinmu->getInmueble(codigoInmueble);

    if (!inmobiliaria || !inmueble)
        return false;

    std::list<Publicacion*> publicaciones = manejador->listarPublicaciones();

    DTFecha* fecha = new DTFecha(ControladorFechaActual::getInstance()->getFechaActual());

    for (auto pub : publicaciones) {  
        bool mismaFecha = (*(pub->getFecha()) == *fecha);
        bool mismoTipo = (pub->getTipo() == tipoPublicacion);
        bool mismoInmueble = (pub->getInmueble()->getCodigo() == codigoInmueble);
        bool mismaInmobiliaria = (pub->getInmobiliaria()->getNickname() == nicknameInmobiliaria);
        bool mismoTexto = (pub->getTexto() == texto);
        bool mismoPrecio = (pub->getPrecio() == precio);

        if (mismaFecha && mismoTipo && mismoInmueble && mismaInmobiliaria && mismoTexto && mismoPrecio) {
            delete fecha;
            return false;
        }
    }

    int nuevoCodigo = manejador->generarCodigo();

    for (Publicacion* pub : publicaciones) {
        if (pub->getTipo() == tipoPublicacion && pub->getInmueble()->getCodigo() == codigoInmueble) {
            if (tipoPublicacion == Venta && pub->getCodigo() == manejador->getCodigoUltimaPublicacionVenta()) {
                pub->setActiva(false);
                manejador->setCodigoUltimaPublicacionVenta(nuevoCodigo);
            } else if (tipoPublicacion == Alquiler && pub->getCodigo() == manejador->getCodigoUltimaPublicacionAlquiler()) {
                pub->setActiva(false);
                manejador->setCodigoUltimaPublicacionAlquiler(nuevoCodigo);
            }
        }
    }

   std::set<AdministraPropiedad *> admins = inmobiliaria->getAdministraciones();
   AdministraPropiedad* admin; 
   for (auto adm : admins)
   {
    if (adm->getInmueble() == inmueble)
    {
      admin = adm;
    }
   }
    Publicacion* nuevaPublicacion = new Publicacion(nuevoCodigo, fecha, tipoPublicacion, texto, precio, true);

    nuevaPublicacion->setAdministra(admin);
    manejador->agregarPublicacion(nuevaPublicacion);

    for (Subscriptor* s : inmobiliaria->getSuscriptores()) {
        if (s && s->estaSuscriptoA(inmobiliaria)) {
            s->notificar(nuevaPublicacion);
        }
    }

    return true;
}





std::set<DTPublicacion> ControladorPublicacion::listarPublicaciones(
    TipoPublicacion tipoPublicacion, 
    float precioMinimo, 
    float precioMaximo, 
    TipoInmuebleenum::TipoInmueble tipoInmueble
) {
    std::set<DTPublicacion> publicacionesFiltradas;
    std::list<Publicacion*> listaPublicaciones = ManejadorPublicaciones::getManejadorPublicaciones()->listarPublicaciones();

    for (Publicacion* pub : listaPublicaciones) {
        // Solo mostrar publicaciones activas
        if (!pub->esActiva())
            continue;

        // Filtro por tipo de publicación
        if (pub->getTipo() != tipoPublicacion)
            continue;

        // Filtro por precio
        if (pub->getPrecio() < precioMinimo || pub->getPrecio() > precioMaximo)
            continue;

        // Filtro por tipo de inmueble
        if (tipoInmueble != TipoInmuebleenum::Todos &&
            pub->getInmueble()->getTipoInmueble() != tipoInmueble)
            continue;

        // Si pasó todos los filtros, agregamos la publicación
        DTPublicacion dtpub(
            pub->getCodigo(),
            pub->getFecha(),
            pub->getTexto(),
            pub->ConvertirPrecio(),
            pub->getInmobiliaria()->getNickname()
        );
        publicacionesFiltradas.insert(dtpub);
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