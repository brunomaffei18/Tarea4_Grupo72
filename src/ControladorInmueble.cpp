#include "../include/IControladorInmueble.h"
#include "../include/ControladorInmueble.h"
#include "../include/ManejadorInmueble.h"
#include <string>
#include "../include/Inmueble.h"
#include <set>
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/DTInmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"

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
    ManejadorInmueble* manejadorInmueble = new ManejadorInmueble();
    std::list<DTInmueble*> inmuebles = manejadorInmueble->listarInmuebles();
    
    for (std::list<DTInmueble*>::iterator i = inmuebles.begin(); i != inmuebles.end(); i++) {
        if ((*i)->getCodigo() == codigoInmueble) {
            DTInmueble result = *(*i);
            delete manejadorInmueble;
            return result;
        }
    }
    delete manejadorInmueble;
    
}
void ControladorInmueble:: altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo){
    ManejadorInmueble* manejador=ManejadorInmueble::getManejadorInmueble();
    int codigo=manejador->generarCodigo();
    ::Casa* casanueva=new ::Casa(esPH, techo, codigo, direccion, numeroPuerta, superficie, anoConstruccion);
    manejador->agregarInmueble(casanueva);
    
};

void  ControladorInmueble:: altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes){
   ManejadorInmueble* manejadorinm=ManejadorInmueble::getManejadorInmueble();
    int codigo=manejadorinm->generarCodigo();
    Apartamento* apartamentoNuevo=new Apartamento(piso, tieneAscensor, gastosComunes, codigo, direccion, numeroPuerta, superficie, anoConstruccion);
    manejadorinm->agregarInmueble(apartamentoNuevo);
    

};
    


//     void ControladorInmueble::eliminarInmueble(int codigoInmueble){
//  //cuando esten hechas las clases faltantes se vuelve 
//     };
//     std::set<DTInmueble*> ControladorInmueble::listarInmuebles(){
//      ManejadorInmueble* manejadorInmueble = new ManejadorInmueble();
//     std::list<DTInmueble*> inmuebles = manejadorInmueble->listarInmuebles();
//     std::set<DTInmueble*> resultado;
//     for (std::list<DTInmueble*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
//         resultado.insert(*it);
//     }
//     delete manejadorInmueble;
//     return resultado;
//     };
  
   