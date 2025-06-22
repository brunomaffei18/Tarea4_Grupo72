 #include "../include/Inmueble.h"
 #include <string>
 #include "../include/AdministraPropiedad.h"
 
 
 Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion){
  this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anoConstruccion = anoConstruccion;
};
        void Inmueble::AgregarAdministrados(AdministraPropiedad *Administados){
            this->InmueblesAdministrados.insert(Administados);
        }
 void Inmueble::EliminarPublicaciones(){

  for (std::set<AdministraPropiedad*>::iterator i = InmueblesAdministrados.begin(); i != InmueblesAdministrados.end(); i++)
  {
    (*i)->DarBajaPublicaciones();
  }
  
  
   
        };
        Inmueble::~Inmueble(){

          // for (std::set<AdministraPropiedad*>::iterator i =InmueblesAdministrados.begin();i!=InmueblesAdministrados.end();i++){
          //   delete *i;
          // }
          InmueblesAdministrados.clear();
        };
int Inmueble::getCodigo() {
    return this->codigo;
}

Propietario* Inmueble::getPropietario(){
    return propietario;
}

void Inmueble::setPropietario(Propietario* p){
  propietario=p;
}

   std::string Inmueble:: getDireccion(){
return this->direccion;
   };
   std::set<AdministraPropiedad*> Inmueble::getInmueblesAdministrados(){
    return this->InmueblesAdministrados;
   }
     int Inmueble:: getNumeroPuerta(){return this->numeroPuerta;};
     int Inmueble::getSuperficie(){return this->superficie;};
     int Inmueble::getAnoConstruccion(){return this->anoConstruccion;};
     void Inmueble::eliminarAdministrados(AdministraPropiedad* administrados){
         this->InmueblesAdministrados.erase(administrados);
     };