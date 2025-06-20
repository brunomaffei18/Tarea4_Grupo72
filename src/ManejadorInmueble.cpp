#include "../include/ManejadorInmueble.h"
#include "../include/Inmobiliaria.h"

ManejadorInmueble* ManejadorInmueble::instancia = nullptr;

ManejadorInmueble* ManejadorInmueble::getManejadorInmueble(){
    if(instancia==nullptr)
        instancia= new ManejadorInmueble();
    return instancia;
}


       ManejadorInmueble::ManejadorInmueble(){};

        int ManejadorInmueble::generarCodigo(){
            return inmuebles.size()+1;
        };
        void ManejadorInmueble::agregarInmueble(Inmueble* inmueble){
            inmuebles[inmueble->getCodigo()]= inmueble;

        };
        Inmueble* ManejadorInmueble::getInmueble(int codigoInmueble){
            if(inmuebles.find(codigoInmueble)!=inmuebles.end()){
                return inmuebles[codigoInmueble];
            }else{
                return nullptr;
            }

        };
        void ManejadorInmueble::eliminarInmueble(int codigoInmueble){
            
            Inmueble* inmueble=inmuebles[codigoInmueble];
            std::set<AdministraPropiedad*>administracion=inmueble->getInmueblesAdministrados();
            for (auto admin: administracion){
                admin->DarBajaPublicaciones();
                    Inmobiliaria*i=admin->getInmobiliaria();
                i->getAdministraciones();
            }
            

            auto inm=inmuebles.find(codigoInmueble);
            if(inm!=inmuebles.end()){
                delete inm->second;
                inmuebles.erase(inm);
            }


        };
        std::list<DTInmueble*> ManejadorInmueble::listarInmuebles(){
            std::list<DTInmueble*> listaDTInmuebles;
            for (auto i = inmuebles.begin(); i !=inmuebles.end(); i++)
            {
                Inmueble* inmueble=i->second;
                DTInmueble* DTinmuebles=new DTInmueble(inmueble->getCodigo(), inmueble->getDireccion(), inmueble->getNumeroPuerta(), inmueble->getSuperficie(), inmueble->getAnoConstruccion());
                listaDTInmuebles.push_back(DTinmuebles);
            }
            return listaDTInmuebles;
                };


        ManejadorInmueble::~ManejadorInmueble(){
            for (auto i = inmuebles.begin(); i != inmuebles.end(); i++)
                {
                    delete i->second;
                }
            inmuebles.clear();

        };