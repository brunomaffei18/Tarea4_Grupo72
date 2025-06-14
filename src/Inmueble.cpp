 #include "../include/Inmueble.h"
 #include <string>
 
 
 Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion){
  this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anoConstruccion = anoConstruccion;
};
        
 void Inmueble:: EliminarPublicaciones(){

        };
        Inmueble::~Inmueble(){

        };