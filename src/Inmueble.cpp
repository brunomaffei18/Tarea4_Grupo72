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
        void Inmueble::AgragarAdministrados(AdministraPropiedad *Administados){
            this->InmueblesAdministrados.insert(Administados);
        }
 void Inmueble::EliminarPublicaciones(){

  for (std::set<AdministraPropiedad*>::iterator i = InmueblesAdministrados.begin(); i != InmueblesAdministrados.end(); i++)
  {
    (*i)->DarBajaPublicaciones();
  }
  
  
   
        };
        Inmueble::~Inmueble(){

          for (std::set<AdministraPropiedad*>::iterator i =InmueblesAdministrados.begin();i!=InmueblesAdministrados.end();i++){
            delete *i;
          }
          InmueblesAdministrados.clear();
        };
int Inmueble::getCodigo() {
    return this->codigo;
}

   std::string Inmueble:: getDireccion(){

   };
     int Inmueble:: getNumeroPuerta(){return this->numeroPuerta;};
     int Inmueble::getSuperficie(){return this->superficie;};
     int Inmueble::getAnoConstruccion(){return this->anoConstruccion;};