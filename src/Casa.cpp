#include "../include/Casa.h"
#include "../include/Inmueble.h"
#include <string>

Casa:: Casa(bool esPH, TipoTecho techo,int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion):Inmueble(codigo,direccion, numeroPuerta, superficie, anoConstruccion){
    this->esPH = esPH;
    this->techo = techo;
};


   bool Casa:: getEsPH(){
   return this->esPH;
   };
        TipoTecho  Casa:: getTecho(){ 
            return this->techo;
        };
        Casa::~Casa(){
        
        };

    TipoInmuebleenum::TipoInmueble Casa::getTipoInmueble() const {
        return TipoInmuebleenum::Casa;
    }