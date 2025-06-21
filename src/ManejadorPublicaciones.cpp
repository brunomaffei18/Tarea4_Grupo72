#include "../include/ManejadorPublicaciones.h"

ManejadorPublicaciones* ManejadorPublicaciones::instancia = nullptr;

ManejadorPublicaciones* ManejadorPublicaciones::getManejadorPublicaciones(){
    if(instancia==nullptr)
        instancia= new ManejadorPublicaciones();
    return instancia;
}

        int ManejadorPublicaciones:: generarCodigo(){
            return publicaciones.size()+1;

        };
        void ManejadorPublicaciones::agregarPublicacion(Publicacion* publicacion){
            publicaciones[publicacion->getCodigo()]=publicacion;
        };
        std::list<Publicacion*> ManejadorPublicaciones:: listarPublicaciones(){
            std::list<Publicacion*> lista;
            for (auto lp: publicaciones){
                lista.push_back(lp.second);
            }
            return lista;

        };
       ManejadorPublicaciones:: ManejadorPublicaciones(){
         
        };
    
  void ManejadorPublicaciones::setCodigoUltimaPublicacionVenta(int codigo){
    this->codigoUltimaPUblicacionVenta=codigo;
  };
        int ManejadorPublicaciones::getCodigoUltimaPublicacionVenta() const {
            return this->codigoUltimaPUblicacionVenta;
        }

void ManejadorPublicaciones:: setCodigoUltimaPublicacionAlquiler(int codigo){
    this->codigoUltimaPUblicacionAlquiler = codigo;
};
        int ManejadorPublicaciones::getCodigoUltimaPublicacionAlquiler() const {
            return this->codigoUltimaPUblicacionAlquiler;
        };


ManejadorPublicaciones::~ManejadorPublicaciones(){
    delete instancia;
    instancia = nullptr;
}  