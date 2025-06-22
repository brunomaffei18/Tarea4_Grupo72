#include "../include/ManejadorPublicaciones.h"

ManejadorPublicaciones* ManejadorPublicaciones::instancia =NULL;

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
            if(publicaciones.empty()){
                return -1;//Aca habia un NULL y arriba un this->codigoUltimaPUblicacionVenta
            }
            return this->codigoUltimaPUblicacionVenta;
        }

void ManejadorPublicaciones:: setCodigoUltimaPublicacionAlquiler(int codigo){
    this->codigoUltimaPUblicacionAlquiler = codigo;
};

 int ManejadorPublicaciones::getCodigoUltimaPublicacionAlquiler() const {
            /*if(this->codigoUltimaPUblicacionAlquiler==NULL){
                return NULL;
            }*/
            return this->codigoUltimaPUblicacionAlquiler;
        };


ManejadorPublicaciones::~ManejadorPublicaciones(){
    delete instancia;
    instancia =NULL;
}  