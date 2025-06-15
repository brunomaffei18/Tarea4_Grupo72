#include "../include/ControladorInmueble.h"
#include "../include/ManejadorInmueble.h"
#include <string>
#include <set>
#include "../include/DTInmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"


ControladorInmueble* ControladorInmueble::getInstancia(){
 if(Instancia ==NULL){
    Instancia=new ControladorInmueble();

 }
 return Instancia;
}

ControladorInmueble::ControladorInmueble(){
        

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



    void ControladorInmueble::eliminarInmueble(int codigoInmueble){
 //cuando esten hechas las clases faltantes se vuelve 
    };
    std::set<DTInmueble*> ControladorInmueble::listarInmuebles(){
     ManejadorInmueble* manejadorInmueble = new ManejadorInmueble();
    std::list<DTInmueble*> inmuebles = manejadorInmueble->listarInmuebles();
    std::set<DTInmueble*> resultado;
    for (std::list<DTInmueble*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        resultado.insert(*it);
    }
    delete manejadorInmueble;
    return resultado;
    };
  
   