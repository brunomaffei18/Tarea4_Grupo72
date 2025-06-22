#include "../include/DTFecha.h"
#include "../include/Inmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/Publicacion.h"
#include "../include/AdministraPropiedad.h"

//#include "../include/AdministraPropiedad.h"

AdministraPropiedad::AdministraPropiedad(DTFecha* fecha, Inmueble* inmueble, Inmobiliaria* inmobiliaria)
    : fecha(new DTFecha(fecha)),
      inmuebleAdmin(inmueble),
      InmobiliariaResponsable(inmobiliaria){
}

Inmueble* AdministraPropiedad::getInmueble(){
    return this->inmuebleAdmin;
}
Inmobiliaria* AdministraPropiedad::getInmobiliaria(){
    return this->InmobiliariaResponsable;
}

//Asumo que elimina todas las publicaciones, si deberia desactivarlas falda el metodo en Publicaciones.h
void AdministraPropiedad::DarBajaPublicaciones(){
std::map<int, Publicacion*>::iterator it;
for (it = Publicaciones.begin(); it != Publicaciones.end(); ++it){
    Publicaciones.erase(it->first);
}
}

//Asumo que elimina unicamente la publicacion que se le pasa.
void AdministraPropiedad::borrarPublicacion(Publicacion p){
int key = p.getCodigo();
this->Publicaciones.erase(key);
}

AdministraPropiedad::~AdministraPropiedad(){
    delete this->fecha;

    std::map<int, Publicacion*>::iterator it;
    for (it = Publicaciones.begin(); it != Publicaciones.end(); ++it){
        delete it->second;
    }

    Publicaciones.clear();
}

DTFecha* AdministraPropiedad::getFechaPublicacion(){
    return this->fecha;
}
