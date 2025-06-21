#include "../include/ManejadorInmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/ManejadorUsuario.h"
#include "../include/DTInmuebleListado.h"

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
            }

        };
        void ManejadorInmueble::eliminarInmueble(int codigoInmueble){
            auto it =inmuebles.find(codigoInmueble);
            Inmueble* inmueble=it->second;
            std::set<AdministraPropiedad*>administracion=inmueble->getInmueblesAdministrados();
            for (auto admin: administracion){
                admin->DarBajaPublicaciones();
                    Inmobiliaria*i=admin->getInmobiliaria();
                i->eliminarAdministracion(admin);
                delete admin;
            }
            ManejadorUsuario* manejdorU=ManejadorUsuario::getManejadorUsuario();
            std::map<std::string,Propietario*>& propietario=manejdorU->getPropietarios();
            for (auto& prop:propietario){
                prop.second->desvincularInmueble(codigoInmueble);
            }

            delete inmueble;
            inmuebles.erase(it);
            


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
        // std::list<DTInmuebleListado>ManejadorInmueble::ListarInmueblesListados(){
        //         std::list<DTInmuebleListado> listyadelistados;
        //         for(auto i=inmuebles.begin();i!=inmuebles.end();i++){
        //             ManejadorUsuario* manejadorU=ManejadorUsuario::getManejadorUsuario();
        //             std::map<std::string,Propietario*>& propietarios=manejadorU->getPropietarios();

        //             DTInmuebleListado dtLIstadss=DTInmuebleListado(i->second->getCodigo(),i->second->getDireccion(),)
        //         }
        // }
        ManejadorInmueble::~ManejadorInmueble(){
            for (auto i = inmuebles.begin(); i != inmuebles.end(); i++)
                {
                    delete i->second;
                }
            inmuebles.clear();

        };

    std::map<int, Inmueble*> ManejadorInmueble::getInmuebles() {
        return inmuebles;
    }