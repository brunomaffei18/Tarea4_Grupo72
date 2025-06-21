#include "../include/IControladorInmueble.h"
#include "../include/ControladorInmueble.h"
#include "../include/ManejadorInmueble.h"
#include <string>
#include "../include/Inmueble.h"
#include <set>
#include "../include/DTInmuebleListado.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/DTInmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"
#include "../include/ManejadorPublicaciones.h"
#include "../include/ManejadorUsuario.h";

ControladorInmueble :: ControladorInmueble()
{
    this->manejadorinm=ManejadorInmueble::getManejadorInmueble();
}
ControladorInmueble* ControladorInmueble::getInstancia(){
 if(Instancia ==NULL){
    Instancia=new ControladorInmueble();

 }
 return Instancia;
}


ControladorInmueble::~ControladorInmueble(){
    delete Instancia;
}
ControladorInmueble* ControladorInmueble::Instancia = NULL;

 DTInmueble ControladorInmueble::detalleInmueble(int codigoInmueble){
    ManejadorInmueble* manejadorInmueble =ManejadorInmueble::getManejadorInmueble();
    std::list<DTInmueble*> inmuebles = manejadorInmueble->listarInmuebles();
    
    for (std::list<DTInmueble*>::iterator i = inmuebles.begin(); i != inmuebles.end(); i++) {
        if ((*i)->getCodigo() == codigoInmueble) {
            DTInmueble result = *(*i);
            delete *i;
            return result;
        }
    }
    delete manejadorInmueble;
    
}
void ControladorInmueble:: altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo){
    ManejadorInmueble* manejador=ManejadorInmueble::getManejadorInmueble();
    int codigo=manejador->generarCodigo();
    Casa* casanueva=new Casa(esPH, techo, codigo, direccion, numeroPuerta, superficie, anoConstruccion);
    manejador->agregarInmueble(casanueva);
    
        if (this->propietarioRecordado != NULL)
        {
        this->propietarioRecordado->vincularInmueble(casanueva);
        }  
};

void  ControladorInmueble:: altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes){
    ManejadorInmueble* manejadorinm=ManejadorInmueble::getManejadorInmueble();
    int codigo=manejadorinm->generarCodigo();
    Apartamento* apartamentoNuevo=new Apartamento(piso, tieneAscensor, gastosComunes, codigo, direccion, numeroPuerta, superficie, anoConstruccion);
    manejadorinm->agregarInmueble(apartamentoNuevo);

    if (this->propietarioRecordado != NULL)
        {
        this->propietarioRecordado->vincularInmueble(apartamentoNuevo);
        }
};
    


//    void ControladorInmueble::eliminarInmueble(int codigoInmueble){
//         ManejadorUsuario* manejadorUsuario=ManejadorUsuario::getManejadorUsuario();
//         std::map<std::string,Propietario*>& propietarios = manejadorUsuario->getPropietarios();
       
//         Inmueble*inmu=manejadorinm->getInmueble(codigoInmueble);
//         inmu->EliminarPublicaciones();
//         std::set<AdministraPropiedad*>administrar=inmu->getInmueblesAdministrados();
//         for ( std::set<AdministraPropiedad*>::iterator i = administrar.begin(); i !=administrar.end(); i++)
//         {
            
//         }
         


//      };



     std::set<DTInmuebleListado*> ControladorInmueble::listarInmuebles(){
        

        };

    //  std::list<DTInmuebleListado> inmuebles = manejadorInmueble->listarInmuebles();
    //  std::set<DTInmueble*> resultado;
    //  for (std::list<DTInmueble*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
    //      resultado.insert(*it);
    //  }
    
    //  return resultado;
    
  
   void ControladorInmueble::setPropietarioRecordado(Propietario* prop){
    propietarioRecordado=prop;
   }