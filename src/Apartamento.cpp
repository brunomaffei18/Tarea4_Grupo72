#include "../include/Apartamento.h"   
#include "../include/Inmueble.h"
#include "../include/DTInmueble.h"

#include <string>

Apartamento::Apartamento(int piso, bool tieneAscensor, float gastosComunes,int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion):Inmueble(codigo,direccion, numeroPuerta, superficie, anoConstruccion) {
    this->piso = piso;
    this->tieneAscensor = tieneAscensor;
    this->gastosComunes = gastosComunes;
};
int Apartamento::getPiso() {
    return this->piso;
};
bool Apartamento::getTieneAscensor() {
    return this->tieneAscensor;
};
       float Apartamento::getGastosComunes(){
           return this->gastosComunes;
       };
       Apartamento::~Apartamento(){
          
       };